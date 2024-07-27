#include "Scene.h"

Scene::Scene()
{
    numShapes = 4;
    shapes = new Shape *[numShapes];

    // Plane
    shapes[0] = new Box(Vector(3, new double[3]{0, -0.1, 0}), 0.01, 0.8, 0.8, Vector(3, new double[3]{0.5, 0.5, 0.5}));

    // Wall
    shapes[1] = new Box(Vector(3, new double[3]{0, 0, -0.1}), 0.6, 0.8, 0.02, Vector(3, new double[3]{1, 0, 0}));

    // Window
    shapes[2] = new Box(Vector(3, new double[3]{0, 0, 0}), 0.6, 0.8, 0.05, Vector(3, new double[3]{0, 0.8, 0}));

    // Sphere
    shapes[3] = new Sphere(20, Vector(3, new double[3]{0.0, 0.0, 0.4}), 0.1, Vector(3, new double[3]{0, 0, 1}));
}