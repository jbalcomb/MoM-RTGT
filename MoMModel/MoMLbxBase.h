// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#ifndef MOMLBXBASE_H_
#define MOMLBXBASE_H_

#include <vector>

#include "MoMCommon.h"

namespace MoM
{

/// \brief Defines a base class for reading and writing LBX files
class MoMLbxBase
{
public:
    struct Annotation
    {
        char subfile[9];
        char comment[23];
    };

    MoMLbxBase();
    MoMLbxBase(const MoMLbxBase& rhs);
    MoMLbxBase& operator=(const MoMLbxBase& rhs);
    virtual ~MoMLbxBase();

    virtual void close() throw();

    bool load(const std::string& filename);
    bool save(const std::string& filename);

    std::string getFilename() const
    {
        return m_filename;
    }

    size_t getNrRecords() const;
    uint8_t* getRecord(size_t recordNr);
    const uint8_t* getRecord(size_t recordNr) const;
    size_t getRecordSize(size_t recordNr) const;

    size_t getNrSubRecords(size_t recordNr) const;
    const uint8_t* getSubRecord(size_t recordNr, size_t subRecordNr) const;
    uint8_t* getSubRecord(size_t recordNr, size_t subRecordNr);
    bool getSubRecord(size_t recordNr, size_t subRecordNr, std::vector<uint8_t>& subRecordData) const;
    size_t getSubRecordSize(size_t recordNr) const;

    bool replaceRecord(size_t recordNr, const std::vector<uint8_t>& dataBuffer);

private:
    void initPointers();

    std::string             m_filename;
    std::vector<uint8_t>    m_contents;

    LBXHEADER*              m_LBX_Header;
    uint32_t*               m_DataOffsets;
    Annotation*             m_Annotations;
    uint8_t*                m_Data;
};

}

#endif
