#include "user.h"

user::user(int cappedHealth, int battleHealth, int challenge, int fast, int str, int magicMana, std::string userName, int expLeft, const attack& firstAttack, const attack& secondAttack)
		: character(cappedHealth, battleHealth, challenge, fast), strength(str), mana(magicMana), name(userName), exp(expLeft), attack1(firstAttack), attack2(secondAttack) {
	}
	attack user::getAttack1() {
		return attack1;
	}

	attack user::getAttack2() {
		return attack2;
	}
	int user::getStrength() {
		return strength;
	}

	int user::getMana() {
		return mana;
	}
	int user::getExp() {
		return exp;
	}

	std::string user::getName() {
		return name;
	}

	void user::addItem(const inventory& item) {
		userInventory.push_back(item);
		std::cout << item.getItem() << " added to your inventory.\n";
	}

	void user::removeItem(int index) {
		if (index < 0 || index >= userInventory.size()) {
			std::cout << "Invalid index. Cannot remove item.\n";
			return;
		}
		std::cout << userInventory[index].getItem() << " removed from your inventory.\n";
		userInventory.erase(userInventory.begin() + index);
	}

	void user::displayInventory() {
		if (userInventory.empty()) {
			std::cout << "Your inventory is empty.\n";
			return;
		}

		std::cout << "==== User Inventory ====\n";
		for (size_t i = 0; i < userInventory.size(); ++i) {
			std::cout << "[" << i + 1 << "] ";
			userInventory[i].display();
			std::cout << "--------------------------\n";
		}
	}

	void user::useItem(int index) {
		if (index < 0 || index >= userInventory.size()) {
			std::cout << "Invalid index. Cannot use item.\n";
			return;
		}

		inventory& item = userInventory[index];
		if (item.typeOfThing() == "Consumable") {
			health += item.getAmount(); // Example: Add the amount to health
			if (health > maxHealth) health = maxHealth;
			std::cout << "Used " << item.getItem() << ". Health restored to " << health << ".\n";
			removeItem(index); // Remove the used item
		}
		else {
			std::cout << "You cannot use this item directly.\n";
		}
	}

	void user::increaseStrength(int amount) {
		strength *= amount;
		std::cout << "Strength increased by " << amount << " times. Current strength: " << strength << ".\n";
	}

	// Method to update mana
	void user::restoreMana(int amount) {
		mana += amount;
		std::cout << "Mana restored by " << amount << ". Current mana: " << mana << ".\n";
	}

	void user::speedIncrease(int amount) {
		speed *= amount;
		std::cout << "Speed increased by " << amount << " times. Current Speed: " << speed << ".\n";
	}

	// Method to display character stats
	void user::displayStats() {
		std::cout << "==== User Stats ====\n";
		std::cout << "Level: " << level << "\n";
		std::cout << "Health: " << health << "/" << maxHealth << "\n";
		std::cout << "Strength: " << strength << "\n";
		std::cout << "Mana: " << mana << "\n";
	}

