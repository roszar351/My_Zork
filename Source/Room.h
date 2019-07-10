#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>

#include "item.h"
#include "enemy.h"
#include "utilityfunctions.h"

using namespace std;
using std::vector;

class Room {

private:
	string description;
	map<string, Room*> exits;
	string exitString();
    vector <Item*> itemsInRoom;
    vector <Enemy*> enemiesInRoom;
    int trap;

public:
    int numberOfItems();
    Room(string description, int = 0);
	void setExits(Room *north, Room *east, Room *south, Room *west);
	string shortDescription();
	string longDescription();
	Room* nextRoom(string direction);
    void addItem(Item *inItem);
    void addEnemy(Enemy *enemy);
    string displayItem();
    Item* isItemInRoom(string inString);
    void removeItemFromRoom(int location);
    int getTrap();
    bool fight();
    Enemy* getEnemy();
    void killEnemy(int = 0);
};

#endif
