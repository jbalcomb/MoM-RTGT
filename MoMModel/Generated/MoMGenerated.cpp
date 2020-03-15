// File: MoMModel/Generated/MoMGenerated.cpp
// Generated from: MoMTemplate.h

#include <ctype.h>
#include <iomanip>
#include <sstream>

#include "MoMGenerated.h"

#ifdef _MSC_VER                // Compiler MS Visual Studio
#pragma warning(disable: 4100) // MSVC: unreferenced formal parameter
#endif

namespace MoM {

std::ostream& operator<<(std::ostream& os, const eBannerColor& rhs)
{
    switch (rhs)
    {
    case BANNER_Blue: os << "BANNER_Blue"; break;
    case BANNER_Green: os << "BANNER_Green"; break;
    case BANNER_Purple: os << "BANNER_Purple"; break;
    case BANNER_Red: os << "BANNER_Red"; break;
    case BANNER_Yellow: os << "BANNER_Yellow"; break;
    case BANNER_Brown: os << "BANNER_Brown"; break;
    case eBannerColor_MAX: os << "eBannerColor_MAX"; break;
    default: os << "<Unknown eBannerColor>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eBattleCondition& rhs)
{
    switch (rhs)
    {
    case BATTLECONDITION_other: os << "BATTLECONDITION_other"; break;
    case BATTLECONDITION_strategic_city_combat: os << "BATTLECONDITION_strategic_city_combat"; break;
    case BATTLECONDITION_sorcery_node: os << "BATTLECONDITION_sorcery_node"; break;
    case BATTLECONDITION_nature_node: os << "BATTLECONDITION_nature_node"; break;
    case BATTLECONDITION_chaos_node: os << "BATTLECONDITION_chaos_node"; break;
    case BATTLECONDITION_sea: os << "BATTLECONDITION_sea"; break;
    case eBattleCondition_MAX: os << "eBattleCondition_MAX"; break;
    default: os << "<Unknown eBattleCondition>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eBattleEnchantment& rhs)
{
    switch (rhs)
    {
    case BATTLEENCHANTMENT_True_Light: os << "BATTLEENCHANTMENT_True_Light"; break;
    case BATTLEENCHANTMENT_Darkness: os << "BATTLEENCHANTMENT_Darkness"; break;
    case BATTLEENCHANTMENT_Warp_Reality: os << "BATTLEENCHANTMENT_Warp_Reality"; break;
    case BATTLEENCHANTMENT_Black_Prayer: os << "BATTLEENCHANTMENT_Black_Prayer"; break;
    case BATTLEENCHANTMENT_Wrack: os << "BATTLEENCHANTMENT_Wrack"; break;
    case BATTLEENCHANTMENT_Metal_Fires: os << "BATTLEENCHANTMENT_Metal_Fires"; break;
    case BATTLEENCHANTMENT_Prayer: os << "BATTLEENCHANTMENT_Prayer"; break;
    case BATTLEENCHANTMENT_High_Prayer: os << "BATTLEENCHANTMENT_High_Prayer"; break;
    case BATTLEENCHANTMENT_Terror: os << "BATTLEENCHANTMENT_Terror"; break;
    case BATTLEENCHANTMENT_Call_Lightning: os << "BATTLEENCHANTMENT_Call_Lightning"; break;
    case BATTLEENCHANTMENT_Counter_Magic: os << "BATTLEENCHANTMENT_Counter_Magic"; break;
    case BATTLEENCHANTMENT_Mass_Invisibility: os << "BATTLEENCHANTMENT_Mass_Invisibility"; break;
    case BATTLEENCHANTMENT_Entangle: os << "BATTLEENCHANTMENT_Entangle"; break;
    case BATTLEENCHANTMENT_Mana_Leak: os << "BATTLEENCHANTMENT_Mana_Leak"; break;
    case BATTLEENCHANTMENT_Blur: os << "BATTLEENCHANTMENT_Blur"; break;
    case eBattleEnchantment_MAX: os << "eBattleEnchantment_MAX"; break;
    default: os << "<Unknown eBattleEnchantment>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eBattleUnitActive& rhs)
{
    switch (rhs)
    {
    case BATTLEUNITACTIVE_alive: os << "BATTLEUNITACTIVE_alive"; break;
    case BATTLEUNITACTIVE_recalled: os << "BATTLEUNITACTIVE_recalled"; break;
    case BATTLEUNITACTIVE_fleeing: os << "BATTLEUNITACTIVE_fleeing"; break;
    case BATTLEUNITACTIVE_not_involved: os << "BATTLEUNITACTIVE_not_involved"; break;
    case BATTLEUNITACTIVE_dead: os << "BATTLEUNITACTIVE_dead"; break;
    case BATTLEUNITACTIVE_undeaded: os << "BATTLEUNITACTIVE_undeaded"; break;
    case BATTLEUNITACTIVE_removed: os << "BATTLEUNITACTIVE_removed"; break;
    case eBattleUnitActive_MAX: os << "eBattleUnitActive_MAX"; break;
    default: os << "<Unknown eBattleUnitActive>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eBattleUnitTactic& rhs)
{
    switch (rhs)
    {
    case TACTIC_ready: os << "TACTIC_ready"; break;
    case TACTIC_done: os << "TACTIC_done"; break;
    case TACTIC_wait: os << "TACTIC_wait"; break;
    case TACTIC_melee: os << "TACTIC_melee"; break;
    case TACTIC_shoot: os << "TACTIC_shoot"; break;
    case TACTIC_unclear_102: os << "TACTIC_unclear_102"; break;
    case TACTIC_unclear_103: os << "TACTIC_unclear_103"; break;
    case TACTIC_doom_bolt: os << "TACTIC_doom_bolt"; break;
    case TACTIC_fireball: os << "TACTIC_fireball"; break;
    case TACTIC_healing: os << "TACTIC_healing"; break;
    case TACTIC_cast_item_spell: os << "TACTIC_cast_item_spell"; break;
    case TACTIC_cast_spell: os << "TACTIC_cast_spell"; break;
    case TACTIC_summon_demon: os << "TACTIC_summon_demon"; break;
    case TACTIC_web: os << "TACTIC_web"; break;
    case TACTIC_flee_150: os << "TACTIC_flee_150"; break;
    case TACTIC_unset_333: os << "TACTIC_unset_333"; break;
    case eBattleUnitTactic_MAX: os << "eBattleUnitTactic_MAX"; break;
    default: os << "<Unknown eBattleUnitTactic>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eBuilding& rhs)
{
    switch (rhs)
    {
    case BUILDING_Not_applicable: os << "BUILDING_Not_applicable"; break;
    case BUILDING_None: os << "BUILDING_None"; break;
    case BUILDING_Trade_Goods: os << "BUILDING_Trade_Goods"; break;
    case BUILDING_Housing: os << "BUILDING_Housing"; break;
    case BUILDING_Barracks: os << "BUILDING_Barracks"; break;
    case BUILDING_Armory: os << "BUILDING_Armory"; break;
    case BUILDING_Fighters_Guild: os << "BUILDING_Fighters_Guild"; break;
    case BUILDING_Armorers_Guild: os << "BUILDING_Armorers_Guild"; break;
    case BUILDING_War_College: os << "BUILDING_War_College"; break;
    case BUILDING_Smithy: os << "BUILDING_Smithy"; break;
    case BUILDING_Stable: os << "BUILDING_Stable"; break;
    case BUILDING_Animists_Guild: os << "BUILDING_Animists_Guild"; break;
    case BUILDING_Fantastic_Stable: os << "BUILDING_Fantastic_Stable"; break;
    case BUILDING_Shipwright_Guild: os << "BUILDING_Shipwright_Guild"; break;
    case BUILDING_Ship_Yard: os << "BUILDING_Ship_Yard"; break;
    case BUILDING_Maritime_Guild: os << "BUILDING_Maritime_Guild"; break;
    case BUILDING_Sawmill: os << "BUILDING_Sawmill"; break;
    case BUILDING_Library: os << "BUILDING_Library"; break;
    case BUILDING_Sages_Guild: os << "BUILDING_Sages_Guild"; break;
    case BUILDING_Oracle: os << "BUILDING_Oracle"; break;
    case BUILDING_Alchemist_Guild: os << "BUILDING_Alchemist_Guild"; break;
    case BUILDING_University: os << "BUILDING_University"; break;
    case BUILDING_Wizards_Guild: os << "BUILDING_Wizards_Guild"; break;
    case BUILDING_Shrine: os << "BUILDING_Shrine"; break;
    case BUILDING_Temple: os << "BUILDING_Temple"; break;
    case BUILDING_Parthenon: os << "BUILDING_Parthenon"; break;
    case BUILDING_Cathedral: os << "BUILDING_Cathedral"; break;
    case BUILDING_Marketplace: os << "BUILDING_Marketplace"; break;
    case BUILDING_Bank: os << "BUILDING_Bank"; break;
    case BUILDING_Merchants_Guild: os << "BUILDING_Merchants_Guild"; break;
    case BUILDING_Granary: os << "BUILDING_Granary"; break;
    case BUILDING_Farmers_Market: os << "BUILDING_Farmers_Market"; break;
    case BUILDING_Foresters_Guild: os << "BUILDING_Foresters_Guild"; break;
    case BUILDING_Builders_Hall: os << "BUILDING_Builders_Hall"; break;
    case BUILDING_Mechanicians_Guild: os << "BUILDING_Mechanicians_Guild"; break;
    case BUILDING_Miners_Guild: os << "BUILDING_Miners_Guild"; break;
    case BUILDING_City_Walls: os << "BUILDING_City_Walls"; break;
    case eBuilding_array_MAX: os << "eBuilding_array_MAX"; break;
    case BUILDING_Forest: os << "BUILDING_Forest"; break;
    case BUILDING_Grass: os << "BUILDING_Grass"; break;
    case BUILDING_Water: os << "BUILDING_Water"; break;
    case BUILDING_Hill: os << "BUILDING_Hill"; break;
    case eBuilding_extra_MAX: os << "eBuilding_extra_MAX"; break;
    default: os << "<Unknown eBuilding>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eBuilding8& rhs)
{
    switch (rhs)
    {
    case BUILDING8_Not_applicable: os << "BUILDING8_Not_applicable"; break;
    case BUILDING8_None: os << "BUILDING8_None"; break;
    case BUILDING8_Trade_Goods: os << "BUILDING8_Trade_Goods"; break;
    case BUILDING8_Housing: os << "BUILDING8_Housing"; break;
    case BUILDING8_Barracks: os << "BUILDING8_Barracks"; break;
    case BUILDING8_Armory: os << "BUILDING8_Armory"; break;
    case BUILDING8_Fighters_Guild: os << "BUILDING8_Fighters_Guild"; break;
    case BUILDING8_Armorers_Guild: os << "BUILDING8_Armorers_Guild"; break;
    case BUILDING8_War_College: os << "BUILDING8_War_College"; break;
    case BUILDING8_Smithy: os << "BUILDING8_Smithy"; break;
    case BUILDING8_Stable: os << "BUILDING8_Stable"; break;
    case BUILDING8_Animists_Guild: os << "BUILDING8_Animists_Guild"; break;
    case BUILDING8_Fantastic_Stable: os << "BUILDING8_Fantastic_Stable"; break;
    case BUILDING8_Shipwright_Guild: os << "BUILDING8_Shipwright_Guild"; break;
    case BUILDING8_Ship_Yard: os << "BUILDING8_Ship_Yard"; break;
    case BUILDING8_Maritime_Guild: os << "BUILDING8_Maritime_Guild"; break;
    case BUILDING8_Sawmill: os << "BUILDING8_Sawmill"; break;
    case BUILDING8_Library: os << "BUILDING8_Library"; break;
    case BUILDING8_Sages_Guild: os << "BUILDING8_Sages_Guild"; break;
    case BUILDING8_Oracle: os << "BUILDING8_Oracle"; break;
    case BUILDING8_Alchemist_Guild: os << "BUILDING8_Alchemist_Guild"; break;
    case BUILDING8_University: os << "BUILDING8_University"; break;
    case BUILDING8_Wizards_Guild: os << "BUILDING8_Wizards_Guild"; break;
    case BUILDING8_Shrine: os << "BUILDING8_Shrine"; break;
    case BUILDING8_Temple: os << "BUILDING8_Temple"; break;
    case BUILDING8_Parthenon: os << "BUILDING8_Parthenon"; break;
    case BUILDING8_Cathedral: os << "BUILDING8_Cathedral"; break;
    case BUILDING8_Marketplace: os << "BUILDING8_Marketplace"; break;
    case BUILDING8_Bank: os << "BUILDING8_Bank"; break;
    case BUILDING8_Merchants_Guild: os << "BUILDING8_Merchants_Guild"; break;
    case BUILDING8_Granary: os << "BUILDING8_Granary"; break;
    case BUILDING8_Farmers_Market: os << "BUILDING8_Farmers_Market"; break;
    case BUILDING8_Foresters_Guild: os << "BUILDING8_Foresters_Guild"; break;
    case BUILDING8_Builders_Hall: os << "BUILDING8_Builders_Hall"; break;
    case BUILDING8_Mechanicians_Guild: os << "BUILDING8_Mechanicians_Guild"; break;
    case BUILDING8_Miners_Guild: os << "BUILDING8_Miners_Guild"; break;
    case BUILDING8_City_Walls: os << "BUILDING8_City_Walls"; break;
    case eBuilding8_array_MAX: os << "eBuilding8_array_MAX"; break;
    case BUILDING8_Forest: os << "BUILDING8_Forest"; break;
    case BUILDING8_Grass: os << "BUILDING8_Grass"; break;
    case BUILDING8_Water: os << "BUILDING8_Water"; break;
    case BUILDING8_Hill: os << "BUILDING8_Hill"; break;
    case eBuilding8_extra_MAX: os << "eBuilding8_extra_MAX"; break;
    default: os << "<Unknown eBuilding8>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eBuildingCategory& rhs)
{
    switch (rhs)
    {
    case BUILDINGCATEGORY_trade_housing: os << "BUILDINGCATEGORY_trade_housing"; break;
    case BUILDINGCATEGORY_monetary: os << "BUILDINGCATEGORY_monetary"; break;
    case BUILDINGCATEGORY_religious: os << "BUILDINGCATEGORY_religious"; break;
    case BUILDINGCATEGORY_research: os << "BUILDINGCATEGORY_research"; break;
    case BUILDINGCATEGORY_military: os << "BUILDINGCATEGORY_military"; break;
    case BUILDINGCATEGORY_productive: os << "BUILDINGCATEGORY_productive"; break;
    case BUILDINGCATEGORY_food: os << "BUILDINGCATEGORY_food"; break;
    case BUILDINGCATEGORY_ships: os << "BUILDINGCATEGORY_ships"; break;
    case eBuildingCategory_MAX: os << "eBuildingCategory_MAX"; break;
    default: os << "<Unknown eBuildingCategory>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eBuildingStatus& rhs)
{
    switch (rhs)
    {
    case BUILDINGSTATUS_Not_Built: os << "BUILDINGSTATUS_Not_Built"; break;
    case BUILDINGSTATUS_Replaced: os << "BUILDINGSTATUS_Replaced"; break;
    case BUILDINGSTATUS_Built: os << "BUILDINGSTATUS_Built"; break;
    case BUILDINGSTATUS_CoM_Destroyed: os << "BUILDINGSTATUS_CoM_Destroyed"; break;
    case BUILDINGSTATUS_Destroyed: os << "BUILDINGSTATUS_Destroyed"; break;
    case eBuildingStatus_MAX: os << "eBuildingStatus_MAX"; break;
    default: os << "<Unknown eBuildingStatus>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eCentralStructure& rhs)
{
    switch (rhs)
    {
    case CENTRALSTRUCTURE_none: os << "CENTRALSTRUCTURE_none"; break;
    case CENTRALSTRUCTURE_outpost: os << "CENTRALSTRUCTURE_outpost"; break;
    case CENTRALSTRUCTURE_city_grid: os << "CENTRALSTRUCTURE_city_grid"; break;
    case CENTRALSTRUCTURE_wizards_fortress: os << "CENTRALSTRUCTURE_wizards_fortress"; break;
    case CENTRALSTRUCTURE_small_tower: os << "CENTRALSTRUCTURE_small_tower"; break;
    case CENTRALSTRUCTURE_tower_between_planes: os << "CENTRALSTRUCTURE_tower_between_planes"; break;
    case CENTRALSTRUCTURE_cave: os << "CENTRALSTRUCTURE_cave"; break;
    case CENTRALSTRUCTURE_temple: os << "CENTRALSTRUCTURE_temple"; break;
    case CENTRALSTRUCTURE_medium_tower: os << "CENTRALSTRUCTURE_medium_tower"; break;
    case CENTRALSTRUCTURE_sorcery_node: os << "CENTRALSTRUCTURE_sorcery_node"; break;
    case CENTRALSTRUCTURE_chaos_node: os << "CENTRALSTRUCTURE_chaos_node"; break;
    case CENTRALSTRUCTURE_nature_node: os << "CENTRALSTRUCTURE_nature_node"; break;
    case CENTRALSTRUCTURE_ruins: os << "CENTRALSTRUCTURE_ruins"; break;
    case eCentralStructure_MAX: os << "eCentralStructure_MAX"; break;
    default: os << "<Unknown eCentralStructure>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eCityEnchantments& rhs)
{
    switch (rhs)
    {
    case CITYENCH_Wall_of_Fire: os << "CITYENCH_Wall_of_Fire"; break;
    case CITYENCH_Chaos_Rift: os << "CITYENCH_Chaos_Rift"; break;
    case CITYENCH_Dark_Rituals: os << "CITYENCH_Dark_Rituals"; break;
    case CITYENCH_Evil_Presence: os << "CITYENCH_Evil_Presence"; break;
    case CITYENCH_Cursed_Lands: os << "CITYENCH_Cursed_Lands"; break;
    case CITYENCH_Pestilence: os << "CITYENCH_Pestilence"; break;
    case CITYENCH_Cloud_of_Shadow: os << "CITYENCH_Cloud_of_Shadow"; break;
    case CITYENCH_Famine: os << "CITYENCH_Famine"; break;
    case CITYENCH_Flying_Fortress: os << "CITYENCH_Flying_Fortress"; break;
    case CITYENCH_Nature_Ward: os << "CITYENCH_Nature_Ward"; break;
    case CITYENCH_Sorcery_Ward: os << "CITYENCH_Sorcery_Ward"; break;
    case CITYENCH_Chaos_Ward: os << "CITYENCH_Chaos_Ward"; break;
    case CITYENCH_Life_Ward: os << "CITYENCH_Life_Ward"; break;
    case CITYENCH_Death_Ward: os << "CITYENCH_Death_Ward"; break;
    case CITYENCH_Natures_Eye: os << "CITYENCH_Natures_Eye"; break;
    case CITYENCH_Earth_Gate: os << "CITYENCH_Earth_Gate"; break;
    case CITYENCH_Stream_of_Life: os << "CITYENCH_Stream_of_Life"; break;
    case CITYENCH_Gaias_Blessing: os << "CITYENCH_Gaias_Blessing"; break;
    case CITYENCH_Inspirations: os << "CITYENCH_Inspirations"; break;
    case CITYENCH_Prosperity: os << "CITYENCH_Prosperity"; break;
    case CITYENCH_Astral_Gate: os << "CITYENCH_Astral_Gate"; break;
    case CITYENCH_Heavenly_Light: os << "CITYENCH_Heavenly_Light"; break;
    case CITYENCH_Consecration: os << "CITYENCH_Consecration"; break;
    case CITYENCH_Wall_of_Darkness: os << "CITYENCH_Wall_of_Darkness"; break;
    case CITYENCH_Altar_of_Battle: os << "CITYENCH_Altar_of_Battle"; break;
    case CITYENCH_Nightshade: os << "CITYENCH_Nightshade"; break;
    case eCityEnchantments_MAX: os << "eCityEnchantments_MAX"; break;
    default: os << "<Unknown eCityEnchantments>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eCityWall& rhs)
{
    switch (rhs)
    {
    case CITYWALL_type1_first: os << "CITYWALL_type1_first"; break;
    case CITYWALL_type2_first: os << "CITYWALL_type2_first"; break;
    case CITYWALL_type3_first: os << "CITYWALL_type3_first"; break;
    case CITYWALL_walloffire_first: os << "CITYWALL_walloffire_first"; break;
    case CITYWALL_wallofdarkness_first: os << "CITYWALL_wallofdarkness_first"; break;
    case eCityWall_MAX: os << "eCityWall_MAX"; break;
    default: os << "<Unknown eCityWall>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eCity_Size& rhs)
{
    switch (rhs)
    {
    case CITYSIZE_Outpost: os << "CITYSIZE_Outpost"; break;
    case CITYSIZE_Hamlet: os << "CITYSIZE_Hamlet"; break;
    case CITYSIZE_Village: os << "CITYSIZE_Village"; break;
    case CITYSIZE_Town: os << "CITYSIZE_Town"; break;
    case CITYSIZE_City: os << "CITYSIZE_City"; break;
    case CITYSIZE_Capital: os << "CITYSIZE_Capital"; break;
    case eCity_Size_MAX: os << "eCity_Size_MAX"; break;
    default: os << "<Unknown eCity_Size>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eCombatEnchantment& rhs)
{
    switch (rhs)
    {
    case COMBATENCHANTMENT_Vertigo: os << "COMBATENCHANTMENT_Vertigo"; break;
    case COMBATENCHANTMENT_Confusion: os << "COMBATENCHANTMENT_Confusion"; break;
    case COMBATENCHANTMENT_Whirlwind: os << "COMBATENCHANTMENT_Whirlwind"; break;
    case COMBATENCHANTMENT_Mind_Storm: os << "COMBATENCHANTMENT_Mind_Storm"; break;
    case COMBATENCHANTMENT_Shatter: os << "COMBATENCHANTMENT_Shatter"; break;
    case COMBATENCHANTMENT_Weakness: os << "COMBATENCHANTMENT_Weakness"; break;
    case COMBATENCHANTMENT_Black_Sleep: os << "COMBATENCHANTMENT_Black_Sleep"; break;
    case COMBATENCHANTMENT_Warp_Creature_Attack: os << "COMBATENCHANTMENT_Warp_Creature_Attack"; break;
    case COMBATENCHANTMENT_Warp_Creature_Defense: os << "COMBATENCHANTMENT_Warp_Creature_Defense"; break;
    case COMBATENCHANTMENT_Warp_Creature_Resistance: os << "COMBATENCHANTMENT_Warp_Creature_Resistance"; break;
    case COMBATENCHANTMENT_Mind_Twist: os << "COMBATENCHANTMENT_Mind_Twist"; break;
    case COMBATENCHANTMENT_Haste: os << "COMBATENCHANTMENT_Haste"; break;
    case COMBATENCHANTMENT_Web: os << "COMBATENCHANTMENT_Web"; break;
    case COMBATENCHANTMENT_Creature_Binding: os << "COMBATENCHANTMENT_Creature_Binding"; break;
    case COMBATENCHANTMENT_Possession: os << "COMBATENCHANTMENT_Possession"; break;
    case COMBATENCHANTMENT_No_Effect80: os << "COMBATENCHANTMENT_No_Effect80"; break;
    case eCombatEnchantment_MAX: os << "eCombatEnchantment_MAX"; break;
    default: os << "<Unknown eCombatEnchantment>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eDifficulty& rhs)
{
    switch (rhs)
    {
    case DIFFICULTY_Tutorial: os << "DIFFICULTY_Tutorial"; break;
    case DIFFICULTY_Easy: os << "DIFFICULTY_Easy"; break;
    case DIFFICULTY_Normal: os << "DIFFICULTY_Normal"; break;
    case DIFFICULTY_Hard: os << "DIFFICULTY_Hard"; break;
    case DIFFICULTY_Impossible: os << "DIFFICULTY_Impossible"; break;
    case eDifficulty_MAX: os << "eDifficulty_MAX"; break;
    default: os << "<Unknown eDifficulty>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eDifficulty140m& rhs)
{
    switch (rhs)
    {
    case DIFFICULTY140M_Easy: os << "DIFFICULTY140M_Easy"; break;
    case DIFFICULTY140M_Normal: os << "DIFFICULTY140M_Normal"; break;
    case DIFFICULTY140M_Hard: os << "DIFFICULTY140M_Hard"; break;
    case DIFFICULTY140M_Extreme: os << "DIFFICULTY140M_Extreme"; break;
    case DIFFICULTY140M_Impossible: os << "DIFFICULTY140M_Impossible"; break;
    case eDifficulty140m_MAX: os << "eDifficulty140m_MAX"; break;
    default: os << "<Unknown eDifficulty140m>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eDifficulty150& rhs)
{
    switch (rhs)
    {
    case DIFFICULTY150_Easy: os << "DIFFICULTY150_Easy"; break;
    case DIFFICULTY150_Normal: os << "DIFFICULTY150_Normal"; break;
    case DIFFICULTY150_Advanced: os << "DIFFICULTY150_Advanced"; break;
    case DIFFICULTY150_Expert: os << "DIFFICULTY150_Expert"; break;
    case DIFFICULTY150_Master: os << "DIFFICULTY150_Master"; break;
    case DIFFICULTY150_Lunatic: os << "DIFFICULTY150_Lunatic"; break;
    case eDifficulty150_MAX: os << "eDifficulty150_MAX"; break;
    default: os << "<Unknown eDifficulty150>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eDifficulty60& rhs)
{
    switch (rhs)
    {
    case DIFFICULTY60_Easy: os << "DIFFICULTY60_Easy"; break;
    case DIFFICULTY60_Normal: os << "DIFFICULTY60_Normal"; break;
    case DIFFICULTY60_Fair: os << "DIFFICULTY60_Fair"; break;
    case DIFFICULTY60_Advanced: os << "DIFFICULTY60_Advanced"; break;
    case DIFFICULTY60_Expert: os << "DIFFICULTY60_Expert"; break;
    case DIFFICULTY60_Master: os << "DIFFICULTY60_Master"; break;
    case DIFFICULTY60_Lunatic: os << "DIFFICULTY60_Lunatic"; break;
    case eDIFFICULTY60_MAX: os << "eDIFFICULTY60_MAX"; break;
    default: os << "<Unknown eDifficulty60>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eEvent& rhs)
{
    switch (rhs)
    {
    case EVENT_None: os << "EVENT_None"; break;
    case EVENT_Meteor: os << "EVENT_Meteor"; break;
    case EVENT_Gift_from_the_Gods: os << "EVENT_Gift_from_the_Gods"; break;
    case EVENT_Disjunction: os << "EVENT_Disjunction"; break;
    case EVENT_Diplomatic_Marriage: os << "EVENT_Diplomatic_Marriage"; break;
    case EVENT_Earthquake: os << "EVENT_Earthquake"; break;
    case EVENT_Pirates: os << "EVENT_Pirates"; break;
    case EVENT_Plague: os << "EVENT_Plague"; break;
    case EVENT_Rebellion: os << "EVENT_Rebellion"; break;
    case EVENT_Donation: os << "EVENT_Donation"; break;
    case EVENT_Depletion: os << "EVENT_Depletion"; break;
    case EVENT_Mine_found: os << "EVENT_Mine_found"; break;
    case EVENT_Population_Boom: os << "EVENT_Population_Boom"; break;
    case EVENT_Good_Moon: os << "EVENT_Good_Moon"; break;
    case EVENT_Bad_Moon: os << "EVENT_Bad_Moon"; break;
    case EVENT_Conjunction_Chaos: os << "EVENT_Conjunction_Chaos"; break;
    case EVENT_Conjunction_Nature: os << "EVENT_Conjunction_Nature"; break;
    case EVENT_Conjunction_Sorcery: os << "EVENT_Conjunction_Sorcery"; break;
    case EVENT_Mana_Short: os << "EVENT_Mana_Short"; break;
    case eEvent_MAX: os << "eEvent_MAX"; break;
    default: os << "<Unknown eEvent>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eGameState& rhs)
{
    switch (rhs)
    {
    case STATE_City_display: os << "STATE_City_display"; break;
    case STATE_Game: os << "STATE_Game"; break;
    case STATE_Armies: os << "STATE_Armies"; break;
    case STATE_Cities: os << "STATE_Cities"; break;
    case STATE_Exit: os << "STATE_Exit"; break;
    case STATE_Main: os << "STATE_Main"; break;
    case STATE_Magic: os << "STATE_Magic"; break;
    case STATE_Road_Building_You: os << "STATE_Road_Building_You"; break;
    case STATE_Change: os << "STATE_Change"; break;
    case STATE_Item_You: os << "STATE_Item_You"; break;
    case STATE_Next_turn_seq: os << "STATE_Next_turn_seq"; break;
    case STATE_11_default: os << "STATE_11_default"; break;
    case STATE_Spells: os << "STATE_Spells"; break;
    case STATE_13_default: os << "STATE_13_default"; break;
    case STATE_Info: os << "STATE_Info"; break;
    case STATE_Diplomacy: os << "STATE_Diplomacy"; break;
    case STATE_Computers_turn_GUESS: os << "STATE_Computers_turn_GUESS"; break;
    default: os << "<Unknown eGameState>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eGlobalEnchantment& rhs)
{
    switch (rhs)
    {
    case GLOBALENCHANTMENT_Eternal_Night: os << "GLOBALENCHANTMENT_Eternal_Night"; break;
    case GLOBALENCHANTMENT_Evil_Omens: os << "GLOBALENCHANTMENT_Evil_Omens"; break;
    case GLOBALENCHANTMENT_Zombie_Mastery: os << "GLOBALENCHANTMENT_Zombie_Mastery"; break;
    case GLOBALENCHANTMENT_Aura_of_Majesty: os << "GLOBALENCHANTMENT_Aura_of_Majesty"; break;
    case GLOBALENCHANTMENT_Wind_Mastery: os << "GLOBALENCHANTMENT_Wind_Mastery"; break;
    case GLOBALENCHANTMENT_Suppress_Magic: os << "GLOBALENCHANTMENT_Suppress_Magic"; break;
    case GLOBALENCHANTMENT_Time_Stop: os << "GLOBALENCHANTMENT_Time_Stop"; break;
    case GLOBALENCHANTMENT_Nature_Awareness: os << "GLOBALENCHANTMENT_Nature_Awareness"; break;
    case GLOBALENCHANTMENT_Natures_Wrath: os << "GLOBALENCHANTMENT_Natures_Wrath"; break;
    case GLOBALENCHANTMENT_Herb_Mastery: os << "GLOBALENCHANTMENT_Herb_Mastery"; break;
    case GLOBALENCHANTMENT_Chaos_Surge: os << "GLOBALENCHANTMENT_Chaos_Surge"; break;
    case GLOBALENCHANTMENT_Doom_Mastery: os << "GLOBALENCHANTMENT_Doom_Mastery"; break;
    case GLOBALENCHANTMENT_Great_Wasting: os << "GLOBALENCHANTMENT_Great_Wasting"; break;
    case GLOBALENCHANTMENT_Meteor_Storm: os << "GLOBALENCHANTMENT_Meteor_Storm"; break;
    case GLOBALENCHANTMENT_Armageddon: os << "GLOBALENCHANTMENT_Armageddon"; break;
    case GLOBALENCHANTMENT_Tranquility: os << "GLOBALENCHANTMENT_Tranquility"; break;
    case GLOBALENCHANTMENT_Life_Force: os << "GLOBALENCHANTMENT_Life_Force"; break;
    case GLOBALENCHANTMENT_Crusade: os << "GLOBALENCHANTMENT_Crusade"; break;
    case GLOBALENCHANTMENT_Just_Cause: os << "GLOBALENCHANTMENT_Just_Cause"; break;
    case GLOBALENCHANTMENT_Holy_Arms: os << "GLOBALENCHANTMENT_Holy_Arms"; break;
    case GLOBALENCHANTMENT_Planar_Seal: os << "GLOBALENCHANTMENT_Planar_Seal"; break;
    case GLOBALENCHANTMENT_Charm_of_Life: os << "GLOBALENCHANTMENT_Charm_of_Life"; break;
    case GLOBALENCHANTMENT_Detect_Magic: os << "GLOBALENCHANTMENT_Detect_Magic"; break;
    case GLOBALENCHANTMENT_Awareness: os << "GLOBALENCHANTMENT_Awareness"; break;
    case eGlobalEnchantment_MAX: os << "eGlobalEnchantment_MAX"; break;
    default: os << "<Unknown eGlobalEnchantment>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eGrand_Vizier& rhs)
{
    switch (rhs)
    {
    case GRANDVIZIER_Off: os << "GRANDVIZIER_Off"; break;
    case GRANDVIZIER_On: os << "GRANDVIZIER_On"; break;
    default: os << "<Unknown eGrand_Vizier>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eHelpIndex& rhs)
{
    switch (rhs)
    {
    case eHelpIndex_NONE: os << "eHelpIndex_NONE"; break;
    case HELP_EXIT_SPELL_BOOK: os << "HELP_EXIT_SPELL_BOOK"; break;
    case HELP_EARTH_TO_MUD: os << "HELP_EARTH_TO_MUD"; break;
    case HELP_RESIST_ELEMENTS: os << "HELP_RESIST_ELEMENTS"; break;
    case HELP_WALL_OF_STONE: os << "HELP_WALL_OF_STONE"; break;
    case HELP_GIANT_STRENGTH: os << "HELP_GIANT_STRENGTH"; break;
    case HELP_WEB: os << "HELP_WEB"; break;
    case HELP_figure12_WAR_BEARS: os << "HELP_figure12_WAR_BEARS"; break;
    case HELP_STONE_SKIN: os << "HELP_STONE_SKIN"; break;
    case HELP_WATER_WALKING: os << "HELP_WATER_WALKING"; break;
    case HELP_figure13_SPRITES: os << "HELP_figure13_SPRITES"; break;
    case HELP_EARTH_LORE: os << "HELP_EARTH_LORE"; break;
    case HELP_CRACKS_CALL: os << "HELP_CRACKS_CALL"; break;
    case HELP_NATURES_EYE: os << "HELP_NATURES_EYE"; break;
    case HELP_ICE_BOLT: os << "HELP_ICE_BOLT"; break;
    case HELP_figure13_GIANT_SPIDERS: os << "HELP_figure13_GIANT_SPIDERS"; break;
    case HELP_CHANGE_TERRAIN: os << "HELP_CHANGE_TERRAIN"; break;
    case HELP_PATH_FINDING: os << "HELP_PATH_FINDING"; break;
    case HELP_figure13_COCKATRICES: os << "HELP_figure13_COCKATRICES"; break;
    case HELP_TRANSMUTE: os << "HELP_TRANSMUTE"; break;
    case HELP_NATURES_CURES: os << "HELP_NATURES_CURES"; break;
    case HELP_figure13_BASILISKS: os << "HELP_figure13_BASILISKS"; break;
    case HELP_ELEMENTAL_ARMOR: os << "HELP_ELEMENTAL_ARMOR"; break;
    case HELP_PETRIFY: os << "HELP_PETRIFY"; break;
    case HELP_figure13_STONE_GIANT: os << "HELP_figure13_STONE_GIANT"; break;
    case HELP_IRON_SKIN: os << "HELP_IRON_SKIN"; break;
    case HELP_ICE_STORM: os << "HELP_ICE_STORM"; break;
    case HELP_EARTHQUAKE: os << "HELP_EARTHQUAKE"; break;
    case HELP_figure13_GORGONS: os << "HELP_figure13_GORGONS"; break;
    case HELP_MOVE_FORTRESS: os << "HELP_MOVE_FORTRESS"; break;
    case HELP_GAIAS_BLESSING: os << "HELP_GAIAS_BLESSING"; break;
    case HELP_figure13_EARTH_ELEMENTAL: os << "HELP_figure13_EARTH_ELEMENTAL"; break;
    case HELP_REGENERATION: os << "HELP_REGENERATION"; break;
    case HELP_figure13_BEHEMOTH: os << "HELP_figure13_BEHEMOTH"; break;
    case HELP_ENTANGLE: os << "HELP_ENTANGLE"; break;
    case HELP_NATURES_AWARENESS: os << "HELP_NATURES_AWARENESS"; break;
    case HELP_CALL_LIGHTNING: os << "HELP_CALL_LIGHTNING"; break;
    case HELP_figure13_COLOSSUS: os << "HELP_figure13_COLOSSUS"; break;
    case HELP_EARTH_GATE: os << "HELP_EARTH_GATE"; break;
    case HELP_HERB_MASTERY: os << "HELP_HERB_MASTERY"; break;
    case HELP_figure13_GREAT_WYRM: os << "HELP_figure13_GREAT_WYRM"; break;
    case HELP_NATURES_WRATH: os << "HELP_NATURES_WRATH"; break;
    case HELP_RESIST_MAGIC: os << "HELP_RESIST_MAGIC"; break;
    case HELP_DISPEL_MAGIC_TRUE: os << "HELP_DISPEL_MAGIC_TRUE"; break;
    case HELP_FLOATING_ISLANDS: os << "HELP_FLOATING_ISLANDS"; break;
    case HELP_GUARDIAN_WIND: os << "HELP_GUARDIAN_WIND"; break;
    case HELP_Figure13_PHANTOM_WARRIORS: os << "HELP_Figure13_PHANTOM_WARRIORS"; break;
    case HELP_CONFUSION: os << "HELP_CONFUSION"; break;
    case HELP_WORD_OF_RECALL: os << "HELP_WORD_OF_RECALL"; break;
    case HELP_COUNTER_MAGIC: os << "HELP_COUNTER_MAGIC"; break;
    case HELP_figure14_NAGAS: os << "HELP_figure14_NAGAS"; break;
    case HELP_PSIONIC_BLAST: os << "HELP_PSIONIC_BLAST"; break;
    case HELP_BLUR: os << "HELP_BLUR"; break;
    case HELP_DISENCHANT_TRUE: os << "HELP_DISENCHANT_TRUE"; break;
    case HELP_VERTIGO: os << "HELP_VERTIGO"; break;
    case HELP_SPELL_LOCK: os << "HELP_SPELL_LOCK"; break;
    case HELP_ENCHANT_ROAD: os << "HELP_ENCHANT_ROAD"; break;
    case HELP_FLIGHT: os << "HELP_FLIGHT"; break;
    case HELP_WIND_MASTERY: os << "HELP_WIND_MASTERY"; break;
    case HELP_SPELL_BLAST: os << "HELP_SPELL_BLAST"; break;
    case HELP_AURA_OF_MAJESTY: os << "HELP_AURA_OF_MAJESTY"; break;
    case HELP_Figure13_PHANTOM_BEAST: os << "HELP_Figure13_PHANTOM_BEAST"; break;
    case HELP_DISJUNCTION_TRUE: os << "HELP_DISJUNCTION_TRUE"; break;
    case HELP_INVISIBILITY: os << "HELP_INVISIBILITY"; break;
    case HELP_WIND_WALKING: os << "HELP_WIND_WALKING"; break;
    case HELP_BANISH: os << "HELP_BANISH"; break;
    case HELP_Figure13_STORM_GIANT: os << "HELP_Figure13_STORM_GIANT"; break;
    case HELP_Figure13_AIR_ELEMENTAL: os << "HELP_Figure13_AIR_ELEMENTAL"; break;
    case HELP_MIND_STORM: os << "HELP_MIND_STORM"; break;
    case HELP_STASIS: os << "HELP_STASIS"; break;
    case HELP_MAGIC_IMMUNITY: os << "HELP_MAGIC_IMMUNITY"; break;
    case HELP_HASTE: os << "HELP_HASTE"; break;
    case HELP_figure14_DJINN: os << "HELP_figure14_DJINN"; break;
    case HELP_SPELL_WARD: os << "HELP_SPELL_WARD"; break;
    case HELP_CREATURE_BINDING: os << "HELP_CREATURE_BINDING"; break;
    case HELP_MASS_INVISIBILITY: os << "HELP_MASS_INVISIBILITY"; break;
    case HELP_GREAT_UNSUMMONING: os << "HELP_GREAT_UNSUMMONING"; break;
    case HELP_SPELL_BINDING: os << "HELP_SPELL_BINDING"; break;
    case HELP_FLYING_FORTRESS: os << "HELP_FLYING_FORTRESS"; break;
    case HELP_Figure14_SKY_DRAKE: os << "HELP_Figure14_SKY_DRAKE"; break;
    case HELP_SUPPRESS_MAGIC: os << "HELP_SUPPRESS_MAGIC"; break;
    case HELP_TIME_STOP: os << "HELP_TIME_STOP"; break;
    case HELP_WARP_WOOD: os << "HELP_WARP_WOOD"; break;
    case HELP_DISRUPT: os << "HELP_DISRUPT"; break;
    case HELP_FIRE_BOLT: os << "HELP_FIRE_BOLT"; break;
    case HELP_figure11_HELL_HOUNDS: os << "HELP_figure11_HELL_HOUNDS"; break;
    case HELP_CORRUPTION: os << "HELP_CORRUPTION"; break;
    case HELP_spell_SPECIAL_ELDRITCH_WEAPON: os << "HELP_spell_SPECIAL_ELDRITCH_WEAPON"; break;
    case HELP_WALL_OF_FIRE: os << "HELP_WALL_OF_FIRE"; break;
    case HELP_spell_SPECIAL_SHATTER: os << "HELP_spell_SPECIAL_SHATTER"; break;
    case HELP_spell_SPECIAL2_WARP_CREATURE: os << "HELP_spell_SPECIAL2_WARP_CREATURE"; break;
    case HELP_figure11_FIRE_ELEMENTAL: os << "HELP_figure11_FIRE_ELEMENTAL"; break;
    case HELP_LIGHTNING_BOLT: os << "HELP_LIGHTNING_BOLT"; break;
    case HELP_Figure11_FIRE_GIANT: os << "HELP_Figure11_FIRE_GIANT"; break;
    case HELP_spell_SPECIAL_CHAOS_CHANNELS: os << "HELP_spell_SPECIAL_CHAOS_CHANNELS"; break;
    case HELP_spell_SPECIAL_FLAME_BLADE: os << "HELP_spell_SPECIAL_FLAME_BLADE"; break;
    case HELP_figure11_GARGOYLES: os << "HELP_figure11_GARGOYLES"; break;
    case HELP_FIREBALL: os << "HELP_FIREBALL"; break;
    case HELP_figure11_DOOM_BAT: os << "HELP_figure11_DOOM_BAT"; break;
    case HELP_RAISE_VOLCANO: os << "HELP_RAISE_VOLCANO"; break;
    case HELP_spell_SPECIAL2_IMMOLATION: os << "HELP_spell_SPECIAL2_IMMOLATION"; break;
    case HELP_Figure11_CHIMERA: os << "HELP_Figure11_CHIMERA"; break;
    case HELP_WARP_LIGHTNING: os << "HELP_WARP_LIGHTNING"; break;
    case HELP_spell_COMPIX_METAL_FIRES: os << "HELP_spell_COMPIX_METAL_FIRES"; break;
    case HELP_figure11_CHAOS_SPAWN: os << "HELP_figure11_CHAOS_SPAWN"; break;
    case HELP_DOOM_BOLT: os << "HELP_DOOM_BOLT"; break;
    case HELP_MAGIC_VORTEX: os << "HELP_MAGIC_VORTEX"; break;
    case HELP_Figure11_EFREET: os << "HELP_Figure11_EFREET"; break;
    case HELP_FIRE_STORM: os << "HELP_FIRE_STORM"; break;
    case HELP_spell_COMPIX_WARP_REALITY: os << "HELP_spell_COMPIX_WARP_REALITY"; break;
    case HELP_FLAME_STRIKE: os << "HELP_FLAME_STRIKE"; break;
    case HELP_CHAOS_RIFT: os << "HELP_CHAOS_RIFT"; break;
    case HELP_Figure11_HYDRA: os << "HELP_Figure11_HYDRA"; break;
    case HELP_DISINTEGRATE: os << "HELP_DISINTEGRATE"; break;
    case HELP_METEOR_STORM: os << "HELP_METEOR_STORM"; break;
    case HELP_GREAT_WASTING: os << "HELP_GREAT_WASTING"; break;
    case HELP_CALL_CHAOS: os << "HELP_CALL_CHAOS"; break;
    case HELP_CHAOS_SURGE: os << "HELP_CHAOS_SURGE"; break;
    case HELP_DOOM_MASTERY: os << "HELP_DOOM_MASTERY"; break;
    case HELP_figure11_GREAT_DRAKE: os << "HELP_figure11_GREAT_DRAKE"; break;
    case HELP_CALL_THE_VOID: os << "HELP_CALL_THE_VOID"; break;
    case HELP_ARMAGEDON: os << "HELP_ARMAGEDON"; break;
    case HELP_BLESS: os << "HELP_BLESS"; break;
    case HELP_STAR_FIRES: os << "HELP_STAR_FIRES"; break;
    case HELP_ENDURANCE: os << "HELP_ENDURANCE"; break;
    case HELP_HOLY_WEAPON: os << "HELP_HOLY_WEAPON"; break;
    case HELP_HEALING: os << "HELP_HEALING"; break;
    case HELP_HOLY_ARMOR: os << "HELP_HOLY_ARMOR"; break;
    case HELP_JUST_CAUSE: os << "HELP_JUST_CAUSE"; break;
    case HELP_TRUE_LIGHT: os << "HELP_TRUE_LIGHT"; break;
    case HELP_figure12_GUARDIAN_SPIRIT: os << "HELP_figure12_GUARDIAN_SPIRIT"; break;
    case HELP_HEROISM: os << "HELP_HEROISM"; break;
    case HELP_TRUE_SIGHT: os << "HELP_TRUE_SIGHT"; break;
    case HELP_PLANE_SHIFT: os << "HELP_PLANE_SHIFT"; break;
    case HELP_RESURRECTION: os << "HELP_RESURRECTION"; break;
    case HELP_DISPEL_EVIL: os << "HELP_DISPEL_EVIL"; break;
    case HELP_PLANAR_SEAL: os << "HELP_PLANAR_SEAL"; break;
    case HELP_Figure12_UNICORNS: os << "HELP_Figure12_UNICORNS"; break;
    case HELP_RAISE_DEAD: os << "HELP_RAISE_DEAD"; break;
    case HELP_PLANAR_TRAVEL: os << "HELP_PLANAR_TRAVEL"; break;
    case HELP_HEAVENLY_LIGHT: os << "HELP_HEAVENLY_LIGHT"; break;
    case HELP_PRAYER: os << "HELP_PRAYER"; break;
    case HELP_LION_HEART: os << "HELP_LION_HEART"; break;
    case HELP_figures3_INCARNATION: os << "HELP_figures3_INCARNATION"; break;
    case HELP_INVULNERABILITY: os << "HELP_INVULNERABILITY"; break;
    case HELP_RIGHTEOUSNESS: os << "HELP_RIGHTEOUSNESS"; break;
    case HELP_PROSPERITY: os << "HELP_PROSPERITY"; break;
    case HELP_ALTAR_OF_BATTLE: os << "HELP_ALTAR_OF_BATTLE"; break;
    case HELP_figure12_ANGEL: os << "HELP_figure12_ANGEL"; break;
    case HELP_STREAM_OF_LIFE: os << "HELP_STREAM_OF_LIFE"; break;
    case HELP_MASS_HEALING: os << "HELP_MASS_HEALING"; break;
    case HELP_HOLY_WORD: os << "HELP_HOLY_WORD"; break;
    case HELP_HIGH_PRAYER: os << "HELP_HIGH_PRAYER"; break;
    case HELP_INSPIRATIONS: os << "HELP_INSPIRATIONS"; break;
    case HELP_ASTRAL_GATE: os << "HELP_ASTRAL_GATE"; break;
    case HELP_HOLY_ARMS: os << "HELP_HOLY_ARMS"; break;
    case HELP_CONSECRATION: os << "HELP_CONSECRATION"; break;
    case HELP_LIFE_FORCE: os << "HELP_LIFE_FORCE"; break;
    case HELP_TRANQUILITY: os << "HELP_TRANQUILITY"; break;
    case HELP_CRUSADE: os << "HELP_CRUSADE"; break;
    case HELP_figure12_ARCHANGEL: os << "HELP_figure12_ARCHANGEL"; break;
    case HELP_CHARM_OF_LIFE: os << "HELP_CHARM_OF_LIFE"; break;
    case HELP_Figure12_SKELETONS: os << "HELP_Figure12_SKELETONS"; break;
    case HELP_spell_SPECIAL_WEAKNESS: os << "HELP_spell_SPECIAL_WEAKNESS"; break;
    case HELP_DARK_RITUALS: os << "HELP_DARK_RITUALS"; break;
    case HELP_spell_SPECIAL_CLOAK_OF_FEAR: os << "HELP_spell_SPECIAL_CLOAK_OF_FEAR"; break;
    case HELP_spell_SPECIAL2_BLACK_SLEEP: os << "HELP_spell_SPECIAL2_BLACK_SLEEP"; break;
    case HELP_Figure12_GHOULS: os << "HELP_Figure12_GHOULS"; break;
    case HELP_LIFE_DRAIN: os << "HELP_LIFE_DRAIN"; break;
    case HELP_TERROR: os << "HELP_TERROR"; break;
    case HELP_spell_COMPIX_DARKNESS: os << "HELP_spell_COMPIX_DARKNESS"; break;
    case HELP_MANA_LEAK: os << "HELP_MANA_LEAK"; break;
    case HELP_DRAIN_POWER: os << "HELP_DRAIN_POWER"; break;
    case HELP_spell_SPECIAL_POSSESSION: os << "HELP_spell_SPECIAL_POSSESSION"; break;
    case HELP_Figure12_LYCANTHROPY: os << "HELP_Figure12_LYCANTHROPY"; break;
    case HELP_spell_COMPIX_BLACK_PRAYER: os << "HELP_spell_COMPIX_BLACK_PRAYER"; break;
    case HELP_spell_SPECIAL_BLACK_CHANNELS: os << "HELP_spell_SPECIAL_BLACK_CHANNELS"; break;
    case HELP_Figure12_NIGHT_STALKER: os << "HELP_Figure12_NIGHT_STALKER"; break;
    case HELP_SUBVERSION: os << "HELP_SUBVERSION"; break;
    case HELP_WALL_OF_DARKNESS: os << "HELP_WALL_OF_DARKNESS"; break;
    case HELP_spell_SPECIAL2_BERSERK: os << "HELP_spell_SPECIAL2_BERSERK"; break;
    case HELP_Figure12_SHADOW_DEMONS: os << "HELP_Figure12_SHADOW_DEMONS"; break;
    case HELP_spell_SPECIAL_WRAITH_FORM: os << "HELP_spell_SPECIAL_WRAITH_FORM"; break;
    case HELP_spell_COMPIX_WRACK: os << "HELP_spell_COMPIX_WRACK"; break;
    case HELP_EVIL_PRESENCE: os << "HELP_EVIL_PRESENCE"; break;
    case HELP_Figure12_WRAITHS: os << "HELP_Figure12_WRAITHS"; break;
    case HELP_CLOUD_OF_SHADOW: os << "HELP_CLOUD_OF_SHADOW"; break;
    case HELP_WARP_NODE: os << "HELP_WARP_NODE"; break;
    case HELP_BLACK_WIND: os << "HELP_BLACK_WIND"; break;
    case HELP_Figure12_ZOMBIE_MASTERY: os << "HELP_Figure12_ZOMBIE_MASTERY"; break;
    case HELP_FAMINE: os << "HELP_FAMINE"; break;
    case HELP_CURSED_LANDS: os << "HELP_CURSED_LANDS"; break;
    case HELP_CRUEL_UNMINDING: os << "HELP_CRUEL_UNMINDING"; break;
    case HELP_WORD_OF_DEATH: os << "HELP_WORD_OF_DEATH"; break;
    case HELP_Figure12_DEATH_KNIGHTS: os << "HELP_Figure12_DEATH_KNIGHTS"; break;
    case HELP_DEATH_SPELL: os << "HELP_DEATH_SPELL"; break;
    case HELP_ANIMATE_DEAD: os << "HELP_ANIMATE_DEAD"; break;
    case HELP_PESTILENCE: os << "HELP_PESTILENCE"; break;
    case HELP_ETERNAL_NIGHT: os << "HELP_ETERNAL_NIGHT"; break;
    case HELP_EVIL_OMENS: os << "HELP_EVIL_OMENS"; break;
    case HELP_DEATH_WISH: os << "HELP_DEATH_WISH"; break;
    case HELP_Figure12_DEMON_LORD: os << "HELP_Figure12_DEMON_LORD"; break;
    case HELP_figure11_MAGIC_SPIRIT: os << "HELP_figure11_MAGIC_SPIRIT"; break;
    case HELP_DISPEL_MAGIC: os << "HELP_DISPEL_MAGIC"; break;
    case HELP_spell_cityscap_SUMMONING_CIRCLE: os << "HELP_spell_cityscap_SUMMONING_CIRCLE"; break;
    case HELP_DISENCHANT_AREA: os << "HELP_DISENCHANT_AREA"; break;
    case HELP_RECALL_HERO: os << "HELP_RECALL_HERO"; break;
    case HELP_DETECT_MAGIC: os << "HELP_DETECT_MAGIC"; break;
    case HELP_ENCHANT_ITEM: os << "HELP_ENCHANT_ITEM"; break;
    case HELP_SUMMON_HERO: os << "HELP_SUMMON_HERO"; break;
    case HELP_AWARENESS: os << "HELP_AWARENESS"; break;
    case HELP_DISJUNCTION: os << "HELP_DISJUNCTION"; break;
    case HELP_CREATE_ARTIFACT: os << "HELP_CREATE_ARTIFACT"; break;
    case HELP_SUMMON_CHAMPION: os << "HELP_SUMMON_CHAMPION"; break;
    case HELP_spell_SPELL_OF_MASTERY: os << "HELP_spell_SPELL_OF_MASTERY"; break;
    case HELP_SPECIAL2_PAGE_BACK: os << "HELP_SPECIAL2_PAGE_BACK"; break;
    case HELP_SPECIAL2_PAGE_FORWARD: os << "HELP_SPECIAL2_PAGE_FORWARD"; break;
    case HELP_MAIN_GAME: os << "HELP_MAIN_GAME"; break;
    case HELP_MAIN_SPELLS: os << "HELP_MAIN_SPELLS"; break;
    case HELP_MAIN_ARMIES: os << "HELP_MAIN_ARMIES"; break;
    case HELP_MAIN_CITIES: os << "HELP_MAIN_CITIES"; break;
    case HELP_MAIN_MAGIC: os << "HELP_MAIN_MAGIC"; break;
    case HELP_MAIN_INFORMATION: os << "HELP_MAIN_INFORMATION"; break;
    case HELP_MAIN_PLANE: os << "HELP_MAIN_PLANE"; break;
    case HELP_MAIN_DONE: os << "HELP_MAIN_DONE"; break;
    case HELP_MAIN_PATROL: os << "HELP_MAIN_PATROL"; break;
    case HELP_MAIN_WAIT: os << "HELP_MAIN_WAIT"; break;
    case HELP_MAIN_BUILD: os << "HELP_MAIN_BUILD"; break;
    case HELP_MAIN_PURIFY: os << "HELP_MAIN_PURIFY"; break;
    case HELP_MAIN_MELD: os << "HELP_MAIN_MELD"; break;
    case HELP_NEXT_TURN: os << "HELP_NEXT_TURN"; break;
    case HELP_REDUCED_MAP: os << "HELP_REDUCED_MAP"; break;
    case HELP_TOTAL_GOLD: os << "HELP_TOTAL_GOLD"; break;
    case HELP_TOTAL_MANA: os << "HELP_TOTAL_MANA"; break;
    case HELP_GOLD_INCOME: os << "HELP_GOLD_INCOME"; break;
    case HELP_FOOD_RESERVE: os << "HELP_FOOD_RESERVE"; break;
    case HELP_MANA_INCOME: os << "HELP_MANA_INCOME"; break;
    case HELP_MOVES: os << "HELP_MOVES"; break;
    case HELP_1_REDUCED_MAP: os << "HELP_1_REDUCED_MAP"; break;
    case HELP_UNIT_NAME: os << "HELP_UNIT_NAME"; break;
    case HELP_UNIT_ENCHANTMENTS: os << "HELP_UNIT_ENCHANTMENTS"; break;
    case HELP_ARMYLIST_ITEMS: os << "HELP_ARMYLIST_ITEMS"; break;
    case HELP_1_ARMYLIST_OK: os << "HELP_1_ARMYLIST_OK"; break;
    case HELP_1_UPKEEP: os << "HELP_1_UPKEEP"; break;
    case HELP_EMPTY_HERO_SLOT: os << "HELP_EMPTY_HERO_SLOT"; break;
    case HELP_ARMYLIST_UP_ARROW: os << "HELP_ARMYLIST_UP_ARROW"; break;
    case HELP_ARMYLIST_DOWN_ARROW: os << "HELP_ARMYLIST_DOWN_ARROW"; break;
    case HELP_ANVIL: os << "HELP_ANVIL"; break;
    case HELP_ARMYLIST_ALCHEMY: os << "HELP_ARMYLIST_ALCHEMY"; break;
    case HELP_2_ARMYLIST_OK: os << "HELP_2_ARMYLIST_OK"; break;
    case HELP_2_REDUCED_MAP: os << "HELP_2_REDUCED_MAP"; break;
    case HELP_2_CITY_NAME: os << "HELP_2_CITY_NAME"; break;
    case HELP_CITY_ENCHANTMENTS: os << "HELP_CITY_ENCHANTMENTS"; break;
    case HELP_RELOAD_OK: os << "HELP_RELOAD_OK"; break;
    case HELP_MAIN_WALKING: os << "HELP_MAIN_WALKING"; break;
    case HELP_MAIN_FORESTER: os << "HELP_MAIN_FORESTER"; break;
    case HELP_MAIN_MOUNTAINEER: os << "HELP_MAIN_MOUNTAINEER"; break;
    case HELP_MAIN_FLYING: os << "HELP_MAIN_FLYING"; break;
    case HELP_MAIN_PATHFINDING: os << "HELP_MAIN_PATHFINDING"; break;
    case HELP_MAIN_SWIMMING: os << "HELP_MAIN_SWIMMING"; break;
    case HELP_MAIN_SAILING: os << "HELP_MAIN_SAILING"; break;
    case HELP_MAIN_WIND_WALKING: os << "HELP_MAIN_WIND_WALKING"; break;
    case HELP_MAIN_PLANAR_TRAVEL: os << "HELP_MAIN_PLANAR_TRAVEL"; break;
    case HELP_MAGIC_GRAY_GEM: os << "HELP_MAGIC_GRAY_GEM"; break;
    case HELP_MAGIC_SHATTERED_GEM: os << "HELP_MAGIC_SHATTERED_GEM"; break;
    case HELP_POWER_DISTRIBUTION: os << "HELP_POWER_DISTRIBUTION"; break;
    case HELP_CASTING_SKILL_RATIO: os << "HELP_CASTING_SKILL_RATIO"; break;
    case HELP_MANA_POINTS_RATIO: os << "HELP_MANA_POINTS_RATIO"; break;
    case HELP_RESEARCH_RATIO: os << "HELP_RESEARCH_RATIO"; break;
    case HELP_MAGIC_ALCHEMY: os << "HELP_MAGIC_ALCHEMY"; break;
    case HELP_3_MAGIC_OK: os << "HELP_3_MAGIC_OK"; break;
    case HELP_3_ENCHANTMENTS: os << "HELP_3_ENCHANTMENTS"; break;
    case HELP_RELATIONS: os << "HELP_RELATIONS"; break;
    case HELP_WIZARD_STATISTICS_delete: os << "HELP_WIZARD_STATISTICS_delete"; break;
    case HELP_SPELL_CASTING_SKILL: os << "HELP_SPELL_CASTING_SKILL"; break;
    case HELP_MAGIC_RESERVE: os << "HELP_MAGIC_RESERVE"; break;
    case HELP_POWER_BASE: os << "HELP_POWER_BASE"; break;
    case HELP_CASTING_1: os << "HELP_CASTING_1"; break;
    case HELP_RESEARCHING: os << "HELP_RESEARCHING"; break;
    case HELP_SUMMON_TO: os << "HELP_SUMMON_TO"; break;
    case HELP_BARBARIAN_TOWNSFOLK: os << "HELP_BARBARIAN_TOWNSFOLK"; break;
    case HELP_BEASTMEN_TOWNSFOLK: os << "HELP_BEASTMEN_TOWNSFOLK"; break;
    case HELP_DARK_ELF_TOWNSFOLK: os << "HELP_DARK_ELF_TOWNSFOLK"; break;
    case HELP_DRACONIAN_TOWNSFOLK: os << "HELP_DRACONIAN_TOWNSFOLK"; break;
    case HELP_DWARF_TOWNSFOLK: os << "HELP_DWARF_TOWNSFOLK"; break;
    case HELP_GNOLL_TOWNSFOLK: os << "HELP_GNOLL_TOWNSFOLK"; break;
    case HELP_HALFLING_TOWNSFOLK: os << "HELP_HALFLING_TOWNSFOLK"; break;
    case HELP_HIGH_ELF_TOWNSFOLK: os << "HELP_HIGH_ELF_TOWNSFOLK"; break;
    case HELP_HIGH_MEN_TOWNSFOLK: os << "HELP_HIGH_MEN_TOWNSFOLK"; break;
    case HELP_KLACKON_TOWNSFOLK: os << "HELP_KLACKON_TOWNSFOLK"; break;
    case HELP_LIZARDMEN_TOWNSFOLK: os << "HELP_LIZARDMEN_TOWNSFOLK"; break;
    case HELP_NOMAD_TOWNSFOLK: os << "HELP_NOMAD_TOWNSFOLK"; break;
    case HELP_ORC_TOWNSFOLK: os << "HELP_ORC_TOWNSFOLK"; break;
    case HELP_TROLL_TOWNSFOLK: os << "HELP_TROLL_TOWNSFOLK"; break;
    case HELP_3_CITY_NAME: os << "HELP_3_CITY_NAME"; break;
    case HELP_CITY_RESOURCES_delete: os << "HELP_CITY_RESOURCES_delete"; break;
    case HELP_BACKGRND_FOOD: os << "HELP_BACKGRND_FOOD"; break;
    case HELP_BACKGRND_PRODUCTION: os << "HELP_BACKGRND_PRODUCTION"; break;
    case HELP_BACKGRND_GOLD: os << "HELP_BACKGRND_GOLD"; break;
    case HELP_BACKGRND_GOLD_MAINTENANCE: os << "HELP_BACKGRND_GOLD_MAINTENANCE"; break;
    case HELP_BACKGRND_MAGICAL_POWER: os << "HELP_BACKGRND_MAGICAL_POWER"; break;
    case HELP_BACKGRND_SPELL_RESEARCH: os << "HELP_BACKGRND_SPELL_RESEARCH"; break;
    case HELP_4_ENCHANTMENTS: os << "HELP_4_ENCHANTMENTS"; break;
    case HELP_CITY_VIEW: os << "HELP_CITY_VIEW"; break;
    case HELP_4_CITY_SCAPE: os << "HELP_4_CITY_SCAPE"; break;
    case HELP_PRODUCING: os << "HELP_PRODUCING"; break;
    case HELP_BACKGRND_BUY: os << "HELP_BACKGRND_BUY"; break;
    case HELP_BACKGRND_CHANGE: os << "HELP_BACKGRND_CHANGE"; break;
    case HELP_BACKGRND_OK: os << "HELP_BACKGRND_OK"; break;
    case HELP_BACKGRND_Barbarian_Farmers: os << "HELP_BACKGRND_Barbarian_Farmers"; break;
    case HELP_BACKGRND_Barbarian_Workers: os << "HELP_BACKGRND_Barbarian_Workers"; break;
    case HELP_BACKGRND_Barbarian_Rebels: os << "HELP_BACKGRND_Barbarian_Rebels"; break;
    case HELP_BACKGRND_Beastmen_Farmers: os << "HELP_BACKGRND_Beastmen_Farmers"; break;
    case HELP_BACKGRND_Beastmen_Workers: os << "HELP_BACKGRND_Beastmen_Workers"; break;
    case HELP_BACKGRND_Beastmen_Rebels: os << "HELP_BACKGRND_Beastmen_Rebels"; break;
    case HELP_BACKGRND_Dark_Elf_Farmers: os << "HELP_BACKGRND_Dark_Elf_Farmers"; break;
    case HELP_BACKGRND_Dark_Elf_Workers: os << "HELP_BACKGRND_Dark_Elf_Workers"; break;
    case HELP_BACKGRND_Dark_Elf_Rebels: os << "HELP_BACKGRND_Dark_Elf_Rebels"; break;
    case HELP_BACKGRND_Draconian_Farmers: os << "HELP_BACKGRND_Draconian_Farmers"; break;
    case HELP_BACKGRND_Draconian_Workers: os << "HELP_BACKGRND_Draconian_Workers"; break;
    case HELP_BACKGRND_Draconian_Rebels: os << "HELP_BACKGRND_Draconian_Rebels"; break;
    case HELP_BACKGRND_Dwarf_Farmers: os << "HELP_BACKGRND_Dwarf_Farmers"; break;
    case HELP_BACKGRND_Dwarf_Workers: os << "HELP_BACKGRND_Dwarf_Workers"; break;
    case HELP_BACKGRND_Dwarf_Rebels: os << "HELP_BACKGRND_Dwarf_Rebels"; break;
    case HELP_BACKGRND_Gnoll_Farmers: os << "HELP_BACKGRND_Gnoll_Farmers"; break;
    case HELP_BACKGRND_Gnoll_Workers: os << "HELP_BACKGRND_Gnoll_Workers"; break;
    case HELP_BACKGRND_Gnoll_Rebels: os << "HELP_BACKGRND_Gnoll_Rebels"; break;
    case HELP_BACKGRND_Halfling_Farmers: os << "HELP_BACKGRND_Halfling_Farmers"; break;
    case HELP_BACKGRND_Halfling_Workers: os << "HELP_BACKGRND_Halfling_Workers"; break;
    case HELP_BACKGRND_Halfling_Rebels: os << "HELP_BACKGRND_Halfling_Rebels"; break;
    case HELP_BACKGRND_High_Elf_Farmers: os << "HELP_BACKGRND_High_Elf_Farmers"; break;
    case HELP_BACKGRND_High_Elf_Workers: os << "HELP_BACKGRND_High_Elf_Workers"; break;
    case HELP_BACKGRND_High_Elf_Rebels: os << "HELP_BACKGRND_High_Elf_Rebels"; break;
    case HELP_BACKGRND_High_Men_Farmers: os << "HELP_BACKGRND_High_Men_Farmers"; break;
    case HELP_BACKGRND_High_Men_Workers: os << "HELP_BACKGRND_High_Men_Workers"; break;
    case HELP_BACKGRND_High_Men_Rebels: os << "HELP_BACKGRND_High_Men_Rebels"; break;
    case HELP_BACKGRND_Klackon_Farmers: os << "HELP_BACKGRND_Klackon_Farmers"; break;
    case HELP_BACKGRND_Klackon_Workers: os << "HELP_BACKGRND_Klackon_Workers"; break;
    case HELP_BACKGRND_Klackon_Rebels: os << "HELP_BACKGRND_Klackon_Rebels"; break;
    case HELP_BACKGRND_Lizardmen_Farmers: os << "HELP_BACKGRND_Lizardmen_Farmers"; break;
    case HELP_BACKGRND_Lizardmen_Workers: os << "HELP_BACKGRND_Lizardmen_Workers"; break;
    case HELP_BACKGRND_Lizardmen_Rebels: os << "HELP_BACKGRND_Lizardmen_Rebels"; break;
    case HELP_BACKGRND_Nomad_Farmers: os << "HELP_BACKGRND_Nomad_Farmers"; break;
    case HELP_BACKGRND_Nomad_Workers: os << "HELP_BACKGRND_Nomad_Workers"; break;
    case HELP_BACKGRND_Nomad_Rebels: os << "HELP_BACKGRND_Nomad_Rebels"; break;
    case HELP_BACKGRND_Orc_Farmers: os << "HELP_BACKGRND_Orc_Farmers"; break;
    case HELP_BACKGRND_Orc_Workers: os << "HELP_BACKGRND_Orc_Workers"; break;
    case HELP_BACKGRND_Orc_Rebels: os << "HELP_BACKGRND_Orc_Rebels"; break;
    case HELP_BACKGRND_Troll_Farmers: os << "HELP_BACKGRND_Troll_Farmers"; break;
    case HELP_BACKGRND_Troll_Workers: os << "HELP_BACKGRND_Troll_Workers"; break;
    case HELP_BACKGRND_Troll_Rebels: os << "HELP_BACKGRND_Troll_Rebels"; break;
    case HELP_PORTRAIT: os << "HELP_PORTRAIT"; break;
    case HELP_NAME: os << "HELP_NAME"; break;
    case HELP_STATISTICS: os << "HELP_STATISTICS"; break;
    case HELP_GOLD: os << "HELP_GOLD"; break;
    case HELP_MANA_1: os << "HELP_MANA_1"; break;
    case HELP_SPELL_RANKS: os << "HELP_SPELL_RANKS"; break;
    case HELP_SPECIAL_ABILITIES: os << "HELP_SPECIAL_ABILITIES"; break;
    case HELP_HEROES: os << "HELP_HEROES"; break;
    case HELP_PLANE: os << "HELP_PLANE"; break;
    case HELP_MAP: os << "HELP_MAP"; break;
    case HELP_CLOSE: os << "HELP_CLOSE"; break;
    case HELP_CHANGE_PLANES: os << "HELP_CHANGE_PLANES"; break;
    case HELP_MAP_KEY: os << "HELP_MAP_KEY"; break;
    case HELP_POWER_GRAPH: os << "HELP_POWER_GRAPH"; break;
    case HELP_STATUS: os << "HELP_STATUS"; break;
    case HELP_MAGIC_POWER: os << "HELP_MAGIC_POWER"; break;
    case HELP_SPELL_RESEARCH: os << "HELP_SPELL_RESEARCH"; break;
    case HELP_ARMY_STRENGTH: os << "HELP_ARMY_STRENGTH"; break;
    case HELP_ALCHEMY_GOLD: os << "HELP_ALCHEMY_GOLD"; break;
    case HELP_MAGIC_ALCHEMY_RATIO: os << "HELP_MAGIC_ALCHEMY_RATIO"; break;
    case HELP_ALCHEMY_POWER: os << "HELP_ALCHEMY_POWER"; break;
    case HELP_MAGIC_CANCEL: os << "HELP_MAGIC_CANCEL"; break;
    case HELP_MAGIC_ALCHEMY_TOGGLE: os << "HELP_MAGIC_ALCHEMY_TOGGLE"; break;
    case HELP_4_MAGIC_OK: os << "HELP_4_MAGIC_OK"; break;
    case HELP_BUILDING_OPTIONS: os << "HELP_BUILDING_OPTIONS"; break;
    case HELP_UNIT_OPTIONS: os << "HELP_UNIT_OPTIONS"; break;
    case HELP_1_CANCEL: os << "HELP_1_CANCEL"; break;
    case HELP_1_OK: os << "HELP_1_OK"; break;
    case HELP_BUILDING_DESCRIPTION: os << "HELP_BUILDING_DESCRIPTION"; break;
    case HELP_ALLOWS: os << "HELP_ALLOWS"; break;
    case HELP_MAINTENANCE: os << "HELP_MAINTENANCE"; break;
    case HELP_COST: os << "HELP_COST"; break;
    case HELP_UNIT_MOVES: os << "HELP_UNIT_MOVES"; break;
    case HELP_MELEE: os << "HELP_MELEE"; break;
    case HELP_UNITVIEW_Sword: os << "HELP_UNITVIEW_Sword"; break;
    case HELP_UNITVIEW_Magic_Weapon: os << "HELP_UNITVIEW_Magic_Weapon"; break;
    case HELP_UNITVIEW_Mithril_Weapon: os << "HELP_UNITVIEW_Mithril_Weapon"; break;
    case HELP_RANGE_1: os << "HELP_RANGE_1"; break;
    case HELP_UNITVIEW_THROWN_delete: os << "HELP_UNITVIEW_THROWN_delete"; break;
    case HELP_UNITVIEW_Bow: os << "HELP_UNITVIEW_Bow"; break;
    case HELP_UNITVIEW_Rock: os << "HELP_UNITVIEW_Rock"; break;
    case HELP_UNITVIEW_Magical_Attack: os << "HELP_UNITVIEW_Magical_Attack"; break;
    case HELP_UNITVIEW_MAGICAL_BREATH_delete: os << "HELP_UNITVIEW_MAGICAL_BREATH_delete"; break;
    case HELP_UNITVIEW_ARMOR: os << "HELP_UNITVIEW_ARMOR"; break;
    case HELP_UNITVIEW_RESISTANCE: os << "HELP_UNITVIEW_RESISTANCE"; break;
    case HELP_UNITVIEW_HITS: os << "HELP_UNITVIEW_HITS"; break;
    case HELP_SPECIAL_LARGE_SHIELD: os << "HELP_SPECIAL_LARGE_SHIELD"; break;
    case HELP_SPECIAL_PLANE_SHIFT: os << "HELP_SPECIAL_PLANE_SHIFT"; break;
    case HELP_SPECIAL_WALL_CRUSHER: os << "HELP_SPECIAL_WALL_CRUSHER"; break;
    case HELP_SPECIAL_HEALER: os << "HELP_SPECIAL_HEALER"; break;
    case HELP_SPECIAL_CREATE_OUTPOST: os << "HELP_SPECIAL_CREATE_OUTPOST"; break;
    case HELP_SPECIAL_INVISIBILITY_1: os << "HELP_SPECIAL_INVISIBILITY_1"; break;
    case HELP_SPECIAL_CREATE_UNDEAD: os << "HELP_SPECIAL_CREATE_UNDEAD"; break;
    case HELP_SPECIAL2_LONG_RANGE: os << "HELP_SPECIAL2_LONG_RANGE"; break;
    case HELP_SPECIAL_LAND_CORRUPTION: os << "HELP_SPECIAL_LAND_CORRUPTION"; break;
    case HELP_SPECIAL_MELD_WITH_NODE: os << "HELP_SPECIAL_MELD_WITH_NODE"; break;
    case HELP_SPECIAL_NON_CORPOREAL: os << "HELP_SPECIAL_NON_CORPOREAL"; break;
    case HELP_SPECIAL_WIND_WALKING_1: os << "HELP_SPECIAL_WIND_WALKING_1"; break;
    case HELP_SPECIAL_REGENERATION: os << "HELP_SPECIAL_REGENERATION"; break;
    case HELP_SPECIAL_PURIFY: os << "HELP_SPECIAL_PURIFY"; break;
    case HELP_SPECIAL2_LUCKY: os << "HELP_SPECIAL2_LUCKY"; break;
    case HELP_SPECIAL_POISON_IMMUNITY: os << "HELP_SPECIAL_POISON_IMMUNITY"; break;
    case HELP_SPECIAL_FIRE_IMMUNITY: os << "HELP_SPECIAL_FIRE_IMMUNITY"; break;
    case HELP_SPECIAL_STONING_IMMUNITY: os << "HELP_SPECIAL_STONING_IMMUNITY"; break;
    case HELP_SPECIAL_WEAPON_IMMUNITY: os << "HELP_SPECIAL_WEAPON_IMMUNITY"; break;
    case HELP_SPECIAL_MISSILES_IMMUNITY: os << "HELP_SPECIAL_MISSILES_IMMUNITY"; break;
    case HELP_SPECIAL_ILLUSIONS_IMMUNITY: os << "HELP_SPECIAL_ILLUSIONS_IMMUNITY"; break;
    case HELP_SPECIAL_COLD_IMMUNITY: os << "HELP_SPECIAL_COLD_IMMUNITY"; break;
    case HELP_SPECIAL_MAGIC_IMMUNITY_1: os << "HELP_SPECIAL_MAGIC_IMMUNITY_1"; break;
    case HELP_SPECIAL_DEATH_IMMUNITY: os << "HELP_SPECIAL_DEATH_IMMUNITY"; break;
    case HELP_SPECIAL_HEALING_SPELL: os << "HELP_SPECIAL_HEALING_SPELL"; break;
    case HELP_SPECIAL_FIRE_BALL_SPELL: os << "HELP_SPECIAL_FIRE_BALL_SPELL"; break;
    case HELP_SPECIAL_DOOMBOLT_SPELL: os << "HELP_SPECIAL_DOOMBOLT_SPELL"; break;
    case HELP_SPECIAL_IMMOLATION: os << "HELP_SPECIAL_IMMOLATION"; break;
    case HELP_SPECIAL2_CAUSE_FEAR_SPELL: os << "HELP_SPECIAL2_CAUSE_FEAR_SPELL"; break;
    case HELP_SPECIAL2_WEB_SPELL: os << "HELP_SPECIAL2_WEB_SPELL"; break;
    case HELP_SPECIAL_RESISTANCE_TO_ALL: os << "HELP_SPECIAL_RESISTANCE_TO_ALL"; break;
    case HELP_SPECIAL_HOLY_BONUS: os << "HELP_SPECIAL_HOLY_BONUS"; break;
    case HELP_SPECIAL_ARMOR_PIERCING: os << "HELP_SPECIAL_ARMOR_PIERCING"; break;
    case HELP_SPECIAL_POISON: os << "HELP_SPECIAL_POISON"; break;
    case HELP_SPECIAL_LIFE_STEAL: os << "HELP_SPECIAL_LIFE_STEAL"; break;
    case HELP_SPECIAL2_CHAOS: os << "HELP_SPECIAL2_CHAOS"; break;
    case HELP_SPECIAL2_DESTRUCTION: os << "HELP_SPECIAL2_DESTRUCTION"; break;
    case HELP_SPECIAL_ILLUSION: os << "HELP_SPECIAL_ILLUSION"; break;
    case HELP_SPECIAL_STONING_TOUCH: os << "HELP_SPECIAL_STONING_TOUCH"; break;
    case HELP_SPECIAL2_CAUSE_DEATH: os << "HELP_SPECIAL2_CAUSE_DEATH"; break;
    case HELP_SPECIAL2_POWER_DRAIN: os << "HELP_SPECIAL2_POWER_DRAIN"; break;
    case HELP_SPECIAL2_DISPEL_EVIL: os << "HELP_SPECIAL2_DISPEL_EVIL"; break;
    case HELP_SPECIAL_CHAOS_CHANNEL_1: os << "HELP_SPECIAL_CHAOS_CHANNEL_1"; break;
    case HELP_SPECIAL_CHAOS_CHANNEL_2: os << "HELP_SPECIAL_CHAOS_CHANNEL_2"; break;
    case HELP_SPECIAL_CHAOS_CHANNEL_3: os << "HELP_SPECIAL_CHAOS_CHANNEL_3"; break;
    case HELP_SPECIAL2_THROWN: os << "HELP_SPECIAL2_THROWN"; break;
    case HELP_SPECIAL2_FIRE_BREATH: os << "HELP_SPECIAL2_FIRE_BREATH"; break;
    case HELP_SPECIAL2_LIGHTNING_BREATH: os << "HELP_SPECIAL2_LIGHTNING_BREATH"; break;
    case HELP_SPECIAL_STONING_GAZE: os << "HELP_SPECIAL_STONING_GAZE"; break;
    case HELP_SPECIAL2_DOOM_GAZE: os << "HELP_SPECIAL2_DOOM_GAZE"; break;
    case HELP_SPECIAL2_DEATH_GAZE: os << "HELP_SPECIAL2_DEATH_GAZE"; break;
    case HELP_SPECIAL2_IMMOLATION: os << "HELP_SPECIAL2_IMMOLATION"; break;
    case HELP_SPECIAL2_GUARDIAN_WIND: os << "HELP_SPECIAL2_GUARDIAN_WIND"; break;
    case HELP_SPECIAL2_BERSERK: os << "HELP_SPECIAL2_BERSERK"; break;
    case HELP_SPECIAL_CLOAK_OF_FEAR: os << "HELP_SPECIAL_CLOAK_OF_FEAR"; break;
    case HELP_SPECIAL_BLACK_CHANNELS: os << "HELP_SPECIAL_BLACK_CHANNELS"; break;
    case HELP_SPECIAL_WRAITH_FORM: os << "HELP_SPECIAL_WRAITH_FORM"; break;
    case HELP_SPECIAL_REGENERATE: os << "HELP_SPECIAL_REGENERATE"; break;
    case HELP_SPECIAL_PATHFINDING_1: os << "HELP_SPECIAL_PATHFINDING_1"; break;
    case HELP_SPECIAL_WATER_WALKING: os << "HELP_SPECIAL_WATER_WALKING"; break;
    case HELP_SPECIAL_ELEMENTAL_ARMOR: os << "HELP_SPECIAL_ELEMENTAL_ARMOR"; break;
    case HELP_SPECIAL_RESIST_ELEMENTS: os << "HELP_SPECIAL_RESIST_ELEMENTS"; break;
    case HELP_SPECIAL_STONE_SKIN: os << "HELP_SPECIAL_STONE_SKIN"; break;
    case HELP_SPECIAL_IRON_SKIN: os << "HELP_SPECIAL_IRON_SKIN"; break;
    case HELP_SPECIAL_ENDURANCE: os << "HELP_SPECIAL_ENDURANCE"; break;
    case HELP_SPECIAL2_SPELL_LOCK: os << "HELP_SPECIAL2_SPELL_LOCK"; break;
    case HELP_SPECIAL_INVISIBILITY_2: os << "HELP_SPECIAL_INVISIBILITY_2"; break;
    case HELP_SPECIAL_WIND_WALKING_2: os << "HELP_SPECIAL_WIND_WALKING_2"; break;
    case HELP_SPECIAL_FLIGHT: os << "HELP_SPECIAL_FLIGHT"; break;
    case HELP_SPECIAL_RESIST_MAGIC: os << "HELP_SPECIAL_RESIST_MAGIC"; break;
    case HELP_SPECIAL_MAGIC_IMMUNITY_2: os << "HELP_SPECIAL_MAGIC_IMMUNITY_2"; break;
    case HELP_SPECIAL_FLAME_BLADE: os << "HELP_SPECIAL_FLAME_BLADE"; break;
    case HELP_SPECIAL_ELDRITCH_WEAPON: os << "HELP_SPECIAL_ELDRITCH_WEAPON"; break;
    case HELP_SPECIAL_TRUE_SIGHT: os << "HELP_SPECIAL_TRUE_SIGHT"; break;
    case HELP_SPECIAL_HOLY_WEAPON: os << "HELP_SPECIAL_HOLY_WEAPON"; break;
    case HELP_SPECIAL_HEROISM: os << "HELP_SPECIAL_HEROISM"; break;
    case HELP_SPECIAL_BLESS: os << "HELP_SPECIAL_BLESS"; break;
    case HELP_SPECIAL_LION_HEART: os << "HELP_SPECIAL_LION_HEART"; break;
    case HELP_SPECIAL_GIANT_STRENGTH: os << "HELP_SPECIAL_GIANT_STRENGTH"; break;
    case HELP_SPECIAL_PLANAR_TRAVEL: os << "HELP_SPECIAL_PLANAR_TRAVEL"; break;
    case HELP_SPECIAL_HOLY_ARMOR: os << "HELP_SPECIAL_HOLY_ARMOR"; break;
    case HELP_SPECIAL_RIGHTEOUSNESS: os << "HELP_SPECIAL_RIGHTEOUSNESS"; break;
    case HELP_SPECIAL_INVULNERABILITY: os << "HELP_SPECIAL_INVULNERABILITY"; break;
    case HELP_SPECIAL_VERTIGO: os << "HELP_SPECIAL_VERTIGO"; break;
    case HELP_SPECIAL2_CONFUSION: os << "HELP_SPECIAL2_CONFUSION"; break;
    case HELP_SPECIAL2_WHIRLWIND: os << "HELP_SPECIAL2_WHIRLWIND"; break;
    case HELP_SPECIAL2_MIND_STORM: os << "HELP_SPECIAL2_MIND_STORM"; break;
    case HELP_SPECIAL_SHATTER: os << "HELP_SPECIAL_SHATTER"; break;
    case HELP_SPECIAL_WEAKNESS: os << "HELP_SPECIAL_WEAKNESS"; break;
    case HELP_SPECIAL2_BLACK_SLEEP: os << "HELP_SPECIAL2_BLACK_SLEEP"; break;
    case HELP_SPECIAL2_WARP_CREATURE_1: os << "HELP_SPECIAL2_WARP_CREATURE_1"; break;
    case HELP_SPECIAL2_WARP_CREATURE_2: os << "HELP_SPECIAL2_WARP_CREATURE_2"; break;
    case HELP_SPECIAL2_WARP_CREATURE_3: os << "HELP_SPECIAL2_WARP_CREATURE_3"; break;
    case HELP_SPECIAL2_MANA_LEAK: os << "HELP_SPECIAL2_MANA_LEAK"; break;
    case HELP_SPECIAL_HASTE: os << "HELP_SPECIAL_HASTE"; break;
    case HELP_SPECIAL_WEB: os << "HELP_SPECIAL_WEB"; break;
    case HELP_SPECIAL_CREATURE_BINDING: os << "HELP_SPECIAL_CREATURE_BINDING"; break;
    case HELP_SPECIAL_POSSESSION: os << "HELP_SPECIAL_POSSESSION"; break;
    case HELP_2_UPKEEP: os << "HELP_2_UPKEEP"; break;
    case HELP_UNITVIEW_PAGE_UP: os << "HELP_UNITVIEW_PAGE_UP"; break;
    case HELP_UNITVIEW_PAGE_DOWN: os << "HELP_UNITVIEW_PAGE_DOWN"; break;
    case HELP_DISMISS: os << "HELP_DISMISS"; break;
    case HELP_2_OK: os << "HELP_2_OK"; break;
    case HELP_2_CITY_SCAPE: os << "HELP_2_CITY_SCAPE"; break;
    case HELP_CITY_GARRISONS: os << "HELP_CITY_GARRISONS"; break;
    case HELP_UNIT_LIST: os << "HELP_UNIT_LIST"; break;
    case HELP_BACKGRND_OUTPOST_SIZE_1: os << "HELP_BACKGRND_OUTPOST_SIZE_1"; break;
    case HELP_BACKGRND_OUTPOST_SIZE_2: os << "HELP_BACKGRND_OUTPOST_SIZE_2"; break;
    case HELP_BACKGRND_OUTPOST_SIZE_3: os << "HELP_BACKGRND_OUTPOST_SIZE_3"; break;
    case HELP_OUTPOST_SCAPE: os << "HELP_OUTPOST_SCAPE"; break;
    case HELP_MAIN_CANCEL_1: os << "HELP_MAIN_CANCEL_1"; break;
    case HELP_CASTING_2: os << "HELP_CASTING_2"; break;
    case HELP_ROAD_BUILDING: os << "HELP_ROAD_BUILDING"; break;
    case HELP_MAIN_OK: os << "HELP_MAIN_OK"; break;
    case HELP_MAIN_CANCEL_2: os << "HELP_MAIN_CANCEL_2"; break;
    case HELP_SURVEY: os << "HELP_SURVEY"; break;
    case HELP_MAIN_CANCEL_3: os << "HELP_MAIN_CANCEL_3"; break;
    case HELP_hero_SPECIAL_LEADERSHIP: os << "HELP_hero_SPECIAL_LEADERSHIP"; break;
    case HELP_hero_SPECIAL_LEGENDARY: os << "HELP_hero_SPECIAL_LEGENDARY"; break;
    case HELP_hero_SPECIAL_BLADEMASTER: os << "HELP_hero_SPECIAL_BLADEMASTER"; break;
    case HELP_hero_SPECIAL_ARMSMASTER: os << "HELP_hero_SPECIAL_ARMSMASTER"; break;
    case HELP_hero_SPECIAL_CONSTITUTION: os << "HELP_hero_SPECIAL_CONSTITUTION"; break;
    case HELP_hero_SPECIAL_MIGHT: os << "HELP_hero_SPECIAL_MIGHT"; break;
    case HELP_hero_SPECIAL_ARCANE_POWER: os << "HELP_hero_SPECIAL_ARCANE_POWER"; break;
    case HELP_hero_SPECIAL_SAGE: os << "HELP_hero_SPECIAL_SAGE"; break;
    case HELP_hero_SPECIAL_PRAYERMASTER: os << "HELP_hero_SPECIAL_PRAYERMASTER"; break;
    case HELP_hero_SPECIAL_LUCKY: os << "HELP_hero_SPECIAL_LUCKY"; break;
    case HELP_hero_SPECIAL_CHARMED: os << "HELP_hero_SPECIAL_CHARMED"; break;
    case HELP_hero_SPECIAL_NOBLE: os << "HELP_hero_SPECIAL_NOBLE"; break;
    case HELP_unit_SPECIAL_RECRUIT: os << "HELP_unit_SPECIAL_RECRUIT"; break;
    case HELP_unit_SPECIAL_REGULAR: os << "HELP_unit_SPECIAL_REGULAR"; break;
    case HELP_unit_SPECIAL_VETERAN: os << "HELP_unit_SPECIAL_VETERAN"; break;
    case HELP_unit_SPECIAL_ELITE: os << "HELP_unit_SPECIAL_ELITE"; break;
    case HELP_unit_SPECIAL_ULTRA_ELITE: os << "HELP_unit_SPECIAL_ULTRA_ELITE"; break;
    case HELP_unit_SPECIAL_CHAMPION: os << "HELP_unit_SPECIAL_CHAMPION"; break;
    case HELP_hero_SPECIAL_HERO: os << "HELP_hero_SPECIAL_HERO"; break;
    case HELP_hero_SPECIAL_MYRMIDON: os << "HELP_hero_SPECIAL_MYRMIDON"; break;
    case HELP_hero_SPECIAL_CAPTAIN: os << "HELP_hero_SPECIAL_CAPTAIN"; break;
    case HELP_hero_SPECIAL_COMMANDER: os << "HELP_hero_SPECIAL_COMMANDER"; break;
    case HELP_hero_SPECIAL_CHAMPION: os << "HELP_hero_SPECIAL_CHAMPION"; break;
    case HELP_hero_SPECIAL_LORD: os << "HELP_hero_SPECIAL_LORD"; break;
    case HELP_hero_SPECIAL_GRAND_LORD: os << "HELP_hero_SPECIAL_GRAND_LORD"; break;
    case HELP_hero_SPECIAL_SUPER_HERO: os << "HELP_hero_SPECIAL_SUPER_HERO"; break;
    case HELP_hero_SPECIAL_DEMI_GOD: os << "HELP_hero_SPECIAL_DEMI_GOD"; break;
    case HELP_SPECIAL2_QUIVER: os << "HELP_SPECIAL2_QUIVER"; break;
    case HELP_SPECIAL2_PLUS_TO_HIT: os << "HELP_SPECIAL2_PLUS_TO_HIT"; break;
    case HELP_SPECIAL2_MIN_TO_HIT: os << "HELP_SPECIAL2_MIN_TO_HIT"; break;
    case HELP_SPECIAL_CONSTRUCTION: os << "HELP_SPECIAL_CONSTRUCTION"; break;
    case HELP_SPECIAL_SCOUTING: os << "HELP_SPECIAL_SCOUTING"; break;
    case HELP_ITEMISC_MERGING_1: os << "HELP_ITEMISC_MERGING_1"; break;
    case HELP_SPECIAL_TELEPORTING: os << "HELP_SPECIAL_TELEPORTING"; break;
    case HELP_SPECIAL_PATHFINDING_2: os << "HELP_SPECIAL_PATHFINDING_2"; break;
    case HELP_SPECIAL_MOUNTAINEER: os << "HELP_SPECIAL_MOUNTAINEER"; break;
    case HELP_SPECIAL_FORESTER: os << "HELP_SPECIAL_FORESTER"; break;
    case HELP_SPECIAL2_SUMMON_DEMONS: os << "HELP_SPECIAL2_SUMMON_DEMONS"; break;
    case HELP_SPECIAL2_UNDEAD: os << "HELP_SPECIAL2_UNDEAD"; break;
    case HELP_SPECIAL2_STASIS: os << "HELP_SPECIAL2_STASIS"; break;
    case HELP_SPECIAL_CASTER: os << "HELP_SPECIAL_CASTER"; break;
    case HELP_ITEMISC_MAGIC_IMMUNITY: os << "HELP_ITEMISC_MAGIC_IMMUNITY"; break;
    case HELP_ITEMISC_REGENERATE: os << "HELP_ITEMISC_REGENERATE"; break;
    case HELP_ITEMISC_HASTE: os << "HELP_ITEMISC_HASTE"; break;
    case HELP_ITEMISC_TRUE_SIGHT: os << "HELP_ITEMISC_TRUE_SIGHT"; break;
    case HELP_ITEMISC_PATH_FINDING: os << "HELP_ITEMISC_PATH_FINDING"; break;
    case HELP_ITEMISC_WATER_WALKING: os << "HELP_ITEMISC_WATER_WALKING"; break;
    case HELP_ITEMISC_BLESS: os << "HELP_ITEMISC_BLESS"; break;
    case HELP_ITEMISC_LION_HEART: os << "HELP_ITEMISC_LION_HEART"; break;
    case HELP_ITEMISC_INVISIBILITY: os << "HELP_ITEMISC_INVISIBILITY"; break;
    case HELP_ITEMISC_PLANAR_TRAVEL: os << "HELP_ITEMISC_PLANAR_TRAVEL"; break;
    case HELP_ITEMISC_ENDURANCE: os << "HELP_ITEMISC_ENDURANCE"; break;
    case HELP_ITEMISC_RIGHTEOUSNESS: os << "HELP_ITEMISC_RIGHTEOUSNESS"; break;
    case HELP_ITEMISC_INVULNERABILITY: os << "HELP_ITEMISC_INVULNERABILITY"; break;
    case HELP_ITEMISC_RESIST_ELEMENTS: os << "HELP_ITEMISC_RESIST_ELEMENTS"; break;
    case HELP_ITEMISC_ELEMENTAL_ARMOR: os << "HELP_ITEMISC_ELEMENTAL_ARMOR"; break;
    case HELP_ITEMISC_CLOAK_OF_FEAR: os << "HELP_ITEMISC_CLOAK_OF_FEAR"; break;
    case HELP_ITEMISC_FLIGHT: os << "HELP_ITEMISC_FLIGHT"; break;
    case HELP_ITEMISC_RESIST_MAGIC: os << "HELP_ITEMISC_RESIST_MAGIC"; break;
    case HELP_ITEMISC_GUARDIAN_WIND: os << "HELP_ITEMISC_GUARDIAN_WIND"; break;
    case HELP_ITEMISC_GIANT_STRENGTH: os << "HELP_ITEMISC_GIANT_STRENGTH"; break;
    case HELP_ITEMISC_MERGING_2: os << "HELP_ITEMISC_MERGING_2"; break;
    case HELP_ITEMISC_SWORD_SLOT_1: os << "HELP_ITEMISC_SWORD_SLOT_1"; break;
    case HELP_ITEMISC_BOW_SLOT_1: os << "HELP_ITEMISC_BOW_SLOT_1"; break;
    case HELP_ITEMISC_STAVE_SWORD_SLOT_1: os << "HELP_ITEMISC_STAVE_SWORD_SLOT_1"; break;
    case HELP_ITEMISC_STAVE_SLOT_1: os << "HELP_ITEMISC_STAVE_SLOT_1"; break;
    case HELP_ITEMISC_ARMOR_SLOT_1: os << "HELP_ITEMISC_ARMOR_SLOT_1"; break;
    case HELP_ITEMISC_MISCELLANEOUS_SLOT_1: os << "HELP_ITEMISC_MISCELLANEOUS_SLOT_1"; break;
    case HELP_ITEMISC_SWORD_SLOT_2: os << "HELP_ITEMISC_SWORD_SLOT_2"; break;
    case HELP_ITEMISC_BOW_SLOT_2: os << "HELP_ITEMISC_BOW_SLOT_2"; break;
    case HELP_ITEMISC_STAVE_SWORD_SLOT_2: os << "HELP_ITEMISC_STAVE_SWORD_SLOT_2"; break;
    case HELP_ITEMISC_STAVE_SLOT_2: os << "HELP_ITEMISC_STAVE_SLOT_2"; break;
    case HELP_ITEMISC_ARMOR_SLOT_2: os << "HELP_ITEMISC_ARMOR_SLOT_2"; break;
    case HELP_ITEMISC_MISCELLANEOUS_SLOT_2: os << "HELP_ITEMISC_MISCELLANEOUS_SLOT_2"; break;
    case HELP_COMPIX_SPELL_BUTTON: os << "HELP_COMPIX_SPELL_BUTTON"; break;
    case HELP_COMPIX_WAIT_BUTTON: os << "HELP_COMPIX_WAIT_BUTTON"; break;
    case HELP_COMPIX_INFO_BUTTON: os << "HELP_COMPIX_INFO_BUTTON"; break;
    case HELP_COMPIX_AUTO_BUTTON: os << "HELP_COMPIX_AUTO_BUTTON"; break;
    case HELP_COMPIX_FLEE_BUTTON: os << "HELP_COMPIX_FLEE_BUTTON"; break;
    case HELP_COMPIX_DONE_BUTTON: os << "HELP_COMPIX_DONE_BUTTON"; break;
    case HELP_SKILL: os << "HELP_SKILL"; break;
    case HELP_MANA_2: os << "HELP_MANA_2"; break;
    case HELP_RANGE_2: os << "HELP_RANGE_2"; break;
    case HELP_ATTACKER: os << "HELP_ATTACKER"; break;
    case HELP_DEFENDER: os << "HELP_DEFENDER"; break;
    case HELP_combat_COMPIX_LIGHT: os << "HELP_combat_COMPIX_LIGHT"; break;
    case HELP_combat_COMPIX_DARKNESS: os << "HELP_combat_COMPIX_DARKNESS"; break;
    case HELP_combat_COMPIX_WARP_REALITY: os << "HELP_combat_COMPIX_WARP_REALITY"; break;
    case HELP_combat_COMPIX_BLACK_PRAYER: os << "HELP_combat_COMPIX_BLACK_PRAYER"; break;
    case HELP_combat_COMPIX_WRACK: os << "HELP_combat_COMPIX_WRACK"; break;
    case HELP_combat_COMPIX_METAL_FIRES: os << "HELP_combat_COMPIX_METAL_FIRES"; break;
    case HELP_combat_COMPIX_PRAYER: os << "HELP_combat_COMPIX_PRAYER"; break;
    case HELP_combat_COMPIX_HIGH_PRAYER: os << "HELP_combat_COMPIX_HIGH_PRAYER"; break;
    case HELP_combat_COMPIX_TERROR: os << "HELP_combat_COMPIX_TERROR"; break;
    case HELP_combat_COMPIX_CALL_LIGHTNING: os << "HELP_combat_COMPIX_CALL_LIGHTNING"; break;
    case HELP_combat_COMPIX_COUNTER_MAGIC: os << "HELP_combat_COMPIX_COUNTER_MAGIC"; break;
    case HELP_combat_COMPIX_MASS_INVISIBILITY: os << "HELP_combat_COMPIX_MASS_INVISIBILITY"; break;
    case HELP_combat_COMPIX_DISPELS_NON_SORCERY: os << "HELP_combat_COMPIX_DISPELS_NON_SORCERY"; break;
    case HELP_combat_COMPIX_DISPELS_NON_CHAOS: os << "HELP_combat_COMPIX_DISPELS_NON_CHAOS"; break;
    case HELP_combat_COMPIX_DISPELS_NON_NATURE: os << "HELP_combat_COMPIX_DISPELS_NON_NATURE"; break;
    case HELP_combat_COMPIX_SORCERY_NODE_AURA: os << "HELP_combat_COMPIX_SORCERY_NODE_AURA"; break;
    case HELP_combat_COMPIX_CHAOS_NODE_AURA: os << "HELP_combat_COMPIX_CHAOS_NODE_AURA"; break;
    case HELP_combat_COMPIX_NATURE_NODE_AURA: os << "HELP_combat_COMPIX_NATURE_NODE_AURA"; break;
    case HELP_combat_COMPIX_CLOUD_OF_DARKNESS: os << "HELP_combat_COMPIX_CLOUD_OF_DARKNESS"; break;
    case HELP_combat_COMPIX_HOLY_LIGHT: os << "HELP_combat_COMPIX_HOLY_LIGHT"; break;
    case HELP_combat_COMPIX_CHAOS_SURGE: os << "HELP_combat_COMPIX_CHAOS_SURGE"; break;
    case HELP_combat_COMPIX_ETERNAL_NIGHT: os << "HELP_combat_COMPIX_ETERNAL_NIGHT"; break;
    case HELP_combat_COMPIX_CRUSADE: os << "HELP_combat_COMPIX_CRUSADE"; break;
    case HELP_combat_COMPIX_HOLY_ARMS: os << "HELP_combat_COMPIX_HOLY_ARMS"; break;
    case HELP_combat_COMPIX_CHARM_OF_LIFE: os << "HELP_combat_COMPIX_CHARM_OF_LIFE"; break;
    case HELP_combat_COMPIX_ZOMBIE_MASTERY: os << "HELP_combat_COMPIX_ZOMBIE_MASTERY"; break;
    case HELP_DAMAGE: os << "HELP_DAMAGE"; break;
    case HELP_hero_SPECIAL2_AGILE: os << "HELP_hero_SPECIAL2_AGILE"; break;
    case HELP_CONTINUE: os << "HELP_CONTINUE"; break;
    case HELP_LOAD: os << "HELP_LOAD"; break;
    case HELP_NEW_GAME: os << "HELP_NEW_GAME"; break;
    case HELP_QUIT_TO_DOS: os << "HELP_QUIT_TO_DOS"; break;
    case HELP_COMPIX_ENTANGLE: os << "HELP_COMPIX_ENTANGLE"; break;
    case HELP_LOAD_LOAD_BUTTON: os << "HELP_LOAD_LOAD_BUTTON"; break;
    case HELP_LOAD_QUIT_BUTTON: os << "HELP_LOAD_QUIT_BUTTON"; break;
    case HELP_LOAD_SETTINGS_BUTTON: os << "HELP_LOAD_SETTINGS_BUTTON"; break;
    case HELP_LOAD_SAVE_BUTTON: os << "HELP_LOAD_SAVE_BUTTON"; break;
    case HELP_LOAD_OK_BUTTON: os << "HELP_LOAD_OK_BUTTON"; break;
    case HELP_SAVED_GAMES_1: os << "HELP_SAVED_GAMES_1"; break;
    case HELP_SAVED_GAMES_2: os << "HELP_SAVED_GAMES_2"; break;
    case HELP_setup_NEWGAME_OK_BUTTON: os << "HELP_setup_NEWGAME_OK_BUTTON"; break;
    case HELP_NEWGAME_CANCEL_BUTTON: os << "HELP_NEWGAME_CANCEL_BUTTON"; break;
    case HELP_DIFFICULTY_LEVEL: os << "HELP_DIFFICULTY_LEVEL"; break;
    case HELP_difficulty_INTRO: os << "HELP_difficulty_INTRO"; break;
    case HELP_difficulty_EASY: os << "HELP_difficulty_EASY"; break;
    case HELP_difficulty_NORMAL: os << "HELP_difficulty_NORMAL"; break;
    case HELP_difficulty_HARD: os << "HELP_difficulty_HARD"; break;
    case HELP_difficulty_IMPOSSIBLE: os << "HELP_difficulty_IMPOSSIBLE"; break;
    case HELP_OPPONENTS: os << "HELP_OPPONENTS"; break;
    case HELP_LAND_SIZE: os << "HELP_LAND_SIZE"; break;
    case HELP_land_SMALL: os << "HELP_land_SMALL"; break;
    case HELP_land_MEDIUM: os << "HELP_land_MEDIUM"; break;
    case HELP_land_LARGE: os << "HELP_land_LARGE"; break;
    case HELP_MAGIC_INTENSITY: os << "HELP_MAGIC_INTENSITY"; break;
    case HELP_nodes_WEAK: os << "HELP_nodes_WEAK"; break;
    case HELP_nodes_NORMAL: os << "HELP_nodes_NORMAL"; break;
    case HELP_nodes_POWERFUL: os << "HELP_nodes_POWERFUL"; break;
    case HELP_SPELL_OF_RETURN: os << "HELP_SPELL_OF_RETURN"; break;
    case HELP_SELECT_A_BANNER: os << "HELP_SELECT_A_BANNER"; break;
    case HELP_MERLIN: os << "HELP_MERLIN"; break;
    case HELP_RAVEN: os << "HELP_RAVEN"; break;
    case HELP_SHAREE: os << "HELP_SHAREE"; break;
    case HELP_LO_PAN: os << "HELP_LO_PAN"; break;
    case HELP_JAFAR: os << "HELP_JAFAR"; break;
    case HELP_OBERIC: os << "HELP_OBERIC"; break;
    case HELP_TAURON: os << "HELP_TAURON"; break;
    case HELP_SSSRA: os << "HELP_SSSRA"; break;
    case HELP_RJAK: os << "HELP_RJAK"; break;
    case HELP_FREYA: os << "HELP_FREYA"; break;
    case HELP_HORUS: os << "HELP_HORUS"; break;
    case HELP_ARIEL: os << "HELP_ARIEL"; break;
    case HELP_TLALOC: os << "HELP_TLALOC"; break;
    case HELP_KALI: os << "HELP_KALI"; break;
    case HELP_CUSTOM: os << "HELP_CUSTOM"; break;
    case HELP_SELECT_WIZARD_PICTURE: os << "HELP_SELECT_WIZARD_PICTURE"; break;
    case HELP_SOUND_EFFECTS: os << "HELP_SOUND_EFFECTS"; break;
    case HELP_BACKGROUND_MUSIC: os << "HELP_BACKGROUND_MUSIC"; break;
    case HELP_EVENT_MUSIC: os << "HELP_EVENT_MUSIC"; break;
    case HELP_CITY_SPELL_EVENTS: os << "HELP_CITY_SPELL_EVENTS"; break;
    case HELP_OVERLAND_SPELL_EVENTS: os << "HELP_OVERLAND_SPELL_EVENTS"; break;
    case HELP_SUMMONING_EVENTS: os << "HELP_SUMMONING_EVENTS"; break;
    case HELP_END_OF_TURN_SUMMARY: os << "HELP_END_OF_TURN_SUMMARY"; break;
    case HELP_AUTOMATIC_ADVICE: os << "HELP_AUTOMATIC_ADVICE"; break;
    case HELP_RANDOM_EVENTS: os << "HELP_RANDOM_EVENTS"; break;
    case HELP_AUTOMATIC_COMBAT: os << "HELP_AUTOMATIC_COMBAT"; break;
    case HELP_REVOLTING_RAIDERS: os << "HELP_REVOLTING_RAIDERS"; break;
    case HELP_MONSTERS_GONE_WILD: os << "HELP_MONSTERS_GONE_WILD"; break;
    case HELP_ENEMY_MOVES: os << "HELP_ENEMY_MOVES"; break;
    case HELP_ENEMY_SPELLS: os << "HELP_ENEMY_SPELLS"; break;
    case HELP_SPELL_BOOK_ORDERING: os << "HELP_SPELL_BOOK_ORDERING"; break;
    case HELP_SPELL_ANIMATIONS: os << "HELP_SPELL_ANIMATIONS"; break;
    case HELP_SHOW_NODE_OWNERS: os << "HELP_SHOW_NODE_OWNERS"; break;
    case HELP_EXPANDING_HELP: os << "HELP_EXPANDING_HELP"; break;
    case HELP_ALCHEMY: os << "HELP_ALCHEMY"; break;
    case HELP_WARLORD: os << "HELP_WARLORD"; break;
    case HELP_CHANNELER: os << "HELP_CHANNELER"; break;
    case HELP_ARCHMAGE: os << "HELP_ARCHMAGE"; break;
    case HELP_ARTIFICER: os << "HELP_ARTIFICER"; break;
    case HELP_CONJURER: os << "HELP_CONJURER"; break;
    case HELP_SAGE_MASTER: os << "HELP_SAGE_MASTER"; break;
    case HELP_MYRRAN: os << "HELP_MYRRAN"; break;
    case HELP_DIVINE_POWER: os << "HELP_DIVINE_POWER"; break;
    case HELP_FAMOUS: os << "HELP_FAMOUS"; break;
    case HELP_RUNEMASTER: os << "HELP_RUNEMASTER"; break;
    case HELP_CHARISMATIC: os << "HELP_CHARISMATIC"; break;
    case HELP_CHAOS_MASTERY: os << "HELP_CHAOS_MASTERY"; break;
    case HELP_NATURE_MASTERY: os << "HELP_NATURE_MASTERY"; break;
    case HELP_SORCERY_MASTERY: os << "HELP_SORCERY_MASTERY"; break;
    case HELP_INFERNAL_POWER: os << "HELP_INFERNAL_POWER"; break;
    case HELP_MANA_FOCUSING: os << "HELP_MANA_FOCUSING"; break;
    case HELP_NODE_MASTERY: os << "HELP_NODE_MASTERY"; break;
    case HELP_MAGIC_PICKS: os << "HELP_MAGIC_PICKS"; break;
    case HELP_play_NEWGAME_OK_BUTTON: os << "HELP_play_NEWGAME_OK_BUTTON"; break;
    case HELP_SPECIAL2_GUISE: os << "HELP_SPECIAL2_GUISE"; break;
    case HELP_cityscap_TRADE_GOODS: os << "HELP_cityscap_TRADE_GOODS"; break;
    case HELP_cityscap_HOUSING: os << "HELP_cityscap_HOUSING"; break;
    case HELP_cityscap_BARRACKS: os << "HELP_cityscap_BARRACKS"; break;
    case HELP_cityscap_ARMORY: os << "HELP_cityscap_ARMORY"; break;
    case HELP_cityscap_FIGHTERS_GUILD: os << "HELP_cityscap_FIGHTERS_GUILD"; break;
    case HELP_cityscap_ARMORERS_GUILD: os << "HELP_cityscap_ARMORERS_GUILD"; break;
    case HELP_cityscap_WAR_COLLEGE: os << "HELP_cityscap_WAR_COLLEGE"; break;
    case HELP_cityscap_SMITHY: os << "HELP_cityscap_SMITHY"; break;
    case HELP_cityscap_STABLES: os << "HELP_cityscap_STABLES"; break;
    case HELP_cityscap_ANIMISTS_GUILD: os << "HELP_cityscap_ANIMISTS_GUILD"; break;
    case HELP_cityscap_FANTASTIC_STABLE: os << "HELP_cityscap_FANTASTIC_STABLE"; break;
    case HELP_cityscap_SHIP_WRIGHTS_GUILD: os << "HELP_cityscap_SHIP_WRIGHTS_GUILD"; break;
    case HELP_cityscap_SHIPYARD: os << "HELP_cityscap_SHIPYARD"; break;
    case HELP_cityscap_MARITIME_GUILD: os << "HELP_cityscap_MARITIME_GUILD"; break;
    case HELP_cityscap_SAWMILL: os << "HELP_cityscap_SAWMILL"; break;
    case HELP_cityscap_LIBRARY: os << "HELP_cityscap_LIBRARY"; break;
    case HELP_cityscap_SAGES_GUILD: os << "HELP_cityscap_SAGES_GUILD"; break;
    case HELP_cityscap_ORACLE: os << "HELP_cityscap_ORACLE"; break;
    case HELP_cityscap_ALCHEMISTS_GUILD: os << "HELP_cityscap_ALCHEMISTS_GUILD"; break;
    case HELP_cityscap_UNIVERSITY: os << "HELP_cityscap_UNIVERSITY"; break;
    case HELP_cityscap_WIZARDS_GUILD: os << "HELP_cityscap_WIZARDS_GUILD"; break;
    case HELP_cityscap_SHRINE: os << "HELP_cityscap_SHRINE"; break;
    case HELP_cityscap_TEMPLE: os << "HELP_cityscap_TEMPLE"; break;
    case HELP_cityscap_PARTHENON: os << "HELP_cityscap_PARTHENON"; break;
    case HELP_cityscap_CATHEDRAL: os << "HELP_cityscap_CATHEDRAL"; break;
    case HELP_cityscap_MARKETPLACE: os << "HELP_cityscap_MARKETPLACE"; break;
    case HELP_cityscap_BANK: os << "HELP_cityscap_BANK"; break;
    case HELP_cityscap_MERCHANTS_GUILD: os << "HELP_cityscap_MERCHANTS_GUILD"; break;
    case HELP_cityscap_GRANARY: os << "HELP_cityscap_GRANARY"; break;
    case HELP_cityscap_FARMERS_MARKET: os << "HELP_cityscap_FARMERS_MARKET"; break;
    case HELP_cityscap_FORESTERS_GUILD: os << "HELP_cityscap_FORESTERS_GUILD"; break;
    case HELP_cityscap_BUILDERS_HALL: os << "HELP_cityscap_BUILDERS_HALL"; break;
    case HELP_cityscap_MECHANICIANS_GUILD: os << "HELP_cityscap_MECHANICIANS_GUILD"; break;
    case HELP_cityscap_MINERS_GUILD: os << "HELP_cityscap_MINERS_GUILD"; break;
    case HELP_CITYSCAP_CITY_WALLS: os << "HELP_CITYSCAP_CITY_WALLS"; break;
    case HELP_cityscap_SUMMONING_CIRCLE: os << "HELP_cityscap_SUMMONING_CIRCLE"; break;
    case HELP_cityscap_EARTH_GATE: os << "HELP_cityscap_EARTH_GATE"; break;
    case HELP_cityscap_STREAM_OF_LIFE: os << "HELP_cityscap_STREAM_OF_LIFE"; break;
    case HELP_cityscap_ASTRAL_GATE: os << "HELP_cityscap_ASTRAL_GATE"; break;
    case HELP_cityscap_FORTRESS: os << "HELP_cityscap_FORTRESS"; break;
    case HELP_cityscap_DARK_RITUALS: os << "HELP_cityscap_DARK_RITUALS"; break;
    case HELP_cityscap_ALTAR_OF_BATTLE: os << "HELP_cityscap_ALTAR_OF_BATTLE"; break;
    case HELP_TREATIES: os << "HELP_TREATIES"; break;
    case HELP_SCROLL_PAGE_BACK: os << "HELP_SCROLL_PAGE_BACK"; break;
    case HELP_SCROLL_PAGE_FORWARD: os << "HELP_SCROLL_PAGE_FORWARD"; break;
    case HELP_spellscr_CANCEL: os << "HELP_spellscr_CANCEL"; break;
    case HELP_EXTRA_MANA_COST: os << "HELP_EXTRA_MANA_COST"; break;
    case HELP_NONE: os << "HELP_NONE"; break;
    case HELP_UNITVIEW_Adamantium_Weapon: os << "HELP_UNITVIEW_Adamantium_Weapon"; break;
    case HELP_TAX_PER_POPULATION: os << "HELP_TAX_PER_POPULATION"; break;
    case HELP_ADVISORS: os << "HELP_ADVISORS"; break;
    case HELP_mirror_FAMOUS: os << "HELP_mirror_FAMOUS"; break;
    case HELP_NIGHTSHADE: os << "HELP_NIGHTSHADE"; break;
    case HELP_COMPIX_MANA_LEAK: os << "HELP_COMPIX_MANA_LEAK"; break;
    case HELP_PLAGUE: os << "HELP_PLAGUE"; break;
    case HELP_POPULATION_BOOM: os << "HELP_POPULATION_BOOM"; break;
    case HELP_BLUE_CONJUNCTION: os << "HELP_BLUE_CONJUNCTION"; break;
    case HELP_RED_CONJUNCTION: os << "HELP_RED_CONJUNCTION"; break;
    case HELP_GREEN_CONJUNCTION: os << "HELP_GREEN_CONJUNCTION"; break;
    case HELP_BAD_MOON: os << "HELP_BAD_MOON"; break;
    case HELP_GOOD_MOON: os << "HELP_GOOD_MOON"; break;
    case HELP_MANA_SHORT: os << "HELP_MANA_SHORT"; break;
    case HELP_POPULATION: os << "HELP_POPULATION"; break;
    case HELP_DEATH_SPELLS: os << "HELP_DEATH_SPELLS"; break;
    case HELP_CHAOS_SPELLS: os << "HELP_CHAOS_SPELLS"; break;
    case HELP_LIFE_SPELLS: os << "HELP_LIFE_SPELLS"; break;
    case HELP_NATURE_SPELLS: os << "HELP_NATURE_SPELLS"; break;
    case HELP_SORCERY_SPELLS: os << "HELP_SORCERY_SPELLS"; break;
    case HELP_MANIACAL: os << "HELP_MANIACAL"; break;
    case HELP_RUTHLESS: os << "HELP_RUTHLESS"; break;
    case HELP_AGGRESSIVE: os << "HELP_AGGRESSIVE"; break;
    case HELP_CHAOTIC: os << "HELP_CHAOTIC"; break;
    case HELP_LAWFUL: os << "HELP_LAWFUL"; break;
    case HELP_PEACEFUL: os << "HELP_PEACEFUL"; break;
    case HELP_PRAGMATIST: os << "HELP_PRAGMATIST"; break;
    case HELP_MILITARIST: os << "HELP_MILITARIST"; break;
    case HELP_THEURGIST: os << "HELP_THEURGIST"; break;
    case HELP_PERFECTIONIST: os << "HELP_PERFECTIONIST"; break;
    case HELP_EXPANSIONIST: os << "HELP_EXPANSIONIST"; break;
    case HELP_WIZARD_PACT: os << "HELP_WIZARD_PACT"; break;
    case HELP_ALLIANCE: os << "HELP_ALLIANCE"; break;
    case HELP_NO_REPORT: os << "HELP_NO_REPORT"; break;
    case HELP_MOVEMENT_ANIMATIONS: os << "HELP_MOVEMENT_ANIMATIONS"; break;
    case HELP_COMPIX_BLUR: os << "HELP_COMPIX_BLUR"; break;
    case HELP_HALL_OF_FAME: os << "HELP_HALL_OF_FAME"; break;
    case HELP_SPELLS: os << "HELP_SPELLS"; break;
    case HELP_TOWNSFOLK: os << "HELP_TOWNSFOLK"; break;
    case HELP_BANISHED_WIZARDS: os << "HELP_BANISHED_WIZARDS"; break;
    case HELP_FAME: os << "HELP_FAME"; break;
    case HELP_YEAR: os << "HELP_YEAR"; break;
    case HELP_score_SPELL_OF_MASTERY: os << "HELP_score_SPELL_OF_MASTERY"; break;
    case HELP_FINAL_SCORE: os << "HELP_FINAL_SCORE"; break;
    case HELP_RAZE_CITY: os << "HELP_RAZE_CITY"; break;
    case eHelpIndex_MAX: os << "eHelpIndex_MAX"; break;
    default: os << "<Unknown eHelpIndex>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eHeroAbility& rhs)
{
    switch (rhs)
    {
    case HEROABILITY_Leadership: os << "HEROABILITY_Leadership"; break;
    case HEROABILITY_Leadership_X: os << "HEROABILITY_Leadership_X"; break;
    case HEROABILITY_2: os << "HEROABILITY_2"; break;
    case HEROABILITY_Legendary: os << "HEROABILITY_Legendary"; break;
    case HEROABILITY_Legendary_X: os << "HEROABILITY_Legendary_X"; break;
    case HEROABILITY_5: os << "HEROABILITY_5"; break;
    case HEROABILITY_Blademaster: os << "HEROABILITY_Blademaster"; break;
    case HEROABILITY_Blademaster_X: os << "HEROABILITY_Blademaster_X"; break;
    case HEROABILITY_8: os << "HEROABILITY_8"; break;
    case HEROABILITY_Armsmaster: os << "HEROABILITY_Armsmaster"; break;
    case HEROABILITY_Armsmaster_X: os << "HEROABILITY_Armsmaster_X"; break;
    case HEROABILITY_11: os << "HEROABILITY_11"; break;
    case HEROABILITY_Constitution: os << "HEROABILITY_Constitution"; break;
    case HEROABILITY_Constitution_X: os << "HEROABILITY_Constitution_X"; break;
    case HEROABILITY_14: os << "HEROABILITY_14"; break;
    case HEROABILITY_Might: os << "HEROABILITY_Might"; break;
    case HEROABILITY_Might_X: os << "HEROABILITY_Might_X"; break;
    case HEROABILITY_17: os << "HEROABILITY_17"; break;
    case HEROABILITY_Arcane_Power: os << "HEROABILITY_Arcane_Power"; break;
    case HEROABILITY_Arcane_Power_X: os << "HEROABILITY_Arcane_Power_X"; break;
    case HEROABILITY_20: os << "HEROABILITY_20"; break;
    case HEROABILITY_Sage: os << "HEROABILITY_Sage"; break;
    case HEROABILITY_Sage_X: os << "HEROABILITY_Sage_X"; break;
    case HEROABILITY_23: os << "HEROABILITY_23"; break;
    case HEROABILITY_Prayermaster: os << "HEROABILITY_Prayermaster"; break;
    case HEROABILITY_Prayermaster_X: os << "HEROABILITY_Prayermaster_X"; break;
    case HEROABILITY_Agility_X: os << "HEROABILITY_Agility_X"; break;
    case HEROABILITY_Lucky: os << "HEROABILITY_Lucky"; break;
    case HEROABILITY_Charmed: os << "HEROABILITY_Charmed"; break;
    case HEROABILITY_Noble: os << "HEROABILITY_Noble"; break;
    case HEROABILITY_30: os << "HEROABILITY_30"; break;
    case HEROABILITY_Agility: os << "HEROABILITY_Agility"; break;
    case eHeroAbility_MAX: os << "eHeroAbility_MAX"; break;
    default: os << "<Unknown eHeroAbility>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eHero_Level_Status& rhs)
{
    switch (rhs)
    {
    case HEROLEVELSTATUS_Level_1: os << "HEROLEVELSTATUS_Level_1"; break;
    case HEROLEVELSTATUS_Level_2: os << "HEROLEVELSTATUS_Level_2"; break;
    case HEROLEVELSTATUS_Level_3: os << "HEROLEVELSTATUS_Level_3"; break;
    case HEROLEVELSTATUS_Level_4: os << "HEROLEVELSTATUS_Level_4"; break;
    case HEROLEVELSTATUS_Level_5: os << "HEROLEVELSTATUS_Level_5"; break;
    case HEROLEVELSTATUS_Level_6: os << "HEROLEVELSTATUS_Level_6"; break;
    case HEROLEVELSTATUS_Level_7: os << "HEROLEVELSTATUS_Level_7"; break;
    case HEROLEVELSTATUS_Level_8: os << "HEROLEVELSTATUS_Level_8"; break;
    case HEROLEVELSTATUS_Level_9: os << "HEROLEVELSTATUS_Level_9"; break;
    case HEROLEVELSTATUS_Dead_Level_1: os << "HEROLEVELSTATUS_Dead_Level_1"; break;
    case HEROLEVELSTATUS_Dead_Level_2: os << "HEROLEVELSTATUS_Dead_Level_2"; break;
    case HEROLEVELSTATUS_Dead_Level_3: os << "HEROLEVELSTATUS_Dead_Level_3"; break;
    case HEROLEVELSTATUS_Dead_Level_4: os << "HEROLEVELSTATUS_Dead_Level_4"; break;
    case HEROLEVELSTATUS_Dead_Level_5: os << "HEROLEVELSTATUS_Dead_Level_5"; break;
    case HEROLEVELSTATUS_Dead_Level_6: os << "HEROLEVELSTATUS_Dead_Level_6"; break;
    case HEROLEVELSTATUS_Dead_Level_7: os << "HEROLEVELSTATUS_Dead_Level_7"; break;
    case HEROLEVELSTATUS_Dead_Level_8: os << "HEROLEVELSTATUS_Dead_Level_8"; break;
    case HEROLEVELSTATUS_Dead_Level_9: os << "HEROLEVELSTATUS_Dead_Level_9"; break;
    case HEROLEVELSTATUS_Active_in_Wizards_army: os << "HEROLEVELSTATUS_Active_in_Wizards_army"; break;
    default: os << "<Unknown eHero_Level_Status>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eHero_TypeCode& rhs)
{
    switch (rhs)
    {
    case HEROTYPE_Fighter: os << "HEROTYPE_Fighter"; break;
    case HEROTYPE_Bow: os << "HEROTYPE_Bow"; break;
    case HEROTYPE_Fighter_Wizard: os << "HEROTYPE_Fighter_Wizard"; break;
    case HEROTYPE_Wizard: os << "HEROTYPE_Wizard"; break;
    case eHero_TypeCode_MAX: os << "eHero_TypeCode_MAX"; break;
    default: os << "<Unknown eHero_TypeCode>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eHousing& rhs)
{
    switch (rhs)
    {
    case HOUSING_wooden_house: os << "HOUSING_wooden_house"; break;
    case HOUSING_tree_house: os << "HOUSING_tree_house"; break;
    case HOUSING_mud_hut: os << "HOUSING_mud_hut"; break;
    case eHousing_MAX: os << "eHousing_MAX"; break;
    default: os << "<Unknown eHousing>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eItemPower& rhs)
{
    switch (rhs)
    {
    case ITEMPOWER_Vampiric: os << "ITEMPOWER_Vampiric"; break;
    case ITEMPOWER_Guardian_Wind: os << "ITEMPOWER_Guardian_Wind"; break;
    case ITEMPOWER_Lightning: os << "ITEMPOWER_Lightning"; break;
    case ITEMPOWER_Cloak_Of_Fear: os << "ITEMPOWER_Cloak_Of_Fear"; break;
    case ITEMPOWER_Destruction: os << "ITEMPOWER_Destruction"; break;
    case ITEMPOWER_Wraith_Form: os << "ITEMPOWER_Wraith_Form"; break;
    case ITEMPOWER_Regeneration: os << "ITEMPOWER_Regeneration"; break;
    case ITEMPOWER_Pathfinding: os << "ITEMPOWER_Pathfinding"; break;
    case ITEMPOWER_Water_Walking: os << "ITEMPOWER_Water_Walking"; break;
    case ITEMPOWER_Resist_Elements: os << "ITEMPOWER_Resist_Elements"; break;
    case ITEMPOWER_Elemental_Armour: os << "ITEMPOWER_Elemental_Armour"; break;
    case ITEMPOWER_Chaos: os << "ITEMPOWER_Chaos"; break;
    case ITEMPOWER_Stoning: os << "ITEMPOWER_Stoning"; break;
    case ITEMPOWER_Endurance: os << "ITEMPOWER_Endurance"; break;
    case ITEMPOWER_Haste: os << "ITEMPOWER_Haste"; break;
    case ITEMPOWER_Invisibility: os << "ITEMPOWER_Invisibility"; break;
    case ITEMPOWER_Death: os << "ITEMPOWER_Death"; break;
    case ITEMPOWER_Flight: os << "ITEMPOWER_Flight"; break;
    case ITEMPOWER_Resist_Magic: os << "ITEMPOWER_Resist_Magic"; break;
    case ITEMPOWER_Magic_Immunity: os << "ITEMPOWER_Magic_Immunity"; break;
    case ITEMPOWER_Flaming: os << "ITEMPOWER_Flaming"; break;
    case ITEMPOWER_Holy_Avenger: os << "ITEMPOWER_Holy_Avenger"; break;
    case ITEMPOWER_True_Sight: os << "ITEMPOWER_True_Sight"; break;
    case ITEMPOWER_Phantasmal: os << "ITEMPOWER_Phantasmal"; break;
    case ITEMPOWER_Power_Drain: os << "ITEMPOWER_Power_Drain"; break;
    case ITEMPOWER_Bless: os << "ITEMPOWER_Bless"; break;
    case ITEMPOWER_Lion_Heart: os << "ITEMPOWER_Lion_Heart"; break;
    case ITEMPOWER_Giant_Strength: os << "ITEMPOWER_Giant_Strength"; break;
    case ITEMPOWER_Planar_Travel: os << "ITEMPOWER_Planar_Travel"; break;
    case ITEMPOWER_Merging: os << "ITEMPOWER_Merging"; break;
    case ITEMPOWER_Righteousness: os << "ITEMPOWER_Righteousness"; break;
    case ITEMPOWER_Invulnerability: os << "ITEMPOWER_Invulnerability"; break;
    case eItemPower_MAX: os << "eItemPower_MAX"; break;
    default: os << "<Unknown eItemPower>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eItemPowerType& rhs)
{
    switch (rhs)
    {
    case ITEMPOWERTYPE_Strength: os << "ITEMPOWERTYPE_Strength"; break;
    case ITEMPOWERTYPE_Accuracy: os << "ITEMPOWERTYPE_Accuracy"; break;
    case ITEMPOWERTYPE_Defense: os << "ITEMPOWERTYPE_Defense"; break;
    case ITEMPOWERTYPE_Wizardry: os << "ITEMPOWERTYPE_Wizardry"; break;
    case ITEMPOWERTYPE_Power: os << "ITEMPOWERTYPE_Power"; break;
    case ITEMPOWERTYPE_Speed: os << "ITEMPOWERTYPE_Speed"; break;
    case ITEMPOWERTYPE_Protection: os << "ITEMPOWERTYPE_Protection"; break;
    case ITEMPOWERTYPE_mutex_resist_elements: os << "ITEMPOWERTYPE_mutex_resist_elements"; break;
    case ITEMPOWERTYPE_mutex_resist_magic: os << "ITEMPOWERTYPE_mutex_resist_magic"; break;
    case ITEMPOWERTYPE_other_specials: os << "ITEMPOWERTYPE_other_specials"; break;
    case eItemPowerType_MAX: os << "eItemPowerType_MAX"; break;
    default: os << "<Unknown eItemPowerType>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eItem_Icon& rhs)
{
    switch (rhs)
    {
    case Sword_1: os << "Sword_1"; break;
    case Sword_2: os << "Sword_2"; break;
    case Sword_3: os << "Sword_3"; break;
    case Sword_4: os << "Sword_4"; break;
    case Sword_5: os << "Sword_5"; break;
    case Sword_6: os << "Sword_6"; break;
    case Sword_7: os << "Sword_7"; break;
    case Sword_8: os << "Sword_8"; break;
    case Sword_9: os << "Sword_9"; break;
    case Mace_01: os << "Mace_01"; break;
    case Mace_02: os << "Mace_02"; break;
    case Mace_03: os << "Mace_03"; break;
    case Mace_04: os << "Mace_04"; break;
    case Mace_05: os << "Mace_05"; break;
    case Mace_06: os << "Mace_06"; break;
    case Mace_07: os << "Mace_07"; break;
    case Mace_08: os << "Mace_08"; break;
    case Mace_09: os << "Mace_09"; break;
    case Mace_10: os << "Mace_10"; break;
    case Mace_11: os << "Mace_11"; break;
    case Axe_1: os << "Axe_1"; break;
    case Axe_2: os << "Axe_2"; break;
    case Axe_3: os << "Axe_3"; break;
    case Axe_4: os << "Axe_4"; break;
    case Axe_5: os << "Axe_5"; break;
    case Axe_6: os << "Axe_6"; break;
    case Axe_7: os << "Axe_7"; break;
    case Axe_8: os << "Axe_8"; break;
    case Axe_9: os << "Axe_9"; break;
    case Bow_1: os << "Bow_1"; break;
    case Bow_2: os << "Bow_2"; break;
    case Bow_3: os << "Bow_3"; break;
    case Bow_4: os << "Bow_4"; break;
    case Bow_5: os << "Bow_5"; break;
    case Bow_6: os << "Bow_6"; break;
    case Bow_7: os << "Bow_7"; break;
    case Bow_8: os << "Bow_8"; break;
    case Bow_9: os << "Bow_9"; break;
    case Staff_1: os << "Staff_1"; break;
    case Staff_2: os << "Staff_2"; break;
    case Staff_3: os << "Staff_3"; break;
    case Staff_4: os << "Staff_4"; break;
    case Staff_5: os << "Staff_5"; break;
    case Staff_6: os << "Staff_6"; break;
    case Staff_7: os << "Staff_7"; break;
    case Staff_8: os << "Staff_8"; break;
    case Staff_9: os << "Staff_9"; break;
    case Chain_1: os << "Chain_1"; break;
    case Chain_2: os << "Chain_2"; break;
    case Chain_3: os << "Chain_3"; break;
    case Chain_4: os << "Chain_4"; break;
    case Chain_5: os << "Chain_5"; break;
    case Chain_6: os << "Chain_6"; break;
    case Chain_7: os << "Chain_7"; break;
    case Chain_8: os << "Chain_8"; break;
    case Plate_1: os << "Plate_1"; break;
    case Plate_2: os << "Plate_2"; break;
    case Plate_3: os << "Plate_3"; break;
    case Plate_4: os << "Plate_4"; break;
    case Plate_5: os << "Plate_5"; break;
    case Plate_6: os << "Plate_6"; break;
    case Plate_7: os << "Plate_7"; break;
    case Shield_1: os << "Shield_1"; break;
    case Shield_2: os << "Shield_2"; break;
    case Shield_3: os << "Shield_3"; break;
    case Shield_4: os << "Shield_4"; break;
    case Shield_5: os << "Shield_5"; break;
    case Shield_6: os << "Shield_6"; break;
    case Shield_7: os << "Shield_7"; break;
    case Shield_8: os << "Shield_8"; break;
    case Shield_9: os << "Shield_9"; break;
    case Shield_10: os << "Shield_10"; break;
    case Pendant_1: os << "Pendant_1"; break;
    case Pendant_2: os << "Pendant_2"; break;
    case Brooch_1: os << "Brooch_1"; break;
    case Brooch_2: os << "Brooch_2"; break;
    case Brooch_3: os << "Brooch_3"; break;
    case Brooch_4: os << "Brooch_4"; break;
    case Ring_1: os << "Ring_1"; break;
    case Ring_2: os << "Ring_2"; break;
    case Ring_3: os << "Ring_3"; break;
    case Ring_4: os << "Ring_4"; break;
    case Ring_5: os << "Ring_5"; break;
    case Ring_6: os << "Ring_6"; break;
    case Cloak_1: os << "Cloak_1"; break;
    case Cloak_2: os << "Cloak_2"; break;
    case Cloak_3: os << "Cloak_3"; break;
    case Cloak_4: os << "Cloak_4"; break;
    case Cloak_5: os << "Cloak_5"; break;
    case Cloak_6: os << "Cloak_6"; break;
    case Gauntlet_1: os << "Gauntlet_1"; break;
    case Gauntlet_2: os << "Gauntlet_2"; break;
    case Gauntlet_3: os << "Gauntlet_3"; break;
    case Gauntlet_4: os << "Gauntlet_4"; break;
    case Helmet_1: os << "Helmet_1"; break;
    case Helmet_2: os << "Helmet_2"; break;
    case Helmet_3: os << "Helmet_3"; break;
    case Helmet_4: os << "Helmet_4"; break;
    case Helmet_5: os << "Helmet_5"; break;
    case Helmet_6: os << "Helmet_6"; break;
    case Helmet_7: os << "Helmet_7"; break;
    case Orb_1: os << "Orb_1"; break;
    case Orb_2: os << "Orb_2"; break;
    case Orb_3: os << "Orb_3"; break;
    case Orb_4: os << "Orb_4"; break;
    case Orb_5: os << "Orb_5"; break;
    case Orb_6: os << "Orb_6"; break;
    case Wand_1: os << "Wand_1"; break;
    case Wand_2: os << "Wand_2"; break;
    case Wand_3: os << "Wand_3"; break;
    case Wand_4: os << "Wand_4"; break;
    case Wand_5: os << "Wand_5"; break;
    case Wand_6: os << "Wand_6"; break;
    case Wand_7: os << "Wand_7"; break;
    case Wand_8: os << "Wand_8"; break;
    case eItem_Icon_MAX: os << "eItem_Icon_MAX"; break;
    default: os << "<Unknown eItem_Icon>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eItem_Type& rhs)
{
    switch (rhs)
    {
    case ITEMTYPE_Sword: os << "ITEMTYPE_Sword"; break;
    case ITEMTYPE_Mace: os << "ITEMTYPE_Mace"; break;
    case ITEMTYPE_Axe: os << "ITEMTYPE_Axe"; break;
    case ITEMTYPE_Bow: os << "ITEMTYPE_Bow"; break;
    case ITEMTYPE_Staff: os << "ITEMTYPE_Staff"; break;
    case ITEMTYPE_Wand: os << "ITEMTYPE_Wand"; break;
    case ITEMTYPE_Various: os << "ITEMTYPE_Various"; break;
    case ITEMTYPE_Shield: os << "ITEMTYPE_Shield"; break;
    case ITEMTYPE_Chain_Mail: os << "ITEMTYPE_Chain_Mail"; break;
    case ITEMTYPE_Plate_Mail: os << "ITEMTYPE_Plate_Mail"; break;
    case eItem_Type_MAX: os << "eItem_Type_MAX"; break;
    default: os << "<Unknown eItem_Type>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eLand_Size& rhs)
{
    switch (rhs)
    {
    case LANDSIZE_Small: os << "LANDSIZE_Small"; break;
    case LANDSIZE_Medium: os << "LANDSIZE_Medium"; break;
    case LANDSIZE_Large: os << "LANDSIZE_Large"; break;
    case eLand_Size_MAX: os << "eLand_Size_MAX"; break;
    default: os << "<Unknown eLand_Size>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eLand_Size140m& rhs)
{
    switch (rhs)
    {
    case LANDSIZE140M_Small: os << "LANDSIZE140M_Small"; break;
    case LANDSIZE140M_Medium: os << "LANDSIZE140M_Medium"; break;
    case LANDSIZE140M_Large: os << "LANDSIZE140M_Large"; break;
    case LANDSIZE140M_Huge: os << "LANDSIZE140M_Huge"; break;
    case eLand_Size140m_MAX: os << "eLand_Size140m_MAX"; break;
    default: os << "<Unknown eLand_Size140m>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eLand_Size150& rhs)
{
    switch (rhs)
    {
    case LANDSIZE150_Tiny: os << "LANDSIZE150_Tiny"; break;
    case LANDSIZE150_Small: os << "LANDSIZE150_Small"; break;
    case LANDSIZE150_Fair: os << "LANDSIZE150_Fair"; break;
    case LANDSIZE150_Large: os << "LANDSIZE150_Large"; break;
    case LANDSIZE150_Huge: os << "LANDSIZE150_Huge"; break;
    case eLand_Size150_MAX: os << "eLand_Size150_MAX"; break;
    default: os << "<Unknown eLand_Size150>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eLand_Size60& rhs)
{
    switch (rhs)
    {
    case LANDSIZE60_Tiny: os << "LANDSIZE60_Tiny"; break;
    case LANDSIZE60_Small: os << "LANDSIZE60_Small"; break;
    case LANDSIZE60_Fair: os << "LANDSIZE60_Fair"; break;
    case LANDSIZE60_Large: os << "LANDSIZE60_Large"; break;
    case LANDSIZE60_Huge: os << "LANDSIZE60_Huge"; break;
    case eLand_Size60_MAX: os << "eLand_Size60_MAX"; break;
    default: os << "<Unknown eLand_Size60>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eLevel& rhs)
{
    switch (rhs)
    {
    case LEVEL_Level_1: os << "LEVEL_Level_1"; break;
    case LEVEL_Level_2: os << "LEVEL_Level_2"; break;
    case LEVEL_Level_3: os << "LEVEL_Level_3"; break;
    case LEVEL_Level_4: os << "LEVEL_Level_4"; break;
    case LEVEL_Level_5: os << "LEVEL_Level_5"; break;
    case LEVEL_Level_6: os << "LEVEL_Level_6"; break;
    case LEVEL_Level_7: os << "LEVEL_Level_7"; break;
    case LEVEL_Level_8: os << "LEVEL_Level_8"; break;
    case LEVEL_Level_9: os << "LEVEL_Level_9"; break;
    case eLevel_MAX: os << "eLevel_MAX"; break;
    default: os << "<Unknown eLevel>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eMagic_Powerful& rhs)
{
    switch (rhs)
    {
    case MAGICPOWERFUL_Weak: os << "MAGICPOWERFUL_Weak"; break;
    case MAGICPOWERFUL_Normal: os << "MAGICPOWERFUL_Normal"; break;
    case MAGICPOWERFUL_Powerful: os << "MAGICPOWERFUL_Powerful"; break;
    case eMagic_Powerful_MAX: os << "eMagic_Powerful_MAX"; break;
    default: os << "<Unknown eMagic_Powerful>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eMagic_Powerful140m& rhs)
{
    switch (rhs)
    {
    case MAGICPOWERFUL140M_0_5: os << "MAGICPOWERFUL140M_0_5"; break;
    case MAGICPOWERFUL140M_1_0: os << "MAGICPOWERFUL140M_1_0"; break;
    case MAGICPOWERFUL140M_1_5: os << "MAGICPOWERFUL140M_1_5"; break;
    case MAGICPOWERFUL140M_2_0: os << "MAGICPOWERFUL140M_2_0"; break;
    case MAGICPOWERFUL140M_2_5: os << "MAGICPOWERFUL140M_2_5"; break;
    case eMagic_Powerful140m_MAX: os << "eMagic_Powerful140m_MAX"; break;
    default: os << "<Unknown eMagic_Powerful140m>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eMagic_Powerful150& rhs)
{
    switch (rhs)
    {
    case MAGICPOWERFUL150_Weak: os << "MAGICPOWERFUL150_Weak"; break;
    case MAGICPOWERFUL150_Fair: os << "MAGICPOWERFUL150_Fair"; break;
    case MAGICPOWERFUL150_Good: os << "MAGICPOWERFUL150_Good"; break;
    case MAGICPOWERFUL150_High: os << "MAGICPOWERFUL150_High"; break;
    case MAGICPOWERFUL150_Max: os << "MAGICPOWERFUL150_Max"; break;
    case eMagic_Powerful150_MAX: os << "eMagic_Powerful150_MAX"; break;
    default: os << "<Unknown eMagic_Powerful150>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eMagic_Powerful60& rhs)
{
    switch (rhs)
    {
    case MAGICPOWERFUL60_Min: os << "MAGICPOWERFUL60_Min"; break;
    case MAGICPOWERFUL60_Low: os << "MAGICPOWERFUL60_Low"; break;
    case MAGICPOWERFUL60_Fair: os << "MAGICPOWERFUL60_Fair"; break;
    case MAGICPOWERFUL60_High: os << "MAGICPOWERFUL60_High"; break;
    case MAGICPOWERFUL60_Max: os << "MAGICPOWERFUL60_Max"; break;
    case eMagic_Powerful60_MAX: os << "eMagic_Powerful60_MAX"; break;
    default: os << "<Unknown eMagic_Powerful60>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eMovement& rhs)
{
    switch (rhs)
    {
    case MOVEMENT_Unused: os << "MOVEMENT_Unused"; break;
    case MOVEMENT_Walking: os << "MOVEMENT_Walking"; break;
    case MOVEMENT_Forester: os << "MOVEMENT_Forester"; break;
    case MOVEMENT_Mountaineer: os << "MOVEMENT_Mountaineer"; break;
    case MOVEMENT_Swimming: os << "MOVEMENT_Swimming"; break;
    case MOVEMENT_Sailing: os << "MOVEMENT_Sailing"; break;
    case eMovement_MAX: os << "eMovement_MAX"; break;
    default: os << "<Unknown eMovement>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eNode_Type& rhs)
{
    switch (rhs)
    {
    case NODETYPE_Sorcery: os << "NODETYPE_Sorcery"; break;
    case NODETYPE_Nature: os << "NODETYPE_Nature"; break;
    case NODETYPE_Chaos: os << "NODETYPE_Chaos"; break;
    case eNode_Type_MAX: os << "eNode_Type_MAX"; break;
    default: os << "<Unknown eNode_Type>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eObjective& rhs)
{
    switch (rhs)
    {
    case OBJECTIVE_Pragmatist: os << "OBJECTIVE_Pragmatist"; break;
    case OBJECTIVE_Militarist: os << "OBJECTIVE_Militarist"; break;
    case OBJECTIVE_Theurgist: os << "OBJECTIVE_Theurgist"; break;
    case OBJECTIVE_Perfectionist: os << "OBJECTIVE_Perfectionist"; break;
    case OBJECTIVE_Expansionist: os << "OBJECTIVE_Expansionist"; break;
    case eObjective_MAX: os << "eObjective_MAX"; break;
    default: os << "<Unknown eObjective>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eOwner& rhs)
{
    switch (rhs)
    {
    case OWNER_None: os << "OWNER_None"; break;
    case OWNER_YOU: os << "OWNER_YOU"; break;
    case OWNER_1: os << "OWNER_1"; break;
    case OWNER_2: os << "OWNER_2"; break;
    case OWNER_3: os << "OWNER_3"; break;
    case OWNER_4: os << "OWNER_4"; break;
    case OWNER_Neutral: os << "OWNER_Neutral"; break;
    case eOwner_MAX: os << "eOwner_MAX"; break;
    default: os << "<Unknown eOwner>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const ePersonality& rhs)
{
    switch (rhs)
    {
    case PERSONALITY_Maniacal: os << "PERSONALITY_Maniacal"; break;
    case PERSONALITY_Ruthless: os << "PERSONALITY_Ruthless"; break;
    case PERSONALITY_Aggressive: os << "PERSONALITY_Aggressive"; break;
    case PERSONALITY_Chaotic: os << "PERSONALITY_Chaotic"; break;
    case PERSONALITY_Lawful: os << "PERSONALITY_Lawful"; break;
    case PERSONALITY_Peaceful: os << "PERSONALITY_Peaceful"; break;
    case ePersonality_MAX: os << "ePersonality_MAX"; break;
    default: os << "<Unknown ePersonality>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const ePlane& rhs)
{
    switch (rhs)
    {
    case PLANE_Dismissed_Deceased: os << "PLANE_Dismissed_Deceased"; break;
    case PLANE_Limbo: os << "PLANE_Limbo"; break;
    case PLANE_Arcanum: os << "PLANE_Arcanum"; break;
    case PLANE_Myrror: os << "PLANE_Myrror"; break;
    case ePlane_MAX: os << "ePlane_MAX"; break;
    default: os << "<Unknown ePlane>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const ePlane16& rhs)
{
    switch (rhs)
    {
    case PLANE16_Arcanum: os << "PLANE16_Arcanum"; break;
    case PLANE16_Myrror: os << "PLANE16_Myrror"; break;
    case ePlane16_MAX: os << "ePlane16_MAX"; break;
    default: os << "<Unknown ePlane16>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const ePlayer& rhs)
{
    switch (rhs)
    {
    case PLAYER_Dismissed_Deceased: os << "PLAYER_Dismissed_Deceased"; break;
    case PLAYER_YOU: os << "PLAYER_YOU"; break;
    case PLAYER_1: os << "PLAYER_1"; break;
    case PLAYER_2: os << "PLAYER_2"; break;
    case PLAYER_3: os << "PLAYER_3"; break;
    case PLAYER_4: os << "PLAYER_4"; break;
    case PLAYER_NEUTRAL: os << "PLAYER_NEUTRAL"; break;
    case ePlayer_MAX: os << "ePlayer_MAX"; break;
    default: os << "<Unknown ePlayer>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const ePortrait& rhs)
{
    switch (rhs)
    {
    case PORTRAIT_Merlin: os << "PORTRAIT_Merlin"; break;
    case PORTRAIT_Raven: os << "PORTRAIT_Raven"; break;
    case PORTRAIT_Sharee: os << "PORTRAIT_Sharee"; break;
    case PORTRAIT_Lo_Pan: os << "PORTRAIT_Lo_Pan"; break;
    case PORTRAIT_Jafar: os << "PORTRAIT_Jafar"; break;
    case PORTRAIT_Oberic: os << "PORTRAIT_Oberic"; break;
    case PORTRAIT_Rjak: os << "PORTRAIT_Rjak"; break;
    case PORTRAIT_Sssra: os << "PORTRAIT_Sssra"; break;
    case PORTRAIT_Tauron: os << "PORTRAIT_Tauron"; break;
    case PORTRAIT_Freya: os << "PORTRAIT_Freya"; break;
    case PORTRAIT_Horus: os << "PORTRAIT_Horus"; break;
    case PORTRAIT_Ariel: os << "PORTRAIT_Ariel"; break;
    case PORTRAIT_Tlaloc: os << "PORTRAIT_Tlaloc"; break;
    case PORTRAIT_Kali: os << "PORTRAIT_Kali"; break;
    case PORTRAIT_Custom: os << "PORTRAIT_Custom"; break;
    case ePortrait_MAX: os << "ePortrait_MAX"; break;
    default: os << "<Unknown ePortrait>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eProducing& rhs)
{
    switch (rhs)
    {
    case PRODUCING_Computer: os << "PRODUCING_Computer"; break;
    case PRODUCING_None: os << "PRODUCING_None"; break;
    case PRODUCING_Trade_Goods: os << "PRODUCING_Trade_Goods"; break;
    case PRODUCING_Housing: os << "PRODUCING_Housing"; break;
    case PRODUCING_Barracks: os << "PRODUCING_Barracks"; break;
    case PRODUCING_Armory: os << "PRODUCING_Armory"; break;
    case PRODUCING_Fighters_Guild: os << "PRODUCING_Fighters_Guild"; break;
    case PRODUCING_Armorers_Guild: os << "PRODUCING_Armorers_Guild"; break;
    case PRODUCING_War_College: os << "PRODUCING_War_College"; break;
    case PRODUCING_Smithy: os << "PRODUCING_Smithy"; break;
    case PRODUCING_Stable: os << "PRODUCING_Stable"; break;
    case PRODUCING_Animists_Guild: os << "PRODUCING_Animists_Guild"; break;
    case PRODUCING_Fantastic_Stable: os << "PRODUCING_Fantastic_Stable"; break;
    case PRODUCING_Shipwright_Guild: os << "PRODUCING_Shipwright_Guild"; break;
    case PRODUCING_Ship_Yard: os << "PRODUCING_Ship_Yard"; break;
    case PRODUCING_Maritime_Guild: os << "PRODUCING_Maritime_Guild"; break;
    case PRODUCING_Sawmill: os << "PRODUCING_Sawmill"; break;
    case PRODUCING_Library: os << "PRODUCING_Library"; break;
    case PRODUCING_Sages_Guild: os << "PRODUCING_Sages_Guild"; break;
    case PRODUCING_Oracle: os << "PRODUCING_Oracle"; break;
    case PRODUCING_Alchemist_Guild: os << "PRODUCING_Alchemist_Guild"; break;
    case PRODUCING_University: os << "PRODUCING_University"; break;
    case PRODUCING_Wizards_Guild: os << "PRODUCING_Wizards_Guild"; break;
    case PRODUCING_Shrine: os << "PRODUCING_Shrine"; break;
    case PRODUCING_Temple: os << "PRODUCING_Temple"; break;
    case PRODUCING_Parthenon: os << "PRODUCING_Parthenon"; break;
    case PRODUCING_Cathedral: os << "PRODUCING_Cathedral"; break;
    case PRODUCING_Marketplace: os << "PRODUCING_Marketplace"; break;
    case PRODUCING_Bank: os << "PRODUCING_Bank"; break;
    case PRODUCING_Merchants_Guild: os << "PRODUCING_Merchants_Guild"; break;
    case PRODUCING_Granary: os << "PRODUCING_Granary"; break;
    case PRODUCING_Farmers_Market: os << "PRODUCING_Farmers_Market"; break;
    case PRODUCING_Foresters_Guild: os << "PRODUCING_Foresters_Guild"; break;
    case PRODUCING_Builders_Hall: os << "PRODUCING_Builders_Hall"; break;
    case PRODUCING_Mechanicians_Guild: os << "PRODUCING_Mechanicians_Guild"; break;
    case PRODUCING_Miners_Guild: os << "PRODUCING_Miners_Guild"; break;
    case PRODUCING_City_Walls: os << "PRODUCING_City_Walls"; break;
    case eProducing_Building_MAX: os << "eProducing_Building_MAX"; break;
    case PRODUCING_Trireme: os << "PRODUCING_Trireme"; break;
    case PRODUCING_Galley: os << "PRODUCING_Galley"; break;
    case PRODUCING_Catapult: os << "PRODUCING_Catapult"; break;
    case PRODUCING_Warship: os << "PRODUCING_Warship"; break;
    case PRODUCING_Barbarian_Spearmen: os << "PRODUCING_Barbarian_Spearmen"; break;
    case PRODUCING_Barbarian_Swordsmen: os << "PRODUCING_Barbarian_Swordsmen"; break;
    case PRODUCING_Barbarian_Bowmen: os << "PRODUCING_Barbarian_Bowmen"; break;
    case PRODUCING_Barbarian_Cavalry: os << "PRODUCING_Barbarian_Cavalry"; break;
    case PRODUCING_Barbarian_Shaman: os << "PRODUCING_Barbarian_Shaman"; break;
    case PRODUCING_Barbarian_Settlers: os << "PRODUCING_Barbarian_Settlers"; break;
    case PRODUCING_Barbarian_Berserkers: os << "PRODUCING_Barbarian_Berserkers"; break;
    case PRODUCING_Beastmen_Spearmen: os << "PRODUCING_Beastmen_Spearmen"; break;
    case PRODUCING_Beastmen_Swordsmen: os << "PRODUCING_Beastmen_Swordsmen"; break;
    case PRODUCING_Beastmen_Halberdiers: os << "PRODUCING_Beastmen_Halberdiers"; break;
    case PRODUCING_Beastmen_Bowmen: os << "PRODUCING_Beastmen_Bowmen"; break;
    case PRODUCING_Beastmen_Priests: os << "PRODUCING_Beastmen_Priests"; break;
    case PRODUCING_Beastmen_Magicians: os << "PRODUCING_Beastmen_Magicians"; break;
    case PRODUCING_Beastmen_Engineers: os << "PRODUCING_Beastmen_Engineers"; break;
    case PRODUCING_Beastmen_Settlers: os << "PRODUCING_Beastmen_Settlers"; break;
    case PRODUCING_Beastmen_Centaurs: os << "PRODUCING_Beastmen_Centaurs"; break;
    case PRODUCING_Beastmen_Manticores: os << "PRODUCING_Beastmen_Manticores"; break;
    case PRODUCING_Beastmen_Minotaurs: os << "PRODUCING_Beastmen_Minotaurs"; break;
    case PRODUCING_Dark_Elf_Spearmen: os << "PRODUCING_Dark_Elf_Spearmen"; break;
    case PRODUCING_Dark_Elf_Swordsmen: os << "PRODUCING_Dark_Elf_Swordsmen"; break;
    case PRODUCING_Dark_Elf_Halberdiers: os << "PRODUCING_Dark_Elf_Halberdiers"; break;
    case PRODUCING_Dark_Elf_Cavalry: os << "PRODUCING_Dark_Elf_Cavalry"; break;
    case PRODUCING_Dark_Elf_Priests: os << "PRODUCING_Dark_Elf_Priests"; break;
    case PRODUCING_Dark_Elf_Settlers: os << "PRODUCING_Dark_Elf_Settlers"; break;
    case PRODUCING_Dark_Elf_Nightblades: os << "PRODUCING_Dark_Elf_Nightblades"; break;
    case PRODUCING_Dark_Elf_Warlocks: os << "PRODUCING_Dark_Elf_Warlocks"; break;
    case PRODUCING_Dark_Elf_Nightmares: os << "PRODUCING_Dark_Elf_Nightmares"; break;
    case PRODUCING_Draconian_Spearmen: os << "PRODUCING_Draconian_Spearmen"; break;
    case PRODUCING_Draconian_Swordsmen: os << "PRODUCING_Draconian_Swordsmen"; break;
    case PRODUCING_Draconian_Halberdiers: os << "PRODUCING_Draconian_Halberdiers"; break;
    case PRODUCING_Draconian_Bowmen: os << "PRODUCING_Draconian_Bowmen"; break;
    case PRODUCING_Draconian_Shaman: os << "PRODUCING_Draconian_Shaman"; break;
    case PRODUCING_Draconian_Magicians: os << "PRODUCING_Draconian_Magicians"; break;
    case PRODUCING_Draconian_Engineers: os << "PRODUCING_Draconian_Engineers"; break;
    case PRODUCING_Draconian_Settlers: os << "PRODUCING_Draconian_Settlers"; break;
    case PRODUCING_Draconian_Doom_Drakes: os << "PRODUCING_Draconian_Doom_Drakes"; break;
    case PRODUCING_Draconian_Air_Ship: os << "PRODUCING_Draconian_Air_Ship"; break;
    case PRODUCING_Dwarven_Swordsmen: os << "PRODUCING_Dwarven_Swordsmen"; break;
    case PRODUCING_Dwarven_Halberdiers: os << "PRODUCING_Dwarven_Halberdiers"; break;
    case PRODUCING_Dwarven_Engineers: os << "PRODUCING_Dwarven_Engineers"; break;
    case PRODUCING_Dwarven_Hammerhands: os << "PRODUCING_Dwarven_Hammerhands"; break;
    case PRODUCING_Dwarven_Steam_Cannon: os << "PRODUCING_Dwarven_Steam_Cannon"; break;
    case PRODUCING_Dwarven_Golem: os << "PRODUCING_Dwarven_Golem"; break;
    case PRODUCING_Dwarven_Settlers: os << "PRODUCING_Dwarven_Settlers"; break;
    case PRODUCING_Gnoll_Spearmen: os << "PRODUCING_Gnoll_Spearmen"; break;
    case PRODUCING_Gnoll_Swordsmen: os << "PRODUCING_Gnoll_Swordsmen"; break;
    case PRODUCING_Gnoll_Halberdiers: os << "PRODUCING_Gnoll_Halberdiers"; break;
    case PRODUCING_Gnoll_Bowmen: os << "PRODUCING_Gnoll_Bowmen"; break;
    case PRODUCING_Gnoll_Settlers: os << "PRODUCING_Gnoll_Settlers"; break;
    case PRODUCING_Gnoll_Wolf_Riders: os << "PRODUCING_Gnoll_Wolf_Riders"; break;
    case PRODUCING_Halfling_Spearmen: os << "PRODUCING_Halfling_Spearmen"; break;
    case PRODUCING_Halfling_Swordsmen: os << "PRODUCING_Halfling_Swordsmen"; break;
    case PRODUCING_Halfling_Bowmen: os << "PRODUCING_Halfling_Bowmen"; break;
    case PRODUCING_Halfling_Shaman: os << "PRODUCING_Halfling_Shaman"; break;
    case PRODUCING_Halfling_Settlers: os << "PRODUCING_Halfling_Settlers"; break;
    case PRODUCING_Halfling_Slingers: os << "PRODUCING_Halfling_Slingers"; break;
    case PRODUCING_High_Elf_Spearmen: os << "PRODUCING_High_Elf_Spearmen"; break;
    case PRODUCING_High_Elf_Swordsmen: os << "PRODUCING_High_Elf_Swordsmen"; break;
    case PRODUCING_High_Elf_Halberdiers: os << "PRODUCING_High_Elf_Halberdiers"; break;
    case PRODUCING_High_Elf_Cavalry: os << "PRODUCING_High_Elf_Cavalry"; break;
    case PRODUCING_High_Elf_Magicians: os << "PRODUCING_High_Elf_Magicians"; break;
    case PRODUCING_High_Elf_Settlers: os << "PRODUCING_High_Elf_Settlers"; break;
    case PRODUCING_High_Elf_Longbowmen: os << "PRODUCING_High_Elf_Longbowmen"; break;
    case PRODUCING_High_Elf_Elven_Lords: os << "PRODUCING_High_Elf_Elven_Lords"; break;
    case PRODUCING_High_Elf_Pegasai: os << "PRODUCING_High_Elf_Pegasai"; break;
    case PRODUCING_High_Men_Spearmen: os << "PRODUCING_High_Men_Spearmen"; break;
    case PRODUCING_High_Men_Swordsmen: os << "PRODUCING_High_Men_Swordsmen"; break;
    case PRODUCING_High_Men_Bowmen: os << "PRODUCING_High_Men_Bowmen"; break;
    case PRODUCING_High_Men_Cavalry: os << "PRODUCING_High_Men_Cavalry"; break;
    case PRODUCING_High_Men_Priests: os << "PRODUCING_High_Men_Priests"; break;
    case PRODUCING_High_Men_Magicians: os << "PRODUCING_High_Men_Magicians"; break;
    case PRODUCING_High_Men_Engineers: os << "PRODUCING_High_Men_Engineers"; break;
    case PRODUCING_High_Men_Settlers: os << "PRODUCING_High_Men_Settlers"; break;
    case PRODUCING_High_Men_Pikemen: os << "PRODUCING_High_Men_Pikemen"; break;
    case PRODUCING_High_Men_Paladins: os << "PRODUCING_High_Men_Paladins"; break;
    case PRODUCING_Klackon_Spearmen: os << "PRODUCING_Klackon_Spearmen"; break;
    case PRODUCING_Klackon_Swordsmen: os << "PRODUCING_Klackon_Swordsmen"; break;
    case PRODUCING_Klackon_Halberdiers: os << "PRODUCING_Klackon_Halberdiers"; break;
    case PRODUCING_Klackon_Engineers: os << "PRODUCING_Klackon_Engineers"; break;
    case PRODUCING_Klackon_Settlers: os << "PRODUCING_Klackon_Settlers"; break;
    case PRODUCING_Klackon_Stag_Beetle: os << "PRODUCING_Klackon_Stag_Beetle"; break;
    case PRODUCING_Lizardman_Spearmen: os << "PRODUCING_Lizardman_Spearmen"; break;
    case PRODUCING_Lizardman_Swordsmen: os << "PRODUCING_Lizardman_Swordsmen"; break;
    case PRODUCING_Lizardman_Halberdiers: os << "PRODUCING_Lizardman_Halberdiers"; break;
    case PRODUCING_Lizardman_Javelineers: os << "PRODUCING_Lizardman_Javelineers"; break;
    case PRODUCING_Lizardman_Shaman: os << "PRODUCING_Lizardman_Shaman"; break;
    case PRODUCING_Lizardman_Settlers: os << "PRODUCING_Lizardman_Settlers"; break;
    case PRODUCING_Lizardman_Dragon_Turtle: os << "PRODUCING_Lizardman_Dragon_Turtle"; break;
    case PRODUCING_Nomad_Spearmen: os << "PRODUCING_Nomad_Spearmen"; break;
    case PRODUCING_Nomad_Swordsmen: os << "PRODUCING_Nomad_Swordsmen"; break;
    case PRODUCING_Nomad_Bowmen: os << "PRODUCING_Nomad_Bowmen"; break;
    case PRODUCING_Nomad_Priests: os << "PRODUCING_Nomad_Priests"; break;
    case PRODUCING_Nomad_Magicians: os << "PRODUCING_Nomad_Magicians"; break;
    case PRODUCING_Nomad_Settlers: os << "PRODUCING_Nomad_Settlers"; break;
    case PRODUCING_Nomad_Horsebowmen: os << "PRODUCING_Nomad_Horsebowmen"; break;
    case PRODUCING_Nomad_Pikemen: os << "PRODUCING_Nomad_Pikemen"; break;
    case PRODUCING_Nomad_Rangers: os << "PRODUCING_Nomad_Rangers"; break;
    case PRODUCING_Nomad_Griffins: os << "PRODUCING_Nomad_Griffins"; break;
    case PRODUCING_Orc_Spearmen: os << "PRODUCING_Orc_Spearmen"; break;
    case PRODUCING_Orc_Swordsmen: os << "PRODUCING_Orc_Swordsmen"; break;
    case PRODUCING_Orc_Halberdiers: os << "PRODUCING_Orc_Halberdiers"; break;
    case PRODUCING_Orc_Bowmen: os << "PRODUCING_Orc_Bowmen"; break;
    case PRODUCING_Orc_Cavalry: os << "PRODUCING_Orc_Cavalry"; break;
    case PRODUCING_Orc_Shaman: os << "PRODUCING_Orc_Shaman"; break;
    case PRODUCING_Orc_Magicians: os << "PRODUCING_Orc_Magicians"; break;
    case PRODUCING_Orc_Engineers: os << "PRODUCING_Orc_Engineers"; break;
    case PRODUCING_Orc_Settlers: os << "PRODUCING_Orc_Settlers"; break;
    case PRODUCING_Orc_Wyvern_Riders: os << "PRODUCING_Orc_Wyvern_Riders"; break;
    case PRODUCING_Troll_Spearmen: os << "PRODUCING_Troll_Spearmen"; break;
    case PRODUCING_Troll_Swordsmen: os << "PRODUCING_Troll_Swordsmen"; break;
    case PRODUCING_Troll_Halberdiers: os << "PRODUCING_Troll_Halberdiers"; break;
    case PRODUCING_Troll_Shaman: os << "PRODUCING_Troll_Shaman"; break;
    case PRODUCING_Troll_Settlers: os << "PRODUCING_Troll_Settlers"; break;
    case PRODUCING_Troll_War_Trolls: os << "PRODUCING_Troll_War_Trolls"; break;
    case PRODUCING_Troll_War_Mammoths: os << "PRODUCING_Troll_War_Mammoths"; break;
    case eProducing_MAX: os << "eProducing_MAX"; break;
    default: os << "<Unknown eProducing>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eRace& rhs)
{
    switch (rhs)
    {
    case RACE_Barbarian: os << "RACE_Barbarian"; break;
    case RACE_Beastmen: os << "RACE_Beastmen"; break;
    case RACE_Dark_Elf: os << "RACE_Dark_Elf"; break;
    case RACE_Draconian: os << "RACE_Draconian"; break;
    case RACE_Dwarven: os << "RACE_Dwarven"; break;
    case RACE_Gnoll: os << "RACE_Gnoll"; break;
    case RACE_Halfling: os << "RACE_Halfling"; break;
    case RACE_High_Elf: os << "RACE_High_Elf"; break;
    case RACE_High_Men: os << "RACE_High_Men"; break;
    case RACE_Klackon: os << "RACE_Klackon"; break;
    case RACE_Lizardman: os << "RACE_Lizardman"; break;
    case RACE_Nomad: os << "RACE_Nomad"; break;
    case RACE_Orc: os << "RACE_Orc"; break;
    case RACE_Troll: os << "RACE_Troll"; break;
    case RACE_Generic: os << "RACE_Generic"; break;
    case RACE_Arcane: os << "RACE_Arcane"; break;
    case RACE_Nature: os << "RACE_Nature"; break;
    case RACE_Sorcery: os << "RACE_Sorcery"; break;
    case RACE_Chaos: os << "RACE_Chaos"; break;
    case RACE_Life: os << "RACE_Life"; break;
    case RACE_Death: os << "RACE_Death"; break;
    case eRace_MAX: os << "eRace_MAX"; break;
    default: os << "<Unknown eRace>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eRandomPickType& rhs)
{
    switch (rhs)
    {
    case RANDOMPICK_Random_Ftr: os << "RANDOMPICK_Random_Ftr"; break;
    case RANDOMPICK_Random_Mage: os << "RANDOMPICK_Random_Mage"; break;
    case RANDOMPICK_Random_Any: os << "RANDOMPICK_Random_Any"; break;
    case eRandomPickType_MAX: os << "eRandomPickType_MAX"; break;
    default: os << "<Unknown eRandomPickType>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eRanged_Type& rhs)
{
    switch (rhs)
    {
    case RANGED_None: os << "RANGED_None"; break;
    case RANGED_Rock: os << "RANGED_Rock"; break;
    case RANGED_Arrow: os << "RANGED_Arrow"; break;
    case RANGED_Bullet: os << "RANGED_Bullet"; break;
    case RANGED_Chaos_Lightning: os << "RANGED_Chaos_Lightning"; break;
    case RANGED_Chaos_Fireball: os << "RANGED_Chaos_Fireball"; break;
    case RANGED_Sorcery_Illusion: os << "RANGED_Sorcery_Illusion"; break;
    case RANGED_Chaos_Deathbolt: os << "RANGED_Chaos_Deathbolt"; break;
    case RANGED_Nature_Icebolt: os << "RANGED_Nature_Icebolt"; break;
    case RANGED_Nature_Priest: os << "RANGED_Nature_Priest"; break;
    case RANGED_Chaos_Drow: os << "RANGED_Chaos_Drow"; break;
    case RANGED_Nature_Shimmer: os << "RANGED_Nature_Shimmer"; break;
    case RANGED_Nature_Green: os << "RANGED_Nature_Green"; break;
    case RANGED_Thrown_Weapons: os << "RANGED_Thrown_Weapons"; break;
    case RANGED_Fire_Breath: os << "RANGED_Fire_Breath"; break;
    case RANGED_Lightning_Breath: os << "RANGED_Lightning_Breath"; break;
    case RANGED_Stoning_Gaze: os << "RANGED_Stoning_Gaze"; break;
    case RANGED_Multiple_Gaze: os << "RANGED_Multiple_Gaze"; break;
    case RANGED_Death_Gaze: os << "RANGED_Death_Gaze"; break;
    case eRanged_Type_MAX: os << "eRanged_Type_MAX"; break;
    default: os << "<Unknown eRanged_Type>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eRarity& rhs)
{
    switch (rhs)
    {
    case RARITY_Common: os << "RARITY_Common"; break;
    case RARITY_Uncommon: os << "RARITY_Uncommon"; break;
    case RARITY_Rare: os << "RARITY_Rare"; break;
    case RARITY_Very_Rare: os << "RARITY_Very_Rare"; break;
    case eRarity_MAX: os << "eRarity_MAX"; break;
    default: os << "<Unknown eRarity>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eRealm_Type& rhs)
{
    switch (rhs)
    {
    case REALM_None: os << "REALM_None"; break;
    case REALM_Nature: os << "REALM_Nature"; break;
    case REALM_Sorcery: os << "REALM_Sorcery"; break;
    case REALM_Chaos: os << "REALM_Chaos"; break;
    case REALM_Life: os << "REALM_Life"; break;
    case REALM_Death: os << "REALM_Death"; break;
    case REALM_Arcane: os << "REALM_Arcane"; break;
    case eRealm_Type_MAX: os << "eRealm_Type_MAX"; break;
    default: os << "<Unknown eRealm_Type>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eRealm_Type16& rhs)
{
    switch (rhs)
    {
    case REALM16_None: os << "REALM16_None"; break;
    case REALM16_Nature: os << "REALM16_Nature"; break;
    case REALM16_Sorcery: os << "REALM16_Sorcery"; break;
    case REALM16_Chaos: os << "REALM16_Chaos"; break;
    case REALM16_Life: os << "REALM16_Life"; break;
    case REALM16_Death: os << "REALM16_Death"; break;
    case REALM16_Arcane: os << "REALM16_Arcane"; break;
    case eRealm_Type16_MAX: os << "eRealm_Type16_MAX"; break;
    default: os << "<Unknown eRealm_Type16>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eResource& rhs)
{
    switch (rhs)
    {
    case RESOURCE_None: os << "RESOURCE_None"; break;
    case RESOURCE_Food: os << "RESOURCE_Food"; break;
    case RESOURCE_Production: os << "RESOURCE_Production"; break;
    case RESOURCE_Gold: os << "RESOURCE_Gold"; break;
    case RESOURCE_Power: os << "RESOURCE_Power"; break;
    case RESOURCE_Mana: os << "RESOURCE_Mana"; break;
    case RESOURCE_Research: os << "RESOURCE_Research"; break;
    case RESOURCE_Gray_Food: os << "RESOURCE_Gray_Food"; break;
    case RESOURCE_Gray_Gold: os << "RESOURCE_Gray_Gold"; break;
    case RESOURCE_10_Food: os << "RESOURCE_10_Food"; break;
    case RESOURCE_10_Production: os << "RESOURCE_10_Production"; break;
    case RESOURCE_10_Gold: os << "RESOURCE_10_Gold"; break;
    case RESOURCE_10_Power: os << "RESOURCE_10_Power"; break;
    case RESOURCE_10_Mana: os << "RESOURCE_10_Mana"; break;
    case RESOURCE_10_Research: os << "RESOURCE_10_Research"; break;
    case RESOURCE_10_Gray_Food: os << "RESOURCE_10_Gray_Food"; break;
    case RESOURCE_10_Gray_Gold: os << "RESOURCE_10_Gray_Gold"; break;
    case eResource_MAX: os << "eResource_MAX"; break;
    default: os << "<Unknown eResource>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eReward_Specials& rhs)
{
    switch (rhs)
    {
    case REWARD_No_specials: os << "REWARD_No_specials"; break;
    case REWARD_Common_Spell: os << "REWARD_Common_Spell"; break;
    case REWARD_Uncommon_Spell: os << "REWARD_Uncommon_Spell"; break;
    case REWARD_Rare_Spell: os << "REWARD_Rare_Spell"; break;
    case REWARD_Very_Rare_Spell: os << "REWARD_Very_Rare_Spell"; break;
    case REWARD_1_Spellbook_or_Skill: os << "REWARD_1_Spellbook_or_Skill"; break;
    case REWARD_2_Spellbooks_or_Skills: os << "REWARD_2_Spellbooks_or_Skills"; break;
    case eReward_Specials_MAX: os << "eReward_Specials_MAX"; break;
    default: os << "<Unknown eReward_Specials>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eSkill16& rhs)
{
    switch (rhs)
    {
    case SKILL16_None: os << "SKILL16_None"; break;
    case SKILL16_Alchemy: os << "SKILL16_Alchemy"; break;
    case SKILL16_Warlord: os << "SKILL16_Warlord"; break;
    case SKILL16_Chaos_Master: os << "SKILL16_Chaos_Master"; break;
    case SKILL16_Nature_Master: os << "SKILL16_Nature_Master"; break;
    case SKILL16_Sorcery_Master: os << "SKILL16_Sorcery_Master"; break;
    case SKILL16_Infernal_Power: os << "SKILL16_Infernal_Power"; break;
    case SKILL16_Divine_Power: os << "SKILL16_Divine_Power"; break;
    case SKILL16_Sage_Master: os << "SKILL16_Sage_Master"; break;
    case SKILL16_Channeller: os << "SKILL16_Channeller"; break;
    case SKILL16_Myrran: os << "SKILL16_Myrran"; break;
    case SKILL16_Archmage: os << "SKILL16_Archmage"; break;
    case SKILL16_Mana_Focusing: os << "SKILL16_Mana_Focusing"; break;
    case SKILL16_Node_Mastery: os << "SKILL16_Node_Mastery"; break;
    case SKILL16_Famous: os << "SKILL16_Famous"; break;
    case SKILL16_Runemaster: os << "SKILL16_Runemaster"; break;
    case SKILL16_Conjurer: os << "SKILL16_Conjurer"; break;
    case SKILL16_Charismatic: os << "SKILL16_Charismatic"; break;
    case SKILL16_Artificer: os << "SKILL16_Artificer"; break;
    default: os << "<Unknown eSkill16>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eSlot_Type16& rhs)
{
    switch (rhs)
    {
    case SLOT16_Sword: os << "SLOT16_Sword"; break;
    case SLOT16_Bow: os << "SLOT16_Bow"; break;
    case SLOT16_Sword_Staff_Wand: os << "SLOT16_Sword_Staff_Wand"; break;
    case SLOT16_Staff_Wand: os << "SLOT16_Staff_Wand"; break;
    case SLOT16_Armor_Shield: os << "SLOT16_Armor_Shield"; break;
    case SLOT16_Amulet: os << "SLOT16_Amulet"; break;
    case eSlot_Type16_MAX: os << "eSlot_Type16_MAX"; break;
    default: os << "<Unknown eSlot_Type16>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eSlot_Type8& rhs)
{
    switch (rhs)
    {
    case SLOT8_Sword: os << "SLOT8_Sword"; break;
    case SLOT8_Bow: os << "SLOT8_Bow"; break;
    case SLOT8_Sword_Staff_Wand: os << "SLOT8_Sword_Staff_Wand"; break;
    case SLOT8_Staff_Wand: os << "SLOT8_Staff_Wand"; break;
    case SLOT8_Armor_Shield: os << "SLOT8_Armor_Shield"; break;
    case SLOT8_Amulet: os << "SLOT8_Amulet"; break;
    case eSlot_Type8_MAX: os << "eSlot_Type8_MAX"; break;
    default: os << "<Unknown eSlot_Type8>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eSpell& rhs)
{
    switch (rhs)
    {
    case SPELL_None: os << "SPELL_None"; break;
    case SPELL_Earth_to_Mud: os << "SPELL_Earth_to_Mud"; break;
    case SPELL_Resist_Elements: os << "SPELL_Resist_Elements"; break;
    case SPELL_Wall_of_Stone: os << "SPELL_Wall_of_Stone"; break;
    case SPELL_Giant_Strength: os << "SPELL_Giant_Strength"; break;
    case SPELL_Web: os << "SPELL_Web"; break;
    case SPELL_War_Bears: os << "SPELL_War_Bears"; break;
    case SPELL_Stone_Skin: os << "SPELL_Stone_Skin"; break;
    case SPELL_Water_Walking: os << "SPELL_Water_Walking"; break;
    case SPELL_Sprites: os << "SPELL_Sprites"; break;
    case SPELL_Earth_Lore: os << "SPELL_Earth_Lore"; break;
    case SPELL_Cracks_Call: os << "SPELL_Cracks_Call"; break;
    case SPELL_Natures_Eye: os << "SPELL_Natures_Eye"; break;
    case SPELL_Ice_Bolt: os << "SPELL_Ice_Bolt"; break;
    case SPELL_Giant_Spiders: os << "SPELL_Giant_Spiders"; break;
    case SPELL_Change_Terrain: os << "SPELL_Change_Terrain"; break;
    case SPELL_Path_Finding: os << "SPELL_Path_Finding"; break;
    case SPELL_Cockatrices: os << "SPELL_Cockatrices"; break;
    case SPELL_Transmute: os << "SPELL_Transmute"; break;
    case SPELL_Natures_Cures: os << "SPELL_Natures_Cures"; break;
    case SPELL_Basilisk: os << "SPELL_Basilisk"; break;
    case SPELL_Elemental_Armor: os << "SPELL_Elemental_Armor"; break;
    case SPELL_Petrify: os << "SPELL_Petrify"; break;
    case SPELL_Stone_Giant: os << "SPELL_Stone_Giant"; break;
    case SPELL_Iron_Skin: os << "SPELL_Iron_Skin"; break;
    case SPELL_Ice_Storm: os << "SPELL_Ice_Storm"; break;
    case SPELL_Earthquake: os << "SPELL_Earthquake"; break;
    case SPELL_Gorgons: os << "SPELL_Gorgons"; break;
    case SPELL_Move_Fortress: os << "SPELL_Move_Fortress"; break;
    case SPELL_Gaias_Blessing: os << "SPELL_Gaias_Blessing"; break;
    case SPELL_Earth_Elemental: os << "SPELL_Earth_Elemental"; break;
    case SPELL_Regeneration: os << "SPELL_Regeneration"; break;
    case SPELL_Behemoth: os << "SPELL_Behemoth"; break;
    case SPELL_Entangle: os << "SPELL_Entangle"; break;
    case SPELL_Nature_Awareness: os << "SPELL_Nature_Awareness"; break;
    case SPELL_Call_Lightning: os << "SPELL_Call_Lightning"; break;
    case SPELL_Colossus: os << "SPELL_Colossus"; break;
    case SPELL_Earth_Gate: os << "SPELL_Earth_Gate"; break;
    case SPELL_Herb_Mastery: os << "SPELL_Herb_Mastery"; break;
    case SPELL_Great_Wyrm: os << "SPELL_Great_Wyrm"; break;
    case SPELL_Natures_Wrath: os << "SPELL_Natures_Wrath"; break;
    case SPELL_Resist_Magic: os << "SPELL_Resist_Magic"; break;
    case SPELL_Dispel_Magic_True: os << "SPELL_Dispel_Magic_True"; break;
    case SPELL_Floating_Island: os << "SPELL_Floating_Island"; break;
    case SPELL_Guardian_Wind: os << "SPELL_Guardian_Wind"; break;
    case SPELL_Phantom_Warriors: os << "SPELL_Phantom_Warriors"; break;
    case SPELL_Confusion: os << "SPELL_Confusion"; break;
    case SPELL_Word_of_Recall: os << "SPELL_Word_of_Recall"; break;
    case SPELL_Counter_Magic: os << "SPELL_Counter_Magic"; break;
    case SPELL_Nagas: os << "SPELL_Nagas"; break;
    case SPELL_Psionic_Blast: os << "SPELL_Psionic_Blast"; break;
    case SPELL_Blur: os << "SPELL_Blur"; break;
    case SPELL_Disenchant_True: os << "SPELL_Disenchant_True"; break;
    case SPELL_Vertigo: os << "SPELL_Vertigo"; break;
    case SPELL_Spell_Lock: os << "SPELL_Spell_Lock"; break;
    case SPELL_Enchant_Road: os << "SPELL_Enchant_Road"; break;
    case SPELL_Flight: os << "SPELL_Flight"; break;
    case SPELL_Wind_Mastery: os << "SPELL_Wind_Mastery"; break;
    case SPELL_Spell_Blast: os << "SPELL_Spell_Blast"; break;
    case SPELL_Aura_of_Majesty: os << "SPELL_Aura_of_Majesty"; break;
    case SPELL_Phantom_Beast: os << "SPELL_Phantom_Beast"; break;
    case SPELL_Disjunction_True: os << "SPELL_Disjunction_True"; break;
    case SPELL_Invisibility: os << "SPELL_Invisibility"; break;
    case SPELL_Wind_Walking: os << "SPELL_Wind_Walking"; break;
    case SPELL_Banish: os << "SPELL_Banish"; break;
    case SPELL_Storm_Giant: os << "SPELL_Storm_Giant"; break;
    case SPELL_Air_Elemental: os << "SPELL_Air_Elemental"; break;
    case SPELL_Mind_Storm: os << "SPELL_Mind_Storm"; break;
    case SPELL_Stasis: os << "SPELL_Stasis"; break;
    case SPELL_Magic_Immunity: os << "SPELL_Magic_Immunity"; break;
    case SPELL_Haste: os << "SPELL_Haste"; break;
    case SPELL_Djinn: os << "SPELL_Djinn"; break;
    case SPELL_Spell_Ward: os << "SPELL_Spell_Ward"; break;
    case SPELL_Creature_Binding: os << "SPELL_Creature_Binding"; break;
    case SPELL_Mass_Invisibility: os << "SPELL_Mass_Invisibility"; break;
    case SPELL_Great_Unsummoning: os << "SPELL_Great_Unsummoning"; break;
    case SPELL_Spell_Binding: os << "SPELL_Spell_Binding"; break;
    case SPELL_Flying_Fortress: os << "SPELL_Flying_Fortress"; break;
    case SPELL_Sky_Drake: os << "SPELL_Sky_Drake"; break;
    case SPELL_Suppress_Magic: os << "SPELL_Suppress_Magic"; break;
    case SPELL_Time_Stop: os << "SPELL_Time_Stop"; break;
    case SPELL_Warp_Wood: os << "SPELL_Warp_Wood"; break;
    case SPELL_Disrupt: os << "SPELL_Disrupt"; break;
    case SPELL_Fire_Bolt: os << "SPELL_Fire_Bolt"; break;
    case SPELL_Hell_Hounds: os << "SPELL_Hell_Hounds"; break;
    case SPELL_Corruption: os << "SPELL_Corruption"; break;
    case SPELL_Eldritch_Weapon: os << "SPELL_Eldritch_Weapon"; break;
    case SPELL_Wall_of_Fire: os << "SPELL_Wall_of_Fire"; break;
    case SPELL_Shatter: os << "SPELL_Shatter"; break;
    case SPELL_Warp_Creature: os << "SPELL_Warp_Creature"; break;
    case SPELL_Fire_Elemental: os << "SPELL_Fire_Elemental"; break;
    case SPELL_Lightning_Bolt: os << "SPELL_Lightning_Bolt"; break;
    case SPELL_Fire_Giant: os << "SPELL_Fire_Giant"; break;
    case SPELL_Chaos_Channels: os << "SPELL_Chaos_Channels"; break;
    case SPELL_Flame_Blade: os << "SPELL_Flame_Blade"; break;
    case SPELL_Gargoyles: os << "SPELL_Gargoyles"; break;
    case SPELL_Fireball: os << "SPELL_Fireball"; break;
    case SPELL_Doombat: os << "SPELL_Doombat"; break;
    case SPELL_Raise_Volcano: os << "SPELL_Raise_Volcano"; break;
    case SPELL_Immolation: os << "SPELL_Immolation"; break;
    case SPELL_Chimeras: os << "SPELL_Chimeras"; break;
    case SPELL_Warp_Lightning: os << "SPELL_Warp_Lightning"; break;
    case SPELL_Metal_Fires: os << "SPELL_Metal_Fires"; break;
    case SPELL_Chaos_Spawn: os << "SPELL_Chaos_Spawn"; break;
    case SPELL_Doom_Bolt: os << "SPELL_Doom_Bolt"; break;
    case SPELL_Magic_Vortex: os << "SPELL_Magic_Vortex"; break;
    case SPELL_Efreet: os << "SPELL_Efreet"; break;
    case SPELL_Fire_Storm: os << "SPELL_Fire_Storm"; break;
    case SPELL_Warp_Reality: os << "SPELL_Warp_Reality"; break;
    case SPELL_Flame_Strike: os << "SPELL_Flame_Strike"; break;
    case SPELL_Chaos_Rift: os << "SPELL_Chaos_Rift"; break;
    case SPELL_Hydra: os << "SPELL_Hydra"; break;
    case SPELL_Disintegrate: os << "SPELL_Disintegrate"; break;
    case SPELL_Meteor_Storm: os << "SPELL_Meteor_Storm"; break;
    case SPELL_Great_Wasting: os << "SPELL_Great_Wasting"; break;
    case SPELL_Call_Chaos: os << "SPELL_Call_Chaos"; break;
    case SPELL_Chaos_Surge: os << "SPELL_Chaos_Surge"; break;
    case SPELL_Doom_Mastery: os << "SPELL_Doom_Mastery"; break;
    case SPELL_Great_Drake: os << "SPELL_Great_Drake"; break;
    case SPELL_Call_The_Void: os << "SPELL_Call_The_Void"; break;
    case SPELL_Armageddon: os << "SPELL_Armageddon"; break;
    case SPELL_Bless: os << "SPELL_Bless"; break;
    case SPELL_Star_Fires: os << "SPELL_Star_Fires"; break;
    case SPELL_Endurance: os << "SPELL_Endurance"; break;
    case SPELL_Holy_Weapon: os << "SPELL_Holy_Weapon"; break;
    case SPELL_Healing: os << "SPELL_Healing"; break;
    case SPELL_Holy_Armor: os << "SPELL_Holy_Armor"; break;
    case SPELL_Just_Cause: os << "SPELL_Just_Cause"; break;
    case SPELL_True_Light: os << "SPELL_True_Light"; break;
    case SPELL_Guardian_Spirit: os << "SPELL_Guardian_Spirit"; break;
    case SPELL_Heroism: os << "SPELL_Heroism"; break;
    case SPELL_True_Sight: os << "SPELL_True_Sight"; break;
    case SPELL_Plane_Shift: os << "SPELL_Plane_Shift"; break;
    case SPELL_Resurrection: os << "SPELL_Resurrection"; break;
    case SPELL_Dispel_Evil: os << "SPELL_Dispel_Evil"; break;
    case SPELL_Planar_Seal: os << "SPELL_Planar_Seal"; break;
    case SPELL_Unicorns: os << "SPELL_Unicorns"; break;
    case SPELL_Raise_Dead: os << "SPELL_Raise_Dead"; break;
    case SPELL_Planar_Travel: os << "SPELL_Planar_Travel"; break;
    case SPELL_Heavenly_Light: os << "SPELL_Heavenly_Light"; break;
    case SPELL_Prayer: os << "SPELL_Prayer"; break;
    case SPELL_Lionheart: os << "SPELL_Lionheart"; break;
    case SPELL_Incarnation: os << "SPELL_Incarnation"; break;
    case SPELL_Invulnerability: os << "SPELL_Invulnerability"; break;
    case SPELL_Righteousness: os << "SPELL_Righteousness"; break;
    case SPELL_Prosperity: os << "SPELL_Prosperity"; break;
    case SPELL_Altar_of_Battle: os << "SPELL_Altar_of_Battle"; break;
    case SPELL_Angel: os << "SPELL_Angel"; break;
    case SPELL_Stream_of_Life: os << "SPELL_Stream_of_Life"; break;
    case SPELL_Mass_Healing: os << "SPELL_Mass_Healing"; break;
    case SPELL_Holy_Word: os << "SPELL_Holy_Word"; break;
    case SPELL_High_Prayer: os << "SPELL_High_Prayer"; break;
    case SPELL_Inspirations: os << "SPELL_Inspirations"; break;
    case SPELL_Astral_Gate: os << "SPELL_Astral_Gate"; break;
    case SPELL_Holy_Arms: os << "SPELL_Holy_Arms"; break;
    case SPELL_Consecration: os << "SPELL_Consecration"; break;
    case SPELL_Life_Force: os << "SPELL_Life_Force"; break;
    case SPELL_Tranquility: os << "SPELL_Tranquility"; break;
    case SPELL_Crusade: os << "SPELL_Crusade"; break;
    case SPELL_Arch_Angel: os << "SPELL_Arch_Angel"; break;
    case SPELL_Charm_of_Life: os << "SPELL_Charm_of_Life"; break;
    case SPELL_Skeletons: os << "SPELL_Skeletons"; break;
    case SPELL_Weakness: os << "SPELL_Weakness"; break;
    case SPELL_Dark_Rituals: os << "SPELL_Dark_Rituals"; break;
    case SPELL_Cloak_of_Fear: os << "SPELL_Cloak_of_Fear"; break;
    case SPELL_Black_Sleep: os << "SPELL_Black_Sleep"; break;
    case SPELL_Ghouls: os << "SPELL_Ghouls"; break;
    case SPELL_Life_Drain: os << "SPELL_Life_Drain"; break;
    case SPELL_Terror: os << "SPELL_Terror"; break;
    case SPELL_Darkness: os << "SPELL_Darkness"; break;
    case SPELL_Mana_Leak: os << "SPELL_Mana_Leak"; break;
    case SPELL_Drain_Power: os << "SPELL_Drain_Power"; break;
    case SPELL_Possession: os << "SPELL_Possession"; break;
    case SPELL_Lycantrophy: os << "SPELL_Lycantrophy"; break;
    case SPELL_Black_Prayer: os << "SPELL_Black_Prayer"; break;
    case SPELL_Black_Channels: os << "SPELL_Black_Channels"; break;
    case SPELL_Night_Stalker: os << "SPELL_Night_Stalker"; break;
    case SPELL_Subversion: os << "SPELL_Subversion"; break;
    case SPELL_Wall_of_Darkness: os << "SPELL_Wall_of_Darkness"; break;
    case SPELL_Berserk: os << "SPELL_Berserk"; break;
    case SPELL_Shadow_Demons: os << "SPELL_Shadow_Demons"; break;
    case SPELL_Wraith_Form: os << "SPELL_Wraith_Form"; break;
    case SPELL_Wrack: os << "SPELL_Wrack"; break;
    case SPELL_Evil_Presence: os << "SPELL_Evil_Presence"; break;
    case SPELL_Wraiths: os << "SPELL_Wraiths"; break;
    case SPELL_Cloud_Of_Shadow: os << "SPELL_Cloud_Of_Shadow"; break;
    case SPELL_Warp_Node: os << "SPELL_Warp_Node"; break;
    case SPELL_Black_Wind: os << "SPELL_Black_Wind"; break;
    case SPELL_Zombie_Mastery: os << "SPELL_Zombie_Mastery"; break;
    case SPELL_Famine: os << "SPELL_Famine"; break;
    case SPELL_Cursed_Lands: os << "SPELL_Cursed_Lands"; break;
    case SPELL_Cruel_Unminding: os << "SPELL_Cruel_Unminding"; break;
    case SPELL_Word_of_Death: os << "SPELL_Word_of_Death"; break;
    case SPELL_Death_Knights: os << "SPELL_Death_Knights"; break;
    case SPELL_Death_Spell: os << "SPELL_Death_Spell"; break;
    case SPELL_Animate_dead: os << "SPELL_Animate_dead"; break;
    case SPELL_Pestilence: os << "SPELL_Pestilence"; break;
    case SPELL_Eternal_Night: os << "SPELL_Eternal_Night"; break;
    case SPELL_Evil_Omens: os << "SPELL_Evil_Omens"; break;
    case SPELL_Death_Wish: os << "SPELL_Death_Wish"; break;
    case SPELL_Demon_Lord: os << "SPELL_Demon_Lord"; break;
    case SPELL_Magic_Spirit: os << "SPELL_Magic_Spirit"; break;
    case SPELL_Dispel_Magic: os << "SPELL_Dispel_Magic"; break;
    case SPELL_Summoning_Circle: os << "SPELL_Summoning_Circle"; break;
    case SPELL_Disenchant_Area: os << "SPELL_Disenchant_Area"; break;
    case SPELL_Recall_Hero: os << "SPELL_Recall_Hero"; break;
    case SPELL_Detect_Magic: os << "SPELL_Detect_Magic"; break;
    case SPELL_Enchant_Item: os << "SPELL_Enchant_Item"; break;
    case SPELL_Summon_Hero: os << "SPELL_Summon_Hero"; break;
    case SPELL_Awareness: os << "SPELL_Awareness"; break;
    case SPELL_Disjunction: os << "SPELL_Disjunction"; break;
    case SPELL_Create_Artifact: os << "SPELL_Create_Artifact"; break;
    case SPELL_Summon_Champion: os << "SPELL_Summon_Champion"; break;
    case SPELL_Spell_Of_Mastery: os << "SPELL_Spell_Of_Mastery"; break;
    case SPELL_Spell_Of_Return: os << "SPELL_Spell_Of_Return"; break;
    case eSpell_MAX: os << "eSpell_MAX"; break;
    default: os << "<Unknown eSpell>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eSpell16& rhs)
{
    switch (rhs)
    {
    case SPELL16_None: os << "SPELL16_None"; break;
    case SPELL16_Earth_to_Mud: os << "SPELL16_Earth_to_Mud"; break;
    case SPELL16_Resist_Elements: os << "SPELL16_Resist_Elements"; break;
    case SPELL16_Wall_of_Stone: os << "SPELL16_Wall_of_Stone"; break;
    case SPELL16_Giant_Strength: os << "SPELL16_Giant_Strength"; break;
    case SPELL16_Web: os << "SPELL16_Web"; break;
    case SPELL16_War_Bears: os << "SPELL16_War_Bears"; break;
    case SPELL16_Stone_Skin: os << "SPELL16_Stone_Skin"; break;
    case SPELL16_Water_Walking: os << "SPELL16_Water_Walking"; break;
    case SPELL16_Sprites: os << "SPELL16_Sprites"; break;
    case SPELL16_Earth_Lore: os << "SPELL16_Earth_Lore"; break;
    case SPELL16_Cracks_Call: os << "SPELL16_Cracks_Call"; break;
    case SPELL16_Natures_Eye: os << "SPELL16_Natures_Eye"; break;
    case SPELL16_Ice_Bolt: os << "SPELL16_Ice_Bolt"; break;
    case SPELL16_Giant_Spiders: os << "SPELL16_Giant_Spiders"; break;
    case SPELL16_Change_Terrain: os << "SPELL16_Change_Terrain"; break;
    case SPELL16_Path_Finding: os << "SPELL16_Path_Finding"; break;
    case SPELL16_Cockatrices: os << "SPELL16_Cockatrices"; break;
    case SPELL16_Transmute: os << "SPELL16_Transmute"; break;
    case SPELL16_Natures_Cures: os << "SPELL16_Natures_Cures"; break;
    case SPELL16_Basilisk: os << "SPELL16_Basilisk"; break;
    case SPELL16_Elemental_Armor: os << "SPELL16_Elemental_Armor"; break;
    case SPELL16_Petrify: os << "SPELL16_Petrify"; break;
    case SPELL16_Stone_Giant: os << "SPELL16_Stone_Giant"; break;
    case SPELL16_Iron_Skin: os << "SPELL16_Iron_Skin"; break;
    case SPELL16_Ice_Storm: os << "SPELL16_Ice_Storm"; break;
    case SPELL16_Earthquake: os << "SPELL16_Earthquake"; break;
    case SPELL16_Gorgons: os << "SPELL16_Gorgons"; break;
    case SPELL16_Move_Fortress: os << "SPELL16_Move_Fortress"; break;
    case SPELL16_Gaias_Blessing: os << "SPELL16_Gaias_Blessing"; break;
    case SPELL16_Earth_Elemental: os << "SPELL16_Earth_Elemental"; break;
    case SPELL16_Regeneration: os << "SPELL16_Regeneration"; break;
    case SPELL16_Behemoth: os << "SPELL16_Behemoth"; break;
    case SPELL16_Entangle: os << "SPELL16_Entangle"; break;
    case SPELL16_Nature_Awareness: os << "SPELL16_Nature_Awareness"; break;
    case SPELL16_Call_Lightning: os << "SPELL16_Call_Lightning"; break;
    case SPELL16_Colossus: os << "SPELL16_Colossus"; break;
    case SPELL16_Earth_Gate: os << "SPELL16_Earth_Gate"; break;
    case SPELL16_Herb_Mastery: os << "SPELL16_Herb_Mastery"; break;
    case SPELL16_Great_Wyrm: os << "SPELL16_Great_Wyrm"; break;
    case SPELL16_Natures_Wrath: os << "SPELL16_Natures_Wrath"; break;
    case SPELL16_Resist_Magic: os << "SPELL16_Resist_Magic"; break;
    case SPELL16_Dispel_Magic_True: os << "SPELL16_Dispel_Magic_True"; break;
    case SPELL16_Floating_Island: os << "SPELL16_Floating_Island"; break;
    case SPELL16_Guardian_Wind: os << "SPELL16_Guardian_Wind"; break;
    case SPELL16_Phantom_Warriors: os << "SPELL16_Phantom_Warriors"; break;
    case SPELL16_Confusion: os << "SPELL16_Confusion"; break;
    case SPELL16_Word_of_Recall: os << "SPELL16_Word_of_Recall"; break;
    case SPELL16_Counter_Magic: os << "SPELL16_Counter_Magic"; break;
    case SPELL16_Nagas: os << "SPELL16_Nagas"; break;
    case SPELL16_Psionic_Blast: os << "SPELL16_Psionic_Blast"; break;
    case SPELL16_Blur: os << "SPELL16_Blur"; break;
    case SPELL16_Disenchant_True: os << "SPELL16_Disenchant_True"; break;
    case SPELL16_Vertigo: os << "SPELL16_Vertigo"; break;
    case SPELL16_Spell_Lock: os << "SPELL16_Spell_Lock"; break;
    case SPELL16_Enchant_Road: os << "SPELL16_Enchant_Road"; break;
    case SPELL16_Flight: os << "SPELL16_Flight"; break;
    case SPELL16_Wind_Mastery: os << "SPELL16_Wind_Mastery"; break;
    case SPELL16_Spell_Blast: os << "SPELL16_Spell_Blast"; break;
    case SPELL16_Aura_of_Majesty: os << "SPELL16_Aura_of_Majesty"; break;
    case SPELL16_Phantom_Beast: os << "SPELL16_Phantom_Beast"; break;
    case SPELL16_Disjunction_True: os << "SPELL16_Disjunction_True"; break;
    case SPELL16_Invisibility: os << "SPELL16_Invisibility"; break;
    case SPELL16_Wind_Walking: os << "SPELL16_Wind_Walking"; break;
    case SPELL16_Banish: os << "SPELL16_Banish"; break;
    case SPELL16_Storm_Giant: os << "SPELL16_Storm_Giant"; break;
    case SPELL16_Air_Elemental: os << "SPELL16_Air_Elemental"; break;
    case SPELL16_Mind_Storm: os << "SPELL16_Mind_Storm"; break;
    case SPELL16_Stasis: os << "SPELL16_Stasis"; break;
    case SPELL16_Magic_Immunity: os << "SPELL16_Magic_Immunity"; break;
    case SPELL16_Haste: os << "SPELL16_Haste"; break;
    case SPELL16_Djinn: os << "SPELL16_Djinn"; break;
    case SPELL16_Spell_Ward: os << "SPELL16_Spell_Ward"; break;
    case SPELL16_Creature_Binding: os << "SPELL16_Creature_Binding"; break;
    case SPELL16_Mass_Invisibility: os << "SPELL16_Mass_Invisibility"; break;
    case SPELL16_Great_Unsummoning: os << "SPELL16_Great_Unsummoning"; break;
    case SPELL16_Spell_Binding: os << "SPELL16_Spell_Binding"; break;
    case SPELL16_Flying_Fortress: os << "SPELL16_Flying_Fortress"; break;
    case SPELL16_Sky_Drake: os << "SPELL16_Sky_Drake"; break;
    case SPELL16_Suppress_Magic: os << "SPELL16_Suppress_Magic"; break;
    case SPELL16_Time_Stop: os << "SPELL16_Time_Stop"; break;
    case SPELL16_Warp_Wood: os << "SPELL16_Warp_Wood"; break;
    case SPELL16_Disrupt: os << "SPELL16_Disrupt"; break;
    case SPELL16_Fire_Bolt: os << "SPELL16_Fire_Bolt"; break;
    case SPELL16_Hell_Hounds: os << "SPELL16_Hell_Hounds"; break;
    case SPELL16_Corruption: os << "SPELL16_Corruption"; break;
    case SPELL16_Eldritch_Weapon: os << "SPELL16_Eldritch_Weapon"; break;
    case SPELL16_Wall_of_Fire: os << "SPELL16_Wall_of_Fire"; break;
    case SPELL16_Shatter: os << "SPELL16_Shatter"; break;
    case SPELL16_Warp_Creature: os << "SPELL16_Warp_Creature"; break;
    case SPELL16_Fire_Elemental: os << "SPELL16_Fire_Elemental"; break;
    case SPELL16_Lightning_Bolt: os << "SPELL16_Lightning_Bolt"; break;
    case SPELL16_Fire_Giant: os << "SPELL16_Fire_Giant"; break;
    case SPELL16_Chaos_Channels: os << "SPELL16_Chaos_Channels"; break;
    case SPELL16_Flame_Blade: os << "SPELL16_Flame_Blade"; break;
    case SPELL16_Gargoyles: os << "SPELL16_Gargoyles"; break;
    case SPELL16_Fireball: os << "SPELL16_Fireball"; break;
    case SPELL16_Doombat: os << "SPELL16_Doombat"; break;
    case SPELL16_Raise_Volcano: os << "SPELL16_Raise_Volcano"; break;
    case SPELL16_Immolation: os << "SPELL16_Immolation"; break;
    case SPELL16_Chimeras: os << "SPELL16_Chimeras"; break;
    case SPELL16_Warp_Lightning: os << "SPELL16_Warp_Lightning"; break;
    case SPELL16_Metal_Fires: os << "SPELL16_Metal_Fires"; break;
    case SPELL16_Chaos_Spawn: os << "SPELL16_Chaos_Spawn"; break;
    case SPELL16_Doom_Bolt: os << "SPELL16_Doom_Bolt"; break;
    case SPELL16_Magic_Vortex: os << "SPELL16_Magic_Vortex"; break;
    case SPELL16_Efreet: os << "SPELL16_Efreet"; break;
    case SPELL16_Fire_Storm: os << "SPELL16_Fire_Storm"; break;
    case SPELL16_Warp_Reality: os << "SPELL16_Warp_Reality"; break;
    case SPELL16_Flame_Strike: os << "SPELL16_Flame_Strike"; break;
    case SPELL16_Chaos_Rift: os << "SPELL16_Chaos_Rift"; break;
    case SPELL16_Hydra: os << "SPELL16_Hydra"; break;
    case SPELL16_Disintegrate: os << "SPELL16_Disintegrate"; break;
    case SPELL16_Meteor_Storm: os << "SPELL16_Meteor_Storm"; break;
    case SPELL16_Great_Wasting: os << "SPELL16_Great_Wasting"; break;
    case SPELL16_Call_Chaos: os << "SPELL16_Call_Chaos"; break;
    case SPELL16_Chaos_Surge: os << "SPELL16_Chaos_Surge"; break;
    case SPELL16_Doom_Mastery: os << "SPELL16_Doom_Mastery"; break;
    case SPELL16_Great_Drake: os << "SPELL16_Great_Drake"; break;
    case SPELL16_Call_The_Void: os << "SPELL16_Call_The_Void"; break;
    case SPELL16_Armageddon: os << "SPELL16_Armageddon"; break;
    case SPELL16_Bless: os << "SPELL16_Bless"; break;
    case SPELL16_Star_Fires: os << "SPELL16_Star_Fires"; break;
    case SPELL16_Endurance: os << "SPELL16_Endurance"; break;
    case SPELL16_Holy_Weapon: os << "SPELL16_Holy_Weapon"; break;
    case SPELL16_Healing: os << "SPELL16_Healing"; break;
    case SPELL16_Holy_Armor: os << "SPELL16_Holy_Armor"; break;
    case SPELL16_Just_Cause: os << "SPELL16_Just_Cause"; break;
    case SPELL16_True_Light: os << "SPELL16_True_Light"; break;
    case SPELL16_Guardian_Spirit: os << "SPELL16_Guardian_Spirit"; break;
    case SPELL16_Heroism: os << "SPELL16_Heroism"; break;
    case SPELL16_True_Sight: os << "SPELL16_True_Sight"; break;
    case SPELL16_Plane_Shift: os << "SPELL16_Plane_Shift"; break;
    case SPELL16_Resurrection: os << "SPELL16_Resurrection"; break;
    case SPELL16_Dispel_Evil: os << "SPELL16_Dispel_Evil"; break;
    case SPELL16_Planar_Seal: os << "SPELL16_Planar_Seal"; break;
    case SPELL16_Unicorns: os << "SPELL16_Unicorns"; break;
    case SPELL16_Raise_Dead: os << "SPELL16_Raise_Dead"; break;
    case SPELL16_Planar_Travel: os << "SPELL16_Planar_Travel"; break;
    case SPELL16_Heavenly_Light: os << "SPELL16_Heavenly_Light"; break;
    case SPELL16_Prayer: os << "SPELL16_Prayer"; break;
    case SPELL16_Lionheart: os << "SPELL16_Lionheart"; break;
    case SPELL16_Incarnation: os << "SPELL16_Incarnation"; break;
    case SPELL16_Invulnerability: os << "SPELL16_Invulnerability"; break;
    case SPELL16_Righteousness: os << "SPELL16_Righteousness"; break;
    case SPELL16_Prosperity: os << "SPELL16_Prosperity"; break;
    case SPELL16_Altar_of_Battle: os << "SPELL16_Altar_of_Battle"; break;
    case SPELL16_Angel: os << "SPELL16_Angel"; break;
    case SPELL16_Stream_of_Life: os << "SPELL16_Stream_of_Life"; break;
    case SPELL16_Mass_Healing: os << "SPELL16_Mass_Healing"; break;
    case SPELL16_Holy_Word: os << "SPELL16_Holy_Word"; break;
    case SPELL16_High_Prayer: os << "SPELL16_High_Prayer"; break;
    case SPELL16_Inspirations: os << "SPELL16_Inspirations"; break;
    case SPELL16_Astral_Gate: os << "SPELL16_Astral_Gate"; break;
    case SPELL16_Holy_Arms: os << "SPELL16_Holy_Arms"; break;
    case SPELL16_Consecration: os << "SPELL16_Consecration"; break;
    case SPELL16_Life_Force: os << "SPELL16_Life_Force"; break;
    case SPELL16_Tranquility: os << "SPELL16_Tranquility"; break;
    case SPELL16_Crusade: os << "SPELL16_Crusade"; break;
    case SPELL16_Arch_Angel: os << "SPELL16_Arch_Angel"; break;
    case SPELL16_Charm_of_Life: os << "SPELL16_Charm_of_Life"; break;
    case SPELL16_Skeletons: os << "SPELL16_Skeletons"; break;
    case SPELL16_Weakness: os << "SPELL16_Weakness"; break;
    case SPELL16_Dark_Rituals: os << "SPELL16_Dark_Rituals"; break;
    case SPELL16_Cloak_of_Fear: os << "SPELL16_Cloak_of_Fear"; break;
    case SPELL16_Black_Sleep: os << "SPELL16_Black_Sleep"; break;
    case SPELL16_Ghouls: os << "SPELL16_Ghouls"; break;
    case SPELL16_Life_Drain: os << "SPELL16_Life_Drain"; break;
    case SPELL16_Terror: os << "SPELL16_Terror"; break;
    case SPELL16_Darkness: os << "SPELL16_Darkness"; break;
    case SPELL16_Mana_Leak: os << "SPELL16_Mana_Leak"; break;
    case SPELL16_Drain_Power: os << "SPELL16_Drain_Power"; break;
    case SPELL16_Possession: os << "SPELL16_Possession"; break;
    case SPELL16_Lycantrophy: os << "SPELL16_Lycantrophy"; break;
    case SPELL16_Black_Prayer: os << "SPELL16_Black_Prayer"; break;
    case SPELL16_Black_Channels: os << "SPELL16_Black_Channels"; break;
    case SPELL16_Night_Stalker: os << "SPELL16_Night_Stalker"; break;
    case SPELL16_Subversion: os << "SPELL16_Subversion"; break;
    case SPELL16_Wall_of_Darkness: os << "SPELL16_Wall_of_Darkness"; break;
    case SPELL16_Berserk: os << "SPELL16_Berserk"; break;
    case SPELL16_Shadow_Demons: os << "SPELL16_Shadow_Demons"; break;
    case SPELL16_Wraith_Form: os << "SPELL16_Wraith_Form"; break;
    case SPELL16_Wrack: os << "SPELL16_Wrack"; break;
    case SPELL16_Evil_Presence: os << "SPELL16_Evil_Presence"; break;
    case SPELL16_Wraiths: os << "SPELL16_Wraiths"; break;
    case SPELL16_Cloud_Of_Shadow: os << "SPELL16_Cloud_Of_Shadow"; break;
    case SPELL16_Warp_Node: os << "SPELL16_Warp_Node"; break;
    case SPELL16_Black_Wind: os << "SPELL16_Black_Wind"; break;
    case SPELL16_Zombie_Mastery: os << "SPELL16_Zombie_Mastery"; break;
    case SPELL16_Famine: os << "SPELL16_Famine"; break;
    case SPELL16_Cursed_Lands: os << "SPELL16_Cursed_Lands"; break;
    case SPELL16_Cruel_Unminding: os << "SPELL16_Cruel_Unminding"; break;
    case SPELL16_Word_of_Death: os << "SPELL16_Word_of_Death"; break;
    case SPELL16_Death_Knights: os << "SPELL16_Death_Knights"; break;
    case SPELL16_Death_Spell: os << "SPELL16_Death_Spell"; break;
    case SPELL16_Animate_dead: os << "SPELL16_Animate_dead"; break;
    case SPELL16_Pestilence: os << "SPELL16_Pestilence"; break;
    case SPELL16_Eternal_Night: os << "SPELL16_Eternal_Night"; break;
    case SPELL16_Evil_Omens: os << "SPELL16_Evil_Omens"; break;
    case SPELL16_Death_Wish: os << "SPELL16_Death_Wish"; break;
    case SPELL16_Demon_Lord: os << "SPELL16_Demon_Lord"; break;
    case SPELL16_Magic_Spirit: os << "SPELL16_Magic_Spirit"; break;
    case SPELL16_Dispel_Magic: os << "SPELL16_Dispel_Magic"; break;
    case SPELL16_Summoning_Circle: os << "SPELL16_Summoning_Circle"; break;
    case SPELL16_Disenchant_Area: os << "SPELL16_Disenchant_Area"; break;
    case SPELL16_Recall_Hero: os << "SPELL16_Recall_Hero"; break;
    case SPELL16_Detect_Magic: os << "SPELL16_Detect_Magic"; break;
    case SPELL16_Enchant_Item: os << "SPELL16_Enchant_Item"; break;
    case SPELL16_Summon_Hero: os << "SPELL16_Summon_Hero"; break;
    case SPELL16_Awareness: os << "SPELL16_Awareness"; break;
    case SPELL16_Disjunction: os << "SPELL16_Disjunction"; break;
    case SPELL16_Create_Artifact: os << "SPELL16_Create_Artifact"; break;
    case SPELL16_Summon_Champion: os << "SPELL16_Summon_Champion"; break;
    case SPELL16_Spell_Of_Mastery: os << "SPELL16_Spell_Of_Mastery"; break;
    case SPELL16_Spell_Of_Return: os << "SPELL16_Spell_Of_Return"; break;
    case eSpell16_MAX: os << "eSpell16_MAX"; break;
    default: os << "<Unknown eSpell16>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eSpellCategory& rhs)
{
    switch (rhs)
    {
    case SPELLCATEGORY_Normal_summon: os << "SPELLCATEGORY_Normal_summon"; break;
    case SPELLCATEGORY_Unit_enchantment: os << "SPELLCATEGORY_Unit_enchantment"; break;
    case SPELLCATEGORY_Friendly_City_enchantment: os << "SPELLCATEGORY_Friendly_City_enchantment"; break;
    case SPELLCATEGORY_Hostile_City_enchantment: os << "SPELLCATEGORY_Hostile_City_enchantment"; break;
    case SPELLCATEGORY_Fixed_damage: os << "SPELLCATEGORY_Fixed_damage"; break;
    case SPELLCATEGORY_Special: os << "SPELLCATEGORY_Special"; break;
    case SPELLCATEGORY_Target_wizard: os << "SPELLCATEGORY_Target_wizard"; break;
    case SPELLCATEGORY_Global_enchantment: os << "SPELLCATEGORY_Global_enchantment"; break;
    case SPELLCATEGORY_Battle: os << "SPELLCATEGORY_Battle"; break;
    case SPELLCATEGORY_Create_item: os << "SPELLCATEGORY_Create_item"; break;
    case SPELLCATEGORY_Destroy_unit: os << "SPELLCATEGORY_Destroy_unit"; break;
    case SPELLCATEGORY_Resistable_Combat_enchantment: os << "SPELLCATEGORY_Resistable_Combat_enchantment"; break;
    case SPELLCATEGORY_Unresistable_Combat_enchantment: os << "SPELLCATEGORY_Unresistable_Combat_enchantment"; break;
    case SPELLCATEGORY_Mundane_Unit_enchantment: os << "SPELLCATEGORY_Mundane_Unit_enchantment"; break;
    case SPELLCATEGORY_Mundane_Combat_enchantment: os << "SPELLCATEGORY_Mundane_Combat_enchantment"; break;
    case SPELLCATEGORY_Dispel: os << "SPELLCATEGORY_Dispel"; break;
    case SPELLCATEGORY_Disenchant: os << "SPELLCATEGORY_Disenchant"; break;
    case SPELLCATEGORY_Disjunction: os << "SPELLCATEGORY_Disjunction"; break;
    case SPELLCATEGORY_Counter: os << "SPELLCATEGORY_Counter"; break;
    case SPELLCATEGORY_Variable_damage: os << "SPELLCATEGORY_Variable_damage"; break;
    case SPELLCATEGORY_Banish: os << "SPELLCATEGORY_Banish"; break;
    case eSpellCategory_MAX: os << "eSpellCategory_MAX"; break;
    default: os << "<Unknown eSpellCategory>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eSpellKnown& rhs)
{
    switch (rhs)
    {
    case SPELLKNOWN_unknown: os << "SPELLKNOWN_unknown"; break;
    case SPELLKNOWN_knowable: os << "SPELLKNOWN_knowable"; break;
    case SPELLKNOWN_currently_known: os << "SPELLKNOWN_currently_known"; break;
    case SPELLKNOWN_researchable: os << "SPELLKNOWN_researchable"; break;
    case eSpellKnown_MAX: os << "eSpellKnown_MAX"; break;
    default: os << "<Unknown eSpellKnown>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eSpellKnown16& rhs)
{
    switch (rhs)
    {
    case SPELLKNOWN16_unknown: os << "SPELLKNOWN16_unknown"; break;
    case SPELLKNOWN16_knowable: os << "SPELLKNOWN16_knowable"; break;
    case SPELLKNOWN16_currently_known: os << "SPELLKNOWN16_currently_known"; break;
    case SPELLKNOWN16_researchable: os << "SPELLKNOWN16_researchable"; break;
    default: os << "<Unknown eSpellKnown16>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eSpell_Type& rhs)
{
    switch (rhs)
    {
    case SPELLTYPE_Special_Spells: os << "SPELLTYPE_Special_Spells"; break;
    case SPELLTYPE_Summoning: os << "SPELLTYPE_Summoning"; break;
    case SPELLTYPE_Enchantment: os << "SPELLTYPE_Enchantment"; break;
    case SPELLTYPE_City_Spells: os << "SPELLTYPE_City_Spells"; break;
    case SPELLTYPE_Unit_Spells: os << "SPELLTYPE_Unit_Spells"; break;
    case SPELLTYPE_Combat_Spells: os << "SPELLTYPE_Combat_Spells"; break;
    case eSpell_Type_MAX: os << "eSpell_Type_MAX"; break;
    default: os << "<Unknown eSpell_Type>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eTax_Rate& rhs)
{
    switch (rhs)
    {
    case TAX_Rate_1: os << "TAX_Rate_1"; break;
    case TAX_Rate_2: os << "TAX_Rate_2"; break;
    case TAX_Rate_3: os << "TAX_Rate_3"; break;
    case TAX_Rate_4: os << "TAX_Rate_4"; break;
    case TAX_Rate_5: os << "TAX_Rate_5"; break;
    case TAX_Rate_6: os << "TAX_Rate_6"; break;
    case TAX_Rate_7: os << "TAX_Rate_7"; break;
    case eTax_Rate_MAX: os << "eTax_Rate_MAX"; break;
    default: os << "<Unknown eTax_Rate>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eTerrainBattle& rhs)
{
    switch (rhs)
    {
    case TERRAINBATTLE_firstbasic: os << "TERRAINBATTLE_firstbasic"; break;
    case TERRAINBATTLE_lastbasic: os << "TERRAINBATTLE_lastbasic"; break;
    case TERRAINBATTLE_firstextra: os << "TERRAINBATTLE_firstextra"; break;
    case TERRAINBATTLE_lastextra: os << "TERRAINBATTLE_lastextra"; break;
    case eTerrainBattle_MAX: os << "eTerrainBattle_MAX"; break;
    default: os << "<Unknown eTerrainBattle>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eTerrainBonusDeposit& rhs)
{
    switch (rhs)
    {
    case DEPOSIT_no_deposit: os << "DEPOSIT_no_deposit"; break;
    case DEPOSIT_Iron_Ore: os << "DEPOSIT_Iron_Ore"; break;
    case DEPOSIT_Coal: os << "DEPOSIT_Coal"; break;
    case DEPOSIT_Silver_Ore: os << "DEPOSIT_Silver_Ore"; break;
    case DEPOSIT_Gold_Ore: os << "DEPOSIT_Gold_Ore"; break;
    case DEPOSIT_Gems: os << "DEPOSIT_Gems"; break;
    case DEPOSIT_Mithril_Ore: os << "DEPOSIT_Mithril_Ore"; break;
    case DEPOSIT_Adamantium_Ore: os << "DEPOSIT_Adamantium_Ore"; break;
    case DEPOSIT_Quork: os << "DEPOSIT_Quork"; break;
    case DEPOSIT_Crysx: os << "DEPOSIT_Crysx"; break;
    case DEPOSIT_Orihalcon_Ore: os << "DEPOSIT_Orihalcon_Ore"; break;
    case DEPOSIT_Unk_20: os << "DEPOSIT_Unk_20"; break;
    case DEPOSIT_Wild_Game: os << "DEPOSIT_Wild_Game"; break;
    case DEPOSIT_Nightshade: os << "DEPOSIT_Nightshade"; break;
    case eTerrainBonusDeposit_MAX: os << "eTerrainBonusDeposit_MAX"; break;
    default: os << "<Unknown eTerrainBonusDeposit>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eTerrainCategory& rhs)
{
    switch (rhs)
    {
    case TERRAINCATEGORY_Ocean: os << "TERRAINCATEGORY_Ocean"; break;
    case TERRAINCATEGORY_Grasslands: os << "TERRAINCATEGORY_Grasslands"; break;
    case TERRAINCATEGORY_Forest: os << "TERRAINCATEGORY_Forest"; break;
    case TERRAINCATEGORY_Mountain: os << "TERRAINCATEGORY_Mountain"; break;
    case TERRAINCATEGORY_Desert: os << "TERRAINCATEGORY_Desert"; break;
    case TERRAINCATEGORY_Swamp: os << "TERRAINCATEGORY_Swamp"; break;
    case TERRAINCATEGORY_Tundra: os << "TERRAINCATEGORY_Tundra"; break;
    case TERRAINCATEGORY_Shore: os << "TERRAINCATEGORY_Shore"; break;
    case TERRAINCATEGORY_RiverMouth: os << "TERRAINCATEGORY_RiverMouth"; break;
    case TERRAINCATEGORY_Hills: os << "TERRAINCATEGORY_Hills"; break;
    case TERRAINCATEGORY_Plains: os << "TERRAINCATEGORY_Plains"; break;
    case TERRAINCATEGORY_River: os << "TERRAINCATEGORY_River"; break;
    case TERRAINCATEGORY_Volcano: os << "TERRAINCATEGORY_Volcano"; break;
    case TERRAINCATEGORY_SorceryNode: os << "TERRAINCATEGORY_SorceryNode"; break;
    case TERRAINCATEGORY_NatureNode: os << "TERRAINCATEGORY_NatureNode"; break;
    case TERRAINCATEGORY_ChaosNode: os << "TERRAINCATEGORY_ChaosNode"; break;
    case TERRAINCATEGORY_Lake: os << "TERRAINCATEGORY_Lake"; break;
    case eTerrainCategory_MAX: os << "eTerrainCategory_MAX"; break;
    default: os << "<Unknown eTerrainCategory>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eTerrainChange& rhs)
{
    switch (rhs)
    {
    case TERRAINCHANGE_Volcano_you: os << "TERRAINCHANGE_Volcano_you"; break;
    case TERRAINCHANGE_Volcano_player1: os << "TERRAINCHANGE_Volcano_player1"; break;
    case TERRAINCHANGE_Volcano_player3: os << "TERRAINCHANGE_Volcano_player3"; break;
    case TERRAINCHANGE_Road: os << "TERRAINCHANGE_Road"; break;
    case TERRAINCHANGE_Enchanted_Road: os << "TERRAINCHANGE_Enchanted_Road"; break;
    case TERRAINCHANGE_Corruption: os << "TERRAINCHANGE_Corruption"; break;
    case TERRAINCHANGE_Unk_40: os << "TERRAINCHANGE_Unk_40"; break;
    case TERRAINCHANGE_NoRoad80: os << "TERRAINCHANGE_NoRoad80"; break;
    case eTerrainChange_MAX: os << "eTerrainChange_MAX"; break;
    default: os << "<Unknown eTerrainChange>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eTerrainType& rhs)
{
    switch (rhs)
    {
    case ocean1: os << "ocean1"; break;
    case grasslands0: os << "grasslands0"; break;
    case shore1_first: os << "shore1_first"; break;
    case shore1_last: os << "shore1_last"; break;
    case grasslands1: os << "grasslands1"; break;
    case forest1: os << "forest1"; break;
    case mountain1: os << "mountain1"; break;
    case desert1: os << "desert1"; break;
    case swamp1: os << "swamp1"; break;
    case tundra1: os << "tundra1"; break;
    case grasslands_w_sorcery_node: os << "grasslands_w_sorcery_node"; break;
    case forest_w_nature_node: os << "forest_w_nature_node"; break;
    case volcano_w_chaos_node: os << "volcano_w_chaos_node"; break;
    case hills1: os << "hills1"; break;
    case grasslands2: os << "grasslands2"; break;
    case grasslands3: os << "grasslands3"; break;
    case desert2: os << "desert2"; break;
    case desert3: os << "desert3"; break;
    case desert4: os << "desert4"; break;
    case swamp2: os << "swamp2"; break;
    case swamp3: os << "swamp3"; break;
    case volcano: os << "volcano"; break;
    case grasslands4: os << "grasslands4"; break;
    case tundra2: os << "tundra2"; break;
    case tundra3: os << "tundra3"; break;
    case forest2: os << "forest2"; break;
    case forest3: os << "forest3"; break;
    case river1a_first: os << "river1a_first"; break;
    case river1a_last: os << "river1a_last"; break;
    case lake1_first: os << "lake1_first"; break;
    case lake1_last: os << "lake1_last"; break;
    case river2a_first: os << "river2a_first"; break;
    case river2a_last: os << "river2a_last"; break;
    case mountain2_first: os << "mountain2_first"; break;
    case mountain2_last: os << "mountain2_last"; break;
    case hills2_first: os << "hills2_first"; break;
    case hills2_last: os << "hills2_last"; break;
    case desert5_first: os << "desert5_first"; break;
    case desert5_last: os << "desert5_last"; break;
    case shore4_first: os << "shore4_first"; break;
    case shore4_last: os << "shore4_last"; break;
    case river3_first: os << "river3_first"; break;
    case river3_last: os << "river3_last"; break;
    case shore5_first: os << "shore5_first"; break;
    case shore5_last: os << "shore5_last"; break;
    case ocean2: os << "ocean2"; break;
    case tundra4_first: os << "tundra4_first"; break;
    case tundra4_last: os << "tundra4_last"; break;
    case eTerrainType_MAX: os << "eTerrainType_MAX"; break;
    default: os << "<Unknown eTerrainType>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eTower_Node_Lair_Status& rhs)
{
    switch (rhs)
    {
    case LAIRSTATUS_popped: os << "LAIRSTATUS_popped"; break;
    case LAIRSTATUS_intact: os << "LAIRSTATUS_intact"; break;
    case eTower_Node_Lair_Status_MAX: os << "eTower_Node_Lair_Status_MAX"; break;
    default: os << "<Unknown eTower_Node_Lair_Status>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eTower_Node_Lair_Type& rhs)
{
    switch (rhs)
    {
    case LAIRTYPE_Tower: os << "LAIRTYPE_Tower"; break;
    case LAIRTYPE_Chaos_node: os << "LAIRTYPE_Chaos_node"; break;
    case LAIRTYPE_Nature_node: os << "LAIRTYPE_Nature_node"; break;
    case LAIRTYPE_Sorcery_node: os << "LAIRTYPE_Sorcery_node"; break;
    case LAIRTYPE_Mysterious_cave: os << "LAIRTYPE_Mysterious_cave"; break;
    case LAIRTYPE_Dungeon: os << "LAIRTYPE_Dungeon"; break;
    case LAIRTYPE_Ancient_temple: os << "LAIRTYPE_Ancient_temple"; break;
    case LAIRTYPE_Abandoned_keep: os << "LAIRTYPE_Abandoned_keep"; break;
    case LAIRTYPE_Monster_lair: os << "LAIRTYPE_Monster_lair"; break;
    case LAIRTYPE_Ruins: os << "LAIRTYPE_Ruins"; break;
    case LAIRTYPE_Fallen_temple: os << "LAIRTYPE_Fallen_temple"; break;
    case eTower_Node_Lair_Type_MAX: os << "eTower_Node_Lair_Type_MAX"; break;
    default: os << "<Unknown eTower_Node_Lair_Type>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eUnitAbility& rhs)
{
    switch (rhs)
    {
    case eUnitAbility_NONE: os << "eUnitAbility_NONE"; break;
    case UNITABILITY_Cavalry: os << "UNITABILITY_Cavalry"; break;
    case UNITABILITY_Sailing: os << "UNITABILITY_Sailing"; break;
    case UNITABILITY_Swimming: os << "UNITABILITY_Swimming"; break;
    case UNITABILITY_Flying: os << "UNITABILITY_Flying"; break;
    case UNITABILITY_Teleporting: os << "UNITABILITY_Teleporting"; break;
    case UNITABILITY_Forester: os << "UNITABILITY_Forester"; break;
    case UNITABILITY_Mountaineer: os << "UNITABILITY_Mountaineer"; break;
    case UNITABILITY_Merging: os << "UNITABILITY_Merging"; break;
    case UNITABILITY_Fire_Immunity: os << "UNITABILITY_Fire_Immunity"; break;
    case UNITABILITY_Stoning_Immunity: os << "UNITABILITY_Stoning_Immunity"; break;
    case UNITABILITY_Missiles_Immunity: os << "UNITABILITY_Missiles_Immunity"; break;
    case UNITABILITY_Illusions_Immunity: os << "UNITABILITY_Illusions_Immunity"; break;
    case UNITABILITY_Cold_Immunity: os << "UNITABILITY_Cold_Immunity"; break;
    case UNITABILITY_Magic_Immunity: os << "UNITABILITY_Magic_Immunity"; break;
    case UNITABILITY_Death_Immunity: os << "UNITABILITY_Death_Immunity"; break;
    case UNITABILITY_Poison_Immunity: os << "UNITABILITY_Poison_Immunity"; break;
    case UNITABILITY_Weapon_Immunity: os << "UNITABILITY_Weapon_Immunity"; break;
    case UNITABILITY_Flyer: os << "UNITABILITY_Flyer"; break;
    case UNITABILITY_Lucky: os << "UNITABILITY_Lucky"; break;
    case UNITABILITY_Summon_Demons_1: os << "UNITABILITY_Summon_Demons_1"; break;
    case UNITABILITY_Summon_Demons_2: os << "UNITABILITY_Summon_Demons_2"; break;
    case UNITABILITY_Caster_20_MP: os << "UNITABILITY_Caster_20_MP"; break;
    case UNITABILITY_Caster_40_MP: os << "UNITABILITY_Caster_40_MP"; break;
    case UNITABILITY_Standard: os << "UNITABILITY_Standard"; break;
    case UNITABILITY_Healing_Spell: os << "UNITABILITY_Healing_Spell"; break;
    case UNITABILITY_Fire_Ball_Spell: os << "UNITABILITY_Fire_Ball_Spell"; break;
    case UNITABILITY_Doombolt_Spell: os << "UNITABILITY_Doombolt_Spell"; break;
    case UNITABILITY_Immolation: os << "UNITABILITY_Immolation"; break;
    case UNITABILITY_Web_Spell: os << "UNITABILITY_Web_Spell"; break;
    case UNITABILITY_Cause_Fear_Spell: os << "UNITABILITY_Cause_Fear_Spell"; break;
    case UNITABILITY_Resistance_to_All: os << "UNITABILITY_Resistance_to_All"; break;
    case UNITABILITY_Holy_Bonus: os << "UNITABILITY_Holy_Bonus"; break;
    case UNITABILITY_Summoned_Unit: os << "UNITABILITY_Summoned_Unit"; break;
    case UNITABILITY_Large_Shield: os << "UNITABILITY_Large_Shield"; break;
    case UNITABILITY_Plane_Shift: os << "UNITABILITY_Plane_Shift"; break;
    case UNITABILITY_Wall_Crusher: os << "UNITABILITY_Wall_Crusher"; break;
    case UNITABILITY_Healer: os << "UNITABILITY_Healer"; break;
    case UNITABILITY_Create_Outpost: os << "UNITABILITY_Create_Outpost"; break;
    case UNITABILITY_Invisibility: os << "UNITABILITY_Invisibility"; break;
    case UNITABILITY_Create_Undead: os << "UNITABILITY_Create_Undead"; break;
    case UNITABILITY_Long_Range: os << "UNITABILITY_Long_Range"; break;
    case UNITABILITY_Land_Corruption: os << "UNITABILITY_Land_Corruption"; break;
    case UNITABILITY_Meld_With_Node: os << "UNITABILITY_Meld_With_Node"; break;
    case UNITABILITY_Non_Corporeal: os << "UNITABILITY_Non_Corporeal"; break;
    case UNITABILITY_Wind_Walking: os << "UNITABILITY_Wind_Walking"; break;
    case UNITABILITY_Regeneration: os << "UNITABILITY_Regeneration"; break;
    case UNITABILITY_Purify: os << "UNITABILITY_Purify"; break;
    case UNITABILITY_Negate_First_Strike: os << "UNITABILITY_Negate_First_Strike"; break;
    case UNITABILITY_Armor_Piercing: os << "UNITABILITY_Armor_Piercing"; break;
    case UNITABILITY_First_Strike: os << "UNITABILITY_First_Strike"; break;
    case UNITABILITY_Poison_attack: os << "UNITABILITY_Poison_attack"; break;
    case UNITABILITY_Life_Stealing: os << "UNITABILITY_Life_Stealing"; break;
    case UNITABILITY_Automatic_Damage: os << "UNITABILITY_Automatic_Damage"; break;
    case UNITABILITY_Destruction: os << "UNITABILITY_Destruction"; break;
    case UNITABILITY_Illusionary_attack: os << "UNITABILITY_Illusionary_attack"; break;
    case UNITABILITY_Stoning_Touch: os << "UNITABILITY_Stoning_Touch"; break;
    case UNITABILITY_No_effect05: os << "UNITABILITY_No_effect05"; break;
    case UNITABILITY_Death_Touch: os << "UNITABILITY_Death_Touch"; break;
    case UNITABILITY_Power_Drain: os << "UNITABILITY_Power_Drain"; break;
    case UNITABILITY_Dispel_Evil: os << "UNITABILITY_Dispel_Evil"; break;
    case UNITABILITY_Ball_COMBAT: os << "UNITABILITY_Ball_COMBAT"; break;
    case UNITABILITY_Simultaneous_Damage_COMBAT: os << "UNITABILITY_Simultaneous_Damage_COMBAT"; break;
    case UNITABILITY_Eldritch_Weapon_COMBAT: os << "UNITABILITY_Eldritch_Weapon_COMBAT"; break;
    case UNITABILITY_Warp_Lightning_COMBAT: os << "UNITABILITY_Warp_Lightning_COMBAT"; break;
    case eUnitAbility_MAX: os << "eUnitAbility_MAX"; break;
    default: os << "<Unknown eUnitAbility>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eUnitEnchantment& rhs)
{
    switch (rhs)
    {
    case UNITENCHANTMENT_Immolation: os << "UNITENCHANTMENT_Immolation"; break;
    case UNITENCHANTMENT_Guardian_Wind: os << "UNITENCHANTMENT_Guardian_Wind"; break;
    case UNITENCHANTMENT_Berserk: os << "UNITENCHANTMENT_Berserk"; break;
    case UNITENCHANTMENT_Cloak_of_Fear: os << "UNITENCHANTMENT_Cloak_of_Fear"; break;
    case UNITENCHANTMENT_Black_Channels: os << "UNITENCHANTMENT_Black_Channels"; break;
    case UNITENCHANTMENT_Wraith_Form: os << "UNITENCHANTMENT_Wraith_Form"; break;
    case UNITENCHANTMENT_Regeneration: os << "UNITENCHANTMENT_Regeneration"; break;
    case UNITENCHANTMENT_Path_Finding: os << "UNITENCHANTMENT_Path_Finding"; break;
    case UNITENCHANTMENT_Water_Walking: os << "UNITENCHANTMENT_Water_Walking"; break;
    case UNITENCHANTMENT_Resist_Elements: os << "UNITENCHANTMENT_Resist_Elements"; break;
    case UNITENCHANTMENT_Elemental_Armor: os << "UNITENCHANTMENT_Elemental_Armor"; break;
    case UNITENCHANTMENT_Stone_Skin: os << "UNITENCHANTMENT_Stone_Skin"; break;
    case UNITENCHANTMENT_Iron_Skin: os << "UNITENCHANTMENT_Iron_Skin"; break;
    case UNITENCHANTMENT_Endurance: os << "UNITENCHANTMENT_Endurance"; break;
    case UNITENCHANTMENT_Spell_Lock: os << "UNITENCHANTMENT_Spell_Lock"; break;
    case UNITENCHANTMENT_Invisibility: os << "UNITENCHANTMENT_Invisibility"; break;
    case UNITENCHANTMENT_Wind_Walking: os << "UNITENCHANTMENT_Wind_Walking"; break;
    case UNITENCHANTMENT_Flight: os << "UNITENCHANTMENT_Flight"; break;
    case UNITENCHANTMENT_Resist_Magic: os << "UNITENCHANTMENT_Resist_Magic"; break;
    case UNITENCHANTMENT_Magic_Immunity: os << "UNITENCHANTMENT_Magic_Immunity"; break;
    case UNITENCHANTMENT_Flame_Blade: os << "UNITENCHANTMENT_Flame_Blade"; break;
    case UNITENCHANTMENT_Eldritch_Weapon: os << "UNITENCHANTMENT_Eldritch_Weapon"; break;
    case UNITENCHANTMENT_True_Sight: os << "UNITENCHANTMENT_True_Sight"; break;
    case UNITENCHANTMENT_Holy_Weapon: os << "UNITENCHANTMENT_Holy_Weapon"; break;
    case UNITENCHANTMENT_Heroism: os << "UNITENCHANTMENT_Heroism"; break;
    case UNITENCHANTMENT_Bless: os << "UNITENCHANTMENT_Bless"; break;
    case UNITENCHANTMENT_Lionheart: os << "UNITENCHANTMENT_Lionheart"; break;
    case UNITENCHANTMENT_Giant_Strength: os << "UNITENCHANTMENT_Giant_Strength"; break;
    case UNITENCHANTMENT_Planar_Travel: os << "UNITENCHANTMENT_Planar_Travel"; break;
    case UNITENCHANTMENT_Holy_Armor: os << "UNITENCHANTMENT_Holy_Armor"; break;
    case UNITENCHANTMENT_Righteousness: os << "UNITENCHANTMENT_Righteousness"; break;
    case UNITENCHANTMENT_Invulnerability: os << "UNITENCHANTMENT_Invulnerability"; break;
    case eUnitEnchantment_MAX: os << "eUnitEnchantment_MAX"; break;
    default: os << "<Unknown eUnitEnchantment>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eUnitMutation& rhs)
{
    switch (rhs)
    {
    case UNITMUTATION_Chaos_Channels_Demon_Skin: os << "UNITMUTATION_Chaos_Channels_Demon_Skin"; break;
    case UNITMUTATION_Chaos_Channels_Demon_Wings: os << "UNITMUTATION_Chaos_Channels_Demon_Wings"; break;
    case UNITMUTATION_Chaos_Channels_Fiery_Breath: os << "UNITMUTATION_Chaos_Channels_Fiery_Breath"; break;
    case UNITMUTATION_Undead: os << "UNITMUTATION_Undead"; break;
    case UNITMUTATION_Stasis_initial: os << "UNITMUTATION_Stasis_initial"; break;
    case UNITMUTATION_Stasis_lingering: os << "UNITMUTATION_Stasis_lingering"; break;
    case eUnitMutation_MAX: os << "eUnitMutation_MAX"; break;
    default: os << "<Unknown eUnitMutation>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eUnit_Active& rhs)
{
    switch (rhs)
    {
    case UNITACTIVE_awaiting_orders: os << "UNITACTIVE_awaiting_orders"; break;
    case UNITACTIVE_finished: os << "UNITACTIVE_finished"; break;
    case eUnit_Active_MAX: os << "eUnit_Active_MAX"; break;
    default: os << "<Unknown eUnit_Active>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eUnit_Status8& rhs)
{
    switch (rhs)
    {
    case UNITSTATUS8_Ready: os << "UNITSTATUS8_Ready"; break;
    case UNITSTATUS8_Patrol: os << "UNITSTATUS8_Patrol"; break;
    case UNITSTATUS8_Building_road_in_place: os << "UNITSTATUS8_Building_road_in_place"; break;
    case UNITSTATUS8_Going_to_XY: os << "UNITSTATUS8_Going_to_XY"; break;
    case UNITSTATUS8_Reached_destination: os << "UNITSTATUS8_Reached_destination"; break;
    case UNITSTATUS8_Wait: os << "UNITSTATUS8_Wait"; break;
    case UNITSTATUS8_Ink_6: os << "UNITSTATUS8_Ink_6"; break;
    case UNITSTATUS8_Ink_7: os << "UNITSTATUS8_Ink_7"; break;
    case UNITSTATUS8_Purify: os << "UNITSTATUS8_Purify"; break;
    case UNITSTATUS8_Meld: os << "UNITSTATUS8_Meld"; break;
    case UNITSTATUS8_Settle: os << "UNITSTATUS8_Settle"; break;
    case UNITSTATUS8_Seek_transport: os << "UNITSTATUS8_Seek_transport"; break;
    case UNITSTATUS8_Unk_12: os << "UNITSTATUS8_Unk_12"; break;
    case UNITSTATUS8_Unk_13: os << "UNITSTATUS8_Unk_13"; break;
    case UNITSTATUS8_Unk_14: os << "UNITSTATUS8_Unk_14"; break;
    case UNITSTATUS8_Unk_15: os << "UNITSTATUS8_Unk_15"; break;
    case UNITSTATUS8_Move: os << "UNITSTATUS8_Move"; break;
    case UNITSTATUS8_Finished_purifying: os << "UNITSTATUS8_Finished_purifying"; break;
    case eUnit_Status8_MAX: os << "eUnit_Status8_MAX"; break;
    default: os << "<Unknown eUnit_Status8>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eUnit_Type& rhs)
{
    switch (rhs)
    {
    case UNITTYPE_Dwarf: os << "UNITTYPE_Dwarf"; break;
    case UNITTYPE_Barbarian: os << "UNITTYPE_Barbarian"; break;
    case UNITTYPE_Sage: os << "UNITTYPE_Sage"; break;
    case UNITTYPE_Dervish: os << "UNITTYPE_Dervish"; break;
    case UNITTYPE_Beastmaster: os << "UNITTYPE_Beastmaster"; break;
    case UNITTYPE_Bard: os << "UNITTYPE_Bard"; break;
    case UNITTYPE_Orc_Warrior: os << "UNITTYPE_Orc_Warrior"; break;
    case UNITTYPE_Healer: os << "UNITTYPE_Healer"; break;
    case UNITTYPE_Huntress: os << "UNITTYPE_Huntress"; break;
    case UNITTYPE_Thief: os << "UNITTYPE_Thief"; break;
    case UNITTYPE_Druid: os << "UNITTYPE_Druid"; break;
    case UNITTYPE_War_Monk: os << "UNITTYPE_War_Monk"; break;
    case UNITTYPE_Warrior_Mage: os << "UNITTYPE_Warrior_Mage"; break;
    case UNITTYPE_Magician: os << "UNITTYPE_Magician"; break;
    case UNITTYPE_Assassin: os << "UNITTYPE_Assassin"; break;
    case UNITTYPE_Wind_Mage: os << "UNITTYPE_Wind_Mage"; break;
    case UNITTYPE_Ranger: os << "UNITTYPE_Ranger"; break;
    case UNITTYPE_Draconian: os << "UNITTYPE_Draconian"; break;
    case UNITTYPE_Witch: os << "UNITTYPE_Witch"; break;
    case UNITTYPE_Golden_One: os << "UNITTYPE_Golden_One"; break;
    case UNITTYPE_Ninja: os << "UNITTYPE_Ninja"; break;
    case UNITTYPE_Rogue: os << "UNITTYPE_Rogue"; break;
    case UNITTYPE_Amazon: os << "UNITTYPE_Amazon"; break;
    case UNITTYPE_Warlock: os << "UNITTYPE_Warlock"; break;
    case UNITTYPE_Unknown: os << "UNITTYPE_Unknown"; break;
    case UNITTYPE_Illusionist: os << "UNITTYPE_Illusionist"; break;
    case UNITTYPE_Swordsman: os << "UNITTYPE_Swordsman"; break;
    case UNITTYPE_Priestess: os << "UNITTYPE_Priestess"; break;
    case UNITTYPE_Paladin: os << "UNITTYPE_Paladin"; break;
    case UNITTYPE_Black_Knight: os << "UNITTYPE_Black_Knight"; break;
    case UNITTYPE_Elven_Archer: os << "UNITTYPE_Elven_Archer"; break;
    case UNITTYPE_Knight: os << "UNITTYPE_Knight"; break;
    case UNITTYPE_Necromancer: os << "UNITTYPE_Necromancer"; break;
    case UNITTYPE_Chaos_Warrior: os << "UNITTYPE_Chaos_Warrior"; break;
    case UNITTYPE_Chosen: os << "UNITTYPE_Chosen"; break;
    case UNITTYPE_Trireme: os << "UNITTYPE_Trireme"; break;
    case UNITTYPE_Galley: os << "UNITTYPE_Galley"; break;
    case UNITTYPE_Catapult: os << "UNITTYPE_Catapult"; break;
    case UNITTYPE_Warship: os << "UNITTYPE_Warship"; break;
    case UNITTYPE_Barbarian_Spearmen: os << "UNITTYPE_Barbarian_Spearmen"; break;
    case UNITTYPE_Barbarian_Swordsmen: os << "UNITTYPE_Barbarian_Swordsmen"; break;
    case UNITTYPE_Barbarian_Bowmen: os << "UNITTYPE_Barbarian_Bowmen"; break;
    case UNITTYPE_Barbarian_Cavalry: os << "UNITTYPE_Barbarian_Cavalry"; break;
    case UNITTYPE_Barbarian_Shaman: os << "UNITTYPE_Barbarian_Shaman"; break;
    case UNITTYPE_Barbarian_Settlers: os << "UNITTYPE_Barbarian_Settlers"; break;
    case UNITTYPE_Barbarian_Berserkers: os << "UNITTYPE_Barbarian_Berserkers"; break;
    case UNITTYPE_Beastmen_Spearmen: os << "UNITTYPE_Beastmen_Spearmen"; break;
    case UNITTYPE_Beastmen_Swordsmen: os << "UNITTYPE_Beastmen_Swordsmen"; break;
    case UNITTYPE_Beastmen_Halberdiers: os << "UNITTYPE_Beastmen_Halberdiers"; break;
    case UNITTYPE_Beastmen_Bowmen: os << "UNITTYPE_Beastmen_Bowmen"; break;
    case UNITTYPE_Beastmen_Priests: os << "UNITTYPE_Beastmen_Priests"; break;
    case UNITTYPE_Beastmen_Magicians: os << "UNITTYPE_Beastmen_Magicians"; break;
    case UNITTYPE_Beastmen_Engineers: os << "UNITTYPE_Beastmen_Engineers"; break;
    case UNITTYPE_Beastmen_Settlers: os << "UNITTYPE_Beastmen_Settlers"; break;
    case UNITTYPE_Beastmen_Centaurs: os << "UNITTYPE_Beastmen_Centaurs"; break;
    case UNITTYPE_Beastmen_Manticores: os << "UNITTYPE_Beastmen_Manticores"; break;
    case UNITTYPE_Beastmen_Minotaurs: os << "UNITTYPE_Beastmen_Minotaurs"; break;
    case UNITTYPE_Dark_Elf_Spearmen: os << "UNITTYPE_Dark_Elf_Spearmen"; break;
    case UNITTYPE_Dark_Elf_Swordsmen: os << "UNITTYPE_Dark_Elf_Swordsmen"; break;
    case UNITTYPE_Dark_Elf_Halberdiers: os << "UNITTYPE_Dark_Elf_Halberdiers"; break;
    case UNITTYPE_Dark_Elf_Cavalry: os << "UNITTYPE_Dark_Elf_Cavalry"; break;
    case UNITTYPE_Dark_Elf_Priests: os << "UNITTYPE_Dark_Elf_Priests"; break;
    case UNITTYPE_Dark_Elf_Settlers: os << "UNITTYPE_Dark_Elf_Settlers"; break;
    case UNITTYPE_Dark_Elf_Nightblades: os << "UNITTYPE_Dark_Elf_Nightblades"; break;
    case UNITTYPE_Dark_Elf_Warlocks: os << "UNITTYPE_Dark_Elf_Warlocks"; break;
    case UNITTYPE_Dark_Elf_Nightmares: os << "UNITTYPE_Dark_Elf_Nightmares"; break;
    case UNITTYPE_Draconian_Spearmen: os << "UNITTYPE_Draconian_Spearmen"; break;
    case UNITTYPE_Draconian_Swordsmen: os << "UNITTYPE_Draconian_Swordsmen"; break;
    case UNITTYPE_Draconian_Halberdiers: os << "UNITTYPE_Draconian_Halberdiers"; break;
    case UNITTYPE_Draconian_Bowmen: os << "UNITTYPE_Draconian_Bowmen"; break;
    case UNITTYPE_Draconian_Shaman: os << "UNITTYPE_Draconian_Shaman"; break;
    case UNITTYPE_Draconian_Magicians: os << "UNITTYPE_Draconian_Magicians"; break;
    case UNITTYPE_Draconian_Engineers: os << "UNITTYPE_Draconian_Engineers"; break;
    case UNITTYPE_Draconian_Settlers: os << "UNITTYPE_Draconian_Settlers"; break;
    case UNITTYPE_Draconian_Doom_Drakes: os << "UNITTYPE_Draconian_Doom_Drakes"; break;
    case UNITTYPE_Draconian_Air_Ship: os << "UNITTYPE_Draconian_Air_Ship"; break;
    case UNITTYPE_Dwarven_Swordsmen: os << "UNITTYPE_Dwarven_Swordsmen"; break;
    case UNITTYPE_Dwarven_Halberdiers: os << "UNITTYPE_Dwarven_Halberdiers"; break;
    case UNITTYPE_Dwarven_Engineers: os << "UNITTYPE_Dwarven_Engineers"; break;
    case UNITTYPE_Dwarven_Hammerhands: os << "UNITTYPE_Dwarven_Hammerhands"; break;
    case UNITTYPE_Dwarven_Steam_Cannon: os << "UNITTYPE_Dwarven_Steam_Cannon"; break;
    case UNITTYPE_Dwarven_Golem: os << "UNITTYPE_Dwarven_Golem"; break;
    case UNITTYPE_Dwarven_Settlers: os << "UNITTYPE_Dwarven_Settlers"; break;
    case UNITTYPE_Gnoll_Spearmen: os << "UNITTYPE_Gnoll_Spearmen"; break;
    case UNITTYPE_Gnoll_Swordsmen: os << "UNITTYPE_Gnoll_Swordsmen"; break;
    case UNITTYPE_Gnoll_Halberdiers: os << "UNITTYPE_Gnoll_Halberdiers"; break;
    case UNITTYPE_Gnoll_Bowmen: os << "UNITTYPE_Gnoll_Bowmen"; break;
    case UNITTYPE_Gnoll_Settlers: os << "UNITTYPE_Gnoll_Settlers"; break;
    case UNITTYPE_Gnoll_Wolf_Riders: os << "UNITTYPE_Gnoll_Wolf_Riders"; break;
    case UNITTYPE_Halfling_Spearmen: os << "UNITTYPE_Halfling_Spearmen"; break;
    case UNITTYPE_Halfling_Swordsmen: os << "UNITTYPE_Halfling_Swordsmen"; break;
    case UNITTYPE_Halfling_Bowmen: os << "UNITTYPE_Halfling_Bowmen"; break;
    case UNITTYPE_Halfling_Shaman: os << "UNITTYPE_Halfling_Shaman"; break;
    case UNITTYPE_Halfling_Settlers: os << "UNITTYPE_Halfling_Settlers"; break;
    case UNITTYPE_Halfling_Slingers: os << "UNITTYPE_Halfling_Slingers"; break;
    case UNITTYPE_High_Elf_Spearmen: os << "UNITTYPE_High_Elf_Spearmen"; break;
    case UNITTYPE_High_Elf_Swordsmen: os << "UNITTYPE_High_Elf_Swordsmen"; break;
    case UNITTYPE_High_Elf_Halberdiers: os << "UNITTYPE_High_Elf_Halberdiers"; break;
    case UNITTYPE_High_Elf_Cavalry: os << "UNITTYPE_High_Elf_Cavalry"; break;
    case UNITTYPE_High_Elf_Magicians: os << "UNITTYPE_High_Elf_Magicians"; break;
    case UNITTYPE_High_Elf_Settlers: os << "UNITTYPE_High_Elf_Settlers"; break;
    case UNITTYPE_High_Elf_Longbowmen: os << "UNITTYPE_High_Elf_Longbowmen"; break;
    case UNITTYPE_High_Elf_Elven_Lords: os << "UNITTYPE_High_Elf_Elven_Lords"; break;
    case UNITTYPE_High_Elf_Pegasai: os << "UNITTYPE_High_Elf_Pegasai"; break;
    case UNITTYPE_High_Men_Spearmen: os << "UNITTYPE_High_Men_Spearmen"; break;
    case UNITTYPE_High_Men_Swordsmen: os << "UNITTYPE_High_Men_Swordsmen"; break;
    case UNITTYPE_High_Men_Bowmen: os << "UNITTYPE_High_Men_Bowmen"; break;
    case UNITTYPE_High_Men_Cavalry: os << "UNITTYPE_High_Men_Cavalry"; break;
    case UNITTYPE_High_Men_Priests: os << "UNITTYPE_High_Men_Priests"; break;
    case UNITTYPE_High_Men_Magicians: os << "UNITTYPE_High_Men_Magicians"; break;
    case UNITTYPE_High_Men_Engineers: os << "UNITTYPE_High_Men_Engineers"; break;
    case UNITTYPE_High_Men_Settlers: os << "UNITTYPE_High_Men_Settlers"; break;
    case UNITTYPE_High_Men_Pikemen: os << "UNITTYPE_High_Men_Pikemen"; break;
    case UNITTYPE_High_Men_Paladins: os << "UNITTYPE_High_Men_Paladins"; break;
    case UNITTYPE_Klackon_Spearmen: os << "UNITTYPE_Klackon_Spearmen"; break;
    case UNITTYPE_Klackon_Swordsmen: os << "UNITTYPE_Klackon_Swordsmen"; break;
    case UNITTYPE_Klackon_Halberdiers: os << "UNITTYPE_Klackon_Halberdiers"; break;
    case UNITTYPE_Klackon_Engineers: os << "UNITTYPE_Klackon_Engineers"; break;
    case UNITTYPE_Klackon_Settlers: os << "UNITTYPE_Klackon_Settlers"; break;
    case UNITTYPE_Klackon_Stag_Beetle: os << "UNITTYPE_Klackon_Stag_Beetle"; break;
    case UNITTYPE_Lizardman_Spearmen: os << "UNITTYPE_Lizardman_Spearmen"; break;
    case UNITTYPE_Lizardman_Swordsmen: os << "UNITTYPE_Lizardman_Swordsmen"; break;
    case UNITTYPE_Lizardman_Halberdiers: os << "UNITTYPE_Lizardman_Halberdiers"; break;
    case UNITTYPE_Lizardman_Javelineers: os << "UNITTYPE_Lizardman_Javelineers"; break;
    case UNITTYPE_Lizardman_Shaman: os << "UNITTYPE_Lizardman_Shaman"; break;
    case UNITTYPE_Lizardman_Settlers: os << "UNITTYPE_Lizardman_Settlers"; break;
    case UNITTYPE_Lizardman_Dragon_Turtle: os << "UNITTYPE_Lizardman_Dragon_Turtle"; break;
    case UNITTYPE_Nomad_Spearmen: os << "UNITTYPE_Nomad_Spearmen"; break;
    case UNITTYPE_Nomad_Swordsmen: os << "UNITTYPE_Nomad_Swordsmen"; break;
    case UNITTYPE_Nomad_Bowmen: os << "UNITTYPE_Nomad_Bowmen"; break;
    case UNITTYPE_Nomad_Priests: os << "UNITTYPE_Nomad_Priests"; break;
    case UNITTYPE_Nomad_Magicians: os << "UNITTYPE_Nomad_Magicians"; break;
    case UNITTYPE_Nomad_Settlers: os << "UNITTYPE_Nomad_Settlers"; break;
    case UNITTYPE_Nomad_Horsebowmen: os << "UNITTYPE_Nomad_Horsebowmen"; break;
    case UNITTYPE_Nomad_Pikemen: os << "UNITTYPE_Nomad_Pikemen"; break;
    case UNITTYPE_Nomad_Rangers: os << "UNITTYPE_Nomad_Rangers"; break;
    case UNITTYPE_Nomad_Griffins: os << "UNITTYPE_Nomad_Griffins"; break;
    case UNITTYPE_Orc_Spearmen: os << "UNITTYPE_Orc_Spearmen"; break;
    case UNITTYPE_Orc_Swordsmen: os << "UNITTYPE_Orc_Swordsmen"; break;
    case UNITTYPE_Orc_Halberdiers: os << "UNITTYPE_Orc_Halberdiers"; break;
    case UNITTYPE_Orc_Bowmen: os << "UNITTYPE_Orc_Bowmen"; break;
    case UNITTYPE_Orc_Cavalry: os << "UNITTYPE_Orc_Cavalry"; break;
    case UNITTYPE_Orc_Shaman: os << "UNITTYPE_Orc_Shaman"; break;
    case UNITTYPE_Orc_Magicians: os << "UNITTYPE_Orc_Magicians"; break;
    case UNITTYPE_Orc_Engineers: os << "UNITTYPE_Orc_Engineers"; break;
    case UNITTYPE_Orc_Settlers: os << "UNITTYPE_Orc_Settlers"; break;
    case UNITTYPE_Orc_Wyvern_Riders: os << "UNITTYPE_Orc_Wyvern_Riders"; break;
    case UNITTYPE_Troll_Spearmen: os << "UNITTYPE_Troll_Spearmen"; break;
    case UNITTYPE_Troll_Swordsmen: os << "UNITTYPE_Troll_Swordsmen"; break;
    case UNITTYPE_Troll_Halberdiers: os << "UNITTYPE_Troll_Halberdiers"; break;
    case UNITTYPE_Troll_Shaman: os << "UNITTYPE_Troll_Shaman"; break;
    case UNITTYPE_Troll_Settlers: os << "UNITTYPE_Troll_Settlers"; break;
    case UNITTYPE_Troll_War_Trolls: os << "UNITTYPE_Troll_War_Trolls"; break;
    case UNITTYPE_Troll_War_Mammoths: os << "UNITTYPE_Troll_War_Mammoths"; break;
    case UNITTYPE_Arcane_Magic_Spirit: os << "UNITTYPE_Arcane_Magic_Spirit"; break;
    case UNITTYPE_Red_Hell_Hounds: os << "UNITTYPE_Red_Hell_Hounds"; break;
    case UNITTYPE_Red_Gargoyles: os << "UNITTYPE_Red_Gargoyles"; break;
    case UNITTYPE_Red_Fire_Giant: os << "UNITTYPE_Red_Fire_Giant"; break;
    case UNITTYPE_Red_Fire_Elemental: os << "UNITTYPE_Red_Fire_Elemental"; break;
    case UNITTYPE_Red_Chaos_Spawn: os << "UNITTYPE_Red_Chaos_Spawn"; break;
    case UNITTYPE_Red_Chimera: os << "UNITTYPE_Red_Chimera"; break;
    case UNITTYPE_Red_Doom_Bat: os << "UNITTYPE_Red_Doom_Bat"; break;
    case UNITTYPE_Red_Efreet: os << "UNITTYPE_Red_Efreet"; break;
    case UNITTYPE_Red_Hydra: os << "UNITTYPE_Red_Hydra"; break;
    case UNITTYPE_Red_Great_Drake: os << "UNITTYPE_Red_Great_Drake"; break;
    case UNITTYPE_Black_Skeletons: os << "UNITTYPE_Black_Skeletons"; break;
    case UNITTYPE_Black_Ghouls: os << "UNITTYPE_Black_Ghouls"; break;
    case UNITTYPE_Black_Night_Stalker: os << "UNITTYPE_Black_Night_Stalker"; break;
    case UNITTYPE_Black_Werewolves: os << "UNITTYPE_Black_Werewolves"; break;
    case UNITTYPE_Black_Demon: os << "UNITTYPE_Black_Demon"; break;
    case UNITTYPE_Black_Wraiths: os << "UNITTYPE_Black_Wraiths"; break;
    case UNITTYPE_Black_Shadow_Demons: os << "UNITTYPE_Black_Shadow_Demons"; break;
    case UNITTYPE_Black_Death_Knights: os << "UNITTYPE_Black_Death_Knights"; break;
    case UNITTYPE_Black_Demon_Lord: os << "UNITTYPE_Black_Demon_Lord"; break;
    case UNITTYPE_Black_Zombies: os << "UNITTYPE_Black_Zombies"; break;
    case UNITTYPE_White_Unicorns: os << "UNITTYPE_White_Unicorns"; break;
    case UNITTYPE_White_Guardian_Spirit: os << "UNITTYPE_White_Guardian_Spirit"; break;
    case UNITTYPE_White_Angel: os << "UNITTYPE_White_Angel"; break;
    case UNITTYPE_White_Arch_Angel: os << "UNITTYPE_White_Arch_Angel"; break;
    case UNITTYPE_Green_War_Bears: os << "UNITTYPE_Green_War_Bears"; break;
    case UNITTYPE_Green_Sprites: os << "UNITTYPE_Green_Sprites"; break;
    case UNITTYPE_Green_Cockatrices: os << "UNITTYPE_Green_Cockatrices"; break;
    case UNITTYPE_Green_Basilisk: os << "UNITTYPE_Green_Basilisk"; break;
    case UNITTYPE_Green_Giant_Spiders: os << "UNITTYPE_Green_Giant_Spiders"; break;
    case UNITTYPE_Green_Stone_Giant: os << "UNITTYPE_Green_Stone_Giant"; break;
    case UNITTYPE_Green_Colossus: os << "UNITTYPE_Green_Colossus"; break;
    case UNITTYPE_Green_Gorgons: os << "UNITTYPE_Green_Gorgons"; break;
    case UNITTYPE_Green_Earth_Elemental: os << "UNITTYPE_Green_Earth_Elemental"; break;
    case UNITTYPE_Green_Behemoth: os << "UNITTYPE_Green_Behemoth"; break;
    case UNITTYPE_Green_Great_Wyrm: os << "UNITTYPE_Green_Great_Wyrm"; break;
    case UNITTYPE_Blue_Floating_Island: os << "UNITTYPE_Blue_Floating_Island"; break;
    case UNITTYPE_Blue_Phantom_Beast: os << "UNITTYPE_Blue_Phantom_Beast"; break;
    case UNITTYPE_Blue_Phantom_Warriors: os << "UNITTYPE_Blue_Phantom_Warriors"; break;
    case UNITTYPE_Blue_Storm_Giant: os << "UNITTYPE_Blue_Storm_Giant"; break;
    case UNITTYPE_Blue_Air_Elemental: os << "UNITTYPE_Blue_Air_Elemental"; break;
    case UNITTYPE_Blue_Djinn: os << "UNITTYPE_Blue_Djinn"; break;
    case UNITTYPE_Blue_Sky_Drake: os << "UNITTYPE_Blue_Sky_Drake"; break;
    case UNITTYPE_Blue_Nagas: os << "UNITTYPE_Blue_Nagas"; break;
    case eUnit_Type_MAX: os << "eUnit_Type_MAX"; break;
    default: os << "<Unknown eUnit_Type>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eWar_Status& rhs)
{
    switch (rhs)
    {
    case WARSTATUS_None: os << "WARSTATUS_None"; break;
    case WARSTATUS_Wizard_Pact: os << "WARSTATUS_Wizard_Pact"; break;
    case WARSTATUS_Alliance: os << "WARSTATUS_Alliance"; break;
    case WARSTATUS_War: os << "WARSTATUS_War"; break;
    case eWar_Status_MAX: os << "eWar_Status_MAX"; break;
    default: os << "<Unknown eWar_Status>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eWeaponType& rhs)
{
    switch (rhs)
    {
    case WEAPON_normal: os << "WEAPON_normal"; break;
    case WEAPON_magic: os << "WEAPON_magic"; break;
    case WEAPON_mithril: os << "WEAPON_mithril"; break;
    case WEAPON_adamantium: os << "WEAPON_adamantium"; break;
    case eWeaponType_MAX: os << "eWeaponType_MAX"; break;
    default: os << "<Unknown eWeaponType>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eYesNo16& rhs)
{
    switch (rhs)
    {
    case YESNO16_No: os << "YESNO16_No"; break;
    case YESNO16_Yes: os << "YESNO16_Yes"; break;
    case eYesNo16_MAX: os << "eYesNo16_MAX"; break;
    default: os << "<Unknown eYesNo16>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const eYesNo8& rhs)
{
    switch (rhs)
    {
    case YESNO8_No: os << "YESNO8_No"; break;
    case YESNO8_Yes: os << "YESNO8_Yes"; break;
    case eYesNo8_MAX: os << "eYesNo8_MAX"; break;
    default: os << "<Unknown eYesNo8>"; break;
    }
    os << " (" << (unsigned)rhs << ")";
    return os;
}

} // namespace
