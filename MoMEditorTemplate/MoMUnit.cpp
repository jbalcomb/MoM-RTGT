// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include <assert.h>
#include <cmath>

#include "MoMGameBase.h"
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
    m_upAbilities(),
    m_upItems(),
    m_upLevel(),
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
    m_upAbilities(),
    m_upItems(),
    m_upLevel(),
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

void MoMUnit::close()
{
    m_battleUnit = 0;
    m_heroStats = 0;
    m_heroStatsInitializer = 0;
    m_hiredHero = 0;
    m_unitType = 0;
    m_unit = 0;
	m_bonuses = BaseAttributes();
    m_upAbilities = BaseAttributes();
    m_upItems = BaseAttributes();
    m_upLevel = BaseAttributes();
    m_upWeaponType = BaseAttributes();
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

//
// OTHER
//

MoMUnit::MapSpecials MoMUnit::getAbilityEffects() const
{
    MapSpecials mapSpecials;

#define ADDFLAGFEATURE(m, u, field) \
    if (u.s.field) \
    { \
        m[ MoM::replaceUnderscoresBySpaces(#field) ] = 0; \
    }
#define ADDMFIELDFEATURE(m, u, field) \
    if (u->m_##field != 0) \
    { \
        m[ MoM::replaceUnderscoresBySpaces(#field) ] = u->m_##field; \
    }

    if (0 != m_heroStats)
    {
        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Leadership);
        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Leadership_X);
        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Legendary);
        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Legendary_X);
        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Blademaster);
        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Blademaster_X);

        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Armsmaster);
        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Armsmaster_X);
        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Constitution);
        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Constitution_X);
        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Might);

        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Might_X);
        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Arcane_Power);
        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Arcane_Power_X);
        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Sage);
        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Sage_X);

        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Prayermaster);
        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Prayermaster_X);
        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Agility_X);
        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Lucky);
        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Charmed);
        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Noble);
        ADDFLAGFEATURE(mapSpecials, m_heroStats->m_Hero_Abilities, Agility);

        // Additional fields
        if (m_heroStats->m_Hero_Casting_Skill > 0)
        {
            int level = getLevel();
            if (0 == level)
            {
                level++;
            }
            int spellPoints = static_cast<int>(level * (1 + getCastingSkill()) * 5 / 2);
            mapSpecials["Caster"] = spellPoints;
        }
//        for (int spellNr = 0; spellNr < ARRAYSIZE(heroStats.m_Spell); ++spellNr)
//        {
//            if (MoM::SPELL_None != heroStats.m_Spell[spellNr])
//            {
//                ADDMFIELDFEATURE(qtreeHSFlags, heroStats, Spell[spellNr]);
//            }
//        }
    }

    if (0 != m_unitType)
    {
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Movement_Flags, Cavalry);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Movement_Flags, Sailing);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Movement_Flags, Swimming);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Movement_Flags, Flying);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Movement_Flags, Teleporting);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Movement_Flags, Forester);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Movement_Flags, Mountaineer);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Movement_Flags, Merging);

        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Immunity_Flags, Fire_Immunity);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Immunity_Flags, Stoning_Immunity);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Immunity_Flags, Missiles_Immunity);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Immunity_Flags, Illusions_Immunity);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Immunity_Flags, Cold_Immunity);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Immunity_Flags, Magic_Immunity);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Immunity_Flags, Death_Immunity);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Immunity_Flags, Poison_Immunity);

        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attribute_Flags, Weapon_Immunity);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attribute_Flags, Lucky);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attribute_Flags, Summon_Demons_1);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attribute_Flags, Summon_Demons_2);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attribute_Flags, Caster_20_MP);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attribute_Flags, Caster_40_MP);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attribute_Flags, Standard);

        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attribute_Flags, Healing_Spell);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attribute_Flags, Fire_Ball_Spell);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attribute_Flags, Doombolt_Spell);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attribute_Flags, Immolation);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attribute_Flags, Web_Spell);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attribute_Flags, Cause_Fear_Spell);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attribute_Flags, Resistance_to_All);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attribute_Flags, Holy_Bonus);

        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Ability_Flags, Summoned_Unit);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Ability_Flags, Large_Shield);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Ability_Flags, Plane_Shift);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Ability_Flags, Wall_Crusher);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Ability_Flags, Healer);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Ability_Flags, Create_Outpost);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Ability_Flags, Invisibility);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Ability_Flags, Create_Undead);

        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Ability_Flags, Long_Range);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Ability_Flags, Land_Corruption);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Ability_Flags, Meld_With_Node);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Ability_Flags, Non_Corporeal);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Ability_Flags, Wind_Walking);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Ability_Flags, Regeneration);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Ability_Flags, Purify);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Ability_Flags, Negate_First_Strike);

        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attack_Flags, Armor_Piercing);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attack_Flags, First_Strike);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attack_Flags, Poison_attack);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attack_Flags, Life_Stealing);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attack_Flags, Automatic_Damage);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attack_Flags, Destruction);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attack_Flags, Illusionary_attack);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attack_Flags, Stoning_Touch);

        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attack_Flags, Death_Touch);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attack_Flags, Power_Drain);
        ADDFLAGFEATURE(mapSpecials, m_unitType->m_Attack_Flags, Dispel_Evil);


        // Additional fields
//        ADDMFIELDFEATURE(mapSpecials, (unsigned)m_unitType, Ranged_Type);
//        ADDMFIELDFEATURE(mapSpecials, (unsigned)m_unitType, Ranged_Shots);
        if (m_unitType->m_Ranged_Shots != 0)
        {
			if (hasMissileRangedAttack())
			{
				mapSpecials["Arrows"] = m_unitType->m_Ranged_Shots;
			}
			else if (hasMagicalRangedAttack())
			{
				mapSpecials["Spells"] = m_unitType->m_Ranged_Shots;
			}
			else
			{
				mapSpecials["Ranged Shots"] = m_unitType->m_Ranged_Shots;
			}
        }
//        ADDMFIELDFEATURE(mapSpecials, (int)m_unitType, Cost);
//        ADDMFIELDFEATURE(mapSpecials, (unsigned)m_unitType, Building_Required1);
//        ADDMFIELDFEATURE(mapSpecials, (unsigned)m_unitType, Hero_TypeCode_or_Building2);
        if (m_unitType->m_Scouting != 1)
        {
            mapSpecials["Scouting"] = m_unitType->m_Scouting;
        }
        ADDMFIELDFEATURE(mapSpecials, (unsigned)m_unitType, Transport_Capacity);
        ADDMFIELDFEATURE(mapSpecials, (int)m_unitType, Construction);
        ADDMFIELDFEATURE(mapSpecials, (int)m_unitType, Gaze_Modifier);
    }

    if (0 != m_unit)
    {
		if (m_unit->m_Weapon_Mutation.s.Weapon_Type != MoM::WEAPON_normal)
		{
            mapSpecials["Magic Weapon"] = 0;
		}
        ADDFLAGFEATURE(mapSpecials, m_unit->m_Weapon_Mutation, Chaos_Channels_Demon_Skin);
        ADDFLAGFEATURE(mapSpecials, m_unit->m_Weapon_Mutation, Chaos_Channels_Demon_Wings);
        ADDFLAGFEATURE(mapSpecials, m_unit->m_Weapon_Mutation, Chaos_Channels_Fiery_Breath);
        ADDFLAGFEATURE(mapSpecials, m_unit->m_Weapon_Mutation, Undead);
        ADDFLAGFEATURE(mapSpecials, m_unit->m_Weapon_Mutation, Stasis_initial);
        ADDFLAGFEATURE(mapSpecials, m_unit->m_Weapon_Mutation, Stasis_lingering);
    }

#undef ADDMFIELDFEATURE
#undef ADDFLAGFEATURE

    return mapSpecials;
}

MoMUnit::BaseAttributes MoMUnit::getActualAttributes() const
{
    BaseAttributes base = getBaseAttributes();
    BaseAttributes bonus = getBonusAttributes();
    BaseAttributes actual = base;
    bonus.addBonus(m_upAbilities);
    bonus.addBonus(m_upLevel);

    if (base.melee != 0)   actual.melee   += bonus.melee;
    if (base.defense != 0) actual.defense += bonus.defense;
    if (base.ranged != 0)  actual.ranged  += bonus.ranged;
    actual.resistance   += bonus.resistance;
    actual.hitpoints    += bonus.hitpoints;
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
        base.defense = m_unitType->m_Melee;
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

std::string MoMUnit::getHeroName() const
{
    std::string name;
    if (0 != m_hiredHero)
    {
        name = m_hiredHero->m_Hero_name;
    }
    return name;
}

MoMUnit::MapSpecials MoMUnit::getItemEffects() const
{
    MapSpecials mapSpecials;

#define ADDFLAGFEATURE(m, u, field) \
    if (u.s.field) \
    { \
        m[ MoM::replaceUnderscoresBySpaces(#field) ] = 0; \
    }
#define ADDFIELDFEATURE(m, u, field) \
    if (u.field != 0) \
    { \
        m[ MoM::replaceUnderscoresBySpaces(#field) ] = u.field; \
    }
#define ADDMFIELDFEATURE(m, u, field) \
    if (u->m_##field != 0) \
    { \
        m[ MoM::replaceUnderscoresBySpaces(#field) ] = u->m_##field; \
    }

    for (int itemSlotNr = 0; toUInt(itemSlotNr) < gMAX_ITEMSLOTS; ++itemSlotNr)
    {
        if ((0 == m_hiredHero) || (0 == m_game))
            break;
        MoM::Item* item = m_game->getItem(m_hiredHero->m_Items_In_Slot[itemSlotNr]);
        if (0 == item)
            continue;

        // TODO
//        ADDMFIELDFEATURE(mapSpecials, item, Item_Name);
//        ADDMFIELDFEATURE(mapSpecials, item, Icon);
//        ADDMFIELDFEATURE(mapSpecials, item, Slot_Required);
//        ADDMFIELDFEATURE(mapSpecials, item, Item_Type);
//        ADDMFIELDFEATURE(mapSpecials, item, Cost);

//        ADDFIELDFEATURE(mapSpecials, (int)item->m_Bonuses, Attack);
//        ADDFIELDFEATURE(mapSpecials, (int)item->m_Bonuses, To_Hit);
//        ADDFIELDFEATURE(mapSpecials, (int)item->m_Bonuses, Defense);
//        ADDFIELDFEATURE(mapSpecials, (int)item->m_Bonuses, Movement_in_halves);
//        ADDFIELDFEATURE(mapSpecials, (int)item->m_Bonuses, Resistance);
//        ADDFIELDFEATURE(mapSpecials, (int)item->m_Bonuses, Spell_Points);
//        ADDFIELDFEATURE(mapSpecials, -(int)item->m_Bonuses, Spell_Save);

        ADDMFIELDFEATURE(mapSpecials, item, Spell_Number_Charged);
        ADDMFIELDFEATURE(mapSpecials, item, Number_Of_Charges);

        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Vampiric);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Guardian_Wind);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Lightning);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Cloak_Of_Fear);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Destruction);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Wraith_Form);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Regeneration);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Pathfinding);

        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Water_Walking);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Resist_Elements);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Elemental_Armour);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Doom_equals_Chaos);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Stoning);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Endurance);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Haste);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Invisibility);

        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Death);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Flight);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Resist_Magic);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Magic_Immunity);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Flaming);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Holy_Avenger);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, True_Sight);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Phantasmal);

        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Power_Drain);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Bless);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Lion_Heart);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Giant_Strength);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Planar_Travel);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Merging);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Righteousness);
        ADDFLAGFEATURE(mapSpecials, item->m_Bitmask_Powers, Invulnerability);
    }

#undef ADDMFIELDFEATURE
#undef ADDFIELDFEATURE
#undef ADDFLAGFEATURE

    return mapSpecials;
}

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
    else if (0 != m_unitType)
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

int MoMUnit::getCastingSkill() const
{
    int value = 0;
    if (0 != m_heroStats)
    {
        value = m_heroStats->m_Hero_Casting_Skill;
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

eRanged_Type MoMUnit::getRangedType() const
{
    eRanged_Type value = MoM::RANGED_None;
    if (0 != m_unitType)
    {
        value = m_unitType->m_Ranged_Type;
    }
    return value;
}

MoMUnit::MapSpecials MoMUnit::getSpecials() const
{
    MapSpecials mapSpecials = getAbilityEffects();
    MapSpecials mapItemEffects = getItemEffects();
    MapSpecials mapSpellEffects = getSpellEffects();

    mapSpecials.insert(mapItemEffects.begin(), mapItemEffects.end());
    mapSpecials.insert(mapSpellEffects.begin(), mapSpellEffects.end());

    return mapSpecials;
}

MoMUnit::MapSpecials MoMUnit::getSpellEffects() const
{
    MapSpecials mapSpecials;

#define ADDSPELLFLAGFEATURE(m, u, field) \
    if (u.s.field) \
    { \
        m[ MoM::replaceUnderscoresBySpaces(#field) ] = 0; \
    }

    if (0 != m_unit)
    {
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Immolation);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Guardian_Wind);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Berserk);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Cloak_of_Fear);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Black_Channels);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Wraith_Form);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Regeneration);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Path_Finding);

        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Water_Walking);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Resist_Elements);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Elemental_Armor);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Stone_Skin);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Iron_Skin);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Endurance);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Spell_Lock);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Invisibility);

        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Wind_Walking);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Flight);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Resist_Magic);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Magic_Immunity);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Flame_Blade);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Eldritch_Weapon);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, True_Sight);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Holy_Weapon);

        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Heroism);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Bless);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Lionheart);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Giant_Strength);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Planar_Travel);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Holy_Armor);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Righteousness);
        ADDSPELLFLAGFEATURE(mapSpecials, m_unit->m_Unit_Enchantment, Invulnerability);
    }

#undef ADDSPELLFLAGFEATURE

    return mapSpecials;
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

bool MoMUnit::hasMagicalRangedAttack() const
{
    eRanged_Type rangedType = getRangedType();
    bool value = ((rangedType != MoM::RANGED_None) && !hasPhysicalRangedAttack());
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

bool MoMUnit::hasSpecial(const std::string& specialName) const
{
    MapSpecials mapSpecials = getSpecials();
    return (mapSpecials.find(specialName) != mapSpecials.end());
}

bool MoMUnit::isHero() const
{
	// TODO: A hero only counts as a hero if he occupies a hired hero slot.
	return (toUInt(getUnitTypeNr()) < gMAX_HERO_TYPES);
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

    // TODO: other effects: spells

	// TODO: change bonus to 0 if unit has no melee, range, or defense.
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

    MapSpecials mapAbilities = getAbilityEffects();

#define has(str) (mapAbilities.find(str) != mapAbilities.end())
#define get_special(str) mapAbilities[str]
#define set_special(str, bonus)

    // Hero specific
    if (has("Agility"))        { up.defense += bonus = level; set_special("Agility", bonus); }
    if (has("Agility X"))      { up.defense += bonus = static_cast<int>(level * 3 / 2); set_special("Agility x", bonus); }
    if (has("Arcane Power"))   { up.ranged += bonus = level; set_special("Arcane Power", bonus); }
    if (has("Arcane Power X")) { up.ranged += bonus = static_cast<int>(level * 3 / 2); set_special("Arcane Power x", bonus); }
    if (has("Armsmaster"))     { bonus = 2 * level; set_special("Armsmaster", bonus); }
    if (has("Armsmaster X"))   { bonus = static_cast<int>(2 * level * 3 / 2); set_special("Armsmaster x", bonus); }
    // TODO: According to UnitView in Tweaker, Blademaster does not give a toHitRanged bonus
    // TODO: Adjust this also in the Battle simulator web pages
    if (has("Blademaster"))    { up.toHitMelee += bonus = static_cast<int>(level / 2); up.toHitRanged += bonus; set_special("Blademaster", bonus); }
    if (has("Blademaster X"))  { up.toHitMelee += bonus = static_cast<int>(level * 3 / 4); up.toHitRanged += bonus; set_special("Blademaster x", bonus); }
    if (has("Caster"))         { bonus = static_cast<int>(std::ceil(get_special("Caster") / 2.5 + 0.1) * 2.5 * level + 0.1); set_special("Caster", bonus); }
    if (has("Constitution"))   { up.hitpoints += bonus = level; set_special("Constitution", bonus); }
    if (has("Constitution X")) { up.hitpoints += bonus = static_cast<int>(level * 3 / 2); set_special("Constitution", bonus); }
    if (has("Leadership"))     { up.melee += bonus = static_cast<int>(level / 3); if (hasMissileRangedAttack()) up.ranged += static_cast<int>(bonus / 2); set_special("Leadership", bonus); }
    if (has("Leadership X"))   { up.melee += bonus = static_cast<int>(level / 2); if (hasMissileRangedAttack()) up.ranged += static_cast<int>(bonus / 2); set_special("Leadership x", bonus); }

    if (has("Legendary"))      { bonus = 3 * level; set_special("Legendary", bonus); }
    if (has("Legendary X"))    { bonus = static_cast<int>(3 * level * 3 / 2); set_special("Legendary x", bonus); }
    if (has("Lucky"))          { up.toHitMelee += +1; up.toHitRanged += +1; up.toDefend += +1; up.resistance += +1; }
    if (has("Might"))          { up.melee += bonus = level; set_special("Might", bonus); }
    if (has("Might X"))        { up.melee += bonus = static_cast<int>(level * 3 / 2); set_special("Might x", bonus); }
	if (has("Noble"))          { ; }
    if (has("Prayermaster"))   { bonus = level; set_special("Prayermaster", bonus); prayer_bonus = Max(prayer_bonus, bonus); }
    if (has("Prayermaster X")) { bonus = static_cast<int>(level * 3 / 2); set_special("Prayermaster x", bonus); prayer_bonus = Max(prayer_bonus, bonus); }
    if (has("Sage"))           { bonus = 3 * level; set_special("Sage", bonus); }
    if (has("Sage X"))         { bonus = static_cast<int>(3 * level * 3 / 2); set_special("Sage x", bonus); }

    // Unit specific
    if (has("Holy Bonus"))     { bonus = get_special("Holy Bonus"); holy_bonus = Max(holy_bonus, bonus); }
    if (has("Resistance to All")) { bonus = get_special("Resistance to All"); prayer_bonus = Max(prayer_bonus, bonus); }

#undef set_special
#undef has

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
            if (getRangedType() == RANGED_Thrown_Weapons)
            {
                up.ranged += item->m_Bonuses.Attack;
            }
            up.toHitMelee += item->m_Bonuses.To_Hit;
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
		case 5: up.melee = +4; up.ranged = +4; up.defense = +2; up.resistance = +4; up.hitpoints = +4; up.toHitMelee = +2; break;
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
    m_upAbilities = rhs.m_upAbilities;
    m_upItems = rhs.m_upItems;
    m_upLevel = rhs.m_upLevel;
    m_upWeaponType = rhs.m_upWeaponType;
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

}
