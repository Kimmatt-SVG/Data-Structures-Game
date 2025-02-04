#include "enemy.h"

enemy::enemy(int cappedHealth, int battleHealth, int challenge, int fast, int str, int magicMana, int expLeft)
		: character(cappedHealth, battleHealth, challenge, fast), strength(str), mana(magicMana), exp(expLeft) {
}

int enemy::getStrength() {
	return strength;
}

int enemy::getMana() {
	return mana;
}
int enemy::getExp() {
	return exp;
}