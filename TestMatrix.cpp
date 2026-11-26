#include "Matrix.h"

#include <iostream>


int main()
{
    Matrix a(5,5,1);
    Matrix b(10,10);
    Matrix c = a;
    a = b;
    return 0;
}