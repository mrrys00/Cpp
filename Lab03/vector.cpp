// author: Grzegorz Prowadzacy

#include <algorithm>
#include <stdexcept>
#include <utility> // std::swap()

#include "vector.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
//    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif

Vector::Vector(Vector &&vectorSecond) noexcept {
    data = vectorSecond.data;
    vectorSize = vectorSecond.vectorSize;
    vectorCapacity = vectorSecond.vectorCapacity;
    vectorSecond.data = nullptr;
    vectorSecond.vectorSize = 0;
    vectorSecond.vectorCapacity = 0;
}

Vector &Vector::operator=(const Vector &vectorSecond) {
    if(this == &vectorSecond) return *this;
    delete[] data;
    data = new Fraction[vectorSecond.vectorCapacity];
    std::copy(vectorSecond.data, vectorSecond.data + vectorSecond.vectorSize, data);
    vectorCapacity = vectorSecond.vectorCapacity;
    vectorSize = vectorSecond.vectorSize;
    return *this;
}

Vector &Vector::operator=(Vector &&vectorSecond) noexcept {
    if(this == &vectorSecond) return *this;
    delete[] data;
    data = vectorSecond.data;
    vectorSize = vectorSecond.vectorSize;

    vectorCapacity = vectorSecond.vectorCapacity;
    vectorSecond.data = nullptr;
    vectorSecond.vectorSize = 0;
    vectorSecond.vectorCapacity = 0;
    return *this;
}

void Vector::push_back(Fraction fraction) {
    if(vectorSize >= vectorCapacity) {
        auto* expanded = new Fraction[++vectorCapacity];
        std::copy(data, data + vectorSize, expanded);
        
        delete[] data;
        data = expanded;
    }
    data[vectorSize++] = fraction;
    return;
}

Fraction Vector::operator[](size_t index) const {
    if(index >= vectorSize) 
        throw std::out_of_range("Index out of range");
    return data[index];
}

Vector::Vector(Vector &vectorSecond) : data{new Fraction[vectorSecond.capacity()]}, vectorCapacity{vectorSecond.capacity()}, vectorSize{vectorSecond.size()} {
    std::copy(vectorSecond.data, vectorSecond.data + vectorSecond.size(), data);
}

Vector::Vector(size_t data) : data{new Fraction[data]}, vectorCapacity{data}, vectorSize{0} {}

Vector::~Vector() {delete[] data;}

size_t Vector::size() const {return vectorSize;}

size_t Vector::capacity() const {return vectorCapacity;}
