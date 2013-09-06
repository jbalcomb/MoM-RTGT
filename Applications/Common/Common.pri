debug:RELEASE = Debug
release:RELEASE = Release

unix:PLATF = Linux
win32-g++:PLATF = Windows
win32-msvc2008:PLATF = Windows
message(PLATF: $$PLATF)

unix:COMPILER = gcc
win32-g++:COMPILER = mingw
win32-msvc2008:COMPILER = msvc2008
message(COMPILER: $$COMPILER)
message(Compiler Binary: $$QMAKE_CXX)

unix:QMAKE_CXXFLAGS += -g -fshort-enums -Wno-unused-parameter -fno-strict-aliasing -Wno-sign-compare
win32-g++:QMAKE_CXXFLAGS += -g -fshort-enums -Wno-unused-parameter -fno-strict-aliasing -Wno-sign-compare
win32-msvc2008:QMAKE_CXXFLAGS +=
message(QMAKE_CXXFLAGS: $$QMAKE_CXXFLAGS)

unix:QMAKE_LIBS +=
win32-g++:QMAKE_LIBS += -luser32
win32-msvc2008:QMAKE_LIBS += user32.lib
message(QMAKE_LIBS: $$QMAKE_LIBS)

DESTDIR = ../../$${RELEASE}/$${COMPILER}

DEPENDPATH += .
MOC_DIR += ./Generated/$${RELEASE}
OBJECTS_DIR += $${COMPILER}/$${RELEASE}
UI_DIR += ./Generated
RCC_DIR += ./Generated

DEFINES += _CRT_SECURE_NO_WARNINGS
