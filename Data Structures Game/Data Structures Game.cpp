#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "user.h"
#include "enemy.h"
#include "talkingNPC.h"
#include "inventory.h"
#include "item.h"
#include "globals.h"
#include "map.h"
#include "shop.cpp"

user player(100, 30, 20, "Test Dummy");
goblin goba(100, 11, "goba1");
DLL inventory;
shop TestShop(player, inventory);

void displayMenu() {
    std::cout << "========== Game Menu ==========\n";
    std::cout << "1. Return to Game\n";
    std::cout << "2. Enter Battle\n";
    std::cout << "3. Manage Inventory\n";
    std::cout << "4. Enter Shop\n";
    std::cout << "5. Talk to Someone\n";
    std::cout << "6. Explore\n";
    std::cout << "7. Quit Game\n";
    std::cout << "================================\n";
    std::cout << "Enter your choice: ";
}

void explore() {
    GameMap gameMap(5, 5);
    gameMap.addNode(6, "Ancient Forest - The trees here are unnaturally tall.");
    gameMap.addNode(18, "Dangerous Swamp - Thick fog obscures your vision.");
    gameMap.setImpassable(12);
    gameMap.setImpassable(13);
    gameMap.addNode(8, "Village Square - A friendly merchant waves at you from his stall.");

    while (true) {
        system("cls");
        system("cls");
        gameMap.displayCurrentLocation();
        gameMap.displayMap();
        std::cout << "\n=== Exploration Options ===\n";
        std::cout << "W - Move North\n";
        std::cout << "S - Move South\n";
        std::cout << "A - Move West\n";
        std::cout << "D - Move East\n";
        std::cout << "M - Open Menu\n";
        std::cout << "I - Open Inventory\n";
        std::cout << "==========================\n";
        std::cout << "Choose an action: ";

        char input;
        std::cin >> input;
        input = toupper(input);

        switch (input) {
        case 'W':
            if (!gameMap.move('W')) {
                std::cout << "\nYou cannot go that way!\n";
                system("pause");
            }
            break;
        case 'S':
            if (!gameMap.move('S')) {
                std::cout << "\nYou cannot go that way!\n";
                system("pause");
            }
            break;
        case 'A':
            if (!gameMap.move('A')) {
                std::cout << "\nYou cannot go that way!\n";
                system("pause");
            }
            break;
        case 'D':
            if (!gameMap.move('D')) {
                std::cout << "\nYou cannot go that way!\n";
                system("pause");
            }
            break;
        case 'M':
            return;
        case 'I':
            inventory.manaageInventory();
            break;
        default:
            std::cout << "\nInvalid input!\n";
            system("pause");
            break;
        }

        MapNode* current = gameMap.getCurrentLocation();
        if (current->id == 8) {
            roadsideBeggar merchant;
            merchant.printDialogue(1);
            system("pause");
        }
        else if (current->id == 18) {
            if (rand() % 4 == 0) {
                std::cout << "\nA swamp creature attacks you!\n";
                player.battle(goba);
                system("pause");
            }
        }
    }
}

void returnToOverworld() {
    system("cls");
}

void enterShop() {
    std::cout << "You wanna shop...\n";
}

void chat() {
    roadsideBeggar beggar;
    beggar.printDialogue(0);
}

void quitGame() {
    exit(0);
}

void handleMenuChoice(int choice) {
    switch (choice) {
    case 1:
        returnToOverworld();
        break;
    case 2:
        player.battle(goba);
        break;
    case 3:
        inventory.manaageInventory();
        break;
    case 4:
		TestShop.playShop();
        break;
    case 5:
        chat();
        break;
    case 6:
        explore();
        break;
    case 7:
        quitGame();
        break;
    default:
        std::cout << "Invalid choice. Please try again.\n";
        break;
    }
}

int main() {
    srand(time(0));
    inventory.pushBack(new weapons("Sword", "Melee Weapon", 50, 80));
    inventory.pushBack(new weapons("Bow", "Ranged Weapon", 30, 90));
    inventory.pushBack(new HealingPotion("Health Potion", "Consumable", 5, 2, 10));
    inventory.pushBack(new weapons("Sword", "Starting Weapon", 50, 80));
    inventory.pushBack(new weapons("Bow", "Ranged Starting Weapon", 30, 90));
    inventory.pushBack(new HealingPotion("Health Potion", "Consumable", 5, 2, 10));
    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;
        if (choice < 1 || choice > 7) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Invalid input. Please enter a number between 1 and 7.\n";
        }
        else {
            handleMenuChoice(choice);
        }
    }
}

