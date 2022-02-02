#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Coor
{
    ll r;
    ll c;
};

int grass[512][512];

vector<Coor> hundred, lss1, lss2;

bool cmp1(const Coor &A, const Coor &B)
{
    return ((A.r == B.r) ? (A.c < B.c) : (A.r < B.r));
}

bool cmp2(const Coor &A, const Coor &B)
{
    return ((A.c == B.c) ? (A.r < B.r) : (A.c < B.c));
}

ll solve(int n, Coor hdd)
{
    Coor top = lower_bound(lss1.begin(), lss1.end(), hdd, cmp1);
    Coor dwn = upper_bound(lss1.begin(), lss1.end(), hdd, cmp1);
    Coor lft = lower_bound(lss2.begin(), lss2.end(), hdd, cmp2);
    Coor rgt = lower_bound(lss2.begin(), lss2.end(), hdd, cmp2);

    ll ans = 0;

    for (int i = 0; i < )

    return 
}

int main()
{
    int n = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; i++)
        {
            cin >> grass[i][j];

            if (grass[i][j] == 100)
            {
                hundred.push_back((Coor){i, j});
            }
            else if (grass[i][j] < 100)
            {
                lss1.push_back((Coor){i, j});
                lss2.push_back((Coor){i, j});
            }
            else
            {
                continue;
            }
        }
    }

    sort(lss1.begin(), lss1.end(), cmp1);
    sort(lss2.begin(), lss2.end(), cmp2);

    ll ans = 0;

    for (int i = 0; i < hundred.size(); i++)
    {
    }

    return 0;
}