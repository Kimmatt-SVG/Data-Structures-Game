#include<iostream>
#include "item.h"
#include "C:\Users\kingb\source\repos\Data-Structures-Game\game\Data Structures Game\inventory.cpp"

void Purchase(currency &gold, items item, DLL invent) {
	int cost = item.getCost();
	gold.amount = gold.amount - cost;
	invent.pushBack(&item);
	//add to inventory
}
 
void Sell(currency &gold, items item) {
	int sell = item.getSellValue();
	gold.amount = gold.amount + sell;
}