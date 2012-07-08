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

enum eShowNumber
{
    SHOWNUMBER_normal,
    SHOWNUMBER_alwaysPlus,
    SHOWNUMBER_positivePlus,
    SHOWNUMBER_noZero,
    SHOWNUMBER_plusAndNoZero,
    SHOWNUMBER_halfMove
};

class QMoMTableWidgetItemBase : public QTableWidgetItem
{
public:
    QMoMTableWidgetItemBase(const QMoMGamePtr& game, const QString& text = "") :
        QTableWidgetItem(text),
        m_game(game)
    {
        // Not editable by default
        setFlags(flags() & ~Qt::ItemIsEditable);
        // Centered by default
        setTextAlignment(Qt::AlignCenter);
    }
    virtual QList<QAction*> requestActions(QObject* parent) 
    { 
        return QList<QAction*>(); 
    }
    virtual void slotAction()
    {
    }
    virtual QString toString() const
    {
        return QTableWidgetItem::text();
    }
protected:
    QMoMGamePtr m_game;
};

typedef QSharedPointer<QMoMTableWidgetItemBase> QMoMTableWidgetItemPtr;

///////////////////////////////////////////

template<typename Number>
class NumberTableWidgetItem : public QMoMTableWidgetItemBase
{
public:
    NumberTableWidgetItem(const QMoMGamePtr& game, Number& t, int width, eShowNumber showNumber = SHOWNUMBER_normal);
    virtual void setData(int role, const QVariant &value);
    virtual QString toString() const;
private:
    Number* m_ptr;
    int m_width;
    eShowNumber m_showNumber;
};


template<typename Number>
NumberTableWidgetItem<Number>::NumberTableWidgetItem(const QMoMGamePtr& game, Number& t, int width, eShowNumber showNumber) :
    QMoMTableWidgetItemBase(game),
    m_ptr(&t),
    m_width(width),
    m_showNumber(showNumber)
{
    setFlags(flags() | Qt::ItemIsEditable);
    QTableWidgetItem::setData(Qt::EditRole, toString());
}

template<typename Number>
void NumberTableWidgetItem<Number>::setData(int role, const QVariant &value)
{
    switch (role)
    {
    case Qt::EditRole:
        {
            Number newValue = static_cast<Number> (value.toInt());
            if (m_showNumber == SHOWNUMBER_halfMove)
            {
                newValue = static_cast<Number> (2 * value.toDouble());
            }
            (void)m_game->commitData(m_ptr, &newValue, sizeof(Number));
            QTableWidgetItem::setData(role, toString());
        }
        break;
    default:
        QTableWidgetItem::setData(role, value);
        break;
    }
}

template<typename Number>
QString NumberTableWidgetItem<Number>::toString() const
{
    QString result = QString("%0").arg(*m_ptr);
    switch (m_showNumber)
    {
    case SHOWNUMBER_normal:
        // Nothing further to do
        break;
    case SHOWNUMBER_alwaysPlus:
        if (*m_ptr >= 0)
        {
            result = "+" + result;
        }
        break;
    case SHOWNUMBER_positivePlus:
        if (*m_ptr > 0)
        {
            result = "+" + result;
        }
        break;
    case SHOWNUMBER_noZero:
        if (*m_ptr == 0)
        {
            result = "";
        }
        break;
    case SHOWNUMBER_plusAndNoZero:
        if (*m_ptr == 0) 
        {
            result = ""; 
        }
        else if (*m_ptr > 0)
        {
            result = "+" + result;
        }
        break;
    case SHOWNUMBER_halfMove:
        result = QString("%0").arg((double)*m_ptr / 2, m_width, 'f', 1);
        break;
    default:
        assert(0 && "Unknown value if eShowNumber");
    }

    result = QString("%0").arg(result, m_width);
    return result;
}

///////////////////////////////////////////

class TextTableWidgetItem : public QMoMTableWidgetItemBase
{
public:
    TextTableWidgetItem(const QMoMGamePtr& game, char* text, size_t size);
    virtual void setData(int role, const QVariant &value);
    virtual QString toString() const;
private:
    char* m_ptr;
    size_t m_size;
};


TextTableWidgetItem::TextTableWidgetItem(const QMoMGamePtr& game, char* text, size_t size) :
    QMoMTableWidgetItemBase(game),
    m_ptr(text),
    m_size(size)
{
    setFlags(flags() | Qt::ItemIsEditable);
    QTableWidgetItem::setData(Qt::EditRole, toString());
}

void TextTableWidgetItem::setData(int role, const QVariant &value)
{
    switch (role)
    {
    case Qt::EditRole:
        {
            std::string newValue(m_size, '\0');
            strncpy(&newValue[0], value.toByteArray().data(), m_size - 1);
            (void)m_game->commitData(m_ptr, newValue.data(), m_size);
            QTableWidgetItem::setData(role, toString());
        }
        break;
    default:
        QTableWidgetItem::setData(role, value);
        break;
    }
}

QString TextTableWidgetItem::toString() const
{
    std::string str(m_ptr, m_size);
    return QString(str.c_str());
}

/////////////////////////////////////////

template<typename Enum>
class EnumTableWidgetItem : public QMoMTableWidgetItemBase
{
public:
    EnumTableWidgetItem(const QMoMGamePtr& game, Enum& e, Enum max, bool showMinusOneEmpty = false);

    virtual void setData(int role, const QVariant &value);

    virtual QList<QAction*> requestActions(QObject* parent);

    virtual void slotAction();

    virtual QString toString() const;

private:
    void addAction(Enum e);

    // Configuration
    Enum* m_ptr;
    Enum m_max;
    bool m_showMinusOneEmpty;

    // Status

    // Keep track of the action group
    // m_actionGroup is deleted by its parent (the context menu)
    QActionGroup* m_actionGroup;
};

template<typename Enum>
EnumTableWidgetItem<Enum>::EnumTableWidgetItem(const QMoMGamePtr& game, Enum& e, Enum max, bool showMinusOneEmpty) :
    QMoMTableWidgetItemBase(game),
    m_ptr(&e),
    m_max(max),
    m_showMinusOneEmpty(showMinusOneEmpty),
    m_actionGroup()
{
    QTableWidgetItem::setData(Qt::EditRole, toString());
}

template<typename Enum>
void EnumTableWidgetItem<Enum>::setData(int role, const QVariant &value)
{
    switch (role)
    {
    case Qt::EditRole:
        {
            Enum newValue = static_cast<Enum> (value.toInt());
            (void)m_game->commitData(m_ptr, &newValue, sizeof(Enum));
            QTableWidgetItem::setData(role, toString());
        }
        break;
    default:
        QTableWidgetItem::setData(role, value);
        break;
    }
}

template<typename Enum>
void EnumTableWidgetItem<Enum>::addAction(Enum e)
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
        action->setCheckable(true);
        action->setData(QVariant((int)e));
        if (e == *m_ptr)
        {
            action->setChecked(true);
        }
    }
}

template<typename Enum>
QList<QAction*> EnumTableWidgetItem<Enum>::requestActions(QObject* parent)
{
    m_actionGroup = new QActionGroup(parent);

    if (m_showMinusOneEmpty)
    {
        addAction((Enum)-1);
    }

    for (Enum e = (Enum)0; e < m_max; MoM::inc(e))
    {
        addAction(e);
    }

    return m_actionGroup->actions();
}

template<typename Enum>
void EnumTableWidgetItem<Enum>::slotAction()
{
    QAction* action = m_actionGroup->checkedAction();
    setData(Qt::EditRole, action->data());
}

template<typename Enum>
QString EnumTableWidgetItem<Enum>::toString() const
{
    QString str = prettyQStr(*m_ptr);
    if (m_showMinusOneEmpty && (*m_ptr == (Enum)-1))
    {
        str = "";
    }
    return str;
}

/////////////////////////////////////////

template<typename Bitmask, typename Enum>
class BitmaskTableWidgetItem : public QMoMTableWidgetItemBase
{
public:
    BitmaskTableWidgetItem(const QMoMGamePtr& game, Bitmask& bitmask, Enum min, Enum max);

    virtual void setData(int role, const QVariant &value);

    virtual QList<QAction*> requestActions(QObject* parent);

    virtual void slotAction();

private:
    bool has(Enum e) const;
    QString toString();

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
BitmaskTableWidgetItem<Bitmask, Enum>::BitmaskTableWidgetItem(const QMoMGamePtr& game, Bitmask& bitmask, Enum min, Enum max) :
    QMoMTableWidgetItemBase(game),
    m_ptr(&bitmask),
    m_min(min),
    m_max(max),
    m_actionGroup()
{
    QTableWidgetItem::setData(Qt::EditRole, toString());
}

template<typename Bitmask, typename Enum>
void BitmaskTableWidgetItem<Bitmask, Enum>::setData(int role, const QVariant &value)
{
    switch (role)
    {
    case Qt::EditRole:
        {
            Bitmask newValue = static_cast<Bitmask>(value.toUInt());
            (void)m_game->commitData(m_ptr, &newValue, sizeof(Bitmask));
            QTableWidgetItem::setData(role, toString());
        }
        break;
    default:
        QTableWidgetItem::setData(role, value);
        break;
    }
}

template<typename Bitmask, typename Enum>
QList<QAction*> BitmaskTableWidgetItem<Bitmask, Enum>::requestActions(QObject* parent)
{
    m_actionGroup = new QActionGroup(parent);
    m_actionGroup->setExclusive(false);
    for (Enum e = m_min; e < m_max; MoM::inc(e))
    {
        QAction* action = new QAction(prettyQStr(e), m_actionGroup);
        action->setCheckable(true);
        action->setData(QVariant((int)e));
        if (has(e))
        {
            action->setChecked(true);
        }
    }
    return m_actionGroup->actions();
}

template<typename Bitmask, typename Enum>
void BitmaskTableWidgetItem<Bitmask, Enum>::slotAction()
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
    setData(Qt::EditRole, QVariant((unsigned)bitmask));
}

template<typename Bitmask, typename Enum>
bool BitmaskTableWidgetItem<Bitmask, Enum>::has(Enum e) const
{
    Bitmask mask = (1 << ((unsigned)e - (unsigned)m_min));
    return ((*m_ptr & mask) != 0);
}

template<typename Bitmask, typename Enum>
QString BitmaskTableWidgetItem<Bitmask, Enum>::toString()
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

//////////////////////////////////////

DialogTables::DialogTables(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTables)
{
    ui->setupUi(this);

    ui->comboBox_Table->setCurrentIndex(2);

    // TODO: Make the signal-slot connections to gameChanged and gameUpdated (similar to the other dialogs)
}

DialogTables::~DialogTables()
{
    delete ui;
}


QMoMGamePtr DialogTables::getGame()
{
	QMoMGamePtr game;
	MainWindow* controller = MainWindow::getInstance();
    if (0 != controller)
	{
	    game = controller->getGame();
	}
    return game;
}

void DialogTables::keyPressEvent(QKeyEvent* event)
{
    //if there is a control-C event copy data to the global clipboard
    if ((event->key() == Qt::Key_C) && (event->modifiers() & Qt::ControlModifier))
    {
        slotCopy();
    }
    else
    {
        QDialog::keyPressEvent(event);
    }
}

void DialogTables::update_Spell_Data()
{
    QMoMGamePtr game = getGame();
    MoM::Upkeep_Enchantments* upkeepEnchantments = 0;
    MoM::MoMExeWizards* wizardsExe = 0;
    uint8_t* ovl112 = 0;
    int ndata = 0;

    if (!game.isNull())
    {
        if (0 != game->getDataSegment())
        {
            upkeepEnchantments = &game->getDataSegment()->m_Upkeep_Enchantments;
        }
        wizardsExe = game->getWizardsExe();
        ovl112 = game->getWizardsOverlay(112);
        if (0 != game->getSpell_Data((MoM::eSpell)0))
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

    ui->tableWidget->setColumnCount(labels.size());
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    ui->tableWidget->setRowCount(ndata);

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
    {
        ui->tableWidget->setVerticalHeaderItem(row, new QTableWidgetItem(""));
   }

    for (int row = 0; row < ndata; ++row)
    {
        int spellNr = row + 1;
        MoM::eSpell spell = (MoM::eSpell)spellNr;
        MoM::Spell_Data* data = game->getSpell_Data(spell);

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
        ui->tableWidget->setItem(row, col++, new QMoMTableWidgetItemBase(game, QString("%0").arg(spellNr, 3)));

        ui->tableWidget->setItem(row, col, new TextTableWidgetItem(game, data->m_SpellName, sizeof(data->m_SpellName)));
        ui->tableWidget->item(row, col)->setTextColor(color);
        ui->tableWidget->item(row, col++)->setToolTip(game->getHelpText(spell).c_str());

        ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<int16_t>(game, data->m_Spell_desirability, 6));
        ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<int8_t>(game, data->m_Spell_Category, 2));
        ui->tableWidget->setItem(row, col++, new EnumTableWidgetItem<MoM::eSpell_Type>(game, data->m_Section_in_spell_book, MoM::eSpell_Type_MAX));
        ui->tableWidget->setItem(row, col++, new EnumTableWidgetItem<MoM::eRealm_Type>(game, data->m_Magic_Realm, MoM::eRealm_Type_MAX));

        ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<int8_t>(game, data->m_Casting_eligibility, 4));
        ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<uint16_t>(game, data->m_Casting_cost, 5));
        ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<uint16_t>(game, data->m_Research_cost, 5));

        if ((MoM::SPELLTYPE_Summoning == data->m_Section_in_spell_book) && (0 != (int)data->m_Unit_Summoned_or_Spell_Strength))
        {
            QString parameter = prettyQStr((MoM::eUnit_Type)data->m_Unit_Summoned_or_Spell_Strength);
            ui->tableWidget->setItem(row, col++, new QMoMTableWidgetItemBase(game, parameter));
        }
        else
        {
            ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<int8_t>(game, *(int8_t*)&data->m_Unit_Summoned_or_Spell_Strength, 6));
        }

        ui->tableWidget->setItem(row, col++,
                                 new BitmaskTableWidgetItem<uint8_t, MoM::eUnitAbility>(
                                     game, data->m_Immunity_Flags.bits,
                                     MoM::UNITABILITY_Fire_Immunity, MoM::UNITABILITY_Weapon_Immunity));

        ui->tableWidget->setItem(row, col++,
                                 new BitmaskTableWidgetItem<uint16_t, MoM::eUnitAbility>(
                                     game, data->m_Attack_Flags.bits,
                                     MoM::UNITABILITY_Armor_Piercing, MoM::eUnitAbility_MAX));

        uint16_t* pUpkeep = 0;
        ui->tableWidget->setItem(row, col, new QMoMTableWidgetItemBase(game));
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
                ui->tableWidget->setItem(row, col, new NumberTableWidgetItem<uint16_t>(game, *pUpkeep, 5));
            }
        }
        col++;

        // Spell save
        ui->tableWidget->setItem(row, col++, new QMoMTableWidgetItemBase(game));
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
            if ((rowSpell >= 0) && (rowSpell < ndata))
            {
                ui->tableWidget->setItem(rowSpell, col, new NumberTableWidgetItem<int8_t>(game, *pSaveModifier, 4, SHOWNUMBER_alwaysPlus));
            }
        }
    }

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->sortByColumn(0, Qt::AscendingOrder);
    ui->tableWidget->setSortingEnabled(true);
}

void DialogTables::update_Unit_Types()
{
    QMoMGamePtr game = getGame();
    int ndata = 0;

	if ((0 != game) && (0 != game->getUnit_Type_Data((MoM::eUnit_Type)0)))
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

    ui->tableWidget->setColumnCount(labels.size());
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    ui->tableWidget->setRowCount(ndata);

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
    {
        ui->tableWidget->setVerticalHeaderItem(row, new QTableWidgetItem(""));
    }

	for (int row = 0; (0 != game) && (row < ndata); ++row)
    {
        int unitTypeNr = row;
		MoM::Unit_Type_Data* data = game->getUnit_Type_Data((MoM::eUnit_Type)unitTypeNr);
		if (0 == data)
			break;

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
        ui->tableWidget->setItem(row, col++, new QMoMTableWidgetItemBase(game, QString("%0").arg(unitTypeNr, 3)));

        ui->tableWidget->setItem(row, col, new EnumTableWidgetItem<MoM::eRace>(game, data->m_Race_Code, MoM::eRace_MAX));
        ui->tableWidget->item(row, col++)->setTextColor(color);

        ui->tableWidget->setItem(row, col, new QMoMTableWidgetItemBase(game, game->getNameByOffset(data->m_PtrName)));
        ui->tableWidget->item(row, col++)->setTextColor(color);

        ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<uint8_t>(game, data->m_Nr_Figures, 3));
        ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<uint8_t>(game, data->m_Melee, 3, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<uint8_t>(game, data->m_Ranged, 3, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<uint8_t>(game, data->m_Defense, 3));
        ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<uint8_t>(game, data->m_Resistance, 3));
        ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<uint8_t>(game, data->m_Hitpoints, 3));
        ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<int8_t>(game, data->m_To_Hit, 2, SHOWNUMBER_plusAndNoZero));
        ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<uint8_t>(game, data->m_MoveHalves, 5, SHOWNUMBER_halfMove));
        ui->tableWidget->setItem(row, col++, new EnumTableWidgetItem<MoM::eRanged_Type>(game, data->m_Ranged_Type, MoM::eRanged_Type_MAX, true));
        ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<uint8_t>(game, data->m_Ranged_Shots, 3, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<int8_t>(game, data->m_Gaze_Modifier, 3, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<uint16_t>(game, data->m_Cost, 5));
        ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<uint8_t>(game, data->m_Upkeep, 3));

        if (unitTypeNr < (int)MoM::gMAX_HERO_TYPES)
        {
            ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<uint8_t>(game, data->m_Building_Required1, 4));
            ui->tableWidget->setItem(row, col++, new EnumTableWidgetItem<MoM::eHero_TypeCode>(game, *(MoM::eHero_TypeCode*)&data->m_Hero_TypeCode_or_Building2, MoM::eHero_TypeCode_MAX));
        }
        else if (unitTypeNr < MoM::UNITTYPE_Arcane_Magic_Spirit)
        {
            ui->tableWidget->setItem(row, col++, new EnumTableWidgetItem<MoM::eBuilding8>(game, *(MoM::eBuilding8*)&data->m_Building_Required1, MoM::eBuilding8_MAX));
            ui->tableWidget->setItem(row, col++, new EnumTableWidgetItem<MoM::eBuilding8>(game, *(MoM::eBuilding8*)&data->m_Hero_TypeCode_or_Building2, MoM::eBuilding8_MAX));
        }
        else
        {
            ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<uint8_t>(game, data->m_Building_Required1, 4));
            ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<uint8_t>(game, *(uint8_t*)&data->m_Hero_TypeCode_or_Building2, 4));
        }

        ui->tableWidget->setItem(row, col++, new BitmaskTableWidgetItem<uint8_t, MoM::eUnitAbility>(
                                  game, data->m_Movement_Flags.bits,
                                  MoM::UNITABILITY_Cavalry, MoM::succ(MoM::UNITABILITY_Merging)));

        ui->tableWidget->setItem(row, col++, new BitmaskTableWidgetItem<uint8_t, MoM::eUnitAbility>(
                                  game, data->m_Immunity_Flags.bits,
                                  MoM::UNITABILITY_Fire_Immunity, MoM::UNITABILITY_Weapon_Immunity));

        ui->tableWidget->setItem(row, col++, new BitmaskTableWidgetItem<uint16_t, MoM::eUnitAbility>(
                                  game, data->m_Attribute_Flags.bits,
                                  MoM::UNITABILITY_Weapon_Immunity, MoM::succ(MoM::UNITABILITY_Holy_Bonus)));

        ui->tableWidget->setItem(row, col++, new BitmaskTableWidgetItem<uint16_t, MoM::eUnitAbility>(
                                  game, data->m_Ability_Flags.bits,
                                  MoM::UNITABILITY_Summoned_Unit, MoM::UNITABILITY_Armor_Piercing));

        ui->tableWidget->setItem(row, col++, new BitmaskTableWidgetItem<uint16_t, MoM::eUnitAbility>(
                                  game, data->m_Attack_Flags.bits,
                                  MoM::UNITABILITY_Armor_Piercing, MoM::eUnitAbility_MAX));

        ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<uint8_t>(game, data->m_TypeCode, 3));
        ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<uint8_t>(game, data->m_Scouting, 3));

        ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<uint8_t>(game, data->m_Transport_Capacity, 3, SHOWNUMBER_noZero));
        ui->tableWidget->setItem(row, col++, new NumberTableWidgetItem<uint8_t>(game, data->m_Construction, 3, SHOWNUMBER_noZero));
    }

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->sortByColumn(0, Qt::AscendingOrder);
    ui->tableWidget->setSortingEnabled(true);
}

void DialogTables::update_Unrest_Table()
{
    QMoMGamePtr game = getGame();
    int8_t* unrestTable = 0;
    int ndata = 0;

    if (!game.isNull())
    {
        unrestTable = game->getUnrest_Table(MoM::RACE_Barbarian);
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

    ui->tableWidget->setColumnCount(labels.size());
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    ui->tableWidget->setRowCount(ndata);

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
    {
        ui->tableWidget->setVerticalHeaderItem(row, new QTableWidgetItem(""));
    }

    for (int row = 0; row < ndata; ++row)
    {
        int raceNr = row;
        MoM::eRace homeRace = (MoM::eRace)raceNr;
        int8_t* data = game->getUnrest_Table(homeRace);

        int col = 0;
        ui->tableWidget->setItem(row, col++, new QMoMTableWidgetItemBase(game, QString("%0").arg(raceNr, 2)));
        ui->tableWidget->setItem(row, col, new QMoMTableWidgetItemBase(game, prettyQStr(homeRace)));
        ui->tableWidget->item(row, col++)->setToolTip(game->getHelpText(homeRace).c_str());

        for (col = 2; col < labels.size(); ++col)
        {
            MoM::eRace cityRace = (MoM::eRace)(col - 2);
            ui->tableWidget->setItem(row, col, new NumberTableWidgetItem<int8_t>(game, data[cityRace], 3, SHOWNUMBER_positivePlus));
        }
    }

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->sortByColumn(0, Qt::AscendingOrder);
    ui->tableWidget->setSortingEnabled(true);
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

void DialogTables::on_tableWidget_clicked(QModelIndex)
{
    ui->tableWidget->resizeRowsToContents();
}

void DialogTables::on_tableWidget_customContextMenuRequested(const QPoint &pos)
{
    qDebug() << "on_tableWidget_customContextMenuRequested" << pos;
    QTableWidgetItem* pItem = ui->tableWidget->currentItem();

    QMenu contextMenu;
    contextMenu.addAction("Copy", this, SLOT(slotCopy()), QKeySequence("Ctrl+C"));

    QMoMTableWidgetItemBase* pMoMItem = dynamic_cast<QMoMTableWidgetItemBase*>(pItem);
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
            connect(action, SIGNAL(triggered()), this, SLOT(slotItemAction()));
        }
    }

    contextMenu.exec(mapToGlobal(pos));
}

void DialogTables::slotCopy()
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

void DialogTables::slotItemAction()
{
    QTableWidgetItem* pItem = ui->tableWidget->currentItem();
    QMoMTableWidgetItemBase* pMoMItem = dynamic_cast<QMoMTableWidgetItemBase*>(pItem);
    if (0 != pMoMItem)
    {
        pMoMItem->slotAction();
    }
}
