#include <cassert>
#include <iostream>

#include "MoMGameBase.h"
#include "MoMProcess.h"
#include "MoMUtility.h"

#include "MoMHookManager.h"

namespace MoM {

MoMHookManager::MoMHookManager(MoMGameBase* game) :
    m_game(game)
{
    m_process = m_game->getMoMProcess();
}

//
// COPIED FROM: http://www.realmsbeyond.net/forums/showpost.php?p=283483&postcount=59
//
//I've changed the first section of the Unit_strategy_exe() subroutine.
//
//Original code in VANILLA:
//Code:
//; Start of Unit_strategy_exe() routine
//; WIZARDS.EXE:889E4
//
//8B C6             mov     ax, si_casting_battle_unitID
//BA 6E 00          mov     dx, 6Eh ; 'n'
//F7 EA             imul    dx
//C4 1E 2A 92       les     bx, addr_Battle_unit
//03 D8             add     bx, ax
//26 8A 47 43       mov     al, es:[bx+43h]
//98                cbw
//BA 6E 00          mov     dx, 6Eh ; 'n'
//F7 EA             imul    dx
//C4 1E 2A 92       les     bx, addr_Battle_unit
//03 D8             add     bx, ax
//26 8B 7F 44       mov     di, es:[bx+struc_Battle_Unit.field_xPos]
//8B C6             mov     ax, si_casting_battle_unitID
//BA 6E 00          mov     dx, 6Eh ; 'n'
//F7 EA             imul    dx
//C4 1E 2A 92       les     bx, addr_Battle_unit
//03 D8             add     bx, ax
//26 8A 47 43       mov     al, es:[bx+struc_Battle_Unit.field_target_battle_unitID_??]
//98                cbw
//BA 6E 00          mov     dx, 6Eh ; 'n'
//F7 EA             imul    dx
//C4 1E 2A 92       les     bx, addr_Battle_unit
//03 D8             add     bx, ax
//            loc_9251A:
//26 8B 47 46       mov     ax, es:[bx+struc_Battle_Unit.field_yPos]
//89 46 0A          mov     [bp+target_Y], ax
//
//
//Replacing the orange code with the green code.
//Code:
//; Start of Unit_strategy_exe() routine
//; WIZARDS.EXE:889E4

//55              push    bp     ; auto combat
//8B EC           mov     bp, sp
//83 EC 06        sub     sp, 6
//56              push    si_casting_battle_unitID
//57              push    di
//8B 76 06        mov     si_casting_battle_unitID, [bp+casting_battleUnitID]

//8B C6           mov     ax, si_casting_battle_unitID
//BA 6E 00        mov     dx, 6Eh ; 'n'
//F7 EA           imul    dx
//C4 1E 2A 92     les     bx, addr_Battle_unit
//03 D8           add     bx, ax
//26 8A 47 43     mov     al, es:[bx+43h]
//98              cbw
//BA 6E 00        mov     dx, 6Eh ; 'n'
//F7 EA           imul    dx
//C4 1E 2A 92     les     bx, addr_Battle_unit
//03 D8           add     bx, ax
//26 8B 7F 44     mov     di, es:[bx+struc_Battle_Unit.field_xPos]
//26 8B 47 46     mov     ax, es:[bx+struc_Battle_Unit.field_yPos]
//89 7E 0A        mov     [bp+target_Y], di
//89 46 08        mov    [bp+target_X], ax
//
//50              push    ax
//A0 97 92        mov    al, [w_kyrub_dseg_9297]
//08 C0           or    al, al
//74 18           jz    loc_no_external_AI:
//B0 01           mov    al, 1
//A2 96 92        mov    [w_kyrub_dseg_9296], al
//loc_wait_external_AI:
//A0 96 92        mov    al, [w_kyrub_dseg_9296]
//08 C0           or    al, al
//75 F9           jnz    loc_wait_external_AI
//A8 00 89        mov    ax, [w_kyrub_dseg_8900]
//89 46 08        mov    [bp+target_X], ax
//A8 02 89        mov    ax, [w_kyrub_dseg_8902]
//89 46 0A        mov    [bp+target_Y], ax
//loc_no_external_AI:
//58              pop    ax
//
//90 90 90 90 90 90
//
//
//Notice the flag in dseg:9297. By default it is 0, meaning the external ai is disabled. It's purpose is choose whether to use the original ai or wait for the external program. My program changes dseg:9297 flag to 1 when it executes. When dseg:9297 = 1, then MoM waits until dseg:9296 is reset to zero. My program saves x- and y-coordinates to dseg:8900 and dseg:8902.
//
//Code:
//Replace opcodes in 0x889E4
//558BEC83EC0656578B76068B7E080BFF754B837E0A0075458BC6BA6E00F7EAC41E2A9203D8268A474398BA6E00F7EAC41E2A9203D8268B7F448BC6BA6E00F7EAC41E2A9203D8268A474398BA6E00F7EAC41E2A9203D8268B474689460A
//
//with
//558BEC83EC0656578B76068BC6BA6E00F7EAC41E2A9203D8268A474398BA6E00F7EAC41E2A9203D8268B7F44268B4746897E0A89460850A0979208C07418B001A29692A0969208C075F9A80089894608A8028989460A58909090909090
//

bool MoMHookManager::insertHook()
{
    if(0 == m_game)
        return false;

    const size_t hook_exeOffset = 0x889E4;
    const char hook_unit_strategy_exe_str[] =
            "558BEC83EC0656578B76068BC6BA6E00F7EAC41E2A9203D8268A474398BA6E00"
            "F7EAC41E2A9203D8268B7F44268B4746897E0A89460850A0979208C07418B001"
            "A29692A0969208C075F9A80089894608A8028989460A58909090909090";

    bool ok = true;
    uint8_t* codeBase = m_game->getWizardsExeContents();
    if (0 != codeBase)
    {
        std::cout << "failed to commit code changes" << std::endl;
        ok = false;
    }

    uint8_t hook_unit_strategy_exe_code[ARRAYSIZE(hook_unit_strategy_exe_str) / 2] = "";
    if (ok)
    {
        for (size_t i = 0; ok && (i < ARRAYSIZE(hook_unit_strategy_exe_code)); ++i)
        {
            const char* s = &hook_unit_strategy_exe_str[2 * i];
            unsigned hexbyte = 0;
            ok = (1 == sscanf(s, "02X", &hexbyte));
            hook_unit_strategy_exe_code[i] = static_cast<uint8_t>(hexbyte);
        }
        assert(ok && "Failed to copy hex string for Unit_strategy_exe() into byte array");
    }

    if (ok)
    {
        uint8_t* codeHook = codeBase + hook_exeOffset;
        ok = m_game->commitData(codeHook, hook_unit_strategy_exe_code, sizeof(hook_unit_strategy_exe_code));
        if (!ok)
        {
            std::cout << "failed to commit hook_unit_strategy_exe_code change" << std::endl;
        }
    }

    return ok;
}

bool MoMHookManager::raiseHook()
{
    if ((0 == m_process) || (0 == m_game) || (0 == m_game->getDataSegment()))
        return false;

    // Set dseg:9297 to 1
    uint8_t* ptrDseg9297 = 1 + (uint8_t*)&m_game->getDataSegment()->m_WizardsExe_Pointers.w_kyrub_dseg_9296;
    *ptrDseg9297 = 1;
    bool ok = m_process->writeData(ptrDseg9297, 1);
    if (!ok)
    {
        std::cout << "failed to commit dseg:9297 set" << std::endl;
    }
    return ok;
}

bool MoMHookManager::retractHook()
{
    if ((0 == m_process) || (0 == m_game) || (0 == m_game->getDataSegment()))
        return false;

    // Set dseg:9297 to 0
    uint8_t* ptrDseg9297 = 1 + (uint8_t*)&m_game->getDataSegment()->m_WizardsExe_Pointers.w_kyrub_dseg_9296;
    *ptrDseg9297 = 0;
    bool ok = m_process->writeData(ptrDseg9297, 1);
    if (!ok)
    {
        std::cout << "failed to commit dseg:9297 reset" << std::endl;
    }
    return ok;
}

bool MoMHookManager::waitForHook(double timeout)
{
    if ((0 == m_process) || (0 == m_game) || (0 == m_game->getDataSegment()))
        return false;

    const double sleepTime = 0.001;

    // Wait till dseg:9297 is 0
    uint8_t* ptrDseg9297 = 1 + (uint8_t*)&m_game->getDataSegment()->m_WizardsExe_Pointers.w_kyrub_dseg_9296;
    bool ok = true;
    bool hookTriggered = false;
    int nrTries = (int)(timeout / sleepTime + 0.5);
    for (int tryNr = 0; ok && !hookTriggered && (tryNr < nrTries); ++tryNr)
    {
        ok = m_process->readData(ptrDseg9297, 1);
        if (!ok)
        {
            std::cout << "failed to read from dseg:9297" << std::endl;
        }
        else
        {
            hookTriggered = (0 == *ptrDseg9297);
        }
        m_process->sleepSec(0.001);
    }
    return hookTriggered;
}

bool MoMHookManager::releaseHook()
{
    if ((0 == m_process) || (0 == m_game) || (0 == m_game->getDataSegment()))
        return false;

    // Set dseg:9296 to 0
    uint8_t* ptrDseg9296 = (uint8_t*)&m_game->getDataSegment()->m_WizardsExe_Pointers.w_kyrub_dseg_9296;
    *ptrDseg9296 = 0;
    bool ok = m_process->writeData(ptrDseg9296, 1);
    if (!ok)
    {
        std::cout << "failed to commit dseg:9296 reset" << std::endl;
    }
    return ok;
}

}
