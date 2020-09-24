#include <iostream>

int main()
{
	std::cout << "Enter the calculation accuracy: ";
	double x;
	std::cin >> x;

	double a = 1;
	double pi=0;

	for (int i = 1; a >= x; ++i, a = 1. / (2 * i + 1))
		if (i % 2 == 1)
			pi += a;
		else
			pi -= a;
	

	pi = 4 * pi;
	
	if (pi == 0)
		std::cout << "Invalid input\n";
	else
		std::cout << "Your pi: " << pi << '\n';
	
	system("pause");
	return(0);
}