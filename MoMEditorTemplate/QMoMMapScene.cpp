#include <QDebug>
#include <QGraphicsSceneMouseEvent>

#include <QMoMMapTile.h>

#include "QMoMMapScene.h"

namespace MoM
{

QMoMMapScene::QMoMMapScene(MoM::ePlane plane, bool isBattlefield, QObject *parent) :
    QGraphicsScene(parent),
    m_plane(plane),
    m_isBattlefield(isBattlefield)
{
    QRectF rectfTile = MoM::QMoMMapTile(MoMLocation()).boundingRect();
    if (m_isBattlefield)
    {
        setSceneRect(0, 0, 11 * 32, 22 * 8);
    }
    else
    {
        setSceneRect(0, 0, MoM::gMAX_MAP_COLS * rectfTile.width(), MoM::gMAX_MAP_ROWS * rectfTile.height());
    }
}

void QMoMMapScene::addItemAtLocation(QGraphicsItem* item, const MoMLocation& location)
{
    QPointF scenePos;
    convertLocationToScenePos(location, scenePos);
    item->setPos(scenePos);
    addItem(item);
}

QGraphicsPixmapItem* QMoMMapScene::addPixmapAtLocation(const QPixmap& pixmap, const MoM::MoMLocation& location)
{
    QGraphicsPixmapItem* item = addPixmap(pixmap);
    QPointF scenePos;
    convertLocationToScenePos(location, scenePos);
    item->setPos(scenePos);
    return item;
}

// (row,col) in (0..21,0..10)
// xpos = row / 2 + col
// ypos = (row + 1) / 2 + 9 - col
// xpel = 32 * col - 16 * (row % 2)
// ypel = 8 * row - 8
// index = ypos * 21 + xpos

// row = xpos + ypos - 9
// col = (xpos - ypos + 9) / 2
// xpel = (xpos - ypos + 9) * 16
// ypel = (xpos + ypos - 9) * 8
// xpos = xpel / 32 + ypel / 16
// ypos = 9 - xpel / 32 + ypel / 16

void QMoMMapScene::convertLocationToScenePos(const MoMLocation& location, QPointF& scenePos) const
{
    int x = location.m_XPos;
    int y = location.m_YPos;

    if (m_isBattlefield)
    {
        double xpel = (x - y + 9) / 2.0 * 32;
        double ypel = (x + y - 10) * 8;

        scenePos = QPointF(xpel, ypel);
    }
    else
    {
        QRectF rectfTile = MoM::QMoMMapTile(MoMLocation()).boundingRect();
        scenePos = QPointF(x * rectfTile.width(), y * rectfTile.height());
    }
}

void QMoMMapScene::convertScenePosToLocation(const QPointF& scenePos, MoMLocation& location) const
{
    if (m_isBattlefield)
    {
        // xpos = xpel / 32 + ypel / 16
        // ypos = 9 - xpel / 32 + ypel / 16
        double xpel = scenePos.x();
        double ypel = scenePos.y();
        int8_t xpos = (int8_t)(xpel / 32 + ypel / 16);
        int8_t ypos = (int8_t)(9 - xpel / 32 + ypel / 16);
        location = MoM::MoMLocation(xpos, ypos, m_plane, MoMLocation::MAP_battle);
    }
    else
    {
        QRectF rectfTile = MoM::QMoMMapTile(MoMLocation()).boundingRect();
        location = MoM::MoMLocation(scenePos.x() / rectfTile.width(), scenePos.y() / rectfTile.height(), m_plane, MoMLocation::MAP_overland);
    }
}

void QMoMMapScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsScene::mouseMoveEvent(event);

    MoM::MoMLocation loc;
    convertScenePosToLocation(event->scenePos(), loc);

    emit signal_tileChanged(loc);
}

void QMoMMapScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);

    MoM::MoMLocation loc;
    convertScenePosToLocation(event->scenePos(), loc);

    QList<QGraphicsItem*> sceneItems = items(Qt::AscendingOrder);
    QList<QGraphicsItem*> curItems;
    for (int i = 0; i < sceneItems.count(); ++i)
    {
        if (sceneItems.at(i)->boundingRect().contains(sceneItems.at(i)->mapFromScene(event->scenePos())))
        {
            curItems.push_back(sceneItems.at(i));
        }
    }
    emit signal_tileSelected(loc, curItems);
}

}
