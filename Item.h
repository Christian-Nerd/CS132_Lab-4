#pragma once
#include <iostream>
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
int DefaultSize = 0, DefaultCount = 0;
void CategorizeItems(ifstream&, Item*, int& Size, int& Count = DefaultCount);
void AddItem(Item*&, int Position = 0, int& Size = DefaultSize, int& Count = DefaultCount);
void RemoveItem(Item*&, int Position = 0, int& Size = DefaultSize, int& Count = DefaultCount);
void InsertItem(Item*&, int Position = 0, int& Size = DefaultSize, int& Count = DefaultCount);
void DisplayItem(const Item*, const int& Size);
int SearchForItem(Item*, const int& Size, Item Key);
bool operator==(Item& Item1, Item& Item2);
Item operator<<(ostream& out, Item& Item1);
Item operator>> (ifstream& in, Item& Item1);
