#include <iostream>

int calculationLengthOfString(char str[]){
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

void bondingStrings(char str1[],char str2[],char* str3){
    size_t len1 = 0;
    while (str1[len1] != '\0') {
        str3[len1] = str1[len1];
        len1++;
    }
    size_t len2 = 0;
    while (str2[len2] != '\0') {
        str3[len1 + len2] = str2[len2];
        len2++;
    }
    str3[len1 + len2] = '\0';
}

int main() {
    std::cout << "Enter the first string:";
    char str1[256];
    std::cin.getline(str1, 256);
    std::cout << "Enter the second string: ";
    char str2[256];
    std::cin.getline(str2, 256);

    size_t len = calculationLengthOfString(str1) + calculationLengthOfString(str2);
    char* str3=new char[len+1];
    bondingStrings(str1, str2, str3);
    std::cout << str3 << '\n';

    delete[] str3;
    system("pause");
    return(0);
}