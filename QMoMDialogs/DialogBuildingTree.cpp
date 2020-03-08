// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2012-03-12
// ---------------------------------------------------------------------------

#include "DialogBuildingTree.h"
#include "ui_DialogBuildingTree.h"

#include <QGraphicsScene>
#include <QMenu>
#include <QTimer>
#include <QTreeWidget>
#include <QTreeWidgetItem>

#include <cmath>
#include <fstream>
#include <vector>

#include "DialogCalculatorAddress.h"
#include "MainWindow.h"
#include "MoMCombat.h"
#include "MoMController.h"
#include "MoMGenerated.h"
#include "MoMExeWizards.h"
#include "MoMTemplate.h"
#include "MoMTerrain.h"
#include "MoMUtility.h"
#include "QMoMAnimationTile.h"
#include "QMoMMapScene.h"
#include "QMoMMapTile.h"
#include "QMoMResources.h"
#include "QMoMSettings.h"
#include "QMoMTreeItemWidget.h"
#include "QMoMUnitTile.h"

namespace MoM
{

namespace
{

class QMoMBuildingTile : public QGraphicsItem
{
    const int lineHeight = 16;
public:
    QMoMBuildingTile(eBuilding buildingEnum, const QMoMGamePtr& game)
        : QGraphicsItem(),
          m_buildingEnum(buildingEnum),
          m_game(game)
    {
    }

    QRectF boundingRect() const override
    {
        int height = 1;
        height += MoM::QMoMResources::instance().getPixmap(m_buildingEnum, 1).height() + 2; // pixmap
        //height += lineHeight; // Title
        height += m_prerequisites.count() * lineHeight;
        height += m_unitsPossible.count() * (MoM::QMoMResources::instance().getPixmap(
                                                 UNITTYPE_High_Men_Spearmen, 1).height() + 2);
        height += 4;
        return QRectF(0, 0, 120, height);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override
    {
        painter->fillRect(boundingRect(), Qt::white);
        painter->drawRect(boundingRect());

        auto buildingData = m_game->getBuildingData(m_buildingEnum);
        if (buildingData == nullptr)
            return;

        int xLeft = 4;
        int y = 1;
        int dy = lineHeight;

        QPixmap pixmapBuilding = MoM::QMoMResources::instance().getPixmap(m_buildingEnum, 1);
        painter->drawPixmap(xLeft, y, pixmapBuilding);
        painter->drawText(xLeft + pixmapBuilding.width() + 4, y + pixmapBuilding.height() / 2,
                          buildingData->m_BuildingName);
        y += pixmapBuilding.height() + 2;
        for (auto preqTile : m_prerequisites)
        {
            painter->drawText(xLeft , y + dy / 2, QString("Preq: %0").arg(
                                  m_game->getBuildingData(preqTile->buildingEnum())->m_BuildingName));
            y += dy;
        }
        for (auto unit : m_unitsPossible)
        {
            QPixmap pixmapUnit = MoM::QMoMResources::instance().getPixmap(unit.getUnitTypeNr(), 1);
            painter->drawPixmap(xLeft, y, pixmapUnit);
            painter->drawText(xLeft + pixmapUnit.width() + 4, y + pixmapUnit.height() / 2,
                              QString("%0 %1").arg(unit.getRaceName().c_str(),
                                                   unit.getUnitName().c_str()));
            y += pixmapUnit.height() + 2;
        }
    }

    eBuilding buildingEnum() const { return m_buildingEnum; }

    void addPrerequisite(QMoMBuildingTile* preqTile) { m_prerequisites.push_back(preqTile); }
    QVector<QMoMBuildingTile*> getPrerequisites() { return m_prerequisites; }

    void addUnit(const MoMUnit& momUnit) { return m_unitsPossible.push_back(momUnit); }
    QVector<MoMUnit> getUnits() const { return m_unitsPossible; }

    void setCol(int value) { m_col = value; }
    int getCol() const { return m_col; }

private:
    eBuilding m_buildingEnum;
    QMoMGamePtr m_game;
    QVector<QMoMBuildingTile*> m_prerequisites;
    QVector<MoMUnit> m_unitsPossible;
    int m_col = -1;
};

int recurseDependency(QMoMBuildingTile& tile)
{
    if ((tile.buildingEnum() == BUILDING_Trade_Goods) || (tile.buildingEnum() == BUILDING_Housing))
    {
        tile.setCol(0);
    }
    if (tile.getCol() != -1)
        return tile.getCol();

    int maxPreqCol = 0;
    for (auto preqTile : tile.getPrerequisites())
    {
        int col = recurseDependency(*preqTile);
        maxPreqCol = Max(maxPreqCol, col);
    }
    tile.setCol(maxPreqCol + 1);
    return tile.getCol();
}

}

class QMoMBuildingScene : public QGraphicsScene
{
public:
    QMoMBuildingScene() : QGraphicsScene() {}

    void addDependency(QMoMBuildingTile* tile, QMoMBuildingTile* preq)
    {
        auto line = addLine(QLineF(preq->x() + preq->boundingRect().right(),
                                   preq->y() + preq->boundingRect().height() / 2,
                                   tile->x(),
                                   tile->y() + tile->boundingRect().height() / 2));
        line->setZValue(0);
    }
};

DialogBuildingTree::DialogBuildingTree(QWidget *parent) :
    QMoMDialogBase(parent),
    m_scene(std::make_unique<QMoMBuildingScene>()),
    m_timer(new QTimer),
    ui(std::make_unique<Ui::DialogBuildTree>())
{
    ui->setupUi(this);

    postInitialize();

    setWindowFlags(Qt::Window);

    // Update view when checkbox is clicked
    QObject::connect(ui->checkBox_Cities, SIGNAL(clicked()), this, SLOT(slot_gameUpdated()));
    QObject::connect(ui->checkBox_EnemyUnits, SIGNAL(clicked()), this, SLOT(slot_gameUpdated()));
    QObject::connect(ui->checkBox_ExploredOnly, SIGNAL(clicked()), this, SLOT(slot_gameUpdated()));
    QObject::connect(ui->checkBox_Lairs, SIGNAL(clicked()), this, SLOT(slot_gameUpdated()));
    QObject::connect(ui->checkBox_Terrain, SIGNAL(clicked()), this, SLOT(slot_gameUpdated()));
    QObject::connect(ui->checkBox_TerrainBonuses, SIGNAL(clicked()), this, SLOT(slot_gameUpdated()));
    QObject::connect(ui->checkBox_TerrainChanges, SIGNAL(clicked()), this, SLOT(slot_gameUpdated()));
    QObject::connect(ui->checkBox_YourUnits, SIGNAL(clicked()), this, SLOT(slot_gameUpdated()));

    // Update view when items are inspected
//    QObject::connect(m_scene, SIGNAL(signal_tileChanged(MoM::MoMLocation)), this, SLOT(slot_tileChanged(MoM::MoMLocation)));
//    QObject::connect(m_scene, SIGNAL(signal_tileSelected(MoM::MoMLocation)), this, SLOT(slot_tileSelected(MoM::MoMLocation)));
//    QObject::connect(m_scene, SIGNAL(signal_tileDragged(MoM::MoMLocation,MoM::MoMLocation)), this, SLOT(slot_tileDragged(MoM::MoMLocation,MoM::MoMLocation)));

    // Connect timers
    QObject::connect(m_timer.data(), SIGNAL(timeout()), this, SLOT(slot_timerAnimations()));

    // Start timer
    m_timer->start(250);

    ui->graphicsView->setScene(m_scene.get());
}

DialogBuildingTree::~DialogBuildingTree()
{
    preFinalize();
}

void DialogBuildingTree::addBattleUnitSubtree(QTreeWidget* treeWidget, Battle_Unit* battleUnit)
{
//    assert(0 != battleUnit);
//    int battleUnitNr = (int)(battleUnit - m_game->getBattleUnit(0));
//    Unit* unit = m_game->getUnit(battleUnit->m_unitNr);
//    if (0 == unit)
//        return;
//    QString text = QString("%0").arg(prettyQStr(unit->m_Unit_Type));
//    if (battleUnit->m_Weapon_Type_Plus_1 > 1)
//    {
//        text += ", " + prettyQStr((eWeaponType)(battleUnit->m_Weapon_Type_Plus_1 - 1));
//    }
//    QMoMTreeItemWidgetBase* qtreeUnit = new QMoMTreeItemWidgetBase(m_game,
//                                 QString("battle[%0] unit[%1]").arg(battleUnitNr).arg(battleUnit->m_unitNr),
//                                 text);
//    treeWidget->addTopLevelItem(qtreeUnit);

//    qtreeUnit->addChild(new EnumTreeItem<eUnit_Type>(m_game, "Unit Type", &unit->m_Unit_Type, eUnit_Type_MAX));
//    qtreeUnit->addChild(new EnumTreeItem<ePlayer>(m_game, "Owner", &battleUnit->m_Owner, ePlayer_MAX));
//    qtreeUnit->addChild(new EnumTreeItem<eBattleUnitActive>(m_game, "Active", &battleUnit->m_Active, eBattleUnitActive_MAX));
//    qtreeUnit->addChild(new NumberTreeItem<uint8_t>(m_game, "WeaponType", &battleUnit->m_Weapon_Type_Plus_1));
}

void DialogBuildingTree::on_comboBox_Plane_currentIndexChanged(int index)
{
//    switch (index)
//    {
//    case 1:
//        ui->graphicsView->setScene(m_scene.get());
//        break;
//    default:
//        ui->graphicsView->setScene(0);
//        break;
//    }
}

void DialogBuildingTree::on_treeWidget_Tile_customContextMenuRequested(const QPoint &pos)
{
    //qDebug() << "on_treeWidget_Tile_customContextMenuRequested" << pos;
    QTreeWidgetItem* pItem = ui->treeWidget_Tile->currentItem();

    QMenu contextMenu;
    QAction* action = contextMenu.addAction("Address calculator");
    action->connect(action, SIGNAL(triggered()), this, SLOT(slot_addressCalculator()));

    QMoMTreeItemWidgetBase* pMoMItem = dynamic_cast<QMoMTreeItemWidgetBase*>(pItem);
    if (0 != pMoMItem)
    {
        QList<QAction*> actions = pMoMItem->requestActions(&contextMenu);
        if (!actions.isEmpty())
        {
            contextMenu.addSeparator();
        }
        contextMenu.addActions(actions);
        foreach(QAction* action, actions)
        {
            connect(action, SIGNAL(triggered()), this, SLOT(slot_itemAction()));
        }
    }

    contextMenu.exec(ui->treeWidget_Tile->mapToGlobal(pos));
}

void DialogBuildingTree::on_verticalSlider_Zoom_valueChanged(int value)
{
    double scale = 1.0 + value / 100.0;
    if (value < 0)
    {
        scale = std::pow(2.0, value / 100.0);
    }

    ui->graphicsView->resetTransform();
    ui->graphicsView->scale(scale, scale);
}

void DialogBuildingTree::slot_addressCalculator()
{
    DialogCalculatorAddress* dialog = new DialogCalculatorAddress(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
//    QObject::connect(this, SIGNAL(signal_addressChanged(const void*)), dialog, SLOT(slot_addressChanged(const void*)));
    dialog->show();

    QTreeWidgetItem* pItem = ui->treeWidget_Tile->currentItem();
    QMoMTreeItemWidgetBase* pMoMItem = dynamic_cast<QMoMTreeItemWidgetBase*>(pItem);
    if (0 != pMoMItem)
    {
        dialog->slot_addressChanged(pMoMItem->getMoMPointer());
    }
}

void DialogBuildingTree::slot_gameChanged(const QMoMGamePtr& game)
{
    m_game = game;

    slot_gameUpdated();
}

void DialogBuildingTree::slot_gameUpdated()
{
    // Reset game
    m_scene->clear();

    if (m_game.isNull())
        return;
    if (m_game->getBuildingData(BUILDING_None) == nullptr)
        return;

    // Create tile for each building
    QMap<eBuilding, QMoMBuildingTile*> buildingTiles;
    for (int buildingNr = 1; buildingNr < eBuilding_array_MAX; ++buildingNr)
    {
        auto buildingEnum = static_cast<eBuilding>(buildingNr);
        if (m_game->getBuildingData(buildingEnum) == nullptr)
            break;
        auto tile = new QMoMBuildingTile(buildingEnum, m_game);
        m_scene->addItem(tile);
        buildingTiles[buildingEnum] = tile;
    }

    // List units at the buildings they require
    for (int unitTypeNr = 0; unitTypeNr < eUnit_Type_MAX; ++unitTypeNr)
    {
        MoMUnit momUnit(m_game.get(), static_cast<eUnit_Type>(unitTypeNr));
        auto listBuildings = momUnit.getRequiredBuildings();
        for (auto buildingEnum : listBuildings)
        {
            auto it = buildingTiles.find(buildingEnum);
            if (it != buildingTiles.end())
            {
                it.value()->addUnit(momUnit);
            }
        }
    }

    // Register prerequisite tiles for every building tile
    for(auto buildingTile : buildingTiles)
    {
       auto buildingData = m_game->getBuildingData(buildingTile->buildingEnum());
       auto itPreq = buildingTiles.find(buildingData->m_Prerequisite1);
       if (itPreq != buildingTiles.end())
       {
           buildingTile->addPrerequisite(itPreq.value());
       }
       itPreq = buildingTiles.find(buildingData->m_Prerequisite2);
       if (itPreq != buildingTiles.end())
       {
           buildingTile->addPrerequisite(itPreq.value());
       }
    }

    // Find column position for each building tile
    for (auto buildingTile : buildingTiles)
    {
        recurseDependency(*buildingTile);
    }

    // Position each building tile
    QVector<int> firstFreeRow(buildingTiles.count());
    for (auto buildingTile : buildingTiles)
    {
        auto col = buildingTile->getCol();
        auto row = firstFreeRow[col];
        firstFreeRow[col] += buildingTile->boundingRect().height() + 20;
        buildingTile->setPos(buildingTile->getCol() * (buildingTile->boundingRect().width() + 40), row);
        buildingTile->setZValue(1);
    }

    // Add connectors for prequisite tiles to the scene
    for (auto buildingTile : buildingTiles)
    {
        for (auto preqTile : buildingTile->getPrerequisites())
        {
            m_scene->addDependency(buildingTile, preqTile);
        }
    }
}

void DialogBuildingTree::slot_itemAction()
{
    QTreeWidgetItem* pItem = ui->treeWidget_Tile->currentItem();
    QMoMTreeItemWidgetBase* pMoMItem = dynamic_cast<QMoMTreeItemWidgetBase*>(pItem);
    if (0 != pMoMItem)
    {
        pMoMItem->slotAction();
    }
}

void DialogBuildingTree::slot_tileChanged(const MoM::MoMLocation& loc)
{
}

void DialogBuildingTree::slot_tileDragged(const MoMLocation &locFrom, const MoMLocation &locTo)
{
}

void DialogBuildingTree::slot_tileSelected(const MoM::MoMLocation &loc)
{
}

void DialogBuildingTree::slot_timerAnimations()
{
}

void MoM::DialogBuildingTree::on_pushButton_SaveBookmark_clicked()
{
}

void MoM::DialogBuildingTree::on_pushButton_RestoreBookmark_clicked()
{
}

}
