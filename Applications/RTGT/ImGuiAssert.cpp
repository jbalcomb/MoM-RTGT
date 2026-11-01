// ---------------------------------------------------------------------------
// Copyright:   2026 MoM-RTGT contributors
// License:     GPL
// ---------------------------------------------------------------------------

#include "ImGuiAssert.h"

#include <cstdio>

namespace rtgt {

namespace {

void logAssert(const char* expression, const char* file, int line)
{
    std::fprintf(stderr, "Dear ImGui check failed: %s (%s:%d)\n", expression, file, line);
}

ImGuiAssertHandler gHandler = &logAssert;

}

ImGuiAssertHandler setImGuiAssertHandler(ImGuiAssertHandler handler)
{
    ImGuiAssertHandler previous = gHandler;
    gHandler = handler ? handler : &logAssert;
    return previous;
}

void imguiAssertFailed(const char* expression, const char* file, int line)
{
    gHandler(expression, file, line);
}

}
