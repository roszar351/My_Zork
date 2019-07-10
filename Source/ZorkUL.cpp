#include <iostream>

using namespace std;
#include "ZorkUL.h"

ZorkUL::ZorkUL() {
    createRooms();
    player = new Character("Rogmon");
    player->addItem(new Weapon("Wooden Sword", 1, 5, 5));
    numOfTeleports = 0;
}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;

    a = new Room("Poor Village");
        a->addItem(new Item("Poorly drawn Map", 0.25, 2));
    allRooms.push_back(a);
    b = new Room("A Dark Forest", 10);
        b->addEnemy(new Bat());
        b->addEnemy(new Bat());
        b->addItem(new Item("Amazingitem0.5", 0.5, 10));
        b->addItem(new Item("Ogre's head", 4.5, 40));
    allRooms.push_back(b);
    c = new Room("The Fairy Forest");
        c->addItem(new Item("Amazingitem2", 2, 40));
    allRooms.push_back(c);
    d = new Room("A Dangerous Crossroad", 15);
    allRooms.push_back(d);
    e = new Room("The King's Path");
    allRooms.push_back(e);
    f = new Room("A Crossroad");
        f->addEnemy(new Bat());
    allRooms.push_back(f);
    g = new Room("Dwarven Kingdom");
        g->addItem(new Item("Amazingitem", 1, 20));
        g->addItem(new Item("Dwarven Beer", 1, 1));
    allRooms.push_back(g);
    h = new Room("'Venkom' Caves");
        h->addEnemy(new Bat());
        h->addItem(new Weapon("Sword of Destiny", 5.2f, 100, 999));
    allRooms.push_back(h);
    i = new Room("Rocky Mountains", 5);
        i->addItem(new Item("Sign with a skull", 2, 0));
    allRooms.push_back(i);
    j = new Room("King's Hill");
        j->addItem(new Item("Jeweled Crown", 2, 999));
    allRooms.push_back(j);

//             (N, E, S, W)
	a->setExits(f, b, d, c);
	b->setExits(NULL, NULL, NULL, a);
	c->setExits(NULL, a, NULL, NULL);
	d->setExits(a, e, NULL, i);
    e->setExits(NULL, j, NULL, d);
	f->setExits(NULL, g, a, h);
	g->setExits(NULL, NULL, NULL, f);
	h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
    j->setExits(NULL, NULL, NULL, e);
        currentRoom = a;
}

/**
 *  Main play routine.  Loops until end of play.
 */
//void ZorkUL::play() {
//	printWelcome();

//	// Enter the main command loop.  Here we repeatedly read commands and
//	// execute them until the ZorkUL game is over.

//	bool finished = false;
//	while (!finished) {
//		// Create pointer to command and give it a command.
//		Command* command = parser.getCommand();
//		// Pass dereferenced command and check for end of game.
//		finished = processCommand(*command);
//		// Free the memory allocated by "parser.getCommand()"
//		//   with ("return new Command(...)")
//		delete command;
//	}
//	cout << endl;
//	cout << "end" << endl;
//}

string ZorkUL::printWelcome() {
//	cout << "start"<< endl;
//	cout << "info for help"<< endl;
//	cout << endl;
//	cout << currentRoom->longDescription() << endl;
    string msg = "Welcome!\nYou are on a quest to find the divine king's artefacts, "
                 "the long lost Sword of Destiny and the king's precious crown. These"
                 " will allow you to become the new king of the world."
                 "\n\n" + currentRoom->longDescription() + "\n";

    return msg;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
//bool ZorkUL::processCommand(Command command) {
//	if (command.isUnknown()) {
//		cout << "invalid input"<< endl;
//		return false;
//	}

//	string commandWord = command.getCommandWord();
//	if (commandWord.compare("info") == 0)
//		printHelp();

//	else if (commandWord.compare("map") == 0)
//		{
//        cout << "[h] --- [f] --- [g]" << endl;
//        cout << "         |         " << endl;
//        cout << "         |         " << endl;
//        cout << "[c] --- [a] --- [b]" << endl;
//        cout << "         |         " << endl;
//        cout << "         |         " << endl;
//        cout << "[i] --- [d] --- [e] --- [j]" << endl;
//		}

//	else if (commandWord.compare("go") == 0)
//		goRoom(command);

//    else if (commandWord.compare("take") == 0)
//    {
//       	if (!command.hasSecondWord()) {
//            cout << "incomplete input"<< endl;
//        }
//        else if (command.hasSecondWord())
//        {
//            cout << "you're trying to take " + command.getSecondWord() << endl;

//            int location = currentRoom->isItemInRoom(command.getSecondWord());

//            if (location  < 0 )
//                cout << "item is not in room" << endl;
//            else
//                cout << "item is in room" << endl;

//            cout << "index number " << + location << endl;
//            cout << endl;
//            cout << currentRoom->longDescription() << endl;
//        }
//    }

//    else if (commandWord.compare("put") == 0)
//    {

//    }
//    /*
//    {
//    if (!command.hasSecondWord()) {
//		cout << "incomplete input"<< endl;
//        }
//        else
//            if (command.hasSecondWord()) {
//            cout << "you're adding " + command.getSecondWord() << endl;
//            itemsInRoom.push_Back;
//        }
//    }
//*/
//    else if (commandWord.compare("quit") == 0) {
//		if (command.hasSecondWord())
//			cout << "overdefined input"<< endl;
//		else
//			return true; /**signal to quit*/
//	}
//    else if (commandWord.compare("teleport") == 0)
//    {
//        cout << "Teleport!" << endl;
//        teleport();
//    }
//	return false;
//}

/** COMMANDS **/
void ZorkUL::printHelp() {
    cout << "valid inputs are: " << endl;
	parser.showCommands();
}

string ZorkUL::takeItem(string item)
{
    Item *temp = currentRoom->isItemInRoom(item);

    if (temp == nullptr)
    {
        delete(temp);
        return item + " is not in the room!\n" + currentRoom->longDescription() + "\n";
    }

    player->addItem(temp);
    return temp->getShortDescription() + " added to inventory!\n\n" + currentRoom->longDescription() + "\n";
}

string ZorkUL::teleport()
{
    string msg = "";
    int randNum = rand() % allRooms.size();

    currentRoom = allRooms[randNum];
    msg += "Teleported!\n";
    numOfTeleports++;
    //cout << currentRoom->longDescription() << endl;
    if(numOfTeleports >= 5)
    {
        msg += "Teleporting is causing you fatigue, becareful not to overdo it...(chance to take dmg from teleport: " + to_string(int((numOfTeleports - 5.0) / numOfTeleports * 100)) + "%)\n";
        if(rand() % numOfTeleports > 5)
        {
            if(player->damage(20) < 1)
                return "You died from teleporting too much.";
            msg += "You took 20 dmg from teleporting!\n";
        }
    }
    msg += currentRoom->longDescription() + "\n";
    return msg;
//    if(!command.hasSecondWord())
//    {
//        cout << "incomplete input" << endl;
//        return;
//    }

//    string destination = command.getSecondWord();

//    for(unsigned int i = 0; i < allRooms.size(); i++)
//    {
//        if(destination.compare(allRooms[i]->shortDescription()) == 0)
//        {
//            currentRoom = allRooms[i];
//            cout << currentRoom->longDescription() << endl;
//            return;
//        }
//    }
//    cout << "invalid room" << endl;
}

void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}

string ZorkUL::showMap()
{
    string temp = "Here is the map:\n\n";
    temp += "[h] --- [f] --- [g]\n";
    temp += "           |         \n";
    temp += "           |         \n";
    temp += "[c] --- [a] --- [b]\n";
    temp += "           |         \n";
    temp += "           |         \n";
    temp += "[i] --- [d] --- [e] --- [j]\n";

    return temp;
    //return "[h] --- [f] --- [g]\n         |         \n         |         \n[c] --- [a] --- [b]\n         |         \n         |         \n[i] --- [d] --- [e] --- [j]\n";
}

string ZorkUL::go(string direction)
{
	Room* nextRoom = currentRoom->nextRoom(direction);
    string temp = "";

	if (nextRoom == NULL)
        return "Wrong direction!\n" + currentRoom->longDescription() + "\n";
	else
	{
		currentRoom = nextRoom;
        Enemy* enemyInRoom = currentRoom->getEnemy();
        if(enemyInRoom != nullptr)
        {
            string combatLog = combat(enemyInRoom);
            if(player->damage(0) < 1)
                return combatLog;
            temp += combatLog;
        }
        // Only trigger traps if no enemies
        else
        {
            int trapDmg = currentRoom->getTrap();
            if(trapDmg)
            {
                if(player->damage(trapDmg) < 1)
                    return "You were killed by a trap.";

                temp = "You took " + to_string(trapDmg) + " damage!\n" + currentRoom->shortDescription() + " is full of traps! Better not to walk through here too often...\n";
            }
        }
        return temp + currentRoom->longDescription() + "\n";
	}
}

string ZorkUL::combat(Enemy* enemyInRoom)
{
    string temp = "---COMBAT LOG---\nYou have encountered an enemy:\n" + enemyInRoom->longDescription() + "\n";
    int enemiesKilled = 0;
    while(enemyInRoom != nullptr)
    {
        int eDmg = enemyInRoom->attack();
        temp += "You did: " + to_string(player->ATKPow) + "dmg\tYou took: " + to_string(eDmg) + "dmg\n";
        if(player->damage(eDmg) < 1)
            return temp + "--END OF LOG---\n\nYou were killed by a " + enemyInRoom->shortDescription() + "\n";
        if(enemyInRoom->damage(player->ATKPow) < 1)
        {
            enemiesKilled++;
            temp += "You killed a " + enemyInRoom->shortDescription() + "\nYou leveled up!\n";
            currentRoom->killEnemy();
            ++(*player);
            delete(enemyInRoom);
            enemyInRoom = currentRoom->getEnemy();
            if(enemyInRoom != nullptr)
            {
                temp += "You encountered another enemy!\n" + enemyInRoom->longDescription() + "\n";
            }
        }
    }
    temp += "---END OF LOG---\nYou leveled up " + to_string(enemiesKilled) + " time(s). Healing you for " + to_string(enemiesKilled * 25) + ", and increasing your stats.\n\n";
    return temp;
}
