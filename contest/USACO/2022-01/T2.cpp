#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1000010;
// const ll N = 10;

ll h[N];
ll id[N];

set<ll> st;

int main(int argc, char const *argv[])
{
    ll n = 0;

    cin >> n;

    for (ll i = 0; i < n; i++)
    {
        cin >> h[i];
        id[h[i]] = i;
    }

    ll ans = 0;

    st.insert(id[n]);
    for (ll i = (n - 1); i >= 1; i--)
    {
        auto a = st.lower_bound(id[i]);
        auto b = a;

        if (a != st.begin())
        {
            a--;
            ans += (id[i] - (*a) + 1);
        }
        if (b != st.end())
        {
            ans += ((*b) - id[i] + 1);
        }

        st.insert(id[i]);
    }

    cout << ans << endl;

    return 0;
}
