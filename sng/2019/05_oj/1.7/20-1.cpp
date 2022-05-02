#include <bits/stdc++.h>
using namespace std;
int main()
{
    string word;
    char changed[32];
    unsigned int a = 0;
    unsigned int b = 0;
    unsigned int c = 0;
    int n = 0;
    unsigned int i = 0;

    cin >> word;

    a = word.rfind("er");
    b = word.rfind("ly");
    c = word.rfind("ing");

    if (a == (word.size() - 2))
    {
        n = 2;
    }
    if (b == (word.size() - 2))
    {
        n = 2;
    }
    if (c == (word.size() - 3))
    {
        n = 3;
    }

    for (i = 0; i < word.size() - n; i++)
    {
        changed[i] = word[i];
    }

    cout << changed << endl;

    return 0;
}