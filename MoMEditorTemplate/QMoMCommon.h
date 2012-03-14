// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#ifndef QMOMCOMMON_H_
#define QMOMCOMMON_H_

#include <QImage>
#include <QVector>

#include "MoMcommon.h"

namespace MoM
{

bool convertImagesToLbx(const QVector<QImage>& images, std::vector<uint8_t>& dataBuffer, const std::string& context);

inline bool convertImageToLbx(const QImage& image, std::vector<uint8_t>& dataBuffer, const std::string& context)
{
    return convertImagesToLbx(QVector<QImage>(1, image), dataBuffer, context);
}

bool convertLbxToImages(const uint8_t* data, const QVector<QRgb>& defaultColorTable, QVector<QImage>& images, const std::string& context);

inline QImage convertLbxToImage(const uint8_t* data, const QVector<QRgb>& defaultColorTable, const std::string& context)
{
    QVector<QImage> images;
    (void)convertLbxToImages(data, defaultColorTable, images, context);
    if (images.empty())
    {
        return QImage();
    }
    else
    {
        return images[0];
    }
}

void convertLbxToPalette(const uint8_t* dataPalette, QVector<QRgb>& colorTable);

}

#endif
