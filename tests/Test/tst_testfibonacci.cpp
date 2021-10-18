#include <QtTest>

// add necessary includes here

class TestFibonacci : public QObject
{
    Q_OBJECT

public:
    TestFibonacci();
    ~TestFibonacci();

private slots:
    void test_case1();

};

TestFibonacci::TestFibonacci()
{

}

TestFibonacci::~TestFibonacci()
{

}

void TestFibonacci::test_case1()
{

}

QTEST_APPLESS_MAIN(TestFibonacci)

#include "tst_testfibonacci.moc"
