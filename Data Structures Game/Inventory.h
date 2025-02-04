#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>

class inventory {
	private:
		std::string item;
		std::string description;
		int amt;
		bool unique;
		std::string type;
		int place;
	public:
		inventory(std::string varPlace, std::string varDesc, int amount, bool cool, std::string whatItIs, int location);
		int getPlace();
		std::string getItem();
		std::string getDescription();
		std::string typeOfThing();
		int getAmmount();
		bool isUnique();
		void display();

};
#endif 

