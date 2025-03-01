//Shop Class
#include "item.h"
#include "inventory.h"

int Qty;
int getCost(items thing){
	return thing.cost;
}
void Purchase() {
	//Get list of items that can be sold
	//Get Costs
	//Deduct cost from actual money if 
}
void Sell(DLL inventory) {
	int a;

	std::cout << "What do you wish to sell\n";
	inventory.displayList();
	cin >> a;

	for (int i = 1; i <= a; i++) {
		inventory.index->nextNode;
	}
	 
	items q = &inventory.getCurrent()->data;
	getCost(q);

	


}
