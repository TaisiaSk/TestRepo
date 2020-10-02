#include <iostream>

int main()
{
	bool flag;
	std::cout << "Enter the direction (left or down): "; 
	char dir[5];
	std::cin >> dir;
	if (dir[0] == 'd')
		flag = true;
	else
		flag = false;

	const int Rows = 3;
	const int Cols = 4;

	int snake[Rows][Cols];
	int digit = 1;

	if (flag)
	{
		for (size_t cols = 0; cols < Cols; ++cols)
		{
			if (cols % 2 == 0)
				for (size_t rows = 0; rows < Rows; ++rows)
					snake[rows][cols] = digit++;
			else
				for (int rows = Rows - 1; rows >= 0; --rows)
					snake[rows][cols] = digit++;
		}
	}
	else
	{
		for (size_t rows = 0; rows < Rows; ++rows)
		{
			if (rows % 2 == 0)
				for (size_t cols = 0; cols < Cols; ++cols)
					snake[rows][cols] = digit++;
			else
				for (int cols = Cols - 1; cols >= 0; --cols)
					snake[rows][cols] = digit++;
		}
	}

	for (size_t rows = 0; rows < Rows; ++rows)
	{
		for (size_t cols = 0; cols < Cols; ++cols)
			std::cout << snake[rows][cols] << ' ';

		std::cout << '\n';
	}

	system("pause");
	return(0);
}