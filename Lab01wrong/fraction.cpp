#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

#include "fraction.h"

#if IMPLEMENTED_classFractionExists
#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
//int Fraction::removedFractions_ = 0;
//
Fraction::Fraction() : numerator{0}, denominator{1} { }
//
//Fraction::Fraction(int numerator, int denominator) {
//    this -> numerator = numerator;
//    this -> denominator = denominator;
//}

//Fraction::Fraction(std::string name) {
//    if (name.compare(halff)) {
//        this -> numerator = 1;
//        this -> denominator = 2;
//    }
//}

//Fraction::~Fraction() {
//    removedFractions_++;
//}
//
//void Fraction::setNumerator(int newNumerator) {
//    numerator = newNumerator;
//}
//
//void Fraction::setDenominator(int newDenominator) {
//    denominator = newDenominator;
//}
//
//int Fraction::getNumerator() {
//    return this -> numerator;
//}
//
//int Fraction::getDenominator() {
//    return this -> denominator;
//}
//
//void Fraction::print() {
////    std::printf("%d/%d", numerator, denominator);
//    cout << this -> numerator << "/" << this -> denominator << endl;
//    return;
//}
//
//int Fraction::removedFractions() {
//    return removedFractions_;
//}
//
//void Fraction::save(ostream &os) {
//    os << numerator << "/" << denominator;
//}
//
//void Fraction::load(istream &is) {
//    is >> numerator >> denominator;
//}
//    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif
#endif // IMPLEMENTED_classFractionExists










