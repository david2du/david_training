#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int N = 400000;
bool s[N + 1][256];

ull myRand(ull &k1, ull &k2)
{
    ull k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= (k3 << 23);
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}

void gen(int n, ull a1, ull a2)
{
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 256; j++)
            s[i][j] = (myRand(a1, a2) & (1ull << 32)) ? 1 : 0;
}

bool tmp[256];

void hex_exchge(string str, bool stt)
{
    fill(tmp, tmp + 256, false);
    for (auto i = str.begin(), j = 255; i != str.end() && j >= 0; i++, j -= 4)
    {
        auto now = 0;

        if ((*i) <= '9')
        {
            now = (*i) - '0';
        }
        else
        {
            now = 10 + (*i) - 'A';
        }

        tmp[j - 3] = ((now >>= 1) & 1) ^ stt;
        tmp[j - 2] = ((now >>= 1) & 1) ^ stt;
        tmp[j - 1] = ((now >>= 1) & 1) ^ stt;
        tmp[j] = ((now >>= 1) & 1) ^ stt;
    }
}

bool ask(int k)
{

}

int main(int argc, char const *argv[])
{
    auto n = 0, m = 0, a1 = 0ULL, a2 = 0ULL;

    ifstream fin("qi.in");
    ofstream fout("qi.out");

    fin >> n >> m >> a1 >> a2;
    gen(n, a1, a2);

    auto last = false;
    for (auto i = 0; i < m; i++)
    {
        string hex_str;

        fin >> hex_str;

        hex_exchge(hex_str, last);

        auto k = 0;
        fin >> k;

        cout << ask(k) << endl;
    }

    return 0;
}