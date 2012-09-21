#include "QMoMTableItem.h"

///////////////////////////////////////////

QMoMTableItemBase::QMoMTableItemBase(const QMoMGamePtr& game, const QString& text) :
    QTableWidgetItem(text),
    m_game(game)
{
    // Not editable by default
    setFlags(flags() & ~Qt::ItemIsEditable);
    // Centered by default
    setTextAlignment(Qt::AlignCenter);
}

QList<QAction*> QMoMTableItemBase::requestActions(QObject* parent)
{
    return QList<QAction*>();
}

void  QMoMTableItemBase::slotAction()
{
}

QString  QMoMTableItemBase::toString() const
{
    return QTableWidgetItem::text();
}

///////////////////////////////////////////

