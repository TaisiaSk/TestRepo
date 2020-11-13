#include <iostream>

/*bool check_palindrome(char* str, int len,int i) {
    if(len-2*i<1)
        return true;
    if (str[i] != str[len - 1-i]) 
        return false;
    check_palindrome(str, len,++i);
}*/

bool check_palindrome(char* str, int len) {
    if (len <= 0)
        return true;
    if (str[0] != str[len - 1])
        return false;
    check_palindrome(str + 1, len - 2);
}

int main()
{
    char str[] = "abcdcba";

    std::cout << check_palindrome(str, 7) << '\n';

    system("pause");
    return 0;
}