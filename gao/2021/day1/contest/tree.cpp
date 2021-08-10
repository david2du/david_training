#include <bits/stdc++.h>

int d[160];
vector<int> leaf;

int main(int argc, char const *argv[])
{
    int n = 0;
    int root = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        if (d[i] == 1)
        {
            leaf.push_back(i);
        }
    }

    root = leaf[0];

    return 0;
}