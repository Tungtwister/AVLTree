#ifndef _NODE_H_
#define _NODE_H_

using namespace std;

class Node
{
    public:
    string data;
    int count;
    Node* left;
    Node* right;
    Node* parent;
    
    Node();
    Node(string data);
};

#endif
