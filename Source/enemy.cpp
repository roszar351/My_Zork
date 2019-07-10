#include "enemy.h"

Enemy::Enemy(string n, int h, int a, string d)
{
    name = n;
    hp = h;
    ATKPow = a;
    desc = d;
}

string Enemy::shortDescription()
{
    return name;
}

string Enemy::longDescription()
{
    return name + "\n" + desc;
}

int Enemy::damage(const int &dmg)
{
    hp -= dmg;
    return hp;
}

int Enemy::attack()
{
    return ATKPow;
}
