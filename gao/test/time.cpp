#include <iostream>
using namespace std;

int main()
{
    long long n = 1e9;

    clock_t a = clock();
    for (long long i = 0; i < n; i++)
    {
        i++;
        i--;

        i *= 2;
        i /= 2;

    }

    clock_t b = clock();

    cout << (double)(b - a) / (double)(CLOCKS_PER_SEC) << "s" << endl;

    return 0;
}