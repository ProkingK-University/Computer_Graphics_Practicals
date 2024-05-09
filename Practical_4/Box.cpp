#include "Box.h"

Box::Box(Vector center, double height, double width, double length, Vector color)
{
    double halfWidth = width / 2;
    double halfHeight = height / 2;
    double halfLength = length / 2;

    Vector pTop(3, new double[3]{0, halfHeight, 0});
    Vector pBottom(3, new double[3]{0, halfHeight, 0});
    Vector pLeft(3, new double[3]{halfWidth, 0, 0});
    Vector pRight(3, new double[3]{halfWidth, 0, 0});
    Vector pNear(3, new double[3]{0, 0, halfLength});
    Vector pFar(3, new double[3]{0, 0, halfLength});

    Vector topPlane = center + pTop;
    Vector bottomPlane = center - pBottom;
    Vector leftPlane = center - pLeft;
    Vector rightPlane = center + pRight;
    Vector nearPlane = center - pNear;
    Vector farPlane = center + pFar;

    Vector nearLeftTop = nearPlane + leftPlane + topPlane;
    Vector nearRightTop = nearPlane + rightPlane + topPlane;
    Vector nearLeftBottom = nearPlane + leftPlane + bottomPlane;
    Vector nearRightBottom = nearPlane + rightPlane + bottomPlane;

    Vector farLeftTop = farPlane + leftPlane + topPlane;
    Vector farRightTop = farPlane + rightPlane + topPlane;
    Vector farLeftBottom = farPlane + leftPlane + bottomPlane;
    Vector farRightBottom = farPlane + rightPlane + bottomPlane;

    Rectangle *front = new Rectangle(nearRightTop, nearLeftTop, nearLeftBottom, nearRightBottom, color);
    Rectangle *back = new Rectangle(farLeftTop, farRightTop, farRightBottom, farLeftBottom, color * 0.2f);
    Rectangle *left = new Rectangle(nearLeftTop, farLeftTop, farLeftBottom, nearLeftBottom, color * 0.3f);
    Rectangle *right = new Rectangle(farRightTop, nearRightTop, nearRightBottom, farRightBottom, color * 0.4f);
    Rectangle *bottom = new Rectangle(nearRightBottom, nearLeftBottom, farLeftBottom, farRightBottom, color * 0.5f);
    Rectangle *top = new Rectangle(nearRightTop, nearLeftTop, farLeftTop, farRightTop, color * 0.6f);

    numShapes = 6;

    shapes = new Shape *[numShapes]
    {
        front, back, left, right, bottom, top
    };
}