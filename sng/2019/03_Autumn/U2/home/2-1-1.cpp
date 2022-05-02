#include <bits/stdc++.h>
using namespace std;
int main()
{
    string w;
    unsigned int i = 0;
    int asc[128] = {0};
    bool f = false;

    getline(cin, w);

    for (i = 0; i < w.size(); i++)
    {
        asc[w[i]]++;
    }

    for (i = 0; i < w.size(); i++)
    {
        if (asc[w[i]] == 1)
        {
            cout << w[i] << endl;
            f = true;
            break;
        }
    }

    if (f == false)
    {
        cout << "no" << endl;
    }

    return 0;
}