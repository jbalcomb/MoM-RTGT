// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include <QClipboard>
#include <QKeyEvent>
#include <QMenu>

#include <string>

#include "dialogtables.h"
#include "ui_dialogtables.h"

#include "MoMExeWizards.h"
#include "MoMGenerated.h"
#include "MoMTemplate.h"
#include "MoMUtility.h"
#include "mainwindow.h"
#include "QMoMSettings.h"
#include "QMoMTableItem.h"

DialogTables::DialogTables(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTables)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window);

    // Update view when game is changed or updated
    QObject::connect(MainWindow::getInstance(), SIGNAL(signal_gameChanged(QMoMGamePtr)), this, SLOT(slot_gameChanged(QMoMGamePtr)));
    QObject::connect(MainWindow::getInstance(), SIGNAL(signal_gameUpdated()), this, SLOT(slot_gameUpdated()));

    slot_gameChanged(MainWindow::getInstance()->getGame());

    QMoMSettings::readSettings(this);
}

DialogTables::~DialogTables()
{
    QMoMSettings::writeSettings(this);

    delete ui;
}

void DialogTables::keyPressEvent(QKeyEvent* event)
{
    //if there is a control-C event copy data to the global clipboard
    if ((event->key() == Qt::Key_C) && (event->modifiers() & Qt::ControlModifier))
    {
        slot_Copy();
    }
    else
    {
        QDialog::keyPressEvent(event);
    }
}

QColor DialogTables::getRaceColor(MoM::eRace race) const
{
    QColor color = Qt::gray;
    switch (race)
    {
    case MoM::RACE_Nature:     color = Qt::darkGreen;   break;
    case MoM::RACE_Sorcery:    color = Qt::blue;        break;
    case MoM::RACE_Chaos:      color = Qt::darkRed;     break;
    case MoM::RACE_Life:       color = Qt::darkGray;    break;
    case MoM::RACE_Death:      color = Qt::black;       break;
    case MoM::RACE_Arcane:     color = Qt::darkYellow;  break;
    default:                   color = Qt::black;       break;
    }
    return color;
}

void DialogTables::initializeTable(const QStringList &labels, int rows)
{
    ui->tableWidget->setColumnCount(labels.size());
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    ui->tableWidget->setRowCount(rows);

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
    {
        ui->tableWidget->setVerticalHeaderItem(row, new QTableWidgetItem(""));
    }
}

void DialogTables::finalizeTable()
{
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->sortByColumn(0, Qt::AscendingOrder);
    ui->tableWidget->setSortingEnabled(true);
}

void DialogTables::update_Building_Data()
{
    int ndata = 0;
    if (!m_game.isNull())
    {
        ndata = MoM::eBuilding_array_MAX;
    }

    QStringList labels;
    labels << "Nr";
    labels << "BuildingName" << "Prerequisite1" << "Prerequisite2" << "Replaces" << "Regulars" << "Veterans" << "Magic Weapons" << "Upkeep"
           << "Cost" << "Category" << "Animation";
    labels << "Trade/housing" << "Zero_24" << "Zero_26" << "Religious" << "Research" << "Zero_2E";

    initializeTable(labels, ndata);

    for (int row = 0; row < ndata; ++row)
    {
        MoM::eBuilding building = (MoM::eBuilding)row;
        MoM::Building_Data* data = m_game->getBuildingData(building);
        if (0 == data)
            break;

        int col = 0;
        ui->tableWidget->setItem(row, col++, new QMoMTableItemBase(m_game, QString("%0").arg(row, 3)));

        ui->tableWidget->setItem(row, col++, new TextTableItem(m_game, data->m_BuildingName, sizeof(data->m_BuildingName)));
        ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eBuilding>(m_game, &data->m_Prerequisite1, MoM::eBuilding_extra_MAX, SHOWENUM_minusOneAndnoZero));
        ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eBuilding>(m_game, &data->m_Prerequisite2, MoM::eBuilding_extra_MAX, SHOWENUM_minusOneAndnoZero));
        ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eBuilding>(m_game, &data->m_Replaces_building, MoM::eBuilding_extra_MAX, SHOWENUM_minusOneAndnoZero));
        ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eYesNo16>(m_game, &data->m_Produces_Regulars, MoM::eYesNo16_MAX, SHOWENUM_noZero));
        ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eYesNo16>(m_game, &data->m_Produces_Veterans, MoM::eYesNo16_MAX, SHOWENUM_noZero));
        ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eYesNo16>(m_game, &data->m_Produces_Magic_Weapons, MoM::eYesNo16_MAX, SHOWENUM_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int16_t>(m_game, &data->m_Upkeep_yield, 2, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint16_t>(m_game, &data->m_Building_cost, 2, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eBuildingCategory>(m_game, &data->m_Building_category, MoM::eBuildingCategory_MAX));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int16_t>(m_game, &data->m_Animation_related, 2, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint16_t>(m_game, &data->m_AI_trade_goods_housing, 2, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint16_t>(m_game, &data->m_Zero_24, 2, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint16_t>(m_game, &data->m_Zero_26, 2, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint16_t>(m_game, &data->m_AI_Religious, 2, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint16_t>(m_game, &data->m_AI_Research, 2, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint16_t>(m_game, &data->m_Zero_2E, 2, SHOWNUMBER_noZero));
    }

    finalizeTable();
}

void DialogTables::update_Item_Data()
{
    int ndata = 0;
    if (!m_game.isNull())
    {
        ndata = m_game->getNrItemDataLbx();
    }

    QStringList labels;
    labels << "Nr";
    labels << "ItemName" << "Icon" << "Slot" << "Item Type" << "Cost";
    labels << "Att" << "ToHit" << "Def" << "Move" << "Resist" << "Mana" << "Save";
    labels << "Spell" << "NrCharges" << "Powers";
    labels << "Unk32[0]" << "Unk32[1]" << "Unk32[2]" << "Unk32[3]" << "Unk32[4]" << "Unk37";

    initializeTable(labels, ndata);

    for (int row = 0; row < ndata; ++row)
    {
        MoM::ItemDataLbx* dataLbx = m_game->getItemDataLbx(row);
        if (0 == dataLbx)
            break;
        MoM::Item* data = &dataLbx->m_Item;

        int col = 0;
        ui->tableWidget->setItem(row, col++, new QMoMTableItemBase(m_game, QString("%0").arg(row, 3)));

        ui->tableWidget->setItem(row, col++, new TextTableItem(m_game, data->m_Item_Name, sizeof(data->m_Item_Name)));
        ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eItem_Icon>(m_game, &data->m_Icon, MoM::eItem_Icon_MAX));
        ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eSlot_Type8>(m_game, &data->m_Slot_Required, MoM::eSlot_Type8_MAX));
        ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eItem_Type>(m_game, &data->m_Item_Type, MoM::eItem_Type_MAX));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int16_t>(m_game, &data->m_Cost, 5));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int8_t>(m_game, &data->m_Bonuses.Attack, 2, SHOWNUMBER_plusAndNoZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int8_t>(m_game, &data->m_Bonuses.To_Hit, 2, SHOWNUMBER_plusAndNoZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int8_t>(m_game, &data->m_Bonuses.Defense, 2, SHOWNUMBER_plusAndNoZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int8_t>(m_game, &data->m_Bonuses.Movement_in_halves, 2, SHOWNUMBER_plusAndNoZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int8_t>(m_game, &data->m_Bonuses.Resistance, 2, SHOWNUMBER_plusAndNoZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int8_t>(m_game, &data->m_Bonuses.Spell_Points, 2, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int8_t>(m_game, &data->m_Bonuses.Spell_Save, 2, SHOWNUMBER_plusAndNoZero));
        ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eSpell>(m_game, &data->m_Spell_Number_Charged, MoM::eSpell_MAX, SHOWENUM_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int16_t>(m_game, &data->m_Number_Of_Charges, 2, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new BitmaskTableItem<uint32_t, MoM::eItemPower>(
                                     m_game, &data->m_Bitmask_Powers.bits, (MoM::eItemPower)0, MoM::eItemPower_MAX));

        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, &dataLbx->m_Index_in_spellbook_GUESS[0], 3, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, &dataLbx->m_Index_in_spellbook_GUESS[1], 3, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, &dataLbx->m_Index_in_spellbook_GUESS[2], 3, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, &dataLbx->m_Index_in_spellbook_GUESS[3], 3, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, &dataLbx->m_Index_in_spellbook_GUESS[4], 3, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, &dataLbx->m_Unk_37, 3, SHOWNUMBER_noZero));
    }

    finalizeTable();
}

void DialogTables::update_Item_Powers()
{
    int ndata = 0;
    if (!m_game.isNull())
    {
        ndata = m_game->getNrItemPowLbx();
    }

    QStringList labels;
    labels << "Nr";
    labels << "PowerName" << "Enchantible" << "Mana" << "Power Type" << "Bonus/NrBooks" << "Powers";

    initializeTable(labels, ndata);

    for (int row = 0; row < ndata; ++row)
    {
        MoM::ItemPowLbx* data = m_game->getItemPowLbx(row);
        if (0 == data)
            break;

        int col = 0;
        ui->tableWidget->setItem(row, col++, new QMoMTableItemBase(m_game, QString("%0").arg(row, 3)));

        ui->tableWidget->setItem(row, col++, new TextTableItem(m_game, data->m_Name, sizeof(data->m_Name)));
        ui->tableWidget->setItem(row, col++, new BitmaskTableItem<uint32_t, MoM::eItem_Type>(
                                     m_game, &data->m_Bitmask_Powers.bits, (MoM::eItem_Type)0, MoM::eItem_Type_MAX));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int16_t>(m_game, &data->m_Mana_cost_to_enchant, 5));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint16_t>(m_game, &data->m_PowerType, 1, SHOWNUMBER_hex));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int16_t>(m_game, &data->m_Required_Nr_Spell_Books, 2));
        ui->tableWidget->setItem(row, col++, new BitmaskTableItem<uint32_t, MoM::eItemPower>(
                                     m_game, &data->m_Bitmask_Powers.bits, (MoM::eItemPower)0, MoM::eItemPower_MAX));
    }

    finalizeTable();
}

void DialogTables::update_Items_in_game()
{
    int ndata = 0;
    if (!m_game.isNull())
    {
        ndata = MoM::gMAX_ITEMS;
    }

    QStringList labels;
    labels << "Nr";
    labels << "ItemName" << "Icon" << "Slot" << "Item Type" << "Cost";
    labels << "Att" << "ToHit" << "Def" << "Move" << "Resist" << "Mana" << "Save";
    labels << "Spell" << "NrCharges" << "Powers";

    initializeTable(labels, ndata);

    for (int row = 0; row < ndata; ++row)
    {
        MoM::Item* data = m_game->getItem(row);
        if (0 == data)
            break;

        int col = 0;
        ui->tableWidget->setItem(row, col++, new QMoMTableItemBase(m_game, QString("%0").arg(row, 3)));

        ui->tableWidget->setItem(row, col++, new TextTableItem(m_game, data->m_Item_Name, sizeof(data->m_Item_Name)));
        ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eItem_Icon>(m_game, &data->m_Icon, MoM::eItem_Icon_MAX));
        ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eSlot_Type8>(m_game, &data->m_Slot_Required, MoM::eSlot_Type8_MAX));
        ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eItem_Type>(m_game, &data->m_Item_Type, MoM::eItem_Type_MAX));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int16_t>(m_game, &data->m_Cost, 5));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int8_t>(m_game, &data->m_Bonuses.Attack, 2, SHOWNUMBER_plusAndNoZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int8_t>(m_game, &data->m_Bonuses.To_Hit, 2, SHOWNUMBER_plusAndNoZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int8_t>(m_game, &data->m_Bonuses.Defense, 2, SHOWNUMBER_plusAndNoZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int8_t>(m_game, &data->m_Bonuses.Movement_in_halves, 2, SHOWNUMBER_halfMove));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int8_t>(m_game, &data->m_Bonuses.Resistance, 2, SHOWNUMBER_plusAndNoZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int8_t>(m_game, &data->m_Bonuses.Spell_Points, 2, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int8_t>(m_game, &data->m_Bonuses.Spell_Save, 2, SHOWNUMBER_plusAndNoZero));
        ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eSpell>(m_game, &data->m_Spell_Number_Charged, MoM::eSpell_MAX, SHOWENUM_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int16_t>(m_game, &data->m_Number_Of_Charges, 2, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new BitmaskTableItem<uint32_t, MoM::eItemPower>(
                                     m_game, &data->m_Bitmask_Powers.bits, (MoM::eItemPower)0, MoM::eItemPower_MAX));
    }

    finalizeTable();
}

void DialogTables::update_Race_Data()
{
    int ndata = 0;
    if (!m_game.isNull())
    {
        ndata = MoM::gMAX_RACES;
    }

    QStringList labels;
    labels << "Nr";
    labels << "RaceName" << "Nr prohibited";
    for (size_t i = 0; i < ARRAYSIZE(((MoM::Race_Data*)0)->m_Prohibited_buildings); ++i)
    {
        labels << QString("Prohibited%0").arg(1 + i);
    }
    labels << "Outpost growth (%)" << "City growth (10/turn)" << "Housing";

    initializeTable(labels, ndata);

    for (int row = 0; row < ndata; ++row)
    {
        MoM::eRace race = (MoM::eRace)row;
        MoM::Race_Data* data = m_game->getRaceData(race);
        if (0 == data)
            break;

        int col = 0;
        ui->tableWidget->setItem(row, col++, new QMoMTableItemBase(m_game, QString("%0").arg(row, 3)));

        char* ptrName = const_cast<char*>(m_game->getNameByOffset(data->m_PtrName));
        ui->tableWidget->setItem(row, col, new TextTableItem(m_game, ptrName, strlen(ptrName) + 1));
        ui->tableWidget->item(row, col)->setTextColor(getRaceColor(race));
        ui->tableWidget->item(row, col++)->setToolTip(m_game->getHelpText(race).c_str());

        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint16_t>(m_game, &data->m_Number_of_prohibited_buildings, 2));
        for (size_t i = 0; i < ARRAYSIZE(data->m_Prohibited_buildings); ++i)
        {
            ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eBuilding>(m_game, &data->m_Prohibited_buildings[i], MoM::eBuilding_extra_MAX, SHOWENUM_noZero));
        }

        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint16_t>(m_game, &data->m_Outpost_growth_probability, 2));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int16_t>(m_game, &data->m_City_population_growth_modifier, 2, SHOWNUMBER_plusAndNoZero));
        ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eHousing>(m_game, &data->m_Housing_picture, MoM::eHousing_MAX));
    }

    finalizeTable();
}

void DialogTables::update_Spell_Data()
{
    MoM::Upkeep_Enchantments* upkeepEnchantments = 0;
    MoM::MoMExeWizards* wizardsExe = 0;
    uint8_t* ovl112 = 0;
    int ndata = 0;

    if (!m_game.isNull())
    {
        if (0 != m_game->getDataSegment())
        {
            upkeepEnchantments = &m_game->getDataSegment()->m_Upkeep_Enchantments;
        }
        wizardsExe = m_game->getWizardsExe();
        ovl112 = m_game->getWizardsOverlay(112);
        if (0 != m_game->getSpellData((MoM::eSpell)0))
        {
            ndata = (int)MoM::eSpell_MAX - 1;
        }
    }

    QStringList labels;
    labels << "Nr";
    labels << "SpellName" << "Desirability" << "Category" << "Section" << "Realm" << "Elegibility"
            << "Casting" << "Research" << "Parameter" << "Immunities" << "Attack Flags";
    labels<< "Upkeep";
    labels<< "Save";

    initializeTable(labels, ndata);

    for (int row = 0; row < ndata; ++row)
    {
        int spellNr = row + 1;
        MoM::eSpell spell = (MoM::eSpell)spellNr;
        MoM::Spell_Data* data = m_game->getSpellData(spell);

        MoM::eRealm_Type realm = (MoM::eRealm_Type)((spellNr - 1) / 40);
        QColor color = Qt::gray;
        switch (realm)
        {
        case MoM::REALM_Nature:     color = Qt::darkGreen; break;
        case MoM::REALM_Sorcery:    color = Qt::blue; break;
        case MoM::REALM_Chaos:      color = Qt::darkRed; break;
        case MoM::REALM_Life:       color = Qt::darkGray; break;
        case MoM::REALM_Death:      color = Qt::black; break;
        case MoM::REALM_Arcane:     color = Qt::darkYellow; break;
        default:                    break;
        }

        int col = 0;
        ui->tableWidget->setItem(row, col++, new QMoMTableItemBase(m_game, QString("%0").arg(spellNr, 3)));

        ui->tableWidget->setItem(row, col, new TextTableItem(m_game, data->m_SpellName, sizeof(data->m_SpellName)));
        ui->tableWidget->item(row, col)->setTextColor(color);
        ui->tableWidget->item(row, col++)->setToolTip(m_game->getHelpText(spell).c_str());

        ui->tableWidget->setItem(row, col++, new NumberTableItem<int16_t>(m_game, &data->m_Spell_desirability, 6));
        ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eSpellCategory>(m_game, &data->m_Spell_Category, MoM::eSpellCategory_MAX));
        ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eSpell_Type>(m_game, &data->m_Section_in_spell_book, MoM::eSpell_Type_MAX));
        ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eRealm_Type>(m_game, &data->m_Magic_Realm, MoM::eRealm_Type_MAX));

        ui->tableWidget->setItem(row, col++, new NumberTableItem<int8_t>(m_game, &data->m_Casting_eligibility, 4));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint16_t>(m_game, &data->m_Casting_cost, 5));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint16_t>(m_game, &data->m_Research_cost, 5));

        QMoMTableItemBase* itemParameters[4] = { 0, 0, 0, 0 };
        switch (data->m_Spell_Category)
        {
        case MoM::SPELLCATEGORY_Normal_summon:     // normal summoning spell (all but hero/champion/torin). Byte 0x20 contains the creature summoned, 21-23 are blank.
            itemParameters[0] = new QMoMTableItemBase(m_game, prettyQStr((MoM::eUnit_Type)data->m_Parameters[0]));
            break;
        case MoM::SPELLCATEGORY_Unit_enchantment:  // enchantment that can be cast on a friendly unit. Bytes 0x20-0x23 contain the mask for the enchantment applied (same as bytes 0x18-0x1B in the unit data structure in the save file). While no current spells do this, it is possible to set more than one bit; doing so will apply both spells, and will also prevent casting if either spell is already on the unit.
        case MoM::SPELLCATEGORY_Mundane_Unit_enchantment:          // friendly unit enchantment that only works on mundane units. Otherwise identical to 0x01.
            itemParameters[0] = new BitmaskTableItem<uint32_t, MoM::eUnitEnchantment>(
                        m_game, (uint32_t*)&data->m_Parameters[0],
                        (MoM::eUnitEnchantment)0, MoM::eUnitEnchantment_MAX);
            itemParameters[1] = new QMoMTableItemBase(m_game, QString());
            itemParameters[2] = new QMoMTableItemBase(m_game, QString());
            break;
        case MoM::SPELLCATEGORY_Friendly_City_enchantment:  // enchantment hits a friendly city. Byte 0x20 contains the code for the city enchantment, in the same order as for city enchantments in the save file, but starts at 0 (0x00 is wall of fire, 0x18 is altar of battle).
        case MoM::SPELLCATEGORY_Hostile_City_enchantment:  // enchantment hits a hostile city. Byte 0x20 is the same as above.
            break;
        case MoM::SPELLCATEGORY_Fixed_damage:      // non-moddable damaging spell. Byte 0x20 is the magnitude, 0x21 is the immunity flags that apply (same as for monsters), 0x22 and 0x23 are attack flags (same as for monsters, but for byte 0x23, 0x80, listed as no effect for monsters, makes it act like warp lightning, and 0x10 makes it act like fireball. Neither flag seems to apply to critter attacks, though I haven't tried all possible combinations. Not all attack flags work for spells).
            itemParameters[0] = new NumberTableItem<uint8_t>(m_game, &data->m_Parameters[0], 4, SHOWNUMBER_normal);
            itemParameters[1] = new BitmaskTableItem<uint8_t, MoM::eUnitAbility>(
                                         m_game, &data->m_Parameters[1],
                                         MoM::UNITABILITY_Fire_Immunity, MoM::UNITABILITY_Weapon_Immunity);
            itemParameters[2] = new BitmaskTableItem<uint16_t, MoM::eUnitAbility>(
                                         m_game, (uint16_t*)&data->m_Parameters[2],
                                         MoM::UNITABILITY_Armor_Piercing, MoM::eUnitAbility_MAX);
            break;
        case MoM::SPELLCATEGORY_Variable_damage:   // variable cost damage spells; max cost = base cost * 5. Otherwise identical to 0x04. The extra effect per extra mana spent is probably determined by the flags, it isn't coded here.
                                                // Life Drain, Fire Bolt, Ice Bolt, Lightning Bolt, Psionic Blast, Fireball
                                                //      base spell strength + (mana - cost)
            itemParameters[0] = new NumberTableItem<uint8_t>(m_game, &data->m_Parameters[0], 4, SHOWNUMBER_normal);
            itemParameters[1] = new BitmaskTableItem<uint8_t, MoM::eUnitAbility>(
                                         m_game, &data->m_Parameters[1],
                                         MoM::UNITABILITY_Fire_Immunity, MoM::UNITABILITY_Weapon_Immunity);
            itemParameters[2] = new BitmaskTableItem<uint16_t, MoM::eUnitAbility>(
                                         m_game, (uint16_t*)&data->m_Parameters[2],
                                         MoM::UNITABILITY_Armor_Piercing, MoM::eUnitAbility_MAX);
            break;
        case MoM::SPELLCATEGORY_Special:           // unusual spells. I haven't been able to determine how they're parsed, and there are a lot of them.
            break;
        case MoM::SPELLCATEGORY_Target_wizard:     // spells that target one wizard. 0x20 appears to be the effect (there are only four spells in this category: spell blast, cruel unminding, drain power, subversion).
            itemParameters[0] = new NumberTableItem<uint8_t>(m_game, &data->m_Parameters[0], 4, SHOWNUMBER_normal);
            break;
        case MoM::SPELLCATEGORY_Global_enchantment:// global enchantment. Byte 0x20 contains the code for the global enchantment, in the same order as for global enchantments in the save file, but starts at 0 (0x00 is eternal night, 0x17 is awareness).
            break;
        case MoM::SPELLCATEGORY_Battle:            // combat globals (affect all units). Mostly, it's twice the number of the enchantment (if you want, you can add +1, and apply spells to the other side), but the instants (Call Chaos, Death Spell, Holy Word, Mass Healing, Flame Strike) would appear to be special case coded. If byte 0x21 is set, it seems to just make the spell not work in most cases (cloning flame strike does not work). Enchantment codes are:
                                                //    00: true light
                                                //    02: darkness
                                                //    04: warp reality
                                                //    06: black prayer
                                                //    08: wrack
                                                //    0a: metal fires
                                                //    0c: prayer
                                                //    0e: high prayer
                                                //    10: terror
                                                //    12: call lightning
                                                //    14: counter magic (which is a different bit; probably says moddable/not moddable)
                                                //    16: mass invisibility
                                                //    18: entangle
                                                //    1a: mana leak
                                                //    1c: blur
            itemParameters[0] = new NumberTableItem<uint8_t>(m_game, &data->m_Parameters[0], 4, SHOWNUMBER_normal);
            itemParameters[1] = new BitmaskTableItem<uint8_t, MoM::eUnitAbility>(
                                         m_game, &data->m_Parameters[1],
                                         MoM::UNITABILITY_Fire_Immunity, MoM::UNITABILITY_Weapon_Immunity);
            itemParameters[2] = new BitmaskTableItem<uint16_t, MoM::eUnitAbility>(
                                         m_game, (uint16_t*)&data->m_Parameters[2],
                                         MoM::UNITABILITY_Armor_Piercing, MoM::eUnitAbility_MAX);
            break;
        case MoM::SPELLCATEGORY_Create_item:       // enchant item and create artifact.
            break;
        case MoM::SPELLCATEGORY_Destroy_unit:      // spells that destroy a unit. Byte 0x21 looks like it may be a normal immunity byte, as it's 0x22 for petrify, 0x20 for disintegrate, but there's missing information here.
            itemParameters[1] = new BitmaskTableItem<uint8_t, MoM::eUnitAbility>(
                                         m_game, &data->m_Parameters[1],
                                         MoM::UNITABILITY_Fire_Immunity, MoM::UNITABILITY_Weapon_Immunity);
            break;
        case MoM::SPELLCATEGORY_Resistable_Combat_enchantment:// hostile (resisted) combat enchantments. Bytes 0x20-0x21 are a mask for what effect is created:
        case MoM::SPELLCATEGORY_Unresistable_Combat_enchantment:   // hostile (un-resisted) combat enchantments. Otherwise as 0x0d
        case MoM::SPELLCATEGORY_Mundane_Combat_enchantment:        // hostile (resisted) combat enchantments that only work on mundane units.
            itemParameters[0] = new BitmaskTableItem<uint16_t, MoM::eCombatEnchantment>(
                        m_game, (uint16_t*)&data->m_Parameters[0],
                        (MoM::eCombatEnchantment)0, MoM::eCombatEnchantment_MAX);
            itemParameters[1] = new QMoMTableItemBase(m_game, QString());
            break;
        case MoM::SPELLCATEGORY_Dispel:            // dispel magic, dispel magic true. Max cost = base cost * 5.
        case MoM::SPELLCATEGORY_Disenchant:        // disenchant area, disenchant true. Max cost = base cost * 5.
        case MoM::SPELLCATEGORY_Disjunction:       // disjunction, disjunction true. Max cost = base cost * 5.
        case MoM::SPELLCATEGORY_Counter:           // counter magic. Max cost = base cost * 5. Functions otherwise like 0x0a, so it's likely that other area spells could be modded, though effects would likely be undefined.
        case MoM::SPELLCATEGORY_Banish:
        default:
            break;
        }

        for (int i = 0; i < 3; ++i)
        {
            if (0 != itemParameters[i])
            {
                ui->tableWidget->setItem(row, col++, itemParameters[i]);
            }
            else if (i < 2)
            {
                ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, (uint8_t*)&data->m_Parameters[i], 6, SHOWNUMBER_noZero));
            }
            else
            {
                ui->tableWidget->setItem(row, col++, new NumberTableItem<uint16_t>(m_game, (uint16_t*)&data->m_Parameters[i], 6, SHOWNUMBER_noZero));
            }
        }

        uint16_t* pUpkeep = 0;
        ui->tableWidget->setItem(row, col, new QMoMTableItemBase(m_game));
        if (0 != upkeepEnchantments)
        {
            switch (spell)
            {
            // Unit_Enchantments
            case MoM::SPELL_Guardian_Wind: pUpkeep = &upkeepEnchantments->Guardian_Wind; break;
            case MoM::SPELL_Berserk: pUpkeep = &upkeepEnchantments->Berserk; break;
            case MoM::SPELL_Cloak_of_Fear: pUpkeep = &upkeepEnchantments->Cloak_of_Fear; break;
            case MoM::SPELL_Black_Channels: pUpkeep = &upkeepEnchantments->Black_Channels; break;
            case MoM::SPELL_Wraith_Form: pUpkeep = &upkeepEnchantments->Wraith_Form; break;
            case MoM::SPELL_Regeneration: pUpkeep = &upkeepEnchantments->Regeneration; break;
            case MoM::SPELL_Path_Finding: pUpkeep = &upkeepEnchantments->Path_Finding; break;
            case MoM::SPELL_Water_Walking: pUpkeep = &upkeepEnchantments->Water_Walking; break;
            case MoM::SPELL_Resist_Elements: pUpkeep = &upkeepEnchantments->Resist_Elements; break;
            case MoM::SPELL_Elemental_Armor: pUpkeep = &upkeepEnchantments->Elemental_Armor; break;
            case MoM::SPELL_Stone_Skin: pUpkeep = &upkeepEnchantments->Stone_Skin; break;
            case MoM::SPELL_Iron_Skin: pUpkeep = &upkeepEnchantments->Iron_Skin; break;
            case MoM::SPELL_Endurance: pUpkeep = &upkeepEnchantments->Endurance; break;
            case MoM::SPELL_Spell_Lock: pUpkeep = &upkeepEnchantments->Spell_Lock; break;
            case MoM::SPELL_Invisibility: pUpkeep = &upkeepEnchantments->Invisibility; break;
            case MoM::SPELL_Wind_Walking: pUpkeep = &upkeepEnchantments->Wind_Walking; break;
            case MoM::SPELL_Flight: pUpkeep = &upkeepEnchantments->Flight; break;
            case MoM::SPELL_Resist_Magic: pUpkeep = &upkeepEnchantments->Resist_Magic; break;
            case MoM::SPELL_Magic_Immunity: pUpkeep = &upkeepEnchantments->Magic_Immunity; break;
            case MoM::SPELL_Flame_Blade: pUpkeep = &upkeepEnchantments->Flame_Blade; break;
            case MoM::SPELL_Eldritch_Weapon: pUpkeep = &upkeepEnchantments->Eldritch_Weapon; break;
            case MoM::SPELL_True_Sight: pUpkeep = &upkeepEnchantments->True_Sight; break;
            case MoM::SPELL_Holy_Weapon: pUpkeep = &upkeepEnchantments->Holy_Weapon; break;
            case MoM::SPELL_Heroism: pUpkeep = &upkeepEnchantments->Heroism; break;
            case MoM::SPELL_Bless: pUpkeep = &upkeepEnchantments->Bless; break;
            case MoM::SPELL_Lionheart: pUpkeep = &upkeepEnchantments->Lionheart; break;
            case MoM::SPELL_Giant_Strength: pUpkeep = &upkeepEnchantments->Giant_Strength; break;
            case MoM::SPELL_Planar_Travel: pUpkeep = &upkeepEnchantments->Planar_Travel; break;
            case MoM::SPELL_Holy_Armor: pUpkeep = &upkeepEnchantments->Holy_Armor; break;
            case MoM::SPELL_Righteousness: pUpkeep = &upkeepEnchantments->Righteousness; break;
            case MoM::SPELL_Invulnerability: pUpkeep = &upkeepEnchantments->Invulnerability; break;

            // City Enchantments
            case MoM::SPELL_Wall_of_Fire: pUpkeep = &upkeepEnchantments->Wall_of_Fire; break;
            case MoM::SPELL_Chaos_Rift: pUpkeep = &upkeepEnchantments->Chaos_Rift; break;
            case MoM::SPELL_Dark_Rituals: pUpkeep = &upkeepEnchantments->Dark_Rituals; break;
            case MoM::SPELL_Evil_Presence: pUpkeep = &upkeepEnchantments->Evil_Presence; break;
            case MoM::SPELL_Cursed_Lands: pUpkeep = &upkeepEnchantments->Cursed_Lands; break;
            case MoM::SPELL_Pestilence: pUpkeep = &upkeepEnchantments->Pestilence; break;
            case MoM::SPELL_Cloud_Of_Shadow: pUpkeep = &upkeepEnchantments->Cloud_of_Shadow; break;
            case MoM::SPELL_Famine: pUpkeep = &upkeepEnchantments->Famine; break;
            case MoM::SPELL_Flying_Fortress: pUpkeep = &upkeepEnchantments->Flying_Fortress; break;
            // TODO: SPELL_Spell_Ward
//            case MoM::SPELL_Nature_Ward: upkeep = upkeepEnchantments->Nature_Ward; break;
//            case MoM::SPELL_Sorcery_Ward: upkeep = upkeepEnchantments->Sorcery_Ward; break;
//            case MoM::SPELL_Chaos_Ward: upkeep = upkeepEnchantments->Chaos_Ward; break;
//            case MoM::SPELL_Life_Ward: upkeep = upkeepEnchantments->Life_Ward; break;
//            case MoM::SPELL_Death_Ward: upkeep = upkeepEnchantments->Death_Ward; break;
            case MoM::SPELL_Natures_Eye: pUpkeep = &upkeepEnchantments->Natures_Eye; break;
            case MoM::SPELL_Earth_Gate: pUpkeep = &upkeepEnchantments->Earth_Gate; break;
            case MoM::SPELL_Stream_of_Life: pUpkeep = &upkeepEnchantments->Stream_of_Life; break;
            case MoM::SPELL_Gaias_Blessing: pUpkeep = &upkeepEnchantments->Gaias_Blessing; break;
            case MoM::SPELL_Inspirations: pUpkeep = &upkeepEnchantments->Inspirations; break;
            case MoM::SPELL_Prosperity: pUpkeep = &upkeepEnchantments->Prosperity; break;
            case MoM::SPELL_Astral_Gate: pUpkeep = &upkeepEnchantments->Astral_Gate; break;
            case MoM::SPELL_Heavenly_Light: pUpkeep = &upkeepEnchantments->Heavenly_Light; break;
            case MoM::SPELL_Consecration: pUpkeep = &upkeepEnchantments->Consecration; break;
            case MoM::SPELL_Wall_of_Darkness: pUpkeep = &upkeepEnchantments->Wall_of_Darkness; break;
            case MoM::SPELL_Altar_of_Battle: pUpkeep = &upkeepEnchantments->Altar_of_Battle; break;
            // TODO: ?
//            case MoM::SPELL_Nightshade: upkeep = upkeepEnchantments->Nightshade; break;

            // Global Enchantments
            case MoM::SPELL_Eternal_Night: pUpkeep = &upkeepEnchantments->Eternal_Night; break;
            case MoM::SPELL_Evil_Omens: pUpkeep = &upkeepEnchantments->Evil_Omens; break;
            case MoM::SPELL_Zombie_Mastery: pUpkeep = &upkeepEnchantments->Zombie_Mastery; break;
            case MoM::SPELL_Aura_of_Majesty: pUpkeep = &upkeepEnchantments->Aura_of_Majesty; break;
            case MoM::SPELL_Wind_Mastery: pUpkeep = &upkeepEnchantments->Wind_Mastery; break;
            case MoM::SPELL_Suppress_Magic: pUpkeep = &upkeepEnchantments->Suppress_Magic; break;
            case MoM::SPELL_Time_Stop: pUpkeep = &upkeepEnchantments->Time_Stop; break;
            case MoM::SPELL_Nature_Awareness: pUpkeep = &upkeepEnchantments->Nature_Awareness; break;
            case MoM::SPELL_Natures_Wrath: pUpkeep = &upkeepEnchantments->Natures_Wrath; break;
            case MoM::SPELL_Herb_Mastery: pUpkeep = &upkeepEnchantments->Herb_Mastery; break;
            case MoM::SPELL_Chaos_Surge: pUpkeep = &upkeepEnchantments->Chaos_Surge; break;
            case MoM::SPELL_Doom_Mastery: pUpkeep = &upkeepEnchantments->Doom_Mastery; break;
            case MoM::SPELL_Great_Wasting: pUpkeep = &upkeepEnchantments->Great_Wasting; break;
            case MoM::SPELL_Meteor_Storm: pUpkeep = &upkeepEnchantments->Meteor_Storm; break;
            case MoM::SPELL_Armageddon: pUpkeep = &upkeepEnchantments->Armageddon; break;
            case MoM::SPELL_Tranquility: pUpkeep = &upkeepEnchantments->Tranquility; break;
            case MoM::SPELL_Life_Force: pUpkeep = &upkeepEnchantments->Life_Force; break;
            case MoM::SPELL_Crusade: pUpkeep = &upkeepEnchantments->Crusade; break;
            case MoM::SPELL_Just_Cause: pUpkeep = &upkeepEnchantments->Just_Cause; break;
            case MoM::SPELL_Holy_Arms: pUpkeep = &upkeepEnchantments->Holy_Arms; break;
            case MoM::SPELL_Planar_Seal: pUpkeep = &upkeepEnchantments->Planar_Seal; break;
            case MoM::SPELL_Charm_of_Life: pUpkeep = &upkeepEnchantments->Charm_of_Life; break;
            case MoM::SPELL_Detect_Magic: pUpkeep = &upkeepEnchantments->Detect_Magic; break;
            case MoM::SPELL_Awareness: pUpkeep = &upkeepEnchantments->Awareness; break;
            default: break;
            }

            if (0 != pUpkeep)
            {
                ui->tableWidget->setItem(row, col, new NumberTableItem<uint16_t>(m_game, pUpkeep, 5));
            }
        }
        col++;

        // Spell save
        ui->tableWidget->setItem(row, col++, new QMoMTableItemBase(m_game));
    }

    if ((0 != wizardsExe) && (0 != ovl112))
    {
        int col = ui->tableWidget->columnCount() - 1;

        for (size_t i = 0; i < wizardsExe->getNrSpellSaves(); ++i)
        {
            int saveSpellNr = (int)ovl112[ wizardsExe->getSpellSave(i).spellOffset ];
            int8_t *pSaveModifier = 0;
            if (0 != wizardsExe->getSpellSave(i).saveOffset)
            {
                pSaveModifier = (int8_t*)&ovl112[ wizardsExe->getSpellSave(i).saveOffset ];
            }
            int rowSpell = saveSpellNr - 1;
            if ((rowSpell >= 0) && (rowSpell < ndata) && (0 != pSaveModifier))
            {
                ui->tableWidget->setItem(rowSpell, col, new NumberTableItem<int8_t>(m_game, pSaveModifier, 4, SHOWNUMBER_alwaysPlus));
            }
        }
    }

    finalizeTable();
}

void DialogTables::update_Unit_Types()
{
    int ndata = 0;

    if ((0 != m_game) && (0 != m_game->getUnitTypeData((MoM::eUnit_Type)0)))
	{
		ndata = MoM::eUnit_Type_MAX;
	}

    QStringList labels;
    labels << "Nr" << "Race" << "UnitName"
            << "Fig" << "Me" << "Ra" << "Df" << "Re" << "Hp" << "Th" << "Move"
            << "RangedType" << "Shots" << "Gaze/Poison"
            << "Cost" << "Upkeep" << "Parm1" << "Parm2"
            << "Movement" << "Immunities" << "Attributes" << "Abilities" << "Attacks"
            << "TypeCode" << "Scout" << "Transport" << "Construction";

    initializeTable(labels, ndata);

    for (int row = 0; (0 != m_game) && (row < ndata); ++row)
    {
        int unitTypeNr = row;
        MoM::Unit_Type_Data* data = m_game->getUnitTypeData((MoM::eUnit_Type)unitTypeNr);
		if (0 == data)
			break;

        QColor color = getRaceColor(data->m_Race_Code);

        int col = 0;
        ui->tableWidget->setItem(row, col++, new QMoMTableItemBase(m_game, QString("%0").arg(unitTypeNr, 3)));

        ui->tableWidget->setItem(row, col, new EnumTableItem<MoM::eRace>(m_game, &data->m_Race_Code, MoM::eRace_MAX));
        ui->tableWidget->item(row, col++)->setTextColor(color);

        ui->tableWidget->setItem(row, col, new QMoMTableItemBase(m_game, m_game->getNameByOffset(data->m_PtrName)));
        ui->tableWidget->item(row, col++)->setTextColor(color);

        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, &data->m_Nr_Figures, 3));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, &data->m_Melee, 3, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, &data->m_Ranged, 3, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, &data->m_Defense, 3));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, &data->m_Resistance, 3));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, &data->m_Hitpoints, 3));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int8_t>(m_game, &data->m_To_Hit, 2, SHOWNUMBER_plusAndNoZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, &data->m_MoveHalves, 5, SHOWNUMBER_halfMove));
        ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eRanged_Type>(m_game, &data->m_Ranged_Type, MoM::eRanged_Type_MAX, SHOWENUM_minusOne));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, &data->m_Ranged_Shots, 3, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<int8_t>(m_game, &data->m_Gaze_Modifier, 3, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint16_t>(m_game, &data->m_Cost, 5));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, &data->m_Upkeep, 3));

        if (unitTypeNr < (int)MoM::gMAX_HERO_TYPES)
        {
            ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, &data->m_Building1Required_or_PortraitLbxIndex, 4));
            ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eHero_TypeCode>(m_game, (MoM::eHero_TypeCode*)&data->m_Building2_or_HeroType, MoM::eHero_TypeCode_MAX));
        }
        else if (unitTypeNr < MoM::UNITTYPE_Arcane_Magic_Spirit)
        {
            ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eBuilding8>(m_game, (MoM::eBuilding8*)&data->m_Building1Required_or_PortraitLbxIndex, MoM::eBuilding8_array_MAX, SHOWENUM_noZero));
            ui->tableWidget->setItem(row, col++, new EnumTableItem<MoM::eBuilding8>(m_game, (MoM::eBuilding8*)&data->m_Building2_or_HeroType, MoM::eBuilding8_array_MAX, SHOWENUM_noZero));
        }
        else
        {
            ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, &data->m_Building1Required_or_PortraitLbxIndex, 4, SHOWNUMBER_noZero));
            ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, (uint8_t*)&data->m_Building2_or_HeroType, 4, SHOWNUMBER_noZero));
        }

        ui->tableWidget->setItem(row, col++, new BitmaskTableItem<uint8_t, MoM::eUnitAbility>(
                                  m_game, &data->m_Movement_Flags.bits,
                                  MoM::UNITABILITY_Cavalry, MoM::succ(MoM::UNITABILITY_Merging)));

        ui->tableWidget->setItem(row, col++, new BitmaskTableItem<uint8_t, MoM::eUnitAbility>(
                                  m_game, &data->m_Immunity_Flags.bits,
                                  MoM::UNITABILITY_Fire_Immunity, MoM::UNITABILITY_Weapon_Immunity));

        ui->tableWidget->setItem(row, col++, new BitmaskTableItem<uint16_t, MoM::eUnitAbility>(
                                  m_game, &data->m_Attribute_Flags.bits,
                                  MoM::UNITABILITY_Weapon_Immunity, MoM::succ(MoM::UNITABILITY_Holy_Bonus)));

        ui->tableWidget->setItem(row, col++, new BitmaskTableItem<uint16_t, MoM::eUnitAbility>(
                                  m_game, &data->m_Ability_Flags.bits,
                                  MoM::UNITABILITY_Summoned_Unit, MoM::UNITABILITY_Armor_Piercing));

        ui->tableWidget->setItem(row, col++, new BitmaskTableItem<uint16_t, MoM::eUnitAbility>(
                                  m_game, &data->m_Attack_Flags.bits,
                                  MoM::UNITABILITY_Armor_Piercing, MoM::eUnitAbility_MAX));

        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint16_t>(m_game, &data->m_Unit_picture, 3));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, &data->m_Scouting, 3));

        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, &data->m_Transport_Capacity, 3, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableItem<uint8_t>(m_game, &data->m_Construction, 3, SHOWNUMBER_noZero));
    }

    finalizeTable();
}

void DialogTables::update_Unrest_Table()
{
    int8_t* unrestTable = 0;
    int ndata = 0;

    if (!m_game.isNull())
    {
        unrestTable = m_game->getUnrest_Table(MoM::RACE_Barbarian);
    }
    if (0 != unrestTable)
    {
        ndata = (int)MoM::gMAX_RACES;
    }

    QStringList labels;
    labels << "Nr" << "HomeRace";
    for (MoM::eRace race = (MoM::eRace)0; MoM::toUInt(race) < MoM::gMAX_RACES; MoM::inc(race))
    {
        labels << prettyQStr(race);
    }

    initializeTable(labels, ndata);

    for (int row = 0; row < ndata; ++row)
    {
        int raceNr = row;
        MoM::eRace homeRace = (MoM::eRace)raceNr;
        int8_t* data = m_game->getUnrest_Table(homeRace);

        int col = 0;
        ui->tableWidget->setItem(row, col++, new QMoMTableItemBase(m_game, QString("%0").arg(raceNr, 2)));
        ui->tableWidget->setItem(row, col, new QMoMTableItemBase(m_game, prettyQStr(homeRace)));
        ui->tableWidget->item(row, col++)->setToolTip(m_game->getHelpText(homeRace).c_str());

        for (col = 2; col < labels.size(); ++col)
        {
            MoM::eRace cityRace = (MoM::eRace)(col - 2);
            ui->tableWidget->setItem(row, col, new NumberTableItem<int8_t>(m_game, &data[cityRace], 3, SHOWNUMBER_plusAndNoZero));
        }
    }

    finalizeTable();
}

void DialogTables::on_comboBox_Table_currentIndexChanged(QString newIndex)
{
    setWindowTitle(newIndex);

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);

    if ("Building Data" == newIndex)
    {
        update_Building_Data();
    }
    else if ("Item Data" == newIndex)
    {
        update_Item_Data();
    }
    else if ("Item Powers" == newIndex)
    {
        update_Item_Powers();
    }
    else if ("Items in game" == newIndex)
    {
        update_Items_in_game();
    }
    else if ("Race Data" == newIndex)
    {
        update_Race_Data();
    }
    else if ("Spell Data" == newIndex)
    {
        update_Spell_Data();
    }
    else if ("Unit Types" == newIndex)
    {
        update_Unit_Types();
    }
    else if ("Unrest Table" == newIndex)
    {
        update_Unrest_Table();
    }
    else
    {
        // Nothing to show
    }
}

void DialogTables::on_tableWidget_clicked(QModelIndex)
{
    ui->tableWidget->resizeRowsToContents();
}

void DialogTables::on_tableWidget_customContextMenuRequested(const QPoint &pos)
{
    qDebug() << "on_tableWidget_customContextMenuRequested" << pos;
    QTableWidgetItem* pItem = ui->tableWidget->currentItem();

    QMenu contextMenu;
    contextMenu.addAction("Copy", this, SLOT(slot_Copy()), QKeySequence("Ctrl+C"));

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
}

void DialogTables::slot_Copy()
{
    QByteArray byteArray;

    int leftColumn = ui->tableWidget->columnCount();
    int rightColumn = 0;
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
    {
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col)
        {
            QTableWidgetItem* item = ui->tableWidget->item(row, col);
            if (item->isSelected())
            {
                leftColumn = std::min(col, leftColumn);
                rightColumn = std::max(col, rightColumn);
            }
        }
    }

    for (int col = leftColumn; col <= rightColumn; ++col)
    {
        byteArray.append(ui->tableWidget->horizontalHeaderItem(col)->text());
        byteArray.append("\t");
    }
    byteArray.append("\r\n");

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
    {
        bool selectedItems = false;
        for (int col = leftColumn; col <= rightColumn; ++col)
        {
            QTableWidgetItem* item = ui->tableWidget->item(row, col);
            if (item->isSelected())
            {
                byteArray.append(item->text());
                byteArray.append("\t");
                selectedItems = true;
           }
        }
        if (selectedItems)
        {
            byteArray.append("\r\n");
        }
    }

    QMimeData * mimeData = new QMimeData();
    mimeData->setData("text/plain", byteArray);
    QApplication::clipboard()->setMimeData(mimeData);
}

void DialogTables::slot_ItemAction()
{
    QTableWidgetItem* pItem = ui->tableWidget->currentItem();
    QMoMTableItemBase* pMoMItem = dynamic_cast<QMoMTableItemBase*>(pItem);
    if (0 != pMoMItem)
    {
        pMoMItem->slotAction();
    }
}

void DialogTables::slot_gameChanged(const QMoMGamePtr &game)
{
    m_game = game;

    slot_gameUpdated();
}

void DialogTables::slot_gameUpdated()
{
}
