#include "Vector.h"

Vector::Vector(int n)
{
    if (n > 0)
    {
        this->n = n;
        arr = new double[n];

        for (int i = 0; i < n; i++)
        {
            arr[i] = 1.0;
        }
    }
    else
    {
        throw MathExceptions::InvalidVectorSize;
    }
}

Vector::Vector(int n, double *arr)
{
    this->n = n;
    this->arr = arr;
}

Vector::Vector(const Vector &other)
{
    n = other.n;
    arr = new double[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = other.arr[i];
    }
}

Vector Vector::operator+(const Vector other) const
{
    // TODO: Implement
    return Vector(0);
}

Vector Vector::operator-(const Vector other) const
{
    // TODO: Implement
    return Vector(0);
}

Vector Vector::operator*(const double scalar) const
{
    // TODO: Implement
    return Vector(0);
}

double Vector::operator*(const Vector other) const
{
    // TODO: Implement
    return 0.0;
}

int Vector::getN() const
{
    // TODO: Implement
    return 0;
}

Vector::operator Matrix() const
{
    // TODO: Implement
    return Matrix(0, 0);
}

double Vector::magnitude() const
{
    // TODO: Implement
    return 0.0;
}

Vector Vector::unitVector() const
{
    // TODO: Implement
    return Vector(0);
}

Vector Vector::crossProduct(const Vector other) const
{
    // TODO: Implement
    return Vector(0);
}

Vector::~Vector()
{
    // TODO: Implement
}