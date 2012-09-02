#-------------------------------------------------
#
# Project created by QtCreator 2012-08-31T19:39:56
#
#-------------------------------------------------

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

QT       -= core gui

TARGET = MoMCore
TEMPLATE = lib
DESTDIR = $${COMPILER}/bin
OBJECTS_DIR += $${COMPILER}/obj

#CONFIG += staticlib

DEFINES += MOMCORE_LIBRARY
DEFINES += _CRT_SECURE_NO_WARNINGS

INCLUDEPATH += \
    . \
    ../MoMEditorTemplate \
    C:/Python32/include

QMAKE_LIBS += C:/Python32/libs/python32.lib

SOURCES += MoMCore.cpp \
    ../MoMEditorTemplate/MoMProcess$${PLATF}.cpp \
    ../swig/mom_wrap.cxx

HEADERS += MoMCore.h

HEADERS += \
    ../MoMEditorTemplate/MoMCatnip.h \
    ../MoMEditorTemplate/MoMCommon.h \
    ../MoMEditorTemplate/MoMController.h \
    ../MoMEditorTemplate/MoMExeBase.h \
    ../MoMEditorTemplate/MoMExeMagic.h \
    ../MoMEditorTemplate/MoMExeWizards.h \
    ../MoMEditorTemplate/MoMGameBase.h \
    ../MoMEditorTemplate/MoMGameCustom.h \
    ../MoMEditorTemplate/MoMGameMemory.h \
    ../MoMEditorTemplate/MoMGameSave.h \
    ../MoMEditorTemplate/MoMGenerated.h \
    ../MoMEditorTemplate/MoMLbxBase.h \
    ../MoMEditorTemplate/MoMLocation.h \
    ../MoMEditorTemplate/MoMProcess.h \
    ../MoMEditorTemplate/MoMTemplate.h \
    ../MoMEditorTemplate/MoMTerrain.h \
    ../MoMEditorTemplate/MoMUnit.h \
    ../MoMEditorTemplate/MoMUtility.h \
    ../MoMEditorTemplate/TeeRedirecter.h

SOURCES += \
    ../MoMEditorTemplate/MoMCatnip.cpp \
    ../MoMEditorTemplate/MoMController.cpp \
    ../MoMEditorTemplate/MoMGameBase.cpp \
    ../MoMEditorTemplate/MoMGameCustom.cpp \
    ../MoMEditorTemplate/MoMGameMemory.cpp \
    ../MoMEditorTemplate/MoMGameSave.cpp \
    ../MoMEditorTemplate/MoMGenerated.cpp \
    ../MoMEditorTemplate/MoMExeBase.cpp \
    ../MoMEditorTemplate/MoMExeMagic.cpp \
    ../MoMEditorTemplate/MoMExeWizards.cpp \
    ../MoMEditorTemplate/MoMLbxBase.cpp \
    ../MoMEditorTemplate/MoMProcessCommon.cpp \
    ../MoMEditorTemplate/MoMTerrain.cpp \
    ../MoMEditorTemplate/MoMUnit.cpp \
    ../MoMEditorTemplate/MoMUtility.cpp
