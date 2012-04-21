// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2012-03-12
// ---------------------------------------------------------------------------

#include <QGraphicsScene>
#include <QTimer>
#include <QTreeWidgetItem>

#include <cmath>

#include "dialogoverlandmap.h"
#include "ui_dialogoverlandmap.h"

#include "mainwindow.h"
#include "MoMUtility.h"
#include "MoMGenerated.h"
#include "MoMExeWizards.h"
#include "MoMTemplate.h"
#include "QMoMMapTile.h"
#include "QMoMResources.h"
#include "QMoMUnitTile.h"

using MoM::QMoMResources;

class QTreeItem : public QTreeWidgetItem
{

};


DialogOverlandMap::DialogOverlandMap(QWidget *parent) :
    QDialog(parent),
    m_sceneArcanus(new QGraphicsScene),
    m_sceneMyrror(new QGraphicsScene),
    m_timer(new QTimer),
    ui(new Ui::DialogOverlandMap)
{
    ui->setupUi(this);

    QRectF rectfTile = MoM::QMoMMapTile().boundingRect();
    m_sceneArcanus->setSceneRect(0, 0, MoM::gMAX_MAP_COLS * rectfTile.width(), MoM::gMAX_MAP_ROWS * rectfTile.height());
    m_sceneMyrror->setSceneRect(0, 0, MoM::gMAX_MAP_COLS * rectfTile.width(), MoM::gMAX_MAP_ROWS * rectfTile.height());
    ui->graphicsView->setSceneRect(m_sceneArcanus->sceneRect());

    ui->comboBox_Plane->setCurrentIndex(1);

    // Update view when game is changed or updated
    QObject::connect(MainWindow::getInstance(), SIGNAL(signal_gameChanged(QMoMGamePtr)), this, SLOT(slot_gameChanged(QMoMGamePtr)));
    QObject::connect(MainWindow::getInstance(), SIGNAL(signal_gameUpdated()), this, SLOT(slot_gameUpdated()));

    // Update view when checkbox is clicked
    QObject::connect(ui->checkBox_BonusDeposits, SIGNAL(clicked()), this, SLOT(slot_gameUpdated()));
    QObject::connect(ui->checkBox_EnemyUnits, SIGNAL(clicked()), this, SLOT(slot_gameUpdated()));
    QObject::connect(ui->checkBox_Lairs, SIGNAL(clicked()), this, SLOT(slot_gameUpdated()));
    QObject::connect(ui->checkBox_Terrain, SIGNAL(clicked()), this, SLOT(slot_gameUpdated()));
    QObject::connect(ui->checkBox_YourUnits, SIGNAL(clicked()), this, SLOT(slot_gameUpdated()));

    // Connect timers
    QObject::connect(m_timer.data(), SIGNAL(timeout()), this, SLOT(slot_timerActiveUnit()));

    slot_gameChanged(MainWindow::getInstance()->getGame());
    m_timer->start(250);

    MoM::Location loc;
    loc.m_Plane = MoM::PLANE_Arcanum;
    loc.m_XPos = 23;
    loc.m_YPos = 31;
    slot_tileChanged(loc);
}

DialogOverlandMap::~DialogOverlandMap()
{
    delete ui;
    delete m_sceneMyrror;
    delete m_sceneArcanus;
}

void DialogOverlandMap::on_comboBox_Plane_currentIndexChanged(int index)
{
    switch (index)
    {
    case 1:
        ui->graphicsView->setScene(m_sceneArcanus);
        break;
    case 2:
        ui->graphicsView->setScene(m_sceneMyrror);
        break;
    default:
        ui->graphicsView->setScene(0);
        break;
    }
}

void DialogOverlandMap::slot_gameChanged(const QMoMGamePtr& game)
{
    m_game = game;

    slot_gameUpdated();
}

void DialogOverlandMap::slot_gameUpdated()
{
    // Reset game
    m_sceneArcanus->clear();
    m_sceneMyrror->clear();
    m_lookup.clear();

    if (m_game.isNull())
        return;

    QGraphicsScene* scene[MoM::ePlane_MAX] = { m_sceneArcanus, m_sceneMyrror };
    QRectF rectfTile = MoM::QMoMMapTile().boundingRect();

    // Add fixed map tiles
    // Show terrain
    if (ui->checkBox_Terrain->isChecked())
    {
        for (MoM::ePlane plane = (MoM::ePlane)0; MoM::toUInt(plane) < MoM::ePlane_MAX; MoM::inc(plane))
        {
            for (int y = 0; y < (int)MoM::gMAX_MAP_ROWS; ++y)
            {
                for (int x = 0; x < (int)MoM::gMAX_MAP_COLS; ++x)
                {
                    MoM::QMoMMapTile* mapTile = new MoM::QMoMMapTile;
                    mapTile->setPlane(plane);
                    mapTile->setTerrainType(m_game->getTerrainType(plane, x, y));
                    if (ui->checkBox_BonusDeposits->isChecked())
                    {
                        mapTile->setBonusDeposit(m_game->getBonusDeposit(plane, x, y));
                    }
                    mapTile->setPos(x * rectfTile.width(), y * rectfTile.height());
                    scene[plane]->addItem(mapTile);
                }
            }
        }
    }


    // Update items that are not fixed

    // Show units
    for (int unitNr = 0; (unitNr < m_game->getNrUnits()) && (MoM::toUInt(unitNr) < MoM::gMAX_UNITS); ++unitNr)
    {
        MoM::Unit* unit = m_game->getUnit(unitNr);
        if ((0 != unit)
                && MoM::inRange(unit->m_Unit_Type, MoM::eUnit_Type_MAX)
                && MoM::inRange(unit->m_Plane, MoM::ePlane_MAX))
        {
            if (!ui->checkBox_YourUnits->isChecked() && (unit->m_Owner == MoM::PLAYER_YOU))
                continue;
            if (!ui->checkBox_EnemyUnits->isChecked() && (unit->m_Owner != MoM::PLAYER_YOU))
                continue;

            MoM::MoMUnit momUnit(m_game.data());
            momUnit.changeUnit(unit);

            MoM::QMoMUnitTile* unitTile = new MoM::QMoMUnitTile;
            unitTile->setGame(m_game);
            unitTile->setUnit(unit);

            scene[unit->m_Plane]->addItem(unitTile);
            unitTile->setPos(unit->m_XPos * rectfTile.width(), unit->m_YPos * rectfTile.height());
            unitTile->setToolTip(momUnit.getDisplayName().c_str());
            m_lookup.insert(unit, unitTile);
        }
    }

    // Show lairs
    if (ui->checkBox_Lairs->isChecked())
    {
        for (int lairNr = 0; (MoM::toUInt(lairNr) < MoM::gMAX_NODES_LAIRS_TOWERS); ++lairNr)
        {
            MoM::Tower_Node_Lair* lair = m_game->getLair(lairNr);
            if (0 == lair)
                continue;
            QPixmap pixmapLair = MoM::QMoMResources::instance().getPixmap(lair->m_Type, 1);
            if (MoM::inRange(lair->m_Type, MoM::eTower_Node_Lair_Type_MAX)
                    && MoM::inRange(lair->m_Plane, MoM::ePlane_MAX)
                    && !pixmapLair.isNull())
            {
                QGraphicsItem* mapLairItem = scene[lair->m_Plane]->addPixmap(pixmapLair);
                mapLairItem->setPos(lair->m_XPos * rectfTile.width(), lair->m_YPos * rectfTile.height());
                mapLairItem->setScale(rectfTile.width() / pixmapLair.width());
                mapLairItem->setToolTip(prettyQStr(lair->m_Type));
                m_lookup.insert(lair, mapLairItem);
            }
        }
    }
}

void DialogOverlandMap::slot_tileChanged(const MoM::Location& loc)
{
    ui->treeWidget_Tile->clear();

    QTreeItem* qtreeItem;
    qtreeItem = new QTreeItem;
    qtreeItem->setText(0, "Location");
    qtreeItem->setText(1, QString("%0:(%1,%2)").arg(prettyQStr(loc.m_Plane)).arg(loc.m_XPos).arg(loc.m_YPos));
    ui->treeWidget_Tile->addTopLevelItem(qtreeItem);
    qtreeItem = new QTreeItem;
    qtreeItem->setText(0, "text2");
    ui->treeWidget_Tile->addTopLevelItem(qtreeItem);
}

void DialogOverlandMap::slot_timerActiveUnit()
{
    if (m_game.isNull() || (0 == m_game->getGame_Data_Exe()))
        return;
    int unitNrActive = m_game->getGame_Data_Exe()->m_UnitNr_Active;
    MoM::Unit* unit = m_game->getUnit(unitNrActive);
    if (0 == unit)
        return;
    QGraphicsItem* qItem = lookup(unit);
    if (0 != qItem)
    {
        qItem->setVisible(!qItem->isVisible());
    }
}

void DialogOverlandMap::on_verticalSlider_Zoom_valueChanged(int value)
{
    double scale = 1.0 + value / 100.0;
    if (value < 0)
    {
        scale = std::pow(2.0, value / 100.0);
    }

    ui->graphicsView->resetTransform();
    ui->graphicsView->scale(scale, scale);
}
