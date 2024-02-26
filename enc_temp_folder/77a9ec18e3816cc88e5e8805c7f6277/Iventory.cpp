#include "Item.h"
int main() 
{
	cout << setprecision(2);
	do
	{
		Item *Inventory = new Item[50];
		int Size = 50, Count = 0;;
		ifstream Data;
		OpenInvenentoryFile(Data);
		CategorizeItems(Data, Inventory, Size, Count);
		cout << "You can output your inventory to a file, add/remove items, and search for items by name";
		cout << endl;
		ChooseOperation(Data, Inventory, Size, Count);
	} while (UserContinue());
	return 0;
}