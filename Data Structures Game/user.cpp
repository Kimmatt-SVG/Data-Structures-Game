#include "user.h"
#include <random>
#include <thread>

user::user(int battleHealth, int str, int magicMana, std::string userName) {
	health = battleHealth;
	strength = str;
	mana = magicMana;
	name = userName;
}

//getters
int user::getHealth() {
	return health;
}
int user::getStrength() {
	return strength;
}
int user::getMana() {
	return mana;
}
std::string user::getName() {
	return name;
}

//setters
void user::setHealth(int newHealth) {
	health = newHealth;
}
void user::setStrength(int newStrength) {
	strength = newStrength;
}
void user::setName(std::string newName) {
	name = newName;
}

//methods
//genertes random attack value
int user::randomAtkValue() {
	std::random_device rd;   // Seed generator
	std::mt19937 gen(rd());  // Random number generator (Mersenne Twister)
	std::uniform_int_distribution<int> distr(strength - 10, strength); // range
	return distr(gen);
}

void user::battle(enemy& enemy) { //!FIXME - MIGHT NEED TO MOVE THE HEALTH CHECKS FOR BOTH PLAYER AND ENEMY	
	//main battle loop while the players health is above 0
	while (true) {
		//players choice
		int playerChoice;
		//checks if you are dead
		if (health <= 0) {
			std::cout << std::endl;
			std::cout << "You died!";
			std::cout << std::endl;
			std::cout << "Press 5 to continue...";
			std::cin >> playerChoice;
			if (playerChoice == 5) {
				break;
			}
		}
		//checks if you win
		if (enemy.getHealth() <= 0) {
			system("CLS");
			std::cout << "You Won against: " << enemy.getName() << std::endl;
			std::cout << "Press 5 to continue...";
			std::cin >> playerChoice;
			if (playerChoice == 5) {
				break;
			}
		}
		// Display player and enemy stats
		// clears screen
		system("CLS");
		std::cout << std::endl;
		std::cout << "========================\n";
		std::cout << "| Enemy: " << enemy.getName() << std::endl;
		std::cout << "| Enemy HP: " << enemy.getHealth() << std::endl;
		std::cout << "========================\n";
		std::cout << std::endl;
		std::cout << "HP: " << health << std::endl;
		std::cout << "1. Attack" << std::endl;
		std::cout << "2. ...." << std::endl;
		std::cout << "3. ...." << std::endl;
		std::cout << "4. ...." << std::endl;
		std::cout << "You choose: ";
		std::cin >> playerChoice;
		std::cout << std::endl;
		//catches wrong imput
		if (playerChoice < 1 || playerChoice > 4) {
			std::cout << "That is not an option";
			break;
		}
		if (playerChoice == 1) {
			// need a temp place to store random ATK
			int tempPlayerDamage = randomAtkValue();
			//update enemy health
			enemy.setHealth(enemy.getHealth() - tempPlayerDamage);
			std::cout << "You have attacked! ";
			std::this_thread::sleep_for(std::chrono::seconds(2)); // Pause for 2 seconds
			std::cout << "You did " << tempPlayerDamage << " Damage!" << std::endl << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2)); // Pause for 2 seconds
		}

		//enemys turn
		//calls the random attack function and applies it to the player
		//temp place to store random value
		int tempEnemyDamage = enemy.randomAtkValue();
		health = health - tempEnemyDamage;
		std::cout << "You have been attacked by " << enemy.getName() << std::endl;
		std::cout << "Damage inflicted: " << tempEnemyDamage << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(5)); // Pause for 5 seconds
	}
}
