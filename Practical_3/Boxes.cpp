#include "Boxes.h"

Boxes::Boxes(int numBoxes, Vector *centers, double *heights, double *widths, double *lengths, Vector *colors)
{
    numShapes = numBoxes;
    shapes = new Shape *[numShapes];
    for (int i = 0; i < numShapes; i++)
    {
        shapes[i] = new Box(centers[i], heights[i], widths[i], lengths[i], colors[i]);
    }
}