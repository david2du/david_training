#include <bits/stdc++.h>
using namespace std;

vector<int> m;
list<int> lst;

int main(int argc, char const *argv[])
{
    int n = 0, k = 0;

    while (cin >> n >> k)
    {
        for (int i = 0; i < k; i++)
        {
            int a = 0;

            cin >> a;

            m.push_back(a);
        }

        for (int i = 0; i < n; i++)
        {
            lst.push_back(i);
        }

        auto it = lst.begin();
        int nown = 0;
        int rnd = 0;
        while (lst.size() > 1)
        {
            if (it == lst.end())
            {
                it = lst.begin();
            }

            if (nown == m[rnd] - 1)
            {
                it = lst.erase(it);
                rnd++;

                if (rnd >= k)
                {
                    rnd = 0;
                }
                nown = 0;
            }
            else
            {
                it++;
                nown++;
            }
        }

        cout << *(lst.begin()) << endl;

        lst.clear();
        m.clear();
    }

    return 0;
}
