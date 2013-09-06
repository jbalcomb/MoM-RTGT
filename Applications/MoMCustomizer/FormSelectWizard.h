#ifndef FORMSELECTWIZARD_H
#define FORMSELECTWIZARD_H

#include <QWidget>

namespace Ui {
class FormSelectWizard;
}

class FormSelectWizard : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormSelectWizard(QWidget *parent = 0);
    ~FormSelectWizard();
    
private slots:
    void on_pushButton_Custom_clicked();

signals:
    void signal_accepted();

private:
    Ui::FormSelectWizard *ui;
};

#endif // FORMSELECTWIZARD_H
