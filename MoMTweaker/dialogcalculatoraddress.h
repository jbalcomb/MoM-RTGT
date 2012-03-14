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

namespace MoM {
    class MoMGameBase;
}

namespace Ui {
    class DialogCalculatorAddress;
}

class DialogCalculatorAddress : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCalculatorAddress(QWidget *parent = 0);
    ~DialogCalculatorAddress();

    MoM::MoMGameBase* getGame();
    void update();

private:
    Ui::DialogCalculatorAddress *ui;

    bool m_updating;

private slots:
    void on_lineEdit_OffsetMem_textChanged(QString );
    void on_lineEdit_OffsetIDA_textChanged(QString );
    void on_lineEdit_OffsetExe_textChanged(QString );
};

#endif // DIALOGCALCULATORADDRESS_H
