#include <bits/stdc++.h>
using namespace std;

const int T = 10000 + 10;

vector<int> sq;
vector<int> v[T];

bool check(int n, const vector<int> &ve)
{
    for (int i = 1; i < n; ++i)
    {
        if (*lower_bound(sq.begin(), sq.end(), ve[i - 1] + ve[i]) == (ve[i - 1] + ve[i]))
            return false;
    }
    return true;
}
void solve(int t, int x)
{
    int n = 0;

    n = x;

    v[t].push_back(1);
    for (int i = 2; i <= n; ++i)
    {
        v[t].push_back(i);
        int s = v[t].size();
        // cout << "&" << *lower_bound(sq.begin(), sq.end(), v[t][s - 1] + v[t][s - 2]) << " " << v[t][s - 1] + v[t][s - 2];
        if (*lower_bound(sq.begin(), sq.end(), v[t][s - 1] + v[t][s - 2]) == (v[t][s - 1] + v[t][s - 2]))
        {
            swap(v[t][s - 3], v[t][s - 2]);
        }
    }
    // cout << endl;
    if (!check(n, v[t]))
    {
        cout << "Err" << n << endl;

        exit(0);
    }
    else if (n % 100 == 0)
        cout << "A" << n << endl;
    // for (auto i : v[t])
    //     cout << i << " ";
    // cout << endl;
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 2; i <= 2000; ++i)
        sq.push_back(i * i);
    for (int i = 0; i < t; ++i)
    {
        solve(0, i + 20000);
        v[0].clear();
        // solve(i);
    }

    return 0;
}