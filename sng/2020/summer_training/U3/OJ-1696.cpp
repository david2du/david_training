#include <bits/stdc++.h>
using namespace std;

stack<double> num;
stack<char> ch;

double str2d(string str) // string to double
{
	double d;
	stringstream s;

	s << str;
	s >> d;

	return d;
}

/**
 * @return Return true: The got string is a float number.
 * Return false: The got string is a char symbol, includes '+', '-', '*', '/'.
*/
bool preorder(int n)
{
	string s;

	cin >> s;

	if ((s[0] == '+') ||
		(s[0] == '-') ||
		(s[0] == '*') ||
		(s[0] == '/'))
	{
		ch.push(s[0]);

		preorder(0);
		return false;
	}
	else
	{
		n++;
		num.push(str2d(s));
	}

	if (n < 2)
	{
		if (preorder(n))
		{
			int y = num.top();
			num.pop();
			int x = num.top();
			num.pop();
			char c = ch.top();
			ch.pop();

			switch (c)
			{
			case '+':
				num.push(x + y);
				break;
			case '-':
				num.push(x - y);
				break;
			case '*':
				num.push(x * y);
				break;
			case '/':
				num.push(x / y);
				break;
			default:
				assert(false);
			}

			while (!preorder(0))
				;
				return 0;
		}
	}
	else
	{
		return true;
	}

	return false;
}

int main()
{
	preorder(0);
	printf("%f", num.top());

	return 0;
}