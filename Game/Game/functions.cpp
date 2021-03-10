#include <iostream>
#include "unit.h"
#include "functions.h"

void fight(Unit* u1, Unit* u2)
{
    if (rand() % 2)
    {
        Unit* tmp = u1;
        u1 = u2;
        u2 = tmp;
    }

    while (u1->alive() && u2->alive())
    {
        u1->roar();
        u1->hit(u2);
        u2->status();

        if (u2->alive())
        {
            u2->roar();
            u2->hit(u1);
            u1->status();
        }
    }

    if (u1->alive())
        u1->heal();
    else
        u2->heal();
}
