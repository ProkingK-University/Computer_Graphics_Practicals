#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
public:
    Triangle(Vector a, Vector b, Vector c, Vector color);

    int numPoints();
    int numColours();
    int numVertices();

    double **createColourArray(Vector color);
    double **createVertexArray(Vector a, Vector b, Vector c);
};

#endif