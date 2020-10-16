#include <iostream>
#include <ctime>

int main()
{
	srand(time(NULL));

	std::cout << "Enter the number of rows (N): ";
	int N, t;
	std::cin >> N;

	std::cout << "Enter the number of columns (M): ";
	int M;
	std::cin >> M;

	std::cout << "Enter A: ";
	int A;
	std::cin >> A;

	std::cout << "Enter B: ";
	int B;
	std::cin >> B;

	int** arr = new int* [N];
	for (size_t i = 0; i < N; ++i)
		arr[i] = new int[M];

	std::cout << "Source array:\n";
	for (size_t i = 0; i < N; ++i)
	{
		for (size_t j = 0; j < M; ++j)
		{
			arr[i][j] = rand() % (B - A + 1) + A;
			std::cout << arr[i][j] << ' ';
		}
		std::cout << '\n';
	}

	for (size_t i = 0; i < N; ++i)
		for (size_t idx = 0; idx <= i; ++idx)
		{
			for (int j = M - 1; j >= 0; --j)
			{
				if (j == M - 1)
					t = arr[i][j];
				else
					arr[i][j + 1] = arr[i][j];
			}
			arr[i][0] = t;
		}

	std::cout << "Array with shifted rows:\n";
	for (size_t i = 0; i < N; ++i)
	{
		for (size_t j = 0; j < M; ++j)
			std::cout << arr[i][j] << ' ';
		std::cout << '\n';
	}

	for (size_t i = 0; i < M; ++i)
		for (size_t idx = 0; idx <= i; ++idx)
		{
			for (int j = N - 1; j >= 0; --j)
			{
				if (j == N - 1)
					t = arr[j][i];
				else
					arr[j+1][i] = arr[j][i];
			}
			arr[0][i] = t;
		}

	std::cout << "Array with shifted colums:\n";
	for (size_t i = 0; i < N; ++i)
	{
		for (size_t j = 0; j < M; ++j)
			std::cout << arr[i][j] << ' ';
		std::cout << '\n';
	}
	
	for (size_t i = 0; i < N; ++i)
		delete[] arr[i];

	delete[] arr;
	
	system("pause");
	return(0);
}