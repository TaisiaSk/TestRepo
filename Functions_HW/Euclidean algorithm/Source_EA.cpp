#include <iostream>
#include "Header_EA.h"

int main()
{
    std::cout << "Enter first value: ";
    int val1;
    std::cin >> val1;

    std::cout << "Enter second value: ";
    int val2;
    std::cin >> val2;

    int NOD = calculationNOD(val1, val2);
    std::cout << "Result: " << NOD << '\n';

    system("pause");
    return(0);
}