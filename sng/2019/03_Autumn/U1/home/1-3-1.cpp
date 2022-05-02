#include <bits/stdc++.h>
using namespace std; 
int main()
{
    string w;
    int cs[128] = {0};
    unsigned int i = 0;
    char c;

    cin >> w;

    for (i = 0; i < w.size(); i++)
    {
        c = w[i];
        cs[c]++;
    }

    for (i = 0; i < 128; i++)
    {
        if (cs[i] > 0)
        {
            cout << (char)i << ":(" << cs[i] << ")" << endl;
        }
    }

    return 0;
} 