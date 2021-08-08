#include <bits/stdc++.h>
using namespace std;

struct Rule
{
    int a;
    int b;
};

Rule rule[60];

map<string, int> mp;

int main()
{
    string N;

    int k = 0;

    cin >> N >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> rule[i].a >> rule[i].b;
    }

    return 0;
}