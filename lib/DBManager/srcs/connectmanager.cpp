/* connectmanager.cpp */

#include "connectmanager.hpp"

#include <QDir>
#include <QFile>
#include <QSqlDatabase>
#include <QStandardPaths>
#include <QUrl>

namespace nsDb {

namespace {
struct DBRemove
{
  void operator()(QSqlDatabase* db_)
  {
    db_->close();
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
    delete db_;
  }
};
}

struct ConnectManager::ConnectManagerPrivate
{
  std::unique_ptr<QSqlDatabase> database;
  bool isValid{ false };
  DBState state{ DBState::OK };
  QString dbFullPath;

  bool setup();
  bool setupWorkspace();
  bool setupDatabase();
  bool setupTables();
};

/*          ***** ***** ***** *****          */

ConnectManager::ConnectManager()
  : m_db(std::make_unique<ConnectManagerPrivate>())
{
  m_db->isValid = m_db->setup();
}

bool
ConnectManager::isValid() const
{
  return (m_db->isValid);
}

QString
ConnectManager::state()
{
  switch (m_db->state) {
    case DBState::OK:
      return ("OK");
    case DBState::ERROR_DRIVER:
      return ("DRIVER ERROR");
    case DBState::ERROR_WORKSPACE:
      return ("WORKSPACE ERROR.");
    case DBState::ERROR_OPEN:
      return ("OPEN ERROR.");
    case DBState::ERROR_TABLES:
      return ("TABLES ERROR");
    case DBState::ERROR_COPY_DATABASE:
      return ("COPY DATABASE");
    default:
      return {};
  }
}

ConnectManager::~ConnectManager()
{
  // dtor
}

ConnectManager&
ConnectManager::instance()
{
  static ConnectManager inst;

  return (inst);
}

bool
ConnectManager::ConnectManagerPrivate::setup()
{
  QString driver{ nsDb::gDBDrivers["sqlite"] };

  if (!QSqlDatabase::isDriverAvailable(driver)) {
    state = nsDb::DBState::ERROR_DRIVER;
    qCritical() << "Error Driver";
    return (false);
  }

  if (!setupWorkspace()) {
    state = nsDb::DBState::ERROR_WORKSPACE;
    qCritical() << "Error Workspace";
    return (false);
  }

  if (!setupDatabase()) {
    state = nsDb::DBState::ERROR_COPY_DATABASE;
    qCritical() << "Error COPY Database";
    return (false);
  }

  database.reset(new QSqlDatabase{ QSqlDatabase::addDatabase(driver) });
  database->setDatabaseName(dbFullPath);

  if (!database->open()) {
    state = DBState::ERROR_OPEN;
    qCritical() << "Err0R: Database didn't open !";
    return (false);
  }

  if (!setupTables()) {
    state = nsDb::DBState::ERROR_TABLES;
    qCritical() << "Error Tables";
    return (false);
  }
  qDebug() << "dbpath: " << dbFullPath;

  return (true);
}

bool
ConnectManager::ConnectManagerPrivate::setupWorkspace()
{
  QString dirName{ "MorseDB" };
  QString name{ "morse.db" };

  auto dbPath =
    QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/" +
    dirName;

  qDebug() << "<< ----------- dbPath: " << dbPath;

  QDir dir(dbPath);

  if (!dir.exists()) {
    auto result = dir.mkdir(dbPath);

    qInfo() << "Creating dir to database. [" << result << "]";
  }
  dbFullPath = dbPath + "/" + name;

  qDebug() << "<< ----------- dbFullPath: " << dbFullPath;

  return (dir.exists());
}

bool
ConnectManager::ConnectManagerPrivate::setupDatabase()
{
  QFile file(dbFullPath);

  bool result{ true };

  if (!file.exists()) {
    result = QFile::copy(":/morse.db", dbFullPath);

    if (result)
      qInfo() << "The Database was copied [...] to " << dbFullPath;
  }

  file.close();

  return (result);
}

bool
ConnectManager::ConnectManagerPrivate::setupTables()
{
  return (true);
}

}
