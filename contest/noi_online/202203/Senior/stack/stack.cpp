#include <bits/stdc++.h>
using namespace std;

const int N = 500010;

int a[N], b[N];
int l[N], r[N];

set<int> grp;
map<int, int> mp[N];

int main(int argc, char const *argv[])
{
    int n = 0, q = 0;

    freopen("stack.in", "r", stdin);
    freopen("stack.out", "w", stdout);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < q; i++)
    {
        cin >> l[i] >> r[i];

        mp[l[i]][r[i]] = 0;
        grp.insert(l[i]);
    }

    stack<int> stk;

    for (auto si = grp.begin(); si != grp.end(); si++)
    {
        int now = (*si);

        stack<pair<int, int>> stk;
        int lastr = now - 1, cnt = 0;
        for (auto it = mp[now].begin(); it != mp[now].end(); it++)
        {
            for (int i = lastr + 1; i <= (it->first); i++)
            {
                while (!stk.empty() && !(stk.top().first != a[i] && stk.top().second > b[i]))
                {
                    stk.pop();
                }
                if (stk.empty())
                {
                    cnt++;
                }
                stk.push(make_pair(a[i], b[i]));
            }

            mp[now][it->first] = cnt;
            lastr = it->first;
        }
    }

    for (int i = 0; i < q; i++)
    {

        cout << mp[l[i]][r[i]] << endl;
    }

    return 0;
}
