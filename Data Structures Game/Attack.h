#ifndef ATTACK_H
#define ATTACK_H
#include <string>

class attack {
	public:
		std::string attackName;
		int damage;
		int accuracy;
		std::string message;
	public:
		attack(std::string attNa, int hurt, int hit, std::string talk);
		std::string getName();
		int getDamage();
		int getAccuracy();
		std::string getMessage();
};

#endif