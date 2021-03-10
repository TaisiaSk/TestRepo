#pragma once
#include <iostream>

class Unit
{
protected:
    double _baseHealth;
    double _health;
    double _strength;

public:  
    Unit(double baseHealth , double strength ) :_baseHealth(baseHealth), _strength(strength) { heal(); }

    virtual void roar()const = 0;
    virtual void status()const = 0;
    virtual void winRoar()const = 0;

    void hit(Unit* unit)
    {
        double damage = (double)_strength * (rand() % 6);
        unit->takeHit(damage);
    }

    void takeHit(double damage)
    {
        _health -= damage;
    }

    bool alive() const
    {
        return _health > 0;
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
    void winRoar()const override { std::cout << "I'm an Alien! I'm a winner! Sh-kr-sh-krr!!!\n"; }
public:
    Alien(double baseHealth, double strength ) :Unit(baseHealth, strength ) {}
};

class Predator :public Unit
{
protected:
    void roar()const override { std::cout << "Arr-rr-r\n"; }
    void status()const override { std::cout << "Predator's health " << _health << '\n'; }
    void winRoar()const override { std::cout << "I'm a Predator! I'm a winner! Arr-rr-r!!!\n"; }
public:
    Predator(double baseHealth, double strength) :Unit(baseHealth, strength) {}
};