#include "user.h"
#include <random>
#include <thread>
#include "inventory.h"
#include "item.h"
#include "globals.h"
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#pragma comment(lib, "Winmm.lib")

user::user(int battleHealth, int str, int magicMana, std::string userName) {
	health = battleHealth;
	strength = str;
	mana = magicMana;
	name = userName;
	gold = 10000;
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
int user::getGold() {
	return gold;
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
void user::setGold(int newGold) {
	gold = newGold;
}
void user::setName(std::string newName) {
	name = newName;
}
void user::setMana(int newMana) {
	mana = newMana;
}

//methods
//genertes random attack value
int user::randomAtkValue() {
	std::random_device rd;   // Seed generator
	std::mt19937 gen(rd());  // Random number generator (Mersenne Twister)
	std::uniform_int_distribution<int> distr(strength - 10, strength); // range
	return distr(gen);
}

#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#pragma comment(lib, "Winmm.lib")

void playSoundEffect(const std::string& soundFile) {
    std::wstring wideCommand = L"play " + std::wstring(soundFile.begin(), soundFile.end()) + L" from 0";
    mciSendString(wideCommand.c_str(), NULL, 0, NULL);
}


void user::battle(enemy& enemy) {
    // Play background music
    PlaySound(TEXT("battle.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    // Pointer to the currently equipped weapon
    weapons* equippedWeapon = nullptr;

    // Initialize equipped weapon to the first weapon in the inventory
    node* firstSlot = inventory.getFirst();
    if (firstSlot) {
        equippedWeapon = dynamic_cast<weapons*>(firstSlot->data);
    }
    int resetE = enemy.getHealth();
    int resetU = health;
    // Main battle loop
    while (true) {
        // Player's choice
        int playerChoice;
        

        // Check if the player is dead
        if (health <= 0) {
            enemy.setHealth(resetE);
            health = resetU;
            PlaySound(NULL, NULL, SND_PURGE); // Stop background music
            std::cout << std::endl;
            std::cout << "You died!" << std::endl;
            std::cout << "Press 5 to continue...";
            std::cin >> playerChoice;
            if (playerChoice == 5) {
                break;
            }
        }

        // Check if the enemy is dead
        if (enemy.getHealth() <= 0) {
            enemy.setHealth(resetE);
            health = resetU;
            PlaySound(NULL, NULL, SND_PURGE); // Stop background music
            system("CLS");
            std::cout << "You Won against: " << enemy.getName() << std::endl;
            std::cout << "Press 5 to continue...";
            std::cin >> playerChoice;
            if (playerChoice == 5) {
                break;
            }
        }

        // Display player and enemy stats
        system("CLS");
        std::cout << std::endl;
        std::cout << "========================\n";
        std::cout << "| Enemy: " << enemy.getName() << std::endl;
        std::cout << "| Enemy HP: " << enemy.getHealth() << std::endl;
        std::cout << "========================\n";
        std::cout << std::endl;
        std::cout << "HP: " << health << std::endl;
        std::cout << "MP: " << mana << std::endl;
        std::cout << "Equipped Weapon: " << (equippedWeapon ? equippedWeapon->getItem() : "None") << std::endl;
        std::cout << "1. Attack" << std::endl;
        std::cout << "2. Do absolutetly nothing" << std::endl;
        std::cout << "3. Use Health Potion" << std::endl;
        std::cout << "4. Switch Weapon" << std::endl;
        std::cout << "5. Run Away" << std::endl;
        std::cout << "You choose: ";
        std::cin >> playerChoice;
        std::cout << std::endl;

        // Handle invalid input
        if (playerChoice < 1 || playerChoice > 5) {
            std::cout << "That is not an option.";
            break;
        }

        if (playerChoice == 1) {
            // Attack with the equipped weapon or fallback to strength-based attack
            playSoundEffect("attack.wav"); // Play attack sound effect
            int tempPlayerDamage = equippedWeapon ? equippedWeapon->getDamage() : randomAtkValue();
            enemy.setHealth(enemy.getHealth() - tempPlayerDamage);
            std::cout << "You attacked with " << (equippedWeapon ? equippedWeapon->getItem() : "your fists") << "!";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << " You did " << tempPlayerDamage << " damage!" << std::endl << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        if (playerChoice == 2) {
            std::cout << "You are picking your nose for boggies" << std::endl; 
        }
        if (playerChoice == 3) {
            // Use health potion logic
            playSoundEffect("health_potion.wav"); // Play health potion sound effect
            node* current = inventory.getFirst();
            bool potionFound = false;
            while (current != nullptr) {
                HealingPotion* potion = dynamic_cast<HealingPotion*>(current->data);
                if (potion && potion->getItem() == "Health Potion") {
                    if (potion->getAmmount() > 0) {
                        health += potion->getHealingAmmount();
                        potion->use();
                        std::cout << "You used a Health Potion and healed " << potion->getHealingAmmount() << " HP! " << potion->getAmmount() << " Potions remaining.\n\n";
                        if (potion->getAmmount() <= 0) {
                            inventory.removeNode(current);
                            std::cout << "You used up the last Health Potion.\n";
                        }
                        potionFound = true;
                    }
                    else {
                        std::cout << "This potion is empty.\n";
                    }
                    break;
                }
                current = current->nextNode;
            }

            if (!potionFound) {
                std::cout << "You have no Health Potions left!\n";
            }

            std::this_thread::sleep_for(std::chrono::seconds(2));
        }

        if (playerChoice == 4) {
            playSoundEffect("switch_weapon.wav"); // Play sound effect

            std::vector<node*> weaponSlots;
            node* current = inventory.getFirst();
            int slotCount = 0;

            std::cout << "Choose a weapon to equip:\n";

            while (current && weaponSlots.size() < 3) {
                weapons* weapon = dynamic_cast<weapons*>(current->data);
                if (weapon) {
                    weaponSlots.push_back(current);
                    std::cout << weaponSlots.size() << ". " << weapon->getItem() << "\n";
                }
                current = current->nextNode;
                slotCount++;
            }

            std::cout << weaponSlots.size() + 1 << ". Cancel\n";
            int weaponChoice;
            std::cin >> weaponChoice;

            if (weaponChoice >= 1 && weaponChoice <= weaponSlots.size()) {
                weapons* selectedWeapon = dynamic_cast<weapons*>(weaponSlots[weaponChoice - 1]->data);
                if (selectedWeapon) {
                    equippedWeapon = selectedWeapon;
                    std::cout << "You equipped " << equippedWeapon->getItem() << "!\n";
                }
            }
            else {
                std::cout << "No weapon equipped.\n";
            }
        }

        if (playerChoice == 5) {
            PlaySound(NULL, NULL, SND_PURGE); // Stop background music
            playSoundEffect("run_away.wav"); // Play running away sound effect
            std::cout << "You flee away to fight another day...";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            system("cls");
            break;
        }
        if (playerChoice != 4) {
            if (enemy.getHealth() > 0) {
                // Enemy's turn
                int tempEnemyDamage = enemy.randomAtkValue();
                playSoundEffect("enemy_attack.wav"); // Play enemy attack sound effect
                health -= tempEnemyDamage;
                std::cout << "You have been attacked by " << enemy.getName() << std::endl;
                std::cout << "Damage inflicted: " << tempEnemyDamage << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(5));
            }
            else {
                std::cout << enemy.getName() << " tried to attack but has unfortunately died" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(5));

            }
        }
    }

    // Stop the background music after the battle ends
    PlaySound(NULL, NULL, SND_PURGE);
}




