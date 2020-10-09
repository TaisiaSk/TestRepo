#include <iostream>

int main()
{
	std::cout << "Input decimal number: ";// - ex 5
	char dec[10];
	std::cin >> dec;

	std::cout << "Enter the number system (2-10): ";
	int n;
	std::cin >> n;

	size_t size = strlen(dec);

	if (n == 10)
		std::cout << "Result: " << dec << '\n';
	else
	{
		int digit = 0;
		for (int i = 0; i < size; ++i)
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
		size = strlen(dec);
		char st;
		for (int i = 0; i < size /2; ++i)
		{
			st = dec[i];
			dec[i] = dec[size - 1 - i];
			dec[size - 1 - i] = st;
		}
		std::cout << "Result: " << dec << '\n';
	}

	system("pause");
	return(0);
}