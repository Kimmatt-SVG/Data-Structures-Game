#include <iostream>
#include <vector>
#include "user.h"
#include "enemy.h"
#include "inventory.h"
#include "item.h"

//create test objects here 
// (IMPORTANT!!! - STRENGTH VALUES NEED TO BE ATLEAST <10 OR WILL RESLUT IN A NEGATIVE ATTACK NUMBER)
user player(100, 30, 5, "Test Dummy");
goblin goba(100, 11, "goba1");
//Creates inventory
DLL inventory;
//methods

void displayMenu() {
	//system("CLS");
	std::cout << "========== Game Menu ==========\n";
	std::cout << "1. Return to Game\n";
	std::cout << "2. Enter Battle\n";
	std::cout << "3. Manage Inventory\n";
	std::cout << "4. Enter Shop\n";
	std::cout << "5. Talk to Someone\n";
	std::cout << "6. Quit Game\n";
	std::cout << "================================\n";
	std::cout << "Enter your choice: ";
}

void returnToOverworld() {
	std::cout << "You returning to da overworld...\n";
}

void enterShop() {
	std::cout << "You wanna shop...\n";
}

void chat() {
	std::cout << "You feel lonely...\n";
}

void quitGame() {
	std::cout << "You wannna bug off!\n";
	exit(0);
}

void handleMenuChoice(int choice) {
	switch (choice) {
	case 1:
		returnToOverworld();
		break;
	case 2:
		//for rigt now this is only one battle with a goblin
		player.battle(goba);
		break;
	case 3:
		//just displays the inventory
		inventory.displayList();
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
		std::cout << "Invalid choice. Please try again.\n";
		break;
	}
}

int main(){

	//creates various wepons and items and inputs them into test inventory
	inventory.pushBack(new weapons("Sword", "A sharp blade", "Melee Weapon", 50, 80));
	inventory.pushBack(new weapons("Bow", "A long-range bow", "Ranged Weapon", 30, 90));
	inventory.pushBack(new healing("Health Potion", "Restores HP", "Consumable", 50, 0));
	inventory.pushBack(new healing("Mana Potion", "Restores Mana", "Consumable", 0, 50));
	inventory.pushBack(new items("Shield", "Blocks attacks", "Armor"));
	inventory.pushBack(new items("Torch", "Provides light", "Utility"));

	//overarching game loop
	int choice;
	while (true) {
		displayMenu();
		std::cin >> choice;
		if (choice < 1 || choice > 6) {
			std::cin.clear();
			std::cout << "Invalid input. Please enter a number between 1 and 6.\n";
		}
		else {
			handleMenuChoice(choice);
		}
	}
}




