#include <bits/stdc++.h>
using namespace std;

bool cmp(const long long &A, const long long &B)
{
    return A > B;
}

int main()
{
    vector<long long> v;
    const long long n = 10000;

    //cin >> n;
    srand(time(0));
    for (long long i = 0; i < n; i++)
    {
        v.push_back(i % 1000);
    }

    clock_t A = clock();
    sort(v.begin(), v.end());
    clock_t B = clock();

    cout << "No CMP: " << (double)(B - A) / (double)CLOCKS_PER_SEC << "s" << endl;

    A = clock();
    sort(v.begin(), v.end(), cmp);
    B = clock();

    cout << "CMP: " << (double)(B - A) / (double)CLOCKS_PER_SEC << "s" << endl;

    return 0;
}