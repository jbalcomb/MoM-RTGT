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
#include <QMap>

#include <QMoMSharedPointers.h>

class QGraphicsItem;
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
    typedef QMap<const void*, QGraphicsItem*> LookupMap;

    QGraphicsItem* lookup(const void* momPtr)
    {
        LookupMap::iterator it = m_lookup.find(momPtr);
        if (m_lookup.end() == it)
            return 0;
        else
            return it.value();
    }

private:
    QMoMGamePtr m_game;

    QGraphicsScene* m_sceneArcanus;
    QGraphicsScene* m_sceneMyrror;
    LookupMap m_lookup;
    QMoMTimerPtr m_timer;

    Ui::DialogOverlandMap *ui;

private slots:
    void on_comboBox_Plane_currentIndexChanged(int index);
    void on_verticalSlider_Zoom_valueChanged(int value);
    void slot_gameChanged(const QMoMGamePtr& game);
    void slot_gameUpdated();
    void slot_tileChanged(const MoM::Location& loc);
    void slot_timerActiveUnit();
};

#endif // DIALOGOVERLANDMAP_H
