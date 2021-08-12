#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

vector<ll> edge[200010];

ll dis(ll a, ll b, int fa)
{
    if (a == b)
    {
        return 1;
    }

    for (int i = 0; i < edge[a].size(); i++)
    {
        if (edge[a][i] != fa)
        {
            int ans = dis(edge[a][i], b, a);
            if (ans)
            {
                return ans + 1;
            }
        }
    }

    return 0;
}

ll solve(ll a, ll b, ll c)
{
    //cout << dis(a, b, -1) << " " << dis(b, c, -1) << " " << dis(a, c, -1) << endl;
    if ((a - b >= 0 && c - b >= 0) || (a - b <= 0 && c - b <= 0))
    {
        return dis(a, b, -1) + dis(b, c, -1) - dis(a, c, -1);
    }
    return min(dis(a, b, -1), dis(b, c, -1));
}

int main(int argc, char const *argv[])
{
    ll n = 0, q = 0, num = 0;

    freopen("1.in", "r", stdin);
    freopen("hollow.out", "w", stdout);

    cin >> n >> q >> num;

    for (ll i = 0; i < (n - 1); i++)
    {
        ll x = 0, y = 0;

        cin >> x >> y;

        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for (ll i = 0; i < q; i++)
    {
        ll a = 0, b = 0, c = 0;

        cin >> a >> b >> c;
        cout << solve(a, b, c) << endl;
    }

    return 0;
}