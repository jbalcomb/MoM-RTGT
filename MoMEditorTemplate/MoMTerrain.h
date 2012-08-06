#ifndef MOMTERRAIN_H
#define MOMTERRAIN_H

#include "MoMTemplate.h"

namespace MoM
{

class MoMTerrain
{
public:
    explicit MoMTerrain(MoMGameBase* game);

    const Location& getLocation() const
    {
        return m_location;
    }
    void setLocation(const Location& loc);

    City* getCity();
    Tower_Node_Lair* getLair();
    std::vector<int> getUnits();

    static eTerrainCategory getTerrainCategory(eTerrainType terrainType);

private:
    MoMGameBase* m_game;
    Location m_location;
};

}

#endif // MOMTERRAIN_H
