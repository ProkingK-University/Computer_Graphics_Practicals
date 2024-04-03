#include "Rectangle.h"

Rectangle::Rectangle(Vector a, Vector b, Vector c, Vector d, Vector colour)
{
    numShapes = 2;
    shapes = new Shape *[numShapes];

    shapes[0] = new Triangle(a, b, c, colour);
    shapes[1] = new Triangle(c, d, a, colour);

    double **vertexArray = createVertexArray();
    double **colourArray = createColourArray(colour);

    colours = new Matrix(6, 3, colourArray);
    vertices = new Matrix(6, 2, vertexArray);

    for (int i = 0; i < 6; i++)
    {
        delete[] colourArray[i];
    }

    delete[] colourArray;

    for (int i = 0; i < 6; i++)
    {
        delete[] vertexArray[i];
    }

    delete[] vertexArray;
}

double **Rectangle::createVertexArray()
{
    double **array = new double *[6];

    for (int i = 0; i < 6; i++)
    {
        array[i] = new double[2];
    }

    int count = 0;

    for (int i = 0; i < numShapes; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                array[count][k] = (*shapes[i]->vertices)[j][k];
            }

            count++;
        }
    }

    return array;
}

double **Rectangle::createColourArray(Vector colour)
{
    double **array = new double *[6];

    for (int i = 0; i < 6; i++)
    {
        array[i] = new double[3];
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            array[i][j] = colour[j];
        }
    }

    return array;
}