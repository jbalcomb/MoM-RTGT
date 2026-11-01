// ---------------------------------------------------------------------------
// Copyright:   2026 MoM-RTGT contributors
// License:     GPL
// ---------------------------------------------------------------------------

#include "FileBrowser.h"

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <system_error>

#include <imgui.h>

namespace fs = std::filesystem;

namespace rtgt {

namespace {

std::string toLower(std::string text)
{
    std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c) { return (char)std::tolower(c); });
    return text;
}

bool inputText(const char* label, std::string& text, ImGuiInputTextFlags flags = 0)
{
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "%s", text.c_str());
    if (!ImGui::InputText(label, buffer, sizeof(buffer), flags))
    {
        return false;
    }
    text = buffer;
    return true;
}

}

FileBrowser::FileBrowser(std::vector<std::string> extensions) :
    m_extensions(std::move(extensions))
{
    for (auto& extension : m_extensions)
    {
        extension = toLower(extension);
    }
    std::error_code ec;
    setDirectory(fs::current_path(ec));
}

void FileBrowser::setDirectory(const fs::path& directory)
{
    std::error_code ec;
    fs::path absolute = fs::absolute(directory, ec);
    m_directory = ec ? directory : absolute.lexically_normal();
    m_pathInput = m_directory.u8string();
    m_needsScan = true;
}

bool FileBrowser::matchesFilter(const fs::path& path) const
{
    if (m_showAllFiles)
    {
        return true;
    }
    const std::string extension = toLower(path.extension().u8string());
    return std::find(m_extensions.begin(), m_extensions.end(), extension) != m_extensions.end();
}

void FileBrowser::scan()
{
    m_needsScan = false;
    m_entries.clear();
    m_error.clear();
    m_selected = -1;

    std::error_code ec;
    fs::directory_iterator it(m_directory, fs::directory_options::skip_permission_denied, ec);
    if (ec)
    {
        m_error = ec.message();
        return;
    }
    for (const fs::directory_entry& entry : it)
    {
        std::error_code entryError;
        const bool isDirectory = entry.is_directory(entryError);
        if (!isDirectory && !matchesFilter(entry.path()))
        {
            continue;
        }
        const std::uintmax_t size = isDirectory ? 0 : entry.file_size(entryError);
        m_entries.push_back({entry.path().filename().u8string(), isDirectory, entryError ? 0 : size});
    }
    std::sort(m_entries.begin(), m_entries.end(), [](const Entry& a, const Entry& b) {
        if (a.isDirectory != b.isDirectory)
        {
            return a.isDirectory;
        }
        return toLower(a.name) < toLower(b.name);
    });
}

bool FileBrowser::draw(fs::path& chosen)
{
    if (m_needsScan)
    {
        scan();
    }

    bool picked = false;

    if (ImGui::Button("Up") && m_directory.has_parent_path() && m_directory.parent_path() != m_directory)
    {
        setDirectory(m_directory.parent_path());
    }
    ImGui::SameLine();
    if (ImGui::Button("Refresh"))
    {
        m_needsScan = true;
    }
    ImGui::SameLine();
    if (ImGui::Checkbox("All files", &m_showAllFiles))
    {
        m_needsScan = true;
    }

    ImGui::SetNextItemWidth(-FLT_MIN);
    if (inputText("##path", m_pathInput, ImGuiInputTextFlags_EnterReturnsTrue))
    {
        std::error_code ec;
        const fs::path typed = fs::u8path(m_pathInput);
        if (fs::is_directory(typed, ec))
        {
            setDirectory(typed);
        }
        else if (fs::is_regular_file(typed, ec))
        {
            chosen = typed;
            picked = true;
        }
        else
        {
            m_error = "Not found: " + m_pathInput;
        }
    }

    if (!m_error.empty())
    {
        ImGui::TextColored(ImVec4(1.0f, 0.4f, 0.4f, 1.0f), "%s", m_error.c_str());
    }

    const ImGuiTableFlags tableFlags = ImGuiTableFlags_RowBg | ImGuiTableFlags_ScrollY | ImGuiTableFlags_BordersInnerV;
    if (ImGui::BeginTable("files", 2, tableFlags, ImVec2(0.0f, -ImGui::GetFrameHeightWithSpacing())))
    {
        ImGui::TableSetupScrollFreeze(0, 1);
        ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableSetupColumn("Size", ImGuiTableColumnFlags_WidthFixed);
        ImGui::TableHeadersRow();

        fs::path enterDirectory;
        ImGuiListClipper clipper;
        clipper.Begin((int)m_entries.size());
        while (clipper.Step())
        {
            for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; ++i)
            {
                const Entry& entry = m_entries[i];
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                const std::string label = (entry.isDirectory ? "[dir] " : "") + entry.name;
                if (ImGui::Selectable(label.c_str(), m_selected == i,
                                      ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_AllowDoubleClick))
                {
                    m_selected = i;
                    if (ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
                    {
                        if (entry.isDirectory)
                        {
                            enterDirectory = m_directory / fs::u8path(entry.name);
                        }
                        else
                        {
                            chosen = m_directory / fs::u8path(entry.name);
                            picked = true;
                        }
                    }
                }
                ImGui::TableNextColumn();
                if (!entry.isDirectory)
                {
                    ImGui::Text("%llu", (unsigned long long)entry.size);
                }
            }
        }
        ImGui::EndTable();
        if (!enterDirectory.empty())
        {
            setDirectory(enterDirectory);
        }
    }

    const bool canOpen = m_selected >= 0 && m_selected < (int)m_entries.size() && !m_entries[m_selected].isDirectory;
    ImGui::BeginDisabled(!canOpen);
    if (ImGui::Button("Open") && canOpen)
    {
        chosen = m_directory / fs::u8path(m_entries[m_selected].name);
        picked = true;
    }
    ImGui::EndDisabled();

    return picked;
}

}
