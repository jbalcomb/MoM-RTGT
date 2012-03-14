#ifndef DIALOGTOOLS_H
#define DIALOGTOOLS_H

#include <QDialog>
#include <QStatusBar>

namespace Ui {
class DialogTools;
}

namespace MoM {
    class MoMGameBase;
}

class DialogTools : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogTools(QWidget *parent = 0);
    ~DialogTools();
   
private slots:
    void on_pushButton_AddUnit_clicked();
    void on_pushButton_RepopLairs_clicked();
    void on_pushButton_ApplyBuildQueues_clicked();
    void on_pushButton_CatnipMod_clicked();
    void on_pushButton_LucernMod_clicked();
    void on_pushButton_Validate_clicked();
    void on_pushButton_SelectInitialSpells_clicked();

private:
	MoM::MoMGameBase* getGame();
	QStatusBar* statusBar();

    Ui::DialogTools *ui;
};

#endif // DIALOGTOOLS_H
