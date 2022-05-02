#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    int num[1010] = {0};

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    int maxSum = 0, sum = 0;
    int bsti = 0, bstj = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum += num[j];

            if (sum > maxSum)
            {
                maxSum = sum;
                bsti = i;
                bstj = j;
            }
        }

        sum = 0;
    }

    printf("MAX_SUM a[%d ~ %d]:%d", bsti, bstj, maxSum);

    return 0;
}