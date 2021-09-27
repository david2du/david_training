#include <iostream>
#include <string>
using namespace std;

const int MAX = 110;
int a[MAX], c[MAX];

int divide(const string &str, int b, string &ans)
{
    int i = 0, lena = 0, lenc = 0, x = 0;

    lena = (int)str.size();
    for (i = 0; i < la; i++)
    {
        a[lena - i - 1] = str[i] - '0';
    }

    x = 0;
    for (i = lena - 1; i >= 0; i--)
    {
        c[i] = (x * 10 + a[i]) / b;
        x = (x * 10 + a[i]) % b;
    }
    lenc = lena;
    while (lenc > 1 && c[lenc - 1] == 0)
    {
        lenc--;
    }

    ans.clear();
    for (int i = 0; i < lenc; i++)
    {
        ans += (c[lenc - i - 1] +'0');
    }

    return x;
}

int main(int argc, const char *argv[])
{
    string a, b;

    freopen("excel.in", "r", stdin);
    freopen("excel.out", "w", stdout);

    cin >> a >> b;

    while (b != "0")
    {
        v.push_back(divide(b, 27) == 0 ? 26 : b % 26);
        b = (b - v[v.size() - 1]) / 26;
        //cout << v[v.size() - 1] << endl;
    }

    for(long long i = v.size() - 1; i >= 0; i--)
    {
        printf("%c", v[i] + 'A' - 1);
    }
    cout << a << endl;

    return 0;
}