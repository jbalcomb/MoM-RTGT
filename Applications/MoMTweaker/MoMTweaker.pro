## ---------------------------------------------------------------------------
## Copyright:   2011 Klaas van Aarsen
## License:     GPL
## Author:      I like Serena (aka Klaas van Aarsen)
## Created:     2010-05-01
## ---------------------------------------------------------------------------

include(../Common/Common.pri)

TEMPLATE = app

VERSION = 0.3.1
DEFINES += VERSION=\\\"$${VERSION}\\\"

TARGET = MoMTweaker

QT += core gui

include(MoMTweaker.pri)

# Additional platform specific sources
SOURCES += \
    ./main.cpp
