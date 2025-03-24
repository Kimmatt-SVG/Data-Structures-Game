#pragma once
#include <string>

class items {
private:
    std::string item;
    std::string type;
    int cost;

public:
    items(const std::string& itemName, const std::string& classification, int costAmnt);
    virtual ~items() = default; // Virtual destructor for proper cleanup in derived classes

    std::string getItem() const;
    std::string getType() const;
    int getCost() const;
};

class weapons : public items {
private:
    int damage;

public:
    weapons(const std::string& item, const std::string& classification, int costAmnt, int dam);
    int getDamage() const;
};

class Potions : public items {
private:
    int ammount;

public:
    Potions(const std::string& item, const std::string& classification, int costAmnt, int ammount);
    int getAmmount();
    void use();
};

class HealingPotion : public Potions {
private:
    int healingAmmount;

public:
    HealingPotion(const std::string& item, const std::string& classification, int costAmnt, int ammount, int healingAmmount);
    int getHealingAmmount();
};

class currency : public items {
private:
    int amount;

public:
    currency(const std::string& item, const std::string& classification, int costAmnt, int amnt);
    int getMoney() const;
};