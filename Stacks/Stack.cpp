#include "Stack.h"

Stack::Stack() {
	stackPtr = NULL;
}

Stack::~Stack() {
	item* p1;
	item* p2;

	p1 = stackPtr;
	while (p1 != NULL) {
		p2 = p1;
		p1 = p1->prev;
		p2->prev = NULL;
		delete p2;
	}
}

void Stack::Push(string name, int value) {
	item* n = new item;

	n->name = name;
	n->value = value;
	
	if (stackPtr == NULL) {
		stackPtr = n;
		stackPtr->prev = NULL;
	}
	else {
		n->prev = stackPtr;
		stackPtr = n;
	}
}

void Stack::Pop() {
	if (stackPtr == NULL) {
		cout << "Stack is empty" << endl;
	}
	else {
		/*item* n = new item;
		n = stackPtr;
		cout << n->name << " " << n->value << endl;
		stackPtr = stackPtr->prev;
		n->prev = NULL;
		delete n;*/

		item* p = stackPtr;
		ReadItem(p);
		stackPtr = stackPtr->prev;
		p->prev = NULL;
		delete p;
	}
}

void Stack::ReadItem(item* r) {
	cout << "---------------------" << endl;
	cout << "name: " << r->name << endl;
	cout << "value: " << r->value << endl;
	cout << "---------------------" << endl;
	
	/*stackPtr = r;

	if (stackPtr == NULL) {
		cout << "Item does not exist" << endl;
	}
	else {
		cout << stackPtr->name << " " << stackPtr->value << endl;
	}*/
}

void Stack::Print() {
	item* p = stackPtr;

	while (p != NULL) {
		ReadItem(p);
		p = p->prev;
	}
}
