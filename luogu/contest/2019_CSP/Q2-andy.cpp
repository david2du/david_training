#include <bits/stdc++.h>
using namespace std; 

int NMAX = 100010;
int a[NMAX];
int n; 

int main() {
    cin >> n; 
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i]; 
    }

    sort(a+1,a+n+1);
    lower_bound(a+1,a+n+1, a[n]);

    123445
    555
    445

    return 0; 
}