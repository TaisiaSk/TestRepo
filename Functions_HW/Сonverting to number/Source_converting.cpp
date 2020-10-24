#include <iostream>
#include "Header.h"

int main()
{
    std::cout << "Enter any string: ";
    char str[256];
    std::cin.getline(str,256);

    int value = convertingStringToNumber(str);
    std::cout << "Result: " << value << '\n';

    system("pause");
    return(0);
}