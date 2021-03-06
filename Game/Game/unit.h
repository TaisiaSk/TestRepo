#pragma once
#include <iostream>

class Unit
{
public:
    double _baseHealth;
    double _health;
    double _strength;

    Unit(double baseHealth = 0, double strength = 0) :_baseHealth(rand() % 1001), _strength(rand() % 101) { heal(); }

    virtual void roar()const = 0;
    virtual void status()const = 0;

    void hit(Unit& unit)
    {
        double damage = _strength * (rand() % 6);
        unit.takeHit(damage);
    }

    void takeHit(double damage)
    {
        _health -= damage;
    }

    bool alive() const
    {
        if (_health > 0)
            return true;
        return false;
    }

    void heal()
    {
        _health = _baseHealth;
    }
};

class Alien :public Unit
{
protected:
    void roar()const override { std::cout << "Sh-kr-sh-krr\n"; }
    void status()const override { std::cout << "Alien's health " << _health << '\n'; }
public:
    Alien() :Unit() {}
};

class Predator :public Unit
{
protected:
    void roar()const override { std::cout << "Arr-rr-r\n"; }
    void status()const override { std::cout << "Predator's health " << _health << '\n'; }
public:
    Predator() : Unit() {}
};