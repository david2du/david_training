#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	freopen("title.in", "r", stdin);
	freopen("title.out", "w", stdout);
	
	string s;
	int sum = 0;
	unsigned int i = 0;
	
	getline(cin, s, '\n');
	
	for (i = 0; i < s.size(); i++)
	{
		if ((s[i] != ' ') && (s[i] != '\n'))
		{
			sum++;
		}
	}
	
	cout << sum << endl;
	
	return 0;
}
