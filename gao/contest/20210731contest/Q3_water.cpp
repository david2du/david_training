#include <bits/stdc++.h>
using namespace std;

struct Pep
{
    long long t;
    int id;

    bool operator<(const Pep &A) const
    {
        return t < A.t;
    }
};

Pep T[1010];

long long n, m;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> T[i].t;
        T[i].id = i + 1;
    }

    sort(T, T + n);

    cout << T[0].id;
    for (int i = 1; i < n; i++)
    {
        cout << " " << T[i].id;
    }
    cout << endl;

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (T[i].t * (n - i - 1));
    }

    printf("%.2f\n", (double)(sum) / (double)(n));

    return 0;
}