#include <iostream>
#include <string>
#include "Header.h"

int main()
{
    std::cout << "Enter any string: ";
    std::string str;
    getline(std::cin, str);

    int length = calculationLengthOfString(str);
    std::cout << "Length of string: " << length << '\n';

    system("pause");
    return(0);
}