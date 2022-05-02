#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ah[10] = {0};
    int i = 0;
    int th = 0;
    const int CH = 30;
    int sh = 0;
    int n = 0;

    for (i = 0; i < 10; i++)
    {
        cin >> ah[i];
    }
    cin >> th;
    sh = CH + th;

    for (i = 0; i < 10; i++)
    {
        if (ah[i] <= sh)
        {
            n++;
        }
    }

    cout << n << endl;

    return 0;
}