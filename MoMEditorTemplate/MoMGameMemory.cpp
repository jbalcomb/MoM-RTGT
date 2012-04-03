// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include <assert.h>
#include <fstream>
#include <iostream>
#include <string.h> // memcmp()

#include "MoMController.h"
#include "MoMUtility.h"
#include "MoMExeWizards.h"

#include "MoMGameMemory.h"

namespace MoM {

namespace {

const size_t gMAX_NAME_SIZE = 256;

}

MoMGameMemory::MoMGameMemory(void)
: MoMGameBase(),
  m_process(),
  m_WizardsExe(),
  m_filename_WizardsExe()
{
}

void MoMGameMemory::closeGame() throw()
{
    try
    {
        m_process.reset();
        m_WizardsExe.reset();
        m_filename_WizardsExe.clear();
    }
    catch (...)
    {
        // Make sure this cleanup function does not throw
    }
}

bool MoMGameMemory::commitChanges()
{
    if (0 == m_process.get())
        return false;

    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    if (0 == pMoMDataSegment)
        return false;

    // TODO: Not everything is written, but in the current usage only contents of Lairs (Repop Lairs) or Cities (Build queues) are needed
    bool ok = true;
    if (ok) ok = m_process->writeData(this->getCities(), gMAX_CITIES * sizeof(City));
    if (ok) ok = m_process->writeData(this->getNumber_of_Cities(), sizeof(uint16_t));
    if (ok) ok = m_process->writeData(this->getUnit_Types(), eUnit_Type_MAX * sizeof(MoM::Unit_Type_Data));
    if (ok) ok = m_process->writeData(this->getLairs(), gMAX_NODES_LAIRS_TOWERS * sizeof(Tower_Node_Lair));
    for (ePlayer playerNr = (ePlayer)0; (unsigned)playerNr < gMAX_VALID_WIZARDS; inc(playerNr))
    {
        if (ok) ok = m_process->writeData(this->getList_Hero_stats(playerNr), sizeof(List_Hero_stats));
    }
    if (ok) ok = m_process->writeData(this->getUnits(), gMAX_UNITS * sizeof(Unit));
    if (ok) ok = m_process->writeData(this->getNumber_of_Units(), sizeof(uint16_t));
    if (ok) ok = m_process->writeData(this->getWizards(), gMAX_VALID_WIZARDS * sizeof(Wizard));

    return ok;
}

bool MoMGameMemory::commitData(void* ptr, const void* pNewValue, size_t size)
{
    bool ok = true;

    // TODO: Compare old value with new value BEFORE commit
    //       What to do if the memory has changed? Perhaps significantly?
    //       - DOSBox restarted
    //       - MoM MAGIC.EXE or WIZARDS.EXE restarted
    //       - Content of memory reordered, such as the order of the Units
    //       Presumably we want to warn the user of this and allow him to overrule
    if ((0 != m_WizardsExe.get()) && m_WizardsExe->writeData(ptr, pNewValue, size))
    {
        memcpy(ptr, pNewValue, size);
        /*
        // TODO: Give warning with confirm to modify the file
        // TODO: Make backup of original if not already done so
        //       Let's call it "WIZARDS.EXE_TweakerBackup"
        std::fstream::pos_type pos = (std::fstream::pos_type)(ptrByte - (uint8_t*)m_WizardsExe.get());
        std::fstream fs(m_filename_WizardsExe.c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::binary);
        if (!fs)
        {
            std::cout << "WARN: Could not open file for writing '" << m_filename_WizardsExe << "'" << std::endl;
            ok = false;
        }
        else if (!fs.seekp(pos))
        {
            std::cout << "WARN: Could not seek to pos 0x" << std::hex << pos << std::dec << " in file '" << m_filename_WizardsExe << "'" << std::endl;
            ok = false;
        }
        else if (!fs.write((const char*)pNewValue, size))
        {
            std::cout << "WARN: Could not write data to pos 0x" << std::hex << pos << std::dec << " in file '" << m_filename_WizardsExe << "'" << std::endl;
            ok = false;
        }
        else
        {
            std::cout << "INFO: " << size << " bytes written to pos 0x" << std::hex << pos << std::dec << " in file '" << m_filename_WizardsExe << "'" << std::endl;
            memcpy(ptr, pNewValue, size);
        }
        */
    }
    else if (0 != m_process.get())
    {
        memcpy(ptr, pNewValue, size);
        ok = m_process->writeData(ptr, size);
    }
    else
    {
        ok = false;
    }
    return ok;
}

/*
bool MoMGameMemory::findAndOpenGame(const std::string& windowTitle)
{
    closeGame();

    std::auto_ptr<MoMProcess> momProcess( new MoMProcess );

    if (!momProcess->findProcessAndData(windowTitle))
    {
        return false;
    }

    if (!openGame(momProcess))
    {
        return false;
    }

    return true;
}
*/

Available_spell_page* MoMGameMemory::getAvailable_spell_pages()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return (Available_spell_page*)((uint8_t*)pMoMDataSegment + pMoMDataSegment->m_offset_Available_spell_pages);
}

Battlefield* MoMGameMemory::getBattlefield()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    if (0 == pMoMDataSegment)
        return false;
    return derefHeapPointer<Battlefield>(pMoMDataSegment->m_WizardsExe_Pointers.addr_Battlefield, 1);
}

Battle_Unit* MoMGameMemory::getBattle_Unit_View()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return derefHeapPointer<Battle_Unit>(pMoMDataSegment->m_WizardsExe_Pointers.addr_Battle_Unit_View, 1);
}

uint16_t* MoMGameMemory::getNumber_of_Battle_Units()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return validateStaticPointer(&pMoMDataSegment->m_Nr_Battle_Units, 1);
}

Battle_Unit* MoMGameMemory::getBattle_Units()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return derefHeapPointer<Battle_Unit>(pMoMDataSegment->m_WizardsExe_Pointers.addr_Battle_Unit, MoM::gMAX_BATTLE_UNITS);
}

eBonusDeposit* MoMGameMemory::getBonusDeposits()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return derefHeapPointer<eBonusDeposit>(pMoMDataSegment->m_WizardsExe_Pointers.addr_special_terrain_loc_,
            ePlane_MAX * gMAX_MAP_ROWS * gMAX_MAP_COLS);
}

City* MoMGameMemory::getCities()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return derefHeapPointer<City>(pMoMDataSegment->m_WizardsExe_Pointers.addr_Cities, MoM::gMAX_CITIES);
}

MoMDataSegment* MoMGameMemory::getDataSegment()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return validateStaticPointer(pMoMDataSegment, 1);
}

Building_Data* MoMGameMemory::getBuilding_Data()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return derefHeapPointer<Building_Data>(pMoMDataSegment->m_WizardsExe_Pointers.addr_Building_Data, eBuilding_MAX);
}

Events_Status* MoMGameMemory::getEvents_Status()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return derefHeapPointer<Events_Status>(pMoMDataSegment->m_WizardsExe_Pointers.addr_events, 1);
}

Fortress* MoMGameMemory::getFortresses()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
	return derefHeapPointer<Fortress>(pMoMDataSegment->m_WizardsExe_Pointers.addr_fortress_data, gMAX_WIZARD_RECORDS);
}

std::string MoMGameMemory::getGameDirectory()
{
    std::string dir;
    if (0 != m_process.get())
    {
        dir = dirFromFilepath(m_process->getExeFilepath());
    }
    return dir;
}

WizardsExe_Game_Data* MoMGameMemory::getGame_Data_Exe()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return validateStaticPointer(&pMoMDataSegment->m_Game_Data, 1);
}

Game_Settings* MoMGameMemory::getGame_Settings()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return validateStaticPointer(&pMoMDataSegment->m_Game_Settings, 1);
}

eGameState* MoMGameMemory::getGameState()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return validateStaticPointer(&pMoMDataSegment->m_WizardsExe_Pointers.w_Game_flow, 1);
}

uint16_t* MoMGameMemory::getGameTurn()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return validateStaticPointer(&pMoMDataSegment->m_Game_Data.m_Current_Turn, 1);
}

Item* MoMGameMemory::getItems()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return derefHeapPointer<Item>(pMoMDataSegment->m_WizardsExe_Pointers.addr_Items, MoM::gMAX_ITEMS);
}

eSpell16* MoMGameMemory::getHero_spells()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return derefHeapPointer<eSpell16>(pMoMDataSegment->m_addr_Hero_Spells, 4);
}

Hero_stats* MoMGameMemory::getList_Hero_stats(ePlayer playerNr)
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return derefHeapPointer<Hero_stats>(pMoMDataSegment->m_WizardsExe_Pointers.addr_Hero_stat[playerNr], MoM::gMAX_HERO_TYPES);
}

Tower_Node_Lair* MoMGameMemory::getLairs()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return derefHeapPointer<Tower_Node_Lair>(pMoMDataSegment->m_WizardsExe_Pointers.addr_Lairs_data, MoM::gMAX_NODES_LAIRS_TOWERS);
}

const char* MoMGameMemory::getNameByOffset(uint16_t offset)
{
    if (0 == m_process.get())
        return 0;
    char* namebuffer = (char*)m_process->getDatasegmentData();
    if (0 == validateStaticPointer(namebuffer, gMAX_NAME_SIZE))
        return 0;
    // Check if there is a terminating zero in range
    for (size_t i = 0; i < gMAX_NAME_SIZE; ++i)
    {
        if (namebuffer[i] == '\0')
        {
            return namebuffer + offset;
        }
    }
    // No terminating zero found
    return 0;
}

uint16_t* MoMGameMemory::getNumber_of_Cities()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return validateStaticPointer(&pMoMDataSegment->m_Game_Data.m_Number_of_Cities, 1);
}

uint16_t* MoMGameMemory::getNumber_of_Units()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return validateStaticPointer(&pMoMDataSegment->m_Game_Data.m_Number_of_Units, 1);
}

uint16_t* MoMGameMemory::getNumber_of_Wizards()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return validateStaticPointer(&pMoMDataSegment->m_Game_Data.m_Number_of_Wizards, 1);
}

uint8_t* MoMGameMemory::getWizardsOverlay(size_t ovlNr)
{
    if (0 == m_WizardsExe.get())
        return 0;

    uint8_t* ptr = m_WizardsExe->getOverlay(ovlNr);

    return ptr;
}

Spell_Data* MoMGameMemory::getSpell_Data()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return derefHeapPointer<Spell_Data>(pMoMDataSegment->m_WizardsExe_Pointers.addr_Spell_Data, MoM::eSpell_MAX);
}

Spells_Cast_in_Battle* MoMGameMemory::getSpells_Cast_in_Battle()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return derefHeapPointer<Spells_Cast_in_Battle>(pMoMDataSegment->m_WizardsExe_Pointers.addr_Spells_Cast_in_Battle, 1);
}

eTerrainType* MoMGameMemory::getTerrainTypes()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return derefHeapPointer<eTerrainType>(pMoMDataSegment->m_WizardsExe_Pointers.addr_TerrainTypes,
            ePlane_MAX * gMAX_MAP_ROWS * gMAX_MAP_COLS);
}

Unit* MoMGameMemory::getUnits()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return derefHeapPointer<Unit>(pMoMDataSegment->m_WizardsExe_Pointers.addr_Units, MoM::gMAX_UNITS);
}

Unit_Type_Data* MoMGameMemory::getUnit_Types()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return validateStaticPointer(&pMoMDataSegment->m_Hero_Types.Dwarf, MoM::eUnit_Type_MAX);
}

Wizard* MoMGameMemory::getWizards()
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return validateStaticPointer(pMoMDataSegment->m_Wizards, MoM::gMAX_WIZARD_RECORDS);
}

int8_t* MoMGameMemory::getUnrest_Table(eRace homeRace)
{
    if (0 == m_process.get())
        return 0;
    MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
    return derefHeapPointer<int8_t>(pMoMDataSegment->m_WizardsExe_Pointers.addr_Unrest_Table[homeRace], MoM::gMAX_RACES);
}

bool MoMGameMemory::openGame(std::auto_ptr<MoMProcess>& momProcess)
{
    if (0 == momProcess.get())
        return false;
    if (MoM::gOFFSET_WIZARDS_DSEG_CODE != momProcess->getOffset_DS_Code())
        return false;

    closeGame();

    // Transfer ownership
    m_process = momProcess;

    m_filename_WizardsExe = m_process->getExeFilepath();
    if (m_filename_WizardsExe.empty())
    {
        // TODO: errorhandling??
        return true;
    }

    m_WizardsExe.reset(new MoMExeWizards);
    if (!m_WizardsExe->load(m_filename_WizardsExe))
    {
        std::cout << "Could not (fully) read file '"<< m_filename_WizardsExe << "'" << std::endl;
        m_WizardsExe.reset();
        // TODO: errorhandling??
        return true;
    }

    return true;
}

bool MoMGameMemory::validate()
{
    if (0 == m_process.get())
        return 0;
    bool ok = true;

    std::cout << "NOTE: Validation in Memory currently only checks consistency and not any ranges" << std::endl;

    char* pDATASEGMENT_IDENTIFIER = validateStaticPointer((char*)m_process->getDatasegmentData(), sizeof(gDATASEGMENT_IDENTIFIER));
    if (0 == pDATASEGMENT_IDENTIFIER)
    {
        std::cout << "Access Violation: Not enough space for the DATASEGMENT IDENTIFIER" << std::endl;
        ok = false;
    }
    else if (0 != memcmp(pDATASEGMENT_IDENTIFIER, gDATASEGMENT_IDENTIFIER, sizeof(gDATASEGMENT_IDENTIFIER)))
    {
        std::cout << "Access Violation: The DATASEGMENT IDENTIFIER has been corrupted" << std::endl;
        ok = false;
    }
    else
    {
		MoMController momController;
        ok = momController.validateConsistency(*this);
    }

    return ok;
}

}
