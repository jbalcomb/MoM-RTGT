#include <QtCore/QString>
#include <QtTest/QtTest>

int runTests_MoMGameBase(int argc, char *argv[]);
int runTests_Test_MoMTweaker(int argc, char *argv[]);


int main(int argc, char *argv[])
{
    int exitCode = 0;
    if (0 == exitCode) exitCode = runTests_MoMGameBase(argc, argv);
    if (0 == exitCode) exitCode = runTests_Test_MoMTweaker(argc, argv);
    return exitCode;
}
