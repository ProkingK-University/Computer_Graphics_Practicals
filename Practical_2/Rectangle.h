#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Triangle.h"

class Rectangle : public Shape
{
public:
    Rectangle(Vector a, Vector b, Vector c, Vector d, Vector colour);

    double **createVertexArray();
    double **createColourArray(Vector colour);
};

#endif