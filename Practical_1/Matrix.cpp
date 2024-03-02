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
    // TODO: Implement
    return Matrix(0, 0);
}

Matrix Matrix::operator+(const Matrix other) const
{
    // TODO: Implement
    return Matrix(0, 0);
}

Matrix Matrix::operator*(const Matrix other) const
{
    // TODO: Implement
    return Matrix(0, 0);
}

Matrix Matrix::operator*(const double scalar) const
{
    // TODO: Implement
    return Matrix(0, 0);
}

Matrix::~Matrix()
{
    for (int i = 0; i < n; ++i)
    {
        delete[] arr[i];
    }

    delete[] arr;
}

SquareMatrix::SquareMatrix(int n) : Matrix(n, n) {}

SquareMatrix::SquareMatrix(int n, double **arr) : Matrix(n, n, arr) {}

double SquareMatrix::determinant() const
{
    // TODO: Implement
    return 0.0;
}

SquareMatrix SquareMatrix::operator!() const
{
    // TODO: Implement
    return SquareMatrix(0);
}

Vector SquareMatrix::solve(const Vector v) const
{
    // TODO: Implement
    return Vector(0);
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