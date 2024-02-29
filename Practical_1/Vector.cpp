#include "Vector.h"

Vector::Vector(int n)
{
    // TODO: Implement
}

Vector::Vector(int n, double *arr)
{
    // TODO: Implement
}

Vector::Vector(const Vector &other)
{
    // TODO: Implement
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