#include "Item.h"
#include "Inventory.h"

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

