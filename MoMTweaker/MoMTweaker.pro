## ---------------------------------------------------------------------------
## Copyright:   2011 Klaas van Aarsen
## License:     GPL
## Author:      I like Serena (aka Klaas van Aarsen)
## Created:     2010-05-01
## ---------------------------------------------------------------------------

TEMPLATE = app

unix:PLATF = Linux
win32:PLATF = Windows

unix:VERSION = $$system(svn info . | grep 'Changed\ Rev' | cut -b 19-)
win32:VERSION = 6
!isEmpty(VERSION){
  VERSION = 0.1.$${VERSION}
}

TARGET = MoMTweaker
DESTDIR = bin

QT += core gui
CONFIG += debug
#DEFINES += QT_LARGEFILE_SUPPORT
INCLUDEPATH += ./GeneratedFiles \
    ./GeneratedFiles/Debug \
    . \
    ../MoMEditorTemplate
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/Debug
OBJECTS_DIR += $${PLATF}
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles

include(MoMTweaker.pri)

SOURCES += ../MoMEditorTemplate/MoMProcess$${PLATF}.cpp

unix:QMAKE_CXXFLAGS += -g -fshort-enums -Wno-unused-parameter
win32:QMAKE_LIBS += user32.lib
