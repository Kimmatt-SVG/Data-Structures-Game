#include <iostream>
#include <string>

#include "item.h"


// items class implementation
items::items(const std::string& itemName, const std::string& desc, const std::string& classification, int costAmnt, int sellValue)
    : item(itemName), description(desc), type(classification), cost(costAmnt), sell(sellValue) {}

std::string items::getItem() const {
    return item;
}

std::string items::getDescription() const {
    return description;
}

std::string items::getType() const {
    return type;
}

int items::getCost() const {
    return cost;
}

int items::getSellValue() const {
    return sell;
}

// weapons class implementation
weapons::weapons(const std::string& item, const std::string& description, const std::string& classification, int costAmnt, int sellValue, int dam, int acc)
    : items(item, description, classification, costAmnt, sellValue), damage(dam), accuracy(acc) {}

int weapons::getDamage() const {
    return damage;
}

int weapons::getAccuracy() const {
    return accuracy;
}

// healing class implementation
healing::healing(const std::string& item, const std::string& description, const std::string& classification, int costAmnt, int sellValue, int h, int mana)
    : items(item, description, classification, costAmnt, sellValue), heal(h), manaUsage(mana) {}

int healing::getHeal() const {
    return heal;
}

int healing::getManaCost() const {
    return manaUsage;
}

void healing::display() const {
    // Implementation for display
}

// currency class implementation
currency::currency(const std::string& item, const std::string& description, const std::string& classification, int costAmnt, int sellValue, int amnt)
    : items(item, description, classification, costAmnt, sellValue), amount(amnt) {}

int currency::getMoney() const {
    return amount;
}