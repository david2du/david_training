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

inline void updD(ll id)
{
    ll d = 0;
    for (ll i = 0; i < tr[id].chd.size(); ++i)
    {
        d = max(d, tr[tr[id].chd[i]].dep);
    }
    ++d;
    tr[id].dep = d;
}

inline void adjust(ll id)
{
    if (tr[id].dep <= 1)
        return;
    if (tr[id].chd.size() >= k)
        return;
    vector<pair<ll, Node>> v;

    bool flag = false;
    while(tr[id].chd.size() < k && !flag)
    {
        flag = true;
        ll mxi = 0;
        Node mx(0, 0, 0);
        for (ll j = 0; j < tr[id].chd.size(); ++j)
        {
            if (!tr[tr[id].chd[j]].chd.empty())
            {
                flag = false;
                auto t = tr[tr[tr[id].chd[j]].chd.back()];
                if (t > mx)
                {
                    mx = t;
                    mxi = j;
                }
            }
        }
        if (flag)
            break;
        tr[id].chd.push_back(mx.id);

        tr[tr[id].chd[mxi]].chd.pop_back();
        tr[tr[id].chd[mxi]].sum -= mx.sum;

        updD(tr[id].chd[mxi]);
        updD(id);
    }
    // ll piv[13];
    // for (ll i = 0; i < tr[id].chd.size(); ++i)
    //     piv[i] = tr[tr[id].chd[i]].chd.size() - 1;
    // bool flag = false;
    // for (ll i = 0; i < k && !flag; ++i)
    // {
    //     flag = true;
    //     ll mxi = 0;
    //     Node mx(0, 0, 0);
    //     for (ll j = 0; j < tr[id].chd.size(); ++j)
    //     {
    //         if (piv[j] >= 0)
    //         {
    //             flag = false;
    //             auto t = tr[tr[tr[id].chd[i]].chd[piv[j]]];
    //             if (t > mx)
    //             {
    //                 mx = t;
    //                 mxi = j;
    //             }
    //         }
    //     }
    //     --piv[mxi];
    //     tr[id].chd.push_back(tr[tr[id].chd[i]].chd.back());
    //     tr[id].sum += mx.sum;
    //     tr[id].dep = max(tr[id].dep, mx.dep);
    //     v.push_back(make_pair(tr[tr[id].chd[i]].chd[piv[mxi]], mx));
    // }

    for (ll i = 0; i < tr[id].chd.size(); ++i)
        adjust(tr[id].chd[i]);
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
    build();
    //adjust(tr.size() - 1);
    cout << pushD(tr.size() - 1) << endl;
    cout << tr.back().dep << endl;

    return 0;
}