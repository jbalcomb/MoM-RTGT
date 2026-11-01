// ---------------------------------------------------------------------------
// Copyright:   2026 MoM-RTGT contributors
// License:     GPL
// ---------------------------------------------------------------------------

/// \file
/// \brief      What happens when a Dear ImGui assertion fails (see rtgt_imconfig.h)

#ifndef RTGT_IMGUIASSERT_H
#define RTGT_IMGUIASSERT_H

namespace rtgt {

using ImGuiAssertHandler = void (*)(const char* expression, const char* file, int line);

/// Replace the handler (the default prints to stderr); returns the previous one
ImGuiAssertHandler setImGuiAssertHandler(ImGuiAssertHandler handler);

void imguiAssertFailed(const char* expression, const char* file, int line);

}

#endif
