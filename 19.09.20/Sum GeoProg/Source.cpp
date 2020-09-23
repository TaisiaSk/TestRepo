#include <iostream>

int main()
{
	std::cout << "Enter x (-1,1): ";
	double x;
	std::cin >> x;

	double y = x;

	std::cout << "Enter eps: ";
	double eps;
	std::cin >> eps;

	double sum = 1;

	while (abs(x) > eps)
	{
		sum += x;
		x = x*y;
	}
	
	std::cout << "Your sum: " << sum ;

	if (sum > 1 / (1 - y))
		std::cout << " > 1/(1-x)\n" ;
	else
		if (sum < 1 / (1 - y))
			std::cout << " < 1/(1-x)\n";
		else
			std::cout << " = 1/(1-x)\n";

	system("pause");
	return(0);
}