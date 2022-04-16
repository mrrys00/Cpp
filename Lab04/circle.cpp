using namespace std;

#include "shape.h"
#include "circle.h"

Shapes::Circle::Circle(int cx, int cy, int rad) : radius(rad) {
    center.first = cx;
    center.second = cy;
}

int Shapes::Circle::x() const {return center.first;}

int Shapes::Circle::y() const {return center.second;}

int Shapes::Circle::getRadius() const {return radius;}

bool Shapes::Circle::isIn(int x, int y) const {
    return (x - center.first) * (x - center.first) + (y - center.second) * (y - center.second) <= radius * radius;
}
