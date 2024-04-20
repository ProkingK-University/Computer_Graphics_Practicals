#ifndef CONE_H
#define CONE_H

#include "Circle.h"

class Cone : public Shape
{
public:
    Cone(int numTriangles, Vector center, GLfloat radius, GLfloat height, Vector color);
};

#endif