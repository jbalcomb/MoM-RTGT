#ifndef DIALOGADDARTIFACT_H
#define DIALOGADDARTIFACT_H

#include <QDialog>

namespace Ui {
class DialogAddArtifact;
}

#include "QMoMSharedPointers.h"

class DialogAddArtifact : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogAddArtifact(QWidget *parent = 0);
    ~DialogAddArtifact();
    
public slots:
    void slot_gameChanged(const QMoMGamePtr& game);
    void slot_gameUpdated();

private slots:
    void on_pushButton_AddArtifact_clicked();

private:
    QMoMGamePtr m_game;

    Ui::DialogAddArtifact *ui;
};

#endif // DIALOGADDARTIFACT_H
