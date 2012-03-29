// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#ifndef QMOMTREEITEM_H
#define QMOMTREEITEM_H

#include <QStandardItem>

#include <iomanip>

#include "MoMGameBase.h"
#include "QMoMResources.h"
#include "QMoMSharedPointers.h"

template< typename T >
inline QString toQStr(const T& t)
{
    std::ostringstream oss;
    oss << std::boolalpha;
    oss << t;
    return oss.str().c_str();
}

template<>
inline QString toQStr<uint8_t>(const uint8_t& t)
{
    std::ostringstream oss;
    oss << (unsigned)t;
    if (t >= 16)
    {
        oss << " 0x" << std::hex << std::setfill('0') << std::setw(2) << (unsigned)t;
    }
    return oss.str().c_str();
}

template<>
inline QString toQStr<int8_t>(const int8_t& t)
{
    std::ostringstream oss;
    oss << (int)t;
    if (t < -1 || t >= 16)
    {
        oss << " 0x" << std::hex << std::setfill('0') << std::setw(2) << (unsigned)(uint8_t)t;
    }
    return oss.str().c_str();
}

template<>
inline QString toQStr<uint16_t>(const uint16_t& t)
{
    std::ostringstream oss;
    oss << (unsigned)t;
    if (t >= 16)
    {
        oss << " 0x" << std::hex << std::setfill('0') << std::setw(4) << t;
    }
    return oss.str().c_str();
}

template<>
inline QString toQStr<int16_t>(const int16_t& t)
{
    std::ostringstream oss;
    oss << (int)t;
    if (t < -1 || t >= 16)
    {
        oss << " 0x" << std::hex << std::setfill('0') << std::setw(4) << (uint16_t)t;
    }
    return oss.str().c_str();
}

template<>
inline QString toQStr<uint32_t>(const uint32_t& t)
{
    std::ostringstream oss;
    oss << (unsigned)t;
    if (t >= 16)
    {
        oss << " 0x" << std::hex << std::setfill('0') << std::setw(8) << (unsigned)t;
    }
    return oss.str().c_str();
}

template<>
inline QString toQStr<int32_t>(const int32_t& t)
{
    std::ostringstream oss;
    oss << (int)t;
    if (t < -1 || t >= 16)
    {
        oss << " 0x" << std::hex << std::setfill('0') << std::setw(8) << (uint32_t)t;
    }
    return oss.str().c_str();
}

template< typename T >
inline QString prettyQStr(const T& t)
{
    QString tmp(toQStr(t));

    // Strip number information
    tmp.replace(QRegExp(" \\(\\d+\\)"), "");
    // Strip m_ prefix
    tmp.replace(QRegExp("^m_"), "");
    // Strip CAPITAL_ prefix
    tmp.replace(QRegExp("^[A-Z][A-Z0-9]+_"), "");
    // Replace underscores by spaces
    tmp.replace('_', ' ');

    return tmp;
}

class QMoMTreeItemBase
{
public:
    QMoMTreeItemBase(const QString& data = QString(), const QMoMLazyIconPtr& icon = QMoMLazyIconPtr()) :
            m_parent(),
            m_row(),
            m_icon(icon),
            m_data(data),
            m_children(),
            m_flags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable)
    {
        // Strip number information
        m_data.replace(QRegExp(" \\(\\d+\\)"), "");
        // Strip m_ prefix
        m_data.replace(QRegExp("^m_"), "");
        // Strip CAPITAL_ prefix
        m_data.replace(QRegExp("^[A-Z][A-Z0-9]+_"), "");
        // Replace underscores by spaces
        m_data.replace('_', ' ');

        if (m_icon.isNull() && !m_data.isEmpty())
        {
            m_icon = QMoMLazyIconPtr(new MoM::QMoMLazyIcon<QString>(QString("images:" + m_data + ".gif")));
        }
    }

    virtual ~QMoMTreeItemBase()
    {
        for (int row = 0; row < m_children.count(); ++row)
        {
            for (int col = 0; col < m_children[row].count(); ++col)
            {
                delete m_children[row][col];
            }
        }
    }

    virtual void appendChild(const QString& feature, QMoMTreeItemBase* value)
    {
        QList<QMoMTreeItemBase*> items;

        items.append(new QMoMTreeItemBase(feature));
        items.append(value);
        items.append(new QMoMTreeItemBase);

        appendRow(items);
    }

    virtual void appendTree(QMoMTreeItemBase* tree, const QString& value)
    {
        QList<QMoMTreeItemBase*> items;

        items.append(tree);
        items.append(new QMoMTreeItemBase(value));
        items.append(new QMoMTreeItemBase);

        appendRow(items);
    }

    void appendRow(const QList<QMoMTreeItemBase*>& items)
    {
        int newRow = m_children.count();
        m_children.append(items);
        for (int i = 0; i < m_children.back().count(); ++i)
        {
            QMoMTreeItemBase* item = m_children.back().at(i);
            item->setParent(this);
            item->setRow(newRow);
        }
    }

    void appendEmptyRow()
    {
        QList<QMoMTreeItemBase*> items;
        items.append(new QMoMTreeItemBase());
        items.append(new QMoMTreeItemBase());
        items.append(new QMoMTreeItemBase());
        appendRow(items);
    }

    QMoMTreeItemBase* child(int row, int col)
    {
        if (row >= m_children.count())
            return 0;
        if (col >= m_children[row].count())
            return 0;
        return m_children[row][col];
    }

    virtual bool commitData(void* ptr, void* pNewValue, size_t size)
    {
        bool ok = true;
        if (0 != m_game)
        {
            ok = m_game->commitData(ptr, pNewValue, size);
        }
        return ok;
    }

    virtual QVariant data(int role) const
    {
//        qDebug() << QString("data(%0)=%1").arg((Qt::ItemDataRole)role).arg(m_data);

        m_flags &= ~Qt::ItemIsEditable; // If we get here, this item is not editable by the user

        switch (role)
        {
        case Qt::DisplayRole:
        case Qt::EditRole:
            return m_data;
        case Qt::DecorationRole:
            if (m_icon.isNull())
                return QIcon();
            else
                return m_icon->data();
        default:
            return QVariant();
        }
    }

    Qt::ItemFlags flags() const
    {
        return m_flags;
    }

    static const QMoMGamePtr& game(void)
    {
        return m_game;
    }

    const QMoMLazyIconPtr& lazyIcon() const
    {
        return m_icon;
    }

    QMoMTreeItemBase* parent() const
    {
        return m_parent;
    }

    void removeRows(int firstRow, int lastRow)
    {
        if (lastRow >= m_children.count())
        {
            lastRow = m_children.count() - 1;
        }
        for (int row = lastRow; row >= firstRow; --row)
        {
            QList<QMoMTreeItemBase*>& curRow = m_children[row];
            for (int col = curRow.count() - 1; col >= 0; --col)
            {
                delete curRow[col];
            }
            m_children.removeAt(row);
        }
    }

    int row() const
    {
        return m_row;
    }

    int rowCount() const
    {
        return m_children.count();
    }

    void setChild(int row, int col, QMoMTreeItemBase* item)
    {
        if (row > m_children.count())
            return;
        if (row == m_children.count())
        {
            appendEmptyRow();
        }
        if (col >= m_children[row].count())
            return;

        delete m_children[row][col];
        m_children[row][col] = item;

        item->setParent(this);
        item->setRow(row);
    }

    virtual void setData(const QVariant &value, int role)
    {
//        qDebug() << QString("setData(value='%0', role=%1)").arg(value.value<QString>()).arg((Qt::ItemDataRole)role);
        if (Qt::EditRole == role)
        {
            if (QVariant::Icon == value.type())
            {
                m_icon = QMoMLazyIconPtr(new MoM::QMoMLazyIcon<QIcon>(value.value<QIcon>()));
            }
            else if (QVariant::String == value.type())
            {
                m_data = value.value<QString>();
            }
            else
            {
                // Nothing to do
            }
        }
        else if (Qt::UserRole == role)
        {
            m_data = value.value<QString>();

            // Strip number information
            m_data.replace(QRegExp(" \\(\\d+\\)"), "");
            // Strip m_ prefix
            m_data.replace(QRegExp("^m_"), "");
            // Strip CAPITAL_ prefix
            m_data.replace(QRegExp("^[A-Z][A-Z0-9]+_"), "");
            // Replace underscores by spaces
            m_data.replace('_', ' ');

            m_icon = QMoMLazyIconPtr(new MoM::QMoMLazyIcon<QString>("images:" + m_data + ".gif"));
        }
        else
        {
            // Nothing to do
        }
    }

    static void setGame(const QMoMGamePtr game)
    {
        m_game = game;
    }

    void setLazyIcon(const QString& ref) const
    {
        m_icon = QMoMLazyIconPtr(new MoM::QMoMLazyIcon<QString>(ref));
    }

private:

    void setParent(QMoMTreeItemBase* parent)
    {
        m_parent = parent;
    }
    void setRow(int row)
    {
        m_row = row;
    }

    QMoMTreeItemBase* m_parent;
    int m_row;
    mutable QMoMLazyIconPtr m_icon;
    QString m_data;
    QList< QList<QMoMTreeItemBase*> > m_children;
    mutable Qt::ItemFlags m_flags;

    static QMoMGamePtr m_game;
};

template< typename T >
class QMoMTreeItem : public QMoMTreeItemBase
{
public:
    explicit QMoMTreeItem(T* ptr) :
        QMoMTreeItemBase(),
        m_ptr(ptr),
        m_mask(0),
        m_shift(0)
    {
    }
    QMoMTreeItem(T* ptr, unsigned mask) :
        QMoMTreeItemBase(),
        m_ptr(ptr),
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
    }

    virtual QVariant data(int role) const
    {
        QString value;
        if ((Qt::DisplayRole == role) || (Qt::EditRole == role) || (Qt::DecorationRole == role))
        {
            if (0 == m_mask)
            {
                // Strip uppercase prefix
                // Replace underscores by spaces
                value = toQStr(*m_ptr).replace(QRegExp("^[A-Z][A-Z0-9]+_"), "").replace('_', ' ');
            }
            else
            {
                value = toQStr(static_cast<T>(((unsigned)*m_ptr & m_mask) >> m_shift));
            }
        }
//        qDebug() << QString("data(%0)=%1").arg((Qt::ItemDataRole)role).arg(value);
        switch (role)
        {
        case Qt::DisplayRole:
        case Qt::EditRole:
            return value;
        case Qt::DecorationRole:
            {
                // Strip number information
                value.replace(QRegExp(" \\(\\d+\\)"), "");
                setLazyIcon("images:" + value + ".gif");
                return QMoMTreeItemBase::data(role);
            }
        default:
            return QVariant();
        }
    }

    virtual void setData(const QVariant &value, int role)
    {
//        qDebug() << QString("setData(value='%0', role=%1)").arg(value.value<QString>()).arg((Qt::ItemDataRole)role);
        switch (role)
        {
        case Qt::EditRole:
            {
                T newValue;
                if (0 == m_mask)
                {
                    newValue = static_cast<T> (value.toInt());
                }
                else
                {
                    unsigned tmp = ((unsigned)*m_ptr & ~m_mask);
                    newValue = static_cast<T>(tmp | (((unsigned)value.toInt() << m_shift) & m_mask));
                }
                (void)commitData(m_ptr, &newValue, sizeof(T));
            }
            break;
        default:
            break;
        }
   }

signals:

public slots:

private:
    T* m_ptr;
    unsigned m_mask;
    unsigned m_shift;
};

template< size_t N>
class QMoMTreeItem< char[N] > : public QMoMTreeItemBase
{
public:
    explicit QMoMTreeItem(char ptr[N]) :
        QMoMTreeItemBase(),
        m_ptr(ptr)
    {
    }

    virtual QVariant data(int role) const
    {
        QString value(m_ptr);

//        qDebug() << QString("data(%0)=%1").arg((Qt::ItemDataRole)role).arg(value);

        switch (role)
        {
        case Qt::DisplayRole:
        case Qt::EditRole:
            return value;
        case Qt::DecorationRole:
//            return QIcon("images:" + value + ".gif");
            return QMoMTreeItemBase::data(role);
        default:
            return QVariant();
        }
    }

    virtual void setData(const QVariant &value, int role)
    {
//        qDebug() << QString("setData(%0, %1)").arg(value.value<QString>()).arg((Qt::ItemDataRole)role);
        char newvalue[N] = "";
        switch (role)
        {
        case Qt::EditRole:
            strncpy(newvalue, value.toByteArray().data(), N - 1);
            (void)commitData(m_ptr, newvalue, strlen(newvalue) + 1);
            break;
        default:
            break;
        }
   }

signals:

public slots:

private:
    // NOT IMPLEMENTED
    QMoMTreeItem();

    char* m_ptr;
};

template<>
class QMoMTreeItem< const char* > : public QMoMTreeItemBase
{
public:
    explicit QMoMTreeItem(const char* ptr) :
        QMoMTreeItemBase(),
        m_ptr(ptr),
        m_size(strlen(ptr) + 1)
    {
    }

    virtual QVariant data(int role) const
    {
        QString value(m_ptr);

//        qDebug() << QString("data(%0)=%1").arg((Qt::ItemDataRole)role).arg(value);

        switch (role)
        {
        case Qt::DisplayRole:
        case Qt::EditRole:
            return value;
        case Qt::DecorationRole:
//            return QIcon("images:" + value + ".gif");
            return QMoMTreeItemBase::data(role);
        default:
            return QVariant();
        }
    }

    virtual void setData(const QVariant &value, int role)
    {
//        qDebug() << QString("setData(value='%0', role=%1)").arg(value.value<QString>()).arg((Qt::ItemDataRole)role);
        std::string newvalue(m_size, '\0');
        switch (role)
        {
        case Qt::EditRole:
            strncpy(&newvalue[0], value.toByteArray().data(), m_size - 1);
            (void)commitData((char*)m_ptr, &newvalue[0], m_size);
            break;
        default:
            break;
        }
   }

signals:

public slots:

private:
    // NOT IMPLEMENTED
    QMoMTreeItem();

    const char* m_ptr;
    size_t m_size;
};

//
//
//

template< typename T >
class QMoMTreeItemSubtree : public QMoMTreeItemBase
{
public:
    explicit QMoMTreeItemSubtree(T* ptr, const QString& data = QString(), const QMoMLazyIconPtr& icon = QMoMLazyIconPtr()) :
        QMoMTreeItemBase(data, icon),
        m_ptr(ptr)
    {
    }

    T* getMoMPointer()
    {
        return m_ptr;
    }

signals:

public slots:

private:
    T* m_ptr;
};

#endif // QMOMTREEITEM_H
