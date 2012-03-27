## ---------------------------------------------------------------------------
## Copyright:   2011 Klaas van Aarsen
## License:     GPL
## Author:      I like Serena (aka Klaas van Aarsen)
## Created:     2010-05-01
## ---------------------------------------------------------------------------

unix:PLATF = Linux
win32-g++:PLATF = Windows
win32-msvc2008:PLATF = Windows

unix:COMPILER = gcc
win32-g++:COMPILER = mingw
win32-msvc2008:COMPILER = msvc2008

unix:QMAKE_CXXFLAGS += -g -fshort-enums -Wno-unused-parameter
win32-g++:QMAKE_CXXFLAGS += -g -fshort-enums -Wno-unused-parameter
win32-msvc2008:QMAKE_CXXFLAGS +=

unix:QMAKE_LIBS +=
win32-g++:QMAKE_LIBS += -luser32
win32-msvc2008:QMAKE_LIBS += user32.lib

TEMPLATE = app

#unix:VERSION = $$system(svn info . | grep 'Changed\ Rev' | cut -b 19-)
VERSION = 1
!isEmpty(VERSION){
  VERSION = 0.2.$${VERSION}
}

TARGET = MoMTweaker
DESTDIR = $${COMPILER}/bin

QT += core gui
CONFIG += debug

#DEFINES += QT_LARGEFILE_SUPPORT
INCLUDEPATH += ./GeneratedFiles \
    ./GeneratedFiles/Debug \
    . \
    ../MoMEditorTemplate
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/Debug
OBJECTS_DIR += $${COMPILER}/obj
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles

include(MoMTweaker.pri)

# Additional platform specific sources
SOURCES += \
    ../MoMEditorTemplate/MoMProcess$${PLATF}.cpp \
    ./main.cpp
