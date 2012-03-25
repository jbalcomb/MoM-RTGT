// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2012-03-12
// ---------------------------------------------------------------------------

// OS specific

// Standard C++ Library

// Library
#include <MoMController.h>
#include <MoMGameCustom.h>
#include <MoMGenerated.h>
#include <MoMLbxBase.h>
#include <MoMGameMemory.h>
#include <MoMProcess.h>
#include <MoMGameSave.h>
#include <MoMutility.h>
#include <QMoMCommon.h>
#include <QMoMResources.h>

// Local
#include "dialogbuildingqueues.h"
#include "dialogcalculatoraddress.h"
#include "dialogselectinitialspells.h"
#include "mainwindow.h"

// Module header
#include "dialogtools.h"
#include "ui_dialogtools.h"

DialogTools::DialogTools(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTools)
{
    ui->setupUi(this);
    setFont(MoM::QMoMResources::g_Font);
}

DialogTools::~DialogTools()
{
    delete ui;
}

QMoMGamePtr DialogTools::getGame()
{
	QMoMGamePtr game;
	MainWindow* controller = MainWindow::getInstance();
    if (0 != controller)
	{
	    game = controller->getGame();
	}
    return game;
}

void DialogTools::on_pushButton_Validate_clicked()
{
    MainWindow* controller = MainWindow::getInstance();
	QMoMGamePtr game = getGame();
    if (game.isNull())
    {
        (void)QMessageBox::warning(this, 
            tr("Repop Lairs"),
            tr("There is no game to operate on"));
        return;
    }

    bool ok = controller->refreshMemory();

    if (ok)
    {
        ok = game->validate();
        if (!ok)
        {
            (void)QMessageBox::warning(this,
                tr("Validate"),
                tr("The game failed validation"));
        }
    }

    if (!ok)
    {
        statusBar()->showMessage(tr("Game failed validation"));
    }
    else
    {
        statusBar()->showMessage(tr("Game checks out Ok"));
    }

    update();
}

void DialogTools::on_pushButton_ApplyBuildQueues_clicked()
{
    DialogBuildingQueues* dialog = new DialogBuildingQueues(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void DialogTools::on_pushButton_Calculator_clicked()
{
    DialogCalculatorAddress* dialog = new DialogCalculatorAddress(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void DialogTools::on_pushButton_RepopLairs_clicked()
{
    MainWindow* controller = MainWindow::getInstance();
	QMoMGamePtr game = getGame();
    if (game.isNull())
    {
        (void)QMessageBox::warning(this, 
            tr("Repop Lairs"),
            tr("There is no game to operate on"));
        return;
    }

    bool ok = controller->refreshMemory();

    if (ok)
    {
		MoM::MoMController momController;
        ok = momController.repopLairs(*game, 
            ui->checkBox_RepopMaxOut->isChecked());
        if (!ok)
        {
            (void)QMessageBox::warning(this, 
                tr("Repop Lairs"),
				tr("Failed to repop the lairs: %0").arg(momController.errorString().c_str()));
        }
    }

    if (ok)
    {
        ok = controller->commitMemory();
    }

    if (!ok)
    {
        statusBar()->showMessage(tr("Failed to repop Lairs"));
    }
    else
    {
        statusBar()->showMessage(tr("Lairs have been repopulated"));
    }

    update();
}

void DialogTools::on_pushButton_CatnipMod_clicked()
{
    MainWindow* controller = MainWindow::getInstance();
	QMoMGamePtr game = getGame();
    if (game.isNull())
    {
        (void)QMessageBox::warning(this,
            tr("Catnip mod"),
            tr("There is no game to operate on"));
        return;
    }

    bool ok = controller->refreshMemory();

    if (ok)
    {
        // Update set_hero_slots() based on hero_type
        // Target is that a hero_type of 0-3 works as before (Fig, Bow, FigWiz, Wiz) -> (1-5-6, 2-5-6, 3-5-6, 4-6-6)
        // But that otherwise the hero_type can be of the form 0x0RQP, where P, Q, R are the 3 slots-types (1-6)
        // This means that a hero_type of 0x0652 is equivalent to a hero_type of 1 (Bow), yielding Bow-Armor-Ring

        static uint8_t new_set_hero_slots[] =
        {
//                8                      ; int __cdecl __far set_hero_slot_types(int unitType, int hero_slot_types)
//                9 0000                     set_hero_slot_types      proc far       ; CODE XREF: j_set_hero_slot_types
//               10
//               11       =0006              unitType               = word ptr  6
//               12       =0008              hero_slot_types        = word ptr  8
//               13
//               14       =01AB              offset_hero_type       = 01ABh
//               15       =SI                si_hero_slot_types     = si
//               16       =CX                cx_unitType            = cx
//               17
//               18                      ; ovr130:0000
          0x55,                         // 0000  push   bp
          0x8B,  0xEC,                  // 0001  mov    bp,    sp
          0x56,                         // 0003  push   si_hero_slot_types
          0x8B,  0x4E, 0x06,            // 0004  mov    cx_unitType, [bp+unitType]
          0x8B,  0x76, 0x08,            // 0007  mov    si_hero_slot_types,    [bp+hero_slot_types]
          0x8B,  0xC1,                  // 000A  mov    ax,    cx_unitType
          0xBA,  0x24, 0x00,            // 000C  mov    dx,    24h
          0xF7,  0xEA,                  // 000F  imul   dx
          0x8B,  0xD8,                  // 0011  mov    bx,    ax
//               28
//               29                      ; ovr130:0013
          0x8A,  0x87, 0xAB, 0x01,      // 0013  mov   al, offset_hero_type[bx]   ;    AX = 0-3 as before, or 6 + P + 6 * (Q + 6 * R), where P,Q,R are the slot-types - 1
          0x32,  0xE4,                  // 0017  xor   ah, ah
          0x3D,  0x06, 0x00,            // 0019  cmp   ax, 6
          0x7D,  0x16,                  // 001C  jge   new_method
//               35
          0x40,                         // 001E  inc   ax
          0x89,  0x04,                  // 001F  mov   [si], ax         ; Set slot1 to 1-4 (Sword, Bow, Sword/Staff, Staff)
          0xBA,  0x05, 0x00,            // 0021  mov   dx, 5
          0x89,  0x54, 0x02,            // 0024  mov   [si+2], dx       ; Set slot2 to 5 (Armor)
          0x42,                         // 0027  inc   dx
          0x89,  0x54, 0x04,            // 0028  mov   [si+4], dx       ; Set slot3 to 6 (Ring)
          0x3C,  0x04,                  // 002B  cmp   al, 4
          0x75,  0x21,                  // 002D  jnz   done
          0x89,  0x54, 0x02,            // 002F  mov   [si+2], dx       ; If AX is 4 (Wizard), overrule slot2 to 6 (Ring)
          0xEB,  0x1C,                  // 0032  jmp   short done
//               46
//               47 0034                 new_method:
          0xB1,  0x06,                  // 0034  mov   cl, 6
          0x2A,  0xC1,                  // 0036  sub   al, cl           ; AX = P + 6 * (Q + 6 * R), where P,Q,R are the slot-types - 1
          0x99,                         // 0038  cwd
          0xF6,  0xF9,                  // 0039  idiv  cl               ; AH = P, AL = Q + 6 * R
          0x8A,  0xD4,                  // 003B  mov   dl, ah
          0x42,                         // 003D  inc   dx
          0x89,  0x14,                  // 003E  mov   [si], dx         ; Set slot 1 to <P>
          0x32,  0xE4,                  // 0040  xor   ah, ah
          0xF6,  0xF9,                  // 0042  idiv  cl               ; AH = Q, AL = R
          0x8A,  0xD4,                  // 0044  mov   dl, ah
          0x42,                         // 0046  inc   dx
          0x89,  0x54, 0x02,            // 0047  mov   [si+2], dx       ; Set slot 2 to <Q>
          0x8A,  0xD0,                  // 004A  mov   dl, al
          0x42,                         // 004C  inc   dx
          0x89,  0x54, 0x04,            // 004D  mov   [si+4], dx       ; Set slot 3 to <R>
//               63
//               64 0050                 done:
          0x5E,                         // 0050  pop   si
          0x5D,                         // 0051  pop   bp
          0xCB,                         // 0052  retf
//               68
//               69                      ; nops
//               70 0053                         endp

                // ...          nops
                //              endp
                // ovr130:0071
        };

        uint8_t* code = game->getWizardsOverlay(130);

        if (0 != code)
        {
            memcpy(code, new_set_hero_slots, sizeof(new_set_hero_slots));
            memset(code + sizeof(new_set_hero_slots), '\0', 0x0071 - sizeof(new_set_hero_slots));

            ok = game->commitData(code, code, 0x0071);
        }
    }

    if (ok)
    {
        // TODO: Large Shield is +3 or +4

        uint16_t spareNameOffset = 0xEA60;   // Spare room in Stack Segment
        uint16_t size = 0;
        char* spareNameBuffer = const_cast<char*>(game->getNameByOffset(spareNameOffset));
        char* spareNames = spareNameBuffer;

        uint16_t offsetClerics = spareNameOffset;
        size = 1 + sprintf(spareNames, "%s", "Clerics");
        spareNameOffset += size;
        spareNames += size;
        uint16_t offsetEvokers = spareNameOffset;
        size += 1 + sprintf(spareNames, "%s", "Evokers");
        spareNameOffset += size;
        spareNames += size;
        uint16_t offsetSorcerers = spareNameOffset;
        size += 1 + sprintf(spareNames, "%s", "Sorcerers");
        spareNameOffset += size;
        spareNames += size;
        uint16_t offsetEnchanters = spareNameOffset;
        size += 1 + sprintf(spareNames, "%s", "Enchanters");
        spareNameOffset += size;
        spareNames += size;
        uint16_t offsetSummoners = spareNameOffset;
        size += 1 + sprintf(spareNames, "%s", "Summoners");
        spareNameOffset += size;
        spareNames += size;
        uint16_t offsetWizards = spareNameOffset;
        size += 1 + sprintf(spareNames, "%s", "Wizards");
        spareNameOffset += size;
        spareNames += size;

        ok = game->commitData(spareNameBuffer, spareNameBuffer, (size_t)(spareNames - spareNameBuffer));

        for (int unitTypeNr = 35; unitTypeNr <= 0x9A; ++unitTypeNr)
        {
            MoM::eUnit_Type unitType = static_cast<MoM::eUnit_Type>(unitTypeNr);
            MoM::Unit_Type_Data* data = game->getUnit_Type_Data(unitType);
            if (0 == data)
            {
                ok = false;
                break;
            }
            QString unitName = toQStr(unitType);

            bool isFootUnit = (QRegExp("Spearmen").indexIn(unitName)
                    || QRegExp("Swordsmen").indexIn(unitName)
                    || QRegExp("Bowmen").indexIn(unitName)
                    || QRegExp("Swordsmen").indexIn(unitName)
                    || QRegExp("Halberdiers").indexIn(unitName)
                    || QRegExp("Pikemen").indexIn(unitName)
                    || QRegExp("Berserkers").indexIn(unitName)
                    || QRegExp("Minotaurs").indexIn(unitName)
                    || QRegExp("Nightblades").indexIn(unitName)
                    || QRegExp("Hammerhands").indexIn(unitName)
                    || QRegExp("Rangers").indexIn(unitName)
                    || QRegExp("War_Trolls").indexIn(unitName)
                    );

//            bool isCavalry = (QRegExp("Cavalry").indexIn(unitName)
//                    || QRegExp("Horsebowmen").indexIn(unitName)
//                    || QRegExp("Centaurs").indexIn(unitName)
//                    || QRegExp("Nightmares").indexIn(unitName)
//                    || QRegExp("Wolf_Riders").indexIn(unitName)
//                    || QRegExp("Elven_Lords").indexIn(unitName)
//                    || QRegExp("Pegasai").indexIn(unitName)
//                    || QRegExp("Paladins").indexIn(unitName)
//                    || QRegExp("Stag_Beetle").indexIn(unitName)
//                    || QRegExp("Dragon_Turtle").indexIn(unitName)
//                    || QRegExp("Griffins").indexIn(unitName)
//                    || QRegExp("Wyvern_Riders").indexIn(unitName)
//                    || QRegExp("War_Mammoths").indexIn(unitName)
//                    );

            //Clerics are a new unit type which is available to high men, beastmen and halflings.
            //They replace priests and shaman respectively.
            bool isCleric = ((MoM::UNITTYPE_Beastmen_Priests == unitType) || (MoM::UNITTYPE_Halfling_Shaman == unitType) || (MoM::UNITTYPE_High_Men_Priests == unitType));

            if (isCleric)
            {
            }

            //All foot units get 2 moves and 2 hearts, cavalry gets 4 moves and 5 hearts, catapults stay at 1 move and 10 hearts.
            if (isFootUnit)
            {
                data->m_MoveHalves = 4;
                data->m_Hitpoints = 2;
            }
            else if (-1 != QRegExp("Cavalry").indexIn(unitName))
            {
                data->m_MoveHalves = 8;
                data->m_Hitpoints = 5;
            }

            if (-1 != QRegExp("Spearmen").indexIn(unitName))
            {
                //Spearmen: Cost 20, 7 fig, 2 off, 3 def, negate first strike
                data->m_Cost = 20;
                data->m_Nr_Figures = 7;
                data->m_Melee = 2;
                data->m_Defense = 3;
                data->m_Ability_Flags.s.Negate_First_Strike = true;
            }
            else if (-1 != QRegExp("Swordsmen").indexIn(unitName))
            {
                //Swordsmen: Cost 30, 7 fig, 4 off, 2 def, large shield (hacked to give +3 or possibly +4 ranged def)
                data->m_Cost = 30;
                data->m_Nr_Figures = 7;
                data->m_Melee = 4;
                data->m_Defense = 2;
                data->m_Ability_Flags.s.Large_Shield = true;
            }
            else if (-1 != QRegExp("Bowmen").indexIn(unitName))
            {
                //Bowmen: Cost 40, 6 fig, 1 off, 1 def, 2 rng, 6 ammo
                data->m_Cost = 40;
                data->m_Nr_Figures = 6;
                data->m_Melee = 1;
                data->m_Defense = 1;
                data->m_Ranged = 2;
                data->m_Ranged_Shots = 6;
            }
            else if (-1 != QRegExp("Halberdiers").indexIn(unitName))
            {
                //Halberdiers: Cost 50, 6 fig, 5 off, 3 def, armour piercing
                data->m_Cost = 50;
                data->m_Nr_Figures = 6;
                data->m_Melee = 5;
                data->m_Defense = 3;
                data->m_Attack_Flags.s.Armor_Piercing = true;
            }
            else if (-1 != QRegExp("Cavalry").indexIn(unitName))
            {
                //Cavalry: Cost 60, 4 fig, 7 off, 2 def, first strike
                data->m_Cost = 60;
                data->m_Nr_Figures = 4;
                data->m_Melee = 7;
                data->m_Defense = 2;
                data->m_Ranged = 2;
                data->m_Attack_Flags.s.First_Strike = true;
            }
            else if (isCleric)
            {
                //Clerics: Cost 100, 3 fig, 6 off, 5 def, healing
                data->m_PtrName = offsetClerics;
                data->m_Cost = 100;
                data->m_Nr_Figures = 3;
                data->m_Melee = 6;
                data->m_Defense = 5;
                data->m_Ability_Flags.s.Healer = false;
                data->m_Ability_Flags.s.Purify = false;
                data->m_Attribute_Flags.s.Healing_Spell = true;
            }
            else if (-1 != QRegExp("Shaman").indexIn(unitName))
            {
                //Shaman: Cost 80, 3 fig, 2 off, 4 def, 3 rng, 4 ammo, purify, healer
                data->m_Cost = 80;
                data->m_Nr_Figures = 3;
                data->m_Melee = 2;
                data->m_Defense = 4;
                data->m_Ranged = 3;
                data->m_Ranged_Shots = 4;
                data->m_Ability_Flags.s.Purify = true;
                data->m_Ability_Flags.s.Healer = true;
                data->m_Attribute_Flags.s.Healing_Spell = false;
            }
            else if (-1 != QRegExp("Priests").indexIn(unitName))
            {
                //Priests: Cost 120, 3 fig, 3 off, 4 def, 4 rng, 4 ammo, magic immunity
                data->m_Cost = 120;
                data->m_Nr_Figures = 3;
                data->m_Melee = 3;
                data->m_Defense = 4;
                data->m_Ranged = 4;
                data->m_Ranged_Shots = 4;
                data->m_Ability_Flags.s.Purify = false;
                data->m_Ability_Flags.s.Healer = false;
                data->m_Attribute_Flags.s.Healing_Spell = false;
                data->m_Immunity_Flags.s.Magic_Immunity = true;
            }
            else if (-1 != QRegExp("Magicians").indexIn(unitName))
            {
                //Magicians: stats (and name) vary from race to race

                // 3 figures (default is 4)
                data->m_Nr_Figures = 3;
                // Fire Ball Spell is no longer a "given"
                data->m_Attribute_Flags.s.Fire_Ball_Spell = false;
                // Default Ranged strength is 5 for Magicians and 7 for Warlocks
                // Default Ranged Shots is 4

                switch (unitType)
                {
                case MoM::UNITTYPE_Beastmen_Magicians:
                    //        Beastmen Evokers
                    //        Fireball, strength 5 ranged attack, 6 ammo
                    data->m_PtrName = offsetEvokers;
                    data->m_Attribute_Flags.s.Fire_Ball_Spell = true;
                    data->m_Ranged = 5;
                    data->m_Ranged_Shots = 6;
                    break;

                case MoM::UNITTYPE_Draconian_Magicians:
                    //        Draconian Sorcerers
                    //        Caster 40, no ranged attack, fire breath and decent melee
                    data->m_PtrName = offsetSorcerers;
                    data->m_Attribute_Flags.s.Caster_40_MP = true;
                    data->m_Race_Code = MoM::RACE_Chaos;            // Has to be a color (not arcane) to make Caster_40_MP work
                    data->m_Attribute_Flags.s.Standard = false;     // Do not display the color-prefix for the name
                    data->m_Ranged_Type = MoM::RANGED_None;
                    data->m_Ranged = 0;
                    data->m_Ranged_Shots = 0;
                    break;

                case MoM::UNITTYPE_Dark_Elf_Warlocks:
                    // No changes
                    break;

                case MoM::UNITTYPE_High_Elf_Magicians:
                    //        High Elf Enchanters
                    //        Caster 20, weak ranged attack and good melee
                    data->m_PtrName = offsetEnchanters;
                    data->m_Attribute_Flags.s.Caster_20_MP = true;
                    data->m_Race_Code = MoM::RACE_Nature;           // Has to be a color (not arcane) to make Caster_40_MP work
                    data->m_Attribute_Flags.s.Standard = false;     // Do not display the color-prefix for the name
                    data->m_Melee = 2;
                    data->m_Ranged = 3;
                    break;

                case MoM::UNITTYPE_High_Men_Magicians:
                    //        High Men Magicians
                    //        Strong ranged attack, 4 figures (others are 3)
                    // data->m_PtrName = offsetMagicians;
                    data->m_Nr_Figures = 4;
                    data->m_Ranged = 7;
                    break;

                case MoM::UNITTYPE_Nomad_Magicians:
                    data->m_PtrName = offsetWizards;
                    data->m_Attribute_Flags.s.Web_Spell = true;
                    break;

                case MoM::UNITTYPE_Orc_Magicians:
                    //        Orc Summoners
                    //        Summon Demon, ranged attack
                    data->m_PtrName = offsetSummoners;
                    data->m_Attribute_Flags.s.Summon_Demons_1 = true;
                    break;

                default:
                    break;
                }
            }
            else if (-1 != QRegExp("Catapult").indexIn(unitName))
            {
                //Catapult: Cost 40, 1 fig, 0 off, 1 def, 8 rng, 10 ammo, long range, wall crusher, large shield
                data->m_Cost = 40;
                data->m_Nr_Figures = 1;
                data->m_Melee = 0;
                data->m_Defense = 1;
                data->m_Ranged = 8;
                data->m_Ranged_Shots = 10;
                data->m_Ability_Flags.s.Long_Range = true;
                data->m_Ability_Flags.s.Wall_Crusher = true;
                data->m_Ability_Flags.s.Large_Shield = true;
            }
        }
    }

    if (ok)
    {
        ok = controller->commitMemory();
    }

    if (!ok)
    {
        statusBar()->showMessage(tr("Failed to apply Catnip mod"));
    }
    else
    {
        statusBar()->showMessage(tr("Catnip mod applied"));
    }

    controller->update();
}

/*
bool replaceUnitGraphics(MoM::eUnit_Type unitType, const std::string& unitFilename, const std::string& figuresFilename)
{
    std::string gameDirectory = m_game->getGameDirectory();

    // Load FONTS.LBX (TODO: needs centralization)
    QVector<QRgb> colorTable(256);
    std::string fontsLbxFile = gameDirectory + "/" + "FONTS.LBX";
    MoM::MoMLbxBase fontsLbx;
    bool ok = fontsLbx.load(fontsLbxFile);
    if (ok)
    {
        const uint8_t* dataPalette = fontsLbx.getRecord(2);
        MoM::convertLbxToPalette(dataPalette, colorTable);
    }

    // Adjust color table for proper color matching
    colorTable.resize(244);
    colorTable[0] = qRgb(255, 0, 255);  // Treat MAGENTA RGB(255, 0, 255) as TRANSPARENT!
    colorTable[232] = qRgb(0, 255, 0);    // Treat GREEN RGB(0, 255, 0) as SHADOW (232 or 239??)

    char buf[256];

    sprintf(buf, "UNITS%d.LBX", 1 + (int)unitType / 120);
    std::string unitsLbxFile = gameDirectory + "/" + buf;

    int figuresFileNr = 1 + (int)unitType * 8 / 120;
    if (figuresFileNr < 10)
    {
        sprintf(buf, "FIGURES%d.LBX", figuresFileNr);
    }
    else
    {
        sprintf(buf, "FIGURE%d.LBX", figuresFileNr);
    }
    std::string figuresLbxFile = gameDirectory + "/" + buf;

    // Load UNITSX.LBX
    MoM::MoMLbxBase unitsLbx;
    if (ok)
    {
        ok = unitsLbx.load(unitsLbxFile);
    }

    // Load FIGUREXX.LBX
    MoM::MoMLbxBase figuresLbx;
    if (ok)
    {
        ok = figuresLbx.load(figuresLbxFile);
    }

    // Replace UNITS2/0 by Lucern/FIGURES4_077_001
    // Load unit bitmap
    QImage image;
    if (ok)
    {
        ok = image.load(unitFilename.c_str());
    }
    if (ok)
    {
        image = image.convertToFormat(QImage::Format_Indexed8, colorTable, Qt::AutoColor);
    }
    std::vector<uint8_t> dataBuffer;
    if (ok)
    {
        ok = MoM::convertImageToLbx(image, dataBuffer, "LucernMod");
    }

    if (ok)
    {
        ok = unitsLbx.replaceRecord(0, dataBuffer);
    }

    // Replace FIGURES9/0-8 by Lucern/FIGURES4_072-079 (4 images each)
    for (int direction = 0; direction < 8; ++direction)
    {
        QVector<QImage> images(4);
        for (int movement = 0; movement < 4; ++movement)
        {
            QImage image;
            QString filename = QString("%0_%1_%2.png")
                    .arg(figuresFilename.c_str())
                    .arg(72 + direction, 3, 10, QChar('0'))
                    .arg(movement, 3, 10, QChar('0'));
            if (ok)
            {
                ok = image.load(filename);
            }
            if (ok)
            {
                images[movement] = image.convertToFormat(QImage::Format_Indexed8, colorTable, Qt::AutoColor);
            }
        }
        std::vector<uint8_t> dataBuffer;
        if (ok)
        {
            ok = MoM::convertImagesToLbx(images, dataBuffer, "LucernMod");
        }
        if (ok)
        {
            ok = figuresLbx.replaceRecord(0 + direction, dataBuffer);
        }
    }

    // Save UNITSX.LBX
    if (ok)
    {
        ok = unitsLbx.save(unitsLbx.getFilename());
    }

    // Save FIGUREXX.LBX
    if (ok)
    {
        ok = figuresLbx.save(figuresLbx.getFilename());
    }

    return ok;
}
*/
void DialogTools::on_pushButton_LucernMod_clicked()
{
    MainWindow* controller = MainWindow::getInstance();
	QMoMGamePtr game = getGame();
    if (game.isNull())
    {
        (void)QMessageBox::warning(this,
            tr("Lucern mod"),
            tr("There is no game to operate on"));
        return;
    }

    // Load FONTS.LBX (TODO: needs centralization)
    QVector<QRgb> colorTable(256);
    std::string fontsLbxFile = game->getGameDirectory() + "/" + "FONTS.LBX";
    MoM::MoMLbxBase fontsLbx;
    bool ok = fontsLbx.load(fontsLbxFile);
    if (ok)
    {
        const uint8_t* dataPalette = fontsLbx.getRecord(2);
        MoM::convertLbxToPalette(dataPalette, colorTable);
    }

    // Adjust color table for proper color matching
    colorTable.resize(244);
    colorTable[0] = qRgb(255, 0, 255);  // Treat MAGENTA RGB(255, 0, 255) as TRANSPARENT!
    colorTable[232] = qRgb(0, 255, 0);    // Treat GREEN RGB(0, 255, 0) as SHADOW (232 or 239??)

    // Load Centaur Scouts
    QImage image;
    if (ok)
    {
        ok = image.load("UNITS2_000_000.png");
    }

    if (ok)
    {
        image = image.convertToFormat(QImage::Format_Indexed8, colorTable, Qt::AutoColor);

        // TODO: Remove verification
        image.save("UNIT_Centaur_Scouts.png");
        std::cout << "pixel(1,5) = " << (int)image.pixelIndex(1,5) << " pixel(1,6) = " << (int)image.pixelIndex(1,6) << std::endl;
//        ui->label_Image->setPixmap(QPixmap::fromImage(image));
    }

    // Load UNITS2.LBX
    std::string units2LbxFile = game->getGameDirectory() + "/" + "UNITS2.LBX";
    MoM::MoMLbxBase units2Lbx;
    if (ok)
    {
        ok = units2Lbx.load(units2LbxFile);
    }

    // Load FIGURES9.LBX
    std::string figuresLbxFile = game->getGameDirectory() + "/" + "FIGURES9.LBX";
    MoM::MoMLbxBase figuresLbx;
    if (ok)
    {
        ok = figuresLbx.load(figuresLbxFile);
    }

    // Replace UNITS2/0 by Lucern/FIGURES4_077_001
    const QVector<QImage> images(1, image);
    std::vector<uint8_t> dataBuffer;
    if (ok)
    {
        ok = MoM::convertImagesToLbx(images, dataBuffer, "LucernMod");
    }

    if (ok)
    {
        ok = units2Lbx.replaceRecord(0, dataBuffer);
    }

    // Replace FIGURES9/0-8 by Lucern/FIGURES4_072-079 (4 images each)
    for (int direction = 0; direction < 8; ++direction)
    {
        QVector<QImage> images(4);
        for (int movement = 0; movement < 4; ++movement)
        {
            QImage image;
            QString filename = QString("Lucern/Centaur Scouts/FIGURES4_%0_%1.png").arg(72 + direction, 3, 10, QChar('0')).arg(movement, 3, 10, QChar('0'));
            if (ok)
            {
                ok = image.load(filename);
            }
            if (ok)
            {
                images[movement] = image.convertToFormat(QImage::Format_Indexed8, colorTable, Qt::AutoColor);
            }
        }
        std::vector<uint8_t> dataBuffer;
        if (ok)
        {
            ok = MoM::convertImagesToLbx(images, dataBuffer, "LucernMod");
        }
        if (ok)
        {
            ok = figuresLbx.replaceRecord(0 + direction, dataBuffer);
        }
    }

    // Save UNITS2.LBX
    if (ok)
    {
        ok = units2Lbx.save(units2Lbx.getFilename());
    }

    // Save FIGURES9.LBX
    if (ok)
    {
        ok = figuresLbx.save(figuresLbx.getFilename());
    }

    if (!ok)
    {
        statusBar()->showMessage(tr("Failed to apply Lucern mod"));
    }
    else
    {
        statusBar()->showMessage(tr("Lucern mod applied"));
    }

    controller->update();
}

void DialogTools::on_pushButton_SelectInitialSpells_clicked()
{
    DialogSelectInitialSpells* dialog = new DialogSelectInitialSpells(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

QStatusBar* DialogTools::statusBar()
{
    MainWindow* mainWindow = MainWindow::getInstance();
	return mainWindow->statusBar();
}
