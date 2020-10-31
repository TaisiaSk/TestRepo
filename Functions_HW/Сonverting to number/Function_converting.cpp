#include <iostream>
#include "Header.h"

int convertingStringToNumber(char str[])
{
    int len = strlen(str);
    int val = 0;
    int dec = 1;
    for (int i = len - 1; i >= 0; --i)
    {
        val += (str[i]-'0') * dec;
        dec *= 10;
    }
    return val;
}