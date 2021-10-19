#ifndef TST_MORSECODE_HPP
#define TST_MORSECODE_HPP

#include "connectmanager.hpp"

#include <QtTest>

class TestDBManager : public QObject
{

  Q_OBJECT

public:
  TestDBManager();
  ~TestDBManager();

private slots:
  void test_connectManager();

private:
  nsDb::ConnectManager& m_connectManager;
};

#endif // TST_MORSECODE_HPP
