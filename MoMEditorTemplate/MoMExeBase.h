// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#ifndef MOMEXEBASE_H
#define MOMEXEBASE_H

#include "MoMCommon.h"

namespace MoM {

class MoMExeBase
{
public:
    MoMExeBase();
    virtual ~MoMExeBase()
    {
        close();
    }

    virtual void close() throw();

    bool convertExeOffset_to_OvlOffset(size_t exeOffset, size_t& ovlNr, uint16_t& ovlOffset);
    bool convertOvlOffset_to_ExeOffset(size_t ovlNr, uint16_t ovlOffset, size_t& exeOffset);
    bool convertExeOffset_to_DsegOffset(size_t exeOffset, uint16_t& dsegOffset);
    bool convertDsegOffset_to_ExeOffset(uint16_t dsegOffset, size_t& exeOffset);

    bool load(const std::string& filename);

    bool save(const std::string& filename);

    void setOverlayParameters(size_t offsetStubSegmentEntries, size_t nrStubSegments, size_t firstStubNr);

    bool writeData(const void* ptr, const void* pNewValue, size_t size);

    EXE_Header* getExeHeader()
    {
        return m_EXE_Header;
    }

    std::string getFilename() const
    {
        return m_filename;
    }

    uint8_t* getDataSegment()
    {
        return m_DataSegment;
    }

    uint8_t* getOverlay(size_t ovlNr);

    uint8_t* getExeContents()
    {
        if (m_contents.empty())
            return 0;
        return &m_contents[0];
    }

    size_t getExeSize() const
    {
        return m_contents.size();
    }

private:

    void initializeStubs();

    // NOT IMPLEMENTED
    MoMExeBase(const MoMExeBase& rhs);
    MoMExeBase& operator=(const MoMExeBase& rhs);

    // STATUS

    std::string             m_filename;
    std::vector<uint8_t>    m_contents;
    std::vector<BorlandStub*>    m_Stubs;

    EXE_Header*             m_EXE_Header;
    EXE_Reloc*              m_EXE_Reloc;
    uint8_t*                m_Load_Module;
    BorlandSegmentEntry*    m_StubSegments;
    uint8_t*                m_DataSegment;
    char*                   m_BorlandIdentifier;
    uint8_t*                m_StackSegment;
    uint8_t*                m_Overlays;

    // CONFIG

    size_t                  m_offsetStubSegmentEntries;
    size_t                  m_nrStubSegments;
    size_t                  m_firstStubNr;
};

}

#endif
