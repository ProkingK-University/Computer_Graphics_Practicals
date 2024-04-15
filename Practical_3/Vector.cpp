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
    if (n == other.n)
    {
        Vector v = Vector(n);

        for (int i = 0; i < n; i++)
        {
            v.arr[i] = arr[i] + other.arr[i];
        }

        return v;
    }
    else
    {
        throw MathExceptions::InvalidVectorAddition;
    }
}

Vector Vector::operator-(const Vector other) const
{
    if (n == other.n)
    {
        Vector v = Vector(n);

        for (int i = 0; i < n; i++)
        {
            v.arr[i] = arr[i] - other.arr[i];
        }

        return v;
    }
    else
    {
        throw MathExceptions::InvalidVectorAddition;
    }
}

Vector Vector::operator*(const double scalar) const
{
    Vector v = Vector(n);

    for (int i = 0; i < n; i++)
    {
        v.arr[i] = arr[i] * scalar;
    }

    return v;
}

double Vector::operator*(const Vector other) const
{
    if (n == other.n)
    {
        double result = 0.0;

        for (int i = 0; i < n; ++i)
        {
            result += arr[i] * other.arr[i];
        }

        return result;
    }
    else
    {
        throw MathExceptions::InvalidDotProduct;
    }
}

int Vector::getN() const
{
    return n;
}

Vector::operator Matrix() const
{
    double **vectorValues = new double *[n];

    for (int i = 0; i < n; i++)
    {
        vectorValues[i] = new double[1];
        vectorValues[i][0] = arr[i];
    }

    return Matrix(n, 1, vectorValues);
}

double Vector::magnitude() const
{
    double sum = 0.0;

    for (int i = 0; i < n; ++i)
    {
        sum += arr[i] * arr[i];
    }

    return sqrt(sum);
}

Vector Vector::unitVector() const
{
    double magnitude = this->magnitude();

    if (magnitude != 0)
    {
        Vector v = Vector(n);

        for (int i = 0; i < n; i++)
        {
            v.arr[i] = arr[i] / magnitude;
        }

        return v;
    }
    else
    {
        throw MathExceptions::InvalidUnitVector;
    }
}

Vector Vector::crossProduct(const Vector other) const
{
    if (n == 3 && other.n == 3)
    {
        Vector v = Vector(3);

        v.arr[0] = arr[1] * other.arr[2] - arr[2] * other.arr[1];
        v.arr[1] = arr[2] * other.arr[0] - arr[0] * other.arr[2];
        v.arr[2] = arr[0] * other.arr[1] - arr[1] * other.arr[0];

        return v;
    }
    else
    {
        throw MathExceptions::InvalidCrossProduct;
    }
}

Vector::~Vector()
{
    delete[] arr;
    arr = NULL;
}