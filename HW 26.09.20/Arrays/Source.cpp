#include <iostream>

int main()
{
	const int Size = 10;
	int arr[Size];

	for (int idx = 0; idx < Size; ++idx)
	{
		arr[idx] = rand() % (sizeof(int)*8);
	}

	std::cout << "Source array:" << '\n';

	for (int idx = 0; idx < Size; ++idx)
	{
		std::cout << arr[idx] << ' ';
	}

	std::cout << '\n' << "Reverse array:" << '\n';

	char st;
	for (int idx =0; idx < Size; ++idx)
	{
		if (idx < Size / 2)
		{
			st = arr[idx];
			arr[idx] = arr[Size - 1 - idx];
			arr[Size - 1 - idx] = st;
		}

		std::cout << arr[idx] << ' ';
	}

	std::cout << '\n';

	system("pause");
	return(0);
}