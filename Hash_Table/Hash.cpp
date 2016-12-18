#include "Hash.h"

myhash::myhash() {
	for (int i = 0; i < tableSize; i++) {
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = NULL;
	}
}

myhash::~myhash() {
	for (int i = 0; i < tableSize; i++) {
		delete HashTable[i];
	}
}

int myhash::Hash(string key) {
	int index;
	int hash = 0;

	for (unsigned int i = 0; i < key.length(); i++) {
		hash = hash + (int)key[i];
	}

	index = hash % tableSize;
	
	return index;
}

void myhash::AddItem(string name, string drink) {
	int index = Hash(name);

	if (HashTable[index]->name == "emtpy") {
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
	}
	else {
		item* Ptr = HashTable[index];
		item* n = new item;
		n->name = name;
		n->drink = drink;
		n->next = NULL;

		while (Ptr->next != NULL) {
			Ptr = Ptr->next;
		}
		Ptr->next = n;
	}
}

int myhash::NumberOfItemsInIndex(int index) {
	int count = 0;

	if (HashTable[index]->name == "empty") {
		count = 0;
	}
	else {
		count++;
		item* Ptr = HashTable[index];

		while (Ptr->next != NULL) {
			count++;
			Ptr = Ptr->next;
		}
		//return count;
	}

	return count;
}

void myhash::PrintTable() {
	int number;

	for (int i = 0; i < tableSize; i++) {
		number = NumberOfItemsInIndex(i);
		cout << "-----------------------" << endl;
		cout << "index = " << i << endl;
		cout << HashTable[i]->name << endl;
		cout << HashTable[i]->drink << endl;
		cout << "# of items = " << number << endl;
		cout << "-----------------------" << endl;
	}
}

void myhash::PrintItemsInIndex(int index) {
	item* Ptr = HashTable[index];

	if (Ptr->name == "empty") {
		cout << "index " << index << " is empty" << endl;
	}
	else {
		cout << "index " << index << " contains the following items" << endl;

		while (Ptr != NULL) {
			cout << "-----------------------" << endl;
			cout << Ptr->name << endl;
			cout << Ptr->drink << endl;
			cout << "-----------------------" << endl;
			Ptr = Ptr->next;
		}
	}
}

void myhash::FindDrink(string name) {
	int index = Hash(name);
	bool foundName = false;
	string drink;

	item* Ptr = HashTable[index];

	while (Ptr != NULL) {
		if (Ptr->name == name) {
			foundName = true;
			drink = Ptr->drink;
		}
		Ptr = Ptr->next;
	}
	
	if (foundName == true) {
		cout << "Favorite drink = " << drink << endl;
	}
	else {
		cout << name << "'s info was not found in the Hash table" << endl;
	}

}

void myhash::RemoveItem(string name) {
	int index = Hash(name);

	item* delPtr;
	item* P1;
	item* P2;

	// Case 0 - bucket is empty
	if (HashTable[index]->name == "empty" && HashTable[index]->drink == "empty") {
		cout << name << " was not found in the Hash Table" << endl;
	}

	// Case 1 - only 1 item in bucket and item has matching name
	else if (HashTable[index]->name == name && HashTable[index]->next == NULL) {
		HashTable[index]->name = "empty";
		HashTable[index]->drink = "empty";

		cout << name << " was removed from the Hash Table" << endl;
	}

	// Case 2 - match is located in the first item in the bucket but there are
	//          more items in the bucket
	else if (HashTable[index]->name == name) {
		delPtr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete delPtr;

		cout << name << " was removed from the Hash Table" << endl;
	}

	// Case 3 - bucket contains items but first item is not a match
	// Case 3.1 - no match
	// Case 3.2 - match is found
	else {
		P1 = HashTable[index]->next;
		P2 = HashTable[index];

		while (P1 != NULL && P1->name != name) {
			P2 = P1;
			P1 = P1->next;
		}

		// Case 3.1
		if (P1 == NULL) {
			cout << name << " was not found in the Hash Table" << endl;
		}

		// Case 3.2
		else {
			delPtr = P1;
			P1 = P1->next;
			P2->next = P1;

			delete delPtr;
			cout << name << " was removed from the Hash Table" << endl;
		}
	}

}
