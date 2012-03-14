#ifndef DIALOGOVERLANDMAP_H
#define DIALOGOVERLANDMAP_H

#include <QDialog>

class QGraphicsScene;

namespace Ui {
    class DialogOverlandMap;
}

namespace MoM {
    class MoMGameBase;
}

class DialogOverlandMap : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOverlandMap(QWidget *parent = 0);
    ~DialogOverlandMap();

private:
    MoM::MoMGameBase* getGame();

    QGraphicsScene* m_sceneArcanus;
    QGraphicsScene* m_sceneMyrror;

    Ui::DialogOverlandMap *ui;

private slots:
    void on_comboBox_Plane_currentIndexChanged(int index);
};

#endif // DIALOGOVERLANDMAP_H
