#include <QtCore/QString>
#include <QtTest/QtTest>

#include "TeeRedirecter.h"

int runTests_Test_MoMTweaker(int argc, char *argv[]);


// The Qt-free core tests moved to tests/ (doctest, built with CMake).

int main(int argc, char *argv[])
{
    const char* output_filename = "cout_cerr.log";
    std::cout << "Teeing output to " << output_filename << std::endl;
    TeeRedirecter redirecter(output_filename, true);

    int exitCode = 0;
    if (0 == exitCode) exitCode = runTests_Test_MoMTweaker(argc, argv);
    return exitCode;
}
