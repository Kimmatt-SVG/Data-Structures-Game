#include <string>
#include <iostream>
#include "enemy.h"
#include "Map.cpp"
#ifndef USER_H
#define USER_H

class user {
public:
	int health;
	int strength;
	int mana;
	int gold;
	std::string name;
public:
	//constructors
	user(int battleHealth, int str, int magicMana, std::string userName);
	//getters
	int getHealth();
	int getStrength();
	int getMana();
	int getGold();
	std::string getName();
	//setters
	void setHealth(int newHealth);
	void setStrength(int newStrength);
	void setGold(int newGold);
	void setName(std::string newName);
	//methods
	int randomAtkValue();
	void battle(enemy& enemy);

	//movement
	void whereAmI() {
		std::cout << "Currently at node " << currentNode << "\n";
		map->displayNode(currentNode);
	}
    void moveTo() {
        auto current = map->getNode(currentNode);
        if (!current) {
            std::cout << "Current location invalid.\n";
            return;
        }

        std::cout << "You can move to:\n";
        for (int neighbor : current->neighbors) {
            auto neighborNode = map->getNode(neighbor);
            std::cout << " - Node " << neighbor << " (";
            switch (neighborNode->type) {
            case LocationType::SHOP: std::cout << "Shop"; break;
            case LocationType::ENEMY: std::cout << "Enemy"; break;
            case LocationType::NPC: std::cout << "NPC"; break;
            case LocationType::EMPTY: std::cout << "Empty"; break;
            }
            std::cout << ")\n";
        }

        std::cout << "Enter the node ID you want to move to: ";
        int choice;
        std::cin >> choice;

        // Check if choice is valid
        for (int neighbor : current->neighbors) {
            if (neighbor == choice) {
                currentNode = choice;
                std::cout << "Moved to node " << currentNode << "\n";
                map->displayNode(currentNode);
                return;
            }
        }

        std::cout << "Invalid choice. You stay at node " << currentNode << ".\n";
    }

};

#endif
