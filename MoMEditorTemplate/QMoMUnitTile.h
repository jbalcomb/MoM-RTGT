// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2011-09-30
// ---------------------------------------------------------------------------

/// \file

#ifndef QMOMUNITTILE_H_
#define QMOMUNITTILE_H_

#include <QGraphicsItem>

#include "MoMTemplate.h"
#include "QMoMSharedPointers.h"

namespace MoM
{

class QMoMUnitTile: public QGraphicsItem
{
public:
    QMoMUnitTile();
    virtual ~QMoMUnitTile();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    void setGame(const QMoMGamePtr& game)
    {
        m_game = game;
    }
    void setUnit(MoM::Unit* unit)
    {
        m_unit = unit;
    }

private:
    QMoMGamePtr m_game;
    MoM::Unit* m_unit;
};

}

#endif // QMOMUNITTILE_H
