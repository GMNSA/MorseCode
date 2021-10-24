/* morsecodeinternational.cpp */

#include "morsecodeinternational.hpp"
#include "internationmorse.hpp"
#include <QDebug>

MorseCodeInternational::MorseCodeInternational()
  : m_processor(std::make_unique<nsDb::Processor>())
  , m_nLimitText(200)
  , m_letterPunctuation(convertingDataForTwoData(
      m_processor->requestData(nsDb::DBTables::PUNCTUATION)))
  , m_lettersDigit(convertingDataForTwoData(
      m_processor->requestData(nsDb::DBTables::DIGITS)))
  , m_lettersEn(convertingDataForTwoData(
      m_processor->requestData(nsDb::DBTables::EN_ALPHABET)))
  , m_lettersRu(convertingDataForTwoData(
      m_processor->requestData(nsDb::DBTables::RUS_ALPHABET)))
{
  // ctor
}

/*          ***** ***** ***** *****          */

MorseCodeInternational::~MorseCodeInternational()
{
  // dtor
}

/*          ***** ***** ***** *****          */

/**
 * @brief MorseCodeInternational::encryption
 *        (Encrypt get Data to MorseCode)
 * @param _text -> The Text that we will encrypt.
 * @return -> (QString) Encrypted Data.
 */

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

  auto text{ splitText(tmpText) };

  encryptData(text, m_letterPunctuation);
  encryptData(text, m_lettersDigit);
  encryptData(text, m_lettersEn);
  encryptData(text, m_lettersRu);

  tmpText = text.join(" ");

  qDebug() << "ALL RESULT: " << tmpText;
  return (tmpText);
}

/*          ***** ***** ***** *****          */

QString
MorseCodeInternational::decryptionToEn(const QString text_)
{
  Q_UNUSED(text_);
  // QString tmpText = text_;
  // qDebug() << "PSSS: " << tmpText;

  // if (tmpText.isEmpty())
  //   return {};

  // // if (tmpText.size() > m_nLimitText) {
  // //   tmpText = tmpText.left(m_nLimitText);
  // // }

  // m_lastOrigTextEncrypt = tmpText;

  // auto splitText{ text_.split(" ") };

  // splitText = decodProcess(splitText, codeToLetterEn);

  // tmpText = joinText(splitText);

  // qDebug() << "DECRYPT EN RESULT: " << tmpText;
  // return (tmpText);
  return {};
}

/*          ***** ***** ***** *****          */

void
MorseCodeInternational::clearData()
{
  m_lastOrigText.clear();
}

/*          ***** ***** ***** *****          */

void
MorseCodeInternational::setNLimitText(int limit_)
{
  m_nLimitText = limit_;
}

/*          ***** ***** ***** *****          */

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

/*          ***** ***** ***** *****          */

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

/*          ***** ***** ***** *****          */

/**
 * @brief MorseCodeInternational::encryptData
 *        ( encrypt the data in the morse code )
 * @param text_ -> (QStringList &) The Data that we wiil encrypt.
 * @param data_ -> (Morse Code)
 */
void
MorseCodeInternational::encryptData(QStringList& text_,
                                    QMap<QString, QString> data_)
{
  auto iterator{ data_.begin() };
  auto iteratorEnd{ data_.end() };

  for (auto& i : text_) {
    iterator = { data_.begin() };
    for (; iterator != iteratorEnd; ++iterator) {
      if (i == iterator.key())
        i = iterator.value();
    }
  }
}

/*          ***** ***** ***** *****          */

/**
 * @brief MorseCodeInternational::splitText
 *          (Splits Letter into spaces, words into '|' )
 * @param text_ -> (QString const &) The Data that we will split.
 * @return -> QStringList
 */
QStringList
MorseCodeInternational::splitText(const QString& text_)
{
  QStringList temp;
  QString tmpText{ text_ };

  qDebug() << "origin: " << text_;

  bool isSpace{ false };
  tmpText = tmpText.replace("|", " ");

  for (auto& i : text_) {
    if (i == ' ') {
      isSpace = true;
      temp.push_back("|");
    } else if (isSpace && i == ' ') {
      continue;
    } else if (isSpace) {
      temp.push_back(i);
      isSpace = false;
    } else {
      temp.push_back(i);
    }
  }

  return (temp);
}

/*          ***** ***** ***** *****          */

QMap<QString, QString>
MorseCodeInternational::convertingDataForTwoData(
  QPair<nsDb::DBResult, QVector<QVariantList>> data_)
{
  Q_UNUSED(data_);

  if (data_.first == nsDb::DBResult::FALSE) {
    qCritical() << "convertingDataForTwoData: GET RESULT [FALSE]";
    return {};
  }

  QMap<QString, QString> returnData;
  int nData{ 0 };

  for (auto& list : data_.second) {
    nData = list.size();
    if (nData == 2) {
      returnData[list.at(0).toString()] = list.at(1).toString();
    }
  }

  return { returnData };
}
