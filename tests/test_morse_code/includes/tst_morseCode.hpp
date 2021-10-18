#ifndef TST_MORSECODE_HPP
#define TST_MORSECODE_HPP

#include "morsecodeinternational.hpp"
#include <QtTest>

class TestMorseCode : public QObject
{

  Q_OBJECT

public:
  TestMorseCode();
  ~TestMorseCode();

private slots:
  void test_en();
  void test_ru();
  void test_ruText();
  void test_decrtyptEn();

private:
  MorseCodeInternational m_app;
};

#endif // TST_MORSECODE_HPP
