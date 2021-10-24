/* morsecodeinternational.hpp */

#ifndef MORSECODEINTERNATIONAL_HPP
#define MORSECODEINTERNATIONAL_HPP

#include "processor.hpp"
#include <QObject>
#include <memory>

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
  std::unique_ptr<nsDb::Processor> m_processor;
  QString m_lastOrigText;
  QString m_lastOrigTextEncrypt;
  int m_nLimitText;

  QMap<QString, QString> m_letterPunctuation;
  QMap<QString, QString> m_lettersDigit;
  QMap<QString, QString> m_lettersEn;
  QMap<QString, QString> m_lettersRu;

private:
  QString joinText(QStringList text_);
  QStringList decodProcess(QStringList text_,
                           QMap<QString, QString> codeProcess_);
  void encryptData(QStringList& text_, QMap<QString, QString> data_);
  QStringList splitText(QString const& text_);

#ifdef FOR_TEST
public:
#endif
  QMap<QString, QString> convertingDataForTwoData(
    QPair<nsDb::DBResult, QVector<QVariantList>> data_);
};
#endif // MORSECODEINTERNATIONAL_HPP
