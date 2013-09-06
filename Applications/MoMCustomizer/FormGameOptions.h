#ifndef FORMGAMEOPTIONS_H
#define FORMGAMEOPTIONS_H

#include <QWidget>

namespace Ui {
class FormGameOptions;
}

class FormGameOptions : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormGameOptions(QWidget *parent = 0);
    ~FormGameOptions();
    
private slots:
    void on_pushButton_OK_clicked();

signals:
    void signal_accepted();

private:
    Ui::FormGameOptions *ui;
};

#endif // FORMGAMEOPTIONS_H
