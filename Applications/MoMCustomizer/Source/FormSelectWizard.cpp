#include "FormSelectWizard.h"
#include "ui_FormSelectWizard.h"

#include <QMoMResources.h>

FormSelectWizard::FormSelectWizard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSelectWizard)
{
    ui->setupUi(this);

    QFont font = MoM::QMoMResources::g_Font;
    font.setBold(true);
    font.setPixelSize(20);
    ui->pushButton_Custom->setFont(font);
    ui->pushButton_Custom->setText("Custom");
}

FormSelectWizard::~FormSelectWizard()
{
    delete ui;
}

void FormSelectWizard::on_pushButton_Custom_clicked()
{
    emit signal_accepted();
}
