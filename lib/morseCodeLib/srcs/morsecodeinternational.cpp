/* morsecodeinternational.cpp */

#include "morsecodeinternational.hpp"
#include "internationmorse.hpp"
#include <QDebug>

MorseCodeInternational::MorseCodeInternational()
  : m_nLimitText(200)
{
  // ctor
}

MorseCodeInternational::~MorseCodeInternational()
{
  // dtor
}

QString
MorseCodeInternational::encryption(QString const _text)
{
  QString tmpText = _text.trimmed();

  tmpText = tmpText.replace(" ", "");

  if (tmpText.isEmpty())
    return {};
  else
    tmpText = _text.trimmed();

  if (tmpText.size() > m_nLimitText) {
    tmpText = tmpText.left(m_nLimitText);
  }

  m_lastOrigText =
    tmpText + "\n\n[limit symbols: " + QString::number(m_nLimitText) + "]\n";

  tmpText = (tmpText.toUpper());

  auto punctuationIter{ letterPunctuation.begin() };
  auto punctuationIterEnd{ letterPunctuation.end() };

  for (; punctuationIter != punctuationIterEnd; ++punctuationIter) {
    tmpText.replace(punctuationIter.key(), punctuationIter.value());
  }

  auto digitIter{ lettersDigit.begin() };
  auto digitIterEnd{ lettersDigit.end() };

  for (; digitIter != digitIterEnd; ++digitIter) {
    tmpText.replace(digitIter.key(), digitIter.value());
  }

  auto enIter{ lettersEn.begin() };
  auto enIterEnd{ lettersEn.end() };

  for (; enIter != enIterEnd; ++enIter) {
    tmpText.replace(enIter.key(), enIter.value());
  }

  auto ruIter{ lettersRu.begin() };
  auto ruIterEnd{ lettersRu.end() };

  for (; ruIter != ruIterEnd; ++ruIter) {
    tmpText.replace(ruIter.key(), ruIter.value());
  }

  qDebug() << "RESULT: " << tmpText;
  return (tmpText);
}

QString
MorseCodeInternational::decryptionToEn(const QString text_)
{
  QString tmpText = text_;
  qDebug() << "PSSS: " << tmpText;

  if (tmpText.isEmpty())
    return {};

  // if (tmpText.size() > m_nLimitText) {
  //   tmpText = tmpText.left(m_nLimitText);
  // }

  m_lastOrigTextEncrypt = tmpText;

  auto splitText{ text_.split(" ") };

  splitText = decodProcess(splitText, codeToLetterEn);

  tmpText = joinText(splitText);

  qDebug() << "RESULT: " << tmpText;
  return (tmpText);
}

void
MorseCodeInternational::clearData()
{
  m_lastOrigText.clear();
}

void
MorseCodeInternational::setNLimitText(int limit_)
{
  m_nLimitText = limit_;
}

QString
MorseCodeInternational::joinText(QStringList text_)
{
  bool space{ false };
  QString result;

  for (auto& l : text_) {
    if (l == "" && !space) {
      space = true;
      result += " ";
    } else
      result += l;
  }

  return (result);
}

QStringList
MorseCodeInternational::decodProcess(QStringList splitText,
                                     QMap<QString, QString> codeProcess_)
{
  auto beginIter{ codeProcess_.begin() };
  auto endIter{ codeProcess_.end() };

  for (auto& l : splitText) {
    beginIter = codeProcess_.begin();
    for (; beginIter != endIter; ++beginIter) {
      if ((l + " ") == beginIter.key()) {
        l = beginIter.value();
        break;
      }
    }
  }
  return (splitText);
}
