#!/usr/bin/env python3
"""Generate code from the game structures in MoMModel/MoMTemplate.h.

Python translation of scripts/generate_code.pl; the output is byte-for-byte the same.

Reads   Platform/MoMCommon.h and MoMModel/MoMTemplate.h
Writes  MoMModel/Generated/MoMGenerated.{h,cpp}     operator<< for every enum
        QMoMCommon/Generated/QMoMGenerated.{h,cpp}  constructTreeItem() for every struct (Qt tree)
        MoMGenerated.idc                            IDA Pro type definitions

Usage (from any directory):
    python3 scripts/generate_code.py            # regenerate the files
    python3 scripts/generate_code.py --check    # exit 1 if a committed file is out of date
    python3 scripts/generate_code.py --verbose  # also print the parse log (as the Perl script did)
"""

import argparse
import os
import re
import sys

INPUTFILE = "MoMTemplate.h"
INPUTFILENAMES = ["Platform/MoMCommon.h", "MoMModel/" + INPUTFILE]
GENDIR = "MoMModel/Generated"
HFILENAME = "MoMGenerated.h"
CPPFILENAME = "MoMGenerated.cpp"
QT_GENDIR = "QMoMCommon/Generated"
QT_HFILENAME = "QMoMGenerated.h"
QT_CPPFILENAME = "QMoMGenerated.cpp"
IDC_GENDIR = "."
IDC_FILENAME = "MoMGenerated.idc"

# The headers are ASCII; latin-1 maps bytes 1:1 like Perl does without an encoding layer.
ENCODING = "latin-1"


# ---------------------------------------------------------------------------
# Perl semantics that the original script relies on
# ---------------------------------------------------------------------------

def perl_eval(expr):
    """Evaluate a C-like integer expression like Perl's eval() under 'use strict'.

    Returns None (Perl: undef) when the expression cannot be evaluated,
    for instance because it contains a bareword.
    """
    if expr is None:
        return None
    if isinstance(expr, (int, float)):
        return expr
    text = str(expr)
    if re.search(r"[A-Za-z_]", re.sub(r"\b0[xX][0-9A-Fa-f]+\b", "", text)):
        return None
    # Perl treats a leading 0 as octal
    text = re.sub(r"\b0([0-7]+)\b", r"0o\1", text)
    if not re.fullmatch(r"[0-9a-fA-FxXo+\-*/%()<>|&^~\s]*", text):
        return None
    try:
        value = eval(text, {"__builtins__": {}}, {})
    except Exception:
        return None
    if isinstance(value, float) and value.is_integer():
        value = int(value)
    return value


def perl_num(value):
    """Numeric value of a scalar like Perl's numification (undef and junk become 0)."""
    if value is None:
        return 0
    if isinstance(value, (int, float)):
        return value
    m = re.match(r"\s*([+-]?\d+)", str(value))
    return int(m.group(1)) if m else 0


def perl_str(value):
    """String value of a scalar like Perl's stringification."""
    if value is None:
        return ""
    if isinstance(value, float) and value.is_integer():
        return str(int(value))
    return str(value)


def perl_split_comma(line):
    """split(/,\\s*/, $line): like re.split, but trailing empty fields are removed."""
    fields = re.split(r",\s*", line)
    while fields and fields[-1] == "":
        fields.pop()
    return fields


def remove_each_match(pattern, text, handle):
    """Mimic Perl's  while (s#pattern##) { handle(...) }

    Each iteration removes the first match from the remaining text and
    searches again from the start, exactly like the Perl loop.
    """
    regex = re.compile(pattern, re.ASCII)
    while True:
        m = regex.search(text)
        if not m:
            return text
        text = text[:m.start()] + text[m.end():]
        handle(m)


# ---------------------------------------------------------------------------
# Parser
# ---------------------------------------------------------------------------

class Parser:
    def __init__(self, log):
        self.constants = {}
        self.enums = {}
        self.struct_unions = {}
        self.log = log

    def parse(self, text):
        # Strip comment and Carriage Returns (if any)
        text = text.replace("\r", "")
        text = re.sub(r"/\*[\s\S]*?\*/", "", text)
        text = re.sub(r"\s*//[^\n]*", "", text, flags=re.ASCII)

        # Collect constants
        def on_constant(m):
            self.constants[m.group(2)] = m.group(3)
        text = remove_each_match(r"\bconst (unsigned|size_t) (\w+) = (\d+);", text, on_constant)

        # Collect enums (includes collecting the enumerators in constants)
        def on_enum(m):
            enumname, enumsizebits, enumbody = m.group(1), m.group(3), m.group(4)
            if "ENUMSIZE" in enumname:
                return
            self.process_enum(enumname, enumsizebits, enumbody)
        text = remove_each_match(r"enum\s+(\w+)\s*(ENUMSIZE(\d+))?[^{]*\{([^}]*)\}[^;]*;", text, on_enum)

        # Collect structs and unions
        def on_struct(m):
            self.process_struct_union(m.group(1), m.group(3), m.group(2))
        text = remove_each_match(r"typedef (struct|union|class)\b[^{]*\{([\s\S]*?\n)\}\s*(\w+);", text, on_struct)

    def process_enum(self, enumname, enumsizebits, enumbody):
        enumsize = 4
        if enumsizebits is not None:
            enumsize = perl_eval(enumsizebits) / 8
            if enumsize.is_integer():
                enumsize = int(enumsize)
        names = []
        values = []
        enumerator_value = -1

        self.log("enumname = %s (%s)\n" % (enumname, perl_str(enumsize)))
        line_regex = re.compile(r"^\s*([^\n]*)\n", re.ASCII)
        while True:
            m = line_regex.match(enumbody)
            if not m:
                break
            enumbody = enumbody[m.end():]
            line = m.group(1)

            # Strip comment and white space
            line = re.sub(r"\s*//\s*(.*)", "", line, count=1, flags=re.ASCII)
            line = re.sub(r"^\s*", "", line, flags=re.ASCII)

            for enumerator in perl_split_comma(line):
                m_assign = re.match(r"^(\w+)\s*=\s*(\S+)$", enumerator, re.ASCII)
                m_name = re.match(r"^(\w+)$", enumerator, re.ASCII)
                if m_assign:
                    enumerator_name, enumerator_value = m_assign.group(1), m_assign.group(2)
                elif m_name:
                    enumerator_name = m_name.group(1)
                    enumerator_value = perl_num(perl_eval(enumerator_value)) + 1
                else:
                    sys.exit("Cannot parse enum '%s' at line '%s'" % (enumname, line))

                names.append(enumerator_name)
                values.append(enumerator_value)
                self.constants[enumerator_name] = enumerator_value

        self.enums[enumname] = {"size": enumsize, "names": names, "values": values}

    def process_struct_union(self, classtype, classname, classbody):
        datamembers = []    # old-style: type, declarator, type, declarator, ...
        memberlist = []
        offset = 0
        countbits = 0
        classsize = None

        self.log("classname = %s\nclassbody = '%s'\n\n" % (classname, classbody))
        decl_regex = re.compile(r"^([^;]*?);[^\n]*\n", re.ASCII)
        while True:
            m = decl_regex.match(classbody)
            if not m:
                break
            classbody = classbody[m.end():]
            declaration = m.group(1)

            # Strip leading and trailing white space
            declaration = re.sub(r"^(\s|\n)+", "", declaration, flags=re.ASCII)
            declaration = re.sub(r"\s+$", "", declaration, flags=re.ASCII)

            m_decl = re.match(r"^([^;]*?)\s*\b(\w+(\[[^\]]*\])*(\s*:\s*\d+)?)$", declaration, re.ASCII)
            if not m_decl:
                continue
            type_, datamember = m_decl.group(1), m_decl.group(2)

            m_member = re.match(r"^(\w+)(\[([^\]]+)\])?(\s*:\s*(\d+))?$", datamember, re.ASCII)
            if not m_member:
                sys.exit("Cannot parse class '%s' at declaration '%s'" % (classname, declaration))
            name, range_, bits = m_member.group(1), m_member.group(3), m_member.group(5)

            rangevalue = None
            if range_ is None:
                pass
            elif range_ in self.constants:
                rangevalue = self.constants[range_]
            else:
                rangevalue = perl_eval(range_)

            typesize = 0
            m_int = re.match(r"^u?int(\d+)_t$", type_, re.ASCII)
            if type_ == "char":
                typesize = 1
            elif m_int:
                typesize = int(m_int.group(1)) // 8
            elif type_ == "DS_Offset":
                typesize = 2
            elif type_ in self.enums:
                typesize = self.enums[type_]["size"]
            elif type_ in self.struct_unions:
                typesize = self.struct_unions[type_]["size"]
            membersize = typesize
            if rangevalue is not None:
                membersize *= perl_num(rangevalue)

            out = "%s\t%s" % (type_, name)
            if rangevalue is not None:
                out += "[%s]" % perl_str(rangevalue)
            if bits is not None:
                out += ":%s" % bits
            out += ";\t// %02X\tsize %03X\n" % (offset, membersize)
            self.log(out)

            # Register data member
            datamembers.extend([type_, datamember])
            member = {
                "type": type_,
                "name": name,
                "offset": offset,
                "typesize": typesize,
                "size": membersize,
            }
            if range_ is not None:
                member["range"] = range_
            if rangevalue is not None:
                member["rangevalue"] = rangevalue
            if bits is not None:
                member["bits"] = bits
                member["bitmask"] = 1 << countbits
            memberlist.append(member)

            if classtype == "union":
                classsize = membersize
            elif bits is not None:
                countbits += int(bits)
            else:
                offset += membersize

        if classtype != "union":
            classsize = offset
        self.log("SIZE %03X\n" % perl_num(classsize))

        self.struct_unions[classname] = {
            "datamembers": datamembers,
            "size": classsize,
            "members": memberlist,
        }


# ---------------------------------------------------------------------------
# Generators. Each returns the file contents as a string.
# ---------------------------------------------------------------------------

def generate_code_h(p, gendir, hfilename):
    out = []
    out.append("// File: %s/%s\n" % (gendir, hfilename))
    out.append("// Generated from: %s\n" % INPUTFILE)
    out.append("\n")
    out.append("#include <iostream>\n")
    out.append("\n")
    out.append("#include \"%s\"\n" % INPUTFILE)
    out.append("\n")
    out.append("namespace MoM {\n")
    out.append("\n")
    for enumname in sorted(p.enums):
        out.append("std::ostream& operator<<(std::ostream& os, const %s& rhs);\n" % enumname)
    out.append("\n")
    out.append("\n")
    out.append("}\n")
    return "".join(out)


def generate_code_cpp(p, gendir, hfilename, cppfilename):
    out = []
    out.append(
        "// File: %s/%s\n" % (gendir, cppfilename) +
        "// Generated from: %s\n" % INPUTFILE +
        "\n"
        "#include <ctype.h>\n"
        "#include <iomanip>\n"
        "#include <sstream>\n"
        "\n"
        "#include \"%s\"\n" % hfilename +
        "\n"
        "#ifdef _MSC_VER                // Compiler MS Visual Studio\n"
        "#pragma warning(disable: 4100) // MSVC: unreferenced formal parameter\n"
        "#endif\n"
        "\n"
        "namespace MoM {\n"
        "\n")

    # Generate ostream operator<<()
    for enumname in sorted(p.enums):
        out.append("std::ostream& operator<<(std::ostream& os, const %s& rhs)\n" % enumname)
        out.append("{\n")
        out.append("    switch (rhs)\n")
        out.append("    {\n")
        for enumvalue in p.enums[enumname]["names"]:
            if "_SIZE__" in enumvalue or "_FIRST" in enumvalue:
                continue
            out.append("    case %s: os << \"%s\"; break;\n" % (enumvalue, enumvalue))
        out.append("    default: os << \"<Unknown %s>\"; break;\n" % enumname)
        out.append("    }\n")
        out.append("    os << \" (\" << (unsigned)rhs << \")\";\n")
        out.append("    return os;\n")
        out.append("}\n")
        out.append("\n")

    out.append("} // namespace\n")
    return "".join(out)


def generate_qt_h(p, gendir, hfilename):
    out = []
    out.append("// File: %s/%s\n" % (gendir, hfilename))
    out.append("// Generated from: %s\n" % INPUTFILE)
    out.append("\n")
    out.append("#include <iostream>\n")
    out.append("\n")
    out.append("#include \"%s\"\n" % INPUTFILE)
    out.append("#include \"QMoMTreeItemModel.h\"\n")
    out.append("\n")
    out.append("namespace MoM {\n")
    out.append("\n")
    for classname in sorted(p.struct_unions):
        out.append("QMoMTreeItemModelBase* constructTreeItem(%s* rhs, const QString& context);\n" % classname)
    out.append("\n")
    out.append("}\n")
    return "".join(out)


def is_int_type(type_):
    return re.search(r"u?int\d+_t", type_, re.ASCII) is not None


def generate_qt_cpp(p, gendir, hfilename, cppfilename):
    out = []
    w = out.append
    w("// File: %s/%s\n" % (gendir, cppfilename))
    w("// Generated from: %s\n" % INPUTFILE)
    w("\n")
    w("#include <ctype.h>\n")
    w("#include <iomanip>\n")
    w("#include <sstream>\n")
    w("\n")
    w("#include <MoMGenerated.h>\n")
    w("\n")
    w("#include \"%s\"\n" % hfilename)
    w("\n")
    w("namespace MoM {\n")
    w("\n")

    # Generate constructTreeItem()
    for classname in sorted(p.struct_unions):
        all_datamembers = p.struct_unions[classname]["datamembers"]

        w("QMoMTreeItemModelBase* constructTreeItem(%s* rhs, const QString& context)\n" % classname)
        w("{\n")
        w("    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<%s>(rhs, context);\n" % classname)
        w("    if (0 == rhs)\n")
        w("        return ptree;\n")
        w("\n")

        for i in range(0, len(all_datamembers) - 1, 2):
            type_, datamember = all_datamembers[i], all_datamembers[i + 1]

            if type_ == "DS_Offset":
                type_ = "uint16_t"
            m = re.match(r"^(\w+)(\[([^\]]+)\])?(\s*:\s*(.*))?$", datamember, re.ASCII)
            name, range_, bitmask = m.group(1), m.group(3), m.group(5)
            display_name = '"%s"' % name
            m_enum = re.match(r"^(e[A-Z][^_]*)_(\w+)$", name, re.ASCII)
            if m_enum:
                display_name = "QMoMResources::instance().getNameSkill(%s::%s)" % (m_enum.group(1), m_enum.group(2))

            if range_ is not None and type_ == "char":
                w("    ptree->appendChild(%s, new QMoMTreeItemModel<char[%s]>(rhs->%s));\n" % (display_name, range_, name))
            elif range_ is not None:
                psubtree = "ptree%s" % name
                w("    QMoMTreeItemModelBase* %s = ptree;\n" % psubtree)
                if len(all_datamembers) > 2:
                    w("    if (%s > 3)\n" % range_)
                    w("    {\n")
                    w("        %s = new QMoMTreeItemModelBase(%s);\n" % (psubtree, display_name))
                    w("        ptree->appendTree(%s, \"\");\n" % psubtree)
                    w("    }\n")
                w("    for (unsigned i = 0; i < %s; ++i)\n" % range_)
                w("    {\n")
                w("          std::ostringstream oss;\n")
                w("          oss << \"%s[\" << i << \"]\";\n" % name)
                if is_int_type(type_) or type_ in p.enums:
                    w("          %s->appendChild(oss.str().c_str(), new QMoMTreeItemModel<%s>(&rhs->%s[i]));\n" % (psubtree, type_, name))
                else:
                    w("          %s->appendTree(constructTreeItem(&rhs->%s[i], oss.str().c_str()), \"\");\n" % (psubtree, name))
                w("    }\n")
            elif is_int_type(type_) and bitmask is not None:
                max_value = 2 ** perl_num(bitmask) - 1
                w("    %s mask%s;\n" % (classname, name))
                w("    memset(&mask%s, '\\0', sizeof(mask%s));\n" % (name, name))
                w("    mask%s.%s = %s;\n" % (name, name, max_value))
                w("    if (1 == sizeof(mask%s))\n" % name)
                w("        ptree->appendChild(%s, new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&mask%s));\n" % (display_name, name))
                w("    else if (2 == sizeof(mask%s))\n" % name)
                w("        ptree->appendChild(%s, new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&mask%s));\n" % (display_name, name))
                w("    else\n")
                w("        ptree->appendChild(%s, new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&mask%s));\n" % (display_name, name))
            elif type_ in p.enums and (type_ + "140m") in p.enums:
                for version, suffix in (("6.0", "60"), ("1.50", "150"), ("1.40m", "140m")):
                    keyword = "if" if suffix == "60" else "else if"
                    w("    %s (QMoMTreeItemModelBase::game()->getMoMVersion() >= std::string(\"%s\"))\n" % (keyword, version))
                    w("    {\n")
                    w("        ptree->appendChild(%s, new QMoMTreeItemModel<%s%s>((%s%s*)&rhs->%s));\n" % (display_name, type_, suffix, type_, suffix, name))
                    w("    }\n")
                w("    else\n")
                w("    {\n")
                w("        ptree->appendChild(%s, new QMoMTreeItemModel<%s>(&rhs->%s));\n" % (display_name, type_, name))
                w("    }\n")
            elif is_int_type(type_) or type_ in p.enums:
                w("    ptree->appendChild(%s, new QMoMTreeItemModel<%s>(&rhs->%s));\n" % (display_name, type_, name))
            else:
                w("    ptree->appendTree(constructTreeItem(&rhs->%s, %s), \"\");\n" % (name, display_name))

        w("    return ptree;\n")
        w("}\n")
        w("\n")

    w("\n")
    w("} // namespace\n")
    return "".join(out)


def generate_idc(p, gendir, idcfilename):
    out = []
    w = out.append
    w("// File: %s/%s\n" % (gendir, idcfilename) +
      "// Generated from: %s\n" % INPUTFILE +
      "\n"
      "//      This file contains the user-defined type definitions.\n"
      "//      To use it press F2 in IDA and enter the name of this file.\n"
      "//\n"
      "\n"
      "#define UNLOADED_FILE   1\n"
      "#include <idc.idc>\n"
      "\n"
      "static main(void)\n"
      "{\n"
      "  Enums();              // enumerations\n"
      "  Structures();         // structure types\n"
      "\tLowVoids(0x20);\n"
      "\tHighVoids(0xF978);\n"
      "}\n"
      "\n"
      "static Enums_0(id) {\n"
      "\n")

    for enumname in sorted(p.enums):
        enum = p.enums[enumname]
        w("    id = AddEnum(-1,\"%s\",0x1100000);\n" % enumname)
        if "bitmask" in enum:
            w("    SetEnumBf(id,1);\n")
        for name, value in zip(enum["names"], enum["values"]):
            if value is None:
                sys.exit("Can't find value for '%s' '%s'" % (enumname, name))
            bitmask_value = value if "bitmask" in enum else -1
            w("    AddConstEx(id,\"%s\",\t%s,\t%s);\n" % (name, perl_str(value), perl_str(bitmask_value)))

    w("\n"
      "\treturn id;\n"
      "}\n"
      "\n"
      "//------------------------------------------------------------------------\n"
      "// Information about enum types\n"
      "\n"
      "static Enums(void) {\n"
      "        auto id;\n"
      "\tid = Enums_0(id);\n"
      "}\n"
      "\n"
      "static Structures_0(id) {\n"
      "        auto mid;\n"
      "\n")

    for classname in sorted(p.struct_unions):
        w("    id = AddStrucEx(-1,\"%s\",0);\n" % classname)
    w("\n")

    # IDA member flags:
    #   0x000400 struct-field (always on)   0x800000 enum-byte / char
    #   0x10000000 dw   0x20000000 dd       0x60000000 struct
    for classname in sorted(p.struct_unions):
        w("    id = GetStrucIdByName(\"%s\");\n" % classname)
        for member in p.struct_unions[classname]["members"]:
            name = member["name"]
            offset = member["offset"]
            type_ = member["type"]
            size = member["size"]
            idcflags = 0x000400
            idctype = "-1"

            if type_ == "char":
                idctype = "0x0"
                idcflags |= 0x800000
            elif type_ in p.enums:
                idctype = "GetEnum(\"%s\")" % type_
                idcflags |= 0x800000
            elif type_ in p.struct_unions:
                idctype = "GetStrucIdByName(\"%s\")" % type_
                idcflags |= 0x60000000

            if re.match(r"^u?int16_t", type_, re.ASCII) or (type_ in p.enums and p.enums[type_]["size"] == 2):
                idcflags |= 0x10000000
            elif re.match(r"^u?int32_t", type_, re.ASCII):
                idcflags |= 0x20000000

            if type_ == "DS_Offset":
                w("    mid = AddStrucMember(id,\"%s\",\t0X%X,\t0x10500400,\t0X36AA0,\t2,\t0XFFFFFFFF,\t0X0,\t0x000002);\n"
                  % (name, offset))
            else:
                w("    mid = AddStrucMember(id,\"%s\",\t0X%X,\t0X%06X,\t%s,\t%s);\n"
                  % (name, offset, idcflags, idctype, perl_str(size)))

    w("\treturn id;\n"
      "}\n"
      "\n"
      "//------------------------------------------------------------------------\n"
      "// Information about structure types\n"
      "\n"
      "static Structures(void) {\n"
      "        auto id;\n"
      "\tid = Structures_0(id);\n"
      "}\n"
      "\n"
      "// End of file.\n")
    return "".join(out)


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    script_dir = os.path.dirname(os.path.abspath(__file__))
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--root", default=os.path.dirname(script_dir),
                        help="repository root (default: the parent of this script's directory)")
    parser.add_argument("--check", action="store_true",
                        help="do not write; exit 1 if a generated source file differs from the committed one")
    parser.add_argument("--no-idc", action="store_true", help="do not generate the IDA .idc file")
    parser.add_argument("--verbose", action="store_true", help="print the parse log")
    args = parser.parse_args()

    log = sys.stdout.write if args.verbose else (lambda text: None)

    text = ""
    for inputfilename in INPUTFILENAMES:
        with open(os.path.join(args.root, inputfilename), encoding=ENCODING, newline="") as fh:
            text += fh.read()

    p = Parser(log)
    p.parse(text)

    outputs = [
        (GENDIR, HFILENAME, generate_code_h(p, GENDIR, HFILENAME)),
        (GENDIR, CPPFILENAME, generate_code_cpp(p, GENDIR, HFILENAME, CPPFILENAME)),
        (QT_GENDIR, QT_HFILENAME, generate_qt_h(p, QT_GENDIR, QT_HFILENAME)),
        (QT_GENDIR, QT_CPPFILENAME, generate_qt_cpp(p, QT_GENDIR, QT_HFILENAME, QT_CPPFILENAME)),
    ]
    if not args.no_idc and not args.check:
        outputs.append((IDC_GENDIR, IDC_FILENAME, generate_idc(p, IDC_GENDIR, IDC_FILENAME)))

    stale = []
    for gendir, filename, content in outputs:
        path = os.path.join(args.root, gendir, filename)
        if args.check:
            try:
                with open(path, encoding=ENCODING, newline="") as fh:
                    current = fh.read()
            except OSError:
                current = None
            if current != content:
                stale.append(os.path.join(gendir, filename))
        else:
            with open(path, "w", encoding=ENCODING, newline="") as fh:
                fh.write(content)

    if stale:
        sys.stderr.write("Out of date (run: python3 scripts/generate_code.py):\n")
        for path in stale:
            sys.stderr.write("    %s\n" % path)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
