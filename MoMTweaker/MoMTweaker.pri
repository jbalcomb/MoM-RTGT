## ---------------------------------------------------------------------------
## Copyright:   2011 Klaas van Aarsen
## License:     GPL
## Author:      I like Serena (aka Klaas van Aarsen)
## Created:     2010-05-01
## ---------------------------------------------------------------------------

HEADERS += \
    ../MoMEditorTemplate/MoMcommon.h \
    ../MoMEditorTemplate/MoMController.h \
    ../MoMEditorTemplate/MoMGameCustom.h \
    ../MoMEditorTemplate/MoMExeBase.h \
    ../MoMEditorTemplate/MoMGameBase.h \
    ../MoMEditorTemplate/MoMGenerated.h \
    ../MoMEditorTemplate/MoMLbxBase.h \
    ../MoMEditorTemplate/MoMExeMagic.h \
    ../MoMEditorTemplate/MoMGameMemory.h \
    ../MoMEditorTemplate/MoMProcess.h \
    ../MoMEditorTemplate/MoMGameSave.h \
    ../MoMEditorTemplate/MoMTemplate.h \
    ../MoMEditorTemplate/MoMUnit.h \
    ../MoMEditorTemplate/MoMUtility.h \
    ../MoMEditorTemplate/MoMExeWizards.h \
    ../MoMEditorTemplate/QMoMGenerated.h \
    ../MoMEditorTemplate/QMoMLbx.h \
    ../MoMEditorTemplate/QMoMMapTile.h \
    ../MoMEditorTemplate/QMoMResources.h \
    ../MoMEditorTemplate/QMoMSharedPointers.h \
    ../MoMEditorTemplate/QMoMTreeItem.h \
    ../MoMEditorTemplate/QMoMUtility.h \
    \
    ../MoMTweaker/dialogcalculatoraddress.h \
    ../MoMTweaker/dialogselectinitialspells.h \
    ../MoMTweaker/dialogbuildingqueues.h \
    ../MoMTweaker/dialogtables.h \
    ../MoMTweaker/dialogoverlandmap.h \
    ../MoMTweaker/dialogaddunit.h \
    ../MoMTweaker/dialogtools.h \
    ../MoMTweaker/mainwindow.h \
    ../MoMTweaker/unitmodel.h

SOURCES += \
    ../MoMEditorTemplate/MoMController.cpp \
    ../MoMEditorTemplate/MoMGameBase.cpp \
    ../MoMEditorTemplate/MoMGameCustom.cpp \
    ../MoMEditorTemplate/MoMGameMemory.cpp \
    ../MoMEditorTemplate/MoMGameSave.cpp \
    ../MoMEditorTemplate/MoMGenerated.cpp \
    ../MoMEditorTemplate/MoMLbxBase.cpp \
    ../MoMEditorTemplate/MoMExeBase.cpp \
    ../MoMEditorTemplate/MoMExeMagic.cpp \
    ../MoMEditorTemplate/MoMExeWizards.cpp \
    ../MoMEditorTemplate/MoMProcessCommon.cpp \
    ../MoMEditorTemplate/MoMUnit.cpp \
    ../MoMEditorTemplate/MoMUtility.cpp \
    ../MoMEditorTemplate/QMoMGenerated.cpp \
    ../MoMEditorTemplate/QMoMLbx.cpp \
    ../MoMEditorTemplate/QMoMMapTile.cpp \
    ../MoMEditorTemplate/QMoMResources.cpp \
    ../MoMEditorTemplate/QMoMTreeItem.cpp \
    ../MoMEditorTemplate/QMoMUtility.cpp \
    \
    ../MoMTweaker/dialogcalculatoraddress.cpp \
    ../MoMTweaker/dialogselectinitialspells.cpp \
    ../MoMTweaker/dialogbuildingqueues.cpp \
    ../MoMTweaker/dialogtables.cpp \
    ../MoMTweaker/dialogoverlandmap.cpp \
    ../MoMTweaker/dialogaddunit.cpp \
    ../MoMTweaker/dialogtools.cpp \
    ../MoMTweaker/mainwindow.cpp \
    ../MoMTweaker/unitmodel.cpp

FORMS += \
    ../MoMTweaker/mainwindow.ui \
    ../MoMTweaker/dialogcalculatoraddress.ui \
    ../MoMTweaker/dialogselectinitialspells.ui \
    ../MoMTweaker/dialogbuildingqueues.ui \
    ../MoMTweaker/dialogtables.ui \
    ../MoMTweaker/dialogoverlandmap.ui \
    ../MoMTweaker/dialogaddunit.ui \
    ../MoMTweaker/dialogtools.ui

RESOURCES += ../Resources/InteractiveGameTweaker.qrc
