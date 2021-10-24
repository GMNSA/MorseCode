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
  ERROR_TABLES,
  ERROR_COPY_DATABASE
};

enum class DBTables
{
  EN_ALPHABET = 0,
  RUS_ALPHABET,
  DIGITS,
  PUNCTUATION
};

static QMap<QString, QString> gDBaseArgs{ { "enalphabet", "letter, code" },
                                          { "rusalphabet", "letter, code" },
                                          { "digits", "number, code" },
                                          { "punctuation", "letter, code" } };
}

#endif // DB_TYPE_HPP
