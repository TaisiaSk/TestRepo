#include <iostream>
#include <ctime>

//task 1

template <typename Type>
Type* external_border(const int** arr,
					const size_t Rows,
					const size_t Cols) {
	int size = 0;
	Type* arr1 = new Type[2 * Rows + 2 * Cols - 4];
	for (size_t j = 0; j < Cols - 1; ++j){
		arr1[size] = arr[0][j];
		size++;
	}

	for (size_t i = 0; i < Rows - 1; ++i){
		arr1[size] = arr[i][Rows - 1];
		size++;
	}

	for (int j = Cols - 1; j > 0; --j){
		arr1[size] = arr[Rows - 1][j];
		size++;
	}

	for (int i = Rows - 1; i > 0; --i){
		arr1[size] = arr[i][0];
		size++;
	}
	return arr1;
}

void print_array(const int* arr, const size_t Size)
{
	for (size_t idx = 0; idx < Size; ++idx)
		std::cout << arr[idx] << '\t';
	std::cout << '\n';
}

int main() {
    srand(time(NULL));

	std::cout << "Enter the number of rows: ";
	int row;
	std::cin >> row;

	std::cout << "Enter the number of columns: ";
	int col;
	std::cin >> col;
		
	int** arr = new int* [row];
	for (size_t i = 0; i < row; ++i)
		arr[i] = new int[col];

	std::cout << "Source array:\n";
	for (size_t i = 0; i < row; ++i)
	{
		for (size_t j = 0; j < col; ++j)
		{
			arr[i][j] = rand() % 202 + 101;
			std::cout << arr[i][j] << '\t';
		}
		std::cout << '\n';
	}

	std::cout << "External border:\n";
	int* arr1=external_border<int>((const int**)arr, row, col);
	size_t Size = 2 * row + 2 * col - 4;
	print_array(arr1, Size);


	for (size_t i = 0; i < row; ++i)
		delete[] arr[i];

	delete[] arr;
	delete[] arr1;

    system("pause");
    return(0);
}