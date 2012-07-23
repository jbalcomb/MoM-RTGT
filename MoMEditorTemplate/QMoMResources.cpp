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
#include <MoMUtility.h>
#include <QMoMLbx.h>
#include <QMoMTreeItem.h>
#include <QMoMUtility.h>

#include "QMoMResources.h"

namespace MoM
{

const QFont QMoMResources::g_FontSmall("Sans Serif", 10, -1, false);
#ifdef _WIN32
const QFont QMoMResources::g_Font("Monotype Corsiva", 11, -1, false);
#else
// Note: attribute italic=true is required for URW Chancery L
const QFont QMoMResources::g_Font("URW Chancery L", 12, -1, true);
#endif

QMoMResources* QMoMResources::m_instance = 0;

QMoMResources::QMoMResources(const QMoMGamePtr& game) : m_game()
{
    setGame(game);
}

QMoMResources::~QMoMResources()
{
}

void QMoMResources::createInstance(const QMoMGamePtr &game)
{
    delete m_instance;
    m_instance = new QMoMResources(game);
}

QMoMResources &QMoMResources::instance()
{
    if (0 == m_instance)
    {
        m_instance = new QMoMResources(QMoMGamePtr());
    }
    return *m_instance;
}

void QMoMResources::setGame(const QMoMGamePtr& game)
{
    if (game.data() != m_game.data())
    {
        qDebug() << getDateTimeStr() << ">QMoMResources::setGame() begin";
        m_game = game;

        (void)createColorTable();

        (void)createBuildingImages();
        (void)createLbxImages("ITEMISC", m_itemiscImages);
        (void)createLbxImages("ITEMS", m_itemsImages);
        (void)createLairImages();
        (void)createLbxImages("MAPBACK", m_mapBackImages);
        (void)createLbxImages("SPECIAL", m_specialImages);
        // UnitImages are created before SpellImages, because SpellImages uses them
        (void)createUnitImages();
        // m_specialImages and UnitImages should already have been created, because SpellImages uses them
        (void)createSpellImages();
        (void)createTerrainImages();

        qDebug() << getDateTimeStr() << "<QMoMResources::setGame() end";
    }
}

const QMoMImagePtr QMoMResources::getImage(MoM::eBannerColor bannerColor) const
{
    QMoMImagePtr image;
    unsigned index = 14 + toUInt(bannerColor);
    if (inVectorRange(m_mapBackImages, index))
    {
        image = m_mapBackImages[index];
    }
    return image;
}

const QMoMImagePtr QMoMResources::getImage(MoM::eBonusDeposit bonusDeposit) const
{
    QMoMImagePtr image;
    unsigned index = -1;
    switch (bonusDeposit)
    {
    case DEPOSIT_Iron_Ore:      index = 78; break;
    case DEPOSIT_Coal:          index = 79; break;
    case DEPOSIT_Silver_Ore:    index = 80; break;
    case DEPOSIT_Gold_Ore:      index = 81; break;
    case DEPOSIT_Gems:          index = 82; break;
    case DEPOSIT_Mithril_Ore:   index = 83; break;
    case DEPOSIT_Adamantium_Ore:    index = 84; break;
    case DEPOSIT_Quork:         index = 85; break;
    case DEPOSIT_Crysx:         index = 86; break;
    case DEPOSIT_Wild_Game:     index = 92; break;
    case DEPOSIT_Nightshade:    index = 91; break;
    case DEPOSIT_no_deposit:
    default:                    break;
    }
    if (inVectorRange(m_mapBackImages, index))
    {
        image = m_mapBackImages[index];
    }
    return image;
}

const QMoMImagePtr QMoMResources::getImage(MoM::eBuilding building) const
{
    QMoMImagePtr image;
    if (inVectorRange(m_buildingImages, building))
    {
        image = m_buildingImages[building];
    }
    return image;
}

const QMoMImagePtr  QMoMResources::getImage(MoM::eItem_Icon itemIcon) const
{
    QMoMImagePtr image;
    if (inVectorRange(m_itemsImages, itemIcon))
    {
        image = m_itemsImages[itemIcon];
    }
    return image;
}

const QMoMImagePtr  QMoMResources::getImage(MoM::eTower_Node_Lair_Type lair) const
{
    QMoMImagePtr image;
    if (inVectorRange(m_lairImages, lair))
    {
        image = m_lairImages[lair];
    }
    return image;
}

const QMoMImagePtr QMoMResources::getImage(eRace race) const
{
    QMoMImagePtr image(new QImage(QString(":/race/%0.gif").arg(prettyQStr(race))));
    return image;
}

const QMoMImagePtr QMoMResources::getImage(MoM::eRandomPickType randomPickType) const
{
    QMoMImagePtr image(new QImage(QString(":/abilities/%0.gif").arg(prettyQStr(randomPickType))));
    return image;
}

const QMoMImagePtr QMoMResources::getImage(MoM::eSlot_Type16 slotType) const
{
    static const int lookupItemisc[MoM::eSlot_Type16_MAX] =
    {
        -1,
        27, // SLOT16_Sword = 1,
        28, // SLOT16_Bow = 2,
        29, // SLOT16_Sword_Staff_Wand = 3,
        30, // SLOT16_Staff_Wand = 4,
        32, // SLOT16_Armor_Shield = 5,
        31, // SLOT16_Amulet = 6,
    };

    int index = -1;
    if (MoM::toUInt(slotType) < ARRAYSIZE(lookupItemisc))
    {
        index = lookupItemisc[slotType];
    }
    QMoMImagePtr image;
    if (inVectorRange(m_itemiscImages, index))
    {
        image = m_itemiscImages[index];
    }
    return image;
}

const QMoMImagePtr QMoMResources::getImage(MoM::eSpell spell) const
{
    QMoMImagePtr image;
    if (inVectorRange(m_spellImages, spell))
    {
        image = m_spellImages[spell];
    }
    return image;
}

const QMoMImagePtr QMoMResources::getImage(MoM::eTerrainType terrain) const
{
    QMoMImagePtr image;
    if (inVectorRange(m_terrainTypeImages, terrain))
    {
        image = m_terrainTypeImages[terrain];
    }
    return image;
}

const QMoMImagePtr QMoMResources::getImage(MoM::eUnit_Type unitType) const
{
    QMoMImagePtr image;
    if (inVectorRange(m_unitImages, unitType))
    {
        image = m_unitImages[unitType];
    }
    return image;
}

bool QMoMResources::createColorTable()
{
    if (m_game.isNull())
        return false;
    m_colorTable.resize(256);
    std::string fontsLbxFile = m_game->getGameDirectory() + "/" + "FONTS.LBX";
    MoM::MoMLbxBase fontsLbx;
    if (!fontsLbx.load(fontsLbxFile))
        return false;

    uint8_t* dataPalette = fontsLbx.getRecord(2);
    MoM::convertLbxToPalette(dataPalette, m_colorTable);

    return true;
}

bool QMoMResources::createBuildingImages()
{
    if (m_game.isNull())
        return false;
    std::string lbxFile = m_game->getGameDirectory() + "/" + "CITYSCAP.LBX";
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

bool QMoMResources::createLairImages()
{
    if (m_game.isNull())
        return false;
    std::string lairsLbxFile = m_game->getGameDirectory() + "/" + "RELOAD.LBX";
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

bool QMoMResources::createLbxImages(const std::string& lbxTitle, QVector<QMoMImagePtr>& vecImages)
{
    if (m_game.isNull())
        return false;
    std::string lbxFile = m_game->getGameDirectory() + "/" + lbxTitle + ".LBX";
    MoM::MoMLbxBase lbx;
    if (!lbx.load(lbxFile))
        return false;
    vecImages.resize(lbx.getNrRecords());
    for (size_t i = 0; i < lbx.getNrRecords(); ++i)
    {
        vecImages[i] = MoM::convertLbxToImage(lbx.getRecord(i), m_colorTable, lbxTitle + toStr(i));
    }
    return true;
}

bool QMoMResources::createSpellImages()
{
    // PRE: UnitImages should already have been created, because SpellImages uses them

    if (m_game.isNull())
        return false;
    std::string cityscapLbxFile = m_game->getGameDirectory() + "/" + "CITYSCAP.LBX";
    std::string monsterLbxFile = m_game->getGameDirectory() + "/" + "MONSTER.LBX";
    std::string specfxLbxFile = m_game->getGameDirectory() + "/" + "SPECFX.LBX";
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
    for (MoM::eSpell spell = (MoM::eSpell)0; spell < MoM::eSpell_MAX; MoM::inc(spell))
    {
        const HelpLBXentry* helpEntry = m_game->getHelpEntry(spell);
        if (0 != helpEntry)
        {
            if (std::string(helpEntry->lbxFile) == std::string("SPECIAL.LBX"))
            {
                if (inVectorRange(m_specialImages, helpEntry->lbxIndex))
                {
                    m_spellImages[spell] = m_specialImages[helpEntry->lbxIndex];
                }
            }
        }

        MoM::Spell_Data* spellData = m_game->getSpell_Data(spell);
        if ((0 != spellData) && (MoM::SPELLTYPE_Summoning == spellData->m_Section_in_spell_book))
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


    //600	LIGHT	COMPIX.LBX	5
    //601	DARKNESS	COMPIX.LBX	6
    //602	WARP REALITY	COMPIX.LBX	7
    //603	BLACK PRAYER	COMPIX.LBX	8
    //604	WRACK	COMPIX.LBX	9
    //605	METAL FIRES	COMPIX.LBX	10
    //606	PRAYER	COMPIX.LBX	11
    //607	HIGH PRAYER	COMPIX.LBX	12
    //608	TERROR	COMPIX.LBX	13
    //609	CALL LIGHTNING	COMPIX.LBX	14
    //610	COUNTER MAGIC	COMPIX.LBX	15
    //611	MASS INVISIBILITY	COMPIX.LBX	41
    //612	DISPELS NON-SORCERY	COMPIX.LBX	54
    //613	DISPELS NON-CHAOS	COMPIX.LBX	47
    //614	DISPELS NON-NATURE	COMPIX.LBX	52
    //615	SORCERY NODE AURA	COMPIX.LBX	55
    //616	CHAOS NODE AURA	COMPIX.LBX	48
    //617	NATURE NODE AURA	COMPIX.LBX	53
    //618	CLOUD OF DARKNESS	COMPIX.LBX	50
    //619	HOLY LIGHT	COMPIX.LBX	44
    //620	CHAOS SURGE	COMPIX.LBX	46
    //621	ETERNAL NIGHT	COMPIX.LBX	49
    //622	CRUSADE	COMPIX.LBX	42
    //623	HOLY ARMS	COMPIX.LBX	43
    //624	CHARM OF LIFE	COMPIX.LBX	45
    //625	ZOMBIE MASTERY	COMPIX.LBX	51

    //632	ENTANGLE	COMPIX.LBX	60


    //449	IMMOLATION	SPECIAL2.LBX	6
    //450	GUARDIAN WIND	SPECIAL2.LBX	7
    //451	BERSERK	SPECIAL2.LBX	17
    //452	CLOAK OF FEAR	SPECIAL.LBX	97
    //453	BLACK CHANNELS	SPECIAL.LBX	67
    //454	WRAITH FORM	SPECIAL.LBX	68
    //455	REGENERATE	SPECIAL.LBX	69
    //456	PATHFINDING	SPECIAL.LBX	70
    //457	WATER WALKING	SPECIAL.LBX	71
    //458	ELEMENTAL ARMOR	SPECIAL.LBX	73
    //459	RESIST ELEMENTS	SPECIAL.LBX	72
    //460	STONE SKIN	SPECIAL.LBX	74
    //461	IRON SKIN	SPECIAL.LBX	75
    //462	ENDURANCE	SPECIAL.LBX	76
    //463	SPELL LOCK	SPECIAL2.LBX	8
    //464	INVISIBILITY	SPECIAL.LBX	78
    //465	WIND WALKING	SPECIAL.LBX	79
    //466	FLIGHT	SPECIAL.LBX	80
    //467	RESIST MAGIC	SPECIAL.LBX	81
    //468	MAGIC IMMUNITY	SPECIAL.LBX	82
    //469	FLAME BLADE	SPECIAL.LBX	83
    //470	ELDRITCH WEAPON	SPECIAL.LBX	84
    //471	TRUE SIGHT	SPECIAL.LBX	85
    //472	HOLY WEAPON	SPECIAL.LBX	86
    //473	HEROISM	SPECIAL.LBX	87
    //474	BLESS	SPECIAL.LBX	88
    //475	LION HEART	SPECIAL.LBX	89
    //476	GIANT STRENGTH	SPECIAL.LBX	65
    //477	PLANAR TRAVEL	SPECIAL.LBX	91
    //478	HOLY ARMOR	SPECIAL.LBX	92
    //479	RIGHTEOUSNESS	SPECIAL.LBX	93
    //480	INVULNERABILITY	SPECIAL.LBX	94
    //481	VERTIGO	SPECIAL.LBX	101
    //482	CONFUSION	SPECIAL2.LBX	0
    //483	WHIRLWIND	SPECIAL2.LBX	1
    //484	MIND STORM	SPECIAL2.LBX	2
    //485	SHATTER	SPECIAL.LBX	95
    //486	WEAKNESS	SPECIAL.LBX	96
    //487	BLACK SLEEP	SPECIAL2.LBX	3
    //488	WARP CREATURE	SPECIAL2.LBX	11
    //489	WARP CREATURE	SPECIAL2.LBX	12
    //490	WARP CREATURE	SPECIAL2.LBX	13
    //491	MANA LEAK	SPECIAL2.LBX	10
    //492	HASTE	SPECIAL.LBX	77
    //493	WEB	SPECIAL.LBX	99
    //494	CREATURE BINDING	SPECIAL.LBX	100
    //495	POSSESSION	SPECIAL.LBX	98


    return true;
}

bool QMoMResources::createTerrainImages()
{
    if (m_game.isNull())
        return false;
    std::string terrainLbxFile = m_game->getGameDirectory() + "/" + "TERRAIN.LBX";
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

bool QMoMResources::createUnitImages()
{
    if (m_game.isNull())
        return false;
    std::string units1LbxFile = m_game->getGameDirectory() + "/" + "UNITS1.LBX";
    std::string units2LbxFile = m_game->getGameDirectory() + "/" + "UNITS2.LBX";
    std::string monsterLbxFile = m_game->getGameDirectory() + "/" + "MONSTER.LBX";
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

    // Put specific hero pictures in, since the unit-type pictures are only small horses
    m_unitImages[UNITTYPE_Dwarf] = QMoMImagePtr(new QImage(":/units/Dwarf.gif"));
    m_unitImages[UNITTYPE_Barbarian] = QMoMImagePtr(new QImage(":/units/Barbarian.gif"));
    m_unitImages[UNITTYPE_Sage] = QMoMImagePtr(new QImage(":/units/Sage.gif"));
    m_unitImages[UNITTYPE_Dervish] = QMoMImagePtr(new QImage(":/units/Dervish.gif"));
    m_unitImages[UNITTYPE_Beastmaster] = QMoMImagePtr(new QImage(":/units/Beastmaster.gif"));
    m_unitImages[UNITTYPE_Bard] = QMoMImagePtr(new QImage(":/units/Bard.gif"));
    m_unitImages[UNITTYPE_Orc_Warrior] = QMoMImagePtr(new QImage(":/units/Orc Warrior.gif"));
    m_unitImages[UNITTYPE_Healer] = QMoMImagePtr(new QImage(":/units/Healer.gif"));
    m_unitImages[UNITTYPE_Huntress] = QMoMImagePtr(new QImage(":/units/Huntress.gif"));
    m_unitImages[UNITTYPE_Thief] = QMoMImagePtr(new QImage(":/units/Thief.gif"));
    m_unitImages[UNITTYPE_Druid] = QMoMImagePtr(new QImage(":/units/Druid.gif"));
    m_unitImages[UNITTYPE_War_Monk] = QMoMImagePtr(new QImage(":/units/War Monk.gif"));
    m_unitImages[UNITTYPE_Warrior_Mage] = QMoMImagePtr(new QImage(":/units/Warrior Mage.gif"));
    m_unitImages[UNITTYPE_Magician] = QMoMImagePtr(new QImage(":/units/Magician.gif"));
    m_unitImages[UNITTYPE_Assassin] = QMoMImagePtr(new QImage(":/units/Assassin.gif"));
    m_unitImages[UNITTYPE_Wind_Mage] = QMoMImagePtr(new QImage(":/units/Wind Mage.gif"));
    m_unitImages[UNITTYPE_Ranger] = QMoMImagePtr(new QImage(":/units/Ranger.gif"));
    m_unitImages[UNITTYPE_Draconian] = QMoMImagePtr(new QImage(":/units/Draconian.gif"));
    m_unitImages[UNITTYPE_Witch] = QMoMImagePtr(new QImage(":/units/Witch.gif"));
    m_unitImages[UNITTYPE_Golden_One] = QMoMImagePtr(new QImage(":/units/Golden One.gif"));
    m_unitImages[UNITTYPE_Ninja] = QMoMImagePtr(new QImage(":/units/Ninja.gif"));
    m_unitImages[UNITTYPE_Rogue] = QMoMImagePtr(new QImage(":/units/Rogue.gif"));
    m_unitImages[UNITTYPE_Amazon] = QMoMImagePtr(new QImage(":/units/Amazon.gif"));
    m_unitImages[UNITTYPE_Warlock] = QMoMImagePtr(new QImage(":/units/Warlock.gif"));
    m_unitImages[UNITTYPE_Unknown] = QMoMImagePtr(new QImage(":/units/Unknown.gif"));
    m_unitImages[UNITTYPE_Illusionist] = QMoMImagePtr(new QImage(":/units/Illusionist.gif"));
    m_unitImages[UNITTYPE_Swordsman] = QMoMImagePtr(new QImage(":/units/Swordsman.gif"));
    m_unitImages[UNITTYPE_Priestess] = QMoMImagePtr(new QImage(":/units/Priestess.gif"));
    m_unitImages[UNITTYPE_Paladin] = QMoMImagePtr(new QImage(":/units/Paladin.gif"));
    m_unitImages[UNITTYPE_Black_Knight] = QMoMImagePtr(new QImage(":/units/Black Knight.gif"));
    m_unitImages[UNITTYPE_Elven_Archer] = QMoMImagePtr(new QImage(":/units/Elven Archer.gif"));
    m_unitImages[UNITTYPE_Knight] = QMoMImagePtr(new QImage(":/units/Knight.gif"));
    m_unitImages[UNITTYPE_Necromancer] = QMoMImagePtr(new QImage(":/units/Necromancer.gif"));
    m_unitImages[UNITTYPE_Chaos_Warrior] = QMoMImagePtr(new QImage(":/units/Chaos Warrior.gif"));
    m_unitImages[UNITTYPE_Chosen] = QMoMImagePtr(new QImage(":/units/Chosen.gif"));

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
