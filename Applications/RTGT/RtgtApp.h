// ---------------------------------------------------------------------------
// Copyright:   2026 MoM-RTGT contributors
// License:     GPL
// ---------------------------------------------------------------------------

/// \file
/// \brief      The MoM-RTGT user interface, independent of the window system

#ifndef RTGT_RTGTAPP_H
#define RTGT_RTGTAPP_H

#include <memory>
#include <string>
#include <vector>

#include "FileBrowser.h"
#include "LogCapture.h"

struct ImGuiContext;
struct ImGuiSettingsHandler;
struct ImGuiTextBuffer;

namespace MoM {
class MoMGameBase;
}

namespace rtgt {

/// What the open game data comes from
enum class Source
{
    None,
    LiveGame,   ///< WIZARDS.EXE running in DOSBox
    LiveSetup,  ///< MAGIC.EXE (new game setup) running in DOSBox
    File,       ///< A save game, WIZARDS.EXE, MAGIC.EXE or rule LBX on disk
};

const char* sourceName(Source source);

/// The application state and its Dear ImGui panels.
/// Call registerSettings() once after ImGui::CreateContext(), then frame() between
/// ImGui::NewFrame() and ImGui::Render(). Destroy the App before the ImGui context:
/// the destructor saves the settings and unregisters them.
class App
{
public:
    App();
    ~App();

    void registerSettings();
    void frame();

    bool quitRequested() const { return m_quitRequested; }
    std::string windowTitle() const;

    // Actions; each one reports its outcome in statusMessage() and the log
    bool connectToGame();
    bool openFile(const std::string& path);
    bool rereadGame();
    void closeGame();

    MoM::MoMGameBase* game() const { return m_game.get(); }
    Source source() const { return m_source; }
    const std::string& statusMessage() const { return m_status; }
    LogCapture& log() { return m_log; }

private:
    void setStatus(const std::string& message);
    void addRecentFile(const std::string& path);
    void autoRefresh();

    void drawMenuBar();
    void drawDockSpace();
    void drawGamePanel();
    void drawGameSummary();
    void drawWizardsTable();
    void drawLogPanel();
    void drawFilePanel();
    void drawAboutWindow();

    // ImGui .ini settings handler callbacks
    static void* settingsReadOpen(ImGuiContext*, ImGuiSettingsHandler*, const char* name);
    static void settingsReadLine(ImGuiContext*, ImGuiSettingsHandler*, void* entry, const char* line);
    static void settingsWriteAll(ImGuiContext*, ImGuiSettingsHandler* handler, ImGuiTextBuffer* out);

    LogCapture m_log;  // first, so it captures everything the core prints
    std::unique_ptr<MoM::MoMGameBase> m_game;
    Source m_source = Source::None;
    std::string m_status = "Not connected";

    FileBrowser m_fileBrowser;
    std::vector<std::string> m_recentFiles;

    bool m_autoRefresh = true;
    float m_refreshSeconds = 2.0f;
    double m_lastRead = 0.0;

    bool m_showGame = true;
    bool m_showFiles = true;
    bool m_showLog = true;
    bool m_showAbout = false;
    bool m_showImGuiDemo = false;
    bool m_resetLayout = false;
    bool m_quitRequested = false;
    unsigned long long m_logSeen = 0;
};

}

#endif
