#pragma once
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
struct Item
{
	int ItemNumber;
	int NumberInStock;
	float UnitPrice;
	int MinimunInventoryLevel;
	string ItemName;
	Item(int Number = 0, int InStock = 0, float Price = 0, int InventoryLevel = 1, string Name = "Untitled") :
		ItemNumber(Number), NumberInStock(InStock), UnitPrice(Price),
		MinimunInventoryLevel(InventoryLevel), ItemName(Name)
	{};
	Item operator=(Item& Item1);
};
bool operator==(Item& Item1, Item& Item2);
Item operator<<(ostream& out, Item& Item1);
Item operator>> (ifstream& in, Item& Item1);

