#include "Item.h"
int main() 
{
	Item *Inventory = new Item[50];
	int Size = 50, Count = 0;;
	ifstream Data;
	OpenInvenentoryFile(Data);
	CategorizeItems(Data, Inventory, Size, Count);
	cout << "You can output your inventory to a file, add/remove items, and search for items by name" << endl;
	ChooseOperation(Data, Inventory, Size, Count);
	return 0;
}