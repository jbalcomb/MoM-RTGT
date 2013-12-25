#include "MoMCity.h"

#include "MoMGameBase.h"

namespace MoM {

MoMCity::MoMCity(MoMGameBase *game, const City *city) :
    m_game(game),
    m_city(city)
{
}

bool MoMCity::canProduce(eBuilding building) const
{
    // Cannot build what is already there
    if (isBuildingPresent(building))
        return false;

    bool allowed = true;

    // Check prohibited buildings
    Race_Data* raceData = m_game->getRaceData(m_city->m_Race);
    if (0 == raceData)
        return false;
    for (unsigned i = 0; allowed
        && (i < raceData->m_Number_of_prohibited_buildings)
        && (i < ARRAYSIZE(raceData->m_Prohibited_buildings));
        ++i)
    {
        if (building == raceData->m_Prohibited_buildings[i])
        {
            allowed = false;
        }
    }

    // Check prerequisites
    Building_Data* buildingData = m_game->getBuildingData(building);
    if (0 == buildingData)
        return false;
    if (!isBuildingPresent(buildingData->m_Prerequisite1))
    {
        allowed = false;
    }
    if (!isBuildingPresent(buildingData->m_Prerequisite2))
    {
        allowed = false;
    }

    // TODO: Check forests for Sawmill
    // TODO: Check hills/mountains/volcanoes(?) for Miners Guild

    return allowed;
}

bool MoMCity::canProduce(eProducing produce) const
{
    bool allowed = canProduce(static_cast<eBuilding>(produce));
    if (!allowed)
    {
        allowed = canProduce(static_cast<eUnit_Type>(toUInt(produce) - 100));
    }
    return allowed;
}

bool MoMCity::canProduce(eUnit_Type unitTypeNr) const
{
    Unit_Type_Data* unitType = m_game->getUnitTypeData(unitTypeNr);
    if (0 == unitType)
        return false;

    // Check race
    if ((unitType->m_Race_Code != m_city->m_Race) && (unitType->m_Race_Code != RACE_Generic_ship_or_catapult))
    {
        return false;   // Wrong race and not generic
    }

    // Check building requirements
    if (unitType->m_Building1Required_or_PortraitLbxIndex == BUILDING_None)
    {
        // Building requirements satisfied
    }
    else if ((toUInt(unitType->m_Building1Required_or_PortraitLbxIndex) < eBuilding_array_MAX)
             && (m_city->m_Building_Status.a[unitType->m_Building1Required_or_PortraitLbxIndex] != BUILDINGSTATUS_Built)
             && (m_city->m_Building_Status.a[unitType->m_Building1Required_or_PortraitLbxIndex] != BUILDINGSTATUS_Replaced))
    {
        return false;   // First required building not present
    }
    else if (unitType->m_Building2_or_HeroType == BUILDING_None)
    {
        // Building requirements satisfied
    }
    else if ((toUInt(unitType->m_Building2_or_HeroType) < eBuilding_array_MAX)
             && (m_city->m_Building_Status.a[unitType->m_Building2_or_HeroType] != BUILDINGSTATUS_Built)
             && (m_city->m_Building_Status.a[unitType->m_Building2_or_HeroType] != BUILDINGSTATUS_Replaced))
    {
        return false;   // Second required building not present
    }

    // Check if there is space
    std::vector<int> units;
    m_game->findUnitsAtLocation(MoMLocation(*m_city), units);
    if (units.size() >= gMAX_UNITS_IN_LOCATION)
        return false;

    return true;
}

int MoMCity::getCostToProduce(eProducing producing) const
{
    int buildingCost = -1;
    if (producing < MoM::PRODUCING_BUILDING_MAX)
    {
        MoM::Building_Data* buildingData = m_game->getBuildingData((eBuilding)producing);
        if (0 != buildingData)
        {
            buildingCost = buildingData->m_Building_cost;
        }
    }
    else
    {
        MoM::eUnit_Type unitTypeNr = (MoM::eUnit_Type)((int)producing - (int)MoM::PRODUCING_Trireme + (int)MoM::UNITTYPE_Trireme);
        MoM::Unit_Type_Data* unitData = m_game->getUnitTypeData(unitTypeNr);
        if (0 != unitData)
        {
            buildingCost = unitData->m_Cost;
        }
    }
    return buildingCost;
}

int MoMCity::getTimeToComplete(eProducing producing) const
{
    // TODO: Count coal and iron for unit cost reduction (other factors?)
    int timeCompletion = 999;
    if (m_city->m_Hammers > 0)
    {
        int buildingCost = getCostToProduce(producing);
        timeCompletion = (buildingCost - m_city->m_HammersAccumulated + m_city->m_Hammers - 1) / m_city->m_Hammers;
    }
    return timeCompletion;
}

bool MoMCity::isBuildingPresent(eBuilding building) const
{
    if (toUInt(building) >= eBuilding_array_MAX)
        return false;
    return (BUILDINGSTATUS_Built == m_city->m_Building_Status.a[building])
            || (BUILDINGSTATUS_Replaced == m_city->m_Building_Status.a[building]);
}

}
