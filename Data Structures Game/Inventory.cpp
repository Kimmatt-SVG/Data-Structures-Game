#include "Inventory.h"
#include <string>
#include <iostream>

inventory::inventory(std::string varPlace, std::string varDesc, int amount, bool cool, std::string whatItIs, int location) : item(varPlace), description(varDesc), amt(amount), unique(cool), type(whatItIs), place(location) {

}

int inventory::getPlace() {
	return place;
}

std::string inventory::getItem() {
	return item;
}

std::string inventory::getDescription() {
	return description;
}

std::string inventory::typeOfThing() {
	return type;
}

int inventory::getAmmount() {
	return amt;
}

bool inventory::isUnique() {
	return unique;
}

void inventory::display() {
	std::cout << "Item no. " << place << "\n" << std::endl;
	std::cout << "Item: " << item << "\n"
		<< "Description: " << description << "\n"
		<< "Amount: " << amt << "\n"
		<< "Unique: " << (unique ? "Yes" : "No") << "\n"
		<< "Type: " << type << "\n";
}