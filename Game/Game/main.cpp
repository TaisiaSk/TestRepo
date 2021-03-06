#include <iostream>
#include "unit.h"
#include "functions.h"

int main()
{    
    Unit** units = new Unit* [10];
    for (size_t idx = 0; idx < 10; ++idx)
    {
        if (rand() % 2)
            units[idx] = new Alien();
        else
            units[idx] = new Predator();
    }
       
    for (size_t idx = 0; idx < 9; ++idx)
    {
        int i1 = rand() % 10;
        int i2 = rand() % 10;

        while (!units[i1]->alive())
            i1 = rand() % 10;
        while (!units[i2]->alive())
            i2 = rand() % 10;

        fight(units[i1], units[i2]);
    }

    for (size_t idx = 0; idx < 10; ++idx)
        if (units[idx]->alive())
            std::cout << "Winner " << idx << '\n';

    system("pause");
    return 0;
}