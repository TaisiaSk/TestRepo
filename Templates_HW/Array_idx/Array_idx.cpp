#include <iostream>

template <typename Type>
void change_arr(Type& arr, Type& arr_idx, Type& arr_res, const int size) {
    for (int i = 0; i < size; ++i)
        arr_res[arr_idx[i]] = arr[i];
}

template <typename Type, typename Type2, typename Type3>
void intersection(Type& arr,Type2& arr2,Type3& arr_res2, const int Size, const int Size2,int& count) {
    size_t k = 0;
    for (size_t i = 0; i < Size; ++i)
        for (size_t j = 0; j < Size2; ++j)
            if (arr[i] == arr2[j]) {
                arr_res2[k++] = arr[i];
                ++count;
            }
}

template <typename Type, typename Type2, typename Type3>
void unification(Type& arr, Type2& arr2, Type3& arr_res3, const int Size, const int Size2, int& count) {
    bool flag=1;
    for (size_t i = 0; i < Size; ++i)
        arr_res3[count++] = arr[i];
    for (size_t i = 0; i < Size2; ++i) {
        for (size_t j = 0; j < Size; ++j)
            if (arr2[i] == arr[j]) {
                flag = 0;
                break;
            }
        if (flag)
            arr_res3[count++] = arr2[i];
        flag = 1;
    }  
}

template <typename Type, typename Type2, typename Type3>
void difference(Type& arr, Type2& arr2, Type3 arr_res4, const int Size, const int Size2, int& count) {
    for (int i = 0; i < Size; ++i) {
        bool flag = 1;
        for (int j = 0; j < Size2; ++j) {
            if (arr[i] == arr2[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            arr_res4[count++] = arr[i];
        }
   }
    for (int i = 0; i < Size2; ++i) {
        bool flag = 1;
        for (int j = 0; j < Size; ++j) {
            if (arr2[i] == arr[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            arr_res4[count++] = arr2[i];
        }
    }
}

//invalid
/*template<typename Type, typename Type1>
void kkk(Type& arr_13,int Size,const int SizeB, Type1& arr_res5, int& count) {
    if (Size == 1) {
        arr_res5[count++][SizeB - 1] = arr_13[0];
        return;
    }
    for (int i = 0; i < Size; i++) {
        Type* arr_ = new Type[Size - 1];
        int k = 0;
        bool flag = 0;
        for (int j = 0; j < Size; j++) {
            if (j == i) {
                flag = 1;
            }
            if (j != i) {
                (*arr_)[k++] = arr_13[j];
            }
        }
        arr_res5[count][SizeB - Size] = arr_13[0];
        kkk(*arr_, Size - 1, SizeB, arr_res5, count);
    }
}*/


int main() {
    int arr[] = { 1,2,3,4,5,6 };
    int arr_idx[] = { 3,0,2,5,4,1 };
    const int Size=sizeof(arr)/4;
    int arr_res[Size];
    int arr2[] = { 4,3,8,9,1,0 };
    const int Size2 = sizeof(arr2) / 4;
    int arr_res2[Size];
    int arr_res3[Size + Size2];
    int arr_res4[Size + Size2];
    
   change_arr(arr, arr_idx, arr_res, Size);
    for (int i = 0; i < Size; ++i)
        std::cout << arr_res[i] << ' ';
    std::cout << '\n';

    int count = 0;
    intersection(arr, arr2, arr_res2, Size, Size2,count);
    for(size_t i = 0; i < count; ++i)
        std::cout << arr_res2[i] << ' ';
    std::cout << '\n';

    int count1 = 0;
    unification(arr, arr2, arr_res3, Size, Size2, count1);
    for (size_t i = 0; i < count1; ++i)
        std::cout << arr_res3[i] << ' ';*/
    /*
    int count2 = 0;
    difference(arr, arr2, arr_res4, Size, Size2, count2);
    for (int i = 0; i < count2; i++) {
        std::cout << arr_res4[i] << ' ';
    }
    
    /*int count3 = 0;
    int arr13[] = { 1,2,3 };
    const int Size13 = sizeof(arr13) / 4;
    int fac = 1;
    for (int i = 1; i < Size13; i++) {
        fac *= (i + 1);
    }
    int** arr_res5 = new int*[fac];
    for (int i = 0; i < fac; ++i)
        arr_res5[i] = new int[Size13];

    kkk(arr13, Size13, Size13, arr_res5, count3);

    for (int i = 0; i < fac; i++) {
        for (int j = 0; j < Size13; j++) {
            std::cout << arr_res5[i][j] << ' ';
        }
        std::cout << '\n';
    }*/

    system("pause");
    return 0;
}