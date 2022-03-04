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

Fraction::Fraction(int numerator, int denominator = 1) {
    this -> numerator = numerator;
    this -> denominator = denominator;
}

Fraction::Fraction() : numerator{0}, denominator{1} { }

void Fraction::setNumerator(int newNumerator) {
    numerator = newNumerator;
}

void Fraction::setDenominator(int newDenominator) {
    denominator = newDenominator;
}

int Fraction::getNumerator() const {
    return this -> numerator;
}

int Fraction::getDenominator() const {
    return this -> denominator;
}

void Fraction::print() const {
    //    std::printf("%d/%d", numerator, denominator);
    cout << numerator << "/" << denominator << endl;
}

Fraction::~Fraction() {
    removedFractions_++;
}
int Fraction::removedFractions() {
    return removedFractions_;
}

void Fraction::save(std::ostream &os) const {
    os << numerator << "/" << denominator;
}
void Fraction::load(std::istream &is) {
    is >> numerator >> denominator;
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


