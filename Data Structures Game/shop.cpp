#include <iostream>
#include <vector>
#include "enemy.h"
#include "inventory.h"
#include "item.h"

class Shop {
private:
    std::vector<std::shared_ptr<items>> stock;

public:
    void addItemToShop(std::shared_ptr<items> item) {
        stock.push_back(item);
    }

    void displayStock() const {
        std::cout << "\nShop Inventory:\n";
        for (size_t i = 0; i < stock.size(); ++i) {
            std::cout << i + 1 << ". " << stock[i]->getItem() << " - " << stock[i]->getCost() << " gold\n";
        }
    }

    std::shared_ptr<items> buyItem(int index, int& playerGold) {
        if (index < 0 || index >= stock.size()) {
            std::cout << "Invalid choice!\n";
            return nullptr;
        }
        if (playerGold < stock[index]->getCost()) {
            std::cout << "Not enough gold!\n";
            return nullptr;
        }
        playerGold -= stock[index]->getCost();
        std::shared_ptr<items> purchasedItem = stock[index];
        stock.erase(stock.begin() + index);
        return purchasedItem;
    }
};

class Player {
private:
    int gold;
    DLL inventory;

public:
    Player(int startingGold) : gold(startingGold) {}


    void sellItem(items &item, currency &gold) {
       
    }

};