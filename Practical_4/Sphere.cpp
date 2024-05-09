#include "Sphere.h"

Sphere::Sphere(int numTriangles, Vector center, GLfloat radius, Vector color)
{
    numShapes = numTriangles * numTriangles;
    shapes = new Shape *[numShapes];
    
    GLfloat angleStep = 2.0f * M_PI / numTriangles;

    for (int i = 0; i < numTriangles; ++i)
    {
        for (int j = 0; j < numTriangles; ++j)
        {
            GLfloat angle = i * angleStep;
            GLfloat nextAngle = (i + 1) * angleStep;
            GLfloat verticalAngle = j * angleStep;
            GLfloat nextVerticalAngle = (j + 1) * angleStep;

            Vector point1 = center + Vector(3, new double[3]{radius * sin(verticalAngle) * cos(angle), radius * sin(verticalAngle) * sin(angle), radius * cos(verticalAngle)});
            Vector point2 = center + Vector(3, new double[3]{radius * sin(nextVerticalAngle) * cos(nextAngle), radius * sin(nextVerticalAngle) * sin(nextAngle), radius * cos(nextVerticalAngle)});

            shapes[i * numTriangles + j] = new Triangle(center, point1, point2, color);
        }
    }
}