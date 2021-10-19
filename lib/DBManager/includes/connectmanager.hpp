/* connectmanager.hpp */

#ifndef CONNECTMANAGER_HPP
#define CONNECTMANAGER_HPP

#include "dbtype.hpp"
#include <QDebug>
#include <memory>

namespace nsDb {

class ConnectManager
{
public:
  virtual ~ConnectManager();
  static ConnectManager& instance();

  bool isValid() const;
  QString state();

private:
  ConnectManager();
  ConnectManager(ConnectManager const&) = delete;
  ConnectManager& operator=(ConnectManager const&) = delete;

private:
  struct ConnectManagerPrivate;
  std::unique_ptr<ConnectManagerPrivate> m_db;
};

}

#endif // CONNECTMANAGER_HPP
