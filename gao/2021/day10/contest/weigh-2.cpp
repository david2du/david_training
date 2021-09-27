#include <iostream>
#include <vector>
using namespace std;

vector<long long> w;

const long long BS[6] = {1, 2, 3, 5, 10, 20};

inline void divi(long long a, long long idx)
{
    long long t = 1;
    while (a > 0)
    {
        if (a >= t)
        {
            w.push_back(t * BS[idx]);
        }
        else
        {
            w.push_back(a * BS[idx]);
        }

        a -= t;
        t <<= 1;
    }
}

bitset<1000010> f;

int main(int argc, char const *argv[])
{
    long long cnt = 0;
    long long sum = 0;
    for (long long i = 0; i < 6; i++)
    {
        long long a = 0;

        cin >> a;

        divi(a, i);
        sum += a * BS[i];
    }

    for (long long i = 0; i < w.size(); i++)
    {
        f[w[i]] = true;
        for (long long j = 1; j <= sum; j++)
        {
            if (f[j] == true)
            {
                f[j + w[i]] = true;
            }
        }
    }

    long long ans = 0;
    for (long long j = 1; j <= sum; j++)
    {
        if (f[j])
        {
            ans++;
            //cout << j << endl;
        }
    }

    cout << "Total=" << ans << endl;

    return 0;
}