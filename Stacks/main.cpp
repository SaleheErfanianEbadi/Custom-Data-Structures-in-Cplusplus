#include <iostream>

#include "Stack.h"

using namespace std;

int main() {

	Stack Sally;

	Sally.Push("Salehe", 1);
	Sally.Push("Mohammad", 2);
	Sally.Push("Fatemeh", 3);
	Sally.Push("Saeedeh", 4);
	Sally.Push("Amir", 5);

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
	Sally.Push("Facebook", 1);
	Sally.Print();

	cout << endl << endl << "New stack" << endl;
	Sally.Push("Oculus", 1);
	Sally.Print();

	return 0;
}