#include <iostream>
#include "Rational_Fraction.h"

int main()
{
    Rational_Fraction frac(1, 2);
    Rational_Fraction frac1(5);
    Rational_Fraction frac2(0.4);
    std::cout << frac2 << '\n';
    std::cout << frac << ' ' << frac1 << '\n';
    std::cout << "Multiplication " << frac * frac1 << '\n';
    std::cout<<"Sum "<< frac + frac1 << '\n';
    std::cout << frac2.decimal() << ' '<< frac2.ceil()<<' ' << frac2.round() << '\n';
    system("pause");
    return 1;
}