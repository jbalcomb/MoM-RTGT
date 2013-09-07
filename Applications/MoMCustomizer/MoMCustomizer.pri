## ---------------------------------------------------------------------------
## Copyright:   2011 Klaas van Aarsen
## License:     GPL
## Author:      I like Serena (aka Klaas van Aarsen)
## Created:     2010-05-01
## ---------------------------------------------------------------------------

INCLUDEPATH += \
    . \
    ../../Applications/MoMCustomizer \
    ../../MoMControl \
    ../../MoMModel \
    ../../MoMModel/Generated \
    ../../Platform \
    ../../QMoMCommon \
    ../../QMoMCommon/Generated \
    ../../QMoMDialogs \
    ../../Utility \
    ../../giflib-5.0.4/lib

HEADERS += ./MainWindow.h \
    ../../MoMModel/Generated/MoMGenerated.h \
    ../../MoMModel/MoMExeMagic.h \
    ../../MoMModel/MoMGameCustom.h \
    ../../MoMModel/MoMLbxBase.h \
    ../../MoMModel/MoMTemplate.h \
    ../../Platform/MoMCommon.h \
    ../../Platform/MoMExeBase.h \
    ../../Platform/MoMProcess.h \
    ../../QMoMCommon/QMoMAnimation.h \
    ../../QMoMCommon/QMoMGifHandler.h \
    ../../QMoMCommon/QMoMLbx.h \
    ../../QMoMCommon/QMoMResources.h \
    ../../Utility/MoMUtility.h \
    ../../Utility/TeeRedirecter.h \
    ../../giflib-5.0.4/lib/gif_stdint.h \
    ../../giflib-5.0.4/lib/gif_unistd.h \
    ../../giflib-5.0.4/lib/gif_lib_private.h \
    ../../giflib-5.0.4/lib/gif_hash.h \
    ../../giflib-5.0.4/lib/gif_lib.h \
    FormSelectWizard.h \
    FormGameOptions.h \
    DialogWizard.h \
    FormWizardsName.h \
    FormMagicPickScreen.h \
    FormSelectSpells.h \
    FormSelectRaces.h \
    FormSelectBanner.h

SOURCES += \
    ./MainWindow.cpp \
    ../../MoMModel/Generated/MoMGenerated.cpp \
    ../../MoMModel/MoMExeMagic.cpp \
    ../../MoMModel/MoMGameBase.cpp \
    ../../MoMModel/MoMGameCustom.cpp \
    ../../MoMModel/MoMLbxBase.cpp \
    ../../Platform/MoMExeBase.cpp \
    ../../Platform/MoMProcessCommon.cpp \
    ../../Platform/MoMProcess$${PLATF}.cpp \
    ../../QMoMCommon/QMoMAnimation.cpp \
    ../../QMoMCommon/QMoMGifHandler.cpp \
    ../../QMoMCommon/QMoMLbx.cpp \
    ../../QMoMCommon/QMoMResources.cpp \
    ../../Utility/MoMUtility.cpp \
    ../../giflib-5.0.4/lib/quantize.cpp \
    ../../giflib-5.0.4/lib/gifalloc.cpp \
    ../../giflib-5.0.4/lib/gif_hash.cpp \
    ../../giflib-5.0.4/lib/gif_font.cpp \
    ../../giflib-5.0.4/lib/gif_err.cpp \
    ../../giflib-5.0.4/lib/egif_lib.cpp \
    ../../giflib-5.0.4/lib/dgif_lib.cpp \
    FormSelectWizard.cpp \
    FormGameOptions.cpp \
    DialogWizard.cpp \
    FormWizardsName.cpp \
    FormMagicPickScreen.cpp \
    FormSelectSpells.cpp \
    FormSelectRaces.cpp \
    FormSelectBanner.cpp

FORMS += ./MainWindow.ui \
    FormSelectWizard.ui \
    FormGameOptions.ui \
    DialogWizard.ui \
    FormWizardsName.ui \
    FormMagicPickScreen.ui \
    FormSelectSpells.ui \
    FormSelectRaces.ui \
    FormSelectBanner.ui

#RESOURCES += Resources/QMoMCustomizer.qrc \
#    ../../Resources/InteractiveGameTweaker.qrc
