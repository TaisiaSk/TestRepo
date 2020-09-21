#include <iostream>

int main()
{
	std::cout << "Enter Fahrenheit start degrees: ";
	double fahrenheit_start;
	std::cin >> fahrenheit_start;

	std::cout << "Enter Fahrenheit end degrees: ";
	double fahrenheit_end;
	std::cin >> fahrenheit_end;

	std::cout << "Enter Fahrenheit step degrees: ";
	double fahrenheit_step;
	std::cin >> fahrenheit_step;

	std::cout << "Fahrenheit    Celsius    Status\n";

	for (; fahrenheit_end > fahrenheit_start; fahrenheit_start += fahrenheit_step)
	{
		double celsius = 5. / 9 * (fahrenheit_start - 32);
	
		std::cout << fahrenheit_start<<"    "<<celsius<<"    ";
		if (celsius > 30)
			std::cout << "HOT!\n";
		else if (celsius < 15)
			std::cout << "COLD!\n";
		else
			std::cout << "NORM!\n";

		//fahrenheit_start += fahrenheit_step;
}
	//Monster alternative using ternary condition operator
	//Be careful, young padavan! Use wisely.
	//std::cout << "This is ";
	//std::cout << ((celsius > 30) ? "hot" : ((celsius < 15) ? "cold" : "ok"));
	//std::cout << '\n';

	system("pause");
	return 0;
}