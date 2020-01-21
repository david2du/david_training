#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    int leftChild;
    int rightChild;
};

const int N = 110;
Tree tree[N];
int treeN, root;

void visit(int fa)
{
    cout << fa << " ";
}

void preorder(int fa)
{
    if (fa > 0)
    {
        visit(fa);
        preorder(tree[fa].leftChild);
        preorder(tree[fa].rightChild);
    }
}

void inorder(int fa)
{
    if (fa > 0)
    {
        inorder(tree[fa].leftChild);
        visit(fa);
        inorder(tree[fa].rightChild);
    }
}

void postorder(int fa)
{
    if (fa > 0)
    {
        postorder(tree[fa].leftChild);
        postorder(tree[fa].rightChild);
        visit(fa);
    }
}

void buildTree()
{
    cin >> treeN >> root;

    for (int i = 1; i <= treeN; i++)
    {
        cin >> tree[i].leftChild >> tree[i].rightChild;
    }
}

void order()
{
    preorder(root);
    cout << endl;

    inorder(root);
    cout << endl;

    postorder(root);
    cout << endl;
}

int main()
{
    buildTree();
    order();

    return 0;
}