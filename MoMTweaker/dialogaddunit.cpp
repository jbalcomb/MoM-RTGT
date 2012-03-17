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
#include <MoMutility.h>
#include "QMoMResources.h"

#include "mainwindow.h"

DialogAddUnit::DialogAddUnit(QWidget *parent) :
    QDialog(parent),
    m_unit(),
    m_labelWidth(),
    m_lineHeight(),
    m_pictureHeight(),
    m_unitSpecificItems(),
    m_sceneUnit(new QGraphicsScene),
    ui(new Ui::DialogAddUnit)
{
    ui->setupUi(this);

    // Note: attribute italic=true is required for URW Chancery L
    m_font = QFont("URW Chancery L", 12, -1, true);
    m_unit = new MoM::MoMUnit;
    m_unit->setGame(getGame());

    // Initialize combo box with units

    // Note: clearing the combo box triggers a signal currentIndexChanged.
    ui->comboBox_Unit->clear();

    MoM::MoMGameBase* game = getGame();
    MoM::Unit_Type_Data* unitTypes = 0;
    int ndata = 0;

    if (0 != game)
    {
        unitTypes = game->getUnit_Types();
    }
    if (0 != unitTypes)
    {
        ndata = (int)MoM::eUnit_Type_MAX;
    }
    ui->comboBox_Unit->addItem("");
    for (int row = 0; row < ndata; ++row)
    {
		MoM::eUnit_Type unitTypeNr = static_cast<MoM::eUnit_Type>(row);
        MoM::Unit_Type_Data* data = &unitTypes[unitTypeNr];

		QString title = QString("%0").arg((int)unitTypeNr, 3) + "   " + QString(game->getRaceName(data->m_Race_Code).c_str()) + "   " + QString(game->getNameByOffset(data->m_PtrName));
        QIcon icon = MoM::QMoMResources::instance().getIcon(unitTypeNr);

        ui->comboBox_Unit->addItem(icon, title);
	}


    // Initalize graphics view with items that are fixed
    QRectF rectf = ui->graphicsView_Unit->rect();
    m_sceneUnit->setSceneRect(0, 0, rectf.width(), rectf.height());
    ui->graphicsView_Unit->setSceneRect(0, 0, rectf.width(), rectf.height());


    // Use a pixmap as reference for coordinate positions
    QPixmap pixmap(":/images/sword_normal.gif");
    m_lineHeight = pixmap.height() * 4 / 3;

    // Use a text label as reference for coordinate positions
    QGraphicsSimpleTextItem* item = addText(QPointF(0, 0), "To Hit Ranged");
    m_labelWidth = item->boundingRect().width();
    m_sceneUnit->removeItem(item);
    delete item;
    item = 0;

    m_pictureHeight = 4 * m_lineHeight;


    QGraphicsSimpleTextItem* textItem = 0;
    QPointF pos(0, m_pictureHeight);

    pos = QPoint(m_labelWidth, 2 * m_lineHeight);
    textItem = addText(pos, "Moves");
    pos.ry() += m_lineHeight;
    textItem = addText(pos, "Upkeep");
    pos.ry() += m_lineHeight;

    pos = QPoint(0, m_pictureHeight);
    textItem = addText(pos, "Melee");
    pos.ry() += m_lineHeight;
    textItem = addText(pos, "Range");
    pos.ry() += m_lineHeight;
    textItem = addText(pos, "Armor");
    pos.ry() += m_lineHeight;
    textItem = addText(pos, "Resist");
    pos.ry() += m_lineHeight;
    textItem = addText(pos, "Hits");
    pos.ry() += m_lineHeight;


    ui->graphicsView_Unit->setScene(m_sceneUnit);
}

DialogAddUnit::~DialogAddUnit()
{
    delete ui;
    delete m_sceneUnit;
    delete m_unit;
}

MoM::MoMGameBase* DialogAddUnit::getGame()
{
    MainWindow* controller = MainWindow::getInstance();
    if (0 == controller)
        return 0;
    MoM::MoMGameBase* game = controller->getGame();
    return game;
}

QGraphicsSimpleTextItem* DialogAddUnit::addText(const QPointF& pos, const QString& text)
{
    QGraphicsSimpleTextItem* textItem = m_sceneUnit->addSimpleText(text, m_font);
    textItem->setBrush(QBrush(Qt::white));
    textItem->setPos(pos);
    return textItem;
}

void DialogAddUnit::displaySpecial(QPointF& pos, const QString& specialName, int specialValue)
{
  QGraphicsItem* item = 0;

  QString imageName = ":/abilities/" + specialName + ".gif";

  QPixmap pixmap(imageName);
  item = m_sceneUnit->addPixmap(pixmap);
  m_unitSpecificItems.push_back(item);
  item->setPos(pos);

  item = addText(pos + QPointF(pixmap.width() * 4 / 3, 0), specialName);
  m_unitSpecificItems.push_back(item);

  pos.rx() += ui->graphicsView_Unit->width() / 2;
  if (pos.rx() > ui->graphicsView_Unit->width() * 3 / 4)
  {
      pos.setX(0);
      pos.ry() += MoM::Max(pixmap.height() + 2, 34);
  }
}

void DialogAddUnit::displayStrength(QPointF& pos, int strength, const QString& imageBaseName)
{
  // calculate number of normal, lost_normal, gold, and lost_gold icons
  int normal = strength, lost_normal = 0, gold = 0, lost_gold = 0;
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
         y += pixmap.width() / 4;
     }
     if (col > 0 && col % 5 == 0)
     {
         x += pixmap.width() / 8;
     }
     QGraphicsItem* item = m_sceneUnit->addPixmap(pixmap);
     m_unitSpecificItems.push_back(item);
     item->setPos(x, y);
     x += pixmap.width();
  }
//      for (i = 0; i < lost_normal; ++i, ++col)
//      {
//         if (col > 0 && col % 15 == 0) doc.writeln("<br />");
//         doc.write("<img ");
//         if (col > 0 && col % 5 == 0) doc.write(style_spacer);
//         doc.writeln("src=\"images/" + image + "_normal_lost.gif\" alt=\"n\">");
//      }
//      for (i = 0; i < gold; ++i, ++col)
//      {
//         if (col > 0 && col % 15 == 0) doc.writeln("<br />");
//         doc.write("<img ");
//         if (col > 0 && col % 5 == 0) doc.write(style_spacer);
//         doc.writeln("src=\"images/" + image + "_gold.gif\" alt=\"G\">");
//      }
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
      m_unitSpecificItems.push_back(textItem);
      QFont font(textItem->font());
      font.setPixelSize(10);
      textItem->setFont(font);
  }

  pos.ry() += 10;
}

void DialogAddUnit::on_buttonBox_clicked(QAbstractButton *button)
{
    MainWindow* controller = MainWindow::getInstance();
    if (0 == controller)
        return;

    if (QDialogButtonBox::ApplyRole == ui->buttonBox->buttonRole(button))
    {
        MoM::eUnit_Type unitType = static_cast<MoM::eUnit_Type>(ui->comboBox_Unit->currentIndex());
        controller->addUnit(unitType);
        update();
    }
}

void DialogAddUnit::on_comboBox_Unit_currentIndexChanged(int index)
{
    m_unit->setUnitTypeNr(static_cast<MoM::eUnit_Type>(index - 1));

    // Remove old items
    foreach(QGraphicsItem* item, m_unitSpecificItems)
    {
        m_sceneUnit->removeItem(item);
        delete item;
    }
    m_unitSpecificItems.clear();

    if (index <= 0)
        return;

    // Add new items

    const QImage* pImage = MoM::QMoMResources::instance().getImage(m_unit->getUnitTypeNr());
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

    QPointF posName(m_labelWidth, 0);
    QGraphicsSimpleTextItem* textItem = addText(posName, QString(m_unit->getName()));
    m_unitSpecificItems.push_back(textItem);
    QFont fontName(m_font);
    fontName.setPixelSize(20);
    textItem->setFont(fontName);

    pos = QPointF(ui->graphicsView_Unit->width() * 2 / 3, m_lineHeight);
    QPixmap pixmap(":images/tohit.gif");
    QGraphicsItem* item = m_sceneUnit->addPixmap(pixmap);
    m_unitSpecificItems.push_back(item);
    item->setPos(pos);
    pos.rx() += pixmap.width() + 2;

    if (m_unit->getMelee())
    {
       displayToHit(pos, m_unit->getToHitMelee(), "Melee");
    }
    else
    {
        pos.ry() += 10;
    }
    if (m_unit->getRanged())
    {
        displayToHit(pos, m_unit->getToHitRanged(), "Ranged");
    }
    else
    {
        pos.ry() += 10;
    }
    if (m_unit->getArmor())
    {
        displayToHit(pos, m_unit->getToDefend(), "Defend");
    }

    pos = QPointF(m_labelWidth, m_pictureHeight);

    QString imageBaseName;
    switch (m_unit->getWeaponType())
    {
    default:
    case MoM::WEAPON_normal:        imageBaseName = "sword"; break;
    case MoM::WEAPON_magic:         imageBaseName = "sword_magic"; break;
    case MoM::WEAPON_mithril:       imageBaseName = "sword_mithril"; break;
    case MoM::WEAPON_adamantium:    imageBaseName = "sword_adamantium"; break;
    }

    displayStrength(pos, m_unit->getMelee(), imageBaseName);

    switch (m_unit->getRangedType())
    {
    case MoM::RANGED_Rock:           imageBaseName = "rock"; break;
    case MoM::RANGED_Arrow:          imageBaseName = "bow"; break;
    case MoM::RANGED_Bullet:         imageBaseName = "rock"; break;
    case MoM::RANGED_Thrown_Weapons: imageBaseName = "thrown"; break;
    default:                         imageBaseName = "fireball"; break;
    }

    displayStrength(pos, m_unit->getRanged(), imageBaseName);

    displayStrength(pos, m_unit->getArmor(), "shield");
    displayStrength(pos, m_unit->getResist(), "resistance");
    displayStrength(pos, m_unit->getHits(), "heart");

    MoM::MoMUnit::MapSpecials mapSpecials(m_unit->getSpecials());
    pos.rx() = 0;
    pos.ry() += m_lineHeight;
    for (MoM::MoMUnit::MapSpecials::const_iterator it = mapSpecials.begin(); it != mapSpecials.end(); ++it)
    {
        QString specialName(it->first.c_str());
        displaySpecial(pos, specialName, it->second);
    }

}
