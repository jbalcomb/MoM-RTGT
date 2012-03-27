## ---------------------------------------------------------------------------
## Copyright:   2011 Klaas van Aarsen
## License:     GPL
## Author:      I like Serena (aka Klaas van Aarsen)
## Created:     2010-05-01
## ---------------------------------------------------------------------------


HEADERS += ./mainwindow.h \
    ../MoMEditorTemplate/MoMGameCustom.h \
    ../MoMEditorTemplate/MoMcommon.h \
    ../MoMEditorTemplate/MoMExeBase.h \
    ../MoMEditorTemplate/MoMGenerated.h \
    ../MoMEditorTemplate/MoMExeMagic.h \
    ../MoMEditorTemplate/MoMProcess.h \
    ../MoMEditorTemplate/MoMTemplate.h \
    ../MoMEditorTemplate/MoMUtility.h \
    ../MoMEditorTemplate/QMoMTreeItem.h
SOURCES += \
    ./mainwindow.cpp \
    ../MoMEditorTemplate/MoMGameBase.cpp \
    ../MoMEditorTemplate/MoMGameCustom.cpp \
    ../MoMEditorTemplate/MoMExeBase.cpp \
    ../MoMEditorTemplate/MoMGenerated.cpp \
    ../MoMEditorTemplate/MoMExeMagic.cpp \
    ../MoMEditorTemplate/MoMProcessCommon.cpp \
    ../MoMEditorTemplate/MoMUtility.cpp \
    ../MoMEditorTemplate/QMoMTreeItem.cpp
FORMS += ./mainwindow.ui
RESOURCES += ../Resources/InteractiveGameTweaker.qrc
