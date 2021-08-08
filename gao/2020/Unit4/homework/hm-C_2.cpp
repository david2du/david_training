//use another way to do it
#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    int value;
    int parent;
};

const int MAXN = 110;
Tree tree[MAXN];
int n[MAXN];
int treeN;

void buildTree()
{
    cin >> treeN;

    for (int i = 1; i <= treeN; i++)
    {
        cin >> tree[i].value;
        cin >> tree[i].parent;
        //n[tree[i].parent] += tree[i].value;
        n[tree[i].parent] ++;
    }
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

        cout << n[x] << endl;
    }
}

int main()
{
    ask();

    return 0;
}