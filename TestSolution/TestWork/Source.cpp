#include <iostream>

int main()
{
	int x = 2;    //swap(x,y)
	int y = 3;
	x = x + y;
	y = x - y;
	x = x - y;
	std::cout << y<<" "<< x << '\n';

	system("pause");
	return(0);
}