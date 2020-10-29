#include <iostream>
#include "Header.h"

int main()
{
    std::cout << "Enter any string: ";
    char str[256];
    std::cin.getline(str, 256);

    int length = calculationLengthOfString(str);
    std::cout << "Length of string: " << length << '\n';

    system("pause");
    return(0);
}