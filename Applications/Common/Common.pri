debug:RELEASE = Debug
release:RELEASE = Release

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

DESTDIR = ../../$${RELEASE}/$${COMPILER}

DEPENDPATH += .
MOC_DIR += ./Generated/$${RELEASE}
OBJECTS_DIR += $${COMPILER}/$${RELEASE}
UI_DIR += ./Generated
RCC_DIR += ./Generated

DEFINES += _CRT_SECURE_NO_WARNINGS
