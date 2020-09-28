#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
	std::cout << "Enter x: ";
	int x;
	std::cin >> x;

	std::cout << "Enter step dx: ";
	int dx;
	std::cin >> dx;

	std::cout << "Enter eps: ";
	int eps;
	std::cin >> eps;

	std::cout << "     f(x): " << "    " << "sin(x): \n";
	
	double result = x;
	int factorial = 1;
	for (int n = 1;  abs(result) > eps; ++n)
	{
		result = ((-1) ^ (n + 1) * x ^ (2 * n + 1)) /factorial;

		std::cout << "x" << n << "   ";
		std::cout << std::setw(8) << std::left;
		std::cout << result << "  " << sin(x) << '\n';
		x += dx;
		factorial *= (n*2) * (2*n + 1);
	}


	system("pause");
	return(0);
}