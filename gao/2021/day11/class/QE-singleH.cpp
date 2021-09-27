#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <random>
using namespace std;

typedef unsigned long long HT; // Single Hash Type

HT hashs(const string &s, const vector<HT> &base)
{
    HT h = 0;

    for (int i = 0; i < s.size(); i++)
    {
        h += (s[i] * base[i]);
    }

    return h;
}

vector<HT> base;

void hash_init(int size)
{
    random_device rd;
    mt19937 rand_n(rd());

    for (int i = 0; i < size; i++)
    {
        base.push_back((HT)(rand_n()));
    }
}

set<HT> st;

void add(const string &s)
{
    st.insert(hashs(s, base));
}

bool ask(const string &s)
{
    return (st.find(hashs(s, base)) != st.end());
}

int main(int argc, char const *argv[])
{
    int n = 0;

    cin >> n;

    hash_init(256);

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        string op;

        getline(cin, op);

        if (s == "add")
        {
            add(op);
        }
        else
        {
            if (ask(op))
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
    }

    return 0;
}
