#include "bat.h"

Bat::Bat(string name, int hp, int atkPow, string desc) : Enemy(name, hp, atkPow, desc)
{

}

int Bat::attack()
{
    // chance to miss
    if(rand() % 5 != 0)
        return ATKPow;
    else
        return 0;
}
