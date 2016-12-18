#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};

void SearchRecursive(node* Ptr, int searchValue);

int main() {

	node* n = new node;
	node* head = n;
	node* t = n;

	n->data = 1;
	//n->next->data = 2;
	
	for (int i = 2; i < 10; i++) {
		n = new node;
		n->data = i;
		t->next = n;
		t = n;
	}
	n->next = NULL;
	t = head;

	while (t != NULL) {
		cout << t->data << " ";
		t = t->next;
	}

	cout << endl;
	SearchRecursive(head, 4);

	return 0;
}

void SearchRecursive(node* Ptr, int searchValue) {
	if (Ptr == NULL) {
		cout << searchValue << " was not found in the list" << endl;
	}
	else if (Ptr->data == searchValue) {
		cout << searchValue << " is in the list" << endl;
	}
	else {
		SearchRecursive(Ptr->next, searchValue);
	}
}
