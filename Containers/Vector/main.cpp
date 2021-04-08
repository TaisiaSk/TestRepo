#include <iostream>
#include "vector.h"

int main()
{
    Vector<int> vec(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << *vec.begin() << '\n';

    for (int example : vec)
        std::cout << example << ' ';
    std::cout << '\n';

    vec.erase(++vec.begin());

    for (int example : vec)
        std::cout << example << ' ';

    system("pause");
    return 0;
}