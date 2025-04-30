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
#include "limits"

//CREATE GAME OBJECTS HERE

DLL inventory;
user player(100, 30, 20, "Test Dummy");
goblin goba(100, 11, "goba1");
goblin brown(10000000000, 1111, "Dr. Tyler Brown");
shop TestShop(player, inventory);

// Define items for the Mythic Shop
std::vector<items*> mythicItems = {
    new weapons("Excalibur", "The legendary sword of King Arthur", 500, 150),
    new weapons("Mjolnir", "The mighty hammer of Thor", 800, 200),
    new HealingPotion("Elixir of Life", "A potion that fully restores health", 300, 1, 100),
    new items("Phoenix Feather", "A rare item with mystical properties", 1000)
};

// Create the Mythic Shop
shop mythicShop("Mythic Shop", mythicItems, player, inventory);

void startGame() {
    int c = 0;
    std::string name;
     
    std::cout << "Select your character:\n";
    std::cout << "1. Knight\n";
    std::cout << "Stats: 100 HP, 30 Strength, 20 Mana\n";
    std::cout << "2. Ranger\n";
    std::cout << "Stats: 80 HP, 20 Strength, 40 Mana\n";
    std::cout << "3. Gladiator\n";
    std::cout << "Stats: 120 HP, 40 Strength, 10 Mana\n";

    std::cin >> c;
	std::cout << std::endl;

    if (c == 1) {
        player.setHealth(100);
        player.setStrength(30);
        player.setMana(20);
        inventory.pushBack(new weapons("Dagger", "Melee Weapon", 20, 80));
        inventory.pushBack(new weapons("Sword", "Melee Weapon", 50, 80));
        inventory.pushBack(new HealingPotion("Health Potion", "Consumable", 5, 2, 10));
    }
    else if (c == 2) {
        player.setHealth(80);
        player.setStrength(20);
        player.setMana(40);
        inventory.pushBack(new weapons("Dagger", "Melee Weapon", 20, 80));
        inventory.pushBack(new weapons("Bow", "Ranged Weapon", 30, 90));
        inventory.pushBack(new HealingPotion("Health Potion", "Consumable", 5, 2, 10));
    }
    else if (c == 3) {
        player.setHealth(120);
        player.setStrength(40);
        player.setMana(10);
        inventory.pushBack(new weapons("Gladiator Sword", "Melee Weapon", 60, 100));
        inventory.pushBack(new weapons("Axe", "Heavy Battle Axe", 70, 90));
        inventory.pushBack(new HealingPotion("Health Potion", "Consumable", 5, 2, 10));
    }
    else {
        std::cout << "Invalid choice. Defaulting to Knight.\n";
        player.setHealth(100);
        player.setStrength(30);
        player.setMana(20);
        inventory.pushBack(new HealingPotion("Health Potion", "Consumable", 5, 2, 10));
    }

    std::cout << "Enter your character name: " << std::endl;
    std::cin >> name;
    player.setName(name);
	std::cout << std::endl;
    std::cout << "Welcome, " << name << "!\n";

    // Display starting inventory
    std::cout << "\nYour starting inventory:\n";
    inventory.displayInvnetory();

    pauseThenClear();
}


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
    // Play background music for exploration
    PlaySound(TEXT("explore.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    GameMap gameMap(5, 5);
    gameMap.setImpassable(1);

    while (true) {
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

        if (std::cin.fail()) {
            std::cin.clear();
            continue;
        }

        // Handle movement and play sound effects
        switch (input) {
        case 'W':
            if (!gameMap.move('W')) {
                std::cout << "\nYou cannot go that way!\n";
                system("pause");
            }
            else {
                playSoundEffect("move_east.wav");
            }
            break;
        case 'S':
            if (!gameMap.move('S')) {
                std::cout << "\nYou cannot go that way!\n";
                system("pause");
            }
            else {
                playSoundEffect("move_east.wav");
            }
            break;
        case 'A':
            if (!gameMap.move('A')) {
                std::cout << "\nYou cannot go that way!\n";
                system("pause");
            }
            else {
                playSoundEffect("move_east.wav");
            }
            break;
        case 'D':
            if (!gameMap.move('D')) {
                std::cout << "\nYou cannot go that way!\n";
                system("pause");
            }
            else {
                playSoundEffect("move_east.wav");
            }
            break;
        case 'M':
            // Stop exploration music when returning to the menu
            PlaySound(NULL, NULL, SND_PURGE);
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
        if (!current) {
            std::cerr << "Error: currentLocation is null!\n";
            continue;
        }
        if (current->id == 8) {
            roadsideBeggar merchant;
            merchant.printDialogue(1);
            system("pause");
        }
        else if (current->id == 13) {
            if (rand() % 2 == 0) {
                std::cout << "\nA swamp creature attacks you!\n";
                PlaySound(NULL, NULL, SND_PURGE); // Stop exploration music
                player.battle(goba);
                PlaySound(TEXT("explore.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); // Resume exploration music
                system("pause");
            }
        }
        else if (current->id == 0) {
            if (rand() % 3 == 0) {
                std::cout << "\nA swamp creature attacks you!\n";
                PlaySound(NULL, NULL, SND_PURGE); // Stop exploration music
                player.battle(brown);
                PlaySound(TEXT("explore.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); // Resume exploration music
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
    startGame();
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

