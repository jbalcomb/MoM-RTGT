#ifndef QMOMMAPSCENE_H
#define QMOMMAPSCENE_H

#include <QGraphicsScene>
#include <QList>
class QGraphicsItem;

#include <MoMLocation.h>
#include <MoMTemplate.h>

namespace MoM
{

class QMoMMapScene : public QGraphicsScene
{
    Q_OBJECT
public:
    QMoMMapScene(MoM::ePlane plane, bool isBattlefield, QObject *parent = 0);

    void addItemAtLocation(QGraphicsItem* item, const MoM::MoMLocation& location);
    QGraphicsPixmapItem* addPixmapAtLocation(const QPixmap& pixmap, const MoM::MoMLocation& location);
    void convertLocationToScenePos(const MoM::MoMLocation& location, QPointF& scenePos) const;
    void convertScenePosToLocation(const QPointF& scenePos, MoM::MoMLocation& location) const;

protected:
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);

public slots:

signals:
    void signal_tileChanged(const MoM::MoMLocation& loc);
    void signal_tileSelected(const MoM::MoMLocation& loc, const QList<QGraphicsItem*>& graphicItems);

private:
    MoM::ePlane m_plane;
    bool m_isBattlefield;
};

}

#endif // QMOMMAPSCENE_H
