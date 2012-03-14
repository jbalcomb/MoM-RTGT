// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#include "MoMGameBase.h"
#include "MoMProcess.h"
#include "MoMExeMagic.h"

namespace MoM {


class MoMGameCustom : public MoMGameBase
{
public:
    MoMGameCustom(void);
    virtual ~MoMGameCustom();

    void closeGame() throw();

    virtual bool commitData(void* ptr, const void* pNewValue, size_t size);

    bool openGame(std::auto_ptr<MoMProcess>& momProcess);

    virtual std::string getGameDirectory();

    virtual const char* getNameByOffset(uint16_t offset);

    virtual bool isOpen() const
    {
        return ((0 != m_process.get()) && m_process->isOpen());
    }

    virtual bool readData()
    {
        return ((0 != m_process.get()) && m_process->readData());
    }

public:

    virtual std::string getSources() const
    {
        return "Connected setup " + m_filename_MagicExe;
    }
    virtual bool validate()
    {
        return true;
    }
    virtual MoM::City* getCities()
    {
        return 0;
    }
    virtual WizardsExe_Game_Data* getGame_Data_Exe();
    virtual Game_Settings* getGame_Settings();
    virtual MoM::Hero_stats* getList_Hero_stats(MoM::ePlayer)
    {
        return 0;
    }
    virtual MoM::Item* getItems()
    {
        return 0;
    }
    virtual MoM::Tower_Node_Lair* getLairs()
    {
        return 0;
    }
    virtual uint16_t* getNumber_of_Cities()
    {
        return 0;
    }
    virtual uint16_t* getNumber_of_Units()
    {
        return 0;
    }
    virtual uint16_t* getNumber_of_Wizards();
    virtual MoM::Unit* getUnits()
    {
        return 0;
    }
    virtual MoM::Wizard* getWizards();

// private:
    virtual MoMMagicDataSegment* getMagicDataSegment();

    virtual uint8_t* getMagicOverlay(size_t ovlNr);

    virtual uint8_t* getMagicExeContents()
    {
        if (0 == m_MagicExe.get())
            return 0;
        return m_MagicExe->getExeContents();
    }

    virtual MoMMagicDataSegment* getMagicExeDataSegment()
    {
        if (0 == m_MagicExe.get())
            return 0;
        return (MoMMagicDataSegment*)m_MagicExe->getDataSegment();
    }

    virtual MoMExeMagic* getMagicExe()
    {
        return m_MagicExe.get();
    }

private:
    template< typename T >
    T* derefHeapPointer(const EXE_Reloc& pointer, size_t nr_elements)
    {
        if (0 == m_process.get())
            return 0;

        if ((EXE_Reloc*)0 == validateStaticPointer((EXE_Reloc*)&pointer, 1))
            return 0;
        MoMMagicDataSegment* pMoMDataSegment = (MoMMagicDataSegment*)m_process->getDatasegmentData();
        if (0 == pMoMDataSegment)
            return 0;
        T* ptr = (T*)m_process->derefPointer(pointer, nr_elements * sizeof(T));
        if ((uint8_t*)ptr < (uint8_t*)pMoMDataSegment + sizeof(MoMMagicDataSegment))
        {
            ptr = 0;
        }
        return ptr;
    }

    template< typename T >
    T* validateStaticPointer(T* ptr, size_t nr_elements)
    {
        if (0 == m_process.get())
            return 0;

        MoMMagicDataSegment* pMoMDataSegment = (MoMMagicDataSegment*)m_process->getDatasegmentData();
        if (0 == pMoMDataSegment)
            return 0;
        if (!m_process->validPointer(ptr, nr_elements * sizeof(T)))
            return 0;
        if ((uint8_t*)ptr < (uint8_t*)pMoMDataSegment)
            return 0;
        if ((uint8_t*)ptr + nr_elements * sizeof(T) > (uint8_t*)pMoMDataSegment + sizeof(MoMMagicDataSegment))
            return 0;

        return ptr;
    }


    std::auto_ptr<MoMProcess> m_process;
    std::auto_ptr<MoMExeMagic> m_MagicExe;
    std::string m_filename_MagicExe;
};

}
