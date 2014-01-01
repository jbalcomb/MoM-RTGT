// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#ifndef DIALOGBUILDINGQUEUES_H
#define DIALOGBUILDINGQUEUES_H

#include <QAbstractButton>
#include <QDialog>
#include <QModelIndex>

#include "QMoMDialogBase.h"

namespace Ui {
    class DialogBuildingQueues;
}

namespace MoM {
    enum eResource;
}

class DialogBuildingQueues : public QMoMDialogBase
{
    Q_OBJECT

public:
    explicit DialogBuildingQueues(QWidget *parent = 0);
    ~DialogBuildingQueues();

private slots:
    void on_buttonBox_clicked(QAbstractButton* button);
    void on_tableWidget_Cities_cellChanged(int row, int column);
    void on_tableWidget_Cities_clicked(const QModelIndex &index);
    void on_tableWidget_Cities_customContextMenuRequested(const QPoint &pos);
    void slot_gameChanged(const QMoMGamePtr& game);
	void slot_gameUpdated();
    void slot_ItemActionCities();
    void slot_ItemActionSummary();

    void on_tableWidget_Summary_customContextMenuRequested(const QPoint &pos);

private:
    static QIcon getResourceIcon(MoM::eResource resource, int value);
    void update();

    bool m_updating;
    int m_columnFarmers;
    int m_columnBuy;    

    Ui::DialogBuildingQueues *ui;
};


#endif // DIALOGBUILDINGQUEUES_H
