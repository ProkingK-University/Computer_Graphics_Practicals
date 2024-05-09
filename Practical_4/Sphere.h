#ifndef SPHERE_H
#define SPHERE_H

#include "Triangle.h"

class Sphere : public Shape
{
public:
    Sphere(int numTriangles, Vector center, GLfloat radius, Vector color);
};

#endif