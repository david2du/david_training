#include <bits/stdc++.h>
using namespace std;

set<int> st;

typedef long long ll;

const ll MOD = 998244353LL;
        ll p = 0, k = 0;

bitset<(1 << 21)> vst;

void dfs(int now_num)
{

}

int main(int argc, char const *argv[])
{
    ll t = 0;

    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        cin >> p >> k;

        cout << solve() << endl;
    }

    return 0;
}
