---
title: Shared knowledge with Simtex Universe and ReMoM
---

# Shared knowledge: MoM-RTGT, ReMoM and Simtex Universe

[← Home](index.md)

Three projects describe the same bytes:

| Project | What it knows | Form |
|---|---|---|
| **MoM-RTGT** | Packed C structs for the data segment, save game, unit/spell/building tables; overlay offsets of patch sites; LBX record types | `MoMModel/MoMTemplate.h`, `Platform/MoMCommon.h`, generated `MoMGenerated.idc`, `xml/momrtgt.xml` (unused) |
| **ReMoM** | A complete C reconstruction of WIZARDS.EXE and MAGIC.EXE v1.31 with `dseg` and segment/overlay annotations; LBX, VOC and XMI format docs | `MoX/src/MOM_DAT.h/.c`, `doc/WZD-Segments.md`, `doc/___LBX/*.md`, `doc/Audio/*`, `doc/simtex_lbx_v131.hexpat`, `doc/spell_data_table.json` |
| **STU-Simtex_Universe** | Intended home for community documentation (LBX library, manager, browser) | headings only so far |

## Naming and addressing differ

| Concept | MoM-RTGT | ReMoM |
|---|---|---|
| Data segment address | `dseg:9296`, DS-relative offsets | `// WZD dseg:50AC` |
| Code location | `ovr114`, file offset `0x889E4` | `// WZD o114p03` (overlay / procedure), `sNNpNN` (segment / procedure) |
| Executables | `WIZARDS.EXE`, `MAGIC.EXE` | `WZD`, `MGC` |
| Unit type record | `Unit_Type_Data` | `s_UNIT_TYPE` (sizeof 0x24) |

The address calculator (`DialogCalculatorAddress`) already converts between EXE file
offset, segment:offset and memory offset. That logic belongs in the shared library too.

## Proposal: one machine-readable layout

```mermaid
flowchart LR
  SRC["STU layout files (YAML / JSON)<br/>per exe + version:<br/>segments, overlays, dseg symbols,<br/>structs & fields, enums, LBX catalogue"]
  SRC --> GEN[[generator]]
  GEN --> H1["MoM-RTGT<br/>MoMTemplate.h + ImGui editors"]
  GEN --> H2["ReMoM<br/>cross-check MOM_DAT.h offsets"]
  GEN --> IDC["IDA .idc / Ghidra script /<br/>ImHex .hexpat"]
  GEN --> WEB["GitHub Pages reference<br/>(searchable tables)"]
```

1. Start by **exporting** what RTGT already has. `generate_code.pl` parses
   `MoMTemplate.h`, so it can emit JSON (struct name, field, type, offset, size, enum)
   as easily as it emits `.idc`.
2. Compare that export with ReMoM's `MOM_DAT.h` offsets. Mismatches are either RTGT
   errors, version differences (1.31 vs 1.40n) or ReMoM naming gaps, and each one is
   worth knowing.
3. Make the STU repository the home of the reconciled data and its Pages site. RTGT and
   ReMoM consume it: generated headers in RTGT, verification tests in ReMoM.

**Open questions:** which name wins when the projects disagree (ReMoM's names follow the
disassembly, RTGT's follow community usage)? Which game versions does the shared data
cover? Should STU stay a separate repository or become a folder inside ReMoM?
