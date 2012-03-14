// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include <QtGui>

#include <sstream>

#include <MoMGameCustom.h>
#include <MoMGenerated.h>
#include <MoMLbxBase.h>
#include <MoMutility.h>
#include <MoMExeWizards.h>
#include <QMoMCommon.h>
#include <QMoMGenerated.h>
#include "QMoMResources.h"

#include "unitmodel.h"

using MoM::QMoMResources;

// TODO: Remove all (other) references of m_game from this file
MoM::MoMGameBase* TreeItemBase::m_game = 0;


UnitModel::UnitModel(QObject *parent) :
    QAbstractItemModel(parent),
    m_rootItem(0)
{
    setupModelData(0);
}

void UnitModel::setGame(MoM::MoMGameBase* game)
{
    setupModelData(game);
}

int UnitModel::columnCount(const QModelIndex& /*parent*/) const
{
    return m_columnCount;
}

QVariant UnitModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    TreeItemBase* item = reinterpret_cast<TreeItemBase*> (index.internalPointer());

    return item->data(role);
}

Qt::ItemFlags UnitModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    TreeItemBase* item = reinterpret_cast<TreeItemBase*> (index.internalPointer());
    return item->flags();
}

QVariant UnitModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    QVariant header;
    if ((orientation == Qt::Horizontal) && (role == Qt::DisplayRole))
    {
        switch (section)
        {
        case 0:
            header = tr("Feature");
            break;
        case 1:
            header = tr("Value");
            break;
        case 2:
            header = tr("Comment");
            break;
        default:
            break;
        }
    }
    //    else if ((orientation == Qt::Horizontal) && (role == Qt::FontRole))
    //    {
    //        header = QFont("Monotype Corsiva", 12);
    //    }
    else
    {
        // Nothing to do
    }
    return header;
}

QModelIndex UnitModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    TreeItemBase *parentItem;

    if (!parent.isValid())
        parentItem = m_rootItem;
    else
        parentItem = static_cast<TreeItemBase*> (parent.internalPointer());

    TreeItemBase *childItem = parentItem->child(row, column);
    if (childItem)
    {
        return createIndex(row, column, childItem);
    }
    else
    {
        return QModelIndex();
    }
}

QModelIndex UnitModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeItemBase *childItem = static_cast<TreeItemBase*> (index.internalPointer());
    TreeItemBase *parentItem = childItem->parent();

    if (parentItem == m_rootItem)
    {
        return QModelIndex();
    }
    else
    {
        return createIndex(parentItem->row(), 0, parentItem);
    }
}

int UnitModel::rowCount(const QModelIndex &parent) const
{
    TreeItemBase *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = m_rootItem;
    else
        parentItem = static_cast<TreeItemBase*> (parent.internalPointer());

    if (0 == parentItem)
    {
        return 0;
    }
    else
    {
        return parentItem->rowCount();
    }
}

bool UnitModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
        TreeItemBase* item = reinterpret_cast<TreeItemBase*> (index.internalPointer());
        item->setData(value, role);
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

void UnitModel::update()
{
    setupModelData(TreeItemBase::game());
}

void UnitModel::removeUnusedRows(int toprow, TreeItemBase* ptree, int firstUnusedRow)
{
    if (ptree->rowCount() > firstUnusedRow)
    {
        beginRemoveRows(this->createIndex(toprow, 0, ptree), firstUnusedRow, ptree->rowCount() - 1);
        ptree->removeRows(firstUnusedRow, ptree->rowCount() - 1);
        endRemoveRows();
    }
}


void update_Battlefield(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row)
{
    if (0 == game)
        return;
    MoM::Battlefield* pBattlefield = game->getBattlefield();

    if (row >= ptree->rowCount())
    {
        ptree->setChild(row, 0, constructTreeItem(pBattlefield, ""));
    }
    ptree->child(row, 0)->setData(toQStr("Battlefield"), Qt::UserRole);
    if ((0 != game) && (0 != game->getDataSegment()))
    {
        const MoM::EXE_Reloc& addr = game->getDataSegment()->m_WizardsExe_Pointers.addr_Battlefield;
        ptree->child(row, 1)->setData(toQStr(addr), Qt::EditRole);
    }
    else
    {
        ptree->child(row, 1)->setData(QString(), Qt::EditRole);
    }
    ptree->child(row, 2)->setData(QString(), Qt::EditRole);

    ++row;
}

void update_Battle_Unit_View(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row)
{
    if (0 == game)
        return;
    MoM::Battle_Unit* pBattle_Unit_View = game->getBattle_Unit_View();
    if (0 == pBattle_Unit_View)
        return;

    if (row >= ptree->rowCount())
    {
        ptree->setChild(row, 0, constructTreeItem(pBattle_Unit_View, ""));
    }
    QString id;
    int unitNr = pBattle_Unit_View->m_unitNr;
    if ((unitNr >= 0) && (unitNr < game->getNrUnits()) && (unitNr < (int)MoM::gMAX_UNITS))
    {
        MoM::Unit* unit = game->getUnit(unitNr);
        if (0 != unit)
        {
            id = toQStr(unit->m_Unit_Type);
        }
    }
    else
    {
        id = toQStr(pBattle_Unit_View->m_Race_Code);
    }
    ptree->child(row, 0)->setData(id, Qt::UserRole);
    ptree->child(row, 1)->setData(toQStr(pBattle_Unit_View->m_Owner), Qt::UserRole);
    ptree->child(row, 2)->setData(QString(), Qt::EditRole);

    ++row;
}

void update_Battle_Units(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row)
{
    if (0 == game)
        return;
    MoM::Battle_Unit* pBattleUnits = game->getBattle_Units();
    if (0 == pBattleUnits)
        return;
    if (0 == game->getNumber_of_Battle_Units())
        return;
    int nrBattle_Units = *game->getNumber_of_Battle_Units();

    if (row >= ptree->rowCount())
    {
        ptree->appendChild("m_Number_of_Battle_Units", new TreeItem<uint16_t>(game->getNumber_of_Battle_Units()));
    }
    row++;

    for (int i = 0; (i < nrBattle_Units) && (i < (int)MoM::gMAX_BATTLE_UNITS); ++i)
    {
        MoM::Battle_Unit& battleUnit = pBattleUnits[i];
        if (row >= ptree->rowCount())
        {
            ptree->setChild(row, 0, constructTreeItem(&battleUnit, ""));
        }

        QString id;
        int unitNr = battleUnit.m_unitNr;
        if ((unitNr >= 0) && (unitNr < game->getNrUnits()) && (unitNr < (int)MoM::gMAX_UNITS))
        {
            MoM::Unit* unit = game->getUnit(unitNr);
            if (0 != unit)
            {
                id = toQStr(unit->m_Unit_Type);
            }
        }
        else
        {
            id = toQStr(battleUnit.m_Race_Code);
        }
        ptree->child(row, 0)->setData(id, Qt::UserRole);
        ptree->child(row, 1)->setData(toQStr(battleUnit.m_Owner), Qt::UserRole);
        ptree->child(row, 2)->setData(QString("BattleUnit[%0]").arg(i), Qt::EditRole);

        ++row;
    }
}

void UnitModel::update_Buildings(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row)
{
    for (MoM::eBuilding building = (MoM::eBuilding)0; (0 != game) && (0 != game->getBuilding_Data()) && (building < MoM::eBuilding_MAX); MoM::inc(building))
    {
        MoM::Building_Data* buildingData = game->getBuilding_Data(building);
        if (0 == buildingData)
            break;
        if (building >= ptree->rowCount())
        {
            ptree->setChild(row, 0, constructTreeItem(buildingData, ""));

            ptree->child(row, 0)->setData(toQStr(building), Qt::UserRole);
//            ptree->child(row, 1)->setData(QString("(%0, %1, %2) %3")
//                                                    .arg(lair->m_XPos).arg(lair->m_YPos).arg(lair->m_Plane)
//                                                    .arg(prettyQStr(lair->m_Status)), Qt::UserRole);
            ptree->child(row, 2)->setData(QString("Building[%0]").arg((int)building), Qt::EditRole);
        }
        ++row;
    }
}

void update_Cities(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row)
{
    for (int cityNr = 0; (0 != game) && (cityNr < game->getNrCities()) && (cityNr < (int)MoM::gMAX_CITIES); ++cityNr)
    {
        MoM::City* city = game->getCity(cityNr);
        if (0 == city)
            break;
        if (cityNr >= ptree->rowCount())
        {
            ptree->setChild(row, 0, constructTreeItem(city, ""));
        }
        ptree->child(cityNr, 0)->setData(QString("%0 \"%1\"").arg(toQStr(city->m_Race)).arg(toQStr(city->m_City_Name)),
                Qt::UserRole);
        ptree->child(cityNr, 1)->setData(toQStr(city->m_Owner), Qt::UserRole);
        ptree->child(cityNr, 2)->setData(QString("City[%0]").arg(cityNr), Qt::EditRole);

        ++row;
    }
}

void update_Events(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row)
{
    if (0 == game)
        return;

    MoM::Events_Status* eventStatus = game->getEvents_Status();
    if (0 == eventStatus)
        return;

    {
        if (row >= ptree->rowCount())
        {
            ptree->setChild(row, 0, constructTreeItem(eventStatus, "Events Status"));

//            ptree->child(row, 0)->setData(toQStr((MoM::eRace)row), Qt::UserRole);
//            ptree->child(row, 1)->setData(QString(), Qt::EditRole);
//            ptree->child(row, 2)->setData(QString("Race[%0]").arg(raceNr), Qt::EditRole);
        }

        ++row;
    }
}

void update_Game_Data(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row)
{
    if (0 == game)
        return;

    if (row >= ptree->rowCount())
    {
        ptree->setChild(row, 0, constructTreeItem(game->getGame_Data_Save(), ""));
    }
    ptree->child(row, 0)->setData(QString("SAVE:Game_Data"), Qt::EditRole);
    ptree->child(row, 1)->setData(QString(), Qt::EditRole);
    ptree->child(row, 2)->setData(QString("SAVEn.GAM only"), Qt::EditRole);
    ++row;

    MoM::MoMDataSegment* dataSegment = game->getDataSegment();

    if (row >= ptree->rowCount())
    {
        ptree->setChild(row, 0, constructTreeItem(game->getGame_Data_Exe(), ""));

        if ((0 != dataSegment) && game->getGame_Data_Exe())
        {
            ptree->child(row, 0)->appendChild(QString("MoM Version"), new TreeItem<char[7]>(dataSegment->m_MoM_Version));
            ptree->child(row, 0)->appendChild(QString(" RNG_Next_Turn_Seed"), new TreeItem<uint32_t>((uint32_t*)&dataSegment->m_Next_Turn_seed_storage_lo));
            ptree->child(row, 0)->appendChild(QString(" RNG_Seed"), new TreeItem<uint32_t>((uint32_t*)&dataSegment->m_RNG_seed_lo));
            ptree->child(row, 0)->appendChild(QString(" DEBUG Off"), new TreeItem<uint16_t>(&dataSegment->m_DEBUG_Off));
            ptree->child(row, 0)->appendChild(QString(" BIOS Clock snapshot"), new TreeItem<uint32_t>(&dataSegment->m_BIOS_clock_snapshot));
            ptree->child(row, 0)->appendChild(QString("Game_State"), new TreeItem<MoM::eGameState>(&dataSegment->m_WizardsExe_Pointers.w_Game_flow));
            ptree->child(row, 0)->appendChild(QString("Kyrub_ds:9294"), new TreeItem<int16_t>(&dataSegment->m_WizardsExe_Pointers.w_kyrub_dseg_9294));
            ptree->child(row, 0)->appendChild(QString("Kyrub_ds:9296"), new TreeItem<int16_t>(&dataSegment->m_WizardsExe_Pointers.w_kyrub_dseg_9296));
        }
    }
    ptree->child(row, 0)->setData(QString("MEM:Game Data"), Qt::EditRole);
    ptree->child(row, 1)->setData(QString(), Qt::EditRole);
    ptree->child(row, 2)->setData(QString("Memory only"), Qt::EditRole);
    ++row;

    if (row >= ptree->rowCount())
    {
        ptree->setChild(row, 0, constructTreeItem(game->getGame_Settings(), ""));
    }
    ptree->child(row, 0)->setData(QString("Game_Settings (MAGIC.SET)"), Qt::EditRole);
    ptree->child(row, 1)->setData(QString(), Qt::EditRole);
    ptree->child(row, 2)->setData(QString("Memory only"), Qt::EditRole);
    ++row;

    if (row >= ptree->rowCount())
    {
        TreeItemBase* psubtree = new TreeItemBase("Difficulty Table");
        ptree->appendTree(psubtree, "");
    }
    ptree->child(row, 0)->setData(QString("Difficulty Table"), Qt::EditRole);
    ptree->child(row, 1)->setData(QString(), Qt::EditRole);
    ptree->child(row, 2)->setData(QString(), Qt::EditRole);
    for (int subrow = 0; (0 != dataSegment) && (subrow < (int)ARRAYSIZE(dataSegment->m_DifficultyTable)); ++subrow)
    {
        TreeItemBase* psubtree = ptree->child(row, 0);
        if (subrow >= psubtree->rowCount())
        {
            MoM::eDifficulty difficulty = (MoM::eDifficulty)subrow;
            psubtree->appendTree(constructTreeItem(&dataSegment->m_DifficultyTable[subrow], toQStr(difficulty)), "");
        }
    }
    ++row;
/*
    if (row >= ptree->rowCount())
    {
        ptree->appendChild(QString("Game_State"), new TreeItem<MoM::eGameState> (&dataSegment->m_WizardsExe_Pointers.w_Game_flow));
        ptree->appendChild(QString("Kyrub_dseg:9294"), new TreeItem<int16_t> (&dataSegment->m_WizardsExe_Pointers.w_kyrub_dseg_9294));
        ptree->appendChild(QString("Kyrub_dseg:9296"), new TreeItem<int16_t> (&dataSegment->m_WizardsExe_Pointers.w_kyrub_dseg_9296));
    }
    row += 3;
*/
    if (row >= ptree->rowCount())
    {
        TreeItemBase* psubtree = new TreeItemBase("Stack Segment");
        ptree->appendTree(psubtree, "");
    }
    ptree->child(row, 0)->setData(QString("Stack Segment"), Qt::EditRole);
    ptree->child(row, 1)->setData(QString(), Qt::EditRole);
    ptree->child(row, 2)->setData(QString(), Qt::EditRole);
    for (int subrow = 0; (0 != dataSegment) && (subrow < 0x400); ++subrow)
    {
        TreeItemBase* psubtree = ptree->child(row, 0);
        if (subrow >= psubtree->rowCount())
        {
            psubtree->appendChild(QString("Stack[%0]").arg(2 * (0x7C00 + subrow), 4, 16), new TreeItem<uint16_t> ((uint16_t*)&dataSegment->m_DataSegmentStart + 0x7C00 + subrow));
        }
    }
    ++row;
}

void update_Heroes_Hired(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row, MoM::ePlayer wizardNr)
{
    if (0 == game)
        return;

    MoM::Wizard* wizard = game->getWizard(wizardNr);
    if (0 == wizard)
        return;

    for (int heroSlotNr = 0; heroSlotNr < (int)MoM::gMAX_HIRED_HEROES; ++heroSlotNr)
    {
        MoM::Hired_Hero& hiredHero = wizard->m_Heroes_hired_by_wizard[heroSlotNr];
        int unitNr = hiredHero.m_Unit_Nr;
        if (row >= ptree->rowCount())
        {
            ptree->setChild(row, 0, constructTreeItem(&hiredHero, "Hired_Hero (Wizard)"));
        }

        MoM::Unit* unit = game->getUnit(unitNr);
        if (0 == unit || unitNr < 0 || unitNr >= (int)MoM::gMAX_UNITS)
        {
            ptree->child(row, 0)->setData(QString(), Qt::UserRole);
        }
        else
        {
            ptree->child(row, 0)->setData(toQStr(unit->m_Unit_Type), Qt::UserRole);
        }
        ptree->child(row, 1)->setData(QString(hiredHero.m_Hero_name), Qt::UserRole);
        ptree->child(row, 2)->setData(QString("HeroSlot[%0]").arg(heroSlotNr), Qt::EditRole);

        ++row;
    }
}

void update_Hero_Stats(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row, MoM::ePlayer wizardNr)
{
    if (0 == game)
        return;

    for (int heroTypeNr = 0; heroTypeNr < (int)MoM::gMAX_HERO_TYPES; ++heroTypeNr)
    {
        MoM::eUnit_Type unitType = (MoM::eUnit_Type)heroTypeNr;
        MoM::Hero_stats* heroStats = game->getHero_stats(wizardNr, unitType);
        if (0 == heroStats)
            break;
        if (row >= ptree->rowCount())
        {
            ptree->setChild(row, 0, constructTreeItem(heroStats, "Hero_Stats (Wizard)"));
        }

        // Update top-level unit fields
        ptree->child(row, 0)->setData(toQStr(unitType), Qt::UserRole);
        ptree->child(row, 1)->setData(QString(), Qt::UserRole);
        ptree->child(row, 2)->setData(QString("HeroType[%0]").arg(heroTypeNr), Qt::EditRole);

        ++row;
    }
}

void UnitModel::update_Items_in_Game(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row)
{
    for (int i = 0; (0 != game) && (i < (int)MoM::gMAX_ITEMS); ++i)
    {
        MoM::Item* pItems = game->getItems();
        if (0 == pItems)
        {
            break;
        }
        MoM::Item& item = pItems[i];
        if (row >= ptree->rowCount())
        {
            ptree->setChild(row, 0, constructTreeItem(&item, ""));

            ptree->child(row, 2)->setData(QString("Item[%0]").arg(i), Qt::UserRole);
        }
        ptree->child(row, 0)->setData(toQStr(item.m_Item_Name), Qt::EditRole);
		QIcon icon = QMoMResources::instance().getIcon(item.m_Item_Type);
        if (!icon.isNull())
        {
            if ((item.m_Cost > 0) || (0 != item.m_Icon))
            {
                ptree->child(row, 0)->setData(icon, Qt::EditRole);
                ptree->child(row, 1)->setData(toQStr(item.m_Item_Type), Qt::UserRole);
            }
            else
            {
                ptree->child(row, 0)->setData(QIcon(), Qt::EditRole);
                ptree->child(row, 1)->setData(QString(), Qt::UserRole);
            }
        }

        ++row;
    }
}

void UnitModel::update_Lairs(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row)
{
    for (int lairNr = 0; (0 != game) && (0 != game->getLairs()) && (lairNr < (int)MoM::gMAX_NODES_LAIRS_TOWERS); ++lairNr)
    {
        MoM::Tower_Node_Lair* lair = game->getLair(lairNr);
        if (0 == lair)
            break;
        if (lairNr >= ptree->rowCount())
        {
            ptree->setChild(row, 0, constructTreeItem(lair, ""));

            ptree->child(lairNr, 0)->setData(toQStr(lair->m_Type), Qt::UserRole);
            ptree->child(lairNr, 1)->setData(QString("(%0, %1, %2) %3")
                                                    .arg(lair->m_XPos).arg(lair->m_YPos).arg((int)lair->m_Plane)
                                                    .arg(prettyQStr(lair->m_Status)), Qt::UserRole);
            ptree->child(lairNr, 2)->setData(QString("Lair[%0]").arg(lairNr), Qt::EditRole);

			QIcon icon = QMoMResources::instance().getIcon(lair->m_Type);
            if (!icon.isNull())
            {
                ptree->child(row, 0)->appendChild(QString("LairIcon"), new TreeItemBase(QString(), icon));

                ptree->child(row, 0)->setData(icon, Qt::EditRole);
            }
        }
        ++row;
    }
}

void update_Races(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row)
{
    if (0 == game)
        return;

    MoM::MoMDataSegment* dataSegment = game->getDataSegment();
    if (0 == dataSegment)
        return;

    for (int raceNr = 0; raceNr < (int)ARRAYSIZE(dataSegment->m_Race_Data); ++raceNr)
    {
        if (row >= ptree->rowCount())
        {
            ptree->setChild(row, 0, constructTreeItem(&dataSegment->m_Race_Data[raceNr], ""));

            // Additional custom fields:
            // Name which is pointed to by PtrName
            const char* ptrName = game->getNameByOffset(dataSegment->m_Race_Data[raceNr].m_PtrName);
            if (0 != ptrName)
            {
                ptree->child(row, 0)->appendChild(QString("*PtrName"), new TreeItem<const char*>(ptrName));
            }

            ptree->child(row, 0)->setData(toQStr((MoM::eRace)row), Qt::UserRole);
            ptree->child(row, 1)->setData(QString(), Qt::EditRole);
            ptree->child(row, 2)->setData(QString("Race[%0]").arg(raceNr), Qt::EditRole);
        }

        ++row;
    }
}

void UnitModel::update_Spell_Data(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row)
{
    if (0 == game)
        return;

    MoM::Spell_Data* spellData = game->getSpell_Data();
    if (0 == spellData)
        return;

    for (int spellNr = 0; spellNr < (int)MoM::eSpell_MAX; ++spellNr)
    {
        MoM::eSpell spell = (MoM::eSpell)spellNr;
        if (row >= ptree->rowCount())
        {
            ptree->setChild(row, 0, constructTreeItem(&spellData[spellNr], ""));
        }

        ptree->child(spellNr, 0)->setData(toQStr(spell), Qt::UserRole);
		QIcon icon = QMoMResources::instance().getIcon(spell);
        if (!icon.isNull())
        {
            ptree->child(spellNr, 0)->setData(icon, Qt::EditRole);
        }

        if ((spellNr <= MoM::SPELL_Magic_Spirit) && (spellNr - 1) % 10 == 0)
        {
            const char* rarityStr[4] = { "Common", "Uncommon", "Rare", "Very Rare" };
            int rarity = ((spellNr + 40 - 1) % 40 / 10);
            QString qRarity = rarityStr[rarity];
            MoM::eRealm_Type color = (MoM::eRealm_Type)((spellNr - 1) / 40);
            ptree->child(spellNr, 1)->setData(QString("%0, %1").arg(toQStr(color)).arg(qRarity), Qt::UserRole);
        }
        else
        {
            ptree->child(spellNr, 1)->setData(QString(), Qt::UserRole);
        }
        ptree->child(spellNr, 2)->setData(QString("Spell[%0]").arg(spellNr), Qt::EditRole);
        ++row;
    }
}

void update_Spells_Cast_in_Battle(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row)
{
    if (0 == game)
        return;
    MoM::Spells_Cast_in_Battle* pSpells_Cast_in_Battle = game->getSpells_Cast_in_Battle();

    if (row >= ptree->rowCount())
    {
        ptree->setChild(row, 0, constructTreeItem(pSpells_Cast_in_Battle, ""));
    }
    ptree->child(row, 0)->setData(toQStr("Spells_Cast_in_Battle"), Qt::UserRole);
    if ((0 != game) && (0 != game->getDataSegment()))
    {
        const MoM::EXE_Reloc& addr = game->getDataSegment()->m_WizardsExe_Pointers.addr_Spells_Cast_in_Battle;
        ptree->child(row, 1)->setData(toQStr(addr), Qt::EditRole);
    }
    else
    {
        ptree->child(row, 1)->setData(QString(), Qt::EditRole);
    }
    ptree->child(row, 2)->setData(QString(), Qt::EditRole);

    ++row;
}

void update_Units_in_Game(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row)
{
    for (int unitNr = 0; (0 != game) && (unitNr < game->getNrUnits()) && (unitNr < (int)MoM::gMAX_UNITS); ++unitNr)
    {
        MoM::Unit* unit = game->getUnit(unitNr);
        if (0 == unit)
            break;
        if (row >= ptree->rowCount())
        {
            ptree->setChild(row, 0, constructTreeItem(unit, ""));

            // Additional custom fields

            // Weapon_Type, which is an enum stored as a bitfield
            MoM::unionUnit_Weapon_Mutation mask;
            mask.bits = 0;
            mask.s.Weapon_Type = 0x03;
            ptree->child(row, 0)->appendChild(QString("Weapon_Type"), new TreeItem<MoM::eWeaponType>((MoM::eWeaponType*)&unit->m_Weapon_Mutation.bits, mask.bits));
/*
            // Unit Type Data, if available
            if ((unsigned)unit.m_Unit_Type < MoM::eUnit_Type_MAX)
            {
                MoM::Unit_Type_Data* pUnitData = game->getUnit_Type_Data(unit.m_Unit_Type);
                if (0 != pUnitData)
                {
                    constructTreeItem(ptree->child(row, 0), pUnitData, "Unit_Type_Data (Global)");
                }
            }

            // Hired Hero, if applicable
            if ((unsigned)unit.m_Hero_Slot_Number < MoM::gMAX_HIRED_HEROES)
            {
                MoM::Hired_Hero& hiredHero = game->getWizard(unit.m_Owner).m_Heroes_hired_by_wizard[unit.m_Hero_Slot_Number];

                constructTreeItem(ptree->child(row, 0), &hiredHero, "Hired_Hero (Wizard)");
            }

            // Hero Stats, if applicable
            if ((unsigned)unit.m_Unit_Type < MoM::gMAX_HERO_TYPES)
            {
                MoM::Hero_stats& heroStats = game->getHero_stats(unit.m_Owner, unit.m_Unit_Type);

                constructTreeItem(ptree->child(row, 0), &heroStats, "Hero_Stats (Wizard)");
            }
*/
        }

        // Update top-level unit fields
        ptree->child(row, 0)->setData(toQStr(unit->m_Unit_Type), Qt::UserRole);
        ptree->child(row, 1)->setData(toQStr(unit->m_Owner), Qt::UserRole);
        ptree->child(row, 2)->setData(QString("Unit[%0]").arg(unitNr), Qt::EditRole);

        ++row;
    }
}

void UnitModel::update_Unit_Types(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row)
{
    if (0 == game)
        return;

    MoM::MoMDataSegment* dataSegment = game->getDataSegment();
    if (0 == dataSegment)
        return;

    for (int unitTypeNr = 0; unitTypeNr < MoM::eUnit_Type_MAX; ++unitTypeNr)
    {
        MoM::eUnit_Type unitType = (MoM::eUnit_Type)unitTypeNr;
        MoM::Unit_Type_Data* pUnitData = game->getUnit_Type_Data(unitType);
        if (0 == pUnitData)
        {
            break;
        }
        if (row >= ptree->rowCount())
        {
            ptree->setChild(row, 0, constructTreeItem(pUnitData, ""));

            // Update top-level unit fields (only need to do this once, since they won't change)
            ptree->child(row, 0)->setData(toQStr(unitType), Qt::UserRole);
            ptree->child(row, 1)->setData(QString(), Qt::EditRole);
            ptree->child(row, 2)->setData(QString("UnitType[%0]").arg(unitTypeNr), Qt::EditRole);

            // Additional custom fields:
            // Name which is pointed to by PtrName
            const char* ptrName = game->getNameByOffset(pUnitData->m_PtrName);
            if (0 != ptrName)
            {
                ptree->child(row, 0)->appendChild(QString("*PtrName"), new TreeItem<const char*>(ptrName));
            }

//            std::string gameDir = game->getGameDirectory();
//            if (!gameDir.empty() && (unitType >= MoM::gMAX_HERO_TYPES))
//            {
//                std::string unitLbx;
//                size_t lbxIndex = unitType;
//                if (lbxIndex < 120)
//                {
//                    unitLbx = "UNITS1";
//                }
//                else
//                {
//                    unitLbx = "UNITS2";
//                    lbxIndex -= 120;
//                }
//                unitLbx = gameDir + "/" + unitLbx + ".LBX";
//                MoM::MoMLbxBase lbxFile;
//                if (lbxFile.load(unitLbx))
//                {
//                    uint8_t* data = lbxFile.getRecord(lbxIndex);
//
////                    std::cout << "Convert " << unitType << " from " << unitLbx << "[" << lbxIndex << "]" << std::endl;
//                    QImage image = MoM::convertLbxToImage(data, m_colorTable);
//                    image = image.scaled(image.size() * 2, Qt::IgnoreAspectRatio, Qt::SmoothTransformation );
//
//                    QIcon icon(QPixmap::fromImage(image));
//                    ptree->child(row, 0)->appendChild(QString("UnitIcon"), new TreeItemBase(QString(), icon));
//
//                    ptree->child(row, 0)->setData(icon, Qt::EditRole);
//                }
//            }

			QIcon icon = QMoMResources::instance().getIcon(unitType);
            if (!icon.isNull())
            {
                ptree->child(row, 0)->appendChild(QString("UnitIcon"), new TreeItemBase(QString(), icon));

                ptree->child(row, 0)->setData(icon, Qt::EditRole);
            }

        }

        ++row;
    }
}

void update_Wizards(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row)
{
    for (int wizardNr = 0; (0 != game) && (wizardNr < game->getNrWizards()) && (wizardNr < (int)MoM::gMAX_WIZARD_RECORDS); ++wizardNr)
    {
        MoM::Wizard* wizard = game->getWizard(wizardNr);
        if (0 == wizard)
            break;
        if (wizardNr >= ptree->rowCount())
        {
            ptree->setChild(row, 0, constructTreeItem(wizard, ""));
        }
        ptree->child(wizardNr, 0)->setData(toQStr(wizard->m_Portrait), Qt::UserRole);
        ptree->child(wizardNr, 1)->setData(QString("\"%0\"").arg(toQStr(wizard->m_Name)), Qt::UserRole);
        ptree->child(wizardNr, 2)->setData(QString("wizard[%0]").arg(wizardNr), Qt::EditRole);

        ++row;
    }
}


void UnitModel::setupModelData(MoM::MoMGameBase* game)
{
    //    QStandardItemModel::setColumnCount(this->m_columnCount);
    //    QStandardItemModel::setHorizontalHeaderItem(0, new QStandardItem(tr("Feature")));
    //    QStandardItemModel::setHorizontalHeaderItem(1, new QStandardItem(tr("Value")));
    //    QStandardItemModel::setHorizontalHeaderItem(2, new QStandardItem(tr("Comment")));

    //    QStandardItemModel::horizontalHeaderItem(0)->setFont(QFont(QString("Monotype Corsiva"), 14));
    //    QStandardItemModel::horizontalHeaderItem(1)->setFont(QFont(QString("Monotype Corsiva"), 14));
    //    QStandardItemModel::horizontalHeaderItem(2)->setFont(QFont(QString("Monotype Corsiva"), 14));

    //     QStandardItem *parentItem = QStandardItemModel::invisibleRootItem();

    if (0 == m_rootItem)
    {

        m_rootItem = new TreeItemBase();
    }

    TreeItemBase *parentItem = m_rootItem;

//    if (TreeItemBase::game() != game)
//    {
//        parentItem->removeRows(0, parentItem->rowCount() - 1);
//    }

    TreeItemBase::setGame(game);

    if (!QMoMResources::hasInstance() && (0 != game))
    {
        QMoMResources::createInstance(game);
    }

    int toprow = 0;

    {
        if (toprow == parentItem->rowCount())
        {
            parentItem->appendEmptyRow();
        }

        int nrGameData = 0;
        if (0 != game)
        {
            nrGameData = 4; // TODO: Proper nr rows
        }
        parentItem->child(toprow, 0)->setData(tr("Game Data"), Qt::UserRole);
        parentItem->child(toprow, 1)->setData(QString(), Qt::EditRole);
        if (0 == game)
        {
            parentItem->child(toprow, 2)->setData(QString(), Qt::EditRole);
        }
        else
        {
            parentItem->child(toprow, 2)->setData(tr("MoM Version %0").arg(toQStr(game->getMoM_Version())), Qt::EditRole);
        }

        int row = 0;
        TreeItemBase* ptree = parentItem->child(toprow, 0);
        if (nrGameData > ptree->rowCount())
        {
            beginInsertRows(createIndex(toprow, 0, ptree), ptree->rowCount(), nrGameData - 1);
            update_Game_Data(ptree, game, row);
            endInsertRows();
        }
        else
        {
            update_Game_Data(ptree, game, row);
        }
        removeUnusedRows(toprow, ptree, row);

        toprow++;
    }

    {
        if (toprow == parentItem->rowCount())
        {
            parentItem->appendEmptyRow();
        }

        int nrBuildings = 0;
        parentItem->child(toprow, 0)->setData(tr("Buildings"), Qt::UserRole);
        if ((0 != game) && (0 != game->getDataSegment()))
        {
            const MoM::EXE_Reloc& addr = game->getDataSegment()->m_WizardsExe_Pointers.addr_Building_Data;
            parentItem->child(toprow, 1)->setData(toQStr(addr), Qt::EditRole);
        }
        else
        {
            parentItem->child(toprow, 1)->setData(QString(), Qt::EditRole);
        }
        if (0 == game)
        {
            parentItem->child(toprow, 2)->setData(QString(), Qt::EditRole);
        }
        else
        {
            nrBuildings = MoM::eBuilding_MAX;
            parentItem->child(toprow, 2)->setData(tr("NrBuildings = %0").arg(nrBuildings), Qt::EditRole);
        }

        int row = 0;
        TreeItemBase* ptree = parentItem->child(toprow, 0);
        if (nrBuildings > ptree->rowCount())
        {
            beginInsertRows(createIndex(toprow, 0, ptree), ptree->rowCount(), nrBuildings - 1);
            update_Buildings(ptree, game, row);
            endInsertRows();
        }
        else
        {
            update_Buildings(ptree, game, row);
        }
        removeUnusedRows(toprow, ptree, row);

        toprow++;
    }

    {
        if (toprow == parentItem->rowCount())
        {
            parentItem->appendEmptyRow();
        }

        int nrRaces = 0;
        parentItem->child(toprow, 0)->setData(tr("Races"), Qt::EditRole);
        parentItem->child(toprow, 1)->setData(QString(), Qt::EditRole);
        if ((0 == game) || (0 == game->getDataSegment()))
        {
            parentItem->child(toprow, 2)->setData(QString(), Qt::EditRole);
        }
        else
        {
            nrRaces = ARRAYSIZE(game->getDataSegment()->m_Race_Data);
            parentItem->child(toprow, 2)->setData(QString("NrRaces = %1").arg(nrRaces), Qt::EditRole);
        }

        int row = 0;
        TreeItemBase* ptree = parentItem->child(toprow, 0);
        if (nrRaces > ptree->rowCount())
        {
            beginInsertRows(createIndex(toprow, 0, ptree), ptree->rowCount(), nrRaces - 1);
            update_Races(ptree, game, row);
            endInsertRows();
        }
        else
        {
            update_Races(ptree, game, row);
        }
        removeUnusedRows(toprow, ptree, row);

        toprow++;
    }

    {
        if (toprow == parentItem->rowCount())
        {
            parentItem->appendEmptyRow();
        }

        int nrWizards = 0;
        parentItem->child(toprow, 0)->setData(tr("Wizards"), Qt::UserRole);
        parentItem->child(toprow, 1)->setData(QString(), Qt::EditRole);
        if (0 == game)
        {
            parentItem->child(toprow, 2)->setData(QString(), Qt::EditRole);
        }
        else
        {
            nrWizards = game->getNrWizards();
            parentItem->child(toprow, 2)->setData(tr("NrWizards = %0").arg(nrWizards), Qt::EditRole);
        }

        int row = 0;
        TreeItemBase* ptree = parentItem->child(toprow, 0);
        if ((nrWizards > ptree->rowCount()))
        {
            beginInsertRows(createIndex(toprow, 0, ptree), ptree->rowCount(), nrWizards - 1);
            update_Wizards(ptree, game, row);
            endInsertRows();
        }
        else
        {
            update_Wizards(ptree, game, row);
        }
        removeUnusedRows(toprow, ptree, row);

        toprow++;
    }

    {
        if (toprow == parentItem->rowCount())
        {
            parentItem->appendEmptyRow();
        }

        int nrLairs = 0;
        parentItem->child(toprow, 0)->setData(tr("Lairs"), Qt::UserRole);
        if ((0 != game) && (0 != game->getDataSegment()))
        {
            const MoM::EXE_Reloc& addr = game->getDataSegment()->m_WizardsExe_Pointers.addr_Lairs_data;
            parentItem->child(toprow, 1)->setData(toQStr(addr), Qt::EditRole);
        }
        else
        {
            parentItem->child(toprow, 1)->setData(QString(), Qt::EditRole);
        }
        if (0 == game)
        {
            parentItem->child(toprow, 2)->setData(QString(), Qt::EditRole);
        }
        else
        {
            nrLairs = MoM::gMAX_NODES_LAIRS_TOWERS;
            parentItem->child(toprow, 2)->setData(tr("NrLairs = %0").arg(nrLairs), Qt::EditRole);
        }

        int row = 0;
        TreeItemBase* ptree = parentItem->child(toprow, 0);
        if (nrLairs > ptree->rowCount())
        {
            beginInsertRows(createIndex(toprow, 0, ptree), ptree->rowCount(), nrLairs - 1);
            update_Lairs(ptree, game, row);
            endInsertRows();
        }
        else
        {
            update_Lairs(ptree, game, row);
        }
        removeUnusedRows(toprow, ptree, row);

        toprow++;
    }

    {
        if (toprow == parentItem->rowCount())
        {
            parentItem->appendEmptyRow();
        }

        int nrCities = 0;
        parentItem->child(toprow, 0)->setData(tr("Cities"), Qt::UserRole);

        if ((0 != game) && (0 != game->getDataSegment()))
        {
            const MoM::EXE_Reloc& addr = game->getDataSegment()->m_WizardsExe_Pointers.addr_Cities;
            parentItem->child(toprow, 1)->setData(toQStr(addr), Qt::EditRole);
        }
        else
        {
            parentItem->child(toprow, 1)->setData(QString(), Qt::EditRole);
        }
        if (0 == game)
        {
            parentItem->child(toprow, 2)->setData(QString(), Qt::EditRole);
        }
        else
        {
            nrCities = game->getNrCities();
            parentItem->child(toprow, 2)->setData(tr("NrCities = %0").arg(nrCities), Qt::EditRole);
        }

        int row = 0;
        TreeItemBase* ptree = parentItem->child(toprow, 0);
        if (nrCities > ptree->rowCount())
        {
            beginInsertRows(createIndex(toprow, 0, ptree), ptree->rowCount(), nrCities - 1);
            update_Cities(ptree, game, row);
            endInsertRows();
        }
        else
        {
            update_Cities(ptree, game, row);
        }
        removeUnusedRows(toprow, ptree, row);

        toprow++;
    }

    {
        if (toprow == parentItem->rowCount())
        {
            parentItem->appendEmptyRow();
        }

//        int nrCities = 0;
        parentItem->child(toprow, 0)->setData(tr("Events"), Qt::UserRole);

        if ((0 != game) && (0 != game->getDataSegment()))
        {
            const MoM::EXE_Reloc& addr = game->getDataSegment()->m_WizardsExe_Pointers.addr_events;
            parentItem->child(toprow, 1)->setData(toQStr(addr), Qt::EditRole);
        }
        else
        {
            parentItem->child(toprow, 1)->setData(QString(), Qt::EditRole);
        }
        parentItem->child(toprow, 2)->setData(QString(), Qt::EditRole);

        int row = 0;
        TreeItemBase* ptree = parentItem->child(toprow, 0);
//        if (nrCities > ptree->rowCount())
//        {
//            beginInsertRows(createIndex(toprow, 0, ptree), ptree->rowCount(), nrCities - 1);
//            update_Cities(ptree, game, row);
//            endInsertRows();
//        }
//        else
        {
            update_Events(ptree, game, row);
        }
//        removeUnusedRows(toprow, ptree, row);

        toprow++;
    }

    {
        if (toprow == parentItem->rowCount())
        {
            parentItem->appendEmptyRow();
        }

        int nrUnitSections = 0;
        parentItem->child(toprow, 0)->setData(tr("Units"), Qt::UserRole);
        parentItem->child(toprow, 1)->setData(QString(), Qt::EditRole);
        if (0 == game)
        {
            parentItem->child(toprow, 2)->setData(QString(), Qt::EditRole);
        }
        else
        {
            nrUnitSections = 4;     // TODO: Proper number
            parentItem->child(toprow, 2)->setData(tr("NrUnits in Game = %0").arg(game->getNrUnits()), Qt::EditRole);
        }

        int row = 0;
        TreeItemBase* ptree = parentItem->child(toprow, 0);

        int oldRowCount = ptree->rowCount();
        if (nrUnitSections > oldRowCount)
        {
            beginInsertRows(createIndex(toprow, 0, ptree), oldRowCount, nrUnitSections - 1);
        }

        {
            if (row >= ptree->rowCount())
            {
                TreeItemBase* psubtree = new TreeItemBase("XP Level Table");
                ptree->appendTree(psubtree, "");
            }

            MoM::MoMDataSegment* dataSegment = 0;
            if (0 != game)
            {
                dataSegment = game->getDataSegment();
            }

            ptree->child(row, 0)->setData(QString("XP Table (Global)"), Qt::EditRole);
            ptree->child(row, 1)->setData(QString(), Qt::EditRole);
            ptree->child(row, 2)->setData(QString(), Qt::EditRole);

            TreeItemBase* psubtree = ptree->child(row, 0);
            int subrow = 0;
            for (subrow = 0; (0 != dataSegment) && (subrow < (int)ARRAYSIZE(dataSegment->m_XP_Level_Table)); ++subrow)
            {
                if (subrow >= psubtree->rowCount())
                {
                    psubtree->appendChild(QString("Level %0").arg(subrow + 1), new TreeItem<uint16_t> (&dataSegment->m_XP_Level_Table[subrow]));
                }
            }
            removeUnusedRows(row, psubtree, subrow);

            ++row;
        }

        {
            if (row == ptree->rowCount())
            {
                ptree->appendEmptyRow();
            }
            ptree->child(row, 0)->setData(tr("Unit Types (Global)"), Qt::UserRole);
            ptree->child(row, 1)->setData(QString(), Qt::EditRole);
            if (0 == game)
            {
                ptree->child(row, 2)->setData(QString(), Qt::EditRole);
            }
            else
            {
                ptree->child(row, 2)->setData(tr("NrUnit Types = %0").arg((int)MoM::eUnit_Type_MAX), Qt::EditRole);
            }

            int subrow = 0;
            TreeItemBase* psubtree = ptree->child(row, 0);
            update_Unit_Types(psubtree, game, subrow);
            removeUnusedRows(row, psubtree, subrow);

            ++row;
        }

        {
            if (row == ptree->rowCount())
            {
                ptree->appendEmptyRow();
            }
            ptree->child(row, 0)->setData(tr("Hero Stats (YOU)"), Qt::UserRole);
            if ((0 != game) && (0 != game->getDataSegment()))
            {
                const MoM::EXE_Reloc& addr = game->getDataSegment()->m_WizardsExe_Pointers.addr_Hero_stat[MoM::PLAYER_YOU];
                ptree->child(row, 1)->setData(toQStr(addr), Qt::EditRole);
            }
            else
            {
                ptree->child(row, 1)->setData(QString(), Qt::EditRole);
            }
            if (0 == game)
            {
                ptree->child(row, 2)->setData(QString(), Qt::EditRole);
            }
            else
            {
                ptree->child(row, 2)->setData(tr("NrHero Types = %0").arg(MoM::gMAX_HERO_TYPES), Qt::EditRole);
            }

            int subrow = 0;
            TreeItemBase* psubtree = ptree->child(row, 0);
            update_Hero_Stats(psubtree, game, subrow, MoM::PLAYER_YOU);
            removeUnusedRows(row, psubtree, subrow);

            ++row;
        }

        {
            if (row == ptree->rowCount())
            {
                ptree->appendEmptyRow();
            }
            ptree->child(row, 0)->setData(tr("Heroes Hired (YOU)"), Qt::UserRole);
            ptree->child(row, 1)->setData(QString(), Qt::EditRole);
            if (0 == game)
            {
                ptree->child(row, 2)->setData(QString(), Qt::EditRole);
            }
            else
            {
                ptree->child(row, 2)->setData(tr("NrHero Slots = %0").arg(MoM::gMAX_HIRED_HEROES), Qt::EditRole);
            }

            int subrow = 0;
            TreeItemBase* psubtree = ptree->child(row, 0);
            update_Heroes_Hired(psubtree, game, subrow, MoM::PLAYER_YOU);
            removeUnusedRows(row, psubtree, subrow);

            ++row;
        }

        {
            if (row == ptree->rowCount())
            {
                ptree->appendEmptyRow();
            }
            ptree->child(row, 0)->setData(tr("Units in Game"), Qt::UserRole);
            if ((0 != game) && (0 != game->getDataSegment()))
            {
                const MoM::EXE_Reloc& addr = game->getDataSegment()->m_WizardsExe_Pointers.addr_Units;
                ptree->child(row, 1)->setData(toQStr(addr), Qt::EditRole);
            }
            else
            {
                ptree->child(row, 1)->setData(QString(), Qt::EditRole);
            }
            if (0 == game)
            {
                ptree->child(row, 2)->setData(QString(), Qt::EditRole);
            }
            else
            {
                ptree->child(row, 2)->setData(tr("NrUnits in Game = %0").arg(game->getNrUnits()), Qt::EditRole);
            }

            int subrow = 0;
            TreeItemBase* psubtree = ptree->child(row, 0);
            update_Units_in_Game(psubtree, game, subrow);
            removeUnusedRows(row, psubtree, subrow);

            ++row;
        }

        if (nrUnitSections > oldRowCount)
        {
            endInsertRows();
        }

        removeUnusedRows(toprow, ptree, row);

        toprow++;
    }

    {
        if (toprow == parentItem->rowCount())
        {
            parentItem->appendEmptyRow();
        }

        int nrItems = 0;
        parentItem->child(toprow, 0)->setData(tr("Items"), Qt::UserRole);
        parentItem->child(toprow, 1)->setData(QString(), Qt::EditRole);
        if (0 != game)
        {
            nrItems = game->getNrItems();
            parentItem->child(toprow, 2)->setData(tr("NrItems = %0").arg(nrItems), Qt::EditRole);
        }

        int row = 0;
        TreeItemBase* ptree = parentItem->child(toprow, 0);
        if (nrItems > ptree->rowCount())
        {
            beginInsertRows(createIndex(toprow, 0, ptree), ptree->rowCount(), nrItems - 1);
            update_Items_in_Game(ptree, game, row);
            endInsertRows();
        }
        else
        {
            update_Items_in_Game(ptree, game, row);
        }
        removeUnusedRows(toprow, ptree, row);

        toprow++;
    }

    {
        if (toprow == parentItem->rowCount())
        {
            parentItem->appendEmptyRow();
        }

        int nrSpellSections = 3;    // TODO: Proper number
        parentItem->child(toprow, 0)->setData(tr("Spells"), Qt::UserRole);
        parentItem->child(toprow, 1)->setData(QString(), Qt::EditRole);
        parentItem->child(toprow, 2)->setData(QString(), Qt::EditRole);

        int row = 0;
        TreeItemBase* ptree = parentItem->child(toprow, 0);

        int oldRowCount = ptree->rowCount();
        if (nrSpellSections > oldRowCount)
        {
            beginInsertRows(createIndex(toprow, 0, ptree), oldRowCount, nrSpellSections - 1);
        }

        {
            if (row >= ptree->rowCount())
            {
                TreeItemBase* psubtree = new TreeItemBase("Spell Data");
                ptree->appendTree(psubtree, "");
            }

            MoM::MoMDataSegment* dataSegment = 0;
            if (0 != game)
            {
                dataSegment = game->getDataSegment();
            }

            ptree->child(row, 0)->setData(QString("Spell Data"), Qt::EditRole);
            if ((0 != game) && (0 != game->getDataSegment()))
            {
                const MoM::EXE_Reloc& addr = game->getDataSegment()->m_WizardsExe_Pointers.addr_Spell_Data;
                ptree->child(row, 1)->setData(toQStr(addr), Qt::EditRole);
            }
            else
            {
                ptree->child(row, 1)->setData(QString(), Qt::EditRole);
            }
            ptree->child(row, 2)->setData(QString("Memory only"), Qt::EditRole);

            int subrow = 0;
            TreeItemBase* psubtree = ptree->child(row, 0);
            update_Spell_Data(psubtree, game, subrow);
            removeUnusedRows(row, psubtree, subrow);

            ++row;
        }

        {
            if (row >= ptree->rowCount())
            {
                ptree->setChild(row, 0, new TreeItemBase(""));
            }
            if ((0 != game) && (0 != game->getDataSegment()))
            {
                if (0 == ptree->child(row, 0)->rowCount())
                {
                    ptree->setChild(row, 0, MoM::constructTreeItem(&game->getDataSegment()->m_Upkeep_Enchantments, ""));
                }
            }
            else
            {
                if (ptree->child(row, 0)->rowCount() > 0)
                {
                    removeUnusedRows(row, ptree->child(row, 0), 0);
                }
            }

            ptree->child(row, 0)->setData(QString("Upkeep Enchantments"), Qt::EditRole);
            ptree->child(row, 1)->setData(QString(), Qt::EditRole);
            ptree->child(row, 2)->setData(QString(), Qt::EditRole);

            ++row;
        }

        {
            if (row >= ptree->rowCount())
            {
                ptree->setChild(row, 0, new TreeItemBase("EXE:Spell Saves"));
            }

            uint8_t* ovl112 = 0;
            MoM::MoMExeWizards* wizardsExe = 0;
            if (0 != game)
            {
                ovl112 = game->getWizardsOverlay(112);
                wizardsExe = game->getWizardsExe();
            }

            TreeItemBase* psubtree = ptree->child(row, 0);
            int subrow = 0;
            if ((0 != ovl112) && (0 != wizardsExe) && (0 == psubtree->rowCount()))
            {
                for (subrow = 0; subrow < (int)wizardsExe->getNrSpellSaves(); ++subrow)
                {
                    psubtree->appendChild("Spell", new TreeItem<MoM::eSpell>((MoM::eSpell*)&ovl112[ wizardsExe->getSpellSave(subrow).spellOffset ]));
                    if (0 == wizardsExe->getSpellSave(subrow).saveOffset)
                    {
                        psubtree->child(subrow, 2)->setData(QString("0 (unchangeable)"), Qt::EditRole);
                    }
                    else
                    {
                        psubtree->setChild(subrow, 2, new TreeItem<int16_t>((int16_t*)&ovl112[ wizardsExe->getSpellSave(subrow).saveOffset ]));
                    }
                }
            }
            ptree->child(row, 0)->setData(QString("Spell Saves"), Qt::EditRole);
            ptree->child(row, 1)->setData(QString("Spells can be swapped!"), Qt::EditRole);
            ptree->child(row, 2)->setData(QString("MODIFIES Wizards.exe"), Qt::EditRole);

            if (0 == ovl112)
            {
                removeUnusedRows(row, psubtree, subrow);
            }

            ++row;
        }

        if (nrSpellSections > oldRowCount)
        {
            endInsertRows();
        }
        removeUnusedRows(toprow, ptree, row);

        toprow++;
    }

    {
        if (toprow == parentItem->rowCount())
        {
            parentItem->appendEmptyRow();
        }

        int nrBattleSections = 0;
        if ((0 != game) && (0 != game->getDataSegment()))
        {
            nrBattleSections = 3;       // TODO: Proper number
        }
        parentItem->child(toprow, 0)->setData(tr("MEM:Battle"), Qt::UserRole);
        parentItem->child(toprow, 1)->setData(QString(), Qt::EditRole);
        parentItem->child(toprow, 2)->setData(QString("Memory only"), Qt::EditRole);

        int row = 0;
        TreeItemBase* ptree = parentItem->child(toprow, 0);

        int oldRowCount = ptree->rowCount();
        if (nrBattleSections > oldRowCount)
        {
            beginInsertRows(createIndex(toprow, 0, ptree), oldRowCount, nrBattleSections - 1);
        }

        if ((0 != game) && (0 != game->getDataSegment()))
        {
            if (row == ptree->rowCount())
            {
                ptree->appendEmptyRow();
            }

            ptree->child(row, 0)->setData(tr("Battle_Units"), Qt::UserRole);
            const MoM::EXE_Reloc& addr = game->getDataSegment()->m_WizardsExe_Pointers.addr_Battle_Unit;
            ptree->child(row, 1)->setData(toQStr(addr), Qt::EditRole);
            if (0 != game->getNumber_of_Battle_Units())
            {
                int nrBattle_Units = *game->getNumber_of_Battle_Units();
                ptree->child(row, 2)->setData(tr("NrBattle_Units = %0").arg(nrBattle_Units), Qt::EditRole);
            }
            else
            {
                ptree->child(row, 2)->setData(QString(), Qt::EditRole);
            }

            int subrow = 0;
            TreeItemBase* psubtree = ptree->child(row, 0);
            update_Battle_Units(psubtree, game, subrow);
            removeUnusedRows(row, psubtree, subrow);

            row++;
        }

        update_Battlefield(ptree, game, row);

        update_Spells_Cast_in_Battle(ptree, game, row);

        if (nrBattleSections > oldRowCount)
        {
            endInsertRows();
        }
        removeUnusedRows(toprow, ptree, row);

        toprow++;
    }

    {
        if (toprow == parentItem->rowCount())
        {
            parentItem->appendEmptyRow();
        }

        parentItem->child(toprow, 0)->setData(tr("Current Unit View"), Qt::UserRole);
        if ((0 != game) && (0 != game->getDataSegment()))
        {
            const MoM::EXE_Reloc& addr = game->getDataSegment()->m_WizardsExe_Pointers.addr_Battle_Unit_View;
            parentItem->child(toprow, 1)->setData(toQStr(addr), Qt::EditRole);
        }
        else
        {
            parentItem->child(toprow, 1)->setData(QString(), Qt::EditRole);
        }
        parentItem->child(toprow, 2)->setData(QString(), Qt::EditRole);

        int row = 0;
        TreeItemBase* ptree = parentItem->child(toprow, 0);
        update_Battle_Unit_View(ptree, game, row);
        removeUnusedRows(toprow, ptree, row);

        toprow++;
    }

    {
        if (toprow == parentItem->rowCount())
        {
            parentItem->appendEmptyRow();
        }

        int nrMiscellaneous = 0;
        parentItem->child(toprow, 0)->setData(tr("EXE:Miscellaneous"), Qt::UserRole);
        parentItem->child(toprow, 1)->setData(QString(), Qt::EditRole);
        parentItem->child(toprow, 2)->setData(QString("MODIFIES Wizards.exe"), Qt::EditRole);

        int row = 0;
        TreeItemBase* ptree = parentItem->child(toprow, 0);

        uint8_t* ovl117 = 0;
        uint8_t* ovl122 = 0;
        uint8_t* ovl140 = 0;
        uint8_t* ovl164 = 0;
        if (0 != game)
        {
            ovl117 = game->getWizardsOverlay(117);
            ovl122 = game->getWizardsOverlay(122);
            ovl140 = game->getWizardsOverlay(140);
            ovl164 = game->getWizardsOverlay(164);
        }
        if ((0 != ovl117) && (0 != ovl122) && (0 != ovl140) && (0 != ovl140))
        {
            nrMiscellaneous = 6;        // TODO: Proper number
        }

        int oldRowCount = ptree->rowCount();
        if (nrMiscellaneous > oldRowCount)
        {
            beginInsertRows(createIndex(toprow, 0, ptree), oldRowCount, nrMiscellaneous - 1);
        }

        if ((0 != ovl117) && (0 != ovl122) && (0 != ovl140) && (0 != ovl140))
        {
            if (0 == ptree->rowCount())
            {
                if (game->getMoM_Version() >= std::string("1.40j"))
                {
                    ptree->appendChild("City Wall Defense", new TreeItem<int8_t>((int8_t*)&ovl122[ 0x0FEB ]));
                    ptree->child(row, 2)->setData("Default +3 shields", Qt::EditRole);
                    row++;
                    ptree->appendChild("Broken Wall Defense", new TreeItem<int8_t>((int8_t*)&ovl122[ 0x0FF1 ]));
                    ptree->child(row, 2)->setData("Default +1 shields", Qt::EditRole);
                    row++;
                }
                else
                {
                    ptree->appendChild("City Wall Defense", new TreeItem<int8_t>((int8_t*)&ovl122[ 0x0FEC ]));
                    ptree->child(row, 2)->setData("Default +3 shields", Qt::EditRole);
                    row++;
                    ptree->appendChild("Broken Wall Defense", new TreeItemBase("1 (unchangeable)"));
                    ptree->child(row, 2)->setData("Default +1 shields", Qt::EditRole);
                    row++;
                }
                ptree->appendChild("Large Shield", new TreeItem<int8_t>((int8_t*)&ovl122[ 0x16F1 ]));
                ptree->child(row, 2)->setData("Default +2 shields", Qt::EditRole);
                row++;

                ptree->appendChild("Noble", new TreeItem<int8_t>((int8_t*)&ovl140[ 0x068F ]));
                ptree->child(row, 2)->setData("Default 10 gold/turn", Qt::EditRole);
                row++;

                ptree->appendChild("Turns before AI aggressive", new TreeItem<int8_t>((int8_t*)&ovl164[ 0x12BB ]));
                ptree->child(row, 2)->setData("Default 100 turns", Qt::EditRole);
                row++;

                ptree->appendChild("Max spells of colored unit", new TreeItem<int8_t>((int8_t*)&ovl117[ 0x0179 ]));
                ptree->child(row, 2)->setData("Default 40 spells", Qt::EditRole);
                row++;
            }
        }

        if (nrMiscellaneous > oldRowCount)
        {
            endInsertRows();
        }

        if (0 == nrMiscellaneous)
        {
            removeUnusedRows(toprow, ptree, row);
        }

        toprow++;
    }

    {
        if (toprow == parentItem->rowCount())
        {
            parentItem->appendEmptyRow();
        }

        int nrCustomizerSections = 0;
        if ((0 != game) && (0 != game->getMagicDataSegment()))
        {
            nrCustomizerSections = 2; // TODO: Proper number
        }
        parentItem->child(toprow, 0)->setData(tr("Customizer"), Qt::UserRole);
        parentItem->child(toprow, 1)->setData(QString(), Qt::EditRole);
        parentItem->child(toprow, 2)->setData(QString("Setup only"), Qt::EditRole);

        int row = 0;
        TreeItemBase* ptree = parentItem->child(toprow, 0);

        int oldRowCount = ptree->rowCount();
        if (nrCustomizerSections > oldRowCount)
        {
            beginInsertRows(createIndex(toprow, 0, ptree), oldRowCount, nrCustomizerSections - 1);
        }

        if ((0 != game) && (0 != game->getMagicDataSegment()))
        {
            if (row == ptree->rowCount())
            {
                ptree->appendEmptyRow();
            }

            ptree->child(row, 0)->setData(tr("MEM:Customizer"), Qt::UserRole);
            ptree->child(row, 1)->setData(QString(), Qt::EditRole);
            ptree->child(row, 2)->setData(QString(), Qt::EditRole);

            int subrow = 0;
            TreeItemBase* psubtree = ptree->child(row, 0);
            MoM::MoMMagicDataSegment* pMagicDataSegment = game->getMagicDataSegment();

            if (0 == psubtree->rowCount())
            {
                psubtree->appendChild("Sorcery_Picks_Divider", new TreeItem<uint16_t>(&pMagicDataSegment->m_Sorcery_Picks_Divider));
                subrow++;
                psubtree->appendChild("Nature_Picks_Divider", new TreeItem<uint16_t>(&pMagicDataSegment->m_Nature_Picks_Divider));
                subrow++;
                psubtree->appendChild("Chaos_Picks_Divider", new TreeItem<uint16_t>(&pMagicDataSegment->m_Chaos_Picks_Divider));
                subrow++;
                psubtree->appendChild("Death_Picks_Divider", new TreeItem<uint16_t>(&pMagicDataSegment->m_Death_Picks_Divider));
                subrow++;
                psubtree->appendChild("Life_Picks_Divider", new TreeItem<uint16_t>(&pMagicDataSegment->m_Life_Picks_Divider));
                subrow++;

                psubtree->appendChild("Total_Picks_Left", new TreeItem<uint16_t>(&pMagicDataSegment->m_Total_Picks_Left));
                subrow++;

//                psubtree->appendChild("Select_Wizard_Shown", new TreeItem<MoM::ePortrait>(&pMagicDataSegment->m_Select_Wizard_Shown));
//                subrow++;

                for (MoM::ePortrait portrait = (MoM::ePortrait)0; portrait < MoM::ePortrait_MAX; MoM::inc(portrait))
                {
                    psubtree->appendTree(constructTreeItem(&pMagicDataSegment->m_Wizard_Types[portrait], toQStr(portrait)), "");
                    psubtree->child(subrow, 1)->setData(QString(), Qt::EditRole);
                    psubtree->child(subrow, 2)->setData(QString("WizardType[%0]").arg((int)portrait), Qt::EditRole);
                    subrow++;
                }

                for (MoM::eUnit_Type heroType = (MoM::eUnit_Type)0; heroType < MoM::gMAX_HERO_TYPES; MoM::inc(heroType))
                {
                    psubtree->appendTree(constructTreeItem(&pMagicDataSegment->m_Hero_Stats_Initializers[heroType], toQStr(heroType)), "");
                    psubtree->child(subrow, 1)->setData(QString(), Qt::EditRole);
                    psubtree->child(subrow, 2)->setData(QString("HeroType[%0]").arg((int)heroType), Qt::EditRole);
                    subrow++;
                }
            }

//            removeUnusedRows(row, psubtree, subrow);

            row++;
        }

        uint8_t* magicExeContents = 0;
        uint8_t* ovl51 = 0;
        if (0 != game)
        {
            magicExeContents = game->getMagicExeContents();
            ovl51 = game->getMagicOverlay(51);
        }
        if ((0 != magicExeContents) && (0 != ovl51))
        {
            if (row == ptree->rowCount())
            {
                ptree->appendEmptyRow();
            }

            ptree->child(row, 0)->setData(tr("EXE:Customizer"), Qt::UserRole);
            ptree->child(row, 1)->setData(QString(), Qt::EditRole);
            ptree->child(row, 2)->setData(QString("MODIFIES Magic.exe"), Qt::EditRole);

            int subrow = 0;
            TreeItemBase* psubtree = ptree->child(row, 0);

            if (0 == psubtree->rowCount())
            {
                psubtree->appendChild("Total picks", new TreeItem<uint16_t>((uint16_t*)&magicExeContents[0x3394B]));
                psubtree->child(subrow, 2)->setData("(default 11)", Qt::EditRole);
                subrow++;

                psubtree->appendChild("Landmass_total_tiles Small", new TreeItem<uint16_t>((uint16_t*)&ovl51[0x1E9A + 3]));
                psubtree->child(subrow, 2)->setData("(default 360)", Qt::EditRole);
                subrow++;
                psubtree->appendChild("Landmass_total_tiles Medium", new TreeItem<uint16_t>((uint16_t*)&ovl51[0x1EA1 + 3]));
                psubtree->child(subrow, 2)->setData("(default 480)", Qt::EditRole);
                subrow++;
                psubtree->appendChild("Landmass_total_tiles Large", new TreeItem<uint16_t>((uint16_t*)&ovl51[0x1EA8 + 3]));
                psubtree->child(subrow, 2)->setData("Game may freeze if too high 1200 < n <= 1720  (default 720)", Qt::EditRole);
                subrow++;

                psubtree->appendChild("Landmass_min continent_tiles Small", new TreeItem<uint16_t>((uint16_t*)&ovl51[0x1F61 + 1]));
                psubtree->child(subrow, 2)->setData("10 + dice(n)  (default 5: 6-15)", Qt::EditRole);
                subrow++;
                psubtree->appendChild("Landmass_min continent_tiles Medium", new TreeItem<uint16_t>((uint16_t*)&ovl51[0x1F73 + 1]));
                psubtree->child(subrow, 2)->setData("10 + dice(n)  (default 10: 11-20)", Qt::EditRole);
                subrow++;
                psubtree->appendChild("Landmass_min continent_tiles Large", new TreeItem<uint16_t>((uint16_t*)&ovl51[0x1F82 + 1]));
                psubtree->child(subrow, 2)->setData("10 + dice(n)  (default 20: 21-30)", Qt::EditRole);
                subrow++;

                psubtree->appendChild("Nr of Towers", new TreeItem<uint8_t>(&ovl51[0x08C1 + 2]));
                psubtree->child(subrow, 2)->setData("Max 6 towers  (default 6)", Qt::EditRole);
                subrow++;
//                psubtree->appendChild("Offset Myrror Towers (don't change)", new TreeItem<uint8_t>(&ovl51[0x2EE1 + 2]));
//                subrow++;
                psubtree->appendChild("Nr of Towers + 6", new TreeItem<uint8_t>(&ovl51[0x2F31 + 2]));
                psubtree->child(subrow, 2)->setData("Always set to towers + 6", Qt::EditRole);
                subrow++;
                psubtree->appendChild("Nr Normal lairs", new TreeItem<uint16_t>((uint16_t*)&magicExeContents[0x3933E + 3]));
                psubtree->child(subrow, 2)->setData("Max 25  (default 25)", Qt::EditRole);
                subrow++;
                psubtree->appendChild("Nr Weak lairs", new TreeItem<uint8_t>(&magicExeContents[0x396A2 + 2]));
                psubtree->child(subrow, 2)->setData("Max 32  (default 32)", Qt::EditRole);
                subrow++;

                psubtree->appendChild("Normal lair monster cash Arcanus", new TreeItem<uint16_t>((uint16_t*)&magicExeContents[0x39574 + 1]));
                psubtree->child(subrow, 2)->setData("dice(n) * 50 + 50  (default 29: 100-1500)", Qt::EditRole);
                subrow++;
                psubtree->appendChild("Normal lair monster cash Myrror", new TreeItem<uint16_t>((uint16_t*)&magicExeContents[0x39588 + 1]));
                psubtree->child(subrow, 2)->setData("dice(n) * 100 + 100  (default 24: 200-2500)", Qt::EditRole);
                subrow++;
                psubtree->appendChild("Weak lair monster cash Arcanus", new TreeItem<uint16_t>((uint16_t*)&magicExeContents[0x3966B + 1]));
                psubtree->child(subrow, 2)->setData("dice(n) * 10  (default 10: 10-100)", Qt::EditRole);
                subrow++;
                psubtree->appendChild("Weak lair monster cash Myrror", new TreeItem<uint16_t>((uint16_t*)&magicExeContents[0x39670 + 1]));
                psubtree->child(subrow, 2)->setData("dice(n) * 10  (default 20: 20-200)", Qt::EditRole);
                subrow++;
                psubtree->appendChild("Nr monsters in lair (dice)", new TreeItem<uint16_t>((uint16_t*)&magicExeContents[0x39987 + 1]));
                psubtree->child(subrow, 2)->setData("dice(n)  See OSG p.416-418  (default n = 4)", Qt::EditRole);
                subrow++;
                psubtree->appendChild("Nr secondary monsters in lair (dice)", new TreeItem<uint16_t>((uint16_t*)&magicExeContents[0x39B6E + 1]));
                psubtree->child(subrow, 2)->setData("dice(n - Nr primary monsters)  (default n = 10)", Qt::EditRole);
                subrow++;
                psubtree->appendChild("Lower primary monsters (dice)", new TreeItem<uint16_t>((uint16_t*)&magicExeContents[0x39A93 + 1]));
                psubtree->child(subrow, 2)->setData("1 in dice(n) throws primary back  (default n = 2)", Qt::EditRole);
                subrow++;

                psubtree->appendChild("Chance same race on continents (dice)", new TreeItem<uint16_t>((uint16_t*)&magicExeContents[0x3DD82 + 1]));
                psubtree->child(subrow, 2)->setData("1 in dice(n) makes the race random  (default n = 4)", Qt::EditRole);
                subrow++;

                psubtree->appendChild("Distance to connect cities", new TreeItem<uint16_t>((uint16_t*)&magicExeContents[0x3EAF0 + 1]));
                psubtree->child(subrow, 2)->setData("Diagonal tiles count as 1.5  (default 11 squares)", Qt::EditRole);
                subrow++;

                psubtree->appendChild("Turns before random events start", new TreeItem<uint16_t>((uint16_t*)&magicExeContents[0x47C32 + 3]));
                psubtree->child(subrow, 2)->setData("(default 50 turns)", Qt::EditRole);
                subrow++;

                psubtree->appendChild("Random picks of opponents on Normal (dice)", new TreeItem<uint16_t>((uint16_t*)&magicExeContents[0x467f2 + 1]));
                psubtree->child(subrow, 2)->setData("dice(n)  (default n = 3)", Qt::EditRole);
                subrow++;
                psubtree->appendChild("Random picks of opponents on Hard (dice)", new TreeItem<uint16_t>((uint16_t*)&magicExeContents[0x46801 + 1]));
                psubtree->child(subrow, 2)->setData("dice(n) + d3  (default n = 3)", Qt::EditRole);
                subrow++;
                psubtree->appendChild("Random picks of opponents on Impossible (dice)", new TreeItem<uint16_t>((uint16_t*)&magicExeContents[0x46811 + 1]));
                psubtree->child(subrow, 2)->setData("dice(n) + d5  (default n = 5)", Qt::EditRole);
                subrow++;
                psubtree->appendChild("Random picks of opponents on Impossible+1 (dice)", new TreeItem<uint16_t>((uint16_t*)&magicExeContents[0x46821 + 1]));
                psubtree->child(subrow, 2)->setData("dice(n) + d8  (default n = 8)", Qt::EditRole);
                subrow++;

                psubtree->appendChild("Total nr of AI picks on Normal and below", new TreeItem<uint16_t>((uint16_t*)&magicExeContents[0x469ed + 3]));
                psubtree->child(subrow, 2)->setData("(default 11 picks)", Qt::EditRole);
                subrow++;
                psubtree->appendChild("Total nr of AI picks on Hard", new TreeItem<uint16_t>((uint16_t*)&magicExeContents[0x469f9 + 3]));
                psubtree->child(subrow, 2)->setData("(default 13 picks)", Qt::EditRole);
                subrow++;
                psubtree->appendChild("Total nr of AI picks on Impossible", new TreeItem<uint16_t>((uint16_t*)&magicExeContents[0x46a05 + 3]));
                psubtree->child(subrow, 2)->setData("(default 15 picks)", Qt::EditRole);
                subrow++;
            }

//            removeUnusedRows(row, psubtree, subrow);

            row++;
        }

        if (nrCustomizerSections > oldRowCount)
        {
            endInsertRows();
        }
        if (0 == nrCustomizerSections)
        {
            removeUnusedRows(toprow, ptree, row);
        }

        toprow++;
    }

    if (0 != game)
    {
        MoM::Available_spell_page* availableSpellPages = game->getAvailable_spell_pages();
        MoM::Available_spell_page& first = *availableSpellPages;

        MoM::eSpell16* hero_spells = game->getHero_spells();
        MoM::eSpell16& spell = *hero_spells;
    }


    emit dataChanged(index(0, 0), index(parentItem->rowCount() - 1, m_columnCount - 1));
}
