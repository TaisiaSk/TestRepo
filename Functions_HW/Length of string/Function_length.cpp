#include <iostream>
#include "Header.h"

int calculationLengthOfString(char str[])
{
    int count=0;
    while (str[count] != '\0') {
        count++;
    }
       
    return count;
}