#include <iostream>
#include <vector>
#include "enemy.h"
#include "inventory.h"
#include "item.h"

class Shop {
private:
    std::vector<items> stock;

public:
    void addItemToShop(items item) {
        stock.push_back(item);
    }
    void displayStock() {
        std::cout << "========Shop Inventory========";
        for (int i = 0; i < stock.size(); i++) {
            std::cout << i + 1 << ". ";
            std::cout << stock[i].getItem() << " Cost: ";
            std::cout << stock[i].getCost() << std::endl;
        }
    }
    
    void buyItem(currency &gold) {
        displayStock();
        int index;
        std::cout << "What do you wish to buy\n";
        std::cin >> index;
        if (gold.getCost() >= stock[index].getCost()) {
            gold.deduct(stock[index].getCost());
        }
        else {
            std::cout << "\nGo get more money\n";
        }

    }

    void sellItems(DLL &inventory, currency &gold) {
        int sell = 0;
        node* selling = inventory.head;
        while (sell == 0) {
            //Iterate throught inventory to see what you want to sell
            std::cout << "(1 to sell, 0 for next)";
            std::cin >> sell;
            if (sell == 1) {
                gold.deposit(selling->data->getCost());
                inventory.deleteCurrent();
                break;
            }
            else {
                selling = selling->nextNode;
            }
        }
    }
    //void displayStock() const {
      //  std::cout << "\nShop Inventory:\n";
        //for (size_t i = 0; i < stock.size(); ++i) {
          //  std::cout << i + 1 << ". " << stock[i]->getItem() << " - " << stock[i]->getCost() << " gold\n";
        //}
    //}

    //std::shared_ptr<items> buyItem(int index, int& playerGold) {
      //  if (index < 0 || index >= stock.size()) {
        //    std::cout << "Invalid choice!\n";
          //  return nullptr;
        //}
        //if (playerGold < stock[index]->getCost()) {
          //  std::cout << "Not enough gold!\n";
            //return nullptr;
        //}
        //layerGold -= stock[index]->getCost();
       //std::shared_ptr<items> purchasedItem = stock[index];
        //stock.erase(stock.begin() + index);
        //return purchasedItem;
        // }
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

int main() {

}