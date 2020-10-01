#include <iostream>
#include <stdlib.h>


int main()
{
	std::cout << "Input you string: "; // - ex. 2
	char str[20];
	std::cin.getline(str, 20);

	for (int i = 0; i < 20; ++i)
	{
		if (str[i] == tolower(str[i]))
			str[i]=toupper(str[i]);
		else
			str[i]=tolower(str[i]);
	}

	std::cout << str << '\n';



	std::cout << "Input string (digit): "; // - ex. 3
	char bin[256];
	std::cin.getline(bin, 256);
	
	for (size_t i = 0; i < strlen(bin); ++i)
	{
		if (i == strlen(bin)-1)
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

	for (size_t i = 0; i <= strlen(num); ++i)
	{
		if (num[i] == '1')
			digit += (1 << (strlen(num)-i-1));

	}

	char result[9] ;
	for (size_t j = strlen(result);j>=0;--j)
	{
		if (digit > 0)
		{
			result[j] = digit % 10 + '0';
			digit /= 10;
		}
		else
		{
			result[j] = 0;
		}
	}

	std::cout << "Decimal: " << result << '\n';
	

	system("pause");
	return(0);
}