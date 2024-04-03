#ifndef CIRCLE_H
#define CIRCLE_H

#include "Triangle.h"

class Circle : public Shape
{
public:
    Circle(int numTriangles, Vector centre, GLfloat radius, Vector color);
};

#endif