#ifndef QOVERLANDMAPSCENE_H
#define QOVERLANDMAPSCENE_H

#include <QGraphicsScene>
#include <QList>
class QGraphicsItem;

#include <MoMTemplate.h>

class QOverlandMapScene : public QGraphicsScene
{
    Q_OBJECT
public:
    QOverlandMapScene(MoM::ePlane plane, QObject *parent = 0);

protected:
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

public slots:

signals:
    void signal_tileChanged(const MoM::Location& loc, const QList<QGraphicsItem*>& graphicItems);

private:
    MoM::ePlane m_plane;
};

#endif // QOVERLANDMAPSCENE_H
