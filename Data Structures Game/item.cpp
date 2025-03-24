#include <iostream>
#include <string>

#include "item.h"


// items class implementation
items::items(const std::string& itemName, const std::string& classification, int costAmnt)
    : item(itemName), type(classification), cost(costAmnt) {}

std::string items::getItem() const {
    return item;
}

std::string items::getType() const {
    return type;
}

int items::getCost() const {
    return cost;
}

// weapons class implementation
weapons::weapons(const std::string& item, const std::string& classification, int costAmnt, int dam)
    : items(item, classification, costAmnt), damage(dam) {}

int weapons::getDamage() const {
    return damage;
}

// Potions class implementation
Potions::Potions(const std::string& item, const std::string& classification, int costAmnt, int ammount) 
    : items(item, classification, costAmnt), ammount(ammount) {} 


int Potions::getAmmount() {
    return ammount;
}
void Potions::use() {
    ammount = ammount - 1;
}

//healling potion class
HealingPotion::HealingPotion(const std::string& item, const std::string& classification, int costAmnt, int ammount, int healingAmmount)
    : Potions(item, classification, costAmnt, ammount), healingAmmount(healingAmmount) {
}

int HealingPotion::getHealingAmmount() {
    return healingAmmount;
}


// currency class implementation
currency::currency(const std::string& item, const std::string& classification, int costAmnt, int amnt)
    : items(item, classification, costAmnt), amount(amnt) {}

int currency::getMoney() const {
    return amount;
}