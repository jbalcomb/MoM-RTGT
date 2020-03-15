// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#pragma once

#include "MoMLbxBase.h"
#include "MoMTemplate.h"

namespace MoM
{

inline Spell_Data* getLbxSpellData(MoM::MoMLbxBase& lbx)
{
    const auto* data = lbx.getRecord(0);
    auto size = lbx.getRecordSize(0);
    if (data == nullptr)
        return nullptr;
    auto* spellData = (Spell_Data*)(data + 4);
    if ((uint8_t*)spellData + eSpell_MAX * sizeof(Spell_Data) > data + size)
        return nullptr;
    return spellData;
}

struct MoMImageBuffer { uint8_t* pointer = 0; size_t size = 0; };

inline std::vector<std::vector<std::vector<MoMImageBuffer>>> getLbxTerrainData(MoM::MoMLbxBase& lbx)
{
    // TODO: Check if size fits

    // TODO: Why does the bitmap data in TERRAIN.LBX start 192 bytes later
    uint8_t* data = lbx.getRecord(0) + 192;
    uint8_t* ptrLbx1 = lbx.getRecord(1);
    std::vector<std::vector<std::vector<MoMImageBuffer>>> terrainAnimations(
                ePlane_MAX,
                std::vector<std::vector<MoMImageBuffer>>(eTerrainType_MAX));
    for (size_t terrainNr = 0; terrainNr < (int)MoM::eTerrainType_MAX; ++terrainNr)
    {
        // TODO: How do I know that the bitmap data in TERRAIN.LBX has actually
        //       fixed-size subrecords of 0x0180 bytes each?
        // TODO: How do I know that these records contain uncompressed data?

        // Arcanum
        uint16_t loByte = ptrLbx1[2 * terrainNr];
        uint16_t hiByte = ptrLbx1[2 * terrainNr + 1];
        size_t sizeImage = 0x180;
        int nrImages = 1;
        if (0 != (loByte & 0x80))
        {
            nrImages = 4;  // Animation of 4 frames
        }
        loByte &= 0x7F;
        unsigned terrainPicIndex = hiByte;
        unsigned offset = 0x4000 * loByte + sizeImage * hiByte - 2 * sizeImage;

        auto& terrainAnimationArcanum = terrainAnimations[PLANE_Arcanum][terrainNr];
        terrainAnimationArcanum.resize(nrImages);
        for (int imageNr = 0; imageNr < nrImages; ++imageNr)
        {
            terrainAnimationArcanum[imageNr] = { data + offset + imageNr * sizeImage, sizeImage };
        }

        // Myrror
        loByte = ptrLbx1[2 * (762 + terrainNr)];
        hiByte = ptrLbx1[2 * (762 + terrainNr) + 1];
        sizeImage = 0x180;
        nrImages = 1;
        if (0 != (loByte & 0x80))
        {
            nrImages = 4;  // Animation of 4 frames
        }
        loByte &= 0x7F;
        terrainPicIndex = hiByte;
        offset = 0x4000 * loByte + sizeImage * hiByte - 2 * sizeImage;

        auto& terrainAnimationMyrror = terrainAnimations[PLANE_Arcanum][terrainNr];
        terrainAnimationMyrror.resize(nrImages);
        for (int imageNr = 0; imageNr < nrImages; ++imageNr)
        {
            terrainAnimationMyrror[imageNr] = { data + offset + imageNr * sizeImage, sizeImage };
        }
    }
    return terrainAnimations;
}

}
