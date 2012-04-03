// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#include "MoMGameBase.h"
#include "MoMProcess.h"
#include "MoMExeWizards.h"

namespace MoM {

class MoMGameMemory :
    public MoMGameBase
{
public:
    MoMGameMemory(void);
    virtual ~MoMGameMemory()
    {
        closeGame();
    }

    void closeGame() throw();

    bool commitChanges();
    virtual bool commitData(void* ptr, const void* pNewValue, size_t size);

//    bool findAndOpenGame(const std::string& windowTitle);
    bool openGame(std::auto_ptr<MoMProcess>& momProcess);

    virtual std::string getGameDirectory();

    virtual eGameState* getGameState();
    virtual uint16_t* getGameTurn();
    virtual const char* getNameByOffset(uint16_t offset);

    virtual std::string getSources() const
    {
        return "Connected game " + m_filename_WizardsExe;
    }

    virtual bool isOpen() const
    {
        return ((0 != m_process.get()) && m_process->isOpen());
    }

    virtual bool readData()
    {
        return ((0 != m_process.get()) && m_process->readData());
    }

    virtual bool validate();

private:
    template< typename T >
    T* derefHeapPointer(const EXE_Reloc& pointer, size_t nr_elements)
    {
        assert(0 != m_process.get());
        if ((EXE_Reloc*)0 == validateStaticPointer((EXE_Reloc*)&pointer, 1))
            return 0;
        MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
        if (0 == pMoMDataSegment)
            return 0;
        T* ptr = (T*)m_process->derefPointer(pointer, nr_elements * sizeof(T));
        if ((uint8_t*)ptr < (uint8_t*)pMoMDataSegment + sizeof(MoMDataSegment))
        {
            ptr = 0;
        }
        return ptr;
    }

    template< typename T >
    T* validateStaticPointer(T* ptr, size_t nr_elements)
    {
        assert(0 != m_process.get());
        MoMDataSegment* pMoMDataSegment = (MoMDataSegment*)m_process->getDatasegmentData();
        if (0 == pMoMDataSegment)
            return 0;
        if (!m_process->validPointer(ptr, nr_elements * sizeof(T)))
            return 0;
        if ((uint8_t*)ptr < (uint8_t*)pMoMDataSegment)
            return 0;
        if ((uint8_t*)ptr + nr_elements * sizeof(T) > (uint8_t*)pMoMDataSegment + sizeof(MoMDataSegment))
            return 0;

        return ptr;
    }

    virtual Available_spell_page* getAvailable_spell_pages();
    virtual Battlefield* getBattlefield();
    virtual Battle_Unit* getBattle_Unit_View();
    virtual Battle_Unit* getBattle_Units();
    virtual eBonusDeposit* getBonusDeposits();
    virtual Building_Data* getBuilding_Data();
    virtual City* getCities();
    virtual Events_Status* getEvents_Status();
    virtual Fortress* getFortresses();
    virtual WizardsExe_Game_Data* getGame_Data_Exe();
    virtual Game_Settings* getGame_Settings();
    virtual eSpell16* getHero_spells();
    virtual Hero_stats* getList_Hero_stats(ePlayer playerNr);
    virtual Item* getItems();
    virtual Tower_Node_Lair* getLairs();
    virtual uint16_t* getNumber_of_Battle_Units();
    virtual uint16_t* getNumber_of_Cities();
    virtual uint16_t* getNumber_of_Units();
    virtual uint16_t* getNumber_of_Wizards();
    virtual Spell_Data* getSpell_Data();
    virtual Spells_Cast_in_Battle* getSpells_Cast_in_Battle();
    virtual eTerrainType* getTerrainTypes();
    virtual Unit* getUnits();
    virtual Unit_Type_Data* getUnit_Types();
    virtual int8_t* getUnrest_Table(eRace homeRace);
    virtual Wizard* getWizards();


    virtual MoMDataSegment* getDataSegment();
    virtual const uint8_t* getSeg0Pointer()
    {
        if (0 == m_process.get())
            return 0;
        return m_process->getSeg0Pointer();
    }
    virtual uint8_t* getWizardsExeContents()
    {
        if (0 == m_WizardsExe.get())
            return 0;
        return m_WizardsExe->getExeContents();
    }
    virtual MoMDataSegment* getWizardsExeDataSegment()
    {
        if (0 == m_WizardsExe.get())
            return 0;
        return (MoMDataSegment*)m_WizardsExe->getDataSegment();
    }
    virtual uint8_t* getWizardsOverlay(size_t ovlNr);

    virtual MoMExeWizards* getWizardsExe()
    {
        return m_WizardsExe.get();
    }

    std::auto_ptr<MoMProcess> m_process;
    std::auto_ptr<MoMExeWizards> m_WizardsExe;
    std::string m_filename_WizardsExe;
};

}
