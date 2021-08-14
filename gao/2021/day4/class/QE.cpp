#include <iostream>
using namespace std;

int x[50010];

int LB(int x)
{
    return x & (-x);
}

void add(int idx, int addn, int n)
{
    while(idx <= n)
    {
        x[idx] += addn;
        x += LB(x);
    }
}

int sub(int x)
{
    int ans =0 ;

    while(x > 0)
    {
        ans += x[idx];
        x -= LB(x);
    }

    return 0;
}

int query(int l, int r)
{
    return sub(r) - sub(l);
}

int main(int argc, char const *argv[])
{
    int t = 0;

    cin >> t;
    for (int i =0; i < t; i++)
    {
        int n = 0;

        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            int a = 0;

            cin >> a;

            add(i, a, n);
        }

        while(true)
        {
            string s;

            cin >> s;
            if (s == 'Add')
            {
                
            }
        }
    }
    
    return 0;
}