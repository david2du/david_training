#include <bits/stdc++.h>
using namespace std;

float sc[100] = {0.0};
string sn[100];

int main()
{
    int i = 0, j = 0;
    int n = 0, k = 0;

    cin >> n >> k;

    for (i = 0; i < n; i++)
    {
        cin >> sn[i] >> sc[i];
    }
    
    for (i = 0; i <= n -2; i++)
    {
        for (j = 0; j <= n - i - 2; j++)
        {
            if (sc[j + 1] < sc[j])
            {
                swap(sc[j], sc[j + 1]);
                swap(sn[j], sn[j + 1]);
            }
        }
    }

    cout << sn[k - 1];
    cout << " " << sc[k - 1] << endl;
    //printf(" %g", sc[k - 1]);

    return 0; 
}