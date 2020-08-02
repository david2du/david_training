#include<bits/stdc++.h>
using namespace std;
int main()
{
    ofstream fout("N.out");
	int a = 0;
    int b = 0;
    int n = 0;
    int q = 0, r = 0;
    
    scanf("%d / %d", &a, &b);
    
	system("cls");
	cout << a << " / " << b << " =		";
	fout << a << " / " << b << " =		"; 

    q =  a / b;

    cout << q << ".";
    fout << q << ".";

    r = a % b;
    n = r;

    while (r != 0)
    {
        n *= 10;

        q = n / b;

        cout << q;
        fout << q;

        r = n % b;        
		n = r;
    } 

    return 0;
}
