#include "TriangularPrism.h"

TriangularPrism::TriangularPrism(Vector center, double height, double base, double length, Vector color)
{
    Vector pTop(3, new double[3]{0, height / 2, 0});
    Vector pBottom(3, new double[3]{0, -height / 2, 0});
    Vector pFront(3, new double[3]{0, 0, length / 2});
    Vector pBack(3, new double[3]{0, 0, -length / 2});
    Vector pLeft(3, new double[3]{-base / 2, 0, 0});
    Vector pRight(3, new double[3]{base / 2, 0, 0});

    Vector frontTop = center + pTop + pFront;
    Vector frontBottomLeft = center + pBottom + pFront + pLeft;
    Vector frontBottomRight = center + pBottom + pFront + pRight;

    Vector backTop = center + pTop + pBack;
    Vector backBottomLeft = center + pBottom + pBack + pLeft;
    Vector backBottomRight = center + pBottom + pBack + pRight;

    Triangle *front = new Triangle(frontTop, frontBottomLeft, frontBottomRight, color);
    Triangle *back = new Triangle(backTop, backBottomLeft, backBottomRight, color);
    Rectangle *left = new Rectangle(backBottomLeft, frontBottomLeft, frontTop, backTop, color);
    Rectangle *right = new Rectangle(frontBottomRight, backBottomRight, backTop, frontTop, color);
    Rectangle *bottom = new Rectangle(frontBottomLeft, backBottomLeft, backBottomRight, frontBottomRight, color);

    numShapes = 5;

    shapes = new Shape *[numShapes]
    {
        front, back, left, right, bottom
    };
}