#include <iostream>
#include <cmath>

int main()
{
	std::cout << "Enter digit: ";//-9
	int digit;
	std::cin >> digit;

	int k = 0;
	while (digit > 0)
	{
		if (digit % 2 == 1)
			++k;
		digit >>= 1;
	}

	//do k += digit % 2; while (digit /= 2);

	std::cout << "Number of 1: " << k << '\n';


	std::cout << "Enter your digit: ";//-10
	unsigned int digit1;
	std::cin >> digit1;

	std::cout << "Enter a positive number to shift to the left or a negative number to shift to the right: ";
	int x;
	std::cin >> x;


	if (x < 0)
	{
		x = abs(x);

		for (; x > 0; --x)
			if (digit1 % 2 == 1)
				digit1 = (digit1 >> 1) | (1 << (sizeof(int)*8 - 1));
			else
				digit1 >>= 1;

		std::cout << "Result: " << digit1 << '\n';
	}

	else
	{
		for (; x > 0; --x)
			if ((digit1 >>(sizeof(int)*8-1))&1 == 1)
				digit1 = ((digit1 << 1) | 1);
			else
				digit1 = (digit1 << 1);

		std::cout << "Result: " << digit1 << '\n';
	}
	
		
	system("pause");
	return(0);
}
