#include "inventory.h"
#include "globals.h"

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
        // Check if the list already has 8 items
        int count = 0;
        node* temp = head;
        while (temp) {
            count++;
            temp = temp->nextNode;
        }

        if (count >= 4) {
            std::cout << "Inventory is full. Cannot add more items." << std::endl;
            return;
        }

        // Add the new item to the list
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

    void DLL::displayInvnetory() {
        node* temp = head;
        int counter = 1; // Initialize a counter for numbering items
        std::cout << std::endl << "This is your inventory: " << std::endl;
        while (temp) {
            std::string itemName = temp->data->getItem();
            std::cout << counter << ". " << itemName << std::endl; // Display the item with its number
            temp = temp->nextNode;
            counter++; // Increment the counter
        }
        std::cout << std::endl;
    }

    void DLL::swapItems() {
        if (!head || !head->nextNode) {
            std::cout << "Not enough items in the inventory to swap." << std::endl;
            return;
        }

        // Display the inventory
        displayInvnetory();

        int firstItemIndex, secondItemIndex;
        std::cout << "Enter the number of the first item to swap: ";
        std::cin >> firstItemIndex;
        std::cout << "Enter the number of the second item to swap: ";
        std::cin >> secondItemIndex;

        // Validate input
        if (firstItemIndex < 1 || secondItemIndex < 1 || firstItemIndex == secondItemIndex) {
            std::cout << "Invalid input. Please try again." << std::endl;
            return;
        }

        // Find the nodes corresponding to the selected indices
        node* firstNode = head;
        node* secondNode = head;
        int currentIndex = 1;

        while (firstNode && currentIndex < firstItemIndex) {
            firstNode = firstNode->nextNode;
            currentIndex++;
        }

        currentIndex = 1;
        while (secondNode && currentIndex < secondItemIndex) {
            secondNode = secondNode->nextNode;
            currentIndex++;
        }

        // Ensure both nodes exist
        if (!firstNode || !secondNode) {
            std::cout << "One or both items not found. Please try again." << std::endl;
            return;
        }

        // Check if the first two slots are being swapped with non-weapon items
        if ((firstItemIndex <= 2 || secondItemIndex <= 2)) {
            if (firstNode->data->getType() != "Weapon" || secondNode->data->getType() != "Weapon") {
                std::cout << "Error: Only weapon-type items can be swapped into the first two slots." << std::endl;
                return;
            }
        }

        // Swap the data pointers
        items* temp = firstNode->data;
        firstNode->data = secondNode->data;
        secondNode->data = temp;

        // Display the updated inventory
        std::cout << "Items swapped successfully!" << std::endl;
        displayInvnetory();
        pauseThenClear();
    }



    void DLL::manaageInventory() {
        while (true) { // Loop until the user chooses to quit
            int counter = 1;
            system("cls");

            int response;

            node* temp = head;
            std::cout << "This is your inventory: " << std::endl;
            while (temp) {
                std::string itemName = temp->data->getItem();

                HealingPotion* potion = dynamic_cast<HealingPotion*>(temp->data);
                if (potion) {
                    std::cout << counter << ". " << itemName << " (x" << potion->getAmmount() << ")" << std::endl;
                }
                else {
                    std::cout << counter << ". " << itemName << std::endl;
                }

                temp = temp->nextNode;
                counter++;
            }

            std::cout << "Press 1 to remove an item, 2 to swap items, or 0 to quit: ";
            std::cin >> response;

            if (response == 1) {
                int itemIndex;
                std::cout << "Enter the item number you would like to remove (press 0 to exit): ";
                std::cin >> itemIndex;

                if (itemIndex == 0) {
                    continue; // Return to the main menu
                }

                if (itemIndex < 1 || itemIndex >= counter) {
                    std::cout << "Invalid item number. Please try again." << std::endl;
                    system("pause");
                    continue;
                }

                // Find the node to remove
                node* target = head;
                int currentIndex = 1;
                while (target && currentIndex < itemIndex) {
                    target = target->nextNode;
                    currentIndex++;
                }

                if (target) {
                    removeNode(target);
                    std::cout << "Item removed successfully!" << std::endl;
                }
                else {
                    std::cout << "Item not found. Please try again." << std::endl;
                }

                system("pause");
            }
            else if (response == 2) {
                system("cls");
                swapItems();
            }
            else if (response == 0) {
                system("cls");
                return; // Exit the loop and quit
            }
            else {
                std::cout << "Invalid choice. Please try again." << std::endl;
                system("pause");
            }
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
