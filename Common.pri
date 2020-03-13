# Suffix of platform specific source files
unix:PLATF = Linux
win32-g++:PLATF = Windows
win32-msvc2008:PLATF = Windows
win32-msvc2010:PLATF = Windows
message(PLATF: $$PLATF)

unix:QMAKE_CXXFLAGS += -g -fno-strict-aliasing -Wno-unused-parameter -Wno-sign-compare
win32-g++:QMAKE_CXXFLAGS += -fno-strict-aliasing -Wno-unused-parameter -Wno-sign-compare
win32-msvc2008:QMAKE_CXXFLAGS +=
win32-msvc2010:QMAKE_CXXFLAGS +=
message(QMAKE_CXXFLAGS: $$QMAKE_CXXFLAGS)

unix:QMAKE_LIBS +=
win32-g++:QMAKE_LIBS += -luser32 -lpsapi
win32-msvc2008:QMAKE_LIBS += user32.lib psapi.lib
win32-msvc2010:QMAKE_LIBS += user32.lib psapi.lib
message(QMAKE_LIBS: $$QMAKE_LIBS)

DEFINES += _CRT_SECURE_NO_WARNINGS PSAPI_VERSION=1

QT += core gui widgets