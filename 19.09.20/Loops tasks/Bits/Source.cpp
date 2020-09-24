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
			k++;
		digit=digit >> 1;
	}

	std::cout << "Number of 1: " << k << '\n';


	std::cout << "Enter your digit: ";//-10
	int digit1;
	std::cin >> digit1;
	std::cout << "Enter a positive number to shift to the left or a negative number to shift to the right: ";
	int x;
	std::cin >> x;

	int length=0;
	int a = digit1;
	while (a > 0) 
	{
		length++;
		a = a >> 1;
	}
	

	if (abs(x) != x)    
	{
		x = abs(x);

		for (; x > 0; x--)
			if (digit1 % 2 == 1)
				digit1 = (digit1 >> 1) | (1 << (length - 1));
			else
				digit1 = digit1 >> 1;

		std::cout << "Result: " << digit1 << '\n';
	}

	else                      
	{
		for (; x > 0; x--) 
			if (digit1 | (1 << (length - 1)) == digit1)
				digit1 = ((digit1 << 1) | 1) & ~(1 << length);
			else
				digit1 = (digit1 << 1) & ~(1 << length);

	std::cout << "Result: " << digit1 << '\n';
	}



	system("pause");
	return(0);
}
