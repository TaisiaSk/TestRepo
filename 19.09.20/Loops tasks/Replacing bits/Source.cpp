#include <iostream>

int main()
{
	std::cout << "Enter digit: ";
	unsigned int digit;
	std::cin >> digit;

	for (int i = 0;i<sizeof(int)*8 ;i+=2)
	{
		if (((digit >> i) & 1) != ((digit >> (i + 1)) & 1))
			digit = (digit ^ (3 << i));

		std::cout << digit << '\n';
	}

	std::cout << "Result: " << digit << '\n';

	system("pause");
	return(0);
}