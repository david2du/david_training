#include <bits/stdc++.h>
using namespace std;

short num[1024];
int srt[3];

int main()
{
    int n = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        srt[num[i]]++;
    }

    for (int i = 0; i < srt[0]; i++)
    {
        cout << 0 << " ";
    }
    for (int i = 0; i < srt[1]; i++)
    {
        cout << 1 << " ";
    }
    for (int i = 0; i < srt[2]; i++)
    {
        cout << 2 << " ";
    }

    return 0;
}