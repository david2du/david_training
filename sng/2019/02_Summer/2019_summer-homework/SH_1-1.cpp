#include <bits/stdc++.h>
using namespace std;
vector<int> split(int n)
{
    vector<int> sn;
    int i = 0;

    while(n != 0)
    {
        i = n % 10;
        sn.push_back(i);
        n = (n - i) / 10;
    }

    return sn; 
}

bool judge(int n)
{
    vector<int> sn;
    bool j = false;
    unsigned int i = 0;

    sn = split(n);
    for (i = 0; i < sn.size(); i++)
    {
        if (sn[i] == 0)
        {
            j = true;
            break;
        }
    }

    return j;
}

int main()
{
    int n = 0;
    int i = 0;
    int ans = 0;

    cin >> n;

    for (i = 1; i < (n + 1); i++)
    {
        if (judge(i) == true)
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}