/* executor.hpp */

#ifndef EXECUTOR_HPP
#define EXECUTOR_HPP

#include "connectmanager.hpp"
#include <QSqlQuery>

namespace nsDb {

class Executor
{
public:
  Executor();
  virtual ~Executor();

  Executor(Executor const&) = delete;
  Executor& operator=(Executor const&) = delete;

  QPair<DBResult, QSqlQuery> executor(QString const& queryText_,
                                      QVariantList const& args_ = {});

private:
  ConnectManager& m_connectManager;
};

}

#endif // EXECUTOR_HPP
