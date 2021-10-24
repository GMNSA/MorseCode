/* selector.cpp */

#include "selector.hpp"
#include <QSqlRecord>

namespace nsDb {

Selector::Selector()
  : m_executor(std::make_unique<Executor>())
{
  // ctor
}

QPair<DBResult, QVector<QVariantList>>
Selector::punctuation(const QString& tablename_)
{
  Q_UNUSED(tablename_);
  QVector<QVariantList> returnData;

  QVariantList temp;

  QString request{ " SELECT " + nsDb::gDBaseArgs["punctuation"] + "  FROM " +
                   tablename_ };

  auto [result, data] = m_executor->executor(request);

  if (result == nsDb::DBResult::OK) {
    auto nRecords{ data.record().count() };
    while (data.next()) {
      temp.clear();
      for (int i{ 0 }; i < nRecords; ++i) {
        temp.push_back(data.record().value(i));
      }
      returnData.push_back(temp);
    }
  }

  return { result, returnData };
}

/*          ***** ***** ***** *****          */

QPair<DBResult, QVector<QVariantList>>
Selector::digits(const QString& tablename_)
{
  Q_UNUSED(tablename_);
  QVector<QVariantList> returnData;

  QVariantList temp;

  QString request{ " SELECT " + nsDb::gDBaseArgs["digits"] + "  FROM " +
                   tablename_ };

  auto [result, data] = m_executor->executor(request);

  if (result == nsDb::DBResult::OK) {
    auto nRecords{ data.record().count() };
    while (data.next()) {
      temp.clear();
      for (int i{ 0 }; i < nRecords; ++i) {
        temp.push_back(data.record().value(i));
      }
      returnData.push_back(temp);
    }
  }

  return { result, returnData };
}

/*          ***** ***** ***** *****          */

QPair<DBResult, QVector<QVariantList>>
Selector::rusAlphabet(const QString& tablename_)
{
  Q_UNUSED(tablename_);
  QVector<QVariantList> returnData;

  QVariantList temp;

  QString request{ " SELECT " + nsDb::gDBaseArgs["rusalphabet"] + "  FROM " +
                   tablename_ };

  auto [result, data] = m_executor->executor(request);

  if (result == nsDb::DBResult::OK) {
    auto nRecords{ data.record().count() };
    while (data.next()) {
      temp.clear();
      for (int i{ 0 }; i < nRecords; ++i) {
        temp.push_back(data.record().value(i));
      }
      returnData.push_back(temp);
    }
  }

  return { result, returnData };
}

/*          ***** ***** ***** *****          */

QPair<DBResult, QVector<QVariantList>>
Selector::enAlphabet(const QString& tablename_)
{
  Q_UNUSED(tablename_);
  QVector<QVariantList> returnData;

  QVariantList temp;

  QString request{ " SELECT " + nsDb::gDBaseArgs["enalphabet"] + "  FROM " +
                   tablename_ };

  auto [result, data] = m_executor->executor(request);

  if (result == nsDb::DBResult::OK) {
    auto nRecords{ data.record().count() };
    while (data.next()) {
      temp.clear();
      for (int i{ 0 }; i < nRecords; ++i) {
        temp.push_back(data.record().value(i));
      }
      returnData.push_back(temp);
    }
  }

  return { result, returnData };
}

Selector::~Selector()
{
  // dtor
}

}
