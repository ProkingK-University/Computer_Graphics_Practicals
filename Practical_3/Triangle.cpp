#include "Triangle.h"

Triangle::Triangle(Vector a, Vector b, Vector c, Vector colour) : Shape()
{
    double **colourArray = createColourArray(colour);
    double **vertexArray = createVertexArray(a, b, c);

    colours = new Matrix(3, 3, colourArray);
    vertices = new Matrix(3, 3, vertexArray);

    for (int i = 0; i < 3; i++)
    {
        delete[] colourArray[i];
        delete[] vertexArray[i];
    }

    delete[] colourArray;
    delete[] vertexArray;
}

double **Triangle::createVertexArray(Vector a, Vector b, Vector c)
{
    double **array = new double *[3];

    for (int i = 0; i < 3; i++)
    {
        array[i] = new double[3];
    }

    for (int i = 0; i < 3; i++)
    {
        array[0][i] = a[i];
        array[1][i] = b[i];
        array[2][i] = c[i];
    }

    return array;
}

double **Triangle::createColourArray(Vector color)
{
    double **array = new double *[3];

    for (int i = 0; i < 3; i++)
    {
        array[i] = new double[3];
    }

    for (int i = 0; i < 3; i++)
    {
        array[0][i] = color[i];
        array[1][i] = color[i];
        array[2][i] = color[i];
    }

    return array;
}

int Triangle::numPoints() { return 3; }

int Triangle::numColours() { return 9; }

int Triangle::numVertices() { return 9; }