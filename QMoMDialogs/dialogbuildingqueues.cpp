// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include "DialogBuildingQueues.h"
#include "ui_DialogBuildingQueues.h"

#include <QMenu>

#include <MoMCity.h>
#include <MoMController.h>
#include <MoMGenerated.h>
#include <QMoMTableItem.h>
#include <QMoMSettings.h>

#include "MainWindow.h"

using namespace MoM;

DialogBuildingQueues::DialogBuildingQueues(QWidget *parent) :
    QDialog(parent),
    m_game(),
    m_contextMenuOpen(false),
    ui(new Ui::DialogBuildingQueues)
{
    ui->setupUi(this);

    ui->splitter->setSizes(QList<int>() << 100 << 680);

    ui->tableWidget_QueueDefinition->setColumnWidth(0, 140);
    ui->tableWidget_QueueDefinition->setColumnWidth(1, 420);

    QStringList labelsQueue;
    labelsQueue << "Build" << "Conditions";
    ui->tableWidget_QueueDefinition->setColumnCount(labelsQueue.size());
    ui->tableWidget_QueueDefinition->setHorizontalHeaderLabels(labelsQueue);

    int row = 0;
	ui->tableWidget_QueueDefinition->clear();
    ui->tableWidget_QueueDefinition->setRowCount(26);

    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Garrison"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem("Garrison < 1 and not producing(Garrison)"));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Garrison"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem("producing(Garrison)"));
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
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem("Pop < 4"));
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
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Stable"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem("if allowed(Animists Guild)"));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Animists Guild"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Parthenon"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Shipwright Guild"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem("if allowed(Merchants Guild)"));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Ship Yard"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem("if allowed(Merchants Guild)"));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Merchants Guild"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Cathedral"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;
    ui->tableWidget_QueueDefinition->setItem(row, 0, new QTableWidgetItem("Wizards Guild"));
    ui->tableWidget_QueueDefinition->setItem(row, 1, new QTableWidgetItem(""));
    row++;

    ui->tableWidget_QueueDefinition->setRowCount(row);
    ui->tableWidget_QueueDefinition->resizeRowsToContents();

    QStringList labelsCities;
    labelsCities << "Nr"
           << "Name" << "Race" << "Pop" << "Farmers" << "Food" << "Prod" << "Completion" << "Producing"
           << "Time" << "Garrison" << "CostBuy";
    ui->tableWidget_Cities->setColumnCount(labelsCities.size());
    ui->tableWidget_Cities->setHorizontalHeaderLabels(labelsCities);
    ui->tableWidget_Cities->sortByColumn(0, Qt::AscendingOrder);

    QMoMSettings::readSettingsWindow(this);

    QObject::connect(MainWindow::getInstance(), SIGNAL(signal_gameChanged(QMoMGamePtr)), this, SLOT(slot_gameChanged(QMoMGamePtr)));
	QObject::connect(MainWindow::getInstance(), SIGNAL(signal_gameUpdated()), this, SLOT(slot_gameUpdated()));

	slot_gameChanged(MainWindow::getInstance()->getGame());
}

DialogBuildingQueues::~DialogBuildingQueues()
{
    QMoMSettings::writeSettingsWindow(this);

    delete ui;
}

void DialogBuildingQueues::update()
{
    MainWindow* controller = MainWindow::getInstance();
    if (0 == controller)
        return;
	int nrCities = 0;
    int nrUnits = 0;
    if (0 != m_game)
	{
        nrCities = m_game->getNrCities();
        nrUnits = m_game->getNrUnits();
    }

    MoM::MoMController momController(m_game.data());

    ui->tableWidget_Cities->setSortingEnabled(false);

    int row = 0;
    for (int cityNr = 0; (cityNr < nrCities) && (cityNr < (int)MoM::gMAX_CITIES); ++cityNr)
    {
        City* city = m_game->getCity(cityNr);
        if (0 == city)
            break;
        if (MoM::PLAYER_YOU != city->m_Owner)
            continue;
        MoMCity momCity(m_game.data(), city);

        int buildingCost = momCity.getCostToProduce(city->m_Producing);
        int timeCompletion = momCity.getTimeToComplete(city->m_Producing);
        int garrisonSize = momController.countGarrison(MoMLocation(*city));
        int foodSurplus = city->m_Food_Produced - city->m_Population;
        QString foodSurplusStr = QString("%0").arg(foodSurplus);
        if (foodSurplus >= 0)
        {
            foodSurplusStr = "+" + foodSurplusStr;
        }
        int costToBuy = momCity.getCostToBuy(city->m_Producing);

        if (row >= ui->tableWidget_Cities->rowCount())
        {
            ui->tableWidget_Cities->insertRow(row);
        }
        int col = 0;
        ui->tableWidget_Cities->setItem(row, col++, new QTableWidgetItem(QString("%0").arg(cityNr, 2)));
        ui->tableWidget_Cities->setItem(row, col++, new QTableWidgetItem(city->m_City_Name));
        ui->tableWidget_Cities->setItem(row, col++, new QTableWidgetItem(
                                            *QMoMResources::instance().getIcon(city->m_Race),
                                            prettyQStr(city->m_Race)));
        ui->tableWidget_Cities->setItem(row, col++, new QTableWidgetItem(QString("%0").arg((int)(city->m_Population), 2)));
        ui->tableWidget_Cities->setItem(row, col++, new NumberTableItem<int8_t>(m_game, &city->m_Number_of_farmers_allocated, 2, SHOWNUMBER_normal));
        ui->tableWidget_Cities->setItem(row, col++, new QTableWidgetItem(
                                            *QMoMResources::instance().getIcon(LBXRecordID("BACKGRND", 40), 2),
                                            foodSurplusStr));
        ui->tableWidget_Cities->setItem(row, col++, new QTableWidgetItem(
                                            *QMoMResources::instance().getIcon(LBXRecordID("BACKGRND", 41), 2),
                                            QString("%0").arg((int)(city->m_Hammers), 3)));
        ui->tableWidget_Cities->setItem(row, col++, new QTableWidgetItem(QString("%0 /%1").arg((int)city->m_HammersAccumulated, 4).arg(buildingCost, 4)));
        QList<eProducing> listProducing;
        MOM_FOREACH(eProducing, produce, eProducing_MAX)
        {
            if (momCity.canProduce(produce))
            {
                listProducing << produce;
            }
        }
        ui->tableWidget_Cities->setItem(row, col++, new EnumTableItemList<eProducing>(m_game, &city->m_Producing, listProducing));
        ui->tableWidget_Cities->setItem(row, col++, new QTableWidgetItem(QString("%0").arg(timeCompletion, 3)));
        ui->tableWidget_Cities->setItem(row, col++, new QTableWidgetItem(QString("%0").arg(garrisonSize)));
        ui->tableWidget_Cities->setItem(row, col++, new QTableWidgetItem(QString("%0").arg(costToBuy)));

        for (int col = 0; col < ui->tableWidget_Cities->columnCount(); ++col)
        {
            ui->tableWidget_Cities->item(row, col)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        }

        row++;
    }

    ui->tableWidget_Cities->setRowCount(row);
    for (int row = 0; row < ui->tableWidget_Cities->rowCount(); ++row)
    {
        ui->tableWidget_Cities->setVerticalHeaderItem(row, new QTableWidgetItem(""));
    }
    ui->tableWidget_Cities->resizeRowsToContents();
    ui->tableWidget_Cities->setSortingEnabled(true);


    int totalGoldSurplus = 0;
    int totalFoodSurplus = 0;
    for (int cityNr = 0; cityNr < nrCities; ++cityNr)
    {
        City* city = m_game->getCity(cityNr);
        if (0 == city)
            break;
        if (MoM::PLAYER_YOU != city->m_Owner)
            continue;
        totalGoldSurplus += city->m_Coins - city->m_Maintenance;
        totalFoodSurplus += city->m_Food_Produced - city->m_Population;
    }
    for (int unitNr = 0; unitNr < nrUnits; ++unitNr)
    {
        Unit* unit = m_game->getUnit(unitNr);
        if (0 == unit)
            break;
        if (MoM::PLAYER_YOU != unit->m_Owner)
            continue;
        MoMUnit momUnit(m_game.data(), unit);
        if (momUnit.isNormal() && !momUnit.isGeneric())
        {
            totalFoodSurplus--;
        }
        if (momUnit.isHero() || momUnit.isNormal())
        {
            totalGoldSurplus -= momUnit.getUnitTypeData().m_Upkeep;
        }
        if (momUnit.hasHeroAbility(HEROABILITY_Noble))
        {
            totalGoldSurplus += momUnit.getHeroAbility(HEROABILITY_Noble);
        }
    }

    int totalGold = 0;
    if ((0 != m_game) && (0 != m_game->getWizard(PLAYER_YOU)))
    {
        totalGold = m_game->getWizard(PLAYER_YOU)->m_Gold_Coins;
    }

    row = 0;
    ui->tableWidget_Summary->verticalHeaderItem(row)->setText("Total gold");
    ui->tableWidget_Summary->item(row++, 0)->setText(QString("%0").arg(totalGold));
    ui->tableWidget_Summary->verticalHeaderItem(row)->setText("Gold/turn");
    ui->tableWidget_Summary->item(row++, 0)->setText(QString("%0").arg(totalGoldSurplus));
    ui->tableWidget_Summary->verticalHeaderItem(row)->setText("Food/turn");
    ui->tableWidget_Summary->item(row++, 0)->setText(QString("%0").arg(totalFoodSurplus));
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

void DialogBuildingQueues::on_tableWidget_Cities_customContextMenuRequested(const QPoint &pos)
{
    qDebug() << "on_tableWidget_Cities_customContextMenuRequested" << pos;
    m_contextMenuOpen = true;

    QTableWidgetItem* pItem = ui->tableWidget_Cities->currentItem();

    QMenu contextMenu;
//    contextMenu.addAction("Copy", this, SLOT(slot_Copy()), QKeySequence("Ctrl+C"));

    QMoMTableItemBase* pMoMItem = dynamic_cast<QMoMTableItemBase*>(pItem);
    if (0 != pMoMItem)
    {
        QList<QAction*> actions = pMoMItem->requestActions(&contextMenu);
        if (!actions.empty())
        {
            contextMenu.addSeparator();
            contextMenu.addActions(actions);
        }
        foreach(QAction* action, actions)
        {
            connect(action, SIGNAL(triggered()), this, SLOT(slot_ItemAction()));
        }
    }

    contextMenu.exec(mapToGlobal(pos));

    m_contextMenuOpen = false;
}

void DialogBuildingQueues::slot_gameChanged(const QMoMGamePtr& game)
{
    // TODO: Recover from an open context menu, while the game is changed
    if (m_contextMenuOpen)
        return;

    m_game = game;
	update();
}

void DialogBuildingQueues::slot_gameUpdated()
{
    if (m_contextMenuOpen)
        return;

    update();
}

void DialogBuildingQueues::slot_ItemAction()
{
    QTableWidgetItem* pItem = ui->tableWidget_Cities->currentItem();
    QMoMTableItemBase* pMoMItem = dynamic_cast<QMoMTableItemBase*>(pItem);
    if (0 != pMoMItem)
    {
        pMoMItem->slotAction();
    }
}
