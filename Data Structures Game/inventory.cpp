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

        //a counter number to lable how many items there are in the inventory
        int couter = 1;

        //clears the CLI
        system("cls");

        //temp variables to hold user response
        int response;
        int response2;

        //displayes whole inventory
        node* temp = head;
        std::cout << "This is your inventory: " << std::endl;
        while (temp) {
            temp->data->getItem();
            std::cout << couter << ". " << temp->data->getItem() << std::endl;
            temp = temp->nextNode;
            couter++;
        }

        //displays choices for managing inventory 
        std::cout << "Press 1 to manage inventory or 0 to quit" << std::endl;
        std::cin >> response;

        //catches a miss responce
        if (response != 1 && response != 0) {
            std::cout << "This is an invalid choice";
            manaageInventory();
        }
        //manages inventory
        else if (response == 1) {
            std::cout << "Enter the item number you would like to remove (press 0 to exit): " << std::endl;

            std::cin >> response2;
            system("cls");

                //checks for exit response
            if (response2 == 0) {
                return;
            }

            //checks if the number is a valid number
            if (response2 < 1 || response2 >= couter) {
                manaageInventory();
                return;
            }

            //finds the node that the user inputed 
            node* target = head;
            int count = 1;
            while (target != nullptr && count < response2) {
                target = target->nextNode;
                count++;
             }

             //if the node does not exist
             if (target == nullptr) {
                  return;
             }

             //removes the node from the list
             if (target == head) {
                //if the target is the first node
                DLL::popFront();
             }
             else if (target == DLL::getLast()) {
                 //if target is the last node
                 DLL::popBack();
             }
             else {
                // Otherwise, unlink the node from the list and delete it
                target->prevNode->nextNode = target->nextNode;
                target->nextNode->prevNode = target->prevNode;
                delete target;
             }

             std::cout << "Item removed successfully." << std::endl;
        }
        //exits
        else if (response == 0) {
            system("cls");
            return;
        }
    }
