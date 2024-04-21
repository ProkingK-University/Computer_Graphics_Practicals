#include "Plane.h"

Plane::Plane()
{
    numShapes = 6;
    shapes = new Shape *[numShapes];

    shapes[0] = new Box(Vector(3, new double[3]{0.5, 0.5, 0.5}), 0.1, 0.1, 0.3, Vector(3, new double[3]{1, 0, 0}));
    shapes[1] = new TriangularPrism(Vector(3, new double[3]{0.35, 0.5, 0.5}), 0.01, 0.3, 0.1, Vector(3, new double[3]{0, 1, 0}));
    shapes[2] = new TriangularPrism(Vector(3, new double[3]{0.65, 0.5, 0.5}), 0.01, 0.3, 0.1, Vector(3, new double[3]{0, 1, 0}));
    shapes[3] = new Cone(20, Vector(3, new double[3]{0.5, 0.5, 0.35}), 0.05, 0.1, Vector(3, new double[3]{0, 0, 1}));
    shapes[4] = new Cylinder(20, Vector(3, new double[3]{0.45, 0.45, 0.6}), 0.02, 0.1, Vector(3, new double[3]{1, 1, 0}));
    shapes[5] = new Cylinder(20, Vector(3, new double[3]{0.55, 0.45, 0.6}), 0.02, 0.1, Vector(3, new double[3]{1, 1, 0}));
}