// ---------------------------------------------------------------------------
// Copyright:   2026 MoM-RTGT contributors
// License:     GPL
// ---------------------------------------------------------------------------

#include "LogCapture.h"

namespace rtgt {

LogCapture::LogCapture() :
    m_cout(*this, std::cout.rdbuf()),
    m_cerr(*this, std::cerr.rdbuf())
{
    std::cout.rdbuf(&m_cout);
    std::cerr.rdbuf(&m_cerr);
}

LogCapture::~LogCapture()
{
    std::cout.flush();
    std::cerr.flush();
    std::cout.rdbuf(m_cout.original());
    std::cerr.rdbuf(m_cerr.original());
}

void LogCapture::add(const std::string& line)
{
    m_lines.push_back(line);
    while (m_lines.size() > kMaxLines)
    {
        m_lines.pop_front();
    }
    ++m_generation;
}

void LogCapture::clear()
{
    m_lines.clear();
    ++m_generation;
}

void LogCapture::appendText(std::string& pending, const char* s, std::streamsize count)
{
    for (std::streamsize i = 0; i < count; ++i)
    {
        if (s[i] == '\n')
        {
            add(pending);
            pending.clear();
        }
        else if (s[i] != '\r')
        {
            pending += s[i];
        }
    }
}

LogCapture::TeeBuffer::int_type LogCapture::TeeBuffer::overflow(int_type ch)
{
    if (traits_type::eq_int_type(ch, traits_type::eof()))
    {
        return traits_type::not_eof(ch);
    }
    const char c = traits_type::to_char_type(ch);
    m_owner.appendText(m_pending, &c, 1);
    return m_original->sputc(c);
}

std::streamsize LogCapture::TeeBuffer::xsputn(const char* s, std::streamsize count)
{
    m_owner.appendText(m_pending, s, count);
    return m_original->sputn(s, count);
}

int LogCapture::TeeBuffer::sync()
{
    return m_original->pubsync();
}

}
