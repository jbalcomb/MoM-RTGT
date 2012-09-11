#include <QtCore/QString>
#include <QtTest/QtTest>

#include <cstdio>
#include <fstream>

#include <MoMCombat.h>
#include <MoMGameMemory.h>

class Test_MoMCombat : public QObject
{
    Q_OBJECT
    
public:
    Test_MoMCombat();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();

    void init();
    void cleanup();

    void testCase_Nominal();

    void testCase_Abilities();
    void testCase_AbilityFlying();
    void testCase_AbilityInvisible();
    void testCase_Items();
    void testCase_ItemFlying();
    void testCase_ItemInvisible();
//    void testCase_ItemInvulnerability();
    void testCase_Level();

    void testCase_ShootArrows();
    void testCase_ShootMagic();

//    void testCase_SpecialPreBreath();
//    void testCase_SpecialPreGaze();
//    void testCase_SpecialPreThrown();
//    void testCase_SpecialPreGazeDefend();
//    void testCase_SpecialPreMultipleGaze();

//    void testCase_SpecialImmolation();
//    void testCase_SpecialPoison();
//    void testCase_SpecialTouch();
//    void testCase_SpecialFirstStrike();

//    void testCase_Spells();
    void testCase_SpellFlying();
//    void testCase_SpellInvisibility();
//    void testCase_SpellInvulnerability();
    void testCase_WeaponType();

private:
    MoM::MoMGameMemory m_game;
    MoM::CombatUnit m_attacker;
    MoM::CombatUnit m_defender;
};

Test_MoMCombat::Test_MoMCombat() :
    m_game(),
    m_attacker(&m_game),
    m_defender(&m_game)
{
}

void Test_MoMCombat::initTestCase()
{
    // General set up, which is connecting to a game, since we need the unit data.
    std::auto_ptr<MoM::MoMProcess> momProcess(new MoM::MoMProcess);
    QVERIFY(momProcess->findProcessAndData());
    QVERIFY(m_game.openGame(momProcess));
    m_attacker.setGame(&m_game);
    m_defender.setGame(&m_game);
}

void Test_MoMCombat::cleanupTestCase()
{
}

void Test_MoMCombat::init()
{
    m_attacker.damage = 0;
    m_defender.damage = 0;
}

void Test_MoMCombat::cleanup()
{
}

void Test_MoMCombat::testCase_Nominal()
{
    MoM::MoMCombat combat;
    m_attacker.changeUnit(MoM::UNITTYPE_High_Men_Swordsmen);
    m_defender.changeUnit(MoM::UNITTYPE_High_Men_Spearmen);
    QString ostr = combat.combat_attack(m_attacker, m_defender).c_str();

    QCOMPARE(m_defender.damage, 1.00842);
    QCOMPARE(m_attacker.damage, 0.0);
    QString expected("Unit of 6 High Men Swordsmen attacks for 1 damage\n"
                     "Unit of 8 High Men Spearmen attacks for 0 damage\n"
                     "Unit of High Men Spearmen has 7 units left with a total of 7 hp\n\n");
    QCOMPARE(ostr, expected);
}

void Test_MoMCombat::testCase_Abilities()
{
}

void Test_MoMCombat::testCase_AbilityFlying()
{
    MoM::MoMCombat combat;

    // Cannot attack flying creature
    m_attacker.changeUnit(MoM::UNITTYPE_High_Men_Swordsmen);
    m_defender.changeUnit(MoM::UNITTYPE_Green_Gorgons);
    QString ostr = combat.combat_attack(m_attacker, m_defender).c_str();
    QCOMPARE(m_defender.damage, 0.0);
    QCOMPARE(m_attacker.damage, 0.0);

    // Flying creature can attack ground unit
    m_attacker.changeUnit(MoM::UNITTYPE_Green_Gorgons);
    m_defender.changeUnit(MoM::UNITTYPE_High_Men_Spearmen);
    ostr = combat.combat_attack(m_attacker, m_defender).c_str();
    QCOMPARE(m_defender.damage, 0.0);
    QCOMPARE(m_attacker.damage, 0.0);
}

void Test_MoMCombat::testCase_AbilityInvisible()
{
    MoM::MoMCombat combat;

    // Attack invisible
    m_attacker.changeUnit(MoM::UNITTYPE_High_Men_Swordsmen);
    m_defender.changeUnit(MoM::UNITTYPE_Dark_Elf_Nightblades);
    QString ostr = combat.combat_attack(m_attacker, m_defender).c_str();
    QCOMPARE(m_defender.damage, 0.0);
    QCOMPARE(m_attacker.damage, 0.0);

    // Defend against invisible
    m_attacker.changeUnit(MoM::UNITTYPE_Dark_Elf_Nightblades);
    m_defender.changeUnit(MoM::UNITTYPE_High_Men_Swordsmen);
    ostr = combat.combat_attack(m_attacker, m_defender).c_str();
    QCOMPARE(m_defender.damage, 0.0);
    QCOMPARE(m_attacker.damage, 0.0);
}

void Test_MoMCombat::testCase_Items()
{
}

void Test_MoMCombat::testCase_ItemFlying()
{
}

void Test_MoMCombat::testCase_ItemInvisible()
{
}

void Test_MoMCombat::testCase_Level()
{
    MoM::MoMCombat combat;
    MoM::Unit attUnit = m_attacker.getUnitInGame();
    attUnit.m_Unit_Type = MoM::UNITTYPE_High_Men_Swordsmen;
    attUnit.m_Level = MoM::LEVEL_Level_5;   // Super-Elite
    m_attacker.changeUnit(&attUnit);
    m_defender.changeUnit(MoM::UNITTYPE_High_Men_Spearmen);
    QString ostr = combat.combat_attack(m_attacker, m_defender).c_str();

    QCOMPARE(m_defender.damage, 5.42637);
    QCOMPARE(m_attacker.damage, 0.0);
    QString expected("Unit of 6 High Men Swordsmen attacks for 1 damage\n"
                     "Unit of 8 High Men Spearmen attacks for 0 damage\n"
                     "Unit of High Men Spearmen has 7 units left with a total of 7 hp\n\n");
    QCOMPARE(ostr, expected);
}

void Test_MoMCombat::testCase_ShootArrows()
{
}

void Test_MoMCombat::testCase_ShootMagic()
{
}

void Test_MoMCombat::testCase_SpellFlying()
{
    MoM::MoMCombat combat;

    // Cannot attack flying creature
    m_attacker.changeUnit(MoM::UNITTYPE_High_Men_Swordsmen);
    MoM::Unit defUnit = m_defender.getUnitInGame();
    defUnit.m_Unit_Type = MoM::UNITTYPE_High_Men_Spearmen;
    defUnit.m_Unit_Enchantment.s.Flight = true;
    m_defender.changeUnit(&defUnit);
    QString ostr = combat.combat_attack(m_attacker, m_defender).c_str();
    QCOMPARE(m_defender.damage, 0.0);
    QCOMPARE(m_attacker.damage, 0.0);

    // Flying creature can attack ground unit
    MoM::Unit attUnit = m_attacker.getUnitInGame();
    attUnit.m_Unit_Type = MoM::UNITTYPE_High_Men_Swordsmen;
    attUnit.m_Unit_Enchantment.s.Flight = true;
    m_attacker.changeUnit(&attUnit);
    m_defender.changeUnit(MoM::UNITTYPE_High_Men_Spearmen);
    ostr = combat.combat_attack(m_attacker, m_defender).c_str();
    QCOMPARE(m_defender.damage, 0.0);
    QCOMPARE(m_attacker.damage, 0.0);
}

void Test_MoMCombat::testCase_WeaponType()
{
    MoM::MoMCombat combat;
    m_attacker.changeUnit(MoM::UNITTYPE_High_Men_Swordsmen);
    MoM::Unit defUnit = m_defender.getUnitInGame();
    defUnit.m_Unit_Type = MoM::UNITTYPE_High_Men_Spearmen;
    defUnit.m_Weapon_Mutation.s.Weapon_Type = MoM::WEAPON_adamantium;
    m_defender.changeUnit(&defUnit);
    QString ostr = combat.combat_attack(m_attacker, m_defender).c_str();

    QCOMPARE(m_defender.damage, 0.494126);
    QCOMPARE(m_attacker.damage, 0.0);
    QString expected("Unit of 6 High Men Swordsmen attacks for 1 damage\n"
                     "Unit of 8 High Men Spearmen attacks for 0 damage\n"
                     "Unit of High Men Spearmen has 7 units left with a total of 7 hp\n\n");
    QCOMPARE(ostr, expected);
}


int runTests_MoMCombat(int argc, char *argv[])
{
    Test_MoMCombat tc;
    return QTest::qExec(&tc, argc, argv);
}

#include "tst_momcombat.moc"
