#include "Scene.h"

Scene::Scene()
{
    numShapes = 3;
    shapes = new Shape *[numShapes];

    // Plane
    shapes[0] = new Box(Vector(3, new double[3]{0, -0.1, 0}), 0.01, 0.8, 0.8, Vector(3, new double[3]{0.5, 0.5, 0.5}));

    // Wall
    shapes[1] = new Box(Vector(3, new double[3]{0, 0, 0.8}), 0.6, 0.8, 0.1, Vector(3, new double[3]{1, 0, 0}));

    // Window
    shapes[2] = new Box(Vector(3, new double[3]{0, 0, 0.5}), 0.6, 0.8, 0.4, Vector(3, new double[3]{0, 0.8, 0}));
}