#ifndef DB_TYPE_HPP
#define DB_TYPE_HPP

#include <QMap>
#include <QString>

namespace nsDb {
static QMap<QString, QString> gDBDrivers{ { "sqlite", "QSQLITE" } };

enum class DBResult
{
  OK = 0,
  FALSE
};

enum class DBState
{
  OK = 0,
  ERROR_DRIVER,
  ERROR_WORKSPACE,
  ERROR_OPEN,
  ERROR_TABLES
};

static QMap<QString, QString> gDBContactsArgs{ { "Contacts",
                                                 "name, surname, phone" } };
}

#endif // DB_TYPE_HPP
