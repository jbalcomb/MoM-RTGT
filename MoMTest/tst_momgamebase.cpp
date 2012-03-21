#include <QtCore/QString>
#include <QtTest/QtTest>

#include <cstdio>
#include <fstream>

#include <MoMGameSave.h>

namespace
{
const std::string gRefGameFile = "REFTEST.GAM";
const std::string gNotExistingGameFile = "NOTEXIST.GAM";
const std::string gTestGameFile = "SAVETEST.GAM";
}

// Implement function for POSIX diff that is not (always) available (in Windows)
int diff(const std::string& file1, const std::string& file2)
{
    // Open both files
    std::ifstream ifs1(file1.c_str(), std::ios::binary);
    if (!ifs1)
        return 2;
    std::ifstream ifs2(file2.c_str(), std::ios::binary);
    if (!ifs2)
        return 2;

    // Get file sizes
    ifs1.seekg(0, std::ios_base::end);
    std::ios::pos_type size1 = ifs1.tellg();
    ifs2.seekg(0, std::ios_base::end);
    std::ios::pos_type size2 = ifs2.tellg();
    if (size1 != size2)
        return 1;
    ifs1.seekg(0, std::ios_base::beg);
    ifs2.seekg(0, std::ios_base::beg);

    // Read files
    std::string buf1(size1, '\0');
    ifs1.read(&buf1[0], size1);
    if (!ifs1)
        return 2;
    std::string buf2(size2, '\0');
    ifs2.read(&buf2[0], size2);
    if (!ifs2)
        return 2;

    if (buf1 == buf2)
        return 0;
    else
        return 1;
}

class Test_MoMGameBase : public QObject
{
    Q_OBJECT
    
public:
    Test_MoMGameBase();
    
private Q_SLOTS:
    void testCase_Failures();
    void load();
    void save();
};

Test_MoMGameBase::Test_MoMGameBase()
{
}

void Test_MoMGameBase::testCase_Failures()
{
    MoM::MoMGameSave game;
    QVERIFY(!game.load(gNotExistingGameFile.c_str()));
    QCOMPARE(game.errorString().c_str(), "Could not open file 'NOTEXIST.GAM' for reading");
}

void Test_MoMGameBase::load()
{
    MoM::MoMGameSave game;
    QVERIFY(game.load(gRefGameFile.c_str()));
    QCOMPARE(game.errorString().c_str(), "");
}

void Test_MoMGameBase::save()
{
    // TODO: Check each possible type of file (.LBX, MAGIC.EXE, etcetera)

    // Setup: clean up and load a file
    (void)std::remove(gTestGameFile.c_str());
    MoM::MoMGameSave game;
    QVERIFY(game.load(gRefGameFile.c_str()));

    // Test: save file and compare it with reference
    QVERIFY(game.save(gTestGameFile.c_str()));
    QCOMPARE(game.errorString().c_str(), "");
    QCOMPARE(diff(gRefGameFile, gTestGameFile), 0);

    // Clean up
    QCOMPARE(std::remove(gTestGameFile.c_str()), 0);
}

int runTests_MoMGameBase(int argc, char *argv[])
{
    Test_MoMGameBase tc;
    return QTest::qExec(&tc, argc, argv);
}

#include "tst_momgamebase.moc"
