#include <bits/stdc++.h>
using namespace std;

long long a[10010];

int main(int argc, char const *argv[])
{
    int n = 0, a = 0;

    cin >> n >> a;
    for (int i = 0; i < n; i++)
    {
        a[i] = (long long)rand();
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    long long ans = 0;
    int 
    for (int i = 0; i < n; i++)
    {
        ans += a[i];
    }
    
    return 0;
}