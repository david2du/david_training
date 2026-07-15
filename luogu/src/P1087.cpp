#include <bits/stdc++.h>
using namespace std;

string s;

int divi(int l, int r)
{
    if (r - l <= 1)
    {
        cout << ((s[l] != '0') ? 'I' : 'B');
        return s[l] != '0';
    }

    int a = divi(l, (l + r) / 2);
    int b = divi((l + r) / 2, r);
    if (((a | b) & 2) || (a ^ b))
    {
        cout << 'F';
        return 2;
    }
    cout << (((a & b) != 0) ? 'I' : 'B');
    return (a & b) != 0;
}

int main()
{
    int n = 0;
    cin >> n >> s;
    divi(0, s.size());

    return 0;
}