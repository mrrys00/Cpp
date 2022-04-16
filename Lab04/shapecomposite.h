#ifndef SHAPECOMPOSITE_H
#define SHAPECOMPOSITE_H

#include <memory>

#include "shape.h"

namespace Shapes
{
enum class ShapeOperation
{
    INTERSECTION,
    SUM,
    DIFFERENCE
};

class ShapeComposite : public Shape
{
    std::shared_ptr<Shape> shape1, shape2;
    ShapeOperation operation;

public:
    ShapeComposite(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2, ShapeOperation operation): shape1(shape1), shape2(shape2), operation(operation) {}

    [[nodiscard]] bool isIn(int x, int y) const override {
        if (operation == ShapeOperation::SUM)
            return shape1->isIn(x, y) || shape2->isIn(x, y);
        else if (operation == ShapeOperation::INTERSECTION)
            return shape1->isIn(x, y) && shape2->isIn(x, y);

        return (shape1->isIn(x, y) && !shape2->isIn(x, y)) || (!shape1->isIn(x, y) && shape2->isIn(x, y));
    }
};
} // namespace Shapes

#endif // SHAPECOMPOSITE_H
