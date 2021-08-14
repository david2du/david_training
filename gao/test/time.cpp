#include <iostream>
using namespace std;

int main()
{
    long long n = 0;

    cin >> n;

    time_t a = clock();
    for (long long i = 0; i < n; i++)
    {

    }

    time_t b = clock();

    cout << (double)(b - a) / (double)(CLOCKS_PER_SEC) << "s" << endl;

    return 0;
}