// Runs the MoM-RTGT user interface headless: no window, no rendering, no input.
// This checks that every panel can be drawn in each state without tripping
// Dear ImGui's assertions (Begin/End balance, ID conflicts, ...).

#include <doctest.h>

#include <cstdio>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

#include <imgui.h>
#include <imgui_impl_null.h>

#include <MoMGameBase.h>
#include "ImGuiAssert.h"
#include "RtgtApp.h"

namespace
{

const std::string gRefGameFile = std::string(RTGT_TEST_DATA_DIR) + "REFTEST.GAM";

// A failed Dear ImGui check fails the test, also in release builds
[[noreturn]] void throwOnImGuiAssert(const char* expression, const char* file, int line)
{
    throw std::logic_error(std::string("IM_ASSERT(") + expression + ") at " + file + ":" + std::to_string(line));
}

class HeadlessImGui
{
public:
    HeadlessImGui()
    {
        rtgt::setImGuiAssertHandler(&throwOnImGuiAssert);
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.IniFilename = nullptr;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.DisplaySize = ImVec2(1280, 800);
        ImGui_ImplNullPlatform_Init();
        ImGui_ImplNullRender_Init();
    }
    ~HeadlessImGui()
    {
        ImGui_ImplNullRender_Shutdown();
        ImGui_ImplNullPlatform_Shutdown();
        ImGui::DestroyContext();
    }

    void frames(rtgt::App& app, int count)
    {
        for (int i = 0; i < count; ++i)
        {
            ImGui_ImplNullPlatform_NewFrame();
            ImGui_ImplNullRender_NewFrame();
            ImGui::NewFrame();
            app.frame();
            ImGui::Render();
        }
    }

    /// Frames without an App
    void frames(int count)
    {
        for (int i = 0; i < count; ++i)
        {
            ImGui_ImplNullPlatform_NewFrame();
            ImGui_ImplNullRender_NewFrame();
            ImGui::NewFrame();
            ImGui::Render();
        }
    }
};

}

TEST_SUITE("RTGT UI")
{

TEST_CASE("draws without a game")
{
    HeadlessImGui imgui;
    rtgt::App app;
    app.registerSettings();
    imgui.frames(app, 3);
    CHECK(app.game() == nullptr);
    CHECK(app.source() == rtgt::Source::None);
    CHECK_FALSE(app.quitRequested());
}

TEST_CASE("opens a save game and shows it")
{
    HeadlessImGui imgui;
    rtgt::App app;
    app.registerSettings();
    imgui.frames(app, 2);

    REQUIRE(app.openFile(gRefGameFile));
    CHECK(app.source() == rtgt::Source::File);
    REQUIRE(app.game() != nullptr);
    CHECK(app.game()->getSources().find("REFTEST.GAM") != std::string::npos);
    CHECK(app.windowTitle().find("REFTEST.GAM") != std::string::npos);
    imgui.frames(app, 3);

    app.closeGame();
    CHECK(app.game() == nullptr);
    imgui.frames(app, 2);
}

TEST_CASE("reports a file that cannot be opened")
{
    HeadlessImGui imgui;
    rtgt::App app;
    app.registerSettings();

    CHECK_FALSE(app.openFile("NOTEXIST.GAM"));
    CHECK(app.game() == nullptr);
    CHECK(app.statusMessage().find("NOTEXIST.GAM") != std::string::npos);
    imgui.frames(app, 2);
}

TEST_CASE("settings are saved to disk when the App and the ImGui context go away")
{
    // As in main(): the App is destroyed first, then the context, which saves the
    // .ini file once more. That must neither reach the destroyed App nor drop its settings.
    const std::string iniFile = "rtgt_ui_tests.ini";
    (void)std::remove(iniFile.c_str());
    {
        HeadlessImGui imgui;
        ImGui::GetIO().IniFilename = iniFile.c_str();
        {
            rtgt::App app;
            app.registerSettings();
            REQUIRE(app.openFile(gRefGameFile));
            imgui.frames(app, 2);
        }
        imgui.frames(2);
    }
    std::ifstream in(iniFile);
    std::stringstream contents;
    contents << in.rdbuf();
    CHECK(contents.str().find("[RTGT][Settings]") != std::string::npos);
    CHECK(contents.str().find("Recent=" + gRefGameFile) != std::string::npos);
    CHECK(contents.str().find("[Docking]") != std::string::npos);
    in.close();
    CHECK(std::remove(iniFile.c_str()) == 0);
}

TEST_CASE("keeps settings in the ini file")
{
    std::string ini;
    {
        HeadlessImGui imgui;
        rtgt::App app;
        app.registerSettings();
        REQUIRE(app.openFile(gRefGameFile));
        imgui.frames(app, 2);
        ini = ImGui::SaveIniSettingsToMemory();
    }
    CHECK(ini.find("[RTGT][Settings]") != std::string::npos);
    CHECK(ini.find("Recent=" + gRefGameFile) != std::string::npos);
    CHECK(ini.find("[Docking]") != std::string::npos);

    HeadlessImGui imgui;
    rtgt::App app;
    app.registerSettings();
    ImGui::LoadIniSettingsFromMemory(ini.c_str());
    imgui.frames(app, 2);
    CHECK(ImGui::SaveIniSettingsToMemory() == ini);
}

}
