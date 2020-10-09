#include <iostream>

int main()
{
	int row;
	std::cout << "Enter the number of rows: ";
	std::cin >> row;
	int** arr = new int* [row];

	int col;
	std::cout << "Enter the number of columns: ";
	std::cin >> col;

	for (size_t idx = 0; idx < row; ++idx)
		arr[idx] = new int[col];

	for (size_t i = 0; i < row; ++i)
		for (size_t j = 0; j < col; ++j)
			arr[i][j] = rand() % 200 - 100;

	std::cout << "Array: " << '\n';
	for (size_t i = 0; i < row; ++i)
	{
		for (size_t j = 0; j < col; ++j)
		{
			std::cout << arr[i][j] << ' ';
		}
		std::cout << '\n';
	}

	std::cout << '\n' << "Saddle points: ";

	int point = -101;
	int column;
	for (size_t i = 0; i < row; ++i)
	{
		for (size_t j = 0; j < col; ++j)
			if (arr[i][j] > point)
			{
				point = arr[i][j];
				column = j;
			}
		for (size_t idx = 0; idx < row; ++idx)
		{
			if (arr[idx][column] < point)
			{
				point = -101;
				break;
			}
		}
		if (point > -101)
			std::cout << '(' << i << ',' << column << ') ' << arr[i][column] << '  ';
		point = -101;
	}

	std::cout << '\n';


	for (size_t i = 0; i < row; ++i)
		delete[] arr[i];
	delete[] arr;

	system("pause");
	return(0);
}