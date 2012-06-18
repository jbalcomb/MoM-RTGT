// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include <assert.h>
#include <ctype.h>      // tolower()
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>     // memset(), strncpy(), strrchr()

#include "MoMController.h"
#include "MoMGenerated.h"
#include "MoMLbxBase.h"
#include "MoMUtility.h"
#include "MoMExeWizards.h"

#include "MoMGameBase.h"

namespace MoM {

namespace {

//struct HeroSpecial
//{
//    eHeroAbility    heroAbility;
//    eHelpIndex      helpIndex;
//    std::string     lbxFile;
//    int             lbxIndex;
//};

//struct ItemSpecial
//{
//    eItemPower      itemPower;
//    eHelpIndex      helpIndex;
//    std::string     lbxFile;
//    int             lbxIndex;
//};

//struct UnitSpecial
//{
//    eUnitAbility    unitAbility;
//    eHelpIndex      helpIndex;
//    std::string     lbxFile;
//    int             lbxIndex;
//};

template<typename Enum>
struct Special
{
    Enum            ability;
    eHelpIndex      helpIndex;
    std::string     lbxFile;
    int             lbxIndex;
};

//Special<eCombatEnchantment> gTableCombatSpecials[eCombatEnchantment_MAX] =
//{
//    { UNITABILITY_Cavalry, eHelpIndex_NONE, "MAIN.LBX", 38 },
//};

Special<eHeroAbility> gTableHeroSpecials[eHeroAbility_MAX] =
{
    { HEROABILITY_Leadership, HELP_hero_SPECIAL_LEADERSHIP, "SPECIAL.LBX", 43 },
    { HEROABILITY_Leadership_X, HELP_hero_SPECIAL_LEADERSHIP, "SPECIAL.LBX", 43 },
    { HEROABILITY_2, eHelpIndex_NONE, "", -1 },
    { HEROABILITY_Legendary, HELP_hero_SPECIAL_LEGENDARY, "SPECIAL.LBX", 45 },
    { HEROABILITY_Legendary_X, HELP_hero_SPECIAL_LEGENDARY, "SPECIAL.LBX", 45 },
    { HEROABILITY_5, eHelpIndex_NONE, "", -1 },
    { HEROABILITY_Blademaster, HELP_hero_SPECIAL_BLADEMASTER, "SPECIAL.LBX", 46 },
    { HEROABILITY_Blademaster_X, HELP_hero_SPECIAL_BLADEMASTER, "SPECIAL.LBX", 46 },
    { HEROABILITY_8, eHelpIndex_NONE, "", -1 },
    { HEROABILITY_Armsmaster, HELP_hero_SPECIAL_ARMSMASTER, "SPECIAL.LBX", 47 },
    { HEROABILITY_Armsmaster_X, HELP_hero_SPECIAL_ARMSMASTER, "SPECIAL.LBX", 47 },
    { HEROABILITY_11, eHelpIndex_NONE, "", -1 },
    { HEROABILITY_Constitution, HELP_hero_SPECIAL_CONSTITUTION, "SPECIAL.LBX", 50 },
    { HEROABILITY_Constitution_X, HELP_hero_SPECIAL_CONSTITUTION, "SPECIAL.LBX", 50 },
    { HEROABILITY_14, eHelpIndex_NONE, "", -1 },
    { HEROABILITY_Might, HELP_hero_SPECIAL_MIGHT, "SPECIAL.LBX", 52 },
    { HEROABILITY_Might_X, HELP_hero_SPECIAL_MIGHT, "SPECIAL.LBX", 52 },
    { HEROABILITY_17, eHelpIndex_NONE, "", -1 },
    { HEROABILITY_Arcane_Power, HELP_hero_SPECIAL_ARCANE_POWER, "SPECIAL.LBX", 54 },
    { HEROABILITY_Arcane_Power_X, HELP_hero_SPECIAL_ARCANE_POWER, "SPECIAL.LBX", 56 },  // TODO: ??
    { HEROABILITY_20, eHelpIndex_NONE, "", -1 },
    { HEROABILITY_Sage, HELP_hero_SPECIAL_SAGE, "SPECIAL.LBX", 61 },
    { HEROABILITY_Sage_X, HELP_hero_SPECIAL_SAGE, "SPECIAL.LBX", 61 },
    { HEROABILITY_23, eHelpIndex_NONE, "", -1 },
    { HEROABILITY_Prayermaster, HELP_hero_SPECIAL_PRAYERMASTER, "SPECIAL.LBX", 57 },
    { HEROABILITY_Prayermaster_X, HELP_hero_SPECIAL_PRAYERMASTER, "SPECIAL.LBX", 57 },
    { HEROABILITY_Agility_X, HELP_hero_SPECIAL2_AGILE, "SPECIAL2.LBX", 32 },
    { HEROABILITY_Lucky, HELP_hero_SPECIAL_LUCKY, "SPECIAL.LBX", 58 },
    { HEROABILITY_Charmed, HELP_hero_SPECIAL_CHARMED, "SPECIAL.LBX", 86 },
    { HEROABILITY_Noble, HELP_hero_SPECIAL_NOBLE, "SPECIAL.LBX", 87 },
    { HEROABILITY_30, eHelpIndex_NONE, "", -1 },
    { HEROABILITY_Agility, HELP_hero_SPECIAL2_AGILE, "SPECIAL2.LBX", 32 },
};

Special<eItemPower> gTableItemSpecials[eItemPower_MAX] =
{
    { ITEMPOWER_Vampiric, eHelpIndex_NONE, "", -1 },
    { ITEMPOWER_Guardian_Wind, HELP_ITEMISC_GUARDIAN_WIND, "ITEMISC.LBX", 35 },
    { ITEMPOWER_Lightning, eHelpIndex_NONE, "ITEMISC.LBX", -1 },
    { ITEMPOWER_Cloak_Of_Fear, HELP_ITEMISC_CLOAK_OF_FEAR, "ITEMISC.LBX", 15 },
    { ITEMPOWER_Destruction, HELP_SPECIAL2_DESTRUCTION, "ITEMISC.LBX", -1 },
    { ITEMPOWER_Wraith_Form, HELP_SPECIAL_WRAITH_FORM, "ITEMISC.LBX", -1 },
    { ITEMPOWER_Regeneration, HELP_ITEMISC_REGENERATE, "ITEMISC.LBX", 1 },
    { ITEMPOWER_Pathfinding, HELP_ITEMISC_PATH_FINDING, "ITEMISC.LBX", 4 },

    { ITEMPOWER_Water_Walking, HELP_ITEMISC_WATER_WALKING, "ITEMISC.LBX", 5 },
    { ITEMPOWER_Resist_Elements, HELP_ITEMISC_RESIST_ELEMENTS, "ITEMISC.LBX", 13 },
    { ITEMPOWER_Elemental_Armour, HELP_ITEMISC_ELEMENTAL_ARMOR, "ITEMISC.LBX", 14 },
    { ITEMPOWER_Doom_equals_Chaos, HELP_SPECIAL2_CHAOS, "ITEMISC.LBX", -1 },
    { ITEMPOWER_Stoning, HELP_SPECIAL_STONING_TOUCH, "ITEMISC.LBX", -1 },
    { ITEMPOWER_Endurance, HELP_ITEMISC_ENDURANCE, "ITEMISC.LBX", 10 },
    { ITEMPOWER_Haste, HELP_ITEMISC_HASTE, "ITEMISC.LBX", 2 },
    { ITEMPOWER_Invisibility, HELP_ITEMISC_INVISIBILITY, "ITEMISC.LBX", 8 },

    { ITEMPOWER_Death, eHelpIndex_NONE, "ITEMISC.LBX", -1 },
    { ITEMPOWER_Flight, HELP_ITEMISC_FLIGHT, "ITEMISC.LBX", 16 },
    { ITEMPOWER_Resist_Magic, HELP_ITEMISC_RESIST_MAGIC, "ITEMISC.LBX", 17 },
    { ITEMPOWER_Magic_Immunity, HELP_ITEMISC_MAGIC_IMMUNITY, "ITEMISC.LBX", 0 },
    { ITEMPOWER_Flaming, eHelpIndex_NONE, "ITEMISC.LBX", -1 },
    { ITEMPOWER_Holy_Avenger, eHelpIndex_NONE, "ITEMISC.LBX", -1 },
    { ITEMPOWER_True_Sight, HELP_ITEMISC_TRUE_SIGHT, "ITEMISC.LBX", 3 },
    { ITEMPOWER_Phantasmal, eHelpIndex_NONE, "ITEMISC.LBX", -1 },

    { ITEMPOWER_Power_Drain, eHelpIndex_NONE, "ITEMISC.LBX", -1 },
    { ITEMPOWER_Bless, HELP_ITEMISC_BLESS, "ITEMISC.LBX", 6 },
    { ITEMPOWER_Lion_Heart, HELP_ITEMISC_LION_HEART, "ITEMISC.LBX", 7 },
    { ITEMPOWER_Giant_Strength, HELP_ITEMISC_GIANT_STRENGTH, "ITEMISC.LBX", 34 },
    { ITEMPOWER_Planar_Travel, HELP_ITEMISC_PLANAR_TRAVEL, "ITEMISC.LBX", 9 },
    { ITEMPOWER_Merging, HELP_ITEMISC_MERGING_2, "ITEMISC.LBX", 18 },
    { ITEMPOWER_Righteousness, HELP_ITEMISC_RIGHTEOUSNESS, "ITEMISC.LBX", 11 },
    { ITEMPOWER_Invulnerability, HELP_ITEMISC_INVULNERABILITY, "ITEMISC.LBX", 12 },
};

Special<eUnitAbility> gTableUnitSpecials[eUnitAbility_MAX] =
{
    // Movement_Flags
    // TODO: Image numbers?? In MAIN.LBX but also in SPECIAL.LBX:0,1,2??
    // TODO: left is: Pathfinding, Wind Walking, Planar Travel
    { UNITABILITY_Cavalry, eHelpIndex_NONE, "MAIN.LBX", 38 },
    { UNITABILITY_Sailing, HELP_MAIN_SAILING, "MAIN.LBX", 18 },
    { UNITABILITY_Swimming, HELP_MAIN_SWIMMING, "MAIN.LBX", 19 },
    { UNITABILITY_Flying, HELP_MAIN_FLYING, "MAIN.LBX", 22 },
    { UNITABILITY_Teleporting, HELP_SPECIAL_TELEPORTING, "SPECIAL.LBX", 37 },
    { UNITABILITY_Forester, HELP_SPECIAL_FORESTER, "SPECIAL.LBX", 1 },
    { UNITABILITY_Mountaineer, HELP_SPECIAL_MOUNTAINEER, "SPECIAL.LBX", 2 },
    { UNITABILITY_Merging, HELP_ITEMISC_MERGING_1, "ITEMISC.LBX", 36 },

    // Zeroes
    { eUnitAbility_NONE, eHelpIndex_NONE, "", -1 },
    { eUnitAbility_NONE, eHelpIndex_NONE, "", -1 },
    { eUnitAbility_NONE, eHelpIndex_NONE, "", -1 },
    { eUnitAbility_NONE, eHelpIndex_NONE, "", -1 },
    { eUnitAbility_NONE, eHelpIndex_NONE, "", -1 },
    { eUnitAbility_NONE, eHelpIndex_NONE, "", -1 },
    { eUnitAbility_NONE, eHelpIndex_NONE, "", -1 },
    { eUnitAbility_NONE, eHelpIndex_NONE, "", -1 },

    // Immunity_Flags
    { UNITABILITY_Fire_Immunity, HELP_SPECIAL_FIRE_IMMUNITY, "SPECIAL.LBX", 6 },
    { UNITABILITY_Stoning_Immunity, HELP_SPECIAL_STONING_IMMUNITY, "SPECIAL.LBX", 7 },
    { UNITABILITY_Missiles_Immunity, HELP_SPECIAL_MISSILES_IMMUNITY, "SPECIAL.LBX", 9 },
    { UNITABILITY_Illusions_Immunity, HELP_SPECIAL_ILLUSIONS_IMMUNITY, "SPECIAL.LBX", 10 },
    { UNITABILITY_Cold_Immunity, HELP_SPECIAL_COLD_IMMUNITY, "SPECIAL.LBX", 11 },
    { UNITABILITY_Magic_Immunity, HELP_SPECIAL_MAGIC_IMMUNITY_1, "SPECIAL.LBX", 12 },
    { UNITABILITY_Death_Immunity, HELP_SPECIAL_DEATH_IMMUNITY, "SPECIAL.LBX", 49 },
    { UNITABILITY_Poison_Immunity, HELP_SPECIAL_POISON_IMMUNITY, "SPECIAL.LBX", 5 },

    // Attribute_Flags
    { UNITABILITY_Weapon_Immunity, HELP_SPECIAL_WEAPON_IMMUNITY, "SPECIAL.LBX", 8 },
    { UNITABILITY_Flyer, HELP_SPECIAL_FLIGHT, "SPECIAL.LBX", 80 },
    { UNITABILITY_Lucky, HELP_SPECIAL2_LUCKY, "SPECIAL2.LBX", 16 },
    { UNITABILITY_Summon_Demons_1, HELP_SPECIAL2_SUMMON_DEMONS, "SPECIAL2.LBX", 28 },
    { UNITABILITY_Summon_Demons_2, HELP_SPECIAL2_SUMMON_DEMONS, "SPECIAL2.LBX", 28 },
    { UNITABILITY_Caster_20_MP, HELP_SPECIAL_CASTER, "SPECIAL.LBX", 55 },
    { UNITABILITY_Caster_40_MP, HELP_SPECIAL_CASTER, "SPECIAL.LBX", 55 },
    { UNITABILITY_Standard, eHelpIndex_NONE, "SPECIAL.LBX", -1 },

    { UNITABILITY_Healing_Spell, HELP_SPECIAL_HEALING_SPELL, "SPECIAL.LBX", 38 },
    { UNITABILITY_Fire_Ball_Spell, HELP_SPECIAL_FIRE_BALL_SPELL, "SPECIAL.LBX", 39 },
    { UNITABILITY_Doombolt_Spell, HELP_SPECIAL_DOOMBOLT_SPELL, "SPECIAL.LBX", 41 },
    { UNITABILITY_Immolation, HELP_SPECIAL_IMMOLATION, "SPECIAL.LBX", 32 },
    { UNITABILITY_Web_Spell, HELP_SPECIAL2_WEB_SPELL, "SPECIAL2.LBX", 20 },
    { UNITABILITY_Cause_Fear_Spell, HELP_SPECIAL2_CAUSE_FEAR_SPELL, "SPECIAL2.LBX", 21},
    { UNITABILITY_Resistance_to_All, HELP_SPECIAL_RESISTANCE_TO_ALL, "SPECIAL.LBX", 33 },
    { UNITABILITY_Holy_Bonus, HELP_SPECIAL_HOLY_BONUS, "SPECIAL.LBX", 34 },

    // Zeroes
    { eUnitAbility_NONE, eHelpIndex_NONE, "", -1 },
    { eUnitAbility_NONE, eHelpIndex_NONE, "", -1 },
    { eUnitAbility_NONE, eHelpIndex_NONE, "", -1 },
    { eUnitAbility_NONE, eHelpIndex_NONE, "", -1 },
    { eUnitAbility_NONE, eHelpIndex_NONE, "", -1 },
    { eUnitAbility_NONE, eHelpIndex_NONE, "", -1 },
    { eUnitAbility_NONE, eHelpIndex_NONE, "", -1 },
    { eUnitAbility_NONE, eHelpIndex_NONE, "", -1 },

    // Ability_Flags
    { UNITABILITY_Summoned_Unit, eHelpIndex_NONE, "", -1 },
    { UNITABILITY_Large_Shield, HELP_SPECIAL_LARGE_SHIELD, "SPECIAL.LBX", 14 },
    { UNITABILITY_Plane_Shift, HELP_SPECIAL_PLANE_SHIFT, "SPECIAL.LBX", 4 },
    { UNITABILITY_Wall_Crusher, HELP_SPECIAL_WALL_CRUSHER, "SPECIAL.LBX", 15 },
    { UNITABILITY_Healer, HELP_SPECIAL_HEALER, "SPECIAL.LBX", 16 },
    { UNITABILITY_Create_Outpost, HELP_SPECIAL_CREATE_OUTPOST, "SPECIAL.LBX", 17 },
    { UNITABILITY_Invisibility, HELP_SPECIAL_INVISIBILITY_1, "SPECIAL.LBX", 18 },
    { UNITABILITY_Create_Undead, HELP_SPECIAL_CREATE_UNDEAD, "SPECIAL.LBX", 19 },

    { UNITABILITY_Long_Range, HELP_SPECIAL2_LONG_RANGE, "SPECIAL2.LBX", 18 },
    { UNITABILITY_Land_Corruption, HELP_SPECIAL_LAND_CORRUPTION, "SPECIAL.LBX", 21 },
    { UNITABILITY_Meld_With_Node, HELP_SPECIAL_MELD_WITH_NODE, "SPECIAL.LBX", 40 },
    { UNITABILITY_Non_Corporeal, HELP_SPECIAL_NON_CORPOREAL, "SPECIAL.LBX", 22 },
    { UNITABILITY_Wind_Walking, HELP_SPECIAL_WIND_WALKING_1, "SPECIAL.LBX", 23 },
    { UNITABILITY_Regeneration, HELP_SPECIAL_REGENERATION, "SPECIAL.LBX", 24 },
    { UNITABILITY_Purify, HELP_SPECIAL_PURIFY, "SPECIAL.LBX", 25 },
    { UNITABILITY_Negate_First_Strike, HELP_SPECIAL_NEGATE_FIRST_STRIKE, "SPECIAL.LBX", 48 },

    // Attack_Flags
    { UNITABILITY_Armor_Piercing, HELP_SPECIAL_ARMOR_PIERCING, "SPECIAL.LBX", 28 },
    { UNITABILITY_First_Strike, HELP_SPECIAL_FIRST_STRIKE, "SPECIAL.LBX", 29 },
    { UNITABILITY_Poison_attack, HELP_SPECIAL_POISON, "SPECIAL.LBX", 30 },
    { UNITABILITY_Life_Stealing, HELP_SPECIAL_LIFE_STEAL, "SPECIAL.LBX", 31 },
    { UNITABILITY_Automatic_Damage, eHelpIndex_NONE, "", -1 },
    { UNITABILITY_Destruction, HELP_SPECIAL2_DESTRUCTION, "SPECIAL2.LBX", 5 },
    { UNITABILITY_Illusionary_attack, HELP_SPECIAL_ILLUSION, "SPECIAL.LBX", 35 },
    { UNITABILITY_Stoning_Touch, HELP_SPECIAL_STONING_TOUCH, "SPECIAL.LBX", 26 },

    { UNITABILITY_No_effect05, eHelpIndex_NONE, "", -1 },
    { UNITABILITY_Death_Touch, eHelpIndex_NONE, "", -1 },
    { UNITABILITY_Power_Drain, HELP_SPECIAL2_POWER_DRAIN, "SPECIAL2.LBX", 31 },
    { UNITABILITY_Dispel_Evil, HELP_SPECIAL2_DISPEL_EVIL, "SPECIAL.LBX", 22 },
    { UNITABILITY_No_effect04_COMBAT, eHelpIndex_NONE, "", -1 },
    { UNITABILITY_No_effect03_COMBAT, eHelpIndex_NONE, "", -1 },
    { UNITABILITY_Eldritch_Weapon_COMBAT, HELP_SPECIAL_ELDRITCH_WEAPON, "SPECIAL.LBX", 84 },
    { UNITABILITY_Warp_Lightning_COMBAT, eHelpIndex_NONE, "", -1 },
};

Special<eUnitEnchantment> gTableUnitEnchantments[eUnitEnchantment_MAX] =
{
    { UNITENCHANTMENT_Immolation, HELP_SPECIAL2_IMMOLATION, "SPECIAL2.LBX", 6 },
    { UNITENCHANTMENT_Guardian_Wind, HELP_SPECIAL2_GUARDIAN_WIND, "SPECIAL2.LBX", 7 },
    { UNITENCHANTMENT_Berserk, HELP_SPECIAL2_BERSERK, "SPECIAL2.LBX", 17 },
    { UNITENCHANTMENT_Cloak_of_Fear, HELP_SPECIAL_CLOAK_OF_FEAR, "SPECIAL.LBX", 97 },
    { UNITENCHANTMENT_Black_Channels, HELP_SPECIAL_BLACK_CHANNELS, "SPECIAL.LBX", 67 },
    { UNITENCHANTMENT_Wraith_Form, HELP_SPECIAL_WRAITH_FORM, "SPECIAL.LBX", 68 },
    { UNITENCHANTMENT_Regeneration, HELP_SPECIAL_REGENERATE, "SPECIAL.LBX", 69 },
    { UNITENCHANTMENT_Path_Finding, HELP_SPECIAL_PATHFINDING_1, "SPECIAL.LBX", 70 },

    { UNITENCHANTMENT_Water_Walking, HELP_SPECIAL_WATER_WALKING, "SPECIAL.LBX", 71 },
    { UNITENCHANTMENT_Resist_Elements, HELP_SPECIAL_RESIST_ELEMENTS, "SPECIAL.LBX", 72 },
    { UNITENCHANTMENT_Elemental_Armor, HELP_SPECIAL_ELEMENTAL_ARMOR, "SPECIAL.LBX", 73 },
    { UNITENCHANTMENT_Stone_Skin, HELP_SPECIAL_STONE_SKIN, "SPECIAL.LBX", 74 },
    { UNITENCHANTMENT_Iron_Skin, HELP_SPECIAL_IRON_SKIN, "SPECIAL.LBX", 75 },
    { UNITENCHANTMENT_Endurance, HELP_SPECIAL_ENDURANCE, "SPECIAL.LBX", 76 },
    { UNITENCHANTMENT_Spell_Lock, HELP_SPECIAL2_SPELL_LOCK, "SPECIAL2.LBX", 8 },
    { UNITENCHANTMENT_Invisibility, HELP_SPECIAL_INVISIBILITY_2, "SPECIAL.LBX", 78 },

    { UNITENCHANTMENT_Wind_Walking, HELP_SPECIAL_WIND_WALKING_2, "SPECIAL.LBX", 79 },
    { UNITENCHANTMENT_Flight, HELP_SPECIAL_FLIGHT, "SPECIAL.LBX", 80 },
    { UNITENCHANTMENT_Resist_Magic, HELP_SPECIAL_RESIST_MAGIC, "SPECIAL.LBX", 81 },
    { UNITENCHANTMENT_Magic_Immunity, HELP_SPECIAL_MAGIC_IMMUNITY_2, "SPECIAL.LBX", 82 },
    { UNITENCHANTMENT_Flame_Blade, HELP_SPECIAL_FLAME_BLADE, "SPECIAL.LBX", 83 },
    { UNITENCHANTMENT_Eldritch_Weapon, HELP_SPECIAL_ELDRITCH_WEAPON, "SPECIAL.LBX", 84 },
    { UNITENCHANTMENT_True_Sight, HELP_SPECIAL_TRUE_SIGHT, "SPECIAL.LBX", 85 },
    { UNITENCHANTMENT_Holy_Weapon, HELP_SPECIAL_HOLY_WEAPON, "SPECIAL.LBX", 86 },

    { UNITENCHANTMENT_Heroism, HELP_SPECIAL_HEROISM, "SPECIAL.LBX", 87 },
    { UNITENCHANTMENT_Bless, HELP_SPECIAL_BLESS, "SPECIAL.LBX", 88 },
    { UNITENCHANTMENT_Lionheart, HELP_SPECIAL_LION_HEART, "SPECIAL.LBX", 89 },
    { UNITENCHANTMENT_Giant_Strength, HELP_SPECIAL_GIANT_STRENGTH, "SPECIAL.LBX", 65 },
    { UNITENCHANTMENT_Planar_Travel, HELP_SPECIAL_PLANAR_TRAVEL, "SPECIAL.LBX", 91 },
    { UNITENCHANTMENT_Holy_Armor, HELP_SPECIAL_HOLY_ARMOR, "SPECIAL.LBX", 90 },
    { UNITENCHANTMENT_Righteousness, HELP_SPECIAL_RIGHTEOUSNESS, "SPECIAL.LBX", 93 },
    { UNITENCHANTMENT_Invulnerability, HELP_SPECIAL_INVULNERABILITY, "SPECIAL.LBX", 94 },
};

Special<eUnitMutation> gTableUnitMutations[eUnitMutation_MAX] =
{
    { UNITMUTATION_Chaos_Channels_Demon_Skin, HELP_SPECIAL_CHAOS_CHANNEL_1, "SPECIAL.LBX", 62 },
    { UNITMUTATION_Chaos_Channels_Demon_Wings, HELP_SPECIAL_CHAOS_CHANNEL_2, "SPECIAL.LBX", 63 },
    { UNITMUTATION_Chaos_Channels_Fiery_Breath, HELP_SPECIAL_CHAOS_CHANNEL_3, "SPECIAL.LBX", 64 },
    { UNITMUTATION_Undead, HELP_SPECIAL2_UNDEAD, "SPECIAL2.LBX", 9 },
    { UNITMUTATION_Stasis_initial, HELP_SPECIAL2_STASIS, "SPECIAL2.LBX", 4 },
    { UNITMUTATION_Stasis_lingering, HELP_SPECIAL2_STASIS, "SPECIAL2.LBX", 4 },
};

}

MoMGameBase::MoMGameBase()
{
    assert(1 == sizeof(eSkill) && "Check enum-size (g++ flag -fshort-enums)");
    assert(0x04C8 == sizeof(Wizard) && "Check pack-struct (g++ flag -fpack-struct)");
}

MoMGameBase::~MoMGameBase()
{
}

// TODO: Centralize getGameDirectory() here.

int MoMGameBase::getCostToProduce(eProducing producing)
{
	int buildingCost = -1;
	if (producing < MoM::PRODUCING_BUILDING_MAX)
	{
		MoM::Building_Data* buildingData = getBuilding_Data((eBuilding)producing);
		if (0 != buildingData)
		{
			buildingCost = buildingData->m_Building_cost;
		}
	}
	else 
	{
		MoM::eUnit_Type unitTypeNr = (MoM::eUnit_Type)((int)producing - (int)MoM::PRODUCING_Trireme + (int)MoM::UNITTYPE_Trireme);
		MoM::Unit_Type_Data* unitData = getUnit_Type_Data(unitTypeNr);
		if (0 != unitData)
		{
			buildingCost = unitData->m_Cost;
		}
	}
	return buildingCost;
}

std::string MoMGameBase::getHelpText(eHelpIndex helpTextNr)
{
    const size_t maxwidth = 60;

    if (0 == m_HelpLbx.get())
    {
        m_HelpLbx.reset(new MoMLbxBase);
        // Only try to load once and ignore result.
        // We'll check if it's there when we use it.
        (void)m_HelpLbx->load(this->getGameDirectory() + "/HELP.LBX");
    }
    if (m_HelpLbx->getNrRecords() < 3)
    {
        return "(HELP.LBX is not available)";
    }

    std::string text;
    if ((helpTextNr >= 0) && (helpTextNr < eHelpIndex_MAX))
    {
        // TODO: Check ranges
        const HelpLBXentry* helpLbxEntries = reinterpret_cast<const HelpLBXentry*>(m_HelpLbx->getRecord(2) + 4);
        const char* title = helpLbxEntries[helpTextNr].title;
        const char* description = helpLbxEntries[helpTextNr].description;

        text = std::string(title) + ": " + description;
    }

    // Wrap text within maxwidth
    size_t posStart = 0;
    while (posStart + maxwidth < text.length())
    {
        size_t pos;
        for (pos = posStart + maxwidth; (text[pos] != ' ') && (text[pos] != '\n') && (text[pos] != '\x14') && (pos > posStart); --pos)
        {
        }
        if (pos <= posStart)
        {
            break;
        }
        text[pos] = '\n';
        posStart = pos + 1;
    }

    return text;
}

std::string MoMGameBase::getHelpText(eHeroAbility heroAbility)
{
    std::string value;
    if ((heroAbility >= 0) && (heroAbility < ARRAYSIZE(gTableHeroSpecials)))
    {
        value = getHelpText(gTableHeroSpecials[heroAbility].helpIndex);
    }
    return value;
}

std::string MoMGameBase::getHelpText(eItemPower itemPower)
{
    std::string value;
    if ((itemPower >= 0) && (itemPower < ARRAYSIZE(gTableItemSpecials)))
    {
        value = getHelpText(gTableItemSpecials[itemPower].helpIndex);
    }
    return value;
}

std::string MoMGameBase::getHelpText(eSpell spell)
{
    std::string value;
    if ((spell >= 1) && (spell < eSpell_MAX))
    {
        eHelpIndex helpIndex = (MoM::eHelpIndex)(0 + spell);
        value = getHelpText(helpIndex);
    }
    return value;
}

std::string MoMGameBase::getHelpText(eUnitAbility unitAbility)
{
    std::string value;
    if ((unitAbility >= 0) && (unitAbility < ARRAYSIZE(gTableUnitSpecials)))
    {
        value = getHelpText(gTableUnitSpecials[unitAbility].helpIndex);
    }
    return value;
}

std::string MoMGameBase::getHelpText(eUnitEnchantment unitEnchantment)
{
    std::string value;
    if ((unitEnchantment >= 0) && (unitEnchantment < ARRAYSIZE(gTableUnitEnchantments)))
    {
        value = getHelpText(gTableUnitEnchantments[unitEnchantment].helpIndex);
    }
    return value;
}

std::string MoMGameBase::getHelpText(eUnitMutation unitMutation)
{
    std::string value;
    if ((unitMutation >= 0) && (unitMutation < ARRAYSIZE(gTableUnitMutations)))
    {
        value = getHelpText(gTableUnitMutations[unitMutation].helpIndex);
    }
    return value;
}

// TODO: Replace all references in other modules to race names by getRaceName()
std::string MoMGameBase::getRaceName(eRace race)
{
	std::string raceName;
 	const MoMDataSegment* pMoMDataSegment = getDataSegment();
    if ((0 != pMoMDataSegment) && (static_cast<unsigned>(race) < gMAX_RACES))
	{
		const char* ptrName = getNameByOffset(pMoMDataSegment->m_Race_Data[race].m_PtrName);
		if (0 != ptrName)
		{
			raceName = ptrName;
		}
	}
	if (raceName.empty())
	{
		raceName = toStr(race);
		// Strip Capital prefix
		size_t pos = 0;
		while ((pos < raceName.size()) && isupper(raceName[pos]))
		{
			pos++;
		}
		if ((pos >= 2) && (pos + 1 < raceName.size()))
		{
			raceName = raceName.substr(pos + 1);
		}
		// Strip trailing numbers
		pos = raceName.find('(');
        if ((std::string::npos != pos) && (pos > 1))
		{
            raceName = raceName.substr(0, pos - 1);
		}
		// Replace underscores by spaces
        raceName = replaceUnderscoresBySpaces(raceName);
	}
	return raceName;
}

}
