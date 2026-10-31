#include <doctest.h>

#include <cmath>
#include <cstring>
#include <fstream>
#include <memory>
#include <string>

#include <MoMCombat.h>
#include <MoMController.h>
#include <MoMGameMemory.h>
#include "test_utility.h"

// These tests need the unit data of a running game, so they connect to
// Master of Magic in DOSBox. They are skipped by default; run them with
//      rtgt_tests --no-skip

namespace
{

// Connect once and share the connection between all test cases
MoM::MoMGameMemory* liveGame()
{
    static MoM::MoMGameMemory gameMemory;
    static bool tried = false;
    static bool connected = false;
    if (!tried)
    {
        tried = true;
        std::unique_ptr<MoM::MoMProcess> momProcess(new MoM::MoMProcess);
        connected = momProcess->findProcessAndData() && gameMemory.openGame(momProcess);
    }
    return connected ? &gameMemory : nullptr;
}

class CombatFixture
{
public:
    CombatFixture() :
        m_game(liveGame()),
        m_combat(),
        m_attacker(m_game),
        m_defender(m_game)
    {
        REQUIRE_MESSAGE(m_game != nullptr, "No running Master of Magic found in DOSBox");
    }

protected:
    void createHero(MoM::ePlayer playerNr, int slotNr, int unitNr)
    {
        MoM::Hired_Hero* hiredHero = m_game->getHiredHero(playerNr, slotNr);
        MoM::Unit* unit = m_game->getUnit(unitNr);

        REQUIRE(hiredHero != nullptr);
        REQUIRE(unit != nullptr);
        memset(hiredHero, '\0', sizeof(*hiredHero));
        memset(unit, '\0', sizeof(*unit));

        hiredHero->m_Unit_Nr = unitNr;
        hiredHero->m_Items_In_Slot[0] = -1;
        hiredHero->m_Items_In_Slot[1] = -1;
        hiredHero->m_Items_In_Slot[2] = -1;
        unit->m_Owner = playerNr;
        unit->m_Hero_Slot_Number = slotNr;
    }

    void test_combat_attack(const std::string& testName)
    {
        std::ofstream ofs((testName + ".out").c_str());

        ofs << testName << "\n";
        ofs << "Unit " << m_attacker.getDisplayName() << "\n"
            << "attacks unit " <<  m_defender.getDisplayName() << "\n\n";

        std::string ostr = m_combat.combat_attack(m_attacker, m_defender);

        ofs << ostr;
        ofs.close();

        CHECK_MESSAGE(0 == diff(testName + ".out", refFile(testName)), testName);
    }

    void test_shoot_attack(const std::string& testName, int distance)
    {
        std::ofstream ofs((testName + ".out").c_str());

        ofs << testName << "\n";
        ofs << "Unit " << m_attacker.getDisplayName() << "\n"
            << "shoot unit " <<  m_defender.getDisplayName() << "\n"
            << "at distance " <<  distance << "\n\n";

        std::string ostr = m_combat.shoot_attack(m_attacker, m_defender, distance);

        ofs << ostr;
        ofs.close();

        CHECK_MESSAGE(0 == diff(testName + ".out", refFile(testName)), testName);
    }

    static std::string refFile(const std::string& testName)
    {
        return std::string(RTGT_TEST_DATA_DIR) + "combat/" + testName + ".ref";
    }

    MoM::MoMGameMemory* m_game;
    MoM::MoMCombat  m_combat;
    MoM::CombatUnit m_attacker;
    MoM::CombatUnit m_defender;
};

}

TEST_SUITE("live" * doctest::skip())
{

TEST_CASE_FIXTURE(CombatFixture, "combat: nominal")
{
    m_attacker.changeUnit(MoM::UNITTYPE_High_Men_Swordsmen);
    m_defender.changeUnit(MoM::UNITTYPE_High_Men_Spearmen);
    test_combat_attack("testCase_Nominal");
}

// TODO: First Strike, Armor Piercing, Breath, Gaze, Touch, ...
// TODO: Items: Vampiric, ...

TEST_CASE_FIXTURE(CombatFixture, "combat: ability flying")
{
    // Cannot attack flying creature
    m_attacker.changeUnit(MoM::UNITTYPE_High_Men_Swordsmen);
    m_defender.changeUnit(MoM::UNITTYPE_Green_Gorgons);
    test_combat_attack("testCase_AbilityFlying1");

    // Flying creature can attack ground unit in which case the ground unit can retaliate
    m_attacker.changeUnit(MoM::UNITTYPE_Green_Gorgons);
    m_defender.changeUnit(MoM::UNITTYPE_High_Men_Spearmen);
    test_combat_attack("testCase_AbilityFlying2");
}

TEST_CASE_FIXTURE(CombatFixture, "combat: ability invisible")
{
    // Attack invisible
    m_attacker.changeUnit(MoM::UNITTYPE_High_Men_Swordsmen);
    m_defender.changeUnit(MoM::UNITTYPE_Dark_Elf_Nightblades);
    test_combat_attack("testCase_AbilityInvisible1");

    // Defend against invisible
    m_attacker.changeUnit(MoM::UNITTYPE_Dark_Elf_Nightblades);
    m_defender.changeUnit(MoM::UNITTYPE_High_Men_Swordsmen);
    test_combat_attack("testCase_AbilityInvisible2");
}

TEST_CASE_FIXTURE(CombatFixture, "combat: item flying")
{
    int attUnitNr = 0;
    int defUnitNr = 1;

    // Can't attack flying hero
    createHero(MoM::PLAYER_YOU, 0, attUnitNr);
    MoM::Unit* attUnit = m_game->getUnit(attUnitNr);
    MoM::Hired_Hero* attHero = m_game->getHiredHero(attUnit);
    attUnit->m_Unit_Type = MoM::UNITTYPE_Dwarf;
    m_attacker.changeUnit(attUnit);

    createHero(MoM::PLAYER_1, 0, defUnitNr);
    MoM::Unit* defUnit = m_game->getUnit(defUnitNr);
    MoM::Hired_Hero* defHero = m_game->getHiredHero(defUnit);
    defUnit->m_Unit_Type = MoM::UNITTYPE_Barbarian;
    defHero->m_Items_In_Slot[2] = 0;
    MoM::Item* item = m_game->getItem(0);
    memset(item, '\0', sizeof(*item));
    item->m_Bitmask_Powers.s.Flight = true;
    m_defender.changeUnit(defUnit);

    test_combat_attack("testCase_ItemFlying1");

    // Flying hero can attack flying hero
    attHero->m_Items_In_Slot[2] = 0;
    test_combat_attack("testCase_ItemFlying2");
}

TEST_CASE_FIXTURE(CombatFixture, "combat: level")
{
    MoM::Unit attUnit = m_attacker.getUnitInGame();
    attUnit.m_Unit_Type = MoM::UNITTYPE_High_Men_Swordsmen;
    attUnit.m_Level = MoM::LEVEL_Level_5;   // Super-Elite
    m_attacker.changeUnit(&attUnit);

    MoM::Unit defUnit = m_defender.getUnitInGame();
    defUnit.m_Unit_Type = MoM::UNITTYPE_High_Men_Spearmen;
    defUnit.m_Level = MoM::LEVEL_Level_2;   // Regular
    m_defender.changeUnit(&defUnit);

    test_combat_attack("testCase_Level");
}

TEST_CASE_FIXTURE(CombatFixture, "combat: shoot arrows")
{
    // Regular shooting arrows
    m_attacker.changeUnit(MoM::UNITTYPE_High_Men_Bowmen);
    m_defender.changeUnit(MoM::UNITTYPE_High_Men_Spearmen);
    test_shoot_attack("testCase_ShootArrows_Arrows", 5);

    // Bullets
    m_attacker.changeUnit(MoM::UNITTYPE_Halfling_Slingers);
    m_defender.changeUnit(MoM::UNITTYPE_High_Men_Spearmen);
    test_shoot_attack("testCase_ShootArrows_Bullets", 10);

    // Rocks
    m_attacker.changeUnit(MoM::UNITTYPE_Catapult);
    m_defender.changeUnit(MoM::UNITTYPE_High_Men_Spearmen);
    test_shoot_attack("testCase_ShootArrows_Rocks", 10);

    // Shoot invisible not allowed at a distance
    m_attacker.changeUnit(MoM::UNITTYPE_Catapult);
    m_defender.changeUnit(MoM::UNITTYPE_Dark_Elf_Nightblades);
    test_shoot_attack("testCase_ShootArrows_Invis1", 2);

    // Shoot invisible at distance 1
    m_attacker.changeUnit(MoM::UNITTYPE_Catapult);
    m_defender.changeUnit(MoM::UNITTYPE_Dark_Elf_Nightblades);
    test_shoot_attack("testCase_ShootArrows_Invis2", 1);
}

TEST_CASE_FIXTURE(CombatFixture, "combat: shoot magic")
{
    // Shoot magic
    m_attacker.changeUnit(MoM::UNITTYPE_Blue_Storm_Giant);
    m_defender.changeUnit(MoM::UNITTYPE_High_Men_Spearmen);
    test_shoot_attack("testCase_ShootMagic_Unit", 5);

    // Use mana
    MoM::Unit attUnit = m_attacker.getUnitInGame();
    attUnit.m_Unit_Type = MoM::UNITTYPE_Healer;
    attUnit.m_Level = MoM::LEVEL_Level_4;
    m_attacker.changeUnit(&attUnit);
    m_defender.changeUnit(MoM::UNITTYPE_High_Men_Spearmen);
    test_shoot_attack("testCase_ShootMagic_Hero", 5);

    // Shoot invisible not allowed at a distance
    m_attacker.changeUnit(MoM::UNITTYPE_High_Men_Priests);
    m_defender.changeUnit(MoM::UNITTYPE_Dark_Elf_Nightblades);
    test_shoot_attack("testCase_ShootMagic_Invis1", 2);

    // Shoot invisible at distance 1
    m_attacker.changeUnit(MoM::UNITTYPE_High_Men_Priests);
    m_defender.changeUnit(MoM::UNITTYPE_Dark_Elf_Nightblades);
    test_shoot_attack("testCase_ShootMagic_Invis2", 1);
}

TEST_CASE_FIXTURE(CombatFixture, "combat: spell flying")
{
    // Cannot attack flying creature
    m_attacker.changeUnit(MoM::UNITTYPE_High_Men_Swordsmen);
    MoM::Unit defUnit = m_defender.getUnitInGame();
    defUnit.m_Unit_Type = MoM::UNITTYPE_High_Men_Spearmen;
    defUnit.m_Unit_Enchantment.s.Flight = true;
    m_defender.changeUnit(&defUnit);
    test_combat_attack("testCase_SpellFlying1");

    // Flying creature can attack ground unit
    MoM::Unit attUnit = m_attacker.getUnitInGame();
    attUnit.m_Unit_Type = MoM::UNITTYPE_High_Men_Swordsmen;
    attUnit.m_Unit_Enchantment.s.Flight = true;
    m_attacker.changeUnit(&attUnit);
    m_defender.changeUnit(MoM::UNITTYPE_High_Men_Spearmen);
    test_combat_attack("testCase_SpellFlying2");
}

TEST_CASE_FIXTURE(CombatFixture, "combat: weapon type")
{
    MoM::Unit attUnit = m_attacker.getUnitInGame();
    attUnit.m_Unit_Type = MoM::UNITTYPE_High_Men_Swordsmen;
    attUnit.m_Weapon_Mutation.s.Weapon_Type = MoM::WEAPON_magic;
    m_attacker.changeUnit(&attUnit);

    MoM::Unit defUnit = m_defender.getUnitInGame();
    defUnit.m_Unit_Type = MoM::UNITTYPE_High_Men_Spearmen;
    defUnit.m_Weapon_Mutation.s.Weapon_Type = MoM::WEAPON_adamantium;
    m_defender.changeUnit(&defUnit);

    test_combat_attack("testCase_WeaponType");
}

}
