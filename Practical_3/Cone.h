#ifndef CONE_H
#define CONE_H

#include "Circle.h"

class Cone : public Shape
{
public:
    Cone(int numTriangles, Vector center, double radius, double height, Vector color);
};

#endif