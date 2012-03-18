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

#include <MoMTemplate.h>

namespace MoM {
    class MoMGameBase;
}

namespace MoM {

class QMoMResources
{
public:
    QMoMResources(MoM::MoMGameBase* game);
    virtual ~QMoMResources();

    static void createInstance(MoM::MoMGameBase* game)
    {
        delete m_instance;
        m_instance = new QMoMResources(game);
    }

    static QMoMResources& instance()
    {
        if (0 == m_instance)
        {
            m_instance = new QMoMResources(0);
        }
        return *m_instance;
    }

    void setGame(MoM::MoMGameBase* game);

	const QVector<QRgb>& GetColorTable()
	{
		return m_colorTable;
	}

    template<typename T>
    QIcon getIcon(T t) const
    {
        const QImage* image = getImage(t);
        QIcon icon;
        if (0 != image)
        {
            icon = QPixmap::fromImage(*image);
        }
        return icon;
    }

    const QImage* getImage(MoM::eBuilding building) const
	{
		const QImage* image = 0;
		if (inRange(m_buildingImages, building))
		{
			image = &m_buildingImages[building];
		}
		return image;
	}
	const QImage* getImage(MoM::eItem_Type item) const
	{
		const QImage* image = 0;
		if (inRange(m_itemImages, item))
		{
			image = &m_itemImages[item];
		}
		return image;
	}
	const QImage* getImage(MoM::eTower_Node_Lair_Type lair) const
	{
		const QImage* image = 0;
		if (inRange(m_lairImages, lair))
		{
			image = &m_lairImages[lair];
		}
		return image;
	}
	const QImage* getImage(MoM::eSpell spell) const
	{
		const QImage* image = 0;
		if (inRange(m_spellImages, spell))
		{
			image = &m_spellImages[spell];
		}
		return image;
	}
	const QImage* getImage(MoM::eTerrainType terrain) const
	{
		const QImage* image = 0;
		if (inRange(m_terrainTypeImages, terrain))
		{
			image = &m_terrainTypeImages[terrain];
		}
		return image;
	}
	const QImage* getImage(MoM::eUnit_Type unitType) const
	{
		const QImage* image = 0;
		if (inRange(m_unitImages, unitType))
		{
			image = &m_unitImages[unitType];
		}
		return image;
	}

public:
    static const QFont g_FontSmall;
    static const QFont g_Font;
    static const QFont g_FontBig;

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
	bool inRange(const QVector<QImage>& v, T t) const
	{
		return (static_cast<unsigned>(t) < static_cast<unsigned>(v.size()));
	}

    static QMoMResources* m_instance;

    MoM::MoMGameBase* m_game;

    QVector<QRgb> m_colorTable;
    QVector<QImage> m_buildingImages;
    QVector<QImage> m_itemImages;
    QVector<QImage> m_lairImages;
    QVector<QImage> m_specialsImages;
    QVector<QImage> m_spellImages;
    QVector<QImage> m_terrainTypeImages;
    QVector<QImage> m_unitImages;
};

}

#endif // QMOMRESOURCES_H_
