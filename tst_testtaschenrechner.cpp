#include <QtTest>
#include "taschenrechner.hpp"

class TestTaschenrechner : public QObject
{
    Q_OBJECT

public:
    TestTaschenrechner();
    ~TestTaschenrechner();

private slots:
    void test_constructor();
    void test_addition();
    void test_multiplication();
    void test_minus();
    void test_division();
    void handle_division_by_zero();
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

void TestTaschenrechner::test_addition()
{
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            int expected = i + j;
            Taschenrechner rechner;
            std::string first_int = std::to_string(i);
            std::string second_int = std::to_string(j);
            std::string eingabe = first_int + "+" + second_int;
            rechner.setEingabe(eingabe);
            int actual = rechner.berechne();
            QCOMPARE(expected, actual);
        }
    }
}

void TestTaschenrechner::test_multiplication()
{
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            int expected = i * j;
            Taschenrechner rechner;
            std::string first_int = std::to_string(i);
            std::string second_int = std::to_string(j);
            std::string eingabe = first_int + "*" + second_int;
            rechner.setEingabe(eingabe);
            int actual = rechner.berechne();
            QCOMPARE(expected, actual);
        }
    }
}

void TestTaschenrechner::test_minus()
{
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            int expected = i - j;
            Taschenrechner rechner;
            std::string first_int = std::to_string(i);
            std::string second_int = std::to_string(j);
            std::string eingabe = first_int + "-" + second_int;
            rechner.setEingabe(eingabe);
            int actual = rechner.berechne();
            QCOMPARE(expected, actual);
        }
    }
}

void TestTaschenrechner::test_division()
{
    for (int i = 0; i < 100; i++){
        for (int j = 1; j < 100; j++){
            int expected = i / j;
            Taschenrechner rechner;
            std::string first_int = std::to_string(i);
            std::string second_int = std::to_string(j);
            std::string eingabe = first_int + "/" + second_int;
            rechner.setEingabe(eingabe);
            int actual = rechner.berechne();
            QCOMPARE(expected, actual);
        }
    }
}

void TestTaschenrechner::handle_division_by_zero()
{
    Taschenrechner rechner;
    rechner.setEingabe("1/0");
    bool throws_exception = false;
    try {
        rechner.berechne();
    }  catch (std::exception e) {
        throws_exception = true;
    }
    QCOMPARE(throws_exception, true);
}

QTEST_APPLESS_MAIN(TestTaschenrechner)

#include "tst_testtaschenrechner.moc"
