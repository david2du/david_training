#include <bits/stdc++.h>
using namespace std;

int rectangle(int l, int w)
{
	int size = 0;
	size = l * w;
	
	return size;
}

int main()
{
	int l = 0, w = 0;
	int size = 0;
	
	cin >> l >> w;
	
	size = rectangle(l, w);
	cout << size << endl;
	
	return 0;
}
