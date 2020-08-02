#include <iostream>
using namespace std;
//int a = 0, b = 0; 
void swap(int &a, int &b)
{
    int c = 0;

    c = a;
    a = b;
    b = c;

}

int main()
{
    int a = 0, b = 0;
    cin >> a >> b;

    swap(a, b);
    cout << a << " " << b << endl;
}