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
            toDefend(),
            moves()
        {}
        void addBonus(const BaseAttributes& up);

        int melee;
        int defense;
        int ranged;
        int resistance;
        int hitpoints;
        int toHitMelee;
        int toHitRanged;
        int toDefend;
        double moves;
    };

    MoMUnit();
    explicit MoMUnit(MoM::MoMGameBase* game);
    virtual ~MoMUnit();
    MoMUnit(const MoMUnit& rhs);
    MoMUnit& operator=(const MoMUnit& rhs);

    void close();

    void changeUnit(eUnit_Type unitTypeNr);
    void changeUnit(Hired_Hero* hiredHero);
    void changeUnit(Hero_stats* heroStats);
    void changeUnit(Unit_Type_Data* unitType);
    void changeUnit(Unit* unit);
    void setGame(MoMGameBase* game);

//    int getMelee() const;
//    int getRanged() const;
//    int getArmor() const;
//    int getResist() const;
//    int getHits() const;
//    int getToHitMelee() const;
//    int getToHitRanged() const;
//    int getToDefend() const;

    MapSpecials getAbilityEffects() const;
    BaseAttributes getActualAttributes() const;
    BaseAttributes getBaseAttributes() const;
    BaseAttributes getBonusAttributes() const;
    int getCastingSkill() const;
    std::string getDisplayName() const;
    std::string getHeroName() const;
    MapSpecials getItemEffects() const;
    Item* getSlotItem(int itemSlotNr) const;
    eSlot_Type16 getSlotType(int itemSlotNr) const;
    int getLevel() const;
    double getMoves() const;
    int getNrFigures() const;
    eRace getRace() const;
    std::string getRaceName() const;
    eRanged_Type getRangedType() const;
    MapSpecials getSpecials() const;
    MapSpecials getSpellEffects() const;
    std::string getUnitName() const;
    eUnit_Type getUnitTypeNr() const;
    int getUpkeep() const;
    eWeaponType getWeaponType() const;
    int getXP() const;

    bool hasMagicalRangedAttack() const;
    bool hasMissileRangedAttack() const;
    bool hasPhysicalRangedAttack() const;
    bool hasThrownRangedAttack() const;
    bool hasSpecial(const std::string& specialName) const;

	bool isHero() const;

private:

    /// \brief (Re)applies all effects
    void applyEffects();

    /// \brief (Re)applies effects of (hero) abilities
    void applyAbilities();

    /// \brief (Re)applies effects of items
    void applyItems();

    /// \brief (Re)applies effects of level
    void applyLevel();

    /// \brief (Re)applies effects of weapon type
	void applyWeaponType();

    void copyMemberData(const MoMUnit& rhs);

    // NOT IMPLEMENTED

    // CONFIG
    MoMGameBase* m_game;

    // STATUS
    Battle_Unit* m_battleUnit;
    Hero_stats* m_heroStats;
    Hero_Stats_Initializer* m_heroStatsInitializer;
    Hired_Hero* m_hiredHero;
    Unit* m_unit;
    Unit_Type_Data* m_unitType;

    BaseAttributes m_bonuses;
    BaseAttributes m_upAbilities;
    BaseAttributes m_upItems;
    BaseAttributes m_upLevel;
    BaseAttributes m_upWeaponType;
};

}

#endif
