#include "Matrix.h"

Matrix::Matrix(int n, int m)
{
    // TODO: Implement
}

Matrix::Matrix(const Matrix &other)
{
    // TODO: Implement
}

Matrix::Matrix(int n, int m, double **arr)
{
    // TODO: Implement
}

int Matrix::getM() const
{
    // TODO: Implement
    return 0;
}

int Matrix::getN() const
{
    // TODO: Implement
    return 0;
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
    // TODO: Implement
}

SquareMatrix::SquareMatrix(int n) : Matrix(n, n)
{
    // TODO: Implement
}

SquareMatrix::SquareMatrix(int n, double **arr) : Matrix(n, n, arr)
{
    // TODO: Implement
}

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

SquareMatrix::~SquareMatrix()
{
    // TODO: Implement
}

IdentityMatrix::IdentityMatrix(int n) : SquareMatrix(n)
{
    // TODO: Implement
}

IdentityMatrix::~IdentityMatrix()
{
    // TODO: Implement
}