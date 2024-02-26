#include "Item.h"
Item *Inventory;
int Size, Count;
ifstream Data;
int main() 
{
	cout << setprecision(2);
	OpenInvenentoryFile(Data);
	do
	{
		Inventory = new Item[50];
		Size = 50;
		Count = 0;
		CategorizeItems(Data, Inventory, Size, Count);
		cout << "You can output your inventory to a file, add/remove items, and search for items by name";
		cout << endl;
		ChooseOperation(Data, Inventory, Size, Count);
	} while (UserContinue());
	Data.close();
	return 0;
}