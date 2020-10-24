#include <iostream>
#include <string>
#include "Header.h"

int calculationLengthOfString(std::string str)
{
    int count=0;
    for (size_t i = 0; i < str.size(); ++i)
        count++;
       
    return count;
}