// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2012-03-12
// ---------------------------------------------------------------------------

// OS specific

// Standard C++ Library

// Library
#include <MoMController.h>
#include <MoMGameCustom.h>
#include <MoMGenerated.h>
#include <MoMLbxBase.h>
#include <MoMGameMemory.h>
#include <MoMProcess.h>
#include <MoMGameSave.h>
#include <MoMUtility.h>
#include <QMoMLbx.h>
#include <QMoMResources.h>

// Local
#include "dialogbuildingqueues.h"
#include "dialoglbxeditor.h"
#include "dialogselectinitialspells.h"
#include "mainwindow.h"

// Module header
#include "dialogtools.h"
#include "ui_dialogtools.h"

DialogTools::DialogTools(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTools)
{
    ui->setupUi(this);
    setFont(MoM::QMoMResources::g_Font);
}

DialogTools::~DialogTools()
{
    delete ui;
}

QMoMGamePtr DialogTools::getGame()
{
	QMoMGamePtr game;
	MainWindow* controller = MainWindow::getInstance();
    if (0 != controller)
	{
	    game = controller->getGame();
	}
    return game;
}

void DialogTools::on_pushButton_Validate_clicked()
{
    MainWindow* controller = MainWindow::getInstance();
	QMoMGamePtr game = getGame();
    if (game.isNull())
    {
        (void)QMessageBox::warning(this, 
            tr("Repop Lairs"),
            tr("There is no game to operate on"));
        return;
    }

    bool ok = controller->refreshMemory();

    if (ok)
    {
        ok = game->validate();
        if (!ok)
        {
            (void)QMessageBox::warning(this,
                tr("Validate"),
                tr("The game failed validation"));
        }
    }

    if (!ok)
    {
        statusBar()->showMessage(tr("Game failed validation"));
    }
    else
    {
        statusBar()->showMessage(tr("Game checks out Ok"));
    }

    update();
}

void DialogTools::on_pushButton_ApplyBuildQueues_clicked()
{
    DialogBuildingQueues* dialog = new DialogBuildingQueues(MainWindow::getInstance());
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void DialogTools::on_pushButton_LbxEditor_clicked()
{
    DialogLbxEditor* dialog = new DialogLbxEditor(MainWindow::getInstance());
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void DialogTools::on_pushButton_RepopLairs_clicked()
{
    MainWindow* controller = MainWindow::getInstance();
	QMoMGamePtr game = getGame();
    if (game.isNull())
    {
        (void)QMessageBox::warning(this, 
            tr("Repop Lairs"),
            tr("There is no game to operate on"));
        return;
    }

    bool ok = controller->refreshMemory();

    if (ok)
    {
        MoM::MoMController momController(game.data());
        ok = momController.repopLairs(ui->checkBox_RepopMaxOut->isChecked());
        if (!ok)
        {
            (void)QMessageBox::warning(this, 
                tr("Repop Lairs"),
				tr("Failed to repop the lairs: %0").arg(momController.errorString().c_str()));
        }
    }

    if (ok)
    {
        ok = controller->commitMemory();
    }

    if (!ok)
    {
        statusBar()->showMessage(tr("Failed to repop Lairs"));
    }
    else
    {
        statusBar()->showMessage(tr("Lairs have been repopulated"));
    }

    update();
}

void DialogTools::on_pushButton_LucernMod_clicked()
{
    MainWindow* controller = MainWindow::getInstance();
	QMoMGamePtr game = getGame();
    if (game.isNull())
    {
        (void)QMessageBox::warning(this,
            tr("Lucern mod"),
            tr("There is no game to operate on"));
        return;
    }

    // Load FONTS.LBX (TODO: needs centralization)
    MoM::QMoMPalette colorTable(256);
    std::string fontsLbxFile = game->getGameDirectory() + "/" + "FONTS.LBX";
    MoM::MoMLbxBase fontsLbx;
    bool ok = fontsLbx.load(fontsLbxFile);
    if (ok)
    {
        const uint8_t* dataPalette = fontsLbx.getRecord(2);
        MoM::convertLbxToPalette(dataPalette, colorTable);
    }

    // Adjust color table for proper color matching
    colorTable.resize(244);
    colorTable[0] = qRgb(255, 0, 255);  // Treat MAGENTA RGB(255, 0, 255) as TRANSPARENT!
    colorTable[232] = qRgb(0, 255, 0);    // Treat GREEN RGB(0, 255, 0) as SHADOW (232 or 239??)

    // Load Centaur Scouts
    QMoMImagePtr image(new QImage);
    if (ok)
    {
        ok = image->load("UNITS2_000_000.png");
    }

    if (ok)
    {
        QImage saveImage = image->convertToFormat(QImage::Format_Indexed8, colorTable, Qt::AutoColor);

        // TODO: Remove verification
        saveImage.save("UNIT_Centaur_Scouts.png");
        std::cout << "pixel(1,5) = " << (int)saveImage.pixelIndex(1,5) << " pixel(1,6) = " << (int)saveImage.pixelIndex(1,6) << std::endl;
//        ui->label_Image->setPixmap(QPixmap::fromImage(saveImage));
    }

    // Load UNITS2.LBX
    std::string units2LbxFile = game->getGameDirectory() + "/" + "UNITS2.LBX";
    MoM::MoMLbxBase units2Lbx;
    if (ok)
    {
        ok = units2Lbx.load(units2LbxFile);
    }

    // Load FIGURES9.LBX
    std::string figuresLbxFile = game->getGameDirectory() + "/" + "FIGURES9.LBX";
    MoM::MoMLbxBase figuresLbx;
    if (ok)
    {
        ok = figuresLbx.load(figuresLbxFile);
    }

    // Replace UNITS2/0 by Lucern/FIGURES4_077_001
    const MoM::QMoMAnimation images(1, image);
    std::vector<uint8_t> dataBuffer;
    if (ok)
    {
        ok = MoM::convertImagesToLbx(images, dataBuffer, "LucernMod");
    }

    if (ok)
    {
        ok = units2Lbx.replaceRecord(0, dataBuffer);
    }

    // Replace FIGURES9/0-8 by Lucern/FIGURES4_072-079 (4 images each)
    for (int direction = 0; direction < 8; ++direction)
    {
        MoM::QMoMAnimation images(4);
        for (int movement = 0; movement < 4; ++movement)
        {
            QImage image;
            QString filename = QString("Lucern/Centaur Scouts/FIGURES4_%0_%1.png").arg(72 + direction, 3, 10, QChar('0')).arg(movement, 3, 10, QChar('0'));
            if (ok)
            {
                ok = image.load(filename);
            }
            if (ok)
            {
                images[movement] = QMoMImagePtr(new QImage(image.convertToFormat(QImage::Format_Indexed8, colorTable, Qt::AutoColor)));
            }
        }
        std::vector<uint8_t> dataBuffer;
        if (ok)
        {
            ok = MoM::convertImagesToLbx(images, dataBuffer, "LucernMod");
        }
        if (ok)
        {
            ok = figuresLbx.replaceRecord(0 + direction, dataBuffer);
        }
    }

    // Save UNITS2.LBX
    if (ok)
    {
        ok = units2Lbx.save(units2Lbx.getFilename());
    }

    // Save FIGURES9.LBX
    if (ok)
    {
        ok = figuresLbx.save(figuresLbx.getFilename());
    }

    if (!ok)
    {
        statusBar()->showMessage(tr("Failed to apply Lucern mod"));
    }
    else
    {
        statusBar()->showMessage(tr("Lucern mod applied"));
    }

    controller->update();
}

void DialogTools::on_pushButton_SelectInitialSpells_clicked()
{
    DialogSelectInitialSpells* dialog = new DialogSelectInitialSpells(MainWindow::getInstance());
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

QStatusBar* DialogTools::statusBar()
{
    MainWindow* mainWindow = MainWindow::getInstance();
	return mainWindow->statusBar();
}
