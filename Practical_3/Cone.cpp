#include "Cone.h"

Cone::Cone(int numTriangles, Vector center, double radius, double height, Vector color)
{
    numShapes = numTriangles;
    shapes = new Shape *[numTriangles];

    double angleStep = 2.0f * M_PI / numTriangles;
    Vector apex = center + Vector(3, new double[3]{0, 0, height});

    for (int i = 0; i < numTriangles; ++i)
    {
        double angle = i * angleStep;
        double nextAngle = (i + 1) * angleStep;

        Vector point1 = center + Vector(3, new double[3]{radius * cos(angle), radius * sin(angle), 0});
        Vector point2 = center + Vector(3, new double[3]{radius * cos(nextAngle), radius * sin(nextAngle), 0});

        shapes[i] = new Triangle(apex, point1, point2, color);
    }
}