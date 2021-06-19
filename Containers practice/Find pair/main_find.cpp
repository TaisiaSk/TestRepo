#include <iostream>
#include <utility>
#include <map>

std::pair<int, size_t> function(int const* arr, size_t Size, int target)
{
    std::pair<int, size_t> result;
    std::map<int, size_t> mate;
    for (size_t i = 0; i < Size; ++i)
        mate.insert(std::pair<int, size_t>(arr[i],i));

    for (auto it = mate.rbegin(); it != mate.rend(); ++it)
        if (it->first < target)
        {
            for (auto it2 = mate.begin(); it2 != mate.end(); ++it2)
            {
                if ((it->first + it2->first) == target)
                {
                    result.first = it2->second;
                    result.second = it->second;
                    return result;
                }
                if ((it->first + it2->first) > target)
                    break;
            }
        }   
}

int main()
{
    std::cout << "Input size of array: ";
    size_t Size;
    std::cin >> Size;
    int* arr = new int[Size];
    std::cout << "Input data: ";
    for (size_t idx = 0; idx < Size; ++idx)
        std::cin>>arr[idx];
    std::cout << "Input target: ";
    int target;
    std::cin >> target;

    std::pair<int, size_t> test = function(arr, Size, target);
    std::cout << test.first << ' ' << test.second << '\n';

    system("pause");
    return 0;
}