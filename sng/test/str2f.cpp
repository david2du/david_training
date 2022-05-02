#include <bits/stdc++.h>
using namespace std;

float str2f(string str) // string to float
{
	stringstream s;
	float f;
	
	s << str;
	s >> f;
	
	return f;
}

int main()
{
    string s;

    cin >> s;
    printf("%f", str2f(s));

    return 0;
}