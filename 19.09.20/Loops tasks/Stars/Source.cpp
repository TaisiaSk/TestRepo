#include <iostream>


int main()
{
	std::cout << "Input the height of the right triangle: "; // - task 2
	int height1;
	std::cin >> height1;


	for (int i = 1; i <= height1; ++i)
	{
		for (int j = 0; j != i; ++j)
			std::cout << "*";
		std::cout << '\n';
	}



	std::cout << "Input the height of the isosceles triangle: "; // - task 3
	int height2;
	std::cin >> height2;

	for (int i = 0; i < height2; ++i)
	{
		for (int j = height2-i-1; j != 0; --j)
			std::cout << " ";
		for (int y = 0; y != 2*i+1; ++y)
			std::cout << "*";
		std::cout << '\n';
	}



	std::cout << "Input the height of the rombus: "; // - task 4
	int height3;
	std::cin >> height3;

	for (int i = 0; i < height3-height3/2; ++i)
	{
		for (int j = height3 / 2 +i+1; j != height3; ++j)
			std::cout << " ";
		for (int y = 0; y != 2 * i + 1; ++y)
			std::cout << "*";
		std::cout << '\n';
	}

	for (int i = height3/2; i !=0; --i)
	{
		for (int j = height3-height3/2; j != i; --j)
			std::cout << " ";
		for (int y = 2*i-1; y != 0; --y)
			std::cout << "*";
		std::cout << '\n';
	}



	std::cout << "Input the height of the hollow rombus: "; // - task 4(a)
	int height4;
	std::cin >> height4;

	for (int i = 0; i < height4/2; ++i) 
	{
		for (int j = 0; j < height4; ++j)
			if (j - i == height4 - height4 / 2 - 1||i+j== height4 - height4 / 2 - 1)
				std::cout << "*";
			else
				std::cout << " ";
		std::cout << '\n';
	}

	for (int i = height4 / 2; i <height4 ; ++i)
	{
		for (int j = 0; j < height4; ++j)
			if (i - j == height4 / 2||i+j==2*(height4-1)-height4/2)
				std::cout << "*";
			else
				std::cout << " ";
		std::cout << '\n';
	}



	std::cout << "Input the height of the checkered rombus: "; // - task 4(b)
	int height5;
	std::cin >> height5;

	for (int i = 0; i < height5 - height5 / 2; ++i)
	{
		for (int j = height5 / 2 + i + 1; j != height5; ++j)
			std::cout << " ";
		for (int y = 0; y != 2 * i + 1; ++y)
			if (y % 2 == 0)
				std::cout << "*";
			else
				std::cout << " ";
		std::cout << '\n';
	}

	for (int i = height5 / 2; i != 0; --i)
	{
		for (int j = height5 - height5 / 2; j != i; --j)
			std::cout << " ";
		for (int y = 2 * i - 1; y != 0; --y)
			if (y % 2 == 1)
				std::cout << "*";
			else
				std::cout << " ";
		std::cout << '\n';
	}
	

	system("pause");
	return(0);
}