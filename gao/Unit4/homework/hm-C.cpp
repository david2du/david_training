//use "Tree" to do it;
#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    int value;
    int parent;
};

const int MAXN = 110;
Tree tree[MAXN];
int treeN;

void buildTree()
{
    cin >> treeN;

    for (int i = 1; i <= treeN; i++)
    {
        cin >> tree[i].value;
        cin >> tree[i].parent;
    }
}

int findChild(int x)
{
    int n = 0;
    int childN = 0;

    for (int i = 1; i <= treeN; i++)
    {
        n = tree[i].parent;
        if (n == x)
        {
            childN++;
        }
    }

    return childN;
}

void ask()
{
    buildTree();

    int k = 0;
    int x = 0;

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> x;

        cout << findChild(x) << endl;
    }
}

int main()
{
    ask();

    return 0;
}