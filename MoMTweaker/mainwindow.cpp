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
#include <MoMutility.h>
#include <QMoMCommon.h>

// Local
#include "dialogcalculatoraddress.h"
#include "dialogoverlandmap.h"
#include "dialogtables.h"
#include "dialogtools.h"


MainWindow* MainWindow::m_instance = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_timer(),
    m_UnitModel(this),
    m_filedialogLoadGame(this),
    m_filedialogSaveGame(this),
    m_game()
{
    ui->setupUi(this);

	m_instance = this;

    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    m_timer->start(10000);

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
#ifdef _WIN32
    m_filedialogLoadGame.setDirectory("C:/games/MAGIC-work/");
    m_filedialogSaveGame.setDirectory("C:/games/MAGIC-work/");
    setFont(QFont("Monotype Corsiva", 11));
    ui->treeView->setFont(QFont("Monotype Corsiva", 11));
#else // Linux
    m_filedialogLoadGame.setDirectory("/media/C_DRIVE/GAMES/MAGIC-work/");
    m_filedialogSaveGame.setDirectory("/media/C_DRIVE/GAMES/MAGIC-work/");
//    setFont(QFont("URW Chancery L", 12));
//    ui->treeView->setFont(QFont("URW Chancery L", 11));
#endif


    // --- Configure TreeWidget ---
//    ui->treeWidget->setColumnWidth(0, 250);
//    ui->treeWidget->setColumnWidth(1, 250);

    // -- Configure TreeView ---
//    ui->treeView->setColumnWidth(0, 350);
//    ui->treeView->setColumnWidth(1, 350);
    ui->treeView->setModel(&m_UnitModel);

    // --- Set background ---
    //QBrush brush(QPixmap(":/images/background_unit.gif"));
    //ui->treeWidget->setBackgroundRole(QPalette::ColorRole::Button);
    //QPalette palette = ui->treeWidget->palette();
    //palette.setBrush(ui->treeWidget->backgroundRole(), brush);
    //ui->treeWidget->setAutoFillBackground(true);
    //ui->treeWidget->setPalette(palette);

    update();
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
    if (0 == m_game.get())
    {
        (void)QMessageBox::warning(this,
            tr("Summon"),
            tr("There is no game to operate on"));
        return;
    }

    bool ok = refreshMemory();

    if (ok)
    {
		ok = MoM::MoMController::addUnit(*m_game, MoM::PLAYER_YOU, unitType);
        if (!ok)
        {
            (void)QMessageBox::warning(this,
                tr("Summon"),
                tr("Failed to summon"));
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
    }

    update();
}

void MainWindow::applyBuildQueues()
{
    if (0 == m_game.get())
    {
        (void)QMessageBox::warning(this,
            tr("Apply Building Queues"),
            tr("There is no game to operate on"));
        return;
    }

    bool ok = refreshMemory();

    if (ok)
    {
        ok = MoM::MoMController::applyBuildingQueue(*m_game, MoM::PLAYER_YOU);
        if (!ok)
        {
            (void)QMessageBox::warning(this,
                tr("Apply Building Queues"),
                tr("Failed to apply the Building Queues"));
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
    }

    update();
}

bool MainWindow::commitMemory()
{
    bool ok = true;
    MoM::MoMGameMemory* memGame = dynamic_cast<MoM::MoMGameMemory*>(m_game.get());
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
    if (0 != m_game.get())
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
    if (0 != m_game.get())
    {
        title = m_game->getSources();
    }

    setWindowTitle(title.c_str());

    /*
    MoM::ePlayer playerNr = MoM::PLAYER_YOU;
    bool activeOnly = ui->checkBox_ShowActiveOnly->isChecked();

//    ui->treeWidget->clear();

    if (0 == m_game)
    {
        return;
    }

    // TODO: index-range-checks

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
        // UNIT DATA
        //

        featurePrefix = tr("HD.");

        if (0 != pHeroData)
        {
            QTreeWidgetItem* qtreeHDFields
                = new QTreeWidgetItem(qtreeHero, 
                    QStringList(tr("Hero Data.Fields")));

            const char* hdName = m_game->getNameByOffset(pHeroData->m_PtrName);
            addTreeFeature(qtreeHDFields, 
                tr("HD.Name"), 
                QIcon(),
                QString(hdName), 
                QIcon());
            addTreeFeature(qtreeHDFields, 
                tr("HD.Upkeep"), 
                QIcon(),
                toQStr((unsigned)pHeroData->m_Upkeep), 
                QIcon());

            ADDMFIELDFEATURE(qtreeHDFields, (int)(*pHeroData), Cost);
            ADDMFIELDFEATURE(qtreeHDFields, (*pHeroData), Race_Code);
            ADDMFIELDFEATURE(qtreeHDFields, (unsigned)(*pHeroData), Buildings_Required1);
            ADDMFIELDFEATURE(qtreeHDFields, (*pHeroData), Hero_TypeCode);
            ADDMFIELDFEATURE(qtreeHDFields, (unsigned)(*pHeroData), UNKTypeCode);
            ADDMFIELDFEATURE(qtreeHDFields, (unsigned)(*pHeroData), Scouting_Range);
            ADDMFIELDFEATURE(qtreeHDFields, (unsigned)(*pHeroData), Transport_Capacity);
            ADDMFIELDFEATURE(qtreeHDFields, (int)(*pHeroData), Construction_Capacity);

            QTreeWidgetItem* qtreeHDCombat
                = new QTreeWidgetItem(qtreeHero, QStringList(tr("Hero Data.Combat(base)")));

            ADDMFIELDFEATURE(qtreeHDCombat, (unsigned)(*pHeroData), NrFigures);
            sprintf(buf, "%.1f", pHeroData->m_MoveHalves / 2.0);
            addTreeFeature(qtreeHDCombat, 
                tr("HD.Move"), 
                QIcon(),
                QString(buf), 
                QIcon());
            addTreeFeature(qtreeHDCombat, 
                tr("HD.Melee"), 
                QIcon(":/images/sword_normal.gif"),
                toQStr((unsigned)pHeroData->m_Melee), 
                QIcon(":/images/sword_normal.gif"));
            addTreeFeature(qtreeHDCombat, 
                tr("HD.Range"), 
                QIcon(":/images/ranged_unknown.gif"),
                toQStr((unsigned)pHeroData->m_Ranged), 
                QIcon(":/images/fireball_normal.gif"));
            addTreeFeature(qtreeHDCombat, 
                tr("HD.RangedType"), 
                QIcon(":/images/ranged_unknown.gif"),
                toQStr(pHeroData->m_Ranged_Type),
                QIcon());
            addTreeFeature(qtreeHDCombat, 
                tr("HD.RangedShots"), 
                QIcon(":/images/ranged_unknown.gif"),
                toQStr((unsigned)pHeroData->m_Ranged_Shots),
                QIcon());
            addTreeFeature(qtreeHDCombat, 
                tr("HD.Armor"), 
                QIcon(":/images/shield_normal.gif"),
                toQStr((unsigned)pHeroData->m_Defense), 
                QIcon(":/images/shield_normal.gif"));
            addTreeFeature(qtreeHDCombat, 
                tr("HD.Resist"), 
                QIcon(":/images/resistance_normal.gif"),
                toQStr((unsigned)pHeroData->m_Resistance), 
                QIcon(":/images/resistance_normal.gif"));
            addTreeFeature(qtreeHDCombat, 
                tr("HD.Hits"), 
                QIcon(":/images/heart_normal.gif"),
                toQStr((unsigned)pHeroData->m_Hit_Points),
                QIcon(":/images/heart_normal.gif"));

            sprintf(buf, "%+d", (int)pHeroData->m_To_Hit);
            addTreeFeature(qtreeHDCombat, 
                tr("HD.ToHit"), 
                QIcon(":/images/To Hit.gif"),
                QString(buf), 
                QIcon(":/images/To Hit.gif"));

            addTreeFeature(qtreeHDCombat, 
                tr("HD.GazeModifier"), 
                QIcon(),
                toQStr((int)pHeroData->m_Gaze_Modifier),
                QIcon());

            featurePrefix = tr("HD.");

            QTreeWidgetItem* qtreeHDFlags
                = new QTreeWidgetItem(qtreeHero, QStringList(tr("Hero Data.Flags")));
            
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Movement_Flags, Cavalry);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Movement_Flags, Sailing);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Movement_Flags, Swimming);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Movement_Flags, Flying);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Movement_Flags, Teleporting);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Movement_Flags, Forester);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Movement_Flags, Mountaineer);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Movement_Flags, Merging);

            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Fire_Immunity);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Stoning_Immunity);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Missiles_Immunity);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Illusions_Immunity);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Cold_Immunity);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Magic_Immunity);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Death_Immunity);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Poison_Immunity);

            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Weapon_Immunity);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Lucky);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Summon_Demons_1);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Summon_Demons_2);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Caster_20_MP);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Caster_40_MP);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Standard);

            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Healing_Spell);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Fire_Ball_Spell);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Doombolt_Spell);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Immolation);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Web_Spell);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Cause_Fear_Spell);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Resistance_to_All);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Attribute_Flags, Holy_Bonus);

            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Ability_Flags, Summoned_unit);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Ability_Flags, Large_Shield);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Ability_Flags, Plane_Shift);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Ability_Flags, Wall_Crusher);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Ability_Flags, Healer);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Ability_Flags, Create_Outpost);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Ability_Flags, Invisibility);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Ability_Flags, Create_Undead);

            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Ability_Flags, Long_Range);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Ability_Flags, Land_Corruption);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Ability_Flags, Meld_With_Node);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Ability_Flags, Non_Corporeal);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Ability_Flags, Wind_Walking);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Ability_Flags, Regeneration);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Ability_Flags, Purify);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Ability_Flags, Negate_First_Strike);

            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Special_attack_Flags, Armor_Piercing);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Special_attack_Flags, First_Strike);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Special_attack_Flags, Poison_attack);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Special_attack_Flags, Life_Stealing);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Special_attack_Flags, Automatic_Damage);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Special_attack_Flags, Destruction);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Special_attack_Flags, Illusionary_attack);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Special_attack_Flags, Stoning_Touch);

            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Special_attack_Flags, Death_Touch);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Special_attack_Flags, Power_Drain);
            ADDFLAGFEATURE(qtreeHDFlags, pHeroData->m_Special_attack_Flags, Dispel_Evil);
        }

        //
        // HERO STATS
        //

        featurePrefix = tr("HS.");

        QTreeWidgetItem* qtreeHSFlags
            = new QTreeWidgetItem(qtreeHero, QStringList(tr("Hero Stats.Flags")));

        ADDMFIELDFEATURE(qtreeHSFlags, heroStats, Level_Status);
        ADDMFIELDFEATURE(qtreeHSFlags, (unsigned)heroStats, Hero_Casting_Skill);
        for (int spellNr = 0; spellNr < ARRAYSIZE(heroStats.m_Spell); ++spellNr)
        {
            if (MoM::SPELL_None != heroStats.m_Spell[spellNr])
            {
                ADDMFIELDFEATURE(qtreeHSFlags, heroStats, Spell[spellNr]);
            }
        }

        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Leadership);
        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Leadership_X);
        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Legendary);
        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Legendary_X);
        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Blademaster);
        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Blademaster_X);

        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Armsmaster);
        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Armsmaster_X);
        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Constitution);
        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Constitution_X);
        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Might);

        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Might_X);
        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Arcane_Power);
        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Arcane_Power_X);
        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Sage);
        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Sage_X);

        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Prayermaster);
        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Prayermaster_X);
        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Agility_X);
        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Lucky);
        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Charmed);
        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Noble);
        ADDFLAGFEATURE(qtreeHSFlags, heroStats.m_Hero_Abilities, Agility);


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
        ADDMFIELDFEATURE(qtreeUFields, (unsigned)unit, Scouting_Range);
        ADDMFIELDFEATURE(qtreeUFields, (int)unit, Road_Building_left_to_complete);
        //int8_t      m_Road_Building_parms[3];

         QTreeWidgetItem* qtreeUFlags
            = new QTreeWidgetItem(qtreeHero, QStringList(tr("Unit.Flags")));

        addTreeFeature(qtreeUFlags, 
            tr("U.Weapon type"), 
            QIcon(),
            toQStr((MoM::eWeaponType)unit.m_Weapon_Mutation.s.Weapon_Type), 
            QIcon());
        ADDSPELLFLAGFEATURE(qtreeUFlags, unit.m_Weapon_Mutation, Chaos_Channels_Demon_Skin);
        ADDSPELLFLAGFEATURE(qtreeUFlags, unit.m_Weapon_Mutation, Chaos_Channels_Demon_Wings);
        ADDSPELLFLAGFEATURE(qtreeUFlags, unit.m_Weapon_Mutation, Chaos_Channels_Fiery_Breath);
        ADDSPELLFLAGFEATURE(qtreeUFlags, unit.m_Weapon_Mutation, Undead);
        ADDSPELLFLAGFEATURE(qtreeUFlags, unit.m_Weapon_Mutation, Stasis_initial);
        ADDSPELLFLAGFEATURE(qtreeUFlags, unit.m_Weapon_Mutation, Stasis_lingering);

         QTreeWidgetItem* qtreeUEnchantments
            = new QTreeWidgetItem(qtreeHero, QStringList(tr("Unit.Enchantments")));

        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Immolation);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Guardian_Wind);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Berserk);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Cloak_of_Fear);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Black_Channels);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Wraith_Form);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Regeneration);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Path_Finding);

        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Water_Walking);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Resist_Elements);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Elemental_Armor);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Stone_Skin);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Iron_Skin);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Endurance);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Spell_Lock);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Invisibility);

        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Wind_Walking);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Flight);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Resist_Magic);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Magic_Immunity);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Flame_Blade);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Eldritch_Weapon);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, True_Sight);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Holy_Weapon);

        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Heroism);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Bless);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Lion_Heart);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Giant_Strength);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Planar_Travel);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Holy_Armor);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Righteousness);
        ADDSPELLFLAGFEATURE(qtreeUEnchantments, unit.m_Unit_Enchantment, Invulnerability);

//        ui->treeWidget->addTopLevelItem(qtreeHero);
        delete qtreeHero;
    }
    */

    ui->pushButton_Reread->setEnabled(
            (0 != dynamic_cast<MoM::MoMGameMemory*>(m_game.get()))
            || (0 != dynamic_cast<MoM::MoMGameCustom*>(m_game.get()))
            );
    ui->pushButton_Save->setEnabled(0 != dynamic_cast<MoM::MoMGameSave*>(m_game.get()));

    if (ui->checkBox_UpdateTree->isChecked())
    {
        m_UnitModel.update();
    }
}

#ifdef _WIN32

BOOL CALLBACK wndEnumProc(HWND hwnd, LPARAM lParam)
{
    QStringList& windowTitles = *(QStringList*)lParam;

    char szTitle[4096] = "";
    if (0 < GetWindowTextA(hwnd, szTitle, sizeof(szTitle)))
    {
        QString qtitle(szTitle);
        if (-1 != qtitle.indexOf(QString("DOSBox"), 0, Qt::CaseInsensitive))
        {
            windowTitles.append(szTitle);
        }
    }

    return TRUE;
}
#endif

void MainWindow::on_pushButton_Connect_clicked()
{
    m_game.reset();
    m_UnitModel.setGame(m_game.get());

    QString title("DOSBox Status Window");

#ifdef _WIN32
    QStringList windowTitles;
    if (EnumWindows(wndEnumProc, (LPARAM)&windowTitles)
        && !windowTitles.isEmpty())
    {
        title = windowTitles.front();
    }
#else // Linux
    title = "dosbox";     // Process name
#endif

    std::auto_ptr<MoM::MoMProcess> momProcess( new MoM::MoMProcess );

    bool ok = momProcess->findProcessAndData(title.toAscii().data());
    std::auto_ptr<MoM::MoMGameMemory> memGame( new MoM::MoMGameMemory );
    std::auto_ptr<MoM::MoMGameCustom> customGame( new MoM::MoMGameCustom );
    if (ok && memGame->openGame(momProcess))
    {
        m_game = memGame;
    }
    else if (ok && customGame->openGame(momProcess))
    {
        m_game = customGame;
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
            tr("Could not find MoM using title '%1'").arg(title));
    }
    else
    {
        statusBar()->showMessage(tr("Updating treeview ..."));
        m_UnitModel.setGame(m_game.get());
        statusBar()->showMessage(tr("Game connected"));
    }
    update();

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

    statusBar()->showMessage(tr("Game cleared"));
    m_game.reset();
    m_UnitModel.setGame(m_game.get());

    QString fileName = m_filedialogLoadGame.selectedFiles().first();

    MoM::MoMLbxBase lbxFile;
    std::auto_ptr<MoM::MoMGameSave> saveGame( new MoM::MoMGameSave );

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
        m_game = saveGame;
        statusBar()->showMessage(tr("Updating Treeview..."));
        m_UnitModel.setGame(m_game.get());
        statusBar()->showMessage(tr("Game loaded"));
    }

    update();
}

void MainWindow::on_pushButton_Save_clicked()
{
    MoM::MoMGameSave* saveGame = dynamic_cast<MoM::MoMGameSave*>(m_game.get());
    if ((0 == saveGame) || !saveGame->isOpen())
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
    if (0 == m_game.get())
        return;

    bool ok = m_game->readData();
    if (!ok)
    {
        statusBar()->showMessage(tr("Reread failed"));
    }
    else
    {
        statusBar()->showMessage(tr("Reread completed"));
    }
    update();
}

void MainWindow::onTimer()
{
    if ((0 == m_game.get()) || (0 != dynamic_cast<MoM::MoMGameSave*>(m_game.get())))
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
    update();
}



void MainWindow::on_pushButton_ShowTables_clicked()
{
    DialogTables* dialog = new DialogTables(this);
    dialog->show();
}

void MainWindow::on_pushButton_Calculator_clicked()
{
    DialogCalculatorAddress* dialog = new DialogCalculatorAddress(this);
    dialog->show();
}

void MainWindow::on_pushButton_Map_clicked()
{
    DialogOverlandMap* dialog = new DialogOverlandMap(this);
    dialog->show();
}


void MainWindow::on_pushButton_Tools_clicked()
{
    DialogTools* dialog = new DialogTools(this);
    dialog->show();
}
