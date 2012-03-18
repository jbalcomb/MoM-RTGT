// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include <assert.h>

#include "MoMGameBase.h"
#include "MoMutility.h"

#include "MoMUnit.h"

namespace MoM
{

MoMUnit::MoMUnit() :
    m_game(),
    m_unitTypeNr(),
    m_battleUnit(),
    m_heroStats(),
    m_heroStatsInitializer(),
    m_hiredHero(),
    m_unit(),
    m_unitType(),
    m_up(),
    m_dn()
{
}

void MoMUnit::close()
{
    m_battleUnit = 0;
    m_heroStats = 0;
    m_heroStatsInitializer = 0;
    m_hiredHero = 0;
    m_unitType = 0;
    m_unit = 0;
    m_up = BaseAttributes();
    m_dn = BaseAttributes();
}

int MoMUnit::getMelee() const
{
    int value = 0;
    if (0 != m_unitType)
    {
        value = m_unitType->m_Melee;
    }
    return value;
}

int MoMUnit::getRanged() const
{
    int value = 0;
    if (0 != m_unitType)
    {
        value = m_unitType->m_Ranged;
    }
    return value;
}

int MoMUnit::getArmor() const
{
    int value = 0;
    if (0 != m_unitType)
    {
        value = m_unitType->m_Defense;
    }
    return value;
}

int MoMUnit::getResist() const
{
    int value = 0;
    if (0 != m_unitType)
    {
        value = m_unitType->m_Resistance;
    }
    return value;
}

int MoMUnit::getHits() const
{
    int value = 0;
    if (0 != m_unitType)
    {
        value = m_unitType->m_Hitpoints;
    }
    return value;
}

std::string MoMUnit::getDisplayName() const
{
    std::string raceName = getRaceName();
    std::string unitName = getUnitName();

    std::string name = raceName + " " + unitName;

    return name;
}

double MoMUnit::getMoves() const
{
    double value = 0;
    if (0 != m_unitType)
    {
        value = m_unitType->m_MoveHalves / 2.0;
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
//        ADDMFIELDFEATURE(qtreeHSFlags, heroStats, Level_Status);
//        ADDMFIELDFEATURE(qtreeHSFlags, (unsigned)heroStats, Hero_Casting_Skill);
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
//        ADDMFIELDFEATURE(mapSpecials, (int)m_unitType, Cost);
//        ADDMFIELDFEATURE(mapSpecials, (unsigned)m_unitType, Building_Required1);
//        ADDMFIELDFEATURE(mapSpecials, (unsigned)m_unitType, Hero_TypeCode_or_Building2);
        if (m_unitType->m_Scout != 1)
        {
            ADDMFIELDFEATURE(mapSpecials, (unsigned)m_unitType, Scout);
        }
        ADDMFIELDFEATURE(mapSpecials, (unsigned)m_unitType, Transport_Capacity);
        ADDMFIELDFEATURE(mapSpecials, (int)m_unitType, Construction);
        ADDMFIELDFEATURE(mapSpecials, (int)m_unitType, Gaze_Modifier);
    }

#undef ADDFLAGFEATURE

    return mapSpecials;
}


int MoMUnit::getToHitMelee() const
{
    int value = 0;
    if (0 != m_unitType)
    {
        value = m_unitType->m_To_Hit + m_up.toHitMelee - m_dn.toHitMelee;
    }
    return value;
}

int MoMUnit::getToHitRanged() const
{
    int value = 0;
    if (0 != m_unitType)
    {
        value = m_unitType->m_To_Hit + m_up.toHitRanged - m_dn.toHitRanged;
    }
    return value;
}

int MoMUnit::getToDefend() const
{
    int value = 0 + m_up.toDefend - m_dn.toDefend;
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

bool MoMUnit::hasSpecial(const std::string& specialName) const
{
    MapSpecials mapSpecials = getSpecials();
    return (mapSpecials.find(specialName) != mapSpecials.end());
}

void MoMUnit::setGame(MoMGameBase* game)
{
    m_game = game;
    setUnitTypeNr(m_unitTypeNr);
}

void MoMUnit::setUnitTypeNr(eUnit_Type unitTypeNr)
{
    close();

    m_unitTypeNr = unitTypeNr;

    if (0 != m_game)
    {
//        m_battleUnit = m_game->getBattle_Units();
        m_heroStats = m_game->getHero_stats(MoM::PLAYER_YOU, m_unitTypeNr);
//        m_heroStatsInitializer = 0;
//        m_hiredHero = 0;
        m_unitType = m_game->getUnit_Type_Data(m_unitTypeNr);
//        m_unit = 0;

        // TODO: Lucky should be centralized in a neat function or something
        if (hasSpecial("Lucky"))
        {
            m_up.toHitMelee++;
            m_up.toHitRanged++;
            m_up.toDefend++;
            m_up.resistance++;
        }
    }
}

}
