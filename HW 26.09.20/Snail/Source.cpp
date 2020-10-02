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

	int snail[Rows][Cols];
	int digit = 1;

	if (flag)
	{
		for (int i = 0; digit<=Cols*Rows;++i)
		{
			for (size_t rows = i; rows < Rows-i; ++rows)
				snail[rows][i] = digit++;

			for (size_t cols = i + 1; cols < Cols-i; ++cols)
				snail[Rows-1-i][cols] = digit++;
			
			for (int rows = Rows - 2-i; rows >= i; --rows)
				snail[rows][Cols-1-i] = digit++;

			for (int cols = Cols - 2-i; cols >= i+1; --cols)
				snail[i][cols] = digit++;
		}
	}
	else
	{
		for (int i = 0; digit <= Cols * Rows; ++i)
		{
			for (size_t cols = i; cols < Cols - 1-i; ++cols)
				snail[i][cols] = digit++;

			for (size_t rows = i ; rows < Rows - i; ++rows)
				snail[rows][Cols-1-i] = digit++;

			for (int cols = Cols - 2 - i; cols >= i+1; --cols)
				snail[Rows-1-i][cols] = digit++;

			for (int rows = Rows - 1 - i; rows >= i + 1; --rows)
				snail[rows][i] = digit++;
		}
	}

	for (size_t rows = 0; rows < Rows; ++rows)
	{
		for (size_t cols = 0; cols < Cols; ++cols)
			std::cout << snail[rows][cols] << ' ';

		std::cout << '\n';
	}

	system("pause");
	return(0);
}