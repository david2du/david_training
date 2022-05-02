#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b)
{
    return a > b;
}

int main()
{
    vector<string> a;
    vector<string> b;
    int n = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        string h;

        cin >> s >> h;

        if (s == "male")
        {
            a.push_back(h);
        }
        else
        {
            b.push_back(h);
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), cmp);

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}