#include <string>
#include <iostream>
#include "enemy.h"
#ifndef USER_H
#define USER_H

class user {
public:
	int health;
	int strength;
	int mana;
	std::string name;
public:
	//constructors
	user(int battleHealth, int str, int magicMana, std::string userName);
	//getters
	int getHealth();
	int getStrength();
	int getMana();
	std::string getName();
	//setters
	void setHealth(int newHealth);
	void setStrength(int newStrength);
	void setName(std::string newName);
	//methods
	int randomAtkValue();
	void battle(enemy& enemy);
};

#endif
