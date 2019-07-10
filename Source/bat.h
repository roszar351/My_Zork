#ifndef BAT_H
#define BAT_H

#include "Enemy.h"

class Bat : public Enemy
{
public:
    Bat(string = "Bat", int = 25, int = 8, string = "It's a bat...scary...");
    virtual int attack();
};

#endif // BAT_H
