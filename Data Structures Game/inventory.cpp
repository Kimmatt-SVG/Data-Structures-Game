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

    void DLL::manaageInventory() {
        int couter = 1;
        system("cls");

        int response;
        int response2;

        node* temp = head;
        std::cout << "This is your inventory: " << std::endl;
        while (temp) {
            std::string itemName = temp->data->getItem();

            HealingPotion* potion = dynamic_cast<HealingPotion*>(temp->data);
            if (potion) {
                std::cout << couter << ". " << itemName << " (x" << potion->getAmmount() << ")" << std::endl;
            }
            else {
                std::cout << couter << ". " << itemName << std::endl;
            }

            temp = temp->nextNode;
            couter++;
        }

        std::cout << "Press 1 to manage inventory or 0 to quit" << std::endl;
        std::cin >> response;

        if (response != 1 && response != 0) {
            std::cout << "This is an invalid choice";
            manaageInventory();
        }
        else if (response == 1) {
            std::cout << "Enter the item number you would like to remove (press 0 to exit): " << std::endl;
            std::cin >> response2;
            system("cls");

            if (response2 == 0) return;

            if (response2 < 1 || response2 >= couter) {
                manaageInventory();
                return;
            }

            node* target = head;
            int count = 1;
            while (target != nullptr && count < response2) {
                target = target->nextNode;
                count++;
            }

            if (target == nullptr) return;

            if (target == head) {
                popFront();
            }
            else if (target == getLast()) {
                popBack();
            }
            else {
                target->prevNode->nextNode = target->nextNode;
                target->nextNode->prevNode = target->prevNode;
                delete target;
            }

            std::cout << "Item removed successfully." << std::endl;
        }
        else if (response == 0) {
            system("cls");
            return;
        }
    }


    void DLL::removeNode(node* target) {
        if (!target) return;

        // If the target is the head node, use popFront.
        if (target == head) {
            popFront();
            return;
        }

        // If the target is the last node, use popBack.
        if (target == getLast()) {
            popBack();
            return;
        }

        // Otherwise, unlink the node and delete it.
        node* prev = target->prevNode;
        node* next = target->nextNode;
        if (prev) {
            prev->nextNode = next;
        }
        if (next) {
            next->prevNode = prev;
        }
        delete target;
    }
