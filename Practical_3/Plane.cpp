#include "Plane.h"

Plane::Plane()
{
    numShapes = 5;
    shapes = new Shape *[numShapes];

    // Body of the plane
    shapes[0] = new Box(Vector(3, new double[3]{0, 0, 0}), 1.0, 0.1, 0.2, Vector(3, new double[3]{1, 0, 0}));

    // Wings of the plane
    shapes[1] = new Box(Vector(3, new double[3]{0, -0.5, 0}), 0.6, 0.02, 0.2, Vector(3, new double[3]{0, 1, 0}));
    shapes[2] = new Box(Vector(3, new double[3]{0, 0.5, 0}), 0.6, 0.02, 0.2, Vector(3, new double[3]{0, 1, 0}));

    // Tail of the plane
    shapes[3] = new Box(Vector(3, new double[3]{-0.5, 0, 0}), 0.2, 0.1, 0.05, Vector(3, new double[3]{1, 0, 0}));
    shapes[4] = new Box(Vector(3, new double[3]{-0.5, 0, 0.125}), 0.1, 0.02, 0.1, Vector(3, new double[3]{0, 0, 1}));
}