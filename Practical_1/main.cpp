#include <iostream>

#include "Vector.h"

int main()
{
    double *arr = new double[3];

    for (int i = 0; i < 3; i++)
    {
        arr[i] = i + 1;
    }

    Vector *v1 = new Vector(3);
    Vector *v2 = new Vector(*v1);
    Vector *v3 = new Vector(3, arr);

    v1->print();
    std::cout << std::endl;
    v2->print();
    std::cout << std::endl;
    v3->print();

    Matrix m = *v3;

    m.print();

    return 0;
}