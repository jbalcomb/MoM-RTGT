// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include <QApplication>

#include "QMoMSettings.h"
#include "TeeRedirecter.h"

#include "MainWindow.h"

int main(int argc, char *argv[])
{
    const char* output_filename = "cout_cerr.log";
    std::cout << "Teeing output to " << output_filename << std::endl;
    TeeRedirecter redirecter(output_filename, true);

    // Run application
    QApplication a(argc, argv);

    // Settings for the configuration
    QMoMSettings::initialize("MoMTweaker");

    MainWindow w;
    w.show();
    return a.exec();
}
