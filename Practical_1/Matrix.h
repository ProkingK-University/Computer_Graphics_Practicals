#ifndef MATRIX_H
#define MATRIX_H

#include <cmath>
#include <iomanip>
#include <iostream>

#include "Vector.h"
#include "MathExceptions.h"

class Vector;

class Matrix
{
protected:
    int n;
    int m;
    double **arr;

public:
    Matrix(int, int);
    Matrix(const Matrix &);
    Matrix(int, int, double **);

    int getM() const;
    int getN() const;

    Matrix operator~() const;
    Matrix operator+(const Matrix) const;
    Matrix operator*(const Matrix) const;
    Matrix operator*(const double) const;

    double *&operator[](int index) const
    {
        if (index >= n || index < 0)
        {
            throw MathExceptions::InvalidIndex;
        }

        return arr[index];
    }

    void print() const
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                std::cout << (*this)[i][j] << " ";
            }

            std::cout << std::endl;
        }
    }

    virtual ~Matrix();
};

class SquareMatrix : public Matrix
{
public:
    SquareMatrix(int);
    SquareMatrix(int, double **);

    double determinant() const;
    SquareMatrix operator!() const;
    Vector solve(const Vector) const;

    virtual ~SquareMatrix();
};

class IdentityMatrix : public SquareMatrix
{
public:
    IdentityMatrix(int);
    virtual ~IdentityMatrix();
};

#endif /*MATRIX_H*/