#include <iostream>

int main()
{
	std::cout << "Input decimal number: ";// - ex 5
	char dec[10];
	std::cin >> dec;

	std::cout << "Enter the number system (2-10): ";
	int n;
	std::cin >> n;

	if (n == 10)
		std::cout << "Result: " << dec << '\n';
	else
	{
		int digit = 0;
		for (int i = 0; i < strlen(dec); ++i)
		{
			digit = digit*10 + dec[i] - '0';
		}

		for (int j = 0; j<10; ++j)
		{
			if (digit > 0)
			{
				dec[j] = digit % n + '0';
				digit /= n;
			}
			else
				dec[j] = '\0';
		}

		char st;
		for (int i = 0; i < strlen(dec)/2; ++i)
		{
			st = dec[i];
			dec[i] = dec[strlen(dec) - 1 - i];
			dec[strlen(dec) - 1 - i] = st;
		}
		std::cout << "Result: " << dec << '\n';
	}

	system("pause");
	return(0);
}