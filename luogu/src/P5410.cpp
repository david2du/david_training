#include <bits/stdc++.h>
using namespace std;

const int N = 20000010;
int z[N];
int lcp[N];

void init(const string &p) // calc z[]
{
    int r_max = 0;
    int pos = 0;
    z[0] = p.size();
    for (int i = 1; i < p.size(); ++i)
    {
        if (r_max > i)
            z[i] = min(z[i - pos], r_max - i + 1);
        while ((p[i + z[i]] == p[z[i]]) && (i + z[i] < p.size()))
            z[i]++;
        if (z[i] + i - 1 > r_max)
        {
            r_max = z[i] + i - 1;
            pos = i;
        }
    }
}

void exkmp(const string &s, const string &p) // calc lcp[]
{
    int r_max = 0;
    int pos = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (r_max > i)
            lcp[i] = min(z[i - pos], r_max - i + 1);
        while ((s[i + lcp[i]] == p[lcp[i]]) && (i + lcp[i] < s.size()))
            lcp[i]++;
        if (lcp[i] + i - 1 > r_max)
        {
            r_max = lcp[i] + i - 1;
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

    init(b);
    exkmp(a, b);

    calc(z, b.size());
    calc(lcp, a.size());

    return 0;
}