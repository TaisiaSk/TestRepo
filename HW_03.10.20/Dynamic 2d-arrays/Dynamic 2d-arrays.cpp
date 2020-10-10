#include <iostream>
#include <ctime>

int main()
{
	srand(time(NULL));

	int row;
	std::cout << "Enter the number of rows: ";
	std::cin >> row;
	int** arr1 = new int* [row];
	int** arr2 = new int* [row];
	int** arr3 = new int* [row];
	
	int col;
	std::cout << "Enter the number of columns: ";
	std::cin >> col;
	
	for (size_t idx = 0; idx < row; ++idx)
	{
		arr1[idx] = new int[col];
		arr2[idx] = new int[col];
		arr3[idx] = new int[col];
	}


	for (size_t i = 0; i < row; ++i)
		for (size_t j = 0; j < col; ++j)
		{
			arr1[i][j] = rand() % 201 - 100;
			arr2[i][j] = rand() % 201 - 100;
			arr3[i][j] = arr1[i][j] + arr2[i][j];
		}



	std::cout << "The first 2D-array: " << '\n';
	for (size_t i = 0; i < row; ++i)
	{
		for (size_t j = 0; j < col; ++j)
		{
			std::cout << arr1[i][j] << ' ';
		}
		std::cout << '\n';
	}



	std::cout << "The second 2D-array: " << '\n';
	for (size_t i = 0; i < row; ++i)
	{
		for (size_t j = 0; j < col; ++j)
		{
			std::cout << arr2[i][j] << ' ';
		}
		std::cout << '\n';
	}



	std::cout << "The third 2D-array: " << '\n';
	for (size_t i = 0; i < row; ++i)
	{
		for (size_t j = 0; j < col; ++j)
		{
			std::cout << arr3[i][j] << ' ';
		}
		std::cout << '\n';
	}



	int** arr1_tr = new int* [col];
	for (size_t idx = 0; idx < col; ++idx)
		arr1_tr[idx] = new int[row];

	for (size_t i = 0; i < col; ++i)
		for (size_t j = 0; j < row; ++j)
		{
			arr1_tr[i][j] = arr1[j][i];
		}

	std::cout << "Transpose the first array: " << '\n';
	for (size_t i = 0; i < col; ++i)
	{
		for (size_t j = 0; j < row; ++j)
		{
			std::cout << arr1_tr[i][j] << ' ';
		}
		std::cout << '\n';
	}



	int** product = new int*[row];
	for (size_t idx = 0; idx < row; ++idx)
		product[idx] = new int[row];

	for (size_t i = 0; i < row; ++i)
		for (size_t j = 0; j < row; ++j)
		{
			product[i][j] = 0;
			for (size_t idx = 0; idx < col; ++idx)
				product[i][j] += arr1[i][idx] * arr1_tr[idx][j];
		}

	std::cout << "Product of the first array by the transposed one: " << '\n';
	for (size_t i = 0; i < row; ++i)
	{
		for (size_t j = 0; j < row; ++j)
		{
			std::cout << product[i][j] << ' ';
		}
		std::cout << '\n';
	}



	for (size_t i = 0; i < row; ++i)
	{
		delete[] arr1[i];
		delete[] arr2[i];
		delete[] arr3[i];
		delete[] product[i];
	}

	for (size_t i = 0; i < col; ++i)
		delete[] arr1_tr[i];
		
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr1_tr;
	delete[] product;

	system("pause");
	return(0);
}