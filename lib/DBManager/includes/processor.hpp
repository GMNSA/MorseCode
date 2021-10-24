/* processor.hpp */

#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include "dbtype.hpp"

#include <QPair>
#include <QVariantList>
#include <memory>

namespace nsDb {

class Processor
{
public:
  Processor();
  virtual ~Processor();

  Processor(Processor const&) = delete;
  Processor& operator=(Processor const&) = delete;

  QPair<DBResult, QVector<QVariantList>> requestData(nsDb::DBTables typeTable_);

private:
  struct ProcessorPrivate;
  std::unique_ptr<ProcessorPrivate> m_db;
};

}
#endif // PROCESSOR_HPP
