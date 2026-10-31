// ---------------------------------------------------------------------------
// Copyright:   2011-2020 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2011-04-03
// Modified:    2020-03-07
// ---------------------------------------------------------------------------

SUPPORTED PLATFORMS
===================
Windows
Linux
macOS       Core library and tests only; attaching to a running DOSBox is not implemented yet

DEPENDENCIES
============
Qt          Needed for GUI components
python3     Needed to regenerate sources (scripts/generate_code.py)


DEPLOYING
=========
In both Windows and Linux you need the Qt dynamic libraries available.

In Windows you can do this by putting Qt5Core.dll, Qt5Gui.dll, and Qt5Widgets.dll in the same 
directory as the executables and any redistributables of the compiler as well.

In Linux you can do this by putting libQtCore.so, libQtGui.so, and libQtWidgets.so in 
the same directory as the executables and adding the current directory to 
the environment variable LD_LIBRARY_PATH.


BUILDING FROM SOURCES WITH CMAKE
================================
Needs CMake 3.16+ and a C++14 compiler. Qt5 is only needed for the GUI applications.

    cmake -S . -B build                         # core library + unit tests
    cmake --build build
    ctest --test-dir build --output-on-failure

    cmake -S . -B build -DRTGT_BUILD_QT_APPS=ON # also MoMTweaker and MoMCustomizer

Executables end up in build/bin. The combat tests need a running game in DOSBox
and are skipped by default; run them with: build/bin/rtgt_tests --no-skip

After changing MoMModel/MoMTemplate.h, regenerate the generated sources with
    cmake --build build --target rtgt_generate      (or: python3 scripts/generate_code.py)
ctest fails while the committed generated sources are out of date.


BUILDING FROM SOURCES WITH QMAKE
================================
1. Download QtCreator.
2. Open one of the projects, for instance Applications\MoMTweaker\MoMTweaker.pro.
3. Build & Run.
4. If you make changes to the structures that map to the game, you'll have 
   regenerate some sources:
        python3 scripts/generate_code.py