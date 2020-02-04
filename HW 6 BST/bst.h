#include <iostream>
//creates the object Node to be used in a tree
class Node {
	public:
    int key;			
    Node* left;	
    Node* right;

    Node(int data) 
	{
		key = data; 
		left = NULL; 
		right = NULL; 
	}
};

class BST {
public:
	BST();	//PURPOSE: constructor
	~BST();	//PURPOSE: destructor

	/* insertion */

	// PARAM:	key = The leaf to be inserted   
	void insert(int data);	//PURPOSE: Overloaded function to insert a node or a leaf into the proper location.
	// PARAM:	node = a pointer to the root to find the leaf to be inserted
	// PARAM:	key = The leaf to be inserted  
	Node* insert(Node* node, int data); //PURPOSE: Overloaded function to insert a node or a leaf into the proper location.

	/* search */
	// PARAM:	key = The leaf to be searched
	Node* search(int key);//PURPOSE:Overloaded search function. calls the Overloaded search function to protect the private variables.
	// PARAM:	node = a pointer to the root to find the leaf to be deleated
	// PARAM:	key = The leaf to be deleated
	Node* search(Node* node, int key);// PURPOSE:Overloaded search function. searches the nodes inorder of the root node. returns search result.

	/* delection */

	// PARAM:	key = The leaf to be deleated
	void remove(int key);// PURPOSE: Remove a speicific leaf at the key, calls the other overloaded remove function
	// PARAM:	node = a pointer to the root to find the leaf to be deleated
	// PARAM:	key = The leaf to be deleated
	Node* remove(Node* node, int key);// PURPOSE: Remove a speicific node at the key implemented in the privious remove function.
	// PARAM:	node = a pointer to the root to find left most node
	Node* leftmostNode(Node* node);// PURPOSE: Retreaves the left move node and returns the current.

	/* in-order traversal */
	//PARAM: NONE
	void inorder();// PURPOSE:	//Overloaded inorder function. calls the overloaded function
	//PARAM: node = the node
	void inorder(Node* node);// PURPOSE: Retreaves the left move node and returns the current.
	// PARAM:   node = a pointer to the root to be deleted
	void deleteTree(Node* node);// PURPOSE: Does Post Order traversal of the tree and deletes the root when the node doesn't equal NULL.
private:
	Node* root;
};

