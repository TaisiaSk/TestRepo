#include <iostream>

int main()
{
	std::cout << "Enter the first digit: ";
	unsigned int digit1;
	std::cin >> digit1;

	std::cout << "Enter the second digit: ";
	unsigned int digit2;
	std::cin >> digit2;

	unsigned int result=0;

	for (int i = 0; digit1 > 0 || digit2 > 0; i += 2)
	{
		result |= (((digit2 & 1) | ((digit1 & 1) << 1))<<i);
		digit1 >>= 1;
		digit2 >>= 1;
	}

	
	std::cout << "Result: " << result << '\n';

	system("pause");
	return(0);
}