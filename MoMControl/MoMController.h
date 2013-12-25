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
    explicit MoMController(MoMGameBase* game) :
        m_game(game)
	{}

	const std::string& errorString() const
	{
		return m_errorString;
	}

    bool addUnit(ePlayer playerNr, eUnit_Type unitType);

    bool applyBuildingQueue(int cityNr);
    bool applyBuildingQueue(ePlayer playerNr);

    int  countGarrison(const MoMLocation& location);
    int  countUnits(const MoMLocation& location);
    bool findCheapestUnitToProduce(const City& city, eProducing& produce);
    City* findCityAtLocation(const MoMLocation& location);
    Node_Attr* findNodeAttrAtLocation(const MoMLocation& location);

    bool polymorphToHero(ePlayer playerNr, int unitNr, eUnit_Type heroNr);

    bool removeCityFromGameQueue(int cityNr);

    bool repopLairs(bool maxOut = false);

private:
//    bool addCitiesToGameQueue();

    bool createUnit(int& unitNr);

    MoMGameBase* m_game;
	std::string m_errorString;
};

}
