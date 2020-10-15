#include <iostream>
#include <ctime>

int main()
{
	srand(time(NULL));

	std::cout << "Enter size: ";
	int N;
	std::cin >> N;

	std::cout << "Enter A: ";
	int A;
	std::cin >> A;

	std::cout << "Enter B: ";
	int B;
	std::cin >> B;

	int* arr = new int [N];
	int max = A - 1;
	int min = B + 1;
		
	std::cout << "Source array:\n";
	for (size_t i = 0; i < N; ++i)
	{
		arr[i] = rand() % (B-A+1) + A;
		std::cout << arr[i] << ' ';
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	std::cout << '\n';

	std::cout << "Transformed array:\n";
	for (size_t i = 0; i < N; ++i)
	{
		if (arr[i] == max)
			std::cout << min << ' ';
		else if (arr[i] == min)
			std::cout << max << ' ';
		else
			std::cout << arr[i] << ' ';
	}

	std::cout << '\n';

	delete[] arr;

	system("pause");
	return(0);
}