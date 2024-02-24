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
};
void CategorizeItems(ifstream&, Item*, int& Size);
void AddItem(Item*, int& Size);
void RemoveItem(Item*, int& Size);
void InsertItem(Item*, int& Size);
void DisplayItem(Item*, int& Size);
void SearchForItem(Item*, int& Size);

