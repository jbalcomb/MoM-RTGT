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

#include "MoMGameBase.h"
#include "QMoMResources.h"
#include "QMoMSharedPointers.h"
#include "QMoMUtility.h"

class QMoMTreeItemBase
{
public:
    QMoMTreeItemBase(const QString& data = QString(), const QMoMLazyIconPtr& icon = QMoMLazyIconPtr());

    virtual ~QMoMTreeItemBase();

    virtual void appendChild(const QString& feature, QMoMTreeItemBase* value);

    virtual void appendTree(QMoMTreeItemBase* tree, const QString& value);

    void appendRow(const QList<QMoMTreeItemBase*>& items);

    void appendEmptyRow();

    QMoMTreeItemBase* child(int row, int col);

    bool commitData(void* ptr, void* pNewValue, size_t size);

    virtual QVariant data(int role) const;

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

    void removeRows(int firstRow, int lastRow);

    bool resolveIcon() const
    {
        if (m_icon.isNull())
            return false;
        return m_icon->resolve();
    }

    int row() const
    {
        return m_row;
    }

    int rowCount() const
    {
        return m_children.count();
    }

    void setChild(int row, int col, QMoMTreeItemBase* item);

    virtual void setData(const QVariant &value, int role);

    void setFlagsEditable()
    {
        m_flags |= Qt::ItemIsEditable;
    }

    static void setGame(const QMoMGamePtr game)
    {
        m_game = game;
    }

    template<class T>
    void setLazyIcon(const T& ref) const
    {
        QSharedPointer< MoM::QMoMLazyIcon<T> > p = m_icon.dynamicCast< MoM::QMoMLazyIcon<T> >();
        if (!p.isNull())
        {
            p->setData(ref);
        }
        else
        {
            m_icon = QMoMLazyIconPtr(new MoM::QMoMLazyIcon<T>(ref));
        }
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
    Qt::ItemFlags m_flags;

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
        setFlagsEditable();
    }
    QMoMTreeItem(T* ptr, unsigned mask) :
        QMoMTreeItemBase(),
        m_ptr(ptr),
        m_mask(mask),
        m_shift(0)
    {
        setFlagsEditable();
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
        setFlagsEditable();
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
        setFlagsEditable();
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
