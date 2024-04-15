#include "Shape.h"

Shape::Shape()
{
    numShapes = 0;
    shapes = new Shape *[numShapes];
}

int Shape::numPoints()
{
    int count = 0;

    for (int i = 0; i < numShapes; i++)
    {
        count += shapes[i]->numPoints();
    }

    return count;
}

int Shape::numColours()
{
    int count = 0;

    for (int i = 0; i < numShapes; i++)
    {
        count += shapes[i]->numColours();
    }

    return count;
}

int Shape::numVertices()
{
    int count = 0;

    for (int i = 0; i < numShapes; i++)
    {
        count += shapes[i]->numVertices();
    }

    return count;
}

GLfloat *Shape::toVertexArray()
{
    int totalVertices = numVertices();

    GLfloat *result = new GLfloat[totalVertices];

    if (numShapes > 0)
    {
        int count = 0;

        for (int i = 0; i < numShapes; i++)
        {
            GLfloat *temp = shapes[i]->toVertexArray();

            for (int j = 0; j < shapes[i]->numVertices(); j++)
            {
                result[count++] = temp[j];
            }

            delete[] temp;
        }
    }
    else
    {
        int count = 0;

        for (int i = 0; i < totalVertices / 2; i++)
        {
            result[count++] = (*vertices)[i][0];
            result[count++] = (*vertices)[i][1];
        }
    }

    return result;
}

GLfloat *Shape::toVertexLineArray()
{
    int totalVertices = numVertices() * 2;

    GLfloat *result = new GLfloat[totalVertices];

    if (numShapes > 0)
    {
        int count = 0;

        for (int i = 0; i < numShapes; i++)
        {
            GLfloat *temp = shapes[i]->toVertexLineArray();

            int totalShapeVertices = shapes[i]->numVertices() * 2;

            for (int j = 0; j < totalShapeVertices; j++)
            {
                result[count++] = temp[j];
            }

            delete[] temp;
        }
    }
    else
    {
        result[0] = (*vertices)[0][0];
        result[1] = (*vertices)[0][1];
        result[2] = (*vertices)[1][0];
        result[3] = (*vertices)[1][1];
        result[4] = (*vertices)[1][0];
        result[5] = (*vertices)[1][1];
        result[6] = (*vertices)[2][0];
        result[7] = (*vertices)[2][1];
        result[8] = (*vertices)[2][0];
        result[9] = (*vertices)[2][1];
        result[10] = (*vertices)[0][0];
        result[11] = (*vertices)[0][1];
    }

    return result;
}

GLfloat *Shape::toColourArray()
{
    int totalColours = numColours();

    GLfloat *result = new GLfloat[totalColours];

    if (numShapes > 0)
    {
        int count = 0;

        for (int i = 0; i < numShapes; i++)
        {
            GLfloat *temp = shapes[i]->toColourArray();

            for (int j = 0; j < shapes[i]->numColours(); j++)
            {
                result[count++] = temp[j];
            }

            delete[] temp;
        }
    }
    else
    {
        int count = 0;
        int totalVertices = numVertices();

        for (int i = 0; i < totalVertices / 2; i++)
        {
            result[count++] = (*colours)[i][0];
            result[count++] = (*colours)[i][1];
            result[count++] = (*colours)[i][2];
        }
    }

    return result;
}

GLfloat *Shape::toColourLineArray()
{
    int totalColours = numVertices() * 3;

    GLfloat *result = new GLfloat[totalColours];

    if (numShapes > 0)
    {
        int count = 0;

        for (int i = 0; i < numShapes; i++)
        {
            GLfloat *temp = shapes[i]->toColourLineArray();

            int totalShapeColours = shapes[i]->numVertices() * 3;

            for (int j = 0; j < totalShapeColours; j++)
            {
                result[count++] = temp[j];
            }

            delete[] temp;
        }
    }
    else
    {
        int count = 0;
        int totalVertices = numVertices();

        for (int i = 0; i < totalVertices; i++)
        {
            result[count++] = (*colours)[0][0];
            result[count++] = (*colours)[0][1];
            result[count++] = (*colours)[0][2];
        }
    }

    return result;
}

void Shape::rotate(GLfloat angle)
{
    double *centre = new double[2];
    centre[0] = (*shapes[0]->vertices)[0][0];
    centre[1] = (*shapes[0]->vertices)[0][1];

    double **originArray = new double *[3]
    {
        new double[3]{1, 0, -centre[0]},
        new double[3]{0, 1, -centre[1]},
        new double[3]{ 0, 0, 1 } };

    double **normalArray = new double *[3]
    {
        new double[3]{1, 0, centre[0]},
        new double[3]{0, 1, centre[1]},
        new double[3]{ 0, 0, 1 } };

    double a = cos(angle);
    double b = sin(angle);

    double **arrayRotate = new double *[3]
    {
        new double[3]{a, -b, 0},
        new double[3]{b, a, 0},
        new double[3]{0, 0, 1} };

    Matrix origin(3, 3, originArray);
    Matrix normal(3, 3, normalArray);
    Matrix rotate(3, 3, arrayRotate);

    Matrix result = normal * rotate * origin;

    applyMatrix(result);
}

void Shape::applyMatrix(Matrix matrix, bool rotate)
{
    if (rotate)
    {
        shapes[4]->rotate(10);
        shapes[5]->rotate(10);
        shapes[6]->rotate(10);
        shapes[7]->rotate(10);
    }
    else
    {
        if (numShapes > 0)
        {
            for (int i = 0; i < numShapes; i++)
            {
                shapes[i]->applyMatrix(matrix);
            }
        }
        else
        {
            int totalPoints = numPoints();

            for (int i = 0; i < totalPoints; i++)
            {
                int numRows = vertices->getM() + 1;

                double **array = new double *[numRows];

                for (int j = 0; j < numRows; j++)
                {
                    array[j] = new double[1];

                    if (j == numRows - 1)
                    {
                        array[j][0] = 1;
                    }
                    else
                    {
                        array[j][0] = (*vertices)[i][j];
                    }
                }

                Matrix point(numRows, 1, array);

                Matrix result = matrix * point;

                for (int j = 0; j < numRows - 1; j++)
                {
                    (*vertices)[i][j] = result[j][0];
                }
            }
        }
    }
}

Shape::~Shape()
{
    delete[] shapes;
}