#pragma once
#include <string>

class items {
private:
    std::string item;
    std::string description;
    std::string type;
    int cost;
    int sell;

public:
    items(const std::string& itemName, const std::string& desc, const std::string& classification, int costAmnt, int sellValue);
    virtual ~items() = default; // Virtual destructor for proper cleanup in derived classes

    std::string getItem() const;
    std::string getDescription() const;
    std::string getType() const;
    int getCost() const;
    int getSellValue() const;
};

class weapons : public items {
private:
    int damage;
    int accuracy;

public:
    weapons(const std::string& item, const std::string& description, const std::string& classification, int costAmnt, int sellValue, int dam, int acc);
    int getDamage() const;
    int getAccuracy() const;
};

class healing : public items {
private:
    int heal;
    int manaUsage;

public:
    healing(const std::string& item, const std::string& description, const std::string& classification, int costAmnt, int sellValue, int h, int mana);
    int getHeal() const;
    int getManaCost() const;
    void display() const;
};

class currency : public items {
private:
    int amount;

public:
    currency(const std::string& item, const std::string& description, const std::string& classification, int costAmnt, int sellValue, int amnt);
    int getMoney() const;
    void deduct(int n) {
        amount -= n;
        if (amount < 0) amount = 0;
    }
    void deposit(int n) {
        amount += n;
    }
};