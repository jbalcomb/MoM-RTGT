#include "DialogWizard.h"
#include "ui_DialogWizard.h"

#include <QDebug>
#include <QKeyEvent>

#include <QMoMResources.h>
#include "FormGameOptions.h"
#include "FormSelectWizard.h"
#include "FormWizardsName.h"
#include "FormMagicPickScreen.h"
#include "FormSelectSpells.h"
#include "FormSelectRaces.h"
#include "FormSelectBanner.h"


DialogWizard::DialogWizard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogWizard),
    m_form()
{
    ui->setupUi(this);

    // Display first form
    slot_selectGameOptions();

    // Start MoM process
    qDebug() << "Start MoM process";
//    bool ok = momProcess.createProcess(
//                "C:\\Program Files (x86)\\DOSBox-0.74\\DOSBox.exe",
//                "-conf C:\\games\\MAGIC\\dosbox.conf MAGIC.EXE -noconsole",
//                "C:\\games\\MAGIC-work");
    bool ok = momProcess.createProcess(
                "C:\\Program Files (x86)\\DOSBox-0.74\\DOSBox.exe",
                "\"C:\\Program Files (x86)\\DOSBox-0.74\\DOSBox.exe\""
                    " -conf C:\\games\\MAGIC-work\\MC_dosbox.conf"      // Execute dosbox.conf
                    " -noconsole",                                      // No console (in Windows)
                "C:\\games\\MAGIC-work");
    qDebug() << "createProcess() -> " << ok;
}

DialogWizard::~DialogWizard()
{
    bool ok = momProcess.terminateProcess();
    qDebug() << "terminateProcess() -> " << ok;

    delete ui;
}

void DialogWizard::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Escape)
    {
        // Previous form
        qDebug() << "Key_Escape";
        emit signal_rejected();
    }
    else if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        // Next form
        qDebug() << "Key_Enter";
        emit signal_accepted();
    }
    else
    {
        QDialog::keyPressEvent(event);
    }
}

void DialogWizard::slot_selectGameOptions()
{
    delete m_form;
    disconnect(SIGNAL(signal_rejected()));
    disconnect(SIGNAL(signal_accepted()));

    FormGameOptions* form = new FormGameOptions(this);
    QObject::connect(this, SIGNAL(signal_rejected()), this, SLOT(slot_rejected()));
    QObject::connect(form, SIGNAL(signal_rejected()), this, SLOT(slot_rejected()));
    QObject::connect(this, SIGNAL(signal_accepted()), this, SLOT(slot_selectWizard()));
    QObject::connect(form, SIGNAL(signal_accepted()), this, SLOT(slot_selectWizard()));
    form->show();
    m_form = form;
}

void DialogWizard::slot_selectWizard()
{
    delete m_form;
    disconnect(SIGNAL(signal_rejected()));
    disconnect(SIGNAL(signal_accepted()));

    FormSelectWizard* form = new FormSelectWizard(this);
    QObject::connect(this, SIGNAL(signal_rejected()), this, SLOT(slot_selectGameOptions()));
    QObject::connect(this, SIGNAL(signal_accepted()), this, SLOT(slot_selectName()));
    QObject::connect(form, SIGNAL(signal_accepted()), this, SLOT(slot_selectName()));
    form->show();
    m_form = form;
}

void DialogWizard::slot_selectName()
{
    delete m_form;
    disconnect(SIGNAL(signal_rejected()));
    disconnect(SIGNAL(signal_accepted()));

    FormWizardsName* form = new FormWizardsName(this);
    QObject::connect(this, SIGNAL(signal_rejected()), this, SLOT(slot_selectWizard()));
    QObject::connect(this, SIGNAL(signal_accepted()), this, SLOT(slot_selectMagicPicks()));
    form->show();
    m_form = form;
}

void DialogWizard::slot_selectMagicPicks()
{
    delete m_form;
    disconnect(SIGNAL(signal_rejected()));
    disconnect(SIGNAL(signal_accepted()));

    FormMagicPickScreen* form = new FormMagicPickScreen(this);
    QObject::connect(this, SIGNAL(signal_rejected()), this, SLOT(slot_selectName()));
    QObject::connect(form, SIGNAL(signal_accepted()), this, SLOT(slot_selectSpells()));
    form->show();
    m_form = form;
}

void DialogWizard::slot_selectSpells()
{
    delete m_form;
    disconnect(SIGNAL(signal_rejected()));
    disconnect(SIGNAL(signal_accepted()));

    FormSelectSpells* form = new FormSelectSpells(this);
    QObject::connect(this, SIGNAL(signal_rejected()), this, SLOT(slot_selectMagicPicks()));
    QObject::connect(form, SIGNAL(signal_accepted()), this, SLOT(slot_selectRaces()));
    form->show();
    m_form = form;
}

void DialogWizard::slot_selectRaces()
{
    delete m_form;
    disconnect(SIGNAL(signal_rejected()));
    disconnect(SIGNAL(signal_accepted()));

    FormSelectRaces* form = new FormSelectRaces(this);
    QObject::connect(this, SIGNAL(signal_rejected()), this, SLOT(slot_selectSpells()));
    QObject::connect(this, SIGNAL(signal_accepted()), this, SLOT(slot_selectBanner()));
    form->show();
    m_form = form;
}

void DialogWizard::slot_selectBanner()
{
    delete m_form;
    disconnect(SIGNAL(signal_rejected()));
    disconnect(SIGNAL(signal_accepted()));

    FormSelectBanner* form = new FormSelectBanner(this);
    QObject::connect(this, SIGNAL(signal_rejected()), this, SLOT(slot_selectRaces()));
    QObject::connect(this, SIGNAL(signal_accepted()), this, SLOT(slot_accepted()));
    form->show();
    m_form = form;
}

void DialogWizard::slot_accepted()
{
    delete m_form;
    disconnect(SIGNAL(signal_rejected()));
    disconnect(SIGNAL(signal_accepted()));

    qDebug() << "accepted";
    qDebug() << "Execute world generation ... (TODO)";
    qDebug() << "Start WIZARDS.EXE ... (TODO)";
    close();
}

void DialogWizard::slot_rejected()
{
    delete m_form;
    disconnect(SIGNAL(signal_rejected()));
    disconnect(SIGNAL(signal_accepted()));

    qDebug() << "rejected";
    close();
}
