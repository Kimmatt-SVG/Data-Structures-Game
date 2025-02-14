#pragma once
using namespace std; 
#include <string>
//fill out later
class items {
private: 
	string item;
	string description;
//	int amount;
	string type;
	
public: 
	items(string itemName, string desc, string classification) : item(itemName), description(desc), type(classification) {}

	string getItem() const {
		return item;
	}

	string getDescription() const {
		return description;
	}
	

	string getType() const {
		return type; 
	}
};

class weapons : public items {
private:
	int damage;
	int accuracy;
public:
	weapons(string item, string	description, string classification, int dam, int acc) : items(item, description, classification), damage(dam), accuracy(acc) {}


	int getDamage() const {
		return damage;


	}

	int getAccuracy() const {
		return accuracy; 
	}
};