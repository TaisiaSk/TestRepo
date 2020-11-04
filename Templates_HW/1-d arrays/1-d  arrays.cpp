#include <iostream>
#include <ctime>

template <typename Type>
Type* new_array(const size_t Size){
    return new Type[Size];
}

void fill_random_array(int* arr,
                       const size_t Size,
                       const int Lb=-10,
                       const int Ub=10)
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

//task 3
template <typename Type>
Type frequent(const Type* arr, const size_t Size) {
    Type freq;
    size_t count = 1;
    size_t maxcount = 1;
    for (size_t i = 0; i < Size - 1; i++) {
        for (size_t j = i+1; j < Size; j++) {
            if (arr[i] == arr[j])
                count++;
        }
        if (count >= maxcount) {
            maxcount = count;
            freq = arr[i];
        }
        count = 1;
    }
    if (maxcount != 1)
        return freq;
    else
        return(0);
}

//task 4
template <typename Type>
Type* array_of_single_elements(const Type* arr, const size_t Size,int* len) {
    Type* arr_s = new Type[Size];
    int count = 0;
    int k = 0;
    for (size_t i = 0; i < Size; i++) {
        for (size_t j = 0; j < Size; j++)
            if (arr[i] == arr[j] && i != j)
                count++;
        if (count == 0)
            arr_s[k++] = arr[i];
        count = 0;
    }
    *len = k;
    return arr_s;
}

//task 5
template <typename Type>
void arrays_nonnegative_and_negative(const Type* arr,
                                        Type* arr_non,
                                        Type* arr_neg,
                                        const size_t Size,
                                        int* size_non,
                                        int* size_neg) {
    int len_non = 0, len_neg = 0;
    for (size_t i = 0; i < Size; ++i) 
        if (arr[i] < 0) 
            arr_neg[len_neg++] = arr[i];
        else 
            arr_non[len_non++] = arr[i];

    *size_non = len_non;
    *size_neg = len_neg;
    
}

//task 7
template <typename Type>
Type sum(const Type* arr, size_t i, const size_t Size) {
    if (i == Size - 1)
        return arr[i];
    return arr[i] + sum(arr, i + 1, Size);
}

//task 8
template <typename Type>
Type* insert_into_arr(const Type* arr, const size_t Size,Type num,Type idx) {
    Type* result = new Type[Size + 1];
    for (int i=0 ,k=0; k < Size+1;++k) {
        if (i == idx) {
            result[idx] = num;
            idx = -1;
        }
        else 
           result[k] = arr[i++];
    }
    return result;
}

//task 9
template <typename Type>
Type* insert_arr_into_arr(const Type* arr, const Type* arr_in, const size_t Size, const size_t Size_in, Type idx) {
    Type* result = new Type[Size + Size_in];
    for (int i = 0,k=0; i < Size + Size_in; ++i) 
        if (i == idx) {
            for (int j = 0; j < Size_in; ++j)
                result[i + j] = arr_in[j];
            i += Size_in-1;
        }
        else
            result[i] = arr[k++];
    return result;
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
        std::cout << "\nMinimum " << result[0] << " and following minimum " << result[1] << '\n';
    else
        std::cout << "\nMinimum " << result[0] << '\n';

    if (frequent(arr, Size) != 0)
        std::cout << "The most frequently encountered array element: " << frequent(arr, Size) << '\n';
    else
        std::cout << "All elements occur once." << '\n';

    std::cout << "\nArray of single elements:\n";
    int Size_s;
    int* arr_s = array_of_single_elements(arr, Size,&Size_s);
    for (size_t i = 0; i < Size_s; i++)
        std::cout << arr_s[i] << '\t';
    std::cout << '\n';

    int* arr_neg = new int[Size];
    int* arr_non = new int[Size];
    int size_non;
    int size_neg;
    arrays_nonnegative_and_negative(arr, arr_non, arr_neg, Size, &size_non, &size_neg);
    std::cout << "\nArray of non-negative elements:\n";
    for (size_t idx = 0; idx < size_non; ++idx)
        std::cout << arr_non[idx] << '\t';
    std::cout << '\n';
    std::cout << "Array of negative elements:\n";
    for (size_t idx = 0; idx < size_neg; ++idx)
        std::cout << arr_neg[idx] << '\t';
    std::cout << '\n';

    std::cout << "Sum of elements: " << sum(arr, 0, Size) << '\n';

    //for task 8
    std::cout << "Enter a number: ";
    int num;
    std::cin >> num;

    std::cout << "Enter a index: ";
    int idx;
    std::cin >> idx;

    int* arr_ins = insert_into_arr(arr, Size, num, idx);
    std::cout << "Array with the inserted element:\n";
    for (size_t i = 0; i < Size + 1; ++i)
        std::cout << arr_ins[i] << '\t';
    std::cout << '\n';

    //for task 9
    std::cout << "Enter size of inserted array: ";
    size_t Size_in;
    std::cin >> Size_in;

    int* arr_in = new_array<int>(Size_in);
    fill_random_array(arr_in, Size_in);
    std::cout << "Inserted array:\n";
    print_array(arr_in, Size_in);

    std::cout << "Enter a index: ";
    int idx9;
    std::cin >> idx9;

    int* arr_ins_arr = insert_arr_into_arr(arr,arr_in,Size,Size_in,idx9);
    std::cout << "Array with the inserted array:\n";
    for (size_t i = 0; i < Size + Size_in; ++i)
        std::cout << arr_ins_arr[i] << '\t';
    std::cout << '\n';
    
    delete[] arr;
    delete[] arr_s;
    delete[] arr_ins;
    delete[] arr_in;
    delete[] arr_ins_arr;
    system("pause");
    return(0);
}