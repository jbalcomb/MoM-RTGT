// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2012-03-12
// ---------------------------------------------------------------------------

#include <qgraphicsitem.h>
#include <qgraphicsscene.h>

#include "dialogaddunit.h"
#include "ui_dialogaddunit.h"

#include <MoMGenerated.h>
#include <MoMUnit.h>
#include <MoMUtility.h>
#include "QMoMResources.h"
#include "QMoMSharedPointers.h"

#include "mainwindow.h"

DialogAddUnit::DialogAddUnit(QWidget *parent, UnitModel* unitModel) :
    QDialog(parent),
	m_game(),
    m_unit(new MoM::MoMUnit),
    m_unitModel(unitModel),
    m_updating(false),
    m_labelWidth(),
    m_lineHeight(),
    m_pictureHeight(),
    m_unitSpecificItems(),
    m_sceneUnit(new QGraphicsScene),
    ui(new Ui::DialogAddUnit)
{
    ui->setupUi(this);

    setFont(MoM::QMoMResources::g_Font);
    m_font = MoM::QMoMResources::g_Font;
    m_font.setPointSize(16);
    setAttribute(Qt::WA_DeleteOnClose);

    // Initalize graphics view with items that are fixed
    QRectF rectf = ui->graphicsView_Unit->rect();
    m_sceneUnit->setSceneRect(0, 0, rectf.width(), rectf.height());
    ui->graphicsView_Unit->setSceneRect(0, 0, rectf.width(), rectf.height());


    // Use a pixmap as reference for coordinate positions
    QPixmap pixmapSword(":/images/sword_normal.gif");
    m_lineHeight = pixmapSword.height() * 4 / 3;
    QPixmap pixmapPicture(":/units/Healer.gif");
    m_labelWidth = pixmapPicture.width() * 4 / 3;
    m_pictureHeight = pixmapPicture.height() * 4 / 3;


    QGraphicsSimpleTextItem* textItem = 0;
    QPointF pos(0, m_pictureHeight);
    bool fixedText = true;

    pos = QPoint(m_labelWidth, m_pictureHeight - 4 * MoM::QMoMResources::g_FontSmall.pointSize());
    textItem = addText(pos, "Figures", fixedText);
    textItem->setFont(MoM::QMoMResources::g_FontSmall);
    pos.ry() += MoM::QMoMResources::g_FontSmall.pointSize();
    textItem = addText(pos, "Moves", fixedText);
    textItem->setFont(MoM::QMoMResources::g_FontSmall);
    pos.ry() += MoM::QMoMResources::g_FontSmall.pointSize();
    textItem = addText(pos, "Upkeep", fixedText);
    textItem->setFont(MoM::QMoMResources::g_FontSmall);
    pos.ry() += MoM::QMoMResources::g_FontSmall.pointSize();

    pos = QPoint(0, m_pictureHeight);
    textItem = addText(pos, "Melee", fixedText);
    pos.ry() += m_lineHeight;
    textItem = addText(pos, "Range", fixedText);
    pos.ry() += m_lineHeight;
    textItem = addText(pos, "Armor", fixedText);
    pos.ry() += m_lineHeight;
    textItem = addText(pos, "Resist", fixedText);
    pos.ry() += m_lineHeight;
    textItem = addText(pos, "Hits", fixedText);
    pos.ry() += m_lineHeight;


    ui->graphicsView_Unit->setScene(m_sceneUnit);


    QObject::connect(MainWindow::getInstance(), SIGNAL(signal_gameChanged(QMoMGamePtr)), this, SLOT(slot_gameChanged(QMoMGamePtr)));
	QObject::connect(MainWindow::getInstance(), SIGNAL(signal_gameUpdated()), this, SLOT(slot_gameUpdated()));

    // Connect the item model UnitModel to the dialog
    QObject::connect(m_unitModel, SIGNAL(signal_unitChanged(QMoMUnitPtr)), this, SLOT(slot_unitChanged(QMoMUnitPtr)), Qt::QueuedConnection);

	slot_gameChanged(MainWindow::getInstance()->getGame());
}

DialogAddUnit::~DialogAddUnit()
{
    delete ui;
    delete m_sceneUnit;
}

QGraphicsSimpleTextItem* DialogAddUnit::addText(const QPointF& pos, const QString& text, bool fixed)
{
    QGraphicsSimpleTextItem* textItem = m_sceneUnit->addSimpleText(text, m_font);
    if (!fixed)
    {
        m_unitSpecificItems.push_back(textItem);
    }
    textItem->setBrush(QBrush(Qt::white));
    textItem->setPos(pos);
    return textItem;
}

void DialogAddUnit::displayItem(QPointF &pos, MoM::eSlot_Type16 slotType, const MoM::Item* momItem)
{
    if ((MoM::eSlot_Type16)0 == slotType)
        return;

    QPointF tmpPos = pos;
    QGraphicsItem* item = 0;

    // TODO: Slot type icon
	QString strSlotType = prettyQStr(slotType) + ":  ";
    item = addText(tmpPos, strSlotType);
    tmpPos.rx() += item->boundingRect().width();

	QPixmap pixmapItem;
	if (0 != momItem)
	{
		pixmapItem = MoM::QMoMResources::instance().getPixmap(momItem->m_Icon, 2);
		if (!pixmapItem.isNull())
		{
			QGraphicsItem* item = m_sceneUnit->addPixmap(pixmapItem);
			m_unitSpecificItems.push_back(item);
			item->setPos(tmpPos);
			tmpPos.rx() += pixmapItem.width() * 4 / 3;
		}

		QString text = QString("%0").arg(momItem->m_Item_Name);
		item = addText(tmpPos, text);
	}

    pos.ry() += MoM::Max(pixmapItem.height() + 2, 34);
}

void DialogAddUnit::displayLevel(QPointF &pos, int level, int experience)
{
    QGraphicsItem* item = 0;

    QPixmap pixmap(":/images/Level " + QString("%0").arg(level) + ".gif");
    item = m_sceneUnit->addPixmap(pixmap);
    m_unitSpecificItems.push_back(item);
    item->setPos(pos);

    QString text = QString("Level %0 (%1 ep)").arg(level).arg(experience);
    item = addText(pos + QPointF(pixmap.width() * 4 / 3, 0), text);

    pos.ry() += MoM::Max(pixmap.height() + 2, 34);
}

void DialogAddUnit::displaySpecial(QPointF& pos, const QString& specialName, int specialValue, const QString& pixmapDir)
{
  QGraphicsItem* item = 0;

  QPixmap pixmap(pixmapDir + specialName + ".gif");
  item = m_sceneUnit->addPixmap(pixmap);
  m_unitSpecificItems.push_back(item);
  item->setPos(pos);

  QString text = specialName;
  if (specialValue != 0)
  {
      text += " " + QString("%0").arg(specialValue);
  }
  item = addText(pos + QPointF(pixmap.width() * 4 / 3, 0), text);

  pos.rx() += ui->graphicsView_Unit->width() / 2;
  if (pos.rx() > ui->graphicsView_Unit->width() * 3 / 4)
  {
      pos.setX(0);
      pos.ry() += MoM::Max(pixmap.height() + 2, 34);
  }
}

void DialogAddUnit::displayStrength(QPointF& pos, int strength, int bonusStrength, const QString& imageBaseName)
{
  // calculate number of normal, lost_normal, gold, and lost_gold icons
  int normal = strength, lost_normal = 0, gold = bonusStrength, lost_gold = 0;
//      if (m_unit.bonuses[strength] >= m_unit.penalties[strength])
//      {
//         // Bonus at least as large as the penalty - only lost gold
//         normal = unit.fixedunit[strength];
//         lost_normal = 0;
//         gold = unit.bonuses[strength] - unit.penalties[strength];
//         lost_gold = unit.penalties[strength];
//      }
//      else if (unit.fixedunit[strength] + unit.bonuses[strength] >= unit.penalties[strength])
//      {
//         // More penalty than bonus, but the total is not negative - lost gold and lost normal
//         normal = unit[strength];
//         lost_normal = unit.penalties[strength] - unit.bonuses[strength];
//         gold = 0;
//         lost_gold = unit.bonuses[strength];
//      }
//      else
//      {
//         // More penalty than strength - truncate to zero with lost normal and lost gold
//         normal = 0;
//         lost_normal = unit.fixedunit[strength];
//         gold = 0;
//         lost_gold = unit.bonuses[strength];
//      }

  int left = pos.x();
  int x = left;
  int y = pos.y();
  int i, col = 0;
  QPixmap pixmap(":/images/" + imageBaseName + "_normal.gif");
  for (i = 0; i < normal; ++i, ++col)
  {
     if (col > 0 && col % 15 == 0)
     {
         left += pixmap.width() / 3;
         x = left;
         y += pixmap.width() / 3;
     }
     if (col > 0 && col % 5 == 0)
     {
         x += pixmap.width() / 5;
     }
     QGraphicsItem* item = m_sceneUnit->addPixmap(pixmap);
     m_unitSpecificItems.push_back(item);
     item->setPos(x, y);
     x += pixmap.width() + 1;
  }
//      for (i = 0; i < lost_normal; ++i, ++col)
//      {
//         if (col > 0 && col % 15 == 0) doc.writeln("<br />");
//         doc.write("<img ");
//         if (col > 0 && col % 5 == 0) doc.write(style_spacer);
//         doc.writeln("src=\"images/" + image + "_normal_lost.gif\" alt=\"n\">");
//      }
    pixmap = QPixmap(":/images/" + imageBaseName + "_gold.gif");
      for (i = 0; i < gold; ++i, ++col)
      {
         if (col > 0 && col % 15 == 0)
         {
             left += pixmap.width() / 3;
             x = left;
             y += pixmap.width() / 3;
         }
         if (col > 0 && col % 5 == 0)
         {
             x += pixmap.width() / 5;
         }
         QGraphicsItem* item = m_sceneUnit->addPixmap(pixmap);
         m_unitSpecificItems.push_back(item);
         item->setPos(x, y);
         x += pixmap.width() + 1;
      }
//      for (i = 0; i < lost_gold; ++i, ++col)
//      {
//         if (col > 0 && col % 15 == 0) doc.writeln("<br />");
//         doc.write("<img ");
//         if (col > 0 && col % 5 == 0) doc.write(style_spacer);
//         doc.writeln("src=\"images/" + image + "_gold_lost.gif\" alt=\"g\">");
//      }

  pos.ry() += m_lineHeight;
}

void DialogAddUnit::displayToHit(QPointF& pos, int toHit, const QString& labelText)
{
    QString textModifier = QString("%0").arg(toHit);
    if (toHit >= 0)
    {
        textModifier = QString("+%0").arg(toHit);
    }

  if (!labelText.isEmpty())
  {
      QGraphicsSimpleTextItem* textItem = addText(pos, textModifier + " " + labelText);
      textItem->setFont(MoM::QMoMResources::g_FontSmall);
  }

  pos.ry() += 10;
}

void DialogAddUnit::on_buttonBox_clicked(QAbstractButton *button)
{
    MainWindow* controller = MainWindow::getInstance();
    if (0 == controller)
        return;

    QDialogButtonBox::ButtonRole buttonRole = ui->buttonBox->buttonRole(button);
    if (QDialogButtonBox::ApplyRole == buttonRole)
    {
        MoM::eUnit_Type unitType = static_cast<MoM::eUnit_Type>(ui->comboBox_Unit->currentIndex() - 1);
        controller->addUnit(unitType);
    }
}

void DialogAddUnit::on_comboBox_Unit_currentIndexChanged(int index)
{
    // Do nothing if we are busy with an external update
    if (m_updating)
        return;

    m_unit->changeUnit(static_cast<MoM::eUnit_Type>(index - 1));
	update();
}

void DialogAddUnit::slot_gameChanged(const QMoMGamePtr& game)
{
    MoM::UpdateLock lock(m_updating);

    m_game = game;
	m_unit->setGame(m_game.data());

    // Reinitialize combo box with units

    // Save current unitType index
	int index = ui->comboBox_Unit->currentIndex();
    ui->comboBox_Unit->clear();

    ui->comboBox_Unit->addItem("");
    MOM_FOREACH(eUnit_Type, unitTypeNr, eUnit_Type_MAX)
    {
        QString title = prettyQStr(unitTypeNr);

        MoM::Unit_Type_Data* data = 0;
        if ((0 != game) && (0 != (data = game->getUnit_Type_Data(unitTypeNr))))
        {
            title = QString("%0").arg((int)unitTypeNr, 3) + "   " + QString(game->getRaceName(data->m_Race_Code).c_str()) + "   " + QString(game->getNameByOffset(data->m_PtrName));
        }
        QIcon icon = MoM::QMoMResources::instance().getIcon(unitTypeNr);

        ui->comboBox_Unit->addItem(icon, title);
	}

    // Restore current unitType index
    m_unit->changeUnit(static_cast<MoM::eUnit_Type>(index - 1));
    ui->comboBox_Unit->setCurrentIndex(index);

    update();
}

void DialogAddUnit::slot_gameUpdated()
{
    MoM::UpdateLock lock(m_updating);

    update();
}

void DialogAddUnit::slot_unitChanged(const QMoMUnitPtr& unit)
{
    MoM::UpdateLock lock(m_updating);

    m_unit = unit;
    MoM::eUnit_Type unitTypeNr = m_unit->getUnitTypeNr();
    ui->comboBox_Unit->setCurrentIndex(1 + toInt(unitTypeNr));

    update();
}

void DialogAddUnit::update()
{
    // Remove old items
    foreach(QGraphicsItem* item, m_unitSpecificItems)
    {
        m_sceneUnit->removeItem(item);
        delete item;
    }
    m_unitSpecificItems.clear();

    // Add new items

    const QMoMImagePtr pImage = MoM::QMoMResources::instance().getImage(m_unit->getUnitTypeNr());
    if (0 != pImage)
    {
        QImage image(*pImage);
        if (image.width() < 32)
        {
            image = image.scaled(image.size() * 2, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        }
        QPixmap pixmap;
        pixmap.convertFromImage(image);
        QGraphicsItem* item = m_sceneUnit->addPixmap(pixmap);
        m_unitSpecificItems.push_back(item);
        QPointF pos((m_labelWidth - pixmap.width()) / 2, (m_pictureHeight - pixmap.height()) / 2);
        item->setPos(pos);
    }

    QPointF pos;
    QGraphicsSimpleTextItem* textItem = 0;

    // Name
    pos = QPointF(m_labelWidth, 0);
    QFont fontName(MoM::QMoMResources::g_Font);
    fontName.setPointSize(20);
    if (m_unit->getHeroName().empty())
    {
        textItem = addText(pos, QString(m_unit->getDisplayName().c_str()));
        textItem->setFont(fontName);
    }
    else
    {
        textItem = addText(pos, QString(m_unit->getHeroName().c_str()));
        textItem->setFont(fontName);
        pos.ry() += fontName.pointSize();
        textItem = addText(pos, QString(m_unit->getDisplayName().c_str()));
        textItem->setFont(fontName);
    }

    // Figures, moves, upkeep
    pos = QPoint(m_labelWidth + m_labelWidth / 2, m_pictureHeight - 4 * MoM::QMoMResources::g_FontSmall.pointSize());
    textItem = addText(pos, QString("%0").arg(m_unit->getNrFigures()));
    textItem->setFont(MoM::QMoMResources::g_FontSmall);
    pos.ry() += MoM::QMoMResources::g_FontSmall.pointSize();
    textItem = addText(pos, QString("%0").arg(m_unit->getMoves(), 0, 'f', 1));
    textItem->setFont(MoM::QMoMResources::g_FontSmall);
    pos.ry() += MoM::QMoMResources::g_FontSmall.pointSize();
    textItem = addText(pos, QString("%0").arg(m_unit->getUpkeep()));
    textItem->setFont(MoM::QMoMResources::g_FontSmall);

    // To Hit
    pos = QPointF(ui->graphicsView_Unit->width() * 2 / 3, m_pictureHeight - 4 * MoM::QMoMResources::g_FontSmall.pointSize());
    QPixmap pixmap(":images/tohit.gif");
    QGraphicsItem* item = m_sceneUnit->addPixmap(pixmap);
    m_unitSpecificItems.push_back(item);
    item->setPos(pos);
    pos.rx() += pixmap.width() + 2;

    if (m_unit->getMelee() && m_unit->getToHitMelee())
    {
       displayToHit(pos, m_unit->getToHitMelee(), "To Hit Melee");
    }
    else
    {
        pos.ry() += 10;
    }
    if (m_unit->getRanged() && m_unit->getToHitRanged())
    {
        displayToHit(pos, m_unit->getToHitRanged(), "To Hit Ranged");
    }
    else
    {
        pos.ry() += 10;
    }
    if (m_unit->getArmor() && m_unit->getToDefend())
    {
        displayToHit(pos, m_unit->getToDefend(), "To Defend");
    }


    pos = QPointF(m_labelWidth, m_pictureHeight);

    // Basic attributes

    QString imageBaseName;
    switch (m_unit->getWeaponType())
    {
    default:
    case MoM::WEAPON_normal:        imageBaseName = "sword"; break;
    case MoM::WEAPON_magic:         imageBaseName = "sword_magic"; break;
    case MoM::WEAPON_mithril:       imageBaseName = "sword_mithril"; break;
    case MoM::WEAPON_adamantium:    imageBaseName = "sword_adamantium"; break;
    }

    displayStrength(pos, m_unit->getMelee(), m_unit->getBonusAttributes().melee, imageBaseName);

    switch (m_unit->getRangedType())
    {
    case MoM::RANGED_Rock:           imageBaseName = "rock"; break;
    case MoM::RANGED_Arrow:          imageBaseName = "bow"; break;
    case MoM::RANGED_Bullet:         imageBaseName = "rock"; break;
    case MoM::RANGED_Thrown_Weapons: imageBaseName = "thrown"; break;
    default:                         imageBaseName = "fireball"; break;
    }

    displayStrength(pos, m_unit->getRanged(), m_unit->getBonusAttributes().ranged, imageBaseName);

    displayStrength(pos, m_unit->getArmor(), m_unit->getBonusAttributes().defense, "shield");
    displayStrength(pos, m_unit->getResist(), m_unit->getBonusAttributes().resistance, "resistance");
    displayStrength(pos, m_unit->getHits(), m_unit->getBonusAttributes().hitpoints, "heart");

    pos.rx() = 0;
    pos.ry() += m_lineHeight;

    // Level/XP
    if (0 != m_unit->getLevel())
    {
        displayLevel(pos, m_unit->getLevel(), m_unit->getXP());
    }

    // Items
    for (int slotNr = 0; MoM::toUInt(slotNr) < MoM::gMAX_ITEMSLOTS; ++slotNr)
    {
        displayItem(pos, m_unit->getSlotType(slotNr), m_unit->getSlotItem(slotNr));
    }

    // Abilities, item effects, and spell effects
    MoM::MoMUnit::MapSpecials mapAbilityEffects(m_unit->getAbilityEffects());
    MoM::MoMUnit::MapSpecials mapItemEffects(m_unit->getItemEffects());
    MoM::MoMUnit::MapSpecials mapSpellEffects(m_unit->getSpellEffects());
    for (MoM::MoMUnit::MapSpecials::const_iterator it = mapAbilityEffects.begin(); it != mapAbilityEffects.end(); ++it)
    {
        QString specialName(it->first.c_str());
        displaySpecial(pos, specialName, it->second, ":/abilities/");
    }
    for (MoM::MoMUnit::MapSpecials::const_iterator it = mapItemEffects.begin(); it != mapItemEffects.end(); ++it)
    {
        QString specialName(it->first.c_str());
        displaySpecial(pos, specialName, it->second, ":/abilities/");  // TODO: Separate images for item effects
    }
    for (MoM::MoMUnit::MapSpecials::const_iterator it = mapSpellEffects.begin(); it != mapSpellEffects.end(); ++it)
    {
        QString specialName(it->first.c_str());
        displaySpecial(pos, specialName, it->second, ":/spells/");
    }

}
