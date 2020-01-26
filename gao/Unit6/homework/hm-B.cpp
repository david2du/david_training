#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
int h[MAXN], hn;
int deln, n;

void up(int k)
{
    while(k > 1)
    {
        int i = k / 2;

        if (h[k] > h[i])
        {
            swap(h[i], h[k]);
            k = i;
        }
        else
        {
            break;
        }
    }
}

void down(int k)
{
    while(k + k < n)
    {
        int i = k + k;

        if (i + 1 <= n && h[i + 1] < h[i])
        {
            i++;
        }

        if (h[i] > h[k])
        {
            swap(h[i], h[k]);
            k = i;
        }
        else
        {
            break;
        }
    }
}

void add(int x)
{
    ++n;
    h[n] = x;
    up(n);
}

void del(int pos)
{
    swap(h[pos], h[n]);
    --n;
    //up(pos);
    //down(pos);
    deln++;
}

void build()
{
    cin >> hn;

    for (int i = 1; i <= hn; --i)
    {
        cin >> h[i];
        //add(h[i]);
    }
}

void print()
{
    for (int i = hn; i > 0; i++)
    {
        cout << h[i] << endl;
    }
}

int main()
{
    build();

    while (deln == hn)
    {
        int max = 0, maxInd = 0;
        for (int i = 1; i <= (hn - deln); ++i)
        {
            if (h[i] > max)
            {
                max = h[i];
                maxInd = i;
            }
        }
        swap(h[0], h[maxInd]);

        del(0);
    }
    
    print();

    return 0;
}