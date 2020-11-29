#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
	string s;
	
	getline(cin, s);
	//cout << "s :" << s << endl;
	string str;
	getline(cin, str);
	//cout << "str :" << str << endl;
	
	int idx = s.find(str);
	if (idx != string::npos)
	{
		cout << "find(): No." << idx << endl;
	}
	else
	{
		cout << "Not founded." << endl;
	}
	
	idx = s.rfind(str);
	if (idx != string::npos)
	{
		cout << "rfind(): No." << idx << endl;
	}
	else
	{
		cout << "Not founded." << endl;
	}
	
	cout << endl
		 << "__________________REPLACE__________________" << endl;
	
	cin >> str;
	int a = 0, b = 0;
	cin >> a >> b;
	s.replace(a, b, str);
	
	cout << s << endl;
	
	return 0;
}
