#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Date
{
    ll day;
    ll month;
    ll year;
    bool BC;

    Date()
    {
        day = 0;
        month = 0;
        year = 0;
        BC = false;
    }

    Date(int _d, int _m, int _y, int )
    {
        day = _d;
        month = _m;
        year = _y;
        BC = (year < 0);
    }

    void print()
    {
        printf("%d %d %d", day, month, year);
        if (BC)
        {
            printf(" BC");
        }
        printf("\n");
    }
};

const ll JU_F = 365 * 4 + 1;
const ll JU_END = 2302307;

ll y2days(int year)
{

}

Date opr(int jul)
{
    int l = -4712, r = 1582;
    int mid = 0;

    while (l <= r)
    {
        mid = l + (r - l) / 2;

        if ()
    }
}

int main(int argc, char const *argv[])
{
    ll q = 0;

    cin >> q;
    for (ll i = 0; i < q; i++)
    {
        ll r = 0;

        cin >> r;

        opr(r).print();
    }
    
    return 0;
}