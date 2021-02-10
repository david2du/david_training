#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<string> v;

int cmp(int id1, int id2)
{
    int sz = min(v[id1].size(), v[id2].size());
    int cnt = 0;

    for (int i = 0; i < sz; i++)
    {
        cnt++;
        if (v[id1][i] != v[id2][i])
        {
            break;
        }
    }

    return cnt;
}

int main()
{
    int n = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;

        cin >> s;
        v.push_back(s);
    }

    ll ans = 0;
    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans += cmp(i, j);
        }
    }

    cout << ans << endl;

    return 0;
}