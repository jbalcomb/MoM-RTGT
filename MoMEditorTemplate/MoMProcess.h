// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#ifndef MOMPROCESS_H
#define MOMPROCESS_H

#include "MoMCommon.h"

namespace MoM {

/// \brief The first data in the Datasegment (DS) of MoM WIZARDS.EXE
const char gDATASEGMENT_IDENTIFIER[] = "\0\0\0\0Borland C++ - Copyright 1991 Borland Intl.";

/// \brief The segment offset of the MoM Datasegment relative to the MoM Codesegment
///        Unit is the paragraph (16 bytes)
// The offset of the DataSegment (DS) in the CODE can be deduced
// from the first machine code instruction(s) in WIZARDS.EXE, which are:
//      mov dx, seg DSEG        ; BA AA 26
//      mov cs:DGROUP@, dx      ; 2E 89 16 C4 02
// Here you can see that the DataSegment is 26AA (relative to CS)
// And also that it is stored in cs:DGROUP which is at offset 0x02CF (relative to CS)
const size_t gOFFSET_WIZARDS_DSEG_CODE = 0x26AA;
const size_t gOFFSET_MAGIC_DSEG_CODE = 0x21D1;


class MoMProcess
{
public:
    MoMProcess(void);
    ~MoMProcess(void);

    void close() throw();

    bool findProcessAndData();

    const uint8_t* getDatasegmentData() const
    {
        if (m_dataSegmentAndUp.empty())
            return 0;
        return &m_dataSegmentAndUp[0];
    }
    uint8_t* getDatasegmentData()
    {
        if (m_dataSegmentAndUp.empty())
            return 0;
        return &m_dataSegmentAndUp[0];
    }

    std::string getExeFilepath();

    size_t getOffset_DS_Code() const
    {
        return (m_dwOffsetDatasegment - m_dwOffsetCode) / gPARAGRAPH_SIZE;
    }

    void* derefPointer(const EXE_Reloc& pointer, size_t size)
    {
        if (m_dataSegmentAndUp.empty())
            return 0;
        uint8_t* pMemory = getDataFromZero() + gPARAGRAPH_SIZE * pointer.segment + pointer.offset;
        if ((pMemory < &m_dataSegmentAndUp[0]) || (pMemory + size > &m_dataSegmentAndUp[0] + m_dataSegmentAndUp.size()))
        {
            // Out of range
            pMemory = 0;
        }
        return pMemory;
    }

    bool isOpen() const
    {
        return (NULL != m_hProcess
            && 0 != m_lpBaseAddress 
            && 0 != m_dwOffsetDatasegment
            && !m_dataSegmentAndUp.empty());
    }

    bool readData();

    bool validPointer(void* pointer, size_t size)
    {
        if (m_dataSegmentAndUp.empty())
            return false;
        uint8_t* pMemory = (uint8_t*)pointer;
        if ((pMemory < &m_dataSegmentAndUp[0]) || (pMemory + size > &m_dataSegmentAndUp[0] + m_dataSegmentAndUp.size()))
        {
            // Out of range
            return false;
        }
        return true;
    }

    bool writeData(const void* pointer, size_t size);

    static void printError(int errorNumber, const std::string& msg);

private:
    bool findSEG0(const std::vector<uint8_t>& data);

    uint8_t* getDataFromZero()
    {
        if (m_dataSegmentAndUp.empty())
            return 0;
        return &m_dataSegmentAndUp[0] - m_dwOffsetDatasegment + m_dwOffsetSegment0;
    }

    static bool readProcessData(void* hProcess, const uint8_t* lpBaseAddress, size_t size, std::vector<uint8_t>& data);

	bool tryWindowTitle(const std::string& windowTitle);

    void* m_hProcess;
    uint8_t* m_lpBaseAddress;
    size_t  m_dwBaseAddressSize;
    size_t  m_dwOffsetSegment0;
    size_t  m_dwOffsetCode;
    size_t  m_dwOffsetDatasegment;
    std::vector<uint8_t> m_dataSegmentAndUp;
    std::string m_exeFilepath;
};

}

#endif
