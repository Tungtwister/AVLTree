#ifndef _AVLTREE_H
#define _AVLTREE_H

#include "Node.h"

class AVLTree
{
public :

AVLTree();
//Insert an item to the binary search tree and perform rotation if necessary.
void insert(const string &); 
//Return the balance factor of a given node.
int balanceFactor(Node*);
//Traverse and print the tree in inorder notation. 
//Print the string followed by its balance factor in parentheses followed by a , and one space.
void printBalanceFactors(); 
//Generate dotty file and visualize the tree using dotty program. Call this function before and after rotation.
void visualizeTree(const string &); 

private: 

Node* root;
 //Find and return the closest unbalanced node (with balance factor of 2 or -2) to the inserted node.
// Node* findUnbalancedNode(Node*);
//Implement four possible imbalance cases and update the parent of the given node.
Node* rotate(Node *);
//Rotate the subtree to left at the given node and returns the new subroot.
// Node* rotateLeft(Node*);
// //Rotate the subtree to right at the given node and returns the new subroot.
// Node* rotateRight(Node*);
void printBalanceFactors(Node *);
void visualizeTree(ofstream &, Node *);
bool empty() const;
int height(Node* curr) const;


Node* rotateLeftLeft(Node*);
Node* rotateLeftRight(Node*);
Node* rotateRightLeft(Node*);
Node* rotateRightRight(Node*);

void balance(Node*);
};

#endif