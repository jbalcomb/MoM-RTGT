// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#ifndef QMOMLBX_H_
#define QMOMLBX_H_

#include <QImage>
#include <QVector>

#include "MoMCommon.h"
#include "QMoMSharedPointers.h"

namespace MoM
{

typedef QVector<QMoMImagePtr> QMoMAnimation;
typedef QVector<QRgb> QMoMPalette;

const uint8_t gTRANSPARENT_COLOR = 0;
const uint8_t gSHADOW_COLOR = 232;

bool convertImagesToLbx(const QMoMAnimation& images, std::vector<uint8_t>& dataBuffer, const std::string& context);

inline bool convertImageToLbx(const QMoMImagePtr& image, std::vector<uint8_t>& dataBuffer, const std::string& context)
{
    return convertImagesToLbx(QMoMAnimation(1, image), dataBuffer, context);
}

bool convertLbxToImages(const uint8_t* data, const QMoMPalette& defaultColorTable, QMoMAnimation& images, const std::string& context);

inline QMoMImagePtr convertLbxToImage(const uint8_t* data, const QMoMPalette& defaultColorTable, const std::string& context)
{
    QMoMAnimation images;
    (void)convertLbxToImages(data, defaultColorTable, images, context);
    if (images.empty())
    {
        return QMoMImagePtr();
    }
    else
    {
        return images[0];
    }
}

void convertLbxToPalette(const uint8_t* dataPalette, QMoMPalette& colorTable);

}

#endif
