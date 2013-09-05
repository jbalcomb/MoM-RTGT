// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2011-09-30
// ---------------------------------------------------------------------------

#include <string>

#include <QFontDatabase>

#include "MoMGameBase.h"
#include "MoMGenerated.h"
#include "MoMLbxBase.h"
#include "MoMUtility.h"
#include "QMoMLbx.h"
#include "QMoMTreeItemModel.h"
#include "QMoMUtility.h"

#include "QMoMResources.h"

namespace MoM
{

template<typename Enum>
struct Special
{
    Enum            ability;
    eHelpIndex      helpIndex;
    std::string     lbxFile;
    int             lbxIndex;
};

static Special<eHeroAbility> gTableHeroSpecials[eHeroAbility_MAX] =
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

static Special<eItemPower> gTableItemSpecials[eItemPower_MAX] =
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

// lbxIndex is not the actual index, but must still be multiplied by 8
// This is because there are 8 animations for each special.
// One for each direction.
static Special<eRanged_Type> gTableRangedTypes[eRanged_Type_MAX] =
{
    // Zeroes
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },

    // 10-19 Rocks
    { RANGED_Rock, HELP_UNITVIEW_Rock, "CMBMAGIC.LBX", 4 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },

    // 20-29 Missiles
    { RANGED_Arrow, HELP_UNITVIEW_Bow, "CMBMAGIC.LBX", 1 },
    { RANGED_Bullet, eHelpIndex_NONE, "CMBMAGIC.LBX", 5 }, // TODO
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },
    { RANGED_None, eHelpIndex_NONE, "", -1 },

    // 30-39 Magic ranged attack
    { RANGED_Chaos_Lightning, eHelpIndex_NONE, "CMBMAGIC.LBX", 0 },
    { RANGED_Chaos_Fireball, eHelpIndex_NONE, "CMBMAGIC.LBX", 2 },
    { RANGED_Sorcery_Illusion, eHelpIndex_NONE, "CMBMAGIC.LBX", 3 },
    { RANGED_Chaos_Deathbolt, eHelpIndex_NONE, "CMBMAGIC.LBX", 6 },
    { RANGED_Nature_Icebolt, eHelpIndex_NONE, "CMBMAGIC.LBX", 7 },
    { RANGED_Nature_Priest, eHelpIndex_NONE, "CMBMAGIC.LBX", 9 },
    { RANGED_Chaos_Drow, eHelpIndex_NONE, "CMBMAGIC.LBX", 10 },
    { RANGED_Nature_Shimmer, eHelpIndex_NONE, "CMBMAGIC.LBX", 11 },
    { RANGED_Nature_Green, eHelpIndex_NONE, "CMBMAGIC.LBX", 11 },
    { RANGED_None, eHelpIndex_NONE,  "", -1 },

    // TODO
    // 100-109 Thrown/Breath/Gaze
//    RANGED_Thrown_Weapons = 100,
//    RANGED_Fire_Breath = 101,               // (Chaos)
//    RANGED_Lightning_Breath = 102,          // (Chaos)  Sky_Drake
//    RANGED_Stoning_Gaze = 103,              // (Nature) Basilisk, Gorgons (resistance modifier in byte 17)
//    RANGED_Multiple_Gaze = 104,             // (Chaos)  Chaos Spawn
//                                            //          This is actually 3 gazes, including stoning and death
//    RANGED_Death_Gaze = 105,                // (Death)  Night stalker (resistance modifier in byte 17)
};

static Special<eUnitAbility> gTableUnitSpecials[eUnitAbility_MAX] =
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
    { UNITABILITY_Automatic_Damage, HELP_SPECIAL2_CHAOS, "SPECIAL2.LBX", 29 },
    { UNITABILITY_Destruction, HELP_SPECIAL2_DESTRUCTION, "SPECIAL2.LBX", 5 },
    { UNITABILITY_Illusionary_attack, HELP_SPECIAL_ILLUSION, "SPECIAL.LBX", 35 },
    { UNITABILITY_Stoning_Touch, HELP_SPECIAL_STONING_TOUCH, "SPECIAL.LBX", 27 },

    { UNITABILITY_No_effect05, eHelpIndex_NONE, "", -1 },
    { UNITABILITY_Death_Touch, HELP_SPECIAL2_CAUSE_DEATH, "SPECIAL2.LBX", 30 },
    { UNITABILITY_Power_Drain, HELP_SPECIAL2_POWER_DRAIN, "SPECIAL2.LBX", 31 },
    { UNITABILITY_Dispel_Evil, HELP_SPECIAL2_DISPEL_EVIL, "SPECIAL.LBX", 22 },
    { UNITABILITY_Ball_COMBAT, eHelpIndex_NONE, "", -1 },
    { UNITABILITY_Simultaneous_Damage_COMBAT, eHelpIndex_NONE, "", -1 },
    { UNITABILITY_Eldritch_Weapon_COMBAT, HELP_SPECIAL_ELDRITCH_WEAPON, "SPECIAL.LBX", 84 },
    { UNITABILITY_Warp_Lightning_COMBAT, eHelpIndex_NONE, "", -1 },
};

static Special<eUnitEnchantment> gTableUnitEnchantments[eUnitEnchantment_MAX] =
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

static Special<eUnitMutation> gTableUnitMutations[eUnitMutation_MAX] =
{
    { UNITMUTATION_Chaos_Channels_Demon_Skin, HELP_SPECIAL_CHAOS_CHANNEL_1, "SPECIAL.LBX", 62 },
    { UNITMUTATION_Chaos_Channels_Demon_Wings, HELP_SPECIAL_CHAOS_CHANNEL_2, "SPECIAL.LBX", 63 },
    { UNITMUTATION_Chaos_Channels_Fiery_Breath, HELP_SPECIAL_CHAOS_CHANNEL_3, "SPECIAL.LBX", 64 },
    { UNITMUTATION_Undead, HELP_SPECIAL2_UNDEAD, "SPECIAL2.LBX", 9 },
    { UNITMUTATION_Stasis_initial, HELP_SPECIAL2_STASIS, "SPECIAL2.LBX", 4 },
    { UNITMUTATION_Stasis_lingering, HELP_SPECIAL2_STASIS, "SPECIAL2.LBX", 4 },
};


const QFont QMoMResources::g_FontSmall("Sans Serif", 10, -1, false);
#ifdef _WIN32
QFont QMoMResources::g_Font("Monotype Corsiva", 11, -1, false);
#else
// Note: attribute italic=true is required for URW Chancery L
QFont QMoMResources::g_Font("URW Chancery L", 12, -1, true);
#endif
const QFont QMoMResources::g_FontFixed("Courier New", 10, -1, false);

QMoMResources* QMoMResources::m_instance = 0;

QMoMResources::QMoMResources(const QMoMGamePtr& game) : m_game()
{
//    int idMoMFont4 = QFontDatabase::addApplicationFont(":/fonts/MoMFont4.ttf");
//    qDebug() << "Loading/setting MoMFont4:" << idMoMFont4;
//    int idMoMFont7 = QFontDatabase::addApplicationFont(":/fonts/MoMFont7.ttf");
//    g_Font = QFont("MoMFont4");

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

        createBuildingAnimations();
        createCitySizeImages();
        createLbxImages("CMBTCITY", m_cmbtcityImages);
        createLbxAnimations("CITYWALL", m_citywallAnimations);
        createFigureAnimations();
        createLbxImages("ITEMISC", m_itemiscImages);
        createLbxImages("ITEMS", m_itemsImages);
        createLairImages();
        createLbxImages("MAPBACK", m_mapBackImages);

        createLbxImages("SPECIAL", m_specialImages);
        QVector<QMoMImagePtr> special2Images;
        createLbxImages("SPECIAL2", special2Images);
        m_specialImages.resize(120 + special2Images.size());
        for(int i = 0; i < special2Images.size(); ++i)
        {
            m_specialImages[120 + i] = special2Images[i];
        }

        // UnitImages are created before SpellImages, because SpellImages uses them
        createUnitImages();
        // m_specialImages and UnitImages should already have been created, because SpellImages uses them
        createSpellImages();
        createLbxImages("CMBGRASS", m_terrainBattleImages);
        createTerrainImages();

        qDebug() << getDateTimeStr() << "<QMoMResources::setGame() end";
    }
}

const QMoMAnimation QMoMResources::getAnimation(const LBXRecordID &lbxRecordID) const
{
    QMoMAnimation animation;
    if (m_game.isNull())
        return animation;
    std::string lbxFile = m_game->getGameDirectory() + "/" + lbxRecordID.lbxTitle + ".LBX";
    MoM::MoMLbxBase lbx;
    if (!lbx.load(lbxFile))
        return animation;
    MoM::convertLbxToImages(lbx.getRecord(lbxRecordID.lbxIndex), lbx.getRecordSize(lbxRecordID.lbxIndex), m_colorTable, animation, lbxRecordID.lbxTitle + toStr(lbxRecordID.lbxIndex));
    return animation;
}

const QMoMAnimation QMoMResources::getAnimation(MoM::eBuilding building) const
{
    QMoMAnimation animation;
    if (inVectorRange(m_buildingAnimations, building))
    {
        animation = m_buildingAnimations[building];
    }
    return animation;
}

const QMoMAnimation QMoMResources::getAnimation(MoM::eRanged_Type rangedType, int heading) const
{
    QMoMAnimation animation;
    if (MoM::toUInt(rangedType) < ARRAYSIZE(gTableRangedTypes))
    {
        int lbxIndex = gTableRangedTypes[rangedType].lbxIndex;
        lbxIndex = lbxIndex * 8 + heading;
        animation = getAnimation(LBXRecordID(gTableRangedTypes[rangedType].lbxFile.c_str(), lbxIndex));
    }
    return animation;
}

const QMoMAnimation QMoMResources::getAnimation(MoM::eUnit_Type unitType, int heading, MoM::eBannerColor bannerColor) const
{
    QMoMAnimation animation;
    if (heading >= 0 && heading < 8)
    {
        int figureIndex = (int)unitType * 8 + heading;
        if (inVectorRange(m_figureAnimations, figureIndex) && m_figureAnimations[figureIndex].size() >= 4)
        {
            animation = m_figureAnimations[figureIndex];
        }

        changeBannerColor(bannerColor, animation);
    }
    else
    {
        if (inVectorRange(m_unitImages, unitType))
        {
            animation.append(m_unitImages[unitType]);
        }
    }

    return animation;
}

const HelpLBXentry* QMoMResources::getHelpEntry(eHelpIndex helpTextNr)
{
    if (0 == m_helpLbx)
    {
        m_helpLbx = QMoMLbxPtr(new MoMLbxBase);
        // Only try to load once and ignore result.
        // We'll check if it's there when we use it.
        if (m_helpLbx->load(m_game->getGameDirectory() + "/" + "HELP.LBX"))
        {
            // TODO: Remove
            //const HelpLBXentry* helpLbxEntries = reinterpret_cast<const HelpLBXentry*>(m_HelpLbx->getRecord(2) + 4);
            //std::cout << "HelpLBXentries" << std::endl;
            //for (size_t i = 0; i < MoM::eHelpIndex_MAX; ++i)
            //{
            //    std::cout << i << "\t" << helpLbxEntries[i].title << "\t" << helpLbxEntries[i].lbxFile << "\t" << helpLbxEntries[i].lbxIndex << std::endl;
            //}
        }
    }

    const HelpLBXentry* helpEntry = (const HelpLBXentry*)m_helpLbx->getSubRecord(2, helpTextNr);

    return helpEntry;
}

std::string QMoMResources::getHelpText(eHelpIndex helpTextNr)
{
    const size_t maxwidth = 60;

    const HelpLBXentry* helpEntry = getHelpEntry(helpTextNr);

    std::string text;
    if (0 != helpEntry)
    {
        const char* title = helpEntry->title;
        const char* description = helpEntry->description;

        text = std::string(title) + ": " + description;
    }

    // Replace code for newline by actual newline
    text = replaceStrInStr(text, "\x14", "\n");

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

std::string QMoMResources::getHelpText(eBuilding building)
{
    return getHelpText((MoM::eHelpIndex)((int)MoM::HELP_cityscap_TRADE_GOODS - (int)MoM::BUILDING_Trade_Goods + (int)building));
}

std::string QMoMResources::getHelpText(eHeroAbility heroAbility)
{
    std::string value;
    if (toUInt(heroAbility) < ARRAYSIZE(gTableHeroSpecials))
    {
        value = getHelpText(gTableHeroSpecials[heroAbility].helpIndex);
    }
    return value;
}

std::string QMoMResources::getHelpText(eItemPower itemPower)
{
    std::string value;
    if (toUInt(itemPower) < ARRAYSIZE(gTableItemSpecials))
    {
        value = getHelpText(gTableItemSpecials[itemPower].helpIndex);
    }
    return value;
}

std::string QMoMResources::getHelpText(ePortrait wizardPortrait)
{
    return getHelpText((MoM::eHelpIndex)((int)MoM::HELP_MERLIN - (int)PORTRAIT_Merlin + (int)wizardPortrait));
}

std::string QMoMResources::getHelpText(eRace race)
{
    return getHelpText((MoM::eHelpIndex)(MoM::HELP_BARBARIAN_TOWNSFOLK + (int)race)) + "\n"
        + getHelpText((MoM::eHelpIndex)(MoM::HELP_BACKGRND_Barbarian_Farmers + (int)race)) + "\n"
        + getHelpText((MoM::eHelpIndex)(MoM::HELP_BACKGRND_Barbarian_Workers + (int)race)) + "\n"
        + getHelpText((MoM::eHelpIndex)(MoM::HELP_BACKGRND_Barbarian_Rebels + (int)race));

}

std::string QMoMResources::getHelpText(eRanged_Type rangedType)
{
    eHelpIndex helpIndex = eHelpIndex_NONE;

    switch (rangedType)
    {
    case RANGED_None:                   break;

    case RANGED_Rock:                   helpIndex = HELP_UNITVIEW_Rock; break;

    case RANGED_Arrow:
    case RANGED_Bullet:                 helpIndex = HELP_UNITVIEW_Bow; break;

    case RANGED_Chaos_Lightning:
    case RANGED_Chaos_Fireball:
    case RANGED_Sorcery_Illusion:
    case RANGED_Chaos_Deathbolt:
    case RANGED_Nature_Icebolt:
    case RANGED_Nature_Priest:
    case RANGED_Chaos_Drow:
    case RANGED_Nature_Shimmer:
    case RANGED_Nature_Green:           helpIndex = HELP_UNITVIEW_Magical_Attack; break;

    case RANGED_Thrown_Weapons:         helpIndex = HELP_SPECIAL2_THROWN; break;
    case RANGED_Fire_Breath:            helpIndex = HELP_SPECIAL2_FIRE_BREATH; break;
    case RANGED_Lightning_Breath:       helpIndex = HELP_SPECIAL2_LIGHTNING_BREATH; break;
    case RANGED_Stoning_Gaze:           helpIndex = HELP_SPECIAL_STONING_GAZE; break;
    case RANGED_Multiple_Gaze:          helpIndex = HELP_SPECIAL2_DOOM_GAZE; break;
    case RANGED_Death_Gaze:             helpIndex = HELP_SPECIAL2_DEATH_GAZE; break;

    default:                            break;
    }

    std::string value = getHelpText(helpIndex);

    return value;
}

const HelpLBXentry* QMoMResources::getHelpEntry(eSpell spell)
{
    const HelpLBXentry* value = 0;
    if ((spell >= 1) && (spell < eSpell_MAX))
    {
        eHelpIndex helpIndex = (MoM::eHelpIndex)(0 + spell);
        value = getHelpEntry(helpIndex);
    }
    return value;
}

std::string QMoMResources::getHelpText(eSpell spell)
{
    std::string value;
    if ((spell >= 1) && (spell < eSpell_MAX))
    {
        eHelpIndex helpIndex = (MoM::eHelpIndex)(0 + spell);
        value = getHelpText(helpIndex);
    }
    return value;
}

std::string QMoMResources::getHelpText(eUnitAbility unitAbility)
{
    std::string value;
    if (toUInt(unitAbility) < ARRAYSIZE(gTableUnitSpecials))
    {
        value = getHelpText(gTableUnitSpecials[unitAbility].helpIndex);
    }
    return value;
}

std::string QMoMResources::getHelpText(eUnitEnchantment unitEnchantment)
{
    std::string value;
    if (toUInt(unitEnchantment) < ARRAYSIZE(gTableUnitEnchantments))
    {
        value = getHelpText(gTableUnitEnchantments[unitEnchantment].helpIndex);
    }
    return value;
}

std::string QMoMResources::getHelpText(eUnitMutation unitMutation)
{
    std::string value;
    if (toUInt(unitMutation) < ARRAYSIZE(gTableUnitMutations))
    {
        value = getHelpText(gTableUnitMutations[unitMutation].helpIndex);
    }
    return value;
}

const QMoMImagePtr QMoMResources::getImage(const LBXRecordID &lbxRecordID) const
{
    QMoMImagePtr image;
    if (m_game.isNull())
        return image;
    std::string lbxFile = m_game->getGameDirectory() + "/" + lbxRecordID.lbxTitle + ".LBX";
    MoM::MoMLbxBase lbx;
    if (!lbx.load(lbxFile))
        return image;
    image = MoM::convertLbxToImage(lbx.getRecord(lbxRecordID.lbxIndex), lbx.getRecordSize(lbxRecordID.lbxIndex), m_colorTable, lbxRecordID.lbxTitle + toStr(lbxRecordID.lbxIndex));
    return image;
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

const QMoMImagePtr QMoMResources::getImage(MoM::eBuilding building) const
{
    QMoMImagePtr image;
    if (inVectorRange(m_buildingAnimations, building) && !m_buildingAnimations[building].empty())
    {
        image = m_buildingAnimations[building].at(0);
    }
    return image;
}

const QMoMImagePtr QMoMResources::getImage(MoM::eCentralStructure structure) const
{
    static const int lookup[MoM::eCentralStructure_MAX] =
    {
        -1, // CENTRALSTRUCTURE_none,
        18, // CENTRALSTRUCTURE_outpost,
        0,  // CENTRALSTRUCTURE_city_grid,
        17, // CENTRALSTRUCTURE_wizards_fortress,
        21, // CENTRALSTRUCTURE_small_tower,
        20, // CENTRALSTRUCTURE_tower_between_planes,
        19, // CENTRALSTRUCTURE_cave,
        23, // CENTRALSTRUCTURE_temple,
        22, // CENTRALSTRUCTURE_medium_tower,
        66, // CENTRALSTRUCTURE_sorcery_node,   ANIMATION
        120, // CENTRALSTRUCTURE_chaos_node,     ANIMATION - located in another LBX file
        65, // CENTRALSTRUCTURE_nature_node,    ANIMATION
        121,// CENTRALSTRUCTURE_ruins,
    };

    int index = -1;
    if (MoM::toUInt(structure) < ARRAYSIZE(lookup))
    {
        index = lookup[structure];
    }
    QMoMImagePtr image;
    if (CENTRALSTRUCTURE_chaos_node == structure)
    {
        image = getImage(LBXRecordID("CHRIVER", 24));
    }
    else if (inVectorRange(m_cmbtcityImages, index))
    {
        image = m_cmbtcityImages[index];
    }
    return image;
}

const QMoMImagePtr QMoMResources::getImage(MoM::eCity_Size citySize, MoM::eBannerColor bannerColor) const
{
    QMoMImagePtr image;
    int index = (int)citySize - 1;
    if (index < 0)
    {
        index = 0;  // Treat outpost as hamlet
    }
    if (inVectorRange(m_citySizeImages, index))
    {
        image = m_citySizeImages[index];
    }

    changeBannerColor(bannerColor, image);

    return image;
}

const QMoMImagePtr QMoMResources::getImage(MoM::eCityWall wall, bool broken) const
{
    QMoMImagePtr image;
    if (inVectorRange(m_citywallAnimations, wall) && (m_citywallAnimations[wall].size() >= 2))
    {
        image = m_citywallAnimations[wall].at((int)broken);
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

const QMoMImagePtr QMoMResources::getImage(MoM::eRanged_Type rangedType, int heading) const
{
    QMoMAnimation animation = getAnimation(rangedType, heading);
    QMoMImagePtr image;
    if (animation.count() > 2)
    {
        image = animation[2];
    }
    return image;
}

const QMoMImagePtr QMoMResources::getImage(eSlot_Type8 slotType) const
{
    return getImage((MoM::eSlot_Type16)slotType);
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

const QMoMImagePtr QMoMResources::getImage(MoM::eTerrainBattle terrain) const
{
    QMoMImagePtr image;
    if (inVectorRange(m_terrainBattleImages, terrain))
    {
        image = m_terrainBattleImages[terrain];
    }
    return image;
}

const QMoMImagePtr QMoMResources::getImage(MoM::eTerrainBonusDeposit bonusDeposit) const
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

const QMoMImagePtr QMoMResources::getImage(MoM::eTerrainChange terrainChange, int roadDirection) const
{
    QMoMImagePtr image;
    unsigned index = -1;
    switch (terrainChange)
    {
//    case TERRAINCHANGE_Volcano_owner:   index = 77; break;
    case TERRAINCHANGE_Road:            index = 45 + roadDirection; break;  // 45-53
    case TERRAINCHANGE_Enchanted_Road:  index = 54 + roadDirection; break;  // 54-62
    case TERRAINCHANGE_Corruption:      index = 76; break;
    default:                    break;
    }
    if (inVectorRange(m_mapBackImages, index))
    {
        image = m_mapBackImages[index];
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

const QMoMImagePtr QMoMResources::getImage(MoM::eUnit_Type unitType, int heading, MoM::eBannerColor bannerColor) const
{
    QMoMAnimation animation = getAnimation(unitType, heading, bannerColor);
    QMoMImagePtr image;
    if (animation.count() > 1)
    {
        image = animation[1];
    }
    else if (animation.count() > 0)
    {
        image = animation[0];
    }

    return image;
}

void QMoMResources::changeBannerColor(MoM::eBannerColor bannerColor, QMoMAnimation& animation) const
{
    for (int i = 0; i < animation.count(); ++i)
    {
        changeBannerColor(bannerColor, animation[i]);
    }
}

void QMoMResources::changeBannerColor(MoM::eBannerColor bannerColor, QMoMImagePtr& image) const
{
    const int gCOLORS_IN_BANNERS[MoM::eBannerColor_MAX][gCOUNT_BANNER_COLOR] =
    {
        // From dseg:56E8
        {97, 98, 99, 100},
        {66, 67, 68, 69},
        {33, 34, 35, 36},
        {201, 202, 203, 166},
        {160, 161, 162, 163},
        {28, 27, 26, 25},
    };

    if ((BANNER_Green != bannerColor) && (0 != image) && (image->colorCount() >= gFIRST_BANNER_COLOR + gCOUNT_BANNER_COLOR))
    {
        image = QMoMImagePtr(new QImage(*image));
        for (int i = 0; i < gCOUNT_BANNER_COLOR; ++i)
        {
            image->setColor(gFIRST_BANNER_COLOR + i, image->color(gCOLORS_IN_BANNERS[bannerColor][i]));
        }
    }
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

void QMoMResources::createBuildingAnimations()
{
    if (m_game.isNull())
        return;
    std::string lbxFile = m_game->getGameDirectory() + "/" + "CITYSCAP.LBX";
    MoM::MoMLbxBase lbx;
    if (!lbx.load(lbxFile))
        return;
    m_buildingAnimations.resize(lbx.getNrRecords());
    for (MoM::eBuilding building = (MoM::eBuilding)1; building < MoM::eBuilding_array_MAX; MoM::inc(building))
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

        MoM::convertLbxToImages(lbx.getRecord(recordNr), lbx.getRecordSize(recordNr), m_colorTable, m_buildingAnimations[building], toStr(building));
    }
}

void QMoMResources::createCitySizeImages()
{
    if (m_game.isNull())
        return;
    std::string lbxFile = m_game->getGameDirectory() + "/" + "MAPBACK.LBX";
    MoM::MoMLbxBase lbx;
    if (!lbx.load(lbxFile))
        return;
    QMoMAnimation citySizeAnimation;
    MoM::convertLbxToImages(lbx.getRecord(20), lbx.getRecordSize(20), m_colorTable, citySizeAnimation, "city sizes");
    m_citySizeImages.resize(citySizeAnimation.count());
    for (int i = 0; i < citySizeAnimation.count(); ++i)
    {
        m_citySizeImages[i] = citySizeAnimation[i];
    }
}

void QMoMResources::createFigureAnimations()
{
    int firstUnused = 0;
    // Reserve fir 16 files with max 120 images per file
    int sizeReserved = 16 * 120;
    m_figureAnimations.resize(sizeReserved);
    for (int fileNr = 1; fileNr <= 16; ++fileNr)
    {
        std::string lbxTitle;
        if (fileNr < 10)
        {
            lbxTitle = "FIGURES" + toStr(fileNr);
        }
        else
        {
            lbxTitle = "FIGURE" + toStr(fileNr);
        }
        QVector<QMoMAnimation> tmpAnimations;
        (void)createLbxAnimations(lbxTitle, tmpAnimations);
        for(int i = 0; (i < tmpAnimations.size()) && (firstUnused + i < sizeReserved); ++i)
        {
            m_figureAnimations[firstUnused + i] = tmpAnimations[i];
        }
        firstUnused += tmpAnimations.size();
    }
    m_figureAnimations.resize(firstUnused);
}

void QMoMResources::createLairImages()
{
    if (m_game.isNull())
        return;
    std::string lairsLbxFile = m_game->getGameDirectory() + "/" + "RELOAD.LBX";
    MoM::MoMLbxBase lairsLbx;
    if (!lairsLbx.load(lairsLbxFile))
        return;
    m_lairImages.resize(MoM::eTower_Node_Lair_Type_MAX);
    for (size_t i = 0; i < MoM::eTower_Node_Lair_Type_MAX; ++i)
    {
        m_lairImages[i] = MoM::convertLbxToImage(lairsLbx.getRecord(9 + i), lairsLbx.getRecordSize(9 + i), m_colorTable, toStr((MoM::eTower_Node_Lair_Type)i));
    }
}

void QMoMResources::createLbxAnimations(const std::string& lbxTitle, QVector<QMoMAnimation>& vecAnimations)
{
    if (m_game.isNull())
        return;
    std::string lbxFile = m_game->getGameDirectory() + "/" + lbxTitle + ".LBX";
    MoM::MoMLbxBase lbx;
    if (!lbx.load(lbxFile))
        return;
    vecAnimations.resize(lbx.getNrRecords());
    for (size_t i = 0; i < lbx.getNrRecords(); ++i)
    {
        (void)MoM::convertLbxToImages(lbx.getRecord(i), lbx.getRecordSize(i), m_colorTable, vecAnimations[i], lbxTitle + toStr(i));
    }
}

void QMoMResources::createLbxImages(const std::string& lbxTitle, QVector<QMoMImagePtr>& vecImages)
{
    if (m_game.isNull())
        return;
    std::string lbxFile = m_game->getGameDirectory() + "/" + lbxTitle + ".LBX";
    MoM::MoMLbxBase lbx;
    if (!lbx.load(lbxFile))
        return;
    vecImages.resize(lbx.getNrRecords());
    for (size_t i = 0; i < lbx.getNrRecords(); ++i)
    {
        vecImages[i] = MoM::convertLbxToImage(lbx.getRecord(i), lbx.getRecordSize(i), m_colorTable, lbxTitle + toStr(i));
    }
}

void QMoMResources::createSpellImages()
{
    // PRE: UnitImages should already have been created, because SpellImages uses them

    if (m_game.isNull())
        return;
    std::string cityscapLbxFile = m_game->getGameDirectory() + "/" + "CITYSCAP.LBX";
    std::string monsterLbxFile = m_game->getGameDirectory() + "/" + "MONSTER.LBX";
    std::string specfxLbxFile = m_game->getGameDirectory() + "/" + "SPECFX.LBX";
    MoM::MoMLbxBase cityscapLbx;
    MoM::MoMLbxBase monsterLbx;
    MoM::MoMLbxBase specfxLbx;
    if (!cityscapLbx.load(cityscapLbxFile))
        return;
    if (!monsterLbx.load(monsterLbxFile))
        return;
    if (!specfxLbx.load(specfxLbxFile))
        return;

    m_spellImages.resize(MoM::eSpell_MAX);

    // MONSTER.LBX, UNITS1.LBX, UNITS2.LBX
    for (MoM::eSpell spell = (MoM::eSpell)0; spell < MoM::eSpell_MAX; MoM::inc(spell))
    {
        const HelpLBXentry* helpEntry = getHelpEntry(spell);
        if (0 != helpEntry)
        {
            if (std::string(helpEntry->lbxFile) == std::string("SPECIAL.LBX"))
            {
                if (inVectorRange(m_specialImages, helpEntry->lbxIndex))
                {
                    m_spellImages[spell] = m_specialImages[helpEntry->lbxIndex];
                }
            }
            else if (std::string(helpEntry->lbxFile) == std::string("SPECIAL2.LBX"))
            {
                if (inVectorRange(m_specialImages, 120 + helpEntry->lbxIndex))
                {
                    m_spellImages[spell] = m_specialImages[120 + helpEntry->lbxIndex];
                }
            }
        }

        MoM::Spell_Data* spellData = m_game->getSpellData(spell);
        if ((0 != spellData) && (MoM::SPELLCATEGORY_Normal_summon == spellData->m_Spell_Category))
        {
            m_spellImages[spell] = m_unitImages[ spellData->m_Parameters[0] ];
        }
    }

    MoM::eSpell spell;

    // CITYSCAP.LBX
    spell = MoM::SPELL_Summoning_Circle;
    m_spellImages[spell] = MoM::convertLbxToImage(cityscapLbx.getRecord(6), cityscapLbx.getRecordSize(6), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Altar_of_Battle;
    m_spellImages[spell] = MoM::convertLbxToImage(cityscapLbx.getRecord(12), cityscapLbx.getRecordSize(12), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Dark_Rituals;
    m_spellImages[spell] = MoM::convertLbxToImage(cityscapLbx.getRecord(81), cityscapLbx.getRecordSize(81), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Earth_Gate;
    m_spellImages[spell] = MoM::convertLbxToImage(cityscapLbx.getRecord(83), cityscapLbx.getRecordSize(83), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Stream_of_Life;
    m_spellImages[spell] = MoM::convertLbxToImage(cityscapLbx.getRecord(84), cityscapLbx.getRecordSize(84), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Astral_Gate;
    m_spellImages[spell] = MoM::convertLbxToImage(cityscapLbx.getRecord(85), cityscapLbx.getRecordSize(85), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Spell_Ward;
    m_spellImages[spell] = MoM::convertLbxToImage(cityscapLbx.getRecord(96), cityscapLbx.getRecordSize(96), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Inspirations;
    m_spellImages[spell] = MoM::convertLbxToImage(cityscapLbx.getRecord(100), cityscapLbx.getRecordSize(100), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Prosperity;
    m_spellImages[spell] = MoM::convertLbxToImage(cityscapLbx.getRecord(101), cityscapLbx.getRecordSize(101), m_colorTable, toStr(spell));
//    spell = MoM::SPELL_; // Mana cross
//    m_spellImages[spell] = MoM::convertLbxToImage(cityscapLbx.getRecord(102), cityscapLbx.getRecordSize(102), m_colorTable, toStr(spell));

    // MONSTER.LBX
    spell = MoM::SPELL_Summon_Hero;
    m_spellImages[spell] = MoM::convertLbxToImage(monsterLbx.getRecord(45), monsterLbx.getRecordSize(45), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Summon_Champion;
    m_spellImages[spell] = MoM::convertLbxToImage(monsterLbx.getRecord(44), monsterLbx.getRecordSize(44), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Enchant_Item;
    m_spellImages[spell] = MoM::convertLbxToImage(monsterLbx.getRecord(46), monsterLbx.getRecordSize(46), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Create_Artifact;
    m_spellImages[spell] = MoM::convertLbxToImage(monsterLbx.getRecord(46), monsterLbx.getRecordSize(46), m_colorTable, toStr(spell));

    // SPECFX.LBX
    spell = MoM::SPELL_Eternal_Night;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(15), specfxLbx.getRecordSize(15), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Evil_Omens;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(16), specfxLbx.getRecordSize(16), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Zombie_Mastery;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(17), specfxLbx.getRecordSize(17), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Aura_of_Majesty;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(18), specfxLbx.getRecordSize(18), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Wind_Mastery;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(19), specfxLbx.getRecordSize(19), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Suppress_Magic;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(20), specfxLbx.getRecordSize(20), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Time_Stop;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(21), specfxLbx.getRecordSize(21), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Nature_Awareness;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(22), specfxLbx.getRecordSize(22), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Natures_Wrath;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(23), specfxLbx.getRecordSize(23), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Herb_Mastery;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(24), specfxLbx.getRecordSize(24), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Chaos_Surge;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(25), specfxLbx.getRecordSize(25), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Doom_Mastery;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(26), specfxLbx.getRecordSize(26), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Great_Wasting;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(27), specfxLbx.getRecordSize(27), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Meteor_Storm;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(28), specfxLbx.getRecordSize(28), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Armageddon;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(29), specfxLbx.getRecordSize(29), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Tranquility;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(30), specfxLbx.getRecordSize(30), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Life_Force;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(31), specfxLbx.getRecordSize(31), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Crusade;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(32), specfxLbx.getRecordSize(32), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Just_Cause;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(33), specfxLbx.getRecordSize(33), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Holy_Arms;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(34), specfxLbx.getRecordSize(34), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Planar_Seal;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(35), specfxLbx.getRecordSize(35), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Charm_of_Life;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(36), specfxLbx.getRecordSize(36), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Detect_Magic;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(37), specfxLbx.getRecordSize(37), m_colorTable, toStr(spell));

    spell = MoM::SPELL_Death_Wish;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(38), specfxLbx.getRecordSize(38), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Great_Unsummoning;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(39), specfxLbx.getRecordSize(39), m_colorTable, toStr(spell));
    spell = MoM::SPELL_Awareness;
    m_spellImages[spell] = MoM::convertLbxToImage(specfxLbx.getRecord(56), specfxLbx.getRecordSize(56), m_colorTable, toStr(spell));


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
}

void QMoMResources::createTerrainImages()
{
    if (m_game.isNull())
        return;
    std::string terrainLbxFile = m_game->getGameDirectory() + "/" + "TERRAIN.LBX";
    MoM::MoMLbxBase terrainLbx;
    if (!terrainLbx.load(terrainLbxFile))
        return;
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

        m_terrainTypeImages[terrainNr] = MoM::convertLbxToImage(data + i * 0x0180, terrainLbx.getRecordSize(0), m_colorTable, toStr(terrainNr) + "-" + toStr(i));

        i += 888;   // Myrror
        if (i > 906) i -= 3; // No animation
        if (i > 919) i -= 3;
        if (i > 920) i -= 3;
        if (i > 921) i -= 3;
        if (i > 990) i -= 3;

        m_terrainTypeImages[MoM::eTerrainType_MAX + terrainNr] = MoM::convertLbxToImage(data + i * 0x0180, terrainLbx.getRecordSize(0), m_colorTable, toStr(terrainNr) + "-" + toStr(i));
    }
}

void QMoMResources::createUnitImages()
{
    if (m_game.isNull())
        return;
    std::string units1LbxFile = m_game->getGameDirectory() + "/" + "UNITS1.LBX";
    std::string units2LbxFile = m_game->getGameDirectory() + "/" + "UNITS2.LBX";
    std::string monsterLbxFile = m_game->getGameDirectory() + "/" + "MONSTER.LBX";
    MoM::MoMLbxBase units1Lbx;
    MoM::MoMLbxBase units2Lbx;
    MoM::MoMLbxBase monsterLbx;
    if (!units1Lbx.load(units1LbxFile))
        return;
    if (!units2Lbx.load(units2LbxFile))
        return;
    if (!monsterLbx.load(monsterLbxFile))
        return;

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
            m_unitImages[unitType] = MoM::convertLbxToImage(units1Lbx.getRecord(unitType), units1Lbx.getRecordSize(unitType), m_colorTable, toStr(unitType));
        }
        else
        {
            m_unitImages[unitType] = MoM::convertLbxToImage(units2Lbx.getRecord(unitType - 120), units2Lbx.getRecordSize(unitType - 120), m_colorTable, toStr(unitType));
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
            m_unitImages[unitType] = MoM::convertLbxToImage(monsterLbx.getRecord(i), monsterLbx.getRecordSize(i), m_colorTable, toStr(unitType));
        }
    }
}

}