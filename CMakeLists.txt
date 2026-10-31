# ---------------------------------------------------------------------------
# MoM-RTGT - Master of Magic Real-Time Game Tweaker
#
#   rtgt_core       Qt-free game model, controller and platform layer
#   rtgt_tests      doctest unit tests for rtgt_core
#   MoMTweaker      Qt5 GUI      (optional, RTGT_BUILD_QT_APPS)
#   MoMCustomizer   Qt5 GUI      (optional, RTGT_BUILD_QT_APPS)
#
# The qmake projects (*.pro) remain until the Qt GUI is retired.
# ---------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.16)

project(MoM-RTGT VERSION 0.3.4 LANGUAGES CXX)

option(RTGT_BUILD_TESTS   "Build the core unit tests" ON)
option(RTGT_BUILD_QT_APPS "Build the Qt5 applications MoMTweaker and MoMCustomizer" OFF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type" FORCE)
endif()

# Put all executables in one directory so they can be zipped as-is.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(WIN32)
    set(RTGT_PLATFORM Windows)
elseif(APPLE)
    set(RTGT_PLATFORM MacOS)
else()
    set(RTGT_PLATFORM Linux)
endif()
message(STATUS "MoM-RTGT platform layer: ${RTGT_PLATFORM}")

# Compiler settings shared by every target (mirrors Common.pri)
add_library(rtgt_options INTERFACE)
target_compile_definitions(rtgt_options INTERFACE _CRT_SECURE_NO_WARNINGS)
if(MSVC)
    target_compile_options(rtgt_options INTERFACE /W3 /MP /Zc:__cplusplus)  # MoMTemplate.h checks __cplusplus
else()
    target_compile_options(rtgt_options INTERFACE
        -fno-strict-aliasing -Wall -Wno-unused-parameter -Wno-sign-compare
        -Wno-address-of-packed-member)  # the game structs are packed by design
endif()

# ---------------------------------------------------------------------------
# Core library (no Qt)
# ---------------------------------------------------------------------------
add_library(rtgt_core STATIC
    MoMControl/MoMCatnip.cpp
    MoMControl/MoMCombat.cpp
    MoMControl/MoMController.cpp
    MoMControl/MoMHookManager.cpp
    MoMControl/MoMLevelBonuses.cpp
    MoMControl/MoMManageCities.cpp
    MoMModel/Generated/MoMGenerated.cpp
    MoMModel/MoMCity.cpp
    MoMModel/MoMExeMagic.cpp
    MoMModel/MoMExeWizards.cpp
    MoMModel/MoMFli.cpp
    MoMModel/MoMGameBase.cpp
    MoMModel/MoMGameCustom.cpp
    MoMModel/MoMGameMemory.cpp
    MoMModel/MoMGameSave.cpp
    MoMModel/MoMLbxBase.cpp
    MoMModel/MoMTerrain.cpp
    MoMModel/MoMUnit.cpp
    Platform/MoMExeBase.cpp
    Platform/MoMProcessCommon.cpp
    Platform/MoMProcess${RTGT_PLATFORM}.cpp
    Utility/MoMUtility.cpp
)
target_include_directories(rtgt_core PUBLIC
    MoMControl
    MoMModel
    MoMModel/Generated
    Platform
    Utility
    better-enums-0.11.2
)
target_link_libraries(rtgt_core PUBLIC rtgt_options)
if(WIN32)
    target_link_libraries(rtgt_core PUBLIC user32)
endif()

# ---------------------------------------------------------------------------
# Code generation from MoMModel/MoMTemplate.h
#   The generated sources are committed; regenerate them after changing
#   the template with:  cmake --build build --target rtgt_generate
# ---------------------------------------------------------------------------
find_package(Python3 COMPONENTS Interpreter)
if(Python3_Interpreter_FOUND)
    add_custom_target(rtgt_generate
        COMMAND Python3::Interpreter ${PROJECT_SOURCE_DIR}/scripts/generate_code.py
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        COMMENT "Regenerating sources from MoMTemplate.h"
        VERBATIM)
endif()

# ---------------------------------------------------------------------------
# Tests
# ---------------------------------------------------------------------------
if(RTGT_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
    if(Python3_Interpreter_FOUND)
        add_test(NAME generated_code_up_to_date
            COMMAND Python3::Interpreter ${PROJECT_SOURCE_DIR}/scripts/generate_code.py --check)
    endif()
endif()

# ---------------------------------------------------------------------------
# Qt5 applications (to be replaced by the Dear ImGui front end)
# ---------------------------------------------------------------------------
if(RTGT_BUILD_QT_APPS)
    find_package(Qt5 5.9 REQUIRED COMPONENTS Core Gui Widgets)

    add_library(rtgt_giflib STATIC
        giflib-5.0.4/lib/dgif_lib.cpp
        giflib-5.0.4/lib/egif_lib.cpp
        giflib-5.0.4/lib/gif_err.cpp
        giflib-5.0.4/lib/gif_font.cpp
        giflib-5.0.4/lib/gif_hash.cpp
        giflib-5.0.4/lib/gifalloc.cpp
        giflib-5.0.4/lib/quantize.cpp
    )
    target_include_directories(rtgt_giflib PUBLIC giflib-5.0.4/lib)
    target_link_libraries(rtgt_giflib PRIVATE rtgt_options)

    # The Qt dialogs refer back to the MoMTweaker MainWindow, so they are
    # compiled into the executable instead of a separate library (as in qmake).
    file(GLOB RTGT_QT_COMMON_SOURCES CONFIGURE_DEPENDS
        QMoMCommon/*.cpp QMoMCommon/Generated/*.cpp)
    file(GLOB RTGT_QT_DIALOG_SOURCES CONFIGURE_DEPENDS
        QMoMDialogs/*.cpp QMoMDialogs/*.ui)

    add_executable(MoMTweaker WIN32
        Applications/MoMTweaker/main.cpp
        Applications/MoMTweaker/MainWindow.cpp
        Applications/MoMTweaker/MainWindow.ui
        ${RTGT_QT_COMMON_SOURCES}
        ${RTGT_QT_DIALOG_SOURCES}
        Resources/InteractiveGameTweaker.qrc
    )
    set_target_properties(MoMTweaker PROPERTIES
        AUTOMOC ON AUTOUIC ON AUTORCC ON
        AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/QMoMDialogs;${CMAKE_CURRENT_SOURCE_DIR}/Applications/MoMTweaker")
    target_include_directories(MoMTweaker PRIVATE
        Applications/MoMTweaker QMoMCommon QMoMCommon/Generated QMoMDialogs)
    target_compile_definitions(MoMTweaker PRIVATE VERSION="${PROJECT_VERSION}")
    target_link_libraries(MoMTweaker PRIVATE rtgt_core rtgt_giflib Qt5::Widgets)

    add_executable(MoMCustomizer WIN32
        Applications/MoMCustomizer/main.cpp
        Applications/MoMCustomizer/MainWindow.cpp
        Applications/MoMCustomizer/MainWindow.ui
        Applications/MoMCustomizer/DialogWizard.cpp
        Applications/MoMCustomizer/DialogWizard.ui
        Applications/MoMCustomizer/FormGameOptions.cpp
        Applications/MoMCustomizer/FormGameOptions.ui
        Applications/MoMCustomizer/FormMagicPickScreen.cpp
        Applications/MoMCustomizer/FormMagicPickScreen.ui
        Applications/MoMCustomizer/FormSelectBanner.cpp
        Applications/MoMCustomizer/FormSelectBanner.ui
        Applications/MoMCustomizer/FormSelectRaces.cpp
        Applications/MoMCustomizer/FormSelectRaces.ui
        Applications/MoMCustomizer/FormSelectSpells.cpp
        Applications/MoMCustomizer/FormSelectSpells.ui
        Applications/MoMCustomizer/FormSelectWizard.cpp
        Applications/MoMCustomizer/FormSelectWizard.ui
        Applications/MoMCustomizer/FormWizardsName.cpp
        Applications/MoMCustomizer/FormWizardsName.ui
        QMoMCommon/QMoMAnimation.cpp
        QMoMCommon/QMoMGifHandler.cpp
        QMoMCommon/QMoMLbx.cpp
        QMoMCommon/QMoMResources.cpp
        Applications/MoMCustomizer/Resources/QMoMCustomizer.qrc
        Resources/InteractiveGameTweaker.qrc
    )
    set_target_properties(MoMCustomizer PROPERTIES AUTOMOC ON AUTOUIC ON AUTORCC ON)
    target_include_directories(MoMCustomizer PRIVATE Applications/MoMCustomizer QMoMCommon)
    target_compile_definitions(MoMCustomizer PRIVATE VERSION="0.3.1")
    target_link_libraries(MoMCustomizer PRIVATE rtgt_core rtgt_giflib Qt5::Widgets)
endif()
