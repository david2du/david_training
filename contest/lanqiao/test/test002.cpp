#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n = 0;

    cin >> n;

    vector<int> v;

    v.push_back(n * n);

    auto it = v.begin();

    cout << *it << endl;
    
    return 0;
}
