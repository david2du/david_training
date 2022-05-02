#include <bits/stdc++.h>
using namespace std;


char info[1024];

int main()
{

	ifstream fin("a.in");
	ofstream fout("a.out");
	fin.getline(info, sizeof(info));
	cout << info << endl;
	fout << info;
	
	return 0;
}
