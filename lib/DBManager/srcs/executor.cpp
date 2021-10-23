/* executor.cpp */

#include "executor.hpp"
#include <QSqlError>

namespace nsDb {

Executor::Executor()
  : m_connectManager(ConnectManager::instance())
{
  // ctor
}

/**
 * @brief Executor::executor
 *        ()
 * @param queryText_
 * @param args_
 * @return
 */
QPair<DBResult, QSqlQuery>
Executor::executor(const QString& queryText_, const QVariantList& args_)
{
  qDebug() << "STATE: " << m_connectManager.state();
  if (!m_connectManager.isValid()) {
    qCritical("Database is not valid!");
    return { DBResult::FALSE, QSqlQuery{} };
  }

  QSqlQuery query{ queryText_ };
  qintptr nArgs{ args_.size() };
  DBResult isResult{ DBResult::OK };

  for (auto i{ 0 }; i < nArgs; ++i) {
    query.bindValue(i, args_.at(i));
  }

  if (!query.exec()) {
    qCritical() << "\nErr0r: " << query.lastError().text()
                << "\nQuery: " << query.lastQuery();
    isResult = DBResult::FALSE;
  }

  return { isResult, query };
}

Executor::~Executor()
{
  // dtor
}

}
