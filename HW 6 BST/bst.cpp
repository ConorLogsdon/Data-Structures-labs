#include <iostream>
#include "bst.h"

using namespace std;

BST::BST()		//PURPOSE: constructor
{
	root  = NULL;
}

BST::~BST() 	//PURPOSE: destructor
{

	deleteTree(root);	//calls a traversal delestion function.
	root  = NULL;
}
// PARAM:	key = The leaf to be inserted        
void BST::insert(int data) //PURPOSE: Overloaded function to insert a node or a leaf into the proper location.
{
	root = insert(root, data);	//returns the overloaded insert function to be set as the root.

}  
// PARAM:	node = a pointer to the root to find the leaf to be inserted
// PARAM:	key = The leaf to be inserted
Node* BST::insert(Node* node, int data) //PURPOSE: Overloaded function to insert a node or a leaf into the proper location.
{
	if (node == NULL)
		node = new Node(data);
	else if (node->key > data)
	{
		node->left = insert(node->left, data);
	}
	else if (data > node->key)
	{
		node->right = insert(node->right, data); 
	} 
	
	return node;	//retursn inserted node
}
// PARAM:	key = The leaf to be searched
Node* BST::search(int key) //PURPOSE:Overloaded search function. calls the Overloaded search function to protect the private variables.
{
	return search(root, key);	//returns the searched result from the overlaoded function search.
}
// PARAM:	node = a pointer to the root to find the leaf to be deleated
// PARAM:	key = The leaf to be deleated
Node* BST::search(Node* node, int key) // PURPOSE:Overloaded search function. searches the nodes inorder of the root node. returns search result
{
		if (node == NULL || node->key == key) 
			return node;
		if (node->key < key)      
			return search(node->right, key);   
		return search(node->left, key);	//returns the search node if it excists
}
//PARAM: NONE
void BST::inorder() // PURPOSE:	//Overloaded inorder function. calls the overloaded function
{
	inorder(root);	//calls the Overloaded program giving the root of the tree.
}
//PARAM: node = the node
void BST::inorder(Node* node) // PURPOSE:Overloaded inorder function. prints the nodes inorder of the root node
{
	if (node != NULL)	//if the node doesn't equal NULL or not empty
	{
		inorder(node->left);
		cout << node->key << " ";
		inorder(node->right);
	}
}
// PARAM:	key = The leaf to be deleated		
void BST::remove(int key)	// PURPOSE: Remove a speicific leaf at the key, calls the other overloaded remove function
{
	root = remove(root, key);
}
// PARAM:	node = a pointer to the root to find the leaf to be deleated
// PARAM:	key = The leaf to be deleated
Node* BST::remove(Node* node, int key)	// PURPOSE: Remove a speicific node at the key implemented in the privious remove function.
{
	if (node == NULL)
		return node;	//returns NULL if there is no node
	if (node->key > key)	//fixes the placement and deletes the left if it is smaller
		node->left = remove(node->left, key);
	else if (key > node->key)
		node->right = remove(node->right, key);
	else if (node->left == NULL)	//fixes the placement of tree
	{
		Node *temp = node->right;
		delete node;
		return temp;
	}
	else if (node->right == NULL)	//fixes the placement of tree
	{
		Node *temp = node->left;
		delete node;
		return temp;
	}
	else
	{
		Node* temp = leftmostNode(node->left);
		node->key = temp->key;
		node->left = remove(node->left, temp->key);
	}
	return node;	//returns the deleted node.
}
// PARAM:	node = a pointer to the root to find left most node
Node* BST::leftmostNode(Node* node)		// PURPOSE: Retreaves the left move node and returns the current.
{
	Node* current = node; //declairs current
	/* loop down to find the leftmost leaf */    
	while (current->right != NULL)     //while current doesn't point to the right node that is not NULL 
		current = current->right; 
	return current;	//left most node
}


// PARAM:   node = a pointer to the root to be deleted
void BST::deleteTree(Node* node)	// PURPOSE: Does Post Order traversal of the tree and deletes the root when the node doesn't equal NULL.
{
	if (node != NULL)	// if not null continue
	{
		deleteTree(node->left);	//
		deleteTree(node->right);
		delete node;
	}
}