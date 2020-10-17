#include <iostream>
#include <ctime>

int main()
{
	srand(time(NULL));

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
			arr[i][j] = rand() % 201 - 100;

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

	int point;
	int column=-1;
	for (size_t i = 0; i < row; ++i)
	{
		point = arr[i][0];
		for (size_t j = 1; j < col; ++j)
			if (arr[i][j] > point)
			{
				point = arr[i][j];
				column = j;
			}
		if (column > -1)
			for (size_t idx = 0; idx < row; ++idx)
				if (arr[idx][column] >= point)
				{
					if (idx == row - 1)
						std::cout << '(' << i << ',' << column << ') ' << arr[i][column] << '  ';
					else
						continue;
				}
		column = -1;
	}

	std::cout << '\n';


	for (size_t i = 0; i < row; ++i)
		delete[] arr[i];
	delete[] arr;

	system("pause");
	return(0);
}