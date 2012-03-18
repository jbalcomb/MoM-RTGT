## ---------------------------------------------------------------------------
## Copyright:   2011 Klaas van Aarsen
## License:     GPL
## Author:      I like Serena (aka Klaas van Aarsen)
## Created:     2010-05-01
## ---------------------------------------------------------------------------

CPPFLAGS=-I.

SRC=\
	main.cpp\
	MoMController.cpp\
	MoMExeBase.cpp\
	MoMGenerated.cpp\
	MoMLbxBase.cpp\
	MoMExeMagic.cpp\
	MoMGameMemory.cpp\
	MoMProcessCommon.cpp\
	MoMGameSave.cpp\
	MoMutility.cpp\
	MoMExeWizards.cpp

CXXFLAGS=-g -fshort-enums -Wno-unused-parameter
# -fpack-struct

all:	${SRC}
	g++ ${CPPFLAGS} ${CXXFLAGS} -o IGTconsole ${SRC} MoMProcessLinux.cpp

win:	${SRC}
	i586-mingw32msvc-g++ ${INCLUDES} -D_WIN32 ${CPPFLAGS} ${CXXFLAGS} -std=gnu++0x -o IGTconsole.exe ${SRC} MoMProcessWindows.cpp

GENERATEDFILES= \
    MoMGenerated.cpp \
    MoMGenerated.h \
    QMoMGenerated.cpp \
    QMoMGenerated.h

generate: $(GENERATEDFILES)

$(GENERATEDFILES):: MoMcommon.h MoMTemplate.h generate_code.pl
	perl -w generate_code.pl

