// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2011-09-30
// ---------------------------------------------------------------------------

#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QPainter>

#include <math.h>

#include "dialogaddunit.h"
#include "mainwindow.h"
#include "QMoMResources.h"
#include "QMoMUtility.h"

#include "QMoMUnitTile.h"

namespace MoM
{

QMoMUnitTile::QMoMUnitTile(bool isBattlefield) :
	QObject(),
    QGraphicsItem(),
    m_momUnit(),
    m_isBattlefield(isBattlefield)
{
}

QMoMUnitTile::~QMoMUnitTile()
{
}

QRectF QMoMUnitTile::boundingRect() const
{
    if (m_isBattlefield)
    {
        return QRectF(0, 0, 28, 30);
    }
    else
    {
        return QRectF(0, 0, 20, 18);
    }
}

void QMoMUnitTile::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu menu;
    QAction *unitViewAction = menu.addAction("View unit");
    QObject::connect(unitViewAction, SIGNAL(triggered()), this, SLOT(slot_actionUnitView()));
    (void)menu.exec(event->screenPos());
}

void QMoMUnitTile::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    if (0 != m_momUnit)
    {
        // Calculate heading
        int heading = -1;
        if (m_isBattlefield)
        {
            int dx = m_momUnit->getBattleUnit().m_xPosHeaded - m_momUnit->getBattleUnit().m_xPos;
            int dy = m_momUnit->getBattleUnit().m_yPosHeaded - m_momUnit->getBattleUnit().m_yPos;
            if ((0 != dx) || (0 != dy))
            {
                double angle = atan2((double)dy, (double)dx);
                heading = (int)(angle * 4 / 3.14159 + 3.5 + 10) - 10;
                if (heading < 0)
                {
                    heading += 8;
                }
            }
        }

        MoM::Wizard* wizard = 0;
        if (0 != m_game)
        {
            wizard = m_game->getWizard(m_momUnit->getOwner());
        }

        // Get unit image
        eBannerColor banner = BANNER_Green;
        if (0 != wizard)
        {
            banner = wizard->m_BannerColor;
        }
        const QMoMImagePtr imageUnit = QMoMResources::instance().getImage(m_momUnit->getUnitTypeNr(), heading, banner);
        QMoMImagePtr imageBack;
        if (!m_isBattlefield && (0 != wizard))
        {
            imageBack = MoM::QMoMResources::instance().getImage(wizard->m_BannerColor);
        }

        // Paint unit image
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
    DialogAddUnit* dialog = new MoM::DialogAddUnit(MainWindow::getInstance());
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->slot_unitChanged(m_momUnit);
    dialog->show();
}

}
