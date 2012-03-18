// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2012-03-12
// ---------------------------------------------------------------------------

#include <qgraphicsscene.h>

#include "dialogoverlandmap.h"
#include "ui_dialogoverlandmap.h"

#include "MoMutility.h"
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

    MoM::MoMGameBase* game = getGame();
    if (0 != game)
    {
        for (int y = 0; y < (int)MoM::gMAX_MAP_ROWS; ++y)
        {
            for (int x = 0; x < (int)MoM::gMAX_MAP_COLS; ++x)
            {
                MoM::QMoMMapTile* mapTile = new MoM::QMoMMapTile;
                mapTile->setPlane(MoM::PLANE_Arcanum);
                mapTile->setTerrainType(game->getTerrainType(MoM::PLANE_Arcanum, x, y));
                mapTile->setPos(x * rectfTile.width(), y * rectfTile.height());
                m_sceneArcanus->addItem(mapTile);

                mapTile = new MoM::QMoMMapTile;
                mapTile->setPlane(MoM::PLANE_Myrror);
                mapTile->setTerrainType(game->getTerrainType(MoM::PLANE_Myrror, x, y));
                mapTile->setPos(x * rectfTile.width(), y * rectfTile.height());
                m_sceneMyrror->addItem(mapTile);
            }
        }
    }

    ui->comboBox_Plane->setCurrentIndex(1);
}

DialogOverlandMap::~DialogOverlandMap()
{
    delete ui;
    delete m_sceneMyrror;
    delete m_sceneArcanus;
}

MoM::MoMGameBase* DialogOverlandMap::getGame()
{
    MainWindow* controller = MainWindow::getInstance();
    if (0 == controller)
        return 0;
    MoM::MoMGameBase* game = controller->getGame();
    return game;
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
