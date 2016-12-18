#pragma once

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>

using namespace std;

class Stack {

private:

	struct item {
		string name;
		int value;
		item* prev;
	};

	item* stackPtr;


public:

	Stack();
	~Stack();

	void Push(string name, int value);
	void Pop();
	void ReadItem(item* r);
	void Print();


};

#endif // !STACK_H

