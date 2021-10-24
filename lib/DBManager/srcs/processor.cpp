/* processor.cpp */

#include "processor.hpp"

#include "selector.hpp"

namespace nsDb {

struct Processor::ProcessorPrivate
{
  Selector selector;
};

Processor::Processor()
  : m_db(std::make_unique<ProcessorPrivate>())
{
  // ctor
}

QPair<DBResult, QVector<QVariantList>>
Processor::requestData(nsDb::DBTables typeTable_)
{
  switch (typeTable_) {
    case DBTables::DIGITS:
      return m_db->selector.digits();
    case DBTables::EN_ALPHABET:
      return m_db->selector.enAlphabet();
    case DBTables::PUNCTUATION:
      return m_db->selector.punctuation();
    case DBTables::RUS_ALPHABET:
      return m_db->selector.rusAlphabet();
    default:
      qCritical() << "Request FALSE";
      return {};
  };

  return {};
}

Processor::~Processor()
{
  // dtor
}

}
