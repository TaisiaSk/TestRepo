#include <iostream>

int main()
{
	int size;
	std::cout << "Enter size: "; 
	std::cin >> size;
	int* arr1 = new int[size];
	int* arr2 = new int[size];
	int* arr3 = new int[size];
	int scalar = 0;
	double norm = 0;

	for (size_t idx = 0; idx < size; ++idx)
	{
		arr1[idx] = rand() % 200 - 100;
		arr2[idx] = rand() % 200 - 100;
		arr3[idx] = arr1[idx] + arr2[idx];
		norm += arr3[idx] * arr3[idx];
		scalar += arr1[idx] * arr2[idx];
	}

	std::cout << "The first array: " << '\n';
	for (size_t idx = 0; idx < size; ++idx)
	{
		std::cout << arr1[idx] << ' ';
	}

	std::cout <<'\n'<< "The second array: " << '\n';
	for (size_t idx = 0; idx < size; ++idx)
	{
		std::cout << arr2[idx] << ' ';
	}

	std::cout << '\n' << "The third array: " << '\n';
	for (size_t idx = 0; idx < size; ++idx)
	{
		std::cout << arr3[idx] << ' ';
	}
	
	std::cout << '\n' << "Scalar product of arrays: " << scalar << '\n';
	std::cout << "The norm of the array-sum: " << sqrt(norm) << '\n';
	

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	system("pause");
	return(0);
}