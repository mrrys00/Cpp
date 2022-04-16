using namespace std;

#include "shape.h"
#include "rectangle.h"


Shapes::Rectangle::Rectangle(int x, int y, int xTo, int yTo) {
    fromm.first = x;
    fromm.second = y;
    too.first = xTo;
    too.second = yTo;
}

int Shapes::Rectangle::x() const {return fromm.first;}

int Shapes::Rectangle::xTo() const {return too.first;}

int Shapes::Rectangle::y() const {return fromm.second;}

int Shapes::Rectangle::yTo() const {return too.second;}

bool Shapes::Rectangle::isIn(int x_, int y_) const {
    return (x() <= x_ && x_ <= xTo() && y() <= y_ && y_ <= yTo());
}
