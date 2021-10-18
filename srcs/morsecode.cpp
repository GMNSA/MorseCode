/* morsecode.cpp */

#include "morsecode.hpp"
#include "internationmorse.hpp"
#include <QDebug>

MorseCode::MorseCode(int limit_, QObject* parent)
  : QObject(parent)
{
  m_morseCode.setNLimitText(limit_);
}

MorseCode::~MorseCode()
{
  // dtor
}

QString
MorseCode::encryption(QString const text_)
{
  return (m_morseCode.encryption(text_));
}

void
MorseCode::clearData()
{
  m_morseCode.clearData();
}

QString
MorseCode::lastOriginalCode() const
{
  return (m_morseCode.lastOriginalCode());
}
