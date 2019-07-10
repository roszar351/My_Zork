#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"

class Weapon : public Item
{
public:
    Weapon (string, float, float, int);
    virtual int getATK();
    virtual string getLongDescription();
private:
    int ATKPow;
};

#endif // WEAPON_H
