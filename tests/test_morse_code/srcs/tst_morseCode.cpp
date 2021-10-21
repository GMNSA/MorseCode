#include "tst_morseCode.hpp"

TestMorseCode::TestMorseCode() {}

TestMorseCode::~TestMorseCode() {}

void
TestMorseCode::test_en()
{

  QString encrypt(m_app.encryption("a"));
  QVERIFY2(encrypt == ".-", "a != '.-'");

  QVERIFY2(m_app.encryption("b") == "-...", "'B' not valid.");
  QVERIFY2(m_app.encryption("I") == "..", "'I' not valid.");
  encrypt = m_app.encryption("deca");
  QVERIFY2(encrypt == "-.. . -.-. .-", "'deca' is not valid.");

  QVERIFY2(m_app.encryption("c") == "-.-.", "'c' not valid.");
  QVERIFY2(m_app.encryption("g") == "--.", "'g' not valid.");
  QVERIFY2(m_app.encryption("l k") == ".-.. | -.-", "'l k' not valid.");

  QVERIFY2(m_app.encryption("o p r") == "--- | .--. | .-.",
           "'o p r' not valid.");
  QVERIFY2(m_app.encryption("x y z") == "-..- | -.-- | --..",
           "'x y z' not valid.");
}

void
TestMorseCode::test_ru()
{
  QVERIFY2(m_app.encryption("а") == ".-", "'а' not valid.");
  QVERIFY2(m_app.encryption("б") == "-...", "'б' not valid.");

  QVERIFY2(m_app.encryption("с") == "...", "'c' not valid.");
  QVERIFY2(m_app.encryption("р") == ".-.", "'р' not valid.");
  QVERIFY2(m_app.encryption("м") == "--", "'m' not valid.");

  QVERIFY2(m_app.encryption("о р") == "--- | .-.", "'o p' not valid.");
}

void
TestMorseCode::test_ruText()
{
  QString encryptText{
    ".-.- | ... . --. --- -.. -. .-.- | -... -.-- .-.. | .-- | -- "
    ".- --. .- --.. .. -. . --..-- --..-- --..--"
  };
  QString origText = m_app.encryption("Я сегодня был в магазине,,,");
  qDebug() << "ncrypt: " << encryptText;
  QVERIFY2(origText == encryptText, "text' not valid.");
}

void
TestMorseCode::test_decrtyptEn()
{
  // piter pan
  // qDebug() << m_app.decryptionToEn(".--. .. - . .-.     .--. .- -.");
}

QTEST_APPLESS_MAIN(TestMorseCode)
