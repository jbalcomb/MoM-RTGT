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
#include "MoMUtility.h"
#include "MoMExeWizards.h"

#include "MoMGameSave.h"

namespace MoM {

namespace {

const std::string gLowercaseMagicPrefix = "magic";
const std::string gLowercaseWizardsPrefix = "wizards";

std::string lowercase_filetitle(const std::string& filename)
{
    std::string filetitle;
    size_t pos = filename.find_last_of("/\\");
    if (std::string::npos != pos)
    {
        filetitle = filename.substr(pos + 1);
    }
    else
    {
        filetitle = filename;
    }

    return lowercase(filetitle);
}

std::string lowercase_extension(const std::string& filename)
{
    std::string lwr_filetitle = lowercase_filetitle(filename);
    std::string ext;
    size_t pos = lwr_filetitle.find_last_of('.');
    if (std::string::npos != pos)
    {
        ext = lwr_filetitle.substr(pos);
    }
    return ext;
}

}


MoMGameSave::MoMGameSave() :
	MoMGameBase(),
    m_SaveGame(),
    m_filename_SaveGame(),
    m_MagicExe(),
    m_WizardsExe(),
    m_filename_MagicExe(),
    m_filename_WizardsExe(),
    m_BuilddatLbx(),
    m_SpelldatLbx(),
    m_TerrstatLbx(),
    m_GameDirectory(),
    m_playerNr(PLAYER_YOU)
{
}

MoMGameSave::~MoMGameSave()
{
    closeGame();
}

void MoMGameSave::closeGame() throw()
{
}

bool MoMGameSave::commitData(void* ptr, const void* pNewValue, size_t size)
{
    setErrorString("");
    // TODO: Check memory pointer + range
    memcpy(ptr, pNewValue, size);
    return true;
}

std::string MoMGameSave::getGameDirectory() const
{
    return m_GameDirectory;
}

uint8_t* MoMGameSave::getWizardsOverlay(size_t ovlNr)
{
    uint8_t* ptr = 0;

    if (0 != m_WizardsExe.get())
    {
        ptr = m_WizardsExe->getOverlay(ovlNr);
    }

    return ptr;
}

uint8_t* MoMGameSave::getMagicOverlay(size_t ovlNr)
{
    uint8_t* ptr = 0;

    if (0 != m_MagicExe.get())
    {
        ptr = m_MagicExe->getOverlay(ovlNr);
    }

    return ptr;
}

bool MoMGameSave::load(const char* filename)
{
    assert(0 != filename);
    setErrorString("");

    std::string lower_filetitle = lowercase_filetitle(filename);
    std::string ext = lowercase_extension(filename);
    if (".gam" == ext)
    {
        std::ifstream ifs(filename, std::ios_base::in | std::ios_base::binary);
        if (!ifs)
        {
            setErrorString("Could not open file '" + toStr(filename) + "' for reading");
            std::cout << errorString() << std::endl;
            return false;
        }

        m_SaveGame.reset(new SaveGame);
        memset(m_SaveGame.get(), '\0', sizeof(SaveGame));
        if (!ifs.read((char*)m_SaveGame.get(), sizeof(SaveGame)))
        {
            setErrorString("Could not (fully) read file '" + toStr(filename) + "'");
            std::cout << errorString() << std::endl;
            return false;
        }
        m_filename_SaveGame = filename;
    }
    else if ("builddat.lbx" == lower_filetitle)
    {
        m_BuilddatLbx.reset(new MoMLbxBase);
        bool ok = m_BuilddatLbx->load(filename);
        if (!ok)
        {
            setErrorString("Could not (fully) read file '" + toStr(filename) + "'");
            std::cout << errorString() << std::endl;
            return false;
        }
    }
    else if ("spelldat.lbx" == lower_filetitle)
    {
        m_SpelldatLbx.reset(new MoMLbxBase);
        bool ok = m_SpelldatLbx->load(filename);
        if (!ok)
        {
            setErrorString("Could not (fully) read file '" + toStr(filename) + "'");
            std::cout << errorString() << std::endl;
            return false;
        }
    }
    else if ("terrstat.lbx" == lower_filetitle)
    {
        m_TerrstatLbx.reset(new MoMLbxBase);
        bool ok = m_TerrstatLbx->load(filename);
        if (!ok)
        {
            setErrorString("Could not (fully) read file '" + toStr(filename) + "'");
            std::cout << errorString() << std::endl;
            return false;
        }
    }
    else if (".lbx" == ext)
    {
        MoMLbxBase lbxFile;
        bool ok = lbxFile.load(filename);
        if (!ok)
        {
            setErrorString("Could not (fully) read file '" + toStr(filename) + "'");
            std::cout << errorString() << std::endl;
            return false;
        }
    }
    else if ((lower_filetitle.substr(0, gLowercaseMagicPrefix.size()) == gLowercaseMagicPrefix) && (".exe" == ext))
    {
        m_MagicExe.reset(new MoMExeMagic);
        if (!m_MagicExe->load(filename))
        {
            setErrorString("Could not (fully) read file '" + toStr(filename) + "'");
            std::cout << errorString() << std::endl;
            return false;
        }

        m_filename_MagicExe = filename;
    }
    else if ((lower_filetitle.substr(0, gLowercaseWizardsPrefix.size()) == gLowercaseWizardsPrefix) && (".exe" == ext))
    {
        m_WizardsExe.reset(new MoMExeWizards);
        if (!m_WizardsExe->load(filename))
        {
            setErrorString("Could not (fully) read file '" + toStr(filename) + "'");
            std::cout << errorString() << std::endl;
            return false;
        }

        m_filename_WizardsExe = filename;
    }
    else
    {
        setErrorString("Filename pattern unrecognized of '" + toStr(filename) + "'");
        std::cout << errorString() << std::endl;
        return false;
    }

    // Use last succesfully loaded file to identify the game directory
    m_GameDirectory = dirFromFilepath(filename);

    return true;
}


bool MoMGameSave::save(const char* filename)
{
    assert(0 != filename);
    setErrorString("");

    std::string lower_filetitle = lowercase_filetitle(filename);
    std::string ext = lowercase_extension(filename);
    if (".gam" == ext)
    {
        if (0 == m_SaveGame.get())
        {
            setErrorString("Cannot save to '" + toStr(filename) + "' because no SAVEn.GAM was loaded");
            std::cout << errorString() << std::endl;
            return false;
        }

        std::ofstream ofs(filename, std::ios_base::out | std::ios_base::binary);
        if (!ofs)
        {
            setErrorString("Could not open file '" + toStr(filename) + "' for writing");
            std::cout << errorString() << std::endl;
            return false;
        }

        if (!ofs.write((const char*)m_SaveGame.get(), sizeof(SaveGame)))
        {
            setErrorString("Could not write SAVEn.GAM data (fully) to file '" + toStr(filename) + "'");
            std::cout << errorString() << std::endl;
            return false;
        }

        m_filename_SaveGame = filename;
    }
    else if ((lower_filetitle.substr(0, gLowercaseMagicPrefix.size()) == gLowercaseMagicPrefix) && (".exe" == ext))
    {
        if (0 == m_MagicExe.get())
        {
            setErrorString("Cannot save to '" + toStr(filename) + "' because no MAGIC.EXE was loaded");
            std::cout << errorString() << std::endl;
            return false;
        }

        if (!m_MagicExe->save(filename))
        {
            setErrorString("Could not write MAGIC.EXE data (fully) to file '" + toStr(filename) + "'");
            std::cout << errorString() << std::endl;
            return false;
        }

        m_filename_WizardsExe = filename;
    }
    else if ((lower_filetitle.substr(0, gLowercaseWizardsPrefix.size()) == gLowercaseWizardsPrefix) && (".exe" == ext))
    {
        if (0 == m_WizardsExe.get())
        {
            setErrorString("Cannot save to '" + toStr(filename) + "' because no WIZARDS.EXE was loaded");
            std::cout << errorString() << std::endl;
            return false;
        }

        if (!m_WizardsExe->save(filename))
        {
            setErrorString("Could not write WIZARDS.EXE data (fully) to file '" + toStr(filename) + "'");
            std::cout << errorString() << std::endl;
            return false;
        }

        m_filename_WizardsExe = filename;
    }
    else if ("builddat.lbx" == lower_filetitle)
    {
        if (0 == m_BuilddatLbx.get())
        {
            setErrorString("Cannot save to '" + toStr(filename) + "' because no BUILDDAT.LBX was loaded");
            std::cout << errorString() << std::endl;
            return false;
        }

        if (!m_BuilddatLbx->save(filename))
        {
            setErrorString("Could not write BUILDDAT.LBX data (fully) to file '" + toStr(filename) + "'");
            std::cout << errorString() << std::endl;
            return false;
        }
    }
    else if ("spelldat.lbx" == lower_filetitle)
    {
        if (0 == m_SpelldatLbx.get())
        {
            setErrorString("Cannot save to '" + toStr(filename) + "' because no SPELLDAT.LBX was loaded");
            std::cout << errorString() << std::endl;
            return false;
        }

        if (!m_SpelldatLbx->save(filename))
        {
            setErrorString("Could not write SPELLDAT.LBX data (fully) to file '" + toStr(filename) + "'");
            std::cout << errorString() << std::endl;
            return false;
        }
    }
    else if ("terrstat.lbx" == lower_filetitle)
    {
        if (0 == m_TerrstatLbx.get())
        {
            setErrorString("Cannot save to '" + toStr(filename) + "' because no TERRSTAT.LBX was loaded");
            std::cout << errorString() << std::endl;
            return false;
        }

        if (!m_TerrstatLbx->save(filename))
        {
            setErrorString("Could not write TERRSTAT.LBX data (fully) to file '" + toStr(filename) + "'");
            std::cout << errorString() << std::endl;
            return false;
        }
    }
    else
    {
        setErrorString("Could not write WIZARDS.EXE data (fully) to file '" + toStr(filename) + "'");
        std::cout << errorString() << std::endl;
        return false;
    }

    return true;
}

bool MoMGameSave::addLair()
{
    setErrorString("");
    if (0 == m_SaveGame.get())
        return false;

    bool ok = true;
    int lairNr = 0;     // Relocate and change Node[0].

    // Note: UNK fields left unchanged
    Tower_Node_Lair& lair = m_SaveGame->m_Arcanus_Nodes[lairNr];

    lair.m_XPos = m_SaveGame->m_Wizards[m_playerNr].m_X_Coordinate_of_Summoning_Circle + 2;
    lair.m_YPos = m_SaveGame->m_Wizards[m_playerNr].m_Y_Coordinate_of_Summoning_Circle + 1;
    lair.m_Plane = m_SaveGame->m_Wizards[m_playerNr].m_Plane_of_Summoning_Circle;
    lair.m_Status = LAIRSTATUS_intact;
    lair.m_Type = LAIRTYPE_Sorcery_node;
    lair.m_Inhabitant1.m_Inhabitant = UNITTYPE_Blue_Air_Elemental;
    lair.m_Inhabitant1.m_Initial_Nr_of_Inhabitant = 2;
    lair.m_Inhabitant1.m_Remaining_Nr_of_Inhabitant = 2;
    lair.m_Inhabitant2.m_Inhabitant = UNITTYPE_Blue_Phantom_Beast;
    lair.m_Inhabitant2.m_Initial_Nr_of_Inhabitant = 4;
    lair.m_Inhabitant2.m_Remaining_Nr_of_Inhabitant = 4;
    lair.m_Flags.bits = 7;

    Node_Attr& nodeAttr = m_SaveGame->m_Arcanus_Node_Attr[lairNr];
    for (unsigned i = 0; i < ARRAYSIZE(nodeAttr.m_XPos_Mana); ++i)
    {
        nodeAttr.m_XPos_Mana[i] += lair.m_XPos - nodeAttr.m_XPos;
        nodeAttr.m_YPos_Mana[i] += lair.m_YPos - nodeAttr.m_YPos;
    }
    nodeAttr.m_XPos = lair.m_XPos;
    nodeAttr.m_YPos = lair.m_YPos;
    nodeAttr.m_Plane = lair.m_Plane;
    nodeAttr.m_Owner = PLAYER_Dismissed_Deceased;
    nodeAttr.m_Node_Type = NODETYPE_Sorcery;

    if (PLANE_Arcanum == lair.m_Plane)
    {
        m_SaveGame->m_Arcanus_Map_Row[lair.m_YPos].m_Tile[lair.m_XPos] = grasslands_w_sorcery_node;
    }
    else if (PLANE_Myrror == lair.m_Plane)
    {
        m_SaveGame->m_Myrror_Map_Row[lair.m_YPos].m_Tile[lair.m_XPos] = grasslands_w_sorcery_node;
    }

    return ok;
}

bool MoMGameSave::findYourFirstUnit(int& unitNr)
{
    setErrorString("");
    if (0 == m_SaveGame.get())
        return false;

    bool found = false;
    for (unsigned lUnitNr = 0; lUnitNr < m_SaveGame->m_Game_Data.m_Number_of_Units && lUnitNr < ARRAYSIZE(m_SaveGame->m_Unit); ++lUnitNr)
    {
        const Unit& unit = m_SaveGame->m_Unit[lUnitNr];

        if (PLAYER_YOU == unit.m_Owner)
        {
            found = true;
            unitNr = (int)lUnitNr;
            break;
        }
    }
    return found;
}

bool MoMGameSave::findOthersFirstUnit(int& unitNr)
{
    setErrorString("");
    if (0 == m_SaveGame.get())
        return false;

    bool found = false;
    for (unsigned lUnitNr = 0; lUnitNr < m_SaveGame->m_Game_Data.m_Number_of_Units && lUnitNr < ARRAYSIZE(m_SaveGame->m_Unit); ++lUnitNr)
    {
        const Unit& unit = m_SaveGame->m_Unit[lUnitNr];

        if (PLAYER_YOU != unit.m_Owner)
        {
            found = true;
            unitNr = (int)lUnitNr;
            break;
        }
    }
    return found;
}

std::string MoMGameSave::getSources() const
{
    std::string sources;
    if (!m_GameDirectory.empty())
    {
        sources += m_GameDirectory + " - ";
    }
    if (!m_filename_SaveGame.empty())
    {
        sources += " " + m_filename_SaveGame;
    }
    if (!m_filename_MagicExe.empty())
    {
        sources += " " + m_filename_MagicExe;
    }
    if (!m_filename_WizardsExe.empty())
    {
        sources += " " + m_filename_WizardsExe;
    }
    if (0 != m_BuilddatLbx.get())
    {
        sources += " " + m_BuilddatLbx->getFilename();
    }
    if (0 != m_SpelldatLbx.get())
    {
        sources += " " + m_SpelldatLbx->getFilename();
    }
    if (0 != m_TerrstatLbx.get())
    {
        sources += " " + m_TerrstatLbx->getFilename();
    }
    if (sources.empty())
    {
        sources = "MASTER OF MAGIC - Real-Time Game Tweaker";
    }
    return sources;
}

bool MoMGameSave::validate()
{
    setErrorString("");
    if (0 == m_SaveGame.get())
        return false;

    bool ok = MoM::validate(*m_SaveGame,  "MoM files");

    MoMController momController(this);
    ok |= momController.validateConsistency();

    return ok;
}

}
