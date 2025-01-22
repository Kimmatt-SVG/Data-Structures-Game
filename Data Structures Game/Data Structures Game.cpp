﻿#include <iostream>
#include <vector>
using namespace std;

class inventory {
private:
	string item;
	string description;
	int amt;
	bool unique;
	string type;
	int place;
public:
	inventory(string varPlace, string varDesc, int amount, bool cool, string whatItIs, int location) : item(varPlace), description(varDesc), amt(amount), unique(cool), type(whatItIs), place(location) {}

	int getPlace() const {
		return place;
	}

	string getItem() const {
		return item;
	}

	string getDescription() const {
		return description;
	}
	string typeOfThing() const {
		return type;
	}


	int getAmount() const {
		return amt;
	}
	bool isUnique() const {
		return unique;
	}
	void display() const {
		cout << "Item no. " << place << "\n" << endl;
		cout << "Item: " << item << "\n"
			<< "Description: " << description << "\n"
			<< "Amount: " << amt << "\n"
			<< "Unique: " << (unique ? "Yes" : "No") << "\n"
			<< "Type: " << type << "\n";
	}

};

class attack {
public:
	string attackName;
	int damage;
	int accuracy;
	string message;
public:
	attack(string attNa, int hurt, int hit, string talk) : attackName(attNa), damage(hurt), accuracy(hit), message(talk) {}

	string getName() const {
		return attackName;
	}
	int getDamage() const {
		return damage;
	}
	int getAccuracy() const {
		return accuracy;
	}
	string getMessage() const {
		return message;
	}
};

class character {
public:
	int maxHealth;
	int health;
	int level;
	int speed;
public:
	character(int cappedHealth, int battleHealth, int challenge, int fast) : maxHealth(cappedHealth), health(battleHealth), level(challenge), speed(fast) {}

	int getMaxHealth() const {
		return maxHealth;
	}
	int currentHealth() const {
		return health;
	}
	int currentLevel() const {
		return level;
	}
	int getSpeed() const {
		return speed;
	}



};

class user : public character {
public:
	int strength;
	int mana;
	vector<inventory> userInventory;
	string name;
	int exp;
	attack attack1;
	attack attack2;


public:

	user(int cappedHealth, int battleHealth, int challenge, int fast, int str, int magicMana, string userName, int expLeft, const attack& firstAttack, const attack& secondAttack)
		: character(cappedHealth, battleHealth, challenge, fast), strength(str), mana(magicMana), name(userName), exp(expLeft), attack1(firstAttack), attack2(secondAttack) {
	}
	attack getAttack1() const {
		return attack1;
	}

	attack getAttack2() const {
		return attack2;
	}
	int getStrength() const {
		return strength;
	}

	int getMana() const {
		return mana;
	}
	int getExp() const {
		return exp;
	}

	string getName() const {
		return name;
	}

	void addItem(const inventory& item) {
		userInventory.push_back(item);
		cout << item.getItem() << " added to your inventory.\n";
	}

	void removeItem(int index) {
		if (index < 0 || index >= userInventory.size()) {
			cout << "Invalid index. Cannot remove item.\n";
			return;
		}
		cout << userInventory[index].getItem() << " removed from your inventory.\n";
		userInventory.erase(userInventory.begin() + index);
	}

	void displayInventory() const {
		if (userInventory.empty()) {
			cout << "Your inventory is empty.\n";
			return;
		}

		cout << "==== User Inventory ====\n";
		for (size_t i = 0; i < userInventory.size(); ++i) {
			cout << "[" << i + 1 << "] ";
			userInventory[i].display();
			cout << "--------------------------\n";
		}
	}

	void useItem(int index) {
		if (index < 0 || index >= userInventory.size()) {
			cout << "Invalid index. Cannot use item.\n";
			return;
		}

		inventory& item = userInventory[index];
		if (item.typeOfThing() == "Consumable") {
			health += item.getAmount(); // Example: Add the amount to health
			if (health > maxHealth) health = maxHealth;
			cout << "Used " << item.getItem() << ". Health restored to " << health << ".\n";
			removeItem(index); // Remove the used item
		}
		else {
			cout << "You cannot use this item directly.\n";
		}
	}

	void increaseStrength(int amount) {
		strength *= amount;
		cout << "Strength increased by " << amount << " times. Current strength: " << strength << ".\n";
	}

	// Method to update mana
	void restoreMana(int amount) {
		mana += amount;
		cout << "Mana restored by " << amount << ". Current mana: " << mana << ".\n";
	}

	void speedIncrease(int amount) {
		speed *= amount;
		cout << "Speed increased by " << amount << " times. Current Speed: " << speed << ".\n";
	}

	// Method to display character stats
	void displayStats() const {
		cout << "==== User Stats ====\n";
		cout << "Level: " << level << "\n";
		cout << "Health: " << health << "/" << maxHealth << "\n";
		cout << "Strength: " << strength << "\n";
		cout << "Mana: " << mana << "\n";
	}
};

class enemy : public character {
public:
	int strength;
	int mana;
	int exp;

public:
	enemy(int cappedHealth, int battleHealth, int challenge, int fast, int str, int magicMana, int expLeft)
		: character(cappedHealth, battleHealth, challenge, fast), strength(str), mana(magicMana), exp(expLeft) {
	}

	int getStrength() const {
		return strength;
	}

	int getMana() const {
		return mana;
	}
	int getExp() const {
		return exp;
	}
};

class goblin : public enemy {

public:
	attack poke;
	attack shank;
	string name;

public:
	// Constructor for goblin class
	goblin(int cappedHealth, int battleHealth, int challenge, int fast, int str, int magicMana, int expLeft,
		const attack& pokeAttack, const attack& shankAttack, const string& goblinName)
		: enemy(cappedHealth, battleHealth, challenge, fast, str, magicMana, expLeft),
		poke(pokeAttack), shank(shankAttack), name(goblinName) {
	}

	// Getters
	string getName() const {
		return name;
	}

	attack getPoke() const {
		return poke;
	}

	attack getShank() const {
		return shank;
	}

};

/*void battleInitializer(user& player, goblin& enemyGoblin) {
	cout << "You have encountered a wild " << enemyGoblin.getName() << "! \nPrepare to battle...\n\n";

	// Main battle loop
	while (player.currentHealth() > 0 && enemyGoblin.currentHealth() > 0) {
		// Display player and enemy stats
		cout << "========================================\n";
		cout << "" << player.getName() << " | HP: " << player.currentHealth() << "/" << player.getMaxHealth()
			<< " | Mana: " << player.getMana() << "\n";
		cout << "" << enemyGoblin.getName() << " | HP: " << enemyGoblin.currentHealth() << "/" << enemyGoblin.getMaxHealth() << "\n";
		cout << "========================================\n";
		attack attack1 = player.getAttack1();
		attack chosenAttack = player.getAttack2();
		// Player's turn
		cout << "\nYour turn! Choose an action:\n";
		cout << "1. ";
		cout << "2. Heal (if you have healing items)\n";
		cout << "3. Boost Mana\n";
		cout << "Enter your choice: ";
		int choice;
		cin >> choice;

		if (choice == 1) {
			int damage = player.getStrength();
			cout << "\nYou attack the " << enemyGoblin.getName() << " and deal " << damage << " damage!\n";
			enemyGoblin.health -= damage;
			if (enemyGoblin.currentHealth() <= 0) {
				cout << "The " << enemyGoblin.getName() << " has been defeated!\n";
				break;
			}
		}
		else if (choice == 2) {
			if (player.getMana() >= 10) {
				int healAmount = 20; // Example healing amount
				player.health += healAmount;
				if (player.health > player.getMaxHealth()) player.health = player.getMaxHealth();
				player.restoreMana(-10); // Reduce mana for healing
				cout << "\nYou used a healing spell and restored " << healAmount << " HP! Mana cost: 10.\n";
			}
			else {
				cout << "\nNot enough mana to heal!\n";
			}
		}
		else if (choice == 3) {
			int manaBoost = 15;
			player.restoreMana(manaBoost);
			cout << "\nYou focus and restore " << manaBoost << " mana!\n";
		}
		else {
			cout << "\nInvalid choice! You lose your turn.\n";
		}

		// Goblin's turn


		cout << "\n?? " << enemyGoblin.getName() << "'s turn!\n";
		int attackChoice = rand() % 2; // Randomly choose between poke and shank
		attack chosenAttack = (attackChoice == 0) ? enemyGoblin.getPoke() : enemyGoblin.getShank();

		// Determine hit or miss
		int hitChance = rand() % 100;
		if (hitChance < chosenAttack.getAccuracy()) {
			cout << chosenAttack.getMessage() << " It deals " << chosenAttack.getDamage() << " damage!\n";
			player.health -= chosenAttack.getDamage();
			if (player.currentHealth() <= 0) {
				cout << "\n?? You have been defeated by the " << enemyGoblin.getName() << "...\n";
				break;
			}
		}
		else {
			cout << " The goblin's attack missed!\n";
		}
	}

	// Battle results
	if (player.currentHealth() > 0) {
		cout << "\n?? You won the battle with " << player.currentHealth() << " HP remaining!\n";
		cout << "You gained " << enemyGoblin.getExp() << " experience points!\n";
	}
	cout << "========================================\n";
}
*/

void enterBattle() {
	// Sample user and goblin setup
	attack standardSword("Sword", 20, 85, "You try and use that sword you got!");
	attack pocketGat("Gat", 100, 50, "you shoot ur gun!");
	user player(100, 100, 1, 10, 15, 20, "Hero", 0, standardSword, pocketGat); // Health: 100, Strength: 15, Speed: 10
	attack goblinPoke("Poke", 5, 80, "The goblin pokes you with a sharp stick!");
	attack goblinShank("Shank", 10, 60, "The goblin tries to shank you!");
	goblin enemyGoblin(50, 50, 1, 8, 12, 5, 20, goblinPoke, goblinShank, "Goblin"); // Health: 50, Strength: 12

	//battleInitializer(player, enemyGoblin);
}

void returnToOverworld() {
	cout << "You returning to da overworld...\n";
}

void manageInventory() {
	cout << "You managing yo inventory ...\n";
}

void enterShop() {
	cout << "You wanna shop...\n";
}

void chat() {
	cout << "You feel lonely...\n";
}

void quitGame() {
	cout << "You wannna bug off!\n";
	exit(0);
}

// Display menu function
void displayMenu() {
	cout << "========== Game Menu ==========\n";
	cout << "1. Return to Game\n";
	cout << "2. Enter Battle\n";
	cout << "3. Manage Inventory\n";
	cout << "4. Enter Shop\n";
	cout << "5. Talk to Someone\n";
	cout << "6. Quit Game\n";
	cout << "================================\n";
	cout << "Enter your choice: ";
}

// Menu handling function
void handleMenuChoice(int choice) {
	switch (choice) {
	case 1:
		returnToOverworld();
		break;
	case 2:
		enterBattle();
		break;
	case 3:
		manageInventory();
		break;
	case 4:
		enterShop();
		break;
	case 5:
		chat();
		break;
	case 6:
		quitGame();
		break;
	default:
		cout << "Invalid choice. Please try again.\n";
		break;
	}
}

void defaultInventory(vector<inventory>& items) {
	// A vector to store the items
	// Add medieval-themed items
	int i = 1;
	items.emplace_back("Basic Sword", "Made with steel. Its average sized", 1, true, "Weapon", i); i++;
	items.emplace_back("Basic Shield", "This item wont last that long fr.", 1, true, "Armor", i); i++;
	//items.emplace_back("Basic Healing Potion", "Medival gatorade.", 5, false, "Consumable", i); i++;
	items.emplace_back("Gold Coins", "Mideival dolla bill.", 100, false, "Currency", i); i++;
	//items.emplace_back("Torch", "A wooden torch to light dark areas.", 3, false, "Utility", i); i++;
	items.emplace_back("Basic Bow", "A simple wooden bow for ranged attacks.", 1, true, "Weapon", i); i++;
	items.emplace_back("Basic Arrows", "A bundle of arrows for use with a bow.", 20, false, "Ammunition", i); i++;
	//items.emplace_back("Spellbook", "A tome containing basic magical spells.", 1, true, "Magic", i); i++;
	//items.emplace_back("Herbs", "A collection of medicinal herbs for crafting potions.", 10, false, "Crafting Material", i); i++;
	//items.emplace_back("Iron Key", "A heavy iron key that unlocks a mysterious door.", 1, true, "Key", i); i++;

}

int main(){
	int choice;
	while (true) {
		displayMenu();
		cin >> choice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a number between 1 and 6.\n";
		}
		else {
			handleMenuChoice(choice);
		}
	}


	vector<inventory> bob;
	defaultInventory(bob);
}