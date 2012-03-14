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

class DialogBuildingQueues : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBuildingQueues(QWidget *parent = 0);
    ~DialogBuildingQueues();

private:
    void update();

    Ui::DialogBuildingQueues *ui;

private slots:
    void on_buttonBox_clicked(QAbstractButton* button);
};

#endif // DIALOGBUILDINGQUEUES_H
