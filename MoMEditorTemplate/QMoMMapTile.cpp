// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2011-09-30
// ---------------------------------------------------------------------------

#include <qpainter.h>

#include "MoMGenerated.h"
#include "QMoMResources.h"
#include "QMoMUtility.h"

#include "QMoMMapTile.h"

namespace MoM
{

QMoMMapTile::QMoMMapTile() :
    QGraphicsItem(),
    m_bonusDeposit(0),
    m_plane(MoM::PLANE_Arcanum),
    m_terrainType(0)
{
}

QMoMMapTile::~QMoMMapTile()
{
}

QRectF QMoMMapTile::boundingRect() const
{
    return QRectF(0, 0, 20, 18);
}

void QMoMMapTile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    if (0 != m_terrainType)
    {
        int iTerrainType = (int) *m_terrainType;
        if (MoM::PLANE_Myrror == m_plane)
        {
            iTerrainType += MoM::eTerrainType_MAX;
        }
		MoM::eTerrainType terrainType = static_cast<MoM::eTerrainType>(iTerrainType);
		const QMoMImagePtr image = QMoMResources::instance().getImage(terrainType);
		if (0 != image)
		{
			painter->drawImage(boundingRect(), *image);
		}
    }
    else
    {
        QString text = ".";
        if (0 != m_terrainType)
        {
            text = QString::number(static_cast<int> (*m_terrainType));
        }

        painter->setPen(Qt::yellow);
        painter->drawText(boundingRect(), text, QTextOption(Qt::AlignCenter));
    }

    if (0 != m_bonusDeposit)
    {
        QString toolTip;
        QVector<MoM::eBonusDeposit> vecDeposits;
        vecDeposits         << DEPOSIT_Iron_Ore
                            << DEPOSIT_Coal
                            << DEPOSIT_Silver_Ore
                            << DEPOSIT_Gold_Ore
                            << DEPOSIT_Gems
                            << DEPOSIT_Mithril_Ore
                            << DEPOSIT_Adamantium_Ore
                            << DEPOSIT_Quork
                            << DEPOSIT_Crysx
                            << DEPOSIT_Wild_Game
                            << DEPOSIT_Nightshade;
        for (int index = vecDeposits.size(); index-- > 0;)
        {
            MoM::eBonusDeposit deposit = vecDeposits[index];
            if ((*m_bonusDeposit & deposit) != deposit)
                continue;
            const QMoMImagePtr image = QMoMResources::instance().getImage(deposit);
            if (0 != image)
            {
                painter->drawImage(boundingRect(), *image);
            }
            toolTip += prettyQStr(deposit);
            break;
        }
        setToolTip(toolTip);
    }
}

}
