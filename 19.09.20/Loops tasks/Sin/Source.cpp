#include <iostream>
#include <cmath>

int main()
{
	std::cout << "Enter x: ";
	double x;
	std::cin >> x;

	std::cout << "Enter the number of sinuses: ";
	int N;
	std::cin >> N;

	double S;
	S = sin(x);
	
	while (N-- > 1)
		S = sin(S);
	
	std::cout << "Result: " << S << '\n';


	system("pause");
	return(0);
}