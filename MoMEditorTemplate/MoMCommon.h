// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file
/// \brief  Common structures for mapping memory of (Borland) executable files
///         and of LBX files

#ifndef MOMCOMMON_H
#define MOMCOMMON_H

#include <assert.h>     // assert()
#include <iostream>
#include <map>
#include <memory>       // std::auto_ptr
#include <sstream>
#include <vector>


// Specify integer types with specific sizes
#ifdef _MSC_VER         // Compiler MS Visual Studio (no proper POSIX)
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
#else
#include <stdint.h>     // POSIX
#endif


// Specify to pack structures
#ifdef _MSC_VER         // Compiler MS Visual Studio
//#pragma warning( once : 4103 )  // alignment changed after including header, may be due to missing #pragma #pragma pack(1)
#pragma pack(push, 1)
#define PACKED_STRUCT
#endif

#ifdef __MINGW_GCC  // Compiler MinGW
#pragma pack(push, 1)
#define PACKED_STRUCT __attribute__((packed))
#endif

#ifdef __GNUC__         // Compiler g++
#define PACKED_STRUCT __attribute__((packed))
#endif

namespace MoM {

/// \brief The paragraph size used in the i386 architecture
///        It defines the unit of a segment address
const size_t gPARAGRAPH_SIZE = 16;

/// \brief The block size used in the i386 architecture
///        It is used in the EXE_Header to define where the Extra Data starts
const size_t gBLOCK_SIZE = 512;

/// \brief The layout of an EXE Header on the DOS platform
typedef struct PACKED_STRUCT // EXE_Header
{
  uint16_t signature;                       // 00 == 0x5a4D == "MZ"
  uint16_t bytes_in_last_block;             // 02 blocks are 512 bytes
  uint16_t blocks_in_file;                  // 04 blocks are 512 bytes
  uint16_t nr_relocation_items;             // 06 Number of items to relocate when loading offset is known
  uint16_t load_module_offset_paragraphs;   // 08 paragraph is 16 bytes, offset to Load Module
  uint16_t min_needed_paragraphs;           // 0A min # of paragraphs needed to run program
  uint16_t max_needed_paragraphs;           // 0C max # of paragraphs the program would like
  uint16_t ss_offset_in_load_module_paragraphs; // 0E offset in load module of stack segment (in paragraphs)
  uint16_t sp_initial;                      // 10
  uint16_t checksum;                        // 12
  uint16_t ip_program_entry_point;          // 14
  uint16_t cs_offset_in_load_module_paragraphs; // 16 offset in load module of the code segment (in paragraphs)
  uint16_t relocation_table_offset_bytes;   // 18 offset in .EXE file of first relocation item
  uint16_t overlay_number;                  // 1A overlay number (0 for root program)
                                            // 1C
} EXE_Header;

//
//The offset of the beginning of the EXE data is computed like this:
//
//exe_data_start = exe.header_paragraphs * 16L;
//
//The offset of the byte just after the EXE data (in DJGPP, the size of the stub and the start of the COFF image) is computed like this:
//
//extra_data_start = exe.blocks_in_file * 512L;
//if (exe.bytes_in_last_block)
//  extra_data_start -= (512 - exe.bytes_in_last_block);


/// \brief The layout of an DOS relocation unit (a far pointer)
typedef struct PACKED_STRUCT // EXE_Reloc
{
  uint16_t offset;
  uint16_t segment;
} EXE_Reloc;

/// \brief Typedef for a field representing an offset in the datasegment
typedef uint16_t DS_Offset;

typedef struct PACKED_STRUCT // BorlandSegmentEntry
{
    uint16_t    base;
    uint16_t    size;
    uint16_t    type;
    uint16_t    offset;
} BorlandSegmentEntry;

typedef struct PACKED_STRUCT // BorlandStubJmpEntry
{
    //          EA <offset> <base-addr> ; jmp <base-addr>:<offset>
    uint8_t     jmpfar_code;
    uint16_t    offset;
    uint16_t    base_addr;
} BorlandStubJmpEntry;

typedef struct PACKED_STRUCT // BorlandStub
{
    uint8_t     int_code[2];        // 00   CD 3F    ; int 3F
    uint16_t    memswap;            // 02
    uint32_t    fileoff;            // 04   Relative to first overlay
    uint16_t    codesize;           // 08
    uint16_t    relsize;            // 0A
    uint16_t    nentries;           // 0C   Number of jmp-entries
    uint16_t    prevstub;           // 0E
    uint8_t     workarea[0x10];     // 10
    BorlandStubJmpEntry entries[1]; // 20   Array of jmp-entries, each of size 5
                                    //      EA <offset> <base-addr> ; jmp <base-addr>:<offset>
} BorlandStub;

typedef struct PACKED_STRUCT {   // LBXHEADER
    uint16_t    n;                  // 00
    uint32_t    magic_number;       // 02: AD FE 00 00
    uint16_t    reserved;           // 06
                                    // SIZE 08
} LBXHEADER;

}

#ifdef _MSC_VER         // Compiler MS Visual Studio
#pragma pack(pop)
#endif
#ifdef __MINGW_GCC  // Compiler MinGW
#pragma pack(pop)
#endif

#undef PACKED_STRUCT

#endif
