#include "Attack.h"
#include <string>


attack::attack(std::string attNa, int hurt, int hit, std::string talk) : attackName(attNa), damage(hurt), accuracy(hit), message(talk) {}

std::string attack::getName() {
	return attackName;
}
int attack::getDamage() {
	return damage;
}
int attack::getAccuracy() {
	return accuracy;
}
std::string attack::getMessage() {
	return message;
}