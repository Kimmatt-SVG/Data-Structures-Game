#pragma once
using namespace std; 
#include <string>
//fill out later
class items {
private: 
	std::string item;
	std::string description;
//	int amount;
	std::string type;
	
	
public: 
	int cost;
	items(std::string itemName, std::string desc, std::string classification);
	std::string getItem() const;
	std::string getDescription() const;
	std::string getType() const;
};

class weapons : public items {
private:
	int damage;
	int accuracy;
public:
	weapons(std::string item, std::string description, std::string classification, int dam, int acc);
	int getDamage() const;
	int getAccuracy() const;
};

class healing : public items {
private:
	int heal;
	int manaUsage;
public:
	healing(string item, std::string description, std::string classification, int h, int mana);
	int getHeal() const;
	int getManaCost() const;
	void display() const;

};