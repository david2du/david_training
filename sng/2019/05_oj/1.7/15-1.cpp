#include <bits/stdc++.h>
using namespace std;
int main()
{
    string name[100];
    int n = 0;
    int i = 0;
    unsigned int j = 0;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> name[i];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < name[i].size(); j++)
        {
            if ((j == 0) && ((name[i][j] >= 'a') && (name[i][j] <= 'z')))
            {
                name[i][j] -= 32;
            }
            if((j > 0) && ((name[i][j] >= 'A') && (name[i][j] <= 'Z')))
            {
                name[i][j] += 32;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        cout << name[i] << endl;
    }

    return 0;
}