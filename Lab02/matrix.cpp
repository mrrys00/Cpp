#include <iostream>
#include <string>

using namespace std;

#include "matrix.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler


    // #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif

TwoDimensionMatrix::TwoDimensionMatrix() : matrix{{0, 0}, {0, 0}} {}

TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement (*matrix)[2]) : matrix{
        {matrix[0][0],matrix[0][1]},
        {matrix[1][0],matrix[1][1]}
} {}

TwoDimensionMatrix::TwoDimensionMatrix(TwoDimensionMatrix const &other) : matrix{
        {other.get(0, 0), other.get(0, 1)},
        {other.get(1, 0), other.get(1, 1)}
} {}

TwoDimensionMatrix::TwoDimensionMatrix(int a, int b, int c, int d) : matrix{{a, b}, {c, d}} {}

MatrixElement TwoDimensionMatrix::get(int row, int col) const {
    return matrix[row][col];
}

MatrixElement TwoDimensionMatrix::get(int index) const {
    return matrix[index / 2][index % 2];
}

void TwoDimensionMatrix::set(int row, int col, int val) {
    matrix [row][col] = val;
}

void TwoDimensionMatrix::print(ostream &o) const {
    o << matrix[0][0] << ", " << matrix[0][1] << endl << matrix[1][0] << ", " << matrix[1][1] << endl;
}

TwoDimensionMatrix &TwoDimensionMatrix::operator=(const TwoDimensionMatrix &other) {
    if(&other == this) return *this;
    for(int x=0; x<(int)size; x++) for(int y=0; y<(int)size; y++) matrix[y][x] = other.get(y, x);
    return *this;
}

TwoDimensionMatrix &TwoDimensionMatrix::operator*=(MatrixElement number) {
    for(int x=0; x<(int)size; x++) for(auto & field : matrix) field[x] *= number;
    return *this;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix &other) const {
    TwoDimensionMatrix out(
            this->get(0) && other.get(0),
            this->get(1) && other.get(1),
            this->get(2) && other.get(2),
            this->get(3) && other.get(3)
    );
    return out;
}
#pragma GCC diagnostic pop

ostream &operator<<(ostream &o, const TwoDimensionMatrix &matrix) {
    matrix.print(o);
    return o;
}

istream& operator>>(istream &is, TwoDimensionMatrix matrix) {

    std::string str;
    std::string delimiter1 = "{";
    std::string delimiter2 = ",";
    std::string delimiter3 = "}";
    std::string newline = "\n";

    std::string sa,sb,sc,sd;
    is >> sa >> sb >> sc >> sd;
    int a = std::stoi(sa), b = std::stoi(sb), c = std::stoi(sc), d = std::stoi(sd);

    matrix.set(0,0,a);
    matrix.set(0,1,b);
    matrix.set(1,0,c);
    matrix.set(1,1,d);

    return is;
}

TwoDimensionMatrix operator+(const TwoDimensionMatrix &matrix1, const TwoDimensionMatrix &matrix2) {
    auto *out = new TwoDimensionMatrix(
            matrix1.get(0) + matrix2.get(0),
            matrix1.get(1) + matrix2.get(1),
            matrix1.get(2) + matrix2.get(2),
            matrix1.get(3) + matrix2.get(3)
    );
    return *out;
}
