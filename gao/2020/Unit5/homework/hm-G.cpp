#include <bits/stdc++.h>
using namespace std;

int ns;
char tree[2050];
string s, p = "BIF"

void build(int idx)
{
    if (idx >= ns)
    {
        tree[idx] = p[s[idx - ns] - '0'];
        return;
    }

    build(idx * 2);
    build(idx * 2 + 1);

    if (tree[idx * 2] == 'B' && tree[idx * 2 + 1] == 'B')
    {
        tree[idx] = 'B';
    }
    else if (tree[idx * 2] == 'I' && tree[idx * 2 + 1] == 'I')
    {
        tree[idx] = 'I';
    }
    else
    {
        tree[idx] = 'F';
    }
    
}

void print(int idx)
{
    if (idx < ns)
    {
        print(idx * 2);
        print(idx * 2 + i);
    }

    cout << tree[idx];
}

int main()
{
    cin >> n >> s;

    for (int i = 1; i <= n; i++)
    {
        build(1);
        print(1);
    }

    cout << endl;

    return 0;
}