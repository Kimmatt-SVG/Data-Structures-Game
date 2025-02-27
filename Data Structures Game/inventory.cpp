#include "inventory.h"

node::node(items* x) : data(x), nextNode(nullptr), prevNode(nullptr) {}

items* node::getItem() {
    return data;
}


    DLL::DLL() {
        head = index = tail = nullptr;
    }

    node* DLL::getCurrent() {
        return index;
    }

    node* DLL::getLast() {
        if (!head)
            return nullptr;
        node* temp = head;
        while (temp->nextNode) {
            temp = temp->nextNode;
        }
        return temp;

    }
    node* DLL::getFirst() {
        return head;
    }

    void DLL::pushBack(items* newItem) {
        node* newNode = new node(newItem);
        if (!head) {
            head = newNode;
        }
        else {
            node* final = getLast();
            final->nextNode = newNode;
            newNode->prevNode = final;
        }
        index = head;

    }

    void DLL::insertAfter(node* prev, node* newNode) {
        newNode->nextNode = prev->nextNode;
        if (prev->nextNode) prev->nextNode->prevNode = newNode;
        prev->nextNode = newNode;
        newNode->prevNode = prev;
        index = newNode;

    }

    void DLL::insertFront(node* newNode) {

        newNode->nextNode = head;
        head->prevNode = newNode;

        head = newNode;
        newNode->prevNode = nullptr;

        index = head;


    }

    void DLL::deleteCurrent() {

        node* deleting = index;
        node* next = index->nextNode;
        node* prev = index->prevNode;
        if (index == head)
        {
            head = next;
            if (head) {
                head->prevNode = nullptr;
            }
        }
        else {

            prev->nextNode = next;

        }
        if (next) {
            index->nextNode = prev;
        }

        index = next;
        delete deleting;


    }

    void DLL::popBack() {

        if (!head)
            return;
        if (!head->nextNode)
        {
            node* remove = head;
            head = index = nullptr;
            delete remove;
        }
        node* removing = getLast();
        node* prev = getLast()->prevNode;
        prev->nextNode = nullptr;
        removing->prevNode = nullptr;
        delete removing;


    }

    void DLL::popFront() {
        if (!head)
            return;


        node* deleting = head;
        head = head->nextNode;
        if (index == deleting) {
            index = head;
        }

        deleting->nextNode = nullptr;
        head->prevNode = nullptr;

        delete deleting;
    }

    DLL::~DLL() {
        while (head) popFront(); // Clean up memory
    }

    void DLL::displayList() const {
        node* temp = head;
        std::cout << "This is your inventory: " << std::endl;
        while (temp) {
            temp->data->getItem();
            std::cout << temp->data->getItem() << std::endl;
            temp = temp->nextNode;
        }
    }
