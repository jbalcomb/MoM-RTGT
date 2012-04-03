// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2011-09-30
// ---------------------------------------------------------------------------

#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QPainter>

#include "dialogaddunit.h"
#include "mainwindow.h"
#include "QMoMResources.h"
#include "QMoMUtility.h"

#include "QMoMUnitTile.h"

namespace MoM
{

QMoMUnitTile::QMoMUnitTile() :
	QObject(),
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

void QMoMUnitTile::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu menu;
    QAction *unitViewAction = menu.addAction("View unit");
    QObject::connect(unitViewAction, SIGNAL(triggered()), this, SLOT(slot_actionUnitView()));
    QAction *selectedAction = menu.exec(event->screenPos());
    // ...
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
            // Maintain aspect ratio with the boundingRect()
            QRect src = imageUnit->rect();
            QRectF dst = boundingRect();
            qreal dstHeight = dst.width() * src.height() / src.width();
            if (dstHeight < dst.height())
            {
                dst = QRectF(dst.left(), dst.top() + (dst.height() - dstHeight) / 2, dst.width(), dstHeight);
            }
            else
            {
                qreal dstWidth = dst.height() * src.width() / src.height();
                dst = QRectF(dst.left() + (dst.width() - dstWidth) / 2, dst.top(), dstWidth, dst.height());
            }

            painter->drawImage(dst, *imageUnit);
        }

//        QPixmap pixmapUnit = MoM::QMoMResources::instance().getPixmap(unit->m_Unit_Type, 1);
//        if (pixmapUnit.height() > 2 * rectfTile.height())
//        {
//            double scale = 2 * rectfTile.height() / pixmapUnit.height();
//            pixmapUnit = MoM::QMoMResources::instance().getPixmap(unit->m_Unit_Type, scale);
//        }
    }
}

void QMoMUnitTile::slot_actionUnitView()
{
    QMoMUnitPtr qUnit(new MoMUnit(m_game.data()));
    qUnit->changeUnit(m_unit);

    DialogAddUnit* dialog = new DialogAddUnit(MainWindow::getInstance());
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->slot_unitChanged(qUnit);
    dialog->show();
}

}
