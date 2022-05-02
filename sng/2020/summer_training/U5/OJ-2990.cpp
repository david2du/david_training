#include <bits/stdc++.h>
using namespace std;

vector<bool> v;

void print()
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	cout << endl;

	v.clear();
}

int ps, ms;// plus sum; minus sum
int maxp, maxm; // max plus; max minus

void dfs(int left, bool plus)
{
	if (left == 0)
	{
		print();

		return;
	}

	v.push_back(plus);
	ps += plus;
	ms += (!plus);

	if (ps < pmax)
	{
		dfs(left - 1, true);
	}
	else
	{
		dfs(left - 1, false);
	}
}

int main()
{
	int n = 0;

	cin >> n;

	if (n == 0)
	{
		return 0;
	}

	return 0;
}
