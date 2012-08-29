#ifndef QOVERLANDMAPSCENE_H
#define QOVERLANDMAPSCENE_H

#include <QGraphicsScene>
#include <QList>
class QGraphicsItem;

#include <MoMTemplate.h>

namespace MoM
{

class QOverlandMapScene : public QGraphicsScene
{
    Q_OBJECT
public:
    QOverlandMapScene(MoM::ePlane plane, bool isBattlefield, QObject *parent = 0);

protected:
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);

public slots:

signals:
    void signal_tileChanged(const MoM::Location& loc);
    void signal_tileSelected(const MoM::Location& loc, const QList<QGraphicsItem*>& graphicItems);

private:
    MoM::ePlane m_plane;
    bool m_isBattlefield;
};

}

#endif // QOVERLANDMAPSCENE_H
