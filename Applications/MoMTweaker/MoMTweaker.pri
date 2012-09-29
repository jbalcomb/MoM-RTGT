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
        ../../Applications/MoMTweaker

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
    ../../MoMModel/MoMFli.h

SOURCES += \
	../../Applications/MoMTweaker/mainwindow.cpp \
	../../MoMControl/MoMCatnip.cpp \
	../../MoMControl/MoMCombat.cpp \
	../../MoMControl/MoMController.cpp \
	../../MoMControl/MoMHookManager.cpp \
	../../MoMModel/Generated/MoMGenerated.cpp \
	../../MoMModel/MoMExeMagic.cpp \
	../../MoMModel/MoMExeWizards.cpp \
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
	../../QMoMCommon/QMapGraphicsView.cpp \
	../../QMoMCommon/QMoMLbx.cpp \
	../../QMoMCommon/QMoMMapScene.cpp \
	../../QMoMCommon/QMoMMapTile.cpp \
	../../QMoMCommon/QMoMResources.cpp \
	../../QMoMCommon/QMoMSettings.cpp \
	../../QMoMCommon/QMoMTreeCustomExtensions.cpp \
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
    ../../QMoMCommon/QMoMTableItem.cpp \
    ../../QMoMCommon/QMoMTreeItemModel.cpp \
    ../../QMoMCommon/QMoMTreeItemWidget.cpp \
    ../../MoMModel/MoMFli.cpp

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
