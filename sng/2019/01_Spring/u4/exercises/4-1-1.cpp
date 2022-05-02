#include<bits\stdc++.h>
using namespace std;
int main()
{
	int price = 0 ,totalMoney = 0;
	int num = 0 ,rem = 0;
	
	totalMoney = 100;
	price = 26;
	
	num = totalMoney / price;
	rem = totalMoney % price;
	cout << num << "Ö§" << endl;
	cout << rem << "·Ö" <<endl;
	return 0;
}
