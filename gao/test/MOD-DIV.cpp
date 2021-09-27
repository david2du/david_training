#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    long long n = 1e9;
    
    double ave1 = 0.0, ave2 = 0.0;

    for (int j = 0; j < 50; j++)
    {
        clock_t a = clock();

        for (long long i = 0; i < 1e7; i++)
        {
            long long a1 = 1e16;
            a1 %= (long long)(1e8);
        }

        clock_t b = clock();

        cout << (double)(b - a) / (double)(CLOCKS_PER_SEC) << "s" << endl;
        ave1 += (double)(b - a) / (double)(CLOCKS_PER_SEC);

        a = clock();
        for (long long i = 0; i < 1e7; i++)
        {
            long long a1 = 1e16;
            a1 -= a1 / (long long)(1e8) * (long long)(1e8);
        }

        b = clock();

        cout << "   " << (double)(a - b) / (double)(CLOCKS_PER_SEC) << "s" << endl;
        ave2 += (double)(b - a) / (double)(CLOCKS_PER_SEC);
    }

    printf("\n\nMod: %.8lfs  Minus: %.8lfs\n", ave1 / 50.0, ave2 / 50.0);

    return 0;
}