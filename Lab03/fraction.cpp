#include <iostream>
#include <stdexcept> // std::out_of_range
#include <numeric> // std::gcd

#include "fraction.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
//    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif

Fraction::Fraction(int num, int den) : numerator_{num}, denenominator_{den} {if(den == 0) throw std::invalid_argument("Invalid denominator - why 0?");}

void Fraction::setNumerator(int num) {numerator_ = num;}

void Fraction::setDenominator(int den) {
    if(den == 0) throw std::invalid_argument("Invalid denominator - why 0?");
    else denenominator_ = den;
}

void Fraction::set(int num, int den) {
    setNumerator(num);
    setDenominator(den);
}

int Fraction::numerator() const {return numerator_;}

int Fraction::denominator() const {return denenominator_;}

Fraction Fraction::operator+(const Fraction &secondFraction) const {
    int newNumerator = numerator_ * secondFraction.denominator() + denenominator_ * secondFraction.numerator(), newDenominator = denenominator_ *
                                                                                                                                 secondFraction.denominator();

    int divisor = std::gcd(newNumerator, newDenominator);
    Fraction frac(newNumerator / divisor, newDenominator / divisor);
    return frac;
}

Fraction Fraction::operator*(const Fraction &secondFraction) const {
    int newNumerator = numerator_ * secondFraction.numerator(), newDenominator = denenominator_ *
            secondFraction.denominator();

    int divisor = std::gcd(newNumerator, newDenominator);
    Fraction frac(newNumerator / divisor, newDenominator / divisor);
    return frac;
}
