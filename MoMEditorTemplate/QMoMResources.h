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

    static void createInstance(const QMoMGamePtr& game);

    static QMoMResources& instance();

    void setGame(const QMoMGamePtr& game);

    const QVector<QRgb>& getColorTable()
	{
		return m_colorTable;
	}

    template<typename T>
    const QMoMIconPtr getIcon(T t, double scale = 1) const
    {
        QMoMIconPtr iconPtr(new QIcon(getPixmap(t, scale)));
        return iconPtr;
    }

    const QMoMImagePtr getImage(MoM::eBannerColor bannerColor) const;
    const QMoMImagePtr getImage(MoM::eBuilding building) const;
    const QMoMImagePtr getImage(MoM::eCity_Size citySize, MoM::eBannerColor banner = MoM::BANNER_Blue) const;
    const QMoMImagePtr getImage(MoM::eItem_Icon itemIcon) const;
    const QMoMImagePtr getImage(MoM::eTower_Node_Lair_Type lair) const;
    const QMoMImagePtr getImage(MoM::eRace race) const;
    const QMoMImagePtr getImage(MoM::eRandomPickType randomPickType) const;
    const QMoMImagePtr getImage(MoM::eSlot_Type16 slotType) const;
    const QMoMImagePtr getImage(MoM::eSpell spell) const;
    const QMoMImagePtr getImage(MoM::eTerrainBonusDeposit bonusDeposit) const;
    const QMoMImagePtr getImage(MoM::eTerrainChange terrainChange, int roadDirection = 0) const;
    const QMoMImagePtr getImage(MoM::eTerrainType terrain) const;
    const QMoMImagePtr getImage(MoM::eUnit_Type unitType, int heading = -1) const;
    template<typename T>
    const QMoMImagePtr getImage(T) const
    {
        // Default match for getImage()
        return QMoMImagePtr(); 
    }
 
    template<typename T>
    QPixmap getPixmap(T t, double scale = 1.0) const
    {
        const QMoMImagePtr pImage = getImage(t);
        QPixmap pixmap;
        if (!pImage.isNull())
        {
            if (1.0 != scale)
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

    template<typename T>
    QPixmap getPixmap(T t, double scale, MoM::eBannerColor banner) const
    {
        const QMoMImagePtr pImage = getImage(t, banner);
        QPixmap pixmap;
        if (!pImage.isNull())
        {
            if (1.0 != scale)
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
    bool createCitySizeImages();
    bool createLairImages();
    bool createLbxImages(const std::string& lbxTitle, QVector<QMoMImagePtr>& vecImages);
    bool createSpellImages();
    bool createTerrainImages();
    bool createUnitImages();

	template<typename T>
    bool inVectorRange(const QVector<QMoMImagePtr>& v, T t) const
	{
		return (static_cast<unsigned>(t) < static_cast<unsigned>(v.size()));
	}

    static QMoMResources* m_instance;

    QMoMGamePtr m_game;

    QVector<QRgb> m_colorTable;
    QVector<QMoMImagePtr> m_buildingImages;
    QVector<QMoMImagePtr> m_citySizeImages;
    QVector<QMoMImagePtr> m_figureImages;
    QVector<QMoMImagePtr> m_itemiscImages;
    QVector<QMoMImagePtr> m_itemsImages;
    QVector<QMoMImagePtr> m_lairImages;
    QVector<QMoMImagePtr> m_mapBackImages;
    QVector<QMoMImagePtr> m_specialImages;
    QVector<QMoMImagePtr> m_spellImages;
    QVector<QMoMImagePtr> m_terrainTypeImages;
    QVector<QMoMImagePtr> m_unitImages;
};

class QMoMLazyIconBase
{
public:
    explicit QMoMLazyIconBase()
    {
    }
    virtual ~QMoMLazyIconBase()
    {
    }
    virtual const QIcon data() const = 0;
    virtual bool resolve() = 0;
};

template<class T>
class QMoMLazyIcon : public QMoMLazyIconBase
{
public:
    explicit QMoMLazyIcon(const T& t, int scale = 1) :
        QMoMLazyIconBase(),
        m_ref(t),
        m_scale(scale),
        m_icon(),
        m_resolved(false)
    {
    }
    const QIcon data() const
    {
        if (m_icon.isNull())
            return QIcon();
        else
            return *m_icon;
    }
    bool resolve()
    {
        bool resolution = false;
        if (!m_resolved)
        {
            m_icon = QMoMResources::instance().getIcon(m_ref, m_scale);
            m_resolved = true;
            resolution = (!m_icon.isNull() && !m_icon->isNull());
        }
        return resolution;
    }
    void setData(const T& t)
    {
        if (m_ref != t)
        {
            m_ref = t;
            m_resolved = false;
            m_icon.clear();
        }
    }

private:
    T m_ref;
    int m_scale;
    QMoMIconPtr m_icon;
    bool m_resolved;
};

template<>
class QMoMLazyIcon<QString> : public QMoMLazyIconBase
{
public:
    explicit QMoMLazyIcon(const QString& ref = QString()) :
        QMoMLazyIconBase(),
        m_ref(ref),
        m_icon(),
        m_resolved(false)
    {
    }
    const QIcon data() const
    {
        if (m_icon.isNull())
            return QIcon();
        else
            return *m_icon;
    }
    bool resolve()
    {
        bool resolution = false;
        if (!m_resolved)
        {
            m_icon = QMoMIconPtr(new QIcon(m_ref));
            m_resolved = true;
            resolution = (!m_icon.isNull() && !m_icon->isNull());
        }
        return resolution;
    }
    void setData(const QString& ref)
    {
        if (m_ref != ref)
        {
            m_ref = ref;
            m_resolved = false;
            m_icon.clear();
        }
    }
private:
    QString m_ref;
    QMoMIconPtr m_icon;
    bool m_resolved;
};

template<>
class QMoMLazyIcon<QIcon> : public QMoMLazyIconBase
{
public:
    explicit QMoMLazyIcon(const QIcon& ref) :
        QMoMLazyIconBase(),
        m_ref(ref),
        m_icon(),
        m_resolved(false)
    {
    }
    const QIcon data() const
    {
        if (m_icon.isNull())
            return QIcon();
        else
            return *m_icon;
    }
    bool resolve()
    {
        bool resolution = false;
        if (!m_resolved)
        {
            m_icon = QMoMIconPtr(new QIcon(m_ref));
            m_resolved = true;
            resolution = (!m_icon.isNull() && !m_icon->isNull());
        }
        return resolution;
    }
    void setData(const QIcon& ref)
    {
        m_ref = ref;
        m_resolved = false;
        m_icon.clear();
    }
private:
    QIcon m_ref;
    QMoMIconPtr m_icon;
    bool m_resolved;
};

}

#endif // QMOMRESOURCES_H_
