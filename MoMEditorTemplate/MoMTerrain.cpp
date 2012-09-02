#include "MoMController.h"

#include "MoMTerrain.h"

namespace MoM
{

eTerrainCategory MoMTerrain::getTerrainCategory(eTerrainType terrainType)
{
    eTerrainCategory value = (eTerrainCategory)-1;
    switch (terrainType)
    {
    case ocean1:
    case ocean2:
    case ocean3:        value = TERRAINCATEGORY_Ocean; break;

    case grasslands0:
    case grasslands1:
    case grasslands2:
    case grasslands3:
    case grasslands4:   value = TERRAINCATEGORY_Grasslands; break;

    case forest1:
    case forest2:
    case forest3:       value = TERRAINCATEGORY_Forest; break;

    case mountain1:     value = TERRAINCATEGORY_Mountain; break;

    case desert1:
    case desert2:
    case desert3:
    case desert4:       value = TERRAINCATEGORY_Desert; break;

    case swamp1:
    case swamp2:
    case swamp3:        value = TERRAINCATEGORY_Swamp; break;

    case tundra1:
    case tundra2:
    case tundra3:       value = TERRAINCATEGORY_Tundra; break;

    case hills1:        value = TERRAINCATEGORY_Hills; break;

    case volcano:       value = TERRAINCATEGORY_Volcano; break;

    case grasslands_w_sorcery_node: value = TERRAINCATEGORY_Grasslands; break;

    case forest_w_nature_node: value = TERRAINCATEGORY_Forest; break;

    case volcano_w_chaos_node: value = TERRAINCATEGORY_Volcano; break;
    }

    if (value != (eTerrainCategory)-1)
    {
        // Done
    }
    else if ((terrainType >= shore1_first) && (terrainType <= shore1_last))
    {
        value = TERRAINCATEGORY_Shore;
    }
    else if ((terrainType >= river1_first) && (terrainType <= river1_last))
    {
        value = TERRAINCATEGORY_River;
    }
    else if ((terrainType >= shore2_first) && (terrainType <= shore2_last))
    {
        value = TERRAINCATEGORY_Shore;
    }
    else if ((terrainType >= shore3_first) && (terrainType <= shore3_last))
    {
        value = TERRAINCATEGORY_Shore;
    }
    else if ((terrainType >= river2_first) && (terrainType <= river2_last))
    {
        value = TERRAINCATEGORY_River;
    }
    else if ((terrainType >= mountain2_first) && (terrainType <= mountain2_last))
    {
        value = TERRAINCATEGORY_Mountain;
    }
    else if ((terrainType >= hills2_first) && (terrainType <= hills2_last))
    {
        value = TERRAINCATEGORY_Hills;
    }
    else if ((terrainType >= desert5_first) && (terrainType <= desert5_last))
    {
        value = TERRAINCATEGORY_Desert;
    }
    else if ((terrainType >= shore4_first) && (terrainType <= shore4_last))
    {
        value = TERRAINCATEGORY_Shore;
    }
    else if ((terrainType >= tundra4_first) && (terrainType <= tundra4_last))
    {
        value = TERRAINCATEGORY_Tundra;
    }
    else
    {
        // Not found
    }

    return value;
}

MoMTerrain::MoMTerrain(MoMGameBase* game) :
    m_game(game),
    m_location()
{
}

void MoMTerrain::setLocation(const MoMLocation &loc)
{
    m_location = loc;
}

City *MoMTerrain::getCity()
{
    City* value = 0;
    for (int cityNr = 0; cityNr < m_game->getNrCities(); ++cityNr)
    {
        City* city = m_game->getCity(cityNr);
        if (0 == city)
            break;
        if ((city->m_Plane == m_location.m_Plane)
                && (city->m_XPos == m_location.m_XPos)
                && (city->m_YPos == m_location.m_YPos))
        {
            value = city;
            break;
        }
    }
    return value;
}

Tower_Node_Lair *MoMTerrain::getLair()
{
    Tower_Node_Lair* value = 0;
    for (int lairNr = 0; lairNr < gMAX_NODES_LAIRS_TOWERS; ++lairNr)
    {
        Tower_Node_Lair* lair = m_game->getLair(lairNr);
        if (0 == lair)
            break;
        if ((lair->m_Plane == m_location.m_Plane)
                && (lair->m_XPos == m_location.m_XPos)
                && (lair->m_YPos == m_location.m_YPos))
        {
            value = lair;
            break;
        }
    }
    return value;
}

std::vector<int> MoMTerrain::getUnits()
{
    std::vector<int> units;
    if (0 != m_game)
    {
        (void)MoMController::findUnitsAtLocation(*m_game, m_location, units);
    }
    return units;
}

}
