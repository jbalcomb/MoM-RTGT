// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include <stdio.h>  // sscanf

#include <MoMExeMagic.h>
#include <MoMExeWizards.h>
#include <MoMProcess.h>
#include <MoMUtility.h>
#include "mainwindow.h"

#include "dialogcalculatoraddress.h"
#include "ui_dialogcalculatoraddress.h"



DialogCalculatorAddress::DialogCalculatorAddress(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCalculatorAddress),
    m_updating(false)
{
    ui->setupUi(this);

    QObject::connect(MainWindow::getInstance(), SIGNAL(signal_gameChanged(QMoMGamePtr)), this, SLOT(slot_gameChanged(QMoMGamePtr)));
    QObject::connect(MainWindow::getInstance(), SIGNAL(signal_gameUpdated()), this, SLOT(slot_gameUpdated()));

    slot_gameChanged(MainWindow::getInstance()->getGame());
}

DialogCalculatorAddress::~DialogCalculatorAddress()
{
    delete ui;
}

void DialogCalculatorAddress::update()
{
}

void DialogCalculatorAddress::on_lineEdit_OffsetExe_textChanged(QString sExeOffset)
{
    if (m_updating)
        return;
	MoM::UpdateLock lock(m_updating);

    ui->lineEdit_OffsetIDA->clear();
    ui->lineEdit_OffsetMem->clear();
    ui->lineEdit_CurrentValue->clear();

    MoM::MoMExeWizards* wizardsExe = 0;
    if (!m_game.isNull())
    {
        wizardsExe = m_game->getWizardsExe();
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

    if ((0 != wizardsExe) && (exeOffset > 0) && (exeOffset + sizeof(uint16_t) <= wizardsExe->getExeSize()))
    {
        const uint8_t* pointer = wizardsExe->getExeContents() + exeOffset;
        updateCurrentValue(pointer);
    }
}

void DialogCalculatorAddress::on_lineEdit_OffsetIDA_textChanged(QString sIdaOffset)
{
    if (m_updating)
        return;
    MoM::UpdateLock lock(m_updating);

    ui->lineEdit_OffsetExe->clear();
    ui->lineEdit_OffsetMem->clear();
    ui->lineEdit_CurrentValue->clear();

    MoM::MoMExeWizards* wizardsExe = 0;
    if (!m_game.isNull())
    {
        wizardsExe = m_game->getWizardsExe();
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

    if ((0 != wizardsExe) && (exeOffset > 0) && (exeOffset + sizeof(uint16_t) <= wizardsExe->getExeSize()))
    {
        const uint8_t* pointer = wizardsExe->getExeContents() + exeOffset;
        updateCurrentValue(pointer);
    }
}

void DialogCalculatorAddress::on_lineEdit_OffsetMem_textChanged(QString )
{
    // TODO
    ui->lineEdit_OffsetExe->clear();
    ui->lineEdit_OffsetIDA->clear();
    ui->lineEdit_CurrentValue->clear();
}

void DialogCalculatorAddress::slot_gameChanged(const QMoMGamePtr& game)
{
    m_game = game;
    update();
}

void DialogCalculatorAddress::slot_gameUpdated()
{
    update();
}

void DialogCalculatorAddress::slot_addressChanged(const void* momPointer)
{
    if (0 == m_game)
        return;

    // Clear old fields
    ui->lineEdit_OffsetExe->clear();
    ui->lineEdit_OffsetIDA->clear();
    ui->lineEdit_OffsetMem->clear();
    ui->lineEdit_CurrentValue->clear();

    // TODO: Properly distinguish wizards.exe and magic.exe

    QString dosStr;
    dosStr = QString("void* %0").arg((unsigned long)momPointer, 8, 16, QChar('0'));
	QString memStr;

	const MoM::MoMProcess* momProcess = m_game->getMoMProcess();
	if ((0 != momProcess))
	{
		memStr = QString("Base=%0 Size=%1 Seg0=%2 DS=%3")
			.arg((size_t)momProcess->getBaseAddress(), 8, 16, QChar('0'))
			.arg((size_t)momProcess->getBaseAddressSize(), 8, 16, QChar('0'))
			.arg((size_t)momProcess->getOffsetSegment0(), 4, 16, QChar('0'))
			.arg((size_t)momProcess->getOffsetDatasegment(), 4, 16, QChar('0'));
	}

    const MoM::MoMDataSegment* wizardsDataSegment = m_game->getDataSegment();
    // TODO: Sharper boundary check on end-of-memory
    if ((0 != wizardsDataSegment) && (momPointer >= wizardsDataSegment) && (momPointer < (uint8_t*)wizardsDataSegment + 0xFFFFF))
    {
        unsigned dsOffset = ((uint8_t*)momPointer - (uint8_t*)wizardsDataSegment);
        dosStr = QString(" ds:%0").arg(dsOffset, 4, 16, QChar('0'));

        // Triggers updates
        if (dsOffset <= sizeof(MoM::MoMDataSegment))
		{
			ui->lineEdit_OffsetIDA->setText(QString("dseg:%0").arg(dsOffset, 4, 16, QChar('0')));
		}
    }

    const MoM::MoMMagicDataSegment* magicDataSegment = m_game->getMagicDataSegment();
    // TODO: Sharper boundary check on end-of-memory
    if ((0 != magicDataSegment) && (momPointer >= magicDataSegment) && (momPointer < (uint8_t*)magicDataSegment + 0xFFFFF))
    {
        unsigned dsOffset = ((uint8_t*)momPointer - (uint8_t*)magicDataSegment);
        dosStr = QString(" ds:%0").arg(dsOffset, 4, 16, QChar('0'));

        // Triggers updates
        if (dsOffset <= sizeof(MoM::MoMMagicDataSegment))
		{
//			ui->lineEdit_OffsetIDA->setText(QString("dseg:%0").arg(dsOffset, 4, 16, QChar('0')));
		}
    }

    const uint8_t* seg0Pointer = m_game->getSeg0Pointer();
    if ((0 != seg0Pointer) && (momPointer >= seg0Pointer))
    {
        int seg0Offset = ((uint8_t*)momPointer - (uint8_t*)seg0Pointer);
		// TODO: Sharper boundary check on end-of-memory
		if (seg0Offset <= 0xFFFFF)
		{
			dosStr += QString(" %0:%1").arg(seg0Offset / MoM::gPARAGRAPH_SIZE, 4, 16, QChar('0')).arg(seg0Offset % MoM::gPARAGRAPH_SIZE, 1, 16, QChar('0'));
			if (0 != momProcess)
			{
				size_t memOffset = (size_t)(momProcess->getBaseAddress() + momProcess->getOffsetSegment0() + seg0Offset);
				memStr = QString("%0 (%1)").arg(memOffset, 8, 16, QChar('0')).arg(memStr);
			}
		}
    }

	MoM::MoMExeWizards* wizardsExe = m_game->getWizardsExe();
    if ((0 != wizardsExe) && (momPointer >= wizardsExe->getExeContents()) && (momPointer < wizardsExe->getExeContents() + wizardsExe->getExeSize()))
    {
        int wizardsExeOffset = ((uint8_t*)momPointer - (uint8_t*)wizardsExe->getExeContents());
        dosStr += QString(" wizards.exe:%0").arg(wizardsExeOffset, 5, 16, QChar('0'));

        // Triggers updates
        ui->lineEdit_OffsetExe->setText(QString("%0").arg(wizardsExeOffset, 5, 16, QChar('0')));
    }

    MoM::MoMExeMagic* magicExe = m_game->getMagicExe();
    if ((0 != magicExe) && (momPointer >= magicExe->getExeContents()) && (momPointer < magicExe->getExeContents() + magicExe->getExeSize()))
    {
        int magicExeOffset = ((uint8_t*)momPointer - (uint8_t*)magicExe->getExeContents());
        dosStr += QString(" magic.exe:%0").arg(magicExeOffset, 5, 16, QChar('0'));
    }

    MoM::SaveGame* saveGame = m_game->getSaveGame();
    if ((0 != saveGame) && (momPointer >= saveGame) && (momPointer < saveGame + 1))
    {
        int saveGameOffset = ((uint8_t*)momPointer - (uint8_t*)saveGame);
        dosStr += QString(" save:%0").arg(saveGameOffset, 5, 16, QChar('0'));
    }

    ui->lineEdit_OffsetDOS->setText(dosStr);
	ui->lineEdit_OffsetMem->setText(memStr);

    updateCurrentValue((const uint8_t*)momPointer);
}

void DialogCalculatorAddress::updateCurrentValue(const uint8_t* pointer)
{
    QString textCurrentValue;
    if (0 != pointer)
    {
        uint8_t lo = *pointer;
        uint8_t hi = *(pointer + 1);
        int16_t value = *(const int16_t*)pointer;
        textCurrentValue = QString("%0h %1h / %2 %3 / %4")
                .arg((unsigned)lo, 2, 16, QChar('0')).arg((unsigned)hi, 2, 16, QChar('0'))
                .arg((int)(int8_t)lo).arg((int)(int8_t)hi)
                .arg((int)value);
    }
    ui->lineEdit_CurrentValue->setText(textCurrentValue);
}
