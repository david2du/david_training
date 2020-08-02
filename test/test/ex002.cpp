#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string s;
    string s1;
    string s2;
    int i = 0;
    int l = 0;
    
    getline(cin, s, ',');
    getline(cin, s1, ',');
    getline(cin, s2);
    
    int len1 = s1.size();
    int m1 = s.find(s1);
    int m2 = s.rfind(s2);
    
    if ((m2 < m1) || (m1 == -1) || (m2 == -1))
    {
            cout << "-1" << endl;
    }
    else
    {
        cout << m2 - m1 - len1 << endl;
    }    
     
   return 0;   
}