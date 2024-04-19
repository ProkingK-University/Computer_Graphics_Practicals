#ifndef BOXES_H
#define BOXES_H

#include "Box.h"

class Boxes : public Shape
{
public:
    Boxes::Boxes(int numBoxes, Vector *centers, double *heights, double *widths, double *lengths, Vector *colors);
};

#endif