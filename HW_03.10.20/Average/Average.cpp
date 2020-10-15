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

	int* arr = new int[N];
	double average = 0.;
	int count = 0;

	std::cout << "Source array:\n";
	for (size_t i = 0; i < N; ++i)
	{
		arr[i] = rand() % (B - A + 1) + A;
		std::cout << arr[i] << ' ';

		if (arr[i] > 0 && arr[i] % 2 == 0)
		{
			average += arr[i];
			count++;
		}
	}
	std::cout << '\n';

	average/= count;

	std::cout <<"Average value of non-negative even elements: "<< average << '\n';

	delete[] arr;

	system("pause");
	return(0);
}