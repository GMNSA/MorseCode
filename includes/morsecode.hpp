/* morsecode.hpp */

#ifndef MORSECODE_HPP
#define MORSECODE_HPP

#include "morsecodeinternational.hpp"
#include <QObject>

class MorseCode : public QObject
{
  Q_OBJECT
public:
  MorseCode(int limit = 200, QObject* parent = nullptr);
  virtual ~MorseCode();

  Q_INVOKABLE QString encryption(QString const text_);
  Q_INVOKABLE void clearData();
  QString test() const { return ("TEST"); };

  Q_INVOKABLE QString lastOriginalCode() const;
signals:

public slots:

protected:
private:
  MorseCodeInternational m_morseCode;
};
#endif // MORSECODE_HPP
