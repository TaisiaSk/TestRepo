#include <iostream>
#include <ctime>

void fillMatrix(size_t size,double** arr)
{
    for (size_t i = 0; i < size; ++i)
    {
        arr[i] = new double[size];
        for (size_t j = 0; j < size; ++j)
            arr[i][j] = rand() % 202 - 101;
    }
}

void printMatrix(size_t size, double** arr)
{
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
            std::cout << arr[i][j] << "\t";
        std::cout << '\n';
    }
}

void matrixToTriangle(size_t size,double** arr)
{
    double koificient;
    for (size_t i = 0; i < size-1; i++)
    {
        if (arr[i][i] == 0) {
            for (size_t l = 0; l < size; ++l) {
                if (arr[l][i] != 0) {
                    for (size_t k = 0; k < size; ++k) {
                        arr[i][k] += arr[l][k];
                    }
                }
            }
        }
        for (size_t j = i+1; j < size; j++) {
            koificient = -arr[j][i] / arr[i][i];
            for (size_t k = i; k < size; ++k)
            {
                arr[j][k] += arr[i][k] * koificient;
            }
        }

    }
       
}

double detMatrix(size_t size, double** arr) {
    double det=1;
    for (size_t i = 0; i < size; ++i)
        det *= arr[i][i];
    return det;
}

int main()
{
    srand(time(NULL));
    std::cout << "Enter size of matrix: ";
    size_t size;
    std::cin >> size;
    double** arr = new double* [size];

    fillMatrix(size, arr);
    printMatrix(size, arr);
    std::cout << '\n';
    matrixToTriangle(size, arr);
    printMatrix(size, arr);
    std::cout << detMatrix(size,arr) << '\n';

    system("pause");
    return(0);
}