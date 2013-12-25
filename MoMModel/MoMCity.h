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
    int  getCostToProduce(eProducing producing) const;
    int  getTimeToComplete(eProducing producing) const;
    bool isBuildingPresent(eBuilding building) const;

private:
    MoMGameBase* m_game;
    const City* m_city;
};

}

#endif // MOMCITY_H
