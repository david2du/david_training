#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num[7] = {0};

    for (int i = 0; i < 7; i++)
    {
        cin >> num[i];
    }
    sort(num, num + 7);

    cout << num[0] << " " << num[1] << " " << (num[6] - num[0] - num[1]) << endl;

    return 0;
}