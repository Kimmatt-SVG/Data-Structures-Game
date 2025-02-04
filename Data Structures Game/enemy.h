#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"

class enemy : public character {
public:
	int strength;
	int mana;
	int exp;
public:
	enemy(int cappedHealth, int battleHealth, int challenge, int fast, int str, int magicMana, int expLeft);
	int getStrength();
	int getMana();
	int getExp();
};
#endif