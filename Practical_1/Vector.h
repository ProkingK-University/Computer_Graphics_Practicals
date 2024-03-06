#ifndef VECTOR_H
#define VECTOR_H

#include "Matrix.h"
#include "MathExceptions.h"

class Matrix;

class Vector
{
private:
    int n;
    double *arr;

public:
    Vector(int);
    Vector(int, double *);
    Vector(const Vector &);

    Vector operator+(const Vector) const;
    Vector operator-(const Vector) const;
    Vector operator*(const double) const;
    double operator*(const Vector) const;

    int getN() const;
    operator Matrix() const;
    double magnitude() const;
    Vector unitVector() const;
    Vector crossProduct(const Vector) const;

    double &operator[](int index) const
    {
        if (index < 0 || index >= n)
        {
            throw MathExceptions::InvalidIndex;
        }

        return arr[index];
    }

    void print() const
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << arr[i] << "\n";
        }
    };

    ~Vector();
};

#endif /*VECTOR_H*/