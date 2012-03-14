// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include <assert.h>
#include <ctype.h>      // tolower()
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>     // memset(), strncpy(), strrchr()

#include "MoMController.h"
#include "MoMGenerated.h"
#include "MoMLbxBase.h"
#include "MoMutility.h"
#include "MoMExeWizards.h"

#include "MoMGameBase.h"

namespace MoM {

MoMGameBase::MoMGameBase()
{
    assert(1 == sizeof(eSkill) && "Check enum-size (g++ flag -fshort-enums)");
    assert(0x04C8 == sizeof(Wizard) && "Check pack-struct (g++ flag -fpack-struct)");
}

MoMGameBase::~MoMGameBase()
{
}

// TODO: Centralize getGameDirectory() here.

// TODO: Replace all references in other modules to race names by getRaceName()

std::string MoMGameBase::getRaceName(eRace race)
{
	std::string raceName;
 	const MoMDataSegment* pMoMDataSegment = getDataSegment();
    if ((0 != pMoMDataSegment) && (static_cast<unsigned>(race) < gMAX_RACES))
	{
		const char* ptrName = getNameByOffset(pMoMDataSegment->m_Race_Data[race].m_PtrName);
		if (0 != ptrName)
		{
			raceName = ptrName;
		}
	}
	if (raceName.empty())
	{
		raceName = toStr(race);
		// Strip Capital prefix
		size_t pos = 0;
		while ((pos < raceName.size()) && isupper(raceName[pos]))
		{
			pos++;
		}
		if ((pos >= 2) && (pos + 1 < raceName.size()))
		{
			raceName = raceName.substr(pos + 1);
		}
		// Strip trailing numbers
		pos = raceName.find('(');
		if (std::string::npos == pos)
		{
			raceName = raceName.substr(0, pos);
		}
		// Replace underscores by spaces
		while (std::string::npos != (pos = raceName.find('_')))
		{
			raceName[pos] = ' ';
		}
	}
	return raceName;
}

}
