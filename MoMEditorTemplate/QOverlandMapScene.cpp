#include <QDebug>
#include <QGraphicsSceneMouseEvent>

#include <QMoMMapTile.h>

#include "QOverlandMapScene.h"

namespace MoM
{

QOverlandMapScene::QOverlandMapScene(MoM::ePlane plane, bool isBattlefield, QObject *parent) :
    QGraphicsScene(parent),
    m_plane(plane),
    m_isBattlefield(isBattlefield)
{
    QRectF rectfTile = MoM::QMoMMapTile(m_isBattlefield).boundingRect();
    if (m_isBattlefield)
    {
        setSceneRect(0, 0, MoM::gMAX_BATTLE_COLS * rectfTile.width(), MoM::gMAX_BATTLE_ROWS * rectfTile.height());
    }
    else
    {
        setSceneRect(0, 0, MoM::gMAX_MAP_COLS * rectfTile.width(), MoM::gMAX_MAP_ROWS * rectfTile.height());
    }
}

void QOverlandMapScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsScene::mouseMoveEvent(event);

    QRectF rectfTile = MoM::QMoMMapTile(m_isBattlefield).boundingRect();
    MoM::Location loc = { event->scenePos().x() / rectfTile.width(), event->scenePos().y() / rectfTile.height(), m_plane };

    emit signal_tileChanged(loc);
}

void QOverlandMapScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);

    QRectF rectfTile = MoM::QMoMMapTile(m_isBattlefield).boundingRect();
    MoM::Location loc = { event->scenePos().x() / rectfTile.width(), event->scenePos().y() / rectfTile.height(), m_plane };
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
