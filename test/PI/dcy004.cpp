#include<bits/stdc++.h>
using namespace std;
int main()
{
    ofstream fout("PI.out");
    const int A = 355;
    const int B = 113;
    int a = 0;
    int q = 0, r = 0;

    q =  A / B;

    cout << q << ".";
    fout << q << ".";

    r = A % B;
    a = r;

    while (r != 0)
    {
        a *= 10;

        q = a / B;

        cout << q;
        fout << q;

        r = a % B;        
		a = r;
    } 

    return 0;
}
