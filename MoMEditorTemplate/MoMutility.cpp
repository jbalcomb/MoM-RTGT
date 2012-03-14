// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include <cctype>
#include <iomanip>

#include "MoMutility.h"

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
