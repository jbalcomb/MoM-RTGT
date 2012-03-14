## ---------------------------------------------------------------------------
## Copyright:   2011 Klaas van Aarsen
## License:     GPL
## Author:      I like Serena (aka Klaas van Aarsen)
## Created:     2010-05-01
## ---------------------------------------------------------------------------

HEADERS += ./mainwindow.h \
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
    ../MoMEditorTemplate/MoMutility.h \
    ../MoMEditorTemplate/MoMExeWizards.h \
    ../MoMEditorTemplate/QMoMCommon.h \
    ../MoMEditorTemplate/QMoMGenerated.h \
    ../MoMEditorTemplate/treeitem.h \
    QMoMMapTile.h \
    QMoMResources.h \
    unitmodel.h \
    dialogcalculatoraddress.h \
    dialogselectinitialspells.h \
    dialogbuildingqueues.h \
    dialogtables.h \
    dialogoverlandmap.h \
    dialogaddunit.h \
    dialogtools.h
SOURCES += ./main.cpp \
    ./mainwindow.cpp \
    ../MoMEditorTemplate/MoMController.cpp \
    ../MoMEditorTemplate/MoMGameCustom.cpp \
    ../MoMEditorTemplate/MoMExeBase.cpp \
    ../MoMEditorTemplate/MoMGenerated.cpp \
    ../MoMEditorTemplate/MoMLbxBase.cpp \
    ../MoMEditorTemplate/MoMExeMagic.cpp \
    ../MoMEditorTemplate/MoMGameMemory.cpp \
    ../MoMEditorTemplate/MoMProcessCommon.cpp \
    ../MoMEditorTemplate/MoMGameSave.cpp \
    ../MoMEditorTemplate/MoMutility.cpp \
    ../MoMEditorTemplate/MoMExeWizards.cpp \
    ../MoMEditorTemplate/QMoMCommon.cpp \
    ../MoMEditorTemplate/QMoMGenerated.cpp \
    QMoMMapTile.cpp \
    QMoMResources.cpp \
    unitmodel.cpp \
    dialogcalculatoraddress.cpp \
    dialogselectinitialspells.cpp \
    dialogbuildingqueues.cpp \
    dialogtables.cpp \
    dialogoverlandmap.cpp \
    dialogaddunit.cpp \
    dialogtools.cpp
FORMS += ./mainwindow.ui \
    dialogcalculatoraddress.ui \
    dialogselectinitialspells.ui \
    dialogbuildingqueues.ui \
    dialogtables.ui \
    dialogoverlandmap.ui \
    dialogaddunit.ui \
    dialogtools.ui
RESOURCES += ../Resources/InteractiveGameTweaker.qrc
