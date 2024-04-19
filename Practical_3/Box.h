#ifndef BOX_H
#define BOX_H

#include "Rectangle.h"

class Box : public Shape
{
public:
    Box(Vector center, double height, double width, double length, Vector color);
};

#endif