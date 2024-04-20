#ifndef CYLINDER_H
#define CYLINDER_H

#include "Triangle.h"

class Cylinder : public Shape
{
public:
    Cylinder(int numTriangles, Vector center, GLfloat radius, GLfloat height, Vector color);
};

#endif