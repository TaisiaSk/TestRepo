#include <iostream>
#include <math.h>

int main()
{
	std::cout << "Input your digit:"; // - #1
	unsigned int digit;
	std::cin >> digit;

	std::cout << "Input bit number: ";
	unsigned int number;
	std::cin >> number;

	std::cout << "Bit: "<< ((digit >> number) & 1) <<'\n';




	std::cout << "Input bit(a) index: ";  // - #2a
	unsigned int bit_a;
	std::cin >> bit_a;
	std::cout << "Result (2a): " << (digit |(1<<bit_a))<<'\n';


	std::cout << "Input bit(b) index: ";  // - #2b
	unsigned int bit_b;
	std::cin >> bit_b;
	std::cout << "Result (2b): " << (digit & ~(1<<bit_b)) << '\n';


	unsigned int bit_c;
	std::cin >> bit_c;
	std::cout << "Result (2c): " << (digit ^ (1<<bit_c)) << '\n';



	if ((digit & (digit << 1)) == 0)  // - #3
		std::cout << "By the way, your digit is power of two!\n";
	else
		std::cout << "Unfortunately your digit is not a power of two :( \n";


	system("pause");
	return(0);
}