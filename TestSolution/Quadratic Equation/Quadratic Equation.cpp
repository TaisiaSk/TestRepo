#include <iostream>
#include <cmath>

int main() 
{
	std::cout << "Input a: ";
	double a;
	std::cin >> a;
		
	std::cout << "Input b: ";
	double b;
	std::cin >> b;

	std::cout << "Input c: ";
	double c;
	std::cin >> c;

	if (a == 0)
	{
		double root = -c / b;
		std::cout << "Your root: " << root << '\n';
	}
	else
	{

		double D = b * b - 4 * a * c;
		if (D < 0)
			std::cout << "No roots" << '\n';
		else if (D == 0) {
			double root = -b / (2 * a);
			std::cout << "Only one root: " << root << '\n';
		}
		else {
			double x1 = (-b + std::sqrt(D)) / (2 * a);
			double x2 = (-b - std::sqrt(D)) / (2 * a);
			std::cout << "First root: " << x1 << '\n';
			std::cout << "Second root: " << x2 << '\n';
		}
	}
		
	system("pause");
	return(0);
}
