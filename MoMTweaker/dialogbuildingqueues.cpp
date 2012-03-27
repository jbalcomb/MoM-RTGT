// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include "dialogbuildingqueues.h"
#include "ui_dialogbuildingqueues.h"

#include <MoMController.h>
#include <MoMGenerated.h>

#include "mainwindow.h"

DialogBuildingQueues::DialogBuildingQueues(QWidget *parent) :
    QDialog(parent),
	m_game(),
    ui(new Ui::DialogBuildingQueues)
{
    ui->setupUi(this);

    ui->splitter->setSizes(QList<int>() << 100 << 680);

    ui->tableWidget_QueueDefinition->setColumnWidth(0, 140);
    ui->tableWidget_QueueDefinition->setColumnWidth(1, 420);

    int row = 0;
	ui->tableWidget_QueueDefinition->clear();
    ui->tableWidget_QueueDefinition->setRowCount(18);

    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Spearmen"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem("Garrison < 1 and not producing(Garrison)"));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Spearmen"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem("Pop >= 5 and Garrison < 2 and not producing(Garrison)"));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Builder's Hall"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;
//    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("buy(Builder's Hall)"));
//    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem("Completion >= 50%"));
//    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Granary"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;
//    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("buy(Granary)"));
//    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem("Completion >= 50%"));
//    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Smithy"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Marketplace"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Farmer's Market"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Housing"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem("Pop < 8"));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Shrine"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Sawmill"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Foresters Guild"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Library"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Sages Guild"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Temple"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Alchemist Guild"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("University"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Bank"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Miners Guild"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;

    QObject::connect(MainWindow::getInstance(), SIGNAL(signal_gameChanged(QMoMGamePtr)), this, SLOT(slot_gameChanged(QMoMGamePtr)));
	QObject::connect(MainWindow::getInstance(), SIGNAL(signal_gameUpdated()), this, SLOT(slot_gameUpdated()));

	slot_gameChanged(MainWindow::getInstance()->getGame());
}

DialogBuildingQueues::~DialogBuildingQueues()
{
    delete ui;
}

void DialogBuildingQueues::update()
{
    MainWindow* controller = MainWindow::getInstance();
    if (0 == controller)
        return;
	int nrCities = 0;
    if (0 != m_game)
	{
        nrCities = m_game->getNrCities();
	}

	MoM::MoMController momController;

    int row = 0;
    for (int cityNr = 0; (cityNr < nrCities) && (cityNr < (int)MoM::gMAX_CITIES); ++cityNr)
    {
        MoM::City* city = m_game->getCity(cityNr);
        if (0 == city)
            break;
        if (MoM::PLAYER_YOU != city->m_Owner)
            continue;
		QString buildingCost = QString("%0").arg(m_game->getCostToProduce(city->m_Producing));

        std::vector<int> unitsInCity;
        MoM::Location location = { city->m_XPos, city->m_YPos, city->m_Plane };
        (void)momController.findUnitsAtLocation(*m_game, location, unitsInCity);
        int garrisonSize = unitsInCity.size();

        if (row >= ui->tableWidget_Cities->rowCount())
        {
            ui->tableWidget_Cities->insertRow(row);
        }
        ui->tableWidget_Cities->setItem(row, 0, new QTableWidgetItem(city->m_City_Name));
        ui->tableWidget_Cities->setItem(row, 1, new QTableWidgetItem(prettyQStr(city->m_Race)));
        ui->tableWidget_Cities->setItem(row, 2, new QTableWidgetItem(QString("%0").arg(int(city->m_Population))));
		ui->tableWidget_Cities->setItem(row, 3, new QTableWidgetItem(QString("%0 / %1").arg((int)city->m_HammersAccumulated).arg(buildingCost)));
        ui->tableWidget_Cities->setItem(row, 4, new QTableWidgetItem(prettyQStr(city->m_Producing)));
        ui->tableWidget_Cities->setItem(row, 5, new QTableWidgetItem(QString("%0").arg(garrisonSize)));

        row++;
    }
    ui->tableWidget_Cities->setRowCount(row);
    ui->tableWidget_Cities->setSortingEnabled(true);
}

void DialogBuildingQueues::on_buttonBox_clicked(QAbstractButton* button)
{
    MainWindow* controller = MainWindow::getInstance();
    if (0 == controller)
        return;

    if (QDialogButtonBox::ApplyRole == ui->buttonBox->buttonRole(button))
    {
        controller->applyBuildQueues();
        update();
    }
}

void DialogBuildingQueues::slot_gameChanged(const QMoMGamePtr& game)
{
	m_game = game;
	update();
}

void DialogBuildingQueues::slot_gameUpdated()
{
	update();
}
