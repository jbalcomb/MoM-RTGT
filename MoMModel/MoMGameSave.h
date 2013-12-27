// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

/// \file

#include "MoMGameBase.h"
#include "MoMLbxBase.h"
#include "MoMExeMagic.h"
#include "MoMExeWizards.h"

namespace MoM {

class MoMGameSave : public MoMGameBase
{
public:
    MoMGameSave();
    virtual ~MoMGameSave();

    virtual bool load(const char* filename);
    virtual bool save(const char* filename);

protected:
    bool addLair();
    bool findYourFirstUnit(int& unitNr);
    bool findOthersFirstUnit(int& unitNr);

    virtual void closeGame() throw();

    virtual bool commitData(void* ptr, const void* pNewValue, size_t size);

    virtual uint8_t* getArtifacts_in_game()
    {
        if (0 == m_SaveGame.get())
            return 0;
        return m_SaveGame->m_Artifacts_in_Game;
    }

    virtual Building_Data* getBuildingData()
    {
        if (0 == m_BuilddatLbx.get())
            return 0;
        uint8_t* data = m_BuilddatLbx->getRecord(0);
        return (Building_Data*)(data + 4);
    }

    virtual Hero_Choice* getChosen_Hero_Names()
    {
        if (0 == m_SaveGame.get())
            return 0;
        return m_SaveGame->m_Chosen_Hero_Names;
    }

    virtual City* getCities()
    {
        if (0 == m_SaveGame.get())
            return 0;
        return m_SaveGame->m_Cities;
    }

    virtual Events_Status* getEvents_Status()
    {
        if (0 == m_SaveGame.get())
            return 0;
        return &m_SaveGame->m_Events_Status;
    }

    virtual Fortress* getFortresses()
    {
        if (0 == m_SaveGame.get())
            return 0;
		return &m_SaveGame->m_Fortresses[0];
    }

    virtual std::string getGameDirectory() const;

    virtual Game_Data_Save* getGameData_SaveGame()
    {
        if (0 == m_SaveGame.get())
            return 0;
        return &m_SaveGame->m_Game_Data;
    }

    virtual uint16_t* getGameTurn()
    {
        if (0 == m_SaveGame.get())
            return 0;
        return &m_SaveGame->m_Game_Data.m_Current_Turn;
    }

    virtual Hero_stats* getList_Hero_stats(ePlayer playerNr)
    {
        if (0 == m_SaveGame.get())
            return 0;
        return m_SaveGame->m_List_Hero_stats[playerNr].a;
    }

    virtual Hero_Stats_Initializer* getList_Hero_Stats_Initializer()
    {
        MoMMagicDataSegment* pMagicDataSegment = getMagicDataSegment();
        if (0 == pMagicDataSegment)
            return 0;
        return pMagicDataSegment->m_Hero_Stats_Initializers;
    }

    virtual Item* getItems()
    {
        if (0 == m_SaveGame.get())
            return 0;
        return m_SaveGame->m_Items;
    }

    virtual Tower_Node_Lair* getLairs()
    {
        if (0 == m_SaveGame.get())
            return 0;
        return m_SaveGame->m_Arcanus_Towers;
    }

    virtual const char* getNameByOffset(DS_Offset offset)
    {
        char* namebuffer = (char*)getDataSegment();
        if (0 == namebuffer)
            return 0;
        // TODO: Check range and terminating zero
        return namebuffer + offset;
    }

    virtual Node_Attr* getNodeAttributes()
    {
        if (0 == m_SaveGame.get())
            return 0;
        return &m_SaveGame->m_Arcanus_Node_Attr[0];
    }

    virtual uint16_t* getNumber_of_Cities()
    {
        if (0 == m_SaveGame.get())
            return 0;
        return &m_SaveGame->m_Game_Data.m_Number_of_Cities;
    }

    virtual uint16_t* getNumber_of_Units()
    {
        if (0 == m_SaveGame.get())
            return 0;
        return &m_SaveGame->m_Game_Data.m_Number_of_Units;
    }

    virtual uint16_t* getNumber_of_Wizards()
    {
        if (0 == m_SaveGame.get())
            return 0;
        return &m_SaveGame->m_Game_Data.m_Number_of_Wizards;
    }

    virtual std::string getSources() const;

    virtual Spell_Data* getSpellData()
    {
        if (0 == m_SpelldatLbx.get())
            return 0;
        uint8_t* data = m_SpelldatLbx->getRecord(0);
        return (Spell_Data*)(data + 4);
    }

    virtual uint16_t* getTaxUnrestTable()
    {
        MoMDataSegment* pMoMDataSegment = getDataSegment();
        if (0 == pMoMDataSegment)
            return 0;
        return pMoMDataSegment->m_Tax_Unrest_Table;
    }

    virtual eTerrainBonusDeposit* getTerrain_Bonuses()
    {
        if (0 == m_SaveGame.get())
            return 0;
        return &m_SaveGame->m_Arcanus_Bonus_Row[0].m_Bonus_Deposit[0];
    }
    virtual Terrain_Changes* getTerrain_Changes()
    {
        if (0 == m_SaveGame.get())
            return 0;
        return &m_SaveGame->m_Arcanus_Terrain_Changes_Row[0].m_Terrain_Changes[0];
    }
    virtual uint8_t* getTerrain_Explored()
    {
        if (0 == m_SaveGame.get())
            return 0;
        return &m_SaveGame->m_Arcanus_Exploration_Row[0].m_Explored[0];
    }
    virtual int8_t* getTerrain_LandMassID()
    {
        if (0 == m_SaveGame.get())
            return 0;
        return &m_SaveGame->m_Arcanus_LandMassID_Row[0].m_LandMassID[0];
    }
    virtual Map_Movement* getTerrain_Movements()
    {
        if (0 == m_SaveGame.get())
            return 0;
        return &m_SaveGame->m_Arcanus_Movement;
    }
    virtual eTerrainType* getTerrain_Types()
    {
        if (0 == m_SaveGame.get())
            return 0;
        return &m_SaveGame->m_Arcanus_Map_Row[0].m_Tile[0];
    }

    virtual Unit* getUnits()
    {
        if (0 == m_SaveGame.get())
            return 0;
        return m_SaveGame->m_Unit;
    }

    virtual Unit_Type_Data* getUnit_Types()
    {
        MoMDataSegment* pMoMDataSegment = getDataSegment();
        if (0 == pMoMDataSegment)
            return 0;
        return &pMoMDataSegment->m_Hero_Types.Dwarf;
    }

    virtual int8_t* getUnrest_Table(eRace homeRace)
    {
        if (0 == m_TerrstatLbx.get())
            return 0;
        uint8_t* data = m_TerrstatLbx->getRecord(1);
        return (int8_t*)(data + homeRace * gMAX_RACES + 4);
    }

    virtual Wizard* getWizards()
    {
        if (0 == m_SaveGame.get())
            return 0;
        return m_SaveGame->m_Wizards;
    }

    virtual bool isOpen() const
    {
        // TODO
        return true;
    }

    void setPlayer(ePlayer playerNr)
    {
        m_playerNr = playerNr;
    }

//private:
    virtual MoMDataSegment* getDataSegment()
    {
        if (0 == m_WizardsExe.get())
            return 0;
        return (MoMDataSegment*)m_WizardsExe->getDataSegment();
    }

    virtual MoMMagicDataSegment* getMagicDataSegment()
    {
        if (0 == m_MagicExe.get())
            return 0;
        return (MoMMagicDataSegment*)m_MagicExe->getDataSegment();
    }

    virtual MoMExeMagic* getMagicExe()
    {
        return m_MagicExe.get();
    }

    virtual uint8_t* getMagicExeContents()
    {
        if (0 == m_MagicExe.get())
            return 0;
        return m_MagicExe->getExeContents();
    }

    virtual uint8_t* getMagicOverlay(size_t ovlNr);

    virtual SaveGame* getSaveGame()
    {
        if (0 == m_SaveGame.get())
            return 0;
        return m_SaveGame.get();
    }

    virtual MoMExeWizards* getWizardsExe()
    {
        return m_WizardsExe.get();
    }

    virtual uint8_t* getWizardsExeContents()
    {
        if (0 == m_WizardsExe.get())
            return 0;
        return m_WizardsExe->getExeContents();
    }

    virtual uint8_t* getWizardsOverlay(size_t ovlNr);

private:
    bool loadLbx(const std::string& filename, MoMLbxBase* lbxBase);
    bool saveLbx(const std::string& lbxTitle, MoMLbxBase* lbxBase, const std::string& filename);

private:
    std::auto_ptr<SaveGame> m_SaveGame;
    std::string m_filename_SaveGame;
    std::auto_ptr<MoMExeMagic> m_MagicExe;
    std::auto_ptr<MoMExeWizards> m_WizardsExe;
    std::string m_filename_MagicExe;
    std::string m_filename_WizardsExe;
    std::auto_ptr<MoMLbxBase> m_BuilddatLbx;
    std::auto_ptr<MoMLbxBase> m_SpelldatLbx;
    std::auto_ptr<MoMLbxBase> m_TerrstatLbx;
    std::string m_GameDirectory;
    ePlayer m_playerNr;
};

}
