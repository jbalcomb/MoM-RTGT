// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2012-03-12
// ---------------------------------------------------------------------------

#include <QGraphicsScene>
#include <QMenu>
#include <QTimer>
#include <QTreeWidgetItem>

#include <cmath>

#include "dialogmap.h"
#include "ui_dialogmap.h"

#include "dialogcalculatoraddress.h"
#include "mainwindow.h"
#include "MoMController.h"
#include "MoMGenerated.h"
#include "MoMExeWizards.h"
#include "MoMTemplate.h"
#include "MoMTerrain.h"
#include "MoMUtility.h"
#include "QMoMMapTile.h"
#include "QMoMResources.h"
#include "QMoMTreeItem.h"
#include "QMoMUnitTile.h"
#include "QMoMMapScene.h"

namespace MoM
{

class QTreeItemBase : public QTreeWidgetItem
{
public:
    enum { COL_Feature, COL_Value, COL_Comment };

    QTreeItemBase(const QMoMGamePtr& game, const QString& feature, const QString& value) :
        QTreeWidgetItem(),
        m_game(game)
    {
        setText(COL_Feature, feature);
        setText(COL_Value, value);
    }
    virtual void* getMoMPointer() const
    {
        return 0;
    }
    virtual QList<QAction*> requestActions(QObject*)
    {
        return QList<QAction*>();
    }
    virtual void slotAction()
    {
    }
    virtual QString toString() const
    {
        return QTreeWidgetItem::text(COL_Value);
    }
protected:
    QMoMGamePtr m_game;
};

///////////////////////////////////////////

template<typename Number>
class NumberTreeItem : public QTreeItemBase
{
public:
    NumberTreeItem(const QMoMGamePtr& game, const QString& feature, Number* t, Number mask = 0);
    virtual void setData(int column, int role, const QVariant &value);
    virtual QString toString() const;
    virtual void* getMoMPointer() const
    {
        return m_ptr;
    }
private:
    Number* m_ptr;
    Number m_mask;
    unsigned m_shift;
};


template<typename Number>
NumberTreeItem<Number>::NumberTreeItem(const QMoMGamePtr& game, const QString& feature, Number* t, Number mask) :
    QTreeItemBase(game, feature, ""),
    m_ptr(t),
    m_mask(mask),
    m_shift(0)
{
    for (unsigned i = 0; (0 != mask) && (i < 32); ++i)
    {
        if (((mask >> i) << i) != mask)
        {
            break;
        }
        m_shift = i;
    }
    setFlags(flags() | Qt::ItemIsEditable);
    QTreeItemBase::setData(COL_Value, Qt::EditRole, toString());
}

template<typename Number>
void NumberTreeItem<Number>::setData(int column, int role, const QVariant &value)
{
    if ((COL_Value == column) && (Qt::EditRole == role))
    {
        Number newValue = static_cast<Number>(value.toInt());
        if (0 != m_mask)
        {
            unsigned tmp = ((unsigned)*m_ptr & ~m_mask);
            newValue = static_cast<Number>(tmp | (((unsigned)value.toInt() << m_shift) & m_mask));
        }
        (void)m_game->commitData(m_ptr, &newValue, sizeof(Number));
        QTreeItemBase::setData(COL_Value, role, toString());
    }
    else
    {
        QTreeItemBase::setData(column, role, value);
    }
}

template<typename Number>
QString NumberTreeItem<Number>::toString() const
{
    Number value = *m_ptr;
    if (0 != m_mask)
    {
        value =static_cast<Number>(((unsigned)*m_ptr & m_mask) >> m_shift);
    }
    return toQStr(value);
}

/////////////////////////////////////////

template<typename Enum>
class EnumTreeItem : public QTreeItemBase
{
public:
    EnumTreeItem(const QMoMGamePtr& game, const QString& feature, Enum* e, Enum max);

    virtual void* getMoMPointer() const
    {
        return m_ptr;
    }

    virtual void setData(int column, int role, const QVariant &value);

    virtual QList<QAction*> requestActions(QObject* parent);
    virtual void slotAction();

    virtual QString toString() const;

private:
    void addAction(Enum e);
    void updateIcon(Enum e);

    // Configuration
    Enum* m_ptr;
    Enum m_max;

    // Status

    // Keep track of the action group
    // m_actionGroup is deleted by its parent (the context menu)
    QActionGroup* m_actionGroup;
};

template<typename Enum>
EnumTreeItem<Enum>::EnumTreeItem(const QMoMGamePtr& game, const QString& feature, Enum* e, Enum max) :
    QTreeItemBase(game, feature, ""),
    m_ptr(e),
    m_max(max),
    m_actionGroup(0)
{
    setFlags(flags() | Qt::ItemIsEditable);
    QTreeItemBase::setData(COL_Value, Qt::EditRole, toString());
    updateIcon(*m_ptr);
}

template<typename Enum>
void EnumTreeItem<Enum>::setData(int column, int role, const QVariant &value)
{
    if ((COL_Value == column) && (Qt::EditRole == role))
    {
        Enum newValue = static_cast<Enum> (value.toInt());
        (void)m_game->commitData(m_ptr, &newValue, sizeof(Enum));
        QTreeItemBase::setData(COL_Value, role, toString());
        updateIcon(*m_ptr);
    }
    else
    {
        QTreeItemBase::setData(column, role, value);
    }
}

template<typename Enum>
QList<QAction*> EnumTreeItem<Enum>::requestActions(QObject* parent)
{
    m_actionGroup = new QActionGroup(parent);

    for (Enum e = (Enum)0; e < m_max; MoM::inc(e))
    {
        addAction(e);
    }

    return m_actionGroup->actions();
}

template<typename Enum>
void EnumTreeItem<Enum>::slotAction()
{
    QAction* action = m_actionGroup->checkedAction();
    setData(COL_Value, Qt::EditRole, action->data());
}

template<typename Enum>
QString EnumTreeItem<Enum>::toString() const
{
    QString str = prettyQStr(*m_ptr);
    return str;
}

// Private

template<typename Enum>
void EnumTreeItem<Enum>::addAction(Enum e)
{
    assert(m_actionGroup != 0);

    QString name = prettyQStr(e);
    if (!name.isEmpty() && (name[0] == '<') && (e != *m_ptr))
    {
        // Skip <Unknown> entries, unless one of them is selected
    }
    else
    {
        QAction* action = new QAction(name, m_actionGroup);
        QMoMIconPtr iconPtr = MoM::QMoMResources::instance().getIcon(e);
        if (!iconPtr.isNull())
        {
            action->setIcon(*iconPtr);
        }
        action->setCheckable(true);
        action->setData(QVariant((int)e));
        if (e == *m_ptr)
        {
            action->setChecked(true);
        }
    }
}

template<typename Enum>
void EnumTreeItem<Enum>::updateIcon(Enum e)
{
    QMoMIconPtr iconPtr = MoM::QMoMResources::instance().getIcon(e);
    if (!iconPtr.isNull())
    {
        QTreeItemBase::setIcon(COL_Value, *iconPtr);
    }
}

/////////////////////////////////////////

template<typename Bitmask, typename Enum>
class BitmaskTreeItem : public QTreeItemBase
{
public:
    BitmaskTreeItem(const QMoMGamePtr& game, const QString& feature, Bitmask* bitmask, Enum min, Enum max);

    virtual void* getMoMPointer() const
    {
        return m_ptr;
    }

    virtual void setData(int column, int role, const QVariant &value);

    virtual QList<QAction*> requestActions(QObject* parent);
    virtual void slotAction();

    virtual QString toString();

private:
    void addAction(Enum e);
    bool has(Enum e) const;

    // Configuration
    Bitmask* m_ptr;
    Enum m_min;
    Enum m_max;

    // Status

    // Keep track of the action group
    // m_actionGroup is deleted by its parent (the context menu)
    QActionGroup* m_actionGroup;
};

template<typename Bitmask, typename Enum>
BitmaskTreeItem<Bitmask, Enum>::BitmaskTreeItem(const QMoMGamePtr& game, const QString& feature, Bitmask* bitmask, Enum min, Enum max) :
    QTreeItemBase(game, feature, ""),
    m_ptr(bitmask),
    m_min(min),
    m_max(max),
    m_actionGroup()
{
    setFlags(flags() | Qt::ItemIsEditable);
    QTreeItemBase::setData(COL_Value, Qt::EditRole, toString());
}

template<typename Bitmask, typename Enum>
void BitmaskTreeItem<Bitmask, Enum>::setData(int column, int role, const QVariant &value)
{
    if ((COL_Value == column) && (Qt::EditRole == role))
    {
        Bitmask newValue = static_cast<Bitmask>(value.toUInt());
        (void)m_game->commitData(m_ptr, &newValue, sizeof(Bitmask));
        QTreeItemBase::setData(COL_Value, role, toString());
    }
    else
    {
        QTreeItemBase::setData(column, role, value);
    }
}

template<typename Bitmask, typename Enum>
void BitmaskTreeItem<Bitmask, Enum>::addAction(Enum e)
{
    assert(m_actionGroup != 0);

    QString name = prettyQStr(e);
    if (!name.isEmpty() && (name[0] == '<') && !has(e))
    {
        // Skip <Unknown> entries, unless one of them is selected
    }
    else
    {
        QAction* action = new QAction(name, m_actionGroup);
        action->setCheckable(true);
        action->setData(QVariant((int)e));
        if (has(e))
        {
            action->setChecked(true);
        }
    }
}

template<typename Bitmask, typename Enum>
QList<QAction*> BitmaskTreeItem<Bitmask, Enum>::requestActions(QObject* parent)
{
    m_actionGroup = new QActionGroup(parent);
    m_actionGroup->setExclusive(false);
    for (Enum e = m_min; e < m_max; MoM::inc(e))
    {
        addAction(e);
    }
    return m_actionGroup->actions();
}

template<typename Bitmask, typename Enum>
void BitmaskTreeItem<Bitmask, Enum>::slotAction()
{
    Bitmask bitmask = 0;
    Enum e = m_min;
    for (int i = 0; i < m_actionGroup->actions().count(); ++i, MoM::inc(e))
    {
        if (m_actionGroup->actions().at(i)->isChecked())
        {
            bitmask |= (1 << i);
        }
    }
    setData(COL_Value, Qt::EditRole, QVariant((unsigned)bitmask));
}

template<typename Bitmask, typename Enum>
bool BitmaskTreeItem<Bitmask, Enum>::has(Enum e) const
{
    Bitmask mask = (1 << ((unsigned)e - (unsigned)m_min));
    return ((*m_ptr & mask) != 0);
}

template<typename Bitmask, typename Enum>
QString BitmaskTreeItem<Bitmask, Enum>::toString()
{
    QString result;
    for (Enum e = m_min; e < m_max; MoM::inc(e))
    {
        if (has(e))
        {
            if (!result.isEmpty())
            {
                result += ", ";
            }
            QString name = prettyQStr(e);
            name.replace("Immunity", "Imm");
            result += name;
        }
    }
    return result;
}

///////////////////////////////////////////

DialogMap::DialogMap(QWidget *parent) :
    QDialog(parent),
    m_sceneArcanus(new QMoMMapScene(MoM::PLANE_Arcanum, false)),
    m_sceneMyrror(new QMoMMapScene(MoM::PLANE_Myrror, false)),
    m_sceneBattle(new QMoMMapScene(MoM::ePlane_MAX, true)),
    m_timer(new QTimer),
    ui(new Ui::DialogOverlandMap)
{
    ui->setupUi(this);

    QMoMGamePtr game= MainWindow::getInstance()->getGame();
    if ((0 != game) && (game->isBattleInProgress()))
    {
        ui->comboBox_Plane->setCurrentIndex(3);
    }
    else
    {
        ui->comboBox_Plane->setCurrentIndex(1);
    }

    // Update view when game is changed or updated
    QObject::connect(MainWindow::getInstance(), SIGNAL(signal_gameChanged(QMoMGamePtr)), this, SLOT(slot_gameChanged(QMoMGamePtr)));
    QObject::connect(MainWindow::getInstance(), SIGNAL(signal_gameUpdated()), this, SLOT(slot_gameUpdated()));

    // Update view when checkbox is clicked
    QObject::connect(ui->checkBox_Cities, SIGNAL(clicked()), this, SLOT(slot_gameUpdated()));
    QObject::connect(ui->checkBox_EnemyUnits, SIGNAL(clicked()), this, SLOT(slot_gameUpdated()));
    QObject::connect(ui->checkBox_ExploredOnly, SIGNAL(clicked()), this, SLOT(slot_gameUpdated()));
    QObject::connect(ui->checkBox_Lairs, SIGNAL(clicked()), this, SLOT(slot_gameUpdated()));
    QObject::connect(ui->checkBox_Terrain, SIGNAL(clicked()), this, SLOT(slot_gameUpdated()));
    QObject::connect(ui->checkBox_TerrainBonuses, SIGNAL(clicked()), this, SLOT(slot_gameUpdated()));
    QObject::connect(ui->checkBox_TerrainChanges, SIGNAL(clicked()), this, SLOT(slot_gameUpdated()));
    QObject::connect(ui->checkBox_YourUnits, SIGNAL(clicked()), this, SLOT(slot_gameUpdated()));

    // Update view when items are inspected
    QObject::connect(m_sceneArcanus, SIGNAL(signal_tileChanged(MoM::MoMLocation)), this, SLOT(slot_tileChanged(MoM::MoMLocation)));
    QObject::connect(m_sceneMyrror, SIGNAL(signal_tileChanged(MoM::MoMLocation)), this, SLOT(slot_tileChanged(MoM::MoMLocation)));
    QObject::connect(m_sceneBattle, SIGNAL(signal_tileChanged(MoM::MoMLocation)), this, SLOT(slot_tileChanged(MoM::MoMLocation)));
    QObject::connect(m_sceneArcanus, SIGNAL(signal_tileSelected(MoM::MoMLocation,QList<QGraphicsItem*>)), this, SLOT(slot_tileSelected(MoM::MoMLocation,QList<QGraphicsItem*>)));
    QObject::connect(m_sceneMyrror, SIGNAL(signal_tileSelected(MoM::MoMLocation,QList<QGraphicsItem*>)), this, SLOT(slot_tileSelected(MoM::MoMLocation,QList<QGraphicsItem*>)));
    QObject::connect(m_sceneBattle, SIGNAL(signal_tileSelected(MoM::MoMLocation,QList<QGraphicsItem*>)), this, SLOT(slot_tileSelected(MoM::MoMLocation,QList<QGraphicsItem*>)));

    // Connect timers
    QObject::connect(m_timer.data(), SIGNAL(timeout()), this, SLOT(slot_timerActiveUnit()));

    // Force initialization
    slot_gameChanged(MainWindow::getInstance()->getGame());

    // Start timer
    m_timer->start(250);
}

DialogMap::~DialogMap()
{
    delete ui;
    delete m_sceneMyrror;
    delete m_sceneArcanus;
}

void DialogMap::addBattleUnitSubtree(QTreeWidget* treeWidget, Battle_Unit* battleUnit)
{
    assert(0 != battleUnit);
    int battleUnitNr = (int)(battleUnit - m_game->getBattleUnit(0));
    Unit* unit = m_game->getUnit(battleUnit->m_unitNr);
    if (0 == unit)
        return;
    QString text = QString("%0").arg(prettyQStr(unit->m_Unit_Type));
    if (battleUnit->m_Weapon_Type_Plus_1 > 1)
    {
        text += ", " + prettyQStr((eWeaponType)(battleUnit->m_Weapon_Type_Plus_1 - 1));
    }
    QTreeItemBase* qtreeUnit = new QTreeItemBase(m_game,
                                 QString("battle[%0] unit[%1]").arg(battleUnitNr).arg(battleUnit->m_unitNr),
                                 text);
    treeWidget->addTopLevelItem(qtreeUnit);

    qtreeUnit->addChild(new EnumTreeItem<eUnit_Type>(m_game, "Unit Type", &unit->m_Unit_Type, eUnit_Type_MAX));
    qtreeUnit->addChild(new EnumTreeItem<ePlayer>(m_game, "Owner", &battleUnit->m_Owner, ePlayer_MAX));
    qtreeUnit->addChild(new EnumTreeItem<eBattleUnitActive>(m_game, "Active", &battleUnit->m_Active, eBattleUnitActive_MAX));
    qtreeUnit->addChild(new EnumTreeItem<eBattleUnitTactic>(m_game, "Status", &battleUnit->m_Tactic, eBattleUnitTactic_MAX));
    qtreeUnit->addChild(new NumberTreeItem<int8_t>(m_game, "TargetID", &battleUnit->m_Target_BattleUnitID));
    qtreeUnit->addChild(new NumberTreeItem<int16_t>(m_game, "XPos", &battleUnit->m_xPos));
    qtreeUnit->addChild(new NumberTreeItem<int16_t>(m_game, "YPos", &battleUnit->m_yPos));
    qtreeUnit->addChild(new NumberTreeItem<int16_t>(m_game, "XPosHeaded", &battleUnit->m_xPosHeaded));
    qtreeUnit->addChild(new NumberTreeItem<int16_t>(m_game, "YPosHeaded", &battleUnit->m_yPosHeaded));
    qtreeUnit->addChild(new NumberTreeItem<uint8_t>(m_game, "HalfMovesLeft", &battleUnit->m_MoveHalves));
    qtreeUnit->addChild(new NumberTreeItem<uint8_t>(m_game, "CurFigures", &battleUnit->m_Current_Figures));
    qtreeUnit->addChild(new NumberTreeItem<uint8_t>(m_game, "HP figure", &battleUnit->m_Hitpoints_per_Figure));
    qtreeUnit->addChild(new NumberTreeItem<uint8_t>(m_game, "TotDamage", &battleUnit->m_cur_total_damage_GUESS));
    qtreeUnit->addChild(new NumberTreeItem<int8_t>(m_game, "FigDamage", &battleUnit->m_cur_figure_damage_GUESS));
    qtreeUnit->addChild(new NumberTreeItem<int8_t>(m_game, "Suppression", &battleUnit->m_Suppression));
    qtreeUnit->addChild(new NumberTreeItem<uint8_t>(m_game, "WeaponType", &battleUnit->m_Weapon_Type_Plus_1));
}

void DialogMap::addCitySubtree(QTreeWidget *treeWidget, MoMTerrain &momTerrain)
{
    MoM::City* city = momTerrain.getCity();
    if (0 != city)
    {
        int cityNr = (int)(city - m_game->getCity(0));
        Fortress* fortresses = m_game->getFortresses();
        Fortress* fortress = 0;
        if ((0 != fortresses) && equalLocation(fortresses[city->m_Owner], momTerrain.getLocation()))
        {
            fortress = &fortresses[city->m_Owner];
        }

        QString text = QString("%0 \"%1\"").arg(prettyQStr(city->m_Race)).arg(city->m_City_Name);
        if (0 != fortress)
        {
            text += ", fortress";
        }
        QTreeItemBase* qtreeItem = new QTreeItemBase(m_game,
            QString("City[%0]").arg(cityNr),
            text);
        treeWidget->addTopLevelItem(qtreeItem);

//        ptree->appendChild("m_City_Name", new QMoMTreeItem<char[14]>(rhs->m_City_Name));
        qtreeItem->addChild(new EnumTreeItem<eRace>(m_game, "Race", &city->m_Race, eRace_MAX));
        qtreeItem->addChild(new EnumTreeItem<ePlayer>(m_game, "Owner", &city->m_Owner, ePlayer_MAX));
        qtreeItem->addChild(new NumberTreeItem<uint8_t>(m_game, "Population", &city->m_Population));
        qtreeItem->addChild(new EnumTreeItem<eCity_Size>(m_game, "Size", &city->m_Size, eCity_Size_MAX));

//        ptree->appendChild("m_Number_of_farmers_allocated", new QMoMTreeItem<uint8_t>(&rhs->m_Number_of_farmers_allocated));
//        ptree->appendChild("m_PopulationDekaPop", new QMoMTreeItem<uint8_t>(&rhs->m_PopulationDekaPop));
//        ptree->appendChild("m_Player_as_bitmask_GUESS", new QMoMTreeItem<uint8_t>(&rhs->m_Player_as_bitmask_GUESS));
        qtreeItem->addChild(new EnumTreeItem<eProducing>(m_game, "Producing", &city->m_Producing, eProducing_MAX));
//        ptree->appendTree(constructTreeItem(&rhs->m_Building_Status, "m_Building_Status"), "");
//        ptree->appendTree(constructTreeItem(&rhs->m_City_Enchantments, "m_City_Enchantments"), "");
//        ptree->appendChild("m_Nightshade", new QMoMTreeItem<eYesNo8>(&rhs->m_Nightshade));
//        ptree->appendChild("m_Hammers", new QMoMTreeItem<uint8_t>(&rhs->m_Hammers));
        qtreeItem->addChild(new NumberTreeItem<uint16_t>(m_game, "HammersAccumulated", &city->m_HammersAccumulated));
//        ptree->appendChild("m_Coins", new QMoMTreeItem<uint8_t>(&rhs->m_Coins));
//        ptree->appendChild("m_Maintenance", new QMoMTreeItem<uint8_t>(&rhs->m_Maintenance));
//        ptree->appendChild("m_Mana_cr", new QMoMTreeItem<uint8_t>(&rhs->m_Mana_cr));
//        ptree->appendChild("m_Research", new QMoMTreeItem<uint8_t>(&rhs->m_Research));
//        ptree->appendChild("m_Food_Produced", new QMoMTreeItem<uint8_t>(&rhs->m_Food_Produced));
//        ptree->appendChild("m_Road_Connection_GUESS", new QMoMTreeItem<int8_t>(&rhs->m_Road_Connection_GUESS));
    }
}

void DialogMap::addLairSubtree(QTreeWidget *treeWidget, MoMTerrain &momTerrain)
{
    MoM::Tower_Node_Lair* lair = momTerrain.getLair();
    if (0 != lair)
    {
        int lairNr = (int)(lair - m_game->getLair(0));
        MoM::Node_Attr* nodeAttr = MoM::MoMController(m_game.data()).findNodeAttrAtLocation(MoM::MoMLocation(*lair));

        QString text = QString("%0").arg(prettyQStr(lair->m_Type));
        if ((0 != nodeAttr) && (MoM::PLAYER_Dismissed_Deceased != nodeAttr->m_Owner))
        {
            text += QString(",player %0").arg(prettyQStr(nodeAttr->m_Owner));
        }
        QTreeItemBase* qtreeItem = new QTreeItemBase(m_game,
            QString("Lair[%0]").arg(lairNr),
            text);
        treeWidget->addTopLevelItem(qtreeItem);

        qtreeItem->addChild(new EnumTreeItem<eTower_Node_Lair_Status>(m_game, "Status", &lair->m_Status, eTower_Node_Lair_Status_MAX));
        qtreeItem->addChild(new EnumTreeItem<eTower_Node_Lair_Type>(m_game, "Type", &lair->m_Type, eTower_Node_Lair_Type_MAX));

        qtreeItem->addChild(new EnumTreeItem<eUnit_Type>(m_game, "Inhabitant1", &lair->m_Inhabitant1.m_Inhabitant, eUnit_Type_MAX));
        qtreeItem->addChild(new NumberTreeItem<uint16_t>(m_game, "Initial1", (uint16_t*)&lair->m_Inhabitant1, 0xF000));
        qtreeItem->addChild(new NumberTreeItem<uint16_t>(m_game, "Remaining1", (uint16_t*)&lair->m_Inhabitant1, 0x0F00));
        qtreeItem->addChild(new NumberTreeItem<uint8_t>(m_game, "Aware1", (uint8_t*)&lair->m_Flags, 0x02));
        if ((eUnit_Type)0 != lair->m_Inhabitant2.m_Inhabitant)
        {
            qtreeItem->addChild(new EnumTreeItem<eUnit_Type>(m_game, "Inhabitant2", &lair->m_Inhabitant2.m_Inhabitant, eUnit_Type_MAX));
            qtreeItem->addChild(new NumberTreeItem<uint16_t>(m_game, "Initial2", (uint16_t*)&lair->m_Inhabitant2, 0xF000));
            qtreeItem->addChild(new NumberTreeItem<uint16_t>(m_game, "Remaining2", (uint16_t*)&lair->m_Inhabitant2, 0x0F00));
            qtreeItem->addChild(new NumberTreeItem<uint8_t>(m_game, "Aware2", (uint8_t*)&lair->m_Flags, 0x04));
        }
        if (0 != lair->m_Reward_Gold)
        {
            qtreeItem->addChild(new NumberTreeItem<uint16_t>(m_game, "Reward Gold", &lair->m_Reward_Gold));
        }
        if (0 != lair->m_Reward_Mana)
        {
            qtreeItem->addChild(new NumberTreeItem<uint16_t>(m_game, "Reward Mana", &lair->m_Reward_Mana));
        }
        qtreeItem->addChild(new EnumTreeItem<eReward_Specials>(m_game, "Reward Specials", &lair->m_Reward_Specials, eReward_Specials_MAX));
        qtreeItem->addChild(new NumberTreeItem<uint8_t>(m_game, "PrisonerPresent", (uint8_t*)&lair->m_Flags, 0x01));
        for (unsigned i = 0; (i < lair->m_Item_Rewards) && (i < 3); ++i)
        {
            if (lair->m_Item_Value[i] != 0)
            {
                qtreeItem->addChild(new NumberTreeItem<uint16_t>(m_game, QString("Item Value[%0]").arg(i), &lair->m_Item_Value[i]));
            }
        }

        if (0 != nodeAttr)
        {
            qtreeItem->addChild(new EnumTreeItem<ePlayer>(m_game, "Owner", &nodeAttr->m_Owner, ePlayer_MAX));
            qtreeItem->addChild(new NumberTreeItem<uint8_t>(m_game, "Power node", &nodeAttr->m_Power_Node));
        }
    }
}

void DialogMap::addTerrainSubtree(QTreeWidget* treeWidget, MoMTerrain& momTerrain)
{
    const MoMLocation& loc = momTerrain.getLocation();

    treeWidget->addTopLevelItem(new QTreeItemBase(m_game,
        "Location",
        QString("%0:(%1,%2)").arg(prettyQStr(loc.m_Plane)).arg(loc.m_XPos).arg(loc.m_YPos)));

    QTreeItemBase* qtreeTerrain = new QTreeItemBase(m_game, "Terrain", "");
    ui->treeWidget_Tile->addTopLevelItem(qtreeTerrain);
    if (0 != m_game->getTerrainType(loc))
    {
        MoM::eTerrainType terrainType = *m_game->getTerrainType(loc);
        QString text = QString("%0 (%1)")
                .arg(prettyQStr(MoM::MoMTerrain::getTerrainCategory(terrainType)))
                .arg((int)terrainType);
        if ((0 != m_game->getTerrainBonus(loc)) && (MoM::DEPOSIT_no_deposit != *m_game->getTerrainBonus(loc)))
        {
            text += ", " + prettyQStr(*m_game->getTerrainBonus(loc));
        }
        qtreeTerrain->setText(1, text);
    }

    if (0 != m_game->getTerrainType(loc))
    {
        qtreeTerrain->addChild(new EnumTreeItem<MoM::eTerrainType>(m_game, "TerrainType", m_game->getTerrainType(loc), MoM::eTerrainType_MAX));
    }
    if (0 != m_game->getTerrainBonus(loc))
    {
        qtreeTerrain->addChild(new EnumTreeItem<MoM::eTerrainBonusDeposit>(m_game, "TerrainBonus", m_game->getTerrainBonus(loc), MoM::eTerrainBonusDeposit_MAX));
    }
    if (0 != m_game->getTerrainChange(loc))
    {
        qtreeTerrain->addChild(new BitmaskTreeItem<uint8_t, MoM::eTerrainChange>(m_game, "TerrainChange", (uint8_t*)m_game->getTerrainChange(loc), (MoM::eTerrainChange)0, MoM::eTerrainChange_MAX));
    }
    if (0 != m_game->getTerrainExplored(loc))
    {
        qtreeTerrain->addChild(new NumberTreeItem<uint8_t>(m_game, "Explored", m_game->getTerrainExplored(loc)));
    }
    if (0 != m_game->getTerrainLandMassID(loc))
    {
        qtreeTerrain->addChild(new NumberTreeItem<uint8_t>(m_game, "LandMassID", m_game->getTerrainLandMassID(loc)));
    }
    if (0 == m_game->getTerrainMovement(loc, MoM::MOVEMENT_Unused))
    {
        qtreeTerrain->addChild(new QTreeItemBase(m_game, "Moves", "(Not accessible->no road effect)"));
    }
    else
    {
        qtreeTerrain->addChild(new NumberTreeItem<int8_t>(m_game, "MoveUnused", m_game->getTerrainMovement(loc, MoM::MOVEMENT_Unused)));
        qtreeTerrain->addChild(new NumberTreeItem<int8_t>(m_game, "MoveWalk", m_game->getTerrainMovement(loc, MoM::MOVEMENT_Walking)));
        qtreeTerrain->addChild(new NumberTreeItem<int8_t>(m_game, "MoveForester", m_game->getTerrainMovement(loc, MoM::MOVEMENT_Forester)));
        qtreeTerrain->addChild(new NumberTreeItem<int8_t>(m_game, "MoveMountaineer", m_game->getTerrainMovement(loc, MoM::MOVEMENT_Mountaineer)));
        qtreeTerrain->addChild(new NumberTreeItem<int8_t>(m_game, "MoveSwimming", m_game->getTerrainMovement(loc, MoM::MOVEMENT_Swimming)));
        qtreeTerrain->addChild(new NumberTreeItem<int8_t>(m_game, "MoveSailing", m_game->getTerrainMovement(loc, MoM::MOVEMENT_Sailing)));
    }
}

void DialogMap::addUnitSubtree(QTreeWidgetItem *treeWidgetItem, Unit* unit)
{
    assert(0 != unit);
    int unitNr = (int)(unit - m_game->getUnit(0));
    QString text = QString("%0").arg(prettyQStr(unit->m_Unit_Type));
    if (0 != unit->m_Weapon_Mutation.s.Weapon_Type)
    {
        text += ", " + prettyQStr((eWeaponType)unit->m_Weapon_Mutation.s.Weapon_Type);
    }
    QTreeItemBase* qtreeUnit = new QTreeItemBase(m_game,
        QString("unit[%0]").arg(unitNr),
        text);
    treeWidgetItem->addChild(qtreeUnit);

    qtreeUnit->addChild(new EnumTreeItem<eUnit_Type>(m_game, "Unit Type", &unit->m_Unit_Type, eUnit_Type_MAX));
    qtreeUnit->addChild(new EnumTreeItem<ePlayer>(m_game, "Owner", &unit->m_Owner, ePlayer_MAX));
    qtreeUnit->addChild(new NumberTreeItem<int8_t>(m_game, "HalfMovesTotal", &unit->m_Moves_Total));
    qtreeUnit->addChild(new NumberTreeItem<int8_t>(m_game, "HalfMovesLeft", &unit->m_Moves_Left));
    qtreeUnit->addChild(new EnumTreeItem<eUnit_Active>(m_game, "Active", &unit->m_Active, eUnit_Active_MAX));
    qtreeUnit->addChild(new EnumTreeItem<eUnit_Status8>(m_game, "Status", &unit->m_Status, eUnit_Status8_MAX));
    qtreeUnit->addChild(new NumberTreeItem<int8_t>(m_game, "destXPos", &unit->m_XPos_of_destination));
    qtreeUnit->addChild(new NumberTreeItem<int8_t>(m_game, "destYPos", &unit->m_YPos_of_destination));
    qtreeUnit->addChild(new EnumTreeItem<eLevel>(m_game, "Level", &unit->m_Level, eLevel_MAX));
    qtreeUnit->addChild(new NumberTreeItem<int16_t>(m_game, "Experience", &unit->m_Experience));
    qtreeUnit->addChild(new NumberTreeItem<int8_t>(m_game, "Damage", &unit->m_Damage));
    qtreeUnit->addChild(new NumberTreeItem<uint8_t>(m_game, "Grouping", &unit->m_Grouping));
    if (1 != unit->m_Scouting)
    {
        qtreeUnit->addChild(new NumberTreeItem<uint8_t>(m_game, "Scouting", &unit->m_Scouting));
    }
//    ptree->appendTree(constructTreeItem(&rhs->m_Weapon_Mutation, "m_Weapon_Mutation"), "");
    qtreeUnit->addChild(new BitmaskTreeItem<uint32_t, eUnitEnchantment>(m_game, "Enchantments", &unit->m_Unit_Enchantment.bits, (eUnitEnchantment)0, eUnitEnchantment_MAX));
    if (unit->m_Road_Building_left_to_complete > 0)
    {
        qtreeUnit->addChild(new NumberTreeItem<int8_t>(m_game, "roadLeft", &unit->m_Road_Building_left_to_complete));
        qtreeUnit->addChild(new NumberTreeItem<int8_t>(m_game, "fromXPos", &unit->m_XPos_Road_Building_from));
        qtreeUnit->addChild(new NumberTreeItem<int8_t>(m_game, "fromYPos", &unit->m_YPos_Road_Building_from));
    }

}

void DialogMap::on_comboBox_Plane_currentIndexChanged(int index)
{
    switch (index)
    {
    case 1:
        ui->graphicsView->setScene(m_sceneArcanus);
        break;
    case 2:
        ui->graphicsView->setScene(m_sceneMyrror);
        break;
    case 3:
        ui->graphicsView->setScene(m_sceneBattle);
        break;
    default:
        ui->graphicsView->setScene(0);
        break;
    }
}

void DialogMap::on_treeWidget_Tile_customContextMenuRequested(const QPoint &pos)
{
    qDebug() << "on_treeWidget_Tile_customContextMenuRequested" << pos;
    QTreeWidgetItem* pItem = ui->treeWidget_Tile->currentItem();

    QMenu contextMenu;
    QAction* action = contextMenu.addAction("Address calculator");
    action->connect(action, SIGNAL(triggered()), this, SLOT(slot_addressCalculator()));

    QTreeItemBase* pMoMItem = dynamic_cast<QTreeItemBase*>(pItem);
    if (0 != pMoMItem)
    {
        QList<QAction*> actions = pMoMItem->requestActions(&contextMenu);
        if (!actions.isEmpty())
        {
            contextMenu.addSeparator();
        }
        contextMenu.addActions(actions);
        foreach(QAction* action, actions)
        {
            connect(action, SIGNAL(triggered()), this, SLOT(slot_itemAction()));
        }
    }

    contextMenu.exec(ui->treeWidget_Tile->mapToGlobal(pos));
}

void DialogMap::on_verticalSlider_Zoom_valueChanged(int value)
{
    double scale = 1.0 + value / 100.0;
    if (value < 0)
    {
        scale = std::pow(2.0, value / 100.0);
    }

    ui->graphicsView->resetTransform();
    ui->graphicsView->scale(scale, scale);
}

void DialogMap::slot_addressCalculator()
{
    DialogCalculatorAddress* dialog = new DialogCalculatorAddress(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
//    QObject::connect(this, SIGNAL(signal_addressChanged(const void*)), dialog, SLOT(slot_addressChanged(const void*)));
    dialog->show();

    QTreeWidgetItem* pItem = ui->treeWidget_Tile->currentItem();
    QTreeItemBase* pMoMItem = dynamic_cast<QTreeItemBase*>(pItem);
    if (0 != pMoMItem)
    {
        dialog->slot_addressChanged(pMoMItem->getMoMPointer());
    }
}

void DialogMap::slot_gameChanged(const QMoMGamePtr& game)
{
    m_game = game;

    slot_gameUpdated();
}

void DialogMap::slot_gameUpdated()
{
    // Reset game
    m_sceneArcanus->clear();
    m_sceneMyrror->clear();
    m_sceneBattle->clear();

    if (m_game.isNull())
        return;

    QMoMMapScene* scene[MoM::ePlane_MAX] = { m_sceneArcanus, m_sceneMyrror };

    // Show overland terrain
    for (MoM::ePlane plane = (MoM::ePlane)0; MoM::toUInt(plane) < MoM::ePlane_MAX; MoM::inc(plane))
    {
        for (int y = 0; y < (int)MoM::gMAX_MAP_ROWS; ++y)
        {
            for (int x = 0; x < (int)MoM::gMAX_MAP_COLS; ++x)
            {
                MoM::QMoMMapTile* mapTile = new MoM::QMoMMapTile(MoMLocation(x, y, plane, MoMLocation::MAP_overland));
                if (ui->checkBox_Terrain->isChecked())
                {
                    mapTile->setTerrainType(m_game->getTerrainType(plane, x, y));
                }
                if (ui->checkBox_TerrainBonuses->isChecked())
                {
                    mapTile->setTerrainBonus(m_game->getTerrainBonus(plane, x, y));
                }
                if (ui->checkBox_TerrainChanges->isChecked())
                {
                    mapTile->setTerrainChange(m_game->getTerrainChange(plane, x, y));
                }
                if (ui->checkBox_ExploredOnly->isChecked())
                {
                    mapTile->setTerrainExplored(m_game->getTerrainExplored(plane, x, y));
                }
                scene[plane]->addItemAtLocation(mapTile, mapTile->getLocation());
            }
        }
    }


    // Update items that are not fixed

    // Show units
    for (int unitNr = 0; (unitNr < m_game->getNrUnits()) && (MoM::toUInt(unitNr) < MoM::gMAX_UNITS); ++unitNr)
    {
        MoM::Unit* unit = m_game->getUnit(unitNr);
        if ((0 != unit)
                && MoM::inRange(unit->m_Unit_Type, MoM::eUnit_Type_MAX)
                && MoM::inRange(unit->m_Plane, MoM::ePlane_MAX))
        {
            if (!ui->checkBox_YourUnits->isChecked() && (unit->m_Owner == MoM::PLAYER_YOU))
                continue;
            if (!ui->checkBox_EnemyUnits->isChecked() && (unit->m_Owner != MoM::PLAYER_YOU))
                continue;

            QMoMUnitPtr momUnit(new MoMUnit(m_game.data()));
            momUnit->changeUnit(unit);

            MoM::QMoMUnitTile* unitTile = new MoM::QMoMUnitTile;
            unitTile->setGame(m_game);
            unitTile->setUnit(momUnit);

            scene[unit->m_Plane]->addItemAtLocation(unitTile, MoMLocation(*unit, MoMLocation::MAP_overland));
            unitTile->setToolTip(momUnit->getDisplayName().c_str());
        }
    }

    // Show lairs
    if (ui->checkBox_Lairs->isChecked())
    {
        QRectF rectfTile = MoM::QMoMMapTile(MoMLocation()).boundingRect();
        for (int lairNr = 0; (MoM::toUInt(lairNr) < MoM::gMAX_NODES_LAIRS_TOWERS); ++lairNr)
        {
            MoM::Tower_Node_Lair* lair = m_game->getLair(lairNr);
            if (0 == lair)
                continue;
            QPixmap pixmapLair = MoM::QMoMResources::instance().getPixmap(lair->m_Type, 1);
            if (MoM::inRange(lair->m_Type, MoM::eTower_Node_Lair_Type_MAX)
                    && MoM::inRange(lair->m_Plane, MoM::ePlane_MAX)
                    && !pixmapLair.isNull())
            {
                QGraphicsItem* mapLairItem = scene[lair->m_Plane]->addPixmapAtLocation(pixmapLair, MoMLocation(*lair, MoMLocation::MAP_overland));
                mapLairItem->setScale(rectfTile.width() / pixmapLair.width());
                mapLairItem->setToolTip(prettyQStr(lair->m_Type));
            }
        }
    }

    // Show cities
    if (ui->checkBox_Cities->isChecked())
    {
        QRectF rectfTile = MoM::QMoMMapTile(MoMLocation()).boundingRect();
        for (int cityNr = 0; (cityNr < m_game->getNrCities()) && (MoM::toUInt(cityNr) < MoM::gMAX_CITIES); ++cityNr)
        {
            MoM::City* city = m_game->getCity(cityNr);
            Wizard* wizard = m_game->getWizard(city->m_Owner);
            if ((0 == city) || (0 == wizard))
                continue;
            QPixmap pixmapCity = MoM::QMoMResources::instance().getPixmap(city->m_Size, 1, wizard->m_BannerColor);
            if (MoM::inRange(city->m_Plane, MoM::ePlane_MAX)
                    && !pixmapCity.isNull())
            {
                QGraphicsPixmapItem* mapCityItem = scene[city->m_Plane]->addPixmapAtLocation(pixmapCity, MoMLocation(*city, MoMLocation::MAP_overland));
                // city pixmap is about twice as big as a regular tile
                QPointF offset = mapCityItem->offset();
                offset.rx() += (rectfTile.width() - pixmapCity.width()) / 2;
                offset.ry() += (rectfTile.height() - pixmapCity.height()) / 2;
                mapCityItem->setOffset(offset);
                mapCityItem->setToolTip(QString("%0 \"%1\"").arg(prettyQStr(city->m_Race)).arg(city->m_City_Name));
            }
        }
    }

    Battlefield* battlefield = m_game->getBattlefield();
    MoM::Battle_Unit* battleUnits = m_game->getBattleUnit(0);
    if ((0 != battlefield) && (0 != battleUnits))
    {
        // Show battle terrain
        for (int y = 0; y < (int)MoM::gMAX_BATTLE_ROWS; ++y)
        {
            for (int x = 0; x < (int)MoM::gMAX_BATTLE_COLS; ++x)
            {
                MoM::QMoMMapTile* mapTile = new MoM::QMoMMapTile(MoMLocation(x, y, (ePlane)battlefield->m_Plane, MoMLocation::MAP_battle));
                if (ui->checkBox_Terrain->isChecked())
                {
                    int index = x + y * gMAX_BATTLE_COLS;
                    mapTile->setTerrainBattle(&battlefield->m_Terrain[index]);
                }
                m_sceneBattle->addItemAtLocation(mapTile, mapTile->getLocation());
            }
        }

        // Show central structure
        QPixmap pixmapStructure = MoM::QMoMResources::instance().getPixmap(battlefield->m_Central_structure);
        QGraphicsPixmapItem* itemStructure = m_sceneBattle->addPixmapAtLocation(pixmapStructure, MoMLocation(6, 11, (ePlane)battlefield->m_Plane, MoMLocation::MAP_battle));
        QPointF offset = itemStructure->offset();
        if (MoM::CENTRALSTRUCTURE_city_grid == battlefield->m_Central_structure)
        {
            offset.ry() += 2 * 16;
        }
        else if ((MoM::CENTRALSTRUCTURE_sorcery_node == battlefield->m_Central_structure)
                 || (MoM::CENTRALSTRUCTURE_nature_node == battlefield->m_Central_structure))
        {
            offset.ry() += 16;
        }
        else
        {
            int zvalue = m_sceneBattle->convertScenePosToZValue(itemStructure->pos());
            itemStructure->setZValue(zvalue);
        }
        itemStructure->setOffset(offset);

        // Show battle units
        int nrBattleUnits = m_game->getNrBattleUnits();
        for (int battleUnitNr = 0; battleUnitNr < nrBattleUnits; ++battleUnitNr)
        {
            MoM::Battle_Unit* battleUnit = m_game->getBattleUnit(battleUnitNr);
            if (0 == battleUnit)
                break;
            MoMLocation loc(battleUnit->m_xPos, battleUnit->m_yPos, (ePlane)battlefield->m_Plane, MoMLocation::MAP_battle);

            QMoMUnitPtr momUnit(new MoMUnit(m_game.data()));
            momUnit->changeUnit(battleUnit);

            MoM::QMoMUnitTile* unitTile = new MoM::QMoMUnitTile(true);
            unitTile->setGame(m_game);
            unitTile->setUnit(momUnit);

            m_sceneBattle->addItemAtLocation(unitTile, loc);
            int zvalue = m_sceneBattle->convertScenePosToZValue(unitTile->pos());
            unitTile->setZValue(zvalue);
            unitTile->setToolTip(momUnit->getDisplayName().c_str());

            QPointF pos;
            m_sceneBattle->convertLocationToScenePos(loc, pos);
            pos.rx() -= 16;
            pos.ry() -= 30;
            QGraphicsSimpleTextItem* textItem = m_sceneBattle->addSimpleText(QString("%0").arg(battleUnitNr));
            textItem->setFont(QMoMResources::g_FontSmall);
            textItem->setPos(pos);

            QString text = prettyQStr(battleUnit->m_Tactic);
            textItem = m_sceneBattle->addSimpleText(QString("%0").arg(text[0]));
            textItem->setFont(QMoMResources::g_FontSmall);
            pos.rx() += textItem->boundingRect().width() + 4;
            textItem->setPos(pos);

            if (MoM::toUInt(battleUnit->m_Target_BattleUnitID) < (unsigned)nrBattleUnits)
            {
                MoM::Battle_Unit* targetUnit = &battleUnits[battleUnit->m_Target_BattleUnitID];
                MoMLocation locTarget(targetUnit->m_xPos, targetUnit->m_yPos, (ePlane)battlefield->m_Plane, MoMLocation::MAP_battle);
                QPointF ptBegin;
                QPointF ptEnd;
                m_sceneBattle->convertLocationToScenePos(loc, ptBegin);
                m_sceneBattle->convertLocationToScenePos(locTarget, ptEnd);
                ptBegin.ry() -= 8;
                ptEnd.ry() -= 8;
                m_sceneBattle->addLine(QLineF(ptBegin, ptEnd), QPen(Qt::darkRed));
            }
        }

        // Central structure at (6,11)
        // City walls between (5,10) and (8,13)
        // Gate at (8,12)

        static const MoMLocation wallLocations[14] =
        {
            MoMLocation(5, 10),
            MoMLocation(5, 11),
            MoMLocation(5, 12),
            MoMLocation(5, 13),
            MoMLocation(6, 10),
            MoMLocation(7, 10),
            MoMLocation(8, 10),
            MoMLocation(6, 13),
            MoMLocation(7, 13),
            MoMLocation(8, 13),
            MoMLocation(8, 11),
            MoMLocation(8, 12), // Gate

            MoMLocation(5, 13), // Extra for fire/darkness
            MoMLocation(8, 10), // Extra for fire/darkness
        };

        if (battlefield->m_City_Walls)
        {
            for (int i = 0; i < 12; ++i)
            {
                MoM::eCityWall wall = (MoM::eCityWall)i;
                MoMLocation loc = wallLocations[i];
                int wholeIndex = (loc.m_XPos - 5) + (loc.m_YPos - 10) * 4;
                if (0 != battlefield->m_Wall_present_4x4[wholeIndex])
                {
                    bool broken = (2 == battlefield->m_Wall_present_4x4[wholeIndex]);
                    QPixmap pixmapWall = MoM::QMoMResources::instance().getPixmap(wall, 1, broken);
                    (void)m_sceneBattle->addPixmapAtLocation(pixmapWall, wallLocations[i]);
                }
            }
        }
        if (battlefield->m_Wall_of_Fire)
        {
            for (int i = 0; i < 14; ++i)
            {
                MoM::eCityWall wall = (MoM::eCityWall)(i + CITYWALL_walloffire_first);
                QPixmap pixmapWall = MoM::QMoMResources::instance().getPixmap(wall);
                (void)m_sceneBattle->addPixmapAtLocation(pixmapWall, wallLocations[i]);
            }
        }
        if (battlefield->m_Wall_of_Darkness)
        {
            for (int i = 0; i < 14; ++i)
            {
                MoM::eCityWall wall = (MoM::eCityWall)(i + CITYWALL_wallofdarkness_first);
                QPixmap pixmapWall = MoM::QMoMResources::instance().getPixmap(wall);
                (void)m_sceneBattle->addPixmapAtLocation(pixmapWall, wallLocations[i]);
            }
        }

        // Show battlefield menubar (numbers from IDA)
        m_sceneBattle->addRect(m_sceneBattle->sceneRect(), QPen(Qt::black));
        QPixmap pixmapMenubar = MoM::QMoMResources::instance().getPixmap(MoM::LBXRecordID("BACKGRND", 3));
        QGraphicsPixmapItem* itemMenubar = m_sceneBattle->addPixmap(pixmapMenubar);
        itemMenubar->setPos(0, 164);
    }
}

void DialogMap::slot_itemAction()
{
    QTreeWidgetItem* pItem = ui->treeWidget_Tile->currentItem();
    QTreeItemBase* pMoMItem = dynamic_cast<QTreeItemBase*>(pItem);
    if (0 != pMoMItem)
    {
        pMoMItem->slotAction();
    }
}

void DialogMap::slot_tileChanged(const MoM::MoMLocation& loc)
{
    ui->label_Location->setText(QString("Location: (%1,%2)").arg(loc.m_XPos).arg(loc.m_YPos));
}

void DialogMap::slot_tileSelected(const MoM::MoMLocation &loc, const QList<QGraphicsItem *> &graphicItems)
{
    qDebug() << QString("slot_tileSelected(%0:(%1,%2), %3 items").arg(prettyQStr(loc.m_Plane)).arg(loc.m_XPos).arg(loc.m_YPos).arg(graphicItems.count());

    ui->treeWidget_Tile->clear();

    MoM::MoMTerrain momTerrain(m_game.data());
    momTerrain.setLocation(loc);

    addTerrainSubtree(ui->treeWidget_Tile, momTerrain);
    addLairSubtree(ui->treeWidget_Tile, momTerrain);
    addCitySubtree(ui->treeWidget_Tile, momTerrain);

    std::vector<int> units = momTerrain.getUnits();
    if (units.size() > 0)
    {
        QTreeItemBase* qtreeItem = new QTreeItemBase(m_game, 
            QString("Units"), 
            QString("%0 (player %1)").arg(units.size()).arg(prettyQStr(m_game->getUnit(units[0])->m_Owner)));
        ui->treeWidget_Tile->addTopLevelItem(qtreeItem);

        for (size_t i = 0; i < units.size(); ++i)
        {
            addUnitSubtree(qtreeItem, m_game->getUnit(units[i]));
        }
    }

    if (loc.m_Plane == ePlane_MAX)
    {
        for (int battleUnitNr = 0; battleUnitNr < m_game->getNrBattleUnits(); ++battleUnitNr)
        {
            Battle_Unit* battleUnit = m_game->getBattleUnit(battleUnitNr);
            if (0 == battleUnit)
                break;
            if ((loc.m_XPos == battleUnit->m_xPos) && (loc.m_YPos == battleUnit->m_yPos))
            {
                addBattleUnitSubtree(ui->treeWidget_Tile, battleUnit);
            }
        }
    }
}

void DialogMap::slot_timerActiveUnit()
{
    if (m_game.isNull() || (0 == m_game->getGameData_WizardsExe()))
        return;
    int unitNrActive = m_game->getGameData_WizardsExe()->m_UnitNr_Active;
    MoM::Unit* unit = m_game->getUnit(unitNrActive);
    if (0 == unit)
        return;
    // TODO
//    QGraphicsItem* qItem = lookup(unit);
//    if (0 != qItem)
//    {
//        qItem->setVisible(!qItem->isVisible());
//    }
}

}
