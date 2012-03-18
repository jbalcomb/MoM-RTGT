#include <QtCore/QString>
#include <QtTest/QtTest>

#include <mainwindow.h>
#include <ui_mainwindow.h>

class Test_MoMTweaker_MainWindow : public QObject
{
    Q_OBJECT
    
public:
    Test_MoMTweaker_MainWindow();
    
private Q_SLOTS:
    void testCase_Nominal();
    void testCase_Failures();
};

Test_MoMTweaker_MainWindow::Test_MoMTweaker_MainWindow()
{
}

void Test_MoMTweaker_MainWindow::testCase_Nominal()
{
    MainWindow w;
    w.show();

    QTestEventList eventsConnect;
    QTestEventList eventsMessage;
    eventsConnect.addMouseClick(Qt::LeftButton, 0, QPoint(), 1000);
    eventsConnect.simulate(w.ui->pushButton_Connect);
    QCOMPARE(w.statusBar()->currentMessage(), QString("Game connection failed"));
}

void Test_MoMTweaker_MainWindow::testCase_Failures()
{
    QVERIFY2(true, "Failure");
}

int runTests_Test_MoMTweaker(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTEST_DISABLE_KEYPAD_NAVIGATION
    Test_MoMTweaker_MainWindow tc;
    return QTest::qExec(&tc, argc, argv);
}

#include "tst_momtweaker_mainwindow.moc"
