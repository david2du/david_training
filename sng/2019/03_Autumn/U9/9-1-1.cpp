#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int next = 0, mid = 0;
    int top = 0;
    int n = 0;
    int i = 0, j = 0;

    getline(cin, str);
    top = str.size() - 1;
    mid = str.size() / 2;

    for (i = 0; i < mid; i++, top--)
    {
        if (str[i] == str[top])
        {
            n++;
        }
    }

    if (n == str.size() / 2)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }

    return 0;
}
