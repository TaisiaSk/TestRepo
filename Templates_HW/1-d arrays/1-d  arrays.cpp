#include <iostream>
#include <ctime>

template <typename Type>
Type* new_array(const size_t Size){
    return new Type[Size];
}

void fill_random_array(int* arr,
                       const size_t Size,
                       const int Lb=-100,
                       const int Ub=100)
{
    for (size_t idx = 0; idx < Size; ++idx)
        arr[idx] = rand() % (Ub - Lb + 1) + Lb;
}

void print_array(const int* arr, const size_t Size){
    for (size_t idx = 0; idx < Size; ++idx)
        std::cout << arr[idx] << '\t';
    std::cout << '\n';
}

//task 2
template <typename Type>
Type* min_and_following(const Type* arr,
                        const size_t Size) {
    if (Size == 1) {
        Type* arr1 = new Type[1];
        arr1[0] = arr[0];
        return arr1;
    }
        Type* arr1 = new Type[2];
        arr1[0] = arr[0];
        arr1[1] = arr[1];
        for (size_t i = 1; i < Size; ++i) {
            if (arr[i] < arr1[0]) {
                arr1[1] = arr1[0];
                arr1[0] = arr[i];
            }
            else if (arr[i] < arr1[1]) {
                arr1[1] = arr[i];
            }
        }
        return arr1;
}

int main() {
    srand(time(NULL));

    std::cout << "Enter size of array: ";
    size_t Size;
    std::cin >> Size;

    int* arr=new_array<int>(Size);
    fill_random_array(arr, Size);
    std::cout << "Source array:\n";
    print_array(arr, Size);
    int* result = min_and_following(arr, Size);
    if (Size != 1)
        std::cout << "Minimum " << result[0] << " and following minimum " << result[1] << '\n';
    else
        std::cout << "Minimum " << result[0] << '\n';
    
    system("pause");
    return(0);
}