// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include <cctype>
#include <iomanip>

#include "MoMUtility.h"

namespace MoM
{

std::string dirFromFilepath(const std::string filepath)
{
    std::string dir;
    std::string::size_type pos = filepath.find_last_of("/\\");
    if (std::string::npos != pos)
    {
        dir = filepath.substr(0, pos);
    }
    return dir;
}

std::string lowercase(const std::string& str)
{
    std::string result = str;
    for (size_t i = 0; i < result.size(); ++i)
    {
        result[i] = (char)tolower(result[i]);
    }
    return result;
}

std::string prettyEnumStr(const std::string& str)
{
    if (str.empty())
        return "";

    std::string result = str;
    if (str.substr(0, 2) == "m_")
    {
        // Strip data member "m_" prefix
        result = str.substr(2);
    }
    else if ((str[0] >= 'A') && (str[0] <= 'Z'))
    {
        // Strip CAPITAL_ prefix
        size_t pos = 1;
        while (pos < str.length()
               && (((str[pos] >= 'A') && (str[pos] <= 'Z')) || ((str[pos] >= '0') && (str[pos] <= '9'))))
        {
            pos++;
        }
        if ((pos < str.length()) && (str[pos] == '_'))
        {
            result = str.substr(pos + 1);
        }
    }
    else
    {
        // No prefix that should be stripped
    }

    size_t pos;
    if (std::string::npos != (pos = result.find(" (")))
    {
        // Strip postfix with parentheses
        result.resize(pos);
    }

    result = replaceUnderscoresBySpaces(result);

    return result;
}

std::string replaceUnderscoresBySpaces(const std::string& str)
{
    std::string result = str;
    for (size_t i = 0; i < result.size(); ++i)
    {
        if (result[i] == '_')
        {
            result[i] = ' ';
        }
    }
    return result;
}

std::string replaceStrInStr(const std::string& str, const std::string& findStr, const std::string& replaceStr)
{
    std::string result;
    size_t pos = 0;
    size_t posFound;
    while ((posFound = str.find(findStr, pos)) != std::string::npos)
    {
        result += str.substr(pos, posFound - pos);
        result += replaceStr;
        pos = posFound + findStr.length();
    }
    result += str.substr(pos);
    return result;
}

bool writeDataToStream(std::ostream& os, const unsigned char* pdata, size_t size)
{
    size &= 0xFFFFFFF0;     // Make size a multiple of 16

    os.fill('0');

    for (size_t paragraphIndex = 0; paragraphIndex < size; paragraphIndex += 16)
    {
        os << std::hex << std::setw(8) << paragraphIndex << ": ";

        for (size_t i = 0; i < 16; ++i)
        {
            os << std::hex << std::setw(2) << (unsigned)(unsigned char)pdata[paragraphIndex + i];
            if (7 == i)
            {
                os << '-';
            }
            else
            {
                os << ' ';
            }
        }

        for (size_t i = 0; i < 16; ++i)
        {
            if (std::isprint(pdata[paragraphIndex + i]))
            {
                os << pdata[paragraphIndex + i];
            }
            else
            {
                os << '.';
            }
        }

        os << "\n";
    }

    os << std::dec;

    return os.good();
}

}
