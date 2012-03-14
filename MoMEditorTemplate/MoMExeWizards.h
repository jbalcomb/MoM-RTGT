// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#ifndef MOMWIZARDSEXE_H
#define MOMWIZARDSEXE_H

#include "MoMExeBase.h"
#include "MoMTemplate.h"

namespace MoM {

class MoMExeWizards : public MoMExeBase
{
public:
    struct SpellSaveEntry
    {
        size_t spellOffset;
        size_t saveOffset;
    };

    MoMExeWizards();

    virtual void close() throw();

    bool load(const std::string& filename);

    size_t getNrSpellSaves() const;
    SpellSaveEntry getSpellSave(size_t nr);
};

}

#endif
