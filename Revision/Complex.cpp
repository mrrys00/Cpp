//
// Created by mrrys00 on 2/13/22.
//

#include "Complex.h"
#include <iostream>

int main() {
    Complex c1 = Complex(2.6, -3.9), c2 = Complex(2.2,2.2), c3, c4;
    c3 = c1.add(c2);
    c4 = c1.substract(c2);

    if (c3.equals(Complex(4.8, -1.7))) {
        std::cout << "Addition OK" << std::endl;
    } else {
        std::cout << "Addition ERROR" << std::endl;
    }

    c1.overrideAdd(c2);
    if (c3.equals(c3)) {
        std::cout << "Addition override OK" << std::endl;
    } else {
        std::cout << "Addition override ERROR" << std::endl;
    }

    return 0;
}