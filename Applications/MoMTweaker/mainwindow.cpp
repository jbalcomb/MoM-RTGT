// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

// Qt
#include <QImageWriter>
#include <QRegExp>
#include <QSettings>
#include <QTimer>
#include "mainwindow.h"
#include "ui_mainwindow.h"

// Standard C++ Library
#include <sstream>

// Library
#include <MoMCatnip.h>
#include <MoMController.h>
#include <MoMGameCustom.h>
#include <MoMGenerated.h>
#include <MoMLbxBase.h>
#include <MoMGameMemory.h>
#include <MoMProcess.h>
#include <MoMGameSave.h>
#include <MoMUtility.h>
#include <QMoMResources.h>
#include <QMoMSettings.h>

// TODO: Remove again
#include <QPainter>
#include <QMoMGifHandler.h>
#include <QMoMUnitTile.h>
#include <math.h>

// Local
#include "dialogaddunit.h"
#include "dialogcalculatoraddress.h"
#include "dialogmap.h"
#include "dialogtables.h"
#include "dialogtools.h"


MainWindow* MainWindow::m_instance = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_timerReread(new QTimer()),
    m_timerUpdateIcons(new QTimer()),
    m_UnitModel(this),
    m_filedialogLoadGame(this),
    m_filedialogSaveGame(this),
    m_game()
{
    ui->setupUi(this);

	m_instance = this;

    QStringList searchPaths(":/images");
    searchPaths.append(":/units");
    searchPaths.append(":/abilities");
    searchPaths.append(":/spells");
    searchPaths.append(":/race");
    searchPaths.append(":/wizards");
    QDir::setSearchPaths(QString("images"), searchPaths);

    m_filedialogLoadGame.setObjectName("filedialogLoadGame");
    m_filedialogLoadGame.setWindowTitle(tr("Open MoM file"));
    m_filedialogLoadGame.setNameFilter(tr("MoM files (*.insecticide* *.gam wizards*.exe magic*.exe builddat.lbx itemdata.lbx itempow.lbx spelldat.lbx terrstat.lbx);;SAVEn.GAM files (*.gam);;EXE files (wizards*.exe magic*.exe);;LBX files (*.lbx);;Memory dumps(*.insecticide*)"));
    m_filedialogSaveGame.setAcceptMode(QFileDialog::AcceptOpen);
    m_filedialogLoadGame.setFileMode(QFileDialog::ExistingFile);
    m_filedialogLoadGame.setViewMode(QFileDialog::Detail);

    m_filedialogSaveGame.setObjectName("filedialogSaveGame");
    m_filedialogSaveGame.setWindowTitle(tr("Save MoM file"));
    m_filedialogSaveGame.setNameFilter(tr("MoM files (*.gam wizards*.exe magic*.exe builddat.lbx itemdata.lbx itempow.lbx spelldat.lbx terrstat.lbx);;SAVEn.GAM files (*.gam);;EXE files (wizards*.exe magic*.exe);;LBX files (*.lbx);;Memory dumps(*.insecticide*)"));
    m_filedialogSaveGame.setAcceptMode(QFileDialog::AcceptSave);
    m_filedialogSaveGame.setFileMode(QFileDialog::AnyFile);
    m_filedialogSaveGame.setViewMode(QFileDialog::Detail);

    // CONFIG

    setFont(MoM::QMoMResources::g_Font);
    ui->treeView_MoM->setFont(MoM::QMoMResources::g_Font);

#ifdef _WIN32
    m_filedialogLoadGame.setDirectory("C:/GAMES/");
    m_filedialogSaveGame.setDirectory("C:/GAMES/");
#else // Linux
//    m_filedialogLoadGame.setDirectory("/media/C_DRIVE/GAMES/MAGIC-work/");
//    m_filedialogSaveGame.setDirectory("/media/C_DRIVE/GAMES/MAGIC-work/");
    QFont fontTreeView(MoM::QMoMResources::g_Font);
    fontTreeView.setPointSize(fontTreeView.pointSize() - 1);
    ui->treeView_MoM->setFont(fontTreeView);
#endif

    // Connect the item model UnitModel to the treeview
    // TODO: Move to new method in UnitModel
    ui->treeView_MoM->setModel(&m_UnitModel);

    // Read settings
    QMoMSettings::readSettingsWindow(this);

    QObject::connect(ui->treeView_MoM, SIGNAL(clicked(const QModelIndex &)), &m_UnitModel, SLOT(slot_selectionChanged(const QModelIndex &)));

    // Make internal connections to handle events centrally
    QObject::connect(this, SIGNAL(signal_gameChanged(QMoMGamePtr)), this, SLOT(slot_gameChanged(QMoMGamePtr)));
	QObject::connect(this, SIGNAL(signal_gameUpdated()), this, SLOT(slot_gameUpdated()));
    // Connect a timer to trigger refresh updates
    QObject::connect(m_timerReread.data(), SIGNAL(timeout()), this, SLOT(slot_timerReread()));
    QObject::connect(m_timerUpdateIcons.data(), SIGNAL(timeout()), this, SLOT(slot_timerUpdateIcons()));

    // Connect the item model UnitModel to signals from this class
	if (ui->checkBox_UpdateTree->isChecked())
	{
        QObject::connect(this, SIGNAL(signal_gameChanged(QMoMGamePtr)), &m_UnitModel, SLOT(slot_gameChanged(QMoMGamePtr)));
        QObject::connect(this, SIGNAL(signal_gameUpdated()), &m_UnitModel, SLOT(slot_gameUpdated()));
	}

    // Signal to start with an empty game
	emit signal_gameChanged(m_game);

	// Give the tree view a kick to display its contents
    // TODO: This should not be necessary
    m_UnitModel.slot_gameChanged(m_game);
    ui->treeView_MoM->update();

    // Start the timers
    m_timerReread->start(10000);
    m_timerUpdateIcons->start(100);
}

MainWindow::~MainWindow()
{
    QMoMSettings::writeSettingsWindow(this);

    delete ui;
}

QTreeWidgetItem* MainWindow::addTreeFeature(QTreeWidgetItem* parent, 
                                const QString& feature, const QIcon& featureIcon, 
                                const QString& value, const QIcon& valueIcon, 
                                const QString& comment)
{
    QStringList qFeature(feature);
    qFeature.append(value);
    qFeature.append(comment);
    QTreeWidgetItem* qtreeFeature = new QTreeWidgetItem(parent, qFeature);
    qtreeFeature->setIcon(0, featureIcon);
    qtreeFeature->setIcon(1, valueIcon);
    return qtreeFeature;
}

void MainWindow::addUnit(MoM::eUnit_Type unitType)
{
    if (m_game.isNull())
    {
        (void)QMessageBox::warning(this,
            tr("Summon"),
            tr("There is no game to operate on"));
        return;
    }

    bool ok = refreshMemory();

    if (ok)
    {
        MoM::MoMController momController(m_game.data());
        ok = momController.addUnit(MoM::PLAYER_YOU, unitType);
        if (!ok)
        {
            (void)QMessageBox::warning(this,
                tr("Summon"),
				tr("Failed to summon %0: %1").arg(prettyQStr(unitType)).arg(momController.errorString().c_str()));
        }
    }

    if (ok)
    {
        ok = commitMemory();
    }

    if (!ok)
    {
        statusBar()->showMessage(tr("Failed to summon"));
    }
    else
    {
        statusBar()->showMessage(tr("Summon complete"));
		emit signal_gameUpdated();
    }
}

void MainWindow::applyBuildQueues()
{
    if (m_game.isNull())
    {
        (void)QMessageBox::warning(this,
            tr("Apply Building Queues"),
            tr("There is no game to operate on"));
        return;
    }

    bool ok = refreshMemory();

    if (ok)
    {
        MoM::MoMController momController(m_game.data());
        ok = momController.applyBuildingQueue(MoM::PLAYER_YOU);
        if (!ok)
        {
            (void)QMessageBox::warning(this,
                tr("Apply Building Queues"),
				tr("Failed to apply the Building Queues: %0").arg(momController.errorString().c_str()));
        }
    }

    if (ok)
    {
        ok = commitMemory();
    }

    if (!ok)
    {
        statusBar()->showMessage(tr("Failed to apply Building Queues"));
    }
    else
    {
        statusBar()->showMessage(tr("Building Queues applied"));
		emit signal_gameUpdated();
    }
}

bool MainWindow::commitMemory()
{
    bool ok = true;
    QMoMGameMemoryPtr memGame = m_game.dynamicCast<MoM::MoMGameMemory>();
    if (0 != memGame)
    {
        ok = memGame->commitChanges();
        if (!ok)
        {
            (void)QMessageBox::warning(this, 
                tr("Commit memory"),
                tr("Failed to commit the data to process memory"));
        }
     }
    return ok;
}

bool MainWindow::refreshMemory()
{
    bool ok = true;
    if (!m_game.isNull())
    {
        ok = m_game->readData();
        if (!ok)
        {
            (void)QMessageBox::warning(this, 
                tr("Refresh Memory"),
                tr("Failed to reread the process memory"));
        }
    }
    return ok;
}

void MainWindow::update()
{
    std::string title = "MoM Real-Time Game Tweaker";
    if (!m_game.isNull())
    {
        title = m_game->getSources();
    }

    setWindowTitle(title.c_str());

    ui->pushButton_Reread->setEnabled(
            (0 != dynamic_cast<MoM::MoMGameMemory*>(m_game.data()))
            || (0 != dynamic_cast<MoM::MoMGameCustom*>(m_game.data()))
            );
    ui->pushButton_Save->setEnabled(0 != dynamic_cast<MoM::MoMGameSave*>(m_game.data()));
    ui->checkBox_UseIcons->setEnabled(ui->checkBox_UpdateTree->isChecked());
}

void MainWindow::on_pushButton_Connect_clicked()
{
    std::auto_ptr<MoM::MoMProcess> momProcess( new MoM::MoMProcess );

    bool ok = momProcess->findProcessAndData();
	QMoMGamePtr newGame;
    QMoMGameMemoryPtr memGame( new MoM::MoMGameMemory );
    QMoMGameCustomPtr customGame( new MoM::MoMGameCustom );
    if (ok && memGame->openGame(momProcess))
    {
		newGame = memGame.dynamicCast<MoM::MoMGameBase>();
    }
    else if (ok && customGame->openGame(momProcess))
    {
        newGame = customGame.dynamicCast<MoM::MoMGameBase>();
    }
    else
    {
        ok = false;
    }
    if (!ok)
    {
        statusBar()->showMessage(tr("Game connection failed"));
        (void)QMessageBox::warning(this,
            tr("Connect to MoM"),
            tr("Could not find MoM window"));
    }
    else
    {
        statusBar()->showMessage(tr("Game connected"));
    }

	if (ok)
	{
        emit signal_gameChanged(newGame);
	}
}

void MainWindow::on_pushButton_Load_clicked()
{
    if (!m_filedialogLoadGame.exec())
        return;

    QString fileName = m_filedialogLoadGame.selectedFiles().first();

    MoM::MoMLbxBase lbxFile;
    QMoMGamePtr newGame;

    statusBar()->showMessage(tr("Loading game..."));

    QMoMGameSavePtr saveGame( new MoM::MoMGameSave );
    QMoMGameMemoryPtr memoryGame = m_game.dynamicCast<MoM::MoMGameMemory>();
    bool ok = saveGame->load(fileName.toAscii());
    if (ok)
    {
        newGame = saveGame.dynamicCast<MoM::MoMGameBase>();
    }
    else if (memoryGame)
    {
        ok = memoryGame->load(fileName.toAscii());
        if (ok)
        {
            newGame = memoryGame.dynamicCast<MoM::MoMGameBase>();
        }
    }
    else
    {
    }

    if (!ok)
    {
        statusBar()->showMessage(tr("Failed to load game"));
        (void)QMessageBox::warning(this,
            tr("Load MoM game"),
            tr("Could not load MoM game '%1'").arg(fileName));
    }
    else
    {
        statusBar()->showMessage(tr("Game loaded"));
    }

	emit signal_gameChanged(newGame);
}

void MainWindow::on_pushButton_Save_clicked()
{
    bool ok = true;
    QMoMGameSavePtr saveGame = m_game.dynamicCast<MoM::MoMGameSave>();
    QMoMGameMemoryPtr memoryGame = m_game.dynamicCast<MoM::MoMGameMemory>();
    if (saveGame && m_game->isOpen())
    {
        if (!m_filedialogSaveGame.exec())
        {
            return;
        }

        QString fileName = m_filedialogSaveGame.selectedFiles().first();
        ok = saveGame->save(fileName.toAscii());
        if (!ok)
        {
            (void)QMessageBox::warning(this,
                tr("Save MoM file"),
                tr("Failed to save MoM game '%1'").arg(fileName));
        }
    }
    else if (memoryGame && m_game->isOpen())
    {
        if (!m_filedialogSaveGame.exec())
        {
            return;
        }

        QString fileName = m_filedialogSaveGame.selectedFiles().first();
        ok = memoryGame->save(fileName.toAscii());
        if (!ok)
        {
            (void)QMessageBox::warning(this,
                tr("Save MoM memory"),
                tr("Failed to save MoM game '%1'").arg(fileName));
        }
    }
    else
    {
        (void)QMessageBox::warning(this, 
            tr("Save MoM game"),
            tr("There is nothing to save"));
        ok = false;
    }


    if (!ok)
    {
        statusBar()->showMessage(tr("Failed to save game"));
    }
    else
    {
        statusBar()->showMessage(tr("Game saved"));
    }
}

void MainWindow::on_pushButton_Reread_clicked()
{
    if (m_game.isNull())
        return;

    bool ok = m_game->readData();
    if (!ok)
    {
        statusBar()->showMessage(tr("Reread failed"));
    }
    else
    {
        statusBar()->showMessage(tr("Reread completed"));
		emit signal_gameUpdated();
    }
}

void MainWindow::slot_timerReread()
{
    if (m_game.isNull() || (0 != dynamic_cast<MoM::MoMGameSave*>(m_game.data())))
        return;

    bool ok = m_game->readData();
    if (!ok)
    {
        statusBar()->showMessage(tr("Reread failed"), 200);
    }
    else
    {
        statusBar()->showMessage(tr("Reread completed"), 200);
    }
	if (ok && ui->checkBox_ApplyBuildQueues->isChecked())
	{
		applyBuildQueues();
	}
	if (ok)
	{
		emit signal_gameUpdated();
    }
}

void MainWindow::slot_timerUpdateIcons()
{
    if (ui->checkBox_UpdateTree->isChecked() && ui->checkBox_UseIcons->isChecked())
    {
        m_UnitModel.updateFirstUnresolvedIcon();
    }
}

void MainWindow::on_pushButton_AddUnit_clicked()
{
    MoM::DialogAddUnit* dialog = new MoM::DialogAddUnit(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);

    // Connect the item model UnitModel to the dialog
    QObject::connect(&m_UnitModel, SIGNAL(signal_unitChanged(QMoMUnitPtr)), dialog, SLOT(slot_unitChanged(QMoMUnitPtr)));

    dialog->show();
}

void MainWindow::on_pushButton_Calculator_clicked()
{
    DialogCalculatorAddress* dialog = new DialogCalculatorAddress(MainWindow::getInstance());
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    QObject::connect(&m_UnitModel, SIGNAL(signal_addressChanged(const void*)), dialog, SLOT(slot_addressChanged(const void*)));
    dialog->show();
}

void MainWindow::on_pushButton_ShowTables_clicked()
{
    DialogTables* dialog = new DialogTables(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void MainWindow::on_pushButton_Map_clicked()
{
    MoM::DialogMap* dialog = new MoM::DialogMap(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void MainWindow::on_pushButton_CatnipMod_clicked()
{
    MainWindow* controller = MainWindow::getInstance();
    QMoMGamePtr game = getGame();
    if (game.isNull())
    {
        (void)QMessageBox::warning(this,
            tr("Catnip mod"),
            tr("There is no game to operate on"));
        return;
    }

//    MOM_FOREACH(eUnit_Type, unitTypeNr, eUnit_Type_MAX)
//    {
//        int unitNr = 999;
//        MoM::Unit* unit = game->getUnit(unitNr);
//        if (0 == unit)
//            return;
//        memset(unit, '\0', sizeof(MoM::Unit));
//        unit->m_Unit_Type = unitTypeNr;
//        unit->m_Hero_Slot_Number = -1;

//        MoM::Unit_Type_Data* unitType = game->getUnitTypeData(unit->m_Unit_Type);
//        if (0 == unitType)
//            return;

//        MoM::Battle_Unit battleUnit = { 0 };
//        memcpy(&battleUnit.m_Melee, &unitType->m_Melee, sizeof(MoM::Unit_Type_Data) - offsetof(MoM::Unit_Type_Data, m_Melee));
//        battleUnit.m_unitNr = unitNr;
//        battleUnit.m_xPos = 0;
//        battleUnit.m_yPos = 0;

//        QMoMUnitPtr momUnit = QMoMUnitPtr(new MoM::MoMUnit(game.data()));
//        qDebug() << "momUnit empty" << momUnit->getDisplayName().c_str();
//        momUnit->changeUnit(&battleUnit);
//        qDebug() << "momUnit" << momUnit->getDisplayName().c_str();

//        MoM::QMoMUnitTile unitTile(true);
//        unitTile.setGame(game);
//        unitTile.setUnit(momUnit);
//        QRectF rect = unitTile.boundingRect();
//        qDebug() << "unitTile rect" << rect;
//        const int arrFrameNr[10] = {1,0,1,2,1,0,1,2,3,1};
//        QMoMAnimation animation;
//        for (int heading = 2; heading < 10; ++heading)
//        for (int frame = 0; frame < 10; ++frame)
//        {
//            unitTile.setFrameNr(arrFrameNr[frame]);
//            int step = MoM::Min(frame, 8);

//            double angle = (heading - 3) * 3.14159 / 4;
//            int dx = MoM::Round(cos(angle));
//            int dy = MoM::Round(sin(angle));
//            battleUnit.m_xPosHeaded = dx;
//            battleUnit.m_yPosHeaded = dy;
//            qDebug("heading %d %d,%d", heading, battleUnit.m_xPosHeaded, battleUnit.m_yPosHeaded);

//            QMoMImagePtr image(new QImage(rect.width() * 4, rect.height() * 4, QImage::Format_RGB32));
//            qDebug() << "numColors" << image->numColors();

//            MoM::QMoMPalette colorTable = MoM::QMoMResources::instance().getColorTable();
//            colorTable.resize(244);
//            colorTable[0] = qRgb(255, 0, 255);                  // Treat MAGENTA RGB(255, 0, 255) as TRANSPARENT (0)!
//            colorTable[MoM::gSHADOW_COLOR] = qRgb(0, 255, 0);   // Treat GREEN RGB(0, 255, 0) as SHADOW (232)

//            QRgb rgbTransparent = colorTable[0];
//            qDebug() << "rgbTransparent" << rgbTransparent;
//            image->fill(rgbTransparent);
//            QPainter painter(image.data());
//            qDebug() << "translate";
//            painter.translate(rect.width() * 2, rect.height() * 3);
//            qDebug() << "paint terrain";
//            const QMoMImagePtr imageTerrain = MoM::QMoMResources::instance().getImage(MoM::TERRAINBATTLE_firstbasic);
//            if (0 != imageTerrain)
//            {
//                QRectF rectTerrain(-30/2, -16, 30, 16);
//                rectTerrain.translate(-(dx - dy) * (step) * 16 / 8, -(dx + dy) * (step) * 8 / 8 );
//                painter.drawImage(rectTerrain, *imageTerrain);
//                if (step != 0)
//                {
//                    rectTerrain.translate((dx - dy) * 16, (dx + dy) * 8 );
//                    painter.drawImage(rectTerrain, *imageTerrain);
//                }
//            }


//            qDebug() << "paint unit";
//            unitTile.paint(&painter, NULL, NULL);
//            painter.end();

//            image = QMoMImagePtr(new QImage(image->convertToFormat(QImage::Format_Indexed8, colorTable, Qt::AutoColor)));
//            image->setColorTable(MoM::QMoMResources::instance().getColorTable());
//            animation.append(image);

//            qDebug() << "setPixmap";
//            ui->label->setPixmap(QPixmap::fromImage(*image));
//        }

//        QString title = "Tactical_" + QString(momUnit->getDisplayName().c_str()).replace(QRegExp("[^A-Za-z0-9]"), "");
//        QString testFilenameWrite = "C:\\GAMES\\Klaas_Master_of_Magic\\LBX\\gif\\_crop\\Units\\" + title + ".gif";
//        qDebug() << "Opening file " << testFilenameWrite << " to write to";
//        QFile testFileWrite(testFilenameWrite);
//        qDebug() << "exists() -> " << testFileWrite.exists();
//        bool result = testFileWrite.open(QFile::WriteOnly | QFile::Truncate);
//        qDebug() << "open(WriteOnly | Truncate) -> " << result;

//        QMoMGifHandler gifHandlerWrite;
//        gifHandlerWrite.setDevice(&testFileWrite);
//        if (!animation.empty())
//        {
//            animation.crop();
//            animation.scale(2.0);
//            gifHandlerWrite.setAnimationOption(QMoMGifHandler::Disposal, QMoMGifHandler::DisposalBackground);
//            gifHandlerWrite.setAnimationOption(QMoMGifHandler::Delay, 20);
//            result = gifHandlerWrite.writeAnimation(animation);
//        }
//        qDebug() << "gifHandler.writeAnimation(animation) -> " << result;
//    }

    return;


    MoM::MoMCatnip catnip;

    bool ok = catnip.apply(game.data());
    if (!ok)
    {
        statusBar()->showMessage(tr("Failed to apply Catnip mod"));
        (void)QMessageBox::warning(this,
            tr("Catnip mod"),
            catnip.errorString().c_str());
    }
    else
    {
        statusBar()->showMessage(tr("Catnip mod applied"));
        (void)QMessageBox::warning(this,
            tr("Catnip mod"),
            tr( "Catnip mod applied\n"
                "\n"
                "1. All units have an additional half move\n"
                "2. The heroes have alternative slots (and a couple of changes)\n"
                "3. Magicians, priests, and shamen have been renamed and have different abilities\n"
            ));
    }

    controller->update();
}

void MainWindow::on_pushButton_Tools_clicked()
{
    DialogTools* dialog = new DialogTools(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void MainWindow::on_checkBox_UpdateTree_clicked()
{
	if (ui->checkBox_UpdateTree->isChecked())
    {
	    // Connect the item model UnitModel to signals from this class
		QObject::connect(this, SIGNAL(signal_gameChanged(QMoMGamePtr)), &m_UnitModel, SLOT(slot_gameChanged(QMoMGamePtr)));
		QObject::connect(this, SIGNAL(signal_gameUpdated()), &m_UnitModel, SLOT(slot_gameUpdated()));
		statusBar()->showMessage(tr("Updating Treeview..."));
	    m_UnitModel.slot_gameChanged(m_game);
        statusBar()->showMessage(tr("Treeview updated"));
	}
	else
	{
	    // Disconnect the item model UnitModel to signals from this class
		QObject::disconnect(this, SIGNAL(signal_gameChanged(QMoMGamePtr)), &m_UnitModel, SLOT(slot_gameChanged(QMoMGamePtr)));
		QObject::disconnect(this, SIGNAL(signal_gameUpdated()), &m_UnitModel, SLOT(slot_gameUpdated()));
        statusBar()->showMessage(tr("Treeview is not updated anymore"));
	}
    update();
}

void MainWindow::slot_gameChanged(const QMoMGamePtr& game)
{
    m_game = game;

	// TODO: Resources should be loaded centrally...
	// Load resources
    MoM::QMoMResources::instance().setGame(m_game);

	update();
}

void MainWindow::slot_gameUpdated()
{
	update();
}