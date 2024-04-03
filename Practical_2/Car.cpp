#include "Car.h"

Car::Car()
{
    numShapes = 12;
    shapes = new Shape *[numShapes];

    // Car body
    shapes[0] = new Rectangle(
        Vector(2, new double[2]{0.5, 0.0}),
        Vector(2, new double[2]{-0.5, 0.0}),
        Vector(2, new double[2]{-0.5, -0.25}),
        Vector(2, new double[2]{0.5, -0.25}),
        Vector(3, new double[3]{0, 1, 0}));

    // Car roof
    shapes[1] = new Rectangle(
        Vector(2, new double[2]{0.25, 0.25}),
        Vector(2, new double[2]{-0.25, 0.25}),
        Vector(2, new double[2]{-0.25, 0.0}),
        Vector(2, new double[2]{0.25, 0.0}),
        Vector(3, new double[3]{1, 0, 0}));

    // Front and back windows
    shapes[2] = new Rectangle(
        Vector(2, new double[2]{-0.15, 0.15}),
        Vector(2, new double[2]{-0.25, 0.15}),
        Vector(2, new double[2]{-0.25, 0.05}),
        Vector(2, new double[2]{-0.15, 0.05}),
        Vector(3, new double[3]{0, 0, 1}));

    shapes[3] = new Triangle(
        Vector(2, new double[2]{0.15, 0.15}),
        Vector(2, new double[2]{0.25, 0.15}),
        Vector(2, new double[2]{0.25, 0.05}),
        Vector(3, new double[3]{0, 0, 1}));

    // Wheels
    shapes[4] = new Circle(20, Vector(2, new double[2]{-0.35, -0.25}), 0.1, Vector(3, new double[3]{0, 0, 0}));
    shapes[5] = new Circle(20, Vector(2, new double[2]{0.35, -0.25}), 0.1, Vector(3, new double[3]{0, 0, 0}));

    // Wheel centers
    shapes[6] = new Circle(10, Vector(2, new double[2]{-0.35, -0.25}), 0.05, Vector(3, new double[3]{1, 1, 1}));
    shapes[7] = new Circle(10, Vector(2, new double[2]{0.35, -0.25}), 0.05, Vector(3, new double[3]{1, 1, 1}));

    // Headlights
    shapes[8] = new Circle(10, Vector(2, new double[2]{0.5, -0.15}), 0.05, Vector(3, new double[3]{1, 1, 0}));

    // Door handles
    shapes[9] = new Rectangle(
        Vector(2, new double[2]{0.2, -0.05}),
        Vector(2, new double[2]{0.1, -0.05}),
        Vector(2, new double[2]{0.1, -0.1}),
        Vector(2, new double[2]{0.2, -0.1}),
        Vector(3, new double[3]{0, 0, 0}));

    shapes[10] = new Rectangle(
        Vector(2, new double[2]{-0.2, -0.05}),
        Vector(2, new double[2]{-0.1, -0.05}),
        Vector(2, new double[2]{-0.1, -0.1}),
        Vector(2, new double[2]{-0.2, -0.1}),
        Vector(3, new double[3]{0, 0, 0}));

    // Door lines
    shapes[11] = new Rectangle(
        Vector(2, new double[2]{0.001, 0.0}),
        Vector(2, new double[2]{-0.001, 0.0}),
        Vector(2, new double[2]{-0.001, -0.25}),
        Vector(2, new double[2]{0.001, -0.25}),
        Vector(3, new double[3]{0, 0, 0}));
}
