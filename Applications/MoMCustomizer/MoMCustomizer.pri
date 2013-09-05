## ---------------------------------------------------------------------------
## Copyright:   2011 Klaas van Aarsen
## License:     GPL
## Author:      I like Serena (aka Klaas van Aarsen)
## Created:     2010-05-01
## ---------------------------------------------------------------------------

INCLUDEPATH += \
        . \
        ../../Applications/MoMCustomizer \
        ../../Platform \
        ../../MoMControl \
        ../../MoMModel \
        ../../Utility \
        ../../QMoMCommon \
        ../../QMoMCommon/Generated \
        ../../QMoMDialogs \
        ../../MoMModel/Generated

HEADERS += ./mainwindow.h \
        ../../MoMModel/Generated/MoMGenerated.h \
        ../../MoMModel/MoMExeMagic.h \
        ../../MoMModel/MoMGameCustom.h \
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
        ../../MoMModel/Generated/MoMGenerated.cpp \
        ../../MoMModel/MoMExeMagic.cpp \
        ../../MoMModel/MoMGameBase.cpp \
        ../../MoMModel/MoMGameCustom.cpp \
        ../../MoMModel/MoMLbxBase.cpp \
        ../../Platform/MoMExeBase.cpp \
        ../../Platform/MoMProcessCommon.cpp \
        ../../Platform/MoMProcess$${PLATF}.cpp \
        ../../QMoMCommon/QMoMLbx.cpp \
        ../../QMoMCommon/QMoMTreeItemModel.cpp \
        ../../Utility/MoMUtility.cpp
FORMS += ./mainwindow.ui
RESOURCES += ../../Resources/InteractiveGameTweaker.qrc
