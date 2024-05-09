#ifndef SHAPES_H
#define SHAPES_H

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Matrix.h"

class Shape
{
protected:
    int numShapes;

    Matrix *colours;

public:
    Shape **shapes;
    Matrix *vertices;

    Shape();

    virtual int numPoints();
    virtual int numColours();
    virtual int numVertices();

    virtual GLfloat *toVertexArray();
    virtual GLfloat *toColourArray();
    virtual GLfloat *toVertexLineArray();
    virtual GLfloat *toColourLineArray();

    virtual void rotate(double angle);
    virtual void applyMatrix(Matrix matrix, bool rotate = false);

    virtual ~Shape();
};
#endif