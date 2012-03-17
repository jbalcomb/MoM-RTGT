// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#ifndef MOMUNIT_H_
#define MOMUNIT_H_

#include <map>
#include <string>

#include "MoMTemplate.h"

namespace MoM
{

/// \brief Defines a class for accessing MoM units
class MoMUnit
{
public:
    typedef std::map<std::string, int> MapSpecials;

    struct BaseAttributes
    {
        BaseAttributes() :
            melee(),
            defense(),
            ranged(),
            resistance(),
            hitpoints(),
            toHitMelee(),
            toHitRanged(),
            toDefend()
        {}
        int melee;
        int defense;
        int ranged;
        int resistance;
        int hitpoints;
        int toHitMelee;
        int toHitRanged;
        int toDefend;
    };

    MoMUnit();
    virtual ~MoMUnit()
    {}

    void close();

    void setGame(MoMGameBase* game);
    void setUnitTypeNr(eUnit_Type unitTypeNr);
    eUnit_Type getUnitTypeNr() const
    {
        return m_unitTypeNr;
    }

    const char* getName() const;

    int getMelee() const;
    int getRanged() const;
    int getArmor() const;
    int getResist() const;
    int getHits() const;

    eRanged_Type getRangedType() const;
    MapSpecials getSpecials() const;
    int getToHitMelee() const;
    int getToHitRanged() const;
    int getToDefend() const;
    eWeaponType getWeaponType() const;

    bool hasSpecial(const std::string& specialName) const;

private:
    // NOT IMPLEMENTED
    MoMUnit(const MoMUnit& rhs);
    MoMUnit& operator=(const MoMUnit& rhs);

    // CONFIG
    MoMGameBase* m_game;
    eUnit_Type m_unitTypeNr;

    // STATUS
    Battle_Unit* m_battleUnit;
    Hero_stats* m_heroStats;
    Hero_Stats_Initializer* m_heroStatsInitializer;
    Hired_Hero* m_hiredHero;
    Unit* m_unit;
    Unit_Type_Data* m_unitType;
//    BaseAttributes m_up;
//    BaseAttributes m_dn;
};

}

#endif
