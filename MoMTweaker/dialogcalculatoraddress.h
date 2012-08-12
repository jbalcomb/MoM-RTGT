// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#ifndef DIALOGCALCULATORADDRESS_H
#define DIALOGCALCULATORADDRESS_H

#include <QDialog>

#include <QMoMSharedPointers.h>

namespace Ui {
    class DialogCalculatorAddress;
}

class DialogCalculatorAddress : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCalculatorAddress(QWidget *parent = 0);
    ~DialogCalculatorAddress();

    void update();

public slots:
    void slot_gameChanged(const QMoMGamePtr& game);
    void slot_gameUpdated();
    void slot_addressChanged(const void* momPointer);

private:
    void updateCurrentValue(const uint8_t* pointer);

private:
    // CONFIG
    QMoMGamePtr m_game;

    // STATUS
    Ui::DialogCalculatorAddress *ui;

    bool m_updating;

private slots:
    void on_lineEdit_OffsetMem_textChanged(QString );
    void on_lineEdit_OffsetIDA_textChanged(QString );
    void on_lineEdit_OffsetExe_textChanged(QString );
};

#endif // DIALOGCALCULATORADDRESS_H
