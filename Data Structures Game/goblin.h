#ifndef GOBLIN_H
#define GOBLIN_H
#include <string>
#include "attack.h"
#include "enemy.h"

class goblin : public enemy {

public:
	attack poke;
	attack shank;
	std::string name;
public:
	// Constructor for goblin class
	goblin(int cappedHealth, int battleHealth, int challenge, int fast, int str, int magicMana, int expLeft,
		const attack& pokeAttack, const attack& shankAttack, const std::string& goblinName);
	// Getters
	std::string getName();
	attack getPoke();
	attack getShank();

};

#endif