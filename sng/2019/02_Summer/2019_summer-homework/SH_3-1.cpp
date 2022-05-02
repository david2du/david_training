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

int main()
{
    unsigned int n = 0, k = 0;
    vector<int> s1;
    vector<int> s2;
    vector<int> ans; 
    unsigned int i = 0, j = 0;
    
    cin >> n >> k;

    s1 = split(n);
    s2 = split(n);

    for (i = 0; i < (s2.size() - 1); i++)
    {
        for (j = 0; j < (s2.size() - 1 - i); j++)
        {
            if (s2[j] < s2[j])
            {
                swap(s2[j], s2[j + 1]);
            }
        }
    }

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < s1.size(); j++)
        {
            if (s2[i] == s1[j])
            {
                ans.push_back(j);
            }
        }
    }

    for (i = 0; i < k; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}