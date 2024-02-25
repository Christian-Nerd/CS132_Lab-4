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
		Item NewItem = DefineItem();
		int Position = 0;
		cout << "What position do you want your new object to be in?";
		do
		{
			cin >> Position;
			if (!cin)
			{
				cerr << "Invalid Position must be within 0 and " << Size - 1;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		}
		while (!cin);
		AddItem(Inventory, NewItem, Position, Size, Count);
	}
	if (Operation == "remove item" || Operation == "remove")
	{
		Item NewItem = DefineItem();
		int Position = 0;
		cout << "What object do you want to delete?";
		do
		{
			cin >> Position;
			if (!cin)
			{
				cerr << "Invalid Position must be within 0 and " << Size - 1;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		} 
		while (!cin);
		RemoveItem(Inventory, Position, Size, Count);
	}   
	if (Operation == "output" || Operation == "print" || Operation == "<<")
	{
		Item NewItem = DefineItem();
		string FileName;
		ofstream OutputFile;
		int Position = 0;
		cout << "What output Filename do you prefer?";
		do
		{
			cin >> FileName;
			OutputFile.open(FileName, ios::out);
			if (!OutputFile.is_open())
			{
				cerr << "Invalid Output Filename must be within 0 and " << Size - 1;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		}
		while (!cin);
		RemoveItem(Inventory, Position, Size, Count);
	}   
	if (Operation == "search item" || Operation == "search" || Operation == "find")
	{
		Item NewItem = DefineItem();
		string ItemName = "";
		cout << "What object do you want to delete?";
		do
		{
			cin >> ItemName;
			if (!cin)
			{
				cerr << "Invalid ItemName must be a name!";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		}
		while (!cin);
		int Index = SearchForItem(Inventory, Size, ItemName);
		if (Index == -1)
		{
			cout << "Item not found.";
		}
		else
			cout << "Item found at " + Index;
	}   
	return 0;
}