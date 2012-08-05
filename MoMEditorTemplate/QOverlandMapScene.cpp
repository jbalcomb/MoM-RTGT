#include <QDebug>
#include <QGraphicsSceneMouseEvent>

#include <QMoMMapTile.h>

#include "QOverlandMapScene.h"

QOverlandMapScene::QOverlandMapScene(MoM::ePlane plane, QObject *parent) :
    QGraphicsScene(parent),
    m_plane(plane)
{
    QRectF rectfTile = MoM::QMoMMapTile().boundingRect();
    setSceneRect(0, 0, MoM::gMAX_MAP_COLS * rectfTile.width(), MoM::gMAX_MAP_ROWS * rectfTile.height());
}

void QOverlandMapScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    qDebug() << QString("QOverlandMapScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event: pos=(%0,%1), scenePos=(%2,%3))")
        .arg(event->pos().x()).arg(event->pos().y()).arg(event->scenePos().x()).arg(event->scenePos().y());
    QGraphicsScene::mouseMoveEvent(event);

    QRectF rectfTile = MoM::QMoMMapTile().boundingRect();
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
    emit signal_tileChanged(loc, curItems);
}
