// ---------------------------------------------------------------------------
// Copyright:   2026 MoM-RTGT contributors
// License:     GPL
// ---------------------------------------------------------------------------

/// \file
/// \brief      Captures std::cout and std::cerr so the core's messages show in the Log panel

#ifndef RTGT_LOGCAPTURE_H
#define RTGT_LOGCAPTURE_H

#include <deque>
#include <iostream>
#include <streambuf>
#include <string>

namespace rtgt {

/// Keeps the most recent lines written to std::cout and std::cerr, while still
/// passing everything on to the original streams.
class LogCapture
{
public:
    LogCapture();
    ~LogCapture();

    LogCapture(const LogCapture&) = delete;
    LogCapture& operator=(const LogCapture&) = delete;

    /// Add a line from the application itself
    void add(const std::string& line);
    void clear();

    const std::deque<std::string>& lines() const { return m_lines; }
    /// Increases whenever a line is added, so views know when to scroll
    unsigned long long generation() const { return m_generation; }

private:
    class TeeBuffer : public std::streambuf
    {
    public:
        TeeBuffer(LogCapture& owner, std::streambuf* original) : m_owner(owner), m_original(original) {}
        std::streambuf* original() const { return m_original; }

    protected:
        int_type overflow(int_type ch) override;
        std::streamsize xsputn(const char* s, std::streamsize count) override;
        int sync() override;

    private:
        LogCapture& m_owner;
        std::streambuf* m_original;
        std::string m_pending;
    };

    void appendText(std::string& pending, const char* s, std::streamsize count);

    static const size_t kMaxLines = 5000;

    std::deque<std::string> m_lines;
    unsigned long long m_generation = 0;
    TeeBuffer m_cout;
    TeeBuffer m_cerr;
};

}

#endif
