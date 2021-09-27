#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main(int argc, char const *argv[])
{
    long long a = 0, b = 0;

    freopen("excel.in", "r", stdin);
    freopen("excel.out", "w", stdout);

    cin >> a >> b;

    long long t = b;
    while (t > 0)
    {
        v.push_back(t % 26 == 0 ? 26 : t % 26);
        t = (t - v[v.size() - 1]) / 26;
        //cout << v[v.size() - 1] << endl;
    }

    for(long long i = v.size() - 1; i >= 0; i--)
    {
        printf("%c", v[i] + 'A' - 1);
    }
    cout << a << endl;
    
    return 0;
}