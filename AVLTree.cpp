#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "AVLTree.h"

using namespace std;

//Insert an item to the binary search tree and perform rotation if necessary.
AVLTree :: AVLTree()
{
    root = NULL;
}

void AVLTree :: insert(const string & word)
{
    Node* newt = new Node(word);
    Node* mom = root;
      if(empty())
      {
          root = newt;
      }
      else
      {
          Node *curr = root;
          while(curr != NULL)
          {
              mom = curr;
              if(newt->data > curr->data)
              {
                  curr = curr->right;
              }
              else if(newt->data == curr->data)
              {
                  curr->count = curr->count + 1;
                  return;
              }
              else
              {
                  curr = curr->left;
              }
          }
          if(newt->data < mom->data)
          {
              mom->left = newt;
              newt->parent = mom;
          }
          else
          {
              mom->right = newt;
              newt->parent = mom;
          }
      }
    // Node* curNode = findUnbalancedNode(newt);
    // if(curNode != NULL)
    // {
    // rotate(curNode);
    // }
    balance(root);
}
bool AVLTree :: empty() const
  {
      if(root == NULL)
      {
          return true;
      }
      else
      return false;
  }
//Return the balance factor of a given node.
int AVLTree :: balanceFactor(Node* temp)
{
    // cout << "balance factor start" << endl;
    int leftCount = 0;
    int rightCount = 0;
    // Node* curNode = temp;
    leftCount = height(temp->left);
    rightCount = height(temp->right);
    // while(temp->left)
    // {
    //     leftCount++;
    //     temp = temp->left;
    // }
    
    // while(curNode->right)
    // {
    //     rightCount++;
    //     curNode = curNode->right;
    // }
    
    // cout << "balance factor end" << endl;
    return leftCount - rightCount;
}
int AVLTree::height(Node* curr) const {
    if (curr == 0) {
        return 0;
    }
    if (curr -> left == 0 && curr -> right == 0){
        return 0;
    }
    else {
        int leftDep = height(curr -> left);
        int rightDep = height(curr -> right);
        
        if (leftDep > rightDep) {
            return (leftDep + 1);
        }
        else {
            return (rightDep + 1);
        }
    }
}
//Traverse and print the tree in inorder notation. 
//Print the string followed by its balance factor in parentheses followed by a , and one space.
void AVLTree :: printBalanceFactors()
{
    printBalanceFactors(root);
}
//Generate dotty file and visualize the tree using dotty program. Call this function before and after rotation.
void AVLTree :: visualizeTree(const string & outputFilename)
{
     ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

 //Find and return the closest unbalanced node (with balance factor of 2 or -2) to the inserted node.
// Node* AVLTree::findUnbalancedNode(Node* curNode)
// {
//     if(curNode->parent == NULL)
//     {
//         return 0;
//     }
//     else if(balanceFactor(curNode->parent)== 2 || balanceFactor(curNode->parent)== -2)
//     {
//         return curNode->parent;
//     }
//     else {
//         return findUnbalancedNode(curNode->parent);
//     }
// }
void AVLTree :: balance(Node* root)
{
    Node* newt = NULL;
    newt = rotate(root);
    
    if(newt != root)
    {
        root = newt;
    }
}

//Implement four possible imbalance cases and update the parent of the given node.
Node* AVLTree :: rotate(Node* curNode)
{
    
    Node* temp = NULL;
    //balance children
    if(curNode->left)
    {
        curNode->left = rotate(curNode->left);    
    }
    if(curNode->right)
    {
        curNode->right = rotate(curNode->right);
    }
    int bf = balanceFactor(curNode);
    
    if(bf >= 2)
    {
      if(balanceFactor(curNode->left) <= -1)
      {
          temp = rotateLeftRight(curNode);
      }
      else
      {
          temp = rotateLeftLeft(curNode);
      }
    }
    else if(bf <= -2)
    {
        if(balanceFactor(curNode->right) >= 1)
        {
            temp = rotateRightLeft(curNode);
        }
        else
        {
            temp = rotateRightRight(curNode);
        }
    }
    else
    {
        temp = curNode;
    }
    return temp;
}
Node* AVLTree :: rotateLeftLeft(Node* temp)
{
    Node* a = temp;
    Node* b = a->left;
    
    a->left = b->right;
    b->right = a;
    
    return b;
}
Node* AVLTree :: rotateLeftRight(Node* temp)
{
    Node* a = temp;
    Node* b = a->left;
    Node* c = b->right;
    
    a->left = c->right;
    b->right = c->left;
    c->left = b;
    c->right = a;
    
    return c;
}
Node* AVLTree :: rotateRightLeft(Node* temp)
{
    Node* a = temp;
    Node* b = a->right;
    Node* c = b->left;
    
    a->right = c->left;
    b->left = c->right;
    c->right = b;
    c->left = a;
    
    return c;
}
Node* AVLTree :: rotateRightRight(Node* temp)
{
    Node* a = temp;
    Node* b = a->right;
    
    a->right = b->left;
    b->left = a;
    
    return b;
}

void AVLTree :: printBalanceFactors(Node * temp)
{
    if(temp)
    {
        printBalanceFactors(temp->left);
        cout<<temp->data<<"("<<balanceFactor(temp)<<")"<<", ";
        printBalanceFactors(temp->right);
    }
    else
    {
        return;
    }
}
void AVLTree :: visualizeTree(ofstream & outFS, Node * n)
{
    if(n){
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS<<n->data <<" -> " <<n->left->data<<";"<<endl;    
        }

        if(n->right){
            visualizeTree(outFS,n->right);
            outFS<<n->data <<" -> " <<n->right->data<<";"<<endl;    
        }
    }
}