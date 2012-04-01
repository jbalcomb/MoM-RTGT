// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2012-03-12
// ---------------------------------------------------------------------------

#include <qgraphicsscene.h>

#include "dialogoverlandmap.h"
#include "ui_dialogoverlandmap.h"

#include "MoMUtility.h"
#include "MoMGenerated.h"
#include "MoMExeWizards.h"
#include "mainwindow.h"
#include "QMoMMapTile.h"
#include "QMoMResources.h"

using MoM::QMoMResources;

DialogOverlandMap::DialogOverlandMap(QWidget *parent) :
    QDialog(parent),
    m_sceneArcanus(new QGraphicsScene),
    m_sceneMyrror(new QGraphicsScene),
    ui(new Ui::DialogOverlandMap)
{
    ui->setupUi(this);

    QRectF rectfTile = MoM::QMoMMapTile().boundingRect();
    m_sceneArcanus->setSceneRect(0, 0, MoM::gMAX_MAP_COLS * rectfTile.width(), MoM::gMAX_MAP_ROWS * rectfTile.height());
    m_sceneMyrror->setSceneRect(0, 0, MoM::gMAX_MAP_COLS * rectfTile.width(), MoM::gMAX_MAP_ROWS * rectfTile.height());

    ui->comboBox_Plane->setCurrentIndex(1);

    // TODO: Make signal-slot connections to gameChanged and gameUpdated (similar to the other dialogs)
    QObject::connect(MainWindow::getInstance(), SIGNAL(signal_gameChanged(QMoMGamePtr)), this, SLOT(slot_gameChanged(QMoMGamePtr)));
    QObject::connect(MainWindow::getInstance(), SIGNAL(signal_gameUpdated()), this, SLOT(slot_gameUpdated()));

    slot_gameChanged(MainWindow::getInstance()->getGame());
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

    if (m_game.isNull())
        return;

    QRectF rectfTile = MoM::QMoMMapTile().boundingRect();

    // Add fixed map tiles
    // Show terrain
    for (int y = 0; y < (int)MoM::gMAX_MAP_ROWS; ++y)
    {
        for (int x = 0; x < (int)MoM::gMAX_MAP_COLS; ++x)
        {
            MoM::QMoMMapTile* mapTile = new MoM::QMoMMapTile;
            mapTile->setPlane(MoM::PLANE_Arcanum);
            mapTile->setTerrainType(m_game->getTerrainType(MoM::PLANE_Arcanum, x, y));
            mapTile->setPos(x * rectfTile.width(), y * rectfTile.height());
            m_sceneArcanus->addItem(mapTile);

            mapTile = new MoM::QMoMMapTile;
            mapTile->setPlane(MoM::PLANE_Myrror);
            mapTile->setTerrainType(m_game->getTerrainType(MoM::PLANE_Myrror, x, y));
            mapTile->setPos(x * rectfTile.width(), y * rectfTile.height());
            m_sceneMyrror->addItem(mapTile);
        }
    }


    // Update items that are not fixed

    QGraphicsScene* scene[MoM::ePlane_MAX] = { m_sceneArcanus, m_sceneMyrror };

    // Show units
    for (int unitNr = 0; (unitNr < m_game->getNrUnits()) && (MoM::toUInt(unitNr) < MoM::gMAX_UNITS); ++unitNr)
    {
        MoM::Unit* unit = m_game->getUnit(unitNr);
        if ((0 != unit)
                && MoM::inRange(unit->m_Unit_Type, MoM::eUnit_Type_MAX)
                && MoM::inRange(unit->m_Plane, MoM::ePlane_MAX))
        {
            QPixmap pixmapUnit = MoM::QMoMResources::instance().getPixmap(unit->m_Unit_Type, 1);

            QPixmap pixmapBack;
            MoM::Wizard* wizard = m_game->getWizard(unit->m_Owner);
            if (0 != wizard)
            {
                pixmapBack = MoM::QMoMResources::instance().getPixmap(wizard->m_BannerColor);
            }

            QGraphicsItem* mapColorItem = scene[unit->m_Plane]->addPixmap(pixmapBack);
            mapColorItem->setPos(unit->m_XPos * rectfTile.width(), unit->m_YPos * rectfTile.height());

            QGraphicsItem* mapUnitItem = scene[unit->m_Plane]->addPixmap(pixmapUnit);
            mapUnitItem->setPos(unit->m_XPos * rectfTile.width(), unit->m_YPos * rectfTile.height());
        }
    }

    // Show lairs
    for (int lairNr = 0; (MoM::toUInt(lairNr) < MoM::gMAX_NODES_LAIRS_TOWERS); ++lairNr)
    {
        MoM::Tower_Node_Lair* lair = m_game->getLair(lairNr);
        if (0 == lair)
            continue;
        if (MoM::inRange(lair->m_Type, MoM::eTower_Node_Lair_Type_MAX)
                && MoM::inRange(lair->m_Plane, MoM::ePlane_MAX))
        {
            QPixmap pixmapLair = MoM::QMoMResources::instance().getPixmap(lair->m_Type, 1);
            QGraphicsItem* mapLairItem = scene[lair->m_Plane]->addPixmap(pixmapLair);
            mapLairItem->setPos(lair->m_XPos * rectfTile.width(), lair->m_YPos * rectfTile.height());
        }
    }

}
