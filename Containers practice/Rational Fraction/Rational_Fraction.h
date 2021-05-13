#pragma once
#include <iostream>

int gcd(int a, int b)
{
    while (b > 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

class Rational_Fraction
{
private:
    int _num, _den;
    const double eps = 1e6;

public:
    
    Rational_Fraction(int n, int d) : _num(n), _den(d) {}
    Rational_Fraction(int x) : _num(x), _den(1) {}
    Rational_Fraction(double x) 
    {
        _num = x * eps;
        _den = eps;
        reduce();
    }

    Rational_Fraction operator*(Rational_Fraction const& frac)
    {
        Rational_Fraction result(_num * frac._num, _den * frac._den);
        result.reduce();
        return result;
    }

    Rational_Fraction operator/(Rational_Fraction const& frac)
    {        
        Rational_Fraction result(_num * frac._den, _den * frac._num);
        result.reduce();
        return result;
    }

    Rational_Fraction operator+(Rational_Fraction const& frac)
    {
        Rational_Fraction result(_num * frac._den + frac._num * _den, _den * frac._den);
        result.reduce();
        return result;
    }

    Rational_Fraction operator-(Rational_Fraction const& frac)
    {
        Rational_Fraction result(_num * frac._den - frac._num * _den, _den * frac._den);
        result.reduce();
        return result;
    }

    operator int() { return _num / _den; }

    bool operator>(Rational_Fraction const& frac)
    {
        return(_num * frac._den > frac._num * _den);
    }

    bool operator<(Rational_Fraction const& frac) { return !(*this > frac); }


    double decimal()const { return (double)_num / _den; }
    int ceil()
    {
        int ceil = *this;
        if (!(decimal() - ceil))
            return ceil;
        return ++ceil;
    }
    int round()
    {
        int round = *this;
        if ((decimal() - round) >= 0.5)
            return ++round;
        return round;
    }

    int num()const { return _num; }
    int den()const { return _den; }
    
    void reduce()
    {
        int _gcd = gcd(abs(_num), _den);
        if (_gcd != 1)
        {
            _num /= _gcd;
            _den /= _gcd;
        }
    }
};

inline std::ostream& operator<<(std::ostream& out, Rational_Fraction const& obj)
{
    if (obj.den() == 1)
        return out << obj.num();
    return out << obj.num() << "/" << obj.den();
}