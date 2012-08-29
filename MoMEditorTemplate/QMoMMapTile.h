// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2011-09-30
// ---------------------------------------------------------------------------

/// \file

#ifndef QMOMMAPTILE_H_
#define QMOMMAPTILE_H_

#include <QGraphicsItem>

#include "MoMTemplate.h"

namespace MoM
{

class QMoMMapTile : public QGraphicsItem
{
public:
    QMoMMapTile(bool isBattlefield);
    virtual ~QMoMMapTile();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    MoM::ePlane getPlane() const
    {
        return m_plane;
    }
    void setPlane(MoM::ePlane plane)
    {
        m_plane = plane;
    }

    MoM::eTerrainBonusDeposit* getTerrainBonus() const
    {
        return m_terrainBonus;
    }
    void setTerrainBonus(MoM::eTerrainBonusDeposit* bonusDeposit)
    {
        m_terrainBonus = bonusDeposit;
    }

    MoM::Terrain_Changes* getTerrainChange() const
    {
        return m_terrainChange;
    }
    void setTerrainChange(MoM::Terrain_Changes* terrainChange)
    {
        m_terrainChange = terrainChange;
    }

    uint8_t* getTerrainExplored() const
    {
        return m_terrainExplored;
    }
    void setTerrainExplored(uint8_t* terrainExplored)
    {
        m_terrainExplored = terrainExplored;
    }

    MoM::eTerrainType* getTerrainType() const
    {
        return m_terrainType;
    }
    void setTerrainType(MoM::eTerrainType* terrainType)
    {
        m_terrainType = terrainType;
    }

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *)
    {
        qDebug() << "QMoMMapTile::hoverEnterEvent(event)";
    }

private:
    bool m_isBattlefield;
    MoM::ePlane m_plane;
    MoM::eTerrainBonusDeposit* m_terrainBonus;
    MoM::Terrain_Changes* m_terrainChange;
    uint8_t* m_terrainExplored;
    MoM::eTerrainType* m_terrainType;
};

}

#endif // QMOMMAPTILE_H
