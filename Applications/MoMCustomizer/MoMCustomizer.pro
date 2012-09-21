## ---------------------------------------------------------------------------
## Copyright:   2011 Klaas van Aarsen
## License:     GPL
## Author:      I like Serena (aka Klaas van Aarsen)
## Created:     2010-05-01
## ---------------------------------------------------------------------------

unix:PLATF = Linux
win32-g++:PLATF = Windows
win32-msvc2008:PLATF = Windows
message(PLATF: $$PLATF)

unix:COMPILER = gcc
win32-g++:COMPILER = mingw
win32-msvc2008:COMPILER = msvc2008
message(COMPILER: $$COMPILER)
message(Compiler Binary: $$QMAKE_CXX)

unix:QMAKE_CXXFLAGS += -g -fshort-enums -Wno-unused-parameter
win32-g++:QMAKE_CXXFLAGS += -g -fshort-enums -Wno-unused-parameter
win32-msvc2008:QMAKE_CXXFLAGS +=
message(QMAKE_CXXFLAGS: $$QMAKE_CXXFLAGS)

unix:QMAKE_LIBS +=
win32-g++:QMAKE_LIBS += -luser32
win32-msvc2008:QMAKE_LIBS += user32.lib
message(QMAKE_LIBS: $$QMAKE_LIBS)

TEMPLATE = app

#VERSION = $$system(svn info . | grep 'Changed\ Rev' | cut -b 19-)
VERSION = 2
!isEmpty(VERSION){
  VERSION = 0.2.$${VERSION}
}

TARGET = MoMCustomizer
DESTDIR = $${COMPILER}/bin

QT += core gui
CONFIG += debug
#DEFINES += QT_LARGEFILE_SUPPORT
INCLUDEPATH += ./GeneratedFiles \
    . \
    ../MoMEditorTemplate
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles
OBJECTS_DIR += $${COMPILER}/obj
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles

include(MoMCustomizer.pri)

SOURCES += \
    ../MoMEditorTemplate/MoMProcess$${PLATF}.cpp \
    ./main.cpp
