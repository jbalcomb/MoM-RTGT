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
	MoMController()
	{}

	const std::string& errorString() const
	{
		return m_errorString;
	}

    bool addUnit(MoMGameBase& game, ePlayer playerNr, eUnit_Type unitType);

    bool applyBuildingQueue(MoMGameBase& game, int cityNr);
    bool applyBuildingQueue(MoMGameBase& game, ePlayer playerNr);

	static bool findCheapestUnitToProduce(MoMGameBase& game, const City& city, eProducing& produce);
    static bool findUnitsAtLocation(MoMGameBase& game, const MoMLocation& location, std::vector<int>& units);

	static bool isBuildingAllowed(MoMGameBase& game, const City& city, eBuilding building);
	static bool isBuildingPresent(const City& city, eBuilding building);

    bool polymorphToHero(MoMGameBase& game, ePlayer playerNr, int unitNr, eUnit_Type heroNr);

    bool repopLairs(MoMGameBase& game, bool maxOut = false);

    bool validateConsistency(MoMGameBase& game);

private:
    bool createUnit(MoMGameBase& game, int& unitNr);

	std::string m_errorString;
};

}
