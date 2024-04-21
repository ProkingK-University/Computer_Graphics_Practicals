#include "Plane.h"

Plane::Plane()
{
    numShapes = 13;
    shapes = new Shape *[numShapes];

    // Body
    shapes[0] = new Box(Vector(3, new double[3]{0, 0, 0}), 0.2, 0.2, 0.6, Vector(3, new double[3]{1, 0, 0}));

    // Wings
    shapes[1] = new Box(Vector(3, new double[3]{0.1, 0, 0.05}), 0.1, 0.4, 0.2, Vector(3, new double[3]{0, 1, 0}));
    shapes[2] = new Box(Vector(3, new double[3]{-0.1, 0, 0.05}), 0.1, 0.4, 0.2, Vector(3, new double[3]{0, 1, 0}));

    // Cockpit
    shapes[3] = new Box(Vector(3, new double[3]{0, 0.05, 0.05}), 0.1, 0.1, 0.2, Vector(3, new double[3]{0, 0, 1}));

    // Tail
    shapes[4] = new TriangularPrism(Vector(3, new double[3]{0, 0.15, -0.2}), 0.1, 0.2, 0.2, Vector(3, new double[3]{0, 1, 1}));

    // Nose
    shapes[5] = new Cone(100, Vector(3, new double[3]{0, 0, 0.3}), 0.1, 0.1, Vector(3, new double[3]{1, 1, 0}));

    // Wheels
    shapes[6] = new Box(Vector(3, new double[3]{0.025, -0.05, 0.05}), 0.1, 0.025, 0.025, Vector(3, new double[3]{0, 1, 0}));
    shapes[7] = new Cylinder(100, Vector(3, new double[3]{0.025, -0.15, 0.05}), 0.025, 0.025, Vector(3, new double[3]{0, 0, 0}));

    shapes[8] = new Box(Vector(3, new double[3]{-0.025, -0.05, 0.05}), 0.1, 0.025, 0.025, Vector(3, new double[3]{0, 1, 0}));
    shapes[9] = new Cylinder(100, Vector(3, new double[3]{-0.025, -0.15, 0.05}), 0.025, 0.025, Vector(3, new double[3]{0, 0, 0}));

    shapes[10] = new Box(Vector(3, new double[3]{0, -0.05, -0.05}), 0.1, 0.025, 0.025, Vector(3, new double[3]{0, 1, 0}));
    shapes[11] = new Cylinder(100, Vector(3, new double[3]{0, -0.15, -0.05}), 0.025, 0.025, Vector(3, new double[3]{0, 0, 0}));

    // Propeller
    shapes[12] = new Box(Vector(3, new double[3]{0, 0, 0.15}), 0.2, 0.05, 0.05, Vector(3, new double[3]{0, 0, 0}));
}