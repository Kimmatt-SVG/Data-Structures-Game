#include "enemy.h"
#include <random>

//Enemy Class

//constructors
enemy::enemy(int battleHealth, int str, std::string Nname) {
	health = battleHealth;
	strength = str;
	name = Nname;
}
//getters
int enemy::getHealth() {
	return health;
}
int enemy::getStrength() {
	return strength;
}
std::string enemy::getName() {
	return name;
}
//setters
void enemy::setHealth(int newHealth) {
	health = newHealth;
}

//methods]
//genertes random attack value
int enemy::randomAtkValue() {
	std::random_device rd;   // Seed generator
	std::mt19937 gen(rd());  // Random number generator (Mersenne Twister)
	std::uniform_int_distribution<int> distr(strength - 10, strength); // range
	return distr(gen);
}



//Goblin Class

//constructors
goblin::goblin(int battleHealth, int str, std::string Nname) : enemy(battleHealth, str, Nname) {
	name = Nname;
	health = battleHealth;
}

//getters

//setters

//methods