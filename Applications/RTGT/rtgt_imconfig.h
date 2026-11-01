// ---------------------------------------------------------------------------
// Copyright:   2026 MoM-RTGT contributors
// License:     GPL
// ---------------------------------------------------------------------------

/// \file
/// \brief      Dear ImGui configuration for MoM-RTGT (IMGUI_USER_CONFIG)
///
/// Dear ImGui's assertions catch mistakes in UI code. They stay active in release
/// builds and go through rtgt::imguiAssertFailed(): the application logs them,
/// the unit tests turn them into test failures.

#ifndef RTGT_IMCONFIG_H
#define RTGT_IMCONFIG_H

namespace rtgt {
void imguiAssertFailed(const char* expression, const char* file, int line);
}

#define IM_ASSERT(_EXPR) ((_EXPR) ? (void)0 : rtgt::imguiAssertFailed(#_EXPR, __FILE__, __LINE__))

#endif
