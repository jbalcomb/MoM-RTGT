#include <doctest.h>

#include <cstdio>
#include <string>

#include <MoMGameSave.h>
#include "test_utility.h"

namespace
{
const std::string gRefGameFile = std::string(RTGT_TEST_DATA_DIR) + "REFTEST.GAM";
const std::string gNotExistingGameFile = "NOTEXIST.GAM";
const std::string gTestGameFile = "SAVETEST.GAM";
}

TEST_SUITE("MoMGameBase")
{

TEST_CASE("load fails for a missing file")
{
    MoM::MoMGameSave game;
    CHECK_FALSE(game.load(gNotExistingGameFile.c_str()));
    CHECK(game.errorString() == "Could not open file 'NOTEXIST.GAM' for reading");
}

TEST_CASE("load reference save game")
{
    // TODO: Check each possible MoMVersion
    MoM::MoMGameSave game;
    REQUIRE(game.load(gRefGameFile.c_str()));
    CHECK(game.errorString() == "");
}

TEST_CASE("save reproduces the loaded save game byte for byte")
{
    // TODO: Check each possible type of file (.LBX, MAGIC.EXE, etcetera)
    (void)std::remove(gTestGameFile.c_str());
    MoM::MoMGameSave game;
    REQUIRE(game.load(gRefGameFile.c_str()));

    REQUIRE(game.save(gTestGameFile.c_str()));
    CHECK(game.errorString() == "");
    CHECK(diff(gRefGameFile, gTestGameFile) == 0);

    CHECK(std::remove(gTestGameFile.c_str()) == 0);
}

}
