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

DialogAddUnit::DialogAddUnit(QWidget *parent) :
    QDialog(parent),
	m_game(),
    m_unit(new MoM::MoMUnit),
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
    m_sceneUnit->setSceneRect(0, 0, rectf.width()-8, rectf.height());
    ui->graphicsView_Unit->setSceneRect(-8, 0, rectf.width(), rectf.height());


    // Use a pixmap as reference for coordinate positions
    QPixmap pixmapSword(":/images/sword_normal.gif");
    m_lineHeight = pixmapSword.height() * 4 / 3;
    QPixmap pixmapPicture(":/units/Healer.gif");
    m_labelWidth = pixmapPicture.width() * 4 / 3;
    m_pictureHeight = pixmapPicture.height() * 4 / 3;


    ui->graphicsView_Unit->setScene(m_sceneUnit);


    QObject::connect(MainWindow::getInstance(), SIGNAL(signal_gameChanged(QMoMGamePtr)), this, SLOT(slot_gameChanged(QMoMGamePtr)));
	QObject::connect(MainWindow::getInstance(), SIGNAL(signal_gameUpdated()), this, SLOT(slot_gameUpdated()));

	slot_gameChanged(MainWindow::getInstance()->getGame());
}

DialogAddUnit::~DialogAddUnit()
{
    delete ui;
    delete m_sceneUnit;
}

QGraphicsSimpleTextItem* DialogAddUnit::addText(const QPointF& pos, const QString& text, bool fixed, const QString& helpText)
{
    QGraphicsSimpleTextItem* textItem = m_sceneUnit->addSimpleText(text, m_font);
    if (!fixed)
    {
        m_unitSpecificItems.push_back(textItem);
    }
    textItem->setToolTip(helpText);
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

void DialogAddUnit::displayLevel(QPointF &pos, const std::string& levelName, int level, int experience)
{
    QGraphicsItem* item = 0;

    QPixmap pixmap(":/images/Level " + QString("%0").arg(level) + ".gif");
    item = m_sceneUnit->addPixmap(pixmap);
    m_unitSpecificItems.push_back(item);
    item->setPos(pos);

    QString text = QString("Level %0 (%1 ep)").arg(level).arg(experience);
    if (!levelName.empty())
    {
        text = QString("%0 (level %1 / %2 ep)").arg(levelName.c_str()).arg(level).arg(experience);
    }
    item = addText(pos + QPointF(pixmap.width() * 4 / 3, 0), text);

    pos.ry() += MoM::Max(pixmap.height() + 2, 34);
}

void DialogAddUnit::displaySpecial(QPointF& pos, const QString& specialName, int specialValue, const QString& pixmapDir, const QString& helpText)
{
  QGraphicsItem* item = 0;

  QPixmap pixmap(pixmapDir + specialName + ".gif");
  item = m_sceneUnit->addPixmap(pixmap);
  item->setToolTip(helpText);
  m_unitSpecificItems.push_back(item);
  item->setPos(pos);

  QString text = specialName;
  if (specialValue != 0)
  {
      text += " " + QString("%0").arg(specialValue);
  }
  item = addText(pos + QPointF(pixmap.width() * 4 / 3, 0), text);
  item->setToolTip(helpText);

  pos.rx() += ui->graphicsView_Unit->width() / 2;
  if (pos.rx() > ui->graphicsView_Unit->width() * 3 / 4)
  {
      pos.setX(0);
      pos.ry() += MoM::Max(pixmap.height() + 2, 34);
  }
}

void DialogAddUnit::displayStrength(QPointF& pos, int strength, int bonusStrength, const QString& imageBaseName, const QString& helpText)
{
  // calculate number of normal, lost_normal, gold, and lost_gold icons
  int normal = strength - bonusStrength, lost_normal = 0, gold = bonusStrength, lost_gold = 0;
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
     item->setToolTip(helpText);
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
         item->setToolTip(helpText);
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
        QMoMIconPtr icon = MoM::QMoMResources::instance().getIcon(unitTypeNr);

        ui->comboBox_Unit->addItem(*icon, title);
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

    if (0 == m_game)
        return;

    // Add new items

    QGraphicsSimpleTextItem* textItem = 0;
    QPointF pos(0, m_pictureHeight);
    bool fixedText = false;

    pos = QPoint(m_labelWidth, m_pictureHeight - 4 * MoM::QMoMResources::g_FontSmall.pointSize());
    textItem = addText(pos, "Figures", fixedText);
    textItem->setFont(MoM::QMoMResources::g_FontSmall);
    pos.ry() += MoM::QMoMResources::g_FontSmall.pointSize();
    textItem = addText(pos, "Moves", fixedText, m_game->getHelpText(MoM::HELP_MOVES).c_str());
    textItem->setFont(MoM::QMoMResources::g_FontSmall);
    pos.ry() += MoM::QMoMResources::g_FontSmall.pointSize();
    textItem = addText(pos, "Upkeep", fixedText, m_game->getHelpText(MoM::HELP_1_UPKEEP).c_str());
    textItem->setFont(MoM::QMoMResources::g_FontSmall);
    pos.ry() += MoM::QMoMResources::g_FontSmall.pointSize();

    pos = QPoint(0, m_pictureHeight);
    textItem = addText(pos, "Melee", fixedText, m_game->getHelpText(MoM::HELP_MELEE).c_str());
    pos.ry() += m_lineHeight;
    textItem = addText(pos, "Range", fixedText, m_game->getHelpText(MoM::HELP_RANGE_1).c_str() + QString("\nRANGED TYPE: ") + prettyQStr(m_unit->getRangedType()));
    pos.ry() += m_lineHeight;
    textItem = addText(pos, "Armor", fixedText, m_game->getHelpText(MoM::HELP_UNITVIEW_ARMOR).c_str());
    pos.ry() += m_lineHeight;
    textItem = addText(pos, "Resist", fixedText, m_game->getHelpText(MoM::HELP_UNITVIEW_RESISTANCE).c_str());
    pos.ry() += m_lineHeight;
    textItem = addText(pos, "Hits", fixedText, m_game->getHelpText(MoM::HELP_UNITVIEW_HITS).c_str());
    pos.ry() += m_lineHeight;


    MoM::MoMUnit::BaseAttributes actualAttr = m_unit->getActualAttributes();
    MoM::MoMUnit::BaseAttributes bonusAttr = m_unit->getBonusAttributes();

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

    if (actualAttr.melee && actualAttr.toHitMelee)
    {
       displayToHit(pos, actualAttr.toHitMelee, "To Hit Melee");
    }
    else
    {
        pos.ry() += 10;
    }
    if (actualAttr.ranged && actualAttr.toHitRanged)
    {
        displayToHit(pos, actualAttr.toHitRanged, "To Hit Ranged");
    }
    else
    {
        pos.ry() += 10;
    }
    if (actualAttr.defense && actualAttr.toDefend)
    {
        displayToHit(pos, actualAttr.toDefend, "To Defend");
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

    displayStrength(pos, actualAttr.melee, bonusAttr.melee, imageBaseName, prettyQStr(m_unit->getWeaponType()));

    switch (m_unit->getRangedType())
    {
    case MoM::RANGED_Rock:           imageBaseName = "rock"; break;
    case MoM::RANGED_Arrow:          imageBaseName = "bow"; break;
    case MoM::RANGED_Bullet:         imageBaseName = "rock"; break;
    case MoM::RANGED_Thrown_Weapons: imageBaseName = "thrown"; break;
    default:                         imageBaseName = "fireball"; break;
    }

    if (m_unit->hasMagicalBreathAttack() || m_unit->hasMagicalGazeAttack())
    {
        displayStrength(pos, 0, 0, imageBaseName, prettyQStr(m_unit->getRangedType()));
    }
    else
    {
        displayStrength(pos, actualAttr.ranged, bonusAttr.ranged, imageBaseName, prettyQStr(m_unit->getRangedType()));
    }

    displayStrength(pos, actualAttr.defense, bonusAttr.defense, "shield", m_game->getHelpText(MoM::HELP_UNITVIEW_ARMOR).c_str());
    displayStrength(pos, actualAttr.resistance, bonusAttr.resistance, "resistance", m_game->getHelpText(MoM::HELP_UNITVIEW_RESISTANCE).c_str());
    displayStrength(pos,actualAttr.hitpoints, bonusAttr.hitpoints, "heart", m_game->getHelpText(MoM::HELP_UNITVIEW_HITS).c_str());

    pos.rx() = 0;
    pos.ry() += m_lineHeight;

    // Level/XP
    if (0 != m_unit->getLevel())
    {
        displayLevel(pos, m_unit->getLevelName(), m_unit->getLevel(), m_unit->getXP());
    }

    // Items
    for (int slotNr = 0; MoM::toUInt(slotNr) < MoM::gMAX_ITEMSLOTS; ++slotNr)
    {
        displayItem(pos, m_unit->getSlotType(slotNr), m_unit->getSlotItem(slotNr));
    }

    // Abilities, item effects, and spell effects
    MOM_FOREACH(eItemPower, itemPower, eItemPower_MAX)
    {
        if (m_unit->hasSpecial(itemPower))
        {
            QString specialName = prettyQStr(itemPower);
            displaySpecial(pos, specialName, 0, ":/abilities/", m_game->getHelpText(itemPower).c_str());  // TODO: Lookup images for item effects
        }
    }
    MOM_FOREACH(eHeroAbility, heroAbility, eHeroAbility_MAX)
    {
        if (m_unit->hasSpecial(heroAbility))
        {
            QString specialName = prettyQStr(heroAbility);
            displaySpecial(pos, specialName, m_unit->getSpecial(heroAbility), ":/abilities/", m_game->getHelpText(heroAbility).c_str());    // TODO: Lookup images
        }
    }
    MOM_FOREACH(eUnitAbility, unitAbility, eUnitAbility_MAX)
    {
        if (m_unit->hasSpecial(unitAbility))
        {
            QString specialName = prettyQStr(unitAbility);
            displaySpecial(pos, specialName, m_unit->getSpecial(unitAbility), ":/abilities/", m_game->getHelpText(unitAbility).c_str());    // TODO: Lookup images
        }
    }
    MOM_FOREACH(eUnitMutation, unitMutation, eUnitMutation_MAX)
    {
        if (m_unit->hasSpecial(unitMutation))
        {
            QString specialName = prettyQStr(unitMutation);
            displaySpecial(pos, specialName, 0, ":/abilities/", m_game->getHelpText(unitMutation).c_str());    // TODO: Lookup images
        }
    }
    MOM_FOREACH(eUnitEnchantment, unitEnchantment, eUnitEnchantment_MAX)
    {
        if (m_unit->hasSpecial(unitEnchantment))
        {
            QString specialName = prettyQStr(unitEnchantment);
            displaySpecial(pos, specialName, 0, ":/spells/", m_game->getHelpText(unitEnchantment).c_str());    // TODO: Lookup images
        }
    }
    // TODO: Handle specials below separately and eliminate this code
    MoM::MoMUnit::MapSpecials mapAbilityEffects(m_unit->getAbilityEffects());
    if (m_unit->hasMagicalBreathAttack() || m_unit->hasMagicalGazeAttack())
    {
        mapAbilityEffects[MoM::prettyEnumStr(toStr(m_unit->getRangedType()))] = actualAttr.ranged;
    }
    for (MoM::MoMUnit::MapSpecials::const_iterator it = mapAbilityEffects.begin(); it != mapAbilityEffects.end(); ++it)
    {
        QString specialName(it->first.c_str());
        displaySpecial(pos, specialName, it->second, ":/abilities/");
    }

}
