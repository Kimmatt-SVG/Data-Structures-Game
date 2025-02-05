#ifndef ENEMY_H
#define ENEMY_H
#include <string>

class enemy {
public:
	//members
	int health;
	int strength;
	std::string name;
	
public:
	//constructors
	enemy(int battleHealth, int str, std::string Nname);
	//getters
	int getHealth();
	int getStrength();
	std::string getName();
	//setters
	void setHealth(int newHealth);

	//methods]
	int randomAtkValue();
};

class goblin : public enemy {

public:
	//members
	
public:
	//constructors
	goblin(int battleHealth, int str, std::string Nname);
	//getters

	//setters

	//methods




};
#endif