#include <iostream>
#include <vector>
#include <set>
using namespace std;

int a[100010];
set<int> p;

int main(int argc, char const *argv[])
{
    int n = 0;

    // freopen("typeface.in", "r", stdin);
    // freopen("typeface.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int pin = 1;
    p.insert(1);

    while (pin < n - 1)
    {
        if (a[pin] < a[pin + 1])
        {
            int maxn = 0;
            int mi = 0;

            for (int i = pin + 1; i <= n && a[i] >= a[pin]; i++)
            {
                if (a[i] > maxn)
                {
                    maxn = a[i];
                    mi = i;
                }
            }
            if (maxn == 0)
            {
                break;
            }
            pin = mi;
            p.insert(pin);
        }
        else
        {
            int minn = INT_MAX;
            int mi = 0;

            for (int i = pin + 1; i <= n && a[i] <= a[pin]; i++)
            {
                if (a[i] < minn)
                {
                    minn = a[i];
                    mi = i;
                }
            }
            if (minn == INT_MAX)
            {
                break;
            }

            pin = mi;
            p.insert(pin);
        }
    }
    p.insert(n);

    cout << p.size() << endl;
    set<int>::iterator it;
    for (it = p.begin(); it != p.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}