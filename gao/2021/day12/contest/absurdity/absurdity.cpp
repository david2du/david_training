#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    freopen("absurdity.in", "r", stdin);
    freopen("absurdity.out", "w", stdout);

    int a = 0;
    cin >> a;

    string s;

    cin >> s;

    size_t sum = 0;

    sum = s.size() * (s.size() + 1) * (s.size() * 2 + 1) / 6;

    cout << sum % (size_t)(1e9 + 7)<< endl;
    
    return 0;
}