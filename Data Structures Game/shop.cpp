#pragma once
#include "shop.h"
#include "user.h"
#include <vector>
#include <string>
#include <iostream>
#include "inventory.h"


/* REQUIREMENTS:
1. purchaace new items and have them be added to the inventory (DONE)
2. sell items in inventory for gold
3. for potions have it so that you can purchase many of the same item at once
4. have bounds so that you cannot purchase somthing that you cannot afford or you cannt buy
somthing when your inventory is full (DONE)
*/

class shop {
private:
	std::string shopName;
	std::vector<items*> itemsForSale;
	user& ShopPlayer;
	DLL& ShopInventory;
public:
	shop(user &player, DLL &inventory) 
		: shopName("The Shop"),
		itemsForSale{
			new weapons("Sword", "A sharp blade", 50, 80),
			new weapons("Axe", "A Heavy Battle Axe", 70, 90),
			new weapons("LMG", "Light Machine Gun", 1000, 110),
			new HealingPotion("Health Potion", "A magical potion to heal", 30, 1, 10)
		},
		ShopPlayer(player),
		ShopInventory(inventory)
	{ 
		// nothing here
	}

	// Alternative constructor to initialize the shop with a specific name and items
	shop(const std::string& name, const std::vector<items*>& items, user& player, DLL& inventory)
		: shopName(name), itemsForSale(items), ShopPlayer(player), ShopInventory(inventory) {
	}
	

	void displayWelcomeMessage() {
		std::cout << "Welcome to " << shopName << "!" << std::endl;
		std::cout << "Here are the items for sale:" << std::endl << std::endl;
		std::cout << "========================" << std::endl;
		for (size_t i = 0; i < itemsForSale.size(); ++i) {
			std::cout << i + 1 << ". " << itemsForSale[i]->getItem() << " - " << itemsForSale[i]->getCost() << " gold" << std::endl;
		}
		std::cout << "========================" << std::endl << std::endl;
	}

	void displayItems() {
		std::cout << "You have " << ShopPlayer.getGold() << " gold." << std::endl;
		for (size_t i = 0; i < itemsForSale.size(); ++i) {
			std::cout << i + 1 << ". " << itemsForSale[i]->getItem() << " - " << itemsForSale[i]->getCost() << " gold" << std::endl;
			std::cout << itemsForSale[i]->getType() << std::endl;
		}

		//displays inventory
		ShopInventory.displayInvnetory();
	}

	void buyItem() {
		int choice;
		std::cout << std::endl << "Enter the number of the item you want to buy: ";
		std::cin >> choice;

		if (choice < 1 || choice > itemsForSale.size()) {
			std::cout << "Invalid choice. Please try again." << std::endl;
			pauseThenClear();
			return;
		}

		items* selectedItem = itemsForSale[choice - 1];

		// Check if the inventory is full
		int count = 0;
		node* temp = ShopInventory.getFirst();
		while (temp) {
			count++;
			temp = temp->nextNode;
		}

		if (count >= 4) {
			std::cout << "Your inventory is full. You cannot buy this item." << std::endl;
			pauseThenClear();
			return;
		}

		// Check if the player has enough gold
		if (ShopPlayer.getGold() >= selectedItem->getCost()) {
			// Deduct gold and add the item to the inventory
			ShopPlayer.setGold(ShopPlayer.getGold() - selectedItem->getCost());
			ShopInventory.pushBack(selectedItem);

			// Remove the item from the shop
			itemsForSale.erase(itemsForSale.begin() + (choice - 1));

			std::cout << "You bought a " << selectedItem->getItem() << "!" << std::endl;
			pauseThenClear();
		}
		else {
			std::cout << "You don't have enough gold to buy that item." << std::endl;
			pauseThenClear();
		}
	}

	void sellItem() {
		ShopInventory.displayInvnetory();
		std::cout << std::endl;
		std::cout << "Enter the number of the item you want to sell: ";
		int choice;
		std::cin >> choice;
		if (choice < 1 || choice > 4) {
			std::cout << "Invalid choice. Please try again." << std::endl;
			pauseThenClear();
			return;
		}
		node* temp = ShopInventory.getFirst();
		int count = 1;
		while (temp) {
			if (count == choice) {
				items* selectedItem = temp->data;
				// Add the item's cost to the player's gold
				ShopPlayer.setGold(ShopPlayer.getGold() + selectedItem->getCost());
				std::cout << "You sold a " << selectedItem->getItem() << "!" << std::endl;
				// Remove the item from the inventory
				ShopInventory.removeNode(temp);
				break;
			}
			temp = temp->nextNode;
			count++;
		}
		if (temp == nullptr) {
			std::cout << "Item not found in inventory." << std::endl;
		}
		pauseThenClear();
	}

	void playShop() {
		system("cls");
		int choice;
		displayWelcomeMessage();
		std::cout << "1. Buy items \n2. Sell items \n0. Exit the shop: ";
		std::cin >> choice;
		
		if (choice == 1) {
			system("cls");
			displayItems();
			buyItem();
		}
		else if (choice == 2) {
			sellItem();
		}
		else if (choice == 0) {
			std::cout << "Thank you for visiting " << shopName << "!" << std::endl;
			pauseThenClear();
			return;
		}
		else {
			std::cout << "Invalid choice. Please try again." << std::endl;
			pauseThenClear();
		}
		
		
	}
};

