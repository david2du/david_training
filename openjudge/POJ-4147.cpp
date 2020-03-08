#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void hanoi(vector<int> va, char left, char mid, char right)
{

    vector<int> vb, vc;

    if (va.size() == 1)
    {
        printf("NO.%d %d:%c->%c\n", ++cnt, va[0], left, right);

        return;
    }

    for (int i = 1; i < va.size(); i++)
    {
        vb.push_back(va[i]);
    }

    vc.push_back(va[0]);

    hanoi(vb, left, right, mid);
    hanoi(vc, left, mid, right);
    hanoi(vb, mid, left, right);
}

int main()
{
    int n = 0;
    char left = 0, mid = 0, right = 0;

    cin >> n >> left >> mid >> right;

    vector<int> v;

    for (int i = n; i > 0; i--)
    {
        v.push_back(i);
    }

    hanoi(v, left, mid, right);

    return 0;
}