#include "goblin.h"

	// Constructor for goblin class
	goblin::goblin(int cappedHealth, int battleHealth, int challenge, int fast, int str, int magicMana, int expLeft,
		const attack& pokeAttack, const attack& shankAttack, const std::string& goblinName)
		: enemy(cappedHealth, battleHealth, challenge, fast, str, magicMana, expLeft),
		poke(pokeAttack), shank(shankAttack), name(goblinName) {
	}

	// Getters
	std::string goblin::getName() {
		return name;
	}

	attack goblin::getPoke() {
		return poke;
	}

	attack goblin::getShank() {
		return shank;
	}
