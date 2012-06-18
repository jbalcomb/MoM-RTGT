// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2011-09-30
// ---------------------------------------------------------------------------

#include "QMoMTreeItem.h"

QMoMGamePtr QMoMTreeItemBase::m_game;

QMoMTreeItemBase::QMoMTreeItemBase(const QString& data, const QMoMLazyIconPtr& icon) :
        m_parent(),
        m_row(),
        m_icon(icon),
        m_data(data),
        m_children(),
        m_flags(Qt::ItemIsEnabled | Qt::ItemIsSelectable)
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
        setLazyIcon(QString("images:" + m_data + ".gif"));
    }
}

QMoMTreeItemBase::~QMoMTreeItemBase()
{
    for (int row = 0; row < m_children.count(); ++row)
    {
        for (int col = 0; col < m_children[row].count(); ++col)
        {
            delete m_children[row][col];
        }
    }
}

void QMoMTreeItemBase::appendChild(const QString& feature, QMoMTreeItemBase* value)
{
    QList<QMoMTreeItemBase*> items;

    items.append(new QMoMTreeItemBase(feature));
    items.append(value);
    items.append(new QMoMTreeItemBase);

    appendRow(items);
}

void QMoMTreeItemBase::appendTree(QMoMTreeItemBase* tree, const QString& value)
{
    QList<QMoMTreeItemBase*> items;

    items.append(tree);
    items.append(new QMoMTreeItemBase(value));
    items.append(new QMoMTreeItemBase);

    appendRow(items);
}

void QMoMTreeItemBase::appendRow(const QList<QMoMTreeItemBase*>& items)
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

void QMoMTreeItemBase::appendEmptyRow()
{
    QList<QMoMTreeItemBase*> items;
    items.append(new QMoMTreeItemBase());
    items.append(new QMoMTreeItemBase());
    items.append(new QMoMTreeItemBase());
    appendRow(items);
}

QMoMTreeItemBase* QMoMTreeItemBase::child(int row, int col)
{
    if (row >= m_children.count())
        return 0;
    if (col >= m_children[row].count())
        return 0;
    return m_children[row][col];
}

bool QMoMTreeItemBase::commitData(void* ptr, void* pNewValue, size_t size)
{
    bool ok = true;
    if (0 != m_game)
    {
        ok = m_game->commitData(ptr, pNewValue, size);
    }
    return ok;
}

QVariant QMoMTreeItemBase::data(int role) const
{
//        qDebug() << QString("data(%0)=%1").arg((Qt::ItemDataRole)role).arg(m_data);

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
    case Qt::ToolTipRole:
        return m_toolTip;
    default:
        return QVariant();
    }
}

void QMoMTreeItemBase::removeRows(int firstRow, int lastRow)
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

void QMoMTreeItemBase::setChild(int row, int col, QMoMTreeItemBase* item)
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

void QMoMTreeItemBase::setData(const QVariant &value, int role)
{
//        qDebug() << QString("setData(value='%0', role=%1)").arg(value.value<QString>()).arg((Qt::ItemDataRole)role);
    if (Qt::EditRole == role)
    {
        if (QVariant::Icon == value.type())
        {
            setLazyIcon(value.value<QIcon>());
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

        setLazyIcon(QString("images:" + m_data + ".gif"));
    }
    else
    {
        // Nothing to do
    }
}
