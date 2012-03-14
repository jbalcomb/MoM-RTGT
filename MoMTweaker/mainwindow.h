// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QTreeWidget>

#include <MoMGameBase.h>

#include "unitmodel.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addUnit(MoM::eUnit_Type unitType);
    void applyBuildQueues();
    bool commitMemory();
    bool refreshMemory();
    void update();

	static MainWindow* getInstance()
	{
		return m_instance;
	}

    MoM::MoMGameBase* getGame()
    {
        return m_game.get();
    }

private:
    QTreeWidgetItem* addTreeFeature(QTreeWidgetItem* parent, 
        const QString& feature, const QIcon& featureIcon, 
        const QString& value, const QIcon& valueIcon, 
        const QString& comment = "");

private:
    Ui::MainWindow *ui;

	static MainWindow* m_instance;

    QTimer* m_timer;

    UnitModel m_UnitModel;

    QFileDialog m_filedialogLoadGame;
    QFileDialog m_filedialogSaveGame;

    std::auto_ptr<MoM::MoMGameBase> m_game;

private slots:
    void on_pushButton_Calculator_clicked();
    void on_pushButton_Connect_clicked();
    void on_pushButton_Load_clicked();
    void on_pushButton_Map_clicked();
    void on_pushButton_Reread_clicked();
    void on_pushButton_Save_clicked();
    void on_pushButton_ShowTables_clicked();
    void on_pushButton_Tools_clicked();

    void onTimer();
};

#endif // MAINWINDOW_H
