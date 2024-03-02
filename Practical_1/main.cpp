#include <iostream>

#include "Vector.h"

void vectorTests();

int main()
{
    vectorTests();

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