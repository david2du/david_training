#include <bits/stdc++.h>
using namespace std;

const int T = 10000 + 10;

vector<int> sq;
vector<int> v[T];

void solve(int t)
{
    int n = 0;

    cin >> n;

    v[t].push_back(1);
    for (int i = 2; i <= n; ++i)
    {
        v[t].push_back(i);
        int s = v[t].size();
        if (*lower_bound(sq.begin(), sq.end(), v[t][s - 1] + v[t][s - 2]) == (v[t][s - 1] + v[t][s - 2]))
        {
            swap(v[t][0], v[t][s - 1]);
        }
    }
    for (auto i : v[t])
        cout << i << " ";
    cout << endl;
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 2; i <= 2000; ++i)
        sq.push_back(i * i);
    for (int i = 0; i < t; ++i)
    {
        solve(i);
    }

    return 0;
}