#include <bits/stdc++.h>
using namespace std;

int n, l, v, qn; // number, length, velocity, question number
int mag[200010]; // magic

/*
    Years that Sisyphus need to go.
*/
int year(int tme) // time
{
    double sum = 0;

    for (int i = 0; i <= n; i++)
    {
        sum += (double)(mag[i] / v);
        if (sum + (double)(l / v) > (double)tme)
        {
            return i;
        }
    }

    return -1;
}

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    scanf("%d%d%d", &n, &l, &v);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &mag[i]);
    }
    sort(mag + 1, mag + n + 1, cmp);
    scanf("%d", &qn);
    for (int i = 0; i < qn; i++)
    {
        int que = 0; // question
        scanf("%d", &que);

        cout << year(que) << endl;
    }

    return 0;
}