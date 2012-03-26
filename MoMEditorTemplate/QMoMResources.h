// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2011-09-30
// ---------------------------------------------------------------------------

/// \file

#ifndef QMOMRESOURCES_H_
#define QMOMRESOURCES_H_

#include <qfont.h>
#include <qicon.h>
#include <qimage.h>
#include <qvector.h>

#include "MoMTemplate.h"
#include "QMoMSharedPointers.h"

namespace MoM {
    class MoMGameBase;
}

namespace MoM {

class QMoMResources
{
public:
    QMoMResources(const QMoMGamePtr& game);
    virtual ~QMoMResources();

    static void createInstance(const QMoMGamePtr& game)
    {
        delete m_instance;
        m_instance = new QMoMResources(game);
    }

    static QMoMResources& instance()
    {
        if (0 == m_instance)
        {
            m_instance = new QMoMResources(QMoMGamePtr());
        }
        return *m_instance;
    }

    void setGame(const QMoMGamePtr& game);

	const QVector<QRgb>& GetColorTable()
	{
		return m_colorTable;
	}

    template<typename T>
    QIcon getIcon(T t, int scale = 1) const
    {
        QIcon icon(getPixmap(t, scale));
        return icon;
    }

    const QMoMImagePtr getImage(MoM::eBuilding building) const
	{
        QMoMImagePtr image;
		if (inRange(m_buildingImages, building))
		{
            image = m_buildingImages[building];
		}
		return image;
	}
    const QMoMImagePtr getImage(MoM::eItem_Icon itemIcon) const
	{
        QMoMImagePtr image;
        if (inRange(m_itemImages, itemIcon))
		{
            image = m_itemImages[itemIcon];
		}
		return image;
	}
    const QMoMImagePtr getImage(MoM::eTower_Node_Lair_Type lair) const
	{
        QMoMImagePtr image;
        if (inRange(m_lairImages, lair))
		{
            image = m_lairImages[lair];
		}
		return image;
	}
    const QMoMImagePtr getImage(MoM::eRace race) const;
    const QMoMImagePtr getImage(MoM::eSpell spell) const
	{
        QMoMImagePtr image;
        if (inRange(m_spellImages, spell))
		{
            image = m_spellImages[spell];
		}
		return image;
	}
    const QMoMImagePtr getImage(MoM::eTerrainType terrain) const
	{
        QMoMImagePtr image;
        if (inRange(m_terrainTypeImages, terrain))
		{
            image = m_terrainTypeImages[terrain];
		}
		return image;
	}
    const QMoMImagePtr getImage(MoM::eUnit_Type unitType) const
	{
        QMoMImagePtr image;
        if (inRange(m_unitImages, unitType))
		{
            image = m_unitImages[unitType];
		}
		return image;
	}

    template<typename T>
    QPixmap getPixmap(T t, int scale = 1) const
    {
        const QMoMImagePtr pImage = getImage(t);
        QPixmap pixmap;
        if (!pImage.isNull())
        {
			if (1 != scale)
			{
                QImage image = pImage->scaled(pImage->size() * scale, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	            pixmap.convertFromImage(image);
			}
			else
			{
	            pixmap.convertFromImage(*pImage);
			}
        }
        return pixmap;
    }

public:
    static const QFont g_FontSmall;
    static const QFont g_Font;

private:
    bool createColorTable();

    bool createBuildingImages();
    bool createItemImages();
    bool createLairImages();
    bool createSpecialsImages();
    bool createSpellImages();
    bool createTerrainImages();
    bool createUnitImages();

	template<typename T>
    bool inRange(const QVector<QMoMImagePtr>& v, T t) const
	{
		return (static_cast<unsigned>(t) < static_cast<unsigned>(v.size()));
	}

    static QMoMResources* m_instance;

    QMoMGamePtr m_game;

    QVector<QRgb> m_colorTable;
    QVector<QMoMImagePtr> m_buildingImages;
    QVector<QMoMImagePtr> m_itemImages;
    QVector<QMoMImagePtr> m_lairImages;
    QVector<QMoMImagePtr> m_specialsImages;
    QVector<QMoMImagePtr> m_spellImages;
    QVector<QMoMImagePtr> m_terrainTypeImages;
    QVector<QMoMImagePtr> m_unitImages;
};

}

#endif // QMOMRESOURCES_H_
