#ifndef DIALOGADDUNIT_H
#define DIALOGADDUNIT_H

#include <QAbstractButton>
#include <QDialog>

namespace Ui {
class DialogAddUnit;
}

namespace MoM {
    class MoMGameBase;
}

class DialogAddUnit : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogAddUnit(QWidget *parent = 0);
    ~DialogAddUnit();
    
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    MoM::MoMGameBase* getGame();

    Ui::DialogAddUnit *ui;
};

#endif // DIALOGADDUNIT_H
