#include <iostream>
#include "matrix.h"


int main()
{
    size_t rows, cols;
    std::cout << "Input the number of rows ";
    std::cin >> rows;
    std::cout << "Input the number of columns ";
    std::cin >> cols;

    Matrix example(rows,cols);
    example.FillRandom(-50, 50);
    example.Print();
    std::cout << "Determinant: " << example.det() << '\n';
    std::cin >> example;
    std::cout << example;
    
    std::cout << example + example; 
    std::cout << example - example; 
    std::cout << example * example;

    std::cout << "Number of rows: " << example.getRows() << '\n';
    std::cout << "Number of columns: " << example.getCols() << '\n';

    std::cout << "Input row number ";
    std::cin >> rows;
    std::cout << "Input column number ";
    std::cin >> cols;
    std::cout << "Your element: " << example.getValue(rows,cols) << '\n';

    std::cout << "The norm of the matrix: " << example.Norm() << '\n';

    example.transposed().Print();

    
    system("pause");
    return 0;
}