#include <iostream>
using  namespace std; 

string fun(string s)
{
    string str = s + s;

    return str;
}

void fun(string s, string &str)
{
    str = s + s;
}

int main(int argc, char const *argv[])
{
    string ans1 = fun("abcdefg");
    string ans2;
    fun("abcdefg", ans2);

    cout << ans << endl;
    return 0;
}
