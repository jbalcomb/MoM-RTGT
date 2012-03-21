#-------------------------------------------------
#
# Project created by QtCreator 2012-03-18T20:14:15
#
#-------------------------------------------------

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

QT       += testlib

TARGET = MoMTest
DESTDIR = bin

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

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
