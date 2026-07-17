#include <bits/stdc++.h>
using namespace std;

const int N = 20000010;
int z[N];
int lcp[N];

void exkmp(const string &s, const string &p, int *Z, int *L, int S) // calc lcp[]
{
    int r_max = 0;
    int pos = 0;
    for (int i = S; i < s.size(); ++i)
    {
        if (r_max > i)
            L[i] = min(Z[i - pos], r_max - i + 1);
        while ((s[i + L[i]] == p[L[i]]) && (i + L[i] < s.size()))
            L[i]++;
        if (L[i] + i - 1 > r_max)
        {
            r_max = L[i] + i - 1;
            pos = i;
        }
    }
}

void calc(int *arr, int sze)
{
    typedef long long ll;
    ll ans = 0;
    for (int i = 0; i < sze; ++i)
        ans ^= (ll)(i + 1) * (ll)(arr[i] + 1);
    cout << ans << endl;
}

int main()
{
    string a, b;

    cin >> a >> b;
    // cout << a << b << endl;

    z[0] = b.size();
    exkmp(b, b, z, z, 1); // z
    exkmp(a, b, z, lcp, 0); // lcp

    calc(z, b.size());
    calc(lcp, a.size());

    return 0;
}