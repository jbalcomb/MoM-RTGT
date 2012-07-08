// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include <assert.h>
#include <cmath>

#include "MoMGameBase.h"
#include "MoMGenerated.h"
#include "MoMUtility.h"

#include "MoMUnit.h"

namespace MoM
{

MoMUnit::MoMUnit() :
    m_game(),
    m_battleUnit(),
    m_heroStats(),
    m_heroStatsInitializer(),
    m_hiredHero(),
    m_unit(),
    m_unitType(),
	m_bonuses(),
    m_dnSpells(),
    m_penalties(),
    m_upAbilities(),
    m_upItems(),
    m_upLevel(),
    m_upSpells(),
    m_upWeaponType()
{
}

MoMUnit::MoMUnit(MoM::MoMGameBase *game) :
    m_game(),
    m_battleUnit(),
    m_heroStats(),
    m_heroStatsInitializer(),
    m_hiredHero(),
    m_unit(),
    m_unitType(),
    m_bonuses(),
    m_dnSpells(),
    m_penalties(),
    m_upAbilities(),
    m_upItems(),
    m_upLevel(),
    m_upSpells(),
    m_upWeaponType()
{
    setGame(game);
}

MoMUnit::~MoMUnit()
{
}

MoMUnit::MoMUnit(const MoMUnit& rhs)
{
    copyMemberData(rhs);
}

MoMUnit& MoMUnit::operator=(const MoMUnit& rhs)
{
    if (this != &rhs)
    {
        // Release_All_Resources_Of( this );
        // Not applicable

        // Base::operator=( rhs );
        // Not applicable

        // Copy_Member_Data( this, rhs );
        copyMemberData(rhs);
    }
    return *this;
}

void MoMUnit::copyMemberData(const MoMUnit& rhs)
{
    m_game = rhs.m_game;

    m_battleUnit = rhs.m_battleUnit;
    m_heroStats = rhs.m_heroStats;
    m_heroStatsInitializer = rhs.m_heroStatsInitializer;
    m_hiredHero = rhs.m_hiredHero;
    m_unit = rhs.m_unit;
    m_unitType = rhs.m_unitType;
    m_bonuses = rhs.m_bonuses;
    m_dnSpells = rhs.m_dnSpells;
    m_penalties = rhs.m_penalties;
    m_upAbilities = rhs.m_upAbilities;
    m_upItems = rhs.m_upItems;
    m_upLevel = rhs.m_upLevel;
    m_upSpells = rhs.m_upSpells;
    m_upWeaponType = rhs.m_upWeaponType;
}

void MoMUnit::close()
{
    m_battleUnit = 0;
    m_heroStats = 0;
    m_heroStatsInitializer = 0;
    m_hiredHero = 0;
    m_unitType = 0;
    m_unit = 0;
	m_bonuses = BaseAttributes();
    m_dnSpells = BaseAttributes();
    m_penalties = BaseAttributes();
    m_upAbilities = BaseAttributes();
    m_upItems = BaseAttributes();
    m_upLevel = BaseAttributes();
    m_upSpells = BaseAttributes();
    m_upWeaponType = BaseAttributes();
}

void MoMUnit::changeUnit(Battle_Unit *battleUnit)
{
    close();

    m_battleUnit = battleUnit;

    if (0 != m_game)
    {
        m_unit = m_game->getUnit(battleUnit->m_unitNr);

        if (0 != m_unit)
        {
            m_heroStats = m_game->getHero_stats(battleUnit->m_Owner, m_unit->m_Unit_Type);
            m_hiredHero = m_game->getHired_Hero(m_unit);
            m_unitType = m_game->getUnit_Type_Data(m_unit->m_Unit_Type);
        }
//        m_heroStatsInitializer = 0;

        applyEffects();
    }
}

void MoMUnit::changeUnit(eUnit_Type unitTypeNr)
{
    close();

    if (0 != m_game)
    {
//        m_battleUnit = m_game->getBattle_Units();
        // TODO: playerNr is YOU if you want to summon, or otherwise it is unknown
        m_heroStats = m_game->getHero_stats(MoM::PLAYER_YOU, unitTypeNr);
//        m_heroStatsInitializer = 0;
//        m_hiredHero = 0;
        m_unitType = m_game->getUnit_Type_Data(unitTypeNr);
//        m_unit = 0;

        applyEffects();
    }
}

void MoMUnit::changeUnit(Hired_Hero *hiredHero)
{
    close();

    m_hiredHero = hiredHero;

    if (0 != m_game)
    {
        ePlayer playerNr = m_game->getPlayerNr(m_hiredHero);

        m_unit = m_game->getUnit(hiredHero->m_Unit_Nr);
        if (0 != m_unit)
        {
            m_unitType = m_game->getUnit_Type_Data(m_unit->m_Unit_Type);
            m_heroStats = m_game->getHero_stats(playerNr, m_unit->m_Unit_Type);
        }
//        m_battleUnit = m_game->getBattle_Units();
//        m_heroStatsInitializer = 0;

        applyEffects();
    }
}

void MoMUnit::changeUnit(Hero_stats *heroStats)
{
    close();

    m_heroStats = heroStats;

    if (0 != m_game)
    {
        MoM::ePlayer playerNr = m_game->getPlayerNr(m_heroStats);
        MoM::eUnit_Type unitTypeNr = m_game->getUnitTypeNr(m_heroStats);
        m_unitType = m_game->getUnit_Type_Data(unitTypeNr);

        for (unsigned slotNr = 0; slotNr < gMAX_HIRED_HEROES; ++slotNr)
        {
            Hired_Hero* hiredHero = m_game->getHired_Hero(playerNr, slotNr);
            if (0 == hiredHero)
                continue;
            Unit* unit = m_game->getUnit(hiredHero->m_Unit_Nr);
            if (0 == unit)
                continue;
            if (unit->m_Unit_Type == unitTypeNr)
            {
                m_hiredHero = hiredHero;
                m_unit = unit;
            }
        }
//        m_battleUnit = m_game->getBattle_Units();
//        m_heroStatsInitializer = 0;

        applyEffects();
    }
}

void MoMUnit::changeUnit(Hero_Stats_Initializer *heroStatsInitializer)
{
    close();

    m_heroStatsInitializer = heroStatsInitializer;

    if (0 != m_game)
    {
//        m_battleUnit = 0;
//        m_heroStats = 0;
//        m_hiredHero = 0;
//        m_unitType = 0;
//        m_unit = 0;

        applyEffects();
    }
}

void MoMUnit::changeUnit(Unit_Type_Data* unitType)
{
    close();

    m_unitType = unitType;

    if (0 != m_game)
    {
        MoM::eUnit_Type unitTypeNr = m_game->getUnitTypeNr(unitType);

//        m_battleUnit = m_game->getBattle_Units();
        m_heroStats = m_game->getHero_stats(MoM::PLAYER_YOU, unitTypeNr);
//        m_heroStatsInitializer = 0;
//        m_hiredHero = 0;
//        m_unit = 0;

        applyEffects();
    }
}

void MoMUnit::changeUnit(Unit* unit)
{
    assert(0 != unit);
    close();

    m_unit = unit;

    if (0 != m_game)
    {
        MoM::eUnit_Type unitTypeNr = unit->m_Unit_Type;

//        m_battleUnit = m_game->getBattle_Units();
        m_heroStats = m_game->getHero_stats(MoM::PLAYER_YOU, unitTypeNr);
//        m_heroStatsInitializer = 0;
        m_hiredHero = m_game->getHired_Hero(unit);
        m_unitType = m_game->getUnit_Type_Data(unitTypeNr);

        applyEffects();
    }
}


Battle_Unit MoMUnit::getBattleUnit() const
{
    Battle_Unit value;
    memset(&value, '\0', sizeof(value));
    if (0 != m_battleUnit)
    {
        value = *m_battleUnit;
    }
    return value;
}
Hero_stats MoMUnit::getHeroStats() const
{
    Hero_stats value;
    memset(&value, '\0', sizeof(value));
    if (0 != m_heroStats)
    {
        value = *m_heroStats;
    }
    return value;
}
Hero_Stats_Initializer MoMUnit::getHeroStatsInitializer() const
{
    Hero_Stats_Initializer value;
    memset(&value, '\0', sizeof(value));
    if (0 != m_heroStatsInitializer)
    {
        value = *m_heroStatsInitializer;
    }
    return value;
}
Hired_Hero MoMUnit::getHiredHero() const
{
    Hired_Hero value;
    memset(&value, '\0', sizeof(value));
    if (0 != m_hiredHero)
    {
        value = *m_hiredHero;
    }
    return value;
}
Unit MoMUnit::getUnitInGame() const
{
    Unit value;
    memset(&value, '\0', sizeof(value));
    if (0 != m_unit)
    {
        value = *m_unit;
    }
    return value;
}
Unit_Type_Data MoMUnit::getUnitTypeData() const
{
    Unit_Type_Data value;
    memset(&value, '\0', sizeof(value));
    if (0 != m_unitType)
    {
        value = *m_unitType;
    }
    return value;
}



//
// OTHER
//

MoMUnit::BaseAttributes MoMUnit::getActualAttributes() const
{
    BaseAttributes base = getBaseAttributes();
    BaseAttributes bonus = m_bonuses;
    BaseAttributes penalty = m_penalties;
    BaseAttributes actual = base;
    bonus.addBonus(m_upAbilities);
    bonus.addBonus(m_upLevel);

    if (base.melee != 0)        actual.melee        += bonus.melee;
    if (base.defense != 0)      actual.defense      += bonus.defense;
    if (base.ranged != 0)       actual.ranged       += bonus.ranged;
    if (base.resistance != 0)   actual.resistance   += bonus.resistance;
    if (base.hitpoints != 0)    actual.hitpoints    += bonus.hitpoints;
    actual.toHitMelee   += bonus.toHitMelee;
    actual.toHitRanged  += bonus.toHitRanged;
    actual.toDefend     += bonus.toDefend;
    actual.moves        += bonus.moves;

    // TODO:
//    if (0 != m_unit)
//    {
//        actual.moves = m_unit->m_Moves_Total / 2.0;
//    }

    return actual;
}

MoMUnit::BaseAttributes MoMUnit::getBaseAttributes() const
{
    BaseAttributes base;

    if (0 != m_unitType)
    {
        base.melee = m_unitType->m_Melee;
		base.defense = m_unitType->m_Defense;
        base.ranged = m_unitType->m_Ranged;
        base.resistance = m_unitType->m_Resistance;
        base.hitpoints = m_unitType->m_Hitpoints;
        base.toHitMelee = m_unitType->m_To_Hit;
        base.toHitRanged = m_unitType->m_To_Hit;
        base.toDefend = 0;
        base.moves = m_unitType->m_MoveHalves / 2.0;
    }

    return base;
}

MoMUnit::BaseAttributes MoMUnit::getBonusAttributes() const
{
    return m_bonuses;
}

std::string MoMUnit::getDisplayName() const
{
    std::string raceName = getRaceName();
    std::string unitName = getUnitName();

    std::string name = raceName + " " + unitName;

    return name;
}

int MoMUnit::getGazeModifier() const
{
    int value = 0;
    if (0 != m_unitType)
    {
        value = m_unitType->m_Gaze_Modifier;
    }
	return value;
}

std::string MoMUnit::getHeroName() const
{
    std::string name;
    if (0 != m_hiredHero)
    {
        name = m_hiredHero->m_Hero_name;
    }
    return name;
}

MoMUnit::ListSpells MoMUnit::getHeroSpells() const
{
    ListSpells value;
    if (0 != m_heroStats)
    {
        for(int i = 0; i < ARRAYSIZE(m_heroStats->m_Spell); ++i)
        {
            if (m_heroStats->m_Spell[i] != SPELL_None)
            {
                value.push_back(m_heroStats->m_Spell[i]);
            }
        }
    }
    else if (0 != m_heroStatsInitializer)
    {
        for(int i = 0; i < ARRAYSIZE(m_heroStatsInitializer->m_Spell); ++i)
        {
            if (m_heroStatsInitializer->m_Spell[i] != SPELL16_None)
            {
                value.push_back((eSpell)m_heroStatsInitializer->m_Spell[i]);
            }
        }
    }
    else
    {
        // Nothing to do
    }
    return value;
}

eHero_TypeCode MoMUnit::getHeroTypeCode() const
{
    eHero_TypeCode value = (eHero_TypeCode)-1;
    if ((0 != m_unitType) && isHero())
    {
        value = m_unitType->m_Hero_TypeCode_or_Building2;
    }
    return value;
}

//MoMUnit::MapSpecials MoMUnit::getItemEffects() const
//{
//    MapSpecials mapSpecials;

//    for (int itemSlotNr = 0; toUInt(itemSlotNr) < gMAX_ITEMSLOTS; ++itemSlotNr)
//    {
//        if ((0 == m_hiredHero) || (0 == m_game))
//            break;
//        MoM::Item* item = m_game->getItem(m_hiredHero->m_Items_In_Slot[itemSlotNr]);
//        if (0 == item)
//            continue;

//        // TODO
////        ADDMFIELDFEATURE(mapSpecials, item, Item_Name);
////        ADDMFIELDFEATURE(mapSpecials, item, Icon);
////        ADDMFIELDFEATURE(mapSpecials, item, Slot_Required);
////        ADDMFIELDFEATURE(mapSpecials, item, Item_Type);
////        ADDMFIELDFEATURE(mapSpecials, item, Cost);

////        ADDFIELDFEATURE(mapSpecials, (int)item->m_Bonuses, Attack);
////        ADDFIELDFEATURE(mapSpecials, (int)item->m_Bonuses, To_Hit);
////        ADDFIELDFEATURE(mapSpecials, (int)item->m_Bonuses, Defense);
////        ADDFIELDFEATURE(mapSpecials, (int)item->m_Bonuses, Movement_in_halves);
////        ADDFIELDFEATURE(mapSpecials, (int)item->m_Bonuses, Resistance);
////        ADDFIELDFEATURE(mapSpecials, (int)item->m_Bonuses, Spell_Points);
////        ADDFIELDFEATURE(mapSpecials, -(int)item->m_Bonuses, Spell_Save);

////        ADDMFIELDFEATURE(mapSpecials, item, Spell_Number_Charged);
////        ADDMFIELDFEATURE(mapSpecials, item, Number_Of_Charges);

//    }

//    return mapSpecials;
//}

Item* MoMUnit::getSlotItem(int itemSlotNr) const
{
    Item* item = 0;
    if ((0 != m_hiredHero) && (0 != m_game))
    {
        int itemNr = m_hiredHero->m_Items_In_Slot[itemSlotNr];
        item = m_game->getItem(itemNr);
    }
    return item;
}

eSlot_Type16 MoMUnit::getSlotType(int itemSlotNr) const
{
    eSlot_Type16 value = (eSlot_Type16)0;
    if ((0 != m_hiredHero) && (toUInt(itemSlotNr) < gMAX_ITEMSLOTS))
    {
        value = m_hiredHero->m_Slot_Types[itemSlotNr];
    }
    else if ((0 != m_unitType) && isHero())
    {
        // TODO: Centralize hero->itemslot code, including the same code in MoMController

        eSlot_Type16 heroSlotTypes[3];
       // Retrieve the slot types
       if (toUInt(m_unitType->m_Hero_TypeCode_or_Building2) <= toUInt(HEROTYPE_Wizard))
       {
           heroSlotTypes[0] = static_cast<eSlot_Type16>(1 + m_unitType->m_Hero_TypeCode_or_Building2);
           if (HEROTYPE_Wizard == m_unitType->m_Hero_TypeCode_or_Building2)
           {
               heroSlotTypes[1] = SLOT16_Amulet;
           }
           else
           {
               heroSlotTypes[1] = SLOT16_Armor_Shield;
           }
           heroSlotTypes[2] = SLOT16_Amulet;
       }
       else
       {
           unsigned slotCode = static_cast<unsigned>(m_unitType->m_Hero_TypeCode_or_Building2);
           slotCode -= 6;
           heroSlotTypes[0] = static_cast<eSlot_Type16>(1 + slotCode % 6);
           slotCode /= 6;
           heroSlotTypes[1] = static_cast<eSlot_Type16>(1 + slotCode % 6);
           slotCode /= 6;
           heroSlotTypes[2] = static_cast<eSlot_Type16>(1 + slotCode % 6);
       }

       if (toUInt(itemSlotNr) < 3)
       {
           value = heroSlotTypes[itemSlotNr];
       }
    }
    return value;
}

int MoMUnit::getLevel() const
{
    int value = 0;
    if (0 != m_unit)
    {
        value = 1 + m_unit->m_Level;
    }
    else if (0 != m_heroStats)
    {
        value = static_cast<int16_t>(m_heroStats->m_Level_Status);
		if (m_heroStats->m_Level_Status == HEROLEVELSTATUS_Active_in_Wizards_army)
		{
			value = 0;
		}
        else if (value < 0)
        {
            value = -value;
        }
        else
        {
            value++;
        }
    }
    return value;
}

std::string MoMUnit::getLevelName() const
{
    std::string name;
    MoMDataSegment* dataSegment = 0;
    int level = getLevel();
    if ((0 != m_game) && (level > 0) && (0 != (dataSegment = m_game->getDataSegment())))
    {
        level--;
        if (isHero() && (level < ARRAYSIZE(dataSegment->m_HeroLevelNameOffsets)))
        {
            name = m_game->getNameByOffset(dataSegment->m_HeroLevelNameOffsets[level]);
        }
        else if (level < ARRAYSIZE(dataSegment->m_UnitLevelNameOffsets))
        {
            name = m_game->getNameByOffset(dataSegment->m_UnitLevelNameOffsets[level]);
        }
    }
    return name;
}

// TODO: Eliminate using getActualAttributes() instead
double MoMUnit::getMoves() const
{
    double value = 0;
    if (0 != m_unit)
    {
        value = m_unit->m_Moves_Total / 2.0;
    }
    else if (0 != m_unitType)
    {
        value = m_unitType->m_MoveHalves / 2.0;
    }
    return value;
}

int MoMUnit::getCastingSkillBase() const
{
    int value = 0;
    if (0 != m_heroStats)
    {
        value = m_heroStats->m_Hero_Casting_Skill;
    }
    else if (0 != m_heroStatsInitializer)
    {
        value = m_heroStatsInitializer->m_Hero_Casting_Skill;
    }
    return value;
}

int MoMUnit::getCastingSkillTotal() const
{
    int value = getCastingSkillBase();
    if (getLevel() > 0)
    {
        value = static_cast<int>(getLevel() * (1 + getCastingSkillBase()) * 5 / 2);
    }
    return value;
}

int MoMUnit::getConstructionSkill() const
{
    int value = 0;
    if (0 != m_unitType)
    {
        value = m_unitType->m_Construction;
    }
    return value;
}

int MoMUnit::getCost() const
{
    int value = 0;
    if (0 != m_unitType)
    {
        value = m_unitType->m_Cost;
    }
    return value;
}

int MoMUnit::getNrFigures() const
{
    int value = 0;
    if (0 != m_unitType)
    {
        value = m_unitType->m_Nr_Figures;
    }
    return value;
}

MoMUnit::BaseAttributes MoMUnit::getPenaltyAttributes() const
{
    return m_penalties;
}

eRace MoMUnit::getRace() const
{
    eRace value = (eRace)0;
    if (0 != m_unitType)
    {
        value = m_unitType->m_Race_Code;
    }
    return value;
}

std::string MoMUnit::getRaceName() const
{
    std::string name;
    if ((0 != m_game) && (0 != m_unitType))
    {
        name = m_game->getRaceName(m_unitType->m_Race_Code);
    }
    return name;
}

int MoMUnit::getRangedShots() const
{
    int value = 0;
    if (0 != m_unitType)
    {
        value = m_unitType->m_Ranged_Shots;
    }
    return value;
}

eRanged_Type MoMUnit::getRangedType() const
{
    eRanged_Type value = MoM::RANGED_None;
    if (0 != m_unitType)
    {
        value = m_unitType->m_Ranged_Type;
    }
    return value;
}

MoMUnit::ListBuildings MoMUnit::getRequiredBuildings() const
{
    ListBuildings value;

    if ((0 != m_unitType) && isNormal())
    {
        if ((toUInt(m_unitType->m_Building_Required1) >= BUILDING_Barracks)
            && (toUInt(m_unitType->m_Building_Required1) < eBuilding_MAX))
        {
            value.push_back((eBuilding)m_unitType->m_Building_Required1);
        }
        if ((toUInt(m_unitType->m_Hero_TypeCode_or_Building2) >= BUILDING_Barracks)
            && (toUInt(m_unitType->m_Hero_TypeCode_or_Building2) < eBuilding_MAX))
        {
            value.push_back((eBuilding)m_unitType->m_Hero_TypeCode_or_Building2);
        }
    }
    return value;
}

int MoMUnit::getScouting() const
{
    int value = 0;
    if (0 != m_unitType)
    {
        value = m_unitType->m_Scouting;
    }
    return value;
}

int MoMUnit::getSpecial(eHeroAbility heroAbility) const
{
    int bonus = 0;
    int level = getLevel();
    switch (heroAbility)
    {
    case HEROABILITY_Agility:          { bonus = level; break; }
    case HEROABILITY_Agility_X:        { bonus = static_cast<int>(level * 3 / 2); break; }
    case HEROABILITY_Arcane_Power:     { bonus = level; break; }
    case HEROABILITY_Arcane_Power_X:   { bonus = static_cast<int>(level * 3 / 2); break; }
    case HEROABILITY_Armsmaster:       { bonus = 2 * level; break; }
    case HEROABILITY_Armsmaster_X:     { bonus = static_cast<int>(2 * level * 3 / 2); break; }
    case HEROABILITY_Blademaster:      { bonus = static_cast<int>(level / 2); break; }
    case HEROABILITY_Blademaster_X:    { bonus = static_cast<int>(level * 3 / 4); break; }
//    case HEROABILITY_Caster:           { bonus = static_cast<int>(level * (1 + getCastingSkillBase()) * 5 / 2); break; }
    case HEROABILITY_Constitution:     { bonus = level; break; }
    case HEROABILITY_Constitution_X:   { bonus = static_cast<int>(level * 3 / 2); break; }
    case HEROABILITY_Leadership:       { bonus = static_cast<int>(level / 3); break; }
    case HEROABILITY_Leadership_X:     { bonus = static_cast<int>(level / 2); break; }

    case HEROABILITY_Legendary:        { bonus = 3 * level; break; }
    case HEROABILITY_Legendary_X:      { bonus = static_cast<int>(3 * level * 3 / 2); break; }
    case HEROABILITY_Lucky:            { break; }
    case HEROABILITY_Might:            { bonus = level; break; }
    case HEROABILITY_Might_X:          { bonus = static_cast<int>(level * 3 / 2); break; }
    case HEROABILITY_Noble:            { break; }
    case HEROABILITY_Prayermaster:     { bonus = level; break; }
    case HEROABILITY_Prayermaster_X:   { bonus = static_cast<int>(level * 3 / 2); break; }
    case HEROABILITY_Sage:             { bonus = 3 * level; break; }
    case HEROABILITY_Sage_X:           { bonus = static_cast<int>(3 * level * 3 / 2); break; }

    default:                           { break; }
    }
    return bonus;
}

int MoMUnit::getSpecial(eUnitAbility unitAbility) const
{
    int bonus = 0;
    if (0 == m_unitType)
        return 0;
    switch (unitAbility)
    {
    case UNITABILITY_Holy_Bonus:
    case UNITABILITY_Resistance_to_All:
    case UNITABILITY_Poison_attack:
    case UNITABILITY_Life_Stealing:
    case UNITABILITY_Stoning_Touch:
    case UNITABILITY_Death_Touch:
    case UNITABILITY_Power_Drain:
    case UNITABILITY_Dispel_Evil:     { bonus = m_unitType->m_Gaze_Modifier; break; }
    default:                          { break; }
    }
    return bonus;
}

int MoMUnit::getTransportCapacity() const
{
    int value = 0;
    if (0 != m_unitType)
    {
        value = m_unitType->m_Transport_Capacity;
    }
    return value;
}

std::string MoMUnit::getUnitName() const
{
    std::string name;
    if ((0 != m_unitType) && (0 != m_game))
    {
        const char* ptrName = m_game->getNameByOffset(m_unitType->m_PtrName);
        if (0 != ptrName)
        {
            name = ptrName;
        }
    }
    return name;
}

eUnit_Type MoMUnit::getUnitTypeNr() const
{
    eUnit_Type value = (MoM::eUnit_Type)-1;
    if ((0 != m_unit))
    {
        value = m_unit->m_Unit_Type;
    }
    else if ((0 != m_unitType) && (0 != m_game))
    {
        MoM::MoMGameBase* game = const_cast<MoM::MoMGameBase*>(m_game);
        value = game->getUnitTypeNr(m_unitType);
    }
    else if ((0 != m_heroStatsInitializer) && (0 != m_game))
    {
        MoM::MoMGameBase* game = const_cast<MoM::MoMGameBase*>(m_game);
        value = game->getUnitTypeNr(m_heroStatsInitializer);
    }
    else
    {
    }
    return value;
}

int MoMUnit::getUpkeep() const
{
    int value = 0;
    if (0 != m_unitType)
    {
        value = m_unitType->m_Upkeep;
    }
    return value;
}

eWeaponType MoMUnit::getWeaponType() const
{
    eWeaponType value = MoM::WEAPON_normal;
    if (0 != m_unit)
    {
        value = static_cast<eWeaponType>(m_unit->m_Weapon_Mutation.s.Weapon_Type);
    }
    return value;
}

int MoMUnit::getXP() const
{
    int value = 0;
    if (0 != m_unit)
    {
        value = m_unit->m_Experience;
    }
    return value;
}

bool MoMUnit::hasMagicalBreathAttack() const
{
    eRanged_Type rangedType = getRangedType();
    bool value = ((rangedType == MoM::RANGED_Fire_Breath)
                  || (rangedType == MoM::RANGED_Lightning_Breath));
    return value;
}

bool MoMUnit::hasMagicalGazeAttack() const
{
    eRanged_Type rangedType = getRangedType();
    bool value = ((rangedType == MoM::RANGED_Stoning_Gaze)
                  || (rangedType == MoM::RANGED_Multiple_Gaze)
                  || (rangedType == MoM::RANGED_Death_Gaze));
    return value;
}

bool MoMUnit::hasMagicalRangedAttack() const
{
    eRanged_Type rangedType = getRangedType();
    bool value = ((rangedType >= MoM::RANGED_Chaos_Magic1_Storm_Giant)
                  && (rangedType < MoM::RANGED_Thrown_Weapons));
    return value;
}

bool MoMUnit::hasMissileRangedAttack() const
{
    eRanged_Type rangedType = getRangedType();
    bool value = ((rangedType == MoM::RANGED_Arrow)
                  || (rangedType == MoM::RANGED_Bullet)
                  || (rangedType == MoM::RANGED_Rock));
    return value;
}

bool MoMUnit::hasPhysicalRangedAttack() const
{
    bool value = (hasMissileRangedAttack() || hasThrownRangedAttack());
    return value;
}

bool MoMUnit::hasThrownRangedAttack() const
{
    eRanged_Type rangedType = getRangedType();
    bool value = (rangedType == MoM::RANGED_Thrown_Weapons);
    return value;
}

bool MoMUnit::hasSpecial(eHeroAbility heroAbility) const
{
    bool value = false;
    if (m_heroStats != 0)
    {
        value = (1 & (m_heroStats->m_Hero_Abilities.bits >> heroAbility));
    }
    else if (m_heroStatsInitializer != 0)
    {
        value = (1 & (m_heroStatsInitializer->m_Hero_Abilities.bits >> heroAbility));
    }
    else
    {
        // No hero information
    }
    return value;
}

bool MoMUnit::hasSpecial(eItemPower itemPower) const
{
    bool value = false;
    if ((m_game != 0) && (m_hiredHero != 0))
    {
        for (size_t slotNr = 0; !value && (slotNr < gMAX_ITEMSLOTS); ++slotNr)
        {
            int16_t itemNr = m_hiredHero->m_Items_In_Slot[slotNr];
            Item* item = m_game->getItem(itemNr);
            if (item != 0)
            {
                value = (1 & (item->m_Bitmask_Powers.bits >> itemPower));
            }
        }
    }
    return value;
}

bool MoMUnit::hasSpecial(eUnitAbility unitAbility) const
{
    bool value = false;
    if (m_unitType != 0)
    {
        unsigned offset = unitAbility / 8;
        unsigned shift = unitAbility % 8;
        uint8_t* ptr = &m_unitType->m_Movement_Flags.bits;
        value = (1 & (ptr[offset] >> shift));
    }
    return value;
}

bool MoMUnit::hasSpecial(eUnitEnchantment unitAbility) const
{
    bool value = false;
    if (m_unit != 0)
    {
        value = (1 & (m_unit->m_Unit_Enchantment.bits >> unitAbility));
    }
    return value;
}

bool MoMUnit::hasSpecial(eUnitMutation unitMutation) const
{
    bool value = false;
    if ((m_unit != 0) && (unitMutation >= UNITMUTATION_Chaos_Channels_Demon_Skin))
    {
        value = (1 & (m_unit->m_Weapon_Mutation.bits >> unitMutation));
    }
    return value;
}

bool MoMUnit::isHero() const
{
	// TODO: A hero only counts as a hero if he occupies a hired hero slot.
    return (toUInt(getUnitTypeNr()) < gMAX_HERO_TYPES);
}

bool MoMUnit::isNormal() const
{
    return ((toUInt(getUnitTypeNr()) >= gMAX_HERO_TYPES)
            && (getUnitTypeNr() < UNITTYPE_Arcane_Magic_Spirit));
}

bool MoMUnit::isSummoned() const
{
    return (getUnitTypeNr() >= UNITTYPE_Arcane_Magic_Spirit);
}

void MoMUnit::setGame(MoMGameBase* game)
{
    close();
    m_game = game;
}

void MoMUnit::applyEffects()
{
    applyAbilities();
    applyItems();
    applyLevel();
    applyWeaponType();
    applySpells();

    // Check differences with Battle_Unit if available
    if (0 != m_battleUnit)
    {
        BaseAttributes actualAttr = getActualAttributes();
		std::cout << "Verify battle unit fields" << std::endl;
		if (actualAttr.melee != m_battleUnit->m_Melee || this->m_bonuses.melee != m_battleUnit->m_Extra_Attack)
		{
            std::cout << "Melee calc=" << actualAttr.melee << " bonus=" << m_bonuses.melee << " battleUnit=" << (int)m_battleUnit->m_Melee << " battle.extraAtt=" << (int)m_battleUnit->m_Extra_Attack << std::endl;
		}
		if (actualAttr.ranged != m_battleUnit->m_Ranged || this->m_bonuses.ranged != m_battleUnit->m_Extra_Ranged)
		{
            std::cout << "Ranged calc=" << actualAttr.ranged << " bonus=" << m_bonuses.ranged << " battleUnit=" << (int)m_battleUnit->m_Ranged << " battle.extraRa=" << (int)m_battleUnit->m_Extra_Ranged << std::endl;
		}
		if (actualAttr.defense != m_battleUnit->m_Defense || this->m_bonuses.defense != m_battleUnit->m_Extra_Defense)
		{
            std::cout << "Defense calc=" << actualAttr.defense << " bonus=" << m_bonuses.defense << " battleUnit=" << (int)m_battleUnit->m_Defense << " battle.extraDf=" << (int)m_battleUnit->m_Extra_Defense << std::endl;
		}
		if (actualAttr.toHitMelee != m_battleUnit->m_To_Hit + m_battleUnit->m_Extra_ToHit_Melee || this->m_bonuses.toHitMelee != m_battleUnit->m_Extra_ToHit_Melee)
		{
            std::cout << "ToHit Melee calc=" << actualAttr.toHitMelee << " bonus=" << m_bonuses.toHitMelee << " battleUnit=" << (int)m_battleUnit->m_To_Hit << " battle.extraToMe=" << (int)m_battleUnit->m_Extra_ToHit_Melee << std::endl;
		}
		if (actualAttr.toHitRanged != m_battleUnit->m_To_Hit + m_battleUnit->m_Extra_ToHit_Ranged || this->m_bonuses.toHitRanged != m_battleUnit->m_Extra_ToHit_Ranged)
		{
            std::cout << "ToHit Ranged calc=" << actualAttr.toHitRanged << " bonus=" << m_bonuses.toHitRanged << " battleUnit=" << (int)m_battleUnit->m_To_Hit << " battle.extraToRa=" << (int)m_battleUnit->m_Extra_ToHit_Ranged << std::endl;
		}
		if (actualAttr.toDefend != m_battleUnit->m_Extra_ToDefend)
		{
            std::cout << "ToDefend calc=" << actualAttr.toDefend << " bonus=" << m_bonuses.toDefend << " battleUnit=N/A" << " battle.extraToDf=" << (int)m_battleUnit->m_Extra_ToDefend << std::endl;
		}
		if (actualAttr.moves != m_battleUnit->m_MoveHalves / 2.0)
		{
			std::cout << "Moves calc=" << actualAttr.moves << " get=" << getMoves() << " battleUnit=" << m_battleUnit->m_MoveHalves / 2.0 << std::endl;
		}
		if (getGazeModifier() != m_battleUnit->m_Gaze_Modifier)
		{
            std::cout << "Gaze calc=" << getGazeModifier() << " battleUnit=" << (int)m_battleUnit->m_Gaze_Modifier << std::endl;
		}
    }
}

void MoMUnit::applyAbilities()
{
    m_upAbilities = BaseAttributes();
    BaseAttributes& up = m_upAbilities;
    BaseAttributes up_gold;
    int level = getLevel();
    int bonus = 0;
    int holy_bonus = 0;
    int prayer_bonus = 0;

    // Hero specific
    if (hasSpecial(HEROABILITY_Agility))        { up.defense += bonus = level; }
    if (hasSpecial(HEROABILITY_Agility_X))      { up.defense += bonus = static_cast<int>(level * 3 / 2); }
    if (hasSpecial(HEROABILITY_Arcane_Power))   { up.ranged += bonus = level; }
    if (hasSpecial(HEROABILITY_Arcane_Power_X)) { up.ranged += bonus = static_cast<int>(level * 3 / 2); }
    if (hasSpecial(HEROABILITY_Armsmaster))     { bonus = 2 * level; }
    if (hasSpecial(HEROABILITY_Armsmaster_X))   { bonus = static_cast<int>(2 * level * 3 / 2); }
    if (hasSpecial(HEROABILITY_Blademaster))    { up.toHitMelee += bonus = static_cast<int>(level / 2); up.toHitRanged += bonus; }
    if (hasSpecial(HEROABILITY_Blademaster_X))  { up.toHitMelee += bonus = static_cast<int>(level * 3 / 4); up.toHitRanged += bonus; }
//    if (has("Caster"))         { bonus = static_cast<int>(level * (1 + getCastingSkill()) * 5 / 2); set_special("Caster", bonus); }
    if (hasSpecial(HEROABILITY_Constitution))   { up.hitpoints += bonus = level; }
    if (hasSpecial(HEROABILITY_Constitution_X)) { up.hitpoints += bonus = static_cast<int>(level * 3 / 2); }
	// Treat Leadership bonus as gold bonus, since application depends on highest Leadership in group
    if (hasSpecial(HEROABILITY_Leadership))     { up_gold.melee += bonus = static_cast<int>(level / 3); if (hasMissileRangedAttack()) up_gold.ranged += static_cast<int>(bonus / 2); }
    if (hasSpecial(HEROABILITY_Leadership_X))   { up_gold.melee += bonus = static_cast<int>(level / 2); if (hasMissileRangedAttack()) up_gold.ranged += static_cast<int>(bonus / 2); }

    if (hasSpecial(HEROABILITY_Legendary))      { bonus = 3 * level; }
    if (hasSpecial(HEROABILITY_Legendary_X))    { bonus = static_cast<int>(3 * level * 3 / 2); }
    if (hasSpecial(HEROABILITY_Lucky))          { up.toHitMelee += +1; up.toHitRanged += +1; up.toDefend += +1; up.resistance += +1; }
    if (hasSpecial(HEROABILITY_Might))          { up.melee += bonus = level; }
    if (hasSpecial(HEROABILITY_Might_X))        { up.melee += bonus = static_cast<int>(level * 3 / 2); }
    if (hasSpecial(HEROABILITY_Noble))          { ; }
    if (hasSpecial(HEROABILITY_Prayermaster))   { bonus = level; prayer_bonus = Max(prayer_bonus, bonus); }
    if (hasSpecial(HEROABILITY_Prayermaster_X)) { bonus = static_cast<int>(level * 3 / 2); prayer_bonus = Max(prayer_bonus, bonus); }
    if (hasSpecial(HEROABILITY_Sage))           { bonus = 3 * level; }
    if (hasSpecial(HEROABILITY_Sage_X))         { bonus = static_cast<int>(3 * level * 3 / 2);}

    // Unit specific
    if (hasSpecial(UNITABILITY_Holy_Bonus))     { bonus = getSpecial(UNITABILITY_Holy_Bonus); holy_bonus = Max(holy_bonus, bonus); }
    if (hasSpecial(UNITABILITY_Resistance_to_All)) { bonus = getSpecial(UNITABILITY_Resistance_to_All); prayer_bonus = Max(prayer_bonus, bonus); }

    // Process holy_bonus (highest applies)
    up_gold.melee += holy_bonus;
    up_gold.defense += holy_bonus;
    up_gold.resistance += holy_bonus;
    // Process prayer_bonus (highest applies)
    up_gold.resistance += prayer_bonus;

    // Add hero ability bonus where appropriate
    m_bonuses.addBonus(up_gold);
}

void MoMUnit::applyItems()
{
    m_upItems = BaseAttributes();
    BaseAttributes& up = m_upItems;

    for (int itemSlotNr = 0; toUInt(itemSlotNr) < gMAX_ITEMSLOTS; ++itemSlotNr)
    {
        if ((0 == m_hiredHero) || (0 == m_game))
            break;
        MoM::Item* item = m_game->getItem(m_hiredHero->m_Items_In_Slot[itemSlotNr]);
        if (0 == item)
            continue;

        // TODO: Verify how bonus depends on type of artifact
        //       E.g. bow only gives bonus to ranged and toHitRanged
        //       and not to melee or toHitMelee.
        switch (item->m_Item_Type)
        {
        case ITEMTYPE_Sword:
        case ITEMTYPE_Mace:
        case ITEMTYPE_Axe:
            up.melee += item->m_Bonuses.Attack;
            up.toHitMelee += item->m_Bonuses.To_Hit;
            if (getRangedType() == RANGED_Thrown_Weapons)
            {
                up.ranged += item->m_Bonuses.Attack;
                up.toHitRanged += item->m_Bonuses.To_Hit;
            }
            break;
        case ITEMTYPE_Bow:
            // Presumably missile ranged attack
            up.ranged += item->m_Bonuses.Attack;
            up.toHitRanged += item->m_Bonuses.To_Hit;
            break;
        case ITEMTYPE_Staff:
        case ITEMTYPE_Wand:
            // Presumably magical ranged attack
            up.ranged += item->m_Bonuses.Attack;
            break;
        case ITEMTYPE_Various:
            up.melee += item->m_Bonuses.Attack;
            up.ranged += item->m_Bonuses.Attack;
            break;
        case ITEMTYPE_Shield:
        case ITEMTYPE_Chain_Mail:
        case ITEMTYPE_Plate_Mail:
            up.melee += item->m_Bonuses.Attack;
            up.ranged += item->m_Bonuses.Attack;
			// TODO: Add special "Large Shield"
            break;
        default:
            break;
        }

        up.defense += item->m_Bonuses.Defense;
        up.resistance += item->m_Bonuses.Resistance;
        up.hitpoints += 0;
        up.moves += item->m_Bonuses.Movement_in_halves / 2.0;
    }

    m_bonuses.addBonus(up);
}

void MoMUnit::applyLevel()
{
    int level = getLevel();

    m_upLevel = BaseAttributes();
    BaseAttributes& up = m_upLevel;

	if (isHero())
	{
		switch (level)
		{
		default:
		case 0:
		case 1: break;
		case 2: up.melee = +1; up.ranged = +1; up.defense = +1; up.resistance = +1; up.hitpoints = +1; break;
		case 3: up.melee = +2; up.ranged = +2; up.defense = +1; up.resistance = +2; up.hitpoints = +2; up.toHitMelee = +1; break;
		case 4: up.melee = +3; up.ranged = +3; up.defense = +2; up.resistance = +3; up.hitpoints = +3; up.toHitMelee = +1; break;
		case 5: up.melee = +4; up.ranged = +4; up.defense = +2; up.resistance = +4; up.hitpoints = +4; up.toHitMelee = +1; break;
		case 6: up.melee = +5; up.ranged = +5; up.defense = +3; up.resistance = +5; up.hitpoints = +5; up.toHitMelee = +2; break;
		case 7: up.melee = +6; up.ranged = +6; up.defense = +3; up.resistance = +6; up.hitpoints = +6; up.toHitMelee = +2; break;
		case 8: up.melee = +7; up.ranged = +7; up.defense = +4; up.resistance = +7; up.hitpoints = +7; up.toHitMelee = +2; break;
		case 9: up.melee = +8; up.ranged = +8; up.defense = +4; up.resistance = +8; up.hitpoints = +8; up.toHitMelee = +3; break;
		}
	}
	else
	{
      switch (level)
      {
         default:
         case 0:
         case 1: break;
         case 2: up.melee = +1; up.ranged = +1;                  up.resistance = +1; break;
         case 3: up.melee = +1; up.ranged = +1; up.defense = +1; up.resistance = +2; break;
         case 4: up.melee = +2; up.ranged = +2; up.defense = +1; up.resistance = +3; up.hitpoints = +1; up.toHitMelee = +1; break;
         case 5: up.melee = +2; up.ranged = +2; up.defense = +2; up.resistance = +4; up.hitpoints = +1; up.toHitMelee = +2; break;
         case 6: up.melee = +3; up.ranged = +3; up.defense = +2; up.resistance = +5; up.hitpoints = +2; up.toHitMelee = +3; break;
      }
	}

    up.toHitRanged = up.toHitMelee;

//    // Add level bonus where appropriate
//    this.add_bonus(up);
    //    this.fixedunit.add_bonus(up);
}

void MoMUnit::applySpells(const MoMUnit *enemy)
{
    // TODO: other effects: spells

    m_dnSpells = BaseAttributes();
    m_upSpells = BaseAttributes();
    BaseAttributes& dn = m_dnSpells;
    BaseAttributes& up = m_upSpells;

#define hasUnitEnchantment(spell) \
    ((m_unit && m_unit->m_Unit_Enchantment.s.spell) \
            || (m_battleUnit && (m_battleUnit->m_Flags1_UnitEnchantment.s.spell \
                                 || m_battleUnit->m_Flags2_UnitEnchantment.s.spell)))

    //
    // First process spells on which other spells may depend (such as unit_type)
    //

    //    if (spell_active("Black Channels"))
    if (hasUnitEnchantment(Black_Channels))
    {
        up.melee += +3; up.ranged += +1; up.hitpoints += +1; up.resistance += +1; up.defense += +1;
        // add_special("Undead");
    }

    //if (spell_active("Chaos Channel"))
    if (m_unit && m_unit->m_Weapon_Mutation.s.Chaos_Channels_Demon_Skin)
    {
        up.defense += +2;
    }
    if (m_unit && m_unit->m_Weapon_Mutation.s.Chaos_Channels_Demon_Wings)
    {
//        if (!has("Flying"))
//            add_special("Flying", 2);
//        else if (get_special("Flying") < 2)
//            set_special("Flying", 2);
    }
    if (m_unit && m_unit->m_Weapon_Mutation.s.Chaos_Channels_Fiery_Breath)
    {
//        if (!has("Fire Breath"))
//            add_special("Fire Breath", 2);
//        else if (get_special("Fire Breath") < 2)
//            set_special("Fire Breath", 2);
    }

    //
    // Process the regular spells
    //

    // "Berserk" is processed last (after other effects on Me and Df)

    // "Black Channels" is processed earlier (before other effects depending on unit_type)

//    if (spell_active("Black Prayer"))
//    {
//        if (baseunit.Me) dn.Me += +1; dn.Df += +1; dn.Re += +2;
//    }

    // "Black Sleep" is processed last (after other effects on Me/Ra/Df/Re)

//    if (spell_active("Bless"))
//    {
//        if (enemy && (enemy.is_type("Death") || enemy.is_type("Chaos")))
//        {
//            // [Manual] says Df/Re+2, but [Game] and [Strategy Guide] say Df/Re+3.
//            // TODO: Df/Re only against R&G Melee, All Breath, R&G Magic Ranged, R&G Spells
//            up.Df += +3;
//            up.Re += +3;
//        }
//    }

    // "Blur" is processed last (after possible True Sightn)

    // "Chaos Channel" is processed earlier (before other effects depending on unit_type)

//    if ((spell_active("Chaos Surge") || enemy && enemy.spell_active("Chaos Surge")) && is_type("Chaos"))
//    {
//        if (baseunit.Me) up.Me += +2; if (baseunit.Ra) up.Ra += +2;
//        // [Strategy Guide]
//        up.Df += +2;
//    }

//    if (spell_active("Charm of Life"))
//    {
//        up.Hp += +Math.max(1, Math.floor(Hp / 4));
//    }

//    if (spell_active("Cloak of Fear"))
//    {
//        // Each turn each opposing unit must resist (Re +1) or cower in fear (cannot attack, but can still counter)
//    }

//    if (spell_active("Darkness") || enemy && enemy.spell_active("Darkness"))
//    {
//        if (is_type("Death"))
//        {
//            if (baseunit.Me) up.Me += +1; up.Df += +1; up.Re += +1;
//        }
//        else if (is_type("Life"))
//        {
//            if (baseunit.Me) dn.Me += +1; dn.Df += +1; dn.Re += +1;
//        }
//    }

//    if (spell_active("Eldritch Weapon"))
//    {
//        if (Me) add_special("Magic Weapon");      // Can hit creatures with Weapon Immunity
//    }
//    if (enemy && enemy.spell_active("Eldritch Weapon"))
//    {
//        dn.Tb += +1;                              // The To-Block (Tb) of the enemy is reduced by 1
//    }

//    if (spell_active("Elemental Armor"))
//    {
//        // TODO: Df/Re only against All Breath, R&G Magic Ranged, R&G Spells
//        // up.Df += +10;
//        up.Re += +10;
//    }

    //if (spell_active("Flame Blade"))
    if (hasUnitEnchantment(Flame_Blade))
    {
        up.melee += +2; if (hasMissileRangedAttack()) up.ranged += +2;
//        if (Me) add_special("Magic Weapon");      // Can hit creatures with Weapon Immunity
    }

//    if (spell_active("Flight") && !has("Flying"))
//    {
//        add_special("Flying", 0);                 // ??? amount = landbased move + 1
//    }

    //if (spell_active("Giant Strength"))
    if (hasUnitEnchantment(Giant_Strength))
    {
        up.melee += +1; if (hasThrownRangedAttack()) up.ranged += +1;
    }

//    if (spell_active("Guardian Wind"))
//    {
//        add_special("Missile Imm");
//    }

    // "Haste" is processed last (after other effects on Me and Ra)

//    if (spell_active("High Prayer"))
//    {
//        if (baseunit.Me) up.Me += +2; up.Df += +2; up.Re += +3; up.Th += +1; up.Th_Ra += +1; up.Tb += +1;
//    }

    //if (spell_active("Holy Armor"))
    if (hasUnitEnchantment(Holy_Armor))
    {
        up.defense += +2;
    }

    //if (spell_active("Holy Weapon"))
    if (hasUnitEnchantment(Holy_Weapon))
    {
//        if (Me) add_special("Magic Weapon");      // Can hit creatures with Weapon Immunity
        up.toHitMelee += +1;
        if (hasPhysicalRangedAttack()) up.toHitRanged += +1;
    }

//    if (spell_active("Immolation"))
//    {
//        if (has("Immolation"))
//            set_special("Immolation", Math.max(get_special("Immolation"), 4));
//        else
//            add_special("Immolation", 4);
//    }

//    if (spell_active("Invisibility"))
//    {
//        add_special("Invisibility");
//    }

    // Actual effect of "Invisibility" is processed last (after possible True Sight)

//    if (spell_active("Invulnerability"))
//    {
//        add_special("Weapon Imm");
//    }

    //if (spell_active("Iron Skin"))
    if (hasUnitEnchantment(Iron_Skin))
    {
        up.defense += +5;
    }

    //if (spell_active("Lion Heart"))
    if (hasUnitEnchantment(Lionheart))
    {
        // [Manual] says Me/Ra/Hp/Re +2, but [Game] shows Me/Ra/Hp/Re +3.
        up.melee += +3;
        if (hasPhysicalRangedAttack()) up.ranged += +3;
        up.hitpoints += +3;
        up.resistance += +3;
    }

//    if (spell_active("Magic Immunity"))
//    {
//        add_special("Magic Imm");
//    }

//    if (spell_active("Metal Fires"))
//    {
//        if (this.is_type("Normal") && !spell_active("Flame Blade"))
//        {
//            if (baseunit.Me) up.Me += +1; if (baseunit.Ra && range_type == "Physical" && !has("Rocks")) up.Ra += +1;
//            if (Me) add_special("Magic Weapon");      // Can hit creatures with Weapon Immunity
//        }
//    }

//    if (spell_active("Prayer"))
//    {
//        // Verified 2010-11-13 with [Tweaker] that Prayer and High Prayer do not stack
//        if (!spell_active("High Prayer"))
//        {
//            up.Th += +1; up.Th_Ra += +1; up.Tb += +1; up.Re += +1;
//        }
//    }

//    if (spell_active("Regeneration"))
//    {
//        add_special("Regeneration");
//    }

//    if (spell_active("Resist Elements"))
//    {
//        if (!spell_active("Elemental Armor"))
//        {
//            if (enemy && (enemy.is_type("Chaos") || enemy.is_type("Nature")))
//            {
//                // TODO: Df/Re only against All Breath, R&G Magic Ranged, R&G Spells
//                // Df+=3
//                up.Re += +3;
//            }
//        }
//    }

//    if (spell_active("Resist Magic"))
//    {
//        up.Re += +5;
//    }

//    if (spell_active("Righteousness"))
//    {
//        // TODO: Df/Re only against All Breath, B&R Magic Ranged, B&R Spells
//        // Df = (50)
//        up.Re += +30;
//    }

    // "Shatter" is processed last (after other effects on Me/Ra/Df/Re)

    //if (spell_active("Stone Skin"))
    if (hasUnitEnchantment(Stone_Skin))
    {
        up.defense += +1;
    }

//    if (spell_active("Terror"))
//    {
//        // Each turn the unit must resist (Re +1) or cower in fear (cannot attack, but can still counter)
//    }

//    if (spell_active("True Light") || enemy && enemy.spell_active("True Light"))
//    {
//        if (is_type("Life"))
//        {
//            if (baseunit.Me) up.Me += +1; up.Df += +1; up.Re += +1;
//        }
//        else if (is_type("Death"))
//        {
//            if (baseunit.Me) dn.Me += +1; dn.Df += +1; dn.Re += +1;
//        }
//    }

//    if (spell_active("True Sight"))
//    {
//        add_special("Illusion Imm");
//    }

    //if (spell_active("Vertigo"))
    if (m_battleUnit && m_battleUnit->m_Flags_Combat_Enchantment.Vertigo)
    {
        dn.toHitMelee += +2;
        dn.toHitRanged += +2;
        dn.defense += +1;
    }

    // "Warp Creature" is processed last (after other effects on Me/Ra/Df/Re)

//    if (spell_active("Warp Reality") || enemy && enemy.spell_active("Warp Reality"))
//    {
//        if (!is_type("Chaos")) { dn.Th += +2; dn.Th_Ra += +2; }
//    }

//    if (spell_active("Warp Wood"))
//    {
//        if (has("Arrows")) set_special("Arrows", 0);
//        if (has("Bullets")) set_special("Bullets", 0);
//    }

    //if (spell_active("Weakness"))
    if (m_battleUnit && m_battleUnit->m_Flags_Combat_Enchantment.Weakness)
    {
        dn.melee += +2; if (hasMissileRangedAttack()) dn.ranged += +2;
    }

    // "Web" is processed last (after Flight and Wraith Form)

//    if (spell_active("Wrack"))
//    {
//        // each enemy figure resists or loses 1 hp per turn
//    }

//    if (spell_active("Wraith Form"))
//    {
//        add_special("Weapon Imm");
//        add_special("Non Corporeal");
//    }


    //
    // Process the spells last that must be processed after other spells
    //

//    if (spell_active("Berserk"))
//    {
//        up.Me += Me; dn.Df += Df;
//    }

//    if (spell_active("Black Sleep"))
//    {
//        // Chance to resist initially.
//        // Me, Ra, Df are effective reduced to zero.
//        dn.Me = Me + up.Me;
//        dn.Ra = Ra + up.Ra;
//        dn.Df = Df + up.Df;
//    }

//    if (enemy && enemy.spell_active("Blur") && !has("Illusion Imm"))
//    {
//        // TODO: Proper processing: ignore 10% of hits or something like that
//        dn.Th += +1;
//        dn.Th_Ra += +1;
//    }

//    if (spell_active("Haste"))
//    {
//        if (baseunit.Me) up.Me += Me; if (baseunit.Ra) up.Ra += Ra;
//    }

//    if (enemy && enemy.has("Invisibility") && !has("Illusion Imm"))
//    {
//        dn.Th += +1;
//        dn.Th_Ra += +1;
//    }

//    if (spell_active("Shatter"))
//    {
//        // Resist or Me=Ra=1
//        dn.Me = Math.max(0, Me + up.Me - 1);
//        dn.Ra = Math.max(0, Ra + up.Ra - 1);
//    }

//    if (spell_active("Warp Creature"))
//    {
//        // Resist at -1 or (Me/2 or Df/2 or Re=0)
//        switch (1 * spells[ "Warp Creature" ])
//        {
//        case 1: dn.Me += Math.ceil(Me / 2); break;
//        case 2: dn.Df += Math.ceil(Df / 2); break;
//        case 3: dn.Re += Re; break;
//        }
//    }

//    if (spell_active("Web"))
//    {
//        // Web does not work on Non Corporeal creatures, and can not Web a unit while a previous Web still present
//        if (!has("Non Corporeal") && !has("Web"))
//        {
//            // The web (Df 0) must be destroyed by full combined melee and magic ranged attacks,
//            // before the unit can move again.
//            // The unit can no longer fly for the remainder of the combat
//            add_special("Web", 12);
//            delete_special("Flying");
//        }
//    }

    // Apply spell modifiers where appropriate
    m_bonuses.addBonus(up);
    m_penalties.addBonus(dn);
}

void MoMUnit::applyWeaponType()
{
	m_upWeaponType = BaseAttributes();
	BaseAttributes& up = m_upWeaponType;

	switch (getWeaponType())
	{
	default:
	case MoM::WEAPON_normal:  
		break;
	case MoM::WEAPON_magic: 
		// TODO: Magic Weapon
		//            if (Me) this.add_special("Magic Weapon");
		up.toHitMelee = +1;
		if (hasPhysicalRangedAttack()) up.toHitRanged = +1;
		break;
	case MoM::WEAPON_mithril: 
		//            if (Me) this.add_special("Magic Weapon");
		up.melee = +1;
		up.defense = +1;
		up.toHitMelee = +1;
		if (hasPhysicalRangedAttack())
		{
			up.toHitRanged = +1;
			up.ranged = +1;
		}
		break;
	case MoM::WEAPON_adamantium:
//		if (Me) this.add_special("Magic Weapon");
		up.melee = +2;
		up.defense = +2; 
		up.toHitMelee = +1;
		if (hasPhysicalRangedAttack())
		{
			up.toHitRanged = +1;
			up.ranged = +2;
		}
		break;
	}

	// Add weapon bonus where appropriate
    m_bonuses.addBonus(up);
}

bool MoMUnit::commitData(void *ptr, const void *pNewValue, size_t size)
{
    if ((0 == m_game) || (0 == ptr) || (0 == pNewValue))
        return false;
    return m_game->commitData(ptr, pNewValue, size);
}

void MoMUnit::BaseAttributes::addBonus(const MoMUnit::BaseAttributes& up)
{
    melee += up.melee;
    defense += up.defense;
    ranged += up.ranged;
    resistance += up.resistance;
    hitpoints += up.hitpoints;
    toHitMelee += up.toHitMelee;
    toHitRanged += up.toHitRanged;
    toDefend += up.toDefend;

    moves += up.moves;
}

bool MoMUnit::setUnitTypeData(const Unit_Type_Data &value)
{
    return commitData(m_unitType, &value, sizeof(value));
}

bool MoMUnit::setHeroStats(const Hero_stats &value)
{
    return commitData(m_heroStats, &value, sizeof(value));
}

}
