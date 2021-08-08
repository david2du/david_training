#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    int parent;
    int leftChild;
    int rightChild;
};

const int N = 110;
Tree tree[N];
int treeN, root;

int depth(int x)
{
    int n = x, dep = 0;

    while(n != 0)
    {
        dep++;

        n = tree[n].parent;
    }

    return dep;
}

void buildTree()
{
    cin >> treeN >> root;

    for (int i = 1; i <= treeN; i++)
    {
        cin >> tree[i].leftChild >> tree[i].rightChild;

        tree[tree[i].leftChild].parent = i;
        tree[tree[i].rightChild].parent = i;
    }
}

int main()
{
    buildTree();

    for (int i = 1; i <= treeN; i++)
    {
        cout << depth(i) << endl;
    }

    return 0;
}