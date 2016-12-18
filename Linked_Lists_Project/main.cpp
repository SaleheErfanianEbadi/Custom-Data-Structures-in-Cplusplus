#include <iostream>	

#include "list.h"

using namespace std;

int main() {

	List Sally;

	Sally.AddNode(1);
	Sally.AddNode(2);
	Sally.AddNode(3);

	for (int i = 4; i < 20; i++) {
		Sally.AddNode(i);
	}

	Sally.PrintList();

	for (int i = 1; i < 20; i++) {
		if (i % 2 == 0) {
			Sally.DeleteNode(i);
		}
	}

	Sally.PrintList();

	return 0;
}