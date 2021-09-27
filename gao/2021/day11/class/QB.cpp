#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long SHT;     // Single Hash Type
typedef pair<SHT, SHT> HT; // Hash Type

SHT hash_str(const string &s, const vector<SHT> &BASE)
{
    SHT hashn = 0;

    for (size_t i = 0; i < s.size(); i++)
    {
        hashn += (s[i] - 'A') * BASE[i];
    }

    return hashn;
}

vector<SHT> base1, base2;

HT hashs(const string &s)
{
    HT h;
    h.first = hash_str(s, base1);
    h.second = hash_str(s, base2);

    return h;
}

void init(const string &s)
{
    for (size_t i = 1; i <= s.size(); i++)
    {
        base1.push_back((SHT)(i * 2));
        base2.push_back((SHT)((s.size() - i + 1) * 2));
    }
}

int main(int argc, char const *argv[])
{
    int t = 0;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string s1, s2;
    
        cin >> s1 >> s2;

        init(s1);

        HT hash1 = hashs(s1);
        HT last = hashs(s2.substr(0, s1.size()));
        //printf("HASH2: %lld, %lld\n", last.first, last.second);

        int ans = (hash1 == last);
        for (size_t i = 1; i < (s2.size() - s1.size() + 1); i++)
        {
            HT now;

            now.first = (last.first - (s2[i - 1] - 'A') * base1[0]) / 2 + (s2[i + s1.size() - 1]- 'A') * base1[s1.size() - 1];
            now.second = (last.second - (s2[i - 1] - 'A') * base2[0]) * 2 + (s2[i + s1.size() - 1] - 'A') * base2[s1.size() - 1];

            if (hash1 == now)
            {
                ans++;
            }
            last = now;

            //printf("HASH2: %lld, %lld\n", now.first, now.second);
        }

        cout << ans << endl;

        base1.clear();
        base2.clear();
    }

    return 0;
}