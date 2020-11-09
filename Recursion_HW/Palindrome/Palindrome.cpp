#include <iostream>

bool check_palindrome(char* str, int len,int i) {
    if(len-2*i<1)
        return true;
    if (str[i] != str[len - 1-i]) {
        return false;
    }
    else
        check_palindrome(str, len,++i);
}

int main()
{
    char str[] = "abcdcba";

    std::cout << check_palindrome(str, 7, 0) << '\n';

    system("pause");
    return 0;
}