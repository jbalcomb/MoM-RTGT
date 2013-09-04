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
    ../../MoMModel/MoMGameCustom.h \
    ../../MoMModel/Generated/MoMGenerated.h \
        ../../Platform/MoMCommon.h \
        ../../Platform/MoMExeBase.h \
        ../../Platform/MoMProcess.h \
    ../../MoMModel/MoMTemplate.h \
    ../../Utility/MoMUtility.h \
    ../../QMoMModel/QMoMTreeItem.h \
    ../../Utility/TeeRedirecter.h
SOURCES += \
    ./mainwindow.cpp \
    ../../MoMModel/MoMGameBase.cpp \
    ../../MoMModel/MoMGameCustom.cpp \
    ../../MoMModel/Generated/MoMGenerated.cpp \
        ../../Platform/MoMExeBase.cpp \
        ../../Platform/MoMProcessCommon.cpp \
        ../../Platform/MoMProcess$${PLATF}.cpp \
    ../../Utility/MoMUtility.cpp \
    ../../QMoMCommon/QMoMTreeItemModel.cpp
FORMS += ./mainwindow.ui
RESOURCES += ../../Resources/InteractiveGameTweaker.qrc
