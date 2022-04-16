#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

namespace Shapes
{
class Circle : public Shape
{
public:
    Circle(int cx, int cy, int rad);

    [[nodiscard]] int x() const;
    [[nodiscard]] int y() const;
    [[nodiscard]] int getRadius() const;

    [[nodiscard]] bool isIn(int x, int y) const override;

private:
    Point center;
    int radius;
};
} // namespace Shapes

#endif // CIRCLE_H
