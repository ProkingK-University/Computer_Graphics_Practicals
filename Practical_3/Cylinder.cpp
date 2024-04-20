#include "Cylinder.h"

Cylinder::Cylinder(int numTriangles, Vector center, GLfloat radius, GLfloat height, Vector color)
{
    numShapes = 2 * numTriangles;
    shapes = new Shape *[numShapes];

    GLfloat angleStep = 2.0f * M_PI / numTriangles;
    Vector bottomCenter = center;
    Vector topCenter = center + Vector(3, new double[3]{0, 0, height});

    for (int i = 0; i < numTriangles; ++i)
    {
        GLfloat angle = i * angleStep;
        GLfloat nextAngle = (i + 1) * angleStep;

        Vector bottomPoint1 = bottomCenter + Vector(3, new double[3]{radius * cos(angle), radius * sin(angle), 0});
        Vector bottomPoint2 = bottomCenter + Vector(3, new double[3]{radius * cos(nextAngle), radius * sin(nextAngle), 0});
        Vector topPoint1 = topCenter + Vector(3, new double[3]{radius * cos(angle), radius * sin(angle), 0});
        Vector topPoint2 = topCenter + Vector(3, new double[3]{radius * cos(nextAngle), radius * sin(nextAngle), 0});

        shapes[2 * i] = new Triangle(bottomPoint1, topPoint1, bottomPoint2, color);
        shapes[2 * i + 1] = new Triangle(topPoint1, topPoint2, bottomPoint2, color);
    }
}