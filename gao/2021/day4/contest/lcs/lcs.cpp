#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

int a[300010];
map<int, int> mp;
int x[300010];
int f[300010];

int main(int argc, char const *argv[])
{
    ll n = 0, m = 0;

    //freopen("mex.in", "r", stdin);
    //freopen("mex.out", "w", stdout);

    int cnt1 = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]] = cnt1++;
    }

    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int b = 0;

        cin>> b;

        map<int, int>::iterator it = mp.find(b);
        if (it != mp.end())
        {
            x[cnt++] = (*it).second;
        }
    }

    for (int i = 0; i < cnt; ++i)
    {
        f[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (x[i] > x[j])
            {
                f[i] = max(f[j] + 1, f[i]);
            }
        }
    }

    cout << *max_element(f, f + n + 1) << endl;

    return 0;
}