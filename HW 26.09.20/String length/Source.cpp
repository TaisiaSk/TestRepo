#include <iostream>

int main()
{
	std::cout << "Enter a string of zeros and ones: "; // - ex 7
	char str[20];
	std::cin >> str;

	short lenght0 = 0;
	short lenght1 = 0;
	short n;
	size_t size = strlen(str);

	for (int i = 0; i < size; ++i)
	{
		if (str[i] == '0')
		 lenght0++;

		else
		{
			if (lenght0 > lenght1) 
			{
				lenght1 = lenght0;
				n = i-lenght1+1;
			}
			lenght0 = 0;
		}
	}

	if (lenght0 > lenght1)
	{
		lenght1 = lenght0;
		n = size - lenght1+1;

	}
	
	std::cout << "Beginning of line: " << n << '\n';
	std::cout << "Lenght of zeros: " << lenght1 << '\n';

	system("pause");
	return(0);
}