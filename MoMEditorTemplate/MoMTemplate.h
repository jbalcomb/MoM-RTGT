// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file
/// \brief      Defines enums and structs for mapping memory of Master of Magic

#ifndef MOMTEMPLATE_H
#define MOMTEMPLATE_H

#include "MoMcommon.h"

#define SetBackColor(c)     // Macro to suppress info related to the program 010-EditorTemplate

// Specify to pack structures
#ifdef _MSC_VER     // Compiler MS Visual Studio
#pragma pack(push, 1)
#define PACKED_STRUCT
#endif

#ifdef __linux__     // Compiler Linux g++
#define PACKED_STRUCT __attribute__((packed))
#endif

#ifdef __MINGW_GCC  // Compiler MinGW
#pragma pack(push, 1)
#pragma pack(1)
#define PACKED_STRUCT __attribute__((packed))
#endif

// Specify to use short enums
#ifdef _MSC_VER     // Compiler MS Visual Studio
#pragma warning( once : 4480 )  // nonstandard extension used: specifying underlying type for enum
#define ENUMSIZE8       : uint8_t
#define ENUMSIZE16      : uint16_t
#endif

#ifdef __GNUC__     // Compiler Linux g++ (use g++ -fshort-enums)
#define ENUMSIZE8
#define ENUMSIZE16
#endif

namespace MoM {

//
// ENUMS
//

enum eBannerColor ENUMSIZE16
{
    BANNER_Blue = 0,
    BANNER_Green = 1,
    BANNER_Purple = 2,
    BANNER_Red = 3,
    BANNER_Yellow = 4,
    BANNER_Brown = 5,
    eBannerColor__SIZE__ = 0xFFFF
};

enum eBonusDeposit ENUMSIZE8
{
    DEPOSIT_no_deposit = 0x00,
    DEPOSIT_Iron_Ore = 0x01, // (-5% unit cost)
    DEPOSIT_Coal = 0x02, // (-10% unit cost)
    DEPOSIT_Silver_Ore = 0x03, // (+2 gold)
    DEPOSIT_Gold_Ore = 0x04, // (+3 gold)
    DEPOSIT_Gems = 0x05, // (+5 gold)
    DEPOSIT_Mithril_Ore = 0x06, // (+1 mana)
    DEPOSIT_Adamantium_Ore = 0x07, // (+2 mana)
    DEPOSIT_Quork = 0x08, // (+3 mana)
    DEPOSIT_Crysx = 0x09, // (+5 mana)
    DEPOSIT_Wild_Game = 0x40, // (+2 food)
    DEPOSIT_Nightshade = 0x80, // (50 strength dispel)
};

enum eBuilding ENUMSIZE16
{
    BUILDING_Not_applicable = 0xFFFF,

    BUILDING_None = 0,           // 0

    BUILDING_Trade_Goods,        // 1
    BUILDING_Housing,            // 2

    BUILDING_Barracks,           // 3
    BUILDING_Armory,
    BUILDING_Fighters_Guild,
    BUILDING_Armorers_Guild,
    BUILDING_War_College,
    BUILDING_Smithy,
    BUILDING_Stable,
    BUILDING_Animists_Guild,     // 10
    BUILDING_Fantastic_Stable,
    BUILDING_Shipwright_Guild,
    BUILDING_Ship_Yard,
    BUILDING_Maritime_Guild,
    BUILDING_Sawmill,
    BUILDING_Library,
    BUILDING_Sages_Guild,
    BUILDING_Oracle,
    BUILDING_Alchemist_Guild,
    BUILDING_University,         // 20
    BUILDING_Wizards_Guild,
    BUILDING_Shrine,
    BUILDING_Temple,
    BUILDING_Parthenon,
    BUILDING_Cathedral,
    BUILDING_Marketplace,
    BUILDING_Bank,
    BUILDING_Merchants_Guild,
    BUILDING_Granary,
    BUILDING_Farmers_Market,     // 30
    BUILDING_Foresters_Guild,
    BUILDING_Builders_Hall,
    BUILDING_Mechanicians_Guild,
    BUILDING_Miners_Guild,
    BUILDING_City_Walls,         // 35

    eBuilding_MAX,      // 36
    eBuilding__SIZE__ = 0xFFFF
};

enum eBuildingStatus ENUMSIZE8
{
    BUILDINGSTATUS_Not_Built = 0xFF,
    BUILDINGSTATUS_Replaced = 0,
    BUILDINGSTATUS_Built = 1,
    BUILDINGSTATUS_Destroyed = 2,
    eBuildingStatus__SIZE__ = 0xFF
};

enum eCity_Size ENUMSIZE8
{
    CITYSIZE_Outpost = 0,
    CITYSIZE_Hamlet = 1,
    CITYSIZE_Village = 2,
    CITYSIZE_Town = 3,
    CITYSIZE_City = 4,
    CITYSIZE_Capital = 5,
};

enum eDifficulty ENUMSIZE16
{
    DIFFICULTY_Tutorial = 0,
    DIFFICULTY_Easy = 1,
    DIFFICULTY_Normal = 2,
    DIFFICULTY_Hard = 3,
    DIFFICULTY_Impossible = 4,

    eDifficulty_MAX = 5,
    eDifficulty__SIZE__ = 0xFFFF
};

enum eEvent
{
    EVENT_Meteor              = 0,
    EVENT_Gift_from_the_Gods  = 1,
    EVENT_Disjunction         = 2,
    EVENT_Diplomatic_Marriage  = 3,
    EVENT_Earthquake          = 4,
    EVENT_Pirates             = 5,
    EVENT_Plague              = 6,
    EVENT_Rebellion           = 7,
    EVENT_Donation            = 8,
    EVENT_Depletion           = 9,
    EVENT_Mine_found          = 10,
    EVENT_Population_Boom     = 11,
    EVENT_Good_Moon           = 12,
    EVENT_Bad_Moon            = 13,
    EVENT_Conjunction_Sorcery  = 14,
    EVENT_Conjunction_Nature  = 15,
    EVENT_Conjunction_Chaos   = 16,
    EVENT_Mana_Short          = 17,
};

enum eGameState ENUMSIZE16
{
    STATE_City_display = 0,
    STATE_Game = 1,
    STATE_Armies = 2,
    STATE_Cities = 3,
    STATE_Exit = 4,
    STATE_Main = 5,
    STATE_Magic = 6,
    STATE_Road_Building_You = 7,
    STATE_Change = 8,
    STATE_Item_You = 9, 
    STATE_Next_turn_seq = 10,
    STATE_11_default = 11,
    STATE_Spells = 12,
    STATE_13_default = 13,
    STATE_Info = 14,
    STATE_Diplomacy = 15,
    STATE_Computers_turn_GUESS = 0xFFFF
};

enum eGrand_Vizier ENUMSIZE16
{
    GRANDVIZIER_Off = 0,
    GRANDVIZIER_On = 1,
    eGrand_Vizier__SIZE__ = 0xFFFF
};

enum eHero_Level_Status ENUMSIZE16
{
    HEROLEVELSTATUS_Level_1 = 0,
    HEROLEVELSTATUS_Level_2 = 1,
    HEROLEVELSTATUS_Level_3 = 2,
    HEROLEVELSTATUS_Level_4 = 3,
    HEROLEVELSTATUS_Level_5 = 4,
    HEROLEVELSTATUS_Level_6 = 5,
    HEROLEVELSTATUS_Level_7 = 6,
    HEROLEVELSTATUS_Level_8 = 7,
    HEROLEVELSTATUS_Level_9 = 8,
    HEROLEVELSTATUS_Dead_Level_1 = 0xFFFF,
    HEROLEVELSTATUS_Dead_Level_2 = 0xFFFE,
    HEROLEVELSTATUS_Dead_Level_3 = 0xFFFD,
    HEROLEVELSTATUS_Dead_Level_4 = 0xFFFC,
    HEROLEVELSTATUS_Dead_Level_5 = 0xFFFB,
    HEROLEVELSTATUS_Dead_Level_6 = 0xFFFA,
    HEROLEVELSTATUS_Dead_Level_7 = 0xFFF9,
    HEROLEVELSTATUS_Dead_Level_8 = 0xFFF8,
    HEROLEVELSTATUS_Dead_Level_9 = 0xFFF7,
    HEROLEVELSTATUS_Active_in_Wizards_army = 0xFFEC,
};

enum eHero_TypeCode ENUMSIZE8
{
    HEROTYPE_Fighter = 0,
    HEROTYPE_Bow = 1,
    HEROTYPE_Fighter_Wizard = 2,
    HEROTYPE_Wizard = 3
};

enum eItem_Icon ENUMSIZE16
{
          //0x00     0x08      Sword
    Sword_1 = 0x00, Sword_2, Sword_3, Sword_4, Sword_5, Sword_6, Sword_7, Sword_8, Sword_9,
          //0x09     0x13      Mace
    Mace_01 = 0x09, Mace_02, Mace_03, Mace_04, Mace_05, Mace_06, Mace_07, Mace_08, Mace_09, Mace_10, Mace_11,
          //0x14     0x1C      Axe
    Axe_1 = 0x14, Axe_2, Axe_3, Axe_4, Axe_5, Axe_6, Axe_7, Axe_8, Axe_9,
          //0x1D     0x25      Bow
    Bow_1 = 0x1D, Bow_2, Bow_3, Bow_4, Bow_5, Bow_6, Bow_7, Bow_8, Bow_9,
          //0x26     0x2E      Staff
    Staff_1 = 0x26, Staff_2, Staff_3, Staff_4, Staff_5, Staff_6, Staff_7, Staff_8, Staff_9,
          //0x2F     0x36      Chain Mail
    Chain_1 = 0x2F, Chain_2, Chain_3, Chain_4, Chain_5, Chain_6, Chain_7, Chain_8, 
          // 0x37     0x3D      Plate Mail
    Plate_1 = 0x37, Plate_2, Plate_3, Plate_4, Plate_5, Plate_6, Plate_7,
          // 0x3E     0x47      Shield (Note: Icon 0x46 and 0x47 are identical)
    Shield_1 = 0x3E,
          // 0x48     0x49      Pendant
    Pendant_1 = 0x48,
          // 0x4A     0x4D      Brooch
    Brooch_1 = 0x4A,
          // 0x4E     0x53      Ring
    Ring_1 = 0x4E,
          // 0x54     0x59      Cloak
    Cloak_1 = 0x54,
          // 0x5A     0x5D      Gauntlet
    Gauntlet_1 = 0x5A,
          // 0x5E     0x64      Helmet
    Helmet_1 = 0x5E,
          // 0x65     0x6A      Orb
    Orb_1 = 0x65,
          // 0x6B     0x73      Wand
    Wand_1 = 0x6B, Wand_2, Wand_3, Wand_4, Wand_5, Wand_6, Wand_7, Wand_8,

    eItem_Icon_MAX,
    eItem_Icon__SIZE__ = 0xFFFF
};


enum eItem_Type ENUMSIZE8
{
    ITEMTYPE_Sword,
    ITEMTYPE_Mace,
    ITEMTYPE_Axe,
    ITEMTYPE_Bow,
    ITEMTYPE_Staff,
    ITEMTYPE_Wand,
    ITEMTYPE_Various,
    ITEMTYPE_Shield,
    ITEMTYPE_Chain_Mail,
    ITEMTYPE_Plate_Mail,
    eItem_Type__SIZE__ = 0xFF
};

enum eLand_Size ENUMSIZE16
{
    LANDSIZE_Small,
    LANDSIZE_Medium,
    LANDSIZE_Large,

    eLand_Size_MAX,
    eLand_Size__SIZE__ = 0xFFFF
};

enum eLevel ENUMSIZE8
{
    LEVEL_Level_1 = 0,
    LEVEL_Level_2 = 1,
    LEVEL_Level_3 = 2,
    LEVEL_Level_4 = 3,
    LEVEL_Level_5 = 4,
    LEVEL_Level_6 = 5,
    LEVEL_Level_7 = 6,
    LEVEL_Level_8 = 7,
    LEVEL_Level_9 = 8,
};

enum eMagic_Powerful ENUMSIZE16
{
    MAGICPOWERFUL_Weak,
    MAGICPOWERFUL_Normal,
    MAGICPOWERFUL_Powerful,

    eMagic_Powerful_Size__SIZE__ = 0xFFFF
};

enum eTower_Node_Lair_Status ENUMSIZE8
{
    LAIRSTATUS_popped = 0,
    LAIRSTATUS_intact = 1,
}; 

enum eTower_Node_Lair_Type ENUMSIZE8
{
    // As yet this list is incomplete
    LAIRTYPE_Tower = 0,
    LAIRTYPE_Chaos_node = 1,
    LAIRTYPE_Nature_node = 2,
    LAIRTYPE_Sorcery_node = 3,
    LAIRTYPE_Mysterious_cave = 4,
    LAIRTYPE_Dungeon = 5,
    LAIRTYPE_Ancient_temple = 6,
    LAIRTYPE_Abandoned_keep = 7,
    LAIRTYPE_Monster_lair = 8,
    LAIRTYPE_Ruins = 9,
    LAIRTYPE_Fallen_temple = 10,

    eTower_Node_Lair_Type_MAX
};

enum eNode_Type ENUMSIZE8
{
    NODETYPE_Sorcery = 0, 
    NODETYPE_Nature = 1,
    NODETYPE_Chaos = 2
};

enum eObjective ENUMSIZE16
{
    OBJECTIVE_Pragmatist = 00,
    OBJECTIVE_Militarist = 01,
    OBJECTIVE_Theurgist = 02,
    OBJECTIVE_Perfectionist = 03,
    OBJECTIVE_Expansionist = 04,
    eObjective__SIZE__ = 0xFFFF
};

// Owners are optional, as opposing to a player
enum eOwner ENUMSIZE8
{
    OWNER_None = 0,
    OWNER_YOU = 1,
    OWNER_1 = 2,
    OWNER_2 = 3,
    OWNER_3 = 4,
    OWNER_4 = 5,
    OWNER_Neutral = 6,
    eOwner__SIZE__ = 0xFF
};

enum ePersonality ENUMSIZE16
{
    PERSONALITY_Maniacal = 00,
    PERSONALITY_Ruthless = 01,
    PERSONALITY_Aggressive = 02,
    PERSONALITY_Chaotic = 03,
    PERSONALITY_Lawful = 04,
    PERSONALITY_Peaceful = 05,
    ePersonality__SIZE__ = 0xFFFF
};

// A player is always given, as opposing to an owner,
enum ePlayer ENUMSIZE8
{
    PLAYER_Dismissed_Deceased = 0xFF,
    PLAYER_YOU = 0,
    PLAYER_1 = 1,
    PLAYER_2 = 2,
    PLAYER_3 = 3,
    PLAYER_4 = 4,
    PLAYER_NEUTRAL = 5,
    ePlayer_MAX,
    ePlayer__SIZE__ = 0xFF
};

enum ePlane ENUMSIZE8
{
    PLANE_Dismissed_Deceased = 0xFF,
    PLANE_Arcanum = 0,
    PLANE_Myrror = 1,
    ePlane_MAX,
};

enum ePortrait ENUMSIZE8
{
    PORTRAIT_Merlin = 0,
    PORTRAIT_Raven = 1,
    PORTRAIT_Sharee = 2,
    PORTRAIT_Lo_Pan = 3,
    PORTRAIT_Jafar = 4,
    PORTRAIT_Oberic = 5,
    PORTRAIT_Rjak = 6,
    PORTRAIT_Sssra = 7,
    PORTRAIT_Tauron = 8,
    PORTRAIT_Freya = 9,
    PORTRAIT_Horus = 10,
    PORTRAIT_Ariel = 11,
    PORTRAIT_Tlaloc = 12,
    PORTRAIT_Kali = 13,
    PORTRAIT_Custom = 14,
    ePortrait_MAX,
    ePortrait_SIZE__ = 0xFF
};

enum eProducing ENUMSIZE16
{
    PRODUCING_Computer = 0xFFFC,
    PRODUCING_None = 0,
    
    PRODUCING_Trade_Goods = 1,
    PRODUCING_Housing = 2,
    PRODUCING_Barracks = 3,
    PRODUCING_Armory = 4,
    PRODUCING_Fighters_Guild = 5,
    PRODUCING_Armorers_Guild = 6,
    PRODUCING_War_College = 7,
    PRODUCING_Smithy = 8,
    PRODUCING_Stable = 9,
    PRODUCING_Animists_Guild = 10,
    PRODUCING_Fantastic_Stable = 11,
    PRODUCING_Shipwright_Guild = 12,
    PRODUCING_Ship_Yard = 13,
    PRODUCING_Maritime_Guild = 14,
    PRODUCING_Sawmill = 15,
    PRODUCING_Library = 16,
    PRODUCING_Sages_Guild = 17,
    PRODUCING_Oracle = 18,
    PRODUCING_Alchemist_Guild = 19,
    PRODUCING_University = 20,
    PRODUCING_Wizards_Guild = 21,
    PRODUCING_Shrine = 22,
    PRODUCING_Temple = 23,
    PRODUCING_Parthenon = 24,
    PRODUCING_Cathedral = 25,
    PRODUCING_Marketplace = 26,
    PRODUCING_Bank = 27,
    PRODUCING_Merchants_Guild = 28,
    PRODUCING_Granary = 29,
    PRODUCING_Farmers_Market = 30,
    PRODUCING_Foresters_Guild = 31,
    PRODUCING_Builders_Hall = 32,
    PRODUCING_Mechanicians_Guild = 33,
    PRODUCING_Miners_Guild = 34,
    PRODUCING_City_Walls = 35,
    PRODUCING_BUILDING_MAX, 

    //  * Inanimate units
    PRODUCING_Trireme = 135,
    PRODUCING_Galley = 136,
    PRODUCING_Catapult = 137,
    PRODUCING_Warship = 138,

    //  * 115 Racial units (Sorted by race, then by power)

    PRODUCING_Barbarian_Spearmen,
    PRODUCING_Barbarian_Swordsmen,
    PRODUCING_Barbarian_Bowmen,
    PRODUCING_Barbarian_Cavalry,
    PRODUCING_Barbarian_Shaman,
    PRODUCING_Barbarian_Settlers,
    PRODUCING_Barbarian_Berserkers,

    PRODUCING_Beastmen_Spearmen,
    PRODUCING_Beastmen_Swordsmen,
    PRODUCING_Beastmen_Halberdiers,
    PRODUCING_Beastmen_Bowmen,
    PRODUCING_Beastmen_Priests,
    PRODUCING_Beastmen_Magicians,
    PRODUCING_Beastmen_Engineers,
    PRODUCING_Beastmen_Settlers,
    PRODUCING_Beastmen_Centaurs,
    PRODUCING_Beastmen_Manticores,
    PRODUCING_Beastmen_Minotaurs,

    PRODUCING_Dark_Elf_Spearmen,
    PRODUCING_Dark_Elf_Swordsmen,
    PRODUCING_Dark_Elf_Halberdiers,
    PRODUCING_Dark_Elf_Cavalry,
    PRODUCING_Dark_Elf_Priests,
    PRODUCING_Dark_Elf_Settlers,
    PRODUCING_Dark_Elf_Nightblades,
    PRODUCING_Dark_Elf_Warlocks,
    PRODUCING_Dark_Elf_Nightmares,

    PRODUCING_Draconian_Spearmen,
    PRODUCING_Draconian_Swordsmen,
    PRODUCING_Draconian_Halberdiers,
    PRODUCING_Draconian_Bowmen,
    PRODUCING_Draconian_Shaman,
    PRODUCING_Draconian_Magicians,
    PRODUCING_Draconian_Engineers,
    PRODUCING_Draconian_Settlers,
    PRODUCING_Draconian_Doom_Drakes,
    PRODUCING_Draconian_Air_Ship,

    PRODUCING_Dwarven_Swordsmen,
    PRODUCING_Dwarven_Halberdiers,
    PRODUCING_Dwarven_Engineers,
    PRODUCING_Dwarven_Hammerhands,
    PRODUCING_Dwarven_Steam_Cannon,
    PRODUCING_Dwarven_Golem,
    PRODUCING_Dwarven_Settlers,

    PRODUCING_Gnoll_Spearmen,
    PRODUCING_Gnoll_Swordsmen,
    PRODUCING_Gnoll_Halberdiers,
    PRODUCING_Gnoll_Bowmen,
    PRODUCING_Gnoll_Settlers,
    PRODUCING_Gnoll_Wolf_Riders,

    PRODUCING_Halfling_Spearmen,
    PRODUCING_Halfling_Swordsmen,
    PRODUCING_Halfling_Bowmen,
    PRODUCING_Halfling_Shaman,
    PRODUCING_Halfling_Settlers,
    PRODUCING_Halfling_Slingers,

    PRODUCING_High_Elf_Spearmen,
    PRODUCING_High_Elf_Swordsmen,
    PRODUCING_High_Elf_Halberdiers,
    PRODUCING_High_Elf_Cavalry,
    PRODUCING_High_Elf_Magicians,
    PRODUCING_High_Elf_Settlers,
    PRODUCING_High_Elf_Longbowmen,
    PRODUCING_High_Elf_Elven_Lords,
    PRODUCING_High_Elf_Pegasai,

    PRODUCING_High_Men_Spearmen,
    PRODUCING_High_Men_Swordsmen,
    PRODUCING_High_Men_Bowmen,
    PRODUCING_High_Men_Cavalry,
    PRODUCING_High_Men_Priests,
    PRODUCING_High_Men_Magicians,
    PRODUCING_High_Men_Engineers,
    PRODUCING_High_Men_Settlers,
    PRODUCING_High_Men_Pikemen,
    PRODUCING_High_Men_Paladins,

    PRODUCING_Klackon_Spearmen,
    PRODUCING_Klackon_Swordsmen,
    PRODUCING_Klackon_Halberdiers,
    PRODUCING_Klackon_Engineers,
    PRODUCING_Klackon_Settlers,
    PRODUCING_Klackon_Stag_Beetle,

    PRODUCING_Lizardman_Spearmen,
    PRODUCING_Lizardman_Swordsmen,
    PRODUCING_Lizardman_Halberdiers,
    PRODUCING_Lizardman_Javelineers,
    PRODUCING_Lizardman_Shaman,
    PRODUCING_Lizardman_Settlers,
    PRODUCING_Lizardman_Dragon_Turtle,

    PRODUCING_Nomad_Spearmen,
    PRODUCING_Nomad_Swordsmen,
    PRODUCING_Nomad_Bowmen,
    PRODUCING_Nomad_Priests,
    PRODUCING_Nomad_Magicians,
    PRODUCING_Nomad_Settlers,
    PRODUCING_Nomad_Horsebowmen,
    PRODUCING_Nomad_Pikemen,
    PRODUCING_Nomad_Rangers,
    PRODUCING_Nomad_Griffins,

    PRODUCING_Orc_Spearmen,
    PRODUCING_Orc_Swordsmen,
    PRODUCING_Orc_Halberdiers,
    PRODUCING_Orc_Bowmen,
    PRODUCING_Orc_Cavalry,
    PRODUCING_Orc_Shaman,
    PRODUCING_Orc_Magicians,
    PRODUCING_Orc_Engineers,
    PRODUCING_Orc_Settlers,
    PRODUCING_Orc_Wyvern_Riders,

    PRODUCING_Troll_Spearmen,
    PRODUCING_Troll_Swordsmen,
    PRODUCING_Troll_Halberdiers,
    PRODUCING_Troll_Shaman,
    PRODUCING_Troll_Settlers,
    PRODUCING_Troll_War_Trolls,
    PRODUCING_Troll_War_Mammoths,
    
    eProducing__SIZE__ = 0xFFFF
};


enum eRace ENUMSIZE8
{
    RACE_Barbarian = 0,
    RACE_Beastmen = 1,
    RACE_Dark_Elf = 2,
    RACE_Draconian = 3,
    RACE_Dwarven = 4,
    RACE_Gnoll = 5,
    RACE_Halfling = 6,
    RACE_High_Elf = 7,
    RACE_High_Men = 8,
    RACE_Klackon = 9,
    RACE_Lizardman = 10,
    RACE_Nomad = 11,
    RACE_Orc = 12,
    RACE_Troll = 13,         // Maximum used in SaveGame

    // Extra used in WizardsExe
    RACE_Generic_ship_or_catapult = 0x0E,
    RACE_Arcane = 0x0F,
    RACE_Nature = 0x10,
    RACE_Sorcery = 0x11,
    RACE_Chaos = 0x12,
    RACE_Life = 0x13,
    RACE_Death = 0x14,

    eRace_MAX,
    eRace__SIZE__ = 0xFF
};

enum eRandomPickType ENUMSIZE16 {
    RANDOMPICK_Fighter,
    RANDOMPICK_Mage,
    RANDOMPICK_Any,
    eRandomPickType_MAX,
    eRandomPickType__SIZE__ = 0xFFFF,
};

enum eRanged_Type ENUMSIZE8 {
    RANGED_None = 0xFF,

    // 10-19 Rocks
    RANGED_Rock = 10,

    // 20-29 Missiles
    RANGED_Arrow = 20,
    RANGED_Bullet = 21,                     // Slingers

    // 30-39 Magic ranged attack
    RANGED_Chaos_Magic1_Storm_Giant = 30,   // Warlock, Chaos Warrior, Storm Giant
    RANGED_Chaos_Magic2_Magician = 31,      // Warrior Mage, Magician, Witch, Golden One, Unknown, Magicians, Warlocks
    RANGED_Sorcery_Magic_Illusionist = 32,  // Sage, Illusionist
    RANGED_Chaos_Magic3_Demon = 33,         // Necromancer, Shadow_Demons, Demon_Lord
    RANGED_Nature_Magic1_Wind_Mage = 34,    // Wind_Mage
    RANGED_Nature_Magic2_Shamans = 35,      // Healer, Priestess, Shamans, Priests
    RANGED_Chaos_Magic4_Dark_Elves = 36,    // Dark Elves (Spearmen, Swordsmen, Halberdiers, Cavalry, Nightmares)
    RANGED_Nature_Magic3_Sprites = 37,      // Sprites
    RANGED_Nature_Magic4_Druid = 38,        // Druid

    // 100-109 Thrown/Breath/Gaze
    RANGED_Thrown_Weapons = 100,
    RANGED_Fire_Breath = 101,
    RANGED_Lightning_Breath = 102,          // Sky_Drake
    RANGED_Stoning_Gaze = 103,              // Basilisk, Gorgons (resistance modifier in byte 17)
    RANGED_Multiple_Gaze = 104,             // Chaos Spawn
    RANGED_Death_Gaze = 105,                // Night stalker (resistance modifier in byte 17)
};

enum eRarity
{
    RARITY_Common = 0,
    RARITY_Uncommon = 1,
    RARITY_Rare = 2,
    RARITY_Very_Rare = 3,
    eRarity_MAX
};

enum eRealm_Type ENUMSIZE8
{
    REALM_Nature = 0,
    REALM_Sorcery = 1,
    REALM_Chaos = 2,
    REALM_Life = 3,
    REALM_Death = 4,
    REALM_Arcane = 5,
    eRealm_Type_MAX
};

enum eReward_Specials ENUMSIZE8
{
    REWARD_No_specials = 0,
    REWARD_Common_Spell = 1,
    REWARD_Uncommon_Spell = 2,
    REWARD_Rare_Spell = 3,
    REWARD_Very_Rare_Spell = 4,
    REWARD_1_Spellbook_or_Skill = 5,    //5 = 1 Spellbook or Skill (74% - 26%)
    REWARD_2_Spellbooks_or_Skills = 6,   //6 = 2 Spellbooks or Skills (74% - 26%)
    eReward_Specials_MAX
};

enum eSkill ENUMSIZE8
{
    SKILL_Alchemy,
    SKILL_Warlord,
    SKILL_Chaos_Master,
    SKILL_Nature_Master,
    SKILL_Sorcery_Master,
    SKILL_Infernal_Power,
    SKILL_Divine_Power,
    SKILL_Sage_Master,
    SKILL_Channeller,
    SKILL_Myrran,
    SKILL_Archmage,
    SKILL_Mana_Focusing,
    SKILL_Node_Mastery,
    SKILL_Famous,
    SKILL_Runemaster,
    SKILL_Conjurer,
    SKILL_Charismatic,
    SKILL_Artificer,
    eSkill_MAX,
    eSkill__SIZE__ = 0xFF
};

enum eSkill16 ENUMSIZE16
{
    SKILL16_None = 0xFFFF,
    SKILL16_Alchemy = 0,
    SKILL16_Warlord,
    SKILL16_Chaos_Master,
    SKILL16_Nature_Master,
    SKILL16_Sorcery_Master,
    SKILL16_Infernal_Power,
    SKILL16_Divine_Power,
    SKILL16_Sage_Master,
    SKILL16_Channeller,
    SKILL16_Myrran,
    SKILL16_Archmage,
    SKILL16_Mana_Focusing,
    SKILL16_Node_Mastery,
    SKILL16_Famous,
    SKILL16_Runemaster,
    SKILL16_Conjurer,
    SKILL16_Charismatic,
    SKILL16_Artificer,
    eSkill16__SIZE__ = 0xFFFF
};

enum eSlot_Type8 ENUMSIZE8
{
    SLOT8_Sword = 1,
    SLOT8_Bow = 2,
    SLOT8_Sword_Staff_Wand = 3,
    SLOT8_Staff_Wand = 4,
    SLOT8_Armor_Shield = 5,
    SLOT8_Amulet = 6,
    eSlot_Type8__SIZE__ = 0xFF
};

enum eSlot_Type16 ENUMSIZE16
{
    SLOT16_Sword = 1,
    SLOT16_Bow = 2,
    SLOT16_Sword_Staff_Wand = 3,
    SLOT16_Staff_Wand = 4,
    SLOT16_Armor_Shield = 5,
    SLOT16_Amulet = 6,
    eSlot_Type16__SIZE__ = 0xFFFF
};

enum eSpellKnown ENUMSIZE8
{
    SPELLKNOWN_unknown = 0,
    SPELLKNOWN_knowable = 1,
    SPELLKNOWN_currently_known = 2,
    SPELLKNOWN_researchable = 3,
    eSpellKnown_MAX
};

enum eSpellKnown16 ENUMSIZE16 
{
    SPELLKNOWN16_unknown = 0,
    SPELLKNOWN16_knowable = 1,
    SPELLKNOWN16_currently_known = 2,
    SPELLKNOWN16_researchable = 3,
    eSpellKnown16__SIZE__ = 0xFFFF
};

enum eSpell_Type ENUMSIZE8
{
    SPELLTYPE_Special_Spells = 0,
    SPELLTYPE_Summoning = 1,
    SPELLTYPE_Enchantment = 2,
    SPELLTYPE_City_Spells = 3,
    SPELLTYPE_Unit_Spells = 4,
    SPELLTYPE_Combat_Spells = 5,
    eSpell_Type_MAX
};

enum eSpell ENUMSIZE8
{
    SPELL_None = 0,
    
    //    * NATURE
    SPELL_Earth_to_Mud = 1,
    SPELL_Resist_Elements = 2,
    SPELL_Wall_of_Stone = 3,
    SPELL_Giant_Strength = 4,
    SPELL_Web  = 5,
    SPELL_War_Bears  = 6,
    SPELL_Stone_Skin  = 7,
    SPELL_Water_Walking  = 8,
    SPELL_Sprites  = 9,
    SPELL_Earth_Lore  = 10,

    SPELL_Cracks_Call  = 11,
    SPELL_Natures_Eye  = 12,
    SPELL_Ice_Bolt  = 13,
    SPELL_Giant_Spiders  = 14,
    SPELL_Change_Terrain  = 15,
    SPELL_Path_Finding  = 16,
    SPELL_Cockatrices  = 17,
    SPELL_Transmute  = 18,
    SPELL_Natures_Cures  = 19,
    SPELL_Basilisk  = 20,

    SPELL_Elemental_Armor  = 21,
    SPELL_Petrify  = 22,
    SPELL_Stone_Giant  = 23,
    SPELL_Iron_Skin  = 24,
    SPELL_Ice_Storm  = 25,
    SPELL_Earthquake  = 26,
    SPELL_Gorgons  = 27,
    SPELL_Move_Fortress  = 28,
    SPELL_Gaias_Blessing  = 29,
    SPELL_Earth_Elemental  = 30,

    SPELL_Regeneration  = 31,
    SPELL_Behemoth  = 32,
    SPELL_Entangle  = 33,
    SPELL_Nature_Awareness  = 34,
    SPELL_Call_Lightning  = 35,
    SPELL_Colossus  = 36,
    SPELL_Earth_Gate  = 37,
    SPELL_Herb_Mastery  = 38,
    SPELL_Great_Wyrm  = 39,
    SPELL_Natures_Wrath  = 40,

    //    * SORCERY
    SPELL_Resist_Magic  = 41,
    SPELL_Dispel_Magic_True  = 42,
    SPELL_Floating_Island  = 43,
    SPELL_Guardian_Wind  = 44,
    SPELL_Phantom_Warriors  = 45,
    SPELL_Confusion  = 46,
    SPELL_Word_of_Recall  = 47,
    SPELL_Counter_Magic  = 48,
    SPELL_Nagas  = 49,
    SPELL_Psionic_Blast  = 50,

    SPELL_Blur  = 51,
    SPELL_Disenchant_True  = 52,
    SPELL_Vertigo  = 53,
    SPELL_Spell_Lock  = 54,
    SPELL_Enchant_Road  = 55,
    SPELL_Flight  = 56,
    SPELL_Wind_Mastery  = 57,
    SPELL_Spell_Blast  = 58,
    SPELL_Aura_of_Majesty  = 59,
    SPELL_Phantom_Beast  = 60,

    SPELL_Disjunction_True  = 61,
    SPELL_Invisibility  = 62,
    SPELL_Wind_Walking  = 63,
    SPELL_Banish  = 64,
    SPELL_Storm_Giant  = 65,
    SPELL_Air_Elemental  = 66,
    SPELL_Mind_Storm  = 67,
    SPELL_Stasis  = 68,
    SPELL_Magic_Immunity  = 69,
    SPELL_Haste  = 70,

    SPELL_Djinn  = 71,
    SPELL_Spell_Ward  = 72,
    SPELL_Creature_Binding  = 73,
    SPELL_Mass_Invisibility  = 74,
    SPELL_Great_Unsummoning  = 75,
    SPELL_Spell_Binding  = 76,
    SPELL_Flying_Fortress  = 77,
    SPELL_Sky_Drake  = 78,
    SPELL_Suppress_Magic  = 79,
    SPELL_Time_Stop  = 80,

    //    * CHAOS
    SPELL_Warp_Wood  = 81,
    SPELL_Disrupt  = 82,
    SPELL_Fire_Bolt  = 83,
    SPELL_Hell_Hounds  = 84,
    SPELL_Corruption  = 85,
    SPELL_Eldritch_Weapon  = 86,
    SPELL_Wall_of_Fire  = 87,
    SPELL_Shatter  = 88,
    SPELL_Warp_Creature  = 89,
    SPELL_Fire_Elemental  = 90,

    SPELL_Lightning_Bolt  = 91,
    SPELL_Fire_Giant  = 92,
    SPELL_Chaos_Channels  = 93,
    SPELL_Flame_Blade  = 94,
    SPELL_Gargoyles  = 95,
    SPELL_Fireball  = 96,
    SPELL_Doombat  = 97,
    SPELL_Raise_Volcano  = 98,
    SPELL_Immolation  = 99,
    SPELL_Chimeras  = 100,

    SPELL_Warp_Lightning  = 101,
    SPELL_Metal_Fires  = 102,
    SPELL_Chaos_Spawn  = 103,
    SPELL_Doom_Bolt  = 104,
    SPELL_Magic_Vortex  = 105,
    SPELL_Efreet  = 106,
    SPELL_Fire_Storm  = 107,
    SPELL_Warp_Reality  = 108,
    SPELL_Flame_Strike  = 109,
    SPELL_Chaos_Rift  = 110,

    SPELL_Hydra  = 111,
    SPELL_Disintegrate  = 112,
    SPELL_Meteor_Storm  = 113,
    SPELL_Great_Wasting  = 114,
    SPELL_Call_Chaos  = 115,
    SPELL_Chaos_Surge  = 116,
    SPELL_Doom_Mastery  = 117,
    SPELL_Great_Drake  = 118,
    SPELL_Call_The_Void  = 119,
    SPELL_Armageddon  = 120,

    //    * LIFE
    SPELL_Bless  = 121,
    SPELL_Star_Fires  = 122,
    SPELL_Endurance  = 123,
    SPELL_Holy_Weapon  = 124,
    SPELL_Healing  = 125,
    SPELL_Holy_Armor  = 126,
    SPELL_Just_Cause  = 127,
    SPELL_True_Light  = 128,
    SPELL_Guardian_Spirit  = 129,
    SPELL_Heroism  = 130,

    SPELL_True_Sight  = 131,
    SPELL_Plane_Shift  = 132,
    SPELL_Resurrection  = 133,
    SPELL_Dispel_Evil  = 134,
    SPELL_Planar_Seal  = 135,
    SPELL_Unicorns  = 136,
    SPELL_Raise_Dead  = 137,
    SPELL_Planar_Travel  = 138,
    SPELL_Heavenly_Light  = 139,
    SPELL_Prayer  = 140,

    SPELL_Lionheart  = 141,
    SPELL_Incarnation  = 142,
    SPELL_Invulnerability  = 143,
    SPELL_Righteousness  = 144,
    SPELL_Prosperity  = 145,
    SPELL_Altar_of_Battle  = 146,
    SPELL_Angel  = 147,
    SPELL_Stream_of_Life  = 148,
    SPELL_Mass_Healing  = 149,
    SPELL_Holy_Word  = 150,

    SPELL_High_Prayer  = 151,
    SPELL_Inspirations  = 152,
    SPELL_Astral_Gate  = 153,
    SPELL_Holy_Arms  = 154,
    SPELL_Consecration  = 155,
    SPELL_Life_Force  = 156,
    SPELL_Tranquility  = 157,
    SPELL_Crusade  = 158,
    SPELL_Arch_Angel  = 159,
    SPELL_Charm_of_Life  = 160,

    //    * DEATH
    SPELL_Skeletons  = 161,
    SPELL_Weakness  = 162,
    SPELL_Dark_Rituals  = 163,
    SPELL_Cloak_of_Fear  = 164,
    SPELL_Black_Sleep  = 165,
    SPELL_Ghouls  = 166,
    SPELL_Life_Drain  = 167,
    SPELL_Terror  = 168,
    SPELL_Darkness  = 169,
    SPELL_Mana_Leak  = 170,

    SPELL_Drain_Power  = 171,
    SPELL_Possession  = 172,
    SPELL_Lycantrophy  = 173,
    SPELL_Black_Prayer  = 174,
    SPELL_Black_Channels  = 175,
    SPELL_Night_Stalker  = 176,
    SPELL_Subversion  = 177,
    SPELL_Wall_of_Darkness  = 178,
    SPELL_Berserk  = 179,
    SPELL_Shadow_Demons  = 180,

    SPELL_Wraith_Form  = 181,
    SPELL_Wrack  = 182,
    SPELL_Evil_Presence  = 183,
    SPELL_Wraiths  = 184,
    SPELL_Cloud_Of_Shadow  = 185,
    SPELL_Warp_Node  = 186,
    SPELL_Black_Wind  = 187,
    SPELL_Zombie_Mastery  = 188,
    SPELL_Famine  = 189,
    SPELL_Cursed_Lands  = 190,

    SPELL_Cruel_Unminding  = 191,
    SPELL_Word_of_Death  = 192,
    SPELL_Death_Knights  = 193,
    SPELL_Death_Spell  = 194,
    SPELL_Animate_dead  = 195,
    SPELL_Pestilence  = 196,
    SPELL_Eternal_Night  = 197,
    SPELL_Evil_Omens  = 198,
    SPELL_Death_Wish  = 199,
    SPELL_Demon_Lord  = 200,

    //    * ARCANE = 1,
    SPELL_Magic_Spirit  = 201,
    SPELL_Dispel_Magic  = 202,
    SPELL_Summoning_Circle  = 203,
    SPELL_Disenchant_Area  = 204,
    SPELL_Recall_Hero  = 205,
    SPELL_Detect_Magic  = 206,
    SPELL_Enchant_Item  = 207,
    SPELL_Summon_Hero  = 208,
    SPELL_Awareness  = 209,
    SPELL_Disjunction  = 210,
    SPELL_Create_Artifact  = 211,
    SPELL_Summon_Champion  = 212,
    SPELL_Spell_Of_Mastery  = 213,
    SPELL_Spell_Of_Return  = 214,

    eSpell_MAX
};

enum eSpell16 ENUMSIZE16
{
    SPELL16_None = 0,

    //    * NATURE
    SPELL16_Earth_to_Mud = 1,
    SPELL16_Resist_Elements = 2,
    SPELL16_Wall_of_Stone = 3,
    SPELL16_Giant_Strength = 4,
    SPELL16_Web  = 5,
    SPELL16_War_Bears  = 6,
    SPELL16_Stone_Skin  = 7,
    SPELL16_Water_Walking  = 8,
    SPELL16_Sprites  = 9,
    SPELL16_Earth_Lore  = 10,

    SPELL16_Cracks_Call  = 11,
    SPELL16_Natures_Eye  = 12,
    SPELL16_Ice_Bolt  = 13,
    SPELL16_Giant_Spiders  = 14,
    SPELL16_Change_Terrain  = 15,
    SPELL16_Path_Finding  = 16,
    SPELL16_Cockatrices  = 17,
    SPELL16_Transmute  = 18,
    SPELL16_Natures_Cures  = 19,
    SPELL16_Basilisk  = 20,

    SPELL16_Elemental_Armor  = 21,
    SPELL16_Petrify  = 22,
    SPELL16_Stone_Giant  = 23,
    SPELL16_Iron_Skin  = 24,
    SPELL16_Ice_Storm  = 25,
    SPELL16_Earthquake  = 26,
    SPELL16_Gorgons  = 27,
    SPELL16_Move_Fortress  = 28,
    SPELL16_Gaias_Blessing  = 29,
    SPELL16_Earth_Elemental  = 30,

    SPELL16_Regeneration  = 31,
    SPELL16_Behemoth  = 32,
    SPELL16_Entangle  = 33,
    SPELL16_Nature_Awareness  = 34,
    SPELL16_Call_Lightning  = 35,
    SPELL16_Colossus  = 36,
    SPELL16_Earth_Gate  = 37,
    SPELL16_Herb_Mastery  = 38,
    SPELL16_Great_Wyrm  = 39,
    SPELL16_Natures_Wrath  = 40,

    //    * SORCERY
    SPELL16_Resist_Magic  = 41,
    SPELL16_Dispel_Magic_True  = 42,
    SPELL16_Floating_Island  = 43,
    SPELL16_Guardian_Wind  = 44,
    SPELL16_Phantom_Warriors  = 45,
    SPELL16_Confusion  = 46,
    SPELL16_Word_of_Recall  = 47,
    SPELL16_Counter_Magic  = 48,
    SPELL16_Nagas  = 49,
    SPELL16_Psionic_Blast  = 50,

    SPELL16_Blur  = 51,
    SPELL16_Disenchant_True  = 52,
    SPELL16_Vertigo  = 53,
    SPELL16_Spell_Lock  = 54,
    SPELL16_Enchant_Road  = 55,
    SPELL16_Flight  = 56,
    SPELL16_Wind_Mastery  = 57,
    SPELL16_Spell_Blast  = 58,
    SPELL16_Aura_of_Majesty  = 59,
    SPELL16_Phantom_Beast  = 60,

    SPELL16_Disjunction_True  = 61,
    SPELL16_Invisibility  = 62,
    SPELL16_Wind_Walking  = 63,
    SPELL16_Banish  = 64,
    SPELL16_Storm_Giant  = 65,
    SPELL16_Air_Elemental  = 66,
    SPELL16_Mind_Storm  = 67,
    SPELL16_Stasis  = 68,
    SPELL16_Magic_Immunity  = 69,
    SPELL16_Haste  = 70,

    SPELL16_Djinn  = 71,
    SPELL16_Spell_Ward  = 72,
    SPELL16_Creature_Binding  = 73,
    SPELL16_Mass_Invisibility  = 74,
    SPELL16_Great_Unsummoning  = 75,
    SPELL16_Spell_Binding  = 76,
    SPELL16_Flying_Fortress  = 77,
    SPELL16_Sky_Drake  = 78,
    SPELL16_Suppress_Magic  = 79,
    SPELL16_Time_Stop  = 80,

    //    * CHAOS
    SPELL16_Warp_Wood  = 81,
    SPELL16_Disrupt  = 82,
    SPELL16_Fire_Bolt  = 83,
    SPELL16_Hell_Hounds  = 84,
    SPELL16_Corruption  = 85,
    SPELL16_Eldritch_Weapon  = 86,
    SPELL16_Wall_of_Fire  = 87,
    SPELL16_Shatter  = 88,
    SPELL16_Warp_Creature  = 89,
    SPELL16_Fire_Elemental  = 90,

    SPELL16_Lightning_Bolt  = 91,
    SPELL16_Fire_Giant  = 92,
    SPELL16_Chaos_Channels  = 93,
    SPELL16_Flame_Blade  = 94,
    SPELL16_Gargoyles  = 95,
    SPELL16_Fireball  = 96,
    SPELL16_Doombat  = 97,
    SPELL16_Raise_Volcano  = 98,
    SPELL16_Immolation  = 99,
    SPELL16_Chimeras  = 100,

    SPELL16_Warp_Lightning  = 101,
    SPELL16_Metal_Fires  = 102,
    SPELL16_Chaos_Spawn  = 103,
    SPELL16_Doom_Bolt  = 104,
    SPELL16_Magic_Vortex  = 105,
    SPELL16_Efreet  = 106,
    SPELL16_Fire_Storm  = 107,
    SPELL16_Warp_Reality  = 108,
    SPELL16_Flame_Strike  = 109,
    SPELL16_Chaos_Rift  = 110,

    SPELL16_Hydra  = 111,
    SPELL16_Disintegrate  = 112,
    SPELL16_Meteor_Storm  = 113,
    SPELL16_Great_Wasting  = 114,
    SPELL16_Call_Chaos  = 115,
    SPELL16_Chaos_Surge  = 116,
    SPELL16_Doom_Mastery  = 117,
    SPELL16_Great_Drake  = 118,
    SPELL16_Call_The_Void  = 119,
    SPELL16_Armageddon  = 120,

    //    * LIFE
    SPELL16_Bless  = 121,
    SPELL16_Star_Fires  = 122,
    SPELL16_Endurance  = 123,
    SPELL16_Holy_Weapon  = 124,
    SPELL16_Healing  = 125,
    SPELL16_Holy_Armor  = 126,
    SPELL16_Just_Cause  = 127,
    SPELL16_True_Light  = 128,
    SPELL16_Guardian_Spirit  = 129,
    SPELL16_Heroism  = 130,

    SPELL16_True_Sight  = 131,
    SPELL16_Plane_Shift  = 132,
    SPELL16_Resurrection  = 133,
    SPELL16_Dispel_Evil  = 134,
    SPELL16_Planar_Seal  = 135,
    SPELL16_Unicorns  = 136,
    SPELL16_Raise_Dead  = 137,
    SPELL16_Planar_Travel  = 138,
    SPELL16_Heavenly_Light  = 139,
    SPELL16_Prayer  = 140,

    SPELL16_Lionheart  = 141,
    SPELL16_Incarnation  = 142,
    SPELL16_Invulnerability  = 143,
    SPELL16_Righteousness  = 144,
    SPELL16_Prosperity  = 145,
    SPELL16_Altar_of_Battle  = 146,
    SPELL16_Angel  = 147,
    SPELL16_Stream_of_Life  = 148,
    SPELL16_Mass_Healing  = 149,
    SPELL16_Holy_Word  = 150,

    SPELL16_High_Prayer  = 151,
    SPELL16_Inspirations  = 152,
    SPELL16_Astral_Gate  = 153,
    SPELL16_Holy_Arms  = 154,
    SPELL16_Consecration  = 155,
    SPELL16_Life_Force  = 156,
    SPELL16_Tranquility  = 157,
    SPELL16_Crusade  = 158,
    SPELL16_Arch_Angel  = 159,
    SPELL16_Charm_of_Life  = 160,

    //    * DEATH
    SPELL16_Skeletons  = 161,
    SPELL16_Weakness  = 162,
    SPELL16_Dark_Rituals  = 163,
    SPELL16_Cloak_of_Fear  = 164,
    SPELL16_Black_Sleep  = 165,
    SPELL16_Ghouls  = 166,
    SPELL16_Life_Drain  = 167,
    SPELL16_Terror  = 168,
    SPELL16_Darkness  = 169,
    SPELL16_Mana_Leak  = 170,

    SPELL16_Drain_Power  = 171,
    SPELL16_Possession  = 172,
    SPELL16_Lycantrophy  = 173,
    SPELL16_Black_Prayer  = 174,
    SPELL16_Black_Channels  = 175,
    SPELL16_Night_Stalker  = 176,
    SPELL16_Subversion  = 177,
    SPELL16_Wall_of_Darkness  = 178,
    SPELL16_Berserk  = 179,
    SPELL16_Shadow_Demons  = 180,

    SPELL16_Wraith_Form  = 181,
    SPELL16_Wrack  = 182,
    SPELL16_Evil_Presence  = 183,
    SPELL16_Wraiths  = 184,
    SPELL16_Cloud_Of_Shadow  = 185,
    SPELL16_Warp_Node  = 186,
    SPELL16_Black_Wind  = 187,
    SPELL16_Zombie_Mastery  = 188,
    SPELL16_Famine  = 189,
    SPELL16_Cursed_Lands  = 190,

    SPELL16_Cruel_Unminding  = 191,
    SPELL16_Word_of_Death  = 192,
    SPELL16_Death_Knights  = 193,
    SPELL16_Death_Spell  = 194,
    SPELL16_Animate_dead  = 195,
    SPELL16_Pestilence  = 196,
    SPELL16_Eternal_Night  = 197,
    SPELL16_Evil_Omens  = 198,
    SPELL16_Death_Wish  = 199,
    SPELL16_Demon_Lord  = 200,

    //    * ARCANE = 1,
    SPELL16_Magic_Spirit  = 201,
    SPELL16_Dispel_Magic  = 202,
    SPELL16_Summoning_Circle  = 203,
    SPELL16_Disenchant_Area  = 204,
    SPELL16_Recall_Hero  = 205,
    SPELL16_Detect_Magic  = 206,
    SPELL16_Enchant_Item  = 207,
    SPELL16_Summon_Hero  = 208,
    SPELL16_Awareness  = 209,
    SPELL16_Disjunction  = 210,
    SPELL16_Create_Artifact  = 211,
    SPELL16_Summon_Champion  = 212,
    SPELL16_Spell_Of_Mastery  = 213,
    SPELL16_Spell_Of_Return  = 214,

    eSPELL16_MAX,
    eSpell16__SIZE__ = 0xFFFF
};

enum eTax_Rate ENUMSIZE16
{
    TAX_00_gold_00_unrest = 0,
    TAX_05_gold_10_unrest = 1,
    TAX_10_gold_20_unrest = 2,
    TAX_15_gold_30_unrest = 3,
    TAX_20_gold_45_unrest = 4,
    TAX_25_gold_60_unrest = 5,
    TAX_30_gold_75_unrest = 6,
    eTax_Rate_MAX,
    eTax_Rate__SIZE__ = 0xFFFF
};

enum eTerrainType ENUMSIZE16
{
    ocean = 0x0000,
    Bug_terrain_like_grasslands = 0x0001,
    shore1_first = 0x0002, //  160 various joining configurations
    shore1_last = 0x00A1,
    grasslands1 = 0x00A2,
    forest1 = 0x00A3,
    mountain1 = 0x00A4,
    desert1 = 0x00A5,
    swamp1 = 0x00A6,
    tundra1 = 0x00A7,
    grasslands_w_sorcery_node = 0x00A8,
    forest_w_nature_node = 0x00A9,
    volcano_w_chaos_node = 0x00AA,
    hills1 = 0x00AB,
    grasslands2_first = 0x00AC,
    grasslands2_last = 0x00AD,
    desert2_first = 0x00AE,
    desert2_last = 0x00B0,
    swamp2_first = 0x00B1,
    swamp2_last = 0x00B2,
    volcano = 0x00B3,
    grasslands3 = 0x00B4,
    tundra2_first = 0x00B5,
    tundra2_last = 0x00B6,
    forest2_first = 0x00B7,
    forest2_last = 0x00B8,
    river1_first = 0x00B9, //  river mouth if adjacent to shore
    river1_last = 0x00C4,
    shore2_first = 0x00C5, //  4 river joined large lake
    shore2_last = 0x00C8,
    shore3_first = 0x00C9, //  32 river outlet to ocean
    shore3_last = 0x00E8,
    river2_first = 0x00E9, //  river mouth if adjacent to shore
    river2_last = 0x0102,
    mountain2_first = 0x0103,  //  various joining configurations
    mountain2_last = 0x0112,
    hills2_first = 0x0113, //  various joining configurations
    hills2_last = 0x0123,
    desert3_first = 0x0124,    //  various joining configurations
    desert3_last = 0x01C3,
    shore4_first = 0x01C4, //  various joining configurations, including some river outlets
    shore4_last = 0x0258,
    ocean_first = 0x0259,
    ocean_last = 0x0260,
    Bug_terrain_like_tundra = 0x0261,
    tundra3_first = 0x0262,    //  various joining configurations
    tundra3_last = 0x02F9,
    eTerrainType_MAX,
    eTerrainType__SIZE__ = 0xFFFF
};

enum eUnit_Active ENUMSIZE8
{
    UNITACTIVE_awaiting_orders = 0,         //   00=awaiting orders / "I need attention" (will "jump to" this unit when hitting wait)
    UNITACTIVE_finished = 1,                //   01=finished (won't "jump to" this unit when hitting wait)
    eUnit_Active_SIZE__ = 0xFF
};

enum eUnit_Status ENUMSIZE8
{
    UNITSTATUS_ready = 0,                   //   00=ready
    UNITSTATUS_patrol = 1,                  //   01=patrol
    UNITSTATUS_building_road_in_place = 2,  //   02=building road (in place)
    UNITSTATUS_going_to_XY = 3,             //   03=going to X,Y destination (could be building road too, see 0x1C)
    UNITSTATUS_reached_destination = 4,     //   04=reached destination & expended (0x07 == 01)
                                            //      NOTE: it is a STATE MACHINE FAILURE to have 0x07 = 00 & 0x0B == 04!
    UNITSTATUS_wait = 5,                    //   05=wait until all other units have had a chance to go (then clears all flags)
                                            //      the SAVE game does not record if we are traversing UP or DOWN the units!
                                            //   ??=building road
                                            //   ??=purifying
    UNITSTATUS_unkUnitStatus16 = 16,        //   16=??
    UNITSTATUS_eUnit_Status_SIZE__ = 0xFF
};

enum eUnit_Type ENUMSIZE8
{
    //  * 35 Heroes (00=Brax; 22=Chosen One) => better heroes, higher number
    UNITTYPE_Dwarf = 0,
    HEROTYPE_FIRST = 0,
    UNITTYPE_Barbarian = 1,
    UNITTYPE_Sage = 2,
    UNITTYPE_Dervish = 3,
    UNITTYPE_Beastmaster = 4,
    UNITTYPE_Bard = 5,
    UNITTYPE_Orc_Warrior = 6,
    UNITTYPE_Healer = 7,
    UNITTYPE_Huntress = 8,
    UNITTYPE_Thief = 9,
    UNITTYPE_Druid = 10,
    UNITTYPE_War_Monk = 11,
    UNITTYPE_Warrior_Mage = 12,
    UNITTYPE_Magician = 13,
    UNITTYPE_Assassin = 14,
    UNITTYPE_Wind_Mage = 15,
    UNITTYPE_Ranger = 16,
    UNITTYPE_Draconian = 17,
    UNITTYPE_Witch = 18,
    UNITTYPE_Golden_One = 19,
    UNITTYPE_Ninja = 20,
    UNITTYPE_Rogue = 21,
    UNITTYPE_Amazon = 22,
    UNITTYPE_Warlock = 23,
    UNITTYPE_Unknown = 24,
    UNITTYPE_Illusionist = 25,
    UNITTYPE_Swordsman = 26,
    UNITTYPE_Priestess = 27,
    UNITTYPE_Paladin = 28,
    UNITTYPE_Black_Knight = 29,
    UNITTYPE_Elven_Archer = 30,
    UNITTYPE_Knight = 31,
    UNITTYPE_Necromancer = 32,
    UNITTYPE_Chaos_Warrior = 33,
    UNITTYPE_Chosen = 34,

    //  * Inanimate units (23=Trireme, 24=Galley, 25=Catapult, 26=Warship)
    UNITTYPE_Trireme = 35,
    UNITTYPE_FIRST = 35,
    UNITTYPE_Galley = 36,
    UNITTYPE_Catapult = 37,
    UNITTYPE_Warship = 38,
    
    //  * 0x27-0x99: 115 Racial units (Sorted by race, then by power)
    
    UNITTYPE_Barbarian_Spearmen,     // 39
    UNITTYPE_Barbarian_Swordsmen,
    UNITTYPE_Barbarian_Bowmen,
    UNITTYPE_Barbarian_Cavalry,
    UNITTYPE_Barbarian_Shaman,
    UNITTYPE_Barbarian_Settlers,
    UNITTYPE_Barbarian_Berserkers,

    UNITTYPE_Beastmen_Spearmen,      // 46
    UNITTYPE_Beastmen_Swordsmen,
    UNITTYPE_Beastmen_Halberdiers,
    UNITTYPE_Beastmen_Bowmen,
    UNITTYPE_Beastmen_Priests,
    UNITTYPE_Beastmen_Magicians,
    UNITTYPE_Beastmen_Engineers,
    UNITTYPE_Beastmen_Settlers,
    UNITTYPE_Beastmen_Centaurs,
    UNITTYPE_Beastmen_Manticores,
    UNITTYPE_Beastmen_Minotaurs,

    UNITTYPE_Dark_Elf_Spearmen,      // 57
    UNITTYPE_Dark_Elf_Swordsmen,
    UNITTYPE_Dark_Elf_Halberdiers,
    UNITTYPE_Dark_Elf_Cavalry,
    UNITTYPE_Dark_Elf_Priests,
    UNITTYPE_Dark_Elf_Settlers,
    UNITTYPE_Dark_Elf_Nightblades,
    UNITTYPE_Dark_Elf_Warlocks,
    UNITTYPE_Dark_Elf_Nightmares,

    UNITTYPE_Draconian_Spearmen,     // 66
    UNITTYPE_Draconian_Swordsmen,
    UNITTYPE_Draconian_Halberdiers,
    UNITTYPE_Draconian_Bowmen,
    UNITTYPE_Draconian_Shaman,
    UNITTYPE_Draconian_Magicians,
    UNITTYPE_Draconian_Engineers,
    UNITTYPE_Draconian_Settlers,
    UNITTYPE_Draconian_Doom_Drakes,
    UNITTYPE_Draconian_Air_Ship,

    UNITTYPE_Dwarven_Swordsmen,      // 76
    UNITTYPE_Dwarven_Halberdiers,
    UNITTYPE_Dwarven_Engineers,
    UNITTYPE_Dwarven_Hammerhands,
    UNITTYPE_Dwarven_Steam_Cannon,
    UNITTYPE_Dwarven_Golem,
    UNITTYPE_Dwarven_Settlers,

    UNITTYPE_Gnoll_Spearmen,         // 83
    UNITTYPE_Gnoll_Swordsmen,
    UNITTYPE_Gnoll_Halberdiers,
    UNITTYPE_Gnoll_Bowmen,
    UNITTYPE_Gnoll_Settlers,
    UNITTYPE_Gnoll_Wolf_Riders,

    UNITTYPE_Halfling_Spearmen,      // 89
    UNITTYPE_Halfling_Swordsmen,
    UNITTYPE_Halfling_Bowmen,
    UNITTYPE_Halfling_Shaman,
    UNITTYPE_Halfling_Settlers,
    UNITTYPE_Halfling_Slingers,

    UNITTYPE_High_Elf_Spearmen,      // 95
    UNITTYPE_High_Elf_Swordsmen,
    UNITTYPE_High_Elf_Halberdiers,
    UNITTYPE_High_Elf_Cavalry,
    UNITTYPE_High_Elf_Magicians,
    UNITTYPE_High_Elf_Settlers,
    UNITTYPE_High_Elf_Longbowmen,
    UNITTYPE_High_Elf_Elven_Lords,
    UNITTYPE_High_Elf_Pegasai,

    UNITTYPE_High_Men_Spearmen,      // 104
    UNITTYPE_High_Men_Swordsmen,
    UNITTYPE_High_Men_Bowmen,
    UNITTYPE_High_Men_Cavalry,
    UNITTYPE_High_Men_Priests,
    UNITTYPE_High_Men_Magicians,
    UNITTYPE_High_Men_Engineers,
    UNITTYPE_High_Men_Settlers,
    UNITTYPE_High_Men_Pikemen,
    UNITTYPE_High_Men_Paladins,

    UNITTYPE_Klackon_Spearmen,       // 114
    UNITTYPE_Klackon_Swordsmen,
    UNITTYPE_Klackon_Halberdiers,
    UNITTYPE_Klackon_Engineers,
    UNITTYPE_Klackon_Settlers,
    UNITTYPE_Klackon_Stag_Beetle,

    UNITTYPE_Lizardman_Spearmen,     // 120
    UNITTYPE_Lizardman_Swordsmen,
    UNITTYPE_Lizardman_Halberdiers,
    UNITTYPE_Lizardman_Javelineers,
    UNITTYPE_Lizardman_Shaman,
    UNITTYPE_Lizardman_Settlers,
    UNITTYPE_Lizardman_Dragon_Turtle,

    UNITTYPE_Nomad_Spearmen,         // 127
    UNITTYPE_Nomad_Swordsmen,
    UNITTYPE_Nomad_Bowmen,
    UNITTYPE_Nomad_Priests,
    UNITTYPE_Nomad_Magicians,
    UNITTYPE_Nomad_Settlers,
    UNITTYPE_Nomad_Horsebowmen,
    UNITTYPE_Nomad_Pikemen,
    UNITTYPE_Nomad_Rangers,
    UNITTYPE_Nomad_Griffins,

    UNITTYPE_Orc_Spearmen,           // 137
    UNITTYPE_Orc_Swordsmen,
    UNITTYPE_Orc_Halberdiers,
    UNITTYPE_Orc_Bowmen,
    UNITTYPE_Orc_Cavalry,
    UNITTYPE_Orc_Shaman,
    UNITTYPE_Orc_Magicians,
    UNITTYPE_Orc_Engineers,
    UNITTYPE_Orc_Settlers,
    UNITTYPE_Orc_Wyvern_Riders,

    UNITTYPE_Troll_Spearmen,         // 147
    UNITTYPE_Troll_Swordsmen,
    UNITTYPE_Troll_Halberdiers,
    UNITTYPE_Troll_Shaman,
    UNITTYPE_Troll_Settlers,
    UNITTYPE_Troll_War_Trolls,
    UNITTYPE_Troll_War_Mammoths,

    // * 0x9A-0xC5: 44 Magical (summoned) Creatures

    UNITTYPE_Arcane_Magic_Spirit,    // 154 0x9A

    UNITTYPE_Red_Hell_Hounds,        // 155 0x9B
    UNITTYPE_Red_Gargoyles,
    UNITTYPE_Red_Fire_Giant,
    UNITTYPE_Red_Fire_Elemental,
    UNITTYPE_Red_Chaos_Spawn,
    UNITTYPE_Red_Chimera,
    UNITTYPE_Red_Doom_Bat,
    UNITTYPE_Red_Efreet,
    UNITTYPE_Red_Hydra,
    UNITTYPE_Red_Great_Drake,

    UNITTYPE_Black_Skeletons,        // 165d
    UNITTYPE_Black_Ghouls,
    UNITTYPE_Black_Night_Stalker,
    UNITTYPE_Black_Werewolves,
    UNITTYPE_Black_Demon,
    UNITTYPE_Black_Wraiths,
    UNITTYPE_Black_Shadow_Demons,
    UNITTYPE_Black_Death_Knights,
    UNITTYPE_Black_Demon_Lord,
    UNITTYPE_Black_Zombies,

    UNITTYPE_White_Unicorns,         // 175d
    UNITTYPE_White_Guardian_Spirit,
    UNITTYPE_White_Angel,
    UNITTYPE_White_Arch_Angel,

    UNITTYPE_Green_War_Bears,        // 179d
    UNITTYPE_Green_Sprites,
    UNITTYPE_Green_Cockatrices,
    UNITTYPE_Green_Basilisk,
    UNITTYPE_Green_Giant_Spiders,
    UNITTYPE_Green_Stone_Giant,
    UNITTYPE_Green_Colossus,
    UNITTYPE_Green_Gorgons,
    UNITTYPE_Green_Earth_Elemental,
    UNITTYPE_Green_Behemoth,
    UNITTYPE_Green_Great_Wyrm,

    UNITTYPE_Blue_Floating_Island,
    UNITTYPE_Blue_Phantom_Beast,
    UNITTYPE_Blue_Phantom_Warriors,
    UNITTYPE_Blue_Storm_Giant,
    UNITTYPE_Blue_Air_Elemental,
    UNITTYPE_Blue_Djinn,
    UNITTYPE_Blue_Sky_Drake,
    UNITTYPE_Blue_Nagas,

    eUnit_Type_MAX                // 198 0xC6
};

/*
enum eUpkeep_Enchantment
{
    // Unit_Enchantments
    UPKEEPENCH_Immolation, // 0 Offset EXE:2B3B8
    UPKEEPENCH_Guardian_Wind, // 2 Offset EXE:2B3BA
    UPKEEPENCH_Berserk, // 4 Offset EXE:2B3BC     // Note(12)
    UPKEEPENCH_Cloak_of_Fear, // 6 Offset EXE:2B3BE
    UPKEEPENCH_Black_Channels, // 8 Offset EXE:2B3C0
    UPKEEPENCH_Wraithform, // A Offset EXE:2B3C2
    UPKEEPENCH_Regeneration, // C Offset EXE:2B3C4
    UPKEEPENCH_Pathfinding, // E Offset EXE:2B3C6
    UPKEEPENCH_Water_Walking, // 10 Offset EXE:2B3C8
    UPKEEPENCH_Resist_Elements, // 12 Offset EXE:2B3CA
    UPKEEPENCH_Elemental_Armor, // 14 Offset EXE:2B3CC
    UPKEEPENCH_Stone_Skin, // 16 Offset EXE:2B3CE
    UPKEEPENCH_Iron_Skin, // 18 Offset EXE:2B3D0
    UPKEEPENCH_Endurance, // 1A Offset EXE:2B3D2
    UPKEEPENCH_Spell_Lock, // 1C Offset EXE:2B3D4
    UPKEEPENCH_Invisibility, // 1E Offset EXE:2B3D6
    UPKEEPENCH_Wind_Walking, // 20 Offset EXE:2B3D8
    UPKEEPENCH_Flight, // 22 Offset EXE:2B3DA
    UPKEEPENCH_Resist_Magic, // 24 Offset EXE:2B3DC
    UPKEEPENCH_Magic_Immunity, // 26 Offset EXE:2B3DE
    UPKEEPENCH_Flame_Blade, // 28 Offset EXE:2B3E0
    UPKEEPENCH_Eldritch_Weapon, // 2A Offset EXE:2B3E2
    UPKEEPENCH_True_Sight, // 2C Offset EXE:2B3E4
    UPKEEPENCH_Holy_Weapon, // 2E Offset EXE:2B3E6
    UPKEEPENCH_Heroism, // 30 Offset EXE:2B3E8
    UPKEEPENCH_Bless, // 32 Offset EXE:2B3EA
    UPKEEPENCH_Lion_Heart, // 34 Offset EXE:2B3EC
    UPKEEPENCH_Giant_Strength, // 36 Offset EXE:2B3EE
    UPKEEPENCH_Planar_Travel, // 38 Offset EXE:2B3F0
    UPKEEPENCH_Holy_Armor, // 3A Offset EXE:2B3F2
    UPKEEPENCH_Righteousness, // 3C Offset EXE:2B3F4
    UPKEEPENCH_Invulnerability, // 3E Offset EXE:2B3F6

    // City_Enchantments
    UPKEEPENCH_Wall_of_Fire, // 40 Offset EXE:2B3F8
    UPKEEPENCH_Chaos_Rift, // 42 Offset EXE:2B3FA
    UPKEEPENCH_Dark_Rituals, // 44 Offset EXE:2B3FC
    UPKEEPENCH_Evil_Presence, // 46 Offset EXE:2B3FE
    UPKEEPENCH_Cursed_Lands, // 48 Offset EXE:2B400
    UPKEEPENCH_Pestilence, // 4A Offset EXE:2B402
    UPKEEPENCH_Cloud_of_Shadow, // 4C Offset EXE:2B404
    UPKEEPENCH_Famine, // 4E Offset EXE:2B406
    UPKEEPENCH_Flying_Fortress, // 50 Offset EXE:2B408
    UPKEEPENCH_Nature_Ward, // 52 Offset EXE:2B40A
    UPKEEPENCH_Sorcery_Ward, // 54 Offset EXE:2B40C
    UPKEEPENCH_Chaos_Ward, // 56 Offset EXE:2B40E
    UPKEEPENCH_Life_Ward, // 58 Offset EXE:2B410
    UPKEEPENCH_Death_Ward, // 5A Offset EXE:2B412
    UPKEEPENCH_Natures_Eye, // 5C Offset EXE:2B414
    UPKEEPENCH_Earth_Gate, // 5E Offset EXE:2B416
    UPKEEPENCH_Stream_of_Life, // 60 Offset EXE:2B418
    UPKEEPENCH_Gaias_Blessing, // 62 Offset EXE:2B41A
    UPKEEPENCH_Inspirations, // 64 Offset EXE:2B41C
    UPKEEPENCH_Prosperity, // 66 Offset EXE:2B41E
    UPKEEPENCH_Astral_Gate, // 68 Offset EXE:2B420
    UPKEEPENCH_Heavenly_Light, // 6A Offset EXE:2B422
    UPKEEPENCH_Consecration, // 6C Offset EXE:2B424
    UPKEEPENCH_Wall_of_Darkness, // 6E Offset EXE:2B426
    UPKEEPENCH_Altar_of_Battle, // 70 Offset EXE:2B428
    UPKEEPENCH_Nightshade, // 72 Offset EXE:2B42A

    // Global Enchantments
    UPKEEPENCH_Eternal_Night, // 74 Offset EXE:2B42C
    UPKEEPENCH_Evil_Omens, // 76 Offset EXE:2B42E
    UPKEEPENCH_Zombie_Mastery, // 78 Offset EXE:2B430
    UPKEEPENCH_Aura_of_Majesty, // 7A Offset EXE:2B432
    UPKEEPENCH_Wind_Mastery, // 7C Offset EXE:2B434
    UPKEEPENCH_Suppress_Magic, // 7E Offset EXE:2B436
    UPKEEPENCH_Time_Stop, // 80 Offset EXE:2B438
    UPKEEPENCH_Nature_Awareness, // 82 Offset EXE:2B43A
    UPKEEPENCH_Natures_Wrath, // 84 Offset EXE:2B43C
    UPKEEPENCH_Herb_Mastery, // 86 Offset EXE:2B43E
    UPKEEPENCH_Chaos_Surge, // 88 Offset EXE:2B440
    UPKEEPENCH_Doom_Mastery, // 8A Offset EXE:2B442
    UPKEEPENCH_Great_Wasting, // 8C Offset EXE:2B444
    UPKEEPENCH_Meteor_Storm, // 8E Offset EXE:2B446
    UPKEEPENCH_Armageddon, // 90 Offset EXE:2B448
    UPKEEPENCH_Tranquility, // 92 Offset EXE:2B44A
    UPKEEPENCH_Life_Force, // 94 Offset EXE:2B44C
    UPKEEPENCH_Crusade, // 96 Offset EXE:2B44E
    UPKEEPENCH_Just_Cause, // 98 Offset EXE:2B450
    UPKEEPENCH_Holy_Arms, // 9A Offset EXE:2B452
    UPKEEPENCH_Planar_Seal, // 9C Offset EXE:2B454
    UPKEEPENCH_Charm_of_Life, // 9E Offset EXE:2B456
    UPKEEPENCH_Detect_Magic, // A0 Offset EXE:2B458
    UPKEEPENCH_Awareness, // A2 Offset EXE:2B45A

    eUpkeep_Enchantment_MAX                // A4
};
*/
enum eWar_Status ENUMSIZE8
{
    WARSTATUS_None = 0,
    WARSTATUS_Wizard_Pact = 1,
    WARSTATUS_Alliance = 2,
    WARSTATUS_War = 3
};

enum eWeaponType ENUMSIZE8
{
    WEAPON_normal = 0,
    WEAPON_magic = 1,
    WEAPON_mithril = 2,
    WEAPON_adamantium = 3,
};

enum eYesNo16 ENUMSIZE16
{
    YESNO16_No = 0,
    YESNO16_Yes = 1,

    eYesNo16_Type16__SIZE__ = 0xFFFF
};

enum eYesNo8 ENUMSIZE8
{
    YESNO8_No = 0,
    YESNO8_Yes = 1
};

//
// CONSTANTS
//

static const unsigned gMAX_BATTLE_UNITS = 18;
static const unsigned gMAX_CITIES = 100;
static const unsigned gMAX_HERO_TYPES = 35;
static const unsigned gMAX_HIRED_HEROES = 6;
static const unsigned gMAX_ITEMSLOTS = 3;
static const unsigned gMAX_ITEMS = 138;
static const unsigned gMAX_MAP_COLS = 60;
static const unsigned gMAX_MAP_ROWS = 40;
static const unsigned gMAX_NODES_LAIRS_TOWERS = 102;
static const unsigned gMAX_RACES = 14;
static const unsigned gMAX_UNITS = 1009;
static const unsigned gMAX_VALID_WIZARDS = 5;
static const unsigned gMAX_WIZARD_RECORDS = 6;


//
// STRUCTS / UNIONS
//

typedef struct PACKED_STRUCT // Skills
{
    eYesNo8     Alchemy;        // 00 (0 or 1)
    eYesNo8     Warlord;
    eYesNo8     Chaos_Master;
    eYesNo8     Nature_Master;
    eYesNo8     Sorcery_Master;
    eYesNo8     Infernal_Power; // 05
    eYesNo8     Divine_Power;
    eYesNo8     Sage_Master;
    eYesNo8     Channeller;
    eYesNo8     Myrran;
    eYesNo8     Archmage;       // 0A
    eYesNo8     Mana_Focusing;
    eYesNo8     Node_Mastery;
    eYesNo8     Famous;
    eYesNo8     Runemaster;
    eYesNo8     Conjurer;       // 0F
    eYesNo8     Charismatic;
    eYesNo8     Artificer;      // 11
                                // SIZE 12
} Skills;

typedef union // unionSkills
{
    Skills   s;
    eYesNo8     a[eSkill_MAX]; // (0 or 1)
} unionSkills; // <read=read_unionAbilities>;

typedef struct PACKED_STRUCT // Building_Data
{
    char                m_BuildingName[20];     // 00
    eBuilding           m_Prerequisite1;        // 14
    eBuilding           m_Prerequisite2;        // 16
    eBuilding           m_Replaces_building;    // 18
    eYesNo16            m_Produces_Regulars;    // 1A
    eYesNo16            m_Produces_Veterans;    // 1C
    eYesNo16            m_Produces_Magic_Weapons;   // 1E
    int16_t             m_Upkeep_yield;         // 20
    uint16_t            m_Food_and_pop_bonus;   // 22
    uint16_t            m_Zero_24;              // 24
    uint16_t            m_Unk_26;               // 26
    uint16_t            m_Mana_produced;        // 28
    uint16_t            m_Unk_2A;               // 2A
    uint16_t            m_Building_cost;        // 2C
    uint16_t            m_Zero_2E;              // 2E
    uint16_t            m_Unk_30;               // 30
    uint16_t            m_Unk_32;               // 32
                                                // SIZE 34
} Building_Data;

typedef struct PACKED_STRUCT // Building_Status
{
    eBuildingStatus     None;           // (keep at 0 "Replaced"!!!!!)

    eBuildingStatus     Trade_Goods;    // (keep at -1!!!!!)
    eBuildingStatus     Housing;        // (keep at -1!!!!!)

    eBuildingStatus     Barracks;
    eBuildingStatus     Armory;
    eBuildingStatus     Fighters_Guild;
    eBuildingStatus     Armorers_Guild;
    eBuildingStatus     War_College;
    eBuildingStatus     Smithy;
    eBuildingStatus     Stable;
    eBuildingStatus     Animists_Guild;
    eBuildingStatus     Fantastic_Stable;
    eBuildingStatus     Shipwright_Guild;
    eBuildingStatus     Ship_Yard;
    eBuildingStatus     Maritime_Guild;
    eBuildingStatus     Sawmill;
    eBuildingStatus     Library;
    eBuildingStatus     Sages_Guild;
    eBuildingStatus     Oracle;
    eBuildingStatus     Alchemist_Guild;
    eBuildingStatus     University;
    eBuildingStatus     Wizards_Guild;
    eBuildingStatus     Shrine;
    eBuildingStatus     Temple;
    eBuildingStatus     Parthenon;
    eBuildingStatus     Cathedral;
    eBuildingStatus     Marketplace;
    eBuildingStatus     Bank;
    eBuildingStatus     Merchants_Guild;
    eBuildingStatus     Granary;
    eBuildingStatus     Farmers_Market;
    eBuildingStatus     Foresters_Guild;
    eBuildingStatus     Builders_Hall;
    eBuildingStatus     Mechanicians_Guild;
    eBuildingStatus     Miners_Guild;
    eBuildingStatus     City_Walls;
                                                // SIZE 24
} Building_Status;

typedef union // unionBuilding_Status
{
    eBuildingStatus a[eBuilding_MAX];
    Building_Status s;
} unionBuilding_Status;

typedef struct PACKED_STRUCT // City_Enchantments
{
    eOwner      Wall_of_Fire;
    eOwner      _Chaos_Rift_;
    eOwner      Dark_Rituals;
    eOwner      _Evil_Presence_;
    eOwner      _Cursed_Lands_;
    eOwner      _Pestilence_;
    eOwner      Cloud_of_Shadow;
    eOwner      _Famine_;
    eOwner      Flying_Fortress;
    eOwner      Nature_Ward;
    eOwner      Sorcery_Ward;
    eOwner      Chaos_Ward;
    eOwner      Life_Ward;
    eOwner      Death_Ward;
    eOwner      Natures_Eye;
    eOwner      Earth_Gate;
    eOwner      Stream_of_Life;
    eOwner      Gaias_Blessing;
    eOwner      Inspirations;
    eOwner      Prosperity;
    eOwner      Astral_Gate;
    eOwner      Heavenly_Light;
    eOwner      Consecration;
    eOwner      Wall_of_Darkness;
    eOwner      Altar_of_Battle;
                                    // SIZE 18
} City_Enchantments;

typedef struct PACKED_STRUCT // Combat_Enchantment
{
    uint8_t     Vertigo:1;              // 01
    uint8_t     Confusion:1;            // 02
    uint8_t     Whirlwind:1;            // 04
    uint8_t     Mind_Storm:1;           // 08
    uint8_t     Shatter:1;              // 10
    uint8_t     Weakness:1;             // 20
    uint8_t     Black_Sleep:1;          // 40
    uint8_t     Warp_Creature_Attack:1; // 80

    uint8_t     Warp_Creature_Defense:1;    // 01
    uint8_t     Warp_Creature_Resistance:1; // 02
    uint8_t     Mind_Twist:1;           // 04
    uint8_t     Haste:1;                // 08
    uint8_t     Web:1;                  // 10
    uint8_t     Creature_Binding:1;     // 20
    uint8_t     Possession:1;           // 40
    uint8_t     No_Effect80:1;          // 80
} Combat_Enchantment;

typedef struct PACKED_STRUCT // Events_Status
{
    uint16_t    m_Turn_Event_triggered_GUESS ;         // 00
    uint16_t    m_Meteor_active      ;                 // 02
    uint16_t    m_Meteor_playerNr    ;                 // 04
    uint16_t    m_Meteor_cityNr      ;                 // 06
    uint16_t    m_Gift_of_the_Gods_active ;            // 08
    uint16_t    m_Gift_of_the_Gods_playerNr ;          // 0A
    uint16_t    m_Gift_of_the_Gods_itemNr_GUESS ;      // 0C
    uint16_t    m_Disjunction_active ;                 // 0E
    uint16_t    m_Diplomatic_Marriage_active ;         // 10
    uint16_t    m_Diplomatic_Marriage_playerNr ;       // 12
    uint16_t    m_Diplomatic_Marriage_newCityNr_GUESS ;// 14
    uint16_t    m_Diplomatic_Marriage_cityNr_GUESS ;   // 16
    uint16_t    m_Earthquake_active  ;                 // 18
    uint16_t    m_Earthquake_playerNr ;                // 1A
    uint16_t    m_Earthquake_cityNr  ;                 // 1C
    uint16_t    m_Pirates_active     ;                 // 1E
    uint16_t    m_Pirates_playerNr   ;                 // 20
    uint16_t    m_Pirates_gold_stolen ;                // 22
    uint16_t    m_Plague_active      ;                 // 24
    uint16_t    m_Plague_playerNr    ;                 // 26
    uint16_t    m_Plague_cityNr      ;                 // 28
    uint16_t    m_UNUSED01               ;             // 2A
    uint16_t    m_Rebellion_active   ;                 // 2C
    uint16_t    m_Rebellion_playerNr ;                 // 2E
    uint16_t    m_Rebellion_cityNr   ;                 // 30
    uint16_t    m_Donation_active    ;                 // 32
    uint16_t    m_Donation_playerNr  ;                 // 34
    uint16_t    m_Donation_gold_donated ;              // 36
    uint16_t    m_Depletion_active   ;                 // 38
    uint16_t    m_Depletion_playerNr ;                 // 3A
    uint16_t    m_UNUSED02               ;             // 3C
    uint16_t    m_Mine_found_active  ;                 // 3E
    uint16_t    m_Mine_found_playerNr ;                // 40
    uint16_t    m_UNUSED03               ;             // 42
    uint16_t    m_Population_Boom_active ;             // 44
    uint16_t    m_Population_Boom_CityNr ;             // 46
    uint16_t    m_Population_Boom_PlayerNr ;           // 48
    uint16_t    m_UNUSED04                         ;   // 4A
    uint16_t    m_Good_Moon_active   ;                 // 4C
    uint16_t    m_UNUSED05                         ;   // 4E
    uint16_t    m_Bad_Moon_active    ;                 // 50
    uint16_t    m_UNUSED06                         ;   // 52
    uint16_t    m_Conjunction_Sorcery_active ;         // 54
    uint16_t    m_UNUSED07                         ;   // 56
    uint16_t    m_Conjunction_Nature_active ;          // 58
    uint16_t    m_UNUSED08                         ;   // 5A
    uint16_t    m_Conjunction_Chaos_active ;           // 5C
    uint16_t    m_UNUSED09                         ;   // 5E
    uint16_t    m_Mana_Short_active  ;                 // 60
    uint16_t    m_UNUSED10 ;                           // 62
                                                       // SIZE 64
} Events_Status;

typedef struct PACKED_STRUCT // Game_Data_Save
{
    uint16_t        m_Number_of_Wizards;    // in Wizard Table (including YOU, 2 ... 5)
    eLand_Size      m_Land_Size_setting;
    eMagic_Powerful m_Magic_Powerful_setting;
    eDifficulty     m_Difficulty;
    uint16_t        m_Number_of_Cities;     // in City Table (0 ... 100, of out of a maximum of 100)
    uint16_t        m_Number_of_Units;      // in Unit Instance Table (0 ... 1000, out of a maximum of 1000)
    uint16_t        m_Current_Turn; // <read=read_Turn>;         // year is 1400 + Turn/12, month is Turn%12
    uint16_t        m_UnitNr_Active;
                                            // SIZE 16
} Game_Data_Save;


typedef struct PACKED_STRUCT // Global_Enchantments
{
    uint8_t     Eternal_Night;
    uint8_t     Evil_Omens;
    uint8_t     Zombie_Mastery;
    uint8_t     Aura_of_Majesty;
    uint8_t     Wind_Mastery;
    uint8_t     Suppress_Magic;
    uint8_t     Time_Stop;
    uint8_t     Nature_Awareness;
    uint8_t     Natures_Wrath;
    uint8_t     Herb_Mastery;
    uint8_t     Chaos_Surge;
    uint8_t     Doom_Mastery;
    uint8_t     Great_Wasting;
    uint8_t     Meteor_Storm;
    uint8_t     Armageddon;
    uint8_t     Tranquility;
    uint8_t     Life_Force;
    uint8_t     Crusade;
    uint8_t     Just_Cause;
    uint8_t     Holy_Arms;
    uint8_t     Planar_Seal;
    uint8_t     Charm_of_Life;
    uint8_t     Detect_Magic;
    uint8_t     Awareness;
                                    // SIZE 24
} Global_Enchantments;


typedef struct PACKED_STRUCT // Hero_Ability
{
    uint8_t     Leadership:1;       // 01
    uint8_t     Leadership_X:1;     // 02
    uint8_t     u1:1;               // 04
    uint8_t     Legendary:1;        // 08
    uint8_t     Legendary_X:1;      // 10
    uint8_t     u0:1;               // 20
    uint8_t     Blademaster:1;      // 40
    uint8_t     Blademaster_X:1;    // 80

    uint8_t     u4:1;               // 01
    uint8_t     Armsmaster:1;       // 02
    uint8_t     Armsmaster_X:1;     // 04
    uint8_t     u3:1;               // 08
    uint8_t     Constitution:1;     // 10
    uint8_t     Constitution_X:1;   // 20
    uint8_t     u2:1;               // 40
    uint8_t     Might:1;            // 80

    uint8_t     Might_X:1;          // 01
    uint8_t     u7:1;               // 02
    uint8_t     Arcane_Power:1;     // 04
    uint8_t     Arcane_Power_X:1;   // 08
    uint8_t     u6:1;               // 10
    uint8_t     Sage:1;             // 20
    uint8_t     Sage_X:1;           // 40
    uint8_t     u5:1;               // 80

    uint8_t     Prayermaster:1;     // 01
    uint8_t     Prayermaster_X:1;   // 02
    uint8_t     Agility_X:1;        // 04
    uint8_t     Lucky:1;            // 08
    uint8_t     Charmed:1;          // 10
    uint8_t     Noble:1;            // 20
    uint8_t     u8:1;               // 40
    uint8_t     Agility:1;          // 80
} Hero_Ability;


typedef union // unionHero_Abilities;
{
    Hero_Ability    s;      // <read=read_Hero_Ability>;
    uint32_t        bits;   // <format=hex>;
} unionHero_Abilities; // <read=read_unionHero_Abilities>;

    
typedef struct PACKED_STRUCT // Hired_Hero
{
    int16_t     m_Unit_Nr;              // 00 (see below)
    char        m_Hero_name[14];        // 02 (13 characters + '\0')
    int16_t     m_Items_In_Slot[3];     // 10 (see below)
    eSlot_Type16 m_Slot_Types[3];       // 16 (0-6; see below)
                                        // SIZE 1C
} Hired_Hero;    // <read=read_Hired_Hero>;


typedef struct PACKED_STRUCT // Hero_stats
{
    eHero_Level_Status  m_Level_Status;     // 00
    unionHero_Abilities m_Hero_Abilities;   // 02
    uint8_t     m_Hero_Casting_Skill;       // 06 <read=read_Hero_Casting_Skill>;
    eSpell      m_Spell[4];                 // 07-0A
    uint8_t     m_Garbage;                  // 0B
                                            // SIZE 0C
} Hero_stats; // <read=read_Hero_stats>;

typedef struct PACKED_STRUCT // Hero_Stats_Initializer
{
    uint16_t    m_Nr_Random_picks;          // 00
    eRandomPickType    m_Random_pick_type;  // 02
    unionHero_Abilities m_Hero_Abilities;   // 04
    uint16_t    m_Hero_Casting_Skill;       // 08 <read=read_Hero_Casting_Skill>;
    eSpell16    m_Spell[4];                 // 0A-11
                                            // SIZE 12
} Hero_Stats_Initializer;


typedef struct PACKED_STRUCT // Item_Bonuses
{
    int8_t      Attack;                 // 00
    int8_t      To_Hit;                 // 01
    int8_t      Defense;                // 02
    int8_t      Movement_in_halves;     // 03
    int8_t      Resistance;             // 04
    int8_t      Spell_Points;           // 05
    int8_t      Spell_Save;             // 06
                                        // SIZE 07
} Item_Bonuses; // <read=read_Item_Bonuses>;


typedef struct PACKED_STRUCT Item_Powers
{
    uint8_t     Vampiric:1;
    uint8_t     Guardian_Wind:1;
    uint8_t     Lightning:1;
    uint8_t     Cloak_Of_Fear:1;
    uint8_t     Destruction:1;
    uint8_t     Wraith_Form:1;
    uint8_t     Regeneration:1;
    uint8_t     Pathfinding:1;

    uint8_t     Water_Walking:1;
    uint8_t     Resist_Elements:1;
    uint8_t     Elemental_Armour:1;
    uint8_t     Doom_equals_Chaos:1;
    uint8_t     Stoning:1;
    uint8_t     Endurance:1;
    uint8_t     Haste:1;
    uint8_t     Invisibility:1;

    uint8_t     Death:1;
    uint8_t     Flight:1;
    uint8_t     Resist_Magic:1;
    uint8_t     Magic_Immunity:1;
    uint8_t     Flaming:1;
    uint8_t     Holy_Avenger:1;
    uint8_t     True_Sight:1;
    uint8_t     Phantasmal:1;

    uint8_t     Power_Drain:1;
    uint8_t     Bless:1;
    uint8_t     Lion_Heart:1;
    uint8_t     Giant_Strength:1;
    uint8_t     Planar_Travel:1;
    uint8_t     Merging:1;
    uint8_t     Righteousness:1;
    uint8_t     Invulnerability:1;
} Item_Powers;


typedef union // unionItem_Powers
{
    Item_Powers s;
    uint32_t    bits; // <format=hex>;
} unionItem_Powers; // <read=read_unionItem_Powers>;


typedef struct PACKED_STRUCT // Item
{
    //uint8_t m_Data[0x32];
    char        m_Item_Name[30];            // 00 Item's Name (30 characters + '\0')
    eItem_Icon  m_Icon;                     // 1E Icon (0-0x73; see below)
    eSlot_Type8 m_Slot_Required;            // 20 Slot Required (0-6; see above)
    eItem_Type  m_Item_Type;                // 21 Item Type (0-8; see below)
    int16_t     m_Cost;                     // 22 Cost
    Item_Bonuses        m_Bonuses;          // 24 Bonuses
    eSpell      m_Spell_Number_Charged;     // 2B Spell Number Charged + 1 (-> 0 means no spell charge)
    int16_t     m_Number_Of_Charges;        // 2C Number Of Charges
    unionItem_Powers    m_Bitmask_Powers;   // 2E (bitmasks) Powers
                                            // SIZE 32
} Item; // <read=read_Item>;


typedef struct PACKED_STRUCT List_Hero_stats
{
    //Hero_stats m_Hero_Stats[35];
    Hero_stats      Dwarf;
    Hero_stats      Barbarian;
    Hero_stats      Sage;
    Hero_stats      Dervish;
    Hero_stats      Beastmaster;
    Hero_stats      Bard;
    Hero_stats      Orc_Warrior;
    Hero_stats      Healer;
    Hero_stats      Huntress;
    Hero_stats      Thief;
    Hero_stats      Druid;
    Hero_stats      War_Monk;
    Hero_stats      Warrior_Mage;
    Hero_stats      Magician;
    Hero_stats      Assassin;
    Hero_stats      Wind_Mage;
    Hero_stats      Ranger;
    Hero_stats      Draconian;
    Hero_stats      Witch;
    Hero_stats      Golden_One;
    Hero_stats      Ninja;
    Hero_stats      Rogue;
    Hero_stats      Amazon;
    Hero_stats      Warlock;
    Hero_stats      Unknown;
    Hero_stats      Illusionist;
    Hero_stats      Swordsman;
    Hero_stats      Priestess;
    Hero_stats      Paladin;
    Hero_stats      Black_Knight;
    Hero_stats      Elven_Archer;
    Hero_stats      Knight;
    Hero_stats      Necromancer;
    Hero_stats      Chaos_Warrior;
    Hero_stats      Chosen;
} List_Hero_stats;

typedef union // unionList_Hero_stats
{
    Hero_stats      a[gMAX_HERO_TYPES];
    List_Hero_stats s;
} unionList_Hero_stats;

typedef struct PACKED_STRUCT // Location
{
    uint8_t         m_XPos;         // 00
    uint8_t         m_YPos;         // 01
    ePlane          m_Plane;        // 02
                                    // SIZE 03
} Location;

typedef struct PACKED_STRUCT // MapRow_Bonus
{
    eBonusDeposit   m_Bonus_Deposit[60];
} MapRow_Bonus;


typedef struct PACKED_STRUCT // MapRow_Exploration
{
    uint8_t         m_Explored[60];
} MapRow_Exploration;


typedef struct PACKED_STRUCT // MapRow_LandMassID
{
    uint8_t         m_LandMassID[60];
} MapRow_LandMassID; // <read=read_MapRow_LandMassID>;


typedef struct PACKED_STRUCT // MapRow_Movement
{
    int8_t          m_Moves[60];    // -1 = impassible
} MapRow_Movement; // <read=read_MapRow_Movement>;


typedef struct PACKED_STRUCT // MapRow_Terrain
{
    eTerrainType    m_Tile[60];
} MapRow_Terrain;


typedef struct PACKED_STRUCT // Terrain_Flags
{
    uint8_t     Volcano_producing_for_Owner:3;  // 07 //1 MP/turn for Wizard 1 (YOU) through 5, 0 = no one
    uint8_t     road:1;                         // 08
    uint8_t     enchanted_road:1;               // 10
    uint8_t     corruption:1;                   // 20
    uint8_t     u1:1;                           // 40
    uint8_t     u2:1;                           // 80
} Terrain_Flags; // <read=read_Terrain_Flags>;


typedef struct PACKED_STRUCT // MapRow_Terrain_Flags
{
    Terrain_Flags   m_Terrain_Flags[60];
} MapRow_Terrain_Flags;


typedef struct PACKED_STRUCT // Map_Movement
{
    MapRow_Movement    m_Unused_Row[40];
    MapRow_Movement    m_Walking_Row[40];
    MapRow_Movement    m_Forester_Row[40];
    MapRow_Movement    m_Mountaineer_Row[40];
    MapRow_Movement    m_Swimming_Row[40];
    MapRow_Movement    m_Sailing_Row[40];
} Map_Movement;

typedef struct PACKED_STRUCT // Tower_Node_Lair_Flags
{
    uint8_t         m_Prisoner:1;
    uint8_t         m_YOU_aware_Inhabitant1:1;
    uint8_t         m_YOU_aware_Inhabitant2:1;
    uint8_t         m_Zero:5;
                                //01 unknown 
                                //02 YOU explored node and are aware of Inhabitant #1 
                                //04 YOU explored node and are aware of Inhabitant #2 
                                //other bits are not used and are set to zero  
} Tower_Node_Lair_Flags;

typedef union // unionTower_Node_Lair_Flags
{
    Tower_Node_Lair_Flags s;
    uint8_t bits;
} unionTower_Node_Lair_Flags;

typedef struct PACKED_STRUCT // Lair_Inhabitant
{
    eUnit_Type      m_Inhabitant;                       // 05 (monster index)
    uint8_t         m_Remaining_Nr_of_Inhabitant:4;     // 06 LSNybble
    uint8_t         m_Initial_Nr_of_Inhabitant:4;       // 06 MSNybble
} Lair_Inhabitant;

typedef struct PACKED_STRUCT // Tower_Node_Lair
{
    //uint8_t         m_Data[0x18];
    uint8_t         m_XPos;             // 00
    uint8_t         m_YPos;             // 01
    ePlane          m_Plane;            // 02
    eTower_Node_Lair_Status  m_Status;  // 03 (0 = popped, 1 = intact)
    eTower_Node_Lair_Type    m_Type;    // 04 (e.g., 0ATemple)
    Lair_Inhabitant m_Inhabitant1;      // 05-06
    Lair_Inhabitant m_Inhabitant2;      // 07-08
    uint8_t         m_UNK01;            // 09
    uint16_t        m_Reward_Gold;      // 0A (0, 10 - 200 gold)
    uint16_t        m_Reward_Mana;      // 0C (0, 10 - 200 mana)
    eReward_Specials    m_Reward_Specials;   // 0E
                                //0 = No specials
                                //1 = Common Spell
                                //2 = Uncommon Spell
                                //3 = Rare Spell
                                //4 = Very Rare Spell
                                //5 = 1 Spellbook or Skill (74% - 26%)
                                //6 = 2 Spellbooks or Skills (74% - 26%)
    unionTower_Node_Lair_Flags m_Flags; // 0F
                                //01 Prisoner available
                                //02 YOU explored node and are aware of Inhabitant #1 
                                //04 YOU explored node and are aware of Inhabitant #2 
                                //other bits are not used and are set to zero  
    uint16_t        m_Item_Rewards;     // 10-11 (0 - 3 items)
    uint16_t        m_Item_Value[3];    // 12-17
                                        // SIZE 18
} Tower_Node_Lair; // <read=read_Tower_Node_Lair>;

typedef struct PACKED_STRUCT // Node_Attr
{
//    uint8_t         m_Data[0x30];
    uint8_t         m_XPos;
    uint8_t         m_YPos;
    ePlane          m_Plane;
    ePlayer         m_Owner;        // FF = Not owned by a player
    uint8_t         m_Power_Node;
    uint8_t         m_XPos_Mana[20];
    uint8_t         m_YPos_Mana[20];
    eNode_Type      m_Node_Type;
    uint8_t         m_UNK01[2];     // 00 00 ??
                                    // SIZE 30
} Node_Attr;

typedef struct PACKED_STRUCT // Fortress
{
    uint8_t         m_XPos;
    uint8_t         m_YPos;
    ePlane          m_Plane;
    uint8_t         m_Active; // 00 or 01=non-Eliminated or FF??=not-in-play??
} Fortress;

typedef struct PACKED_STRUCT // Tower_Attr
{
    uint8_t         m_XPos;
    uint8_t         m_YPos;
    uint8_t         m_Closed;   // 00=opened, FF=closed, sealed??
    uint8_t         m_UNK;      // unused ??
} Tower_Attr;

typedef struct PACKED_STRUCT // Map_Tiles
{
    MapRow_Terrain  m_Arcanus_Map_Row[40];
    MapRow_Terrain  m_Myrror_Map_Row[40];
    uint16_t        m_Arcanus_UNK01[0x60];
    uint16_t        m_Myrror_UNK01[0x60];
    MapRow_LandMassID  m_Arcanus_LandMassID_Row[40];
    MapRow_LandMassID  m_Myrror_LandMassID_Row[40];
    Node_Attr       m_Arcanus_Node_Attr[16];
    Node_Attr       m_Myrror_Attr[14];
    Fortress        m_Fortresses[gMAX_WIZARD_RECORDS];
    Tower_Attr      m_Tower_Attr[6];
    // Tower_Node_Lair m_Tower_Node_Lair[102];    // Only 99! Or can it be 102 max?
    //                                           // What happens if a city is reduced to rubble?
    Tower_Node_Lair m_Arcanus_Towers[6];
    Tower_Node_Lair m_Myrror_Towers[6];
    Tower_Node_Lair m_Arcanus_Nodes[16];
    Tower_Node_Lair m_Myrror_Nodes[14];
    Tower_Node_Lair m_Normal_Lairs[25];
    Tower_Node_Lair m_Weak_Lairs[32];
    Tower_Node_Lair m_ExtraLairs_GUESS[3];
} Map_Tiles;


typedef struct PACKED_STRUCT // Map_Attr
{
    MapRow_Bonus            m_Arcanus_Bonus_Row[40];
    MapRow_Bonus            m_Myrror_Bonus_Row[40];
    MapRow_Exploration      m_Arcanus_Exploration_Row[40];
    MapRow_Exploration      m_Myrror_Exploration_Row[40];
    Map_Movement            m_Arcanus_Movement;
    Map_Movement            m_Myrror_Movement;
    Events_Status           m_Events_Status;
    MapRow_Terrain_Flags    m_Arcanus_Terrain_Flags_Row[40];
    MapRow_Terrain_Flags    m_Myrror_Terrain_Flags_Row[40];
} Map_Attr;


typedef struct PACKED_STRUCT // Unit_Weapon_Mutation
{
    //eWeaponType   Weapon_Type:2;
    uint8_t     Weapon_Type:2;
    uint8_t     Chaos_Channels_Demon_Skin:1;
    uint8_t     Chaos_Channels_Demon_Wings:1;
    uint8_t     Chaos_Channels_Fiery_Breath:1;
    uint8_t     Undead:1;
    uint8_t     Stasis_initial:1;
    uint8_t     Stasis_lingering:1;
} Unit_Weapon_Mutation; // <read=read_Unit_Weapon_Mutation>;

typedef union // unionUnit_Weapon_Mutation
{
    Unit_Weapon_Mutation  s;
    uint8_t                bits; // <format=hex>;
} unionUnit_Weapon_Mutation;

typedef struct PACKED_STRUCT // Unit_Enchantment
{
    uint8_t     Immolation:1;       // 01
    uint8_t     Guardian_Wind:1;    // 02
    uint8_t     Berserk:1;          // 04
    uint8_t     Cloak_of_Fear:1;    // 08
    uint8_t     Black_Channels:1;   // 10
    uint8_t     Wraith_Form:1;      // 20
    uint8_t     Regeneration:1;     // 40
    uint8_t     Path_Finding:1;     // 80

    uint8_t     Water_Walking:1;    // 01
    uint8_t     Resist_Elements:1;  // 02
    uint8_t     Elemental_Armor:1;  // 04
    uint8_t     Stone_Skin:1;       // 08
    uint8_t     Iron_Skin:1;        // 10
    uint8_t     Endurance:1;        // 20
    uint8_t     Spell_Lock:1;       // 40
    uint8_t     Invisibility:1;     // 80

    uint8_t     Wind_Walking:1;     // 01
    uint8_t     Flight:1;           // 02
    uint8_t     Resist_Magic:1;     // 04
    uint8_t     Magic_Immunity:1;   // 08
    uint8_t     Flame_Blade:1;      // 10
    uint8_t     Eldritch_Weapon:1;  // 20
    uint8_t     True_Sight:1;       // 40
    uint8_t     Holy_Weapon:1;      // 80

    uint8_t     Heroism:1;          // 01
    uint8_t     Bless:1;            // 02
    uint8_t     Lionheart:1;        // 04
    uint8_t     Giant_Strength:1;   // 08
    uint8_t     Planar_Travel:1;    // 10
    uint8_t     Holy_Armor:1;       // 20
    uint8_t     Righteousness:1;    // 40
    uint8_t     Invulnerability:1;  // 80
} Unit_Enchantment; // <read=read_Unit_Enchantment>;


typedef union // unionUnit_Enchantment
{
    Unit_Enchantment  s;
    uint32_t                bits; // <format=hex>;
} unionUnit_Enchantment; // <read=read_unionUnit_Enchantment>;

typedef struct PACKED_STRUCT // Spells_Cast_in_Battle
{
    uint8_t True_Light[2];          // 00-01    1=True Light (Battle), 2=Heavenly Light (City) / Cloud of Shadow (City), 3=Eternal Darkness (Global)
    uint8_t Darkness[2];            // 02-03
    uint8_t Warp_Reality[2];        // 04-05
    uint8_t Dark_Prayer[2];         // 06-07
    uint8_t Wrack[2];               // 08-09
    uint8_t Metal_Fires[2];         // 0A-0B
    uint8_t Prayer[2];              // 0C-0D
    uint8_t High_Prayer[2];         // 0E-0F
    uint8_t Terror[2];              // 10-11
    uint8_t Call_Lightning[2];      // 12-13
    uint8_t Counter_Magic[2];       // 14-15
    uint8_t Mass_Invisibility[2];   // 16-17
    uint8_t Entangle[2];            // 18-19
    uint8_t Mana_Leak[2];           // 1A-1B
    uint8_t Blur[2];                // 1C-1D
                                    // SIZE 1E
} Spells_Cast_in_Battle;

typedef struct PACKED_STRUCT { // Spells_Known (order in file):

    eSpellKnown     None;

    //    * NATURE
    eSpellKnown     Earth_to_Mud;
    eSpellKnown     Resist_Elements;
    eSpellKnown     Wall_of_Stone;
    eSpellKnown     Giant_Strength;
    eSpellKnown     Web;
    eSpellKnown     War_Bears;
    eSpellKnown     Stone_Skin;
    eSpellKnown     Water_Walking;
    eSpellKnown     Sprites;
    eSpellKnown     Earth_Lore;

    eSpellKnown     Cracks_Call;
    eSpellKnown     Natures_eye;
    eSpellKnown     Ice_Bolt;
    eSpellKnown     Giant_Spiders;
    eSpellKnown     Change_Terrain;
    eSpellKnown     Path_Finding;
    eSpellKnown     Cockatrices;
    eSpellKnown     Transmute;
    eSpellKnown     Natures_Cures;
    eSpellKnown     Basilisk;

    eSpellKnown     Elemental_Armor;
    eSpellKnown     Petrify;
    eSpellKnown     Stone_Giant;
    eSpellKnown     Iron_Skin;
    eSpellKnown     Ice_Storm;
    eSpellKnown     Earthquake;
    eSpellKnown     Gorgons;
    eSpellKnown     Move_Fortress;
    eSpellKnown     Gaias_Blessing;
    eSpellKnown     Earth_Elemental;

    eSpellKnown     Regeneration;
    eSpellKnown     Behemoth;
    eSpellKnown     Entangle;
    eSpellKnown     Nature_Awareness;
    eSpellKnown     Call_Lightning;
    eSpellKnown     Colossus;
    eSpellKnown     Earth_Gate;
    eSpellKnown     Herb_Mastery;
    eSpellKnown     Great_Wyrm;
    eSpellKnown     Natures_Wrath;

    //    * SORCERY
    eSpellKnown     Resist_Magic;
    eSpellKnown     Dispel_Magic_True;
    eSpellKnown     Floating_Island;
    eSpellKnown     Guardian_Wind;
    eSpellKnown     Phantom_Warriors;
    eSpellKnown     Confusion;
    eSpellKnown     Word_of_Recall;
    eSpellKnown     Counter_Magic;
    eSpellKnown     Nagas;
    eSpellKnown     Psionic_Blast;

    eSpellKnown     Blur;
    eSpellKnown     Disenchant_True;
    eSpellKnown     Vertigo;
    eSpellKnown     Spell_Lock;
    eSpellKnown     Enchant_Road;
    eSpellKnown     Flight;
    eSpellKnown     Wind_Mastery;
    eSpellKnown     Spell_Blast;
    eSpellKnown     Aura_of_Majesty;
    eSpellKnown     Phantom_Beast;

    eSpellKnown     Disjunction_True;
    eSpellKnown     Invisibility;
    eSpellKnown     Wind_Walking;
    eSpellKnown     Banish;
    eSpellKnown     Storm_Giant;
    eSpellKnown     Air_Elemental;
    eSpellKnown     Mind_Storm;
    eSpellKnown     Stasis;
    eSpellKnown     Magic_Immunity;
    eSpellKnown     Haste;

    eSpellKnown     Djinn;
    eSpellKnown     Spell_Ward;
    eSpellKnown     Creature_Binding;
    eSpellKnown     Mass_Invisibility;
    eSpellKnown     Great_Unsummoning;
    eSpellKnown     Spell_Binding;
    eSpellKnown     Flying_Fortress;
    eSpellKnown     Sky_Drake;
    eSpellKnown     Suppress_Magic;
    eSpellKnown     Time_Stop;

    //    * CHAOS
    eSpellKnown     Warp_Wood;
    eSpellKnown     Disrupt;
    eSpellKnown     Fire_Bolt;
    eSpellKnown     Hell_Hounds;
    eSpellKnown     Corruption;
    eSpellKnown     Eldritch_Weapon;
    eSpellKnown     Wall_of_Fire;
    eSpellKnown     Shatter;
    eSpellKnown     Warp_Creature;
    eSpellKnown     Fire_Elemental;

    eSpellKnown     Lightning_Bolt;
    eSpellKnown     Fire_Giant;
    eSpellKnown     Chaos_Channels;
    eSpellKnown     Flame_Blade;
    eSpellKnown     Gargoyles;
    eSpellKnown     Fireball;
    eSpellKnown     Doombat;
    eSpellKnown     Raise_Volcano;
    eSpellKnown     Immolation;
    eSpellKnown     Chimeras;

    eSpellKnown     Warp_Lightning;
    eSpellKnown     Metal_Fires;
    eSpellKnown     Chaos_Spawn;
    eSpellKnown     Doom_Bolt;
    eSpellKnown     Magic_Vortex;
    eSpellKnown     Efreet;
    eSpellKnown     Fire_Storm;
    eSpellKnown     Warp_Reality;
    eSpellKnown     Flame_Strike;
    eSpellKnown     Chaos_Rift;

    eSpellKnown     Hydra;
    eSpellKnown     Disintegrate;
    eSpellKnown     Meteor_Storm;
    eSpellKnown     Great_Wasting;
    eSpellKnown     Call_Chaos;
    eSpellKnown     Chaos_Surge;
    eSpellKnown     Doom_Mastery;
    eSpellKnown     Great_Drake;
    eSpellKnown     Call_The_Void;
    eSpellKnown     Armageddon;

    //    * LIFE
    eSpellKnown     Bless;
    eSpellKnown     Star_Fires;
    eSpellKnown     Endurance;
    eSpellKnown     Holy_Weapon;
    eSpellKnown     Healing;
    eSpellKnown     Holy_Armor;
    eSpellKnown     Just_Cause;
    eSpellKnown     True_Light;
    eSpellKnown     Guardian_Spirit;
    eSpellKnown     Heroism;

    eSpellKnown     True_Sight;
    eSpellKnown     Plane_Shift;
    eSpellKnown     Resurrection;
    eSpellKnown     Dispel_Evil;
    eSpellKnown     Planar_Seal;
    eSpellKnown     Unicorns;
    eSpellKnown     Raise_Dead;
    eSpellKnown     Planar_Travel;
    eSpellKnown     Heavenly_Light;
    eSpellKnown     Prayer;

    eSpellKnown     Lionheart;
    eSpellKnown     Incarnation;
    eSpellKnown     Invulnerability;
    eSpellKnown     Righteousness;
    eSpellKnown     Prosperity;
    eSpellKnown     Altar_of_Battle;
    eSpellKnown     Angel;
    eSpellKnown     Stream_of_Life;
    eSpellKnown     Mass_Healing;
    eSpellKnown     Holy_Word;

    eSpellKnown     High_Prayer;
    eSpellKnown     Inspirations;
    eSpellKnown     Astral_Gate;
    eSpellKnown     Holy_Arms;
    eSpellKnown     Consecration;
    eSpellKnown     Life_Force;
    eSpellKnown     Tranquility;
    eSpellKnown     Crusade;
    eSpellKnown     Arch_Angel;
    eSpellKnown     Charm_of_Life;

    //    * DEATH
    eSpellKnown     Skeletons;
    eSpellKnown     Weakness;
    eSpellKnown     Dark_Rituals;
    eSpellKnown     Cloak_of_Fear;
    eSpellKnown     Black_Sleep;
    eSpellKnown     Ghouls;
    eSpellKnown     Life_Drain;
    eSpellKnown     Terror;
    eSpellKnown     Darkness;
    eSpellKnown     Mana_Leak;

    eSpellKnown     Drain_Power;
    eSpellKnown     Possession;
    eSpellKnown     Lycantrophy;
    eSpellKnown     Black_Prayer;
    eSpellKnown     Black_Channels;
    eSpellKnown     Night_Stalker;
    eSpellKnown     Subversion;
    eSpellKnown     Wall_of_Darkness;
    eSpellKnown     Berserk;
    eSpellKnown     Shadow_Demons;

    eSpellKnown     Wraith_Form;
    eSpellKnown     Wrack;
    eSpellKnown     Evil_Presence;
    eSpellKnown     Wraiths;
    eSpellKnown     Cloud_of_Shadow;
    eSpellKnown     Warp_Node;
    eSpellKnown     Black_Wind;
    eSpellKnown     Zombie_Mastery;
    eSpellKnown     Famine;
    eSpellKnown     Cursed_Lands;

    eSpellKnown     Cruel_Unminding;
    eSpellKnown     Word_of_Death;
    eSpellKnown     Death_Knights;
    eSpellKnown     Death_Spell;
    eSpellKnown     Animate_dead;
    eSpellKnown     Pestilence;
    eSpellKnown     Eternal_Night;
    eSpellKnown     Evil_Omens;
    eSpellKnown     Death_Wish;
    eSpellKnown     Demon_Lord;

    //    * ARCANE
    eSpellKnown     Magic_Spirit;
    eSpellKnown     Dispel_Magic;
    eSpellKnown     Summoning_Circle;
    eSpellKnown     Disenchant_Area;
    eSpellKnown     Recall_Hero;
    eSpellKnown     Detect_Magic;
    eSpellKnown     Enchant_Item;
    eSpellKnown     Summon_Hero;
    eSpellKnown     Awareness;
    eSpellKnown     Disjunction;
    eSpellKnown     Create_Artifact;
    eSpellKnown     Summon_Champion;
    eSpellKnown     Spell_Of_Mastery;
    eSpellKnown     Spell_Of_Return;
                                        // SIZE D7
} Spells_Known;

typedef struct PACKED_STRUCT // Wizard
{
    ePortrait       m_Portrait;                         // 000 (0-13)
    char            m_Name[20];                         // 001 (20 characters incl. '\0')
    eRace           m_Home_Race;                        // 015
    eBannerColor    m_BannerColor;                      // 016 (0-4)
    ePersonality    m_Personality;                      // 018 (0-5)
    eObjective      m_Objective;                        // 01A (0-4)
    uint8_t         m_UNK01[8];                         // 01C
    uint16_t        m_Fame;                             // 024
    uint16_t        m_Power_Base;                       // 026
    uint8_t         m_UNK02a[2];                        // 028
    uint8_t         m_Research_Percentage;              // 02A
    uint8_t         m_Mana_Percentage;                  // 02B
    uint8_t         m_Skill_Percentage;                 // 02C
    uint8_t         m_UNK02b;                           // 02D
    int16_t         m_X_Coordinate_of_Summoning_Circle; // 02E (0-59)
    int16_t         m_Y_Coordinate_of_Summoning_Circle; // 030 (0-59)
    ePlane          m_Plane_of_Summoning_Circle;        // 032 (0-1)
    uint8_t         m_Zero01;
    eSpell16        m_Research_Spell_candidates[8];     // 034
    uint8_t         m_UNK03a[4];                        // 044
    uint16_t        m_UNK_048;                          // 048
    uint8_t         m_UNK03b[4];                        // 04A
    uint16_t        m_Cost_Left_of_Spell_being_cast;    // 04E
    uint16_t        m_Initial_Cost_of_Spell_being_cast; // 050
    eSpell          m_Spell_being_cast;                 // 052
    uint8_t         m_Zero02;                           //
    int16_t         m_Unused_Casting_Skill_available_this_turn;     // 054
    int16_t         m_Nominal_Casting_Skill_available_this_turn;    // 056
    eTax_Rate       m_Tax_Rate;                         // 058
    int16_t         m_Number_of_Spellbooks_Nature;      // 05A (0-12) (Na-So-Ch-Li-De)
    int16_t         m_Number_of_Spellbooks_Sorcery;     //
    int16_t         m_Number_of_Spellbooks_Chaos;       //
    int16_t         m_Number_of_Spellbooks_Life;        //
    int16_t         m_Number_of_Spellbooks_Death;       //
    unionSkills     m_Skills;                           // 064
    Hired_Hero      m_Heroes_hired_by_wizard[gMAX_HIRED_HEROES];    // 076 six slots
    uint8_t         m_UNK06[2];                         // 11E
    int16_t         m_Items_in_Slots[4];                // 120 (See below)
    int8_t          m_Contacted[6];                     // 128
    int16_t         m_UNK07a_Relation[6];               // 12E
    int16_t         m_UNK07b_Relation[6];               // 13A
    int16_t         m_UNK07c_Relation[6];               // 146
    int8_t          m_Current_Wizard_Relations[6];      // 152
                                                        //    Notes:
                                                        //    Minimum -100 (if below, game resets to this).
                                                        //    Maximum 100 (if above, game resets to this).
                                                        //
                                                        //    Values:
                                                        //    Empty     -128...-120 (128-136)
                                                        //    Hate      -119...-101 (137-155)
                                                        //    Hate      -100...-81 (156-175)
                                                        //    Troubled  -80...-61 (176-195)
                                                        //    Tense     -60...-41 (196-215)
                                                        //    Restless  -40...-21 (216-235)
                                                        //    Unease    -20...-1 (236-255)
                                                        //    Neutral   0...19
                                                        //    Relaxed   20...39
                                                        //    Calm      40...59
                                                        //    Peaceful  60...79
                                                        //    Friendly  80...99
                                                        //    Harmony   100...119
                                                        //    No Treaty 120...127
    eWar_Status     m_War_Status[6];                    // 158 (0=None, 1=Wizard Pact, 2=Alliance, 3+=War)
    int8_t          m_UNK07d[0x24];                     // 15E
    int8_t          m_UNK07e_Relation[6];               // 182
    int8_t          m_UNK07f_Relation[6];               // 188
    int8_t          m_UNK07g[0xCC];                     // 18E
    int16_t         m_Researching_Left;                 // 25A
    int16_t         m_Mana_Crystals;                    // 25C
    int32_t         m_Wizard_Casting_Skill;             // 25E <read=read_Wizard_Casting_Skill>;
                                                        //     (actual skill is square root of value stored here, rounded up)
    eSpell          m_Researching_Spell;                // 262
    Spells_Known    m_Spells_Known;                     // 263 Spells (0-3) (None-Na-So-Ch-Li-De-Ar)
    int8_t          m_UNK09a[26];                       // 33A
    int8_t          m_UNK_354;                          // 354
    int8_t          m_UNK_355;                          // 355
    int16_t         m_Gold_Coins;                       // 356
    int16_t         m_UNK09b;                           // 358
    uint16_t        m_Astrologer_Magic_Power;           // 35A (0-200)
    uint16_t        m_Astrologer_Spell_Research;        // 35C (0-200)
    uint16_t        m_Astrologer_Army_Strength;         // 35E (0-200)
    uint16_t        m_Astrologer_Power_GUESS;           // 360
    uint8_t         m_Historian[288];                   // 362
                                                        //  Values: 0...0xA0 (0...160) - Sum of Magic Power, Army Strength, and Spell Research
                                                        //  Notes: 0xA0 is barely above the graph
    Global_Enchantments  m_Global_Enchantments;         // 482
    uint8_t         m_UNK11[42];                        // 49A
    eRealm_Type     m_Books_Color;                      // 4C4
    uint8_t         m_Zero04;                           // 
    uint16_t        m_UNK12;                            // 4C6
                                                        // SIZE 4C8
} Wizard; // <read=read_Wizard>;

typedef struct PACKED_STRUCT // Wizard_Type_Data
{
    char            m_Wizard_Name[10];                  // 00
    uint16_t        m_Life_books;                       // 0A
    uint16_t        m_Sorcery_books;                    // 0C
    uint16_t        m_Nature_books;                     // 0E
    uint16_t        m_Death_books;                      // 10
    uint16_t        m_Chaos_books;                      // 12
    eSkill16        m_Skill;                            // 14
                                                        // SIZE 16
} Wizard_Type_Data;

typedef struct PACKED_STRUCT // City
{
    char            m_City_Name[14];            // 00
    eRace           m_Race;                     // 0E
    int8_t          m_XPos;                     // 0F (0-59)
    int8_t          m_YPos;                     // 10 (0-59)
    ePlane          m_Plane;                    // 11 (0 or 1)
    ePlayer         m_Owner;                    // 12 (0-4)
    eCity_Size      m_Size;                     // 13 (0-5; see below)
    uint8_t         m_Population;               // 14 (in thousands) (0-25)
    uint8_t         m_Number_of_farmers_allocated;  // 15 (should be <= population)
    uint8_t         m_UNK01a[2];                // 16-17
    uint8_t         m_PopulationDekaPop;        // 18 (in tenths) (Outpost is 1-9, else 0-99)
    uint8_t         m_UNK01b;                   // 19
    uint8_t         m_Player_as_bitmask_GUESS;  // 1A
    uint8_t         m_UNK01c;                   // 1B
    eProducing      m_Producing;                // 1C-1D (0-??; see below)
    uint8_t         m_UNK02;                    // 1E
    unionBuilding_Status     m_Building_Status; // 1F-42
    City_Enchantments   m_City_Enchantments;    // 43-5B (0 = not present, 1-5 = owner + 1)
    eYesNo8         m_Nightshade;               // 5C (0 or 1)
    uint8_t         m_Hammers;                  // 5D
    uint16_t        m_HammersAccumulated;       // 5E-5F
    uint8_t         m_Coins;                    // 60
    uint8_t         m_Maintenance;              // 61
    uint8_t         m_Mana_cr;                  // 62
    uint8_t         m_Research;                 // 63
    uint8_t         m_Food_Produced;            // 64
    int8_t          m_Road_Connection_GUESS;    // 65
    uint8_t         m_UNK03[12];                // 66-71
                                                // SIZE 72
} City; // <read=read_City>;

typedef struct PACKED_STRUCT // Unit
{
    int8_t      m_XPos;                     // 00 X-Pos (0-59)
    int8_t      m_YPos;                     // 01 Y-Pos (0-39)
    ePlane      m_Plane;                    // 02 Plane
                                            //   00=Arcanus
                                            //   01=Myrror
                                            //   FF=Dismissed / Deceased
    ePlayer     m_Owner;                    // 03 'Owner'
                                            //   00=Player
                                            //   01=First Opponent
                                            //   02=Second Opponent
                                            //   03=Third Opponent
                                            //   04=Fourth Opponent
                                            //   05=Neutral Unit
                                            //   FF=Dismissed / Deceased
    int8_t      m_Moves_Total;              // 04 Moves Total (in 1/2 moves)
    eUnit_Type  m_Unit_Type;                // 05 Icon Number (0x00 - 0xC5)
    int8_t      m_Hero_Slot_Number;         // 06 Hero Slot Number (0-5; -1 (0xFF) means not a hero) (see below)
    eUnit_Active    m_Active;               // 07 Active
    int8_t      m_Moves_Left;               // 08 Moves Left (in 1/2 moves)
    int8_t      m_XPos_of_destination;      // 09 X-Pos of destination (should be 0 if status is not GOING TO)
    int8_t      m_YPos_of_destination;      // 0A Y-Pos of destination (should be 0 if status is not GOING TO)
    eUnit_Status    m_Status;               // 0B Status (0-5)
    eLevel      m_Level;                    // 0C Level (Units: 0-5; Heroes: 0-8; Summon (other than Torin): 0)
    int8_t      m_UNK01;                    // 0D ?? 00
    int16_t     m_Experience;               // 0E-0F Experience (should match level or level will be lowered)
                                            //  (Units: 0-120; Heroes: 0-1000; Summon (other than Torin): 0)
    int8_t      m_Guess_Lifedrain_Damage;   // 10
    int8_t      m_Damage;                   // 11
    uint8_t     m_Grouping;                 // 12
    int8_t      m_Guess_Combat_Enchantment_Flag1; // 13
    int8_t      m_In_Tower_without_Seal; // 14
    int8_t      m_Guess_Combat_Enchantment_Flag3; // 15
    uint8_t     m_Scout;                   // 16
    unionUnit_Weapon_Mutation   m_Weapon_Mutation;  // 17
    unionUnit_Enchantment       m_Unit_Enchantment; // 18-1B <format=hex>;
    int8_t      m_Road_Building_left_to_complete;   // 1C
    int8_t      m_Road_Building_parms[3];           // 1D-1F
                                            // SIZE 20
} Unit; // <read=read_Unit>;

typedef struct PACKED_STRUCT // Upkeep_Enchantments
{
    // Unit_Enchantments
    uint16_t Immolation; // 0 Offset EXE:2B3B8
    uint16_t Guardian_Wind; // 2 Offset EXE:2B3BA
    uint16_t Berserk; // 4 Offset EXE:2B3BC     // Note(12)
    uint16_t Cloak_of_Fear; // 6 Offset EXE:2B3BE
    uint16_t Black_Channels; // 8 Offset EXE:2B3C0
    uint16_t Wraith_Form; // A Offset EXE:2B3C2
    uint16_t Regeneration; // C Offset EXE:2B3C4
    uint16_t Path_Finding; // E Offset EXE:2B3C6
    uint16_t Water_Walking; // 10 Offset EXE:2B3C8
    uint16_t Resist_Elements; // 12 Offset EXE:2B3CA
    uint16_t Elemental_Armor; // 14 Offset EXE:2B3CC
    uint16_t Stone_Skin; // 16 Offset EXE:2B3CE
    uint16_t Iron_Skin; // 18 Offset EXE:2B3D0
    uint16_t Endurance; // 1A Offset EXE:2B3D2
    uint16_t Spell_Lock; // 1C Offset EXE:2B3D4
    uint16_t Invisibility; // 1E Offset EXE:2B3D6
    uint16_t Wind_Walking; // 20 Offset EXE:2B3D8
    uint16_t Flight; // 22 Offset EXE:2B3DA
    uint16_t Resist_Magic; // 24 Offset EXE:2B3DC
    uint16_t Magic_Immunity; // 26 Offset EXE:2B3DE
    uint16_t Flame_Blade; // 28 Offset EXE:2B3E0
    uint16_t Eldritch_Weapon; // 2A Offset EXE:2B3E2
    uint16_t True_Sight; // 2C Offset EXE:2B3E4
    uint16_t Holy_Weapon; // 2E Offset EXE:2B3E6
    uint16_t Heroism; // 30 Offset EXE:2B3E8
    uint16_t Bless; // 32 Offset EXE:2B3EA
    uint16_t Lionheart; // 34 Offset EXE:2B3EC
    uint16_t Giant_Strength; // 36 Offset EXE:2B3EE
    uint16_t Planar_Travel; // 38 Offset EXE:2B3F0
    uint16_t Holy_Armor; // 3A Offset EXE:2B3F2
    uint16_t Righteousness; // 3C Offset EXE:2B3F4
    uint16_t Invulnerability; // 3E Offset EXE:2B3F6

    // City_Enchantments
    uint16_t Wall_of_Fire; // 40 Offset EXE:2B3F8
    uint16_t Chaos_Rift; // 42 Offset EXE:2B3FA
    uint16_t Dark_Rituals; // 44 Offset EXE:2B3FC
    uint16_t Evil_Presence; // 46 Offset EXE:2B3FE
    uint16_t Cursed_Lands; // 48 Offset EXE:2B400
    uint16_t Pestilence; // 4A Offset EXE:2B402
    uint16_t Cloud_of_Shadow; // 4C Offset EXE:2B404
    uint16_t Famine; // 4E Offset EXE:2B406
    uint16_t Flying_Fortress; // 50 Offset EXE:2B408
    uint16_t Nature_Ward; // 52 Offset EXE:2B40A
    uint16_t Sorcery_Ward; // 54 Offset EXE:2B40C
    uint16_t Chaos_Ward; // 56 Offset EXE:2B40E
    uint16_t Life_Ward; // 58 Offset EXE:2B410
    uint16_t Death_Ward; // 5A Offset EXE:2B412
    uint16_t Natures_Eye; // 5C Offset EXE:2B414
    uint16_t Earth_Gate; // 5E Offset EXE:2B416
    uint16_t Stream_of_Life; // 60 Offset EXE:2B418
    uint16_t Gaias_Blessing; // 62 Offset EXE:2B41A
    uint16_t Inspirations; // 64 Offset EXE:2B41C
    uint16_t Prosperity; // 66 Offset EXE:2B41E
    uint16_t Astral_Gate; // 68 Offset EXE:2B420
    uint16_t Heavenly_Light; // 6A Offset EXE:2B422
    uint16_t Consecration; // 6C Offset EXE:2B424
    uint16_t Wall_of_Darkness; // 6E Offset EXE:2B426
    uint16_t Altar_of_Battle; // 70 Offset EXE:2B428
    uint16_t Nightshade; // 72 Offset EXE:2B42A

    // Global Enchantments
    uint16_t Eternal_Night; // 74 Offset EXE:2B42C
    uint16_t Evil_Omens; // 76 Offset EXE:2B42E
    uint16_t Zombie_Mastery; // 78 Offset EXE:2B430
    uint16_t Aura_of_Majesty; // 7A Offset EXE:2B432
    uint16_t Wind_Mastery; // 7C Offset EXE:2B434
    uint16_t Suppress_Magic; // 7E Offset EXE:2B436
    uint16_t Time_Stop; // 80 Offset EXE:2B438
    uint16_t Nature_Awareness; // 82 Offset EXE:2B43A
    uint16_t Natures_Wrath; // 84 Offset EXE:2B43C
    uint16_t Herb_Mastery; // 86 Offset EXE:2B43E
    uint16_t Chaos_Surge; // 88 Offset EXE:2B440
    uint16_t Doom_Mastery; // 8A Offset EXE:2B442
    uint16_t Great_Wasting; // 8C Offset EXE:2B444
    uint16_t Meteor_Storm; // 8E Offset EXE:2B446
    uint16_t Armageddon; // 90 Offset EXE:2B448
    uint16_t Tranquility; // 92 Offset EXE:2B44A
    uint16_t Life_Force; // 94 Offset EXE:2B44C
    uint16_t Crusade; // 96 Offset EXE:2B44E
    uint16_t Just_Cause; // 98 Offset EXE:2B450
    uint16_t Holy_Arms; // 9A Offset EXE:2B452
    uint16_t Planar_Seal; // 9C Offset EXE:2B454
    uint16_t Charm_of_Life; // 9E Offset EXE:2B456
    uint16_t Detect_Magic; // A0 Offset EXE:2B458
    uint16_t Awareness; // A2 Offset EXE:2B45A
                        // SIZE A4
} Upkeep_Enchantments;

typedef struct PACKED_STRUCT // Hero_Choice
{
    char        m_Name[14];
    uint8_t     m_UNK[2];
                                // SIZE 10
} Hero_Choice;

typedef struct PACKED_STRUCT // SaveGame
{
SetBackColor( cLtBlue );
    unionList_Hero_stats m_List_Hero_stats[gMAX_WIZARD_RECORDS];
SetBackColor( cGray );
    Game_Data_Save  m_Game_Data;
SetBackColor( cPurple );
    Wizard          m_Wizards[gMAX_WIZARD_RECORDS];
SetBackColor( cGreen );
    Map_Tiles       m_Map_Tiles;
SetBackColor( cYellow );
    Item            m_Items[128];
SetBackColor( cDkYellow );
    Item            m_Item_Trashcan[10];
SetBackColor( cSilver );
    City            m_Cities[gMAX_CITIES];
SetBackColor( cLtRed );
    Unit            m_Unit[1000];
SetBackColor( cDkRed );
    Unit            m_Units_Trashcan_GUESS[9];
SetBackColor( cLtGreen );
    Map_Attr        m_Map_Attr;
SetBackColor( cGray );
    eGrand_Vizier   m_Grand_Vizier;
SetBackColor( cYellow );
    uint8_t         m_Items_in_Game[250];   // 00 = not in game, 01 = in game
SetBackColor( cLtBlue );
    Hero_Choice     m_Hero_Choices[gMAX_HERO_TYPES];
} SaveGame;

//---------------------------------------------

typedef struct PACKED_STRUCT // Movement_Flags
{
    uint8_t     Cavalry:1;     // 01
    uint8_t     Sailing:1;      // 02
    uint8_t     Swimming:1;     // 04
    uint8_t     Flying:1;       // 08
    uint8_t     Teleporting:1;      // 10
    uint8_t     Forester:1;     // 20
    uint8_t     Mountaineer:1;      // 40
    uint8_t     Merging:1;     // 80
} Movement_Flags;

typedef struct PACKED_STRUCT // Immunity_Flags
{
    uint8_t     Fire_Immunity:1;        // 01
    uint8_t     Stoning_Immunity:1;     // 02
    uint8_t     Missiles_Immunity:1;    // 04
    uint8_t     Illusions_Immunity:1;   // 08
    uint8_t     Cold_Immunity:1;        // 10
    uint8_t     Magic_Immunity:1;       // 20
    uint8_t     Death_Immunity:1;       // 40
    uint8_t     Poison_Immunity:1;      // 80
} Immunity_Flags;

typedef struct PACKED_STRUCT // Attribute_Flags
{
    uint8_t     Weapon_Immunity:1;      // 01
    uint8_t     Flyer:1;                // 02
    uint8_t     Lucky:1;                // 04
    uint8_t     Summon_Demons_1:1;      // 08
    uint8_t     Summon_Demons_2:1;      // 10
    uint8_t     Caster_20_MP:1;         // 20
    uint8_t     Caster_40_MP:1;         // 40
    uint8_t     Standard:1;             // 80

    uint8_t     Healing_Spell:1;        // 01
    uint8_t     Fire_Ball_Spell:1;      // 02
    uint8_t     Doombolt_Spell:1;       // 04
    uint8_t     Immolation:1;           // 08
    uint8_t     Web_Spell:1;            // 10
    uint8_t     Cause_Fear_Spell:1;     // 20
    uint8_t     Resistance_to_All:1;    // 40
    uint8_t     Holy_Bonus:1;           // 80
} Attribute_Flags;

typedef struct PACKED_STRUCT // Ability_Flags
{
    uint8_t     Summoned_Unit:1;      // 01
    uint8_t     Large_Shield:1;     // 02
    uint8_t     Plane_Shift:1;      // 04
    uint8_t     Wall_Crusher:1;     // 08
    uint8_t     Healer:1;       // 10
    uint8_t     Create_Outpost:1;       // 20
    uint8_t     Invisibility:1;     // 40
    uint8_t     Create_Undead:1;        // 80

    uint8_t     Long_Range:1;       // 01
    uint8_t     Land_Corruption:1;        // 02
    uint8_t     Meld_With_Node:1;       // 04
    uint8_t     Non_Corporeal:1;        // 08
    uint8_t     Wind_Walking:1;     // 10
    uint8_t     Regeneration:1;     // 20
    uint8_t     Purify:1;       // 40
    uint8_t     Negate_First_Strike:1;      // 80
} Ability_Flags;

typedef struct PACKED_STRUCT // Attack_Flags
{
    uint8_t     Armor_Piercing:1;       // 01
    uint8_t     First_Strike:1;         // 02
    uint8_t     Poison_attack:1;        // 04
    uint8_t     Life_Stealing:1;        // 08
    uint8_t     Automatic_Damage:1;     // 10   // Chaos Spawn, Black Sleep
    uint8_t     Destruction:1;          // 20
    uint8_t     Illusionary_attack:1;   // 40
    uint8_t     Stoning_Touch:1;        // 80

    uint8_t     No_effect05:1;          // 01
    uint8_t     Death_Touch:1;          // 02
    uint8_t     Power_Drain:1;          // 04
    uint8_t     Dispel_Evil:1;          // 08
    uint8_t     No_effect04_COMBAT:1;          // 10
    uint8_t     No_effect03_COMBAT:1;          // 20
    uint8_t     Eldritch_Weapon_COMBAT:1;      // 40
    uint8_t     Warp_Lightning_COMBAT:1;          // 80
} Attack_Flags;

typedef union // unionMovement_Flags;
{
    Movement_Flags  s;
    uint8_t         bits;
} unionMovement_Flags;

typedef union // unionImmunity_Flags;
{
    Immunity_Flags  s;
    uint8_t         bits;
} unionImmunity_Flags;

typedef union // unionAttribute_Flags;
{
    Attribute_Flags s;
    uint16_t        bits;
} unionAttribute_Flags;

typedef union // unionAbility_Flags;
{
    Ability_Flags   s;
    uint16_t        bits;
} unionAbility_Flags;

typedef union // unionAttack_Flags;
{
    Attack_Flags    s;
    uint16_t        bits;
} unionAttack_Flags;

typedef struct PACKED_STRUCT // Difficulty_Table
{
    int16_t         m_City_Growth_multiplier;       // 00
    int16_t         m_Outpost_Growth_multiplier;    // 02
    int16_t         m_City_Production_multiplier;   // 04
    int16_t         m_City_Coin_multiplier;         // 06
    int16_t         m_City_Mana_multiplier;         // 08
    int16_t         m_City_Research_multiplier;     // 0A
    int16_t         m_City_Food_multiplier;         // 0C
    int16_t         m_City_Maintenance_multiplier;  // 0E
                                                    // SIZE 10
} Difficulty_Table;

typedef struct PACKED_STRUCT // Spell_Data
{
    char            m_SpellName[19];            // 00 ",    0X0,    0x50000400, 0x0,    19);
    int16_t         m_Spell_desirability;       // 13,   0x10000400, -1, 2);
    int8_t          m_Spell_Category;          // 15,   0x000400,   -1, 1);
                            // Spell category?
                            // 4 = Damage spells, spell strength = 0
                            // 12,23 = Banish, Dispel Evil
                            // 22 = Life Drain, Fire Bolt, Ice Bolt, Lightning Bolt, Psionic Blast, Fireball;
                            //      spell strength from field + (mana - cost)
    eSpell_Type     m_Section_in_spell_book;    // 16,   0x000400,   -1, 1);
    eRealm_Type     m_Magic_Realm;              // 17,   0x800400,   GetEnum("enum_RealmType"),  1);
    int8_t          m_Casting_eligibility;      // 18,   0x000400,   -1, 1);
    int8_t          m_UNK01;                    // 19,   0x000400,   -1, 1);
    uint16_t        m_Casting_cost;             // 1A,   0x10000400, -1, 2);
    uint16_t        m_Research_cost;            // 1C,   0x10000400, -1, 2);
    int16_t         m_Sound_effect_when_casting_spell;  // 1E,   0x10000400, -1, 2);
    eUnit_Type      m_Unit_Summoned_or_Spell_Strength;            // 20,   0x000400,   -1, 1);
    unionImmunity_Flags m_Immunity_Flags;       // 21,   0x800400,   GetEnum("enum_AtrributeFlags"), 1);
    unionAttack_Flags   m_Attack_Flags;         // 22,   0x10800400, GetEnum("enum_AttackFlags"),    2);
                                                // SIZE 24
} Spell_Data;

typedef struct PACKED_STRUCT // Unit_Type_Data
{
    uint16_t    m_PtrName;          // 00-01  Pointer to name of unit type (note 1)
    uint8_t     m_Melee;            // 02  Melee attack strength
    uint8_t     m_Ranged;           // 03  Ranged attack strength
    eRanged_Type    m_Ranged_Type;   // 04  Ranged attack type (table 1)
    uint8_t     m_Ranged_Shots;      // 05  Ranged attack number of shots
    uint8_t     m_To_Hit;            // 06  Plus to hit
    uint8_t     m_Defense;          // 07  Defense
    uint8_t     m_Resistance;       // 08  Resistance
    uint8_t     m_MoveHalves;       // 09  Movement rate (in units of 1/2 MP)
    uint16_t    m_Cost;             // 0A-0B  Heroes: cost to hire (note 2)
                                    //     Normal units: cost to build
                                    //     Summoned units: cost to place in lair, node or rampaging force (note 3)
    uint8_t     m_Upkeep;           // 0C  Summoned units: upkeep cost  Others: not used (note 4)
    eRace       m_Race_Code;         // 0D  Race code (table 2)
    uint8_t     m_Building_Required1;    // 0E  Normal units: building required (table 3), Hero: ID Code, Summoned: 6
    eHero_TypeCode     m_Hero_TypeCode_or_Building2;      // 0F  Heroes: type code, Regular units: Building required, Summoned: zero
    uint8_t     m_TypeCode;         // 10  Type code?
    uint8_t     m_UNK01;            // 11  00
    uint8_t     m_Hitpoints;        // 12  Hit points (hearts) per figure
    uint8_t     m_Scout;    // 13  Scouting range
    uint8_t     m_Transport_Capacity;    // 14  Transport capacity (number of units carried)
    uint8_t     m_Nr_Figures;        // 15  Number of figures in the unit
    uint8_t     m_Construction; // 16  Construction capacity (road building)
    int8_t      m_Gaze_Modifier;     // 17  Special attack or bonus strength
    unionMovement_Flags     m_Movement_Flags;   // 18  Movement flags (table 4)
    uint8_t                 m_Zero02;           // 19  00
    unionImmunity_Flags     m_Immunity_Flags;   // 1A  Immunity flags (table 5)
    unionAttribute_Flags    m_Attribute_Flags;  // 1B  Attribute flags (table 6)
                                                // 1C  Attribute flags (table 7)
    uint8_t                 m_Zero03;           // 1D  00
    unionAbility_Flags      m_Ability_Flags;    // 1E  Attribute flags (table 8)
                                                // 1F  Attribute flags (table 9)
    unionAttack_Flags       m_Attack_Flags;     // 20  Special attack flags (table 10)
                                                // 21  Special attack flags (table 11)
    uint8_t    m_UNK02;             // 22  ??
    uint8_t    m_Zero04;            // 23  00
                                    // SIZE 24
} Unit_Type_Data;

typedef struct PACKED_STRUCT // Battlefield
{
    uint8_t field_0[924]; // 0
    uint8_t field_39C; // 39C
    uint8_t field_39D[461]; // 39D
    uint8_t field_56A; // 56A
    uint8_t field_56B[235]; // 56B
    uint8_t field_656; // 656
    uint8_t field_657; // 657
    uint8_t field_658; // 658
    uint8_t field_659[18]; // 659
    uint8_t field_66B; // 66B
    uint8_t field_66C; // 66C
    uint8_t field_66D; // 66D
    uint8_t field_66E[18]; // 66E
    uint8_t field_680; // 680
    uint8_t field_681; // 681
    uint8_t field_682; // 682
    uint8_t field_683; // 683
    uint8_t field_684[180]; // 684
    uint16_t field_738; // 738
    uint8_t field_73A[668]; // 73A
    uint16_t field_9D6_Merging_Teleporting; // 9D6
    uint8_t field_9D8[252]; // 9D8
    uint16_t field_AD4; // AD4
    uint8_t field_AD6[460]; // AD6
    uint16_t field_CA2_sail; // CA2
    uint8_t field_CA4[460]; // CA4
    uint16_t field_E70; // E70
    uint8_t field_E72[600]; // E72
    uint16_t field_10CA; // 10CA
    uint8_t field_10CC[1062]; // 10CC
    uint16_t field_14F2; // 14F2
    uint16_t field_14F4; // 14F4
    uint16_t field_14F6; // 14F6
    uint8_t field_14F8[30]; // 14F8
    uint16_t field_1516; // 1516
    uint8_t field_1518[30]; // 1518
    uint16_t field_1536; // 1536
    uint8_t field_1538[30]; // 1538
    uint16_t field_City_Walls;          // 1556 // 00=No City Walls, 01=City Walls
    uint16_t field_Wall_is_whole[16];   // 1558 // 00=No Wall, 01=Whole Wall, 02=Broken Wall
    uint16_t field_Wall_of_Fire;        // 1578
    uint16_t field_Wall_of_Darkness;    // 157A
    uint16_t field_157C_plane_GUESS;    // 157C
    uint16_t field_157E; // 157E
    uint16_t field_1580; // 1580
    uint16_t field_1582; // 1582
    uint8_t field_Cloud_of_Shadow_GUESS; // 1584
    uint8_t field_1585; // 1585
    uint8_t field_1586; // 1586
    uint8_t field_1587; // 1587
    uint8_t field_1588; // 1588
    uint8_t field_1589; // 1589
    uint8_t field_158A; // 158A
    uint8_t field_158B; // 158B
    uint8_t field_158C; // 158C
    uint8_t field_158D; // 158D
    uint8_t field_158E; // 158E
    uint8_t field_158F; // 158F
    uint8_t field_1590; // 1590
    uint8_t field_1591; // 1591
    uint8_t field_1592; // 1592
    uint8_t field_Heavenly_Light_GUESS; // 1593
                        // SIZE 1594
} Battlefield;

typedef struct PACKED_STRUCT // Battle_Unit
{
                                    // (sizeof=0x6E)
    // First part copied from Unit_Type_Data (starting at offset 2)

    uint8_t     m_Melee;            // 00  Melee attack strength
    uint8_t     m_Ranged;           // 01  Ranged attack strength
    eRanged_Type    m_Ranged_Type;   // 02  Ranged attack type (table 1)
    uint8_t     m_Ranged_Shots;      // 03  Ranged attack number of shots
    uint8_t     m_To_Hit;            // 04  Plus to hit
    uint8_t     m_Defense;          // 05  Defense
    uint8_t     m_Resistance;       // 06  Resistance
    uint8_t     m_MoveHalves;       // 07  Movement rate (in units of 1/2 MP)
    uint16_t    m_Cost;             // 08-09  Heroes: cost to hire (note 2)
                                    //     Normal units: cost to build
                                    //     Summoned units: cost to place in lair, node or rampaging force (note 3)
    uint8_t     m_Upkeep;           // 0A  Summoned units: upkeep cost  Others: not used (note 4)
    eRace       m_Race_Code;         // 0B  Race code (table 2)
    uint8_t     m_Buildings_Required1_UNK;    // 0C-0D  Normal units: buildings required (table 3)
                                        //     Others: note 5
    uint8_t     m_Current_Figures;      // 0D
    uint8_t     m_graphics_ID_GUESS;      // 0E
    uint8_t     m_UNK01;            // 0F  00
    uint8_t     m_Hitpoints_per_Figure;        // 10  Hit points (hearts) per figure
    uint8_t     m_Scout;    // 11  Scouting range
    uint8_t     m_Transport_Capacity_GUESS;    // 12  Transport capacity (number of units carried)
    uint8_t     m_Total_Figures;        // 13  Number of figures in the unit
    uint8_t     m_Construction; // 14  Construction capacity (road building)
    uint8_t     m_Gaze_Modifier;     // 15  Special attack or bonus strength
    unionMovement_Flags     m_Movement_Flags;   // 16  Movement flags (table 4)
    uint8_t                 m_Zero01;           // 17  00
    unionImmunity_Flags     m_Immunity_Flags;   // 18  Immunity flags (table 5)
    unionAttribute_Flags    m_Attribute_Flags;  // 19  Attribute flags (table 6)
                                                // 1A  Attribute flags (table 7)
    uint8_t                 m_Zero02;           // 1B  00
    unionAbility_Flags      m_Ability_Flags;    // 1C  Attribute flags (table 8)
                                                // 1D  Attribute flags (table 9)
    unionAttack_Flags       m_Attack_Flags;         // 1E  Special attack flags (table 10)
                                                // 1F  Special attack flags (table 11)

    uint16_t                m_Zero03;                // 20-21 dw ? ; unused
    Combat_Enchantment      m_Flags_Combat_Enchantment;   // 22-23 dw
    uint8_t                 m_Extra_ToHit_Melee;  // 24 db
    uint8_t                 m_Extra_ToHit_Ranged; // 25 db
    uint8_t                 m_Extra_ToDefend;         // 26 db
    uint8_t                 m_Weapon_Type_Plus_1;   // 27 db ?
    unionAttack_Flags       m_Cur_Attack_Flags;               // 28-29 db
    unionAttack_Flags       m_Item_Attack_Flags;                          // 2A-2B db
    unionUnit_Enchantment   m_Flags2_UnitEnchantment;                          // 2C-2F db
    int16_t                 m_unitNr            ;   // 30-31 db ?
    uint8_t                 m_UNK04;          // 32
    uint8_t                 m_web_              ;   // 33 db ?
    uint8_t                 m_active__;    // 34 db ? Active (0=alive, 4=dead, 6=crackscall) ??
    ePlayer                 m_Owner             ;   // 35 db ?
    uint8_t                 m_cur_total_damage_GUESS     ;    // 36 db ?
    uint8_t                 m_UNK05[2];       // 37
                                              // 38
    uint8_t                 m_cur_figure_damage_GUESS   ;    // 39 db ?
    unionUnit_Enchantment   m_Flags1_UnitEnchantment;       // 3A-3D db
    uint8_t                 m_Suppression    ;   // 3E db ?
    uint8_t                 m_Mana_points       ;   // 3F db ?
    uint8_t                 m_Current_mana_    ;   // 40 db ?
    uint8_t                 m_Item_nr_charges_ ;   // 41 db ?
    uint8_t                 m_Poison_strength_; // 42 db ?
    uint8_t                 m_UNK07a;           // 43
    uint16_t                m_xPos;           // 44-45 db
    uint16_t                m_yPos;           // 46-47 db
    uint16_t                m_xPosHeaded;     // 48-49 db
    uint16_t                m_yPosHeaded;     // 4A-4B db
    uint8_t                 m_UNK07b[8];      // 4C
                                              // 4D
                                              // 4E
                                              // 4F
                                              // 50
                                              // 51
                                              // 52
                                              // 53
    eUnit_Status            m_Status;         // 54 Status (0=ready, 4=reached destination)
    uint8_t                 m_UNK08;          // 55
    int8_t                  m_Confused_State; // 56 (0=stunned?, 1=move randomly?, 2=change allegiance, 3=?)
    uint8_t                 m_UNK09a[13];     // 57
                                              // 58
                                              // 59
                                              // 5A
                                              // 5B
                                              // 5C
                                              // 5D
                                              // 5E
                                              // 5F
                                              // 60
                                              // 61
                                              // 62
                                              // 63
    uint8_t                 m_Extra_Attack;   // 64 db
    uint8_t                 m_Extra_Ranged;   // 65 db
    uint8_t                 m_Extra_Defense;  // 66 db
    uint8_t                 m_Extra_Resistance;// 67 db
    uint8_t                 m_Extra_Hitpoints;// 68 db
    uint8_t                 m_UNK09b[5];      // 69
                                              // 6A
                                              // 6B
                                              // 6C dw ?
                                              // SIZE 6E
} Battle_Unit;

typedef struct PACKED_STRUCT // Unit_Data_Hero_Types
{
    //Unit_Type_Data m_Hero_Types[35];
    Unit_Type_Data      Dwarf;
    Unit_Type_Data      Barbarian;
    Unit_Type_Data      Sage;
    Unit_Type_Data      Dervish;
    Unit_Type_Data      Beastmaster;
    Unit_Type_Data      Bard;
    Unit_Type_Data      Orc_Warrior;
    Unit_Type_Data      Healer;
    Unit_Type_Data      Huntress;
    Unit_Type_Data      Thief;
    Unit_Type_Data      Druid;
    Unit_Type_Data      War_Monk;
    Unit_Type_Data      Warrior_Mage;
    Unit_Type_Data      Magician;
    Unit_Type_Data      Assassin;
    Unit_Type_Data      Wind_Mage;
    Unit_Type_Data      Ranger;
    Unit_Type_Data      Draconian;
    Unit_Type_Data      Witch;
    Unit_Type_Data      Golden_One;
    Unit_Type_Data      Ninja;
    Unit_Type_Data      Rogue;
    Unit_Type_Data      Amazon;
    Unit_Type_Data      Warlock;
    Unit_Type_Data      Unknown;
    Unit_Type_Data      Illusionist;
    Unit_Type_Data      Swordsman;
    Unit_Type_Data      Priestess;
    Unit_Type_Data      Paladin;
    Unit_Type_Data      Black_Knight;
    Unit_Type_Data      Elven_Archer;
    Unit_Type_Data      Knight;
    Unit_Type_Data      Necromancer;
    Unit_Type_Data      Chaos_Warrior;
    Unit_Type_Data      Chosen;
} Unit_Data_Hero_Types;

typedef struct PACKED_STRUCT // Race_Data
{
    uint16_t    m_PtrName;                          // 00-01  Pointer to name of race (note 1)
    uint16_t    m_Number_of_prohibited_buildings;   // 02-03  (0 to 7)
    eBuilding   m_Prohibited_buildings[7];          // 04-11  (table 3)
    uint16_t    m_Outpost_growth_probability;       // 12-13  (percent chance to grow in each turn)
    int16_t     m_City_population_growth_modifier;  // 14-15  (in units of 10 people per turn)
    uint16_t    m_Housing_picture;                  // 16-17  (0 wood frame house, 1 tree house, 2 mud hut)
                                                    // SIZE 18
} Race_Data;

typedef struct PACKED_STRUCT // WizardsExe_Game_Data
{                                           // ds:BD8E
    // Game status
    uint16_t        m_UnitNr_Active;        // 00
    uint16_t        m_Current_Turn;         // 02 year is 1400 + Turn/12, month is Turn%12
    uint16_t        m_Number_of_Units;      // 04 in Unit Instance Table (0 ... 1000, out of a maximum of 1000)
    uint16_t        m_Number_of_Cities;     // 06 in City Table (0 ... 100, of out of a maximum of 100)

    // Game choices
    eDifficulty     m_Difficulty;           // 08
    eMagic_Powerful m_Magic_Powerful_setting;   // 0A
    eLand_Size      m_Land_Size_setting;    // 0C
    uint16_t        m_Number_of_Wizards;    // 0E in Wizard Table (including YOU, 2 ... 5)
                                            // SIZE 10 ds:BD9E
} WizardsExe_Game_Data;

typedef struct PACKED_STRUCT // WizardsExe_Save_Name
{
    char        m_Name[20];
} WizardsExe_Save_Name;

typedef struct PACKED_STRUCT // Game_Settings
{
                                                // ds:BD9E  Maps 1-1 on the MAGIC.SET file (466 bytes)
    eYesNo16    m_Sound_Effects;                        // 00
    eYesNo16    m_Background_Music;
    eYesNo16    m_Event_Music;
    eYesNo16    m_City_Spell_Events;
    eYesNo16    m_Overland_Spell_Events;
    eYesNo16    m_Summoning_Events;
    eYesNo16    m_End_of_Turn_Summary;
    eYesNo16    m_Raze_City;
    eYesNo16    m_Random_Events;                        // 10
    eYesNo16    m_End_of_Turn_Wait;
    eYesNo16    m_Stratic_Combat_Only;
    eYesNo16    m_Auto_Unit_Information;
    eYesNo16    m_Enemy_Moves;
    eYesNo16    m_Enemy_Spells;
    eYesNo16    m_Spell_Book_Ordering;
    eYesNo16    m_Spell_Animations;
    eYesNo16    m_Show_Node_Owners;                     // 20
    eYesNo16    m_Expanding_Help;
    uint16_t    m_UNK01;                                // 24
    uint16_t    m_UNK02;                                // 26
    eDifficulty m_Difficulty;                           // 28
    uint16_t    m_Nr_Opponents;                         // 2A
    eLand_Size  m_Land_Size;                            // 2C
    eMagic_Powerful m_Magic_Powerful;                   // 2E
    eYesNo16    m_Slots_Saved[8];                       // 30
    WizardsExe_Save_Name   m_Save_Names[8];             // 40   // 8 slots with each 18 letters and 2 ending zeroes
    eYesNo16    m_Movement_Animations;                  // E0
    WizardsExe_Save_Name   m_Save_Wizard_Names[10];     // E2   // 10 (?) slots of each 20 bytes (incl. ending zero)
    uint16_t    m_UNK03[20];                            // 1AA
                                                // SIZE 1D2h = 466d
} Game_Settings;

typedef struct // WizardsExe_Pointers
{
    // Offset(dec)  Beschrijving    DS:Ofset(hex)
    EXE_Reloc   addr_Spell_Data ; // 912C
    uint16_t    word_3FBD0  ; // 9130
    uint16_t    w_sound_x   ; // 9132
    uint16_t    word_3FBD4  ; // 9134
    EXE_Reloc   addr_Items  ; // 9136
    EXE_Reloc   addr_item_in_game_GUESS   ; // 913A
    uint8_t unk__913E[26]   ; // 913E
    uint8_t unk_3FBF8[23]   ; // 9158
    uint8_t unk_3FC0F[183]  ; // 916F
    EXE_Reloc   addr_Battle_Unit_View  ; // 9226
    EXE_Reloc   addr_Battle_Unit  ; // 922A
    EXE_Reloc   addr_Spells_Cast_in_Battle   ; // 922E
    EXE_Reloc   addr_Hero_stat[6]   ; // 9232
    uint8_t w_AI_flees[20]  ; // 924A
    uint8_t word_3FCFE[10]  ; // 925E
    uint16_t    word_3FD08  ; // 9268
    uint16_t    word_3FD0A  ; // 926A
    uint16_t    word_3FD0C  ; // 926C
    uint16_t    word_3FD0E  ; // 926E
    uint16_t    word_3FD10  ; // 9270
    uint16_t    word_3FD12  ; // 9272
    EXE_Reloc   addr_Battlefield    ; // 9274
    uint16_t    word_3FD18  ; // 9278
    uint16_t    word_3FD1A  ; // 927A
    uint16_t    w_AI_on_the_move_GUESS  ; // 927C
    uint16_t    w_coo_X_Y_clicked   ; // 927E
    uint16_t    w_coo_Y_X_clicked   ; // 9280
    uint16_t    word_3FD22  ; // 9282
    uint16_t    w_clash_place_type  ; // 9284
    uint8_t w_clash_place_ID[14]    ; // 9286
    int16_t    w_kyrub_dseg_9294  ; // 9294
    int16_t    w_kyrub_dseg_9296  ; // 9296
    uint8_t word_3FD38[20]  ; // 9298
    uint16_t    w_negat_encha_x17_flag_def  ; // 92AC
    uint16_t    w_aggre_spell_color_flag_att    ; // 92AE
    EXE_Reloc   dword_3FD50 ; // 92B0
    uint16_t    word_3FD54  ; // 92B4
    uint8_t word_3FD56[64]  ; // 92B6
    uint8_t word_3FD96[8]   ; // 92F6
    uint16_t    word_3FD9E  ; // 92FE
    uint16_t    word_3FDA0  ; // 9300
    uint16_t    word_3FDA2  ; // 9302
    uint16_t    word_3FDA4  ; // 9304
    uint16_t    word_3FDA6  ; // 9306
    uint16_t    word_3FDA8  ; // 9308
    uint16_t    word_3FDAA  ; // 930A
    uint16_t    word_3FDAC  ; // 930C
    uint16_t    word_3FDAE  ; // 930E
    uint16_t    word_3FDB0  ; // 9310
    uint16_t    word_3FDB2  ; // 9312
    uint16_t    word_3FDB4  ; // 9314
    uint16_t    word_3FDB6  ; // 9316
    uint8_t     word_3FDB8[44]  ; // 9318
    uint16_t    word_3FDE4  ; // 9344
    EXE_Reloc   addr_3FDE6  ; // 9346
    uint16_t    word_3FDEA  ; // 934A
    uint16_t    word_3FDEC  ; // 934C
    uint16_t    word_3FDEE  ; // 934E
    uint16_t    word_3FDF0  ; // 9350
    uint16_t    word_3FDF2  ; // 9352
    uint16_t    word_3FDF4  ; // 9354
    uint16_t    word_3FDF6  ; // 9356
    uint16_t    word_3FDF8  ; // 9358
    uint16_t    word_3FDFA  ; // 935A
    uint16_t    word_3FDFC  ; // 935C
    uint16_t    word_3FDFE  ; // 935E
    uint16_t    word_3FE00  ; // 9360
    uint16_t    word_3FE02  ; // 9362
    uint16_t    word_3FE04  ; // 9364
    uint16_t    word_3FE06  ; // 9366
    uint16_t    word_3FE08  ; // 9368
    uint16_t    word_3FE0A  ; // 936A
    uint16_t    word_3FE0C  ; // 936C
    uint16_t    word_3FE0E  ; // 936E
    uint16_t    word_3FE10  ; // 9370
    uint16_t    word_3FE12  ; // 9372
    uint16_t    word_3FE14  ; // 9374
    uint16_t    word_3FE16  ; // 9376
    uint16_t    word_3FE18  ; // 9378
    uint16_t    word_3FE1A  ; // 937A
    uint16_t    word_3FE1C  ; // 937C
    uint16_t    word_3FE1E  ; // 937E
    uint16_t    word_3FE20  ; // 9380
    uint16_t    word_3FE22  ; // 9382
    uint16_t    word_3FE24  ; // 9384
    uint16_t    word_3FE26  ; // 9386
    uint16_t    word_3FE28  ; // 9388
    uint16_t    word_3FE2A  ; // 938A
    EXE_Reloc   addr_Building_Data ; // 938C
    uint16_t    word_3FE30  ; // 9390
    EXE_Reloc   dword_3FE32 ; // 9392
    uint8_t dword_3FE36[126]    ; // 9396
    uint8_t word_3FEB4[6]   ; // 9414
    uint8_t word_3FEBA[18]  ; // 941A
    uint8_t word_3FECC[22]  ; // 942C
    uint16_t    word_3FEE2  ; // 9442
    uint16_t    w_all_units_moved_GUESS ; // 9444
    uint16_t    word_3FEE6  ; // 9446
    uint16_t    word_3FEE8  ; // 9448
    uint16_t    word_3FEEA  ; // 944A
    uint8_t word_3FEEC[6]   ; // 944C
    uint8_t word_3FEF2[14]  ; // 9452
    EXE_Reloc   word_3FF00  ; // 9460
    uint16_t    word_3FF04  ; // 9464
    uint16_t    word_3FF06  ; // 9466
    uint16_t    word_3FF08  ; // 9468
    uint16_t    word_3FF0A  ; // 946A
    uint16_t    word_3FF0C  ; // 946C
    uint16_t    word_3FF0E  ; // 946E
    uint8_t word_3FF10[14]  ; // 9470
    uint16_t    word_3FF1E  ; // 947E
    uint16_t    word_3FF20  ; // 9480
    uint16_t    word_3FF22  ; // 9482
    uint16_t    word_3FF24  ; // 9484
    uint16_t    word_3FF26  ; // 9486
    uint16_t    word_3FF28  ; // 9488
    uint16_t    word_3FF2A  ; // 948A
    uint16_t    word_3FF2C  ; // 948C
    uint8_t word_3FF2E[6]   ; // 948E
    uint16_t    word_3FF34  ; // 9494
    uint16_t    word_3FF36  ; // 9496
    uint16_t    word_3FF38  ; // 9498
    uint16_t    word_3FF3A  ; // 949A
    uint16_t    word_3FF3C  ; // 949C
    uint16_t    word_3FF3E  ; // 949E
    uint16_t    word_3FF40  ; // 94A0
    uint16_t    word_3FF42  ; // 94A2
    uint16_t    word_3FF44  ; // 94A4
    uint16_t    word_3FF46  ; // 94A6
    uint16_t    word_3FF48  ; // 94A8
    uint16_t    word_3FF4A  ; // 94AA
    uint8_t word_3FF4C[58]  ; // 94AC
    uint16_t    word_3FF86  ; // 94E6
    uint16_t    word_3FF88  ; // 94E8
    uint16_t    word_3FF8A  ; // 94EA
    uint16_t    word_3FF8C  ; // 94EC
    uint16_t    word_3FF8E  ; // 94EE
    uint8_t word_3FF90[30]  ; // 94F0
    uint16_t    word_3FFAE  ; // 950E
    uint16_t    word_3FFB0  ; // 9510
    uint16_t    word_3FFB2  ; // 9512
    uint16_t    word_3FFB4  ; // 9514
    uint16_t    word_3FFB6  ; // 9516
    uint16_t    word_3FFB8  ; // 9518
    uint16_t    word_3FFBA  ; // 951A
    uint16_t    word_3FFBC  ; // 951C
    EXE_Reloc   word_3FFBE  ; // 951E
    uint16_t    word_3FFC2  ; // 9522
    uint16_t    word_3FFC4  ; // 9524
    uint16_t    word_3FFC6  ; // 9526
    EXE_Reloc   word_3FFC8  ; // 9528
    uint16_t    word_3FFCC  ; // 952C
    uint8_t word_3FFCE[14]  ; // 952E
    uint16_t    word_3FFDC  ; // 953C
    uint16_t    word_3FFDE  ; // 953E
    uint8_t word_3FFE0[8]   ; // 9540
    uint8_t word_3FFE8[38]  ; // 9548
    uint16_t    word_4000E  ; // 956E
    uint16_t    word_40010  ; // 9570
    uint16_t    word_40012  ; // 9572
    uint16_t    word_40014  ; // 9574
    uint16_t    word_40016  ; // 9576
    uint16_t    word_40018  ; // 9578
    uint16_t    word_4001A  ; // 957A
    uint16_t    word_4001C  ; // 957C
    uint16_t    word_4001E  ; // 957E
    uint16_t    word_40020  ; // 9580
    uint16_t    word_40022  ; // 9582
    uint16_t    word_40024  ; // 9584
    uint16_t    word_40026  ; // 9586
    uint16_t    word_40028  ; // 9588
    uint16_t    word_4002A  ; // 958A
    uint16_t    word_4002C  ; // 958C
    uint8_t word_4002E[28]  ; // 958E
    uint16_t    word_4004A  ; // 95AA
    uint16_t    word_4004C  ; // 95AC
    uint16_t    word_4004E  ; // 95AE
    uint16_t    word_40050  ; // 95B0
    uint16_t    word_40052  ; // 95B2
    uint16_t    word_40054  ; // 95B4
    uint16_t    word_40056  ; // 95B6
    uint16_t    word_40058  ; // 95B8
    uint16_t    word_4005A  ; // 95BA
    uint16_t    word_4005C  ; // 95BC
    uint16_t    word_4005E  ; // 95BE
    uint16_t    word_40060  ; // 95C0
    uint8_t word_40062[12]  ; // 95C2
    uint8_t word_4006E[34]  ; // 95CE
    uint16_t    word_40090  ; // 95F0
    uint8_t word_40092[82]  ; // 95F2
    EXE_Reloc   addr_city_detailed_GUESS   ; // 9644
    uint8_t word_400E8[244] ; // 9648
    uint16_t    word_401DC  ; // 973C
    uint16_t    word_401DE  ; // 973E
    uint16_t    word_401E0  ; // 9740
    uint16_t    word_401E2  ; // 9742
    uint16_t    word_401E4  ; // 9744
    uint16_t    word_401E6  ; // 9746
    uint16_t    word_401E8  ; // 9748
    uint16_t    word_401EA  ; // 974A
    uint16_t    word_401EC  ; // 974C
    uint16_t    word_401EE  ; // 974E
    uint16_t    word_401F0  ; // 9750
    uint16_t    word_401F2  ; // 9752
    uint16_t    word_401F4  ; // 9754
    uint16_t    word_401F6  ; // 9756
    uint16_t    word_401F8  ; // 9758
    uint16_t    word_401FA  ; // 975A
    uint16_t    word_401FC  ; // 975C
    uint16_t    word_401FE  ; // 975E
    uint16_t    word_40200  ; // 9760
    uint16_t    word_40202  ; // 9762
    uint16_t    word_40204  ; // 9764
    uint16_t    word_40206  ; // 9766
    uint16_t    word_40208  ; // 9768
    uint16_t    word_4020A  ; // 976A
    uint8_t word_4020C[38]  ; // 976C
    uint16_t    word_40232  ; // 9792
    uint16_t    word_40234  ; // 9794
    uint16_t    word_40236  ; // 9796
    uint16_t    word_40238  ; // 9798
    uint16_t    word_4023A  ; // 979A
    uint16_t    word_4023C  ; // 979C
    uint16_t    word_4023E  ; // 979E
    uint16_t    word_40240  ; // 97A0
    uint8_t word_40242[18]  ; // 97A2
    uint16_t    word_40254  ; // 97B4
    uint16_t    word_40256  ; // 97B6
    uint16_t    word_40258  ; // 97B8
    uint8_t word_4025A[50]  ; // 97BA
    uint16_t    word_4028C  ; // 97EC
    uint8_t word_4028E[10]  ; // 97EE
    uint16_t    word_40298  ; // 97F8
    uint16_t    word_4029A  ; // 97FA
    uint16_t    word_4029C  ; // 97FC
    uint8_t word_4029E[34]  ; // 97FE
    uint8_t word_402C0[32]  ; // 9820
    uint16_t    word_402E0  ; // 9840
    uint8_t word_402E2[36]  ; // 9842
    uint8_t word_40306[120] ; // 9866
    uint8_t word_4037E[10]  ; // 98DE
    uint8_t word_40388[10]  ; // 98E8
    uint16_t    word_40392  ; // 98F2
    uint8_t word_40394[20]  ; // 98F4
    uint8_t word_403A8[6]   ; // 9908
    uint8_t word_403AE[10]  ; // 990E
    uint16_t    word_403B8  ; // 9918
    uint16_t    word_403BA  ; // 991A
    uint16_t    word_403BC  ; // 991C
    uint16_t    word_403BE  ; // 991E
    uint16_t    word_403C0  ; // 9920
    uint8_t word_403C2[20]  ; // 9922
    uint16_t    word_403D6  ; // 9936
    uint16_t    word_403D8  ; // 9938
    uint16_t    word_403DA  ; // 993A
    uint16_t    word_403DC  ; // 993C
    uint16_t    word_403DE  ; // 993E
    uint16_t    word_403E0  ; // 9940
    uint16_t    word_403E2  ; // 9942
    uint16_t    word_403E4  ; // 9944
    uint16_t    word_403E6  ; // 9946
    uint16_t    word_403E8  ; // 9948
    uint16_t    word_403EA  ; // 994A
    uint16_t    word_403EC  ; // 994C
    uint16_t    word_403EE  ; // 994E
    uint16_t    word_403F0  ; // 9950
    uint16_t    word_403F2  ; // 9952
    uint16_t    word_403F4  ; // 9954
    uint16_t    word_403F6  ; // 9956
    uint16_t    word_403F8  ; // 9958
    uint16_t    word_403FA  ; // 995A
    uint16_t    word_403FC  ; // 995C
    EXE_Reloc   word_403FE  ; // 995E
    uint16_t    word_40402  ; // 9962
    uint16_t    word_40404  ; // 9964
    uint16_t    word_40406  ; // 9966
    uint16_t    word_40408  ; // 9968
    uint16_t    word_4040A  ; // 996A
    uint16_t    word_4040C  ; // 996C
    uint16_t    word_4040E  ; // 996E
    uint16_t    word_40410  ; // 9970
    uint16_t    word_40412  ; // 9972
    uint16_t    word_40414  ; // 9974
    uint16_t    word_40416  ; // 9976
    uint16_t    word_40418  ; // 9978
    uint16_t    word_4041A  ; // 997A
    uint16_t    word_4041C  ; // 997C
    uint16_t    word_4041E  ; // 997E
    uint16_t    word_40420  ; // 9980
    uint16_t    word_40422  ; // 9982
    uint16_t    word_40424  ; // 9984
    uint16_t    word_40426  ; // 9986
    EXE_Reloc   word_40428  ; // 9988
    uint16_t    word_4042C  ; // 998C
    uint16_t    w_constant_GUESS    ; // 998E
    eGameState  w_Game_flow ; // 9990
    uint16_t    word_40432  ; // 9992
    uint16_t    word_40434  ; // 9994
    uint16_t    word_40436  ; // 9996
    EXE_Reloc   addr_events ; // 9998
    uint16_t    w_uts_in_stack_ovrland_GUESS    ; // 999C
    uint8_t w_Stack_active_GUESS[36]    ; // 999E
    uint8_t byte_40462[281] ; // 99C2
    uint8_t byte_4057B[21]  ; // 9ADB
    uint8_t b_mess_number[82]   ; // 9AF0
    uint8_t byte_405E2[82]  ; // 9B42
    uint8_t byte_40634[82]  ; // 9B94
    uint8_t byte_40686[82]  ; // 9BE6
    uint8_t byte_406D8[21]  ; // 9C38
    uint8_t byte_406ED[21]  ; // 9C4D
    uint8_t byte_40702[21]  ; // 9C62
    uint8_t byte_40717[21]  ; // 9C77
    uint16_t    byte_4072C  ; // 9C8C
    uint16_t    w_video_style_CL_BUG_GUESS  ; // 9C8E
    EXE_Reloc   dword_40730 ; // 9C90
    uint16_t    word_40734  ; // 9C94
    uint16_t    word_40736  ; // 9C96
    uint16_t    word_40738  ; // 9C98
    uint16_t    word_4073A  ; // 9C9A
    EXE_Reloc   dword_4073C ; // 9C9C
    EXE_Reloc   dword_40740 ; // 9CA0
    EXE_Reloc   addr_terrain_cost_GUESS   ; // 9CA4
    EXE_Reloc   dword_40748 ; // 9CA8
    EXE_Reloc   dword_4074C ; // 9CAC
    EXE_Reloc   addr_terrain_scouted_loc    ; // 9CB0
    EXE_Reloc   addr_changed_terrain_loc  ; // 9CB4
    EXE_Reloc   addr_special_terrain_loc_    ; // 9CB8
    EXE_Reloc   addr_Cities ; // 9CBC
    EXE_Reloc   addr_Lairs_data   ; // 9CC0
    EXE_Reloc   addr_tower_attr ; // 9CC4
    EXE_Reloc   addr_fortress_data    ; // 9CC8
    EXE_Reloc   addr_Nodes_Attr    ; // 9CCC
    EXE_Reloc   addr_Continent_  ; // 9CD0
    uint16_t    word_40774  ; // 9CD4
    uint16_t    word_40776  ; // 9CD6
    uint16_t    word_40778  ; // 9CD8
    uint16_t    word_4077A  ; // 9CDA
    EXE_Reloc   addr_TerrainTypes ; // 9CDC
    EXE_Reloc   addr_Unrest_Table[gMAX_RACES]  ; // 9CE0
    uint16_t    word_407B8  ; // 9D18
    uint16_t    word_407BA  ; // 9D1A
    uint16_t    word_407BC  ; // 9D1C
    uint16_t    word_407BE  ; // 9D1E
    uint16_t    word_407C0  ; // 9D20
    uint8_t w_Vizier_allowed_GUESS[8]   ; // 9D22
    EXE_Reloc   dword_407CA ; // 9D2A
    EXE_Reloc   dword_407CE ; // 9D2E
    uint16_t    word_407D2  ; // 9D32
    uint16_t    word_407D4  ; // 9D34
    uint16_t    word_407D6  ; // 9D36
    uint16_t    word_407D8  ; // 9D38
    uint16_t    word_407DA  ; // 9D3A
    uint16_t    word_407DC  ; // 9D3C
    uint16_t    word_407DE  ; // 9D3E
    uint16_t    word_407E0  ; // 9D40
    uint16_t    word_407E2  ; // 9D42
    uint16_t    word_407E4  ; // 9D44
    uint16_t    word_407E6  ; // 9D46
    uint16_t    word_407E8  ; // 9D48
    uint16_t    w_AI_stack_nr   ; // 9D4A
    uint8_t unk_407EC[320]  ; // 9D4C
    EXE_Reloc   dw_Nr_in_stack  ; // 9E8C
    EXE_Reloc   dw_stack_place  ; // 9E90
    EXE_Reloc   dw_pla_stacks_loc   ; // 9E94
    EXE_Reloc   dw_Y_stacks_loc ; // 9E98
    EXE_Reloc   dw_X_stacks_loc ; // 9E9C
    EXE_Reloc   dw_bx_6160  ; // 9EA0
    EXE_Reloc   dw_bx_615C  ; // 9EA4
    EXE_Reloc   dw_bx_6176  ; // 9EA8
    EXE_Reloc   dw_bx_6154  ; // 9EAC
    uint16_t    word_40950  ; // 9EB0
    uint16_t    word_40952  ; // 9EB2
    uint16_t    word_40954  ; // 9EB4
    uint16_t    word_40956  ; // 9EB6
    uint16_t    word_40958  ; // 9EB8
    uint16_t    word_4095A  ; // 9EBA
    uint16_t    word_4095C  ; // 9EBC
    uint16_t    word_4095E  ; // 9EBE
    uint16_t    word_40960  ; // 9EC0
    EXE_Reloc   addr_Units    ; // 9EC2
    EXE_Reloc   dword_40966 ; // 9EC6
            ; // 9ECA
} WizardsExe_Pointers;

typedef struct PACKED_STRUCT {   // Available_spell_page
    char        m_Page_Name[0x10];          // 00
    eSpell16    m_Spells_on_page[6];        // 10
    uint8_t     m_Nr_spells_on_page;        // 1C
    uint8_t     m_Zero;                     // 1D
                                            // SIZE 1E
} Available_spell_page;

typedef struct // MoMDataSegment
{
    char        m_DataSegmentStart[0x19C];          // ds:0 / EXE:294A0
    // "\0\0\0\0Borland C++ - Copyright 1991 Borland Intl.";

    Unit_Data_Hero_Types  m_Hero_Types;             // ds:019C / EXE:2963C

    Unit_Type_Data   m_Normal_Units[4 + 115];

    Unit_Type_Data   m_Summoned_Units[44];

    uint16_t    m_XP_Level_Table[9];                // ds:1D74 / EXE:2B214

    Race_Data   m_Race_Data[14];                    // ds:1D86 / EXE:2B226

    uint8_t     m_UNK03[0x42];                      // ds:1ED6 / EXE:2B376

    Upkeep_Enchantments m_Upkeep_Enchantments;      // ds:1F18 / EXE:2B3B8

    uint8_t     m_UNK05[46];                        // ds:1FBC / EXE:2B45C

    // 5 x 8 entries for each difficulty level
    Difficulty_Table m_DifficultyTable[eDifficulty_MAX];    // ds:1FEA / EXE:2B48A

    uint8_t     m_UNK06a[72];                       // ds:203A / EXE:2B4DA

    char        m_NameBuffer1a[0x5E92 - 0x2082];    // ds:2082 / EXE:2B522

    // Note: this can not be uint32_t because g++ will align it on a 32-bit boundary
    uint16_t    m_Next_Turn_seed_storage_lo;        // ds:5E92
    uint16_t    m_Next_Turn_seed_storage_hi;        // ds:5E94

    uint8_t     m_UNK_5E96[0x6E9E - 0x5E96];        // ds:5E96

    uint16_t    m_Tax_Unrest_Table[eTax_Rate_MAX];  // ds:6E9E

    uint8_t     m_UNK_6EAC[0x7173 - 0x6EAC];        // ds:6EAC

    char        m_MoM_Version[7];                   // ds:7173

    uint8_t     m_UNK_717A[0x71E0 - 0x717A];        // ds:717A

    uint32_t    m_BIOS_clock_snapshot;              // ds:71E0

    uint8_t     m_UNK_71E4[0x7846 - 0x71E4];        // ds:71E4

    // Note: this can not be uint32_t because g++ will align it on a 32-bit boundary
    uint16_t    m_RNG_seed_lo;                      // ds:7846
    uint16_t    m_RNG_seed_hi;                      // ds:7848

    uint8_t     m_UNK06c[0x7876 - 0x784A];          // ds:784A

    uint16_t    m_DEBUG_Off;                        // ds:7876

    uint8_t     m_UNK06d[0x912C - 0x7878];          // ds:7878

    WizardsExe_Pointers m_WizardsExe_Pointers;      // ds:912C

    Wizard      m_Wizards[gMAX_WIZARD_RECORDS];     // ds:9ECA / EXE:3336A

    uint8_t     m_UNK07[0xBD8E - 0xBB7A];           // ds:BB7A

    WizardsExe_Game_Data    m_Game_Data;            // ds:BD8E / EXE:3522E

    Game_Settings    m_Game_Settings;               // ds:BD9E / EXE:2523E

    uint8_t     m_UNK08a[0xC588 - 0xBF70];          // ds:BF70

    uint16_t    m_Nr_Battle_Units;                  // ds:C588

    uint8_t     m_UNK08b[0xC8FA - 0xC58A];          // ds:C58A

    uint16_t    m_offset_Available_spell_pages;     // ds:C8FA

    uint8_t     m_UNK08c[0xC910 - 0xC8FC];          // ds:C8FC

    EXE_Reloc   m_addr_Hero_Spells;                 // ds:C910
    uint16_t    m_Nr_available_spell_pages;         // ds:C914

    uint8_t     m_UNK08d[0xC924 - 0xC916];          // ds:C916

    uint16_t    m_First_visible_available_spell_page;   // ds:C924

    uint8_t     m_UNK083[0xEA54 - 0xC926];          // ds:C926

    // Offset ds:EA54  END DATA SEGMENT (DS)

    uint8_t     m_PARALIGN09[0x0C];                 // ds:EA54 / EXE:37EF4

    // STACK SEGMENT (SS)
    uint16_t    m_StackSegment[0x40];               // CS:35500 / EXE:37F00

} MoMDataSegment;

typedef struct PACKED_STRUCT // MoMMagicDataSegment
{
    char            m_DataSegmentStart[47];          // ds:0 / cs:21D10 / EXE:24510
    // "\0\0\0\0Borland C++ - Copyright 1991 Borland Intl.";

    uint8_t         m_UNK_2F[0x2AD0 - 47];           // ds:2F

    Wizard_Type_Data    m_Wizard_Types[ePortrait_MAX];  // ds:2AD0

    uint8_t         m_UNK_2C1A[0x35D0 - 0x2C1A];           // ds:2C1A

    Hero_Stats_Initializer  m_Hero_Stats_Initializers[gMAX_HERO_TYPES];  // ds:35D0

    uint8_t         m_UNK_3846[0x6900 - 0x3846];           // ds:3846

    Wizard          m_Wizards[6];                   // ds:6900

    eSpell16        m_Spells_selected_of_Realm[150]; // ds:85B0

    uint8_t         m_UNK_86DC[0x87C4 - 0x86DC];       // ds:86DC

    WizardsExe_Game_Data    m_Game_Data;        // ds:87C4

    Game_Settings   m_Game_Settings;                // ds:87D4

    uint8_t         m_UNK_89A6[0x8A14 - 0x89A6];       // ds:89A6

    eSpell          m_Spell_Selected[eSpell_MAX];   // ds:8A14

    uint8_t         m_UNK_8AEB[0x8D52 - 0x8AEB];       // ds:8AEB

    uint16_t        m_Spells_Known_Realm[66];    // ds:8D52
    uint16_t        m_UNK_8DD6;                        // ds:8DD6
    uint16_t        m_Sorcery_Picks_Divider;        // ds:8DD8
    uint16_t        m_Nature_Picks_Divider;         // ds:8DDA
    uint16_t        m_Chaos_Picks_Divider;          // ds:8DDC
    uint16_t        m_Death_Picks_Divider;          // ds:8DDE
    uint16_t        m_Life_Picks_Divider;           // ds:8DE0

    uint16_t        m_UNK_8DE2[2];                     // ds:8DE2

    uint16_t        m_Spells_Known_Realm_Indexed[15];    // ds:8DE6

    uint8_t         m_UNK_8E04[0x8E48 - 0x8E04];       // ds:8E04

    ePortrait       m_Select_Wizard_Shown;          // ds:8E48

    uint8_t         m_UNK_8E49[0x8E94 - 0x8E49];       // ds:8E49

    uint16_t        m_Total_Picks_Left;             // ds:8E94

    uint8_t         m_UNK_8E96[0xAA4A - 0x8E96];       // ds:8E96

                                                    // ds:AA4A  END DATA SEGMENT (DS)

    //    uint8_t     m_PARALIGN09[0x0C];                 // Offset EXE:37EF4 / ds:EA54

    uint8_t         m_UNK_AA4A[0xFE68 - 0xAA4A];       // ds:AA4A

    char            m_Wizards_Name_Shown_1[11];     // ds:FE68

    uint8_t         m_UNK_FE73[0xFEC2 - 0xFE73];       // ds:FE73

    char            m_Wizards_Name_Shown_2[11];     // ds:FEC2
} MoMMagicDataSegment;


typedef struct PACKED_STRUCT {
    uint8_t     m_Code[4];
    Item        m_Item;
    uint8_t     m_UNK01[2];
} ItemLBX;

}

#undef ENUMSIZE8
#undef ENUMSIZE16

#ifdef _MSC_VER     // Compiler MS Visual Studio
#pragma pack(pop)
#endif
#undef PACKED_STRUCT

#endif // MOMTEMPLATE_H
