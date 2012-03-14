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

#include <MoMGameBase.h>
#include "treeitem.h"

class UnitModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit UnitModel(QObject *parent = 0);

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

    void setGame(MoM::MoMGameBase* game);
    void update();
 
private:
    void setupModelData(MoM::MoMGameBase* game);

    void removeUnusedRows(int toprow, TreeItemBase* ptree, int firstUnusedRow);

    void update_Buildings(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row);
    void update_Items_in_Game(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row);
    void update_Lairs(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row);
    void update_Spell_Data(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row);
    void update_Unit_Types(TreeItemBase* ptree, MoM::MoMGameBase* game, int& row);


    static const int m_columnCount = 3;

    TreeItemBase *m_rootItem;

signals:

public slots:

};

#endif // UNITMODEL_H
