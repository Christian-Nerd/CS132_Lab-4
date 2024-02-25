#include "Item.h"
int main() 
{
	Item *Inventory = new Item[50];
	int Size = 50, Count = 0;;
	ifstream Data;
	OpenInvenentoryFile(Data);
	CategorizeItems(Data, Inventory, Size, Count);
	cout << "You can output your inventory to a file, add/remove items, and search for items by name" << endl;
	cout << "Input your operation on the inventory: ";
	string Operation;
	transform(Operation.begin(), Operation.end(), Operation.begin(), tolower); // Convert Current Itemname to lowercase
	cin >> Operation;
	if (Operation == "add item" || Operation == "add")
	{
	int ItemNumber, NumberInStock, MinimunInventoryLevel;
	float UnitPrice;
	string ItemName;

		cout << "Input your item name: ";
		cin >> ItemName;
		while (!cin)
		{
			cout << "Input your Item Number: ";
			cin >> ItemNumber;
			if (!cin)
			{
				cerr << "Invalid Item Number input an integer. " << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		}
		while (!cin) 
		{
			cout << "Input your Stock Number: ";
			cin >> NumberInStock;
			if (!cin)
			{
				cerr << "Invalid Stock Number input an integer. " << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		}
		while (!cin) 
		{
			cout << "Input your Minimum Inventory: ";
			cin >> NumberInStock;
			if (!cin)
			{
				cerr << "Invalid Minimum Inventory Level input an integer. " << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		}

	}
	return 0;
}