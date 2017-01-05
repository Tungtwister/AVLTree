#include <iostream>
#include "Node.h"
using namespace std;

Node :: Node()
{
    left = NULL;
    right = NULL;
    parent = NULL;
    count = 0;
}

Node :: Node(string data)
{
    this->data = data;
    left = NULL;
    right = NULL;
    parent = NULL;
    count = 1;
}