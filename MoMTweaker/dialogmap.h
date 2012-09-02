// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#ifndef DIALOGMAP_H
#define DIALOGMAP_H

#include <QDialog>
#include <QList>
#include <QMap>

#include <MoMLocation.h>
#include <MoMTemplate.h>
#include <QMoMSharedPointers.h>

class QGraphicsItem;
class QGraphicsScene;

namespace Ui {
    class DialogOverlandMap;
}

namespace MoM
{

class DialogMap : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMap(QWidget *parent = 0);
    ~DialogMap();

private:
    void addBattleUnitSubtree(class QTreeWidget* treeWidget, Battle_Unit* battleUnit);
    void addCitySubtree(class QTreeWidget* treeWidget, class MoMTerrain& momTerrain);
    void addLairSubtree(class QTreeWidget* treeWidget, class MoMTerrain& momTerrain);
    void addTerrainSubtree(class QTreeWidget* treeWidget, class MoMTerrain& momTerrain);
    void addUnitSubtree(class QTreeWidgetItem* treeWidgetItem, Unit* unit);

private:
    QMoMGamePtr m_game;

    class QMoMMapScene* m_sceneArcanus;
    class QMoMMapScene* m_sceneMyrror;
    class QMoMMapScene* m_sceneBattle;
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
    void slot_tileChanged(const MoM::MoMLocation& loc);
    void slot_tileSelected(const MoM::MoMLocation& loc, const QList<QGraphicsItem*>& graphicItems);
    void slot_timerActiveUnit();
};

}

#endif // DIALOGMAP_H