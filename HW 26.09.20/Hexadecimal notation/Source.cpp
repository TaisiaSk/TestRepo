#include <iostream>

int main()
{
	std::cout << "Input decimal number: ";// - ex 6
	char str[10];
	std::cin >> str;

	int digit = 0;
	for (int i = 0; i < strlen(str); ++i)
	{
		digit = digit * 10 + str[i] - '0';
	}

	for (int j = 0; j < 10; ++j)
	{
		if (digit > 0)
		{
			if (digit % 16 > 9)
			{
				str[j] = digit % 16 + '7';
				digit /= 16;
			}
			else
			{
				str[j] = digit % 16 + '0';
				digit /= 16;
			}
		}
		else
			str[j] = '\0';
	}

	char st;
	for (int i = 0; i < strlen(str) / 2; ++i)
	{
		st = str[i];
		str[i] = str[strlen(str) - 1 - i];
		str[strlen(str) - 1 - i] = st;
	}
	std::cout << "Result: " << str << '\n';

	system("pause");
	return(0);
}