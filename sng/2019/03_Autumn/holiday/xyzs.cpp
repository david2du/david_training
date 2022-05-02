#include <bits/stdc++.h>
using namespace std;

int group(int num)
{
    int grp = 0; // log number
    int n = 1, sum = 0;

    if (num <= 1)
    {
        return 1;
    }
    while (sum < num)
    {
        n *= 2;
        sum += n;
        grp++;
    }

    return grp;
}

int rltvnm(int grp, int num) // relative number
{
    int n = 1, sum = 0;

    for (int i = 0; i < (grp - 1); i++)
    {
        n *= 2;
        sum += n;
    }

    return num - sum;
}

void findNum(int x)
{
    int rltv = 0;    // relative
    int dgtlPos = 0; // digital position

    dgtlPos = group(x);
    rltv = rltvnm(dgtlPos, x);

    int l = 1, r = (int)pow(2, dgtlPos); // left, right
    int mid = 0;

    while (l < r)
    {
        mid = l + (r - l) / 2;

        if (rltv <= mid)
        {
            cout << 4;
            r = mid;
        }
        else if (rltv > mid)
        {
            cout << 7;
            l = mid + 1;
        }
        else
        {
            continue;
        }
    }
    

    cout << endl;
}

int main()
{
    int n = 0;

    cin >> n;

    findNum(n);
  

    return 0;
}