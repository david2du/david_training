#include <iostream>
using namespace std;
int main()
{
	
	int a = 0, b = 0 ,s = 0;
	cout << "请输入人数和平均每人种的棵树:"<<endl;  
	cin >> a;
	cin >> b;
	s = a * b;
	cout << "总的棵数： " << s << endl;
    return 0;
}
