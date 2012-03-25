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

#include <QMoMSharedPointers.h>

namespace Ui {
    class DialogBuildingQueues;
}

class DialogBuildingQueues : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBuildingQueues(QWidget *parent = 0);
    ~DialogBuildingQueues();

private slots:
    void on_buttonBox_clicked(QAbstractButton* button);
	void slot_gameChanged(const QMoMGamePtr& game);
	void slot_gameUpdated();

private:
    void update();

	QMoMGamePtr m_game;

    Ui::DialogBuildingQueues *ui;
};


#endif // DIALOGBUILDINGQUEUES_H
