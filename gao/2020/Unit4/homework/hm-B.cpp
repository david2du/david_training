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

int findParent(int x, int y)
{
    int n = 0;
    int ret = -1;

    n = x;
    while(ret == -1)
    {
        if (tree[n].parent == y)
        {
            ret = y;
            return ret;
        }

        n = tree[n].parent;

        if (n == 0)
        {
            break;
        }
    }

    n = y;
    while(ret == -1)
    {
        if (tree[n].parent == x)
        {
            ret = x;
            return ret;
        }

        n = tree[n].parent;

        if (n == 0)
        {
            break;
        }
    }

    return ret;
}

void ask()
{
    buildTree();

    int k = 0;
    int x = 0, y = 0;

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;

        cout << findParent(x, y) << endl;
    }
}

int main()
{
    ask();

    return 0;
}
