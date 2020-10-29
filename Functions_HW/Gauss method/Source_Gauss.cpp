#include <iostream>
#include "Header_G.h"
#include <ctime>

int main()
{
    srand(time(NULL));
    std::cout << "Enter size of matrix: ";
    size_t size;
    std::cin >> size;
    double** arr = new double* [size];

    fillMatrix(size, arr);
    printMatrix(size, arr);
    std::cout << '\n';
    matrixToTriangle(size, arr);
    printMatrix(size, arr);
    std::cout << detMatrix(size,arr) << '\n';

    system("pause");
    return(0);
}