#include <bits/stdc++.h>
using namespace std;

void splt(const string &in, const string &pst)
{
    if (in.empty())
        return;
    cout << pst.back();
    if (in.size() <= 1)
        return;
    int pos = in.find(pst.back());
    splt(in.substr(0, pos), pst.substr(0, pos));
    splt(in.substr(pos + 1), pst.substr(pos, pst.size() - pos - 1));
}

int main()
{
    string in, pst;

    cin >> in >> pst;
    splt(in, pst);

    return 0;
}