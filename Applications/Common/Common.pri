# message(CONFIG: $$CONFIG)

# In QtCreator debug and release both occur in a Debug version, so we need the last
CONFIG(debug, debug|release) {
  RELEASE = Debug
} else {
  RELEASE = Release
}
message(RELEASE: $$RELEASE)

unix:PLATF = Linux
win32-g++:PLATF = Windows
win32-msvc2008:PLATF = Windows
win32-msvc2010:PLATF = Windows
message(PLATF: $$PLATF)

unix:COMPILER = gcc
win32-g++:COMPILER = mingw
win32-msvc2008:COMPILER = msvc2008
win32-msvc2010:COMPILER = msvc2010
message(COMPILER: $$COMPILER)
message(QMAKE_CXX: $$QMAKE_CXX)

# TODO: Ensure that we have at least C++11 on every platform
unix:QMAKE_CXXFLAGS += -g -fno-strict-aliasing -Wno-unused-parameter -Wno-sign-compare
win32-g++:QMAKE_CXXFLAGS += -g -fno-strict-aliasing -Wno-unused-parameter  -Wno-sign-compare
win32-msvc2008:QMAKE_CXXFLAGS +=
win32-msvc2010:QMAKE_CXXFLAGS +=
message(QMAKE_CXXFLAGS: $$QMAKE_CXXFLAGS)

unix:QMAKE_LIBS +=
win32-g++:QMAKE_LIBS += -luser32
win32-msvc2008:QMAKE_LIBS += user32.lib
win32-msvc2010:QMAKE_LIBS += user32.lib
message(QMAKE_LIBS: $$QMAKE_LIBS)

DESTDIR = ../../$${RELEASE}/$${COMPILER}

DEPENDPATH += .
MOC_DIR += ./Generated/$${RELEASE}
OBJECTS_DIR += $${COMPILER}/$${RELEASE}
UI_DIR += ./Generated
RCC_DIR += ./Generated

DEFINES += _CRT_SECURE_NO_WARNINGS

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
