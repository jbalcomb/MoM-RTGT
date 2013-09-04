## ---------------------------------------------------------------------------
## Copyright:   2011 Klaas van Aarsen
## License:     GPL
## Author:      I like Serena (aka Klaas van Aarsen)
## Created:     2010-05-01
## ---------------------------------------------------------------------------

INCLUDEPATH += \
        . \
        ../../Platform \
        ../../MoMControl \
        ../../MoMModel \
        ../../MoMModel/Generated \
        ../../Utility \
        ../../QMoMCommon \
        ../../QMoMCommon/Generated \
        ../../QMoMDialogs \
        ../../Applications/MoMCustomizer

HEADERS += ./mainwindow.h \
        ../../MoMModel/MoMExeMagic.h \
    ../../MoMModel/MoMGameCustom.h \
    ../../MoMModel/Generated/MoMGenerated.h \
        ../../MoMModel/MoMLbxBase.h \
    ../../MoMModel/MoMTemplate.h \
        ../../Platform/MoMCommon.h \
        ../../Platform/MoMExeBase.h \
        ../../Platform/MoMProcess.h \
    ../../QMoMCommon/QMoMLbx.h \
    ../../QMoMCommon/QMoMTreeItemModel.h \
    ../../Utility/MoMUtility.h \
    ../../Utility/TeeRedirecter.h
SOURCES += \
    ./mainwindow.cpp \
        ../../MoMModel/MoMExeMagic.cpp \
    ../../MoMModel/MoMGameBase.cpp \
    ../../MoMModel/MoMGameCustom.cpp \
        ../../MoMModel/MoMLbxBase.cpp \
    ../../MoMModel/Generated/MoMGenerated.cpp \
        ../../Platform/MoMExeBase.cpp \
        ../../Platform/MoMProcessCommon.cpp \
        ../../Platform/MoMProcess$${PLATF}.cpp \
    ../../QMoMCommon/QMoMLbx.cpp \
    ../../QMoMCommon/QMoMTreeItemModel.cpp \
    ../../Utility/MoMUtility.cpp
FORMS += ./mainwindow.ui
RESOURCES += ../../Resources/InteractiveGameTweaker.qrc
