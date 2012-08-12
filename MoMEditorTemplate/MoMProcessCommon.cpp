// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string.h>     // memcmp()

#include "MoMProcess.h"
#include "MoMUtility.h"

namespace MoM
{

namespace
{

const uint8_t gCS_SIGNATURE_BYTE = '\xBA';
const uint8_t gCS_SIGNATURE_SEQUENCE[5] = { 0x2E, 0x89, 0x16, 0xC4, 0x02 };

}

bool MoMProcess::findSEG0(const std::vector<uint8_t>& data)
{
    size_t offset_DS_Code = 0;
    if ((m_dwOffsetDatasegment >= gOFFSET_WIZARDS_DSEG_CODE * gPARAGRAPH_SIZE) 
        && (gCS_SIGNATURE_BYTE == data[ m_dwOffsetDatasegment - gOFFSET_WIZARDS_DSEG_CODE * gPARAGRAPH_SIZE ]))
    {
        offset_DS_Code = gOFFSET_WIZARDS_DSEG_CODE;
    }
    else if ((m_dwOffsetDatasegment >= gOFFSET_MAGIC_DSEG_CODE * gPARAGRAPH_SIZE) 
        && (gCS_SIGNATURE_BYTE == data[ m_dwOffsetDatasegment - gOFFSET_MAGIC_DSEG_CODE * gPARAGRAPH_SIZE ]))
    {
        offset_DS_Code = gOFFSET_MAGIC_DSEG_CODE;
    }
    else
    {
        return false;
    }

    m_dwOffsetCode = m_dwOffsetDatasegment - offset_DS_Code * gPARAGRAPH_SIZE;

    uint8_t* ptrCode = (uint8_t*)&data[m_dwOffsetCode];

    // Check Borland CS signature code: BA ?? ?? 2E 89 16 C4 02
    if (0 != memcmp(&ptrCode[3], gCS_SIGNATURE_SEQUENCE, sizeof(gCS_SIGNATURE_SEQUENCE)))
    {
        return false;
    }

    size_t offsetDStoSegment0 = *(uint16_t*)&ptrCode[1];
    std::cout << "Found MoM Data Segment (DS_SEG0) Offset as " << std::hex << offsetDStoSegment0 << ":0" << std::dec << std::endl;
    std::cout << "Hex sequence was:" << std::hex << std::setfill('0');
    for (size_t i = 0; i < 8; ++i)
    {
        std::cout << ' ' << std::setw(2) << (unsigned)ptrCode[i];
    }
    std::cout << std::dec << std::endl;
    offsetDStoSegment0 *= gPARAGRAPH_SIZE;

    if (m_dwOffsetDatasegment < offsetDStoSegment0)
    {
        return false;
    }

    m_dwOffsetSegment0 = m_dwOffsetDatasegment - offsetDStoSegment0;

    return true;
}

bool MoMProcess::readData()
{
//    std::cout << "MoMProcess::readData()" << std::endl;
    if (NULL == m_hProcess)
        return false;
    if (0 == m_lpBaseAddress)
        return false;
    if (0 == m_dwOffsetDatasegment)
        return false;
    if (m_dwOffsetDatasegment >= m_dwBaseAddressSize)
        return false;

    size_t size = m_dwBaseAddressSize - m_dwOffsetDatasegment;

    bool ok = readProcessData(m_hProcess, m_lpBaseAddress + m_dwOffsetDatasegment, size, m_dataSegmentAndUp);

    // Check if we're still the same executable
    if (ok)
    {
        std::vector<uint8_t> signature;
        size_t sizeSignature = 4;
        ok = readProcessData(m_hProcess, m_lpBaseAddress + m_dwOffsetCode, sizeSignature, signature);
        if (ok)
        {
            ok = (gCS_SIGNATURE_BYTE == signature[0]);
        }
        if (ok)
        {
            size_t offsetDStoSegment0 = (m_dwOffsetDatasegment - m_dwOffsetSegment0) / MoM::gPARAGRAPH_SIZE;
            ok = (*(uint16_t*)&signature[1] == offsetDStoSegment0);
        }
    }

    return ok;
}

bool MoMProcess::load(const char *filename)
{
    std::ifstream ifs(filename, std::ios_base::binary);

    bool ok = ifs.good();

    // TODO: Try and get updating the MoM memory to work (now DOSBox plunks out of existance)
    //       For now: break the connection with a quick hack
    if (ok)
    {
        m_lpBaseAddress = NULL;
    }

    // TODO: Check mismatch in size
    if (ok)
    {
        ifs.read(reinterpret_cast<char*>(&m_dataSegmentAndUp[0]), m_dataSegmentAndUp.size());
        ok = ifs.good();
    }

//    if (ok)
//    {
//        ok = writeData(&m_dataSegmentAndUp[0], m_dataSegmentAndUp.size());
//    }

    return ok;
}

bool MoMProcess::save(const char *filename)
{
    std::ofstream ofs(filename, std::ios_base::binary);

    ofs.write(reinterpret_cast<const char*>(&m_dataSegmentAndUp[0]), m_dataSegmentAndUp.size());

    return ofs.good();
}

}
