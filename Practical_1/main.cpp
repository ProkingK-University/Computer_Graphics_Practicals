#include <iostream>

#include "Vector.h"

void vectorTests();
void matrixTests();

int main()
{
    // vectorTests();
    matrixTests();

    return 0;
}

void vectorTests()
{
    std::cout << "Vector Tests" << std::endl;

    double *arr = new double[3];

    for (int i = 0; i < 3; i++)
    {
        arr[i] = i + 1;
    }

    std::cout << "Vector Construction" << std::endl;

    Vector v1(3);
    Vector v2(v1);
    Vector v3(3, arr);

    v1.print();
    std::cout << std::endl;
    v2.print();
    std::cout << std::endl;
    v3.print();

    std::cout << "Vector To Matrix Cast" << std::endl;

    Matrix m = v3;

    m.print();

    // Vector v4(0);

    std::cout << "Vector Addition" << std::endl;

    Vector v5 = v1 + v3;

    v5.print();

    std::cout << "Vector Subtraction" << std::endl;

    Vector v6 = v5 - v1;

    v6.print();

    std::cout << "Vector Scalar Multiplication" << std::endl;

    Vector v7 = v6 * 2;

    v7.print();

    std::cout << "Vector Dot Product" << std::endl;

    double dotProduct = v6 * v7;

    std::cout << dotProduct << std::endl;

    std::cout << "Vector Magnitude" << std::endl;

    double magnitude = v7.magnitude();

    std::cout << magnitude << std::endl;

    std::cout << "Vector Cross Product" << std::endl;

    Vector v8 = v6.crossProduct(v7);

    v8.print();

    std::cout << "Unit Vector" << std::endl;

    Vector v9 = v7.unitVector();

    v9.print();

    std::cout << std::endl;
    std::cout << "END OF VECTOR TESTS" << std::endl;
}

void matrixTests()
{
    std::cout << "MATRIX TEST" << std::endl;

    double **arr = new double *[3];

    for (int i = 0; i < 3; i++)
    {
        arr[i] = new double[3];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = i + j;
        }
    }

    std::cout << "Matrix Construction" << std::endl;

    Matrix m1(3, 3);
    Matrix m2(3, 3, arr);
    Matrix m3(m2);

    m1.print();

    std::cout << std::endl;
    m2.print();

    std::cout << std::endl;
    m3.print();

    std::cout << "Matrix Multiplication" << std::endl;

    Matrix m4 = m2 * m3;

    m4.print();

    std::cout << "Matrix Scalar Multiplication" << std::endl;

    Matrix m5 = m2 * 2;

    m5.print();

    std::cout << "Matrix Addition" << std::endl;

    Matrix m6 = m2 + m3;

    m6.print();

    std::cout << "Matrix Transpose" << std::endl;

    Matrix m7 = ~m6;

    m7.print();

    std::cout << "Matrix Determinant" << std::endl;

    IdentityMatrix im(3);

    std::cout << im.determinant() << std::endl;

    double **detr = new double *[3];

    for (int i = 0; i < 3; i++)
    {
        detr[i] = new double[3];
    }

    detr[0][0] = 1;
    detr[0][1] = -2;
    detr[0][2] = 3;
    detr[1][0] = 2;
    detr[1][1] = 0;
    detr[1][2] = 3;
    detr[2][0] = 1;
    detr[2][1] = 5;
    detr[2][2] = 4;

    SquareMatrix sm(3, detr);

    std::cout << sm.determinant() << std::endl;

    std::cout << "Matrix Inverse" << std::endl;

    Matrix m8 = !sm;

    sm.print();

    std::cout << std::endl;
    m8.print();

    std::cout << "Matrix Solve" << std::endl;

    double **A = new double *[3];

    for (int i = 0; i < 3; i++)
    {
        A[i] = new double[3];
    }

    A[0][0] = 3;
    A[0][1] = 2;
    A[0][2] = -4;
    A[1][0] = 2;
    A[1][1] = 3;
    A[1][2] = 3;
    A[2][0] = 5;
    A[2][1] = -3;
    A[2][2] = 1;

    double *b = new double[3];

    b[0] = 3;
    b[1] = 15;
    b[2] = 14;

    SquareMatrix sm1(3, A);

    Vector v1(3, b);

    Vector v2 = sm1.solve(v1);

    v2.print();
}