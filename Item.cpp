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
}
Item operator>> (ifstream& in, Item& Item1) 
{
	in >> Item1.ItemNumber;
	in >> Item1.NumberInStock;
	in >> Item1.UnitPrice;
	in >> Item1.MinimunInventoryLevel;
	in >> Item1.ItemName;
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
void CategorizeItems(ifstream& File, Item* List, int& Size, int& Count) 
{
	int ItemNumber;
	int NumberInStock;
	float UnitPrice;
	int MinimunInventoryLevel;
	string ItemName;
	string Line;
	stringstream StreamLine; 
	int Iterator = 0;
	while (File)
	{
		File >> Line;
		StreamLine.str(Line);
		File >> ItemNumber;
		File >> NumberInStock;
		File >> UnitPrice;
		File >> MinimunInventoryLevel;
		File >> ItemName;
		if (Iterator < Size)
		{
			List[Iterator].ItemNumber = ItemNumber;
			List[Iterator].NumberInStock = NumberInStock;
			List[Iterator].UnitPrice = UnitPrice;
			List[Iterator].MinimunInventoryLevel = MinimunInventoryLevel;
			List[Iterator].ItemName = ItemName;
			Count++;
		}
		else
			AddItem(List, Size, Count);
	}
	File.clear();
	File.seekg(ios::beg);
}
void AddItem(Item*& List, int& Position, int& Size, int& Count) 
{
	if (Count >= Size) 
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
		List[i] = 
	}
	Size++;
	Count++;
}
void RemoveItem(Item*& List, int& Position, int& Size, int& Count) 
{
	for (int i = 0; i < Size - 1; i++) 
	{
		List[i] = List[i + 1];
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
