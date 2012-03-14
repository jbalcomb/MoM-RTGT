// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2012-03-12
// ---------------------------------------------------------------------------

#include "dialogaddunit.h"
#include "ui_dialogaddunit.h"

#include <MoMGenerated.h>
#include "QMoMResources.h"

#include "mainwindow.h"

DialogAddUnit::DialogAddUnit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddUnit)
{
    ui->setupUi(this);

    MoM::MoMGameBase* game = getGame();
	ui->comboBoxUnit->clear();

    MoM::Unit_Type_Data* unitTypes = 0;
    int ndata = 0;

    if (0 != game)
    {
        unitTypes = game->getUnit_Types();
    }
    if (0 != unitTypes)
    {
        ndata = (int)MoM::eUnit_Type_MAX;
    }
    for (int row = 0; row < ndata; ++row)
    {
		MoM::eUnit_Type unitTypeNr = static_cast<MoM::eUnit_Type>(row);
        MoM::Unit_Type_Data* data = &unitTypes[unitTypeNr];

		QString title = QString("%0").arg((int)unitTypeNr, 3) + "   " + QString(game->getRaceName(data->m_Race_Code).c_str()) + "   " + QString(game->getNameByOffset(data->m_PtrName));
        QIcon icon = MoM::QMoMResources::instance().getIcon(unitTypeNr);

		ui->comboBoxUnit->addItem(icon, title);
	}
}

DialogAddUnit::~DialogAddUnit()
{
    delete ui;
}

MoM::MoMGameBase* DialogAddUnit::getGame()
{
    MainWindow* controller = MainWindow::getInstance();
    if (0 == controller)
        return 0;
    MoM::MoMGameBase* game = controller->getGame();
    return game;
}

void DialogAddUnit::on_buttonBox_clicked(QAbstractButton *button)
{
    MainWindow* controller = MainWindow::getInstance();
    if (0 == controller)
        return;

    if (QDialogButtonBox::ApplyRole == ui->buttonBox->buttonRole(button))
    {
		MoM::eUnit_Type unitType = static_cast<MoM::eUnit_Type>(ui->comboBoxUnit->currentIndex());
        controller->addUnit(unitType);
        update();
    }
}
