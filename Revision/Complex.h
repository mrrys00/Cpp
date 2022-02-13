//
// Created by mrrys00 on 2/13/22.
//

#ifndef CPP_COMPLEX_H
#define CPP_COMPLEX_H
#include <string>
#include <sstream>

class Complex {
private:
    float re, im;
public:
    Complex(float r = 0, float i = 0) {
        re = r;
        im = i;
    }

    void overrideAdd(Complex c) {
        re += c.re;
        im += c.im;
    }

    Complex add(Complex c) {
        return Complex(re + c.re, im + c.im);
    }

    void overrideSubstract(Complex c) {
        re -= c.re;
        im -= c.im;
    }

    Complex substract(Complex c) {
        return Complex(re - c.re, im - c.im);
    }

    bool equals(Complex c) {
        return re == c.re && im == c.im;
    }

    Complex getComplex() {
        return *this;
    }

    std::string toString() {
        std::ostringstream ss;
        ss << "Re " << re << " Im " << im;
        return std::string(ss.str());
    }
};

#endif //CPP_COMPLEX_H
