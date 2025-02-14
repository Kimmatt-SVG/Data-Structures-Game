#include "item.h"
#include <string>

	items::items(std::string itemName, std::string desc, std::string classification) : item(itemName), description(desc), type(classification) {}

	std::string items::getItem() const {
		return item;
	}

	std::string items::getDescription() const {
		return description;
	}


	std::string items::getType() const {
		return type;
	}

	weapons::weapons(std::string item, std::string	description, std::string classification, int dam, int acc) : items(item, description, classification), damage(dam), accuracy(acc) {}


	int weapons::getDamage() const {
		return damage;
	}

	int weapons::getAccuracy() const {
		return accuracy;
	}
