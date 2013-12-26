#ifndef MOMCITY_H
#define MOMCITY_H

#include "MoMTemplate.h"

namespace MoM {

class MoMGameBase;

class MoMCity
{
public:
    MoMCity(MoMGameBase* game, const City* city);

    bool canProduce(eBuilding building) const;
    bool canProduce(eProducing produce) const;
    bool canProduce(eUnit_Type unitTypeNr) const;
    int  getCostToBuy(eProducing producing) const;
    int  getCostToProduce(eProducing producing) const;
    int  getTimeToComplete(eProducing producing) const;
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
