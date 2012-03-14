// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include <stdio.h>  // sscanf

#include <MoMExeWizards.h>
#include "mainwindow.h"

#include "dialogcalculatoraddress.h"
#include "ui_dialogcalculatoraddress.h"



DialogCalculatorAddress::DialogCalculatorAddress(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCalculatorAddress),
    m_updating(false)
{
    ui->setupUi(this);
}

DialogCalculatorAddress::~DialogCalculatorAddress()
{
    delete ui;
}

MoM::MoMGameBase* DialogCalculatorAddress::getGame()
{
    MainWindow* controller = MainWindow::getInstance();
    if (0 == controller)
        return 0;
    MoM::MoMGameBase* game = controller->getGame();
    return game;
}

void DialogCalculatorAddress::update()
{
    MoM::MoMGameBase* game = getGame();
}

void DialogCalculatorAddress::on_lineEdit_OffsetExe_textChanged(QString sExeOffset)
{
    if (m_updating)
        return;
    m_updating = true;

    ui->lineEdit_OffsetIDA->clear();
    ui->lineEdit_OffsetMem->clear();

    MoM::MoMGameBase* game = getGame();
    MoM::MoMExeWizards* wizardsExe = 0;
    if (0 != game)
    {
        wizardsExe = game->getWizardsExe();
    }

    bool ok = false;
    size_t exeOffset = sExeOffset.toULong(&ok, 16);
    size_t ovlNr = 0;
    uint16_t ovlOffset = 0;
    uint16_t dsegOffset = 0;

    if ((0 != wizardsExe) && wizardsExe->convertExeOffset_to_OvlOffset(exeOffset, ovlNr, ovlOffset))
    {
        ui->lineEdit_OffsetIDA->setText(QString("ovr%0:%1").arg(ovlNr, 3, 10, QChar('0')).arg(ovlOffset, 4, 16, QChar('0')));
    }
    else if ((0 != wizardsExe) && wizardsExe->convertExeOffset_to_DsegOffset(exeOffset, dsegOffset))
    {
        ui->lineEdit_OffsetIDA->setText(QString("dseg:%0").arg(dsegOffset, 4, 16, QChar('0')));
    }

    m_updating = false;
}

void DialogCalculatorAddress::on_lineEdit_OffsetIDA_textChanged(QString sIdaOffset)
{
    if (m_updating)
        return;
    m_updating = true;

    ui->lineEdit_OffsetExe->clear();
    ui->lineEdit_OffsetMem->clear();

    MoM::MoMGameBase* game = getGame();
    MoM::MoMExeWizards* wizardsExe = 0;
    if (0 != game)
    {
        wizardsExe = game->getWizardsExe();
    }

    size_t exeOffset = 0;

    unsigned ovrField = 0;
    unsigned offsetField = 0;
    if (2 == sscanf(sIdaOffset.toAscii().data(), " ovr%u:%x", &ovrField, &offsetField))
    {
        size_t ovlNr = ovrField;
        uint16_t ovlOffset = offsetField;
        if ((0 != wizardsExe) && wizardsExe->convertOvlOffset_to_ExeOffset(ovlNr, ovlOffset, exeOffset))
        {
            ui->lineEdit_OffsetExe->setText(QString("%0").arg(exeOffset, 5, 16, QChar('0')));
        }
    }
    else if ((1 == sscanf(sIdaOffset.toAscii().data(), " dseg:%x", &offsetField))
            || (1 == sscanf(sIdaOffset.toAscii().data(), " ds:%x", &offsetField)))
    {
        uint16_t dsegOffset = offsetField;
        if ((0 != wizardsExe) && wizardsExe->convertDsegOffset_to_ExeOffset(dsegOffset, exeOffset))
        {
            ui->lineEdit_OffsetExe->setText(QString("%0").arg(exeOffset, 5, 16, QChar('0')));
        }
    }

    m_updating = false;
}

void DialogCalculatorAddress::on_lineEdit_OffsetMem_textChanged(QString )
{

}
