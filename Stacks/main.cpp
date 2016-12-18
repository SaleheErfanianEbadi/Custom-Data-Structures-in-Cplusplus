#include <iostream>

#include "Stack.h"

using namespace std;

int main() {

	Stack Sally;

	Sally.Push("Justin", 1);
	Sally.Push("Dorothy", 2);
	Sally.Push("Rob", 3);
	Sally.Push("Hank", 4);
	Sally.Push("Susan", 5);

	Sally.Print();

	cout << "Popping" << endl;
	Sally.Pop();

	cout << "Popping" << endl;
	Sally.Pop();

	cout << "Popping" << endl;
	Sally.Pop();

	cout << "Popping" << endl;
	Sally.Pop();

	cout << "Popping" << endl;
	Sally.Pop();

	cout << "Popping" << endl;
	Sally.Pop();

	cout << endl << endl << "New stack" << endl;
	Sally.Push("RIchard", 1);
	Sally.Print();

	cout << endl << endl << "New stack" << endl;
	Sally.Push("Geremy", 1);
	Sally.Print();

	return 0;
}
