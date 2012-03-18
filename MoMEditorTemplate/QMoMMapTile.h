// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2011-09-30
// ---------------------------------------------------------------------------

/// \file

#ifndef QMOMMAPTILE_H_
#define QMOMMAPTILE_H_

#include <qgraphicsitem.h>

#include "MoMTemplate.h"

namespace MoM
{

class QMoMMapTile: public QGraphicsItem
{
public:
    QMoMMapTile();
    virtual ~QMoMMapTile();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    void setPlane(MoM::ePlane plane)
    {
        m_plane = plane;
    }
    void setTerrainType(MoM::eTerrainType* terrainType)
    {
        m_terrainType = terrainType;
    }

private:
    MoM::ePlane m_plane;
    MoM::eTerrainType* m_terrainType;
};

}

#endif // QMOMMAPTILE_H
