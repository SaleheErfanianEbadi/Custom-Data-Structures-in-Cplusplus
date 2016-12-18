#pragma once

#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

class BST {

    private:

    struct node {
        int key;
        node* left;
        node* right;
    };

    node* root;

	node* CreateLeaf(int key);
	void  AddLeafPrivate(int key, node* Ptr);
	void  PrintInOrderPrivate(node* Ptr);
	node* ReturnNode(int key);
	node* ReturnNodePrivate(int key, node* Ptr);
	int   FindSmallestPrivate(node* Ptr);
	void  RemoveNodePrivate(int key, node* Ptr);
	void  RemoveRootMatch();
	void  RemoveMatch(node* parent, node* match, bool left);
	void  RemoveSubTree(node* Ptr);

    public:

    BST();
	~BST();
	
	void  AddLeaf(int key);
	void  PrintInOrder();
	int   ReturnRootKey();
	void  PrintChildren(int key);
	int   FindSmallest();
	void  RemoveNode(int key);

};

#endif // !BST_H
