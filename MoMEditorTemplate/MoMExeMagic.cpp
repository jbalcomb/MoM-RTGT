// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include "MoMExeMagic.h"

namespace MoM
{

namespace
{
const size_t gSIZE_MAGIC_EXE = 303264;

const size_t gOFFSET_STUB_SEGMENT_ENTRIES = 0x23f00;
const size_t gNR_STUB_SEGMENTS = 14;
const size_t gFIRST_STUB_NR = 48;
}

MoMExeMagic::MoMExeMagic() :
    MoMExeBase()
{
}

void MoMExeMagic::close() throw()
{
    MoMExeBase::close();
}

bool MoMExeMagic::load(const std::string& filename)
{
    setOverlayParameters(gOFFSET_STUB_SEGMENT_ENTRIES, gNR_STUB_SEGMENTS, gFIRST_STUB_NR);

    bool ok = MoMExeBase::load(filename);

    return ok;

}

}

