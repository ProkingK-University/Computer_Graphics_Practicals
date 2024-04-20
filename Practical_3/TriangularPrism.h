#ifndef TRIANGULARPRISM_H
#define TRIANGULARPRISM_H

#include "Rectangle.h"

class TriangularPrism : public Shape
{
public:
    TriangularPrism(Vector center, double height, double base, double length, Vector color);
};

#endif