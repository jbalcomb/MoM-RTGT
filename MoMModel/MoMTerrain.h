#ifndef MOMTERRAIN_H
#define MOMTERRAIN_H

#include "MoMTemplate.h"

namespace MoM
{

class MoMTerrain
{
public:
    explicit MoMTerrain(MoMGameBase* game, const MoMLocation& loc);

    const MoMLocation& getLocation() const
    {
        return m_location;
    }
    void                    setLocation(const MoMLocation& loc);

    /// \brief Returns the unit that is alive if there is one.
    ///        Otherwise the first inactive unit is returned.
    Battle_Unit*            getBattleUnit() const;
    eTerrainBonusDeposit    getBonus() const;
    eTerrainCategory        getCategory() const;
    Terrain_Changes         getChanges() const;
    City*                   getCity() const;
    uint8_t                 getExplored() const;
    Tower_Node_Lair*        getLair() const;
    eTerrainType            getType() const;
    std::vector<int>        getUnits() const;

    static eTerrainCategory getTerrainCategory(eTerrainType terrainType);

private:
    MoMGameBase* m_game;
    MoMLocation m_location;
};

}

#endif // MOMTERRAIN_H
