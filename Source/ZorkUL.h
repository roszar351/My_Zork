#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "weapon.h"
#include "bat.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>

#include "Character.h"

using namespace std;

class ZorkUL {

    friend class MainWindow;
private:
	Parser parser;
    Room *currentRoom;
    vector<Room*> allRooms;
    Character *player;
    int numOfTeleports;

	void createRooms();
	bool processCommand(Command command);
    void printHelp();
    void goRoom(Command command);
    void createItems();
    void displayItems();

public:
	ZorkUL();
	void play();
    string takeItem(string item);
    string printWelcome();
    string teleport();
    string showMap();
    string go(string direction);
    string combat(Enemy*);

};

#endif /*ZORKUL_H_*/
