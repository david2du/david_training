#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

const ll MAX = 100010;
const ll MOD = 100000007;

ll num[MAX];  // Number
ll sct[MAX];  // Section
ll sctv[MAX]; // Section Value

ll n;
ll L; // Length

void init()
{
    L = (ll)sqrt(n);

    for (int i = 1; i <= n; i++)
    {
        sct[i] = (i - 1) / L + 1;
    }
}

void update(ll x, ll y, ll z)
{
    if (sct[x] == sct[y])
    {
        for (int i = x; i <= y; i++)
        {
            num[i] += z;
        }
    }

    else
    {
        for (int i = x; sct[i] == sct[x]; i++)
        {
            num[i] += z;
        }
        for (int i = y; sct[i] == sct[y]; i--)
        {
            num[i] += z;
        }
        for (int i = sct[x] + 1; i < sct[y]; i++)
        {
            sctv[i] += z;
        }
    }
}

ll opr(ll x)
{
    return (num[x] + sctv[sct[x]]);
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }

    init();
    for (int i = 1; i <= n; i++)
    {
        int t = 0, l = 0, r = 0, c = 0;

        cin >> t >> l >> r >> c;

        if (t == 1)
        {
            update(l, r, c);
        }
        else
        {
            cout << opr(r) << endl;
        }
    }

    return 0;
}