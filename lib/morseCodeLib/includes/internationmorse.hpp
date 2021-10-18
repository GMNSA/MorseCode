#ifndef INTERNATIONMORSE_HPP
#define INTERNATIONMORSE_HPP

#include <QMap>

QMap<QString, QString> const lettersRu{
  { "А", ".- " },   { "Б", "-... " },  { "В", ".-- " },    { "Г", "--. " },
  { "Д", "-.. " },  { "Е", ". " },     { "Ж", "...- " },   { "З", "--.. " },
  { "И", ".. " },   { "Й", ".--- " },  { "К", "-.- " },    { "Л", ".-.. " },
  { "М", "-- " },   { "Н", "-. " },    { "О", "--- " },    { "П", ".--. " },
  { "Р", ".-. " },  { "С", "... " },   { "Т", "- " },      { "У", "..- " },
  { "Ф", "..-. " }, { "Х", ".... " },  { "Ц", "-.-. " },   { "Ч", "---. " },
  { "Ш", "---- " }, { "Щ", "--.- " },  { "Ъ", ".--.-. " }, { "Ы", "-.-- " },
  { "Ь", "-..- " }, { "Э", "..-.. " }, { "Ю", "..-- " },   { "Я", ".-.- " },
};

QMap<QString, QString> const lettersEn{
  { "A", ".- " },   { "B", "-... " }, { "C", "-.-. " }, { "D", "-.. " },
  { "E", ". " },    { "F", "..-. " }, { "G", "--. " },  { "H", ".... " },
  { "I", ".. " },   { "J", ".--- " }, { "K", "-.- " },  { "L", ".-.. " },
  { "M", "-- " },   { "N", "-. " },   { "O", "--- " },  { "P", ".--. " },
  { "Q", "--.- " }, { "R", ".-. " },  { "S", "... " },  { "T", "- " },
  { "U", "..- " },  { "V", "...- " }, { "W", ".-- " },  { "X", "-..- " },
  { "Y", "-.-- " }, { "Z", "--.. " },
};

QMap<QString, QString> const lettersDigit{
  { "0", "----- " }, { "1", ".---- " }, { "2", "..--- " }, { "3", "...--" },
  { "4", "....- " }, { "5", "..... " }, { "6", "-.... " }, { "7", "--..." },
  { "8", "---.." },  { "9", "----." },
};

QMap<QString, QString> const letterPunctuation{
  { " ", "    " },    { ")", "-.--.- " }, { "(", "-.--. " },
  { ".", ".-.-.- " }, { ",", "--..-- " }, { "+", ".-.-. " },
  { "-", "-....-" },  { "?", "..--.. " }, { "//", "-..-. " }
};

// -------------------------------------------------------------------------
QMap<QString, QString> const codeToLetterEn{

  { ".- ", "A" },   { "-... ", "B" }, { "-.-. ", "C" }, { "-.. ", "D" },
  { ". ", "E" },    { "..-. ", "F" }, { "--. ", "G" },  { ".... ", "H" },
  { ".. ", "I" },   { ".--- ", "J" }, { "-.- ", "K" },  { ".-.. ", "L" },
  { "-- ", "M" },   { "-. ", "N" },   { "--- ", "O" },  { ".--. ", "P" },
  { "--.- ", "Q" }, { ".-. ", "R" },  { "... ", "S" },  { "- ", "T" },
  { "..- ", "U" },  { "...- ", "V" }, { ".-- ", "W" },  { "-..- ", "X" },
  { "-.-- ", "Y" }, { "--.. ", "Z" },
};

QMap<QString, QString> const codeToLetterRu{
  { ".- ", "A" },   { "-... ", "B" }, { "-.-. ", "C" }, { "-.. ", "D" },
  { ". ", "E" },    { "..-. ", "F" }, { "--. ", "G" },  { ".... ", "H" },
  { ".. ", "I" },   { ".--- ", "J" }, { "-.- ", "K" },  { ".-.. ", "L" },
  { "-- ", "M" },   { "-. ", "N" },   { "--- ", "O" },  { ".--. ", "P" },
  { "--.- ", "Q" }, { ".-. ", "R" },  { "... ", "S" },  { "- ", "T" },
  { "..- ", "U" },  { "...- ", "V" }, { ".-- ", "W" },  { "-..- ", "X" },
  { "-.-- ", "Y" }, { "--.. ", "Z" },
};

QMap<QString, QString> const codeToDigit{
  { "----- ", "0" }, { ".---- ", "1" }, { "..--- ", "2" }, { "...--", "3" },
  { "....- ", "4" }, { "..... ", "5" }, { "-.... ", "6" }, { "--...", "7" },
  { "---..", "8" },  { "----.", "9" },
};

QMap<QString, QString> const codeToPunctuation{
  { "    ", " " },    { "-.--.- ", ")" }, { "-.--. ", "(" },
  { ".-.-.- ", "." }, { "--..-- ", "," }, { ".-.-. ", "+" },
  { "-....-", "-" },  { "..--.. ", "?" }, { "-..-. ", "//" }
};

#endif // filename
