// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#ifndef MOMGAMEBASE_H
#define MOMGAMEBASE_H

#include "MoMTemplate.h"
#include "MoMUtility.h"

namespace MoM {

class MoMGameBase
{
public:
    MoMGameBase();

    virtual ~MoMGameBase();

    virtual std::string errorString() const
    {
        return m_errorString;
    }

    virtual bool commitData(void* ptr, const void* pNewValue, size_t size) = 0;

    Building_Data* getBuilding_Data(eBuilding building)
    {
        Building_Data* buildingData = getBuilding_Data();
        if ((0 == buildingData) || !inRange(building, eBuilding_MAX))
            return 0;
        return &buildingData[building];
    }

    City* getCity(int cityNr)
    {
        City* cities = getCities();
        if ((0 == cities) || !inRange(cityNr, gMAX_CITIES))
            return 0;
        return &cities[cityNr];
    }

	int getCostToProduce(eProducing producing);

    virtual std::string getGameDirectory() = 0;

    const HelpLBXentry* getHelpEntry(eHelpIndex helpTextNr);
    std::string getHelpText(eHelpIndex helpTextNr);

    std::string getHelpText(eBuilding building);
    std::string getHelpText(eHeroAbility heroAbility);
    std::string getHelpText(eItemPower itemPower);
    std::string getHelpText(ePortrait wizardPortrait);
    std::string getHelpText(eRace race);
    std::string getHelpText(eRanged_Type rangedType);
    const HelpLBXentry* getHelpEntry(eSpell spell);
    std::string getHelpText(eSpell spell);
    std::string getHelpText(eUnitAbility unitAbility);
    std::string getHelpText(eUnitEnchantment unitEnchantment);
    std::string getHelpText(eUnitMutation unitMutation);

    Hero_stats* getHero_stats(ePlayer playerNr, eUnit_Type heroNr)
    {
        Hero_stats* listHeroStats = getList_Hero_stats(playerNr);
        if ((0 == listHeroStats) || !inRange(heroNr, gMAX_HERO_TYPES))
            return 0;
        return &listHeroStats[heroNr];
    }
    Hero_Stats_Initializer* getHero_Stats_Initializer(eUnit_Type heroNr)
    {
        Hero_Stats_Initializer* listHeroStatsInitializer = getList_Hero_Stats_Initializer();
        if ((0 == listHeroStatsInitializer) || !inRange(heroNr, gMAX_HERO_TYPES))
            return 0;
        return &listHeroStatsInitializer[heroNr];
    }
    Hired_Hero* getHired_Hero(ePlayer playerNr, int slotNr)
    {
        Wizard* wizard = getWizard(playerNr);
        if ((0 == wizard) || !inRange(slotNr, gMAX_HIRED_HEROES))
            return 0;
        return &wizard->m_Heroes_hired_by_wizard[slotNr];
    }
    Hired_Hero* getHired_Hero(const Unit* unit)
    {
        if (0 == unit)
            return 0;
        Wizard* wizard = getWizard(unit->m_Owner);
        if ((0 == wizard) || !inRange(unit->m_Hero_Slot_Number, gMAX_HIRED_HEROES))
            return 0;
        return &wizard->m_Heroes_hired_by_wizard[unit->m_Hero_Slot_Number];
    }
    Item* getItem(int itemNr)
    {
        Item* items = getItems();
        if ((0 == items) || !inRange(itemNr, gMAX_ITEMS))
            return 0;
        return &items[itemNr];
    }
    Tower_Node_Lair* getLair(int lairNr)
    {
        Tower_Node_Lair* lairs = getLairs();
        if ((0 == lairs) || !inRange(lairNr, gMAX_NODES_LAIRS_TOWERS))
            return 0;
        return &lairs[lairNr];
    }
    char* getMoM_Version()
    {
        if (0 != getDataSegment())
        {
            return &getDataSegment()->m_Copyright_and_Version[34];
        }
        else if (0 != this->getMagicDataSegment())
        {
            return &getMagicDataSegment()->m_Copyright1_and_Version[34];
        }
        else
        {
            static char nullVersion[8] = "";
            return nullVersion;
        }
    }
    virtual const char* getNameByOffset(uint16_t /*offset*/)
    {
        return 0;
    }
    int getNrCities()
    {
        if (0 == getNumber_of_Cities())
            return 0;
        return *getNumber_of_Cities();
    }
    void setNrCities(int value)
    {
        if (0 == getNumber_of_Cities())
            return;
        *getNumber_of_Cities() = value;
    }
    int getNrItems()
    {
        Item* items = getItems();
        if (0 == items)
            return 0;
        int nrItems = 0;
        for (int itemNr = 0; itemNr < 128; ++itemNr)
        {
            if ((0 != items[itemNr].m_Cost) && (-1 != items[itemNr].m_Cost))
            {
                nrItems++;
            }
        }
        return nrItems;
    }
    int getNrUnits()
    {
        if (0 == getNumber_of_Units())
            return 0;
        return *getNumber_of_Units();
    }
    void setNrUnits(int value)
    {
        if (0 == getNumber_of_Units())
            return;
        *getNumber_of_Units() = value;
    }
    int getNrWizards()
    {
        if (0 == getNumber_of_Wizards())
            return 0;
        return *getNumber_of_Wizards();
    }
    void setNrWizards(int value)
    {
        if (0 == getNumber_of_Wizards())
            return;
        *getNumber_of_Wizards() = value;
    }

    ePlayer getPlayerNr(const Hero_stats* heroStats)
    {
        ePlayer value = (ePlayer)-1;
        for (ePlayer playerNr = (ePlayer)0; toUInt(playerNr) < gMAX_VALID_WIZARDS; inc(playerNr))
        {
            Hero_stats* firstHeroStats = getList_Hero_stats(playerNr);
            unsigned uUnitTypeNr = toUInt(heroStats - firstHeroStats);
            if (uUnitTypeNr < gMAX_HERO_TYPES)
            {
                value = playerNr;
                break;
            }
        }
        return value;
    }
    ePlayer getPlayerNr(const Hired_Hero* hiredHero)
    {
        ePlayer value = (ePlayer)-1;
        for (ePlayer playerNr = (ePlayer)0; toUInt(playerNr) < gMAX_VALID_WIZARDS; inc(playerNr))
        {
            Wizard* wizard = getWizard(playerNr);
            if (0 == wizard)
                continue;
            Hired_Hero* firstHiredHero = wizard->m_Heroes_hired_by_wizard;
            if (toUInt(hiredHero - firstHiredHero) < gMAX_HIRED_HEROES)
            {
                value = playerNr;
                break;
            }
        }
        return value;
    }

    Race_Data* getRace_Data(eRace race)
    {
		MoMDataSegment* dataSegment = getDataSegment();
        if ((0 == dataSegment) || !inRange(race, eRace_MAX))
            return 0;
		return &dataSegment->m_Race_Data[race];
    }

    std::string getRaceName(eRace race);

    virtual std::string getSources() const = 0;

    Spell_Data* getSpell_Data(eSpell spell)
    {
        Spell_Data* spellData = getSpell_Data();
        if ((0 == spellData) || !inRange(spell, MoM::eSpell_MAX))
            return 0;
        return &spellData[spell];
    }

    eTerrainBonusDeposit* getTerrainBonus(const Location& loc)
    {
        return getTerrainBonus(loc.m_Plane, loc.m_XPos, loc.m_YPos);
    }
    eTerrainBonusDeposit* getTerrainBonus(ePlane plane, int x, int y)
    {
        eTerrainBonusDeposit* data = getTerrain_Bonuses();
		if ((0 == data) || !inRange(plane, MoM::ePlane_MAX) || !inRange(x, MoM::gMAX_MAP_COLS) || !inRange(y, MoM::gMAX_MAP_ROWS))
            return 0;
        return (data + (static_cast<int>(plane) * gMAX_MAP_ROWS + y) * gMAX_MAP_COLS + x);
    }
    Terrain_Changes* getTerrainChange(const Location& loc)
    {
        return getTerrainChange(loc.m_Plane, loc.m_XPos, loc.m_YPos);
    }
    Terrain_Changes* getTerrainChange(ePlane plane, int x, int y)
    {
        Terrain_Changes* data = getTerrain_Changes();
		if ((0 == data) || !inRange(plane, MoM::ePlane_MAX) || !inRange(x, MoM::gMAX_MAP_COLS) || !inRange(y, MoM::gMAX_MAP_ROWS))
            return 0;
        return (data + (static_cast<int>(plane) * gMAX_MAP_ROWS + y) * gMAX_MAP_COLS + x);
    }
    uint8_t* getTerrainExplored(const Location& loc)
    {
        return getTerrainExplored(loc.m_Plane, loc.m_XPos, loc.m_YPos);
    }
    uint8_t* getTerrainExplored(ePlane plane, int x, int y)
    {
        uint8_t* data = getTerrain_Explored();
		if ((0 == data) || !inRange(plane, MoM::ePlane_MAX) || !inRange(x, MoM::gMAX_MAP_COLS) || !inRange(y, MoM::gMAX_MAP_ROWS))
            return 0;
        return (data + (static_cast<int>(plane) * gMAX_MAP_ROWS + y) * gMAX_MAP_COLS + x);
    }
    uint8_t* getTerrainLandMassID(const Location& loc)
    {
        return getTerrainLandMassID(loc.m_Plane, loc.m_XPos, loc.m_YPos);
    }
    uint8_t* getTerrainLandMassID(ePlane plane, int x, int y)
    {
        uint8_t* data = getTerrain_LandMassID();
		if ((0 == data) || !inRange(plane, MoM::ePlane_MAX) || !inRange(x, MoM::gMAX_MAP_COLS) || !inRange(y, MoM::gMAX_MAP_ROWS))
            return 0;
        return (data + (static_cast<int>(plane) * gMAX_MAP_ROWS + y) * gMAX_MAP_COLS + x);
    }
    int8_t* getTerrainMovement(const Location& loc, eMovement movement)
    {
        return getTerrainMovement(loc.m_Plane, loc.m_XPos, loc.m_YPos, movement);
    }
    int8_t* getTerrainMovement(ePlane plane, int x, int y, eMovement movement)
    {
        Map_Movement* data = getTerrain_Movements();
		if ((0 == data) || !inRange(plane, MoM::ePlane_MAX) || !inRange(x, MoM::gMAX_MAP_COLS) || !inRange(y, MoM::gMAX_MAP_ROWS) || !inRange(movement, MoM::eMovement_MAX))
            return 0;
        MapRow_Movement* mapRow = &data[plane].m_Unused_Row[0];
        mapRow += static_cast<unsigned>(movement) * gMAX_MAP_ROWS;
        return &mapRow[y].m_Moves[x];
    }
    eTerrainType* getTerrainType(const Location& loc)
    {
        return getTerrainType(loc.m_Plane, loc.m_XPos, loc.m_YPos);
    }
    eTerrainType* getTerrainType(ePlane plane, int x, int y)
    {
        eTerrainType* data = getTerrain_Types();
		if ((0 == data) || !inRange(plane, MoM::ePlane_MAX) || !inRange(x, MoM::gMAX_MAP_COLS) || !inRange(y, MoM::gMAX_MAP_ROWS))
            return 0;
        return (data + (static_cast<int>(plane) * gMAX_MAP_ROWS + y) * gMAX_MAP_COLS + x);
    }

    Unit* getUnit(int unitNr)
    {
        Unit* units = getUnits();
		if ((0 == units) || !inRange(unitNr, MoM::gMAX_UNITS))
            return 0;
        return &units[unitNr];
    }
    Unit_Type_Data* getUnit_Type_Data(eUnit_Type unitTypeNr)
    {
        Unit_Type_Data* unitTypes = getUnit_Types();
        if ((0 == unitTypes) || !inRange(unitTypeNr, MoM::eUnit_Type_MAX))
            return 0;
        return &unitTypes[unitTypeNr];
    }
    eUnit_Type getUnitTypeNr(const Hero_stats* heroStats)
    {
        eUnit_Type unitTypeNr = (eUnit_Type)-1;
        for (ePlayer playerNr = (ePlayer)0; toUInt(playerNr) < gMAX_VALID_WIZARDS; inc(playerNr))
        {
            Hero_stats* firstHeroStats = getList_Hero_stats(playerNr);
            unsigned value = toUInt(heroStats - firstHeroStats);
            if (value < gMAX_HERO_TYPES)
            {
                unitTypeNr = (eUnit_Type)value;
                break;
            }
        }
        return unitTypeNr;
    }
    eUnit_Type getUnitTypeNr(const Hero_Stats_Initializer* heroStatsInitializer)
    {
        eUnit_Type unitTypeNr = (eUnit_Type)-1;
        Hero_Stats_Initializer* firstHeroStats = getList_Hero_Stats_Initializer();
        unsigned value = toUInt(heroStatsInitializer - firstHeroStats);
        if (value < gMAX_HERO_TYPES)
        {
            unitTypeNr = (eUnit_Type)value;
        }
        return unitTypeNr;
    }
    eUnit_Type getUnitTypeNr(const Unit_Type_Data* unitType)
    {
        eUnit_Type unitTypeNr = (eUnit_Type)-1;
        Unit_Type_Data* unitTypes = getUnit_Types();
        if (0 != unitTypes)
        {
            unitTypeNr = (eUnit_Type)(unitType - unitTypes);
        }
        return unitTypeNr;
    }
    Wizard* getWizard(int wizardNr)
    {
        Wizard* wizards = getWizards();
		if ((0 == wizards) || !inRange(wizardNr, MoM::gMAX_WIZARD_RECORDS))
            return 0;
        return &wizards[wizardNr];
    }

    virtual bool isOpen() const = 0;

    virtual bool readData()
    {
        return true;
    }

    virtual bool validate() = 0;

//
// TODO: Make all methods below protected/private
//

public:
    virtual Available_spell_page* getAvailable_spell_pages()
    {
        return 0;
    }
    virtual Battlefield* getBattlefield()
    {
        return 0;
    }
    virtual Battle_Unit* getBattle_Unit_View()
    {
        return 0;
    }
    virtual Battle_Unit* getBattle_Units()
    {
        return 0;
    }
protected:
    virtual Building_Data* getBuilding_Data()
    {
        return 0;
    }
    virtual City* getCities() = 0;
public:
    virtual Events_Status* getEvents_Status()
    {
        return 0;
    }
    virtual Fortress* getFortresses()
    {
        return 0;
    }
    virtual WizardsExe_Game_Data* getGame_Data_Exe()
    {
        return 0;
    }
    virtual Game_Data_Save* getGame_Data_Save()
    {
        return 0;
    }
    virtual Game_Settings* getGame_Settings()
    {
        return 0;
    }
    virtual eGameState* getGameState()
    {
        return 0;
    }
    virtual uint16_t* getGameTurn()
    {
        return 0;
    }
    virtual eSpell16* getHero_spells()
    {
        return 0;
    }
protected:
    virtual Hero_stats* getList_Hero_stats(ePlayer playerNr) = 0;
    virtual Hero_Stats_Initializer* getList_Hero_Stats_Initializer()
    {
        return 0;
    }
    virtual Item* getItems() = 0;
    virtual Tower_Node_Lair* getLairs() = 0;
public:
    virtual uint16_t* getNumber_of_Battle_Units()
    {
        return 0;
    }
protected:
    virtual uint16_t* getNumber_of_Cities() = 0;
    virtual uint16_t* getNumber_of_Units() = 0;
    virtual uint16_t* getNumber_of_Wizards() = 0;
    virtual Spell_Data* getSpell_Data()
    {
        return 0;
    }
public:
    virtual Spells_Cast_in_Battle* getSpells_Cast_in_Battle()
    {
        return 0;
    }
protected:
    virtual eTerrainBonusDeposit* getTerrain_Bonuses()
    {
        return 0;
    }
    virtual Terrain_Changes* getTerrain_Changes()
    {
        return 0;
    }
    virtual uint8_t* getTerrain_Explored()
    {
        return 0;
    }
    virtual uint8_t* getTerrain_LandMassID()
    {
        return 0;
    }
    virtual Map_Movement* getTerrain_Movements()
    {
        return 0;
    }
    virtual eTerrainType* getTerrain_Types()
    {
        return 0;
    }

    virtual Unit* getUnits() = 0;
    virtual Unit_Type_Data* getUnit_Types()
    {
        return 0;
    }
public:
    virtual int8_t* getUnrest_Table(eRace /* homeRace */)
    {
        return 0;
    }
protected:
    virtual Wizard* getWizards() = 0;

public:
    virtual MoMDataSegment* getDataSegment()
    {
        return 0;
    }
    virtual class MoMExeMagic* getMagicExe()
    {
        return 0;
    }
    virtual MoMMagicDataSegment* getMagicDataSegment()
    {
        return 0;
    }
    virtual uint8_t* getMagicExeContents()
    {
        return 0;
    }
    virtual MoMMagicDataSegment* getMagicExeDataSegment()
    {
        return 0;
    }
    virtual uint8_t* getMagicOverlay(size_t /* ovlNr */)
    {
        return 0;
    }
	virtual const class MoMProcess* getMoMProcess() const
	{
		return 0;
	}
    virtual SaveGame* getSaveGame()
    {
        return 0;
    }
    virtual const uint8_t* getSeg0Pointer()
    {
        return 0;
    }
    virtual class MoMExeWizards* getWizardsExe()
    {
        return 0;
    }
    virtual uint8_t* getWizardsExeContents()
    {
        return 0;
    }
    virtual MoMDataSegment* getWizardsExeDataSegment()
    {
        return 0;
    }
    virtual uint8_t* getWizardsOverlay(size_t /* ovlNr */)
    {
        return 0;
    }

protected:
    virtual void setErrorString(const std::string& value)
    {
        m_errorString = value;
    }

private:
    // NOT IMPLEMENTED
    MoMGameBase(const MoMGameBase& rhs);
    MoMGameBase& operator=(const MoMGameBase& rhs);

    // STATUS
    std::string m_errorString;
    std::auto_ptr<class MoMLbxBase> m_HelpLbx;
};

}

#endif
