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

#include "MoMCity.h"
#include "MoMGenerated.h"
#include "MoMUnit.h"
#include "MoMUtility.h"

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

static bool producingGarrison(const City* city)
{
    return (city->m_Producing >= PRODUCING_BUILDING_MAX);
}

//bool MoMController::addCityToGameQueue(int cityNr)
//{
//    MoMDataSegment* dataSegment = m_game->getDataSegment();
//    if (0 == dataSegment)
//        return false;
//    if (dataSegment->m_nr_city_queue <= 0)
//        return false;   // Queue is not active now. It has no point to fiddle with it now.

//    bool found = false;
//    for (int queueNr = 0; (queueNr < dataSegment->m_nr_city_queue) && (queueNr < ARRAYSIZE(dataSegment->m_arr20_city_queue)); ++queueNr)
//    {
//        CityQueueElement* queueElt = dataSegment->m_arr20_city_queue[queueNr];
//        if (cityNr == queueElt->m_CityNr)
//        {
//            found = true;
//            break;      // Already in queue
//        }
//        if (producingGarrison(*city) && 2 == unitsInCity.size())
//        if (cityNr == queueElt->m_CityNr)
//        {
//            int8_t newCityNr = -1;
//            removed = m_game->commitData(&queueElt->m_CityNr, &newCityNr, sizeof(queueElt->m_CityNr));
//            break;
//        }
//    }

//    return removed;
//    if (producingGarrison(*city) && unitsInCity.size()
//    {
//        // Do nothing - we're producing a Garrison
//        //std::cout << "City '" << city->m_City_Name << "' [" << cityNr << "] "
//        //    << city->m_Producing << " keeps producing a garrison" << std::endl;
//    }
//    else if (0 == unitsInCity.size() && !producingGarrison(*city) && findCheapestUnitToProduce(*city, produce))

//}

bool MoMController::addUnit(ePlayer playerNr, eUnit_Type unitType)
{
	m_errorString.clear();

    if (0 == m_game)
        return false;

    if ((unsigned)unitType >= eUnit_Type_MAX)
    {
        std::cout << "Cannot add unit " << unitType << " because it is out-of-range" << std::endl;
		m_errorString = "UnitType '" + toStr(unitType) + "' is out-of-range";
        return false;
    }

    Wizard* wizard = m_game->getWizard(playerNr);
    if (0 == wizard)
	{
		m_errorString = "Wizard data of player '" + toStr(playerNr) + "' is not accessible";
        return false;
	}

    // TODO: Check playerNr range + wizard not destroyed

	// Create a new unit that is not in the game yet
    int unitNr = -1;
    bool ok = createUnit(unitNr);

    Unit* unit = m_game->getUnit(unitNr);
    if (0 == unit)
	{
		m_errorString = "Failed to create a unit for unitNr '" + toStr(unitNr) + "'";
        ok = false;
	}

	// Initialize the unit to be on the board
	if (ok) 
	{
        assert(unitNr == m_game->getNrUnits());

		unit->m_Unit_Type = unitType;
		// TODO: Check if there is space
		unit->m_XPos = (uint8_t)wizard->m_X_Coordinate_of_Summoning_Circle;
		unit->m_YPos = (uint8_t)wizard->m_Y_Coordinate_of_Summoning_Circle;
		unit->m_Plane = wizard->m_Plane_of_Summoning_Circle;
		unit->m_Owner = playerNr;
		unit->m_Hero_Slot_Number = -1;
		unit->m_Moves_Total = 2;
		unit->m_Moves_Left = 2;
        unit->m_Scouting = 1;
		unit->m_Road_Building_left_to_complete = -1;
	}

	// Polymorph the unit to a hero if applicable
    if (ok && ((unsigned)unitType < gMAX_HERO_TYPES))
	{
        ok = polymorphToHero(playerNr, unitNr, unitType);
	}

	// Put the unit in the game
    if (ok)
    {
        ok = m_game->setNrUnits(unitNr + 1);
    }

    return ok;
}

bool MoMController::addArtifact(ePlayer playerNr, int prefabNr)
{
    m_errorString.clear();
    if (0 == m_game)
        return false;

    // Retrieve item data (or fail)
    ItemDataLbx* prefabItemData = m_game->getItemDataLbx(prefabNr);
    if (0 == prefabItemData)
    {
        m_errorString = "no such item available";
        return false;
    }

    // Check if already in game
    uint8_t* artifactsInGame = m_game->getArtifacts_in_game();
    if (0 == artifactsInGame)
        return false;
    if (artifactsInGame[prefabNr])
    {
        m_errorString = "item has already been seen in the game";
        return false;
    }

    // Find free item slot for its attributes (or fail)
    int16_t freeItemNr = -1;
    Item* freeItem = 0;
    for (int itemNr = 0; (0 == freeItem) && (toUInt(itemNr) < gMAX_ITEMS_IN_GAME); ++itemNr)
    {
        Item* item = m_game->getItem(itemNr);
        if ((0 == item->m_Cost) || (-1 == item->m_Cost))
        {
            freeItemNr = itemNr;
            freeItem = item;
        }
    }
    if (0 == freeItem)
    {
        m_errorString = "maximum items in the games reached";
        return false;
    }

    // Find free item slot in fortress (or fail)
    Wizard* wizard = m_game->getWizard(playerNr);
    int fortressSlotNr = -1;
    for (int slotNr = 0; (-1 == fortressSlotNr) && (toUInt(slotNr) < ARRAYSIZE(wizard->m_Items_in_Slots)); ++slotNr)
    {
        if (-1 == wizard->m_Items_in_Slots[slotNr])
        {
            fortressSlotNr = slotNr;
        }
    }
    if (-1 == fortressSlotNr)
    {
        m_errorString = "no free space in your fortress";
        return false;
    }

    // NiceToHave - check if book requirements satisfied

    // Mark the item as ingame (or fail if already in game)
    // Copy the item's attributes
    // Link item to item slot in fortress
    uint8_t newInGame = true;
    if (!m_game->commitData(&artifactsInGame[prefabNr], &newInGame, sizeof(artifactsInGame[prefabNr]))
            || !m_game->commitData(freeItem, &prefabItemData->m_Item, sizeof(*freeItem))
            || !m_game->commitData(&wizard->m_Items_in_Slots[fortressSlotNr], &freeItemNr, sizeof(wizard->m_Items_in_Slots[fortressSlotNr])))
    {
        m_errorString = "failed to commit the changes to the game";
        return false;
    }

    return true;
}

bool MoMController::applyBuildingQueue(int cityNr)
{
	m_errorString.clear();
    if (0 == m_game)
        return false;

    City* city = m_game->getCity(cityNr);
    if (0 == city)
	{
        m_errorString = "cannot get the data for to city  '" + toStr(cityNr) + "'";
        return false;
	}
    MoMCity momCity(m_game, city);

    eProducing producingBefore = city->m_Producing;
    eProducing producingAfter = city->m_Producing;
    eProducing produce = PRODUCING_None;

    MoMLocation location(*city, MoMLocation::MAP_overland);
    int garrisonSize = countGarrison(location);

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
    //[Housing]             till Pop 4
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
    //[Stable]              if Animists Guild allowed
    //[Animists Guild]
    //[Parthenon]
    //[Shipwright Guild]    if Merchants Guild allowed
    //[Ship Yard Guild]     if Merchants Guild allowed
    //[Merchants Guild]
    //[Cathedral]
    //[Wizards Guild]

    if (CITYSIZE_Outpost == city->m_Size)
    {
        // Do nothing - we're an outpost
        std::cout << "City '" << city->m_City_Name << "' [" << cityNr << "] "
            << city->m_Producing << " is still an outpost" << std::endl;
    }
    else if (producingGarrison(city))
    {
        // Do nothing - we're producing a Garrison
        //std::cout << "City '" << city->m_City_Name << "' [" << cityNr << "] "
        //    << city->m_Producing << " keeps producing a garrison" << std::endl;
    }
    else if (0 == garrisonSize && !producingGarrison(city) && findCheapestUnitToProduce(*city, produce) && momCity.canProduce(produce))
    {
        // Switch from any task to Spearmen if there is none
        producingAfter = produce;
    }
    else if (PRODUCING_Housing != city->m_Producing
          && PRODUCING_Trade_Goods != city->m_Producing)
    {
        // Do nothing - someone specified something to build
    }
    else if (!momCity.isBuildingPresent(BUILDING_Builders_Hall))
    {
        producingAfter = PRODUCING_Builders_Hall;
    }
    else if (!momCity.isBuildingPresent(BUILDING_Granary))
    {
        producingAfter = PRODUCING_Granary;
    }
    else if (!momCity.isBuildingPresent(BUILDING_Smithy))
    {
        producingAfter = PRODUCING_Smithy;
    }
    else if (!momCity.isBuildingPresent(BUILDING_Marketplace))
    {
        producingAfter = PRODUCING_Marketplace;
    }
    else if (!momCity.isBuildingPresent(BUILDING_Farmers_Market))
    {
        producingAfter = PRODUCING_Farmers_Market;
    }
    else if (city->m_Population < 4)
    {
        producingAfter = PRODUCING_Housing;
    }

    else if (!momCity.isBuildingPresent(BUILDING_Shrine))
    {
        producingAfter = PRODUCING_Shrine;
    }
    else if (!momCity.isBuildingPresent(BUILDING_Sawmill) && momCity.canProduce(BUILDING_Sawmill))
    {
        producingAfter = PRODUCING_Sawmill;
    }
    else if (!momCity.isBuildingPresent(BUILDING_Foresters_Guild) && momCity.canProduce(BUILDING_Foresters_Guild))
    {
        producingAfter = PRODUCING_Foresters_Guild;
    }
    else if (!momCity.isBuildingPresent(BUILDING_Library) && momCity.canProduce(BUILDING_Library))
    {
        producingAfter = PRODUCING_Library;
    }
    else if (!momCity.isBuildingPresent(BUILDING_Sages_Guild) && momCity.canProduce(BUILDING_Sages_Guild))
    {
        producingAfter = PRODUCING_Sages_Guild;
    }
    else if (!momCity.isBuildingPresent(BUILDING_Temple) && momCity.canProduce(BUILDING_Temple))
    {
        producingAfter = PRODUCING_Temple;
    }
    else if (!momCity.isBuildingPresent(BUILDING_Alchemist_Guild) && momCity.canProduce(BUILDING_Alchemist_Guild))
    {
        producingAfter = PRODUCING_Alchemist_Guild;
    }
    else if (!momCity.isBuildingPresent(BUILDING_University) && momCity.canProduce(BUILDING_University))
    {
        producingAfter = PRODUCING_University;
    }
    else if (!momCity.isBuildingPresent(BUILDING_Bank) && momCity.canProduce(BUILDING_Bank))
    {
        producingAfter = PRODUCING_Bank;
    }
    else if (!momCity.isBuildingPresent(BUILDING_Miners_Guild) && momCity.canProduce(BUILDING_Miners_Guild))
    {
        producingAfter = PRODUCING_Miners_Guild;
    }
    else if (!momCity.isBuildingPresent(BUILDING_Animists_Guild) && momCity.canProduce(BUILDING_Animists_Guild))
    {
        producingAfter = PRODUCING_Animists_Guild;
    }
    else if (momCity.isBuildingAllowed(BUILDING_Animists_Guild) && !momCity.isBuildingPresent(BUILDING_Stable) && momCity.canProduce(BUILDING_Stable))
    {
        producingAfter = PRODUCING_Stable;
    }
    else if (!momCity.isBuildingPresent(BUILDING_Parthenon) && momCity.canProduce(BUILDING_Parthenon))
    {
        producingAfter = PRODUCING_Parthenon;
    }
    else if (!momCity.isBuildingPresent(BUILDING_Merchants_Guild) && momCity.canProduce(BUILDING_Merchants_Guild))
    {
        producingAfter = PRODUCING_Merchants_Guild;
    }
    else if (momCity.isBuildingAllowed(BUILDING_Merchants_Guild) && !momCity.isBuildingPresent(BUILDING_Shipwright_Guild)
             && momCity.canProduce(BUILDING_Shipwright_Guild))
    {
        producingAfter = PRODUCING_Shipwright_Guild;
    }
    else if (momCity.isBuildingAllowed(BUILDING_Merchants_Guild) && !momCity.isBuildingPresent(BUILDING_Ship_Yard)
             && momCity.canProduce(BUILDING_Ship_Yard))
    {
        producingAfter = PRODUCING_Ship_Yard;
    }
    else if (!momCity.isBuildingPresent(BUILDING_Cathedral) && momCity.canProduce(BUILDING_Cathedral))
    {
        producingAfter = PRODUCING_Cathedral;
    }
    else if (!momCity.isBuildingPresent(BUILDING_Wizards_Guild) && momCity.canProduce(BUILDING_Wizards_Guild))
    {
        producingAfter = PRODUCING_Wizards_Guild;
    }
    else
    {
        // Do nothing - all specified buildings have been built
        //std::cout << "City " << city->m_City_Name
        //    << " (" << city->m_Producing << ") has built all specified buildings" << std::endl;
    }

    if (producingBefore == producingAfter)
    {
        return false;   // No change
    }

    if (!m_game->commitData(&city->m_Producing, &producingAfter, sizeof(city->m_Producing)))
    {
        std::cout << "Failed to chang production of '" << city->m_City_Name << "' [" << cityNr << "] "
                  << producingBefore << "\n\tto " << producingAfter << std::endl;
        return false;   // Failed to change
    }

    // Remove city from game queue to pop up the city screen, if we managed the production
    removeCityFromGameQueue(cityNr);

    std::cout << "Changed production of '" << city->m_City_Name << "' [" << cityNr << "] "
              << producingBefore << " to " << producingAfter << std::endl;
    return true;
}

bool MoMController::applyBuildingQueue(ePlayer playerNr)
{
	m_errorString.clear();

    if (0 == m_game)
        return false;

    bool changed = false;
    for (int cityNr = 0; cityNr < m_game->getNrCities(); ++cityNr)
    {
        const City* city = m_game->getCity(cityNr);
        if (0 == city)
            break;

        if (city->m_Owner == playerNr)
        {
            changed |= applyBuildingQueue(cityNr);
        }
    }
    return changed;
}

bool MoMController::buyProduction(City *city)
{
    m_errorString.clear();
    if (0 == m_game)
        return false;
    MoMCity momCity(m_game, city);
    int costToBuy = momCity.getCostToBuy(city->m_Producing);
    Wizard* wizard = m_game->getWizard(PLAYER_YOU);
    if (0 == wizard)
        return false;
    if (costToBuy <= 0)
    {
        m_errorString = "Cannot buy. Production will already be complete.";
        std::cout << m_errorString << std::endl;
        return false;
    }
    if (wizard->m_Gold_Coins < costToBuy)
    {
        m_errorString = "Not enough gold to buy production";
        std::cout << m_errorString << std::endl;
        return false;
    }

    int16_t newGold = wizard->m_Gold_Coins - costToBuy;
    int16_t newHammersAccumulated = momCity.getCostToProduce(city->m_Producing);
    if (!m_game->commitData(&wizard->m_Gold_Coins, &newGold, sizeof(wizard->m_Gold_Coins)))
    {
        m_errorString = "Failed to commit gold coin changes";
        std::cout << m_errorString << std::endl;
        return false;
    }
    if (!m_game->commitData(&city->m_HammersAccumulated, &newHammersAccumulated, sizeof(city->m_HammersAccumulated)))
    {
        m_errorString = "Failed to commit accumulated hammer changes";
        std::cout << m_errorString << std::endl;
        return false;
    }

    std::cout << "Bought " << city->m_Producing << " for " << costToBuy << " gold" << std::endl;
    return true;
}

int MoMController::calcFoodProduced(ePlayer playerNr) const
{
    if (0 == m_game)
        return 0;
    int foodProduced = 0;
    for (int cityNr = 0; cityNr < m_game->getNrCities(); ++cityNr)
    {
        City* city = m_game->getCity(cityNr);
        if (0 == city)
            break;
        if (playerNr != city->m_Owner)
            continue;
        if (city->m_Population < city->m_Food_Produced)
        {
            foodProduced += city->m_Food_Produced - city->m_Population;
        }
    }
    return foodProduced;
}

int MoMController::calcFoodUpkeep(ePlayer playerNr) const
{
    if (0 == m_game)
        return 0;
    int foodUpkeep = 0;
    for (int unitNr = 0; unitNr < m_game->getNrUnits(); ++unitNr)
    {
        Unit* unit = m_game->getUnit(unitNr);
        if (0 == unit)
            break;
        if (playerNr != unit->m_Owner)
            continue;
        MoMUnit momUnit(m_game, unit);
        if (momUnit.isNormal() && !unit->m_Weapon_Mutation.s.Undead)
        {
            foodUpkeep++;
        }
    }
    return foodUpkeep;
}

int MoMController::calcGoldIncome(ePlayer playerNr) const
{
    if (0 == m_game)
        return 0;
    int goldProduced = 0;
    for (int cityNr = 0; cityNr < m_game->getNrCities(); ++cityNr)
    {
        City* city = m_game->getCity(cityNr);
        if (0 == city)
            break;
        if (playerNr != city->m_Owner)
            continue;
        goldProduced += city->m_Coins - city->m_Maintenance;
    }

    for (int heroSlotNr = 0; toUInt(heroSlotNr) < gMAX_HIRED_HEROES; ++heroSlotNr)
    {
        Hired_Hero* hiredHero = m_game->getHiredHero(playerNr, heroSlotNr);
        MoMUnit momUnit(m_game, hiredHero);
        if (momUnit.hasHeroAbility(HEROABILITY_Noble))
        {
            goldProduced += momUnit.getHeroAbility(HEROABILITY_Noble);
        }
    }

    int foodSurplus = calcFoodProduced(playerNr) - calcFoodUpkeep(playerNr);
    goldProduced += foodSurplus / 2;

    return goldProduced;
}

int MoMController::calcGoldUpkeep(ePlayer playerNr) const
{
    if (0 == m_game)
        return 0;
    int goldUpkeep = 0;
    for (int unitNr = 0; unitNr < m_game->getNrUnits(); ++unitNr)
    {
        Unit* unit = m_game->getUnit(unitNr);
        if (0 == unit)
            break;
        if (playerNr != unit->m_Owner)
            continue;
        MoMUnit momUnit(m_game, unit);
        goldUpkeep += momUnit.calcGoldUpkeep();
    }

    goldUpkeep -= calcTotalFame(playerNr);

    if (goldUpkeep < 0)
    {
        goldUpkeep = 0;
    }

    // TODO: Difficulty multiplier

    return goldUpkeep;
}

int MoMController::calcTotalFame(ePlayer playerNr) const
{
    if (0 == m_game)
        return 0;

    int fame = 0;
    for (int heroSlotNr = 0; toUInt(heroSlotNr) < gMAX_HIRED_HEROES; ++heroSlotNr)
    {
        Hired_Hero* hiredHero = m_game->getHiredHero(playerNr, heroSlotNr);
        MoMUnit momUnit(m_game, hiredHero);
        if (momUnit.hasHeroAbility(HEROABILITY_Legendary))
        {
            fame += momUnit.getHeroAbility(HEROABILITY_Legendary);
        }
        if (momUnit.hasHeroAbility(HEROABILITY_Legendary_X))
        {
            fame += momUnit.getHeroAbility(HEROABILITY_Legendary_X);
        }
    }

    Wizard* wizard = m_game->getWizard(playerNr);
    if (0 != wizard)
    {
        if (wizard->m_Global_Enchantments.Just_Cause)
        {
            fame += 10;
        }

        fame += wizard->m_Fame;
    }

    return fame;
}

int MoMController::countGarrison(const MoMLocation &location)
{
    std::vector<int> units;
    m_game->findUnitsAtLocation(location, units);

    // Count regular units, including catapults, excluding ships, settlers, heroes
    int count = 0;
    for (size_t i = 0; i < units.size(); ++i)
    {
        Unit* unit = m_game->getUnit(units[i]);
        MoMUnit momUnit(m_game);
        momUnit.changeUnit(unit);
        if (!momUnit.isNormal())
            continue;
        if (momUnit.isShip())
            continue;
        if (momUnit.isSettler())
            continue;
        count++;
    }

    return count;
}

int MoMController::countUnits(const MoMLocation &location)
{
    std::vector<int> units;
    m_game->findUnitsAtLocation(location, units);
    return units.size();
}

bool MoMController::createUnit(int& unitNr)
{
	m_errorString.clear();

    if (0 == m_game)
        return false;

    if (m_game->getNrUnits() < 0
        || m_game->getNrUnits() >= (int)gMAX_UNITS)
    {
        std::cout << "Cannot create a unit because NrUnits is out-of-range" << std::endl;
        m_errorString = "Cannot create a unit because NrUnits '" + toStr(m_game->getNrUnits()) + "' is out-of-range";
        return false;
    }

    unitNr = m_game->getNrUnits();

    Unit* unit = m_game->getUnit(unitNr);
    if (0 == unit)
	{
		m_errorString = "Cannot retrieve data for unit '" + toStr(unitNr) + "'";
        return false;
	}

    memset(unit, '\0', sizeof(Unit));

    // Make sure the unit contains "reasonable" data
    unit->m_Hero_Slot_Number = -1;
    unit->m_Moves_Total = 2;
    unit->m_Moves_Left = 2;
    unit->m_Road_Building_left_to_complete = -1;

    return true;
}

bool MoMController::findCheapestUnitToProduce(const City& city, eProducing& produce)
{
    if (0 == m_game)
        return false;
    bool found = false;
	for (eUnit_Type unitTypeNr = UNITTYPE_FIRST; !found && (toUInt(unitTypeNr) < eUnit_Type_MAX); inc(unitTypeNr))
	{
        MoMUnit momUnit(m_game);
        momUnit.changeUnit(unitTypeNr);
        if (momUnit.isShip())
            continue;   // Disregard ships
        if (momUnit.isSettler())
            continue;   // Disregard settlers
        if (momUnit.isBuildable(city))
		{
			produce = static_cast<eProducing>(toUInt(unitTypeNr) - toUInt(UNITTYPE_Trireme) + toUInt(PRODUCING_Trireme));
			found = true;
		}
	}
    return found;
}

City* MoMController::findCityAtLocation(const MoMLocation &location)
{
    City* value = 0;

    if (0 == m_game)
        return value;

    for (int i = 0; i < m_game->getNrCities(); ++i)
    {
        City* city = m_game->getCity(i);
        if (0 == city)
            break;
        if (location == MoMLocation(*city, MoMLocation::MAP_overland))
        {
            value = city;
            break;
        }
    }
    return value;
}

Node_Attr* MoMController::findNodeAttrAtLocation(const MoMLocation& location)
{
    Node_Attr* value = 0;

    if (0 == m_game)
        return value;

    for (size_t i = 0; i < gMAX_NODES; ++i)
    {
        Node_Attr* nodeAttr = m_game->getNodeAttr(i);
        if (0 == nodeAttr)
            break;
        if (location == MoMLocation(*nodeAttr, MoMLocation::MAP_overland))
        {
            value = nodeAttr;
            break;
        }
    }
    return value;
}

bool MoMController::polymorphToHero(ePlayer playerNr, int unitNr, eUnit_Type heroNr)
{
	m_errorString.clear();

    if (0 == m_game)
        return false;

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

    const Unit_Type_Data* unitTypeData = m_game->getUnitTypeData(heroNr);
    if (0 == unitTypeData)
        return false;
    Hero_stats* heroStats = m_game->getHeroStats(playerNr, heroNr);
    if (0 == heroStats)
        return false;
    Unit* unit = m_game->getUnit(unitNr);
    if (0 == unit)
        return false;
    Wizard* wizard = m_game->getWizard(playerNr);
    if (0 == wizard)
        return false;

    // CHECKS

	// TODO: Check if the unit is already a hero in which case we need a different scenario
	//       1. Reuse the current heroSlotNr
	//		 2. Bury the old hero

	// Retrieve the slot types
    m_game->getHeroSlotTypes(unitTypeData->m_Building2_or_HeroType, heroSlotTypes);

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

    // Commit
    if (!m_game->commitData(unit, unit, sizeof(*unit))
        || !m_game->commitData(&hiredHero, &hiredHero, sizeof(hiredHero))
        || !m_game->commitData(&heroStats->m_Level_Status, &heroStats->m_Level_Status, sizeof(heroStats->m_Level_Status)))
    {
        m_errorString = "Failed to commit to game";
        std::cout << m_errorString << std::endl;
        return false;
    }

    return true;
}

bool MoMController::removeCityFromGameQueue(int cityNr)
{
    MoMDataSegment* dataSegment = m_game->getDataSegment();
    if (0 == dataSegment)
        return false;
    bool removed = false;
    for (int queueNr = 0; (queueNr < dataSegment->m_nr_city_queue) && (toUInt(queueNr) < ARRAYSIZE(dataSegment->m_arr20_city_queue)); ++queueNr)
    {
        CityQueueElement* queueElt = &dataSegment->m_arr20_city_queue[queueNr];
        if (cityNr == queueElt->m_CityNr)
        {
            int8_t newCityNr = -1;
            removed = m_game->commitData(&queueElt->m_CityNr, &newCityNr, sizeof(queueElt->m_CityNr));
            break;
        }
    }
    return removed;
}

bool MoMController::repopLairs(bool maxOut)
{
	m_errorString.clear();

    if (0 == m_game)
        return false;

    for (unsigned lairNr = 0; lairNr < gMAX_NODES_LAIRS_TOWERS; ++lairNr)
    {
        Tower_Node_Lair* lair = m_game->getLair(lairNr);
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

    bool ok = m_game->commitData(m_game->getLair(0), m_game->getLair(0), gMAX_NODES_LAIRS_TOWERS * sizeof(Tower_Node_Lair));

    return ok;
}

}
