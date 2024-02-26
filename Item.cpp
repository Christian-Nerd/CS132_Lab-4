#include "Item.h"

Item Item::operator=(Item& Item1) 
{
	if (this == &Item1)
		return *this;
	ItemNumber = Item1.ItemNumber;
	NumberInStock = Item1.NumberInStock;
	UnitPrice = Item1.UnitPrice;
	MinimunInventoryLevel = Item1.MinimunInventoryLevel;
	ItemName = Item1.ItemName;
	return Item1;
}
bool operator==(Item& Item1, Item& Item2) 
{
	return (Item1.ItemNumber == Item2.ItemNumber && Item1.NumberInStock == Item2.NumberInStock && Item1.UnitPrice == Item2.UnitPrice && Item1.MinimunInventoryLevel == Item2.MinimunInventoryLevel && Item1.ItemName == Item2.ItemName);
}
Item operator<<(ostream& out, Item& Item1) 
{
	DisplayItem(Item1, out);
	return Item1;
}
Item operator>> (ifstream& in, Item& Item1) 
{
	in >> Item1.ItemNumber;
	in >> Item1.NumberInStock;
	in >> Item1.UnitPrice;
	in >> Item1.MinimunInventoryLevel;
	in >> Item1.ItemName;
	return Item1;
}

void OpenInvenentoryFile(ifstream& File)
{
	string Filename = "";
	cout << "Please input the path for your inventory file: ";
	cin >> Filename;
	File.open(Filename, ios::in || ios::app);
	while (!File.is_open())
	{
		cerr << endl << "Invalid File Path please renter: ";
		cin >> Filename;
		File.open(Filename, ios::in || ios::app);
	}
}
void ChooseOperation(ifstream& Data, Item* Inventory, int& Size, int& Count)
{
	cout << "Input your operation on the inventory: ";
	string Operation;
	cin >> Operation;
	transform(Operation.begin(), Operation.end(), Operation.begin(), tolower); // Convert Current Itemname to lowercase
	if (Operation == "add item" || Operation == "add")
	{
		Item NewItem = DefineItem();
		int Position = 0;
		do
		{
			cout << "What position do you want your new object to be in? ";
			cin >> Position;
			if (!cin)
			{
				cerr << "Invalid Position must be within 0 and " << Size - 1;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			AddItem(Inventory, NewItem, Position, Size, Count);
		} while (!cin);
	}
	if (Operation == "remove item" || Operation == "remove")
	{
		int Position = 0;
		cout << "What object do you want to delete? ";
		do
		{
			cin >> Position;
			if (!cin)
			{
				cerr << "Invalid Position must be within 0 and " << Size - 1;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		} while (!cin);
			RemoveItem(Inventory, Position, Size, Count);
	}
	if (Operation == "output" || Operation == "print" || Operation == "<<")
	{
		string FileName;
		ofstream OutputFile;
		cout << "What output Filename do you prefer? ";
		do
		{
			cin >> FileName;
			OutputFile.open(FileName, ios::out);
			if (!OutputFile.is_open())
			{
				cerr << "Invalid Output Filename must be a regular name. ";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		} while (!cin || !OutputFile.is_open());
		for (int i = 0; i < Count; i++) 
		{
			OutputFile << Inventory;
		}
		cout << "File created!" << endl;
	}
	if (Operation == "search item" || Operation == "search" || Operation == "find")
	{
		string ItemName = "";
		cout << "What object do you want to delete? ";
		do
		{
			cin >> ItemName;
			if (!cin)
			{
				cerr << "Invalid ItemName must be a name!";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		} while (!cin);
		int Index = SearchForItem(Inventory, Size, ItemName);
		if (Index == -1)
		{
			cout << "Item not found.";
		}
		else
			cout << "Item found at " + Index;
	}
}

bool UserContinue() 
{
	bool Continue = false;
	string Choice = "";
	do
	{
		cout << "Do you want to continue y/n: ";
		cin >> Choice;
		if (!cin)
		{
			cerr << "Invalid Choice must be yes or no: ";
			continue;
		}
		transform(Choice.begin(), Choice.end(), Choice.begin(), tolower); // Turn choice lowercase
		if (Choice == "y" || Choice == "yes")
		{
			Continue = true;
		}
		else if (Choice == "no" || Choice == "n") 
		{
			Continue = false;
			cout << endl << "Goodbye then.";
		}
	} while (!cin);
	return Continue;
}
void CategorizeItems(ifstream& File, Item* List, int& Size, int& Count) 
{
	string ItemNumber;
	string NumberInStock;
	string UnitPrice;
	string MinimunInventoryLevel;
	string ItemName;
	string Line;
	stringstream StreamLine; 
	int Iterator = 0;
	while (File)
	{
		getline(File, Line);
		StreamLine.str(Line);
		if (Iterator < Size)
		{
			cout << !StreamLine;
			StreamLine >> ItemNumber;
			List[Iterator].ItemNumber = stoi(ItemNumber);
			StreamLine >> NumberInStock;
			 List[Iterator].NumberInStock = stoi(NumberInStock);
			StreamLine >> UnitPrice;
			List[Iterator].UnitPrice = stof(UnitPrice);
			StreamLine >> MinimunInventoryLevel;
			List[Iterator].MinimunInventoryLevel = stof(MinimunInventoryLevel);
			StreamLine >> List[Iterator].ItemName;
			Count++;
			cout << !StreamLine;
		}
		else
			AddItem(List, List[Iterator], Iterator, Size, Count);
		Iterator++;
	}
	File.clear();
	File.seekg(ios::beg);
}
Item DefineItem() 
{
		Item Object;
		cout << "Input your item name: ";
		cin >> Object.ItemName;
		while (!cin)
		{
			cout << "Input your Item Number: ";
			cin >> Object.ItemNumber;
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
			cin >> Object.NumberInStock;
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
			cin >> Object.MinimunInventoryLevel;
			if (!cin)
			{
				cerr << "Invalid Minimum Inventory Level input an integer. " << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		}
		while (!cin) 
		{
			cout << "Input your Item's Price: ";
			cin >> Object.UnitPrice;
			if (!cin)
			{
				cerr << "Invalid Price input a integer/decimal. " << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		}
		return Object;
}
void AddItem(Item*& List, Item& Object, int Position, int& Size, int& Count) 
{
	while (Position >= Size) 
	{
		Item* TempList = new Item[Size * 2];
		for (int i = 0; i < Size - 1; i++)
		{
			TempList[i] = List[i];
		}
		delete List;
		TempList = List;
	}
	for (int i = Position; i < Size - 1; i++) 
	{
		List[i + 1] = List[i];
		List[i] = Object;
	}
	Size++;
	Count++;
}
void RemoveItem(Item*& List, int Position, int& Size, int& Count) 
{
	for (int i = Position; i < Size - 1; i++) 
	{
		List[i] = List[i + 1];
	}
	for (int i = 0; Position == Size - 1 && i < Size; i++) 
	{
		List[i + 1] = List[i];
	}
	Size--;
	Count--;
}
void DisplayItems(const Item* List, const int& Size, ostream& out)
{
	for (int i = 0; i < Size; i++) 
	{
		out << List[i].ItemNumber << " ";
		out << List[i].NumberInStock << " ";
		out << List[i].MinimunInventoryLevel << " ";
		out << List[i].UnitPrice << " ";
		out << List[i].ItemName << endl;
	}
}
void DisplayItem(const Item& Object, ostream& out) 
{
		out << Object.ItemNumber << " ";
		out << Object.NumberInStock << " ";
		out << Object.MinimunInventoryLevel << " ";
		out << Object.UnitPrice << " ";
		out << Object.ItemName << endl;
}
int SearchForItem(Item* List, const int& Size, string Key)
{
	transform(Key.begin(), Key.end(), Key.begin(), tolower); // Convert Key Itemname to lowercase
	for (int i = 0; i < Size; i++) 
	{
		transform(List[i].ItemName.begin(), List[i].ItemName.end(), List[i].ItemName.begin(), tolower); // Convert Current Itemname to lowercase
		if (List[i].ItemName == Key)
			return i;
	}
	return -1;
}
