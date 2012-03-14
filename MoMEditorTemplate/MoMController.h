// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#include <vector>

#include "MoMGameBase.h"

namespace MoM {

class MoMController
{
public:
    static bool addUnit(MoMGameBase& game, ePlayer playerNr, eUnit_Type unitType);

    static bool applyBuildingQueue(MoMGameBase& game, int cityNr);
    static bool applyBuildingQueue(MoMGameBase& game, ePlayer playerNr);

    static bool findUnitsAtLocation(MoMGameBase& game, const Location& location, std::vector<int>& units);

    static bool polymorphToHero(MoMGameBase& game, ePlayer playerNr, int unitNr, eUnit_Type heroNr);

    static bool repopLairs(MoMGameBase& game, bool maxOut = false);

    static bool validateConsistency(MoMGameBase& game);

private:
    static bool createUnit(MoMGameBase& game, int& unitNr);
};

}
