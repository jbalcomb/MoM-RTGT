// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#ifndef DIALOGOVERLANDMAP_H
#define DIALOGOVERLANDMAP_H

#include <QDialog>
#include <QList>
#include <QMap>

#include <MoMTemplate.h>
#include <QMoMSharedPointers.h>

class QGraphicsItem;
class QGraphicsScene;

namespace Ui {
    class DialogOverlandMap;
}

namespace MoM
{

class DialogOverlandMap : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOverlandMap(QWidget *parent = 0);
    ~DialogOverlandMap();

private:
    typedef QMap<const void*, QGraphicsItem*> LookupMap;

    QGraphicsItem* lookup(const void* momPtr)
    {
        LookupMap::iterator it = m_lookup.find(momPtr);
        if (m_lookup.end() == it)
            return 0;
        else
            return it.value();
    }

    void addCitySubtree(class QTreeWidget* treeWidget, class MoMTerrain& momTerrain);
    void addLairSubtree(class QTreeWidget* treeWidget, class MoMTerrain& momTerrain);
    void addTerrainSubtree(class QTreeWidget* treeWidget, class MoMTerrain& momTerrain);
    void addUnitSubtree(class QTreeWidgetItem* treeWidgetItem, Unit* unit);

private:
    QMoMGamePtr m_game;

    class QOverlandMapScene* m_sceneArcanus;
    class QOverlandMapScene* m_sceneMyrror;
    LookupMap m_lookup;
    QMoMTimerPtr m_timer;

    Ui::DialogOverlandMap *ui;

private slots:
    void on_comboBox_Plane_currentIndexChanged(int index);
    void on_treeWidget_Tile_customContextMenuRequested(const QPoint &pos);
    void on_verticalSlider_Zoom_valueChanged(int value);
    void slot_addressCalculator();
    void slot_gameChanged(const QMoMGamePtr& game);
    void slot_gameUpdated();
    void slot_itemAction();
    void slot_tileChanged(const MoM::Location& loc);
    void slot_tileSelected(const MoM::Location& loc, const QList<QGraphicsItem*>& graphicItems);
    void slot_timerActiveUnit();
};

}

#endif // DIALOGOVERLANDMAP_H
