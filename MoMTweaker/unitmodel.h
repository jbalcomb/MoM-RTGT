// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#ifndef UNITMODEL_H
#define UNITMODEL_H

#include <QAbstractItemModel>
#include <QSharedPointer>

#include <MoMGameBase.h>
#include <MoMUnit.h>
#include <QMoMSharedPointers.h>
#include <QMoMTreeItem.h>

class UnitModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit UnitModel(QObject *parent = 0);
	virtual ~UnitModel();

    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

//    void setGame(const QMoMGamePtr& game);
//    void update();

public slots:
    void slot_gameChanged(const QMoMGamePtr& game);
    void slot_gameUpdated();
    void slot_selectionChanged(const QModelIndex &index);

signals:
    void signal_unitChanged(const QMoMUnitPtr& unit);

private:
	void abortUpdate();
	void startUpdate();
    void waitForUpdate();
	void threadUpdateModelData();

//    void setupModelData(const QMoMGamePtr& game);

    template<class T>
    void checkUnitChanged(QMoMTreeItemBase* itemBase);

    void removeUnusedRows(int toprow, QMoMTreeItemBase* ptree, int firstUnusedRow);

    void update_Buildings(QMoMTreeItemBase* ptree, const QMoMGamePtr& game, int& row);
    void update_Items_in_Game(QMoMTreeItemBase* ptree, const QMoMGamePtr& game, int& row);
    void update_Lairs(QMoMTreeItemBase* ptree, const QMoMGamePtr& game, int& row);
    void update_Spell_Data(QMoMTreeItemBase* ptree, const QMoMGamePtr& game, int& row);
    void update_Unit_Types(QMoMTreeItemBase* ptree, const QMoMGamePtr& game, int& row);


    static const int m_columnCount = 3;

    QMoMTreeItemPtr m_rootItem;
	bool m_abortUpdate;

	friend class ThreadUpdateModelData;
};

#endif // UNITMODEL_H
