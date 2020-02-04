#include <iostream>
#include "bst.h"
//#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
   BST bst;
   bst.insert(50);
   bst.insert(30);
   bst.insert(20);
   bst.insert(40);
   bst.insert(70);
   bst.insert(60);
   bst.insert(80);
   
   bst.inorder();
   cout << "" << endl;
   cout << (bst.search(50) == NULL ? "Element not found." : "Element found.") << endl;
   bst.remove(40);
   bst.remove(50);
   bst.inorder();
   cout << "" << endl;
   cout << (bst.search(50) == NULL ? "Element not found." : "Element found.") << endl;
   return 0;
}
