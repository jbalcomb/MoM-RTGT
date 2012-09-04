#include "MoMTemplate.h"
#include "mainwindow.h"

#include "dialogexternalai.h"
#include "ui_dialogexternalai.h"

DialogExternalAI::DialogExternalAI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogExternalAI),
    m_game(),
    hookManager(0)
{
    ui->setupUi(this);

    // TODO: Checks + life cycle management of the game and the process
    m_game = MainWindow::getInstance()->getGame();
    hookManager = new MoM::MoMHookManager(m_game.data());
}

DialogExternalAI::~DialogExternalAI()
{
    delete hookManager;

    delete ui;
}

void DialogExternalAI::on_pushButton_InsertHook_clicked()
{
    hookManager->insertHook();
}

void DialogExternalAI::on_pushButton_RaiseHook_clicked()
{
    hookManager->raiseHook();
}

void DialogExternalAI::on_pushButton_WaitForHook_clicked()
{
    hookManager->waitForBait(2.0);
    m_game->readData();
    int battleUnitNr = (int16_t)m_game->getDataSegment()->m_BattleUnit_on_move;
    MoM::Battle_Unit* battleUnit = m_game->getBattleUnit(battleUnitNr);

    ui->lineEdit_BattleUnitNr->setText(QString("%0").arg(battleUnitNr));
    ui->lineEdit_TargetBattleUnitNr->setText(QString("%0").arg((int)battleUnit->m_Target_BattleUnitID));
    ui->lineEdit_Tactic->setText(QString("%0").arg((int)battleUnit->m_Status));
}

void DialogExternalAI::on_pushButton_RetractHook_clicked()
{
    hookManager->retractHook();
}

void DialogExternalAI::on_pushButton_ReleaseHook_clicked()
{
    int battleUnitNr = (int16_t)m_game->getDataSegment()->m_BattleUnit_on_move;
    MoM::Battle_Unit* battleUnit = m_game->getBattleUnit(battleUnitNr);

    battleUnit->m_Target_BattleUnitID = ui->lineEdit_TargetBattleUnitNr->text().toInt();
    battleUnit->m_Status = (MoM::eUnit_Status16)ui->lineEdit_Tactic->text().toInt();
    m_game->commitData(battleUnit, sizeof(*battleUnit));

    MainWindow::getInstance()->on_pushButton_Reread_clicked();

    hookManager->releaseBait();

    on_pushButton_WaitForHook_clicked();
}
