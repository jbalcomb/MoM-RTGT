## ---------------------------------------------------------------------------
## Copyright:   2011 Klaas van Aarsen
## License:     GPL
## Author:      I like Serena (aka Klaas van Aarsen)
## Created:     2010-05-01
## ---------------------------------------------------------------------------

include(../Common/Common.pri)

TEMPLATE = app

#unix:VERSION = $$system(svn info . | grep 'Changed\ Rev' | cut -b 19-)
VERSION = 7
!isEmpty(VERSION){
  VERSION = 0.2.$${VERSION}
}

TARGET = MoMTweaker

QT += core gui
QT += xml

include(MoMTweaker.pri)

# Additional platform specific sources
SOURCES += \
    ./main.cpp
