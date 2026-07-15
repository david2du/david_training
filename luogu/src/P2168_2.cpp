#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 100010;
ll n, k;
ll fre[N];

struct Node
{
    ll id;
    ll sum;
    ll dep;
    vector<ll> chd;

    Node()
    {
        id = 0;
        sum = 0;
        dep = 0;
    }
    Node(const ll &I = 0, const ll &S = 0, const ll &D = 0)
    {
        id = I;
        sum = S;
        dep = D;
    }

    inline bool operator<(const Node &A) const
    {
        if (sum != A.sum)
            return sum < A.sum;
        return dep < A.dep;
    }
    inline bool operator>(const Node &A) const
    {
        if (sum != A.sum)
            return sum > A.sum;
        return dep > A.dep;
    }
};

vector<Node> tr;

inline void build()
{
    priority_queue<Node, vector<Node>, greater<Node>> hp;
    for (ll i = 0; i < n; ++i)
    {
        Node t(i, fre[i], 0);
        tr.push_back(t);
        hp.push(t);
    }

    while (hp.size() > 1)
    {
        Node t(tr.size(), 0, 0);
        for (ll i = 0; i < k && (!hp.empty()); ++i)
        {
            auto tp = hp.top();
            t.sum += tp.sum;
            t.dep = max(t.dep, tp.dep);
            hp.pop();
            t.chd.push_back(tp.id);
        }
        ++t.dep;
        hp.push(t);
        tr.push_back(t);
    }
}

inline ll pushD(ll id)
{
    ll ans = 0;
    
    if (tr[id].dep == 0)
    {
        return 0;
    }

    for (ll i = 0; i < tr[id].chd.size(); ++i)
    {
        ans += (pushD(tr[id].chd[i]) + tr[tr[id].chd[i]].sum);
    }
    return ans;
}

int main()
{
    cin >> n >> k;
    for (ll i = 0; i < n; ++i)
        cin >> fre[i];
    // sort(fre, fre + N);
    int a = (n - 1) % (k - 1);
    a = (-a + k - 1) % (k - 1);
    for (int i = 0; i < a; i++)
        fre[i + n] = 0;
    n += a;
    build();
    cout << pushD(tr.size() - 1) << endl;
    cout << tr.back().dep << endl;

    return 0;
}