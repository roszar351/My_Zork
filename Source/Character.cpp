#include "Character.h"

Character::Character(string description,int s, int d, int c)
{
	this->description = description;
    strength = s;
    dexterity = d;
    stamina = c;
    ATKPow = s / 3;
    hp = int(100 + stamina / 2);
    maxHp = hp;
    head = "( ͡° ͜ʖ ͡°)\n";
    bestWeaponDmg = 0;
}

// Level up the character
Character& Character::operator++()
{
    strength += rand() % 3 + 1;
    dexterity += rand() % 3 + 1;
    stamina += rand() % 3 + 2;
    ATKPow = bestWeaponDmg + strength / 3;
    maxHp = int(100 + stamina / 2);
    heal(25);
    emit change();

    return *this;
}

void Character::addItem(Item *item)
{
    itemsInCharacter.push_back(item);
    checkItemForSignals(item->getShortDescription());
    if(item->getATK() > bestWeaponDmg)
    {
        bestWeaponDmg = item->getATK();
        ATKPow = bestWeaponDmg + strength / 3;
    }
    emit this->change();
    checkForWin();
}

void Character::checkItemForSignals(const string &s)
{
    if(s.compare("Poorly drawn Map") == 0)
        emit pickedMap();
    else if(s.compare("Jeweled Crown") == 0)
    {
        ++(*this);
        emit pickedCrown();
    }
    else if(s.compare("Sword of Destiny") == 0)
    {
        ++(*this);
        emit pickedSoD();
    }
}

string Character::longDescription()
{
  string ret = this->description + "\n";

  ret += head;
  ret += "    |    \n";
  ret += "   /|\\  \n";
  ret += "  / | | \n";
  ret += "    |    \n";
  ret += "   / \\  \n";
  ret += "  /   | \n";

  ret += "HP: " + to_string(hp) + "\nSTR: " + to_string(strength) + "\tDEX: " + to_string(dexterity) + "\tCON: " + to_string(stamina);
  ret += "\nATK: " + to_string(ATKPow) + "\n";

  ret += "\nItem list:\nName,   Weight,   Value,   ATKPow\n";
  for (vector<Item*>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
    ret += (*i)->getLongDescription() + "\n";
  return ret;
}

// Checks if character hp is under 1hp, if so send signal that the player lost and update the head of the player's avatar
void Character::checkHealth()
{
    if(hp < 1)
    {
        head = "( X ʖ̯ X)\n";
        emit this->lose();
    }
}

// Looks through character's inventory looking for item(s) required to win
void Character::checkForWin()
{
    bool sword = false;
    bool crown = false;

    for (vector<Item*>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
    {
        string temp = (*i)->getShortDescription();
        if(temp.compare("Sword of Destiny") == 0)
            sword = true;
        if(temp.compare("Jeweled Crown") == 0)
            crown = true;
    }
    if(sword && crown)
    {
        emit this->win();
    }
}
