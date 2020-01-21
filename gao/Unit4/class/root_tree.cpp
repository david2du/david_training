#include <bits/stdc++.h>
using namespace std;

struct Node_1 //parent
{
    int value;
    int parent;
};//single way to find (child & silbing -> parent)

struct Node_2 //child & sibling
{
    int value;
    int left;//child
    int right;//sibling
};//single way to find (parent -> child & silbing)

struct Node_3 //child & parent 
{
    int value;
    vector<int> child;
    int parent;
};//double ways to find (parent -> child & silbing / child & silbing -> parent)

Node_1 node[n];
Node_2 node2[n];
Node_3 node3[n];

void preorder(int id)
{
    if (id > 0)
    {
        visit(id);

        for each child of node[id] (from left to right)
        {
            preorder(child);
        }
    }
}

int main()
{    
    return 0;
}