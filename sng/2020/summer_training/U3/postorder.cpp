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
	string str;
	stack<float> sta;

	while (cin >> str)
	{
		if ((str[0] == '+') || (str[0] == '-') || (str[0] == '*') || (str[0] == '/'))
		{
			float y = sta.top();
			sta.pop();
			float x = sta.top();
			sta.pop();
			switch (str[0])
			{
			case '+':
				sta.push(x + y);
				break;
			case '-':
				sta.push(x - y);
				break;
			case '*':
				sta.push(x * y);
				break;
			case '/':
				sta.push(x / y);
				break;
			default:
				break;
			}
		}
		else
		{
			sta.push(str2f(str));
		}
	}
	printf("%f", sta.top());

	return 0;
}