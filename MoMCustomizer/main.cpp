// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include <QtGui/QApplication>

#include <fstream>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
#ifdef _WIN32
    const char* output_filename = "cout_cerr.log";
    std::cout << "Redirecting output to " << output_filename << std::endl;
    std::ofstream ofs_cout(output_filename);
    std::cout.rdbuf(ofs_cout.rdbuf());
    std::cerr.rdbuf(ofs_cout.rdbuf());
    std::cout << "Output redirected from cout/cerr" << std::endl;
#endif

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
