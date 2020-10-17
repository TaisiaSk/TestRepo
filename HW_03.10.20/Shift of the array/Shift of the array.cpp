#include <iostream>
#include <ctime>

int main()
{
	srand(time(NULL));

	std::cout << "Enter size: ";
	int N,t;
	std::cin >> N;

	std::cout << "Enter A: ";
	int A;
	std::cin >> A;

	std::cout << "Enter B: ";
	int B;
	std::cin >> B;

	std::cout << "Enter size of shift (M): ";
	int M;
	std::cin >> M;

	int* arr = new int[N];
	
	std::cout << "Source array:\n";
	for (size_t i = 0; i < N; ++i)
	{
		arr[i] = rand() % (B - A + 1) + A;
		std::cout << arr[i] << ' ';

	}
	std::cout << '\n';

	if (M > 0)
	{
		for (size_t i = 0; i < M%N; ++i)
		{
			for (int j = N - 1; j >= 0; --j)
			{
				if (j == N - 1)
					t = arr[j];
				else
					arr[j + 1] = arr[j];
			}
			arr[0] = t;
		}

	}
	else
	{
		for (size_t i = 0; i < abs(M)%N; ++i)
		{
			for (size_t j = 0; j < N; ++j)
			{
				if (j == 0)
					t = arr[j];
				else
					arr[j-1] = arr[j];
			}
			arr[N-1] = t;
		}
	}

	std::cout << "Transformed array:\n";
	for (size_t i = 0; i < N; ++i)
		std::cout << arr[i] << ' ';

	std::cout << '\n';

	delete[] arr;

	system("pause");
	return(0);
}