#ifndef CHARACTER_H
#define CHARACTER_H

class character {
public:
	int maxHealth;
	int health;
	int level;
	int speed;
public:
	character(int cappedHealth, int battleHealth, int challenge, int fast);
	int getMaxHealth();
	int currentHealth();
	int currentLevel();
	int getSpeed();
};

#endif