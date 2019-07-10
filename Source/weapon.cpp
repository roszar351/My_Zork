#include "weapon.h"

Weapon::Weapon(string name, float weight, float value, int ATK) : Item(name, weight, value)
{
    ATKPow = ATK;
}

int Weapon::getATK()
{
    return ATKPow;
}

string Weapon::getLongDescription()
{
    return Item::getLongDescription() + ",  " + to_string(ATKPow) + "dmg";
}
