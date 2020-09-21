#include <iostream>

int main()
{
	std::cout << "Enter x: ";
	double x;
	std::cin >> x;

	double y = x;

	std::cout << "Enter eps: ";
	double eps;
	std::cin >> eps;

	double sum = 1;

	while (abs(x) >= eps)
	{
		sum += x;
		x = x*y;
	}
	
	std::cout << "Your sum: " << sum << '\n';

	system("pause");
	return(0);
}