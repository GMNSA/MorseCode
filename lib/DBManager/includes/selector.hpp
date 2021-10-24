/* selector.hpp */

#ifndef SELECTOR_HPP
#define SELECTOR_HPP

#include "executor.hpp"
#include <memory>

namespace nsDb {

class Selector
{
public:
  Selector();
  virtual ~Selector();

  Selector(Selector const&) = delete;
  Selector& operator=(Selector const&) = delete;

  QPair<DBResult, QVector<QVariantList>> punctuation(
    QString const& tablename_ = "punctuation");

  QPair<DBResult, QVector<QVariantList>> digits(
    QString const& tablename_ = "digits");

  QPair<DBResult, QVector<QVariantList>> rusAlphabet(
    QString const& tablename_ = "rusalphabet");

  QPair<DBResult, QVector<QVariantList>> enAlphabet(
    QString const& tablename_ = "enalphabet");

private:
  std::unique_ptr<Executor> m_executor;
};

}

#endif // SELECTOR_HPP
