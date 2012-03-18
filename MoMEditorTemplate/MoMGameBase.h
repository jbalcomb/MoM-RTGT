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
#include "MoMutility.h"

namespace MoM {

class MoMGameBase
{
public:
    MoMGameBase();

    virtual ~MoMGameBase();

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

    Hero_stats* getHero_stats(ePlayer playerNr, eUnit_Type heroNr)
    {
        Hero_stats* listHeroStats = getList_Hero_stats(playerNr);
        if ((0 == listHeroStats) || !inRange(heroNr, gMAX_HERO_TYPES))
            return 0;
        return &listHeroStats[heroNr];
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
            return getDataSegment()->m_MoM_Version;
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

	std::string getRaceName(eRace race);

    virtual std::string getSources() const = 0;

    virtual eTerrainType* getTerrainType(ePlane plane, int x, int y)
    {
        eTerrainType* terrainTypes = getTerrainTypes();
		if ((0 == terrainTypes) || !inRange(plane, MoM::ePlane_MAX) || !inRange(x, MoM::gMAX_MAP_COLS) || !inRange(y, MoM::gMAX_MAP_ROWS))
            return 0;
        return (terrainTypes + (static_cast<int>(plane) * gMAX_MAP_ROWS + y) * gMAX_MAP_COLS + x);
    }

    Unit* getUnit(int unitNr)
    {
        Unit* units = getUnits();
		if ((0 == units) || !inRange(unitNr, MoM::gMAX_UNITS))
            return 0;
        return &units[unitNr];
    }
    Unit_Type_Data* getUnit_Type_Data(eUnit_Type unitType)
    {
        Unit_Type_Data* unitTypes = getUnit_Types();
		if ((0 == unitTypes) || !inRange(unitType, MoM::eUnit_Type_MAX))
            return 0;
        return &unitTypes[unitType];
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

//protected:
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
    virtual Building_Data* getBuilding_Data()
    {
        return 0;
    }
    virtual City* getCities() = 0;
    virtual Events_Status* getEvents_Status()
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
    virtual Hero_stats* getList_Hero_stats(ePlayer playerNr) = 0;
    virtual Item* getItems() = 0;
    virtual Tower_Node_Lair* getLairs() = 0;
    virtual uint16_t* getNumber_of_Battle_Units()
    {
        return 0;
    }
    virtual uint16_t* getNumber_of_Cities() = 0;
    virtual uint16_t* getNumber_of_Units() = 0;
    virtual uint16_t* getNumber_of_Wizards() = 0;
    virtual Spell_Data* getSpell_Data()
    {
        return 0;
    }
    virtual Spells_Cast_in_Battle* getSpells_Cast_in_Battle()
    {
        return 0;
    }
    virtual eTerrainType* getTerrainTypes()
    {
        return 0;
    }
    virtual Unit* getUnits() = 0;
    virtual Unit_Type_Data* getUnit_Types()
    {
        return 0;
    }
    virtual int8_t* getUnrest_Table(eRace /* homeRace */)
    {
        return 0;
    }
    virtual Wizard* getWizards() = 0;

//private:
    virtual MoMDataSegment* getDataSegment()
    {
        return 0;
    }
    virtual MoMMagicDataSegment* getMagicDataSegment()
    {
        return 0;
    }
    virtual uint8_t* getWizardsExeContents()
    {
        return 0;
    }
    virtual uint8_t* getMagicExeContents()
    {
        return 0;
    }
    virtual MoMDataSegment* getWizardsExeDataSegment()
    {
        return 0;
    }
    virtual MoMMagicDataSegment* getMagicExeDataSegment()
    {
        return 0;
    }
    virtual uint8_t* getWizardsOverlay(size_t /* ovlNr */)
    {
        return 0;
    }
    virtual uint8_t* getMagicOverlay(size_t /* ovlNr */)
    {
        return 0;
    }
    virtual class MoMExeWizards* getWizardsExe()
    {
        return 0;
    }
    virtual class MoMExeMagic* getMagicExe()
    {
        return 0;
    }

private:
    // NOT IMPLEMENTED
    MoMGameBase(const MoMGameBase& rhs);
    MoMGameBase& operator=(const MoMGameBase& rhs);
};

}

#endif
