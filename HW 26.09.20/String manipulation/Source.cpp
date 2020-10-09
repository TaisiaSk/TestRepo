#include <iostream>
#include <stdlib.h>
#include <string>

int main()
{
	std::cout << "Input you string: "; // - ex. 2
	char str[20];
	std::cin.getline(str, 20);

	for (int i = 0; i < 20; ++i)
	{
		if (str[i] <= 90 && str[i] >= 65)
			str[i] += 32;

		else if (str[i] <= 122 && str[i] >= 97)
			str[i] -= 32;
	}

	std::cout << str << '\n';



	std::cout << "Input string (digit): "; // - ex. 3
	char bin[256];
	std::cin.getline(bin, 256);
	
	size_t size = strlen(bin);

	for (size_t i = 0; i < size; ++i)
	{
		if (i == size-1)
			std::cout << "Binary number!" << '\n';


		if (bin[i] == '1' ||  bin[i] == '0')
				continue;
		
		else
		{
			std::cout << "No" << '\n';
			break;
		}

	}



	std::cout << "Enter an eight-bit binary number: ";// - ex.4
	char num[9];
	std::cin.getline(num, 9);

	int digit = 0;
	size_t len = strlen(num);
	for (size_t i = 0; i < len; ++i)
	{
		if (num[i] == '1')
			digit += (1 << (len-i-1));

	}

	for (size_t i = 0; i < len;++ i)
	{
		if (digit > 0)
			num[i] = digit % 10 + '0';
		else
			num[i] = '\0';
		digit /= 10;
	}

	len = strlen(num);

	char st;
	for (int i = 0; i < len/2; ++i)
	{
		st = num[i];
		num[i] = num[len - 1-i];
		num[len - 1-i] = st;
	}
		
	std::cout << "Decimal: " << num << '\n';
	

	system("pause");
	return(0);
}