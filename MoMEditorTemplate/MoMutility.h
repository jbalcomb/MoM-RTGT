// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#ifndef MOMUTILITY_H
#define MOMUTILITY_H

#include <sstream>

namespace MoM {

#ifdef ARRAYSIZE
#undef ARRAYSIZE
#endif
#define ARRAYSIZE(a) (sizeof(a) / sizeof(*(a)))

std::string dirFromFilepath(const std::string filepath);

template< typename E >
inline E inc(E& e)
{
    unsigned u = (unsigned)e;
    u++;
    e = (E)u;
    return e;
}

std::string lowercase(const std::string& str);

template< typename T >
inline std::string toStr(const T& t)
{
    std::ostringstream oss;
    oss << t;
    return oss.str();
}

bool writeDataToStream(std::ostream& os, const unsigned char* pdata, size_t size);

}

#endif
