#include "tst_dbManager.hpp"

TestDBManager::TestDBManager()
  : m_connectManager(nsDb::ConnectManager::instance())
{}

TestDBManager::~TestDBManager() {}

void
TestDBManager::test_connectManager()
{
  QVERIFY2(m_connectManager.isValid() == true, "Check valid is not valid.");
  QVERIFY2(m_connectManager.state() == "OK", "State is not OK");
}

QTEST_APPLESS_MAIN(TestDBManager)
