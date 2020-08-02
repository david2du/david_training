#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    int a[10000] = {0};
    int i = 0;
    int max = 0, min = 0;
       
    cin >> n;
    
    for ( i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    max = a[0];
    min = a[0];
    
    for (i = 0; i < n; i++)
    {
        if (a[i] > max)   
        {
            max = a[i];     
        }
        if (a[i] < min)
        {
            min = a[i];        
        }
    }
    
    
    cout << max - min;    
}
