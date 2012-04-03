// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2011-09-30
// ---------------------------------------------------------------------------

#include <qpainter.h>

#include "QMoMResources.h"
#include "QMoMUtility.h"

#include "QMoMUnitTile.h"

namespace MoM
{

QMoMUnitTile::QMoMUnitTile() :
    QGraphicsItem(),
    m_unit(0)
{
}

QMoMUnitTile::~QMoMUnitTile()
{
}

QRectF QMoMUnitTile::boundingRect() const
{
    return QRectF(0, 0, 20, 18);
}

void QMoMUnitTile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    if (0 != m_unit)
    {
        const QMoMImagePtr imageUnit = QMoMResources::instance().getImage(m_unit->m_Unit_Type);
        QMoMImagePtr imageBack;
        MoM::Wizard* wizard = 0;
        if (0 != m_game)
        {
            wizard = m_game->getWizard(m_unit->m_Owner);
        }
        if (0 != wizard)
        {
            imageBack = MoM::QMoMResources::instance().getImage(wizard->m_BannerColor);
        }
        if (0 != imageBack)
		{
            painter->drawImage(boundingRect(), *imageBack);
		}
        if (0 != imageUnit)
        {
            painter->drawImage(boundingRect(), *imageUnit);
        }

//        QPixmap pixmapUnit = MoM::QMoMResources::instance().getPixmap(unit->m_Unit_Type, 1);
//        if (pixmapUnit.height() > 2 * rectfTile.height())
//        {
//            double scale = 2 * rectfTile.height() / pixmapUnit.height();
//            pixmapUnit = MoM::QMoMResources::instance().getPixmap(unit->m_Unit_Type, scale);
//        }
    }
}

}
