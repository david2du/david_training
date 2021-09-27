#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <random>
using namespace std;

typedef unsigned long long SHT; // Single Hash Type

SHT hashs(const string &s, const vector<SHT> &base)
{
    SHT h = 0;

    for (int i = 0; i < s.size(); i++)
    {
        h += (s[i] * base[i]);
    }

    return h;
}

vector<SHT> base1;
vector<SHT> base2;

void hash_init(int size)
{
    random_device rd;
    mt19937 rand_n(rd());

    for (int i = 0; i < size; i++)
    {
        base1.push_back((SHT)(rand_n()));
    }
    for (int i = 0; i < size; i++)
    {
        base2.push_back((SHT)(rand_n()));
    }
}

typedef pair<SHT, SHT> HT; // Double-Hash Type

HT getHash(const string &s)
{
    HT h;

    h.first = hashs(s, base1);
    h.second = hashs(s, base2);

    return h;
}

set<HT> st;

void add(const string &s)
{
    st.insert(getHash(s));
}

bool ask(const string &s)
{
    return (st.find(getHash(s)) != st.end());
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
