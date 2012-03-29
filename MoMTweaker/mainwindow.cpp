// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

// OS specific
#ifdef _WIN32
#include <windows.h>
#endif

#include <QImageWriter>
#include <QRegExp>
#include <qtimer.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

// Standard C++ Library
#include <sstream>

// Library
#include <MoMController.h>
#include <MoMGameCustom.h>
#include <MoMGenerated.h>
#include <MoMLbxBase.h>
#include <MoMGameMemory.h>
#include <MoMProcess.h>
#include <MoMGameSave.h>
#include <MoMUtility.h>
#include <QMoMResources.h>

// Local
#include "dialogaddunit.h"
#include "dialogoverlandmap.h"
#include "dialogtables.h"
#include "dialogtools.h"


MainWindow* MainWindow::m_instance = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_timer(new QTimer()),
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

    m_filedialogLoadGame.setWindowTitle(tr("Open MoM file"));
    m_filedialogLoadGame.setNameFilter(tr("MoM files (*.gam wizards*.exe magic*.exe builddat.lbx spelldat.lbx terrstat.lbx);;SAVEn.GAM files (*.gam);;EXE files (wizards*.exe magic*.exe);;LBX files (*.lbx)"));
    m_filedialogSaveGame.setAcceptMode(QFileDialog::AcceptOpen);
    m_filedialogLoadGame.setFileMode(QFileDialog::ExistingFile);
    m_filedialogLoadGame.setViewMode(QFileDialog::Detail);

    m_filedialogSaveGame.setWindowTitle(tr("Save MoM file"));
    m_filedialogSaveGame.setNameFilter(tr("MoM files (*.gam wizards*.exe magic*.exe builddat.lbx spelldat.lbx terrstat.lbx);;SAVEn.GAM files (*.gam);;EXE files (wizards*.exe magic*.exe);;LBX files (*.lbx)"));
    m_filedialogSaveGame.setAcceptMode(QFileDialog::AcceptSave);
    m_filedialogSaveGame.setFileMode(QFileDialog::AnyFile);
    m_filedialogSaveGame.setViewMode(QFileDialog::Detail);

    // CONFIG

    setFont(MoM::QMoMResources::g_Font);
    ui->treeView_MoM->setFont(MoM::QMoMResources::g_Font);

    // TODO: Load and save config
#ifdef _WIN32
    m_filedialogLoadGame.setDirectory("C:/games/MAGIC-work/");
    m_filedialogSaveGame.setDirectory("C:/games/MAGIC-work/");
#else // Linux
    m_filedialogLoadGame.setDirectory("/media/C_DRIVE/GAMES/MAGIC-work/");
    m_filedialogSaveGame.setDirectory("/media/C_DRIVE/GAMES/MAGIC-work/");
    QFont fontTreeView(MoM::QMoMResources::g_Font);
    fontTreeView.setPointSize(fontTreeView.pointSize() - 1);
    ui->treeView_MoM->setFont(fontTreeView);
#endif

    // Connect the item model UnitModel to the treeview
    // TODO: Move to new method in UnitModel
    ui->treeView_MoM->setModel(&m_UnitModel);
    QObject::connect(ui->treeView_MoM, SIGNAL(clicked(const QModelIndex &)), &m_UnitModel, SLOT(slot_selectionChanged(const QModelIndex &)), Qt::QueuedConnection);

    // Make internal connections to handle events centrally
    QObject::connect(this, SIGNAL(signal_gameChanged(QMoMGamePtr)), this, SLOT(slot_gameChanged(QMoMGamePtr)));
	QObject::connect(this, SIGNAL(signal_gameUpdated()), this, SLOT(slot_gameUpdated()));
    // Connect a timer to trigger refresh updates
    QObject::connect(m_timer, SIGNAL(timeout()), this, SLOT(slot_timer()));

    // Connect the item model UnitModel to signals from this class
	if (ui->checkBox_UpdateTree->isChecked())
	{
        QObject::connect(this, SIGNAL(signal_gameChanged(QMoMGamePtr)), &m_UnitModel, SLOT(slot_gameChanged(QMoMGamePtr)), Qt::QueuedConnection);
        QObject::connect(this, SIGNAL(signal_gameUpdated()), &m_UnitModel, SLOT(slot_gameUpdated()), Qt::QueuedConnection);
	}

    // Signal to start with an empty game
	emit signal_gameChanged(m_game);

	// Give the tree view a kick to display its contents
    // TODO: This should not be necessary
    m_UnitModel.slot_gameChanged(m_game);
    ui->treeView_MoM->update();

	// Start the timer
    m_timer->start(10000);
}

MainWindow::~MainWindow()
{
    delete m_timer;

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
		MoM::MoMController momController;
		ok = momController.addUnit(*m_game, MoM::PLAYER_YOU, unitType);
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
		MoM::MoMController momController;
        ok = momController.applyBuildingQueue(*m_game, MoM::PLAYER_YOU);
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

    /*
    MoM::Wizard& wizard = m_game->getWizard(playerNr);
    char buf[4096];
    for (int hireNr = 0; hireNr < MoM::gMAX_HIRED_HEROES; ++hireNr)
    {
        MoM::Hired_Hero& hiredHero = wizard.m_Heroes_hired_by_wizard[hireNr];
        if (-1 == hiredHero.m_Unit_Nr)
        {
            continue;
        }

        MoM::Unit& unit = m_game->getUnit(hiredHero.m_Unit_Nr);
        MoM::Hero_stats& heroStats = m_game->getHero_stats(playerNr, unit.m_Unit_Type);
        MoM::Unit_Data* pHeroData = m_game->getUnit_Data(unit.m_Unit_Type);

        QString featurePrefix;

        //
        // HIRED HERO
        //

        QStringList qHero(hiredHero.m_Hero_name);
        qHero.append(QString("the %1").arg(toQStr(unit.m_Unit_Type)));
        QTreeWidgetItem* qtreeHero = new QTreeWidgetItem((QTreeWidget*)0, qHero);
        if ((size_t)unit.m_Unit_Type < ARRAYSIZE(gUnitTypeImage))
        {
            qtreeHero->setIcon(0, QIcon(gUnitTypeImage[unit.m_Unit_Type]));
        }
        QFont font = qtreeHero->font(0);
        font.setPointSize(14);
        qtreeHero->setFont(0, font);
        qtreeHero->setFont(1, font);
        
        featurePrefix = tr("HH.");

        addTreeFeature(qtreeHero, 
            tr("Unit.Level(XP)"), 
            QIcon(),
            QString("%1 (%2)").arg(1 + unit.m_Level).arg(unit.m_Experience), 
            QIcon(":/images/grandlord.gif"));

        QTreeWidgetItem* qtreeHHFields
            = new QTreeWidgetItem(qtreeHero, QStringList(tr("Hired Hero.Fields")));

        ADDMFIELDFEATURE(qtreeHHFields, hiredHero, Hero_name);
        ADDMFIELDFEATURE(qtreeHHFields, (int)hiredHero, Unit_Nr);

        for (int itemSlotNr = 0; itemSlotNr < 3; ++itemSlotNr)
        {
            QTreeWidgetItem* qtreeItem
                = addTreeFeature(qtreeHHFields, 
                    tr("HH.Item %1").arg(1 + itemSlotNr), 
                    QIcon(),
                    toQStr(hiredHero.m_Slot_Types[itemSlotNr]), 
                    QIcon());

            if (-1 != hiredHero.m_Items_In_Slot[itemSlotNr])
            {
                MoM::Item& item = m_game->getItem(hiredHero.m_Items_In_Slot[itemSlotNr]);

                ADDMFIELDFEATURE(qtreeItem, item, Item_Name);
                ADDMFIELDFEATURE(qtreeItem, item, Icon);
                ADDMFIELDFEATURE(qtreeItem, item, Slot_Required);
                ADDMFIELDFEATURE(qtreeItem, item, Item_Type);
                ADDMFIELDFEATURE(qtreeItem, item, Cost);

                ADDFIELDFEATURE(qtreeItem, (int)item.m_Bonuses, Attack);
                ADDFIELDFEATURE(qtreeItem, (int)item.m_Bonuses, To_Hit);
                ADDFIELDFEATURE(qtreeItem, (int)item.m_Bonuses, Defense);
                ADDFIELDFEATURE(qtreeItem, (int)item.m_Bonuses, Movement_in_halves);
                ADDFIELDFEATURE(qtreeItem, (int)item.m_Bonuses, Resistance);
                ADDFIELDFEATURE(qtreeItem, (int)item.m_Bonuses, Spell_Points);
                ADDFIELDFEATURE(qtreeItem, -(int)item.m_Bonuses, Spell_Save);

                ADDMFIELDFEATURE(qtreeItem, item, Spell_Number_Charged);
                ADDMFIELDFEATURE(qtreeItem, item, Number_Of_Charges);

                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Vampiric);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Guardian_Wind);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Lightning);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Cloak_Of_Fear);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Destruction);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Wraith_Form);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Regeneration);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Pathfinding);

                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Water_Walking);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Resist_Elements);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Elemental_Armour);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Doom_equals_Chaos);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Stoning);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Endurance);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Haste);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Invisibility);

                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Death);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Flight);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Resist_Magic);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Magic_Immunity);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Flaming);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Holy_Avenger);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, True_Sight);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Phantasmal);

                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Power_Drain);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Bless);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, LionHeart);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Giant_Strength);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Planar_Travel);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Merging);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Righteousness);
                ADDFLAGFEATURE(qtreeItem, item.m_Bitmask_Powers, Invulnerability);
            }
        }

        //
        // UNITS
        //

        featurePrefix = tr("U.");

        QTreeWidgetItem* qtreeUFields
            = new QTreeWidgetItem(qtreeHero, QStringList(tr("Unit.Fields")));

        ADDMFIELDFEATURE(qtreeUFields, (int)unit, XPos);
        ADDMFIELDFEATURE(qtreeUFields, (int)unit, YPos);
        ADDMFIELDFEATURE(qtreeUFields, unit, Plane);
        ADDMFIELDFEATURE(qtreeUFields, unit, Owner);

        ADDMFIELDFEATURE(qtreeUFields, (int)unit, Moves_Total);
        ADDMFIELDFEATURE(qtreeUFields, unit, Unit_Type);
        ADDMFIELDFEATURE(qtreeUFields, (int)unit, Hero_Slot_Number);
        ADDMFIELDFEATURE(qtreeUFields, unit, Active);
        ADDMFIELDFEATURE(qtreeUFields, (int)unit, Moves_Left);
        ADDMFIELDFEATURE(qtreeUFields, (int)unit, XPos_of_destination);
        ADDMFIELDFEATURE(qtreeUFields, (int)unit, YPos_of_destination);
        ADDMFIELDFEATURE(qtreeUFields, unit, Status);
        ADDMFIELDFEATURE(qtreeUFields, (int)unit, Level);
        ADDMFIELDFEATURE(qtreeUFields, unit, Experience);
        //int8_t      m_Guess_Lifedrain_Damage;
        ADDMFIELDFEATURE(qtreeUFields, (int)unit, Damage);
        ADDMFIELDFEATURE(qtreeUFields, (unsigned)unit, Grouping);
        //int8_t      m_Guess_Combat_Enchantment_Flag[3];
        ADDMFIELDFEATURE(qtreeUFields, (unsigned)unit, Scouting);
        ADDMFIELDFEATURE(qtreeUFields, (int)unit, Road_Building_left_to_complete);
        //int8_t      m_Road_Building_parms[3];

        addTreeFeature(qtreeUFlags, 
            tr("U.Weapon type"), 
            QIcon(),
            toQStr((MoM::eWeaponType)unit.m_Weapon_Mutation.s.Weapon_Type), 
            QIcon());
    }
    */

    ui->pushButton_Reread->setEnabled(
            (0 != dynamic_cast<MoM::MoMGameMemory*>(m_game.data()))
            || (0 != dynamic_cast<MoM::MoMGameCustom*>(m_game.data()))
            );
    ui->pushButton_Save->setEnabled(0 != dynamic_cast<MoM::MoMGameSave*>(m_game.data()));
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
//		if (ui->checkBox_UpdateTree->isChecked())
//		{
//			statusBar()->showMessage(tr("Updating treeview ..."));
//			m_UnitModel.setGame(m_game.get());
//		}
        statusBar()->showMessage(tr("Game connected"));
    }

	if (ok)
	{
        emit signal_gameChanged(newGame);
	}

    if (ok)
    {
        (void) QMessageBox::warning(this,
            tr("Master of Magic Real-Time Game Tweaker"),
            tr( "Changes to WIZARDS.EXE and MAGIC.EXE.\n"
                "\n"
                "Some of the changes you may make on a connected game HAVE to be saved in a .EXE file to take effect.\n"
                "Please be aware of this and make a backup of WIZARDS.EXE and MAGIC.EXE to be safe.\n"
                "Currently no confirmation is asked before changing an .EXE file.\n"
                "\n"
                "This is only relevant if you connect to a game and make changes in sections marked 'MODIFIES Wizards.exe' or 'MODIFIES Magic.exe'."));
    }
}

void MainWindow::on_pushButton_Load_clicked()
{
    if (!m_filedialogLoadGame.exec())
        return;

    QString fileName = m_filedialogLoadGame.selectedFiles().first();

    MoM::MoMLbxBase lbxFile;
    QMoMGameSavePtr saveGame( new MoM::MoMGameSave );

    statusBar()->showMessage(tr("Loading game..."));

    bool ok = saveGame->load(fileName.toAscii());
    if (!ok)
    {
        statusBar()->showMessage(tr("Failed to load game"));
        (void)QMessageBox::warning(this,
            tr("Load MoM SAVEn.GAM"),
            tr("Could not load MoM game '%1'").arg(fileName));
    }
    else
    {
        statusBar()->showMessage(tr("Game loaded"));
    }

	QMoMGamePtr newGame = saveGame.dynamicCast<MoM::MoMGameBase>();
	emit signal_gameChanged(newGame);
}

void MainWindow::on_pushButton_Save_clicked()
{
    QMoMGameSavePtr saveGame = m_game.dynamicCast<MoM::MoMGameSave>();
    if ((saveGame.isNull()) || !saveGame->isOpen())
    {
        (void)QMessageBox::warning(this, 
            tr("Save MoM SAVEn.GAM"),
            tr("Can only save a game that has been loaded first"));
        return;
    }

    if (!m_filedialogSaveGame.exec())
    {
        return;
    }

    QString fileName = m_filedialogSaveGame.selectedFiles().first();
    bool ok = saveGame->save(fileName.toAscii());
    if (!ok)
    {
        (void)QMessageBox::warning(this,
            tr("Save MoM SAVEn.GAM"),
            tr("Failed to save MoM game '%1'").arg(fileName));
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

void MainWindow::slot_timer()
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

void MainWindow::on_pushButton_AddUnit_clicked()
{
    DialogAddUnit* dialog = new DialogAddUnit(this, &m_UnitModel);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
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
    DialogOverlandMap* dialog = new DialogOverlandMap(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

// TODO: Centralize
MoM::eHero_TypeCode heroTypeCode(MoM::eSlot_Type16 slotSword, MoM::eSlot_Type16 slotShield, MoM::eSlot_Type16 slotRing)
{
    unsigned codeSword = static_cast<unsigned>(slotSword) - 1;
    unsigned codeShield = static_cast<unsigned>(slotShield) - 1;
    unsigned codeRing = static_cast<unsigned>(slotRing) - 1;
    unsigned slotCode = 6 + codeSword + 6 *(codeShield + 6 * codeRing);
    return static_cast<MoM::eHero_TypeCode>(slotCode);
}

// TODO: Centralize
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

    bool ok = controller->refreshMemory();

    if (ok)
    {
        // Update set_hero_slots() based on hero_type
        // Target is that a hero_type of 0-3 works as before (Fig, Bow, FigWiz, Wiz) -> (1-5-6, 2-5-6, 3-5-6, 4-6-6)
        // But that otherwise the hero_type can be of the form 0x0RQP, where P, Q, R are the 3 slots-types (1-6)
        // This means that a hero_type of 0x0652 is equivalent to a hero_type of 1 (Bow), yielding Bow-Armor-Ring

        static uint8_t new_set_hero_slots[] =
        {
//                8                      ; int __cdecl __far set_hero_slot_types(int unitType, int hero_slot_types)
//                9 0000                     set_hero_slot_types      proc far       ; CODE XREF: j_set_hero_slot_types
//               10
//               11       =0006              unitType               = word ptr  6
//               12       =0008              hero_slot_types        = word ptr  8
//               13
//               14       =01AB              offset_hero_type       = 01ABh
//               15       =SI                si_hero_slot_types     = si
//               16       =CX                cx_unitType            = cx
//               17
//               18                      ; ovr130:0000
          0x55,                         // 0000  push   bp
          0x8B,  0xEC,                  // 0001  mov    bp,    sp
          0x56,                         // 0003  push   si_hero_slot_types
          0x8B,  0x4E, 0x06,            // 0004  mov    cx_unitType, [bp+unitType]
          0x8B,  0x76, 0x08,            // 0007  mov    si_hero_slot_types,    [bp+hero_slot_types]
          0x8B,  0xC1,                  // 000A  mov    ax,    cx_unitType
          0xBA,  0x24, 0x00,            // 000C  mov    dx,    24h
          0xF7,  0xEA,                  // 000F  imul   dx
          0x8B,  0xD8,                  // 0011  mov    bx,    ax
//               28
//               29                      ; ovr130:0013
          0x8A,  0x87, 0xAB, 0x01,      // 0013  mov   al, offset_hero_type[bx]   ;    AX = 0-3 as before, or 6 + P + 6 * (Q + 6 * R), where P,Q,R are the slot-types - 1
          0x32,  0xE4,                  // 0017  xor   ah, ah
          0x3D,  0x06, 0x00,            // 0019  cmp   ax, 6
          0x7D,  0x16,                  // 001C  jge   new_method
//               35
          0x40,                         // 001E  inc   ax
          0x89,  0x04,                  // 001F  mov   [si], ax         ; Set slot1 to 1-4 (Sword, Bow, Sword/Staff, Staff)
          0xBA,  0x05, 0x00,            // 0021  mov   dx, 5
          0x89,  0x54, 0x02,            // 0024  mov   [si+2], dx       ; Set slot2 to 5 (Armor)
          0x42,                         // 0027  inc   dx
          0x89,  0x54, 0x04,            // 0028  mov   [si+4], dx       ; Set slot3 to 6 (Ring)
          0x3C,  0x04,                  // 002B  cmp   al, 4
          0x75,  0x21,                  // 002D  jnz   done
          0x89,  0x54, 0x02,            // 002F  mov   [si+2], dx       ; If AX is 4 (Wizard), overrule slot2 to 6 (Ring)
          0xEB,  0x1C,                  // 0032  jmp   short done
//               46
//               47 0034                 new_method:
          0xB1,  0x06,                  // 0034  mov   cl, 6
          0x2A,  0xC1,                  // 0036  sub   al, cl           ; AX = P + 6 * (Q + 6 * R), where P,Q,R are the slot-types - 1
          0x99,                         // 0038  cwd
          0xF6,  0xF9,                  // 0039  idiv  cl               ; AH = P, AL = Q + 6 * R
          0x8A,  0xD4,                  // 003B  mov   dl, ah
          0x42,                         // 003D  inc   dx
          0x89,  0x14,                  // 003E  mov   [si], dx         ; Set slot 1 to <P>
          0x32,  0xE4,                  // 0040  xor   ah, ah
          0xF6,  0xF9,                  // 0042  idiv  cl               ; AH = Q, AL = R
          0x8A,  0xD4,                  // 0044  mov   dl, ah
          0x42,                         // 0046  inc   dx
          0x89,  0x54, 0x02,            // 0047  mov   [si+2], dx       ; Set slot 2 to <Q>
          0x8A,  0xD0,                  // 004A  mov   dl, al
          0x42,                         // 004C  inc   dx
          0x89,  0x54, 0x04,            // 004D  mov   [si+4], dx       ; Set slot 3 to <R>
//               63
//               64 0050                 done:
          0x5E,                         // 0050  pop   si
          0x5D,                         // 0051  pop   bp
          0xCB,                         // 0052  retf
//               68
//               69                      ; nops
//               70 0053                         endp

                // ...          nops
                //              endp
                // ovr130:0071
        };

        uint8_t* code = game->getWizardsOverlay(130);

        if (0 != code)
        {
            memcpy(code, new_set_hero_slots, sizeof(new_set_hero_slots));
            memset(code + sizeof(new_set_hero_slots), '\0', 0x0071 - sizeof(new_set_hero_slots));

            ok = game->commitData(code, code, 0x0071);
        }
    }

    // Set hero attributes
    if (ok)
    {
        // HEROES2
        // Copied from http://realmsbeyond.net/forums/showthread.php?t=4303 at 2012-03-25
        //

        // TODO: W/B=Warrior/Bow???
        // TODO: specials

        MoM::Unit_Type_Data* data = 0;

        //Barbarian      0     -     -     -     -     -     -     -     -     -
        // specials: Thrown 3, Blade Master
        //  item slots: W+W+A
        //   spells:
        data = game->getUnit_Type_Data(MoM::UNITTYPE_Barbarian);
        data->m_Hero_TypeCode_or_Building2 = heroTypeCode(MoM::SLOT16_Sword, MoM::SLOT16_Sword, MoM::SLOT16_Armor_Shield);

        //Bard           0     -     -     -     -     -     -     -     -     -
        // specials: Legendary, Charmed, Lucky
        //  item slots: W+A+R
        //   spells:
        data = game->getUnit_Type_Data(MoM::UNITTYPE_Bard);
        data->m_Hero_TypeCode_or_Building2 = heroTypeCode(MoM::SLOT16_Sword, MoM::SLOT16_Armor_Shield, MoM::SLOT16_Amulet);

        //Beastmaster    0     -     -     -     -     -     -     -     -     -
        // specials: Pathfinding, caster 5
        //  item slots: W+A+R
        //   spells:
        data = game->getUnit_Type_Data(MoM::UNITTYPE_Beastmaster);
        data->m_Hero_TypeCode_or_Building2 = heroTypeCode(MoM::SLOT16_Sword, MoM::SLOT16_Armor_Shield, MoM::SLOT16_Amulet);

        //Dervish        0     -     -     -     -     -     -     -     -     -
        // specials: Noble, 1x Random
        //  item slots: W/B+W+R
        //   spells:
        // TODO: Warrior/Bow???
        data = game->getUnit_Type_Data(MoM::UNITTYPE_Dervish);
        data->m_Hero_TypeCode_or_Building2 = heroTypeCode(MoM::SLOT16_Bow, MoM::SLOT16_Sword, MoM::SLOT16_Amulet);

        //Dwarf          0     -     -     -     -     -     -     -     -     -
        // specials: Constitution, Mountaineer, Wall Crushing
        //  item slots: W+A+A
        //   spells:
        data = game->getUnit_Type_Data(MoM::UNITTYPE_Dwarf);
        data->m_Hero_TypeCode_or_Building2 = heroTypeCode(MoM::SLOT16_Sword, MoM::SLOT16_Armor_Shield, MoM::SLOT16_Armor_Shield);

        //Healer         0     -     -     -     -     -     -     -     -     -
        // specials: Healer, Caster 7.5
        //  item slots: W+A+R
        //   spells:
        data = game->getUnit_Type_Data(MoM::UNITTYPE_Healer);
        data->m_Hero_TypeCode_or_Building2 = heroTypeCode(MoM::SLOT16_Sword, MoM::SLOT16_Armor_Shield, MoM::SLOT16_Amulet);

        //Huntress       0     -     -     -     -     -     -     -     -     -
        // specials: Blademaster, Forester, Long Range
        //  item slots: W/B+R+R
        //   spells:
        data = game->getUnit_Type_Data(MoM::UNITTYPE_Huntress);
        data->m_Hero_TypeCode_or_Building2 = heroTypeCode(MoM::SLOT16_Bow, MoM::SLOT16_Amulet, MoM::SLOT16_Amulet);

        //Orc Warrior    0     -     -     -     -     -     -     -     -     -
        // specials: Might, First strike
        //  item slots: W+A+R
        //   spells:
        data = game->getUnit_Type_Data(MoM::UNITTYPE_Orc_Warrior);
        data->m_Hero_TypeCode_or_Building2 = heroTypeCode(MoM::SLOT16_Sword, MoM::SLOT16_Armor_Shield, MoM::SLOT16_Amulet);

        //Sage           0     -     -     -     -     -     -     -     -     -
        // specials: Sage, Caster 7.5
        //  item slots: S+R+R
        //   spells:
        data = game->getUnit_Type_Data(MoM::UNITTYPE_Sage);
        data->m_Hero_TypeCode_or_Building2 = heroTypeCode(MoM::SLOT16_Staff_Wand, MoM::SLOT16_Amulet, MoM::SLOT16_Amulet);

        //Thief          0     -     -     -     -     -     -     -     -     -
        // specials: Armour Piercing, Agility
        //  item slots: W+R+R
        //   spells:
        data = game->getUnit_Type_Data(MoM::UNITTYPE_Thief);
        data->m_Hero_TypeCode_or_Building2 = heroTypeCode(MoM::SLOT16_Sword, MoM::SLOT16_Amulet, MoM::SLOT16_Amulet);

        //Assassin       5     -     -     -     -     -     -     -     -     -
        // specials: Poison, Blade Master, Web, 1x Random
        //  item slots: W+W+R
        //   spells:
        data = game->getUnit_Type_Data(MoM::UNITTYPE_Assassin);
        data->m_Hero_TypeCode_or_Building2 = heroTypeCode(MoM::SLOT16_Sword, MoM::SLOT16_Sword, MoM::SLOT16_Amulet);

        //Druid          5     -     -     -     -     -     -     -     -     -
        // specials: Purification, Regeneration, Caster 7.5
        //  item slots: S+A+R
        //   spells:
        data = game->getUnit_Type_Data(MoM::UNITTYPE_Druid);
        data->m_Hero_TypeCode_or_Building2 = heroTypeCode(MoM::SLOT16_Staff_Wand, MoM::SLOT16_Armor_Shield, MoM::SLOT16_Amulet);

        //Magician       5     -     -     -     -     -     -     -     -     -
        // specials: Arcane Power, Caster 7.5
        //  item slots: S+S+R
        //   spells:
        data = game->getUnit_Type_Data(MoM::UNITTYPE_Magician);
        data->m_Hero_TypeCode_or_Building2 = heroTypeCode(MoM::SLOT16_Staff_Wand, MoM::SLOT16_Staff_Wand, MoM::SLOT16_Amulet);

        //War Monk       5     -     -     -     -     -     -     -     -     -
        // specials: Super Agility, First Strike, Negate First Strike, Blademaster
        //  item slots: R+R+R
        //   spells:
        data = game->getUnit_Type_Data(MoM::UNITTYPE_War_Monk);
        data->m_Hero_TypeCode_or_Building2 = heroTypeCode(MoM::SLOT16_Amulet, MoM::SLOT16_Amulet, MoM::SLOT16_Amulet);

        //Warrior Mage   5     -     -     -     -     -     -     -     -     -
        // specials:
        //  item slots: S/W+A+R
        //   spells:
        data = game->getUnit_Type_Data(MoM::UNITTYPE_Warrior_Mage);
        data->m_Hero_TypeCode_or_Building2 = heroTypeCode(MoM::SLOT16_Sword_Staff_Wand, MoM::SLOT16_Armor_Shield, MoM::SLOT16_Amulet);

        //Draconian     10     -     -     -     -     -     -     -     -     -
        // specials: Fire Breath 5, Flying, Might, 1x Random
        //  item slots: S+A+R
        //   spells:
        data = game->getUnit_Type_Data(MoM::UNITTYPE_Draconian);
        data->m_Hero_TypeCode_or_Building2 = heroTypeCode(MoM::SLOT16_Staff_Wand, MoM::SLOT16_Armor_Shield, MoM::SLOT16_Amulet);

        //Golden One    10     -     -     -     -     -     -     -     -     -
        // specials: Caster 5, 3x Random
        //  item slots: W/S+A+R
        //   spells:
        data = game->getUnit_Type_Data(MoM::UNITTYPE_Golden_One);
        data->m_Hero_TypeCode_or_Building2 = heroTypeCode(MoM::SLOT16_Sword_Staff_Wand, MoM::SLOT16_Armor_Shield, MoM::SLOT16_Amulet);

        //Ranger        10     -     -     -     -     -     -     -     -     -
        // specials: Pathfinding, Caster 5, , Scouting III, 1x Random
        //  item slots: W/B+A+R
        //   spells:
        data = game->getUnit_Type_Data(MoM::UNITTYPE_Ranger);
        data->m_Hero_TypeCode_or_Building2 = heroTypeCode(MoM::SLOT16_Bow, MoM::SLOT16_Armor_Shield, MoM::SLOT16_Amulet);

        //Wind Mage     10     -     -     -     -     -     -     -     -     -
        // specials: Windwalking, caster 7.5, 1x Random
        //  item slots: S+R+R
        //   spells:
        data = game->getUnit_Type_Data(MoM::UNITTYPE_Wind_Mage);
        data->m_Hero_TypeCode_or_Building2 = heroTypeCode(MoM::SLOT16_Staff_Wand, MoM::SLOT16_Amulet, MoM::SLOT16_Amulet);

        //Witch         10     -     -     -     -     -     -     -     -     -
        // specials: Caster 10, Life Steal
        //  item slots: S+R+R
        //   spells:
        data = game->getUnit_Type_Data(MoM::UNITTYPE_Witch);
        data->m_Hero_TypeCode_or_Building2 = heroTypeCode(MoM::SLOT16_Staff_Wand, MoM::SLOT16_Amulet, MoM::SLOT16_Amulet);
    }

    if (ok)
    {
        // TODO: Large Shield is +3 or +4

        uint16_t spareNameOffset = 0xEA60;   // Spare room in Stack Segment
        uint16_t size = 0;
        char* spareNameBuffer = const_cast<char*>(game->getNameByOffset(spareNameOffset));
        char* spareNames = spareNameBuffer;

        uint16_t offsetClerics = spareNameOffset;
        size = 1 + sprintf(spareNames, "%s", "Clerics");
        spareNameOffset += size;
        spareNames += size;
        uint16_t offsetEvokers = spareNameOffset;
        size += 1 + sprintf(spareNames, "%s", "Evokers");
        spareNameOffset += size;
        spareNames += size;
        uint16_t offsetSorcerers = spareNameOffset;
        size += 1 + sprintf(spareNames, "%s", "Sorcerers");
        spareNameOffset += size;
        spareNames += size;
        uint16_t offsetEnchanters = spareNameOffset;
        size += 1 + sprintf(spareNames, "%s", "Enchanters");
        spareNameOffset += size;
        spareNames += size;
        uint16_t offsetSummoners = spareNameOffset;
        size += 1 + sprintf(spareNames, "%s", "Summoners");
        spareNameOffset += size;
        spareNames += size;
        uint16_t offsetWizards = spareNameOffset;
        size += 1 + sprintf(spareNames, "%s", "Wizards");
        spareNameOffset += size;
        spareNames += size;

        ok = game->commitData(spareNameBuffer, spareNameBuffer, (size_t)(spareNames - spareNameBuffer));

        for (int unitTypeNr = 35; unitTypeNr <= 0x9A; ++unitTypeNr)
        {
            MoM::eUnit_Type unitType = static_cast<MoM::eUnit_Type>(unitTypeNr);
            MoM::Unit_Type_Data* data = game->getUnit_Type_Data(unitType);
            if (0 == data)
            {
                ok = false;
                break;
            }
            QString unitName = toQStr(unitType);

            bool isFootUnit = (-1 != QRegExp("Spearmen").indexIn(unitName)
                    || -1 != QRegExp("Swordsmen").indexIn(unitName)
                    || -1 != QRegExp("Bowmen").indexIn(unitName)
                    || -1 != QRegExp("Swordsmen").indexIn(unitName)
                    || -1 != QRegExp("Halberdiers").indexIn(unitName)
                    || -1 != QRegExp("Pikemen").indexIn(unitName)
                    || -1 != QRegExp("Berserkers").indexIn(unitName)
                    || -1 != QRegExp("Minotaurs").indexIn(unitName)
                    || -1 != QRegExp("Nightblades").indexIn(unitName)
                    || -1 != QRegExp("Hammerhands").indexIn(unitName)
                    || -1 != QRegExp("Rangers").indexIn(unitName)
                    || -1 != QRegExp("War_Trolls").indexIn(unitName)
                    );

//            bool isCavalry = (QRegExp("Cavalry").indexIn(unitName)
//                    || QRegExp("Horsebowmen").indexIn(unitName)
//                    || QRegExp("Centaurs").indexIn(unitName)
//                    || QRegExp("Nightmares").indexIn(unitName)
//                    || QRegExp("Wolf_Riders").indexIn(unitName)
//                    || QRegExp("Elven_Lords").indexIn(unitName)
//                    || QRegExp("Pegasai").indexIn(unitName)
//                    || QRegExp("Paladins").indexIn(unitName)
//                    || QRegExp("Stag_Beetle").indexIn(unitName)
//                    || QRegExp("Dragon_Turtle").indexIn(unitName)
//                    || QRegExp("Griffins").indexIn(unitName)
//                    || QRegExp("Wyvern_Riders").indexIn(unitName)
//                    || QRegExp("War_Mammoths").indexIn(unitName)
//                    );

            //Clerics are a new unit type which is available to high men, beastmen and halflings.
            //They replace priests and shaman respectively.
            bool isCleric = ((MoM::UNITTYPE_Beastmen_Priests == unitType) || (MoM::UNITTYPE_Halfling_Shaman == unitType) || (MoM::UNITTYPE_High_Men_Priests == unitType));

            if (isCleric)
            {
            }

			//
            // All foot units get 2 moves and 2 hearts, cavalry gets 4 moves and 5 hearts, catapults stay at 1 move and 10 hearts.
			//

            if (isFootUnit)
            {
                data->m_MoveHalves = 4;
                data->m_Hitpoints = 2;
            }
            else if (-1 != QRegExp("Cavalry").indexIn(unitName))
            {
                data->m_MoveHalves = 8;
                data->m_Hitpoints = 5;
            }
			else if (data->m_Movement_Flags.s.Cavalry)
			{
                data->m_MoveHalves = 8;
			}

			//
			// Normal units
			//

            if (-1 != QRegExp("Spearmen").indexIn(unitName))
            {
                //Spearmen: Cost 20, 7 fig, 2 off, 3 def, negate first strike
                data->m_Cost = 20;
                data->m_Nr_Figures = 7;
                data->m_Melee = 2;
                data->m_Defense = 3;
                data->m_Ability_Flags.s.Negate_First_Strike = true;
            }
            else if (-1 != QRegExp("Swordsmen").indexIn(unitName))
            {
                //Swordsmen: Cost 30, 7 fig, 4 off, 2 def, large shield (hacked to give +3 or possibly +4 ranged def)
                data->m_Cost = 30;
                data->m_Nr_Figures = 7;
                data->m_Melee = 4;
                data->m_Defense = 2;
                data->m_Ability_Flags.s.Large_Shield = true;
            }
            else if (-1 != QRegExp("Bowmen").indexIn(unitName))
            {
                //Bowmen: Cost 40, 6 fig, 1 off, 1 def, 2 rng, 6 ammo
                data->m_Cost = 40;
                data->m_Nr_Figures = 6;
                data->m_Melee = 1;
                data->m_Defense = 1;
                data->m_Ranged = 2;
                data->m_Ranged_Shots = 6;
            }
            else if (-1 != QRegExp("Halberdiers").indexIn(unitName))
            {
                //Halberdiers: Cost 50, 6 fig, 5 off, 3 def, armour piercing
                data->m_Cost = 50;
                data->m_Nr_Figures = 6;
                data->m_Melee = 5;
                data->m_Defense = 3;
                data->m_Attack_Flags.s.Armor_Piercing = true;
            }
            else if (-1 != QRegExp("Cavalry").indexIn(unitName))
            {
                //Cavalry: Cost 60, 4 fig, 7 off, 2 def, first strike
                data->m_Cost = 60;
                data->m_Nr_Figures = 4;
                data->m_Melee = 7;
                data->m_Defense = 2;
                data->m_Ranged = 2;
                data->m_Attack_Flags.s.First_Strike = true;
            }
            else if (isCleric)
            {
                //Clerics: Cost 100, 3 fig, 6 off, 5 def, healing
                data->m_PtrName = offsetClerics;
                data->m_Cost = 100;
                data->m_Nr_Figures = 3;
                data->m_Melee = 6;
                data->m_Defense = 5;
                data->m_Ability_Flags.s.Healer = false;
                data->m_Ability_Flags.s.Purify = false;
                data->m_Attribute_Flags.s.Healing_Spell = true;
            }
            else if (-1 != QRegExp("Shaman").indexIn(unitName))
            {
                //Shaman: Cost 80, 3 fig, 2 off, 4 def, 3 rng, 4 ammo, purify, healer
                data->m_Cost = 80;
                data->m_Nr_Figures = 3;
                data->m_Melee = 2;
                data->m_Defense = 4;
                data->m_Ranged = 3;
                data->m_Ranged_Shots = 4;
                data->m_Ability_Flags.s.Purify = true;
                data->m_Ability_Flags.s.Healer = true;
                data->m_Attribute_Flags.s.Healing_Spell = false;
            }
            else if (-1 != QRegExp("Priests").indexIn(unitName))
            {
                //Priests: Cost 120, 3 fig, 3 off, 4 def, 4 rng, 4 ammo, magic immunity
                data->m_Cost = 120;
                data->m_Nr_Figures = 3;
                data->m_Melee = 3;
                data->m_Defense = 4;
                data->m_Ranged = 4;
                data->m_Ranged_Shots = 4;
                data->m_Ability_Flags.s.Purify = false;
                data->m_Ability_Flags.s.Healer = false;
                data->m_Attribute_Flags.s.Healing_Spell = false;
                data->m_Immunity_Flags.s.Magic_Immunity = true;
            }
            else if (-1 != QRegExp("Magicians").indexIn(unitName))
            {
                //Magicians: stats (and name) vary from race to race

                // 3 figures (default is 4)
                data->m_Nr_Figures = 3;
                // Fire Ball Spell is no longer a "given"
                data->m_Attribute_Flags.s.Fire_Ball_Spell = false;
                // Default Ranged strength is 5 for Magicians and 7 for Warlocks
                // Default Ranged Shots is 4

                switch (unitType)
                {
                case MoM::UNITTYPE_Beastmen_Magicians:
                    //        Beastmen Evokers
                    //        Fireball, strength 5 ranged attack, 6 ammo
                    data->m_PtrName = offsetEvokers;
                    data->m_Attribute_Flags.s.Fire_Ball_Spell = true;
                    data->m_Ranged = 5;
                    data->m_Ranged_Shots = 6;
                    break;

                case MoM::UNITTYPE_Draconian_Magicians:
                    //        Draconian Sorcerers
                    //        Caster 40, no ranged attack, fire breath and decent melee
                    data->m_PtrName = offsetSorcerers;
                    data->m_Attribute_Flags.s.Caster_40_MP = true;
                    data->m_Race_Code = MoM::RACE_Chaos;            // Has to be a color (not arcane) to make Caster_40_MP work
                    data->m_Attribute_Flags.s.Standard = false;     // Do not display the color-prefix for the name
                    data->m_Ranged_Type = MoM::RANGED_None;
                    data->m_Ranged = 0;
                    data->m_Ranged_Shots = 0;
                    break;

                case MoM::UNITTYPE_Dark_Elf_Warlocks:
                    // No changes
                    break;

                case MoM::UNITTYPE_High_Elf_Magicians:
                    //        High Elf Enchanters
                    //        Caster 20, weak ranged attack and good melee
                    data->m_PtrName = offsetEnchanters;
                    data->m_Attribute_Flags.s.Caster_20_MP = true;
                    data->m_Race_Code = MoM::RACE_Nature;           // Has to be a color (not arcane) to make Caster_40_MP work
                    data->m_Attribute_Flags.s.Standard = false;     // Do not display the color-prefix for the name
                    data->m_Melee = 2;
                    data->m_Ranged = 3;
                    break;

                case MoM::UNITTYPE_High_Men_Magicians:
                    //        High Men Magicians
                    //        Strong ranged attack, 4 figures (others are 3)
                    // data->m_PtrName = offsetMagicians;
                    data->m_Nr_Figures = 4;
                    data->m_Ranged = 7;
                    break;

                case MoM::UNITTYPE_Nomad_Magicians:
                    data->m_PtrName = offsetWizards;
                    data->m_Attribute_Flags.s.Web_Spell = true;
                    break;

                case MoM::UNITTYPE_Orc_Magicians:
                    //        Orc Summoners
                    //        Summon Demon, ranged attack
                    data->m_PtrName = offsetSummoners;
                    data->m_Attribute_Flags.s.Summon_Demons_1 = true;
                    break;

                default:
                    break;
                }
            }
            else if (-1 != QRegExp("Catapult").indexIn(unitName))
            {
                //Catapult: Cost 40, 1 fig, 0 off, 1 def, 8 rng, 10 ammo, long range, wall crusher, large shield
                data->m_Cost = 40;
                data->m_Nr_Figures = 1;
                data->m_Melee = 0;
                data->m_Defense = 1;
                data->m_Ranged = 8;
                data->m_Ranged_Shots = 10;
                data->m_Ability_Flags.s.Long_Range = true;
                data->m_Ability_Flags.s.Wall_Crusher = true;
                data->m_Ability_Flags.s.Large_Shield = true;
            }
        }
    }

    if (ok)
    {
        ok = controller->commitMemory();
    }

    if (!ok)
    {
        statusBar()->showMessage(tr("Failed to apply Catnip mod"));
    }
    else
    {
        statusBar()->showMessage(tr("Catnip mod applied"));
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
