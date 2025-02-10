#include <iostream>
#include <vector>
#include "user.h"
#include "enemy.h"

//create test objects here 
// (IMPORTANT!!! - STRENGTH VALUES NEED TO BE ATLEAST <10 OR WILL RESLUT IN A NEGATIVE ATTACK NUMBER)
user player(100, 30, 5, "Test Dummy");
goblin goba(100, 11, "goba1");

//methods

void displayMenu() {
	system("CLS");
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

void manageInventory() {
	std::cout << "You managing yo inventory ...\n";
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
		std::cout << "Invalid choice. Please try again.\n";
		break;
	}
}


//Jack Test Comment
int main(){
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

//king was here



