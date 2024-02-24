#include "Item.h"

void CategorizeItems(ifstream& File, Item* List, int& Size) 
{
	int ItemNumber;
	int NumberInStock;
	float UnitPrice;
	int MinimunInventoryLevel;
	string ItemName;
	string Line;
	stringstream StreamLine; 
	while (File)
	{
		File >> Line;
		StreamLine.str(Line);
	}
	
}
void AddItem(Item* List, int& Size) 
{

}
void RemoveItem(Item* List, int& Size) 
{

}
void InsertItem(Item* List, int& Size) 
{

}
void DisplayItem(Item* List, int& Size) 
{

}
void SearchForItem(Item* List, int& Size) 
{

}
