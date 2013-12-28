#include "DialogAddArtifact.h"
#include "ui_DialogAddArtifact.h"

#include <QMessageBox>

#include "MoMController.h"
#include "QMoMResources.h"

using namespace MoM;

DialogAddArtifact::DialogAddArtifact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddArtifact)
{
    ui->setupUi(this);
}

DialogAddArtifact::~DialogAddArtifact()
{
    delete ui;
}

void DialogAddArtifact::slot_gameChanged(const QMoMGamePtr &game)
{
    m_game = game;
    ui->comboBox_Artifacts->clear();
    for (int artifactNr = 0; artifactNr < gMAX_ARTIFACTS_IN_GAME; ++artifactNr)
    {
        ItemDataLbx* artifact = m_game->getItemDataLbx(artifactNr);
        if (0 == artifact)
            break;
        const uint8_t* artifactsInGame = m_game->getArtifacts_in_game();
        bool inGame = false;
        if (0 != artifactsInGame)
        {
            inGame = artifactsInGame[artifactNr];
        }
        QString text = QString("%0 - %1 - %2").arg(artifactNr, 3).arg(inGame).arg(artifact->m_Item.m_Item_Name);
        ui->comboBox_Artifacts->addItem(*QMoMResources::instance().getIcon(artifact->m_Item.m_Icon), text);
    }
}

void DialogAddArtifact::slot_gameUpdated()
{
}

void DialogAddArtifact::on_pushButton_AddArtifact_clicked()
{
    MoMController momController(m_game.data());
    int artifactNr = ui->comboBox_Artifacts->currentIndex();
    bool ok = momController.addArtifact(PLAYER_YOU, artifactNr);
    if (!ok)
    {
        (void)QMessageBox::warning(this,
            tr("Conjure artifact"),
            tr("Failed to conjure artifact: %1").arg(momController.errorString().c_str()));
    }
    else
    {
        (void)QMessageBox::information(this,
            tr("Summon"),
            tr("Conjured artifact to your fortress"));
    }
}
