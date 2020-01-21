#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    int val;
    int parent;
    int leftChild;
    int rightChild;
};

const int N = 110;
Tree tree[N];
int treeN, root;

int value(int x)
{
    int n = x, valu = 0;

    while(n != 0)
    {
        valu += tree[n].val;

        n = tree[n].parent;
    }

    return valu;
}

void buildTree()
{
    cin >> treeN >> root;

    for (int i = 1; i <= treeN; i++)
    {
        cin >> tree[i].val >> tree[i].leftChild >> tree[i].rightChild;

        tree[tree[i].leftChild].parent = i;
        tree[tree[i].rightChild].parent = i;
    }
}

int main()
{
    buildTree();

    for (int i = 1; i <= treeN; i++)
    {
        cout << value(i) << endl;
    }

    return 0;
}