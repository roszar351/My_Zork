#include "Room.h"
#include "Command.h"


Room::Room(string description, int trapDmg) {
	this->description = description;
    trap = trapDmg;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
	if (north != NULL)
		exits["north"] = north;
	if (east != NULL)
		exits["east"] = east;
	if (south != NULL)
		exits["south"] = south;
	if (west != NULL)
		exits["west"] = west;
}

string Room::shortDescription() {
	return description;
}

string Room::longDescription() {
	return "room = " + description + ".\n" + displayItem() + exitString();
}

string Room::exitString() {
	string returnString = "\nexits =";
	for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
		// Loop through map
		returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
	return returnString;
}

Room* Room::nextRoom(string direction) {
	map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
	if (next == exits.end())
		return NULL; // if exits.end() was returned, there's no room in that direction.
	return next->second; // If there is a room, remove the "second" (Room*)
				// part of the "pair" (<string, Room*>) and return it.
}

void Room::addItem(Item *inItem) {
    //cout <<endl;
    //cout << "Just added" + inItem->getLongDescription();
    itemsInRoom.push_back(inItem);
}

void Room::addEnemy(Enemy *enemy)
{
    enemiesInRoom.push_back(enemy);
}

string Room::displayItem()
{
    string tempString = "items = ";

    if (itemsInRoom.size() < 1)
    {
        tempString = "No items here...";
    }
    else if (itemsInRoom.size() > 0)
    {
        for (unsigned int x = 0; x < itemsInRoom.size(); x++)
        {
            tempString = tempString + itemsInRoom[x]->getShortDescription();
            if(x != itemsInRoom.size() - 1)
                tempString += ", ";
        }
    }
    return tempString;
}

int Room::numberOfItems() {
    return itemsInRoom.size();
}

Item* Room::isItemInRoom(string inString)
{
    if (itemsInRoom.size() < 1)
        return nullptr;
    else if (itemsInRoom.size() > 0)
    {
       for (unsigned int x = 0; x < itemsInRoom.size(); x++)
       {
            // compare inString with short description
            bool tempFlag = util::containsStringIgnoreCase(itemsInRoom[x]->getShortDescription(), inString);
            if (tempFlag)
            {
                Item *temp = itemsInRoom[x];
                itemsInRoom.erase(itemsInRoom.begin()+x);
                return temp;
            }
       }
    }

    return nullptr;
}

int Room::getTrap()
{
    return trap;
}

Enemy* Room::getEnemy()
{
    if(enemiesInRoom.size() <= 0)
        return nullptr;
    else
    {
        return enemiesInRoom[0];
    }
}

void Room::killEnemy(int index)
{
     enemiesInRoom.erase(enemiesInRoom.begin() + index);
}
