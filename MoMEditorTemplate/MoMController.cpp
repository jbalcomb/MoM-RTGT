// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include <assert.h>
#include <iostream>
#include <string.h>
#include <string>

#include "MoMGenerated.h"
#include "MoMutility.h"

#include "MoMController.h"

namespace MoM {

// TODO: Get XP levels from game
int gXPforLevel[] =
{
    0,      // 1	Hero		
    20,     // 2	Myrmidon		
    60,     // 3	Captain		
    120,    // 4	Commander		
    200,    // 5	Champion		
    300,    // 6	Lord		
    450,    // 7	Grand Lord		
    600,    // 8	Super Hero		
    1000    // 9	Demi-God		
};

#define buildingPresent(city, building) \
    (  BUILDINGSTATUS_Built == (city).m_Building_Status.s.building \
    || BUILDINGSTATUS_Replaced == (city).m_Building_Status.s.building )

#define producing(city, building) \
    (PRODUCING_##building == (city).m_Producing)

#define producingGarrison(city) \
    ((city).m_Producing >= PRODUCING_BUILDING_MAX)

bool MoMController::addUnit(MoMGameBase& game, ePlayer playerNr, eUnit_Type unitType)
{
	m_errorString.clear();
    if ((unsigned)unitType >= eUnit_Type_MAX)
    {
        std::cout << "Cannot add unit " << unitType << " because it is out-of-range" << std::endl;
		m_errorString = "UnitType '" + toStr(unitType) + "' is out-of-range";
        return false;
    }

    Wizard* wizard = game.getWizard(playerNr);
    if (0 == wizard)
	{
		m_errorString = "Wizard data of player '" + toStr(playerNr) + "' is not accessible";
        return false;
	}

    // TODO: Check playerNr range + wizard not destroyed

	// Create a new unit that is not in the game yet
    int unitNr = -1;
    bool ok = createUnit(game, unitNr);

    Unit* unit = game.getUnit(unitNr);
    if (0 == unit)
	{
		m_errorString = "Failed to create a unit for unitNr '" + toStr(unitNr) + "'";
        ok = false;
	}

	// Initialize the unit to be on the board
	if (ok) 
	{
		assert(unitNr == game.getNrUnits());

		unit->m_Unit_Type = unitType;
		// TODO: Check if there is space
		unit->m_XPos = (uint8_t)wizard->m_X_Coordinate_of_Summoning_Circle;
		unit->m_YPos = (uint8_t)wizard->m_Y_Coordinate_of_Summoning_Circle;
		unit->m_Plane = wizard->m_Plane_of_Summoning_Circle;
		unit->m_Owner = playerNr;
		unit->m_Hero_Slot_Number = -1;
		unit->m_Moves_Total = 2;
		unit->m_Moves_Left = 2;
        unit->m_Scout = 1;
		unit->m_Road_Building_left_to_complete = -1;
	}

	// Polymorph the unit to a hero if applicable
    if (ok && ((unsigned)unitType < gMAX_HERO_TYPES))
	{
		ok = polymorphToHero(game, playerNr, unitNr, unitType);
	}

	// Put the unit in the game
    if (ok)
    {
        game.setNrUnits(unitNr + 1);
    }

    return ok;
}

bool MoMController::applyBuildingQueue(MoMGameBase& game, int cityNr)
{
	m_errorString.clear();
    City* city = game.getCity(cityNr);
    if (0 == city)
	{
		m_errorString = "Cannot get the data for to city  '" + toStr(cityNr) + "'";
        return false;
	}

    eProducing producingBefore = city->m_Producing;

    std::vector<int> unitsInCity;
    Location location = { city->m_XPos, city->m_YPos, city->m_Plane };
    (void)findUnitsAtLocation(game, location, unitsInCity);

    // TODO: Remove this spell enchantment ;)
//    if (OWNER_None == city->m_City_Enchantments.Gaias_Blessing)
//    {
//        std::cout << "Cast Gaias Blessing on " << city->m_City_Name << std::endl;
//        city->m_City_Enchantments.Gaias_Blessing = OWNER_YOU;
//    }

    // Only change if we producing 'Housing' or 'Trade Goods'
    // This is a good trigger because when something is built
    // the game switches to Housing automatically (unless it was a unit).
    // And when you conquer a city the game sets it tot 'Trade Goods'.
    // The exception is the Garrison - if there is no Garrison, built one first!

    // OPTIMAL GROWTH W/O GOLD AND W/O SIGNIFICANT UNREST
    //[Garrison]
    //[Builders Hall] 
    //[Granary] 
    //[Smithy] 
    //[Marketplace] 
    //[Farmers Market]

    // FURTHER RULES
    //[Housing] till Pop 8
    //[Shrine]
    //[Sawmill]
    //[Foresters Guild]
    //[Library]
    //[Sages Guild]
    //[Temple]
    //[Alchemists Guild]
    //[University]
    //[Bank]
    //[Miners Guild]

    if (CITYSIZE_Outpost == city->m_Size)
    {
        // Do nothing - we're an outpost
        std::cout << "City '" << city->m_City_Name << "' [" << cityNr << "] "
            << city->m_Producing << " is still an outpost" << std::endl;
    }
    else if (producingGarrison(*city))
    {
        // Do nothing - we're producing a Garrison
        //std::cout << "City '" << city->m_City_Name << "' [" << cityNr << "] "
        //    << city->m_Producing << " keeps producing a garrison" << std::endl;
    }
    else if (0 == unitsInCity.size() && !producingGarrison(*city))
    {
        // Switch from any task to Spearmen if there is none
        // TODO: pick the cheapest unit that may be built (if any: Dwarves!)
        city->m_Producing = PRODUCING_High_Men_Spearmen;
    }
    else if (PRODUCING_Housing != city->m_Producing
          && PRODUCING_Trade_Goods != city->m_Producing)
    {
        // Do nothing - someone specified something to build
    }
    else if (!buildingPresent(*city, Builders_Hall))
    {
        city->m_Producing = PRODUCING_Builders_Hall;
    }
    else if (!buildingPresent(*city, Granary))
    {
        city->m_Producing = PRODUCING_Granary;
    }
    else if (!buildingPresent(*city, Smithy))
    {
        city->m_Producing = PRODUCING_Smithy;
    }
    else if (!buildingPresent(*city, Marketplace))
    {
        city->m_Producing = PRODUCING_Marketplace;
    }
    else if (!buildingPresent(*city, Farmers_Market))
    {
        city->m_Producing = PRODUCING_Farmers_Market;
    }
    else if (city->m_Population < 8)
    {
        city->m_Producing = PRODUCING_Housing;
    }

    else if (!buildingPresent(*city, Shrine))
    {
        city->m_Producing = PRODUCING_Shrine;
    }
    else if (!buildingPresent(*city, Sawmill))
    {
        // TODO: forbidden building (no forest)?
        city->m_Producing = PRODUCING_Sawmill;
    }
    else if (!buildingPresent(*city, Foresters_Guild))
    {
        // TODO: forbidden building (no Sawmill)?
        city->m_Producing = PRODUCING_Foresters_Guild;
    }
    else if (!buildingPresent(*city, Library))
    {
        city->m_Producing = PRODUCING_Library;
    }
    else if (!buildingPresent(*city, Sages_Guild))
    {
        // TODO: forbidden building?
        city->m_Producing = PRODUCING_Sages_Guild;
    }
    else if (!buildingPresent(*city, Temple))
    {
        // TODO: forbidden building?
        city->m_Producing = PRODUCING_Temple;
    }
    else if (!buildingPresent(*city, Alchemist_Guild))
    {
        // TODO: forbidden building?
        city->m_Producing = PRODUCING_Alchemist_Guild;
    }
    else if (!buildingPresent(*city, University))
    {
        // TODO: forbidden building?
        city->m_Producing = PRODUCING_University;
    }
    else if (!buildingPresent(*city, Bank))
    {
        // TODO: forbidden building?
        city->m_Producing = PRODUCING_Bank;
    }
    else if (!buildingPresent(*city, Miners_Guild))
    {
        // TODO: forbidden building (no Hills or Mountains)?
        city->m_Producing = PRODUCING_Miners_Guild;
    }
    else
    {
        // Do nothing - all specified buildings have been built
        //std::cout << "City " << city->m_City_Name
        //    << " (" << city->m_Producing << ") has built all specified buildings" << std::endl;
    }

    if (producingBefore != city->m_Producing)
    {
        std::cout << "Changed production of '" << city->m_City_Name << "' [" << cityNr << "] "
            << producingBefore << "\n\tto " << city->m_Producing << std::endl;
    }

    return true;
}

bool MoMController::applyBuildingQueue(MoMGameBase& game, ePlayer playerNr)
{
	m_errorString.clear();
    bool ok = true;
    for (int cityNr = 0; cityNr < game.getNrCities(); ++cityNr)
    {
        const City* city = game.getCity(cityNr);
        if (0 == city)
            break;

        if (city->m_Owner == playerNr)
        {
            ok |= applyBuildingQueue(game, cityNr);
        }
    }
    return ok;
}

bool MoMController::createUnit(MoMGameBase& game, int& unitNr)
{
	m_errorString.clear();
    if (game.getNrUnits() < 0
        || game.getNrUnits() >= (int)gMAX_UNITS)
    {
        std::cout << "Cannot create a unit because NrUnits is out-of-range" << std::endl;
		m_errorString = "Cannot create a unit because NrUnits '" + toStr(game.getNrUnits()) + "' is out-of-range";
        return false;
    }

    unitNr = game.getNrUnits();

    Unit* unit = game.getUnit(unitNr);
    if (0 == unit)
	{
		m_errorString = "Cannot retrieve data for unit '" + toStr(unitNr) + "'";
        return false;
	}

    memset(unit, '\0', sizeof(unit));

    // Make sure the unit contains "reasonable" data
    unit->m_Moves_Total = 2;
    unit->m_Moves_Left = 2;
    unit->m_Road_Building_left_to_complete = -1;

    return true;
}

bool MoMController::findUnitsAtLocation(MoMGameBase& game, const Location& location, std::vector<int>& units)
{
	m_errorString.clear();
    units.clear();

    for (int unitNr = 0; unitNr < game.getNrUnits(); ++unitNr)
    {
        const Unit* unit = game.getUnit(unitNr);
        if (0 == unit)
            break;

        if (location.m_XPos == unit->m_XPos
            && location.m_YPos == unit->m_YPos
            && location.m_Plane == unit->m_Plane)
        {
            units.push_back(unitNr);
        }
    }

    return true;
}

bool MoMController::polymorphToHero(MoMGameBase& game, ePlayer playerNr, int unitNr, eUnit_Type heroNr)
{
	m_errorString.clear();
    // EXTRA INPUT:
	// TODO: Retrieve heroName from game
	// TODO: Retrieve heroSlotTypes from game
    std::string heroName("Tweaker");
    int heroSlotNr = 0;
    eSlot_Type16 heroSlotTypes[3] = {SLOT16_Sword_Staff_Wand, SLOT16_Armor_Shield, SLOT16_Amulet};

    // CHECK INPUT:
    assert((unsigned)unitNr < gMAX_UNITS);
    assert((unsigned)playerNr < gMAX_VALID_WIZARDS);
    assert((unsigned)heroNr < gMAX_HERO_TYPES);
    assert((unsigned)heroSlotNr < gMAX_HIRED_HEROES);

	Unit_Type_Data* unitTypeData = game.getUnit_Type_Data(heroNr);
    if (0 == unitTypeData)
        return false;
    Hero_stats* heroStats = game.getHero_stats(playerNr, heroNr);
    if (0 == heroStats)
        return false;
    Unit* unit = game.getUnit(unitNr);
    if (0 == unit)
        return false;
    Wizard* wizard = game.getWizard(playerNr);
    if (0 == wizard)
        return false;

    // CHECKS

	// TODO: Check if the unit is already a hero in which case we need a different scenario
	//       1. Reuse the current heroSlotNr
	//		 2. Bury the old hero

	// Retrieve the slot types
    if (toUInt(unitTypeData->m_Hero_TypeCode_or_Building2) <= toUInt(HEROTYPE_Wizard))
	{
		heroSlotTypes[0] = static_cast<eSlot_Type16>(1 + unitTypeData->m_Hero_TypeCode_or_Building2);
		if (HEROTYPE_Wizard == unitTypeData->m_Hero_TypeCode_or_Building2)
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
		unsigned slotCode = static_cast<unsigned>(unitTypeData->m_Hero_TypeCode_or_Building2);
		slotCode -= 6;
		heroSlotTypes[0] = static_cast<eSlot_Type16>(1 + slotCode % 6);
		slotCode /= 6;
		heroSlotTypes[1] = static_cast<eSlot_Type16>(1 + slotCode % 6);
		slotCode /= 6;
		heroSlotTypes[2] = static_cast<eSlot_Type16>(1 + slotCode % 6);
	}

    // Check if hero slot is free or search for first free slot
    if (-1 != wizard->m_Heroes_hired_by_wizard[heroSlotNr].m_Unit_Nr)
    {
        for (unsigned i = 0; i < gMAX_HIRED_HEROES; ++i)
        {
            if (-1 == wizard->m_Heroes_hired_by_wizard[i].m_Unit_Nr)
            {
                heroSlotNr = i;
                break;
            }
        }
        if (-1 != wizard->m_Heroes_hired_by_wizard[heroSlotNr].m_Unit_Nr)
        {
            std::cout << "Player " << playerNr << " cannot add hero " << heroNr << " because he has no free slot" << std::endl;
			m_errorString = "Player " + toStr(playerNr) + " cannot add hero " + toStr(heroNr) + " because he has no free slot";
            return false;
        }
    }

    Hired_Hero& hiredHero = wizard->m_Heroes_hired_by_wizard[heroSlotNr];

    // Check if hero is already in your army
    if (HEROLEVELSTATUS_Active_in_Wizards_army == heroStats->m_Level_Status)
    {
        std::cout << "Player " << playerNr << " cannot add hero " << heroNr << " because that hero is already active in his army" << std::endl;
		m_errorString = "Player " + toStr(playerNr) + " cannot add hero " + toStr(heroNr) + " because that hero is already active in his army";
        return false;
    }


    // PROCEDURE

    // Determine Level & XP
    int level = (int8_t)heroStats->m_Level_Status;
    if (level < 0)
    {
        // Resurrect
        level = -1 - level;
    }
    else
    {
        // Summon
        // Level is already correctly set
    }
    if ((unsigned)level >= ARRAYSIZE(gXPforLevel))
    {
        // In case of doubt, make it Level_1
        level = 0;
    }
    int xp = gXPforLevel[level];

    // Bring the unit to your Summoning Circle if it was not yours
    // or if its not on the board
    if ((playerNr != unit->m_Owner)
        || (unit->m_XPos <= 0 || unit->m_YPos <= 0)   // TODO: Include 0? Or exclude?
        || (unit->m_XPos >= 60 || unit->m_YPos >= 40)
        || ((unsigned)unit->m_Plane >= ePlane_MAX))
    {
        // TODO: Check if there is space for our unit
        unit->m_XPos = (uint8_t)wizard->m_X_Coordinate_of_Summoning_Circle;
        unit->m_YPos = (uint8_t)wizard->m_Y_Coordinate_of_Summoning_Circle;
        unit->m_Plane = wizard->m_Plane_of_Summoning_Circle;
    }

    // Change unit to your hero
    unit->m_Owner = playerNr;
    unit->m_Hero_Slot_Number = heroSlotNr;
    unit->m_Unit_Type = heroNr;
    unit->m_Level = (eLevel)level;
    unit->m_Experience = xp;

    // Set hero data
    hiredHero.m_Unit_Nr = unitNr;
    memset(hiredHero.m_Hero_name, '\0', sizeof(hiredHero.m_Hero_name));
    strncpy(hiredHero.m_Hero_name, heroName.c_str(), sizeof(hiredHero.m_Hero_name) - 1);
    hiredHero.m_Items_In_Slot[0] = -1;
    hiredHero.m_Items_In_Slot[1] = -1;
    hiredHero.m_Items_In_Slot[2] = -1;
    hiredHero.m_Slot_Types[0] = heroSlotTypes[0];
    hiredHero.m_Slot_Types[1] = heroSlotTypes[1];
    hiredHero.m_Slot_Types[2] = heroSlotTypes[2];

    // Make hero active in your army
    heroStats->m_Level_Status = HEROLEVELSTATUS_Active_in_Wizards_army;

    return true;
}

bool MoMController::repopLairs(MoMGameBase& game, bool maxOut)
{
	m_errorString.clear();
    for (unsigned lairNr = 0; lairNr < gMAX_NODES_LAIRS_TOWERS; ++lairNr)
    {
        Tower_Node_Lair* lair = game.getLair(lairNr);
        if (0 == lair)
            break;

        if (maxOut)
        {
            if (0 == lair->m_Inhabitant1.m_Initial_Nr_of_Inhabitant || 0 == lair->m_Inhabitant1.m_Inhabitant)
            {
                // No inhabitants
            }
            else if (0 == lair->m_Inhabitant2.m_Initial_Nr_of_Inhabitant || 0 == lair->m_Inhabitant2.m_Inhabitant)
            {
                // Only 1 type of inhabitant
                lair->m_Inhabitant1.m_Initial_Nr_of_Inhabitant = 9;
            }
            else
            {
                lair->m_Inhabitant1.m_Initial_Nr_of_Inhabitant = 3;
                lair->m_Inhabitant2.m_Initial_Nr_of_Inhabitant = 6;
            }
            if (lair->m_Reward_Specials + 1 < eReward_Specials_MAX)
            {
                inc(lair->m_Reward_Specials);
            }
            lair->m_Item_Rewards++;
            if (lair->m_Item_Rewards > 3)
            {
                lair->m_Item_Rewards = 3;
            }
        }
        lair->m_Inhabitant1.m_Remaining_Nr_of_Inhabitant = lair->m_Inhabitant1.m_Initial_Nr_of_Inhabitant;
        lair->m_Inhabitant2.m_Remaining_Nr_of_Inhabitant = lair->m_Inhabitant2.m_Initial_Nr_of_Inhabitant;
        lair->m_Status = LAIRSTATUS_intact;
    }

    return true;
}

bool MoMController::validateConsistency(MoMGameBase& game)
{
	m_errorString.clear();
    bool ok = true;

    // Check internal consistencies
    // TODO:
    // - Unit fields: MaxMove vs Active vs MovesLeft

    // Foreach HiredHero
    for (ePlayer wizardNr = (ePlayer)0; wizardNr < game.getNrWizards(); inc(wizardNr))
    {
        const Wizard* wizard = game.getWizard(wizardNr);
        if (0 == wizard)
            break;

        // TODO: Skip wizards that are out of the game

        for (unsigned heroSlotNr = 0; heroSlotNr < gMAX_HIRED_HEROES; ++heroSlotNr)
        {
            const Hired_Hero& hiredHero = wizard->m_Heroes_hired_by_wizard[heroSlotNr];
            if (-1 == hiredHero.m_Unit_Nr)
                continue;

            // Check corresponding Unit and vice versa
            if (hiredHero.m_Unit_Nr < 0 || hiredHero.m_Unit_Nr >= game.getNrUnits())
            {
                std::cout << "UnitNr " << hiredHero.m_Unit_Nr << " is out of range for Wizard " << wizardNr << " hero slot " << heroSlotNr << std::endl;
                ok = false;
                continue;
            }
            const Unit* unit = game.getUnit(hiredHero.m_Unit_Nr);
            if (0 == unit)
                break;
            if (wizardNr != unit->m_Owner)
            {
                std::cout << "UnitNr " << hiredHero.m_Unit_Nr << " has Owner " << unit->m_Owner << " that does not match playerNr " << wizardNr << std::endl;
                ok = false;
            }
            if ((unsigned)unit->m_Unit_Type >= UNITTYPE_FIRST)
            {
                std::cout << "UnitNr " << hiredHero.m_Unit_Nr << " has UnitType " << unit->m_Unit_Type << " which is not a hero of player " << wizardNr << std::endl;
                ok = false;
                continue;
            }

            // Check corresponding Hero_stats
            const Hero_stats* heroStats = game.getHero_stats(wizardNr, unit->m_Unit_Type);
            if (0 == heroStats)
                break;
            if (HEROLEVELSTATUS_Active_in_Wizards_army != heroStats->m_Level_Status)
            {
                std::cout << "Hero " << unit->m_Unit_Type << " has status " << heroStats->m_Level_Status << " instead of Active_in_Wizards_army for player " << wizardNr << std::endl;
                ok = false;
            }

            // Check corresponding Items and vice versa
            for (int itemSlotNr = 0; itemSlotNr < 3; ++itemSlotNr)
            {
                int itemNr = hiredHero.m_Items_In_Slot[itemSlotNr];
                if (-1 == itemNr)
                   continue;

                if ((unsigned)itemNr >= gMAX_ITEMS)
                {
                    std::cout << "Hero " << unit->m_Unit_Type << " has item with index " << itemNr << " which is out-of-range for player " << wizardNr << std::endl;
                    ok = false;
                }

                //std::cout << "Wizard " << wizardNr << " has Hero " << unit->m_Unit_Type << " who has item " << m_SaveGame.m_Items[itemNr] << std::endl;

                // TODO: Check itemType versus slotType
            }
        }

        for (unsigned itemSlotNr = 0; itemSlotNr < ARRAYSIZE(wizard->m_Items_in_Slots); ++itemSlotNr)
        {
            int itemNr = wizard->m_Items_in_Slots[itemSlotNr];
            if (-1 == itemNr)
               continue;

            if ((unsigned)itemNr >= gMAX_ITEMS)
            {
                std::cout << "Wizard " << wizardNr << " has item with index " << itemNr << " which is out-of-range" << std::endl;
                ok = false;
            }

            //std::cout << "Wizard " << wizardNr << " has item " << m_SaveGame.m_Items[itemNr] << std::endl;

            // TODO: Check itemType versus slotType
        }
        
    }

    // For each Unit
    for (int unitNr = 0; unitNr < game.getNrUnits(); ++unitNr)
    {
        // Check if Unit corresponds 1-1 to a Hired_Hero
        const Unit* unit = game.getUnit(unitNr);
        if (0 == unit)
            break;
        if ((unsigned)unit->m_Unit_Type < gMAX_HERO_TYPES)
        {
            if ((unsigned)unit->m_Hero_Slot_Number >= gMAX_HIRED_HEROES)
            {
                std::cout << "Wizard " << unit->m_Owner << " has Unit " << unitNr << " which is hero " << unit->m_Unit_Type << " but has heroSlotNr " << unit->m_Hero_Slot_Number << std::endl;
                ok = false;
            }
        }
        if (-1 != unit->m_Hero_Slot_Number)
        {
            if ((unsigned)unit->m_Unit_Type >= gMAX_HERO_TYPES)
            {
                std::cout << "Wizard " << unit->m_Owner << " has Unit " << unitNr << " which has heroSlotNr " << (int)unit->m_Hero_Slot_Number << " but has unitType " << unit->m_Unit_Type << std::endl;
                ok = false;
            }
        }
        if ((unsigned)unit->m_Hero_Slot_Number < gMAX_HIRED_HEROES)
        {
            if ((unsigned)unit->m_Owner < gMAX_VALID_WIZARDS)
            {
                const Wizard* owner = game.getWizard(unit->m_Owner);
                if (0 == owner)
                    break;
                const Hired_Hero& hiredHero = owner->m_Heroes_hired_by_wizard[unit->m_Hero_Slot_Number];

                if (hiredHero.m_Unit_Nr != unitNr)
                {
                    std::cout << "Wizard " << unit->m_Owner << " has Unit " << unitNr << " which has heroSlotNr " << (int)unit->m_Hero_Slot_Number << " but that slot has unitNr " << hiredHero.m_Unit_Nr << std::endl;
                    ok = false;
                }
            }
        }
    }

    // For each Hero_stats
    for (ePlayer wizardNr = (ePlayer)0; wizardNr < game.getNrWizards(); inc(wizardNr))
    {
        for (eUnit_Type heroNr = HEROTYPE_FIRST; (unsigned)heroNr < gMAX_HERO_TYPES; inc(heroNr))
        {
            Hero_stats* heroStats = game.getHero_stats(wizardNr, heroNr);
            if (0 == heroStats)
                break;

            // Check if each Hero in the game corresponds to a exactly one Unit
            // Check if each Hero that is not in the game does not correspond to a Hired Hero

            int nrMatchingUnits = 0;
            for (int unitNr = 0; unitNr < game.getNrUnits(); ++unitNr)
            {
                const Unit* unit = game.getUnit(unitNr);
                if (0 == unit)
                    break;

                if (unit->m_Owner == wizardNr && unit->m_Unit_Type == heroNr)
                {
                    nrMatchingUnits++;
                }
            }
            if (HEROLEVELSTATUS_Active_in_Wizards_army == heroStats->m_Level_Status)
            {
                if (1 != nrMatchingUnits)
                {
                    std::cout << "Wizard " << wizardNr << " has active hero " << heroNr << " but " << nrMatchingUnits << " units refer to the hero" << std::endl;
                    ok = false;
                }
            }
            else
            {
                if (0 != nrMatchingUnits)
                {
                    std::cout << "Wizard " << wizardNr << " has inactive hero " << heroNr << " but " << nrMatchingUnits << " units refer to the hero" << std::endl;
                    ok = false;
                }
            }
        }
    }

    return ok;
}

}
