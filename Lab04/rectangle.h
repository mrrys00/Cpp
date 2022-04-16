#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

namespace Shapes
{
class Rectangle : public Shape
{
public:
    Rectangle(int x, int y, int xTo, int yTo);

    [[nodiscard]] int x() const;
    [[nodiscard]] int xTo() const;
    [[nodiscard]] int y() const;
    [[nodiscard]] int yTo() const;

    [[nodiscard]] bool isIn(int x_, int y_) const override;

private:
    Point fromm, too;
};
} // namespace Shapes

#endif // RECTANGLE_H
