mkdir -p Platform/
mkdir -p MoMControl/
mkdir -p MoMModel/
mkdir -p MoMModel/Generated/
mkdir -p Utility/
mkdir -p QMoMCommon/
mkdir -p QMoMCommon/Generated/
mkdir -p QMoMDialogs/

mkdir -p Applications/Common/
mkdir -p Applications/MindyEngine/Generated/
mkdir -p Applications/MindyEngine/Examples/
mkdir -p Applications/MoMTweaker/Generated/
mkdir -p Applications/MoMCustomizer/Generated/
mkdir -p Applications/MoMTest/Generated/
mkdir -p Applications/MoMTest/out/
mkdir -p Applications/MoMTest/Test/

#TODO
#./MoMEditorTemplate/MoMEditorTemplate.sln
#./MoMEditorTemplate/MoMEditorTemplate.vcproj
#./MoMEditorTemplate/main.cpp

#TODO
mv ./MoMEditorTemplate/generate_code.pl scripts/

mv ./MoMCore/MoMCore.cpp Applications/MindyEngine/
mv ./MoMCore/MoMCore.h Applications/MindyEngine/
mv ./MoMCore/MoMCore.pro Applications/MindyEngine/
mv ./swig/BUILD_MOM.bat Applications/MindyEngine/
mv ./swig/example_momai.py Applications/MindyEngine/
mv ./swig/example_momgame.py Applications/MindyEngine/
mv ./swig/example_momhook.py Applications/MindyEngine/
mv ./swig/example_momprocess.py Applications/MindyEngine/
mv ./swig/mom.i Applications/MindyEngine/
mv ./swig/README.txt Applications/MindyEngine/

mv ./MoMCustomizer/CHANGES.txt Applications/MoMCustomizer/
mv ./MoMCustomizer/MoMCustomizer.pri Applications/MoMCustomizer/
mv ./MoMCustomizer/MoMCustomizer.pro Applications/MoMCustomizer/
mv ./MoMCustomizer/MoMCustomizer.vcproj Applications/MoMCustomizer/
mv ./MoMCustomizer/main.cpp    Applications/MoMCustomizer/
mv ./MoMCustomizer/mainwindow.cpp    Applications/MoMCustomizer/
mv ./MoMCustomizer/mainwindow.h    Applications/MoMCustomizer/
mv ./MoMCustomizer/mainwindow.ui    Applications/MoMCustomizer/
mv ./MoMCustomizer/MoMCustomizer_resource.rc Applications/MoMCustomizer/

mv ./MoMTweaker/CHANGES.txt    Applications/MoMTweaker/
mv ./MoMTweaker/main.cpp    Applications/MoMTweaker/
mv ./MoMTweaker/mainwindow.cpp    Applications/MoMTweaker/
mv ./MoMTweaker/mainwindow.h    Applications/MoMTweaker/
mv ./MoMTweaker/mainwindow.ui    Applications/MoMTweaker/
mv ./MoMTweaker/MoMTweaker.pri    Applications/MoMTweaker/
mv ./MoMTweaker/MoMTweaker.pro    Applications/MoMTweaker/
mv ./MoMTweaker/MoMTweaker.vcproj    Applications/MoMTweaker/
mv ./MoMTweaker/MoMTweaker_resource.rc    Applications/MoMTweaker/

mv ./MoMTest/MoMTest.pro    Applications/MoMTest/
mv ./MoMTest/MoMTest.vcproj    Applications/MoMTest/
mv ./MoMTest/out/*.ref    Applications/MoMTest/out/
mv ./MoMTest/REFTEST.GAM    Applications/MoMTest/
mv ./MoMTest/qrc_InteractiveGameTweaker.cpp    Applications/MoMTest/Test/
mv ./MoMTest/test_main.cpp    Applications/MoMTest/Test/
mv ./MoMTest/test_utility.cpp    Applications/MoMTest/Test/
mv ./MoMTest/test_utility.h    Applications/MoMTest/Test/
mv ./MoMTest/tst_momcombat.cpp    Applications/MoMTest/Test/
mv ./MoMTest/tst_momgamebase.cpp    Applications/MoMTest/Test/
mv ./MoMTest/tst_momtweaker_mainwindow.cpp    Applications/MoMTest/Test/


mv ./MoMEditorTemplate/MoMCommon.h   Platform/
mv ./MoMEditorTemplate/MoMProcess.h   Platform/
mv ./MoMEditorTemplate/MoMProcessCommon.cpp   Platform/
mv ./MoMEditorTemplate/MoMProcessLinux.cpp   Platform/
mv ./MoMEditorTemplate/MoMProcessWindows.cpp   Platform/

mv ./MoMEditorTemplate/MoMCatnip.cpp   MoMControl/
mv ./MoMEditorTemplate/MoMCatnip.h   MoMControl/
mv ./MoMEditorTemplate/MoMCombat.cpp   MoMControl/
mv ./MoMEditorTemplate/MoMCombat.h   MoMModel/
mv ./MoMEditorTemplate/MoMController.cpp   MoMControl/
mv ./MoMEditorTemplate/MoMController.h   MoMControl/
mv ./MoMEditorTemplate/MoMHookManager.cpp   MoMControl/
mv ./MoMEditorTemplate/MoMHookManager.h   MoMControl/

mv ./MoMEditorTemplate/MoMExeBase.cpp    MoMModel/
mv ./MoMEditorTemplate/MoMExeBase.h   MoMModel/
mv ./MoMEditorTemplate/MoMExeMagic.cpp    MoMModel/
mv ./MoMEditorTemplate/MoMExeMagic.h   MoMModel/
mv ./MoMEditorTemplate/MoMExeWizards.cpp    MoMModel/
mv ./MoMEditorTemplate/MoMExeWizards.h   MoMModel/
mv ./MoMEditorTemplate/MoMGameBase.cpp    MoMModel/
mv ./MoMEditorTemplate/MoMGameBase.h   MoMModel/
mv ./MoMEditorTemplate/MoMGameCustom.cpp    MoMModel/
mv ./MoMEditorTemplate/MoMGameCustom.h   MoMModel/
mv ./MoMEditorTemplate/MoMGameMemory.cpp    MoMModel/
mv ./MoMEditorTemplate/MoMGameMemory.h   MoMModel/
mv ./MoMEditorTemplate/MoMGameSave.cpp    MoMModel/
mv ./MoMEditorTemplate/MoMGameSave.h   MoMModel/
mv ./MoMEditorTemplate/MoMLbxBase.cpp    MoMModel/
mv ./MoMEditorTemplate/MoMLbxBase.h   MoMModel/
mv ./MoMEditorTemplate/MoMLocation.h   MoMModel/
mv ./MoMEditorTemplate/MoMTemplate.h   MoMModel/
mv ./MoMEditorTemplate/MoMTerrain.cpp    MoMModel/
mv ./MoMEditorTemplate/MoMTerrain.h   MoMModel/
mv ./MoMEditorTemplate/MoMUnit.cpp    MoMModel/
mv ./MoMEditorTemplate/MoMUnit.h   MoMModel/

mv ./MoMEditorTemplate/MoMGenerated.cpp    MoMModel/Generated/
mv ./MoMEditorTemplate/MoMGenerated.h   MoMModel/Generated/


mv ./MoMEditorTemplate/MoMUtility.cpp   Utility/
mv ./MoMEditorTemplate/MoMUtility.h   Utility/
mv ./MoMEditorTemplate/TeeRedirecter.h   Utility/

mv ./MoMEditorTemplate/QMapGraphicsView.cpp    QMoMCommon/
mv ./MoMEditorTemplate/QMapGraphicsView.h    QMoMCommon/
mv ./MoMEditorTemplate/QMoMLazyIcon.h    QMoMCommon/
mv ./MoMEditorTemplate/QMoMLbx.cpp    QMoMCommon/
mv ./MoMEditorTemplate/QMoMLbx.h    QMoMCommon/
mv ./MoMEditorTemplate/QMoMMapScene.cpp    QMoMCommon/
mv ./MoMEditorTemplate/QMoMMapScene.h    QMoMCommon/
mv ./MoMEditorTemplate/QMoMMapTile.cpp    QMoMCommon/
mv ./MoMEditorTemplate/QMoMMapTile.h    QMoMCommon/
mv ./MoMEditorTemplate/QMoMResources.cpp    QMoMCommon/
mv ./MoMEditorTemplate/QMoMResources.h    QMoMCommon/
mv ./MoMEditorTemplate/QMoMSettings.cpp    QMoMCommon/
mv ./MoMEditorTemplate/QMoMSettings.h    QMoMCommon/
mv ./MoMEditorTemplate/QMoMSharedPointers.h    QMoMCommon/
mv ./MoMEditorTemplate/QMoMTreeItem.cpp    QMoMCommon/
mv ./MoMEditorTemplate/QMoMTreeItem.h    QMoMCommon/
mv ./MoMEditorTemplate/QMoMUnitTile.cpp    QMoMCommon/
mv ./MoMEditorTemplate/QMoMUnitTile.h    QMoMCommon/
mv ./MoMEditorTemplate/QMoMUtility.cpp    QMoMCommon/
mv ./MoMEditorTemplate/QMoMUtility.h    QMoMCommon/
mv ./MoMTweaker/QMoMTreeCustomExtensions.cpp    QMoMCommon/
mv ./MoMTweaker/QMoMTreeCustomExtensions.h    QMoMCommon/
mv ./MoMTweaker/unitmodel.cpp    QMoMCommon/
mv ./MoMTweaker/unitmodel.h    QMoMCommon/

mv ./MoMEditorTemplate/QMoMGenerated.cpp    QMoMCommon/Generated/
mv ./MoMEditorTemplate/QMoMGenerated.h    QMoMCommon/Generated/

mv ./MoMTweaker/dialogaddunit.cpp   QMoMDialogs/
mv ./MoMTweaker/dialogaddunit.h   QMoMDialogs/
mv ./MoMTweaker/dialogaddunit.ui   QMoMDialogs/
mv ./MoMTweaker/dialogbuildingqueues.cpp   QMoMDialogs/
mv ./MoMTweaker/dialogbuildingqueues.h   QMoMDialogs/
mv ./MoMTweaker/dialogbuildingqueues.ui   QMoMDialogs/
mv ./MoMTweaker/dialogcalculatoraddress.cpp   QMoMDialogs/
mv ./MoMTweaker/dialogcalculatoraddress.h   QMoMDialogs/
mv ./MoMTweaker/dialogcalculatoraddress.ui   QMoMDialogs/
mv ./MoMTweaker/dialogexternalai.cpp   QMoMDialogs/
mv ./MoMTweaker/dialogexternalai.h   QMoMDialogs/
mv ./MoMTweaker/dialogexternalai.ui   QMoMDialogs/
mv ./MoMTweaker/dialoglbxeditor.cpp   QMoMDialogs/
mv ./MoMTweaker/dialoglbxeditor.h   QMoMDialogs/
mv ./MoMTweaker/dialoglbxeditor.ui   QMoMDialogs/
mv ./MoMTweaker/dialogmap.cpp   QMoMDialogs/
mv ./MoMTweaker/dialogmap.h   QMoMDialogs/
mv ./MoMTweaker/dialogmap.ui   QMoMDialogs/
mv ./MoMTweaker/dialogselectinitialspells.cpp   QMoMDialogs/
mv ./MoMTweaker/dialogselectinitialspells.h   QMoMDialogs/
mv ./MoMTweaker/dialogselectinitialspells.ui   QMoMDialogs/
mv ./MoMTweaker/dialogtables.cpp   QMoMDialogs/
mv ./MoMTweaker/dialogtables.h   QMoMDialogs/
mv ./MoMTweaker/dialogtables.ui   QMoMDialogs/
mv ./MoMTweaker/dialogtools.cpp   QMoMDialogs/
mv ./MoMTweaker/dialogtools.h   QMoMDialogs/
mv ./MoMTweaker/dialogtools.ui   QMoMDialogs/
