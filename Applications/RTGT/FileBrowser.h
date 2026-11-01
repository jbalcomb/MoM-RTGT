// ---------------------------------------------------------------------------
// Copyright:   2026 MoM-RTGT contributors
// License:     GPL
// ---------------------------------------------------------------------------

/// \file
/// \brief      A small file browser panel, so the application needs no native dialog library

#ifndef RTGT_FILEBROWSER_H
#define RTGT_FILEBROWSER_H

#include <cstdint>
#include <filesystem>
#include <string>
#include <vector>

namespace rtgt {

class FileBrowser
{
public:
    /// File name extensions shown by default (case-insensitive, with the dot)
    explicit FileBrowser(std::vector<std::string> extensions);

    void setDirectory(const std::filesystem::path& directory);
    const std::filesystem::path& directory() const { return m_directory; }

    /// Draw the contents of the panel. Returns true when a file is chosen.
    bool draw(std::filesystem::path& chosen);

private:
    struct Entry
    {
        std::string name;
        bool isDirectory;
        std::uintmax_t size;
    };

    void scan();
    bool matchesFilter(const std::filesystem::path& path) const;

    std::vector<std::string> m_extensions;
    std::filesystem::path m_directory;
    std::vector<Entry> m_entries;
    std::string m_error;
    std::string m_pathInput;
    bool m_showAllFiles = false;
    bool m_needsScan = true;
    int m_selected = -1;
};

}

#endif
