#include "tst_dbManager.hpp"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>

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

void
TestDBManager::test_executor()
{
  auto res = m_executor.executor("SELECT * FROM punctuation");
  auto query = res.second;
  auto nRecord = query.record().count();

  QVERIFY2(res.first == nsDb::DBResult::OK, "Query false.");
  QVERIFY2(nRecord == 3, "nRecords not equal 3 (id, letter, code)");
}

void
TestDBManager::test_selector()
{
  auto [result, data] = m_selector.digits();
  auto [resEnAlphabet, dataEnAlphabet] = m_selector.enAlphabet();
  auto [resRusAlphabet, dataRusAlphabet] = m_selector.enAlphabet();
  auto [resPunctuation, dataPunctuation] = m_selector.punctuation();
  auto [resDigits, dataDigits] = m_selector.digits();

  QVERIFY2(result == nsDb::DBResult::OK, "Request false.");
  QVERIFY2(data.empty() == false, "Data is empty");

  QVERIFY2(resEnAlphabet == nsDb::DBResult::OK, "Request enAlphabet false.");
  QVERIFY2(dataEnAlphabet.empty() == false, "Data en alphabet is empty");

  QVERIFY2(resRusAlphabet == nsDb::DBResult::OK, "Request rusAlphabet false.");
  QVERIFY2(dataRusAlphabet.empty() == false, "Data rus alphabet is empty");

  QVERIFY2(resPunctuation == nsDb::DBResult::OK, "Request punctuation false.");
  QVERIFY2(dataPunctuation.empty() == false,
           "Data punctuation alphabet is empty");
}

void
TestDBManager::test_processor()
{
  auto [resDigits, dataDigits] =
    m_processor.requestData(nsDb::DBTables::DIGITS);

  auto [resEn, dataEn] = m_processor.requestData(nsDb::DBTables::EN_ALPHABET);

  auto [resRus, dataRus] =
    m_processor.requestData(nsDb::DBTables::RUS_ALPHABET);

  auto [resPunctuation, dataPunctuation] =
    m_processor.requestData(nsDb::DBTables::PUNCTUATION);

  QVERIFY2(resDigits == nsDb::DBResult::OK, "Request digits false.");
  QVERIFY2(dataDigits.empty() == false, "Data digits is empty");

  QVERIFY2(resEn == nsDb::DBResult::OK, "Request enAlphabet false.");
  QVERIFY2(dataEn.empty() == false, "Data en alphabet is empty");

  QVERIFY2(resRus == nsDb::DBResult::OK, "Request rusAlphabet false.");
  QVERIFY2(dataRus.empty() == false, "Data rus alphabet is empty");

  QVERIFY2(resPunctuation == nsDb::DBResult::OK, "Request punctuation false.");
  QVERIFY2(dataPunctuation.empty() == false,
           "Data punctuation alphabet is empty");
}

QTEST_APPLESS_MAIN(TestDBManager)
