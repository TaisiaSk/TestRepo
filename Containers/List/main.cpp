#include <iostream>
#include "list.h"

int main()
{
    List<int> list;
    list.push_back(3);
    list.push_back(2);
    list.push_back(1);
    list.push_back(0);

    for (auto it = list.begin(); it != list.end(); ++it)
        std::cout << *it << " ";
    std::cout << '\n';

    list.erase(++list.begin());

    for (auto it = list.begin(); it != list.end(); ++it)
        std::cout << *it << " ";

    system("pause");
    return 0;
}