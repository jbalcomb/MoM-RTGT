
#ifdef _WIN32
#include <windows.h>
#include <winerror.h>
#endif

#include <assert.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <signal.h>     // signal(SIGINT);
#include <sstream>
#include <stddef.h>
#include <string>

#include "MoMController.h"
#include "MoMGenerated.h"
#include "MoMGameMemory.h"
#include "MoMProcess.h"
#include "MoMGameSave.h"
#include "MoMutility.h"

using namespace MoM;

bool gHelp = false;
std::string gWindowTitle("DOSBox Status Window");
bool gRepopLairs = false;
bool gRepopMaxOut = false;
bool gAddHero = false;
int gHeroNr = -1;
bool gAllPlayers = false;
bool gApplyBuildingQueue = false;
bool gMonitor = false;
bool gValidate = false;
std::string gReadSAVEnGAM;
std::string gWriteSAVEnGAM;

void usage()
{
    std::cout << 
        "IGTconsole is an Interactive Game Tweaker for Master of Magic 1.31.\n"
        "When it is run it tries to connect to a MoM game in progress.\n"
        "With the options you can specify to make changes in the MoM game.\n"
        "\n"
        "Usage is:\n"
        "  C> IGTconsole [ /option[=value] ... ]\n"
        "\n"
        "NOTE: the options are case sensitive and spaces specified are mandatory.\n"
        "The possible option combinations are:\n"
        "/windowTitle=\"DOSBox Status Window\"  Specify this if your window title\n"
        "                                   deviates from the given title.\n"
        "/read=SAVEn.GAM [/write=SAVEm.GAM] Read from SAVEn.GAM instead of from memory\n"
        "                                   Afterward write to SAVEm.GAM (optionally)\n"
        "/repopLairs[=maxOut]               Repopulate all lairs\n"
        "                                   If 'maxOut' is specified, all lairs are\n"
        "                                   cranked up.\n"
        "/addHero=<heroNr> [/allPlayers]    Adds the hero <heroNr> to your fortress.\n"
        "                                   heroNr 0 is Brax, the Dwarf and 34 is Torin,\n"
        "                                   the Chosen.\n"
        "                                   If /allPlayers is specified, all players get\n"
        "                                   the hero.\n"
        "/applyBuildingQueue                Changes production of all your cities\n"
        "                                   in accordance with the Building Queue\n"
        "/monitor                           Keep monitoring and changing a game\n"
        "                                   in progress\n"
        "/validate                          Validates to see if the game is broken.\n"
        << std::endl;
}

void signalBreak(int)
{
    std::cout << "Break received: stop monitoring" << std::endl;
    gMonitor = false;
}

int main(int argc, char* argv[])
{
    assert(1 == sizeof(MoM::eSkill) && "Check enum-size (g++ flag -fshort-enums)");
    assert(0x04C8 == sizeof(MoM::Wizard) && "Check pack-struct (g++ flag -fpack-struct)");

    int exitCode = 0;

    if (argc <= 1)
    {
        gHelp = true;
    }

    for (int i = 1; i < argc; ++i)
    {
        if ('/' != *argv[i] && '-' != *argv[i])
        {
            gHelp = true;
            break;
        }

        std::string arg(argv[i] + 1);
        std::string value;

        std::string::size_type pos = arg.find("=");
        if (std::string::npos != pos)
        {
            value = arg.substr(pos + 1);
            arg = arg.substr(0, pos);
        }

        if ("windowTitle" == arg)
        {
            gWindowTitle = value;
            std::cout << "Looking for windowTitle='" << gWindowTitle << "'" << std::endl;
        }

        else if ("read" == arg)
        {
            if (value.empty())
            {
                gHelp = true;
                break;
            }
            gReadSAVEnGAM = value;
        }

        else if ("write" == arg)
        {
            if (gReadSAVEnGAM.empty() || value.empty())
            {
                gHelp = true;
            }
            gWriteSAVEnGAM = value;
        }

        else if ("repopLairs" == arg)
        {
            gRepopLairs = true;
            if (!value.empty())
            {
                if ("maxOut" == value)
                {
                    gRepopMaxOut = true;
                }
                else
                {
                    gHelp = true;
                }
            }
        }

        else if ("addHero" == arg)
        {
            gAddHero = true;
            if (value.empty())
            {
                gHelp = true;
            }
            else if (!(std::istringstream(value) >> gHeroNr))
            {
                gHelp = true;
            }
            else if (gHeroNr < 0 || gHeroNr >= gMAX_HERO_TYPES)
            {
                gHelp = true;
            }
        }

        else if ("allPlayers" == arg)
        {
            gAllPlayers = true;
        }

        else if ("applyBuildingQueue" == arg)
        {
            gApplyBuildingQueue = true;
        }

        else if ("monitor" == arg)
        {
            gMonitor = true;
        }

        else if ("validate" == arg)
        {
            gValidate = true;
        }

        else
        {
            gHelp = true;
        }
    }

    if (gHelp)
    {
        usage();
        return 1;
    }

    MoMGameMemory memGame;
    MoMGameSave saveGame;
    MoMGameBase* game = 0;
    bool ok = true;
    if (gReadSAVEnGAM.empty())
    {
        game = &memGame;
        std::cout << "Find MoM in memory" << std::endl;
        std::auto_ptr<MoMProcess> momProcess(new MoMProcess);
        ok = momProcess->findProcessAndData(gWindowTitle);
        if (ok)
        {
            ok = memGame.openGame(momProcess);
        }
    }
    else
    {
        game = &saveGame;
        std::cout << "Load MoM from '" << gReadSAVEnGAM <<"'" << std::endl;
        ok = saveGame.load(gReadSAVEnGAM.c_str());
    }

    if (ok && gAddHero)
    {
        eUnit_Type heroNr = (eUnit_Type)gHeroNr;
        ePlayer nrPlayers = (ePlayer)1;
        if (gAllPlayers)
        {
            nrPlayers = (ePlayer)game->getNrWizards();
        }
        for (ePlayer playerNr = (ePlayer)0; playerNr < nrPlayers; inc(playerNr))
        {
            std::cout << "Add hero " << heroNr << " to wizard " << playerNr << std::endl;
            // Ignore result, because summoning may not always work
            (void)MoMController::addHero(*game, playerNr, heroNr);
        }
    }

    if (ok && gApplyBuildingQueue)
    {
        std::cout << "Apply Building Queue to all your cities" << std::endl;
        ok = MoMController::applyBuildingQueue(*game, PLAYER_YOU);
    }

    if (ok && gRepopLairs)
    {
        std::cout << "Repopulate lairs" << std::endl;
        ok = MoMController::repopLairs(*game, gRepopMaxOut);
    }

    if (ok && gValidate)
    {
        std::cout << "Validate game" << std::endl;
        ok = game->validate();
    }

    if (ok && !gReadSAVEnGAM.empty() && !gWriteSAVEnGAM.empty())
    {
        std::cout << "Saving game to '" << gWriteSAVEnGAM << "'" << std::endl;
        ok = saveGame.save(gWriteSAVEnGAM.c_str());
    }

    if (/*ok &&*/ gReadSAVEnGAM.empty())
    {
        std::cout << "Commit changes to memory" << std::endl;
        ok = memGame.commitChanges();
    }

    if (gMonitor)
    {
        // Handle Ctrl+C as an exit
        signal(SIGINT, signalBreak);
        signal(SIGTERM, signalBreak);
    }
    int turn = -1;
    eGameState gameState = eGameState();
    while (gMonitor)
    {
#ifdef _WIN32
        Sleep(1000);
#else
        sleep(1);
#endif

        if (!memGame.readData())
        {
            break;
        }

        if (*memGame.getGameTurn() == turn && *memGame.getGameState() == gameState)
        {
            continue;
        }

        turn = *memGame.getGameTurn();
        gameState = *memGame.getGameState();
        std::cout << "Turn=" << *memGame.getGameTurn() << " State=" << *memGame.getGameState() << std::endl;

        // Only make changes in the STATE Next_turn_seq
        // Specifically NOT when the computer is making changes!
        //if (::STATE_Next_turn_seq != turn)
        //{
        //    continue;
        //}

        if (ok && gApplyBuildingQueue)
        {
            std::cout << "Apply Building Queue to all your cities" << std::endl;
            ok = MoMController::applyBuildingQueue(*game, PLAYER_YOU);
        }

        if (ok && gValidate)
        {
            std::cout << "Validate game" << std::endl;
            ok = game->validate();
        }

        if (ok)
        {
            ok = memGame.commitChanges();
        }
    }

    //MoMGameMemory lMoMGameMemory;
    //if (lMoMGameMemory.findAndOpenGame())
    //{
    //    WizardsExe_Unit* unitData = lMoMGameMemory.getUnit_Data(Necromancer);
    //    if (0 != unitData)
    //    {
    //        unitData->m_MoveHalves = 30;
    //        unitData->m_Movement_Flags.s.Merging = true;
    //        unitData->m_Ability_Flags.s.Non_Corporeal = true;
    //        unitData->m_Special_attack_Flags.s.Armor_Piercing = true;
    //    }

    //    for (ePlayer playerNr = ePlayer(); playerNr < 5; inc(playerNr))
    //    {
    //        eUnit_Type heroes[] = { ::Necromancer };
    //        for (int i = 0; i < ARRAYSIZE(heroes); ++i)
    //        {
    //            eUnit_Type heroNr = heroes[i];
    //            bool ok = MoMController::addHero(lMoMGameMemory, playerNr, heroNr);
    //            if (ok)
    //            {
    //                std::cout << "Player " << playerNr << " summoned " << heroNr << std::endl;
    //            }
    //            else
    //            {
    //                std::cout << "Player " << playerNr << " failed to summon " << heroNr << std::endl;
    //            }
    //        }
    //    }

    //    bool repop = true;
    //    if (repop)
    //    {
    //        MoMController::repopLairs(lMoMGameMemory, true);
    //    }

    //    bool monitor = false;
    //    int counter = 0;
    //    while (monitor)
    //    {
    //        Sleep(5000);
    //        std::cout << "Monitoring " << counter++ << std::endl;
    //        if (!lMoMGameMemory.readData())
    //        {
    //            monitor = false;
    //        }
    //        if (!lMoMGameMemory.validate())
    //        {
    //            monitor = false;
    //        }
    //    }

    //    lMoMGameMemory.commitChanges();
    //}

    //MoMGameSave lMoMGameSave;
    //if (argc > 1 && lMoMGameSave.load(argv[1]))
    //{
    //    std::ofstream ofs("SAVEGAME.log");
    //    ofs << lMoMGameSave;
    //    ofs.close();

    //    if (!lMoMGameSave.validate())
    //    {
    //        std::cerr << "File '" << argv[1] << "' is not valid." << std::endl;
    //    }

    //int loadWizardsExe(const char* filenameWizardsExe);
    //exitCode = loadWizardsExe("WIZARDS.EXE");

    if (!ok)
    {
        exitCode = 1;
    }

    return exitCode;
}
