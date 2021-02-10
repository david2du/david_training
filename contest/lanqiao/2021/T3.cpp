#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;

    cin >> n;

    int sec = n % 60;
    n /= 60;
    int mnt = n % 60;
    n /= 60;
    int hr = n;

    if (hr < 10)
    {
        printf("0");
    }
    printf("%d:", hr);

    if (mnt < 10)
    {
        printf("0");
    }
    printf("%d:", mnt);

    if (sec < 10)
    {
        printf("0");
    }
    printf("%d\n", sec);

    return 0;
}