#include "DialogSelectRaces.h"
#include "ui_DialogSelectRaces.h"

#include <QMessageBox>

#include "MoMController.h"
#include "MoMGenerated.h"
#include "MoMUtility.h"
#include "QMoMResources.h"
#include "QMoMUtility.h"

using namespace MoM;

DialogSelectRaces::DialogSelectRaces(QWidget *parent) :
    QMoMDialogBase(parent),
    ui(new Ui::DialogSelectRaces)
{
    ui->setupUi(this);
    postInitialize();
}

DialogSelectRaces::~DialogSelectRaces()
{
    preFinalize();
    delete ui;
}

void DialogSelectRaces::on_pushButton_ReplaceDominantRace_clicked()
{
    eRace  race  = (eRace)ui->comboBox_Race->currentIndex();
    ePlane plane = (ePlane)ui->comboBox_Plane->currentIndex();

    MoMController momController(m_game.data());
    if (!momController.replaceDominantRace(plane, race))
    {
        (void)QMessageBox::warning(this,
                                   tr("Select Races"),
                                   tr("Failed to replace race: %1").arg(momController.errorString().c_str()));
    }
    else
    {
        (void)QMessageBox::information(this,
                                       tr("Select Races"),
                                       tr("Replaced race"));
    }
}

void DialogSelectRaces::slot_gameChanged(const QMoMGamePtr &game)
{
    m_game = game;
    ui->comboBox_Race->clear();
    MOM_FOREACH(eRace, race, eRace_MAX)
    {
        ui->comboBox_Race->addItem(*QMoMResources::instance().getIcon(race, 2), prettyQStr(race));
    }
    ui->comboBox_Plane->clear();
    MOM_FOREACH(ePlane, plane, ePlane_MAX)
    {
        ui->comboBox_Plane->addItem(*QMoMResources::instance().getIcon(plane, 2), prettyQStr(plane));
    }
}

void DialogSelectRaces::slot_gameUpdated()
{
}

