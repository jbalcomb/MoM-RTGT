#ifndef MOMCITY_H
#define MOMCITY_H

#include "MoMTemplate.h"

namespace MoM {

class MoMGameBase;
struct MoMLocation;

class MoMCity
{
public:
    MoMCity(MoMGameBase* game, const City* city);

    int  calcBasicFood() const;
    int  calcProductionBonusPercentage() const;
    int  calcFoodProduced() const;
    int  calcHammersProduced() const;
    int  calcCurrentMaxPop() const;
    int  calcTopMaxPop() const;
    int  calcNrRebels() const;
    int  calcNrWorkers() const;
    bool canProduce(eBuilding building) const;
    bool canProduce(eProducing produce) const;
    bool canProduce(eUnit_Type unitTypeNr) const;
    const City* getCity() const;
    int  getCostToBuy(eProducing producing = PRODUCING_None) const;
    int  getCostToProduce(eProducing producing = PRODUCING_None) const;
    int  getTimeToComplete(eProducing producing = PRODUCING_None) const;
    int  getUnitReductionPercentage() const;
    int  getWildGameBonus() const;
    bool hasForestRequirement() const;
    bool hasHillRequirement() const;
    bool hasWaterRequirement() const;
    bool isBuildingAllowed(eBuilding building) const;
    bool isBuildingPresent(eBuilding building) const;

private:
    template<typename Functor>
    bool enumerateTerrain(Functor& functor) const;

    MoMGameBase* m_game;
    const City* m_city;
};

}

#endif // MOMCITY_H
