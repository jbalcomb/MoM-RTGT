// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2011-04-03
// ---------------------------------------------------------------------------

SUPPORTED PLATFORMS
-------------------
Windows     Developed and tested with Windows XP and Windows 7 
			with Visual Studio 2008 
			and also with QtCreator with MinGW
Linux       Developed and tested with Ubuntu 10.04 LTS (with g++ 4.4.3)

DEPENDENCIES
------------
perl        Needed to generate sources (developed with perl 5.10.1)
Qt          Needed for GUI components (developed with Qt 4.8.0)


DEPLOYING
=========
In both Windows and Linux you need the Qt dynamic libraries available.

In Windows you can do this by putting QtCore4.dll QtGui4.dll in the same 
directory as the executables and also adding the Visual Studio redistributables
to that directory (Microsoft.VC90.CRT.manifest, msvcm90.dll, msvcp90.dll, msvcr90.dll).
That is, assuming you have built a Release executable, because a Debug executable
has different dependencies.

In Linux you can do this by putting libQtCore.so.4.8.0 and libQtGui.so.4.8.0 in 
the same directory as the executables and adding the current directory to 
the environment variable LD_LIBRARY_PATH.


BUILDING FROM SOURCES
=====================
Windows
-------
1. Install compiler.
   Either Microsoft's Visual Studio 2008 (commercial), 
   or QtCreator with MinGW (opensource), 
   or both.
		You can download QtCreator with MinGW from: http://qt.nokia.com/downloads/
2. Install the so called Qt Libraries if you didn't already do so in step 1.
		Download from: http://qt.nokia.com/downloads/
3. Install Perl for Windows.
		Download for Windows from: http://www.activestate.com/activeperl/downloads
4. Generate extra sources
        cd MoMEditorTemplate
        perl generate_code.pl
5. Build the MoMCustomizer executable
        cd MoMCustomizer
        qmake                   # To update the location of Qt
        make  or  nmake -f Makefile.Release
6. Build the MoMTweaker executable
        cd MoMTweaker
        qmake                   # To update the location of Qt
        make  or  nmake -f Makefile.Release
7. Alternative you can use Visual Studio to open MoMRTGT.sln and build from there.
   Or you can use QtCreator to open MoMCustomizer/MoMCustomizer.pro 
   or MoMTweaker/MoMTweaker.pro and build from there.

Linux
-----
1. Install QtCreator for g++ (opensource).
   This is optional.
		You can download QtCreator for g++ from: http://qt.nokia.com/downloads/
2. Install the so called Qt Libraries if you didn't already do so in step 1.
		Download from: http://qt.nokia.com/downloads/
3. You should already have Perl, or else you need to install it from you distribution.
4. Generate extra sources
        cd MoMEditorTemplate
        perl generate_code.pl
5. Build the MoMCustomizer executable
        cd MoMCustomizer
        qmake                   # To update the location of Qt
        make  or  nmake -f Makefile.Release
6. Build the MoMTweaker executable
        cd MoMTweaker
        qmake                   # To update the location of Qt
        make  or  nmake -f Makefile.Release
7. Alternative you can use QtCreator to open MoMCustomizer/MoMCustomizer.pro 
   or MoMTweaker/MoMTweaker.pro and build from there.
