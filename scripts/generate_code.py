#!/usr/bin/env python3
"""Generate code from the game structures declared in MoMModel/MoMTemplate.h.

Reads    Platform/MoMCommon.h and MoMModel/MoMTemplate.h
Writes   MoMModel/Generated/MoMGenerated.{h,cpp}     operator<< for every enum
         QMoMCommon/Generated/QMoMGenerated.{h,cpp}  constructTreeItem() for every struct (Qt tree)
         docs/data/mom-layout.json                   all enums and struct layouts, for other tools
         MoMGenerated.idc                            IDA Pro type definitions (not committed)

With --layout-check FILE it writes only a C++ file of static_asserts that the
offsets and sizes computed here match the compiler's (built into the unit tests).

Usage (from any directory):
    python3 scripts/generate_code.py            # regenerate the files
    python3 scripts/generate_code.py --check    # exit 1 if a committed file is out of date
    python3 scripts/generate_code.py --verbose  # also print the parsed struct layouts
"""

from __future__ import annotations

import argparse
import ast
import bisect
import contextlib
import json
import math
import operator
import re
import sys
from dataclasses import dataclass, field
from pathlib import Path

INPUT_FILES = ("Platform/MoMCommon.h", "MoMModel/MoMTemplate.h")
TEMPLATE_HEADER = "MoMTemplate.h"

CORE_DIR = "MoMModel/Generated"
CORE_HEADER = "MoMGenerated.h"
CORE_SOURCE = "MoMGenerated.cpp"
QT_DIR = "QMoMCommon/Generated"
QT_HEADER = "QMoMGenerated.h"
QT_SOURCE = "QMoMGenerated.cpp"
IDC_DIR = "."
IDC_FILE = "MoMGenerated.idc"
JSON_DIR = "docs/data"
JSON_FILE = "mom-layout.json"
JSON_SCHEMA = "momrtgt-layout/1"

# The headers are ASCII; latin-1 keeps any stray byte intact.
ENCODING = "latin-1"


# ---------------------------------------------------------------------------
# Model
# ---------------------------------------------------------------------------


@dataclass
class Enumerator:
    name: str
    value: int
    comment: str | None = None


@dataclass
class Enum:
    name: str
    size: int
    enumerators: list[Enumerator] = field(default_factory=list)
    location: str = ""  # "file:line" of the declaration


@dataclass
class Member:
    type: str
    name: str
    count_expr: str | None = None  # array size as written in the header
    count: int | None = None  # evaluated array size
    bits: int | None = None  # bitfield width
    offset: int = 0
    size: int = 0
    bit_offset: int | None = None  # first bit of a bitfield within its storage unit
    comment: str | None = None

    @property
    def declarator(self) -> str:
        if self.count_expr is not None:
            return f"{self.name}[{self.count_expr}]"
        if self.bits is not None:
            return f"{self.name}:{self.bits}"
        return self.name


@dataclass
class Struct:
    kind: str  # "struct", "union" or "class"
    name: str
    members: list[Member] = field(default_factory=list)
    size: int = 0
    location: str = ""  # "file:line" of the declaration


@dataclass
class Model:
    constants: dict[str, int] = field(default_factory=dict)  # const declarations and enumerators
    declared_constants: list[str] = field(default_factory=list)  # names of the const declarations
    enums: dict[str, Enum] = field(default_factory=dict)
    structs: dict[str, Struct] = field(default_factory=dict)
    warnings: list[str] = field(default_factory=list)

    def sorted_enums(self) -> list[Enum]:
        return [self.enums[name] for name in sorted(self.enums)]

    def sorted_structs(self) -> list[Struct]:
        return [self.structs[name] for name in sorted(self.structs)]

    def type_size(self, type_name: str) -> int | None:
        if type_name == "char":
            return 1
        if m := re.fullmatch(r"u?int(8|16|32|64)_t", type_name):
            return int(m.group(1)) // 8
        if type_name == "DS_Offset":
            return 2
        if type_name in self.enums:
            return self.enums[type_name].size
        if type_name in self.structs:
            return self.structs[type_name].size
        return None


# ---------------------------------------------------------------------------
# Constant expressions
# ---------------------------------------------------------------------------

_C_INTEGER = re.compile(r"\b(0[xX][0-9a-fA-F]+|0[0-7]*|[1-9][0-9]*)[uUlL]*\b")

_BINARY_OPS = {
    ast.Add: operator.add,
    ast.Sub: operator.sub,
    ast.Mult: operator.mul,
    ast.Div: lambda a, b: math.trunc(a / b),  # C integer division
    ast.FloorDiv: lambda a, b: math.trunc(a / b),
    ast.Mod: operator.mod,
    ast.LShift: operator.lshift,
    ast.RShift: operator.rshift,
    ast.BitOr: operator.or_,
    ast.BitAnd: operator.and_,
    ast.BitXor: operator.xor,
}
_UNARY_OPS = {ast.USub: operator.neg, ast.UAdd: operator.pos, ast.Invert: operator.invert}


def _c_literal_to_python(m: re.Match) -> str:
    literal = m.group(1)
    if literal.lower().startswith("0x"):
        return str(int(literal, 16))
    if literal.startswith("0") and len(literal) > 1:
        return str(int(literal, 8))  # C octal
    return literal


def evaluate(expression: str, names: dict[str, int]) -> int:
    """Evaluate a C integer constant expression; names are constants and enumerators."""
    tree = ast.parse(_C_INTEGER.sub(_c_literal_to_python, expression.strip()), mode="eval")

    def visit(node: ast.AST) -> int:
        if isinstance(node, ast.Constant) and type(node.value) is int:
            return node.value
        if isinstance(node, ast.Name) and node.id in names:
            return names[node.id]
        if isinstance(node, ast.BinOp) and type(node.op) in _BINARY_OPS:
            return _BINARY_OPS[type(node.op)](visit(node.left), visit(node.right))
        if isinstance(node, ast.UnaryOp) and type(node.op) in _UNARY_OPS:
            return _UNARY_OPS[type(node.op)](visit(node.operand))
        raise ValueError(f"cannot evaluate '{expression}'")

    return visit(tree.body)


# ---------------------------------------------------------------------------
# Parser
# ---------------------------------------------------------------------------

_CONSTANT = re.compile(r"\bconst\s+(?:unsigned|size_t)\s+(\w+)\s*=\s*([^;]+);")
_ENUM = re.compile(r"\benum\s+(?P<name>\w+)\s*(?:ENUMSIZE(?P<bits>\d+))?[^{;]*\{(?P<body>[^}]*)\}[^;]*;")
# The closing brace of a typedef is at the start of a line; nested braces are indented.
_STRUCT = re.compile(
    r"\btypedef\s+(?P<kind>struct|union|class)\b[^{]*\{(?P<body>.*?\n)\}\s*(?P<name>\w+)\s*;", re.DOTALL
)
_DECLARATION = re.compile(
    r"(?P<type>.*?)\s*\b(?P<name>\w+)\s*(?:\[(?P<count>[^\]]+)\])?\s*(?::\s*(?P<bits>\d+))?", re.DOTALL
)


_COMMENT = re.compile(r"/\*.*?\*/|//[^\n]*", re.DOTALL)


def blank(m: re.Match) -> str:
    """Replace a match by spaces, keeping newlines, so text positions stay valid."""
    return re.sub(r"[^\n]", " ", m[0])


class Source:
    """The concatenated input files, with comments blanked out of the code.

    Positions in `code` are positions in the original text, so a parsed
    declaration can be traced back to its file, line and trailing comment.
    """

    def __init__(self, files: list[tuple[str, str]]):
        self.file_starts: list[tuple[int, str, int]] = []  # (position, file name, line number of position)
        text, line = "", 1
        for name, content in files:
            content = content.replace("\r", "")
            self.file_starts.append((len(text), name, line))
            text += content
            line += content.count("\n")
        self.line_starts = [0] + [m.end() for m in re.finditer("\n", text)]
        self.line_comments: dict[int, str] = {}
        for m in _COMMENT.finditer(text):
            if m[0].startswith("//") and (comment := m[0][2:].strip()):
                self.line_comments[self.line_index(m.start())] = comment
        self.code = _COMMENT.sub(blank, text)

    def line_index(self, position: int) -> int:
        return bisect.bisect_right(self.line_starts, position) - 1

    def comment_at(self, position: int) -> str | None:
        """The // comment at the end of the line containing position."""
        return self.line_comments.get(self.line_index(position))

    def location(self, position: int) -> str:
        start, name, first_line = self.file_starts[bisect.bisect_right([f[0] for f in self.file_starts], position) - 1]
        return f"{name}:{self.line_index(position) - self.line_index(start) + 1}"


def parse(source: Source) -> Model:
    model = Model()
    text = source.code

    for name, value in _CONSTANT.findall(text):
        with contextlib.suppress(ValueError, SyntaxError):  # skip non-integer constants
            model.constants[name] = evaluate(value, model.constants)
            model.declared_constants.append(name)

    for m in _ENUM.finditer(text):
        enum = parse_enum(m["name"], m["bits"], m["body"], m.start("body"), source, model.constants)
        enum.location = source.location(m.start())
        model.enums[enum.name] = enum

    # Enum bodies can contain ';' in their trailing text; blank them out before the structs.
    text = _ENUM.sub(blank, text)
    for m in _STRUCT.finditer(text):
        struct = parse_struct(m["kind"], m["name"], m["body"], m.start("body"), source, model)
        struct.location = source.location(m.start())
        model.structs[struct.name] = struct

    return model


def parse_enum(
    name: str, bits: str | None, body: str, body_start: int, source: Source, constants: dict[str, int]
) -> Enum:
    enum = Enum(name, size=int(bits) // 8 if bits else 4)
    value = -1
    for item in re.finditer(r"[^,]+", body):
        if not item[0].strip():
            continue
        enumerator, _, expression = (s.strip() for s in item[0].partition("="))
        value = evaluate(expression, constants) if expression else value + 1
        position = body_start + item.start() + len(item[0]) - len(item[0].lstrip())
        enum.enumerators.append(Enumerator(enumerator, value, source.comment_at(position)))
        constants[enumerator] = value
    return enum


def parse_struct(kind: str, name: str, body: str, body_start: int, source: Source, model: Model) -> Struct:
    struct = Struct(kind, name)
    for statement in re.finditer(r"([^;]*);", body):
        declaration = statement[1].strip()
        if not declaration:
            continue
        m = _DECLARATION.fullmatch(declaration)
        if not m or not m["type"]:
            raise ValueError(f"{name}: cannot parse declaration '{declaration}'")
        member = Member(
            type=m["type"],
            name=m["name"],
            count_expr=m["count"],
            bits=int(m["bits"]) if m["bits"] else None,
            comment=source.comment_at(body_start + statement.end() - 1),
        )
        if member.count_expr is not None:
            try:
                member.count = evaluate(member.count_expr, model.constants)
            except (ValueError, SyntaxError):
                model.warnings.append(f"{name}.{member.name}: unknown array size '{member.count_expr}'")
        struct.members.append(member)

    layout(struct, model)
    return struct


def layout(struct: Struct, model: Model) -> None:
    """Assign offsets and sizes as for a packed struct or union.

    A run of consecutive bitfields of the same type shares storage units of that type.
    """
    is_union = struct.kind == "union"
    offset = 0
    unit_size = 0  # storage unit size of the current run of bitfields; 0 if none
    bits_used = 0

    def end_bitfield_run() -> None:
        nonlocal offset, unit_size, bits_used
        if unit_size:
            offset += math.ceil(bits_used / (8 * unit_size)) * unit_size
        unit_size = bits_used = 0

    for member in struct.members:
        type_size = model.type_size(member.type)
        if type_size is None:
            model.warnings.append(f"{struct.name}.{member.name}: unknown size of type '{member.type}'")
            type_size = 0

        if member.bits is not None and not is_union and type_size:
            if type_size != unit_size:
                end_bitfield_run()
                unit_size = type_size
            member.offset = offset + bits_used // (8 * unit_size) * unit_size
            member.bit_offset = bits_used % (8 * unit_size)
            member.size = unit_size
            bits_used += member.bits
            continue

        end_bitfield_run()
        member.size = type_size * (1 if member.count is None else member.count)
        if not is_union:
            member.offset = offset
            offset += member.size

    end_bitfield_run()
    struct.size = max((m.size for m in struct.members), default=0) if is_union else offset


# ---------------------------------------------------------------------------
# Generators. Each returns the contents of one file.
# ---------------------------------------------------------------------------


def lines(*parts: str) -> str:
    return "".join(f"{part}\n" for part in parts)


def generate_core_header(model: Model) -> str:
    declarations = [f"std::ostream& operator<<(std::ostream& os, const {e.name}& rhs);" for e in model.sorted_enums()]
    return lines(
        f"// File: {CORE_DIR}/{CORE_HEADER}",
        f"// Generated from: {TEMPLATE_HEADER}",
        "",
        "#include <iostream>",
        "",
        f'#include "{TEMPLATE_HEADER}"',
        "",
        "namespace MoM {",
        "",
        *declarations,
        "",
        "",
        "}",
    )


def generate_core_source(model: Model) -> str:
    out = [
        lines(
            f"// File: {CORE_DIR}/{CORE_SOURCE}",
            f"// Generated from: {TEMPLATE_HEADER}",
            "",
            "#include <ctype.h>",
            "#include <iomanip>",
            "#include <sstream>",
            "",
            f'#include "{CORE_HEADER}"',
            "",
            "#ifdef _MSC_VER                // Compiler MS Visual Studio",
            "#pragma warning(disable: 4100) // MSVC: unreferenced formal parameter",
            "#endif",
            "",
            "namespace MoM {",
            "",
        )
    ]
    for enum in model.sorted_enums():
        # Sentinels (_SIZE__) and aliases (_FIRST) would give duplicate case labels
        cases = [
            f'    case {e.name}: os << "{e.name}"; break;'
            for e in enum.enumerators
            if "_SIZE__" not in e.name and "_FIRST" not in e.name
        ]
        out.append(
            lines(
                f"std::ostream& operator<<(std::ostream& os, const {enum.name}& rhs)",
                "{",
                "    switch (rhs)",
                "    {",
                *cases,
                f'    default: os << "<Unknown {enum.name}>"; break;',
                "    }",
                '    os << " (" << (unsigned)rhs << ")";',
                "    return os;",
                "}",
                "",
            )
        )
    out.append(lines("} // namespace"))
    return "".join(out)


def generate_qt_header(model: Model) -> str:
    declarations = [
        f"QMoMTreeItemModelBase* constructTreeItem({s.name}* rhs, const QString& context);"
        for s in model.sorted_structs()
    ]
    return lines(
        f"// File: {QT_DIR}/{QT_HEADER}",
        f"// Generated from: {TEMPLATE_HEADER}",
        "",
        "#include <iostream>",
        "",
        f'#include "{TEMPLATE_HEADER}"',
        '#include "QMoMTreeItemModel.h"',
        "",
        "namespace MoM {",
        "",
        *declarations,
        "",
        "}",
    )


def is_integer_type(type_name: str) -> bool:
    return re.search(r"u?int\d+_t", type_name) is not None


def enumerator_for_member(model: Model, member_name: str) -> str | None:
    """The enumerator a member is named after: eSkill_Alchemy -> SKILL_Alchemy (an enumerator of eSkill)."""
    enum_name, _, value = member_name.partition("_")
    if enum_name not in model.enums or not value:
        return None
    matches = [e.name for e in model.enums[enum_name].enumerators if e.name.endswith(f"_{value}")]
    return matches[0] if len(matches) == 1 else None


def tree_item_lines(model: Model, struct: Struct, member: Member) -> list[str]:
    """C++ statements that add one member to the Qt tree of its struct."""
    type_name = "uint16_t" if member.type == "DS_Offset" else member.type
    name = member.name
    is_leaf = is_integer_type(type_name) or type_name in model.enums

    if enumerator := enumerator_for_member(model, name):
        # A member named after an enumerator (eSkill_Alchemy for SKILL_Alchemy)
        # is labeled with the name the game gives that enumerator
        label = f"QMoMResources::instance().getName({enumerator})"
    else:
        label = f'"{name}"'

    if member.count_expr is not None and type_name == "char":
        return [f"    ptree->appendChild({label}, new QMoMTreeItemModel<char[{member.count_expr}]>(rhs->{name}));"]

    if member.count_expr is not None:
        count, subtree = member.count_expr, f"ptree{name}"
        out = [f"    QMoMTreeItemModelBase* {subtree} = ptree;"]
        if len(struct.members) > 1:
            # Group larger arrays under their own node
            out += [
                f"    if ({count} > 3)",
                "    {",
                f"        {subtree} = new QMoMTreeItemModelBase({label});",
                f'        ptree->appendTree({subtree}, "");',
                "    }",
            ]
        if is_leaf:
            add = f"{subtree}->appendChild(oss.str().c_str(), new QMoMTreeItemModel<{type_name}>(&rhs->{name}[i]));"
        else:
            add = f'{subtree}->appendTree(constructTreeItem(&rhs->{name}[i], oss.str().c_str()), "");'
        return out + [
            f"    for (unsigned i = 0; i < {count}; ++i)",
            "    {",
            "          std::ostringstream oss;",
            f'          oss << "{name}[" << i << "]";',
            f"          {add}",
            "    }",
        ]

    if is_integer_type(type_name) and member.bits is not None:
        mask = f"mask{name}"
        add = "ptree->appendChild({label}, new QMoMTreeItemModel<{t}>(({t}*)rhs, *({t}*)&{mask}));"
        return [
            f"    {struct.name} {mask};",
            f"    memset(&{mask}, '\\0', sizeof({mask}));",
            f"    {mask}.{name} = {(1 << member.bits) - 1};",
            f"    if (1 == sizeof({mask}))",
            "        " + add.format(label=label, t="uint8_t", mask=mask),
            f"    else if (2 == sizeof({mask}))",
            "        " + add.format(label=label, t="uint16_t", mask=mask),
            "    else",
            "        " + add.format(label=label, t="uint32_t", mask=mask),
        ]

    if type_name in model.enums and f"{type_name}140m" in model.enums:
        # The enum has variants per game version
        out = []
        for keyword, version, suffix in (("if", "6.0", "60"), ("else if", "1.50", "150"), ("else if", "1.40m", "140m")):
            variant = f"{type_name}{suffix}"
            out += [
                f'    {keyword} (QMoMTreeItemModelBase::game()->getMoMVersion() >= std::string("{version}"))',
                "    {",
                f"        ptree->appendChild({label}, new QMoMTreeItemModel<{variant}>(({variant}*)&rhs->{name}));",
                "    }",
            ]
        return out + [
            "    else",
            "    {",
            f"        ptree->appendChild({label}, new QMoMTreeItemModel<{type_name}>(&rhs->{name}));",
            "    }",
        ]

    if is_leaf:
        return [f"    ptree->appendChild({label}, new QMoMTreeItemModel<{type_name}>(&rhs->{name}));"]

    return [f'    ptree->appendTree(constructTreeItem(&rhs->{name}, {label}), "");']


def generate_qt_source(model: Model) -> str:
    out = [
        lines(
            f"// File: {QT_DIR}/{QT_SOURCE}",
            f"// Generated from: {TEMPLATE_HEADER}",
            "",
            "#include <ctype.h>",
            "#include <iomanip>",
            "#include <sstream>",
            "",
            "#include <MoMGenerated.h>",
            "",
            f'#include "{QT_HEADER}"',
            "",
            "namespace MoM {",
            "",
        )
    ]
    for struct in model.sorted_structs():
        body = [line for member in struct.members for line in tree_item_lines(model, struct, member)]
        out.append(
            lines(
                f"QMoMTreeItemModelBase* constructTreeItem({struct.name}* rhs, const QString& context)",
                "{",
                f"    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<{struct.name}>(rhs, context);",
                "    if (0 == rhs)",
                "        return ptree;",
                "",
                *body,
                "    return ptree;",
                "}",
                "",
            )
        )
    out.append(lines("", "} // namespace"))
    return "".join(out)


# IDA member flags
IDA_FIELD = 0x000400
IDA_ENUM = 0x800000  # also used for char
IDA_WORD = 0x10000000
IDA_DWORD = 0x20000000
IDA_STRUCT = 0x60000000


def idc_member_line(model: Model, member: Member) -> str:
    if member.type == "DS_Offset":
        return (
            f'    mid = AddStrucMember(id,"{member.name}",\t0X{member.offset:X},\t0x10500400,'
            f"\t0X36AA0,\t2,\t0XFFFFFFFF,\t0X0,\t0x000002);"
        )

    flags, type_id = IDA_FIELD, "-1"
    if member.type == "char":
        flags, type_id = flags | IDA_ENUM, "0x0"
    elif member.type in model.enums:
        flags, type_id = flags | IDA_ENUM, f'GetEnum("{member.type}")'
    elif member.type in model.structs:
        flags, type_id = flags | IDA_STRUCT, f'GetStrucIdByName("{member.type}")'

    if model.type_size(member.type) == 2:
        flags |= IDA_WORD
    elif model.type_size(member.type) == 4 and member.type not in model.enums:
        flags |= IDA_DWORD

    return (
        f'    mid = AddStrucMember(id,"{member.name}",\t0X{member.offset:X},\t0X{flags:06X},'
        f"\t{type_id},\t{member.size});"
    )


def idc_members(struct: Struct) -> list[Member]:
    """Members as IDA sees them: one member per bitfield storage unit."""
    members, unit_offset = [], None
    for member in struct.members:
        if member.bits is None:
            members.append(member)
            unit_offset = None
        elif member.offset != unit_offset or struct.kind == "union":
            members.append(member)
            unit_offset = member.offset
    return members


def generate_idc(model: Model) -> str:
    enum_lines = []
    for enum in model.sorted_enums():
        enum_lines.append(f'    id = AddEnum(-1,"{enum.name}",0x1100000);')
        enum_lines += [f'    AddConstEx(id,"{e.name}",\t{e.value},\t-1);' for e in enum.enumerators]

    struct_lines = [f'    id = AddStrucEx(-1,"{s.name}",{int(s.kind == "union")});' for s in model.sorted_structs()]
    struct_lines.append("")
    for struct in model.sorted_structs():
        struct_lines.append(f'    id = GetStrucIdByName("{struct.name}");')
        struct_lines += [idc_member_line(model, m) for m in idc_members(struct)]

    return lines(
        f"// File: {IDC_DIR}/{IDC_FILE}",
        f"// Generated from: {TEMPLATE_HEADER}",
        "",
        "//      This file contains the user-defined type definitions.",
        "//      To use it press F2 in IDA and enter the name of this file.",
        "//",
        "",
        "#define UNLOADED_FILE   1",
        "#include <idc.idc>",
        "",
        "static main(void)",
        "{",
        "  Enums();              // enumerations",
        "  Structures();         // structure types",
        "  LowVoids(0x20);",
        "  HighVoids(0xF978);",
        "}",
        "",
        "static Enums_0(id) {",
        "",
        *enum_lines,
        "",
        "  return id;",
        "}",
        "",
        "// Information about enum types",
        "static Enums(void) {",
        "  auto id;",
        "  id = Enums_0(id);",
        "}",
        "",
        "static Structures_0(id) {",
        "  auto mid;",
        "",
        *struct_lines,
        "  return id;",
        "}",
        "",
        "// Information about structure types",
        "static Structures(void) {",
        "  auto id;",
        "  id = Structures_0(id);",
        "}",
        "",
        "// End of file.",
    )


def generate_layout_check(model: Model) -> str:
    """static_asserts that the compiler lays out every struct as computed here."""
    asserts = []
    for struct in model.structs.values():
        asserts.append(f'static_assert(sizeof({struct.name}) == 0x{struct.size:X}, "sizeof({struct.name})");')
        asserts += [
            f'static_assert(offsetof({struct.name}, {m.name}) == 0x{m.offset:X}, "{struct.name}::{m.name}");'
            for m in struct.members
            if m.bits is None
        ]
    return lines(
        "// Generated by scripts/generate_code.py --layout-check",
        f"// Checks that the compiler lays out the structs of {TEMPLATE_HEADER} as the generator computes",
        "",
        "#include <cstddef>",
        "",
        f'#include "{TEMPLATE_HEADER}"',
        "",
        "namespace MoM {",
        "",
        *asserts,
        "",
        "}",
    )


PRIMITIVE_TYPES = {
    "char": {"size": 1, "signed": True},
    "int8_t": {"size": 1, "signed": True},
    "uint8_t": {"size": 1, "signed": False},
    "int16_t": {"size": 2, "signed": True},
    "uint16_t": {"size": 2, "signed": False},
    "int32_t": {"size": 4, "signed": True},
    "uint32_t": {"size": 4, "signed": False},
    "DS_Offset": {"size": 2, "signed": False, "note": "offset into the data segment"},
}


def without_none(**fields: object) -> dict[str, object]:
    return {key: value for key, value in fields.items() if value is not None}


def layout_document(model: Model) -> dict[str, object]:
    """The parsed model as plain data. Offsets and sizes are in bytes."""
    return {
        "schema": JSON_SCHEMA,
        "generator": "scripts/generate_code.py",
        "sources": list(INPUT_FILES),
        "primitive_types": PRIMITIVE_TYPES,
        "constants": {name: model.constants[name] for name in model.declared_constants},
        "enums": [
            {
                "name": enum.name,
                "size": enum.size,
                "location": enum.location,
                "enumerators": [without_none(name=e.name, value=e.value, comment=e.comment) for e in enum.enumerators],
            }
            for enum in model.enums.values()
        ],
        "structs": [
            {
                "name": struct.name,
                "kind": struct.kind,
                "size": struct.size,
                "location": struct.location,
                "members": [
                    without_none(
                        name=m.name,
                        type=m.type,
                        offset=m.offset,
                        size=m.size,
                        count=m.count,
                        count_expr=m.count_expr if m.count_expr != str(m.count) else None,
                        bits=m.bits,
                        bit_offset=m.bit_offset,
                        comment=m.comment,
                    )
                    for m in struct.members
                ],
            }
            for struct in model.structs.values()
        ],
    }


def to_json(value: object, indent: int = 0) -> str:
    """JSON with one line per enumerator or member, which keeps the file readable and diffs small."""
    if isinstance(value, dict) and not any(isinstance(v, (dict, list)) for v in value.values()):
        return json.dumps(value)
    pad, inner = " " * indent, " " * (indent + 2)
    if isinstance(value, dict):
        items = [f"{inner}{json.dumps(k)}: {to_json(v, indent + 2)}" for k, v in value.items()]
        return "{\n" + ",\n".join(items) + f"\n{pad}}}" if items else "{}"
    if isinstance(value, list):
        items = [f"{inner}{to_json(v, indent + 2)}" for v in value]
        return "[\n" + ",\n".join(items) + f"\n{pad}]" if items else "[]"
    return json.dumps(value)


def generate_json(model: Model) -> str:
    return to_json(layout_document(model)) + "\n"


def describe_layouts(model: Model) -> str:
    out = []
    for struct in model.structs.values():
        out.append(f"{struct.kind} {struct.name}  size 0x{struct.size:X}")
        out += [f"    {m.offset:04X}  {m.size:4X}  {m.type} {m.declarator}" for m in struct.members]
    return "\n".join(out) + "\n"


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------


def main() -> int:
    arg_parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    arg_parser.add_argument(
        "--root",
        type=Path,
        default=Path(__file__).resolve().parent.parent,
        help="repository root (default: the parent of this script's directory)",
    )
    arg_parser.add_argument(
        "--check", action="store_true", help="write nothing; exit 1 if a committed generated file is out of date"
    )
    arg_parser.add_argument("--no-idc", action="store_true", help="do not write the IDA .idc file")
    arg_parser.add_argument("--verbose", action="store_true", help="print the parsed struct layouts")
    arg_parser.add_argument(
        "--layout-check",
        type=Path,
        metavar="FILE",
        help="only write a C++ file of static_asserts on the struct layouts",
    )
    args = arg_parser.parse_args()

    model = parse(Source([(name, (args.root / name).read_text(encoding=ENCODING)) for name in INPUT_FILES]))

    for warning in model.warnings:
        print(f"warning: {warning}", file=sys.stderr)
    if args.verbose:
        print(describe_layouts(model), end="")

    if args.layout_check:
        write(args.layout_check, generate_layout_check(model))
        return 0

    outputs = {
        Path(CORE_DIR, CORE_HEADER): generate_core_header(model),
        Path(CORE_DIR, CORE_SOURCE): generate_core_source(model),
        Path(QT_DIR, QT_HEADER): generate_qt_header(model),
        Path(QT_DIR, QT_SOURCE): generate_qt_source(model),
        Path(JSON_DIR, JSON_FILE): generate_json(model),
    }

    if args.check:
        stale = [path for path, content in outputs.items() if read_normalized(args.root / path) != content]
        if stale:
            print("Out of date (run: python3 scripts/generate_code.py):", file=sys.stderr)
            for path in stale:
                print(f"    {path.as_posix()}", file=sys.stderr)
            return 1
        return 0

    if not args.no_idc:
        outputs[Path(IDC_DIR, IDC_FILE)] = generate_idc(model)
    for path, content in outputs.items():
        (args.root / path).parent.mkdir(parents=True, exist_ok=True)
        write(args.root / path, content)
    return 0


def write(path: Path, content: str) -> None:
    with open(path, "w", encoding=ENCODING, newline="\n") as file:
        file.write(content)


def read_normalized(path: Path) -> str | None:
    """File contents with LF line endings (a Windows checkout may use CRLF)."""
    try:
        return path.read_text(encoding=ENCODING).replace("\r\n", "\n")
    except OSError:
        return None


if __name__ == "__main__":
    sys.exit(main())
