# ---------------------------------------------------------------------------
# MoM-RTGT Dear ImGui application
#
#   rtgt_imgui   Dear ImGui (docking branch)
#   rtgt_ui      the user interface (panels, app state); no window system, testable headless
#   MoM-RTGT     the executable: SDL2 window + OpenGL 3 renderer
#
# Dependencies are pinned and downloaded at configure time with FetchContent.
# To build offline, point FETCHCONTENT_SOURCE_DIR_IMGUI / FETCHCONTENT_SOURCE_DIR_SDL2
# at local checkouts of the same tags.
# ---------------------------------------------------------------------------

include(FetchContent)

set(RTGT_IMGUI_TAG v1.92.9b-docking)
set(RTGT_SDL2_TAG release-2.32.10)

# Dear ImGui -----------------------------------------------------------------
FetchContent_Declare(imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG        ${RTGT_IMGUI_TAG}
    GIT_SHALLOW    TRUE)
FetchContent_MakeAvailable(imgui)

add_library(rtgt_imgui STATIC
    ${imgui_SOURCE_DIR}/imgui.cpp
    ${imgui_SOURCE_DIR}/imgui_demo.cpp
    ${imgui_SOURCE_DIR}/imgui_draw.cpp
    ${imgui_SOURCE_DIR}/imgui_tables.cpp
    ${imgui_SOURCE_DIR}/imgui_widgets.cpp
    ImGuiAssert.cpp)
target_include_directories(rtgt_imgui PUBLIC ${imgui_SOURCE_DIR} ${imgui_SOURCE_DIR}/backends ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(rtgt_imgui PUBLIC IMGUI_USER_CONFIG="rtgt_imconfig.h")
target_compile_features(rtgt_imgui PUBLIC cxx_std_17)
set(RTGT_IMGUI_SOURCE_DIR ${imgui_SOURCE_DIR} PARENT_SCOPE)

# User interface ---------------------------------------------------------------
add_library(rtgt_ui STATIC
    FileBrowser.cpp
    LogCapture.cpp
    RtgtApp.cpp)
target_include_directories(rtgt_ui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(rtgt_ui PRIVATE RTGT_VERSION="${PROJECT_VERSION}")
target_compile_features(rtgt_ui PUBLIC cxx_std_17)
target_link_libraries(rtgt_ui PUBLIC rtgt_core rtgt_imgui)

# SDL2: an installed SDL2 if there is one, otherwise build it statically ------
option(RTGT_FETCH_SDL2 "Always download and build SDL2 statically (for portable release builds)" OFF)
if(NOT RTGT_FETCH_SDL2)
    find_package(SDL2 2.0.18 CONFIG QUIET)
endif()
if(TARGET SDL2::SDL2)
    message(STATUS "MoM-RTGT: using installed SDL2 ${SDL2_VERSION}")
    set(RTGT_SDL2_TARGET SDL2::SDL2)
else()
    message(STATUS "MoM-RTGT: building SDL2 ${RTGT_SDL2_TAG} statically")
    set(SDL_SHARED OFF CACHE BOOL "" FORCE)
    set(SDL_STATIC ON CACHE BOOL "" FORCE)
    set(SDL_TEST OFF CACHE BOOL "" FORCE)
    set(SDL2_DISABLE_INSTALL ON CACHE BOOL "" FORCE)
    FetchContent_Declare(SDL2
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG        ${RTGT_SDL2_TAG}
        GIT_SHALLOW    TRUE)
    FetchContent_MakeAvailable(SDL2)
    set(RTGT_SDL2_TARGET SDL2::SDL2-static)
endif()

find_package(OpenGL REQUIRED)

# Executable -------------------------------------------------------------------
add_executable(rtgt WIN32
    main.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl2.cpp)
set_target_properties(rtgt PROPERTIES OUTPUT_NAME MoM-RTGT)
target_link_libraries(rtgt PRIVATE rtgt_ui ${RTGT_SDL2_TARGET} OpenGL::GL)
if(TARGET SDL2::SDL2main)
    target_link_libraries(rtgt PRIVATE SDL2::SDL2main)
endif()
