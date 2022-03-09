#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

#include "fraction.h"

#if IMPLEMENTED_classFractionExists
#ifndef _MSC_FULL_VER // if not Visual Studio Compiler

int Fraction::removedFractions_ = 0;
int Fraction::invalidDenominatorValue = 0;
int Fraction::defaultDenominatorValue = 1;

// g++  --std=c++17 -x c++ -Wall -Wextra -Wpedantic -Weffc++ -g -rdynamic -pipe -frecord-gcc-switches fraction.cpp main.cpp

Fraction::Fraction() : numerator(0), denominator(0) { }

Fraction::Fraction(int numerator, int denominator = defaultDenominatorValue) : numerator(numerator), denominator(denominator) {
//    this -> numerator = numerator;
//    this -> denominator = denominator;
}

Fraction::Fraction(int numerator, int denominator = defaultDenominatorValue, std::string fractionName = "noname") : numerator(numerator), denominator(denominator), fractionName(fractionName) {
//    this -> numerator = numerator;
//    this -> denominator = denominator;
//    this -> fractionName = fractionName;
}



Fraction::~Fraction() {
    removedFractions_++;
}
int Fraction::removedFractions() {
    return removedFractions_;
}

void Fraction::setNumerator(int newNumerator) {
    numerator = newNumerator;
}

void Fraction::setDenominator(int newDenominator) {
    denominator = newDenominator;
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::print() const {
    //    std::printf("%d/%d", numerator, denominator);
    cout << numerator << "/" << denominator << endl;
}



void Fraction::save(std::ostream &os) const {
    os << numerator << "/" << denominator;
}
void Fraction::load(std::istream &is) {
//    https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
//    https://www.freecodecamp.org/news/string-to-int-in-c-how-to-convert-a-string-to-an-integer-example/

    std::string str;
    std::string delimiter = "/";
    is >> str;

    numerator = std::stoi(str.substr(0, str.find(delimiter)));
    str.erase(0,str.find(delimiter) + delimiter.length());
    denominator = std::stoi(str);
}

std::string Fraction::getFractionName() const {
    return this -> fractionName;
}

int Fraction::getInvalidDenominatorValue() {
    return invalidDenominatorValue;
}

int Fraction::getDefaultDenominatorValue() {
    return defaultDenominatorValue;
}





//    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif
#endif // IMPLEMENTED_classFractionExists


