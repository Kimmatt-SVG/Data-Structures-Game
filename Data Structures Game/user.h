#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include <iostream>
#include "Character.h"
#include "Inventory.h"
#include "Attack.h"

class user : public character {
public:
	int strength;
	int mana;
	std::vector<inventory> userInventory;
	std::string name;
	int exp;
	attack attack1;
	attack attack2;
public:
	user(int cappedHealth, int battleHealth, int challenge, int fast, int str, int magicMana, std::string userName, int expLeft, const attack& firstAttack, const attack& secondAttack);
	attack getAttack1();
	attack getAttack2();
	int getStrength();
	int getMana();
	int getExp();
	std::string getName();
	void addItem(const inventory& item);
	void removeItem(int index);
	void displayInventory();
	void useItem(int index);
	void increaseStrength(int amount);
	void restoreMana(int amount);
	void speedIncrease(int amount);
	void displayStats();
};

#endif
