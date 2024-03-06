#include "Matrix.h"

Matrix::Matrix(int n, int m)
{
    if (n > 0 && m > 0)
    {
        this->n = n;
        this->m = m;

        arr = new double *[n];

        for (int i = 0; i < n; i++)
        {
            arr[i] = new double[m];
        }
    }
    else
    {
        throw MathExceptions::InvalidMatrixSize;
    }
}

Matrix::Matrix(const Matrix &other)
{
    n = other.n;
    m = other.m;

    arr = new double *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new double[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = other.arr[i][j];
        }
    }
}

Matrix::Matrix(int n, int m, double **arr)
{
    this->n = n;
    this->m = m;

    this->arr = new double *[n];

    for (int i = 0; i < n; i++)
    {
        this->arr[i] = new double[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            this->arr[i][j] = arr[i][j];
        }
    }
}

int Matrix::getM() const
{
    return m;
}

int Matrix::getN() const
{
    return n;
}

Matrix Matrix::operator~() const
{
    Matrix matrix = Matrix(m, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix.arr[j][i] = arr[i][j];
        }
    }

    return matrix;
}

Matrix Matrix::operator+(const Matrix other) const
{
    if (n == other.n && m == other.m)
    {
        Matrix matrix = Matrix(n, m);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                matrix.arr[i][j] = arr[i][j] + other.arr[i][j];
            }
        }

        return matrix;
    }
    else
    {
        throw MathExceptions::InvalidMatrixAddition;
    }
}

Matrix Matrix::operator*(const Matrix other) const
{
    if (m == other.n)
    {
        Matrix matrix = Matrix(n, other.m);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < other.m; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    matrix.arr[i][j] += arr[i][k] * other.arr[k][j];
                }
            }
        }

        return matrix;
    }
    else
    {
        throw MathExceptions::InvalidMatrixMultiplication;
    }
}

Matrix Matrix::operator*(const double scalar) const
{
    Matrix matrix = Matrix(n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix.arr[i][j] = arr[i][j] * scalar;
        }
    }

    return matrix;
}

Matrix::~Matrix()
{
    for (int i = 0; i < n; ++i)
    {
        delete[] arr[i];
        arr[i] = NULL;
    }

    delete[] arr;
    arr = NULL;
}

SquareMatrix::SquareMatrix(int n) : Matrix(n, n) {}

SquareMatrix::SquareMatrix(int n, double **arr) : Matrix(n, n, arr) {}

double calculateDeterminant(double **matrix, int n)
{
    if (n == 1)
    {
        return matrix[0][0];
    }

    double det = 0;
    double **subMatrix = new double *[n];

    for (int i = 0; i < n; i++)
    {
        subMatrix[i] = new double[n];
    }

    if (n == 2)
    {
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    }
    else
    {
        for (int x = 0; x < n; x++)
        {
            int subI = 0;

            for (int i = 1; i < n; i++)
            {
                int subJ = 0;

                for (int j = 0; j < n; j++)
                {
                    if (j == x)
                    {
                        continue;
                    }
                    else
                    {
                        subMatrix[subI][subJ] = matrix[i][j];
                        subJ++;
                    }
                }

                subI++;
            }

            det = det + (pow(-1, x) * matrix[0][x] * calculateDeterminant(subMatrix, n - 1));
        }
    }

    return det;
}

double SquareMatrix::determinant() const
{
    return calculateDeterminant(arr, n);
}

double **getCofactor(double **matrix, int size)
{
    double **cofactor = new double *[size];

    for (int i = 0; i < size; i++)
    {
        cofactor[i] = new double[size];
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            double **subMatrix = new double *[size - 1];

            for (int k = 0; k < size - 1; k++)
            {
                subMatrix[k] = new double[size - 1];
            }

            int rowOffset = 0;

            for (int k = 0; k < size; k++)
            {
                if (k == i)
                {
                    rowOffset = 1;
                    continue;
                }

                int colOffset = 0;

                for (int l = 0; l < size; l++)
                {
                    if (l == j)
                    {
                        colOffset = 1;
                        continue;
                    }

                    subMatrix[k - rowOffset][l - colOffset] = matrix[k][l];
                }
            }

            double det = calculateDeterminant(subMatrix, size - 1);

            cofactor[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * det;

            for (int k = 0; k < size - 1; k++)
            {
                delete[] subMatrix[k];
            }

            delete[] subMatrix;
        }
    }

    return cofactor;
}

SquareMatrix SquareMatrix::operator!() const
{
    double det = determinant();

    if (det != 0)
    {
        double **array = getCofactor(arr, n);

        SquareMatrix cofactor = SquareMatrix(n, array);

        double **transpose = new double *[n];

        for (int i = 0; i < n; i++)
        {
            transpose[i] = new double[n];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                transpose[j][i] = cofactor.arr[i][j];
            }
        }

        SquareMatrix inverse = SquareMatrix(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                inverse.arr[i][j] = transpose[i][j] / det;
            }
        }

        return inverse;
    }
    else
    {
        throw MathExceptions::UnsolvableSystemOfLinearEquations;
    }
}

void gaussianElimination(double **matrix, double *vector, double *solution, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double ratio = matrix[j][i] / matrix[i][i];

            for (int k = i; k < n; k++)
            {
                matrix[j][k] -= ratio * matrix[i][k];
            }

            vector[j] -= ratio * vector[i];
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        solution[i] = vector[i];

        for (int j = i + 1; j < n; j++)
        {
            solution[i] -= matrix[i][j] * solution[j];
        }

        solution[i] /= matrix[i][i];
    }
}

Vector SquareMatrix::solve(const Vector v) const
{
    double *vector = new double[n];
    double *solution = new double[n];

    for (int i = 0; i < n; i++)
    {
        vector[i] = v[i];
    }

    gaussianElimination(arr, vector, solution, n);

    return Vector(n, solution);
}

SquareMatrix::~SquareMatrix() {}

IdentityMatrix::IdentityMatrix(int n) : SquareMatrix(n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    }
}

IdentityMatrix::~IdentityMatrix() {}