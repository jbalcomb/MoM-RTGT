// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include <QClipboard>
#include <QKeyEvent>

#include "dialogtables.h"
#include "ui_dialogtables.h"

#include "MoMutility.h"
#include "MoMGenerated.h"
#include "MoMExeWizards.h"
#include "mainwindow.h"

DialogTables::DialogTables(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTables)
{
    ui->setupUi(this);

    ui->comboBox_Table->setCurrentIndex(2);
}

DialogTables::~DialogTables()
{
    delete ui;
}


MoM::MoMGameBase* DialogTables::getGame()
{
    MainWindow* controller = MainWindow::getInstance();
    if (0 == controller)
        return 0;
    MoM::MoMGameBase* game = controller->getGame();
    return game;
}

void DialogTables::keyPressEvent(QKeyEvent* event)
{
    //if there is a control-C event copy data to the global clipboard
    if ((event->key() == Qt::Key_C) && (event->modifiers() & Qt::ControlModifier))
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
    else
    {
        QDialog::keyPressEvent(event);
    }
}

void DialogTables::update_Spell_Data()
{
    MoM::MoMGameBase* game = getGame();
    MoM::Spell_Data* spellData = 0;
    MoM::Upkeep_Enchantments* upkeepEnchantments = 0;
    MoM::MoMExeWizards* wizardsExe = 0;
    uint8_t* ovl112 = 0;
    int ndata = 0;

    if (0 != game)
    {
        spellData = game->getSpell_Data();
        if (0 != game->getDataSegment())
        {
            upkeepEnchantments = &game->getDataSegment()->m_Upkeep_Enchantments;
        }
        wizardsExe = game->getWizardsExe();
        ovl112 = game->getWizardsOverlay(112);
    }
    if (0 != spellData)
    {
        ndata = (int)MoM::eSpell_MAX - 1;
    }

    QStringList labels;
    labels << "Nr";
    labels << "SpellName" << "Desirability" << "Category" << "Section" << "Realm" << "Elegibility"
            << "Casting" << "Research" << "Parameter" << "Immunities" << "Attack Flags";
    labels<< "Upkeep";
    labels<< "Save";

    ui->tableWidget->setColumnCount(labels.size());
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    ui->tableWidget->setRowCount(ndata);

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
    {
        ui->tableWidget->setVerticalHeaderItem(row, new QTableWidgetItem(""));
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col)
        {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(""));
            ui->tableWidget->item(row, col)->setTextAlignment(Qt::AlignCenter);
        }
    }

    for (int row = 0; row < ndata; ++row)
    {
        int spellNr = row + 1;
        MoM::eSpell spell = (MoM::eSpell)spellNr;
        MoM::Spell_Data* data = &spellData[spellNr];

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
        ui->tableWidget->item(row, col++)->setText(QString("%0").arg(spellNr, 3));

        ui->tableWidget->item(row, col)->setTextColor(color);
        ui->tableWidget->item(row, col++)->setText(QString(data->m_SpellName));

        ui->tableWidget->item(row, col++)->setText(QString("%0").arg((int)data->m_Spell_desirability, 6));
        ui->tableWidget->item(row, col++)->setText(QString("%0").arg((int)data->m_Spell_Category, 2));
        ui->tableWidget->item(row, col++)->setText(prettyQStr(data->m_Section_in_spell_book));
        ui->tableWidget->item(row, col++)->setText(prettyQStr(data->m_Magic_Realm));
        ui->tableWidget->item(row, col++)->setText(QString("%0").arg((int)data->m_Casting_eligibility, 4));
        ui->tableWidget->item(row, col++)->setText(QString("%0").arg(data->m_Casting_cost, 5));
        ui->tableWidget->item(row, col++)->setText(QString("%0").arg(data->m_Research_cost, 5));

        QString parameter;
        if ((MoM::SPELLTYPE_Summoning == data->m_Section_in_spell_book) && (0 != (int)data->m_Unit_Summoned_or_Spell_Strength))
        {
            parameter = prettyQStr((MoM::eUnit_Type)data->m_Unit_Summoned_or_Spell_Strength);
        }
        else
        {
            parameter = QString("%0").arg((int)data->m_Unit_Summoned_or_Spell_Strength, 6);
        }
        ui->tableWidget->item(row, col++)->setText(parameter);

        QString immunity = toQStr(data->m_Immunity_Flags.s);
        immunity.replace("\n", " ").replace("=1",", ").replace("_"," ").replace("{ ","").replace(",  }","").replace("}","").replace("Immunity", "Imm");
        ui->tableWidget->item(row, col++)->setText(immunity);

        QString attack = toQStr(data->m_Attack_Flags.s);
        attack.replace("\n", " ").replace("=1",", ").replace("_"," ").replace("{ ","").replace(",  }","").replace("}","");
        ui->tableWidget->item(row, col++)->setText(attack);

        uint16_t upkeep = 0;
        if (0 != upkeepEnchantments)
        {
            switch (spell)
            {
            // Unit_Enchantments
            case MoM::SPELL_Guardian_Wind: upkeep = upkeepEnchantments->Guardian_Wind; break;
            case MoM::SPELL_Berserk: upkeep = upkeepEnchantments->Berserk; break;
            case MoM::SPELL_Cloak_of_Fear: upkeep = upkeepEnchantments->Cloak_of_Fear; break;
            case MoM::SPELL_Black_Channels: upkeep = upkeepEnchantments->Black_Channels; break;
            case MoM::SPELL_Wraith_Form: upkeep = upkeepEnchantments->Wraith_Form; break;
            case MoM::SPELL_Regeneration: upkeep = upkeepEnchantments->Regeneration; break;
            case MoM::SPELL_Path_Finding: upkeep = upkeepEnchantments->Path_Finding; break;
            case MoM::SPELL_Water_Walking: upkeep = upkeepEnchantments->Water_Walking; break;
            case MoM::SPELL_Resist_Elements: upkeep = upkeepEnchantments->Resist_Elements; break;
            case MoM::SPELL_Elemental_Armor: upkeep = upkeepEnchantments->Elemental_Armor; break;
            case MoM::SPELL_Stone_Skin: upkeep = upkeepEnchantments->Stone_Skin; break;
            case MoM::SPELL_Iron_Skin: upkeep = upkeepEnchantments->Iron_Skin; break;
            case MoM::SPELL_Endurance: upkeep = upkeepEnchantments->Endurance; break;
            case MoM::SPELL_Spell_Lock: upkeep = upkeepEnchantments->Spell_Lock; break;
            case MoM::SPELL_Invisibility: upkeep = upkeepEnchantments->Invisibility; break;
            case MoM::SPELL_Wind_Walking: upkeep = upkeepEnchantments->Wind_Walking; break;
            case MoM::SPELL_Flight: upkeep = upkeepEnchantments->Flight; break;
            case MoM::SPELL_Resist_Magic: upkeep = upkeepEnchantments->Resist_Magic; break;
            case MoM::SPELL_Magic_Immunity: upkeep = upkeepEnchantments->Magic_Immunity; break;
            case MoM::SPELL_Flame_Blade: upkeep = upkeepEnchantments->Flame_Blade; break;
            case MoM::SPELL_Eldritch_Weapon: upkeep = upkeepEnchantments->Eldritch_Weapon; break;
            case MoM::SPELL_True_Sight: upkeep = upkeepEnchantments->True_Sight; break;
            case MoM::SPELL_Holy_Weapon: upkeep = upkeepEnchantments->Holy_Weapon; break;
            case MoM::SPELL_Heroism: upkeep = upkeepEnchantments->Heroism; break;
            case MoM::SPELL_Bless: upkeep = upkeepEnchantments->Bless; break;
            case MoM::SPELL_Lionheart: upkeep = upkeepEnchantments->Lionheart; break;
            case MoM::SPELL_Giant_Strength: upkeep = upkeepEnchantments->Giant_Strength; break;
            case MoM::SPELL_Planar_Travel: upkeep = upkeepEnchantments->Planar_Travel; break;
            case MoM::SPELL_Holy_Armor: upkeep = upkeepEnchantments->Holy_Armor; break;
            case MoM::SPELL_Righteousness: upkeep = upkeepEnchantments->Righteousness; break;
            case MoM::SPELL_Invulnerability: upkeep = upkeepEnchantments->Invulnerability; break;

            // City Enchantments
            case MoM::SPELL_Wall_of_Fire: upkeep = upkeepEnchantments->Wall_of_Fire; break;
            case MoM::SPELL_Chaos_Rift: upkeep = upkeepEnchantments->Chaos_Rift; break;
            case MoM::SPELL_Dark_Rituals: upkeep = upkeepEnchantments->Dark_Rituals; break;
            case MoM::SPELL_Evil_Presence: upkeep = upkeepEnchantments->Evil_Presence; break;
            case MoM::SPELL_Cursed_Lands: upkeep = upkeepEnchantments->Cursed_Lands; break;
            case MoM::SPELL_Pestilence: upkeep = upkeepEnchantments->Pestilence; break;
            case MoM::SPELL_Cloud_Of_Shadow: upkeep = upkeepEnchantments->Cloud_of_Shadow; break;
            case MoM::SPELL_Famine: upkeep = upkeepEnchantments->Famine; break;
            case MoM::SPELL_Flying_Fortress: upkeep = upkeepEnchantments->Flying_Fortress; break;
            // TODO: SPELL_Spell_Ward
//            case MoM::SPELL_Nature_Ward: upkeep = upkeepEnchantments->Nature_Ward; break;
//            case MoM::SPELL_Sorcery_Ward: upkeep = upkeepEnchantments->Sorcery_Ward; break;
//            case MoM::SPELL_Chaos_Ward: upkeep = upkeepEnchantments->Chaos_Ward; break;
//            case MoM::SPELL_Life_Ward: upkeep = upkeepEnchantments->Life_Ward; break;
//            case MoM::SPELL_Death_Ward: upkeep = upkeepEnchantments->Death_Ward; break;
            case MoM::SPELL_Natures_Eye: upkeep = upkeepEnchantments->Natures_Eye; break;
            case MoM::SPELL_Earth_Gate: upkeep = upkeepEnchantments->Earth_Gate; break;
            case MoM::SPELL_Stream_of_Life: upkeep = upkeepEnchantments->Stream_of_Life; break;
            case MoM::SPELL_Gaias_Blessing: upkeep = upkeepEnchantments->Gaias_Blessing; break;
            case MoM::SPELL_Inspirations: upkeep = upkeepEnchantments->Inspirations; break;
            case MoM::SPELL_Prosperity: upkeep = upkeepEnchantments->Prosperity; break;
            case MoM::SPELL_Astral_Gate: upkeep = upkeepEnchantments->Astral_Gate; break;
            case MoM::SPELL_Heavenly_Light: upkeep = upkeepEnchantments->Heavenly_Light; break;
            case MoM::SPELL_Consecration: upkeep = upkeepEnchantments->Consecration; break;
            case MoM::SPELL_Wall_of_Darkness: upkeep = upkeepEnchantments->Wall_of_Darkness; break;
            case MoM::SPELL_Altar_of_Battle: upkeep = upkeepEnchantments->Altar_of_Battle; break;
            // TODO: ?
//            case MoM::SPELL_Nightshade: upkeep = upkeepEnchantments->Nightshade; break;

            // Global Enchantments
            case MoM::SPELL_Eternal_Night: upkeep = upkeepEnchantments->Eternal_Night; break;
            case MoM::SPELL_Evil_Omens: upkeep = upkeepEnchantments->Evil_Omens; break;
            case MoM::SPELL_Zombie_Mastery: upkeep = upkeepEnchantments->Zombie_Mastery; break;
            case MoM::SPELL_Aura_of_Majesty: upkeep = upkeepEnchantments->Aura_of_Majesty; break;
            case MoM::SPELL_Wind_Mastery: upkeep = upkeepEnchantments->Wind_Mastery; break;
            case MoM::SPELL_Suppress_Magic: upkeep = upkeepEnchantments->Suppress_Magic; break;
            case MoM::SPELL_Time_Stop: upkeep = upkeepEnchantments->Time_Stop; break;
            case MoM::SPELL_Nature_Awareness: upkeep = upkeepEnchantments->Nature_Awareness; break;
            case MoM::SPELL_Natures_Wrath: upkeep = upkeepEnchantments->Natures_Wrath; break;
            case MoM::SPELL_Herb_Mastery: upkeep = upkeepEnchantments->Herb_Mastery; break;
            case MoM::SPELL_Chaos_Surge: upkeep = upkeepEnchantments->Chaos_Surge; break;
            case MoM::SPELL_Doom_Mastery: upkeep = upkeepEnchantments->Doom_Mastery; break;
            case MoM::SPELL_Great_Wasting: upkeep = upkeepEnchantments->Great_Wasting; break;
            case MoM::SPELL_Meteor_Storm: upkeep = upkeepEnchantments->Meteor_Storm; break;
            case MoM::SPELL_Armageddon: upkeep = upkeepEnchantments->Armageddon; break;
            case MoM::SPELL_Tranquility: upkeep = upkeepEnchantments->Tranquility; break;
            case MoM::SPELL_Life_Force: upkeep = upkeepEnchantments->Life_Force; break;
            case MoM::SPELL_Crusade: upkeep = upkeepEnchantments->Crusade; break;
            case MoM::SPELL_Just_Cause: upkeep = upkeepEnchantments->Just_Cause; break;
            case MoM::SPELL_Holy_Arms: upkeep = upkeepEnchantments->Holy_Arms; break;
            case MoM::SPELL_Planar_Seal: upkeep = upkeepEnchantments->Planar_Seal; break;
            case MoM::SPELL_Charm_of_Life: upkeep = upkeepEnchantments->Charm_of_Life; break;
            case MoM::SPELL_Detect_Magic: upkeep = upkeepEnchantments->Detect_Magic; break;
            case MoM::SPELL_Awareness: upkeep = upkeepEnchantments->Awareness; break;
            default: break;
            }

            if (0 != upkeep)
            {
                ui->tableWidget->item(row, col)->setText(QString("%0").arg((uint)upkeep, 5));
            }
        }
        col++;
    }

    if ((0 != wizardsExe) && (0 != ovl112))
    {
        int col = ui->tableWidget->columnCount() - 1;

        for (size_t i = 0; i < wizardsExe->getNrSpellSaves(); ++i)
        {
            int saveSpellNr = (int)ovl112[ wizardsExe->getSpellSave(i).spellOffset ];
            int saveModifier = 0;
            if (0 != wizardsExe->getSpellSave(i).saveOffset)
            {
                saveModifier = (int8_t)ovl112[ wizardsExe->getSpellSave(i).saveOffset ];
            }
            int rowSpell = saveSpellNr - 1;
            if ((rowSpell >= 0) && (rowSpell < ndata))
            {
                char buf[16];
                sprintf(buf, "%+4d", saveModifier);
                ui->tableWidget->item(rowSpell, col)->setText(QString(buf));
            }
        }
    }

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->sortByColumn(0, Qt::AscendingOrder);
    ui->tableWidget->setSortingEnabled(true);
}

void DialogTables::update_Unit_Types()
{
    MoM::MoMGameBase* game = getGame();
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

    QStringList labels;
    labels << "Nr" << "Race" << "UnitName"
            << "Fig" << "Me" << "Ra" << "Df" << "Re" << "Hp" << "Th" << "Move"
            << "RangedType" << "Shots" << "Gaze/Poison"
            << "Cost" << "Upkeep" << "Parm1" << "Parm2"
            << "Movement" << "Immunities" << "Attributes" << "Abilities" << "Attacks"
            << "UNK02" << "TypeCode" << "Scout" << "Transport" << "Construction";

    ui->tableWidget->setColumnCount(labels.size());
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    ui->tableWidget->setRowCount(ndata);

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
    {
        ui->tableWidget->setVerticalHeaderItem(row, new QTableWidgetItem(""));
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col)
        {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(""));
            ui->tableWidget->item(row, col)->setTextAlignment(Qt::AlignCenter);
        }
    }

    for (int row = 0; row < ndata; ++row)
    {
        int unitTypeNr = row;
        MoM::Unit_Type_Data* data = &unitTypes[unitTypeNr];

        QColor color = Qt::gray;
        switch (data->m_Race_Code)
        {
        case MoM::RACE_Nature:     color = Qt::darkGreen;   break;
        case MoM::RACE_Sorcery:    color = Qt::blue;        break;
        case MoM::RACE_Chaos:      color = Qt::darkRed;     break;
        case MoM::RACE_Life:       color = Qt::darkGray;    break;
        case MoM::RACE_Death:      color = Qt::black;       break;
        case MoM::RACE_Arcane:     color = Qt::darkYellow;  break;
        default:                   color = Qt::black;       break;
        }

        int col = 0;
        ui->tableWidget->item(row, col++)->setText(QString("%0").arg(unitTypeNr, 3));

        ui->tableWidget->item(row, col)->setTextColor(color);
        ui->tableWidget->item(row, col++)->setText(prettyQStr(data->m_Race_Code));

        ui->tableWidget->item(row, col)->setTextColor(color);
        ui->tableWidget->item(row, col++)->setText(QString(game->getNameByOffset(data->m_PtrName)));

        ui->tableWidget->item(row, col++)->setText(QString("%0").arg((int)data->m_Nr_Figures, 3));
        if (0 != data->m_Melee)
        {
            ui->tableWidget->item(row, col)->setText(QString("%0").arg((int)data->m_Melee, 3));
        }
        col++;
        if (0 != data->m_Ranged)
        {
            ui->tableWidget->item(row, col)->setText(QString("%0").arg((int)data->m_Ranged, 3));
        }
        col++;
        ui->tableWidget->item(row, col++)->setText(QString("%0").arg((int)data->m_Defense, 3));
        ui->tableWidget->item(row, col++)->setText(QString("%0").arg((int)data->m_Resistance, 3));
        ui->tableWidget->item(row, col++)->setText(QString("%0").arg((int)data->m_Hitpoints, 3));
        if (0 != data->m_To_Hit)
        {
            ui->tableWidget->item(row, col)->setText(QString("+%0").arg((int)data->m_To_Hit));
        }
        col++;
        ui->tableWidget->item(row, col++)->setText(QString("%0").arg((double)data->m_MoveHalves / 2, 5, 'f', 1));
        if (MoM::RANGED_None != data->m_Ranged_Type)
        {
            ui->tableWidget->item(row, col)->setText(prettyQStr(data->m_Ranged_Type));
        }
        col++;
        if (0 != data->m_Ranged_Shots)
        {
            ui->tableWidget->item(row, col)->setText(QString("%0").arg((int)data->m_Ranged_Shots, 3));
        }
        col++;
        if (0 != data->m_Gaze_Modifier)
        {
            char buf[16];
            if (data->m_Gaze_Modifier > 0)
            {
                sprintf(buf, "%3d", data->m_Gaze_Modifier);
            }
            else
            {
                sprintf(buf, "%d", data->m_Gaze_Modifier);
            }
            ui->tableWidget->item(row, col)->setText(QString(buf));
        }
        col++;
        ui->tableWidget->item(row, col++)->setText(QString("%0").arg((unsigned)data->m_Cost, 5));
        ui->tableWidget->item(row, col++)->setText(QString("%0").arg((unsigned)data->m_Upkeep, 3));

        QString parm1, parm2;
        if (unitTypeNr < (int)MoM::gMAX_HERO_TYPES)
        {
            parm1 = QString("%0").arg((unsigned)data->m_Building_Required1, 4);
            parm2 = prettyQStr((MoM::eHero_TypeCode)data->m_Hero_TypeCode_or_Building2);
        }
        else if (unitTypeNr < MoM::UNITTYPE_Arcane_Magic_Spirit)
        {
            parm1 = prettyQStr((MoM::eBuilding)data->m_Building_Required1);
            if (MoM::BUILDING_None != (MoM::eBuilding)data->m_Hero_TypeCode_or_Building2)
            {
                parm2 = prettyQStr((MoM::eBuilding)data->m_Hero_TypeCode_or_Building2);
            }
        }
        else
        {
            parm1 = QString("%0").arg((unsigned)data->m_Building_Required1, 4);
            if (0 != (unsigned)data->m_Hero_TypeCode_or_Building2)
            {
                parm2 = QString("%0").arg((unsigned)data->m_Hero_TypeCode_or_Building2, 4);
            }
        }
        ui->tableWidget->item(row, col++)->setText(parm1);
        ui->tableWidget->item(row, col++)->setText(parm2);

        QString movement = toQStr(data->m_Movement_Flags.s);
        movement.replace("\n", " ").replace("=1",", ").replace("_"," ").replace("{ ","").replace(",  }","").replace("}","");
        ui->tableWidget->item(row, col++)->setText(movement);

        QString immunity = toQStr(data->m_Immunity_Flags.s);
        immunity.replace("\n", " ").replace("=1",", ").replace("_"," ").replace("{ ","").replace(",  }","").replace("}","").replace("Immunity", "Imm");
        ui->tableWidget->item(row, col++)->setText(immunity);

        QString attribute = toQStr(data->m_Attribute_Flags.s);
        attribute.replace("\n", " ").replace("=1",", ").replace("_"," ").replace("{ ","").replace(",  }","").replace("}","");
        ui->tableWidget->item(row, col++)->setText(attribute);

        QString ability = toQStr(data->m_Ability_Flags.s);
        ability.replace("\n", " ").replace("=1",", ").replace("_"," ").replace("{ ","").replace(",  }","").replace("}","");
        ui->tableWidget->item(row, col++)->setText(ability);

        QString attack = toQStr(data->m_Attack_Flags.s);
        attack.replace("\n", " ").replace("=1",", ").replace("_"," ").replace("{ ","").replace(",  }","").replace("}","");
        ui->tableWidget->item(row, col++)->setText(attack);

        ui->tableWidget->item(row, col++)->setText(QString("0x%0").arg((uint)data->m_UNK02, 2, 16, (QChar)'0'));
        ui->tableWidget->item(row, col++)->setText(QString("%0").arg((unsigned)data->m_TypeCode, 3));
        ui->tableWidget->item(row, col++)->setText(QString("%0").arg((unsigned)data->m_Scouting_Range, 3));

        if (0 != data->m_Transport_Capacity)
        {
            ui->tableWidget->item(row, col++)->setText(QString("%0").arg((unsigned)data->m_Transport_Capacity, 3));
        }
        col++;
        if (0 != data->m_Construction_Capacity)
        {
            ui->tableWidget->item(row, col++)->setText(QString("%0").arg((unsigned)data->m_Construction_Capacity, 3));
        }
        col++;

    }

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->sortByColumn(0, Qt::AscendingOrder);
    ui->tableWidget->setSortingEnabled(true);
}

void DialogTables::update_Unrest_Table()
{
    MoM::MoMGameBase* game = getGame();
    int8_t* unrestTable = 0;
    int ndata = 0;

    if (0 != game)
    {
        unrestTable = game->getUnrest_Table(MoM::RACE_Barbarian);
    }
    if (0 != unrestTable)
    {
        ndata = (int)MoM::gMAX_RACES;
    }

    QStringList labels;
    labels << "Nr" << "HomeRace";
    for (MoM::eRace race = (MoM::eRace)0; race < MoM::gMAX_RACES; MoM::inc(race))
    {
        labels << prettyQStr(race);
    }

    ui->tableWidget->setColumnCount(labels.size());
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    ui->tableWidget->setRowCount(ndata);

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
    {
        ui->tableWidget->setVerticalHeaderItem(row, new QTableWidgetItem(""));
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col)
        {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(""));
            ui->tableWidget->item(row, col)->setTextAlignment(Qt::AlignCenter);
        }
    }

    for (int row = 0; row < ndata; ++row)
    {
        int raceNr = row;
        MoM::eRace homeRace = (MoM::eRace)raceNr;
        int8_t* data = game->getUnrest_Table(homeRace);

        int col = 0;
        ui->tableWidget->item(row, col++)->setText(QString("%0").arg(raceNr, 2));
        ui->tableWidget->item(row, col++)->setText(prettyQStr(homeRace));

        for (col = 2; col < labels.size(); ++col)
        {
            MoM::eRace cityRace = (MoM::eRace)(col - 2);
            char buf[16];
            sprintf(buf, "%+d", data[cityRace]);
            ui->tableWidget->item(row, col)->setText(QString("%0").arg(buf, 3));
        }
    }

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->sortByColumn(0, Qt::AscendingOrder);
    ui->tableWidget->setSortingEnabled(true);
}

void DialogTables::on_tableWidget_clicked(QModelIndex /*index*/)
{
    ui->tableWidget->resizeRowsToContents();
}

void DialogTables::on_comboBox_Table_currentIndexChanged(QString newIndex)
{
    setWindowTitle(newIndex);

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);

    if ("Spell Data" == newIndex)
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
