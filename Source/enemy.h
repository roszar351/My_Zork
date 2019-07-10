#ifndef ENEMY_H
#define ENEMY_H

#include <string>

using namespace std;

class Enemy
{
public:
    Enemy(string = "Default enemy name", int = 0, int = 0, string = "Default enemy description");
    virtual string shortDescription();
    virtual string longDescription();
    virtual int damage(const int&);
    virtual int attack();

protected:
    string name;
    int hp;
    int ATKPow;
    string desc;
};

#endif // ENEMY_H
