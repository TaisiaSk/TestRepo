#include <iostream>
#include <math.h>

int main()
{
	std::cout << "Radius of the outer circle: ";
	double R;
	std::cin >> R;

	std::cout << "Radius of the inner cicle: ";
	double r;
	std::cin >> r;

	std::cout << "Input coordinate x:  ";
	double x;
	std::cin >> x;

	std::cout << "Input coordinate y:  ";
	double y;
	std::cin >> y;


	double square_root = std::sqrt(x*x+y*y);
	if (square_root > R || square_root < r)
		std::cout << "Not belong\n";
	else
		std::cout << "Belong\n";



	system("pause");
	return(0);
}