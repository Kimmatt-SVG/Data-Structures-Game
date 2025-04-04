﻿#include <iostream>
#include <vector>
#include "user.h"
#include "enemy.h"
#include "inventory.h"
#include "item.h"
#include "talkingNPC.h" 
#include "globals.h"

user player(100, 30, 20, "Test Dummy");
goblin goba(100, 11, "goba1");
DLL inventory;

// Methods
void displayMenu() {
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
    std::cout << "You wannna bug off!\n";
    exit(0);
}

void handleMenuChoice(int choice) {
    switch (choice) {
    case 1:
        returnToOverworld();
        break;
    case 2:
        // For right now this is only one battle with a goblin
        player.battle(goba);
        break;
    case 3:
        // Just displays the inventory
        inventory.manaageInventory();
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

int main() {
    inventory.pushBack(new weapons("Sword", "Melee Weapon", 50, 80));
    inventory.pushBack(new weapons("Bow", "Ranged Weapon", 30, 90));
    inventory.pushBack(new HealingPotion("Health Potion", "Consumable", 5, 2, 10));
    //inventory.pushBack(new healing("Mana Potion", "Consumable", 3, 1, 0, 50));
    //inventory.pushBack(new items("Shield", "Armor", 4, 2));
    //inventory.pushBack(new items("Torch", "Utility", 0, -1));
    //inventory.pushBack(new currency("Gold Coins", "Currency", 1));
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



