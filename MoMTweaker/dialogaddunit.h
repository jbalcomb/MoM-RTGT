#ifndef DIALOGADDUNIT_H
#define DIALOGADDUNIT_H

#include <QDialog>
#include <QSharedPointer>

#include <MoMTemplate.h>

class QAbstractButton;
class QGraphicsItem;
class QGraphicsScene;
class QGraphicsSimpleTextItem;
class UnitModel;

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
    explicit DialogAddUnit(QWidget *parent, UnitModel* unitModel);
    ~DialogAddUnit();
    
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_comboBox_Unit_currentIndexChanged(int index);
	void slot_gameChanged(MoM::MoMGameBase* game);
	void slot_gameUpdated();
    void slot_unitChanged(const QSharedPointer<MoM::MoMUnit>& unit);

private:
    QGraphicsSimpleTextItem* addText(const QPointF& pos, const QString& text, bool fixed = false);
	void displayItem(QPointF &pos, MoM::eSlot_Type16 slotType, const MoM::Item* momItem);
    void displayLevel(QPointF& pos, int level, int experience);
    void displaySpecial(QPointF& pos, const QString& specialName, int specialValue, const QString& pixmapDir);
    void displayStrength(QPointF& pos, int strength, int bonusStrength, const QString& imageBaseName);
    void displayToHit(QPointF& pos, int toHit, const QString& labelText);
	void update();

	// CONFIG
    MoM::MoMGameBase* m_game;
    QSharedPointer<MoM::MoMUnit> m_unit;
    UnitModel* m_unitModel;

	// STATUS
    bool m_updating;
    QFont m_font;
    int m_labelWidth;
    int m_lineHeight;
    int m_pictureHeight;
    QVector<QGraphicsItem*> m_unitSpecificItems;
    QGraphicsScene* m_sceneUnit;
    Ui::DialogAddUnit *ui;
};

#endif // DIALOGADDUNIT_H
