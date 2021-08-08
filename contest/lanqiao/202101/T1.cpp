#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num[3] ={0};

    for (int i = 0; i < 3; i++)
    {
        cin >> num[i];
    }

    sort(num, num + 3);

    cout << num[0];
    for (int i = 1; i < 3; i++)
    {
        cout << " " << num[i];
    }
    cout << endl;

    return 0;
}