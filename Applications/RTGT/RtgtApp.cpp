// ---------------------------------------------------------------------------
// Copyright:   2026 MoM-RTGT contributors
// License:     GPL
// ---------------------------------------------------------------------------

#include "RtgtApp.h"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <regex>
#include <sstream>

#include <imgui.h>
#include <imgui_internal.h>  // DockBuilder, settings handlers

#include "MoMGameCustom.h"
#include "MoMGameMemory.h"
#include "MoMGameSave.h"
#include "MoMGenerated.h"
#include "MoMProcess.h"

#ifndef RTGT_VERSION
#define RTGT_VERSION "dev"
#endif

namespace rtgt {

namespace {

const char* const kGameWindow = "Game";
const char* const kFilesWindow = "Files";
const char* const kLogWindow = "Log";
const size_t kMaxRecentFiles = 10;
const char* const kSettingsType = "RTGT";

/// An enum value as a readable name: RACE_High_Men (5) -> "High Men"
template <typename T>
std::string prettyName(const T& value)
{
    std::ostringstream oss;
    oss << value;
    std::string text = std::regex_replace(oss.str(), std::regex(R"( \(\d+\)$)"), "");
    text = std::regex_replace(text, std::regex("^[A-Z][A-Z0-9]+_"), "");
    std::replace(text.begin(), text.end(), '_', ' ');
    return text;
}

/// A fixed-size char array from the game, which need not be zero-terminated
template <size_t N>
std::string fixedString(const char (&chars)[N])
{
    return std::string(chars, strnlen(chars, N));
}

void keyValueRow(const char* key, const std::string& value)
{
    ImGui::TableNextRow();
    ImGui::TableNextColumn();
    ImGui::TextDisabled("%s", key);
    ImGui::TableNextColumn();
    ImGui::TextWrapped("%s", value.c_str());
}

}

const char* sourceName(Source source)
{
    switch (source)
    {
    case Source::None: return "None";
    case Source::LiveGame: return "Running game (WIZARDS.EXE)";
    case Source::LiveSetup: return "Running new-game setup (MAGIC.EXE)";
    case Source::File: return "File";
    }
    return "?";
}

App::App() :
    m_fileBrowser({".gam", ".exe", ".lbx"})
{
}

App::~App()
{
    // Dear ImGui saves the .ini file again when its context is destroyed. That would
    // call our settings handler after this App is gone, or (once detached) write the
    // file without our settings. So save it now, for the last time, and detach.
    if (ImGui::GetCurrentContext() && ImGui::FindSettingsHandler(kSettingsType))
    {
        ImGuiIO& io = ImGui::GetIO();
        if (io.IniFilename)
        {
            ImGui::SaveIniSettingsToDisk(io.IniFilename);
            io.IniFilename = nullptr;
        }
        ImGui::RemoveSettingsHandler(kSettingsType);
    }
}

// ---------------------------------------------------------------------------
// Actions
// ---------------------------------------------------------------------------

void App::setStatus(const std::string& message)
{
    m_status = message;
    m_log.add("[RTGT] " + message);
}

bool App::connectToGame()
{
    closeGame();
    setStatus("Looking for Master of Magic in DOSBox...");

    std::unique_ptr<MoM::MoMProcess> process(new MoM::MoMProcess);
    if (!process->findProcessAndData())
    {
        setStatus("No running Master of Magic found in DOSBox");
        return false;
    }

    std::unique_ptr<MoM::MoMGameMemory> liveGame(new MoM::MoMGameMemory);
    if (liveGame->openGame(process))
    {
        m_game = std::move(liveGame);
        m_source = Source::LiveGame;
    }
    else
    {
        std::unique_ptr<MoM::MoMGameCustom> setup(new MoM::MoMGameCustom);
        if (!setup->openGame(process))
        {
            setStatus("Found DOSBox, but could not read the game");
            return false;
        }
        m_game = std::move(setup);
        m_source = Source::LiveSetup;
    }

    m_lastRead = ImGui::GetCurrentContext() ? ImGui::GetTime() : 0.0;
    setStatus(std::string("Connected: ") + sourceName(m_source));
    return true;
}

bool App::openFile(const std::string& path)
{
    closeGame();
    std::unique_ptr<MoM::MoMGameSave> file(new MoM::MoMGameSave);
    if (!file->load(path.c_str()))
    {
        setStatus("Could not open '" + path + "': " + file->errorString());
        return false;
    }
    m_game = std::move(file);
    m_source = Source::File;
    addRecentFile(path);
    setStatus("Opened " + path);
    return true;
}

bool App::rereadGame()
{
    if (!m_game || (m_source != Source::LiveGame && m_source != Source::LiveSetup))
    {
        return false;
    }
    if (ImGui::GetCurrentContext())
    {
        m_lastRead = ImGui::GetTime();
    }
    if (!m_game->readData())
    {
        closeGame();
        setStatus("Lost the connection to the game");
        return false;
    }
    return true;
}

void App::closeGame()
{
    if (m_game)
    {
        m_game->closeGame();
        m_game.reset();
        m_source = Source::None;
        m_status = "Not connected";
    }
}

void App::addRecentFile(const std::string& path)
{
    m_recentFiles.erase(std::remove(m_recentFiles.begin(), m_recentFiles.end(), path), m_recentFiles.end());
    m_recentFiles.insert(m_recentFiles.begin(), path);
    if (m_recentFiles.size() > kMaxRecentFiles)
    {
        m_recentFiles.resize(kMaxRecentFiles);
    }
    if (ImGui::GetCurrentContext())
    {
        ImGui::MarkIniSettingsDirty();
    }
}

void App::autoRefresh()
{
    if (m_autoRefresh && (m_source == Source::LiveGame || m_source == Source::LiveSetup)
        && ImGui::GetTime() - m_lastRead >= m_refreshSeconds)
    {
        rereadGame();
    }
}

std::string App::windowTitle() const
{
    std::string title = "MoM-RTGT " RTGT_VERSION;
    if (m_game)
    {
        title += " - " + m_game->getSources();
    }
    return title;
}

// ---------------------------------------------------------------------------
// Frame
// ---------------------------------------------------------------------------

void App::frame()
{
    autoRefresh();

    if (ImGui::Shortcut(ImGuiMod_Ctrl | ImGuiKey_Q, ImGuiInputFlags_RouteGlobal))
    {
        m_quitRequested = true;
    }
    if (ImGui::Shortcut(ImGuiMod_Ctrl | ImGuiKey_K, ImGuiInputFlags_RouteGlobal))
    {
        connectToGame();
    }
    if (ImGui::Shortcut(ImGuiKey_F5, ImGuiInputFlags_RouteGlobal))
    {
        rereadGame();
    }

    drawMenuBar();
    drawDockSpace();

    if (m_showGame)
    {
        drawGamePanel();
    }
    if (m_showFiles)
    {
        drawFilePanel();
    }
    if (m_showLog)
    {
        drawLogPanel();
    }
    if (m_showAbout)
    {
        drawAboutWindow();
    }
    if (m_showImGuiDemo)
    {
        ImGui::ShowDemoWindow(&m_showImGuiDemo);
    }
}

void App::drawMenuBar()
{
    if (!ImGui::BeginMainMenuBar())
    {
        return;
    }

    const bool live = m_source == Source::LiveGame || m_source == Source::LiveSetup;
    if (ImGui::BeginMenu("File"))
    {
        if (ImGui::MenuItem("Connect to running game", "Ctrl+K"))
        {
            connectToGame();
        }
        if (ImGui::MenuItem("Open file..."))
        {
            m_showFiles = true;
            ImGui::SetWindowFocus(kFilesWindow);
        }
        if (ImGui::BeginMenu("Open recent", !m_recentFiles.empty()))
        {
            std::string chosen;
            for (const std::string& path : m_recentFiles)
            {
                if (ImGui::MenuItem(path.c_str()))
                {
                    chosen = path;
                }
            }
            ImGui::EndMenu();
            if (!chosen.empty())
            {
                openFile(chosen);
            }
        }
        ImGui::Separator();
        if (ImGui::MenuItem("Re-read game", "F5", false, live))
        {
            rereadGame();
        }
        if (ImGui::MenuItem("Close", nullptr, false, m_game != nullptr))
        {
            closeGame();
            setStatus("Closed");
        }
        ImGui::Separator();
        if (ImGui::MenuItem("Quit", "Ctrl+Q"))
        {
            m_quitRequested = true;
        }
        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("View"))
    {
        bool changed = false;
        changed |= ImGui::MenuItem(kGameWindow, nullptr, &m_showGame);
        changed |= ImGui::MenuItem(kFilesWindow, nullptr, &m_showFiles);
        changed |= ImGui::MenuItem(kLogWindow, nullptr, &m_showLog);
        ImGui::Separator();
        if (ImGui::MenuItem("Reset layout"))
        {
            m_showGame = m_showFiles = m_showLog = true;
            m_resetLayout = true;
            changed = true;
        }
        ImGui::Separator();
        ImGui::MenuItem("Dear ImGui demo", nullptr, &m_showImGuiDemo);
        ImGui::EndMenu();
        if (changed)
        {
            ImGui::MarkIniSettingsDirty();
        }
    }

    if (ImGui::BeginMenu("Help"))
    {
        ImGui::MenuItem("About MoM-RTGT", nullptr, &m_showAbout);
        ImGui::EndMenu();
    }

    // Status, right-aligned
    const float width = ImGui::CalcTextSize(m_status.c_str()).x + ImGui::GetStyle().ItemSpacing.x;
    ImGui::SetCursorPosX(std::max(ImGui::GetCursorPosX(), ImGui::GetWindowWidth() - width));
    ImGui::TextUnformatted(m_status.c_str());

    ImGui::EndMainMenuBar();
}

void App::drawDockSpace()
{
    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    const ImGuiID dockspace = ImGui::GetID("MainDockSpace");

    // First run (no saved layout) or View > Reset layout: Files left, Log below, Game in the middle
    if (m_resetLayout || ImGui::DockBuilderGetNode(dockspace) == nullptr)
    {
        m_resetLayout = false;
        ImGui::DockBuilderRemoveNode(dockspace);
        ImGui::DockBuilderAddNode(dockspace, ImGuiDockNodeFlags_DockSpace);
        ImGui::DockBuilderSetNodeSize(dockspace, viewport->WorkSize);
        ImGuiID center = dockspace;
        const ImGuiID left = ImGui::DockBuilderSplitNode(center, ImGuiDir_Left, 0.30f, nullptr, &center);
        const ImGuiID bottom = ImGui::DockBuilderSplitNode(center, ImGuiDir_Down, 0.30f, nullptr, &center);
        ImGui::DockBuilderDockWindow(kFilesWindow, left);
        ImGui::DockBuilderDockWindow(kLogWindow, bottom);
        ImGui::DockBuilderDockWindow(kGameWindow, center);
        ImGui::DockBuilderFinish(dockspace);
    }

    ImGui::DockSpaceOverViewport(dockspace, viewport);
}

// ---------------------------------------------------------------------------
// Panels
// ---------------------------------------------------------------------------

void App::drawGamePanel()
{
    if (!ImGui::Begin(kGameWindow, &m_showGame))
    {
        ImGui::End();
        return;
    }

    if (!m_game)
    {
        ImGui::TextWrapped("No game open. Connect to Master of Magic running in DOSBox, "
                           "or open a save game (SAVEn.GAM), WIZARDS.EXE, MAGIC.EXE or rule LBX file.");
        ImGui::Spacing();
        if (ImGui::Button("Connect to running game"))
        {
            connectToGame();
        }
        ImGui::SameLine();
        if (ImGui::Button("Open file..."))
        {
            m_showFiles = true;
            ImGui::SetWindowFocus(kFilesWindow);
        }
        ImGui::End();
        return;
    }

    drawGameSummary();
    ImGui::Spacing();
    drawWizardsTable();
    ImGui::End();
}

void App::drawGameSummary()
{
    const bool live = m_source == Source::LiveGame || m_source == Source::LiveSetup;
    if (live)
    {
        if (ImGui::Button("Re-read now"))
        {
            rereadGame();
        }
        ImGui::SameLine();
        if (ImGui::Checkbox("Auto refresh", &m_autoRefresh))
        {
            ImGui::MarkIniSettingsDirty();
        }
        ImGui::SameLine();
        ImGui::SetNextItemWidth(ImGui::GetFontSize() * 10.0f);
        if (ImGui::SliderFloat("##interval", &m_refreshSeconds, 0.5f, 30.0f, "every %.1f s"))
        {
            ImGui::MarkIniSettingsDirty();
        }
        ImGui::SameLine();
    }
    if (ImGui::Button("Close"))
    {
        closeGame();
        setStatus("Closed");
        return;
    }

    if (!ImGui::BeginTable("summary", 2, ImGuiTableFlags_SizingStretchProp | ImGuiTableFlags_BordersInnerH))
    {
        return;
    }
    ImGui::TableSetupColumn("key", ImGuiTableColumnFlags_WidthFixed);
    ImGui::TableSetupColumn("value", ImGuiTableColumnFlags_WidthStretch);

    MoM::MoMGameBase& game = *m_game;
    keyValueRow("Source", sourceName(m_source));
    keyValueRow("Data", game.getSources());
    keyValueRow("Game directory", game.getGameDirectory());
    if (const char* version = game.getMoMVersion())
    {
        keyValueRow("Version", version);
    }
    if (const uint16_t* turn = game.getGameTurn())
    {
        keyValueRow("Turn", std::to_string(*turn));
    }
    keyValueRow("Wizards", std::to_string(game.getNrWizards()));
    keyValueRow("Units", std::to_string(game.getNrUnits()));
    keyValueRow("Cities", std::to_string(game.getNrCities()));
    if (live)
    {
        keyValueRow("Last read", std::to_string((int)(ImGui::GetTime() - m_lastRead)) + " s ago");
    }
    ImGui::EndTable();
}

void App::drawWizardsTable()
{
    const int rows = std::min<int>(m_game->getNrWizards(), MoM::gMAX_WIZARD_RECORDS);
    if (rows <= 0)
    {
        return;
    }

    ImGui::SeparatorText("Wizards");
    const ImGuiTableFlags flags = ImGuiTableFlags_RowBg | ImGuiTableFlags_Borders | ImGuiTableFlags_Resizable
                                  | ImGuiTableFlags_SizingFixedFit;
    if (!ImGui::BeginTable("wizards", 7, flags))
    {
        return;
    }
    ImGui::TableSetupColumn("Name");
    ImGui::TableSetupColumn("Race");
    ImGui::TableSetupColumn("Banner");
    ImGui::TableSetupColumn("Gold");
    ImGui::TableSetupColumn("Mana");
    ImGui::TableSetupColumn("Casting skill");
    ImGui::TableSetupColumn("Fame");
    ImGui::TableHeadersRow();
    for (int i = 0; i < rows; ++i)
    {
        const MoM::Wizard* wizardPtr = m_game->getWizard(i);
        if (wizardPtr == nullptr)
        {
            continue;
        }
        const MoM::Wizard& wizard = *wizardPtr;
        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        ImGui::TextUnformatted(fixedString(wizard.m_Name).c_str());
        ImGui::TableNextColumn();
        ImGui::TextUnformatted(prettyName(wizard.m_Home_Race).c_str());
        ImGui::TableNextColumn();
        ImGui::TextUnformatted(prettyName(wizard.m_BannerColor).c_str());
        ImGui::TableNextColumn();
        ImGui::Text("%d", (int)wizard.m_Gold_Coins);
        ImGui::TableNextColumn();
        ImGui::Text("%d", (int)wizard.m_Mana_Crystals);
        ImGui::TableNextColumn();
        ImGui::Text("%d", (int)wizard.m_Wizard_Casting_Skill);
        ImGui::TableNextColumn();
        ImGui::Text("%d", (int)wizard.m_Fame);
    }
    ImGui::EndTable();
}

void App::drawFilePanel()
{
    if (ImGui::Begin(kFilesWindow, &m_showFiles))
    {
        std::filesystem::path chosen;
        const std::filesystem::path before = m_fileBrowser.directory();
        if (m_fileBrowser.draw(chosen))
        {
            openFile(chosen.u8string());
        }
        if (m_fileBrowser.directory() != before)
        {
            ImGui::MarkIniSettingsDirty();
        }
    }
    ImGui::End();
}

void App::drawLogPanel()
{
    if (!ImGui::Begin(kLogWindow, &m_showLog))
    {
        ImGui::End();
        return;
    }
    if (ImGui::Button("Clear"))
    {
        m_log.clear();
    }
    ImGui::SameLine();
    if (ImGui::Button("Copy"))
    {
        std::string text;
        for (const std::string& line : m_log.lines())
        {
            text += line + "\n";
        }
        ImGui::SetClipboardText(text.c_str());
    }

    if (ImGui::BeginChild("lines", ImVec2(0, 0), ImGuiChildFlags_Borders, ImGuiWindowFlags_HorizontalScrollbar))
    {
        const auto& lines = m_log.lines();
        ImGuiListClipper clipper;
        clipper.Begin((int)lines.size());
        while (clipper.Step())
        {
            for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; ++i)
            {
                ImGui::TextUnformatted(lines[i].c_str());
            }
        }
        // Follow new lines unless the user scrolled up
        if (m_log.generation() != m_logSeen && ImGui::GetScrollY() >= ImGui::GetScrollMaxY() - 1.0f)
        {
            ImGui::SetScrollHereY(1.0f);
        }
        m_logSeen = m_log.generation();
    }
    ImGui::EndChild();
    ImGui::End();
}

void App::drawAboutWindow()
{
    ImGui::SetNextWindowSize(ImVec2(ImGui::GetFontSize() * 30.0f, 0.0f), ImGuiCond_Appearing);
    if (ImGui::Begin("About MoM-RTGT", &m_showAbout, ImGuiWindowFlags_NoDocking))
    {
        ImGui::Text("MoM-RTGT %s", RTGT_VERSION);
        ImGui::TextWrapped("Master of Magic Real-Time Game Tweaker: view and change Master of Magic "
                           "while it runs in DOSBox, or edit its files.");
        ImGui::Spacing();
        ImGui::TextWrapped("Originally written by Klaas van Aarsen (\"I like Serena\"), 2011-2020.");
        ImGui::TextWrapped("License: GPL");
        ImGui::TextWrapped("https://github.com/jbalcomb/MoM-RTGT");
        ImGui::Spacing();
        ImGui::TextDisabled("Dear ImGui %s", ImGui::GetVersion());
    }
    ImGui::End();
}

// ---------------------------------------------------------------------------
// Settings, stored in the Dear ImGui .ini file next to the executable
// ---------------------------------------------------------------------------

void App::registerSettings()
{
    ImGuiSettingsHandler handler;
    handler.TypeName = kSettingsType;
    handler.TypeHash = ImHashStr(kSettingsType);
    handler.ReadOpenFn = &App::settingsReadOpen;
    handler.ReadLineFn = &App::settingsReadLine;
    handler.WriteAllFn = &App::settingsWriteAll;
    handler.UserData = this;
    ImGui::AddSettingsHandler(&handler);
}

void* App::settingsReadOpen(ImGuiContext*, ImGuiSettingsHandler* handler, const char* name)
{
    return std::strcmp(name, "Settings") == 0 ? handler->UserData : nullptr;
}

void App::settingsReadLine(ImGuiContext*, ImGuiSettingsHandler*, void* entry, const char* line)
{
    App& app = *static_cast<App*>(entry);
    const char* equals = std::strchr(line, '=');
    if (equals == nullptr)
    {
        return;
    }
    const std::string key(line, equals);
    const std::string value(equals + 1);
    const bool flag = value == "1";

    if (key == "Recent" && !value.empty() && app.m_recentFiles.size() < kMaxRecentFiles)
    {
        app.m_recentFiles.push_back(value);
    }
    else if (key == "Directory" && !value.empty())
    {
        std::error_code ec;
        if (std::filesystem::is_directory(std::filesystem::u8path(value), ec))
        {
            app.m_fileBrowser.setDirectory(std::filesystem::u8path(value));
        }
    }
    else if (key == "AutoRefresh")
    {
        app.m_autoRefresh = flag;
    }
    else if (key == "RefreshSeconds")
    {
        app.m_refreshSeconds = std::clamp(std::strtof(value.c_str(), nullptr), 0.5f, 30.0f);
    }
    else if (key == "ShowGame")
    {
        app.m_showGame = flag;
    }
    else if (key == "ShowFiles")
    {
        app.m_showFiles = flag;
    }
    else if (key == "ShowLog")
    {
        app.m_showLog = flag;
    }
}

void App::settingsWriteAll(ImGuiContext*, ImGuiSettingsHandler* handler, ImGuiTextBuffer* out)
{
    const App& app = *static_cast<const App*>(handler->UserData);
    out->appendf("[%s][Settings]\n", handler->TypeName);
    for (const std::string& path : app.m_recentFiles)
    {
        out->appendf("Recent=%s\n", path.c_str());
    }
    out->appendf("Directory=%s\n", app.m_fileBrowser.directory().u8string().c_str());
    out->appendf("AutoRefresh=%d\n", app.m_autoRefresh ? 1 : 0);
    out->appendf("RefreshSeconds=%.1f\n", app.m_refreshSeconds);
    out->appendf("ShowGame=%d\n", app.m_showGame ? 1 : 0);
    out->appendf("ShowFiles=%d\n", app.m_showFiles ? 1 : 0);
    out->appendf("ShowLog=%d\n", app.m_showLog ? 1 : 0);
    out->append("\n");
}

}
