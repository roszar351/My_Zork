# My_Zork
## Features of the program
---
* Resource files that appear when certain items are picked up e.g. map when you pick up the 'poorly drawn map'.
* Simulated combat & leveling.
* Teleporting too much has a chance to damage the player, but will avoid enemies and traps.
* Some rooms have traps and/or enemies in them.
* To pick up the item, type any part(at least 3 letters) of the item name(ignores case) into the box and click the 'Take' button or press the return key.
* Different messages depending on what caused the death of the player.
* Atk power gets increased by strength(1 point for every 3 strength points) and weapons(best weapon will be used).
* Hp(initial value 100) gets increased by stamina(1 point for every 2 stamina points)
* Win condition:  pick up 'Jeweled Crown' and 'Sword of Destiny'.
* Lose condition: lose all your hp i.e. hp < 1.
## Concepts used in the program
---
### Templates: 
* Used for the damage and heal functions in the character class.
### Operator overloading: 
* Overloaded the prefix '++' operator for the character to level them up.
### Friend classes: 
* The zorkul class is a friend of the character class, to access the character's atkpow,
* The mainwindow class is a friend of the zorkul class, to access the character object.
### Inheritance:
* Weapon inherits from item,
* Bat inherits from enemy.
## Tips:
* Pick up the map in the starting room(Poor Village).
* Don't go through trapped rooms too often.
* Don't use the teleport too often.
---
This project was made for CS4076(Event Driven Programming) module in second year, by: 
* Damian Skrzypek
