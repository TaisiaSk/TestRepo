#include <iostream>
#include "unit.h"
#include "functions.h"

// class GameManager
// cell* field[H][W]
// loop()
// 
// class Cell
// move()->offset
// наследники
// стена и агенты
// 
// class Render
// наследники
// console графика

int main()
{    
    srand(time(NULL));
    size_t kSize;
    std::cout << "Input the number of fighters ";
    std::cin >> kSize;

    Unit** units = new Unit* [kSize];
    for (size_t idx = 0; idx < kSize; ++idx)
    {
        if (rand() % 2)
            units[idx] = new Alien(50,10);
        else
            units[idx] = new Predator(50,10);
    }
       
    for (size_t idx = 0; idx < kSize-1; ++idx)
    {
        int i1 = rand() % kSize;
        int i2 = rand() % kSize;

        while (!units[i1]->alive())
            i1 = rand() % kSize;
        while (!units[i2]->alive())
            i2 = rand() % kSize;

        std::cout << "Fight!\n";
        fight(units[i1], units[i2]);
    }

    for (size_t idx = 0; idx < kSize; ++idx)
        if (units[idx]->alive())
            units[idx]->winRoar();

    system("pause");
    return 0;
}