#ifndef QMOMTABLEITEM_H
#define QMOMTABLEITEM_H

#include <QActionGroup>
#include <QTableWidgetItem>

#include "QMoMResources.h"
#include "QMoMSharedPointers.h"

///////////////////////////////////////////

enum eShowNumber
{
    SHOWNUMBER_normal,
    SHOWNUMBER_alwaysPlus,
    SHOWNUMBER_positivePlus,
    SHOWNUMBER_noZero,
    SHOWNUMBER_plusAndNoZero,
    SHOWNUMBER_hex,
    SHOWNUMBER_halfMove
};

enum eShowEnum
{
    SHOWENUM_normal,
    SHOWENUM_minusOne,
    SHOWENUM_noZero,
    SHOWENUM_minusOneAndnoZero
};

class QMoMTableItemBase : public QTableWidgetItem
{
public:
    QMoMTableItemBase(const QMoMGamePtr& game, const QString& text = "");
    virtual QList<QAction*> requestActions(QObject* parent);
    virtual void slotAction();
    virtual QString toString() const;

protected:
    QMoMGamePtr m_game;
};

///////////////////////////////////////////

template<typename Number>
class NumberTableItem : public QMoMTableItemBase
{
public:
    // g++ complains that it cannot bind an uint16_t to a reference in this template, probably due to some alignment issue,
    // but it does accept a pointer. :).
    NumberTableItem(const QMoMGamePtr& game, Number* t, int width, eShowNumber showNumber = SHOWNUMBER_normal);
    virtual void setData(int role, const QVariant &value);
    virtual QString toString() const;
private:
    Number* m_ptr;
    int m_width;
    eShowNumber m_showNumber;
};


template<typename Number>
NumberTableItem<Number>::NumberTableItem(const QMoMGamePtr& game, Number* t, int width, eShowNumber showNumber) :
    QMoMTableItemBase(game),
    m_ptr(t),
    m_width(width),
    m_showNumber(showNumber)
{
    setFlags(flags() | Qt::ItemIsEditable);
    QTableWidgetItem::setData(Qt::EditRole, toString());
}

template<typename Number>
void NumberTableItem<Number>::setData(int role, const QVariant &value)
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
QString NumberTableItem<Number>::toString() const
{
    QString result = QString("%0").arg((int)*m_ptr);
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
    case SHOWNUMBER_hex:
        result = QString("0x%0").arg((unsigned)*m_ptr, m_width, 16, QChar('0'));
        break;
    case SHOWNUMBER_halfMove:
        if (*m_ptr == 0)
        {
            result = "";
        }
        else
        {
            result = QString("%0").arg((double)*m_ptr / 2, m_width, 'f', 1);
        }
        break;
    default:
        assert(0 && "Unknown value if eShowNumber");
    }

    result = QString("%0").arg(result, m_width);
    return result;
}

///////////////////////////////////////////

class TextTableItem : public QMoMTableItemBase
{
public:
    TextTableItem(const QMoMGamePtr& game, char* text, size_t size);
    virtual void setData(int role, const QVariant &value);
    virtual QString toString() const;
private:
    char* m_ptr;
    size_t m_size;
};


inline TextTableItem::TextTableItem(const QMoMGamePtr& game, char* text, size_t size) :
    QMoMTableItemBase(game),
    m_ptr(text),
    m_size(size)
{
    setFlags(flags() | Qt::ItemIsEditable);
    QTableWidgetItem::setData(Qt::EditRole, toString());
}

inline void TextTableItem::setData(int role, const QVariant &value)
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

inline QString TextTableItem::toString() const
{
    std::string str(m_ptr, m_size);
    return QString(str.c_str());
}

/////////////////////////////////////////

template<typename Enum>
class EnumTableItem : public QMoMTableItemBase
{
public:
    EnumTableItem(const QMoMGamePtr& game, Enum* e, Enum max, eShowEnum showEnum = SHOWENUM_normal);

    virtual void setData(int role, const QVariant &value);

    virtual QList<QAction*> requestActions(QObject* parent);

    virtual void slotAction();

    virtual QString toString() const;

private:
    void addAction(Enum e);

    // Configuration
    Enum* m_ptr;
    Enum m_max;
    eShowEnum m_showEnum;

    // Status

    // Keep track of the action group
    // m_actionGroup is deleted by its parent (the context menu)
    QActionGroup* m_actionGroup;
};

template<typename Enum>
EnumTableItem<Enum>::EnumTableItem(const QMoMGamePtr& game, Enum* e, Enum max, eShowEnum showEnum) :
    QMoMTableItemBase(game),
    m_ptr(e),
    m_max(max),
    m_showEnum(showEnum),
    m_actionGroup()
{
    QTableWidgetItem::setData(Qt::EditRole, toString());
}

template<typename Enum>
void EnumTableItem<Enum>::setData(int role, const QVariant &value)
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
void EnumTableItem<Enum>::addAction(Enum e)
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
QList<QAction*> EnumTableItem<Enum>::requestActions(QObject* parent)
{
    m_actionGroup = new QActionGroup(parent);

    if ((m_showEnum == SHOWENUM_minusOne) || (m_showEnum == SHOWENUM_minusOneAndnoZero))
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
void EnumTableItem<Enum>::slotAction()
{
    QAction* action = m_actionGroup->checkedAction();
    setData(Qt::EditRole, action->data());
}

template<typename Enum>
QString EnumTableItem<Enum>::toString() const
{
    QString str = prettyQStr(*m_ptr);
    if (((m_showEnum == SHOWENUM_minusOne) || (m_showEnum == SHOWENUM_minusOneAndnoZero))
            && (*m_ptr == (Enum)-1))
    {
        str = "";
    }
    else if (((m_showEnum == SHOWENUM_noZero) || (m_showEnum == SHOWENUM_minusOneAndnoZero))
            && (*m_ptr == (Enum)0))
    {
        str = "-";
    }
    return str;
}

/////////////////////////////////////////

template<typename Bitmask, typename Enum>
class BitmaskTableItem : public QMoMTableItemBase
{
public:
    // g++ complains that it cannot bind an uint16_t to a reference in this template, probably due to some alignment issue,
    // but it does accept a pointer. :).
    BitmaskTableItem(const QMoMGamePtr& game, Bitmask* bitmask, Enum min, Enum max);

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
BitmaskTableItem<Bitmask, Enum>::BitmaskTableItem(const QMoMGamePtr& game, Bitmask* bitmask, Enum min, Enum max) :
    QMoMTableItemBase(game),
    m_ptr(bitmask),
    m_min(min),
    m_max(max),
    m_actionGroup()
{
    QTableWidgetItem::setData(Qt::EditRole, toString());
}

template<typename Bitmask, typename Enum>
void BitmaskTableItem<Bitmask, Enum>::setData(int role, const QVariant &value)
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
QList<QAction*> BitmaskTableItem<Bitmask, Enum>::requestActions(QObject* parent)
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
void BitmaskTableItem<Bitmask, Enum>::slotAction()
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
bool BitmaskTableItem<Bitmask, Enum>::has(Enum e) const
{
    Bitmask mask = (1 << ((unsigned)e - (unsigned)m_min));
    return ((*m_ptr & mask) != 0);
}

template<typename Bitmask, typename Enum>
QString BitmaskTableItem<Bitmask, Enum>::toString()
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

#endif // QMOMTABLEITEM_H
