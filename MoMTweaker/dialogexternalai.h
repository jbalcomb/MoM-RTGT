#ifndef DIALOGEXTERNALAI_H
#define DIALOGEXTERNALAI_H

#include <QDialog>

#include "MoMHookManager.h"
#include "QMoMSharedPointers.h"

namespace Ui {
class DialogExternalAI;
}

class DialogExternalAI : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogExternalAI(QWidget *parent = 0);
    ~DialogExternalAI();
    
private slots:
    void on_pushButton_InsertHook_clicked();

    void on_pushButton_RaiseHook_clicked();

    void on_pushButton_WaitForHook_clicked();

    void on_pushButton_RetractHook_clicked();

    void on_pushButton_ReleaseHook_clicked();

private:
    Ui::DialogExternalAI *ui;

    QMoMGamePtr m_game;
    MoM::MoMHookManager* hookManager;
};

#endif // DIALOGEXTERNALAI_H