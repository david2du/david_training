#include <bits/stdc++.h>
using namespace std;

set<int> st;

int main(int argc, char const *argv[])
{
    int t = 0;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n = 0;

        cin >> n;

        for (int j = 1; j <= (n + 1); j++)
        {
            st.insert(n / j);
        }

        cout << st.size() << endl;
        st.clear();
    }

    return 0;
}
