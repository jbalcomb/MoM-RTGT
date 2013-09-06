#include "FormGameOptions.h"
#include "ui_FormGameOptions.h"

FormGameOptions::FormGameOptions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormGameOptions)
{
    ui->setupUi(this);
}

FormGameOptions::~FormGameOptions()
{
    delete ui;
}

void FormGameOptions::on_pushButton_OK_clicked()
{
    emit signal_accepted();
}
