#ifndef MOMTERRAIN_H
#define MOMTERRAIN_H

#include "MoMTemplate.h"

namespace MoM
{

class MoMTerrain
{
public:
    explicit MoMTerrain(MoMGameBase* game);

    const MoMLocation& getLocation() const
    {
        return m_location;
    }
    void setLocation(const MoMLocation& loc);

    /// \brief Returns the unit that is alive if there is one.
    ///        Otherwise the first inactive unit is returned.
    Battle_Unit* getBattleUnit();

    City* getCity();

    Tower_Node_Lair* getLair();

    std::vector<int> getUnits();

    static eTerrainCategory getTerrainCategory(eTerrainType terrainType);

private:
    MoMGameBase* m_game;
    MoMLocation m_location;
};

}

#endif // MOMTERRAIN_H
