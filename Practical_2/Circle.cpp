#include "Circle.h"

Circle::Circle(int numTriangles, Vector center, GLfloat radius, Vector color)
{
    numShapes = numTriangles;
    shapes = new Shape *[numTriangles];

    GLfloat angleStep = 2.0f * M_PI / numTriangles;

    for (int i = 0; i < numTriangles; ++i)
    {
        GLfloat angle = i * angleStep;
        GLfloat nextAngle = (i + 1) * angleStep;

        Vector point1 = center + Vector(2, new double[2]{radius * cos(angle), radius * sin(angle)});
        Vector point2 = center + Vector(2, new double[2]{radius * cos(nextAngle), radius * sin(nextAngle)});

        shapes[i] = new Triangle(center, point1, point2, color);
    }
}