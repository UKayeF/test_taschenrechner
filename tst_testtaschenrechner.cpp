#include <QtTest>
#include "taschenrechner.hpp"

// add necessary includes here

class TestTaschenrechner : public QObject
{
    Q_OBJECT

public:
    TestTaschenrechner();
    ~TestTaschenrechner();

private slots:
    void test_constructor();

};

TestTaschenrechner::TestTaschenrechner()
{

}

TestTaschenrechner::~TestTaschenrechner()
{

}

void TestTaschenrechner::test_constructor()
{
    Taschenrechner rechner;
    std::string eingabe = "3+5";
    rechner.setEingabe(eingabe);
    QCOMPARE(rechner.getEingabe(), eingabe);
}

QTEST_APPLESS_MAIN(TestTaschenrechner)

#include "tst_testtaschenrechner.moc"
