#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>
#include <vector>

#include <QObject>

#include "weapon.h"

using namespace std;

class Character: public QObject
{
    Q_OBJECT
    friend class ZorkUL;
private:
	string description;
    int hp;
    int strength;
    int dexterity;
    int stamina;
    int ATKPow;
    int maxHp;
    int bestWeaponDmg;
    string head;
    vector <Item*> itemsInCharacter;
    void checkItemForSignals(const string&);

public:
    Character(string, int = 5, int = 5, int = 5);
    Character& operator++();

	string shortDescription();
    string longDescription();
    void addItem(Item*);

    // heal the player
    template <typename T> void heal(const T &heal)
    {
        if(hp + abs(int(heal)) < maxHp)
            hp += abs(int(heal));
        else
            hp = maxHp;
        emit change();
    }

    // Deal damage to character
    template <typename T> int damage(const T &dmg)
    {
        hp -= abs(int(dmg));
        checkHealth();
        emit this->change();
        return hp;
    }

private:
    void checkHealth();
    void checkForWin();

signals:
    // Sends a signal to update character information.
    void change();
    // Sends a signal that the player has won(currently picking up the "Sword Of Destiny")
    void win();
    // Sends a signal that the player has lost(having less than 1 hp, trapped rooms)
    void lose();
    // Sends a signal that the player has picked up the map, crown, sword of destiny
    void pickedMap();
    void pickedCrown();
    void pickedSoD();
};

#endif /*CHARACTER_H_*/
