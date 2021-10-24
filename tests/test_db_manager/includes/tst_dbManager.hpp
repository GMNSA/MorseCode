#ifndef TST_MORSECODE_HPP
#define TST_MORSECODE_HPP

#include "connectmanager.hpp"
#include "executor.hpp"
#include "processor.hpp"
#include "selector.hpp"

#include <QtTest>

class TestDBManager : public QObject
{

  Q_OBJECT

public:
  TestDBManager();
  ~TestDBManager();

private slots:
  void test_connectManager();

  void test_executor();

  void test_selector();

  void test_processor();

private:
  nsDb::ConnectManager& m_connectManager;
  nsDb::Executor m_executor;
  nsDb::Selector m_selector;
  nsDb::Processor m_processor;
};

#endif // TST_MORSECODE_HPP
