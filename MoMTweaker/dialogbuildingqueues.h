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

namespace Ui {
    class DialogBuildingQueues;
}

namespace MoM {
	class MoMGameBase;
}

class DialogBuildingQueues : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBuildingQueues(QWidget *parent = 0);
    ~DialogBuildingQueues();

private slots:
    void on_buttonBox_clicked(QAbstractButton* button);
	void slot_gameChanged(MoM::MoMGameBase* game);
	void slot_gameUpdated();

private:
    void update();

	MoM::MoMGameBase* m_game;

    Ui::DialogBuildingQueues *ui;
};


#endif // DIALOGBUILDINGQUEUES_H
