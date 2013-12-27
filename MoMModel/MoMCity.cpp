#include "MoMCity.h"

#include "MoMGameBase.h"
#include "MoMTerrain.h"

namespace MoM {

MoMCity::MoMCity(MoMGameBase *game, const City *city) :
    m_game(game),
    m_city(city)
{
}

int MoMCity::calcBasicFood() const
{
    class CountBasicFood
    {
    public:
        CountBasicFood() : food(0) {}
        bool operator()(const MoMTerrain& terrain)
        {
            food += terrain.getBasicFoodBonus();
            return false;
        }
        int food;
    };

    CountBasicFood count;
    enumerateTerrain(count);

    int basicFood = count.food;
    if (OWNER_None != m_city->m_City_Enchantments.Gaias_Blessing)
    {
        basicFood = basicFood * 3 / 2;
    }

    basicFood /= 4;

    return basicFood;
}

int MoMCity::calcProductionBonusPercentage() const
{
    class CountProductionPercentage
    {
    public:
        CountProductionPercentage(bool gaiasBlessing) : m_gaiasBlessing(gaiasBlessing), productionPercentage(0) {}
        bool operator()(const MoMTerrain& terrain)
        {
            productionPercentage += terrain.getProductionPercentage(m_gaiasBlessing);
            return false;
        }
        bool m_gaiasBlessing;
        int productionPercentage;
    };

    CountProductionPercentage count(OWNER_None != m_city->m_City_Enchantments.Gaias_Blessing);
    enumerateTerrain(count);

    return count.productionPercentage;
}

int MoMCity::calcFoodProduced() const
{
    if (m_city->m_Population <= 0)
        return 0;

    int basicFood = calcBasicFood();
    int nrFarmers = Min(m_city->m_Number_of_farmers_allocated, m_city->m_Population);
    int food = 0;

    if ((m_city->m_Race == RACE_Halfling) || isBuildingPresent(BUILDING_Animists_Guild))
    {
        food = 3 * nrFarmers;
    }
    else
    {
        food = 2 * nrFarmers;
    }

    if (isBuildingPresent(BUILDING_Foresters_Guild))
    {
        food += 2;
    }
    if (OWNER_None != m_city->m_City_Enchantments._Famine_)
    {
        food /= 2;
    }
    if (food > basicFood)
    {
        food = basicFood + (food - basicFood) / 2;
    }
    if (isBuildingPresent(BUILDING_Granary))
    {
        food += 2;
    }
    if (isBuildingPresent(BUILDING_Farmers_Market))
    {
        food += 3;
    }
    food += getWildGameBonus();

    return food;
}

int MoMCity::calcHammersProduced() const
{
    if (m_city->m_Population <= 0)
        return 0;

    int nrFarmers = Min(m_city->m_Number_of_farmers_allocated, m_city->m_Population);
    int nrWorkers = calcNrWorkers();
    int doubledHammersPerWorker = 4;
    if ((m_city->m_Race == RACE_Dwarven) || (m_city->m_Race == RACE_Klackon))
    {
        doubledHammersPerWorker = 6;
    }
    int hammers = (nrWorkers * doubledHammersPerWorker + nrFarmers + 1) / 2;

    int prodPercentage = 100;
    prodPercentage += calcProductionBonusPercentage();
    if (isBuildingPresent(BUILDING_Foresters_Guild))
    {
        prodPercentage += 25;
    }
    if (isBuildingPresent(BUILDING_Sawmill))
    {
        prodPercentage += 25;
    }
    if (isBuildingPresent(BUILDING_Miners_Guild))
    {
        prodPercentage += 50;
    }
    if (isBuildingPresent(BUILDING_Mechanicians_Guild))
    {
        prodPercentage += 50;
    }
    if (OWNER_None != m_city->m_City_Enchantments.Inspirations)
    {
        prodPercentage += 100;
    }

    hammers = hammers * prodPercentage / 100;

    if (OWNER_None != m_city->m_City_Enchantments._Cursed_Lands_)
    {
        hammers /= 2;
    }

    return hammers;
}

int MoMCity::calcCurrentMaxPop() const
{
    int maxPop = calcBasicFood();

    if (isBuildingPresent(BUILDING_Granary))
    {
        maxPop += 2;
    }
    if (isBuildingPresent(BUILDING_Farmers_Market))
    {
        maxPop += 3;
    }
    maxPop += getWildGameBonus();

    return maxPop;
}

int MoMCity::calcTopMaxPop() const
{
    int maxPop = calcBasicFood();
    maxPop += 2;    // Granary
    maxPop += 3;    // Farmers Market
    maxPop += getWildGameBonus();

    return maxPop;
}

int MoMCity::calcNrRebels() const
{
    Wizard* wizard = m_game->getWizard(m_city->m_Owner);
    if (0 == wizard)
        return 0;

    const uint16_t* taxUnrestTable = m_game->getTaxUnrestTable();
    int unrestPercentage = taxUnrestTable[wizard->m_Tax_Rate];

    eRace homeRace = wizard->m_Home_Race;
    const int8_t* racialUnrestTable = m_game->getUnrest_Table(homeRace);
    unrestPercentage += 10 * racialUnrestTable[m_city->m_Race];

    if (OWNER_None != m_city->m_City_Enchantments._Famine_)
    {
        unrestPercentage += 25;
    }

    int nrRebels = m_city->m_Population * unrestPercentage / 100;

    int pacifyingEffects = 0;

    if ((OWNER_None == m_city->m_City_Enchantments._Evil_Presence_)
            || (wizard->m_Number_of_Spellbooks_Death > 0))
    {
        int religiousEffects = 0;

        if (isBuildingPresent(BUILDING_Shrine))
        {
            religiousEffects++;
        }
        if (isBuildingPresent(BUILDING_Temple))
        {
            religiousEffects++;
        }
        if (isBuildingPresent(BUILDING_Parthenon))
        {
            religiousEffects++;
        }
        if (isBuildingPresent(BUILDING_Cathedral))
        {
            religiousEffects++;
        }
        if (wizard->m_Skills.s.Infernal_Power || wizard->m_Skills.s.Divine_Power)
        {
            religiousEffects += religiousEffects / 2;
        }

        pacifyingEffects += religiousEffects;
    }

    if (isBuildingPresent(BUILDING_Oracle))
    {
        pacifyingEffects += 2;
    }
    if (isBuildingPresent(BUILDING_Animists_Guild))
    {
        pacifyingEffects += 1;
    }

    for (int playerNr = 0; playerNr < m_game->getNrWizards(); ++playerNr)
    {
        if (playerNr == m_city->m_Owner)
            continue;
        Wizard* opponent = m_game->getWizard(playerNr);
        if (opponent->m_Global_Enchantments.Great_Wasting)
        {
            pacifyingEffects -= 1;
        }
        if (opponent->m_Global_Enchantments.Armageddon)
        {
            pacifyingEffects -= 2;
        }
    }

    if (OWNER_None != m_city->m_City_Enchantments.Dark_Rituals)
    {
        pacifyingEffects -= 1;
    }
    if (OWNER_None != m_city->m_City_Enchantments._Pestilence_)
    {
        pacifyingEffects -= 2;
    }
    if (OWNER_None != m_city->m_City_Enchantments._Cursed_Lands_)
    {
        pacifyingEffects -= 1;
    }
    if (wizard->m_Global_Enchantments.Just_Cause)
    {
        pacifyingEffects += 1;
    }
    if (OWNER_None != m_city->m_City_Enchantments.Gaias_Blessing)
    {
        pacifyingEffects += 2;
    }

    if (pacifyingEffects < nrRebels)
    {
        int unitEffects = 0;
        for (int unitNr = 0; unitNr < m_game->getNrUnits(); ++unitNr)
        {
            const Unit* unit = m_game->getUnit(unitNr);
            if (0 == unit)
                break;
            if (unit->m_Owner != m_city->m_Owner)
                continue;
            if (MoMLocation(*unit) != MoMLocation(*m_city))
                continue;
            if (unit->m_Unit_Type < UNITTYPE_Arcane_Magic_Spirit)
            {
                unitEffects += 1;
            }
        }
        pacifyingEffects += unitEffects / 2;
    }

    nrRebels = Max(0, nrRebels - pacifyingEffects);

    if (OWNER_None != m_city->m_City_Enchantments.Stream_of_Life)
    {
        nrRebels = 0;
    }

    nrRebels = Min(nrRebels, (int)m_city->m_Population);

    return nrRebels;
}

int MoMCity::calcNrWorkers() const
{
    if (m_city->m_Population <= 0)
        return 0;

    int nrFarmers = Min(m_city->m_Number_of_farmers_allocated, m_city->m_Population);
    int nrRebels  = calcNrRebels();
    int nrWorkers = m_city->m_Population - nrFarmers - nrRebels;

    return nrWorkers;
}

bool MoMCity::canProduce(eBuilding building) const
{
    // Cannot build what is already there
    if (isBuildingPresent(building))
        return false;

    bool allowed = true;

    // Check prohibited buildings
    allowed = isBuildingAllowed(building);

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

const City *MoMCity::getCity() const
{
    return m_city;
}

template<typename Functor>
bool MoMCity::enumerateTerrain(Functor& functor) const
{
    for (int dy = -2; dy <= 2; ++dy)
    {
        for (int dx = -2; dx <= 2; ++dx)
        {
            if (Abs(dx) + Abs(dy) >= 4)
                continue;
            MoMLocation location(
                        (m_city->m_XPos + dx + gMAX_MAP_COLS) % gMAX_MAP_COLS,
                        (m_city->m_YPos + dy + gMAX_MAP_ROWS) % gMAX_MAP_ROWS,
                        m_city->m_Plane,
                        MoMLocation::MAP_overland);
            MoMTerrain terrain(m_game, location);
            if (functor(terrain))
                return true;
        }
    }
    return false;
}

int MoMCity::getCostToBuy(eProducing producing) const
{
    if (PRODUCING_None == producing)
    {
        producing = m_city->m_Producing;
    }

    int buildingCost = getCostToProduce(producing);
    int producedNextTurn = m_city->m_HammersAccumulated + m_city->m_Hammers;
    int productionRemaining = buildingCost - m_city->m_HammersAccumulated;
    int buyCost;
    if (m_city->m_HammersAccumulated <= 0)
    {
        buyCost = 4 * productionRemaining;
    }
    else if (m_city->m_HammersAccumulated < buildingCost / 3)
    {
        buyCost = 3 * productionRemaining;
    }
    else if (producedNextTurn < buildingCost)
    {
        buyCost = 2 * productionRemaining;
    }
    else
    {
        buyCost = 0;    // Cannot buy - completed next turn
    }
    return buyCost;
}

int MoMCity::getCostToProduce(eProducing producing) const
{
    if (PRODUCING_None == producing)
    {
        producing = m_city->m_Producing;
    }

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

        int reductionPercentage = getUnitReductionPercentage();
        buildingCost = buildingCost * (100 - reductionPercentage) / 100;
        if (buildingCost < 0)
        {
            buildingCost = 0;
        }
    }
    return buildingCost;
}

int MoMCity::getTimeToComplete(eProducing producing) const
{
    if (PRODUCING_None == producing)
    {
        producing = m_city->m_Producing;
    }

    int timeCompletion = 999;
    if (m_city->m_Hammers > 0)
    {
        int buildingCost = getCostToProduce(producing);
        timeCompletion = (buildingCost - m_city->m_HammersAccumulated + m_city->m_Hammers - 1) / m_city->m_Hammers;
    }
    return timeCompletion;
}

int MoMCity::getUnitReductionPercentage() const
{
    // TODO: Count for half (?) if on terrain shared with another city
    // TODO: Refactor to MoMTerrain::getUnitReduction()
    class CountUnitReduction
    {
    public:
        CountUnitReduction() : reduction(0) {}
        bool operator()(const MoMTerrain& terrain)
        {
            if (terrain.getChanges().corruption)
            {
            }
            else if (terrain.getBonus() == DEPOSIT_Iron_Ore)
            {
                reduction += 5;
            }
            else if (terrain.getBonus() == DEPOSIT_Coal)
            {
                reduction += 10;
            }
            return false;
        }
        int reduction;
    };

    CountUnitReduction count;
    enumerateTerrain(count);
    return count.reduction;
}

int MoMCity::getWildGameBonus() const
{
    class CountWildGame
    {
    public:
        CountWildGame() : food(0) {}
        bool operator()(const MoMTerrain& terrain)
        {
            if (terrain.getChanges().corruption)
                return false;
            if (terrain.getBonus() == DEPOSIT_Wild_Game)
            {
                if (terrain.isSharedBetweenCities())
                {
                    food++;
                }
                else
                {
                    food += 2;
                }
            }
            return false;
        }
        int food;
    };

    CountWildGame count;
    enumerateTerrain(count);
    return count.food;
}

bool MoMCity::hasForestRequirement() const
{
    class CheckCleanForest
    {
    public:
        bool operator()(const MoMTerrain& terrain)
        {
            return ((terrain.getCategory() == TERRAINCATEGORY_Forest)
                    && (!terrain.getChanges().corruption));
        }
    };

    return enumerateTerrain(CheckCleanForest());
}

bool MoMCity::hasHillRequirement() const
{
    class CheckCleanHill
    {
    public:
        bool operator()(const MoMTerrain& terrain)
        {
            if (terrain.getChanges().corruption)
                return false;
            return ((terrain.getCategory() == TERRAINCATEGORY_Hills)
                    || (terrain.getCategory() == TERRAINCATEGORY_Mountain)
                    || (terrain.getCategory() == TERRAINCATEGORY_Volcano));
        }
    };

    return enumerateTerrain(CheckCleanHill());
}

bool MoMCity::hasWaterRequirement() const
{
    class CheckCleanWater
    {
    public:
        bool operator()(const MoMTerrain& terrain)
        {
            if (terrain.getChanges().corruption)
                return false;
            return ((terrain.getCategory() == TERRAINCATEGORY_Ocean)
                    || (terrain.getCategory() == TERRAINCATEGORY_Shore));
        }
    };

    return enumerateTerrain(CheckCleanWater());
}

bool MoMCity::isBuildingAllowed(eBuilding building) const
{
    // Check prohibited buildings
    Race_Data* raceData = m_game->getRaceData(m_city->m_Race);
    if (0 == raceData)
        return false;
    bool allowed = true;
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
    return allowed;
}

bool MoMCity::isBuildingPresent(eBuilding building) const
{
    if (building == BUILDING_Forest)
    {
        return hasForestRequirement();
    }
    else if (building == BUILDING_Hill)
    {
        return hasHillRequirement();
    }
    else if (building == BUILDING_Water)
    {
        return hasWaterRequirement();
    }
    else if (toUInt(building) < eBuilding_array_MAX)
    {
        return (BUILDINGSTATUS_Built == m_city->m_Building_Status.a[building])
                || (BUILDINGSTATUS_Replaced == m_city->m_Building_Status.a[building]);
    }
    else
    {
        return false;
    }
}

}
