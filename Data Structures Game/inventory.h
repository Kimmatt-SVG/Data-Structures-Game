#pragma once
#include <iostream>
#include <string>
#include "item.h"
//fill out later

class node {
public:
    items* data;
    node* nextNode;
    node* prevNode;

    node(items* x);

    items* getItem();
};

class DLL {
public:
    node* head;
    node* tail;
    node* index;

    DLL();
    node* getCurrent();
    node* getLast();
    node* getFirst();
    void pushBack(items* newItem);
    void insertAfter(node* prev, node* newNode);
    void insertFront(node* newNode);
    void deleteCurrent();
    void popBack();
    void popFront();
    ~DLL();
    void displayList() const;
};


/*
    DLL inventory;

    inventory.pushBack(new weapons("Sword", "A sharp blade", "Melee Weapon", 50, 80));
    inventory.pushBack(new weapons("Bow", "A long-range bow", "Ranged Weapon", 30, 90));
    inventory.pushBack(new healing("Health Potion", "Restores HP", "Consumable", 50, 0));
    inventory.pushBack(new healing("Mana Potion", "Restores Mana", "Consumable", 0, 50));
    inventory.pushBack(new items("Shield", "Blocks attacks", "Armor"));
    inventory.pushBack(new items("Torch", "Provides light", "Utility"));

    std::cout << "Inventory List:\n";
    inventory.displayList();
    */
