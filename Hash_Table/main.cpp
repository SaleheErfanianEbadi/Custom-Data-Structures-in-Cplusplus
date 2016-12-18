#include <iostream>
#include <string>

#include "Hash.h"

using namespace std;

int main() {

	myhash Hashy;
	string name = "";
	
	//Hashy.PrintTable();

	Hashy.AddItem("Paul", "Locha");
	Hashy.AddItem("Kim", "Iced Mocha");
	Hashy.AddItem("Emma", "Strawberry Smoothy");
	Hashy.AddItem("Annie", "Hot Chocolate");
	Hashy.AddItem("Sarah", "Passion Tea");
	Hashy.AddItem("Pepper", "Caramel Mocha");
	Hashy.AddItem("Mike", "Chai Tea");
	Hashy.AddItem("Steve", "Apple Cider");
	Hashy.AddItem("Bill", "Root Beer");
	Hashy.AddItem("Marie", "Skinny Latte");
	Hashy.AddItem("Susan", "Water");
	Hashy.AddItem("Joe", "Green Tea");

	Hashy.PrintItemsInIndex(0);

	Hashy.PrintTable();

	while (name != "exit") {
		cout << "Search for ";
		cin >> name;
		if (name != "exit") {
			Hashy.FindDrink(name);
		}
	}

	Hashy.RemoveItem("Bill");

	return 0;
}