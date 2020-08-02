#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int MAXN = 23;
    bool picture[MAXN][MAXN] = {0};

    srand(time(0));

    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0;j < MAXN; j++)
        {
            picture[i][j] = rand() % 2;
        }
    }

    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0;j < MAXN; j++)
        {
            if (picture[i][j] == true)
            {
                cout << " # ";
            }
            else
            {
                cout << "   ";
            }
        }
        cout << endl;
    }

    getchar();

    return 0;
}