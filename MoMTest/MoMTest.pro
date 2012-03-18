#-------------------------------------------------
#
# Project created by QtCreator 2012-03-18T20:14:15
#
#-------------------------------------------------

QT       += testlib

TARGET = MoMTest
DESTDIR = bin

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

unix:PLATF = Linux
win32:PLATF = Windows

unix:QMAKE_CXXFLAGS += -g -fshort-enums -Wno-unused-parameter
win32:QMAKE_LIBS += user32.lib

MOC_DIR += ./GeneratedFiles
OBJECTS_DIR += $${PLATF}
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles

INCLUDEPATH += \
    ../MoMEditorTemplate \
    ../MoMTweaker \
    ./GeneratedFiles

include(../MoMTweaker/MoMTweaker.pri)

# Additional platform specific sources
SOURCES += \
    ../MoMEditorTemplate/MoMProcess$${PLATF}.cpp \

# Test sources
SOURCES += \
    test_main.cpp \
    tst_momgamebase.cpp \
    tst_momtweaker_mainwindow.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"
