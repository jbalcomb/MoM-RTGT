#ifndef DIALOGADDUNIT_H
#define DIALOGADDUNIT_H

#include <QDialog>

class QAbstractButton;
class QGraphicsItem;
class QGraphicsScene;
class QGraphicsSimpleTextItem;

namespace Ui {
class DialogAddUnit;
}

namespace MoM {
    class MoMGameBase;
    class MoMUnit;
}

class DialogAddUnit : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogAddUnit(QWidget *parent = 0);
    ~DialogAddUnit();
    
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_comboBox_Unit_currentIndexChanged(int index);
	void slot_gameChanged(MoM::MoMGameBase* game);
	void slot_gameUpdated();

private:
    QGraphicsSimpleTextItem* addText(const QPointF& pos, const QString& text, bool fixed = false);
    void displaySpecial(QPointF& pos, const QString& specialName, int specialValue);
    void displayStrength(QPointF& pos, int strength, const QString& imageBaseName);
    void displayToHit(QPointF& pos, int toHit, const QString& labelText);
	void update();

	// CONFIG

	// STATUS
	MoM::MoMGameBase* m_game;
	std::auto_ptr<MoM::MoMUnit> m_unit;

    QFont m_font;
    int m_labelWidth;
    int m_lineHeight;
    int m_pictureHeight;
    QVector<QGraphicsItem*> m_unitSpecificItems;
    QGraphicsScene* m_sceneUnit;
    Ui::DialogAddUnit *ui;
};

#endif // DIALOGADDUNIT_H
