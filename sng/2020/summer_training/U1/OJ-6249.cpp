#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<string> st;

    string s;
    while (cin >> s)
    {
        st.insert(s);
    }
    //sort(st.begin(), st.end());

    for (set<string> :: iterator it = st.begin(); it != st.end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}