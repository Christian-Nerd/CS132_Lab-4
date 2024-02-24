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
	/*
	bool Same = false;
	ItemNumber = Item1.ItemNumber;
	NumberInStock = Item1.NumberInStock;
	UnitPrice = Item1.UnitPrice;
	MinimunInventoryLevel = Item1.MinimunInventoryLevel;
	ItemName = Item1.ItemName;
	*/
	return (Item1.ItemNumber == Item2.ItemNumber && Item1.NumberInStock == Item2.NumberInStock && Item1.UnitPrice == Item2.UnitPrice && Item1.MinimunInventoryLevel == Item2.MinimunInventoryLevel && Item1.ItemName == Item2.ItemName);
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
		}
		else
			AddItem(List, Size, Count);
	}
	
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
void InsertItem(Item*& List, int& Position, int& Size, int& Count) 
{

}
void DisplayItem(const Item* List, const int& Size)
{

}
int SearchForItem(Item* List, const int& Size, Item Key)
{
	
	for (int i = 0; i < Size; i++) 
	{
		if (List[i] == Key)
			return i;
	}
	return -1;
}