#include "Character.h"

	character::character(int cappedHealth, int battleHealth, int challenge, int fast) : maxHealth(cappedHealth), health(battleHealth), level(challenge), speed(fast) {}

	int character::getMaxHealth() {
		return maxHealth;
	}
	int character::currentHealth() {
		return health;
	}
	int character::currentLevel() {
		return level;
	}
	int character::getSpeed() {
		return speed;
	}