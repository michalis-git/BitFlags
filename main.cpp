#include <QCoreApplication>
#include <iostream>

// flags must be powers of 2!! (because for example binary 3 (0011) has ON both 1 and 2)
#define FIRST_FEATURE  0b1        // 00000001
#define SECOND_FEATURE 0b10       // 00000010
#define THIRD_FEATURE 0b10000000  // 10000000
// if all enabled:                   10000011

// e.g.:  10000011 (all)
//      & 00000001 (first)
//        00000001 -> !0
void readFlags(const unsigned int flags) {
  if (flags & FIRST_FEATURE)
    std::cout << "First feature is enabled.\n";
  if (flags & SECOND_FEATURE)
    std::cout << "Second feature is enabled.\n";
  if (flags & THIRD_FEATURE)
    std::cout << "Third feature is enabled.\n";
}

// e.g.:  00000001 (first)
//      | 00000010 (second)
//        00000011 -> 1st and 2nd are ON
void turnOnFlag(const std::string &flagName, unsigned int &flags) {
  if (!flagName.compare("FIRST_FEATURE"))
    flags = flags | FIRST_FEATURE;
  else if (!flagName.compare("SECOND_FEATURE"))
    flags = flags | SECOND_FEATURE;
  else if (!flagName.compare("THIRD_FEATURE"))
    flags = flags | THIRD_FEATURE;
  else
    std::cout << "Error: no such feature.\n";
}

// e.g.:  10000011 (all)
//     (~ 00000010 (second))
//      & 11111101
//        10000001 -> second is now OFF
void turnOffFlag(const std::string &flagName, unsigned int &flags) {
  std::cout << flagName << "\n";
  if (!flagName.compare("FIRST_FEATURE"))
    flags = flags & ~FIRST_FEATURE;
  else if (!flagName.compare("SECOND_FEATURE"))
    flags = flags & ~SECOND_FEATURE;
  else if (!flagName.compare("THIRD_FEATURE"))
    flags = flags & ~THIRD_FEATURE;
  else
    std::cout << "Error: no such feature\n";
}


int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  unsigned int flags = FIRST_FEATURE | SECOND_FEATURE | THIRD_FEATURE;

  readFlags(flags);

  while (true) {
    std::cout << "\nType the name of the feature that you want to enable/disable."
              << "\n(prepend \"+\" to turn on OR \"-\" to turn off)."
              << "\ne.g.: -SECOND_FEATURE"
              << "\nor type \"q\" to quit.\n";

    std::string word;
    std::cin >> word;

    if (word.rfind("-", 0) == 0) {
      word = word.substr(word.find("-") + 1, word.length());
      turnOffFlag(word, flags);
    } else if (word.rfind("+", 0) == 0) {
      word = word.substr(word.find("+") + 1, word.length());
      turnOnFlag(word, flags);
    } else {
      std::cout << "Error: you forgot to prepend + or -\n";
    }

    readFlags(flags);
  }

  return a.exec();
}


//SAME WITH QT

//#include <QCoreApplication>
//#include <iostream>
//#include <QDebug>
//#include <QIODevice>

//#define FIRST_FEATURE  0b1        // 00000001
//#define SECOND_FEATURE 0b10       // 00000010
//#define THIRD_FEATURE 0b10000000  // 10000000
//// if all enabled:                   10000011

//// e.g.:  10000011 (all)
////      & 00000001 (first)
////        00000001 -> !0
//void readFlags(const unsigned int flags) {
//  if (flags & FIRST_FEATURE)
//    qDebug() << "First feature is enabled.";
//  if (flags & SECOND_FEATURE)
//    qDebug() << "Second feature is enabled.";
//  if (flags & THIRD_FEATURE)
//    qDebug() << "Third feature is enabled.";
//}

//// e.g.:  00000001 (first)
////      | 00000010 (second)
////        00000011 -> 1st and 2nd are ON
//void turnOnFlag(const QString &flagName, unsigned int &flags) {
//  if (flagName == "FIRST_FEATURE")
//    flags = flags | FIRST_FEATURE;
//  else if (flagName == "SECOND_FEATURE")
//    flags = flags | SECOND_FEATURE;
//  else if (flagName == "THIRD_FEATURE")
//    flags = flags | THIRD_FEATURE;
//  else
//    qDebug() << "Error: no such feature";
//}

//// e.g.:  10000011 (all)
////     (~ 00000010 (second))
////      & 11111101
////        10000001 -> second is now OFF
//void turnOffFlag(const QString &flagName, unsigned int &flags) {
//  if (flagName == "FIRST_FEATURE")
//    flags = flags & ~FIRST_FEATURE;
//  else if (flagName == "SECOND_FEATURE")
//    flags = flags & ~SECOND_FEATURE;
//  else if (flagName == "THIRD_FEATURE")
//    flags = flags & ~THIRD_FEATURE;
//  else
//    qDebug() << "Error: no such feature";
//}


//int main(int argc, char *argv[]) {
//  QCoreApplication a(argc, argv);

//  unsigned int flags = FIRST_FEATURE | SECOND_FEATURE | THIRD_FEATURE;

//  readFlags(flags);

//  while (true) {
//    qDebug() << "\nType the name of the feature that you want to enable/disable.";
//    qDebug() << "(prepend \"+\" to turn on OR \"-\" to turn off).";
//    qDebug() << "e.g.: -SECOND_FEATURE";
//    qDebug() << "or type \"q\" to quit.";

//    QTextStream qtin(stdin);
//    QString word;
//    qtin >> word;

//    if (word.startsWith("-")) {
//      word = word.mid(word.indexOf("-") + 1);
//      turnOffFlag(word, flags);
//    } else if (word.startsWith("+")) {
//      word = word.mid(word.indexOf("+") + 1);
//      turnOnFlag(word, flags);
//    } else {
//      qDebug() << "Error: you forgot to prepend + or -";
//    }

//    readFlags(flags);
//  }

//  return a.exec();
//}
