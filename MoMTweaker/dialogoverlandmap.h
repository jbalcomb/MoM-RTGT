// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#ifndef DIALOGOVERLANDMAP_H
#define DIALOGOVERLANDMAP_H

#include <QDialog>

#include <QMoMSharedPointers.h>

class QGraphicsScene;

namespace Ui {
    class DialogOverlandMap;
}

class DialogOverlandMap : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOverlandMap(QWidget *parent = 0);
    ~DialogOverlandMap();

private:
    QMoMGamePtr getGame();

    QGraphicsScene* m_sceneArcanus;
    QGraphicsScene* m_sceneMyrror;

    Ui::DialogOverlandMap *ui;

private slots:
    void on_comboBox_Plane_currentIndexChanged(int index);
};

#endif // DIALOGOVERLANDMAP_H
