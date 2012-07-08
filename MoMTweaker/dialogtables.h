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

#include <QMoMSharedPointers.h>

namespace Ui {
    class DialogTables;
}

class DialogTables : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTables(QWidget *parent = 0);
    ~DialogTables();

    void update_Spell_Data();
    void update_Unit_Types();
    void update_Unrest_Table();

protected:
    virtual void keyPressEvent(QKeyEvent* event);

private:
    QMoMGamePtr getGame();

    Ui::DialogTables *ui;

private slots:
    void on_comboBox_Table_currentIndexChanged(QString );
    void on_tableWidget_clicked(QModelIndex index);
    void on_tableWidget_customContextMenuRequested(const QPoint &pos);

    void slotCopy();
    void slotItemAction();
};

#endif // DIALOGTABLES_H
