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

std::string formatCharArray(const char* buffer, unsigned size)
{
    std::ostringstream oss;
    for (unsigned i = 0; i < size; ++i)
    {
        if (isprint((unsigned char)buffer[i]))
        {
            oss << buffer[i];
        }
        else
        {
            oss << "\\x" << std::setbase(16) << std::setw(2) << std::setfill('0') 
                << (unsigned)(unsigned char)buffer[i] 
                << std::setbase(10);
        }
    }
    return oss.str();
}

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

std::ostream& operator<<(std::ostream& os, const eEvent& rhs)
{
    switch (rhs)
    {
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
    case EVENT_Conjunction_Sorcery: os << "EVENT_Conjunction_Sorcery"; break;
    case EVENT_Conjunction_Nature: os << "EVENT_Conjunction_Nature"; break;
    case EVENT_Conjunction_Chaos: os << "EVENT_Conjunction_Chaos"; break;
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
    case ITEMPOWER_Doom_equals_Chaos: os << "ITEMPOWER_Doom_equals_Chaos"; break;
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
    case PRODUCING_BUILDING_MAX: os << "PRODUCING_BUILDING_MAX"; break;
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
    case RACE_Generic_ship_or_catapult: os << "RACE_Generic_ship_or_catapult"; break;
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

std::ostream& operator<<(std::ostream& os, const eSkill& rhs)
{
    switch (rhs)
    {
    case SKILL_Alchemy: os << "SKILL_Alchemy"; break;
    case SKILL_Warlord: os << "SKILL_Warlord"; break;
    case SKILL_Chaos_Master: os << "SKILL_Chaos_Master"; break;
    case SKILL_Nature_Master: os << "SKILL_Nature_Master"; break;
    case SKILL_Sorcery_Master: os << "SKILL_Sorcery_Master"; break;
    case SKILL_Infernal_Power: os << "SKILL_Infernal_Power"; break;
    case SKILL_Divine_Power: os << "SKILL_Divine_Power"; break;
    case SKILL_Sage_Master: os << "SKILL_Sage_Master"; break;
    case SKILL_Channeller: os << "SKILL_Channeller"; break;
    case SKILL_Myrran: os << "SKILL_Myrran"; break;
    case SKILL_Archmage: os << "SKILL_Archmage"; break;
    case SKILL_Mana_Focusing: os << "SKILL_Mana_Focusing"; break;
    case SKILL_Node_Mastery: os << "SKILL_Node_Mastery"; break;
    case SKILL_Famous: os << "SKILL_Famous"; break;
    case SKILL_Runemaster: os << "SKILL_Runemaster"; break;
    case SKILL_Conjurer: os << "SKILL_Conjurer"; break;
    case SKILL_Charismatic: os << "SKILL_Charismatic"; break;
    case SKILL_Artificer: os << "SKILL_Artificer"; break;
    case eSkill_MAX: os << "eSkill_MAX"; break;
    default: os << "<Unknown eSkill>"; break;
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
    case TAX_00_gold_00_unrest: os << "TAX_00_gold_00_unrest"; break;
    case TAX_05_gold_10_unrest: os << "TAX_05_gold_10_unrest"; break;
    case TAX_10_gold_20_unrest: os << "TAX_10_gold_20_unrest"; break;
    case TAX_15_gold_30_unrest: os << "TAX_15_gold_30_unrest"; break;
    case TAX_20_gold_45_unrest: os << "TAX_20_gold_45_unrest"; break;
    case TAX_25_gold_60_unrest: os << "TAX_25_gold_60_unrest"; break;
    case TAX_30_gold_75_unrest: os << "TAX_30_gold_75_unrest"; break;
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
    case DEPOSIT_Unk_10: os << "DEPOSIT_Unk_10"; break;
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
    case river1_first: os << "river1_first"; break;
    case river1_last: os << "river1_last"; break;
    case shore2_first: os << "shore2_first"; break;
    case shore2_last: os << "shore2_last"; break;
    case shore3_first: os << "shore3_first"; break;
    case shore3_last: os << "shore3_last"; break;
    case river2_first: os << "river2_first"; break;
    case river2_last: os << "river2_last"; break;
    case mountain2_first: os << "mountain2_first"; break;
    case mountain2_last: os << "mountain2_last"; break;
    case hills2_first: os << "hills2_first"; break;
    case hills2_last: os << "hills2_last"; break;
    case desert5_first: os << "desert5_first"; break;
    case desert5_last: os << "desert5_last"; break;
    case shore4_first: os << "shore4_first"; break;
    case shore4_last: os << "shore4_last"; break;
    case ocean2: os << "ocean2"; break;
    case ocean3: os << "ocean3"; break;
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

std::ostream& operator<<(std::ostream& os, const Ability_Flags& rhs)
{
    os << "{\n";
    if (0 != rhs.Summoned_Unit)
    {
    os << "Summoned_Unit=" << (unsigned)rhs.Summoned_Unit << "\n";
    }
    if (0 != rhs.Large_Shield)
    {
    os << "Large_Shield=" << (unsigned)rhs.Large_Shield << "\n";
    }
    if (0 != rhs.Plane_Shift)
    {
    os << "Plane_Shift=" << (unsigned)rhs.Plane_Shift << "\n";
    }
    if (0 != rhs.Wall_Crusher)
    {
    os << "Wall_Crusher=" << (unsigned)rhs.Wall_Crusher << "\n";
    }
    if (0 != rhs.Healer)
    {
    os << "Healer=" << (unsigned)rhs.Healer << "\n";
    }
    if (0 != rhs.Create_Outpost)
    {
    os << "Create_Outpost=" << (unsigned)rhs.Create_Outpost << "\n";
    }
    if (0 != rhs.Invisibility)
    {
    os << "Invisibility=" << (unsigned)rhs.Invisibility << "\n";
    }
    if (0 != rhs.Create_Undead)
    {
    os << "Create_Undead=" << (unsigned)rhs.Create_Undead << "\n";
    }
    if (0 != rhs.Long_Range)
    {
    os << "Long_Range=" << (unsigned)rhs.Long_Range << "\n";
    }
    if (0 != rhs.Land_Corruption)
    {
    os << "Land_Corruption=" << (unsigned)rhs.Land_Corruption << "\n";
    }
    if (0 != rhs.Meld_With_Node)
    {
    os << "Meld_With_Node=" << (unsigned)rhs.Meld_With_Node << "\n";
    }
    if (0 != rhs.Non_Corporeal)
    {
    os << "Non_Corporeal=" << (unsigned)rhs.Non_Corporeal << "\n";
    }
    if (0 != rhs.Wind_Walking)
    {
    os << "Wind_Walking=" << (unsigned)rhs.Wind_Walking << "\n";
    }
    if (0 != rhs.Regeneration)
    {
    os << "Regeneration=" << (unsigned)rhs.Regeneration << "\n";
    }
    if (0 != rhs.Purify)
    {
    os << "Purify=" << (unsigned)rhs.Purify << "\n";
    }
    if (0 != rhs.Negate_First_Strike)
    {
    os << "Negate_First_Strike=" << (unsigned)rhs.Negate_First_Strike << "\n";
    }
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Attack_Flags& rhs)
{
    os << "{\n";
    if (0 != rhs.Armor_Piercing)
    {
    os << "Armor_Piercing=" << (unsigned)rhs.Armor_Piercing << "\n";
    }
    if (0 != rhs.First_Strike)
    {
    os << "First_Strike=" << (unsigned)rhs.First_Strike << "\n";
    }
    if (0 != rhs.Poison_attack)
    {
    os << "Poison_attack=" << (unsigned)rhs.Poison_attack << "\n";
    }
    if (0 != rhs.Life_Stealing)
    {
    os << "Life_Stealing=" << (unsigned)rhs.Life_Stealing << "\n";
    }
    if (0 != rhs.Automatic_Damage)
    {
    os << "Automatic_Damage=" << (unsigned)rhs.Automatic_Damage << "\n";
    }
    if (0 != rhs.Destruction)
    {
    os << "Destruction=" << (unsigned)rhs.Destruction << "\n";
    }
    if (0 != rhs.Illusionary_attack)
    {
    os << "Illusionary_attack=" << (unsigned)rhs.Illusionary_attack << "\n";
    }
    if (0 != rhs.Stoning_Touch)
    {
    os << "Stoning_Touch=" << (unsigned)rhs.Stoning_Touch << "\n";
    }
    if (0 != rhs.No_effect01)
    {
    os << "No_effect01=" << (unsigned)rhs.No_effect01 << "\n";
    }
    if (0 != rhs.Death_Touch)
    {
    os << "Death_Touch=" << (unsigned)rhs.Death_Touch << "\n";
    }
    if (0 != rhs.Power_Drain)
    {
    os << "Power_Drain=" << (unsigned)rhs.Power_Drain << "\n";
    }
    if (0 != rhs.Dispel_Evil)
    {
    os << "Dispel_Evil=" << (unsigned)rhs.Dispel_Evil << "\n";
    }
    if (0 != rhs.Ball_COMBAT)
    {
    os << "Ball_COMBAT=" << (unsigned)rhs.Ball_COMBAT << "\n";
    }
    if (0 != rhs.No_effect20_COMBAT)
    {
    os << "No_effect20_COMBAT=" << (unsigned)rhs.No_effect20_COMBAT << "\n";
    }
    if (0 != rhs.Eldritch_Weapon_COMBAT)
    {
    os << "Eldritch_Weapon_COMBAT=" << (unsigned)rhs.Eldritch_Weapon_COMBAT << "\n";
    }
    if (0 != rhs.Warp_Lightning_COMBAT)
    {
    os << "Warp_Lightning_COMBAT=" << (unsigned)rhs.Warp_Lightning_COMBAT << "\n";
    }
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Attribute_Flags& rhs)
{
    os << "{\n";
    if (0 != rhs.Weapon_Immunity)
    {
    os << "Weapon_Immunity=" << (unsigned)rhs.Weapon_Immunity << "\n";
    }
    if (0 != rhs.Flyer)
    {
    os << "Flyer=" << (unsigned)rhs.Flyer << "\n";
    }
    if (0 != rhs.Lucky)
    {
    os << "Lucky=" << (unsigned)rhs.Lucky << "\n";
    }
    if (0 != rhs.Summon_Demons_1)
    {
    os << "Summon_Demons_1=" << (unsigned)rhs.Summon_Demons_1 << "\n";
    }
    if (0 != rhs.Summon_Demons_2)
    {
    os << "Summon_Demons_2=" << (unsigned)rhs.Summon_Demons_2 << "\n";
    }
    if (0 != rhs.Caster_20_MP)
    {
    os << "Caster_20_MP=" << (unsigned)rhs.Caster_20_MP << "\n";
    }
    if (0 != rhs.Caster_40_MP)
    {
    os << "Caster_40_MP=" << (unsigned)rhs.Caster_40_MP << "\n";
    }
    if (0 != rhs.Standard)
    {
    os << "Standard=" << (unsigned)rhs.Standard << "\n";
    }
    if (0 != rhs.Healing_Spell)
    {
    os << "Healing_Spell=" << (unsigned)rhs.Healing_Spell << "\n";
    }
    if (0 != rhs.Fire_Ball_Spell)
    {
    os << "Fire_Ball_Spell=" << (unsigned)rhs.Fire_Ball_Spell << "\n";
    }
    if (0 != rhs.Doombolt_Spell)
    {
    os << "Doombolt_Spell=" << (unsigned)rhs.Doombolt_Spell << "\n";
    }
    if (0 != rhs.Immolation)
    {
    os << "Immolation=" << (unsigned)rhs.Immolation << "\n";
    }
    if (0 != rhs.Web_Spell)
    {
    os << "Web_Spell=" << (unsigned)rhs.Web_Spell << "\n";
    }
    if (0 != rhs.Cause_Fear_Spell)
    {
    os << "Cause_Fear_Spell=" << (unsigned)rhs.Cause_Fear_Spell << "\n";
    }
    if (0 != rhs.Resistance_to_All)
    {
    os << "Resistance_to_All=" << (unsigned)rhs.Resistance_to_All << "\n";
    }
    if (0 != rhs.Holy_Bonus)
    {
    os << "Holy_Bonus=" << (unsigned)rhs.Holy_Bonus << "\n";
    }
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Available_spell_page& rhs)
{
    os << "{\n";
    os << "m_Page_Name=" << formatCharArray(rhs.m_Page_Name, 0x10) << "\n";
    os << "m_Spells_on_page=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << rhs.m_Spells_on_page[i] << ",\n";
    }
    os << ")\n";
    os << "m_Nr_spells_on_page=" << (unsigned)rhs.m_Nr_spells_on_page << " 0x" << std::hex << (unsigned)rhs.m_Nr_spells_on_page << std::dec << "\n";
    os << "m_Zero_1D=" << (unsigned)rhs.m_Zero_1D << " 0x" << std::hex << (unsigned)rhs.m_Zero_1D << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Battle_Figure& rhs)
{
    os << "{\n";
    os << "m_xpel=" << rhs.m_xpel << " 0x" << std::hex << rhs.m_xpel << std::dec << "\n";
    os << "m_ypel=" << rhs.m_ypel << " 0x" << std::hex << rhs.m_ypel << std::dec << "\n";
    os << "m_Pic=" << rhs.m_Pic << " 0x" << std::hex << rhs.m_Pic << std::dec << "\n";
    os << "m_Unk_6_sound=" << rhs.m_Unk_6_sound << " 0x" << std::hex << rhs.m_Unk_6_sound << std::dec << "\n";
    os << "m_Unk_8=" << rhs.m_Unk_8 << " 0x" << std::hex << rhs.m_Unk_8 << std::dec << "\n";
    os << "m_Unk_A=" << rhs.m_Unk_A << " 0x" << std::hex << rhs.m_Unk_A << std::dec << "\n";
    os << "m_Unk_C=" << rhs.m_Unk_C << " 0x" << std::hex << rhs.m_Unk_C << std::dec << "\n";
    os << "m_Owner=" << rhs.m_Owner << "\n";
    os << "m_Unk_10=" << rhs.m_Unk_10 << " 0x" << std::hex << rhs.m_Unk_10 << std::dec << "\n";
    os << "m_Color_enchantment=" << rhs.m_Color_enchantment << " 0x" << std::hex << rhs.m_Color_enchantment << std::dec << "\n";
    os << "m_Unk_14_sound=" << rhs.m_Unk_14_sound << " 0x" << std::hex << rhs.m_Unk_14_sound << std::dec << "\n";
    os << "m_Unk_16=" << rhs.m_Unk_16 << " 0x" << std::hex << rhs.m_Unk_16 << std::dec << "\n";
    os << "m_Unk_18_battleunit_field_58=" << rhs.m_Unk_18_battleunit_field_58 << " 0x" << std::hex << rhs.m_Unk_18_battleunit_field_58 << std::dec << "\n";
    os << "m_ZDepth=" << rhs.m_ZDepth << " 0x" << std::hex << rhs.m_ZDepth << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Battle_Unit& rhs)
{
    os << "{\n";
    os << "m_Melee=" << (unsigned)rhs.m_Melee << " 0x" << std::hex << (unsigned)rhs.m_Melee << std::dec << "\n";
    os << "m_Ranged=" << (unsigned)rhs.m_Ranged << " 0x" << std::hex << (unsigned)rhs.m_Ranged << std::dec << "\n";
    os << "m_Ranged_Type=" << rhs.m_Ranged_Type << "\n";
    os << "m_Ranged_Shots=" << (unsigned)rhs.m_Ranged_Shots << " 0x" << std::hex << (unsigned)rhs.m_Ranged_Shots << std::dec << "\n";
    os << "m_To_Hit=" << (unsigned)rhs.m_To_Hit << " 0x" << std::hex << (unsigned)rhs.m_To_Hit << std::dec << "\n";
    os << "m_Defense=" << (unsigned)rhs.m_Defense << " 0x" << std::hex << (unsigned)rhs.m_Defense << std::dec << "\n";
    os << "m_Resistance=" << (unsigned)rhs.m_Resistance << " 0x" << std::hex << (unsigned)rhs.m_Resistance << std::dec << "\n";
    os << "m_MoveHalves=" << (unsigned)rhs.m_MoveHalves << " 0x" << std::hex << (unsigned)rhs.m_MoveHalves << std::dec << "\n";
    os << "m_Cost=" << rhs.m_Cost << " 0x" << std::hex << rhs.m_Cost << std::dec << "\n";
    os << "m_Upkeep=" << (unsigned)rhs.m_Upkeep << " 0x" << std::hex << (unsigned)rhs.m_Upkeep << std::dec << "\n";
    os << "m_Race_Code=" << rhs.m_Race_Code << "\n";
    os << "m_Building1Required_or_PortraitLbxIndex=" << (unsigned)rhs.m_Building1Required_or_PortraitLbxIndex << " 0x" << std::hex << (unsigned)rhs.m_Building1Required_or_PortraitLbxIndex << std::dec << "\n";
    os << "m_Current_figures=" << (unsigned)rhs.m_Current_figures << " 0x" << std::hex << (unsigned)rhs.m_Current_figures << std::dec << "\n";
    os << "m_BattleUnitNr=" << (int)rhs.m_BattleUnitNr << " 0x" << std::hex << (int)rhs.m_BattleUnitNr << std::dec << "\n";
    os << "m_Unk_0F=" << (unsigned)rhs.m_Unk_0F << " 0x" << std::hex << (unsigned)rhs.m_Unk_0F << std::dec << "\n";
    os << "m_Hitpoints_per_Figure=" << (unsigned)rhs.m_Hitpoints_per_Figure << " 0x" << std::hex << (unsigned)rhs.m_Hitpoints_per_Figure << std::dec << "\n";
    os << "m_Scouting=" << (unsigned)rhs.m_Scouting << " 0x" << std::hex << (unsigned)rhs.m_Scouting << std::dec << "\n";
    os << "m_Transport_Capacity_GUESS=" << (unsigned)rhs.m_Transport_Capacity_GUESS << " 0x" << std::hex << (unsigned)rhs.m_Transport_Capacity_GUESS << std::dec << "\n";
    os << "m_Max_figures=" << (unsigned)rhs.m_Max_figures << " 0x" << std::hex << (unsigned)rhs.m_Max_figures << std::dec << "\n";
    os << "m_Construction=" << (unsigned)rhs.m_Construction << " 0x" << std::hex << (unsigned)rhs.m_Construction << std::dec << "\n";
    os << "m_Gaze_Modifier=" << (int)rhs.m_Gaze_Modifier << " 0x" << std::hex << (int)rhs.m_Gaze_Modifier << std::dec << "\n";
    os << "m_Movement_Flags=" << rhs.m_Movement_Flags << "\n";
    os << "m_Zero_17=" << (unsigned)rhs.m_Zero_17 << " 0x" << std::hex << (unsigned)rhs.m_Zero_17 << std::dec << "\n";
    os << "m_Immunity_Flags=" << rhs.m_Immunity_Flags << "\n";
    os << "m_Attribute_Flags=" << rhs.m_Attribute_Flags << "\n";
    os << "m_Zero_1B=" << (unsigned)rhs.m_Zero_1B << " 0x" << std::hex << (unsigned)rhs.m_Zero_1B << std::dec << "\n";
    os << "m_Ability_Flags=" << rhs.m_Ability_Flags << "\n";
    os << "m_Attack_Flags=" << rhs.m_Attack_Flags << "\n";
    os << "m_Zero_20=" << rhs.m_Zero_20 << " 0x" << std::hex << rhs.m_Zero_20 << std::dec << "\n";
    os << "m_Flags_Combat_Enchantment=" << rhs.m_Flags_Combat_Enchantment << "\n";
    os << "m_Extra_ToHit_Melee=" << (unsigned)rhs.m_Extra_ToHit_Melee << " 0x" << std::hex << (unsigned)rhs.m_Extra_ToHit_Melee << std::dec << "\n";
    os << "m_Extra_ToHit_Ranged=" << (unsigned)rhs.m_Extra_ToHit_Ranged << " 0x" << std::hex << (unsigned)rhs.m_Extra_ToHit_Ranged << std::dec << "\n";
    os << "m_Extra_ToDefend=" << (unsigned)rhs.m_Extra_ToDefend << " 0x" << std::hex << (unsigned)rhs.m_Extra_ToDefend << std::dec << "\n";
    os << "m_Weapon_Type_Plus_1=" << (unsigned)rhs.m_Weapon_Type_Plus_1 << " 0x" << std::hex << (unsigned)rhs.m_Weapon_Type_Plus_1 << std::dec << "\n";
    os << "m_Cur_Attack_Flags=" << rhs.m_Cur_Attack_Flags << "\n";
    os << "m_Item_Attack_Flags=" << rhs.m_Item_Attack_Flags << "\n";
    os << "m_Item_UnitEnchantment=" << rhs.m_Item_UnitEnchantment << "\n";
    os << "m_unitNr=" << rhs.m_unitNr << " 0x" << std::hex << rhs.m_unitNr << std::dec << "\n";
    os << "m_additional_life_per_figure=" << (int)rhs.m_additional_life_per_figure << " 0x" << std::hex << (int)rhs.m_additional_life_per_figure << std::dec << "\n";
    os << "m_web_strength=" << (int)rhs.m_web_strength << " 0x" << std::hex << (int)rhs.m_web_strength << std::dec << "\n";
    os << "m_Active=" << rhs.m_Active << "\n";
    os << "m_Owner=" << rhs.m_Owner << "\n";
    os << "m_tracks_regular_damage=" << (int)rhs.m_tracks_regular_damage << " 0x" << std::hex << (int)rhs.m_tracks_regular_damage << std::dec << "\n";
    os << "m_tracks_lifesteal_damage=" << (int)rhs.m_tracks_lifesteal_damage << " 0x" << std::hex << (int)rhs.m_tracks_lifesteal_damage << std::dec << "\n";
    os << "m_tracks_instant_damage_like_stoning=" << (int)rhs.m_tracks_instant_damage_like_stoning << " 0x" << std::hex << (int)rhs.m_tracks_instant_damage_like_stoning << std::dec << "\n";
    os << "m_top_figure_damage=" << (int)rhs.m_top_figure_damage << " 0x" << std::hex << (int)rhs.m_top_figure_damage << std::dec << "\n";
    os << "m_Flags1_UnitEnchantment=" << rhs.m_Flags1_UnitEnchantment << "\n";
    os << "m_Suppression=" << (int)rhs.m_Suppression << " 0x" << std::hex << (int)rhs.m_Suppression << std::dec << "\n";
    os << "m_Mana_points=" << (int)rhs.m_Mana_points << " 0x" << std::hex << (int)rhs.m_Mana_points << std::dec << "\n";
    os << "m_Current_mana=" << (int)rhs.m_Current_mana << " 0x" << std::hex << (int)rhs.m_Current_mana << std::dec << "\n";
    os << "m_Item_nr_charges=" << (int)rhs.m_Item_nr_charges << " 0x" << std::hex << (int)rhs.m_Item_nr_charges << std::dec << "\n";
    os << "m_Poison_strength=" << (int)rhs.m_Poison_strength << " 0x" << std::hex << (int)rhs.m_Poison_strength << std::dec << "\n";
    os << "m_Target_BattleUnitID=" << (int)rhs.m_Target_BattleUnitID << " 0x" << std::hex << (int)rhs.m_Target_BattleUnitID << std::dec << "\n";
    os << "m_xPos=" << rhs.m_xPos << " 0x" << std::hex << rhs.m_xPos << std::dec << "\n";
    os << "m_yPos=" << rhs.m_yPos << " 0x" << std::hex << rhs.m_yPos << std::dec << "\n";
    os << "m_xPosHeaded=" << rhs.m_xPosHeaded << " 0x" << std::hex << rhs.m_xPosHeaded << std::dec << "\n";
    os << "m_yPosHeaded=" << rhs.m_yPosHeaded << " 0x" << std::hex << rhs.m_yPosHeaded << std::dec << "\n";
    os << "m_Unk_4C_display=" << rhs.m_Unk_4C_display << " 0x" << std::hex << rhs.m_Unk_4C_display << std::dec << "\n";
    os << "m_Unk_4E=" << rhs.m_Unk_4E << " 0x" << std::hex << rhs.m_Unk_4E << std::dec << "\n";
    os << "m_Unk_50=" << rhs.m_Unk_50 << " 0x" << std::hex << rhs.m_Unk_50 << std::dec << "\n";
    os << "m_Unk_52_sound=" << rhs.m_Unk_52_sound << " 0x" << std::hex << rhs.m_Unk_52_sound << std::dec << "\n";
    os << "m_Tactic=" << rhs.m_Tactic << "\n";
    os << "m_Confused_State=" << (int)rhs.m_Confused_State << " 0x" << std::hex << (int)rhs.m_Confused_State << std::dec << "\n";
    os << "m_Unk_57=" << (unsigned)rhs.m_Unk_57 << " 0x" << std::hex << (unsigned)rhs.m_Unk_57 << std::dec << "\n";
    os << "m_Unk_58=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << rhs.m_Unk_58[i] << " 0x" << std::hex << rhs.m_Unk_58[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Extra_Melee=" << (unsigned)rhs.m_Extra_Melee << " 0x" << std::hex << (unsigned)rhs.m_Extra_Melee << std::dec << "\n";
    os << "m_Extra_Ranged=" << (unsigned)rhs.m_Extra_Ranged << " 0x" << std::hex << (unsigned)rhs.m_Extra_Ranged << std::dec << "\n";
    os << "m_Extra_Defense=" << (unsigned)rhs.m_Extra_Defense << " 0x" << std::hex << (unsigned)rhs.m_Extra_Defense << std::dec << "\n";
    os << "m_Extra_Resistance=" << (unsigned)rhs.m_Extra_Resistance << " 0x" << std::hex << (unsigned)rhs.m_Extra_Resistance << std::dec << "\n";
    os << "m_Extra_Hitpoints=" << (unsigned)rhs.m_Extra_Hitpoints << " 0x" << std::hex << (unsigned)rhs.m_Extra_Hitpoints << std::dec << "\n";
    os << "m_Lost_Melee=" << (unsigned)rhs.m_Lost_Melee << " 0x" << std::hex << (unsigned)rhs.m_Lost_Melee << std::dec << "\n";
    os << "m_Lost_Ranged=" << (unsigned)rhs.m_Lost_Ranged << " 0x" << std::hex << (unsigned)rhs.m_Lost_Ranged << std::dec << "\n";
    os << "m_Lost_Defense=" << (unsigned)rhs.m_Lost_Defense << " 0x" << std::hex << (unsigned)rhs.m_Lost_Defense << std::dec << "\n";
    os << "m_Lost_Resistance=" << (unsigned)rhs.m_Lost_Resistance << " 0x" << std::hex << (unsigned)rhs.m_Lost_Resistance << std::dec << "\n";
    os << "m_Unused6D=" << (unsigned)rhs.m_Unused6D << " 0x" << std::hex << (unsigned)rhs.m_Unused6D << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Battlefield& rhs)
{
    os << "{\n";
    os << "m_Terrain=(\n";
    for (unsigned i = 0; i < 462; ++i)
    {
        os << "[" << i << "] " << rhs.m_Terrain[i] << ",\n";
    }
    os << ")\n";
    os << "m_TerrainGroupType=(\n";
    for (unsigned i = 0; i < 462; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_TerrainGroupType[i] << " 0x" << std::hex << (unsigned)rhs.m_TerrainGroupType[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Road=(\n";
    for (unsigned i = 0; i < 462; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Road[i] << " 0x" << std::hex << (unsigned)rhs.m_Road[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Movement_walking=(\n";
    for (unsigned i = 0; i < 462; ++i)
    {
        os << "[" << i << "] " << (int)rhs.m_Movement_walking[i] << " 0x" << std::hex << (int)rhs.m_Movement_walking[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Movement_merging_teleporting_fly=(\n";
    for (unsigned i = 0; i < 462; ++i)
    {
        os << "[" << i << "] " << (int)rhs.m_Movement_merging_teleporting_fly[i] << " 0x" << std::hex << (int)rhs.m_Movement_merging_teleporting_fly[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Movement_similar_to_walking=(\n";
    for (unsigned i = 0; i < 462; ++i)
    {
        os << "[" << i << "] " << (int)rhs.m_Movement_similar_to_walking[i] << " 0x" << std::hex << (int)rhs.m_Movement_similar_to_walking[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Movement_sailing=(\n";
    for (unsigned i = 0; i < 462; ++i)
    {
        os << "[" << i << "] " << (int)rhs.m_Movement_sailing[i] << " 0x" << std::hex << (int)rhs.m_Movement_sailing[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Nr_tree_pics=" << rhs.m_Nr_tree_pics << " 0x" << std::hex << rhs.m_Nr_tree_pics << std::dec << "\n";
    os << "m_xpel_tree_pics=(\n";
    for (unsigned i = 0; i < 100; ++i)
    {
        os << "[" << i << "] " << rhs.m_xpel_tree_pics[i] << " 0x" << std::hex << rhs.m_xpel_tree_pics[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_ypel_tree_pics=(\n";
    for (unsigned i = 0; i < 100; ++i)
    {
        os << "[" << i << "] " << rhs.m_ypel_tree_pics[i] << " 0x" << std::hex << rhs.m_ypel_tree_pics[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_tree_pics=(\n";
    for (unsigned i = 0; i < 100; ++i)
    {
        os << "[" << i << "] " << rhs.m_tree_pics[i] << " 0x" << std::hex << rhs.m_tree_pics[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Nr_rock_pics=" << rhs.m_Nr_rock_pics << " 0x" << std::hex << rhs.m_Nr_rock_pics << std::dec << "\n";
    os << "m_xpel_rock_pics=(\n";
    for (unsigned i = 0; i < 100; ++i)
    {
        os << "[" << i << "] " << rhs.m_xpel_rock_pics[i] << " 0x" << std::hex << rhs.m_xpel_rock_pics[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_ypel_rock_pics=(\n";
    for (unsigned i = 0; i < 100; ++i)
    {
        os << "[" << i << "] " << rhs.m_ypel_rock_pics[i] << " 0x" << std::hex << rhs.m_ypel_rock_pics[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_rock_pics=(\n";
    for (unsigned i = 0; i < 100; ++i)
    {
        os << "[" << i << "] " << rhs.m_rock_pics[i] << " 0x" << std::hex << rhs.m_rock_pics[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Mud=(\n";
    for (unsigned i = 0; i < 462; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Mud[i] << " 0x" << std::hex << (unsigned)rhs.m_Mud[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Central_structure=" << rhs.m_Central_structure << "\n";
    os << "m_Nr_houses=" << rhs.m_Nr_houses << " 0x" << std::hex << rhs.m_Nr_houses << std::dec << "\n";
    os << "m_xpos_houses=(\n";
    for (unsigned i = 0; i < 16; ++i)
    {
        os << "[" << i << "] " << rhs.m_xpos_houses[i] << " 0x" << std::hex << rhs.m_xpos_houses[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_ypos_houses=(\n";
    for (unsigned i = 0; i < 16; ++i)
    {
        os << "[" << i << "] " << rhs.m_ypos_houses[i] << " 0x" << std::hex << rhs.m_ypos_houses[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_house_pics=(\n";
    for (unsigned i = 0; i < 16; ++i)
    {
        os << "[" << i << "] " << rhs.m_house_pics[i] << " 0x" << std::hex << rhs.m_house_pics[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_City_Walls=" << rhs.m_City_Walls << "\n";
    os << "m_Wall_present_4x4=(\n";
    for (unsigned i = 0; i < 16; ++i)
    {
        os << "[" << i << "] " << rhs.m_Wall_present_4x4[i] << " 0x" << std::hex << rhs.m_Wall_present_4x4[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Wall_of_Fire=" << rhs.m_Wall_of_Fire << "\n";
    os << "m_Wall_of_Darkness=" << rhs.m_Wall_of_Darkness << "\n";
    os << "m_Plane=" << rhs.m_Plane << " 0x" << std::hex << rhs.m_Plane << std::dec << "\n";
    os << "m_City_Enchantments=" << rhs.m_City_Enchantments << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const BorlandSegmentEntry& rhs)
{
    os << "{\n";
    os << "base=" << rhs.base << " 0x" << std::hex << rhs.base << std::dec << "\n";
    os << "size=" << rhs.size << " 0x" << std::hex << rhs.size << std::dec << "\n";
    os << "type=" << rhs.type << " 0x" << std::hex << rhs.type << std::dec << "\n";
    os << "offset=" << rhs.offset << " 0x" << std::hex << rhs.offset << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const BorlandStub& rhs)
{
    os << "{\n";
    os << "int_code=(\n";
    for (unsigned i = 0; i < 2; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.int_code[i] << " 0x" << std::hex << (unsigned)rhs.int_code[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "memswap=" << rhs.memswap << " 0x" << std::hex << rhs.memswap << std::dec << "\n";
    os << "fileoff=" << rhs.fileoff << " 0x" << std::hex << rhs.fileoff << std::dec << "\n";
    os << "codesize=" << rhs.codesize << " 0x" << std::hex << rhs.codesize << std::dec << "\n";
    os << "relsize=" << rhs.relsize << " 0x" << std::hex << rhs.relsize << std::dec << "\n";
    os << "nentries=" << rhs.nentries << " 0x" << std::hex << rhs.nentries << std::dec << "\n";
    os << "prevstub=" << rhs.prevstub << " 0x" << std::hex << rhs.prevstub << std::dec << "\n";
    os << "workarea=(\n";
    for (unsigned i = 0; i < 0x10; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.workarea[i] << " 0x" << std::hex << (unsigned)rhs.workarea[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "entries=(\n";
    for (unsigned i = 0; i < 1; ++i)
    {
        os << "[" << i << "] " << rhs.entries[i] << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const BorlandStubJmpEntry& rhs)
{
    os << "{\n";
    os << "jmpfar_code=" << (unsigned)rhs.jmpfar_code << " 0x" << std::hex << (unsigned)rhs.jmpfar_code << std::dec << "\n";
    os << "offset=" << rhs.offset << " 0x" << std::hex << rhs.offset << std::dec << "\n";
    os << "base_addr=" << rhs.base_addr << " 0x" << std::hex << rhs.base_addr << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Building_Data& rhs)
{
    os << "{\n";
    os << "m_BuildingName=" << formatCharArray(rhs.m_BuildingName, 20) << "\n";
    os << "m_Prerequisite1=" << rhs.m_Prerequisite1 << "\n";
    os << "m_Prerequisite2=" << rhs.m_Prerequisite2 << "\n";
    os << "m_Replaces_building=" << rhs.m_Replaces_building << "\n";
    os << "m_Produces_Regulars=" << rhs.m_Produces_Regulars << "\n";
    os << "m_Produces_Veterans=" << rhs.m_Produces_Veterans << "\n";
    os << "m_Produces_Magic_Weapons=" << rhs.m_Produces_Magic_Weapons << "\n";
    os << "m_Upkeep_yield=" << rhs.m_Upkeep_yield << " 0x" << std::hex << rhs.m_Upkeep_yield << std::dec << "\n";
    os << "m_AI_trade_goods_housing=" << rhs.m_AI_trade_goods_housing << " 0x" << std::hex << rhs.m_AI_trade_goods_housing << std::dec << "\n";
    os << "m_Zero_24=" << rhs.m_Zero_24 << " 0x" << std::hex << rhs.m_Zero_24 << std::dec << "\n";
    os << "m_Zero_26=" << rhs.m_Zero_26 << " 0x" << std::hex << rhs.m_Zero_26 << std::dec << "\n";
    os << "m_AI_Religious=" << rhs.m_AI_Religious << " 0x" << std::hex << rhs.m_AI_Religious << std::dec << "\n";
    os << "m_AI_Research=" << rhs.m_AI_Research << " 0x" << std::hex << rhs.m_AI_Research << std::dec << "\n";
    os << "m_Building_cost=" << rhs.m_Building_cost << " 0x" << std::hex << rhs.m_Building_cost << std::dec << "\n";
    os << "m_Zero_2E=" << rhs.m_Zero_2E << " 0x" << std::hex << rhs.m_Zero_2E << std::dec << "\n";
    os << "m_Animation_related=" << rhs.m_Animation_related << " 0x" << std::hex << rhs.m_Animation_related << std::dec << "\n";
    os << "m_Building_category=" << rhs.m_Building_category << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Building_Status& rhs)
{
    os << "{\n";
    os << "No_building=" << rhs.No_building << "\n";
    os << "Trade_Goods=" << rhs.Trade_Goods << "\n";
    os << "Housing=" << rhs.Housing << "\n";
    os << "Barracks=" << rhs.Barracks << "\n";
    os << "Armory=" << rhs.Armory << "\n";
    os << "Fighters_Guild=" << rhs.Fighters_Guild << "\n";
    os << "Armorers_Guild=" << rhs.Armorers_Guild << "\n";
    os << "War_College=" << rhs.War_College << "\n";
    os << "Smithy=" << rhs.Smithy << "\n";
    os << "Stable=" << rhs.Stable << "\n";
    os << "Animists_Guild=" << rhs.Animists_Guild << "\n";
    os << "Fantastic_Stable=" << rhs.Fantastic_Stable << "\n";
    os << "Shipwright_Guild=" << rhs.Shipwright_Guild << "\n";
    os << "Ship_Yard=" << rhs.Ship_Yard << "\n";
    os << "Maritime_Guild=" << rhs.Maritime_Guild << "\n";
    os << "Sawmill=" << rhs.Sawmill << "\n";
    os << "Library=" << rhs.Library << "\n";
    os << "Sages_Guild=" << rhs.Sages_Guild << "\n";
    os << "Oracle=" << rhs.Oracle << "\n";
    os << "Alchemist_Guild=" << rhs.Alchemist_Guild << "\n";
    os << "University=" << rhs.University << "\n";
    os << "Wizards_Guild=" << rhs.Wizards_Guild << "\n";
    os << "Shrine=" << rhs.Shrine << "\n";
    os << "Temple=" << rhs.Temple << "\n";
    os << "Parthenon=" << rhs.Parthenon << "\n";
    os << "Cathedral=" << rhs.Cathedral << "\n";
    os << "Marketplace=" << rhs.Marketplace << "\n";
    os << "Bank=" << rhs.Bank << "\n";
    os << "Merchants_Guild=" << rhs.Merchants_Guild << "\n";
    os << "Granary=" << rhs.Granary << "\n";
    os << "Farmers_Market=" << rhs.Farmers_Market << "\n";
    os << "Foresters_Guild=" << rhs.Foresters_Guild << "\n";
    os << "Builders_Hall=" << rhs.Builders_Hall << "\n";
    os << "Mechanicians_Guild=" << rhs.Mechanicians_Guild << "\n";
    os << "Miners_Guild=" << rhs.Miners_Guild << "\n";
    os << "City_Walls=" << rhs.City_Walls << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const City& rhs)
{
    os << "{\n";
    os << "m_City_Name=" << formatCharArray(rhs.m_City_Name, 14) << "\n";
    os << "m_Race=" << rhs.m_Race << "\n";
    os << "m_XPos=" << (int)rhs.m_XPos << " 0x" << std::hex << (int)rhs.m_XPos << std::dec << "\n";
    os << "m_YPos=" << (int)rhs.m_YPos << " 0x" << std::hex << (int)rhs.m_YPos << std::dec << "\n";
    os << "m_Plane=" << rhs.m_Plane << "\n";
    os << "m_Owner=" << rhs.m_Owner << "\n";
    os << "m_Size=" << rhs.m_Size << "\n";
    os << "m_Population=" << (unsigned)rhs.m_Population << " 0x" << std::hex << (unsigned)rhs.m_Population << std::dec << "\n";
    os << "m_Number_of_farmers_allocated=" << (int)rhs.m_Number_of_farmers_allocated << " 0x" << std::hex << (int)rhs.m_Number_of_farmers_allocated << std::dec << "\n";
    os << "m_Building_sold=" << rhs.m_Building_sold << "\n";
    os << "m_Unk_17=" << (unsigned)rhs.m_Unk_17 << " 0x" << std::hex << (unsigned)rhs.m_Unk_17 << std::dec << "\n";
    os << "m_PopulationDekaPop=" << rhs.m_PopulationDekaPop << " 0x" << std::hex << rhs.m_PopulationDekaPop << std::dec << "\n";
    os << "m_Player_as_bitmask_GUESS=" << (unsigned)rhs.m_Player_as_bitmask_GUESS << " 0x" << std::hex << (unsigned)rhs.m_Player_as_bitmask_GUESS << std::dec << "\n";
    os << "m_Unk_1B=" << (unsigned)rhs.m_Unk_1B << " 0x" << std::hex << (unsigned)rhs.m_Unk_1B << std::dec << "\n";
    os << "m_Producing=" << rhs.m_Producing << "\n";
    os << "m_Nr_buildings=" << (unsigned)rhs.m_Nr_buildings << " 0x" << std::hex << (unsigned)rhs.m_Nr_buildings << std::dec << "\n";
    os << "m_Building_Status=" << rhs.m_Building_Status << "\n";
    os << "m_City_Enchantments=" << rhs.m_City_Enchantments << "\n";
    os << "m_Nightshade=" << rhs.m_Nightshade << "\n";
    os << "m_Hammers=" << (int)rhs.m_Hammers << " 0x" << std::hex << (int)rhs.m_Hammers << std::dec << "\n";
    os << "m_HammersAccumulated=" << rhs.m_HammersAccumulated << " 0x" << std::hex << rhs.m_HammersAccumulated << std::dec << "\n";
    os << "m_Coins=" << (int)rhs.m_Coins << " 0x" << std::hex << (int)rhs.m_Coins << std::dec << "\n";
    os << "m_Maintenance=" << (int)rhs.m_Maintenance << " 0x" << std::hex << (int)rhs.m_Maintenance << std::dec << "\n";
    os << "m_Mana_cr=" << (int)rhs.m_Mana_cr << " 0x" << std::hex << (int)rhs.m_Mana_cr << std::dec << "\n";
    os << "m_Research=" << (int)rhs.m_Research << " 0x" << std::hex << (int)rhs.m_Research << std::dec << "\n";
    os << "m_Food_Produced=" << (int)rhs.m_Food_Produced << " 0x" << std::hex << (int)rhs.m_Food_Produced << std::dec << "\n";
    os << "m_Road_Connection_GUESS=" << (int)rhs.m_Road_Connection_GUESS << " 0x" << std::hex << (int)rhs.m_Road_Connection_GUESS << std::dec << "\n";
    os << "m_Unk_66=(\n";
    for (unsigned i = 0; i < 12; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_66[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_66[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const City_Enchantments& rhs)
{
    os << "{\n";
    os << "Wall_of_Fire=" << rhs.Wall_of_Fire << "\n";
    os << "_Chaos_Rift_=" << rhs._Chaos_Rift_ << "\n";
    os << "Dark_Rituals=" << rhs.Dark_Rituals << "\n";
    os << "_Evil_Presence_=" << rhs._Evil_Presence_ << "\n";
    os << "_Cursed_Lands_=" << rhs._Cursed_Lands_ << "\n";
    os << "_Pestilence_=" << rhs._Pestilence_ << "\n";
    os << "Cloud_of_Shadow=" << rhs.Cloud_of_Shadow << "\n";
    os << "_Famine_=" << rhs._Famine_ << "\n";
    os << "Flying_Fortress=" << rhs.Flying_Fortress << "\n";
    os << "Nature_Ward=" << rhs.Nature_Ward << "\n";
    os << "Sorcery_Ward=" << rhs.Sorcery_Ward << "\n";
    os << "Chaos_Ward=" << rhs.Chaos_Ward << "\n";
    os << "Life_Ward=" << rhs.Life_Ward << "\n";
    os << "Death_Ward=" << rhs.Death_Ward << "\n";
    os << "Natures_Eye=" << rhs.Natures_Eye << "\n";
    os << "Earth_Gate=" << rhs.Earth_Gate << "\n";
    os << "Stream_of_Life=" << rhs.Stream_of_Life << "\n";
    os << "Gaias_Blessing=" << rhs.Gaias_Blessing << "\n";
    os << "Inspirations=" << rhs.Inspirations << "\n";
    os << "Prosperity=" << rhs.Prosperity << "\n";
    os << "Astral_Gate=" << rhs.Astral_Gate << "\n";
    os << "Heavenly_Light=" << rhs.Heavenly_Light << "\n";
    os << "Consecration=" << rhs.Consecration << "\n";
    os << "Wall_of_Darkness=" << rhs.Wall_of_Darkness << "\n";
    os << "Altar_of_Battle=" << rhs.Altar_of_Battle << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Combat_Enchantment& rhs)
{
    os << "{\n";
    if (0 != rhs.Vertigo)
    {
    os << "Vertigo=" << (unsigned)rhs.Vertigo << "\n";
    }
    if (0 != rhs.Confusion)
    {
    os << "Confusion=" << (unsigned)rhs.Confusion << "\n";
    }
    if (0 != rhs.Whirlwind)
    {
    os << "Whirlwind=" << (unsigned)rhs.Whirlwind << "\n";
    }
    if (0 != rhs.Mind_Storm)
    {
    os << "Mind_Storm=" << (unsigned)rhs.Mind_Storm << "\n";
    }
    if (0 != rhs.Shatter)
    {
    os << "Shatter=" << (unsigned)rhs.Shatter << "\n";
    }
    if (0 != rhs.Weakness)
    {
    os << "Weakness=" << (unsigned)rhs.Weakness << "\n";
    }
    if (0 != rhs.Black_Sleep)
    {
    os << "Black_Sleep=" << (unsigned)rhs.Black_Sleep << "\n";
    }
    if (0 != rhs.Warp_Creature_Attack)
    {
    os << "Warp_Creature_Attack=" << (unsigned)rhs.Warp_Creature_Attack << "\n";
    }
    if (0 != rhs.Warp_Creature_Defense)
    {
    os << "Warp_Creature_Defense=" << (unsigned)rhs.Warp_Creature_Defense << "\n";
    }
    if (0 != rhs.Warp_Creature_Resistance)
    {
    os << "Warp_Creature_Resistance=" << (unsigned)rhs.Warp_Creature_Resistance << "\n";
    }
    if (0 != rhs.Mind_Twist)
    {
    os << "Mind_Twist=" << (unsigned)rhs.Mind_Twist << "\n";
    }
    if (0 != rhs.Haste)
    {
    os << "Haste=" << (unsigned)rhs.Haste << "\n";
    }
    if (0 != rhs.Web)
    {
    os << "Web=" << (unsigned)rhs.Web << "\n";
    }
    if (0 != rhs.Creature_Binding)
    {
    os << "Creature_Binding=" << (unsigned)rhs.Creature_Binding << "\n";
    }
    if (0 != rhs.Possession)
    {
    os << "Possession=" << (unsigned)rhs.Possession << "\n";
    }
    if (0 != rhs.No_Effect80)
    {
    os << "No_Effect80=" << (unsigned)rhs.No_Effect80 << "\n";
    }
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Difficulty_Table& rhs)
{
    os << "{\n";
    os << "m_City_Growth_multiplier=" << rhs.m_City_Growth_multiplier << " 0x" << std::hex << rhs.m_City_Growth_multiplier << std::dec << "\n";
    os << "m_Outpost_Growth_multiplier=" << rhs.m_Outpost_Growth_multiplier << " 0x" << std::hex << rhs.m_Outpost_Growth_multiplier << std::dec << "\n";
    os << "m_City_Production_multiplier=" << rhs.m_City_Production_multiplier << " 0x" << std::hex << rhs.m_City_Production_multiplier << std::dec << "\n";
    os << "m_City_Coin_multiplier=" << rhs.m_City_Coin_multiplier << " 0x" << std::hex << rhs.m_City_Coin_multiplier << std::dec << "\n";
    os << "m_City_Mana_multiplier=" << rhs.m_City_Mana_multiplier << " 0x" << std::hex << rhs.m_City_Mana_multiplier << std::dec << "\n";
    os << "m_City_Research_multiplier=" << rhs.m_City_Research_multiplier << " 0x" << std::hex << rhs.m_City_Research_multiplier << std::dec << "\n";
    os << "m_City_Food_multiplier=" << rhs.m_City_Food_multiplier << " 0x" << std::hex << rhs.m_City_Food_multiplier << std::dec << "\n";
    os << "m_City_Maintenance_multiplier=" << rhs.m_City_Maintenance_multiplier << " 0x" << std::hex << rhs.m_City_Maintenance_multiplier << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const EMS_descriptor& rhs)
{
    os << "{\n";
    os << "m_name=" << formatCharArray(rhs.m_name, 9) << "\n";
    os << "m_Unk_09=" << (unsigned)rhs.m_Unk_09 << " 0x" << std::hex << (unsigned)rhs.m_Unk_09 << std::dec << "\n";
    os << "m_Unk_0A=" << rhs.m_Unk_0A << " 0x" << std::hex << rhs.m_Unk_0A << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const EXE_Header& rhs)
{
    os << "{\n";
    os << "signature=" << rhs.signature << " 0x" << std::hex << rhs.signature << std::dec << "\n";
    os << "bytes_in_last_block=" << rhs.bytes_in_last_block << " 0x" << std::hex << rhs.bytes_in_last_block << std::dec << "\n";
    os << "blocks_in_file=" << rhs.blocks_in_file << " 0x" << std::hex << rhs.blocks_in_file << std::dec << "\n";
    os << "nr_relocation_items=" << rhs.nr_relocation_items << " 0x" << std::hex << rhs.nr_relocation_items << std::dec << "\n";
    os << "load_module_offset_paragraphs=" << rhs.load_module_offset_paragraphs << " 0x" << std::hex << rhs.load_module_offset_paragraphs << std::dec << "\n";
    os << "min_needed_paragraphs=" << rhs.min_needed_paragraphs << " 0x" << std::hex << rhs.min_needed_paragraphs << std::dec << "\n";
    os << "max_needed_paragraphs=" << rhs.max_needed_paragraphs << " 0x" << std::hex << rhs.max_needed_paragraphs << std::dec << "\n";
    os << "ss_offset_in_load_module_paragraphs=" << rhs.ss_offset_in_load_module_paragraphs << " 0x" << std::hex << rhs.ss_offset_in_load_module_paragraphs << std::dec << "\n";
    os << "sp_initial=" << rhs.sp_initial << " 0x" << std::hex << rhs.sp_initial << std::dec << "\n";
    os << "checksum=" << rhs.checksum << " 0x" << std::hex << rhs.checksum << std::dec << "\n";
    os << "ip_program_entry_point=" << rhs.ip_program_entry_point << " 0x" << std::hex << rhs.ip_program_entry_point << std::dec << "\n";
    os << "cs_offset_in_load_module_paragraphs=" << rhs.cs_offset_in_load_module_paragraphs << " 0x" << std::hex << rhs.cs_offset_in_load_module_paragraphs << std::dec << "\n";
    os << "relocation_table_offset_bytes=" << rhs.relocation_table_offset_bytes << " 0x" << std::hex << rhs.relocation_table_offset_bytes << std::dec << "\n";
    os << "overlay_number=" << rhs.overlay_number << " 0x" << std::hex << rhs.overlay_number << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const EXE_Reloc& rhs)
{
    os << std::hex << rhs.segment << ':' << rhs.offset << std::dec;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Events_Status& rhs)
{
    os << "{\n";
    os << "m_Turn_Event_triggered_GUESS=" << rhs.m_Turn_Event_triggered_GUESS << " 0x" << std::hex << rhs.m_Turn_Event_triggered_GUESS << std::dec << "\n";
    os << "m_Meteor_active=" << rhs.m_Meteor_active << " 0x" << std::hex << rhs.m_Meteor_active << std::dec << "\n";
    os << "m_Meteor_playerNr=" << rhs.m_Meteor_playerNr << " 0x" << std::hex << rhs.m_Meteor_playerNr << std::dec << "\n";
    os << "m_Meteor_cityNr=" << rhs.m_Meteor_cityNr << " 0x" << std::hex << rhs.m_Meteor_cityNr << std::dec << "\n";
    os << "m_Gift_of_the_Gods_active=" << rhs.m_Gift_of_the_Gods_active << " 0x" << std::hex << rhs.m_Gift_of_the_Gods_active << std::dec << "\n";
    os << "m_Gift_of_the_Gods_playerNr=" << rhs.m_Gift_of_the_Gods_playerNr << " 0x" << std::hex << rhs.m_Gift_of_the_Gods_playerNr << std::dec << "\n";
    os << "m_Gift_of_the_Gods_itemNr_GUESS=" << rhs.m_Gift_of_the_Gods_itemNr_GUESS << " 0x" << std::hex << rhs.m_Gift_of_the_Gods_itemNr_GUESS << std::dec << "\n";
    os << "m_Disjunction_active=" << rhs.m_Disjunction_active << " 0x" << std::hex << rhs.m_Disjunction_active << std::dec << "\n";
    os << "m_Diplomatic_Marriage_active=" << rhs.m_Diplomatic_Marriage_active << " 0x" << std::hex << rhs.m_Diplomatic_Marriage_active << std::dec << "\n";
    os << "m_Diplomatic_Marriage_playerNr=" << rhs.m_Diplomatic_Marriage_playerNr << " 0x" << std::hex << rhs.m_Diplomatic_Marriage_playerNr << std::dec << "\n";
    os << "m_Diplomatic_Marriage_newCityNr_GUESS=" << rhs.m_Diplomatic_Marriage_newCityNr_GUESS << " 0x" << std::hex << rhs.m_Diplomatic_Marriage_newCityNr_GUESS << std::dec << "\n";
    os << "m_Diplomatic_Marriage_cityNr_GUESS=" << rhs.m_Diplomatic_Marriage_cityNr_GUESS << " 0x" << std::hex << rhs.m_Diplomatic_Marriage_cityNr_GUESS << std::dec << "\n";
    os << "m_Earthquake_active=" << rhs.m_Earthquake_active << " 0x" << std::hex << rhs.m_Earthquake_active << std::dec << "\n";
    os << "m_Earthquake_playerNr=" << rhs.m_Earthquake_playerNr << " 0x" << std::hex << rhs.m_Earthquake_playerNr << std::dec << "\n";
    os << "m_Earthquake_cityNr=" << rhs.m_Earthquake_cityNr << " 0x" << std::hex << rhs.m_Earthquake_cityNr << std::dec << "\n";
    os << "m_Pirates_active=" << rhs.m_Pirates_active << " 0x" << std::hex << rhs.m_Pirates_active << std::dec << "\n";
    os << "m_Pirates_playerNr=" << rhs.m_Pirates_playerNr << " 0x" << std::hex << rhs.m_Pirates_playerNr << std::dec << "\n";
    os << "m_Pirates_gold_stolen=" << rhs.m_Pirates_gold_stolen << " 0x" << std::hex << rhs.m_Pirates_gold_stolen << std::dec << "\n";
    os << "m_Plague_active=" << rhs.m_Plague_active << " 0x" << std::hex << rhs.m_Plague_active << std::dec << "\n";
    os << "m_Plague_playerNr=" << rhs.m_Plague_playerNr << " 0x" << std::hex << rhs.m_Plague_playerNr << std::dec << "\n";
    os << "m_Plague_cityNr=" << rhs.m_Plague_cityNr << " 0x" << std::hex << rhs.m_Plague_cityNr << std::dec << "\n";
    os << "m_UNUSED01=" << rhs.m_UNUSED01 << " 0x" << std::hex << rhs.m_UNUSED01 << std::dec << "\n";
    os << "m_Rebellion_active=" << rhs.m_Rebellion_active << " 0x" << std::hex << rhs.m_Rebellion_active << std::dec << "\n";
    os << "m_Rebellion_playerNr=" << rhs.m_Rebellion_playerNr << " 0x" << std::hex << rhs.m_Rebellion_playerNr << std::dec << "\n";
    os << "m_Rebellion_cityNr=" << rhs.m_Rebellion_cityNr << " 0x" << std::hex << rhs.m_Rebellion_cityNr << std::dec << "\n";
    os << "m_Donation_active=" << rhs.m_Donation_active << " 0x" << std::hex << rhs.m_Donation_active << std::dec << "\n";
    os << "m_Donation_playerNr=" << rhs.m_Donation_playerNr << " 0x" << std::hex << rhs.m_Donation_playerNr << std::dec << "\n";
    os << "m_Donation_gold_donated=" << rhs.m_Donation_gold_donated << " 0x" << std::hex << rhs.m_Donation_gold_donated << std::dec << "\n";
    os << "m_Depletion_active=" << rhs.m_Depletion_active << " 0x" << std::hex << rhs.m_Depletion_active << std::dec << "\n";
    os << "m_Depletion_playerNr=" << rhs.m_Depletion_playerNr << " 0x" << std::hex << rhs.m_Depletion_playerNr << std::dec << "\n";
    os << "m_UNUSED02=" << rhs.m_UNUSED02 << " 0x" << std::hex << rhs.m_UNUSED02 << std::dec << "\n";
    os << "m_Mine_found_active=" << rhs.m_Mine_found_active << " 0x" << std::hex << rhs.m_Mine_found_active << std::dec << "\n";
    os << "m_Mine_found_playerNr=" << rhs.m_Mine_found_playerNr << " 0x" << std::hex << rhs.m_Mine_found_playerNr << std::dec << "\n";
    os << "m_UNUSED03=" << rhs.m_UNUSED03 << " 0x" << std::hex << rhs.m_UNUSED03 << std::dec << "\n";
    os << "m_Population_Boom_active=" << rhs.m_Population_Boom_active << " 0x" << std::hex << rhs.m_Population_Boom_active << std::dec << "\n";
    os << "m_Population_Boom_CityNr=" << rhs.m_Population_Boom_CityNr << " 0x" << std::hex << rhs.m_Population_Boom_CityNr << std::dec << "\n";
    os << "m_Population_Boom_PlayerNr=" << rhs.m_Population_Boom_PlayerNr << " 0x" << std::hex << rhs.m_Population_Boom_PlayerNr << std::dec << "\n";
    os << "m_UNUSED04=" << rhs.m_UNUSED04 << " 0x" << std::hex << rhs.m_UNUSED04 << std::dec << "\n";
    os << "m_Good_Moon_active=" << rhs.m_Good_Moon_active << " 0x" << std::hex << rhs.m_Good_Moon_active << std::dec << "\n";
    os << "m_UNUSED05=" << rhs.m_UNUSED05 << " 0x" << std::hex << rhs.m_UNUSED05 << std::dec << "\n";
    os << "m_Bad_Moon_active=" << rhs.m_Bad_Moon_active << " 0x" << std::hex << rhs.m_Bad_Moon_active << std::dec << "\n";
    os << "m_UNUSED06=" << rhs.m_UNUSED06 << " 0x" << std::hex << rhs.m_UNUSED06 << std::dec << "\n";
    os << "m_Conjunction_Sorcery_active=" << rhs.m_Conjunction_Sorcery_active << " 0x" << std::hex << rhs.m_Conjunction_Sorcery_active << std::dec << "\n";
    os << "m_Conjunction_Sorcery_Nr_GUESS=" << rhs.m_Conjunction_Sorcery_Nr_GUESS << " 0x" << std::hex << rhs.m_Conjunction_Sorcery_Nr_GUESS << std::dec << "\n";
    os << "m_Conjunction_Nature_active=" << rhs.m_Conjunction_Nature_active << " 0x" << std::hex << rhs.m_Conjunction_Nature_active << std::dec << "\n";
    os << "m_Conjunction_Nature_Nr_GUESS=" << rhs.m_Conjunction_Nature_Nr_GUESS << " 0x" << std::hex << rhs.m_Conjunction_Nature_Nr_GUESS << std::dec << "\n";
    os << "m_Conjunction_Chaos_active=" << rhs.m_Conjunction_Chaos_active << " 0x" << std::hex << rhs.m_Conjunction_Chaos_active << std::dec << "\n";
    os << "m_Conjunction_Chaos_Nr_GUESS=" << rhs.m_Conjunction_Chaos_Nr_GUESS << " 0x" << std::hex << rhs.m_Conjunction_Chaos_Nr_GUESS << std::dec << "\n";
    os << "m_Mana_Short_active=" << rhs.m_Mana_Short_active << " 0x" << std::hex << rhs.m_Mana_Short_active << std::dec << "\n";
    os << "m_UNUSED10=" << rhs.m_UNUSED10 << " 0x" << std::hex << rhs.m_UNUSED10 << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const FLIC_COLOR_64& rhs)
{
    os << "{\n";
    os << "size=" << rhs.size << " 0x" << std::hex << rhs.size << std::dec << "\n";
    os << "type=" << rhs.type << " 0x" << std::hex << rhs.type << std::dec << "\n";
    os << "chunks=" << rhs.chunks << " 0x" << std::hex << rhs.chunks << std::dec << "\n";
    os << "skip=" << rhs.skip << " 0x" << std::hex << rhs.skip << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const FLIC_FLI_COPY& rhs)
{
    os << "{\n";
    os << "size=" << rhs.size << " 0x" << std::hex << rhs.size << std::dec << "\n";
    os << "type=" << rhs.type << " 0x" << std::hex << rhs.type << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const FLIC_FRAME_TYPE& rhs)
{
    os << "{\n";
    os << "size=" << rhs.size << " 0x" << std::hex << rhs.size << std::dec << "\n";
    os << "type=" << rhs.type << " 0x" << std::hex << rhs.type << std::dec << "\n";
    os << "chunks=" << rhs.chunks << " 0x" << std::hex << rhs.chunks << std::dec << "\n";
    os << "delay=" << rhs.delay << " 0x" << std::hex << rhs.delay << std::dec << "\n";
    os << "reserved=" << rhs.reserved << " 0x" << std::hex << rhs.reserved << std::dec << "\n";
    os << "width=" << rhs.width << " 0x" << std::hex << rhs.width << std::dec << "\n";
    os << "height=" << rhs.height << " 0x" << std::hex << rhs.height << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const FLIC_HEADER& rhs)
{
    os << "{\n";
    os << "size=" << rhs.size << " 0x" << std::hex << rhs.size << std::dec << "\n";
    os << "type=" << rhs.type << " 0x" << std::hex << rhs.type << std::dec << "\n";
    os << "frames=" << rhs.frames << " 0x" << std::hex << rhs.frames << std::dec << "\n";
    os << "width=" << rhs.width << " 0x" << std::hex << rhs.width << std::dec << "\n";
    os << "height=" << rhs.height << " 0x" << std::hex << rhs.height << std::dec << "\n";
    os << "depth=" << rhs.depth << " 0x" << std::hex << rhs.depth << std::dec << "\n";
    os << "flags=" << rhs.flags << " 0x" << std::hex << rhs.flags << std::dec << "\n";
    os << "speed=" << rhs.speed << " 0x" << std::hex << rhs.speed << std::dec << "\n";
    os << "reserved1=" << rhs.reserved1 << " 0x" << std::hex << rhs.reserved1 << std::dec << "\n";
    os << "created=" << rhs.created << " 0x" << std::hex << rhs.created << std::dec << "\n";
    os << "creator=" << rhs.creator << " 0x" << std::hex << rhs.creator << std::dec << "\n";
    os << "updated=" << rhs.updated << " 0x" << std::hex << rhs.updated << std::dec << "\n";
    os << "updater=" << rhs.updater << " 0x" << std::hex << rhs.updater << std::dec << "\n";
    os << "aspect_dx=" << rhs.aspect_dx << " 0x" << std::hex << rhs.aspect_dx << std::dec << "\n";
    os << "aspect_dy=" << rhs.aspect_dy << " 0x" << std::hex << rhs.aspect_dy << std::dec << "\n";
    os << "ext_flags=" << rhs.ext_flags << " 0x" << std::hex << rhs.ext_flags << std::dec << "\n";
    os << "keyframes=" << rhs.keyframes << " 0x" << std::hex << rhs.keyframes << std::dec << "\n";
    os << "totalframes=" << rhs.totalframes << " 0x" << std::hex << rhs.totalframes << std::dec << "\n";
    os << "req_memory=" << rhs.req_memory << " 0x" << std::hex << rhs.req_memory << std::dec << "\n";
    os << "max_regions=" << rhs.max_regions << " 0x" << std::hex << rhs.max_regions << std::dec << "\n";
    os << "transp_num=" << rhs.transp_num << " 0x" << std::hex << rhs.transp_num << std::dec << "\n";
    os << "reserved2=(\n";
    for (unsigned i = 0; i < 24; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.reserved2[i] << " 0x" << std::hex << (unsigned)rhs.reserved2[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "oframe1=" << rhs.oframe1 << " 0x" << std::hex << rhs.oframe1 << std::dec << "\n";
    os << "oframe2=" << rhs.oframe2 << " 0x" << std::hex << rhs.oframe2 << std::dec << "\n";
    os << "reserved3=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.reserved3[i] << " 0x" << std::hex << (unsigned)rhs.reserved3[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Fortress& rhs)
{
    os << "{\n";
    os << "m_XPos=" << (int)rhs.m_XPos << " 0x" << std::hex << (int)rhs.m_XPos << std::dec << "\n";
    os << "m_YPos=" << (int)rhs.m_YPos << " 0x" << std::hex << (int)rhs.m_YPos << std::dec << "\n";
    os << "m_Plane=" << rhs.m_Plane << "\n";
    os << "m_Active=" << (int)rhs.m_Active << " 0x" << std::hex << (int)rhs.m_Active << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Game_Data_Save& rhs)
{
    os << "{\n";
    os << "m_Number_of_Wizards=" << rhs.m_Number_of_Wizards << " 0x" << std::hex << rhs.m_Number_of_Wizards << std::dec << "\n";
    os << "m_Land_Size_setting=" << rhs.m_Land_Size_setting << "\n";
    os << "m_Magic_Powerful_setting=" << rhs.m_Magic_Powerful_setting << "\n";
    os << "m_Difficulty=" << rhs.m_Difficulty << "\n";
    os << "m_Number_of_Cities=" << rhs.m_Number_of_Cities << " 0x" << std::hex << rhs.m_Number_of_Cities << std::dec << "\n";
    os << "m_Number_of_Units=" << rhs.m_Number_of_Units << " 0x" << std::hex << rhs.m_Number_of_Units << std::dec << "\n";
    os << "m_Current_Turn=" << rhs.m_Current_Turn << " 0x" << std::hex << rhs.m_Current_Turn << std::dec << "\n";
    os << "m_UnitNr_Active=" << rhs.m_UnitNr_Active << " 0x" << std::hex << rhs.m_UnitNr_Active << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Game_Settings& rhs)
{
    os << "{\n";
    os << "m_Sound_Effects=" << rhs.m_Sound_Effects << "\n";
    os << "m_Background_Music=" << rhs.m_Background_Music << "\n";
    os << "m_Event_Music=" << rhs.m_Event_Music << "\n";
    os << "m_City_Spell_Events=" << rhs.m_City_Spell_Events << "\n";
    os << "m_Overland_Spell_Events=" << rhs.m_Overland_Spell_Events << "\n";
    os << "m_Summoning_Events=" << rhs.m_Summoning_Events << "\n";
    os << "m_End_of_Turn_Summary=" << rhs.m_End_of_Turn_Summary << "\n";
    os << "m_Raze_City=" << rhs.m_Raze_City << "\n";
    os << "m_Random_Events=" << rhs.m_Random_Events << "\n";
    os << "m_End_of_Turn_Wait=" << rhs.m_End_of_Turn_Wait << "\n";
    os << "m_Stratic_Combat_Only=" << rhs.m_Stratic_Combat_Only << "\n";
    os << "m_Auto_Unit_Information=" << rhs.m_Auto_Unit_Information << "\n";
    os << "m_Enemy_Moves=" << rhs.m_Enemy_Moves << "\n";
    os << "m_Enemy_Spells=" << rhs.m_Enemy_Spells << "\n";
    os << "m_Spell_Book_Ordering=" << rhs.m_Spell_Book_Ordering << "\n";
    os << "m_Spell_Animations=" << rhs.m_Spell_Animations << "\n";
    os << "m_Show_Node_Owners=" << rhs.m_Show_Node_Owners << "\n";
    os << "m_Expanding_Help=" << rhs.m_Expanding_Help << "\n";
    os << "m_Unk_024=" << rhs.m_Unk_024 << " 0x" << std::hex << rhs.m_Unk_024 << std::dec << "\n";
    os << "m_Unk_026=" << rhs.m_Unk_026 << " 0x" << std::hex << rhs.m_Unk_026 << std::dec << "\n";
    os << "m_Difficulty=" << rhs.m_Difficulty << "\n";
    os << "m_Nr_Opponents=" << rhs.m_Nr_Opponents << " 0x" << std::hex << rhs.m_Nr_Opponents << std::dec << "\n";
    os << "m_Land_Size=" << rhs.m_Land_Size << "\n";
    os << "m_Magic_Powerful=" << rhs.m_Magic_Powerful << "\n";
    os << "m_Slots_Saved=(\n";
    for (unsigned i = 0; i < 8; ++i)
    {
        os << "[" << i << "] " << rhs.m_Slots_Saved[i] << ",\n";
    }
    os << ")\n";
    os << "m_Save_Names=(\n";
    for (unsigned i = 0; i < 8; ++i)
    {
        os << "[" << i << "] " << rhs.m_Save_Names[i] << ",\n";
    }
    os << ")\n";
    os << "m_Movement_Animations=" << rhs.m_Movement_Animations << "\n";
    os << "m_Save_Wizard_Names=(\n";
    for (unsigned i = 0; i < 10; ++i)
    {
        os << "[" << i << "] " << rhs.m_Save_Wizard_Names[i] << ",\n";
    }
    os << ")\n";
    os << "m_Unk_1AA=(\n";
    for (unsigned i = 0; i < 20; ++i)
    {
        os << "[" << i << "] " << rhs.m_Unk_1AA[i] << " 0x" << std::hex << rhs.m_Unk_1AA[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Global_Enchantments& rhs)
{
    os << "{\n";
    os << "Eternal_Night=" << (unsigned)rhs.Eternal_Night << " 0x" << std::hex << (unsigned)rhs.Eternal_Night << std::dec << "\n";
    os << "Evil_Omens=" << (unsigned)rhs.Evil_Omens << " 0x" << std::hex << (unsigned)rhs.Evil_Omens << std::dec << "\n";
    os << "Zombie_Mastery=" << (unsigned)rhs.Zombie_Mastery << " 0x" << std::hex << (unsigned)rhs.Zombie_Mastery << std::dec << "\n";
    os << "Aura_of_Majesty=" << (unsigned)rhs.Aura_of_Majesty << " 0x" << std::hex << (unsigned)rhs.Aura_of_Majesty << std::dec << "\n";
    os << "Wind_Mastery=" << (unsigned)rhs.Wind_Mastery << " 0x" << std::hex << (unsigned)rhs.Wind_Mastery << std::dec << "\n";
    os << "Suppress_Magic=" << (unsigned)rhs.Suppress_Magic << " 0x" << std::hex << (unsigned)rhs.Suppress_Magic << std::dec << "\n";
    os << "Time_Stop=" << (unsigned)rhs.Time_Stop << " 0x" << std::hex << (unsigned)rhs.Time_Stop << std::dec << "\n";
    os << "Nature_Awareness=" << (unsigned)rhs.Nature_Awareness << " 0x" << std::hex << (unsigned)rhs.Nature_Awareness << std::dec << "\n";
    os << "Natures_Wrath=" << (unsigned)rhs.Natures_Wrath << " 0x" << std::hex << (unsigned)rhs.Natures_Wrath << std::dec << "\n";
    os << "Herb_Mastery=" << (unsigned)rhs.Herb_Mastery << " 0x" << std::hex << (unsigned)rhs.Herb_Mastery << std::dec << "\n";
    os << "Chaos_Surge=" << (unsigned)rhs.Chaos_Surge << " 0x" << std::hex << (unsigned)rhs.Chaos_Surge << std::dec << "\n";
    os << "Doom_Mastery=" << (unsigned)rhs.Doom_Mastery << " 0x" << std::hex << (unsigned)rhs.Doom_Mastery << std::dec << "\n";
    os << "Great_Wasting=" << (unsigned)rhs.Great_Wasting << " 0x" << std::hex << (unsigned)rhs.Great_Wasting << std::dec << "\n";
    os << "Meteor_Storm=" << (unsigned)rhs.Meteor_Storm << " 0x" << std::hex << (unsigned)rhs.Meteor_Storm << std::dec << "\n";
    os << "Armageddon=" << (unsigned)rhs.Armageddon << " 0x" << std::hex << (unsigned)rhs.Armageddon << std::dec << "\n";
    os << "Tranquility=" << (unsigned)rhs.Tranquility << " 0x" << std::hex << (unsigned)rhs.Tranquility << std::dec << "\n";
    os << "Life_Force=" << (unsigned)rhs.Life_Force << " 0x" << std::hex << (unsigned)rhs.Life_Force << std::dec << "\n";
    os << "Crusade=" << (unsigned)rhs.Crusade << " 0x" << std::hex << (unsigned)rhs.Crusade << std::dec << "\n";
    os << "Just_Cause=" << (unsigned)rhs.Just_Cause << " 0x" << std::hex << (unsigned)rhs.Just_Cause << std::dec << "\n";
    os << "Holy_Arms=" << (unsigned)rhs.Holy_Arms << " 0x" << std::hex << (unsigned)rhs.Holy_Arms << std::dec << "\n";
    os << "Planar_Seal=" << (unsigned)rhs.Planar_Seal << " 0x" << std::hex << (unsigned)rhs.Planar_Seal << std::dec << "\n";
    os << "Charm_of_Life=" << (unsigned)rhs.Charm_of_Life << " 0x" << std::hex << (unsigned)rhs.Charm_of_Life << std::dec << "\n";
    os << "Detect_Magic=" << (unsigned)rhs.Detect_Magic << " 0x" << std::hex << (unsigned)rhs.Detect_Magic << std::dec << "\n";
    os << "Awareness=" << (unsigned)rhs.Awareness << " 0x" << std::hex << (unsigned)rhs.Awareness << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const HelpLBXentry& rhs)
{
    os << "{\n";
    os << "title=" << formatCharArray(rhs.title, 30) << "\n";
    os << "lbxFile=" << formatCharArray(rhs.lbxFile, 14) << "\n";
    os << "lbxIndex=" << rhs.lbxIndex << " 0x" << std::hex << rhs.lbxIndex << std::dec << "\n";
    os << "zero_2E=" << rhs.zero_2E << " 0x" << std::hex << rhs.zero_2E << std::dec << "\n";
    os << "description=" << formatCharArray(rhs.description, 1000) << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Hero_Ability& rhs)
{
    os << "{\n";
    if (0 != rhs.Leadership)
    {
    os << "Leadership=" << (unsigned)rhs.Leadership << "\n";
    }
    if (0 != rhs.Leadership_X)
    {
    os << "Leadership_X=" << (unsigned)rhs.Leadership_X << "\n";
    }
    if (0 != rhs.u1)
    {
    os << "u1=" << (unsigned)rhs.u1 << "\n";
    }
    if (0 != rhs.Legendary)
    {
    os << "Legendary=" << (unsigned)rhs.Legendary << "\n";
    }
    if (0 != rhs.Legendary_X)
    {
    os << "Legendary_X=" << (unsigned)rhs.Legendary_X << "\n";
    }
    if (0 != rhs.u0)
    {
    os << "u0=" << (unsigned)rhs.u0 << "\n";
    }
    if (0 != rhs.Blademaster)
    {
    os << "Blademaster=" << (unsigned)rhs.Blademaster << "\n";
    }
    if (0 != rhs.Blademaster_X)
    {
    os << "Blademaster_X=" << (unsigned)rhs.Blademaster_X << "\n";
    }
    if (0 != rhs.u4)
    {
    os << "u4=" << (unsigned)rhs.u4 << "\n";
    }
    if (0 != rhs.Armsmaster)
    {
    os << "Armsmaster=" << (unsigned)rhs.Armsmaster << "\n";
    }
    if (0 != rhs.Armsmaster_X)
    {
    os << "Armsmaster_X=" << (unsigned)rhs.Armsmaster_X << "\n";
    }
    if (0 != rhs.u3)
    {
    os << "u3=" << (unsigned)rhs.u3 << "\n";
    }
    if (0 != rhs.Constitution)
    {
    os << "Constitution=" << (unsigned)rhs.Constitution << "\n";
    }
    if (0 != rhs.Constitution_X)
    {
    os << "Constitution_X=" << (unsigned)rhs.Constitution_X << "\n";
    }
    if (0 != rhs.u2)
    {
    os << "u2=" << (unsigned)rhs.u2 << "\n";
    }
    if (0 != rhs.Might)
    {
    os << "Might=" << (unsigned)rhs.Might << "\n";
    }
    if (0 != rhs.Might_X)
    {
    os << "Might_X=" << (unsigned)rhs.Might_X << "\n";
    }
    if (0 != rhs.u7)
    {
    os << "u7=" << (unsigned)rhs.u7 << "\n";
    }
    if (0 != rhs.Arcane_Power)
    {
    os << "Arcane_Power=" << (unsigned)rhs.Arcane_Power << "\n";
    }
    if (0 != rhs.Arcane_Power_X)
    {
    os << "Arcane_Power_X=" << (unsigned)rhs.Arcane_Power_X << "\n";
    }
    if (0 != rhs.u6)
    {
    os << "u6=" << (unsigned)rhs.u6 << "\n";
    }
    if (0 != rhs.Sage)
    {
    os << "Sage=" << (unsigned)rhs.Sage << "\n";
    }
    if (0 != rhs.Sage_X)
    {
    os << "Sage_X=" << (unsigned)rhs.Sage_X << "\n";
    }
    if (0 != rhs.u5)
    {
    os << "u5=" << (unsigned)rhs.u5 << "\n";
    }
    if (0 != rhs.Prayermaster)
    {
    os << "Prayermaster=" << (unsigned)rhs.Prayermaster << "\n";
    }
    if (0 != rhs.Prayermaster_X)
    {
    os << "Prayermaster_X=" << (unsigned)rhs.Prayermaster_X << "\n";
    }
    if (0 != rhs.Agility_X)
    {
    os << "Agility_X=" << (unsigned)rhs.Agility_X << "\n";
    }
    if (0 != rhs.Lucky)
    {
    os << "Lucky=" << (unsigned)rhs.Lucky << "\n";
    }
    if (0 != rhs.Charmed)
    {
    os << "Charmed=" << (unsigned)rhs.Charmed << "\n";
    }
    if (0 != rhs.Noble)
    {
    os << "Noble=" << (unsigned)rhs.Noble << "\n";
    }
    if (0 != rhs.u8)
    {
    os << "u8=" << (unsigned)rhs.u8 << "\n";
    }
    if (0 != rhs.Agility)
    {
    os << "Agility=" << (unsigned)rhs.Agility << "\n";
    }
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Hero_Choice& rhs)
{
    os << "{\n";
    os << "m_Name=" << formatCharArray(rhs.m_Name, 14) << "\n";
    os << "m_Experience=" << rhs.m_Experience << " 0x" << std::hex << rhs.m_Experience << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Hero_Stats_Initializer& rhs)
{
    os << "{\n";
    os << "m_Nr_Random_picks=" << rhs.m_Nr_Random_picks << " 0x" << std::hex << rhs.m_Nr_Random_picks << std::dec << "\n";
    os << "m_Random_pick_type=" << rhs.m_Random_pick_type << "\n";
    os << "m_Hero_Abilities=" << rhs.m_Hero_Abilities << "\n";
    os << "m_Hero_Casting_Skill=" << rhs.m_Hero_Casting_Skill << " 0x" << std::hex << rhs.m_Hero_Casting_Skill << std::dec << "\n";
    os << "m_Spell=(\n";
    for (unsigned i = 0; i < 4; ++i)
    {
        os << "[" << i << "] " << rhs.m_Spell[i] << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Hero_stats& rhs)
{
    os << "{\n";
    os << "m_Level_Status=" << rhs.m_Level_Status << "\n";
    os << "m_Hero_Abilities=" << rhs.m_Hero_Abilities << "\n";
    os << "m_Hero_Casting_Skill=" << (unsigned)rhs.m_Hero_Casting_Skill << " 0x" << std::hex << (unsigned)rhs.m_Hero_Casting_Skill << std::dec << "\n";
    os << "m_Spell=(\n";
    for (unsigned i = 0; i < 4; ++i)
    {
        os << "[" << i << "] " << rhs.m_Spell[i] << ",\n";
    }
    os << ")\n";
    os << "m_Garbage=" << (unsigned)rhs.m_Garbage << " 0x" << std::hex << (unsigned)rhs.m_Garbage << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Hired_Hero& rhs)
{
    os << "{\n";
    os << "m_Unit_Nr=" << rhs.m_Unit_Nr << " 0x" << std::hex << rhs.m_Unit_Nr << std::dec << "\n";
    os << "m_Hero_name=" << formatCharArray(rhs.m_Hero_name, 14) << "\n";
    os << "m_Items_In_Slot=(\n";
    for (unsigned i = 0; i < 3; ++i)
    {
        os << "[" << i << "] " << rhs.m_Items_In_Slot[i] << " 0x" << std::hex << rhs.m_Items_In_Slot[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Slot_Types=(\n";
    for (unsigned i = 0; i < 3; ++i)
    {
        os << "[" << i << "] " << rhs.m_Slot_Types[i] << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const HlpEntryLbx& rhs)
{
    os << "{\n";
    os << "lbxIndex=" << rhs.lbxIndex << " 0x" << std::hex << rhs.lbxIndex << std::dec << "\n";
    os << "left=" << rhs.left << " 0x" << std::hex << rhs.left << std::dec << "\n";
    os << "top=" << rhs.top << " 0x" << std::hex << rhs.top << std::dec << "\n";
    os << "right=" << rhs.right << " 0x" << std::hex << rhs.right << std::dec << "\n";
    os << "bottom=" << rhs.bottom << " 0x" << std::hex << rhs.bottom << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Immunity_Flags& rhs)
{
    os << "{\n";
    if (0 != rhs.Fire_Immunity)
    {
    os << "Fire_Immunity=" << (unsigned)rhs.Fire_Immunity << "\n";
    }
    if (0 != rhs.Stoning_Immunity)
    {
    os << "Stoning_Immunity=" << (unsigned)rhs.Stoning_Immunity << "\n";
    }
    if (0 != rhs.Missiles_Immunity)
    {
    os << "Missiles_Immunity=" << (unsigned)rhs.Missiles_Immunity << "\n";
    }
    if (0 != rhs.Illusions_Immunity)
    {
    os << "Illusions_Immunity=" << (unsigned)rhs.Illusions_Immunity << "\n";
    }
    if (0 != rhs.Cold_Immunity)
    {
    os << "Cold_Immunity=" << (unsigned)rhs.Cold_Immunity << "\n";
    }
    if (0 != rhs.Magic_Immunity)
    {
    os << "Magic_Immunity=" << (unsigned)rhs.Magic_Immunity << "\n";
    }
    if (0 != rhs.Death_Immunity)
    {
    os << "Death_Immunity=" << (unsigned)rhs.Death_Immunity << "\n";
    }
    if (0 != rhs.Poison_Immunity)
    {
    os << "Poison_Immunity=" << (unsigned)rhs.Poison_Immunity << "\n";
    }
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Item& rhs)
{
    os << "{\n";
    os << "m_Item_Name=" << formatCharArray(rhs.m_Item_Name, 30) << "\n";
    os << "m_Icon=" << rhs.m_Icon << "\n";
    os << "m_Slot_Required=" << rhs.m_Slot_Required << "\n";
    os << "m_Item_Type=" << rhs.m_Item_Type << "\n";
    os << "m_Cost=" << rhs.m_Cost << " 0x" << std::hex << rhs.m_Cost << std::dec << "\n";
    os << "m_Bonuses=" << rhs.m_Bonuses << "\n";
    os << "m_Spell_Number_Charged=" << rhs.m_Spell_Number_Charged << "\n";
    os << "m_Number_Of_Charges=" << rhs.m_Number_Of_Charges << " 0x" << std::hex << rhs.m_Number_Of_Charges << std::dec << "\n";
    os << "m_Bitmask_Powers=" << rhs.m_Bitmask_Powers << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const ItemDataLbx& rhs)
{
    os << "{\n";
    os << "m_Item=" << rhs.m_Item << "\n";
    os << "m_Index_in_spellbook_GUESS=(\n";
    for (unsigned i = 0; i < 5; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Index_in_spellbook_GUESS[i] << " 0x" << std::hex << (unsigned)rhs.m_Index_in_spellbook_GUESS[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Unk_37=" << (unsigned)rhs.m_Unk_37 << " 0x" << std::hex << (unsigned)rhs.m_Unk_37 << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const ItemPowLbx& rhs)
{
    os << "{\n";
    os << "m_Name=" << formatCharArray(rhs.m_Name, 18) << "\n";
    os << "m_EnchantibleItems=" << rhs.m_EnchantibleItems << " 0x" << std::hex << rhs.m_EnchantibleItems << std::dec << "\n";
    os << "m_Mana_cost_to_enchant=" << rhs.m_Mana_cost_to_enchant << " 0x" << std::hex << rhs.m_Mana_cost_to_enchant << std::dec << "\n";
    os << "m_PowerType=" << rhs.m_PowerType << "\n";
    os << "m_Color=" << rhs.m_Color << "\n";
    os << "m_Required_Nr_Spell_Books=" << rhs.m_Required_Nr_Spell_Books << " 0x" << std::hex << rhs.m_Required_Nr_Spell_Books << std::dec << "\n";
    os << "m_Bitmask_Powers=" << rhs.m_Bitmask_Powers << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Item_Bonuses& rhs)
{
    os << "{\n";
    os << "Attack=" << (int)rhs.Attack << " 0x" << std::hex << (int)rhs.Attack << std::dec << "\n";
    os << "To_Hit=" << (int)rhs.To_Hit << " 0x" << std::hex << (int)rhs.To_Hit << std::dec << "\n";
    os << "Defense=" << (int)rhs.Defense << " 0x" << std::hex << (int)rhs.Defense << std::dec << "\n";
    os << "Movement_in_halves=" << (int)rhs.Movement_in_halves << " 0x" << std::hex << (int)rhs.Movement_in_halves << std::dec << "\n";
    os << "Resistance=" << (int)rhs.Resistance << " 0x" << std::hex << (int)rhs.Resistance << std::dec << "\n";
    os << "Spell_Points=" << (int)rhs.Spell_Points << " 0x" << std::hex << (int)rhs.Spell_Points << std::dec << "\n";
    os << "Spell_Save=" << (int)rhs.Spell_Save << " 0x" << std::hex << (int)rhs.Spell_Save << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Item_Powers& rhs)
{
    os << "{\n";
    if (0 != rhs.Vampiric)
    {
    os << "Vampiric=" << (unsigned)rhs.Vampiric << "\n";
    }
    if (0 != rhs.Guardian_Wind)
    {
    os << "Guardian_Wind=" << (unsigned)rhs.Guardian_Wind << "\n";
    }
    if (0 != rhs.Lightning)
    {
    os << "Lightning=" << (unsigned)rhs.Lightning << "\n";
    }
    if (0 != rhs.Cloak_Of_Fear)
    {
    os << "Cloak_Of_Fear=" << (unsigned)rhs.Cloak_Of_Fear << "\n";
    }
    if (0 != rhs.Destruction)
    {
    os << "Destruction=" << (unsigned)rhs.Destruction << "\n";
    }
    if (0 != rhs.Wraith_Form)
    {
    os << "Wraith_Form=" << (unsigned)rhs.Wraith_Form << "\n";
    }
    if (0 != rhs.Regeneration)
    {
    os << "Regeneration=" << (unsigned)rhs.Regeneration << "\n";
    }
    if (0 != rhs.Pathfinding)
    {
    os << "Pathfinding=" << (unsigned)rhs.Pathfinding << "\n";
    }
    if (0 != rhs.Water_Walking)
    {
    os << "Water_Walking=" << (unsigned)rhs.Water_Walking << "\n";
    }
    if (0 != rhs.Resist_Elements)
    {
    os << "Resist_Elements=" << (unsigned)rhs.Resist_Elements << "\n";
    }
    if (0 != rhs.Elemental_Armour)
    {
    os << "Elemental_Armour=" << (unsigned)rhs.Elemental_Armour << "\n";
    }
    if (0 != rhs.Doom_equals_Chaos)
    {
    os << "Doom_equals_Chaos=" << (unsigned)rhs.Doom_equals_Chaos << "\n";
    }
    if (0 != rhs.Stoning)
    {
    os << "Stoning=" << (unsigned)rhs.Stoning << "\n";
    }
    if (0 != rhs.Endurance)
    {
    os << "Endurance=" << (unsigned)rhs.Endurance << "\n";
    }
    if (0 != rhs.Haste)
    {
    os << "Haste=" << (unsigned)rhs.Haste << "\n";
    }
    if (0 != rhs.Invisibility)
    {
    os << "Invisibility=" << (unsigned)rhs.Invisibility << "\n";
    }
    if (0 != rhs.Death)
    {
    os << "Death=" << (unsigned)rhs.Death << "\n";
    }
    if (0 != rhs.Flight)
    {
    os << "Flight=" << (unsigned)rhs.Flight << "\n";
    }
    if (0 != rhs.Resist_Magic)
    {
    os << "Resist_Magic=" << (unsigned)rhs.Resist_Magic << "\n";
    }
    if (0 != rhs.Magic_Immunity)
    {
    os << "Magic_Immunity=" << (unsigned)rhs.Magic_Immunity << "\n";
    }
    if (0 != rhs.Flaming)
    {
    os << "Flaming=" << (unsigned)rhs.Flaming << "\n";
    }
    if (0 != rhs.Holy_Avenger)
    {
    os << "Holy_Avenger=" << (unsigned)rhs.Holy_Avenger << "\n";
    }
    if (0 != rhs.True_Sight)
    {
    os << "True_Sight=" << (unsigned)rhs.True_Sight << "\n";
    }
    if (0 != rhs.Phantasmal)
    {
    os << "Phantasmal=" << (unsigned)rhs.Phantasmal << "\n";
    }
    if (0 != rhs.Power_Drain)
    {
    os << "Power_Drain=" << (unsigned)rhs.Power_Drain << "\n";
    }
    if (0 != rhs.Bless)
    {
    os << "Bless=" << (unsigned)rhs.Bless << "\n";
    }
    if (0 != rhs.Lion_Heart)
    {
    os << "Lion_Heart=" << (unsigned)rhs.Lion_Heart << "\n";
    }
    if (0 != rhs.Giant_Strength)
    {
    os << "Giant_Strength=" << (unsigned)rhs.Giant_Strength << "\n";
    }
    if (0 != rhs.Planar_Travel)
    {
    os << "Planar_Travel=" << (unsigned)rhs.Planar_Travel << "\n";
    }
    if (0 != rhs.Merging)
    {
    os << "Merging=" << (unsigned)rhs.Merging << "\n";
    }
    if (0 != rhs.Righteousness)
    {
    os << "Righteousness=" << (unsigned)rhs.Righteousness << "\n";
    }
    if (0 != rhs.Invulnerability)
    {
    os << "Invulnerability=" << (unsigned)rhs.Invulnerability << "\n";
    }
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const LBXHEADER& rhs)
{
    os << "{\n";
    os << "n=" << rhs.n << " 0x" << std::hex << rhs.n << std::dec << "\n";
    os << "magic_number=" << rhs.magic_number << " 0x" << std::hex << rhs.magic_number << std::dec << "\n";
    os << "reserved=" << rhs.reserved << " 0x" << std::hex << rhs.reserved << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Lair_Inhabitant& rhs)
{
    os << "{\n";
    os << "m_Inhabitant=" << rhs.m_Inhabitant << "\n";
    if (0 != rhs.m_Remaining_Nr_of_Inhabitant)
    {
    os << "m_Remaining_Nr_of_Inhabitant=" << (unsigned)rhs.m_Remaining_Nr_of_Inhabitant << "\n";
    }
    if (0 != rhs.m_Initial_Nr_of_Inhabitant)
    {
    os << "m_Initial_Nr_of_Inhabitant=" << (unsigned)rhs.m_Initial_Nr_of_Inhabitant << "\n";
    }
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const List_Hero_stats& rhs)
{
    os << "{\n";
    os << "Dwarf=" << rhs.Dwarf << "\n";
    os << "Barbarian=" << rhs.Barbarian << "\n";
    os << "Sage=" << rhs.Sage << "\n";
    os << "Dervish=" << rhs.Dervish << "\n";
    os << "Beastmaster=" << rhs.Beastmaster << "\n";
    os << "Bard=" << rhs.Bard << "\n";
    os << "Orc_Warrior=" << rhs.Orc_Warrior << "\n";
    os << "Healer=" << rhs.Healer << "\n";
    os << "Huntress=" << rhs.Huntress << "\n";
    os << "Thief=" << rhs.Thief << "\n";
    os << "Druid=" << rhs.Druid << "\n";
    os << "War_Monk=" << rhs.War_Monk << "\n";
    os << "Warrior_Mage=" << rhs.Warrior_Mage << "\n";
    os << "Magician=" << rhs.Magician << "\n";
    os << "Assassin=" << rhs.Assassin << "\n";
    os << "Wind_Mage=" << rhs.Wind_Mage << "\n";
    os << "Ranger=" << rhs.Ranger << "\n";
    os << "Draconian=" << rhs.Draconian << "\n";
    os << "Witch=" << rhs.Witch << "\n";
    os << "Golden_One=" << rhs.Golden_One << "\n";
    os << "Ninja=" << rhs.Ninja << "\n";
    os << "Rogue=" << rhs.Rogue << "\n";
    os << "Amazon=" << rhs.Amazon << "\n";
    os << "Warlock=" << rhs.Warlock << "\n";
    os << "Unknown=" << rhs.Unknown << "\n";
    os << "Illusionist=" << rhs.Illusionist << "\n";
    os << "Swordsman=" << rhs.Swordsman << "\n";
    os << "Priestess=" << rhs.Priestess << "\n";
    os << "Paladin=" << rhs.Paladin << "\n";
    os << "Black_Knight=" << rhs.Black_Knight << "\n";
    os << "Elven_Archer=" << rhs.Elven_Archer << "\n";
    os << "Knight=" << rhs.Knight << "\n";
    os << "Necromancer=" << rhs.Necromancer << "\n";
    os << "Chaos_Warrior=" << rhs.Chaos_Warrior << "\n";
    os << "Chosen=" << rhs.Chosen << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const MapRow_Bonus& rhs)
{
    os << "{\n";
    os << "m_Bonus_Deposit=(\n";
    for (unsigned i = 0; i < 60; ++i)
    {
        os << "[" << i << "] " << rhs.m_Bonus_Deposit[i] << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const MapRow_Exploration& rhs)
{
    os << "{\n";
    os << "m_Explored=(\n";
    for (unsigned i = 0; i < 60; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Explored[i] << " 0x" << std::hex << (unsigned)rhs.m_Explored[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const MapRow_LandMassID& rhs)
{
    os << "{\n";
    os << "m_LandMassID=(\n";
    for (unsigned i = 0; i < 60; ++i)
    {
        os << "[" << i << "] " << (int)rhs.m_LandMassID[i] << " 0x" << std::hex << (int)rhs.m_LandMassID[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const MapRow_Movement& rhs)
{
    os << "{\n";
    os << "m_Moves=(\n";
    for (unsigned i = 0; i < 60; ++i)
    {
        os << "[" << i << "] " << (int)rhs.m_Moves[i] << " 0x" << std::hex << (int)rhs.m_Moves[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const MapRow_Terrain& rhs)
{
    os << "{\n";
    os << "m_Tile=(\n";
    for (unsigned i = 0; i < 60; ++i)
    {
        os << "[" << i << "] " << rhs.m_Tile[i] << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const MapRow_Terrain_Changes& rhs)
{
    os << "{\n";
    os << "m_Terrain_Changes=(\n";
    for (unsigned i = 0; i < 60; ++i)
    {
        os << "[" << i << "] " << rhs.m_Terrain_Changes[i] << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Map_Movement& rhs)
{
    os << "{\n";
    os << "m_Unused_Row=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << rhs.m_Unused_Row[i] << ",\n";
    }
    os << ")\n";
    os << "m_Walking_Row=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << rhs.m_Walking_Row[i] << ",\n";
    }
    os << ")\n";
    os << "m_Forester_Row=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << rhs.m_Forester_Row[i] << ",\n";
    }
    os << ")\n";
    os << "m_Mountaineer_Row=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << rhs.m_Mountaineer_Row[i] << ",\n";
    }
    os << ")\n";
    os << "m_Swimming_Row=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << rhs.m_Swimming_Row[i] << ",\n";
    }
    os << ")\n";
    os << "m_Sailing_Row=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << rhs.m_Sailing_Row[i] << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const MoMDataSegment& rhs)
{
    os << "{\n";
    os << "m_DataSegmentStart=" << formatCharArray(rhs.m_DataSegmentStart, 0x0130) << "\n";
    os << "m_Offsets_SkillNames=(\n";
    for (unsigned i = 0; i < eSkill_MAX; ++i)
    {
        os << "[" << i << "] " << rhs.m_Offsets_SkillNames[i] << " 0x" << std::hex << rhs.m_Offsets_SkillNames[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Unk_0154=" << rhs.m_Unk_0154 << " 0x" << std::hex << rhs.m_Unk_0154 << std::dec << "\n";
    os << "m_Offsets_CitySizeNames=(\n";
    for (unsigned i = 0; i < eCity_Size_MAX; ++i)
    {
        os << "[" << i << "] " << rhs.m_Offsets_CitySizeNames[i] << " 0x" << std::hex << rhs.m_Offsets_CitySizeNames[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Offsets_CitySpecialNames=(\n";
    for (unsigned i = 0; i < 7; ++i)
    {
        os << "[" << i << "] " << rhs.m_Offsets_CitySpecialNames[i] << " 0x" << std::hex << rhs.m_Offsets_CitySpecialNames[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Unk_0170=(\n";
    for (unsigned i = 0; i < 22; ++i)
    {
        os << "[" << i << "] " << rhs.m_Unk_0170[i] << " 0x" << std::hex << rhs.m_Unk_0170[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Hero_Types=" << rhs.m_Hero_Types << "\n";
    os << "m_Normal_Units=(\n";
    for (unsigned i = 0; i < 4 + 115; ++i)
    {
        os << "[" << i << "] " << rhs.m_Normal_Units[i] << ",\n";
    }
    os << ")\n";
    os << "m_Summoned_Units=(\n";
    for (unsigned i = 0; i < 44; ++i)
    {
        os << "[" << i << "] " << rhs.m_Summoned_Units[i] << ",\n";
    }
    os << ")\n";
    os << "m_XP_Level_Table=(\n";
    for (unsigned i = 0; i < 9; ++i)
    {
        os << "[" << i << "] " << rhs.m_XP_Level_Table[i] << " 0x" << std::hex << rhs.m_XP_Level_Table[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Race_Data=(\n";
    for (unsigned i = 0; i < 14; ++i)
    {
        os << "[" << i << "] " << rhs.m_Race_Data[i] << ",\n";
    }
    os << ")\n";
    os << "m_Unk_1ED6=" << rhs.m_Unk_1ED6 << " 0x" << std::hex << rhs.m_Unk_1ED6 << std::dec << "\n";
    os << "m_Offset_Arcane=" << rhs.m_Offset_Arcane << " 0x" << std::hex << rhs.m_Offset_Arcane << std::dec << "\n";
    os << "m_Offsets_RealmNames_5=(\n";
    for (unsigned i = 0; i < 5; ++i)
    {
        os << "[" << i << "] " << rhs.m_Offsets_RealmNames_5[i] << " 0x" << std::hex << rhs.m_Offsets_RealmNames_5[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Offsets_CityEnchantmentNames=(\n";
    for (unsigned i = 0; i < eCityEnchantments_MAX; ++i)
    {
        os << "[" << i << "] " << rhs.m_Offsets_CityEnchantmentNames[i] << " 0x" << std::hex << rhs.m_Offsets_CityEnchantmentNames[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Upkeep_Enchantments=" << rhs.m_Upkeep_Enchantments << "\n";
    os << "m_Offsets_PersonalityNames=(\n";
    for (unsigned i = 0; i < ePersonality_MAX; ++i)
    {
        os << "[" << i << "] " << rhs.m_Offsets_PersonalityNames[i] << " 0x" << std::hex << rhs.m_Offsets_PersonalityNames[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Values_Personalities_GUESS=(\n";
    for (unsigned i = 0; i < ePersonality_MAX; ++i)
    {
        os << "[" << i << "] " << rhs.m_Values_Personalities_GUESS[i] << " 0x" << std::hex << rhs.m_Values_Personalities_GUESS[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Offsets_ObjectiveNames=(\n";
    for (unsigned i = 0; i < eObjective_MAX; ++i)
    {
        os << "[" << i << "] " << rhs.m_Offsets_ObjectiveNames[i] << " 0x" << std::hex << rhs.m_Offsets_ObjectiveNames[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Unk_1FDE=" << rhs.m_Unk_1FDE << " 0x" << std::hex << rhs.m_Unk_1FDE << std::dec << "\n";
    os << "m_Values_Objectives_GUESS=(\n";
    for (unsigned i = 0; i < eObjective_MAX; ++i)
    {
        os << "[" << i << "] " << rhs.m_Values_Objectives_GUESS[i] << " 0x" << std::hex << rhs.m_Values_Objectives_GUESS[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_DifficultyTable=(\n";
    for (unsigned i = 0; i < eDifficulty_MAX; ++i)
    {
        os << "[" << i << "] " << rhs.m_DifficultyTable[i] << ",\n";
    }
    os << ")\n";
    os << "m_Unk_203A=(\n";
    for (unsigned i = 0; i < 72; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_203A[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_203A[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_NameBuffer_2082=" << formatCharArray(rhs.m_NameBuffer_2082, 0x3A50 - 0x2082) << "\n";
    os << "m_UnitView_HeroAbility_data=(\n";
    for (unsigned i = 0; i < 23; ++i)
    {
        os << "[" << i << "] " << rhs.m_UnitView_HeroAbility_data[i] << ",\n";
    }
    os << ")\n";
    os << "m_UnitView_UnitAbility_data=(\n";
    for (unsigned i = 0; i < 17; ++i)
    {
        os << "[" << i << "] " << rhs.m_UnitView_UnitAbility_data[i] << ",\n";
    }
    os << ")\n";
    os << "m_UnitView_UnitImmunity_data=(\n";
    for (unsigned i = 0; i < 8; ++i)
    {
        os << "[" << i << "] " << rhs.m_UnitView_UnitImmunity_data[i] << ",\n";
    }
    os << ")\n";
    os << "m_UnitView_UnitSpell_data=(\n";
    for (unsigned i = 0; i < 8; ++i)
    {
        os << "[" << i << "] " << rhs.m_UnitView_UnitSpell_data[i] << ",\n";
    }
    os << ")\n";
    os << "m_UnitView_UnitAttack_data=(\n";
    for (unsigned i = 0; i < 11; ++i)
    {
        os << "[" << i << "] " << rhs.m_UnitView_UnitAttack_data[i] << ",\n";
    }
    os << ")\n";
    os << "m_UnitMutation_data=(\n";
    for (unsigned i = 0; i < 3; ++i)
    {
        os << "[" << i << "] " << rhs.m_UnitMutation_data[i] << ",\n";
    }
    os << ")\n";
    os << "m_UnitRanged_data=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << rhs.m_UnitRanged_data[i] << ",\n";
    }
    os << ")\n";
    os << "m_UnitEnchantment_data=(\n";
    for (unsigned i = 0; i < 32; ++i)
    {
        os << "[" << i << "] " << rhs.m_UnitEnchantment_data[i] << ",\n";
    }
    os << ")\n";
    os << "m_CombatEnchantment_data=(\n";
    for (unsigned i = 0; i < 15; ++i)
    {
        os << "[" << i << "] " << rhs.m_CombatEnchantment_data[i] << ",\n";
    }
    os << ")\n";
    os << "m_ItemPower_data=(\n";
    for (unsigned i = 0; i < 21; ++i)
    {
        os << "[" << i << "] " << rhs.m_ItemPower_data[i] << ",\n";
    }
    os << ")\n";
    os << "m_Offsets_UnitLevelNames=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << rhs.m_Offsets_UnitLevelNames[i] << " 0x" << std::hex << rhs.m_Offsets_UnitLevelNames[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Offsets_HeroLevelNames=(\n";
    for (unsigned i = 0; i < 9; ++i)
    {
        os << "[" << i << "] " << rhs.m_Offsets_HeroLevelNames[i] << " 0x" << std::hex << rhs.m_Offsets_HeroLevelNames[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_ItemPower_text=(\n";
    for (unsigned i = 0; i < 32; ++i)
    {
        os << "[" << i << "] " << rhs.m_ItemPower_text[i] << ",\n";
    }
    os << ")\n";
    os << "m_NameBuffer_4064=" << formatCharArray(rhs.m_NameBuffer_4064, 0x5bd8 - 0x4064) << "\n";
    os << "m_BaseItemPowerCosts=(\n";
    for (unsigned i = 0; i < eItemPowerType_MAX; ++i)
    {
        os << "[" << i << "] " << rhs.m_BaseItemPowerCosts[i] << " 0x" << std::hex << rhs.m_BaseItemPowerCosts[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_NameBuffer_5BEC=" << formatCharArray(rhs.m_NameBuffer_5BEC, 0x5E92 - 0x5BEC) << "\n";
    os << "m_Next_Turn_seed_storage_lo=" << rhs.m_Next_Turn_seed_storage_lo << " 0x" << std::hex << rhs.m_Next_Turn_seed_storage_lo << std::dec << "\n";
    os << "m_Next_Turn_seed_storage_hi=" << rhs.m_Next_Turn_seed_storage_hi << " 0x" << std::hex << rhs.m_Next_Turn_seed_storage_hi << std::dec << "\n";
    os << "m_Unk_5E96=(\n";
    for (unsigned i = 0; i < 0x6E9E - 0x5E96; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_5E96[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_5E96[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Tax_Unrest_Table=(\n";
    for (unsigned i = 0; i < eTax_Rate_MAX; ++i)
    {
        os << "[" << i << "] " << rhs.m_Tax_Unrest_Table[i] << " 0x" << std::hex << rhs.m_Tax_Unrest_Table[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Unk_6EAC=(\n";
    for (unsigned i = 0; i < 0x7151 - 0x6EAC; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_6EAC[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_6EAC[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Copyright_and_Version=" << formatCharArray(rhs.m_Copyright_and_Version, 41) << "\n";
    os << "m_Unk_717A=(\n";
    for (unsigned i = 0; i < 0x71E0 - 0x717A; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_717A[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_717A[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_BIOS_clock_snapshot=" << rhs.m_BIOS_clock_snapshot << " 0x" << std::hex << rhs.m_BIOS_clock_snapshot << std::dec << "\n";
    os << "m_Unk_71E4=(\n";
    for (unsigned i = 0; i < 0x760C - 0x71E4; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_71E4[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_71E4[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_EMS_data_reference_point=" << rhs.m_EMS_data_reference_point << " 0x" << std::hex << rhs.m_EMS_data_reference_point << std::dec << "\n";
    os << "m_Unk_760E=(\n";
    for (unsigned i = 0; i < 0x7846 - 0x760E; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_760E[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_760E[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_RNG_seed_lo=" << rhs.m_RNG_seed_lo << " 0x" << std::hex << rhs.m_RNG_seed_lo << std::dec << "\n";
    os << "m_RNG_seed_hi=" << rhs.m_RNG_seed_hi << " 0x" << std::hex << rhs.m_RNG_seed_hi << std::dec << "\n";
    os << "m_Unk_784A=(\n";
    for (unsigned i = 0; i < 0x7876 - 0x784A; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_784A[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_784A[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_DEBUG_Off=" << rhs.m_DEBUG_Off << " 0x" << std::hex << rhs.m_DEBUG_Off << std::dec << "\n";
    os << "m_Unk_7878=(\n";
    for (unsigned i = 0; i < 0x912C - 0x7878; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_7878[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_7878[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_addr_Spell_Data=" << rhs.m_addr_Spell_Data << "\n";
    os << "word_3FBD0=" << rhs.word_3FBD0 << " 0x" << std::hex << rhs.word_3FBD0 << std::dec << "\n";
    os << "w_sound_x=" << rhs.w_sound_x << " 0x" << std::hex << rhs.w_sound_x << std::dec << "\n";
    os << "word_3FBD4=" << rhs.word_3FBD4 << " 0x" << std::hex << rhs.word_3FBD4 << std::dec << "\n";
    os << "m_addr_Items=" << rhs.m_addr_Items << "\n";
    os << "m_addr_Artifacts_in_Game=" << rhs.m_addr_Artifacts_in_Game << "\n";
    os << "m_item_pics_116=(\n";
    for (unsigned i = 0; i < 116; ++i)
    {
        os << "[" << i << "] " << rhs.m_item_pics_116[i] << " 0x" << std::hex << rhs.m_item_pics_116[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_addr_Battle_Unit_View=" << rhs.m_addr_Battle_Unit_View << "\n";
    os << "m_addr_Battle_Unit=" << rhs.m_addr_Battle_Unit << "\n";
    os << "m_addr_Spells_Cast_in_Battle=" << rhs.m_addr_Spells_Cast_in_Battle << "\n";
    os << "m_addr_Hero_stat=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << rhs.m_addr_Hero_stat[i] << ",\n";
    }
    os << ")\n";
    os << "w_AI_flees=(\n";
    for (unsigned i = 0; i < 20; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.w_AI_flees[i] << " 0x" << std::hex << (unsigned)rhs.w_AI_flees[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_3FCFE=(\n";
    for (unsigned i = 0; i < 10; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_3FCFE[i] << " 0x" << std::hex << (unsigned)rhs.word_3FCFE[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_3FD08=" << rhs.word_3FD08 << " 0x" << std::hex << rhs.word_3FD08 << std::dec << "\n";
    os << "word_3FD0A=" << rhs.word_3FD0A << " 0x" << std::hex << rhs.word_3FD0A << std::dec << "\n";
    os << "word_3FD0C=" << rhs.word_3FD0C << " 0x" << std::hex << rhs.word_3FD0C << std::dec << "\n";
    os << "word_3FD0E=" << rhs.word_3FD0E << " 0x" << std::hex << rhs.word_3FD0E << std::dec << "\n";
    os << "word_3FD10=" << rhs.word_3FD10 << " 0x" << std::hex << rhs.word_3FD10 << std::dec << "\n";
    os << "word_3FD12=" << rhs.word_3FD12 << " 0x" << std::hex << rhs.word_3FD12 << std::dec << "\n";
    os << "m_addr_Battlefield=" << rhs.m_addr_Battlefield << "\n";
    os << "word_3FD18=" << rhs.word_3FD18 << " 0x" << std::hex << rhs.word_3FD18 << std::dec << "\n";
    os << "word_3FD1A=" << rhs.word_3FD1A << " 0x" << std::hex << rhs.word_3FD1A << std::dec << "\n";
    os << "w_AI_on_the_move_GUESS=" << rhs.w_AI_on_the_move_GUESS << " 0x" << std::hex << rhs.w_AI_on_the_move_GUESS << std::dec << "\n";
    os << "w_coo_X_Y_clicked=" << rhs.w_coo_X_Y_clicked << " 0x" << std::hex << rhs.w_coo_X_Y_clicked << std::dec << "\n";
    os << "w_coo_Y_X_clicked=" << rhs.w_coo_Y_X_clicked << " 0x" << std::hex << rhs.w_coo_Y_X_clicked << std::dec << "\n";
    os << "word_3FD22=" << rhs.word_3FD22 << " 0x" << std::hex << rhs.word_3FD22 << std::dec << "\n";
    os << "m_clash_place_type=" << rhs.m_clash_place_type << " 0x" << std::hex << rhs.m_clash_place_type << std::dec << "\n";
    os << "m_clash_cityNr_or_lairNr=" << rhs.m_clash_cityNr_or_lairNr << " 0x" << std::hex << rhs.m_clash_cityNr_or_lairNr << std::dec << "\n";
    os << "word_3FD28=(\n";
    for (unsigned i = 0; i < 12; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_3FD28[i] << " 0x" << std::hex << (unsigned)rhs.word_3FD28[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_kyrub_dseg_9294=" << rhs.m_kyrub_dseg_9294 << " 0x" << std::hex << rhs.m_kyrub_dseg_9294 << std::dec << "\n";
    os << "m_kyrub_dseg_9296=" << rhs.m_kyrub_dseg_9296 << " 0x" << std::hex << rhs.m_kyrub_dseg_9296 << std::dec << "\n";
    os << "word_3FD38=(\n";
    for (unsigned i = 0; i < 20; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_3FD38[i] << " 0x" << std::hex << (unsigned)rhs.word_3FD38[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "w_negat_encha_x17_flag_def=" << rhs.w_negat_encha_x17_flag_def << " 0x" << std::hex << rhs.w_negat_encha_x17_flag_def << std::dec << "\n";
    os << "w_aggre_spell_color_flag_att=" << rhs.w_aggre_spell_color_flag_att << " 0x" << std::hex << rhs.w_aggre_spell_color_flag_att << std::dec << "\n";
    os << "dword_3FD50=" << rhs.dword_3FD50 << "\n";
    os << "word_3FD54=" << rhs.word_3FD54 << " 0x" << std::hex << rhs.word_3FD54 << std::dec << "\n";
    os << "word_3FD56=(\n";
    for (unsigned i = 0; i < 64; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_3FD56[i] << " 0x" << std::hex << (unsigned)rhs.word_3FD56[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_3FD96=(\n";
    for (unsigned i = 0; i < 8; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_3FD96[i] << " 0x" << std::hex << (unsigned)rhs.word_3FD96[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_3FD9E=" << rhs.word_3FD9E << " 0x" << std::hex << rhs.word_3FD9E << std::dec << "\n";
    os << "word_3FDA0=" << rhs.word_3FDA0 << " 0x" << std::hex << rhs.word_3FDA0 << std::dec << "\n";
    os << "word_3FDA2=" << rhs.word_3FDA2 << " 0x" << std::hex << rhs.word_3FDA2 << std::dec << "\n";
    os << "word_3FDA4=" << rhs.word_3FDA4 << " 0x" << std::hex << rhs.word_3FDA4 << std::dec << "\n";
    os << "word_3FDA6=" << rhs.word_3FDA6 << " 0x" << std::hex << rhs.word_3FDA6 << std::dec << "\n";
    os << "word_3FDA8=" << rhs.word_3FDA8 << " 0x" << std::hex << rhs.word_3FDA8 << std::dec << "\n";
    os << "word_3FDAA=" << rhs.word_3FDAA << " 0x" << std::hex << rhs.word_3FDAA << std::dec << "\n";
    os << "word_3FDAC=" << rhs.word_3FDAC << " 0x" << std::hex << rhs.word_3FDAC << std::dec << "\n";
    os << "word_3FDAE=" << rhs.word_3FDAE << " 0x" << std::hex << rhs.word_3FDAE << std::dec << "\n";
    os << "word_3FDB0=" << rhs.word_3FDB0 << " 0x" << std::hex << rhs.word_3FDB0 << std::dec << "\n";
    os << "word_3FDB2=" << rhs.word_3FDB2 << " 0x" << std::hex << rhs.word_3FDB2 << std::dec << "\n";
    os << "word_3FDB4=" << rhs.word_3FDB4 << " 0x" << std::hex << rhs.word_3FDB4 << std::dec << "\n";
    os << "word_3FDB6=" << rhs.word_3FDB6 << " 0x" << std::hex << rhs.word_3FDB6 << std::dec << "\n";
    os << "word_3FDB8=(\n";
    for (unsigned i = 0; i < 44; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_3FDB8[i] << " 0x" << std::hex << (unsigned)rhs.word_3FDB8[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_3FDE4=" << rhs.word_3FDE4 << " 0x" << std::hex << rhs.word_3FDE4 << std::dec << "\n";
    os << "addr_3FDE6=" << rhs.addr_3FDE6 << "\n";
    os << "word_3FDEA=" << rhs.word_3FDEA << " 0x" << std::hex << rhs.word_3FDEA << std::dec << "\n";
    os << "word_3FDEC=" << rhs.word_3FDEC << " 0x" << std::hex << rhs.word_3FDEC << std::dec << "\n";
    os << "word_3FDEE=" << rhs.word_3FDEE << " 0x" << std::hex << rhs.word_3FDEE << std::dec << "\n";
    os << "word_3FDF0=" << rhs.word_3FDF0 << " 0x" << std::hex << rhs.word_3FDF0 << std::dec << "\n";
    os << "word_3FDF2=" << rhs.word_3FDF2 << " 0x" << std::hex << rhs.word_3FDF2 << std::dec << "\n";
    os << "word_3FDF4=" << rhs.word_3FDF4 << " 0x" << std::hex << rhs.word_3FDF4 << std::dec << "\n";
    os << "word_3FDF6=" << rhs.word_3FDF6 << " 0x" << std::hex << rhs.word_3FDF6 << std::dec << "\n";
    os << "word_3FDF8=" << rhs.word_3FDF8 << " 0x" << std::hex << rhs.word_3FDF8 << std::dec << "\n";
    os << "word_3FDFA=" << rhs.word_3FDFA << " 0x" << std::hex << rhs.word_3FDFA << std::dec << "\n";
    os << "word_3FDFC=" << rhs.word_3FDFC << " 0x" << std::hex << rhs.word_3FDFC << std::dec << "\n";
    os << "word_3FDFE=" << rhs.word_3FDFE << " 0x" << std::hex << rhs.word_3FDFE << std::dec << "\n";
    os << "word_3FE00=" << rhs.word_3FE00 << " 0x" << std::hex << rhs.word_3FE00 << std::dec << "\n";
    os << "word_3FE02=" << rhs.word_3FE02 << " 0x" << std::hex << rhs.word_3FE02 << std::dec << "\n";
    os << "word_3FE04=" << rhs.word_3FE04 << " 0x" << std::hex << rhs.word_3FE04 << std::dec << "\n";
    os << "word_3FE06=" << rhs.word_3FE06 << " 0x" << std::hex << rhs.word_3FE06 << std::dec << "\n";
    os << "word_3FE08=" << rhs.word_3FE08 << " 0x" << std::hex << rhs.word_3FE08 << std::dec << "\n";
    os << "word_3FE0A=" << rhs.word_3FE0A << " 0x" << std::hex << rhs.word_3FE0A << std::dec << "\n";
    os << "word_3FE0C=" << rhs.word_3FE0C << " 0x" << std::hex << rhs.word_3FE0C << std::dec << "\n";
    os << "word_3FE0E=" << rhs.word_3FE0E << " 0x" << std::hex << rhs.word_3FE0E << std::dec << "\n";
    os << "word_3FE10=" << rhs.word_3FE10 << " 0x" << std::hex << rhs.word_3FE10 << std::dec << "\n";
    os << "word_3FE12=" << rhs.word_3FE12 << " 0x" << std::hex << rhs.word_3FE12 << std::dec << "\n";
    os << "word_3FE14=" << rhs.word_3FE14 << " 0x" << std::hex << rhs.word_3FE14 << std::dec << "\n";
    os << "word_3FE16=" << rhs.word_3FE16 << " 0x" << std::hex << rhs.word_3FE16 << std::dec << "\n";
    os << "word_3FE18=" << rhs.word_3FE18 << " 0x" << std::hex << rhs.word_3FE18 << std::dec << "\n";
    os << "word_3FE1A=" << rhs.word_3FE1A << " 0x" << std::hex << rhs.word_3FE1A << std::dec << "\n";
    os << "word_3FE1C=" << rhs.word_3FE1C << " 0x" << std::hex << rhs.word_3FE1C << std::dec << "\n";
    os << "word_3FE1E=" << rhs.word_3FE1E << " 0x" << std::hex << rhs.word_3FE1E << std::dec << "\n";
    os << "word_3FE20=" << rhs.word_3FE20 << " 0x" << std::hex << rhs.word_3FE20 << std::dec << "\n";
    os << "word_3FE22=" << rhs.word_3FE22 << " 0x" << std::hex << rhs.word_3FE22 << std::dec << "\n";
    os << "word_3FE24=" << rhs.word_3FE24 << " 0x" << std::hex << rhs.word_3FE24 << std::dec << "\n";
    os << "word_3FE26=" << rhs.word_3FE26 << " 0x" << std::hex << rhs.word_3FE26 << std::dec << "\n";
    os << "word_3FE28=" << rhs.word_3FE28 << " 0x" << std::hex << rhs.word_3FE28 << std::dec << "\n";
    os << "word_3FE2A=" << rhs.word_3FE2A << " 0x" << std::hex << rhs.word_3FE2A << std::dec << "\n";
    os << "m_addr_Building_Data=" << rhs.m_addr_Building_Data << "\n";
    os << "word_3FE30=" << rhs.word_3FE30 << " 0x" << std::hex << rhs.word_3FE30 << std::dec << "\n";
    os << "dword_3FE32=" << rhs.dword_3FE32 << "\n";
    os << "dword_3FE36=(\n";
    for (unsigned i = 0; i < 126; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.dword_3FE36[i] << " 0x" << std::hex << (unsigned)rhs.dword_3FE36[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_3FEB4=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_3FEB4[i] << " 0x" << std::hex << (unsigned)rhs.word_3FEB4[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_3FEBA=(\n";
    for (unsigned i = 0; i < 18; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_3FEBA[i] << " 0x" << std::hex << (unsigned)rhs.word_3FEBA[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_3FECC=(\n";
    for (unsigned i = 0; i < 22; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_3FECC[i] << " 0x" << std::hex << (unsigned)rhs.word_3FECC[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_3FEE2=" << rhs.word_3FEE2 << " 0x" << std::hex << rhs.word_3FEE2 << std::dec << "\n";
    os << "w_all_units_moved_GUESS=" << rhs.w_all_units_moved_GUESS << " 0x" << std::hex << rhs.w_all_units_moved_GUESS << std::dec << "\n";
    os << "word_3FEE6=" << rhs.word_3FEE6 << " 0x" << std::hex << rhs.word_3FEE6 << std::dec << "\n";
    os << "word_3FEE8=" << rhs.word_3FEE8 << " 0x" << std::hex << rhs.word_3FEE8 << std::dec << "\n";
    os << "word_3FEEA=" << rhs.word_3FEEA << " 0x" << std::hex << rhs.word_3FEEA << std::dec << "\n";
    os << "word_3FEEC=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_3FEEC[i] << " 0x" << std::hex << (unsigned)rhs.word_3FEEC[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_3FEF2=(\n";
    for (unsigned i = 0; i < 14; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_3FEF2[i] << " 0x" << std::hex << (unsigned)rhs.word_3FEF2[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_3FF00=" << rhs.word_3FF00 << "\n";
    os << "word_3FF04=" << rhs.word_3FF04 << " 0x" << std::hex << rhs.word_3FF04 << std::dec << "\n";
    os << "word_3FF06=" << rhs.word_3FF06 << " 0x" << std::hex << rhs.word_3FF06 << std::dec << "\n";
    os << "word_3FF08=" << rhs.word_3FF08 << " 0x" << std::hex << rhs.word_3FF08 << std::dec << "\n";
    os << "word_3FF0A=" << rhs.word_3FF0A << " 0x" << std::hex << rhs.word_3FF0A << std::dec << "\n";
    os << "word_3FF0C=" << rhs.word_3FF0C << " 0x" << std::hex << rhs.word_3FF0C << std::dec << "\n";
    os << "word_3FF0E=" << rhs.word_3FF0E << " 0x" << std::hex << rhs.word_3FF0E << std::dec << "\n";
    os << "word_3FF10=(\n";
    for (unsigned i = 0; i < 14; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_3FF10[i] << " 0x" << std::hex << (unsigned)rhs.word_3FF10[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_3FF1E=" << rhs.word_3FF1E << " 0x" << std::hex << rhs.word_3FF1E << std::dec << "\n";
    os << "word_3FF20=" << rhs.word_3FF20 << " 0x" << std::hex << rhs.word_3FF20 << std::dec << "\n";
    os << "word_3FF22=" << rhs.word_3FF22 << " 0x" << std::hex << rhs.word_3FF22 << std::dec << "\n";
    os << "word_3FF24=" << rhs.word_3FF24 << " 0x" << std::hex << rhs.word_3FF24 << std::dec << "\n";
    os << "word_3FF26=" << rhs.word_3FF26 << " 0x" << std::hex << rhs.word_3FF26 << std::dec << "\n";
    os << "word_3FF28=" << rhs.word_3FF28 << " 0x" << std::hex << rhs.word_3FF28 << std::dec << "\n";
    os << "word_3FF2A=" << rhs.word_3FF2A << " 0x" << std::hex << rhs.word_3FF2A << std::dec << "\n";
    os << "word_3FF2C=" << rhs.word_3FF2C << " 0x" << std::hex << rhs.word_3FF2C << std::dec << "\n";
    os << "word_3FF2E=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_3FF2E[i] << " 0x" << std::hex << (unsigned)rhs.word_3FF2E[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_3FF34=" << rhs.word_3FF34 << " 0x" << std::hex << rhs.word_3FF34 << std::dec << "\n";
    os << "word_3FF36=" << rhs.word_3FF36 << " 0x" << std::hex << rhs.word_3FF36 << std::dec << "\n";
    os << "word_3FF38=" << rhs.word_3FF38 << " 0x" << std::hex << rhs.word_3FF38 << std::dec << "\n";
    os << "word_3FF3A=" << rhs.word_3FF3A << " 0x" << std::hex << rhs.word_3FF3A << std::dec << "\n";
    os << "word_3FF3C=" << rhs.word_3FF3C << " 0x" << std::hex << rhs.word_3FF3C << std::dec << "\n";
    os << "word_3FF3E=" << rhs.word_3FF3E << " 0x" << std::hex << rhs.word_3FF3E << std::dec << "\n";
    os << "word_3FF40=" << rhs.word_3FF40 << " 0x" << std::hex << rhs.word_3FF40 << std::dec << "\n";
    os << "word_3FF42=" << rhs.word_3FF42 << " 0x" << std::hex << rhs.word_3FF42 << std::dec << "\n";
    os << "word_3FF44=" << rhs.word_3FF44 << " 0x" << std::hex << rhs.word_3FF44 << std::dec << "\n";
    os << "word_3FF46=" << rhs.word_3FF46 << " 0x" << std::hex << rhs.word_3FF46 << std::dec << "\n";
    os << "word_3FF48=" << rhs.word_3FF48 << " 0x" << std::hex << rhs.word_3FF48 << std::dec << "\n";
    os << "word_3FF4A=" << rhs.word_3FF4A << " 0x" << std::hex << rhs.word_3FF4A << std::dec << "\n";
    os << "word_3FF4C=(\n";
    for (unsigned i = 0; i < 58; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_3FF4C[i] << " 0x" << std::hex << (unsigned)rhs.word_3FF4C[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_3FF86=" << rhs.word_3FF86 << " 0x" << std::hex << rhs.word_3FF86 << std::dec << "\n";
    os << "word_3FF88=" << rhs.word_3FF88 << " 0x" << std::hex << rhs.word_3FF88 << std::dec << "\n";
    os << "word_3FF8A=" << rhs.word_3FF8A << " 0x" << std::hex << rhs.word_3FF8A << std::dec << "\n";
    os << "word_3FF8C=" << rhs.word_3FF8C << " 0x" << std::hex << rhs.word_3FF8C << std::dec << "\n";
    os << "word_3FF8E=" << rhs.word_3FF8E << " 0x" << std::hex << rhs.word_3FF8E << std::dec << "\n";
    os << "word_3FF90=(\n";
    for (unsigned i = 0; i < 30; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_3FF90[i] << " 0x" << std::hex << (unsigned)rhs.word_3FF90[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_3FFAE=" << rhs.word_3FFAE << " 0x" << std::hex << rhs.word_3FFAE << std::dec << "\n";
    os << "word_3FFB0=" << rhs.word_3FFB0 << " 0x" << std::hex << rhs.word_3FFB0 << std::dec << "\n";
    os << "word_3FFB2=" << rhs.word_3FFB2 << " 0x" << std::hex << rhs.word_3FFB2 << std::dec << "\n";
    os << "word_3FFB4=" << rhs.word_3FFB4 << " 0x" << std::hex << rhs.word_3FFB4 << std::dec << "\n";
    os << "word_3FFB6=" << rhs.word_3FFB6 << " 0x" << std::hex << rhs.word_3FFB6 << std::dec << "\n";
    os << "word_3FFB8=" << rhs.word_3FFB8 << " 0x" << std::hex << rhs.word_3FFB8 << std::dec << "\n";
    os << "word_3FFBA=" << rhs.word_3FFBA << " 0x" << std::hex << rhs.word_3FFBA << std::dec << "\n";
    os << "word_3FFBC=" << rhs.word_3FFBC << " 0x" << std::hex << rhs.word_3FFBC << std::dec << "\n";
    os << "word_3FFBE=" << rhs.word_3FFBE << "\n";
    os << "word_3FFC2=" << rhs.word_3FFC2 << " 0x" << std::hex << rhs.word_3FFC2 << std::dec << "\n";
    os << "word_3FFC4=" << rhs.word_3FFC4 << " 0x" << std::hex << rhs.word_3FFC4 << std::dec << "\n";
    os << "word_3FFC6=" << rhs.word_3FFC6 << " 0x" << std::hex << rhs.word_3FFC6 << std::dec << "\n";
    os << "word_3FFC8=" << rhs.word_3FFC8 << "\n";
    os << "word_3FFCC=" << rhs.word_3FFCC << " 0x" << std::hex << rhs.word_3FFCC << std::dec << "\n";
    os << "word_3FFCE=(\n";
    for (unsigned i = 0; i < 14; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_3FFCE[i] << " 0x" << std::hex << (unsigned)rhs.word_3FFCE[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_3FFDC=" << rhs.word_3FFDC << " 0x" << std::hex << rhs.word_3FFDC << std::dec << "\n";
    os << "word_3FFDE=" << rhs.word_3FFDE << " 0x" << std::hex << rhs.word_3FFDE << std::dec << "\n";
    os << "word_3FFE0=(\n";
    for (unsigned i = 0; i < 8; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_3FFE0[i] << " 0x" << std::hex << (unsigned)rhs.word_3FFE0[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_3FFE8=(\n";
    for (unsigned i = 0; i < 38; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_3FFE8[i] << " 0x" << std::hex << (unsigned)rhs.word_3FFE8[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_4000E=" << rhs.word_4000E << " 0x" << std::hex << rhs.word_4000E << std::dec << "\n";
    os << "word_40010=" << rhs.word_40010 << " 0x" << std::hex << rhs.word_40010 << std::dec << "\n";
    os << "word_40012=" << rhs.word_40012 << " 0x" << std::hex << rhs.word_40012 << std::dec << "\n";
    os << "word_40014=" << rhs.word_40014 << " 0x" << std::hex << rhs.word_40014 << std::dec << "\n";
    os << "word_40016=" << rhs.word_40016 << " 0x" << std::hex << rhs.word_40016 << std::dec << "\n";
    os << "word_40018=" << rhs.word_40018 << " 0x" << std::hex << rhs.word_40018 << std::dec << "\n";
    os << "word_4001A=" << rhs.word_4001A << " 0x" << std::hex << rhs.word_4001A << std::dec << "\n";
    os << "word_4001C=" << rhs.word_4001C << " 0x" << std::hex << rhs.word_4001C << std::dec << "\n";
    os << "word_4001E=" << rhs.word_4001E << " 0x" << std::hex << rhs.word_4001E << std::dec << "\n";
    os << "word_40020=" << rhs.word_40020 << " 0x" << std::hex << rhs.word_40020 << std::dec << "\n";
    os << "word_40022=" << rhs.word_40022 << " 0x" << std::hex << rhs.word_40022 << std::dec << "\n";
    os << "word_40024=" << rhs.word_40024 << " 0x" << std::hex << rhs.word_40024 << std::dec << "\n";
    os << "word_40026=" << rhs.word_40026 << " 0x" << std::hex << rhs.word_40026 << std::dec << "\n";
    os << "word_40028=" << rhs.word_40028 << " 0x" << std::hex << rhs.word_40028 << std::dec << "\n";
    os << "word_4002A=" << rhs.word_4002A << " 0x" << std::hex << rhs.word_4002A << std::dec << "\n";
    os << "word_4002C=" << rhs.word_4002C << " 0x" << std::hex << rhs.word_4002C << std::dec << "\n";
    os << "word_4002E=(\n";
    for (unsigned i = 0; i < 28; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_4002E[i] << " 0x" << std::hex << (unsigned)rhs.word_4002E[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_4004A=" << rhs.word_4004A << " 0x" << std::hex << rhs.word_4004A << std::dec << "\n";
    os << "word_4004C=" << rhs.word_4004C << " 0x" << std::hex << rhs.word_4004C << std::dec << "\n";
    os << "word_4004E=" << rhs.word_4004E << " 0x" << std::hex << rhs.word_4004E << std::dec << "\n";
    os << "word_40050=" << rhs.word_40050 << " 0x" << std::hex << rhs.word_40050 << std::dec << "\n";
    os << "word_40052=" << rhs.word_40052 << " 0x" << std::hex << rhs.word_40052 << std::dec << "\n";
    os << "word_40054=" << rhs.word_40054 << " 0x" << std::hex << rhs.word_40054 << std::dec << "\n";
    os << "word_40056=" << rhs.word_40056 << " 0x" << std::hex << rhs.word_40056 << std::dec << "\n";
    os << "word_40058=" << rhs.word_40058 << " 0x" << std::hex << rhs.word_40058 << std::dec << "\n";
    os << "word_4005A=" << rhs.word_4005A << " 0x" << std::hex << rhs.word_4005A << std::dec << "\n";
    os << "word_4005C=" << rhs.word_4005C << " 0x" << std::hex << rhs.word_4005C << std::dec << "\n";
    os << "word_4005E=" << rhs.word_4005E << " 0x" << std::hex << rhs.word_4005E << std::dec << "\n";
    os << "word_40060=" << rhs.word_40060 << " 0x" << std::hex << rhs.word_40060 << std::dec << "\n";
    os << "word_40062=(\n";
    for (unsigned i = 0; i < 12; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_40062[i] << " 0x" << std::hex << (unsigned)rhs.word_40062[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_4006E=(\n";
    for (unsigned i = 0; i < 34; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_4006E[i] << " 0x" << std::hex << (unsigned)rhs.word_4006E[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_40090=" << rhs.word_40090 << " 0x" << std::hex << rhs.word_40090 << std::dec << "\n";
    os << "word_40092=(\n";
    for (unsigned i = 0; i < 82; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_40092[i] << " 0x" << std::hex << (unsigned)rhs.word_40092[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_cityNr_detailed=" << rhs.m_cityNr_detailed << " 0x" << std::hex << rhs.m_cityNr_detailed << std::dec << "\n";
    os << "word_400E8=(\n";
    for (unsigned i = 0; i < 246; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_400E8[i] << " 0x" << std::hex << (unsigned)rhs.word_400E8[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_401DC=" << rhs.word_401DC << " 0x" << std::hex << rhs.word_401DC << std::dec << "\n";
    os << "word_401DE=" << rhs.word_401DE << " 0x" << std::hex << rhs.word_401DE << std::dec << "\n";
    os << "word_401E0=" << rhs.word_401E0 << " 0x" << std::hex << rhs.word_401E0 << std::dec << "\n";
    os << "word_401E2=" << rhs.word_401E2 << " 0x" << std::hex << rhs.word_401E2 << std::dec << "\n";
    os << "word_401E4=" << rhs.word_401E4 << " 0x" << std::hex << rhs.word_401E4 << std::dec << "\n";
    os << "word_401E6=" << rhs.word_401E6 << " 0x" << std::hex << rhs.word_401E6 << std::dec << "\n";
    os << "word_401E8=" << rhs.word_401E8 << " 0x" << std::hex << rhs.word_401E8 << std::dec << "\n";
    os << "word_401EA=" << rhs.word_401EA << " 0x" << std::hex << rhs.word_401EA << std::dec << "\n";
    os << "word_401EC=" << rhs.word_401EC << " 0x" << std::hex << rhs.word_401EC << std::dec << "\n";
    os << "word_401EE=" << rhs.word_401EE << " 0x" << std::hex << rhs.word_401EE << std::dec << "\n";
    os << "word_401F0=" << rhs.word_401F0 << " 0x" << std::hex << rhs.word_401F0 << std::dec << "\n";
    os << "word_401F2=" << rhs.word_401F2 << " 0x" << std::hex << rhs.word_401F2 << std::dec << "\n";
    os << "word_401F4=" << rhs.word_401F4 << " 0x" << std::hex << rhs.word_401F4 << std::dec << "\n";
    os << "word_401F6=" << rhs.word_401F6 << " 0x" << std::hex << rhs.word_401F6 << std::dec << "\n";
    os << "word_401F8=" << rhs.word_401F8 << " 0x" << std::hex << rhs.word_401F8 << std::dec << "\n";
    os << "word_401FA=" << rhs.word_401FA << " 0x" << std::hex << rhs.word_401FA << std::dec << "\n";
    os << "word_401FC=" << rhs.word_401FC << " 0x" << std::hex << rhs.word_401FC << std::dec << "\n";
    os << "word_401FE=" << rhs.word_401FE << " 0x" << std::hex << rhs.word_401FE << std::dec << "\n";
    os << "word_40200=" << rhs.word_40200 << " 0x" << std::hex << rhs.word_40200 << std::dec << "\n";
    os << "word_40202=" << rhs.word_40202 << " 0x" << std::hex << rhs.word_40202 << std::dec << "\n";
    os << "word_40204=" << rhs.word_40204 << " 0x" << std::hex << rhs.word_40204 << std::dec << "\n";
    os << "word_40206=" << rhs.word_40206 << " 0x" << std::hex << rhs.word_40206 << std::dec << "\n";
    os << "word_40208=" << rhs.word_40208 << " 0x" << std::hex << rhs.word_40208 << std::dec << "\n";
    os << "word_4020A=" << rhs.word_4020A << " 0x" << std::hex << rhs.word_4020A << std::dec << "\n";
    os << "word_4020C=(\n";
    for (unsigned i = 0; i < 38; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_4020C[i] << " 0x" << std::hex << (unsigned)rhs.word_4020C[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_40232=" << rhs.word_40232 << " 0x" << std::hex << rhs.word_40232 << std::dec << "\n";
    os << "word_40234=" << rhs.word_40234 << " 0x" << std::hex << rhs.word_40234 << std::dec << "\n";
    os << "word_40236=" << rhs.word_40236 << " 0x" << std::hex << rhs.word_40236 << std::dec << "\n";
    os << "word_40238=" << rhs.word_40238 << " 0x" << std::hex << rhs.word_40238 << std::dec << "\n";
    os << "word_4023A=" << rhs.word_4023A << " 0x" << std::hex << rhs.word_4023A << std::dec << "\n";
    os << "word_4023C=" << rhs.word_4023C << " 0x" << std::hex << rhs.word_4023C << std::dec << "\n";
    os << "word_4023E=" << rhs.word_4023E << " 0x" << std::hex << rhs.word_4023E << std::dec << "\n";
    os << "word_40240=" << rhs.word_40240 << " 0x" << std::hex << rhs.word_40240 << std::dec << "\n";
    os << "word_40242=(\n";
    for (unsigned i = 0; i < 18; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_40242[i] << " 0x" << std::hex << (unsigned)rhs.word_40242[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_40254=" << rhs.word_40254 << " 0x" << std::hex << rhs.word_40254 << std::dec << "\n";
    os << "word_40256=" << rhs.word_40256 << " 0x" << std::hex << rhs.word_40256 << std::dec << "\n";
    os << "word_40258=" << rhs.word_40258 << " 0x" << std::hex << rhs.word_40258 << std::dec << "\n";
    os << "word_4025A=(\n";
    for (unsigned i = 0; i < 50; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_4025A[i] << " 0x" << std::hex << (unsigned)rhs.word_4025A[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_4028C=" << rhs.word_4028C << " 0x" << std::hex << rhs.word_4028C << std::dec << "\n";
    os << "word_4028E=(\n";
    for (unsigned i = 0; i < 10; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_4028E[i] << " 0x" << std::hex << (unsigned)rhs.word_4028E[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_40298=" << rhs.word_40298 << " 0x" << std::hex << rhs.word_40298 << std::dec << "\n";
    os << "word_4029A=" << rhs.word_4029A << " 0x" << std::hex << rhs.word_4029A << std::dec << "\n";
    os << "word_4029C=" << rhs.word_4029C << " 0x" << std::hex << rhs.word_4029C << std::dec << "\n";
    os << "word_4029E=(\n";
    for (unsigned i = 0; i < 34; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_4029E[i] << " 0x" << std::hex << (unsigned)rhs.word_4029E[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_402C0=(\n";
    for (unsigned i = 0; i < 32; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_402C0[i] << " 0x" << std::hex << (unsigned)rhs.word_402C0[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_402E0=" << rhs.word_402E0 << " 0x" << std::hex << rhs.word_402E0 << std::dec << "\n";
    os << "word_402E2=(\n";
    for (unsigned i = 0; i < 36; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_402E2[i] << " 0x" << std::hex << (unsigned)rhs.word_402E2[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_40306=(\n";
    for (unsigned i = 0; i < 120; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_40306[i] << " 0x" << std::hex << (unsigned)rhs.word_40306[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_4037E=(\n";
    for (unsigned i = 0; i < 10; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_4037E[i] << " 0x" << std::hex << (unsigned)rhs.word_4037E[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_40388=(\n";
    for (unsigned i = 0; i < 10; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_40388[i] << " 0x" << std::hex << (unsigned)rhs.word_40388[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_40392=" << rhs.word_40392 << " 0x" << std::hex << rhs.word_40392 << std::dec << "\n";
    os << "word_40394=(\n";
    for (unsigned i = 0; i < 20; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_40394[i] << " 0x" << std::hex << (unsigned)rhs.word_40394[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_403A8=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_403A8[i] << " 0x" << std::hex << (unsigned)rhs.word_403A8[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_403AE=(\n";
    for (unsigned i = 0; i < 10; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_403AE[i] << " 0x" << std::hex << (unsigned)rhs.word_403AE[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_403B8=" << rhs.word_403B8 << " 0x" << std::hex << rhs.word_403B8 << std::dec << "\n";
    os << "word_403BA=" << rhs.word_403BA << " 0x" << std::hex << rhs.word_403BA << std::dec << "\n";
    os << "word_403BC=" << rhs.word_403BC << " 0x" << std::hex << rhs.word_403BC << std::dec << "\n";
    os << "word_403BE=" << rhs.word_403BE << " 0x" << std::hex << rhs.word_403BE << std::dec << "\n";
    os << "word_403C0=" << rhs.word_403C0 << " 0x" << std::hex << rhs.word_403C0 << std::dec << "\n";
    os << "word_403C2=(\n";
    for (unsigned i = 0; i < 20; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_403C2[i] << " 0x" << std::hex << (unsigned)rhs.word_403C2[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "word_403D6=" << rhs.word_403D6 << " 0x" << std::hex << rhs.word_403D6 << std::dec << "\n";
    os << "word_403D8=" << rhs.word_403D8 << " 0x" << std::hex << rhs.word_403D8 << std::dec << "\n";
    os << "word_403DA=" << rhs.word_403DA << " 0x" << std::hex << rhs.word_403DA << std::dec << "\n";
    os << "word_403DC=" << rhs.word_403DC << " 0x" << std::hex << rhs.word_403DC << std::dec << "\n";
    os << "word_403DE=" << rhs.word_403DE << " 0x" << std::hex << rhs.word_403DE << std::dec << "\n";
    os << "word_403E0=" << rhs.word_403E0 << " 0x" << std::hex << rhs.word_403E0 << std::dec << "\n";
    os << "word_403E2=" << rhs.word_403E2 << " 0x" << std::hex << rhs.word_403E2 << std::dec << "\n";
    os << "word_403E4=" << rhs.word_403E4 << " 0x" << std::hex << rhs.word_403E4 << std::dec << "\n";
    os << "word_403E6=" << rhs.word_403E6 << " 0x" << std::hex << rhs.word_403E6 << std::dec << "\n";
    os << "word_403E8=" << rhs.word_403E8 << " 0x" << std::hex << rhs.word_403E8 << std::dec << "\n";
    os << "word_403EA=" << rhs.word_403EA << " 0x" << std::hex << rhs.word_403EA << std::dec << "\n";
    os << "word_403EC=" << rhs.word_403EC << " 0x" << std::hex << rhs.word_403EC << std::dec << "\n";
    os << "word_403EE=" << rhs.word_403EE << " 0x" << std::hex << rhs.word_403EE << std::dec << "\n";
    os << "word_403F0=" << rhs.word_403F0 << " 0x" << std::hex << rhs.word_403F0 << std::dec << "\n";
    os << "word_403F2=" << rhs.word_403F2 << " 0x" << std::hex << rhs.word_403F2 << std::dec << "\n";
    os << "word_403F4=" << rhs.word_403F4 << " 0x" << std::hex << rhs.word_403F4 << std::dec << "\n";
    os << "word_403F6=" << rhs.word_403F6 << " 0x" << std::hex << rhs.word_403F6 << std::dec << "\n";
    os << "word_403F8=" << rhs.word_403F8 << " 0x" << std::hex << rhs.word_403F8 << std::dec << "\n";
    os << "word_403FA=" << rhs.word_403FA << " 0x" << std::hex << rhs.word_403FA << std::dec << "\n";
    os << "word_403FC=" << rhs.word_403FC << " 0x" << std::hex << rhs.word_403FC << std::dec << "\n";
    os << "word_403FE=" << rhs.word_403FE << "\n";
    os << "word_40402=" << rhs.word_40402 << " 0x" << std::hex << rhs.word_40402 << std::dec << "\n";
    os << "word_40404=" << rhs.word_40404 << " 0x" << std::hex << rhs.word_40404 << std::dec << "\n";
    os << "word_40406=" << rhs.word_40406 << " 0x" << std::hex << rhs.word_40406 << std::dec << "\n";
    os << "word_40408=" << rhs.word_40408 << " 0x" << std::hex << rhs.word_40408 << std::dec << "\n";
    os << "word_4040A=" << rhs.word_4040A << " 0x" << std::hex << rhs.word_4040A << std::dec << "\n";
    os << "word_4040C=" << rhs.word_4040C << " 0x" << std::hex << rhs.word_4040C << std::dec << "\n";
    os << "word_4040E=" << rhs.word_4040E << " 0x" << std::hex << rhs.word_4040E << std::dec << "\n";
    os << "word_40410=" << rhs.word_40410 << " 0x" << std::hex << rhs.word_40410 << std::dec << "\n";
    os << "word_40412=" << rhs.word_40412 << " 0x" << std::hex << rhs.word_40412 << std::dec << "\n";
    os << "word_40414=" << rhs.word_40414 << " 0x" << std::hex << rhs.word_40414 << std::dec << "\n";
    os << "word_40416=" << rhs.word_40416 << " 0x" << std::hex << rhs.word_40416 << std::dec << "\n";
    os << "word_40418=" << rhs.word_40418 << " 0x" << std::hex << rhs.word_40418 << std::dec << "\n";
    os << "word_4041A=" << rhs.word_4041A << " 0x" << std::hex << rhs.word_4041A << std::dec << "\n";
    os << "word_4041C=" << rhs.word_4041C << " 0x" << std::hex << rhs.word_4041C << std::dec << "\n";
    os << "word_4041E=" << rhs.word_4041E << " 0x" << std::hex << rhs.word_4041E << std::dec << "\n";
    os << "word_40420=" << rhs.word_40420 << " 0x" << std::hex << rhs.word_40420 << std::dec << "\n";
    os << "word_40422=" << rhs.word_40422 << " 0x" << std::hex << rhs.word_40422 << std::dec << "\n";
    os << "word_40424=" << rhs.word_40424 << " 0x" << std::hex << rhs.word_40424 << std::dec << "\n";
    os << "word_40426=" << rhs.word_40426 << " 0x" << std::hex << rhs.word_40426 << std::dec << "\n";
    os << "word_40428=" << rhs.word_40428 << "\n";
    os << "word_4042C=" << rhs.word_4042C << " 0x" << std::hex << rhs.word_4042C << std::dec << "\n";
    os << "w_constant_GUESS=" << rhs.w_constant_GUESS << " 0x" << std::hex << rhs.w_constant_GUESS << std::dec << "\n";
    os << "m_Game_flow=" << rhs.m_Game_flow << "\n";
    os << "word_40432=" << rhs.word_40432 << " 0x" << std::hex << rhs.word_40432 << std::dec << "\n";
    os << "word_40434=" << rhs.word_40434 << " 0x" << std::hex << rhs.word_40434 << std::dec << "\n";
    os << "word_40436=" << rhs.word_40436 << " 0x" << std::hex << rhs.word_40436 << std::dec << "\n";
    os << "m_addr_events=" << rhs.m_addr_events << "\n";
    os << "w_uts_in_stack_ovrland_GUESS=" << rhs.w_uts_in_stack_ovrland_GUESS << " 0x" << std::hex << rhs.w_uts_in_stack_ovrland_GUESS << std::dec << "\n";
    os << "w_Stack_active_GUESS=(\n";
    for (unsigned i = 0; i < 36; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.w_Stack_active_GUESS[i] << " 0x" << std::hex << (unsigned)rhs.w_Stack_active_GUESS[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "byte_40462=(\n";
    for (unsigned i = 0; i < 281; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.byte_40462[i] << " 0x" << std::hex << (unsigned)rhs.byte_40462[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "byte_4057B=(\n";
    for (unsigned i = 0; i < 21; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.byte_4057B[i] << " 0x" << std::hex << (unsigned)rhs.byte_4057B[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "b_mess_number=(\n";
    for (unsigned i = 0; i < 82; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.b_mess_number[i] << " 0x" << std::hex << (unsigned)rhs.b_mess_number[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "byte_405E2=(\n";
    for (unsigned i = 0; i < 82; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.byte_405E2[i] << " 0x" << std::hex << (unsigned)rhs.byte_405E2[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "byte_40634=(\n";
    for (unsigned i = 0; i < 82; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.byte_40634[i] << " 0x" << std::hex << (unsigned)rhs.byte_40634[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "byte_40686=(\n";
    for (unsigned i = 0; i < 82; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.byte_40686[i] << " 0x" << std::hex << (unsigned)rhs.byte_40686[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "byte_406D8=(\n";
    for (unsigned i = 0; i < 21; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.byte_406D8[i] << " 0x" << std::hex << (unsigned)rhs.byte_406D8[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "byte_406ED=(\n";
    for (unsigned i = 0; i < 21; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.byte_406ED[i] << " 0x" << std::hex << (unsigned)rhs.byte_406ED[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "byte_40702=(\n";
    for (unsigned i = 0; i < 21; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.byte_40702[i] << " 0x" << std::hex << (unsigned)rhs.byte_40702[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "byte_40717=(\n";
    for (unsigned i = 0; i < 21; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.byte_40717[i] << " 0x" << std::hex << (unsigned)rhs.byte_40717[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "byte_4072C=" << rhs.byte_4072C << " 0x" << std::hex << rhs.byte_4072C << std::dec << "\n";
    os << "w_video_style_CL_BUG_GUESS=" << rhs.w_video_style_CL_BUG_GUESS << " 0x" << std::hex << rhs.w_video_style_CL_BUG_GUESS << std::dec << "\n";
    os << "dword_40730=" << rhs.dword_40730 << "\n";
    os << "word_40734=" << rhs.word_40734 << " 0x" << std::hex << rhs.word_40734 << std::dec << "\n";
    os << "word_40736=" << rhs.word_40736 << " 0x" << std::hex << rhs.word_40736 << std::dec << "\n";
    os << "word_40738=" << rhs.word_40738 << " 0x" << std::hex << rhs.word_40738 << std::dec << "\n";
    os << "word_4073A=" << rhs.word_4073A << " 0x" << std::hex << rhs.word_4073A << std::dec << "\n";
    os << "dword_4073C=" << rhs.dword_4073C << "\n";
    os << "dword_40740=" << rhs.dword_40740 << "\n";
    os << "m_addr_terrain_Movement_copy=" << rhs.m_addr_terrain_Movement_copy << "\n";
    os << "dword_40748=" << rhs.dword_40748 << "\n";
    os << "m_addr_Terrain_Movement=" << rhs.m_addr_Terrain_Movement << "\n";
    os << "m_addr_Terrain_Explored=" << rhs.m_addr_Terrain_Explored << "\n";
    os << "m_addr_Terrain_Changes=" << rhs.m_addr_Terrain_Changes << "\n";
    os << "m_addr_Terrain_Bonuses=" << rhs.m_addr_Terrain_Bonuses << "\n";
    os << "m_addr_Cities=" << rhs.m_addr_Cities << "\n";
    os << "m_addr_Lairs_data=" << rhs.m_addr_Lairs_data << "\n";
    os << "m_addr_tower_attr=" << rhs.m_addr_tower_attr << "\n";
    os << "m_addr_fortress_data=" << rhs.m_addr_fortress_data << "\n";
    os << "m_addr_Nodes_Attr=" << rhs.m_addr_Nodes_Attr << "\n";
    os << "m_addr_Terrain_LandMassID=" << rhs.m_addr_Terrain_LandMassID << "\n";
    os << "addr_40774_Terrain=" << rhs.addr_40774_Terrain << "\n";
    os << "addr_40778_Terrain=" << rhs.addr_40778_Terrain << "\n";
    os << "m_addr_Terrain_Types=" << rhs.m_addr_Terrain_Types << "\n";
    os << "m_addr_Unrest_Table=(\n";
    for (unsigned i = 0; i < gMAX_RACES; ++i)
    {
        os << "[" << i << "] " << rhs.m_addr_Unrest_Table[i] << ",\n";
    }
    os << ")\n";
    os << "word_407B8=" << rhs.word_407B8 << " 0x" << std::hex << rhs.word_407B8 << std::dec << "\n";
    os << "word_407BA=" << rhs.word_407BA << " 0x" << std::hex << rhs.word_407BA << std::dec << "\n";
    os << "word_407BC=" << rhs.word_407BC << " 0x" << std::hex << rhs.word_407BC << std::dec << "\n";
    os << "word_407BE=" << rhs.word_407BE << " 0x" << std::hex << rhs.word_407BE << std::dec << "\n";
    os << "word_407C0=" << rhs.word_407C0 << " 0x" << std::hex << rhs.word_407C0 << std::dec << "\n";
    os << "m_Vizier_active=" << rhs.m_Vizier_active << " 0x" << std::hex << rhs.m_Vizier_active << std::dec << "\n";
    os << "word_407C4=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.word_407C4[i] << " 0x" << std::hex << (unsigned)rhs.word_407C4[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "dword_407CA=" << rhs.dword_407CA << "\n";
    os << "dword_407CE=" << rhs.dword_407CE << "\n";
    os << "word_407D2=" << rhs.word_407D2 << " 0x" << std::hex << rhs.word_407D2 << std::dec << "\n";
    os << "word_407D4=" << rhs.word_407D4 << " 0x" << std::hex << rhs.word_407D4 << std::dec << "\n";
    os << "word_407D6=" << rhs.word_407D6 << " 0x" << std::hex << rhs.word_407D6 << std::dec << "\n";
    os << "word_407D8=" << rhs.word_407D8 << " 0x" << std::hex << rhs.word_407D8 << std::dec << "\n";
    os << "word_407DA=" << rhs.word_407DA << " 0x" << std::hex << rhs.word_407DA << std::dec << "\n";
    os << "word_407DC=" << rhs.word_407DC << " 0x" << std::hex << rhs.word_407DC << std::dec << "\n";
    os << "word_407DE=" << rhs.word_407DE << " 0x" << std::hex << rhs.word_407DE << std::dec << "\n";
    os << "word_407E0=" << rhs.word_407E0 << " 0x" << std::hex << rhs.word_407E0 << std::dec << "\n";
    os << "word_407E2=" << rhs.word_407E2 << " 0x" << std::hex << rhs.word_407E2 << std::dec << "\n";
    os << "word_407E4=" << rhs.word_407E4 << " 0x" << std::hex << rhs.word_407E4 << std::dec << "\n";
    os << "word_407E6=" << rhs.word_407E6 << " 0x" << std::hex << rhs.word_407E6 << std::dec << "\n";
    os << "word_407E8=" << rhs.word_407E8 << " 0x" << std::hex << rhs.word_407E8 << std::dec << "\n";
    os << "w_AI_stack_nr=" << rhs.w_AI_stack_nr << " 0x" << std::hex << rhs.w_AI_stack_nr << std::dec << "\n";
    os << "unk_407EC=(\n";
    for (unsigned i = 0; i < 320; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.unk_407EC[i] << " 0x" << std::hex << (unsigned)rhs.unk_407EC[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "dw_Nr_in_stack=" << rhs.dw_Nr_in_stack << "\n";
    os << "dw_stack_place=" << rhs.dw_stack_place << "\n";
    os << "dw_pla_stacks_loc=" << rhs.dw_pla_stacks_loc << "\n";
    os << "dw_Y_stacks_loc=" << rhs.dw_Y_stacks_loc << "\n";
    os << "dw_X_stacks_loc=" << rhs.dw_X_stacks_loc << "\n";
    os << "dw_bx_6160=" << rhs.dw_bx_6160 << "\n";
    os << "dw_bx_615C=" << rhs.dw_bx_615C << "\n";
    os << "dw_bx_6176=" << rhs.dw_bx_6176 << "\n";
    os << "dw_bx_6154=" << rhs.dw_bx_6154 << "\n";
    os << "word_40950=" << rhs.word_40950 << " 0x" << std::hex << rhs.word_40950 << std::dec << "\n";
    os << "word_40952=" << rhs.word_40952 << " 0x" << std::hex << rhs.word_40952 << std::dec << "\n";
    os << "word_40954=" << rhs.word_40954 << " 0x" << std::hex << rhs.word_40954 << std::dec << "\n";
    os << "word_40956=" << rhs.word_40956 << " 0x" << std::hex << rhs.word_40956 << std::dec << "\n";
    os << "word_40958=" << rhs.word_40958 << " 0x" << std::hex << rhs.word_40958 << std::dec << "\n";
    os << "word_4095A=" << rhs.word_4095A << " 0x" << std::hex << rhs.word_4095A << std::dec << "\n";
    os << "word_4095C=" << rhs.word_4095C << " 0x" << std::hex << rhs.word_4095C << std::dec << "\n";
    os << "word_4095E=" << rhs.word_4095E << " 0x" << std::hex << rhs.word_4095E << std::dec << "\n";
    os << "word_40960=" << rhs.word_40960 << " 0x" << std::hex << rhs.word_40960 << std::dec << "\n";
    os << "m_addr_Units=" << rhs.m_addr_Units << "\n";
    os << "m_addr_Chosen_Hero_Names=" << rhs.m_addr_Chosen_Hero_Names << "\n";
    os << "m_Wizards=(\n";
    for (unsigned i = 0; i < gMAX_WIZARD_RECORDS; ++i)
    {
        os << "[" << i << "] " << rhs.m_Wizards[i] << ",\n";
    }
    os << ")\n";
    os << "m_Unk_BB7A=(\n";
    for (unsigned i = 0; i < 0xBD8E - 0xBB7A; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_BB7A[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_BB7A[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Game_Data=" << rhs.m_Game_Data << "\n";
    os << "m_Game_Settings=" << rhs.m_Game_Settings << "\n";
    os << "m_Unk_BF70=(\n";
    for (unsigned i = 0; i < 0xC190 - 0xBF70; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_BF70[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_BF70[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_UnitView_nrLines=" << rhs.m_UnitView_nrLines << " 0x" << std::hex << rhs.m_UnitView_nrLines << std::dec << "\n";
    os << "m_Offset_UnitView_Lines=" << rhs.m_Offset_UnitView_Lines << " 0x" << std::hex << rhs.m_Offset_UnitView_Lines << std::dec << "\n";
    os << "m_UnitView_UnitEnchantment=" << rhs.m_UnitView_UnitEnchantment << "\n";
    os << "m_Unk_C196=(\n";
    for (unsigned i = 0; i < 0xC292 - 0xC198; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_C196[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_C196[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Location_Item=" << rhs.m_Location_Item << " 0x" << std::hex << rhs.m_Location_Item << std::dec << "\n";
    os << "m_Selected_Item=" << rhs.m_Selected_Item << " 0x" << std::hex << rhs.m_Selected_Item << std::dec << "\n";
    os << "m_Unk_C296=(\n";
    for (unsigned i = 0; i < 0xC300 - 0xC296; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_C296[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_C296[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Plane_Item=" << rhs.m_Plane_Item << "\n";
    os << "m_YPos_Item=" << rhs.m_YPos_Item << " 0x" << std::hex << rhs.m_YPos_Item << std::dec << "\n";
    os << "m_XPos_Item=" << rhs.m_XPos_Item << " 0x" << std::hex << rhs.m_XPos_Item << std::dec << "\n";
    os << "m_Unk_C306=(\n";
    for (unsigned i = 0; i < 0xC51C - 0xC306; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_C306[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_C306[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Combat_turn=" << rhs.m_Combat_turn << " 0x" << std::hex << rhs.m_Combat_turn << std::dec << "\n";
    os << "m_Unk_C51E=" << rhs.m_Unk_C51E << " 0x" << std::hex << rhs.m_Unk_C51E << std::dec << "\n";
    os << "m_External_battle_condition=" << rhs.m_External_battle_condition << "\n";
    os << "m_Unk_C522=" << rhs.m_Unk_C522 << " 0x" << std::hex << rhs.m_Unk_C522 << std::dec << "\n";
    os << "m_Offsets_Battlefield_battleUnitIDs=(\n";
    for (unsigned i = 0; i < 22; ++i)
    {
        os << "[" << i << "] " << rhs.m_Offsets_Battlefield_battleUnitIDs[i] << " 0x" << std::hex << rhs.m_Offsets_Battlefield_battleUnitIDs[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Unk_C550=(\n";
    for (unsigned i = 0; i < 0xC582 - 0xC550; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_C550[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_C550[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_BattleUnit_on_move=" << rhs.m_BattleUnit_on_move << " 0x" << std::hex << rhs.m_BattleUnit_on_move << std::dec << "\n";
    os << "m_Defending_wizard=" << rhs.m_Defending_wizard << " 0x" << std::hex << rhs.m_Defending_wizard << std::dec << "\n";
    os << "m_Attacking_wizard=" << rhs.m_Attacking_wizard << " 0x" << std::hex << rhs.m_Attacking_wizard << std::dec << "\n";
    os << "m_Nr_Battle_Units=" << rhs.m_Nr_Battle_Units << " 0x" << std::hex << rhs.m_Nr_Battle_Units << std::dec << "\n";
    os << "m_BattleUnit_pointed_at=" << rhs.m_BattleUnit_pointed_at << " 0x" << std::hex << rhs.m_BattleUnit_pointed_at << std::dec << "\n";
    os << "m_Unk_C58A=(\n";
    for (unsigned i = 0; i < 0xC5C2 - 0xC58C; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_C58A[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_C58A[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Battle_winner=" << rhs.m_Battle_winner << " 0x" << std::hex << rhs.m_Battle_winner << std::dec << "\n";
    os << "m_Battle_loser=" << rhs.m_Battle_loser << " 0x" << std::hex << rhs.m_Battle_loser << std::dec << "\n";
    os << "m_Unk_C5C6=(\n";
    for (unsigned i = 0; i < 0xC5DE - 0xC5C6; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_C5C6[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_C5C6[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_YPos_clash=" << rhs.m_YPos_clash << " 0x" << std::hex << rhs.m_YPos_clash << std::dec << "\n";
    os << "m_XPos_clash=" << rhs.m_XPos_clash << " 0x" << std::hex << rhs.m_XPos_clash << std::dec << "\n";
    os << "m_Unk_C5E2=(\n";
    for (unsigned i = 0; i < 0xC8B4 - 0xC5E2; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_C5E2[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_C5E2[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Battlefield_flags=" << rhs.m_Battlefield_flags << " 0x" << std::hex << rhs.m_Battlefield_flags << std::dec << "\n";
    os << "m_Unk_C8B6=(\n";
    for (unsigned i = 0; i < 0xC8FA - 0xC8B6; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_C8B6[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_C8B6[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_offset_Available_spell_pages=" << rhs.m_offset_Available_spell_pages << " 0x" << std::hex << rhs.m_offset_Available_spell_pages << std::dec << "\n";
    os << "m_Unk_C8FC=(\n";
    for (unsigned i = 0; i < 0xC910 - 0xC8FC; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_C8FC[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_C8FC[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_addr_Hero_Spells=" << rhs.m_addr_Hero_Spells << "\n";
    os << "m_Nr_available_spell_pages=" << rhs.m_Nr_available_spell_pages << " 0x" << std::hex << rhs.m_Nr_available_spell_pages << std::dec << "\n";
    os << "m_Unk_C916=(\n";
    for (unsigned i = 0; i < 0xC924 - 0xC916; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_C916[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_C916[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_First_visible_available_spell_page=" << rhs.m_First_visible_available_spell_page << " 0x" << std::hex << rhs.m_First_visible_available_spell_page << std::dec << "\n";
    os << "m_Unk_C926=(\n";
    for (unsigned i = 0; i < 0xD15A - 0xC926; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_C926[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_C926[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_addr_Battle_figures_256=" << rhs.m_addr_Battle_figures_256 << "\n";
    os << "m_Nr_figures_on_battlefield=" << rhs.m_Nr_figures_on_battlefield << " 0x" << std::hex << rhs.m_Nr_figures_on_battlefield << std::dec << "\n";
    os << "m_Unk_D160=(\n";
    for (unsigned i = 0; i < 0xD188 - 0xD160; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_D160[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_D160[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Battle_activetile_anim=" << rhs.m_Battle_activetile_anim << " 0x" << std::hex << rhs.m_Battle_activetile_anim << std::dec << "\n";
    os << "m_Battle_tileselection_anim=" << rhs.m_Battle_tileselection_anim << " 0x" << std::hex << rhs.m_Battle_tileselection_anim << std::dec << "\n";
    os << "m_Unk_D18C=(\n";
    for (unsigned i = 0; i < 0xD49A - 0xD18C; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_D18C[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_D18C[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_NEAR_HEAP=(\n";
    for (unsigned i = 0; i < 0x1130; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_NEAR_HEAP[i] << " 0x" << std::hex << (unsigned)rhs.m_NEAR_HEAP[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Unk_E5CA=(\n";
    for (unsigned i = 0; i < 0xE5FC - 0xE5CA; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_E5CA[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_E5CA[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_EMS_lbx_descriptors_0C=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << rhs.m_EMS_lbx_descriptors_0C[i] << ",\n";
    }
    os << ")\n";
    os << "m_required_EMS_memory=" << rhs.m_required_EMS_memory << " 0x" << std::hex << rhs.m_required_EMS_memory << std::dec << "\n";
    os << "m_Unk_E7DE=(\n";
    for (unsigned i = 0; i < 0xE800 - 0xE7DE; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_E7DE[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_E7DE[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_arr16_font_palette=(\n";
    for (unsigned i = 0; i < 16; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_arr16_font_palette[i] << " 0x" << std::hex << (unsigned)rhs.m_arr16_font_palette[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_byte_00h_from_fonts_style_data=" << (unsigned)rhs.m_byte_00h_from_fonts_style_data << " 0x" << std::hex << (unsigned)rhs.m_byte_00h_from_fonts_style_data << std::dec << "\n";
    os << "m_byte_14h_from_fonts_style_data=" << (unsigned)rhs.m_byte_14h_from_fonts_style_data << " 0x" << std::hex << (unsigned)rhs.m_byte_14h_from_fonts_style_data << std::dec << "\n";
    os << "m_byte_24h_from_fonts_style_data=" << (unsigned)rhs.m_byte_24h_from_fonts_style_data << " 0x" << std::hex << (unsigned)rhs.m_byte_24h_from_fonts_style_data << std::dec << "\n";
    os << "m_byte_34h_from_fonts_style_data=" << (unsigned)rhs.m_byte_34h_from_fonts_style_data << " 0x" << std::hex << (unsigned)rhs.m_byte_34h_from_fonts_style_data << std::dec << "\n";
    os << "m_Unk_E814=" << rhs.m_Unk_E814 << " 0x" << std::hex << rhs.m_Unk_E814 << std::dec << "\n";
    os << "m_Unk_E816=" << rhs.m_Unk_E816 << " 0x" << std::hex << rhs.m_Unk_E816 << std::dec << "\n";
    os << "m_font_palette_section_index=" << rhs.m_font_palette_section_index << " 0x" << std::hex << rhs.m_font_palette_section_index << std::dec << "\n";
    os << "m_cur_font_nr=" << rhs.m_cur_font_nr << " 0x" << std::hex << rhs.m_cur_font_nr << std::dec << "\n";
    os << "m_display_text_xpel=" << rhs.m_display_text_xpel << " 0x" << std::hex << rhs.m_display_text_xpel << std::dec << "\n";
    os << "m_display_text_ypel=" << rhs.m_display_text_ypel << " 0x" << std::hex << rhs.m_display_text_ypel << std::dec << "\n";
    os << "m_seg_fonts_style_data=" << rhs.m_seg_fonts_style_data << " 0x" << std::hex << rhs.m_seg_fonts_style_data << std::dec << "\n";
    os << "m_seg_fonts_border_style_data=" << rhs.m_seg_fonts_border_style_data << " 0x" << std::hex << rhs.m_seg_fonts_border_style_data << std::dec << "\n";
    os << "m_Unk_E824=(\n";
    for (unsigned i = 0; i < 0xE860 - 0xE824; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_E824[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_E824[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_EMS_lbx_descriptor=" << rhs.m_EMS_lbx_descriptor << "\n";
    os << "m_Unk_E86C=(\n";
    for (unsigned i = 0; i < 0xE8A2 - 0xE86C; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_E86C[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_E86C[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_clickable_area_nr=" << rhs.m_clickable_area_nr << " 0x" << std::hex << rhs.m_clickable_area_nr << std::dec << "\n";
    os << "m_Unk_E8A4=(\n";
    for (unsigned i = 0; i < 0xE8AC - 0xE8A4; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_E8A4[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_E8A4[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_addr_ClickableArea=" << rhs.m_addr_ClickableArea << "\n";
    os << "m_Unk_E8B0=(\n";
    for (unsigned i = 0; i < 0xEA54 - 0xE8B0; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_E8B0[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_E8B0[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_PARALIGN09=(\n";
    for (unsigned i = 0; i < 0x0C; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_PARALIGN09[i] << " 0x" << std::hex << (unsigned)rhs.m_PARALIGN09[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_StackSegment=(\n";
    for (unsigned i = 0; i < 0x40; ++i)
    {
        os << "[" << i << "] " << rhs.m_StackSegment[i] << " 0x" << std::hex << rhs.m_StackSegment[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const MoMFontsCharacterWidths& rhs)
{
    os << "{\n";
    os << "m_characterWidths=(\n";
    for (unsigned i = 0; i < 0x60; ++i)
    {
        os << "[" << i << "] " << (int)rhs.m_characterWidths[i] << " 0x" << std::hex << (int)rhs.m_characterWidths[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const MoMFontsGlyphOffsets& rhs)
{
    os << "{\n";
    os << "m_glyphOffsets=(\n";
    for (unsigned i = 0; i < 0x60; ++i)
    {
        os << "[" << i << "] " << rhs.m_glyphOffsets[i] << " 0x" << std::hex << rhs.m_glyphOffsets[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const MoMFontsStyleData& rhs)
{
    os << "{\n";
    os << "m_Unk_0000=(\n";
    for (unsigned i = 0; i < 0x0010; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_0000[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_0000[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_curFontHeight=" << rhs.m_curFontHeight << " 0x" << std::hex << rhs.m_curFontHeight << std::dec << "\n";
    os << "m_Unk_0012=(\n";
    for (unsigned i = 0; i < 0x0036; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_0012[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_0012[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_curHorizontalSpacing=" << rhs.m_curHorizontalSpacing << " 0x" << std::hex << rhs.m_curHorizontalSpacing << std::dec << "\n";
    os << "m_curCharacterWidths=(\n";
    for (unsigned i = 0; i < 0x60; ++i)
    {
        os << "[" << i << "] " << (int)rhs.m_curCharacterWidths[i] << " 0x" << std::hex << (int)rhs.m_curCharacterWidths[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_curGlyphOffsets=(\n";
    for (unsigned i = 0; i < 0x60; ++i)
    {
        os << "[" << i << "] " << rhs.m_curGlyphOffsets[i] << " 0x" << std::hex << rhs.m_curGlyphOffsets[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_allFontHeights=(\n";
    for (unsigned i = 0; i < 8; ++i)
    {
        os << "[" << i << "] " << rhs.m_allFontHeights[i] << " 0x" << std::hex << rhs.m_allFontHeights[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_allHorizontalSpacings=(\n";
    for (unsigned i = 0; i < 8; ++i)
    {
        os << "[" << i << "] " << rhs.m_allHorizontalSpacings[i] << " 0x" << std::hex << rhs.m_allHorizontalSpacings[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_allLineSpacings=(\n";
    for (unsigned i = 0; i < 8; ++i)
    {
        os << "[" << i << "] " << rhs.m_allLineSpacings[i] << " 0x" << std::hex << rhs.m_allLineSpacings[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_allCharacterWidths=(\n";
    for (unsigned i = 0; i < 8; ++i)
    {
        os << "[" << i << "] " << rhs.m_allCharacterWidths[i] << ",\n";
    }
    os << ")\n";
    os << "m_allGlyphOffsets=(\n";
    for (unsigned i = 0; i < 8; ++i)
    {
        os << "[" << i << "] " << rhs.m_allGlyphOffsets[i] << ",\n";
    }
    os << ")\n";
    os << "m_glyphData=(\n";
    for (unsigned i = 0; i < 1; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_glyphData[i] << " 0x" << std::hex << (unsigned)rhs.m_glyphData[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const MoMImageHeaderLbx& rhs)
{
    os << "{\n";
    os << "width=" << rhs.width << " 0x" << std::hex << rhs.width << std::dec << "\n";
    os << "height=" << rhs.height << " 0x" << std::hex << rhs.height << std::dec << "\n";
    os << "compression=" << rhs.compression << " 0x" << std::hex << rhs.compression << std::dec << "\n";
    os << "nframes=" << rhs.nframes << " 0x" << std::hex << rhs.nframes << std::dec << "\n";
    os << "frameDelay=" << rhs.frameDelay << " 0x" << std::hex << rhs.frameDelay << std::dec << "\n";
    os << "flags=" << rhs.flags << " 0x" << std::hex << rhs.flags << std::dec << "\n";
    os << "reserved_0C=" << rhs.reserved_0C << " 0x" << std::hex << rhs.reserved_0C << std::dec << "\n";
    os << "paletteInfoOffset=" << rhs.paletteInfoOffset << " 0x" << std::hex << rhs.paletteInfoOffset << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const MoMMagicDataSegment& rhs)
{
    os << "{\n";
    os << "m_DataSegmentStart=" << formatCharArray(rhs.m_DataSegmentStart, 47) << "\n";
    os << "m_Unk_002F=(\n";
    for (unsigned i = 0; i < 0x2AD0 - 47; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_002F[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_002F[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Wizard_Types=(\n";
    for (unsigned i = 0; i < ePortrait_MAX; ++i)
    {
        os << "[" << i << "] " << rhs.m_Wizard_Types[i] << ",\n";
    }
    os << ")\n";
    os << "m_Unk_2C1A=(\n";
    for (unsigned i = 0; i < 10; ++i)
    {
        os << "[" << i << "] " << rhs.m_Unk_2C1A[i] << " 0x" << std::hex << rhs.m_Unk_2C1A[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Nr_spell_choices=(\n";
    for (unsigned i = 0; i < 10; ++i)
    {
        os << "[" << i << "] " << rhs.m_Nr_spell_choices[i] << " 0x" << std::hex << rhs.m_Nr_spell_choices[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Unk_2C40=(\n";
    for (unsigned i = 0; i < 0x2C6A - 0x2C42; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_2C40[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_2C40[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Preselected_spell_choices=(\n";
    for (unsigned i = 0; i < 65; ++i)
    {
        os << "[" << i << "] " << rhs.m_Preselected_spell_choices[i] << ",\n";
    }
    os << ")\n";
    os << "m_Unk_2CEC=(\n";
    for (unsigned i = 0; i < 0x3067 - 0x2CEC; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_2CEC[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_2CEC[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Copyright1_and_Version=" << formatCharArray(rhs.m_Copyright1_and_Version, 41) << "\n";
    os << "m_Unk_3090=(\n";
    for (unsigned i = 0; i < 0x35D0 - 0x3090; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_3090[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_3090[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Hero_Stats_Initializers=(\n";
    for (unsigned i = 0; i < gMAX_HERO_TYPES; ++i)
    {
        os << "[" << i << "] " << rhs.m_Hero_Stats_Initializers[i] << ",\n";
    }
    os << ")\n";
    os << "m_Unk_3846=(\n";
    for (unsigned i = 0; i < 0x389A - 0x3846; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_3846[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_3846[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Copyright2_and_Version=" << formatCharArray(rhs.m_Copyright2_and_Version, 41) << "\n";
    os << "m_Unk_38C3=(\n";
    for (unsigned i = 0; i < 0x3CB8 - 0x38C3; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_38C3[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_38C3[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_BIOS_clock_snapshot=" << rhs.m_BIOS_clock_snapshot << " 0x" << std::hex << rhs.m_BIOS_clock_snapshot << std::dec << "\n";
    os << "m_Unk_3CBC=(\n";
    for (unsigned i = 0; i < 0x40E4 - 0x3CBC; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_3CBC[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_3CBC[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_EMS_data_reference_point=" << rhs.m_EMS_data_reference_point << " 0x" << std::hex << rhs.m_EMS_data_reference_point << std::dec << "\n";
    os << "m_Unk_40E6=(\n";
    for (unsigned i = 0; i < 0x431E - 0x40E6; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_40E6[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_40E6[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_RNG_seed_lo=" << rhs.m_RNG_seed_lo << " 0x" << std::hex << rhs.m_RNG_seed_lo << std::dec << "\n";
    os << "m_RNG_seed_hi=" << rhs.m_RNG_seed_hi << " 0x" << std::hex << rhs.m_RNG_seed_hi << std::dec << "\n";
    os << "m_Unk_4322=(\n";
    for (unsigned i = 0; i < 0x434E - 0x4322; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_4322[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_4322[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_DEBUG_Off=" << rhs.m_DEBUG_Off << " 0x" << std::hex << rhs.m_DEBUG_Off << std::dec << "\n";
    os << "m_Unk_4350=(\n";
    for (unsigned i = 0; i < 0x4D44 - 0x4350; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_4350[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_4350[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Want_input_GUESS=" << rhs.m_Want_input_GUESS << " 0x" << std::hex << rhs.m_Want_input_GUESS << std::dec << "\n";
    os << "m_Unk_4D46=(\n";
    for (unsigned i = 0; i < 0x6900 - 0x4D46; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_4D46[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_4D46[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Wizards=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << rhs.m_Wizards[i] << ",\n";
    }
    os << ")\n";
    os << "m_Spells_selected_of_Realm=(\n";
    for (unsigned i = 0; i < 150; ++i)
    {
        os << "[" << i << "] " << rhs.m_Spells_selected_of_Realm[i] << ",\n";
    }
    os << ")\n";
    os << "m_Unk_86DC=(\n";
    for (unsigned i = 0; i < 0x87C4 - 0x86DC; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_86DC[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_86DC[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Game_Data=" << rhs.m_Game_Data << "\n";
    os << "m_Game_Settings=" << rhs.m_Game_Settings << "\n";
    os << "m_Unk_89A6=(\n";
    for (unsigned i = 0; i < 0x8A14 - 0x89A6; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_89A6[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_89A6[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Spell_Selected=(\n";
    for (unsigned i = 0; i < eSpell_MAX; ++i)
    {
        os << "[" << i << "] " << rhs.m_Spell_Selected[i] << ",\n";
    }
    os << ")\n";
    os << "m_Unk_8AEB=(\n";
    for (unsigned i = 0; i < 0x8D52 - 0x8AEB; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_8AEB[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_8AEB[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Spells_Known_Realm=(\n";
    for (unsigned i = 0; i < 66; ++i)
    {
        os << "[" << i << "] " << rhs.m_Spells_Known_Realm[i] << " 0x" << std::hex << rhs.m_Spells_Known_Realm[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Unk_8DD6=" << rhs.m_Unk_8DD6 << " 0x" << std::hex << rhs.m_Unk_8DD6 << std::dec << "\n";
    os << "m_Sorcery_Picks_Divider=" << rhs.m_Sorcery_Picks_Divider << " 0x" << std::hex << rhs.m_Sorcery_Picks_Divider << std::dec << "\n";
    os << "m_Nature_Picks_Divider=" << rhs.m_Nature_Picks_Divider << " 0x" << std::hex << rhs.m_Nature_Picks_Divider << std::dec << "\n";
    os << "m_Chaos_Picks_Divider=" << rhs.m_Chaos_Picks_Divider << " 0x" << std::hex << rhs.m_Chaos_Picks_Divider << std::dec << "\n";
    os << "m_Death_Picks_Divider=" << rhs.m_Death_Picks_Divider << " 0x" << std::hex << rhs.m_Death_Picks_Divider << std::dec << "\n";
    os << "m_Life_Picks_Divider=" << rhs.m_Life_Picks_Divider << " 0x" << std::hex << rhs.m_Life_Picks_Divider << std::dec << "\n";
    os << "m_Unk_8DE2=(\n";
    for (unsigned i = 0; i < 2; ++i)
    {
        os << "[" << i << "] " << rhs.m_Unk_8DE2[i] << " 0x" << std::hex << rhs.m_Unk_8DE2[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Spells_Known_Realm_Indexed=(\n";
    for (unsigned i = 0; i < 15; ++i)
    {
        os << "[" << i << "] " << rhs.m_Spells_Known_Realm_Indexed[i] << " 0x" << std::hex << rhs.m_Spells_Known_Realm_Indexed[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Unk_8E04=(\n";
    for (unsigned i = 0; i < 0x8E0C - 0x8E04; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_8E04[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_8E04[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Button_IDs=(\n";
    for (unsigned i = 0; i < 30; ++i)
    {
        os << "[" << i << "] " << rhs.m_Button_IDs[i] << " 0x" << std::hex << rhs.m_Button_IDs[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Wizard_portrait_shown=" << rhs.m_Wizard_portrait_shown << "\n";
    os << "m_Unk_8E49=(\n";
    for (unsigned i = 0; i < 0x8E92 - 0x8E49; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_8E49[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_8E49[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Button_OK_ID=" << rhs.m_Button_OK_ID << " 0x" << std::hex << rhs.m_Button_OK_ID << std::dec << "\n";
    os << "m_Total_Picks_Left=" << rhs.m_Total_Picks_Left << " 0x" << std::hex << rhs.m_Total_Picks_Left << std::dec << "\n";
    os << "m_Unk_8E96=(\n";
    for (unsigned i = 0; i < 0xA8A2 - 0x8E96; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_8E96[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_8E96[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_addr_ClickableArea=" << rhs.m_addr_ClickableArea << "\n";
    os << "m_Unk_A8A6=(\n";
    for (unsigned i = 0; i < 0xAA4A - 0xA8A6; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_A8A6[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_A8A6[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Unk_AA4A=(\n";
    for (unsigned i = 0; i < 0xFE68 - 0xAA4A; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_AA4A[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_AA4A[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Wizards_Name_Shown_1=" << formatCharArray(rhs.m_Wizards_Name_Shown_1, 11) << "\n";
    os << "m_Unk_FE73=(\n";
    for (unsigned i = 0; i < 0xFEC2 - 0xFE73; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_FE73[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_FE73[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Wizards_Name_Shown_2=" << formatCharArray(rhs.m_Wizards_Name_Shown_2, 11) << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const MoMPaletteInfoLbx& rhs)
{
    os << "{\n";
    os << "paletteOffset=" << rhs.paletteOffset << " 0x" << std::hex << rhs.paletteOffset << std::dec << "\n";
    os << "firstPaletteColorIndex=" << rhs.firstPaletteColorIndex << " 0x" << std::hex << rhs.firstPaletteColorIndex << std::dec << "\n";
    os << "paletteColorCount=" << rhs.paletteColorCount << " 0x" << std::hex << rhs.paletteColorCount << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Movement_Flags& rhs)
{
    os << "{\n";
    if (0 != rhs.Cavalry)
    {
    os << "Cavalry=" << (unsigned)rhs.Cavalry << "\n";
    }
    if (0 != rhs.Sailing)
    {
    os << "Sailing=" << (unsigned)rhs.Sailing << "\n";
    }
    if (0 != rhs.Swimming)
    {
    os << "Swimming=" << (unsigned)rhs.Swimming << "\n";
    }
    if (0 != rhs.Flying)
    {
    os << "Flying=" << (unsigned)rhs.Flying << "\n";
    }
    if (0 != rhs.Teleporting)
    {
    os << "Teleporting=" << (unsigned)rhs.Teleporting << "\n";
    }
    if (0 != rhs.Forester)
    {
    os << "Forester=" << (unsigned)rhs.Forester << "\n";
    }
    if (0 != rhs.Mountaineer)
    {
    os << "Mountaineer=" << (unsigned)rhs.Mountaineer << "\n";
    }
    if (0 != rhs.Merging)
    {
    os << "Merging=" << (unsigned)rhs.Merging << "\n";
    }
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Node_Attr& rhs)
{
    os << "{\n";
    os << "m_XPos=" << (int)rhs.m_XPos << " 0x" << std::hex << (int)rhs.m_XPos << std::dec << "\n";
    os << "m_YPos=" << (int)rhs.m_YPos << " 0x" << std::hex << (int)rhs.m_YPos << std::dec << "\n";
    os << "m_Plane=" << rhs.m_Plane << "\n";
    os << "m_Owner=" << rhs.m_Owner << "\n";
    os << "m_Power_Node=" << (int)rhs.m_Power_Node << " 0x" << std::hex << (int)rhs.m_Power_Node << std::dec << "\n";
    os << "m_XPos_Mana=(\n";
    for (unsigned i = 0; i < 20; ++i)
    {
        os << "[" << i << "] " << (int)rhs.m_XPos_Mana[i] << " 0x" << std::hex << (int)rhs.m_XPos_Mana[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_YPos_Mana=(\n";
    for (unsigned i = 0; i < 20; ++i)
    {
        os << "[" << i << "] " << (int)rhs.m_YPos_Mana[i] << " 0x" << std::hex << (int)rhs.m_YPos_Mana[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Node_Type=" << rhs.m_Node_Type << "\n";
    os << "m_Status=" << (unsigned)rhs.m_Status << " 0x" << std::hex << (unsigned)rhs.m_Status << std::dec << "\n";
    os << "m_Unk_2F=" << (unsigned)rhs.m_Unk_2F << " 0x" << std::hex << (unsigned)rhs.m_Unk_2F << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Race_Data& rhs)
{
    os << "{\n";
    os << "m_PtrName=" << rhs.m_PtrName << " 0x" << std::hex << rhs.m_PtrName << std::dec << "\n";
    os << "m_Number_of_prohibited_buildings=" << rhs.m_Number_of_prohibited_buildings << " 0x" << std::hex << rhs.m_Number_of_prohibited_buildings << std::dec << "\n";
    os << "m_Prohibited_buildings=(\n";
    for (unsigned i = 0; i < 7; ++i)
    {
        os << "[" << i << "] " << rhs.m_Prohibited_buildings[i] << ",\n";
    }
    os << ")\n";
    os << "m_Outpost_growth_probability=" << rhs.m_Outpost_growth_probability << " 0x" << std::hex << rhs.m_Outpost_growth_probability << std::dec << "\n";
    os << "m_City_population_growth_modifier=" << rhs.m_City_population_growth_modifier << " 0x" << std::hex << rhs.m_City_population_growth_modifier << std::dec << "\n";
    os << "m_Housing_picture=" << rhs.m_Housing_picture << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const SaveGame& rhs)
{
    os << "{\n";
    os << "m_List_Hero_stats=(\n";
    for (unsigned i = 0; i < gMAX_WIZARD_RECORDS; ++i)
    {
        os << "[" << i << "] " << rhs.m_List_Hero_stats[i] << ",\n";
    }
    os << ")\n";
    os << "m_Game_Data=" << rhs.m_Game_Data << "\n";
    os << "m_Wizards=(\n";
    for (unsigned i = 0; i < gMAX_WIZARD_RECORDS; ++i)
    {
        os << "[" << i << "] " << rhs.m_Wizards[i] << ",\n";
    }
    os << ")\n";
    os << "m_Arcanus_Map_Row=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << rhs.m_Arcanus_Map_Row[i] << ",\n";
    }
    os << ")\n";
    os << "m_Myrror_Map_Row=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << rhs.m_Myrror_Map_Row[i] << ",\n";
    }
    os << ")\n";
    os << "m_Arcanus_UNK01=(\n";
    for (unsigned i = 0; i < 0x60; ++i)
    {
        os << "[" << i << "] " << rhs.m_Arcanus_UNK01[i] << " 0x" << std::hex << rhs.m_Arcanus_UNK01[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Myrror_UNK01=(\n";
    for (unsigned i = 0; i < 0x60; ++i)
    {
        os << "[" << i << "] " << rhs.m_Myrror_UNK01[i] << " 0x" << std::hex << rhs.m_Myrror_UNK01[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Arcanus_LandMassID_Row=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << rhs.m_Arcanus_LandMassID_Row[i] << ",\n";
    }
    os << ")\n";
    os << "m_Myrror_LandMassID_Row=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << rhs.m_Myrror_LandMassID_Row[i] << ",\n";
    }
    os << ")\n";
    os << "m_Arcanus_Node_Attr=(\n";
    for (unsigned i = 0; i < 16; ++i)
    {
        os << "[" << i << "] " << rhs.m_Arcanus_Node_Attr[i] << ",\n";
    }
    os << ")\n";
    os << "m_Myrror_Node_Attr=(\n";
    for (unsigned i = 0; i < 14; ++i)
    {
        os << "[" << i << "] " << rhs.m_Myrror_Node_Attr[i] << ",\n";
    }
    os << ")\n";
    os << "m_Fortresses=(\n";
    for (unsigned i = 0; i < gMAX_WIZARD_RECORDS; ++i)
    {
        os << "[" << i << "] " << rhs.m_Fortresses[i] << ",\n";
    }
    os << ")\n";
    os << "m_Tower_Attr=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << rhs.m_Tower_Attr[i] << ",\n";
    }
    os << ")\n";
    os << "m_Arcanus_Towers=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << rhs.m_Arcanus_Towers[i] << ",\n";
    }
    os << ")\n";
    os << "m_Myrror_Towers=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << rhs.m_Myrror_Towers[i] << ",\n";
    }
    os << ")\n";
    os << "m_Arcanus_Nodes=(\n";
    for (unsigned i = 0; i < 16; ++i)
    {
        os << "[" << i << "] " << rhs.m_Arcanus_Nodes[i] << ",\n";
    }
    os << ")\n";
    os << "m_Myrror_Nodes=(\n";
    for (unsigned i = 0; i < 14; ++i)
    {
        os << "[" << i << "] " << rhs.m_Myrror_Nodes[i] << ",\n";
    }
    os << ")\n";
    os << "m_Normal_Lairs=(\n";
    for (unsigned i = 0; i < 25; ++i)
    {
        os << "[" << i << "] " << rhs.m_Normal_Lairs[i] << ",\n";
    }
    os << ")\n";
    os << "m_Weak_Lairs=(\n";
    for (unsigned i = 0; i < 32; ++i)
    {
        os << "[" << i << "] " << rhs.m_Weak_Lairs[i] << ",\n";
    }
    os << ")\n";
    os << "m_ExtraLairs_GUESS=(\n";
    for (unsigned i = 0; i < 3; ++i)
    {
        os << "[" << i << "] " << rhs.m_ExtraLairs_GUESS[i] << ",\n";
    }
    os << ")\n";
    os << "m_Items=(\n";
    for (unsigned i = 0; i < 128; ++i)
    {
        os << "[" << i << "] " << rhs.m_Items[i] << ",\n";
    }
    os << ")\n";
    os << "m_Item_Trashcan_GUESS=(\n";
    for (unsigned i = 0; i < 8; ++i)
    {
        os << "[" << i << "] " << rhs.m_Item_Trashcan_GUESS[i] << ",\n";
    }
    os << ")\n";
    os << "m_Item_Found=" << rhs.m_Item_Found << "\n";
    os << "m_Item_Created=" << rhs.m_Item_Created << "\n";
    os << "m_Cities=(\n";
    for (unsigned i = 0; i < gMAX_CITIES; ++i)
    {
        os << "[" << i << "] " << rhs.m_Cities[i] << ",\n";
    }
    os << ")\n";
    os << "m_Unit=(\n";
    for (unsigned i = 0; i < 1000; ++i)
    {
        os << "[" << i << "] " << rhs.m_Unit[i] << ",\n";
    }
    os << ")\n";
    os << "m_Units_Trashcan_GUESS=(\n";
    for (unsigned i = 0; i < 9; ++i)
    {
        os << "[" << i << "] " << rhs.m_Units_Trashcan_GUESS[i] << ",\n";
    }
    os << ")\n";
    os << "m_Arcanus_Bonus_Row=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << rhs.m_Arcanus_Bonus_Row[i] << ",\n";
    }
    os << ")\n";
    os << "m_Myrror_Bonus_Row=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << rhs.m_Myrror_Bonus_Row[i] << ",\n";
    }
    os << ")\n";
    os << "m_Arcanus_Exploration_Row=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << rhs.m_Arcanus_Exploration_Row[i] << ",\n";
    }
    os << ")\n";
    os << "m_Myrror_Exploration_Row=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << rhs.m_Myrror_Exploration_Row[i] << ",\n";
    }
    os << ")\n";
    os << "m_Arcanus_Movement=" << rhs.m_Arcanus_Movement << "\n";
    os << "m_Myrror_Movement=" << rhs.m_Myrror_Movement << "\n";
    os << "m_Events_Status=" << rhs.m_Events_Status << "\n";
    os << "m_Arcanus_Terrain_Changes_Row=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << rhs.m_Arcanus_Terrain_Changes_Row[i] << ",\n";
    }
    os << ")\n";
    os << "m_Myrror_Terrain_Changes_Row=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << rhs.m_Myrror_Terrain_Changes_Row[i] << ",\n";
    }
    os << ")\n";
    os << "m_Grand_Vizier=" << rhs.m_Grand_Vizier << "\n";
    os << "m_Artifacts_in_Game=(\n";
    for (unsigned i = 0; i < gMAX_ARTIFACTS_IN_GAME; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Artifacts_in_Game[i] << " 0x" << std::hex << (unsigned)rhs.m_Artifacts_in_Game[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Chosen_Hero_Names=(\n";
    for (unsigned i = 0; i < gMAX_HERO_TYPES; ++i)
    {
        os << "[" << i << "] " << rhs.m_Chosen_Hero_Names[i] << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Skills& rhs)
{
    os << "{\n";
    os << "Alchemy=" << rhs.Alchemy << "\n";
    os << "Warlord=" << rhs.Warlord << "\n";
    os << "Chaos_Master=" << rhs.Chaos_Master << "\n";
    os << "Nature_Master=" << rhs.Nature_Master << "\n";
    os << "Sorcery_Master=" << rhs.Sorcery_Master << "\n";
    os << "Infernal_Power=" << rhs.Infernal_Power << "\n";
    os << "Divine_Power=" << rhs.Divine_Power << "\n";
    os << "Sage_Master=" << rhs.Sage_Master << "\n";
    os << "Channeller=" << rhs.Channeller << "\n";
    os << "Myrran=" << rhs.Myrran << "\n";
    os << "Archmage=" << rhs.Archmage << "\n";
    os << "Mana_Focusing=" << rhs.Mana_Focusing << "\n";
    os << "Node_Mastery=" << rhs.Node_Mastery << "\n";
    os << "Famous=" << rhs.Famous << "\n";
    os << "Runemaster=" << rhs.Runemaster << "\n";
    os << "Conjurer=" << rhs.Conjurer << "\n";
    os << "Charismatic=" << rhs.Charismatic << "\n";
    os << "Artificer=" << rhs.Artificer << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Spell_Data& rhs)
{
    os << "{\n";
    os << "m_SpellName=" << formatCharArray(rhs.m_SpellName, 19) << "\n";
    os << "m_Spell_desirability=" << rhs.m_Spell_desirability << " 0x" << std::hex << rhs.m_Spell_desirability << std::dec << "\n";
    os << "m_Spell_Category=" << rhs.m_Spell_Category << "\n";
    os << "m_Section_in_spell_book=" << rhs.m_Section_in_spell_book << "\n";
    os << "m_Magic_Realm=" << rhs.m_Magic_Realm << "\n";
    os << "m_Casting_eligibility=" << (int)rhs.m_Casting_eligibility << " 0x" << std::hex << (int)rhs.m_Casting_eligibility << std::dec << "\n";
    os << "m_Unk_19=" << (int)rhs.m_Unk_19 << " 0x" << std::hex << (int)rhs.m_Unk_19 << std::dec << "\n";
    os << "m_Casting_cost=" << rhs.m_Casting_cost << " 0x" << std::hex << rhs.m_Casting_cost << std::dec << "\n";
    os << "m_Research_cost=" << rhs.m_Research_cost << " 0x" << std::hex << rhs.m_Research_cost << std::dec << "\n";
    os << "m_Sound_effect_when_casting_spell=" << rhs.m_Sound_effect_when_casting_spell << " 0x" << std::hex << rhs.m_Sound_effect_when_casting_spell << std::dec << "\n";
    os << "m_Parameters=(\n";
    for (unsigned i = 0; i < 4; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Parameters[i] << " 0x" << std::hex << (unsigned)rhs.m_Parameters[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Spells_Cast_in_Battle& rhs)
{
    os << "{\n";
    os << "True_Light=(\n";
    for (unsigned i = 0; i < 2; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.True_Light[i] << " 0x" << std::hex << (unsigned)rhs.True_Light[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "Darkness=(\n";
    for (unsigned i = 0; i < 2; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.Darkness[i] << " 0x" << std::hex << (unsigned)rhs.Darkness[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "Warp_Reality=(\n";
    for (unsigned i = 0; i < 2; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.Warp_Reality[i] << " 0x" << std::hex << (unsigned)rhs.Warp_Reality[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "Black_Prayer=(\n";
    for (unsigned i = 0; i < 2; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.Black_Prayer[i] << " 0x" << std::hex << (unsigned)rhs.Black_Prayer[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "Wrack=(\n";
    for (unsigned i = 0; i < 2; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.Wrack[i] << " 0x" << std::hex << (unsigned)rhs.Wrack[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "Metal_Fires=(\n";
    for (unsigned i = 0; i < 2; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.Metal_Fires[i] << " 0x" << std::hex << (unsigned)rhs.Metal_Fires[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "Prayer=(\n";
    for (unsigned i = 0; i < 2; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.Prayer[i] << " 0x" << std::hex << (unsigned)rhs.Prayer[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "High_Prayer=(\n";
    for (unsigned i = 0; i < 2; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.High_Prayer[i] << " 0x" << std::hex << (unsigned)rhs.High_Prayer[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "Terror=(\n";
    for (unsigned i = 0; i < 2; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.Terror[i] << " 0x" << std::hex << (unsigned)rhs.Terror[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "Call_Lightning=(\n";
    for (unsigned i = 0; i < 2; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.Call_Lightning[i] << " 0x" << std::hex << (unsigned)rhs.Call_Lightning[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "Counter_Magic=(\n";
    for (unsigned i = 0; i < 2; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.Counter_Magic[i] << " 0x" << std::hex << (unsigned)rhs.Counter_Magic[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "Mass_Invisibility=(\n";
    for (unsigned i = 0; i < 2; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.Mass_Invisibility[i] << " 0x" << std::hex << (unsigned)rhs.Mass_Invisibility[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "Entangle=(\n";
    for (unsigned i = 0; i < 2; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.Entangle[i] << " 0x" << std::hex << (unsigned)rhs.Entangle[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "Mana_Leak=(\n";
    for (unsigned i = 0; i < 2; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.Mana_Leak[i] << " 0x" << std::hex << (unsigned)rhs.Mana_Leak[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "Blur=(\n";
    for (unsigned i = 0; i < 2; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.Blur[i] << " 0x" << std::hex << (unsigned)rhs.Blur[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Spells_Known& rhs)
{
    os << "{\n";
    os << "No_spell=" << rhs.No_spell << "\n";
    os << "Earth_to_Mud=" << rhs.Earth_to_Mud << "\n";
    os << "Resist_Elements=" << rhs.Resist_Elements << "\n";
    os << "Wall_of_Stone=" << rhs.Wall_of_Stone << "\n";
    os << "Giant_Strength=" << rhs.Giant_Strength << "\n";
    os << "Web=" << rhs.Web << "\n";
    os << "War_Bears=" << rhs.War_Bears << "\n";
    os << "Stone_Skin=" << rhs.Stone_Skin << "\n";
    os << "Water_Walking=" << rhs.Water_Walking << "\n";
    os << "Sprites=" << rhs.Sprites << "\n";
    os << "Earth_Lore=" << rhs.Earth_Lore << "\n";
    os << "Cracks_Call=" << rhs.Cracks_Call << "\n";
    os << "Natures_eye=" << rhs.Natures_eye << "\n";
    os << "Ice_Bolt=" << rhs.Ice_Bolt << "\n";
    os << "Giant_Spiders=" << rhs.Giant_Spiders << "\n";
    os << "Change_Terrain=" << rhs.Change_Terrain << "\n";
    os << "Path_Finding=" << rhs.Path_Finding << "\n";
    os << "Cockatrices=" << rhs.Cockatrices << "\n";
    os << "Transmute=" << rhs.Transmute << "\n";
    os << "Natures_Cures=" << rhs.Natures_Cures << "\n";
    os << "Basilisk=" << rhs.Basilisk << "\n";
    os << "Elemental_Armor=" << rhs.Elemental_Armor << "\n";
    os << "Petrify=" << rhs.Petrify << "\n";
    os << "Stone_Giant=" << rhs.Stone_Giant << "\n";
    os << "Iron_Skin=" << rhs.Iron_Skin << "\n";
    os << "Ice_Storm=" << rhs.Ice_Storm << "\n";
    os << "Earthquake=" << rhs.Earthquake << "\n";
    os << "Gorgons=" << rhs.Gorgons << "\n";
    os << "Move_Fortress=" << rhs.Move_Fortress << "\n";
    os << "Gaias_Blessing=" << rhs.Gaias_Blessing << "\n";
    os << "Earth_Elemental=" << rhs.Earth_Elemental << "\n";
    os << "Regeneration=" << rhs.Regeneration << "\n";
    os << "Behemoth=" << rhs.Behemoth << "\n";
    os << "Entangle=" << rhs.Entangle << "\n";
    os << "Nature_Awareness=" << rhs.Nature_Awareness << "\n";
    os << "Call_Lightning=" << rhs.Call_Lightning << "\n";
    os << "Colossus=" << rhs.Colossus << "\n";
    os << "Earth_Gate=" << rhs.Earth_Gate << "\n";
    os << "Herb_Mastery=" << rhs.Herb_Mastery << "\n";
    os << "Great_Wyrm=" << rhs.Great_Wyrm << "\n";
    os << "Natures_Wrath=" << rhs.Natures_Wrath << "\n";
    os << "Resist_Magic=" << rhs.Resist_Magic << "\n";
    os << "Dispel_Magic_True=" << rhs.Dispel_Magic_True << "\n";
    os << "Floating_Island=" << rhs.Floating_Island << "\n";
    os << "Guardian_Wind=" << rhs.Guardian_Wind << "\n";
    os << "Phantom_Warriors=" << rhs.Phantom_Warriors << "\n";
    os << "Confusion=" << rhs.Confusion << "\n";
    os << "Word_of_Recall=" << rhs.Word_of_Recall << "\n";
    os << "Counter_Magic=" << rhs.Counter_Magic << "\n";
    os << "Nagas=" << rhs.Nagas << "\n";
    os << "Psionic_Blast=" << rhs.Psionic_Blast << "\n";
    os << "Blur=" << rhs.Blur << "\n";
    os << "Disenchant_True=" << rhs.Disenchant_True << "\n";
    os << "Vertigo=" << rhs.Vertigo << "\n";
    os << "Spell_Lock=" << rhs.Spell_Lock << "\n";
    os << "Enchant_Road=" << rhs.Enchant_Road << "\n";
    os << "Flight=" << rhs.Flight << "\n";
    os << "Wind_Mastery=" << rhs.Wind_Mastery << "\n";
    os << "Spell_Blast=" << rhs.Spell_Blast << "\n";
    os << "Aura_of_Majesty=" << rhs.Aura_of_Majesty << "\n";
    os << "Phantom_Beast=" << rhs.Phantom_Beast << "\n";
    os << "Disjunction_True=" << rhs.Disjunction_True << "\n";
    os << "Invisibility=" << rhs.Invisibility << "\n";
    os << "Wind_Walking=" << rhs.Wind_Walking << "\n";
    os << "Banish=" << rhs.Banish << "\n";
    os << "Storm_Giant=" << rhs.Storm_Giant << "\n";
    os << "Air_Elemental=" << rhs.Air_Elemental << "\n";
    os << "Mind_Storm=" << rhs.Mind_Storm << "\n";
    os << "Stasis=" << rhs.Stasis << "\n";
    os << "Magic_Immunity=" << rhs.Magic_Immunity << "\n";
    os << "Haste=" << rhs.Haste << "\n";
    os << "Djinn=" << rhs.Djinn << "\n";
    os << "Spell_Ward=" << rhs.Spell_Ward << "\n";
    os << "Creature_Binding=" << rhs.Creature_Binding << "\n";
    os << "Mass_Invisibility=" << rhs.Mass_Invisibility << "\n";
    os << "Great_Unsummoning=" << rhs.Great_Unsummoning << "\n";
    os << "Spell_Binding=" << rhs.Spell_Binding << "\n";
    os << "Flying_Fortress=" << rhs.Flying_Fortress << "\n";
    os << "Sky_Drake=" << rhs.Sky_Drake << "\n";
    os << "Suppress_Magic=" << rhs.Suppress_Magic << "\n";
    os << "Time_Stop=" << rhs.Time_Stop << "\n";
    os << "Warp_Wood=" << rhs.Warp_Wood << "\n";
    os << "Disrupt=" << rhs.Disrupt << "\n";
    os << "Fire_Bolt=" << rhs.Fire_Bolt << "\n";
    os << "Hell_Hounds=" << rhs.Hell_Hounds << "\n";
    os << "Corruption=" << rhs.Corruption << "\n";
    os << "Eldritch_Weapon=" << rhs.Eldritch_Weapon << "\n";
    os << "Wall_of_Fire=" << rhs.Wall_of_Fire << "\n";
    os << "Shatter=" << rhs.Shatter << "\n";
    os << "Warp_Creature=" << rhs.Warp_Creature << "\n";
    os << "Fire_Elemental=" << rhs.Fire_Elemental << "\n";
    os << "Lightning_Bolt=" << rhs.Lightning_Bolt << "\n";
    os << "Fire_Giant=" << rhs.Fire_Giant << "\n";
    os << "Chaos_Channels=" << rhs.Chaos_Channels << "\n";
    os << "Flame_Blade=" << rhs.Flame_Blade << "\n";
    os << "Gargoyles=" << rhs.Gargoyles << "\n";
    os << "Fireball=" << rhs.Fireball << "\n";
    os << "Doombat=" << rhs.Doombat << "\n";
    os << "Raise_Volcano=" << rhs.Raise_Volcano << "\n";
    os << "Immolation=" << rhs.Immolation << "\n";
    os << "Chimeras=" << rhs.Chimeras << "\n";
    os << "Warp_Lightning=" << rhs.Warp_Lightning << "\n";
    os << "Metal_Fires=" << rhs.Metal_Fires << "\n";
    os << "Chaos_Spawn=" << rhs.Chaos_Spawn << "\n";
    os << "Doom_Bolt=" << rhs.Doom_Bolt << "\n";
    os << "Magic_Vortex=" << rhs.Magic_Vortex << "\n";
    os << "Efreet=" << rhs.Efreet << "\n";
    os << "Fire_Storm=" << rhs.Fire_Storm << "\n";
    os << "Warp_Reality=" << rhs.Warp_Reality << "\n";
    os << "Flame_Strike=" << rhs.Flame_Strike << "\n";
    os << "Chaos_Rift=" << rhs.Chaos_Rift << "\n";
    os << "Hydra=" << rhs.Hydra << "\n";
    os << "Disintegrate=" << rhs.Disintegrate << "\n";
    os << "Meteor_Storm=" << rhs.Meteor_Storm << "\n";
    os << "Great_Wasting=" << rhs.Great_Wasting << "\n";
    os << "Call_Chaos=" << rhs.Call_Chaos << "\n";
    os << "Chaos_Surge=" << rhs.Chaos_Surge << "\n";
    os << "Doom_Mastery=" << rhs.Doom_Mastery << "\n";
    os << "Great_Drake=" << rhs.Great_Drake << "\n";
    os << "Call_The_Void=" << rhs.Call_The_Void << "\n";
    os << "Armageddon=" << rhs.Armageddon << "\n";
    os << "Bless=" << rhs.Bless << "\n";
    os << "Star_Fires=" << rhs.Star_Fires << "\n";
    os << "Endurance=" << rhs.Endurance << "\n";
    os << "Holy_Weapon=" << rhs.Holy_Weapon << "\n";
    os << "Healing=" << rhs.Healing << "\n";
    os << "Holy_Armor=" << rhs.Holy_Armor << "\n";
    os << "Just_Cause=" << rhs.Just_Cause << "\n";
    os << "True_Light=" << rhs.True_Light << "\n";
    os << "Guardian_Spirit=" << rhs.Guardian_Spirit << "\n";
    os << "Heroism=" << rhs.Heroism << "\n";
    os << "True_Sight=" << rhs.True_Sight << "\n";
    os << "Plane_Shift=" << rhs.Plane_Shift << "\n";
    os << "Resurrection=" << rhs.Resurrection << "\n";
    os << "Dispel_Evil=" << rhs.Dispel_Evil << "\n";
    os << "Planar_Seal=" << rhs.Planar_Seal << "\n";
    os << "Unicorns=" << rhs.Unicorns << "\n";
    os << "Raise_Dead=" << rhs.Raise_Dead << "\n";
    os << "Planar_Travel=" << rhs.Planar_Travel << "\n";
    os << "Heavenly_Light=" << rhs.Heavenly_Light << "\n";
    os << "Prayer=" << rhs.Prayer << "\n";
    os << "Lionheart=" << rhs.Lionheart << "\n";
    os << "Incarnation=" << rhs.Incarnation << "\n";
    os << "Invulnerability=" << rhs.Invulnerability << "\n";
    os << "Righteousness=" << rhs.Righteousness << "\n";
    os << "Prosperity=" << rhs.Prosperity << "\n";
    os << "Altar_of_Battle=" << rhs.Altar_of_Battle << "\n";
    os << "Angel=" << rhs.Angel << "\n";
    os << "Stream_of_Life=" << rhs.Stream_of_Life << "\n";
    os << "Mass_Healing=" << rhs.Mass_Healing << "\n";
    os << "Holy_Word=" << rhs.Holy_Word << "\n";
    os << "High_Prayer=" << rhs.High_Prayer << "\n";
    os << "Inspirations=" << rhs.Inspirations << "\n";
    os << "Astral_Gate=" << rhs.Astral_Gate << "\n";
    os << "Holy_Arms=" << rhs.Holy_Arms << "\n";
    os << "Consecration=" << rhs.Consecration << "\n";
    os << "Life_Force=" << rhs.Life_Force << "\n";
    os << "Tranquility=" << rhs.Tranquility << "\n";
    os << "Crusade=" << rhs.Crusade << "\n";
    os << "Arch_Angel=" << rhs.Arch_Angel << "\n";
    os << "Charm_of_Life=" << rhs.Charm_of_Life << "\n";
    os << "Skeletons=" << rhs.Skeletons << "\n";
    os << "Weakness=" << rhs.Weakness << "\n";
    os << "Dark_Rituals=" << rhs.Dark_Rituals << "\n";
    os << "Cloak_of_Fear=" << rhs.Cloak_of_Fear << "\n";
    os << "Black_Sleep=" << rhs.Black_Sleep << "\n";
    os << "Ghouls=" << rhs.Ghouls << "\n";
    os << "Life_Drain=" << rhs.Life_Drain << "\n";
    os << "Terror=" << rhs.Terror << "\n";
    os << "Darkness=" << rhs.Darkness << "\n";
    os << "Mana_Leak=" << rhs.Mana_Leak << "\n";
    os << "Drain_Power=" << rhs.Drain_Power << "\n";
    os << "Possession=" << rhs.Possession << "\n";
    os << "Lycantrophy=" << rhs.Lycantrophy << "\n";
    os << "Black_Prayer=" << rhs.Black_Prayer << "\n";
    os << "Black_Channels=" << rhs.Black_Channels << "\n";
    os << "Night_Stalker=" << rhs.Night_Stalker << "\n";
    os << "Subversion=" << rhs.Subversion << "\n";
    os << "Wall_of_Darkness=" << rhs.Wall_of_Darkness << "\n";
    os << "Berserk=" << rhs.Berserk << "\n";
    os << "Shadow_Demons=" << rhs.Shadow_Demons << "\n";
    os << "Wraith_Form=" << rhs.Wraith_Form << "\n";
    os << "Wrack=" << rhs.Wrack << "\n";
    os << "Evil_Presence=" << rhs.Evil_Presence << "\n";
    os << "Wraiths=" << rhs.Wraiths << "\n";
    os << "Cloud_of_Shadow=" << rhs.Cloud_of_Shadow << "\n";
    os << "Warp_Node=" << rhs.Warp_Node << "\n";
    os << "Black_Wind=" << rhs.Black_Wind << "\n";
    os << "Zombie_Mastery=" << rhs.Zombie_Mastery << "\n";
    os << "Famine=" << rhs.Famine << "\n";
    os << "Cursed_Lands=" << rhs.Cursed_Lands << "\n";
    os << "Cruel_Unminding=" << rhs.Cruel_Unminding << "\n";
    os << "Word_of_Death=" << rhs.Word_of_Death << "\n";
    os << "Death_Knights=" << rhs.Death_Knights << "\n";
    os << "Death_Spell=" << rhs.Death_Spell << "\n";
    os << "Animate_dead=" << rhs.Animate_dead << "\n";
    os << "Pestilence=" << rhs.Pestilence << "\n";
    os << "Eternal_Night=" << rhs.Eternal_Night << "\n";
    os << "Evil_Omens=" << rhs.Evil_Omens << "\n";
    os << "Death_Wish=" << rhs.Death_Wish << "\n";
    os << "Demon_Lord=" << rhs.Demon_Lord << "\n";
    os << "Magic_Spirit=" << rhs.Magic_Spirit << "\n";
    os << "Dispel_Magic=" << rhs.Dispel_Magic << "\n";
    os << "Summoning_Circle=" << rhs.Summoning_Circle << "\n";
    os << "Disenchant_Area=" << rhs.Disenchant_Area << "\n";
    os << "Recall_Hero=" << rhs.Recall_Hero << "\n";
    os << "Detect_Magic=" << rhs.Detect_Magic << "\n";
    os << "Enchant_Item=" << rhs.Enchant_Item << "\n";
    os << "Summon_Hero=" << rhs.Summon_Hero << "\n";
    os << "Awareness=" << rhs.Awareness << "\n";
    os << "Disjunction=" << rhs.Disjunction << "\n";
    os << "Create_Artifact=" << rhs.Create_Artifact << "\n";
    os << "Summon_Champion=" << rhs.Summon_Champion << "\n";
    os << "Spell_Of_Mastery=" << rhs.Spell_Of_Mastery << "\n";
    os << "Spell_Of_Return=" << rhs.Spell_Of_Return << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Terrain_Changes& rhs)
{
    os << "{\n";
    if (0 != rhs.Volcano_producing_for_Owner)
    {
    os << "Volcano_producing_for_Owner=" << (unsigned)rhs.Volcano_producing_for_Owner << "\n";
    }
    if (0 != rhs.road)
    {
    os << "road=" << (unsigned)rhs.road << "\n";
    }
    if (0 != rhs.enchanted_road)
    {
    os << "enchanted_road=" << (unsigned)rhs.enchanted_road << "\n";
    }
    if (0 != rhs.corruption)
    {
    os << "corruption=" << (unsigned)rhs.corruption << "\n";
    }
    if (0 != rhs.unknown40)
    {
    os << "unknown40=" << (unsigned)rhs.unknown40 << "\n";
    }
    if (0 != rhs.no_road80)
    {
    os << "no_road80=" << (unsigned)rhs.no_road80 << "\n";
    }
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Tower_Attr& rhs)
{
    os << "{\n";
    os << "m_XPos=" << (int)rhs.m_XPos << " 0x" << std::hex << (int)rhs.m_XPos << std::dec << "\n";
    os << "m_YPos=" << (int)rhs.m_YPos << " 0x" << std::hex << (int)rhs.m_YPos << std::dec << "\n";
    os << "m_Closed=" << (unsigned)rhs.m_Closed << " 0x" << std::hex << (unsigned)rhs.m_Closed << std::dec << "\n";
    os << "m_Unk_03=" << (unsigned)rhs.m_Unk_03 << " 0x" << std::hex << (unsigned)rhs.m_Unk_03 << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Tower_Node_Lair& rhs)
{
    os << "{\n";
    os << "m_XPos=" << (unsigned)rhs.m_XPos << " 0x" << std::hex << (unsigned)rhs.m_XPos << std::dec << "\n";
    os << "m_YPos=" << (unsigned)rhs.m_YPos << " 0x" << std::hex << (unsigned)rhs.m_YPos << std::dec << "\n";
    os << "m_Plane=" << rhs.m_Plane << "\n";
    os << "m_Status=" << rhs.m_Status << "\n";
    os << "m_Type=" << rhs.m_Type << "\n";
    os << "m_Inhabitant1=" << rhs.m_Inhabitant1 << "\n";
    os << "m_Inhabitant2=" << rhs.m_Inhabitant2 << "\n";
    os << "m_Unk_09=" << (unsigned)rhs.m_Unk_09 << " 0x" << std::hex << (unsigned)rhs.m_Unk_09 << std::dec << "\n";
    os << "m_Reward_Gold=" << rhs.m_Reward_Gold << " 0x" << std::hex << rhs.m_Reward_Gold << std::dec << "\n";
    os << "m_Reward_Mana=" << rhs.m_Reward_Mana << " 0x" << std::hex << rhs.m_Reward_Mana << std::dec << "\n";
    os << "m_Reward_Specials=" << rhs.m_Reward_Specials << "\n";
    os << "m_Flags=" << rhs.m_Flags << "\n";
    os << "m_Item_Rewards=" << rhs.m_Item_Rewards << " 0x" << std::hex << rhs.m_Item_Rewards << std::dec << "\n";
    os << "m_Item_Value=(\n";
    for (unsigned i = 0; i < 3; ++i)
    {
        os << "[" << i << "] " << rhs.m_Item_Value[i] << " 0x" << std::hex << rhs.m_Item_Value[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Tower_Node_Lair_Flags& rhs)
{
    os << "{\n";
    if (0 != rhs.m_Prisoner)
    {
    os << "m_Prisoner=" << (unsigned)rhs.m_Prisoner << "\n";
    }
    if (0 != rhs.m_YOU_aware_Inhabitant1)
    {
    os << "m_YOU_aware_Inhabitant1=" << (unsigned)rhs.m_YOU_aware_Inhabitant1 << "\n";
    }
    if (0 != rhs.m_YOU_aware_Inhabitant2)
    {
    os << "m_YOU_aware_Inhabitant2=" << (unsigned)rhs.m_YOU_aware_Inhabitant2 << "\n";
    }
    if (0 != rhs.m_Zero)
    {
    os << "m_Zero=" << (unsigned)rhs.m_Zero << "\n";
    }
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Unit& rhs)
{
    os << "{\n";
    os << "m_XPos=" << (int)rhs.m_XPos << " 0x" << std::hex << (int)rhs.m_XPos << std::dec << "\n";
    os << "m_YPos=" << (int)rhs.m_YPos << " 0x" << std::hex << (int)rhs.m_YPos << std::dec << "\n";
    os << "m_Plane=" << rhs.m_Plane << "\n";
    os << "m_Owner=" << rhs.m_Owner << "\n";
    os << "m_Moves_Total=" << (int)rhs.m_Moves_Total << " 0x" << std::hex << (int)rhs.m_Moves_Total << std::dec << "\n";
    os << "m_Unit_Type=" << rhs.m_Unit_Type << "\n";
    os << "m_Hero_Slot_Number=" << (int)rhs.m_Hero_Slot_Number << " 0x" << std::hex << (int)rhs.m_Hero_Slot_Number << std::dec << "\n";
    os << "m_Active=" << rhs.m_Active << "\n";
    os << "m_Moves_Left=" << (int)rhs.m_Moves_Left << " 0x" << std::hex << (int)rhs.m_Moves_Left << std::dec << "\n";
    os << "m_XPos_of_destination=" << (int)rhs.m_XPos_of_destination << " 0x" << std::hex << (int)rhs.m_XPos_of_destination << std::dec << "\n";
    os << "m_YPos_of_destination=" << (int)rhs.m_YPos_of_destination << " 0x" << std::hex << (int)rhs.m_YPos_of_destination << std::dec << "\n";
    os << "m_Status=" << rhs.m_Status << "\n";
    os << "m_Level=" << rhs.m_Level << "\n";
    os << "m_Unk_0D=" << (int)rhs.m_Unk_0D << " 0x" << std::hex << (int)rhs.m_Unk_0D << std::dec << "\n";
    os << "m_Experience=" << rhs.m_Experience << " 0x" << std::hex << rhs.m_Experience << std::dec << "\n";
    os << "m_Unk_10=" << (int)rhs.m_Unk_10 << " 0x" << std::hex << (int)rhs.m_Unk_10 << std::dec << "\n";
    os << "m_Damage=" << (int)rhs.m_Damage << " 0x" << std::hex << (int)rhs.m_Damage << std::dec << "\n";
    os << "m_Grouping=" << (int)rhs.m_Grouping << " 0x" << std::hex << (int)rhs.m_Grouping << std::dec << "\n";
    os << "m_Guess_Combat_Enchantment_Flag1=" << (int)rhs.m_Guess_Combat_Enchantment_Flag1 << " 0x" << std::hex << (int)rhs.m_Guess_Combat_Enchantment_Flag1 << std::dec << "\n";
    os << "m_In_Tower_without_Seal=" << (int)rhs.m_In_Tower_without_Seal << " 0x" << std::hex << (int)rhs.m_In_Tower_without_Seal << std::dec << "\n";
    os << "m_Guess_Combat_Enchantment_Flag3=" << (int)rhs.m_Guess_Combat_Enchantment_Flag3 << " 0x" << std::hex << (int)rhs.m_Guess_Combat_Enchantment_Flag3 << std::dec << "\n";
    os << "m_Scouting=" << (int)rhs.m_Scouting << " 0x" << std::hex << (int)rhs.m_Scouting << std::dec << "\n";
    os << "m_Weapon_Mutation=" << rhs.m_Weapon_Mutation << "\n";
    os << "m_Unit_Enchantment=" << rhs.m_Unit_Enchantment << "\n";
    os << "m_Road_Building_left_to_complete=" << (int)rhs.m_Road_Building_left_to_complete << " 0x" << std::hex << (int)rhs.m_Road_Building_left_to_complete << std::dec << "\n";
    os << "m_XPos_Road_Building_from=" << (int)rhs.m_XPos_Road_Building_from << " 0x" << std::hex << (int)rhs.m_XPos_Road_Building_from << std::dec << "\n";
    os << "m_YPos_Road_Building_from=" << (int)rhs.m_YPos_Road_Building_from << " 0x" << std::hex << (int)rhs.m_YPos_Road_Building_from << std::dec << "\n";
    os << "m_Unk_1F=" << (int)rhs.m_Unk_1F << " 0x" << std::hex << (int)rhs.m_Unk_1F << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const UnitView_HeroAbility& rhs)
{
    os << "{\n";
    os << "m_bitmask=" << rhs.m_bitmask << " 0x" << std::hex << rhs.m_bitmask << std::dec << "\n";
    os << "m_lbxIndex=" << rhs.m_lbxIndex << " 0x" << std::hex << rhs.m_lbxIndex << std::dec << "\n";
    os << "m_helpIndex=" << rhs.m_helpIndex << " 0x" << std::hex << rhs.m_helpIndex << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const UnitView_ItemText& rhs)
{
    os << "{\n";
    os << "m_offset_label=" << rhs.m_offset_label << " 0x" << std::hex << rhs.m_offset_label << std::dec << "\n";
    os << "m_offset_helpText=" << rhs.m_offset_helpText << " 0x" << std::hex << rhs.m_offset_helpText << std::dec << "\n";
    os << "m_bitmask=" << rhs.m_bitmask << " 0x" << std::hex << rhs.m_bitmask << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const UnitView_Line& rhs)
{
    os << "{\n";
    os << "m_Line=" << formatCharArray(rhs.m_Line, 30) << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const UnitView_Lines& rhs)
{
    os << "{\n";
    os << "m_lines=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << rhs.m_lines[i] << ",\n";
    }
    os << ")\n";
    os << "m_bitmask_unitenchantment=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << rhs.m_bitmask_unitenchantment[i] << " 0x" << std::hex << rhs.m_bitmask_unitenchantment[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_icon_pic=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << rhs.m_icon_pic[i] << " 0x" << std::hex << rhs.m_icon_pic[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_helpIndex=(\n";
    for (unsigned i = 0; i < 40; ++i)
    {
        os << "[" << i << "] " << rhs.m_helpIndex[i] << " 0x" << std::hex << rhs.m_helpIndex[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const UnitView_Mutation& rhs)
{
    os << "{\n";
    os << "m_offset_label=" << rhs.m_offset_label << " 0x" << std::hex << rhs.m_offset_label << std::dec << "\n";
    os << "m_bitmask=" << (unsigned)rhs.m_bitmask << " 0x" << std::hex << (unsigned)rhs.m_bitmask << std::dec << "\n";
    os << "m_lbxIndex=" << (int)rhs.m_lbxIndex << " 0x" << std::hex << (int)rhs.m_lbxIndex << std::dec << "\n";
    os << "m_helpIndex=" << rhs.m_helpIndex << " 0x" << std::hex << rhs.m_helpIndex << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const UnitView_Ranged& rhs)
{
    os << "{\n";
    os << "m_offset_label=" << rhs.m_offset_label << " 0x" << std::hex << rhs.m_offset_label << std::dec << "\n";
    os << "m_rangedType=" << rhs.m_rangedType << "\n";
    os << "m_lbxIndex=" << (int)rhs.m_lbxIndex << " 0x" << std::hex << (int)rhs.m_lbxIndex << std::dec << "\n";
    os << "m_helpIndex=" << rhs.m_helpIndex << " 0x" << std::hex << rhs.m_helpIndex << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const UnitView_SpellData& rhs)
{
    os << "{\n";
    os << "m_offset_label=" << rhs.m_offset_label << " 0x" << std::hex << rhs.m_offset_label << std::dec << "\n";
    os << "m_bitmask=" << rhs.m_bitmask << " 0x" << std::hex << rhs.m_bitmask << std::dec << "\n";
    os << "m_lbxIndex=" << rhs.m_lbxIndex << " 0x" << std::hex << rhs.m_lbxIndex << std::dec << "\n";
    os << "m_helpIndex=" << rhs.m_helpIndex << " 0x" << std::hex << rhs.m_helpIndex << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const UnitView_UnitData& rhs)
{
    os << "{\n";
    os << "m_offset_label=" << rhs.m_offset_label << " 0x" << std::hex << rhs.m_offset_label << std::dec << "\n";
    os << "m_bitmask=" << rhs.m_bitmask << " 0x" << std::hex << rhs.m_bitmask << std::dec << "\n";
    os << "m_lbxIndex=" << rhs.m_lbxIndex << " 0x" << std::hex << rhs.m_lbxIndex << std::dec << "\n";
    os << "m_helpIndex=" << rhs.m_helpIndex << " 0x" << std::hex << rhs.m_helpIndex << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Unit_Data_Hero_Types& rhs)
{
    os << "{\n";
    os << "Dwarf=" << rhs.Dwarf << "\n";
    os << "Barbarian=" << rhs.Barbarian << "\n";
    os << "Sage=" << rhs.Sage << "\n";
    os << "Dervish=" << rhs.Dervish << "\n";
    os << "Beastmaster=" << rhs.Beastmaster << "\n";
    os << "Bard=" << rhs.Bard << "\n";
    os << "Orc_Warrior=" << rhs.Orc_Warrior << "\n";
    os << "Healer=" << rhs.Healer << "\n";
    os << "Huntress=" << rhs.Huntress << "\n";
    os << "Thief=" << rhs.Thief << "\n";
    os << "Druid=" << rhs.Druid << "\n";
    os << "War_Monk=" << rhs.War_Monk << "\n";
    os << "Warrior_Mage=" << rhs.Warrior_Mage << "\n";
    os << "Magician=" << rhs.Magician << "\n";
    os << "Assassin=" << rhs.Assassin << "\n";
    os << "Wind_Mage=" << rhs.Wind_Mage << "\n";
    os << "Ranger=" << rhs.Ranger << "\n";
    os << "Draconian=" << rhs.Draconian << "\n";
    os << "Witch=" << rhs.Witch << "\n";
    os << "Golden_One=" << rhs.Golden_One << "\n";
    os << "Ninja=" << rhs.Ninja << "\n";
    os << "Rogue=" << rhs.Rogue << "\n";
    os << "Amazon=" << rhs.Amazon << "\n";
    os << "Warlock=" << rhs.Warlock << "\n";
    os << "Unknown=" << rhs.Unknown << "\n";
    os << "Illusionist=" << rhs.Illusionist << "\n";
    os << "Swordsman=" << rhs.Swordsman << "\n";
    os << "Priestess=" << rhs.Priestess << "\n";
    os << "Paladin=" << rhs.Paladin << "\n";
    os << "Black_Knight=" << rhs.Black_Knight << "\n";
    os << "Elven_Archer=" << rhs.Elven_Archer << "\n";
    os << "Knight=" << rhs.Knight << "\n";
    os << "Necromancer=" << rhs.Necromancer << "\n";
    os << "Chaos_Warrior=" << rhs.Chaos_Warrior << "\n";
    os << "Chosen=" << rhs.Chosen << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Unit_Enchantment& rhs)
{
    os << "{\n";
    if (0 != rhs.Immolation)
    {
    os << "Immolation=" << (unsigned)rhs.Immolation << "\n";
    }
    if (0 != rhs.Guardian_Wind)
    {
    os << "Guardian_Wind=" << (unsigned)rhs.Guardian_Wind << "\n";
    }
    if (0 != rhs.Berserk)
    {
    os << "Berserk=" << (unsigned)rhs.Berserk << "\n";
    }
    if (0 != rhs.Cloak_of_Fear)
    {
    os << "Cloak_of_Fear=" << (unsigned)rhs.Cloak_of_Fear << "\n";
    }
    if (0 != rhs.Black_Channels)
    {
    os << "Black_Channels=" << (unsigned)rhs.Black_Channels << "\n";
    }
    if (0 != rhs.Wraith_Form)
    {
    os << "Wraith_Form=" << (unsigned)rhs.Wraith_Form << "\n";
    }
    if (0 != rhs.Regeneration)
    {
    os << "Regeneration=" << (unsigned)rhs.Regeneration << "\n";
    }
    if (0 != rhs.Path_Finding)
    {
    os << "Path_Finding=" << (unsigned)rhs.Path_Finding << "\n";
    }
    if (0 != rhs.Water_Walking)
    {
    os << "Water_Walking=" << (unsigned)rhs.Water_Walking << "\n";
    }
    if (0 != rhs.Resist_Elements)
    {
    os << "Resist_Elements=" << (unsigned)rhs.Resist_Elements << "\n";
    }
    if (0 != rhs.Elemental_Armor)
    {
    os << "Elemental_Armor=" << (unsigned)rhs.Elemental_Armor << "\n";
    }
    if (0 != rhs.Stone_Skin)
    {
    os << "Stone_Skin=" << (unsigned)rhs.Stone_Skin << "\n";
    }
    if (0 != rhs.Iron_Skin)
    {
    os << "Iron_Skin=" << (unsigned)rhs.Iron_Skin << "\n";
    }
    if (0 != rhs.Endurance)
    {
    os << "Endurance=" << (unsigned)rhs.Endurance << "\n";
    }
    if (0 != rhs.Spell_Lock)
    {
    os << "Spell_Lock=" << (unsigned)rhs.Spell_Lock << "\n";
    }
    if (0 != rhs.Invisibility)
    {
    os << "Invisibility=" << (unsigned)rhs.Invisibility << "\n";
    }
    if (0 != rhs.Wind_Walking)
    {
    os << "Wind_Walking=" << (unsigned)rhs.Wind_Walking << "\n";
    }
    if (0 != rhs.Flight)
    {
    os << "Flight=" << (unsigned)rhs.Flight << "\n";
    }
    if (0 != rhs.Resist_Magic)
    {
    os << "Resist_Magic=" << (unsigned)rhs.Resist_Magic << "\n";
    }
    if (0 != rhs.Magic_Immunity)
    {
    os << "Magic_Immunity=" << (unsigned)rhs.Magic_Immunity << "\n";
    }
    if (0 != rhs.Flame_Blade)
    {
    os << "Flame_Blade=" << (unsigned)rhs.Flame_Blade << "\n";
    }
    if (0 != rhs.Eldritch_Weapon)
    {
    os << "Eldritch_Weapon=" << (unsigned)rhs.Eldritch_Weapon << "\n";
    }
    if (0 != rhs.True_Sight)
    {
    os << "True_Sight=" << (unsigned)rhs.True_Sight << "\n";
    }
    if (0 != rhs.Holy_Weapon)
    {
    os << "Holy_Weapon=" << (unsigned)rhs.Holy_Weapon << "\n";
    }
    if (0 != rhs.Heroism)
    {
    os << "Heroism=" << (unsigned)rhs.Heroism << "\n";
    }
    if (0 != rhs.Bless)
    {
    os << "Bless=" << (unsigned)rhs.Bless << "\n";
    }
    if (0 != rhs.Lionheart)
    {
    os << "Lionheart=" << (unsigned)rhs.Lionheart << "\n";
    }
    if (0 != rhs.Giant_Strength)
    {
    os << "Giant_Strength=" << (unsigned)rhs.Giant_Strength << "\n";
    }
    if (0 != rhs.Planar_Travel)
    {
    os << "Planar_Travel=" << (unsigned)rhs.Planar_Travel << "\n";
    }
    if (0 != rhs.Holy_Armor)
    {
    os << "Holy_Armor=" << (unsigned)rhs.Holy_Armor << "\n";
    }
    if (0 != rhs.Righteousness)
    {
    os << "Righteousness=" << (unsigned)rhs.Righteousness << "\n";
    }
    if (0 != rhs.Invulnerability)
    {
    os << "Invulnerability=" << (unsigned)rhs.Invulnerability << "\n";
    }
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Unit_Type_Data& rhs)
{
    os << "{\n";
    os << "m_PtrName=" << rhs.m_PtrName << " 0x" << std::hex << rhs.m_PtrName << std::dec << "\n";
    os << "m_Melee=" << (unsigned)rhs.m_Melee << " 0x" << std::hex << (unsigned)rhs.m_Melee << std::dec << "\n";
    os << "m_Ranged=" << (unsigned)rhs.m_Ranged << " 0x" << std::hex << (unsigned)rhs.m_Ranged << std::dec << "\n";
    os << "m_Ranged_Type=" << rhs.m_Ranged_Type << "\n";
    os << "m_Ranged_Shots=" << (unsigned)rhs.m_Ranged_Shots << " 0x" << std::hex << (unsigned)rhs.m_Ranged_Shots << std::dec << "\n";
    os << "m_To_Hit=" << (int)rhs.m_To_Hit << " 0x" << std::hex << (int)rhs.m_To_Hit << std::dec << "\n";
    os << "m_Defense=" << (unsigned)rhs.m_Defense << " 0x" << std::hex << (unsigned)rhs.m_Defense << std::dec << "\n";
    os << "m_Resistance=" << (unsigned)rhs.m_Resistance << " 0x" << std::hex << (unsigned)rhs.m_Resistance << std::dec << "\n";
    os << "m_MoveHalves=" << (unsigned)rhs.m_MoveHalves << " 0x" << std::hex << (unsigned)rhs.m_MoveHalves << std::dec << "\n";
    os << "m_Cost=" << rhs.m_Cost << " 0x" << std::hex << rhs.m_Cost << std::dec << "\n";
    os << "m_Upkeep=" << (unsigned)rhs.m_Upkeep << " 0x" << std::hex << (unsigned)rhs.m_Upkeep << std::dec << "\n";
    os << "m_Race_Code=" << rhs.m_Race_Code << "\n";
    os << "m_Building1Required_or_PortraitLbxIndex=" << (unsigned)rhs.m_Building1Required_or_PortraitLbxIndex << " 0x" << std::hex << (unsigned)rhs.m_Building1Required_or_PortraitLbxIndex << std::dec << "\n";
    os << "m_Building2_or_HeroType=" << rhs.m_Building2_or_HeroType << "\n";
    os << "m_Unit_picture=" << rhs.m_Unit_picture << " 0x" << std::hex << rhs.m_Unit_picture << std::dec << "\n";
    os << "m_Hitpoints=" << (unsigned)rhs.m_Hitpoints << " 0x" << std::hex << (unsigned)rhs.m_Hitpoints << std::dec << "\n";
    os << "m_Scouting=" << (unsigned)rhs.m_Scouting << " 0x" << std::hex << (unsigned)rhs.m_Scouting << std::dec << "\n";
    os << "m_Transport_Capacity=" << (unsigned)rhs.m_Transport_Capacity << " 0x" << std::hex << (unsigned)rhs.m_Transport_Capacity << std::dec << "\n";
    os << "m_Nr_Figures=" << (unsigned)rhs.m_Nr_Figures << " 0x" << std::hex << (unsigned)rhs.m_Nr_Figures << std::dec << "\n";
    os << "m_Construction=" << (unsigned)rhs.m_Construction << " 0x" << std::hex << (unsigned)rhs.m_Construction << std::dec << "\n";
    os << "m_Gaze_Modifier=" << (int)rhs.m_Gaze_Modifier << " 0x" << std::hex << (int)rhs.m_Gaze_Modifier << std::dec << "\n";
    os << "m_Movement_Flags=" << rhs.m_Movement_Flags << "\n";
    os << "m_Zero_19=" << (unsigned)rhs.m_Zero_19 << " 0x" << std::hex << (unsigned)rhs.m_Zero_19 << std::dec << "\n";
    os << "m_Immunity_Flags=" << rhs.m_Immunity_Flags << "\n";
    os << "m_Attribute_Flags=" << rhs.m_Attribute_Flags << "\n";
    os << "m_Zero_1D=" << (unsigned)rhs.m_Zero_1D << " 0x" << std::hex << (unsigned)rhs.m_Zero_1D << std::dec << "\n";
    os << "m_Ability_Flags=" << rhs.m_Ability_Flags << "\n";
    os << "m_Attack_Flags=" << rhs.m_Attack_Flags << "\n";
    os << "m_Sound=" << (unsigned)rhs.m_Sound << " 0x" << std::hex << (unsigned)rhs.m_Sound << std::dec << "\n";
    os << "m_Zero_23=" << (unsigned)rhs.m_Zero_23 << " 0x" << std::hex << (unsigned)rhs.m_Zero_23 << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Unit_Weapon_Mutation& rhs)
{
    os << "{\n";
    if (0 != rhs.Weapon_Type)
    {
    os << "Weapon_Type=" << (unsigned)rhs.Weapon_Type << "\n";
    }
    if (0 != rhs.Chaos_Channels_Demon_Skin)
    {
    os << "Chaos_Channels_Demon_Skin=" << (unsigned)rhs.Chaos_Channels_Demon_Skin << "\n";
    }
    if (0 != rhs.Chaos_Channels_Demon_Wings)
    {
    os << "Chaos_Channels_Demon_Wings=" << (unsigned)rhs.Chaos_Channels_Demon_Wings << "\n";
    }
    if (0 != rhs.Chaos_Channels_Fiery_Breath)
    {
    os << "Chaos_Channels_Fiery_Breath=" << (unsigned)rhs.Chaos_Channels_Fiery_Breath << "\n";
    }
    if (0 != rhs.Undead)
    {
    os << "Undead=" << (unsigned)rhs.Undead << "\n";
    }
    if (0 != rhs.Stasis_initial)
    {
    os << "Stasis_initial=" << (unsigned)rhs.Stasis_initial << "\n";
    }
    if (0 != rhs.Stasis_lingering)
    {
    os << "Stasis_lingering=" << (unsigned)rhs.Stasis_lingering << "\n";
    }
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Upkeep_Enchantments& rhs)
{
    os << "{\n";
    os << "Immolation=" << rhs.Immolation << " 0x" << std::hex << rhs.Immolation << std::dec << "\n";
    os << "Guardian_Wind=" << rhs.Guardian_Wind << " 0x" << std::hex << rhs.Guardian_Wind << std::dec << "\n";
    os << "Berserk=" << rhs.Berserk << " 0x" << std::hex << rhs.Berserk << std::dec << "\n";
    os << "Cloak_of_Fear=" << rhs.Cloak_of_Fear << " 0x" << std::hex << rhs.Cloak_of_Fear << std::dec << "\n";
    os << "Black_Channels=" << rhs.Black_Channels << " 0x" << std::hex << rhs.Black_Channels << std::dec << "\n";
    os << "Wraith_Form=" << rhs.Wraith_Form << " 0x" << std::hex << rhs.Wraith_Form << std::dec << "\n";
    os << "Regeneration=" << rhs.Regeneration << " 0x" << std::hex << rhs.Regeneration << std::dec << "\n";
    os << "Path_Finding=" << rhs.Path_Finding << " 0x" << std::hex << rhs.Path_Finding << std::dec << "\n";
    os << "Water_Walking=" << rhs.Water_Walking << " 0x" << std::hex << rhs.Water_Walking << std::dec << "\n";
    os << "Resist_Elements=" << rhs.Resist_Elements << " 0x" << std::hex << rhs.Resist_Elements << std::dec << "\n";
    os << "Elemental_Armor=" << rhs.Elemental_Armor << " 0x" << std::hex << rhs.Elemental_Armor << std::dec << "\n";
    os << "Stone_Skin=" << rhs.Stone_Skin << " 0x" << std::hex << rhs.Stone_Skin << std::dec << "\n";
    os << "Iron_Skin=" << rhs.Iron_Skin << " 0x" << std::hex << rhs.Iron_Skin << std::dec << "\n";
    os << "Endurance=" << rhs.Endurance << " 0x" << std::hex << rhs.Endurance << std::dec << "\n";
    os << "Spell_Lock=" << rhs.Spell_Lock << " 0x" << std::hex << rhs.Spell_Lock << std::dec << "\n";
    os << "Invisibility=" << rhs.Invisibility << " 0x" << std::hex << rhs.Invisibility << std::dec << "\n";
    os << "Wind_Walking=" << rhs.Wind_Walking << " 0x" << std::hex << rhs.Wind_Walking << std::dec << "\n";
    os << "Flight=" << rhs.Flight << " 0x" << std::hex << rhs.Flight << std::dec << "\n";
    os << "Resist_Magic=" << rhs.Resist_Magic << " 0x" << std::hex << rhs.Resist_Magic << std::dec << "\n";
    os << "Magic_Immunity=" << rhs.Magic_Immunity << " 0x" << std::hex << rhs.Magic_Immunity << std::dec << "\n";
    os << "Flame_Blade=" << rhs.Flame_Blade << " 0x" << std::hex << rhs.Flame_Blade << std::dec << "\n";
    os << "Eldritch_Weapon=" << rhs.Eldritch_Weapon << " 0x" << std::hex << rhs.Eldritch_Weapon << std::dec << "\n";
    os << "True_Sight=" << rhs.True_Sight << " 0x" << std::hex << rhs.True_Sight << std::dec << "\n";
    os << "Holy_Weapon=" << rhs.Holy_Weapon << " 0x" << std::hex << rhs.Holy_Weapon << std::dec << "\n";
    os << "Heroism=" << rhs.Heroism << " 0x" << std::hex << rhs.Heroism << std::dec << "\n";
    os << "Bless=" << rhs.Bless << " 0x" << std::hex << rhs.Bless << std::dec << "\n";
    os << "Lionheart=" << rhs.Lionheart << " 0x" << std::hex << rhs.Lionheart << std::dec << "\n";
    os << "Giant_Strength=" << rhs.Giant_Strength << " 0x" << std::hex << rhs.Giant_Strength << std::dec << "\n";
    os << "Planar_Travel=" << rhs.Planar_Travel << " 0x" << std::hex << rhs.Planar_Travel << std::dec << "\n";
    os << "Holy_Armor=" << rhs.Holy_Armor << " 0x" << std::hex << rhs.Holy_Armor << std::dec << "\n";
    os << "Righteousness=" << rhs.Righteousness << " 0x" << std::hex << rhs.Righteousness << std::dec << "\n";
    os << "Invulnerability=" << rhs.Invulnerability << " 0x" << std::hex << rhs.Invulnerability << std::dec << "\n";
    os << "Wall_of_Fire=" << rhs.Wall_of_Fire << " 0x" << std::hex << rhs.Wall_of_Fire << std::dec << "\n";
    os << "Chaos_Rift=" << rhs.Chaos_Rift << " 0x" << std::hex << rhs.Chaos_Rift << std::dec << "\n";
    os << "Dark_Rituals=" << rhs.Dark_Rituals << " 0x" << std::hex << rhs.Dark_Rituals << std::dec << "\n";
    os << "Evil_Presence=" << rhs.Evil_Presence << " 0x" << std::hex << rhs.Evil_Presence << std::dec << "\n";
    os << "Cursed_Lands=" << rhs.Cursed_Lands << " 0x" << std::hex << rhs.Cursed_Lands << std::dec << "\n";
    os << "Pestilence=" << rhs.Pestilence << " 0x" << std::hex << rhs.Pestilence << std::dec << "\n";
    os << "Cloud_of_Shadow=" << rhs.Cloud_of_Shadow << " 0x" << std::hex << rhs.Cloud_of_Shadow << std::dec << "\n";
    os << "Famine=" << rhs.Famine << " 0x" << std::hex << rhs.Famine << std::dec << "\n";
    os << "Flying_Fortress=" << rhs.Flying_Fortress << " 0x" << std::hex << rhs.Flying_Fortress << std::dec << "\n";
    os << "Nature_Ward=" << rhs.Nature_Ward << " 0x" << std::hex << rhs.Nature_Ward << std::dec << "\n";
    os << "Sorcery_Ward=" << rhs.Sorcery_Ward << " 0x" << std::hex << rhs.Sorcery_Ward << std::dec << "\n";
    os << "Chaos_Ward=" << rhs.Chaos_Ward << " 0x" << std::hex << rhs.Chaos_Ward << std::dec << "\n";
    os << "Life_Ward=" << rhs.Life_Ward << " 0x" << std::hex << rhs.Life_Ward << std::dec << "\n";
    os << "Death_Ward=" << rhs.Death_Ward << " 0x" << std::hex << rhs.Death_Ward << std::dec << "\n";
    os << "Natures_Eye=" << rhs.Natures_Eye << " 0x" << std::hex << rhs.Natures_Eye << std::dec << "\n";
    os << "Earth_Gate=" << rhs.Earth_Gate << " 0x" << std::hex << rhs.Earth_Gate << std::dec << "\n";
    os << "Stream_of_Life=" << rhs.Stream_of_Life << " 0x" << std::hex << rhs.Stream_of_Life << std::dec << "\n";
    os << "Gaias_Blessing=" << rhs.Gaias_Blessing << " 0x" << std::hex << rhs.Gaias_Blessing << std::dec << "\n";
    os << "Inspirations=" << rhs.Inspirations << " 0x" << std::hex << rhs.Inspirations << std::dec << "\n";
    os << "Prosperity=" << rhs.Prosperity << " 0x" << std::hex << rhs.Prosperity << std::dec << "\n";
    os << "Astral_Gate=" << rhs.Astral_Gate << " 0x" << std::hex << rhs.Astral_Gate << std::dec << "\n";
    os << "Heavenly_Light=" << rhs.Heavenly_Light << " 0x" << std::hex << rhs.Heavenly_Light << std::dec << "\n";
    os << "Consecration=" << rhs.Consecration << " 0x" << std::hex << rhs.Consecration << std::dec << "\n";
    os << "Wall_of_Darkness=" << rhs.Wall_of_Darkness << " 0x" << std::hex << rhs.Wall_of_Darkness << std::dec << "\n";
    os << "Altar_of_Battle=" << rhs.Altar_of_Battle << " 0x" << std::hex << rhs.Altar_of_Battle << std::dec << "\n";
    os << "Nightshade=" << rhs.Nightshade << " 0x" << std::hex << rhs.Nightshade << std::dec << "\n";
    os << "Eternal_Night=" << rhs.Eternal_Night << " 0x" << std::hex << rhs.Eternal_Night << std::dec << "\n";
    os << "Evil_Omens=" << rhs.Evil_Omens << " 0x" << std::hex << rhs.Evil_Omens << std::dec << "\n";
    os << "Zombie_Mastery=" << rhs.Zombie_Mastery << " 0x" << std::hex << rhs.Zombie_Mastery << std::dec << "\n";
    os << "Aura_of_Majesty=" << rhs.Aura_of_Majesty << " 0x" << std::hex << rhs.Aura_of_Majesty << std::dec << "\n";
    os << "Wind_Mastery=" << rhs.Wind_Mastery << " 0x" << std::hex << rhs.Wind_Mastery << std::dec << "\n";
    os << "Suppress_Magic=" << rhs.Suppress_Magic << " 0x" << std::hex << rhs.Suppress_Magic << std::dec << "\n";
    os << "Time_Stop=" << rhs.Time_Stop << " 0x" << std::hex << rhs.Time_Stop << std::dec << "\n";
    os << "Nature_Awareness=" << rhs.Nature_Awareness << " 0x" << std::hex << rhs.Nature_Awareness << std::dec << "\n";
    os << "Natures_Wrath=" << rhs.Natures_Wrath << " 0x" << std::hex << rhs.Natures_Wrath << std::dec << "\n";
    os << "Herb_Mastery=" << rhs.Herb_Mastery << " 0x" << std::hex << rhs.Herb_Mastery << std::dec << "\n";
    os << "Chaos_Surge=" << rhs.Chaos_Surge << " 0x" << std::hex << rhs.Chaos_Surge << std::dec << "\n";
    os << "Doom_Mastery=" << rhs.Doom_Mastery << " 0x" << std::hex << rhs.Doom_Mastery << std::dec << "\n";
    os << "Great_Wasting=" << rhs.Great_Wasting << " 0x" << std::hex << rhs.Great_Wasting << std::dec << "\n";
    os << "Meteor_Storm=" << rhs.Meteor_Storm << " 0x" << std::hex << rhs.Meteor_Storm << std::dec << "\n";
    os << "Armageddon=" << rhs.Armageddon << " 0x" << std::hex << rhs.Armageddon << std::dec << "\n";
    os << "Tranquility=" << rhs.Tranquility << " 0x" << std::hex << rhs.Tranquility << std::dec << "\n";
    os << "Life_Force=" << rhs.Life_Force << " 0x" << std::hex << rhs.Life_Force << std::dec << "\n";
    os << "Crusade=" << rhs.Crusade << " 0x" << std::hex << rhs.Crusade << std::dec << "\n";
    os << "Just_Cause=" << rhs.Just_Cause << " 0x" << std::hex << rhs.Just_Cause << std::dec << "\n";
    os << "Holy_Arms=" << rhs.Holy_Arms << " 0x" << std::hex << rhs.Holy_Arms << std::dec << "\n";
    os << "Planar_Seal=" << rhs.Planar_Seal << " 0x" << std::hex << rhs.Planar_Seal << std::dec << "\n";
    os << "Charm_of_Life=" << rhs.Charm_of_Life << " 0x" << std::hex << rhs.Charm_of_Life << std::dec << "\n";
    os << "Detect_Magic=" << rhs.Detect_Magic << " 0x" << std::hex << rhs.Detect_Magic << std::dec << "\n";
    os << "Awareness=" << rhs.Awareness << " 0x" << std::hex << rhs.Awareness << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Wizard& rhs)
{
    os << "{\n";
    os << "m_Portrait=" << rhs.m_Portrait << "\n";
    os << "m_Name=" << formatCharArray(rhs.m_Name, 20) << "\n";
    os << "m_Home_Race=" << rhs.m_Home_Race << "\n";
    os << "m_BannerColor=" << rhs.m_BannerColor << "\n";
    os << "m_Personality=" << rhs.m_Personality << "\n";
    os << "m_Objective=" << rhs.m_Objective << "\n";
    os << "m_Unk_01C=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_01C[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_01C[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_ResearchCost_SpellofMastery_GUESS=" << rhs.m_ResearchCost_SpellofMastery_GUESS << " 0x" << std::hex << rhs.m_ResearchCost_SpellofMastery_GUESS << std::dec << "\n";
    os << "m_Fame=" << rhs.m_Fame << " 0x" << std::hex << rhs.m_Fame << std::dec << "\n";
    os << "m_Power_Base=" << rhs.m_Power_Base << " 0x" << std::hex << rhs.m_Power_Base << std::dec << "\n";
    os << "m_Unk_028=" << rhs.m_Unk_028 << " 0x" << std::hex << rhs.m_Unk_028 << std::dec << "\n";
    os << "m_Research_Percentage=" << (unsigned)rhs.m_Research_Percentage << " 0x" << std::hex << (unsigned)rhs.m_Research_Percentage << std::dec << "\n";
    os << "m_Mana_Percentage=" << (unsigned)rhs.m_Mana_Percentage << " 0x" << std::hex << (unsigned)rhs.m_Mana_Percentage << std::dec << "\n";
    os << "m_Skill_Percentage=" << (unsigned)rhs.m_Skill_Percentage << " 0x" << std::hex << (unsigned)rhs.m_Skill_Percentage << std::dec << "\n";
    os << "m_Mana_generated_by_volcanoes=" << (unsigned)rhs.m_Mana_generated_by_volcanoes << " 0x" << std::hex << (unsigned)rhs.m_Mana_generated_by_volcanoes << std::dec << "\n";
    os << "m_X_Coordinate_of_Summoning_Circle=" << rhs.m_X_Coordinate_of_Summoning_Circle << " 0x" << std::hex << rhs.m_X_Coordinate_of_Summoning_Circle << std::dec << "\n";
    os << "m_Y_Coordinate_of_Summoning_Circle=" << rhs.m_Y_Coordinate_of_Summoning_Circle << " 0x" << std::hex << rhs.m_Y_Coordinate_of_Summoning_Circle << std::dec << "\n";
    os << "m_Plane_of_Summoning_Circle=" << rhs.m_Plane_of_Summoning_Circle << "\n";
    os << "m_Zero_033=" << (unsigned)rhs.m_Zero_033 << " 0x" << std::hex << (unsigned)rhs.m_Zero_033 << std::dec << "\n";
    os << "m_Research_Spell_candidates=(\n";
    for (unsigned i = 0; i < 8; ++i)
    {
        os << "[" << i << "] " << rhs.m_Research_Spell_candidates[i] << ",\n";
    }
    os << ")\n";
    os << "m_Unk_044=(\n";
    for (unsigned i = 0; i < 4; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_044[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_044[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Garrison_average_strength=" << rhs.m_Garrison_average_strength << " 0x" << std::hex << rhs.m_Garrison_average_strength << std::dec << "\n";
    os << "m_Unk_04A=" << rhs.m_Unk_04A << " 0x" << std::hex << rhs.m_Unk_04A << std::dec << "\n";
    os << "m_Skill_Left_in_combat=" << rhs.m_Skill_Left_in_combat << " 0x" << std::hex << rhs.m_Skill_Left_in_combat << std::dec << "\n";
    os << "m_Cost_Left_of_Spell_being_cast=" << rhs.m_Cost_Left_of_Spell_being_cast << " 0x" << std::hex << rhs.m_Cost_Left_of_Spell_being_cast << std::dec << "\n";
    os << "m_Initial_Cost_of_Spell_being_cast=" << rhs.m_Initial_Cost_of_Spell_being_cast << " 0x" << std::hex << rhs.m_Initial_Cost_of_Spell_being_cast << std::dec << "\n";
    os << "m_Spell_being_cast=" << rhs.m_Spell_being_cast << "\n";
    os << "m_Unused_Casting_Skill_available_this_turn=" << rhs.m_Unused_Casting_Skill_available_this_turn << " 0x" << std::hex << rhs.m_Unused_Casting_Skill_available_this_turn << std::dec << "\n";
    os << "m_Nominal_Casting_Skill_available_this_turn=" << rhs.m_Nominal_Casting_Skill_available_this_turn << " 0x" << std::hex << rhs.m_Nominal_Casting_Skill_available_this_turn << std::dec << "\n";
    os << "m_Tax_Rate=" << rhs.m_Tax_Rate << "\n";
    os << "m_Number_of_Spellbooks_Nature=" << rhs.m_Number_of_Spellbooks_Nature << " 0x" << std::hex << rhs.m_Number_of_Spellbooks_Nature << std::dec << "\n";
    os << "m_Number_of_Spellbooks_Sorcery=" << rhs.m_Number_of_Spellbooks_Sorcery << " 0x" << std::hex << rhs.m_Number_of_Spellbooks_Sorcery << std::dec << "\n";
    os << "m_Number_of_Spellbooks_Chaos=" << rhs.m_Number_of_Spellbooks_Chaos << " 0x" << std::hex << rhs.m_Number_of_Spellbooks_Chaos << std::dec << "\n";
    os << "m_Number_of_Spellbooks_Life=" << rhs.m_Number_of_Spellbooks_Life << " 0x" << std::hex << rhs.m_Number_of_Spellbooks_Life << std::dec << "\n";
    os << "m_Number_of_Spellbooks_Death=" << rhs.m_Number_of_Spellbooks_Death << " 0x" << std::hex << rhs.m_Number_of_Spellbooks_Death << std::dec << "\n";
    os << "m_Skills=" << rhs.m_Skills << "\n";
    os << "m_Heroes_hired_by_wizard=(\n";
    for (unsigned i = 0; i < gMAX_HIRED_HEROES; ++i)
    {
        os << "[" << i << "] " << rhs.m_Heroes_hired_by_wizard[i] << ",\n";
    }
    os << ")\n";
    os << "m_Unk_11E=" << rhs.m_Unk_11E << " 0x" << std::hex << rhs.m_Unk_11E << std::dec << "\n";
    os << "m_Items_in_Slots=(\n";
    for (unsigned i = 0; i < 4; ++i)
    {
        os << "[" << i << "] " << rhs.m_Items_in_Slots[i] << " 0x" << std::hex << rhs.m_Items_in_Slots[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Diplomacy=" << rhs.m_Diplomacy << "\n";
    os << "m_Researching_Left=" << rhs.m_Researching_Left << " 0x" << std::hex << rhs.m_Researching_Left << std::dec << "\n";
    os << "m_Mana_Crystals=" << rhs.m_Mana_Crystals << " 0x" << std::hex << rhs.m_Mana_Crystals << std::dec << "\n";
    os << "m_Wizard_Casting_Skill=" << rhs.m_Wizard_Casting_Skill << " 0x" << std::hex << rhs.m_Wizard_Casting_Skill << std::dec << "\n";
    os << "m_Researching_Spell=" << rhs.m_Researching_Spell << "\n";
    os << "m_Spells_Known=" << rhs.m_Spells_Known << "\n";
    os << "m_Unk_33A=(\n";
    for (unsigned i = 0; i < 26; ++i)
    {
        os << "[" << i << "] " << (int)rhs.m_Unk_33A[i] << " 0x" << std::hex << (int)rhs.m_Unk_33A[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Bitmask_banished_wizards=" << rhs.m_Bitmask_banished_wizards << " 0x" << std::hex << rhs.m_Bitmask_banished_wizards << std::dec << "\n";
    os << "m_Gold_Coins=" << rhs.m_Gold_Coins << " 0x" << std::hex << rhs.m_Gold_Coins << std::dec << "\n";
    os << "m_Unk_358=" << rhs.m_Unk_358 << " 0x" << std::hex << rhs.m_Unk_358 << std::dec << "\n";
    os << "m_Astrologer_Magic_Power=" << rhs.m_Astrologer_Magic_Power << " 0x" << std::hex << rhs.m_Astrologer_Magic_Power << std::dec << "\n";
    os << "m_Astrologer_Spell_Research=" << rhs.m_Astrologer_Spell_Research << " 0x" << std::hex << rhs.m_Astrologer_Spell_Research << std::dec << "\n";
    os << "m_Astrologer_Army_Strength=" << rhs.m_Astrologer_Army_Strength << " 0x" << std::hex << rhs.m_Astrologer_Army_Strength << std::dec << "\n";
    os << "m_Astrologer_Power_GUESS=" << rhs.m_Astrologer_Power_GUESS << " 0x" << std::hex << rhs.m_Astrologer_Power_GUESS << std::dec << "\n";
    os << "m_Historian=(\n";
    for (unsigned i = 0; i < 288; ++i)
    {
        os << "[" << i << "] " << (int)rhs.m_Historian[i] << " 0x" << std::hex << (int)rhs.m_Historian[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Global_Enchantments=" << rhs.m_Global_Enchantments << "\n";
    os << "m_Unk_49A=(\n";
    for (unsigned i = 0; i < 42; ++i)
    {
        os << "[" << i << "] " << (unsigned)rhs.m_Unk_49A[i] << " 0x" << std::hex << (unsigned)rhs.m_Unk_49A[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Books_Color=" << rhs.m_Books_Color << "\n";
    os << "m_Zero_4C5=" << (unsigned)rhs.m_Zero_4C5 << " 0x" << std::hex << (unsigned)rhs.m_Zero_4C5 << std::dec << "\n";
    os << "m_Unk_4C6=" << rhs.m_Unk_4C6 << " 0x" << std::hex << rhs.m_Unk_4C6 << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Wizard_Diplomacy& rhs)
{
    os << "{\n";
    os << "m_Contacted=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << (int)rhs.m_Contacted[i] << " 0x" << std::hex << (int)rhs.m_Contacted[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Unk_12E_Relation=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << rhs.m_Unk_12E_Relation[i] << " 0x" << std::hex << rhs.m_Unk_12E_Relation[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Unk_13A_Relation=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << rhs.m_Unk_13A_Relation[i] << " 0x" << std::hex << rhs.m_Unk_13A_Relation[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Unk_146_Relation=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << rhs.m_Unk_146_Relation[i] << " 0x" << std::hex << rhs.m_Unk_146_Relation[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Current_Wizard_Relations=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << (int)rhs.m_Current_Wizard_Relations[i] << " 0x" << std::hex << (int)rhs.m_Current_Wizard_Relations[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_War_Status=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << rhs.m_War_Status[i] << ",\n";
    }
    os << ")\n";
    os << "m_Unk_15E=(\n";
    for (unsigned i = 0; i < 0x24; ++i)
    {
        os << "[" << i << "] " << (int)rhs.m_Unk_15E[i] << " 0x" << std::hex << (int)rhs.m_Unk_15E[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Unk_182_Relation=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << (int)rhs.m_Unk_182_Relation[i] << " 0x" << std::hex << (int)rhs.m_Unk_182_Relation[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Unk_188_Relation=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << (int)rhs.m_Unk_188_Relation[i] << " 0x" << std::hex << (int)rhs.m_Unk_188_Relation[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Unk_18E=(\n";
    for (unsigned i = 0; i < 18; ++i)
    {
        os << "[" << i << "] " << (int)rhs.m_Unk_18E[i] << " 0x" << std::hex << (int)rhs.m_Unk_18E[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Diplomacy_penalty_GUESS=(\n";
    for (unsigned i = 0; i < 6; ++i)
    {
        os << "[" << i << "] " << (int)rhs.m_Diplomacy_penalty_GUESS[i] << " 0x" << std::hex << (int)rhs.m_Diplomacy_penalty_GUESS[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "m_Unk_1A6=(\n";
    for (unsigned i = 0; i < 0xB4; ++i)
    {
        os << "[" << i << "] " << (int)rhs.m_Unk_1A6[i] << " 0x" << std::hex << (int)rhs.m_Unk_1A6[i] << std::dec << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Wizard_Type_Data& rhs)
{
    os << "{\n";
    os << "m_Wizard_Name=" << formatCharArray(rhs.m_Wizard_Name, 10) << "\n";
    os << "m_Life_books=" << rhs.m_Life_books << " 0x" << std::hex << rhs.m_Life_books << std::dec << "\n";
    os << "m_Sorcery_books=" << rhs.m_Sorcery_books << " 0x" << std::hex << rhs.m_Sorcery_books << std::dec << "\n";
    os << "m_Nature_books=" << rhs.m_Nature_books << " 0x" << std::hex << rhs.m_Nature_books << std::dec << "\n";
    os << "m_Death_books=" << rhs.m_Death_books << " 0x" << std::hex << rhs.m_Death_books << std::dec << "\n";
    os << "m_Chaos_books=" << rhs.m_Chaos_books << " 0x" << std::hex << rhs.m_Chaos_books << std::dec << "\n";
    os << "m_Skill=" << rhs.m_Skill << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const WizardsExe_Game_Data& rhs)
{
    os << "{\n";
    os << "m_UnitNr_Active=" << rhs.m_UnitNr_Active << " 0x" << std::hex << rhs.m_UnitNr_Active << std::dec << "\n";
    os << "m_Current_Turn=" << rhs.m_Current_Turn << " 0x" << std::hex << rhs.m_Current_Turn << std::dec << "\n";
    os << "m_Number_of_Units=" << rhs.m_Number_of_Units << " 0x" << std::hex << rhs.m_Number_of_Units << std::dec << "\n";
    os << "m_Number_of_Cities=" << rhs.m_Number_of_Cities << " 0x" << std::hex << rhs.m_Number_of_Cities << std::dec << "\n";
    os << "m_Difficulty=" << rhs.m_Difficulty << "\n";
    os << "m_Magic_Powerful_setting=" << rhs.m_Magic_Powerful_setting << "\n";
    os << "m_Land_Size_setting=" << rhs.m_Land_Size_setting << "\n";
    os << "m_Number_of_Wizards=" << rhs.m_Number_of_Wizards << " 0x" << std::hex << rhs.m_Number_of_Wizards << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const WizardsExe_Save_Name& rhs)
{
    os << "{\n";
    os << "m_Name=" << formatCharArray(rhs.m_Name, 20) << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const unionAbility_Flags& rhs)
{
    os << "{\n";
    os << "s=" << rhs.s << "\n";
    os << "bits=" << rhs.bits << " 0x" << std::hex << rhs.bits << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const unionAttack_Flags& rhs)
{
    os << "{\n";
    os << "s=" << rhs.s << "\n";
    os << "bits=" << rhs.bits << " 0x" << std::hex << rhs.bits << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const unionAttribute_Flags& rhs)
{
    os << "{\n";
    os << "s=" << rhs.s << "\n";
    os << "bits=" << rhs.bits << " 0x" << std::hex << rhs.bits << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const unionBuilding_Status& rhs)
{
    os << "{\n";
    os << "a=(\n";
    for (unsigned i = 0; i < eBuilding_array_MAX; ++i)
    {
        os << "[" << i << "] " << rhs.a[i] << ",\n";
    }
    os << ")\n";
    os << "s=" << rhs.s << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const unionCombat_Enchantment& rhs)
{
    os << "{\n";
    os << "s=" << rhs.s << "\n";
    os << "bits=" << rhs.bits << " 0x" << std::hex << rhs.bits << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const unionHero_Abilities& rhs)
{
    os << "{\n";
    os << "s=" << rhs.s << "\n";
    os << "bits=" << rhs.bits << " 0x" << std::hex << rhs.bits << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const unionImmunity_Flags& rhs)
{
    os << "{\n";
    os << "s=" << rhs.s << "\n";
    os << "bits=" << (unsigned)rhs.bits << " 0x" << std::hex << (unsigned)rhs.bits << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const unionItem_Powers& rhs)
{
    os << "{\n";
    os << "s=" << rhs.s << "\n";
    os << "bits=" << rhs.bits << " 0x" << std::hex << rhs.bits << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const unionList_Hero_stats& rhs)
{
    os << "{\n";
    os << "a=(\n";
    for (unsigned i = 0; i < gMAX_HERO_TYPES; ++i)
    {
        os << "[" << i << "] " << rhs.a[i] << ",\n";
    }
    os << ")\n";
    os << "s=" << rhs.s << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const unionMovement_Flags& rhs)
{
    os << "{\n";
    os << "s=" << rhs.s << "\n";
    os << "bits=" << (unsigned)rhs.bits << " 0x" << std::hex << (unsigned)rhs.bits << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const unionSkills& rhs)
{
    os << "{\n";
    os << "s=" << rhs.s << "\n";
    os << "a=(\n";
    for (unsigned i = 0; i < eSkill_MAX; ++i)
    {
        os << "[" << i << "] " << rhs.a[i] << ",\n";
    }
    os << ")\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const unionTower_Node_Lair_Flags& rhs)
{
    os << "{\n";
    os << "s=" << rhs.s << "\n";
    os << "bits=" << (unsigned)rhs.bits << " 0x" << std::hex << (unsigned)rhs.bits << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const unionUnit_Enchantment& rhs)
{
    os << "{\n";
    os << "s=" << rhs.s << "\n";
    os << "bits=" << rhs.bits << " 0x" << std::hex << rhs.bits << std::dec << "\n";
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const unionUnit_Weapon_Mutation& rhs)
{
    os << "{\n";
    os << "s=" << rhs.s << "\n";
    os << "bits=" << (unsigned)rhs.bits << " 0x" << std::hex << (unsigned)rhs.bits << std::dec << "\n";
    os << "}";
    return os;
}


} // namespace
