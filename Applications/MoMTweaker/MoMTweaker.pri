## ---------------------------------------------------------------------------
## Copyright:   2011 Klaas van Aarsen
## License:     GPL
## Author:      I like Serena (aka Klaas van Aarsen)
## Created:     2010-05-01
## ---------------------------------------------------------------------------

INCLUDEPATH += \
    . \
    ../../Applications/MoMTweaker \
    ../../MoMControl \
    ../../MoMModel \
    ../../MoMModel/Generated \
    ../../Platform \
    ../../QMoMCommon \
    ../../QMoMCommon/Generated \
    ../../QMoMDialogs \
    ../../Utility \
    ../../giflib-5.0.4/lib

HEADERS += \
    ../../Applications/MoMTweaker/mainwindow.h \
    ../../MoMControl/MoMCatnip.h \
    ../../MoMControl/MoMController.h \
    ../../MoMControl/MoMHookManager.h \
    ../../MoMModel/Generated/MoMGenerated.h \
    ../../MoMModel/MoMCombat.h \
    ../../MoMModel/MoMExeMagic.h \
    ../../MoMModel/MoMExeWizards.h \
    ../../MoMModel/MoMGameBase.h \
    ../../MoMModel/MoMGameCustom.h \
    ../../MoMModel/MoMGameMemory.h \
    ../../MoMModel/MoMGameSave.h \
    ../../MoMModel/MoMLbxBase.h \
    ../../MoMModel/MoMLocation.h \
    ../../MoMModel/MoMTemplate.h \
    ../../MoMModel/MoMTerrain.h \
    ../../MoMModel/MoMUnit.h \
    ../../Platform/MoMCommon.h \
    ../../Platform/MoMExeBase.h \
    ../../Platform/MoMProcess.h \
    ../../QMoMCommon/QMapGraphicsView.h \
    ../../QMoMCommon/QMoMLazyIcon.h \
    ../../QMoMCommon/QMoMLbx.h \
    ../../QMoMCommon/QMoMMapScene.h \
    ../../QMoMCommon/QMoMMapTile.h \
    ../../QMoMCommon/QMoMResources.h \
    ../../QMoMCommon/QMoMSettings.h \
    ../../QMoMCommon/QMoMSharedPointers.h \
    ../../QMoMCommon/QMoMTreeCustomExtensions.h \
    ../../QMoMCommon/QMoMUnitTile.h \
    ../../QMoMCommon/QMoMUtility.h \
    ../../QMoMCommon/unitmodel.h \
    ../../QMoMCommon/Generated/QMoMGenerated.h \
    ../../QMoMDialogs/dialogaddunit.h \
    ../../QMoMDialogs/dialogbuildingqueues.h \
    ../../QMoMDialogs/dialogcalculatoraddress.h \
    ../../QMoMDialogs/dialogexternalai.h \
    ../../QMoMDialogs/dialoglbxeditor.h \
    ../../QMoMDialogs/dialogmap.h \
    ../../QMoMDialogs/dialogselectinitialspells.h \
    ../../QMoMDialogs/dialogtables.h \
    ../../QMoMDialogs/dialogtools.h \
    ../../Utility/MoMUtility.h \
    ../../Utility/TeeRedirecter.h \
    ../../QMoMCommon/QMoMTableItem.h \
    ../../QMoMCommon/QMoMTreeItemModel.h \
    ../../QMoMCommon/QMoMTreeItemWidget.h \
    ../../MoMModel/MoMFli.h \
    ../../QMoMCommon/QMoMGifHandler.h \
    ../../QMoMCommon/QMoMAnimation.h \
    ../../QMoMCommon/QMoMAnimationTile.h \
    ../../giflib-5.0.4/lib/gif_stdint.h \
    ../../giflib-5.0.4/lib/gif_unistd.h \
    ../../giflib-5.0.4/lib/gif_lib_private.h \
    ../../giflib-5.0.4/lib/gif_hash.h \
    ../../giflib-5.0.4/lib/gif_lib.h \
    ../../MoMControl/MoMLevelBonuses.h

SOURCES += \
    ../../Applications/MoMTweaker/mainwindow.cpp \
    ../../MoMControl/MoMCatnip.cpp \
    ../../MoMControl/MoMCombat.cpp \
    ../../MoMControl/MoMController.cpp \
    ../../MoMControl/MoMHookManager.cpp \
    ../../MoMModel/Generated/MoMGenerated.cpp \
    ../../MoMModel/MoMExeMagic.cpp \
    ../../MoMModel/MoMExeWizards.cpp \
    ../../MoMModel/MoMFli.cpp \
    ../../MoMModel/MoMGameBase.cpp \
    ../../MoMModel/MoMGameCustom.cpp \
    ../../MoMModel/MoMGameMemory.cpp \
    ../../MoMModel/MoMGameSave.cpp \
    ../../MoMModel/MoMLbxBase.cpp \
    ../../MoMModel/MoMTerrain.cpp \
    ../../MoMModel/MoMUnit.cpp \
    ../../Platform/MoMExeBase.cpp \
    ../../Platform/MoMProcessCommon.cpp \
    ../../Platform/MoMProcess$${PLATF}.cpp \
    ../../QMoMCommon/Generated/QMoMGenerated.cpp \
    ../../QMoMCommon/QMoMAnimation.cpp \
    ../../QMoMCommon/QMoMAnimationTile.cpp \
    ../../QMoMCommon/QMoMGifHandler.cpp \
    ../../QMoMCommon/QMapGraphicsView.cpp \
    ../../QMoMCommon/QMoMLbx.cpp \
    ../../QMoMCommon/QMoMMapScene.cpp \
    ../../QMoMCommon/QMoMMapTile.cpp \
    ../../QMoMCommon/QMoMResources.cpp \
    ../../QMoMCommon/QMoMSettings.cpp \
    ../../QMoMCommon/QMoMTableItem.cpp \
    ../../QMoMCommon/QMoMTreeCustomExtensions.cpp \
    ../../QMoMCommon/QMoMTreeItemModel.cpp \
    ../../QMoMCommon/QMoMTreeItemWidget.cpp \
    ../../QMoMCommon/QMoMUnitTile.cpp \
    ../../QMoMCommon/QMoMUtility.cpp \
    ../../QMoMCommon/unitmodel.cpp \
    ../../QMoMDialogs/dialogaddunit.cpp \
    ../../QMoMDialogs/dialogbuildingqueues.cpp \
    ../../QMoMDialogs/dialogcalculatoraddress.cpp \
    ../../QMoMDialogs/dialogexternalai.cpp \
    ../../QMoMDialogs/dialoglbxeditor.cpp \
    ../../QMoMDialogs/dialogmap.cpp \
    ../../QMoMDialogs/dialogselectinitialspells.cpp \
    ../../QMoMDialogs/dialogtables.cpp \
    ../../QMoMDialogs/dialogtools.cpp \
    ../../Utility/MoMUtility.cpp \
    ../../giflib-5.0.4/lib/quantize.cpp \
    ../../giflib-5.0.4/lib/gifalloc.cpp \
    ../../giflib-5.0.4/lib/gif_hash.cpp \
    ../../giflib-5.0.4/lib/gif_font.cpp \
    ../../giflib-5.0.4/lib/gif_err.cpp \
    ../../giflib-5.0.4/lib/egif_lib.cpp \
    ../../giflib-5.0.4/lib/dgif_lib.cpp \
    ../../MoMControl/MoMLevelBonuses.cpp

FORMS += \
    ../../Applications/MoMTweaker/mainwindow.ui \
    ../../QMoMDialogs/dialogaddunit.ui \
    ../../QMoMDialogs/dialogbuildingqueues.ui \
    ../../QMoMDialogs/dialogcalculatoraddress.ui \
    ../../QMoMDialogs/dialogexternalai.ui \
    ../../QMoMDialogs/dialoglbxeditor.ui \
    ../../QMoMDialogs/dialogmap.ui \
    ../../QMoMDialogs/dialogselectinitialspells.ui \
    ../../QMoMDialogs/dialogtables.ui \
    ../../QMoMDialogs/dialogtools.ui

RESOURCES += ../../Resources/InteractiveGameTweaker.qrc
