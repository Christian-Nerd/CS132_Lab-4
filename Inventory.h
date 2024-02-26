#pragma once
#include "Item.h"
static int DefaultSize = 0, DefaultCount = 0;
void OpenInvenentoryFile(ifstream&);
void ChooseOperation(ifstream&, Item*&, int& Size, int& Count = DefaultCount);
bool UserContinue();
void CategorizeItems(ifstream&, Item*&, int& Size, int& Count = DefaultCount);
Item DefineItem();
void AddItem(Item*&, Item&, int Position = 0, int& Size = DefaultSize, int& Count = DefaultCount);
void RemoveItem(Item*&, int Position = 0, int& Size = DefaultSize, int& Count = DefaultCount);
void DisplayItems(const Item*, const int& Size, ostream&);
void DisplayItem(const Item, ostream&);
int SearchForItem(Item*&, const int& Size, string Key);
