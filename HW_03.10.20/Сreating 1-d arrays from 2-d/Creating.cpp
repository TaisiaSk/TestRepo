#include <iostream>
#include <ctime>

int main()
{
	srand(time(NULL));

	std::cout << "Enter the number of rows (N): ";
	int N;
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

	int* arr_a = new int[N * M];
	int* arr_b = new int[N * M];
	int** arr = new int* [N];
	for (size_t i = 0; i < N; ++i)
		arr[i] = new int[M];

	std::cout << "Source array:\n";
	for (size_t i = 0,idx=0; i < N; ++i)
	{
		for (size_t j = 0; j < M; ++j,++idx)
		{
			arr[i][j] = rand()%(B-A+1)+A;
			std::cout << arr[i][j] << ' ';
			arr_a[idx] = arr[i][j];
		}
		std::cout << '\n';
	}
	
	std::cout << "Array of rows:\n";
	for (size_t i = 0; i < N*M; ++i)
		std::cout<<arr_a[i]<<' ';

	std::cout << "\nArray of colums:\n";
	for (size_t i = 0, idx = 0; i < M; ++i)
		for (size_t j = 0; j < N; ++j, ++idx)
		{
			arr_b[idx] = arr[j][i];
			std::cout << arr_b[idx] << ' ';
		}
		
	std::cout << '\n';

	for (size_t i = 0; i < N; ++i)
		delete[] arr[i];

	delete[] arr;
	delete[] arr_a;
	delete[] arr_b;

	system("pause");
	return(0);
}