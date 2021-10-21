/* morsecodeinternational.hpp */

#ifndef MORSECODEINTERNATIONAL_HPP
#define MORSECODEINTERNATIONAL_HPP

#include <QObject>

class MorseCodeInternational
{
public:
  MorseCodeInternational();
  virtual ~MorseCodeInternational();

  QString encryption(QString const text_);
  QString decryptionToEn(QString const text_);
  void clearData();
  QString test() const { return ("TEST"); };

  QString lastOriginalCode() const { return (m_lastOrigText); }
  void setNLimitText(int limit_);

protected:
private:
  QString m_lastOrigText;
  QString m_lastOrigTextEncrypt;
  int m_nLimitText;

private:
  QString joinText(QStringList text_);
  QStringList decodProcess(QStringList text_,
                           QMap<QString, QString> codeProcess_);
  void encryptData(QStringList& text_, QMap<QString, QString> data_);
  QStringList splitText(QString const& text_);
};
#endif // MORSECODEINTERNATIONAL_HPP
