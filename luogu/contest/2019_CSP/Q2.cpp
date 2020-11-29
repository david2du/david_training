#include <bits/stdc++.h>
using namespace std;

int num[200010];

int main()
{
    int n = 0;
    set<int> st;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                st.insert(num[i] % num[j]);
            }
        }
    }

    if (st.size() < 2)
    {
        cout << -1 << endl;
        return 0;
    }

    set<int>::iterator it = st.end();
    it--;
    it--;

    cout << *it << endl;

    return 0;
}