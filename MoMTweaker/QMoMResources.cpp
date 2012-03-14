// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2011-09-30
// ---------------------------------------------------------------------------

#include <string>

#include <MoMGameBase.h>
#include <MoMGenerated.h>
#include <MoMLbxBase.h>
#include <MoMutility.h>
#include <QMoMCommon.h>

#include "QMoMResources.h"

namespace MoM
{

QMoMResources* QMoMResources::m_instance = 0;

QMoMResources::QMoMResources(MoM::MoMGameBase* game)
{
    if (m_colorTable.empty())
    {
        (void)createColorTable(game);
    }
    if (m_buildingImages.empty())
    {
        (void)createBuildingImages(game);
    }
    if (m_itemImages.empty())
    {
        (void)createItemImages(game);
    }
    if (m_lairImages.empty())
    {
        (void)createLairImages(game);
    }
    if (m_unitImages.empty())
    {
        (void)createUnitImages(game);
    }
    if (m_spellImages.empty())
    {
        // UnitImages should already have been created, because SpellImages uses them
        (void)createSpellImages(game);
    }
    if (m_terrainTypeImages.empty())
    {
        (void)createTerrainImages(game);
    }
}

QMoMResources::~QMoMResources()
{
}

bool QMoMResources::createColorTable(MoM::MoMGameBase* game)
{
    if (0 == game)
        return false;
    m_colorTable.resize(256);
    std::string fontsLbxFile = game->getGameDirectory() + "/" + "FONTS.LBX";
    MoM::MoMLbxBase fontsLbx;
    if (!fontsLbx.load(fontsLbxFile))
        return false;

    uint8_t* dataPalette = fontsLbx.getRecord(2);
    MoM::convertLbxToPalette(dataPalette, m_colorTable);

    return true;
}

bool QMoMResources::createBuildingImages(MoM::MoMGameBase* game)
{
    if (0 == game)
        return false;
    std::string lbxFile = game->getGameDirectory() + "/" + "CITYSCAP.LBX";
    MoM::MoMLbxBase lbx;
    if (!lbx.load(lbxFile))
        return false;
    m_buildingImages.resize(lbx.getNrRecords());
    for (MoM::eBuilding building = (MoM::eBuilding)1; building < MoM::eBuilding_MAX; MoM::inc(building))
    {
        size_t recordNr = 45 + building - MoM::BUILDING_Barracks;
        if (MoM::BUILDING_Trade_Goods == building)
        {
            recordNr = 41;
        }
        else if (MoM::BUILDING_Housing == building)
        {
            recordNr = 42;
        }
        else if (MoM::BUILDING_Foresters_Guild == building)
        {
            recordNr = 78;
        }
        else if (MoM::BUILDING_City_Walls == building)
        {
            recordNr = 114;
        }
        else if (building > MoM::BUILDING_Foresters_Guild)
        {
            recordNr--;
        }
        else
        {
        }
        m_buildingImages[building] = MoM::convertLbxToImage(lbx.getRecord(recordNr), m_colorTable, toStr(building));
    }
    return true;
}

bool QMoMResources::createItemImages(MoM::MoMGameBase* game)
{
    if (0 == game)
        return false;
    std::string itemsLbxFile = game->getGameDirectory() + "/" + "ITEMS.LBX";
    MoM::MoMLbxBase itemsLbx;
    if (!itemsLbx.load(itemsLbxFile))
        return false;
    m_itemImages.resize(itemsLbx.getNrRecords());
    for (size_t i = 0; i < itemsLbx.getNrRecords(); ++i)
    {
        m_itemImages[i] = MoM::convertLbxToImage(itemsLbx.getRecord(i), m_colorTable, toStr((MoM::eItem_Icon)i));
//        QImageWriter w(QString("item%0.png").arg(i));
//        w.write(m_itemImages[i]);
    }
    return true;
}

bool QMoMResources::createLairImages(MoM::MoMGameBase* game)
{
    if (0 == game)
        return false;
    std::string lairsLbxFile = game->getGameDirectory() + "/" + "RELOAD.LBX";
    MoM::MoMLbxBase lairsLbx;
    if (!lairsLbx.load(lairsLbxFile))
        return false;
    m_lairImages.resize(MoM::eTower_Node_Lair_Type_MAX);
    for (size_t i = 0; i < MoM::eTower_Node_Lair_Type_MAX; ++i)
    {
        m_lairImages[i] = MoM::convertLbxToImage(lairsLbx.getRecord(9 + i), m_colorTable, toStr((MoM::eTower_Node_Lair_Type)i));
    }
    return true;
}

bool QMoMResources::createSpellImages(MoM::MoMGameBase* game)
{
    // PRE: UnitImages should already have been created, because SpellImages uses them

    if (0 == game)
        return false;
    std::string cityscapLbxFile = game->getGameDirectory() + "/" + "CITYSCAP.LBX";
    std::string monsterLbxFile = game->getGameDirectory() + "/" + "MONSTER.LBX";
    std::string specfxLbxFile = game->getGameDirectory() + "/" + "SPECFX.LBX";
    MoM::MoMLbxBase cityscapLbx;
    MoM::MoMLbxBase monsterLbx;
    MoM::MoMLbxBase specfxLbx;
    if (!cityscapLbx.load(cityscapLbxFile))
        return false;
    if (!monsterLbx.load(monsterLbxFile))
        return false;
    if (!specfxLbx.load(specfxLbxFile))
        return false;

    m_spellImages.resize(MoM::eSpell_MAX);

    // MONSTER.LBX, UNITS1.LBX, UNITS2.LBX
    MoM::Spell_Data* spellDataArray = game->getSpell_Data();
    for (MoM::eSpell spell = (MoM::eSpell)0; (0 != spellDataArray) && (spell < MoM::eSpell_MAX); MoM::inc(spell))
    {
        MoM::Spell_Data* spellData = &spellDataArray[spell];
        if ((MoM::SPELLTYPE_Summoning == spellData->m_Section_in_spell_book))
        {
            m_spellImages[spell] = m_unitImages[spellData->m_Unit_Summoned_or_Spell_Strength];
        }
    }

    MoM::eSpell spell;

    // CITYSCAP.LBX
    spell = MoM::SPELL_Summoning_Circle;
    m_spellImages[spell] = MoM::convertLbxToImage(cityscapLbx.getRecord(6), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Altar_of_Battle;
    m_spellImages[spell] = MoM::convertLbxToImage(cityscapLbx.getRecord(12), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Dark_Rituals;
    m_spellImages[spell] = MoM::convertLbxToImage(cityscapLbx.getRecord(81), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Earth_Gate;
    m_spellImages[spell] = MoM::convertLbxToImage(cityscapLbx.getRecord(83), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Stream_of_Life;
    m_spellImages[spell] = MoM::convertLbxToImage(cityscapLbx.getRecord(84), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Astral_Gate;
    m_spellImages[spell] = MoM::convertLbxToImage(cityscapLbx.getRecord(85), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Spell_Ward;
    m_spellImages[spell] = MoM::convertLbxToImage(cityscapLbx.getRecord(96), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Inspirations;
    m_spellImages[spell] = MoM::convertLbxToImage(cityscapLbx.getRecord(100), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Prosperity;
    m_spellImages[spell] = MoM::convertLbxToImage(cityscapLbx.getRecord(101), m_colorTable, toStr(spell));
//    spell = MoM::SPELL_; // Mana cross
//    m_spellImages[spell] = MoM::convertLbxToImage(cityscapLbx.getRecord(102), m_colorTable, toStr(spell));

    // MONSTER.LBX
    spell = MoM::SPELL_Summon_Hero;
    m_spellImages[spell] = MoM::convertLbxToImage(monsterLbx.getRecord(45), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Summon_Champion;
    m_spellImages[spell] = MoM::convertLbxToImage(monsterLbx.getRecord(44), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Enchant_Item;
    m_spellImages[spell] = MoM::convertLbxToImage(monsterLbx.getRecord(46), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Create_Artifact;
    m_spellImages[spell] = MoM::convertLbxToImage(monsterLbx.getRecord(46), m_colorTable, toStr(spell));

    // SPECFX.LBX
    spell = MoM::SPELL_Eternal_Night;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(15), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Evil_Omens;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(16), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Zombie_Mastery;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(17), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Aura_of_Majesty;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(18), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Wind_Mastery;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(19), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Suppress_Magic;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(20), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Time_Stop;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(21), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Nature_Awareness;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(22), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Natures_Wrath;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(23), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Herb_Mastery;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(24), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Chaos_Surge;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(25), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Doom_Mastery;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(26), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Great_Wasting;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(27), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Meteor_Storm;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(28), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Armageddon;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(29), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Tranquility;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(30), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Life_Force;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(31), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Crusade;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(32), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Just_Cause;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(33), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Holy_Arms;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(34), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Planar_Seal;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(35), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Charm_of_Life;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(36), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Detect_Magic;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(37), m_colorTable, toStr(spell));

    spell = MoM::SPELL_Death_Wish;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(38), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Great_Unsummoning;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(39), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Awareness;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(56), m_colorTable, toStr(spell));

    return true;
}

bool QMoMResources::createTerrainImages(MoM::MoMGameBase* game)
{
    if (0 == game)
        return false;
    std::string terrainLbxFile = game->getGameDirectory() + "/" + "TERRAIN.LBX";
    MoM::MoMLbxBase terrainLbx;
    if (!terrainLbx.load(terrainLbxFile))
        return false;
    // TODO: Why does the bitmap data in TERRAIN.LBX start 192 bytes later
    uint8_t* data = terrainLbx.getRecord(0) + 192;
    m_terrainTypeImages.resize(2 * MoM::eTerrainType_MAX);
    for (size_t terrainNr = 0; terrainNr < (int)MoM::eTerrainType_MAX; ++terrainNr)
    {
        // TODO: How do I know that the bitmap data in TERRAIN.LBX has actually
        //       fixed-size subrecords of 0x0180 bytes each?
        // TODO: How do I know that these records contain uncompressed data?

        size_t i = 0;

        // Arcanum
        if (terrainNr < 18)
        {
            i = terrainNr;
        }
        else if (terrainNr < 19)
        {
            i = 18 + (terrainNr - 18) * 4;
        }
        else if (terrainNr < 31)
        {
            i = 22 + (terrainNr - 19);
        }
        else if (terrainNr < 50)
        {
            i = 34 + (terrainNr - 31) * 4;
        }
        else if (terrainNr < 54)
        {
            i = 110 + (terrainNr - 50);
        }
        else if (terrainNr < 55)
        {
            i = 114 + (terrainNr - 54) * 4;
        }
        else if (terrainNr < 146)
        {
            i = 118 + (terrainNr - 55);
        }
        else if (terrainNr < 162)
        {
            i = 209 + (terrainNr - 146) * 4;
        }
        else if (terrainNr < 0xA8)
        {
            i = 273 + (terrainNr - 0xA2);
        }
        else if (terrainNr < 0xAB)
        {
            i = 279 + (terrainNr - 0xA8) * 4;
        }
        else if (terrainNr < 0xB3)
        {
            i = 291 + (terrainNr - 0xAB);
        }
        else if (terrainNr < 0xB4)
        {
            i = 299 + (terrainNr - 0xB3) * 4;
        }
        else if (terrainNr < 601)
        {
            i = 303 + (terrainNr - 0xB4);
        }
        else if (terrainNr < 602)
        {
            i = 724 + (terrainNr - 601) * 4;
        }
        else
        {
            i = 728 + (terrainNr - 602);
        }

        m_terrainTypeImages[terrainNr] = MoM::convertLbxToImage(data + i * 0x0180, m_colorTable, toStr(terrainNr) + "-" + toStr(i));

        i += 888;   // Myrror
        if (i > 906) i -= 3; // No animation
        if (i > 919) i -= 3;
        if (i > 920) i -= 3;
        if (i > 921) i -= 3;
        if (i > 990) i -= 3;

        m_terrainTypeImages[MoM::eTerrainType_MAX + terrainNr] = MoM::convertLbxToImage(data + i * 0x0180, m_colorTable, toStr(terrainNr) + "-" + toStr(i));
    }
    return true;
}

bool QMoMResources::createUnitImages(MoM::MoMGameBase* game)
{
    if (0 == game)
        return false;
    std::string units1LbxFile = game->getGameDirectory() + "/" + "UNITS1.LBX";
    std::string units2LbxFile = game->getGameDirectory() + "/" + "UNITS2.LBX";
    std::string monsterLbxFile = game->getGameDirectory() + "/" + "MONSTER.LBX";
    MoM::MoMLbxBase units1Lbx;
    MoM::MoMLbxBase units2Lbx;
    MoM::MoMLbxBase monsterLbx;
    if (!units1Lbx.load(units1LbxFile))
        return false;
    if (!units2Lbx.load(units2LbxFile))
        return false;
    if (!monsterLbx.load(monsterLbxFile))
        return false;

    m_unitImages.resize(MoM::eUnit_Type_MAX);

	// TODO: Put hero pictures in (left out now, since the unit-type pictures are only small horses)
    for (MoM::eUnit_Type unitType = (MoM::eUnit_Type)MoM::gMAX_HERO_TYPES; unitType < MoM::eUnit_Type_MAX; MoM::inc(unitType))
    {
        if (unitType < 120)
        {
            m_unitImages[unitType] = MoM::convertLbxToImage(units1Lbx.getRecord(unitType), m_colorTable, toStr(unitType));
        }
        else
        {
            m_unitImages[unitType] = MoM::convertLbxToImage(units2Lbx.getRecord(unitType - 120), m_colorTable, toStr(unitType));
        }
    }
    for (size_t i = 0; i < monsterLbx.getNrRecords(); ++i)
    {
        MoM::eUnit_Type unitType = (MoM::eUnit_Type)(MoM::UNITTYPE_Arcane_Magic_Spirit + i);
        if (unitType >= MoM::eUnit_Type_MAX)
            break;
        if ((MoM::UNITTYPE_Red_Fire_Elemental != unitType) && (MoM::UNITTYPE_Blue_Floating_Island != unitType)
                && (MoM::UNITTYPE_Blue_Phantom_Warriors != unitType) && (MoM::UNITTYPE_Blue_Phantom_Beast != unitType)
                && (MoM::UNITTYPE_Blue_Air_Elemental != unitType))
        {
            m_unitImages[unitType] = MoM::convertLbxToImage(monsterLbx.getRecord(i), m_colorTable, toStr(unitType));
        }
    }

    return true;
}

}
