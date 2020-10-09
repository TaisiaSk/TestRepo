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

	int zigzag[Rows][Cols];
	int digit = 1;
	
	if (flag)
	{
		for (int i = 0; i<Rows; ++i)
		{
			if (i % 2 == 0)
			{
				for (int rows = 0; rows <= i; ++rows)
					zigzag[rows][i-rows] = digit++;
			}
			else
			{
				for (int cols = 0; cols <= i; ++cols)
					zigzag[i-cols][cols] = digit++;
			}
		}

		for (int j = Cols-1; j >0; --j)
		{
			if (j % 2 == 1)
			{
				for (int cols = Cols-j; cols<Cols; ++cols)
					zigzag[j-cols][cols] = digit++;
			}
			else
			{
				for (int cols = Cols-1; cols >=j; --cols)
					zigzag[Cols-cols][cols] = digit++;
			}
		}


	}

	for (size_t rows = 0; rows < Rows; ++rows)
	{
		for (size_t cols = 0; cols < Cols; ++cols)
			std::cout << zigzag[rows][cols] << ' ';

		std::cout << '\n';
	}

	system("pause");
	return(0);
}