// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include "dialogbuildingqueues.h"
#include "ui_dialogbuildingqueues.h"

#include <MoMGenerated.h>

#include "mainwindow.h"

DialogBuildingQueues::DialogBuildingQueues(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBuildingQueues)
{
    ui->setupUi(this);

    ui->splitter->setSizes(QList<int>() << 100 << 680);

    ui->tableWidget_QueueDefinition->setColumnWidth(0, 140);
    ui->tableWidget_QueueDefinition->setColumnWidth(1, 420);

    int row = 0;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Spearmen"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem("Garrison < 1 and not producing(Garrison)"));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Spearmen"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem("Pop >= 5 and Garrison < 2 and not producing(Garrison)"));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Builder's Hall"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("buy(Builder's Hall)"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem("Completion >= 50%"));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Granary"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("buy(Granary)"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem("Completion >= 50%"));
    row++;
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

    update();
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
    MoM::MoMGameBase* game = controller->getGame();
    if (0 == game)
        return;

    int row = 0;
    for (int cityNr = 0; (cityNr < game->getNrCities()) && (cityNr < (int)MoM::gMAX_CITIES); ++cityNr)
    {
        MoM::City* city = game->getCity(cityNr);
        if (0 == city)
            break;
        if (MoM::PLAYER_YOU != city->m_Owner)
            continue;

        if (row >= ui->tableWidget_Cities->rowCount())
        {
            ui->tableWidget_Cities->insertRow(row);
        }
        ui->tableWidget_Cities->setItem(row, 0, new QTableWidgetItem(city->m_City_Name));
        ui->tableWidget_Cities->setItem(row, 1, new QTableWidgetItem(prettyQStr(city->m_Race)));
        ui->tableWidget_Cities->setItem(row, 2, new QTableWidgetItem(QString("%0").arg(int(city->m_Population))));
        ui->tableWidget_Cities->setItem(row, 3, new QTableWidgetItem(QString("%0 / %1").arg(int(city->m_HammersAccumulated)).arg("?")));
        ui->tableWidget_Cities->setItem(row, 4, new QTableWidgetItem(prettyQStr(city->m_Producing)));
//        ui->tableWidget_Cities->setItem(row, 5, new QTableWidgetItem("?"));

        row++;
    }
    ui->tableWidget_Cities->setRowCount(row);
    ui->tableWidget_Cities->setSortingEnabled(true);
}

void DialogBuildingQueues::on_buttonBox_clicked(QAbstractButton* button)
{
    MainWindow* controller = dynamic_cast<MainWindow*>(this->parent());
    if (0 == controller)
        return;

    if (QDialogButtonBox::ApplyRole == ui->buttonBox->buttonRole(button))
    {
        controller->applyBuildQueues();
        update();
    }
}
