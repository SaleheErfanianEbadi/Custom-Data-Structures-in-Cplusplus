#pragma once

#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>

using namespace std;

class myhash {

private:

	static const int tableSize = 10;

	struct item {
		string name;
		string drink;
		item* next;
	};

	item* HashTable[tableSize];

public:

	myhash();
	~myhash();

	int  Hash(string key);
	void AddItem(string name, string drink);
	int  NumberOfItemsInIndex(int index);
	void PrintTable();
	void PrintItemsInIndex(int index);
	void FindDrink(string name);
	void RemoveItem(string name);

};


#endif // !HASH_H
