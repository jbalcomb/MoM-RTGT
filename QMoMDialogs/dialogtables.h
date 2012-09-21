// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#ifndef DIALOGTABLES_H
#define DIALOGTABLES_H

#include <QDialog>
#include <QModelIndex>

#include "QMoMSharedPointers.h"

namespace Ui {
    class DialogTables;
}

class DialogTables : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTables(QWidget *parent = 0);
    ~DialogTables();

protected:
    virtual void keyPressEvent(QKeyEvent* event);

private:
    QColor getRaceColor(MoM::eRace race) const;

    void initializeTable(const QStringList& labels, int rows);
    void finalizeTable();

    void update_Building_Data();
    void update_Item_Data();
    void update_Item_Powers();
    void update_Items_in_game();
    void update_Race_Data();
    void update_Spell_Data();
    void update_Unit_Types();
    void update_Unrest_Table();

private:
    QMoMGamePtr m_game;

    Ui::DialogTables *ui;

private slots:
    void on_comboBox_Table_currentIndexChanged(QString );
    void on_tableWidget_clicked(QModelIndex index);
    void on_tableWidget_customContextMenuRequested(const QPoint &pos);

    void slot_Copy();
    void slot_ItemAction();
    void slot_gameChanged(const QMoMGamePtr& game);
    void slot_gameUpdated();
};

#endif // DIALOGTABLES_H
