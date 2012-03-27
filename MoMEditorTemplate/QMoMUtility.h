// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#ifndef QMOMUTILITY_H_
#define QMOMUTILITY_H_

#include <QDateTime>

namespace MoM
{

inline QString getDateTimeStr()
{
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    return QString("%0 %1.%2")
            .arg(date.toString(Qt::ISODate))
            .arg(time.toString(Qt::ISODate))
            .arg(time.msec(), 3, 10, QChar('0'));
}

}

#endif
