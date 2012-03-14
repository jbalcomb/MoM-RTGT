// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2011-02-06
// ---------------------------------------------------------------------------

SUPPORTED PLATFORMS
-------------------
Windows     Developed and tested with Windows XP and Windows 7 (with Visual Studio 2008)
Linux       Developed and tested with Ubuntu 10.04 LTS (with g++ 4.4.3)

DEPENDENCIES
------------
perl        Needed to generate sources (developed with perl 5.10.1)
Qt          Needed for GUI components (developed with Qt 4.8.0)

DEPLOYING
---------
In both Windows and Linux you need the Qt dynamic libraries available.

In Linux you can do this by putting libQtCore.so.4.5.0 and libQtGui.so.4.5.0 in 
the same directory as the executables and adding the current directory to 
the environment variable LD_LIBRARY_PATH.

In Windows you can do this by putting QtCore4.dll QtGui4.dll in the same 
directory as the executables and also adding the Visual Studio redistributables
to that directory (Microsoft.VC90.CRT.manifest, msvcm90.dll, msvcp90.dll, msvcr90.dll).
That is, assuming you have built a Release executable.

BUILDING FROM SOURCES
---------------------
1. Generate extra sources
        cd MoMEditorTemplate
        perl generate_code.pl
2. Build the MoMCustomizer executable
        cd MoMCustomizer
        qmake                   # To update the location of Qt
        make  or  nmake -f Makefile.Release
3. Build the MoMTweaker executable
        cd MoMTweaker
        qmake                   # To update the location of Qt
        make  or  nmake -f Makefile.Release
4. Alternative you can use Visual Studio to open MoMRTGT.sln and build from there

