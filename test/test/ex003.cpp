#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string s;
    string s1;
    string s2;
    int i = 0;
    int m1 = 0, m2 = 0;
    int l = 0;
    
    getline(cin, s, ',');
    getline(cin, s1, ',');
    getline(cin, s2);
    
    for (i = 0; i < s.size() ; i++)
    {
        m1 = 0;
        l = i;
        while ((s[l] == s1[m1]) && (m1 < s1.size()))
        {
              m1++;
              l++; 
        }
        if (m1 == s1.size())
        {
            m1 = i + s1.size() - 1;
            break;   
        }
    }
    
    int maxm = 0;
    for (i = m1 - 1; i < s.size(); i++)
    {
        m2 = 0;
        l = i;
        while ((s[l] == s2[m2]) && (m2 < s2.size()))
        {
              m2++;
              l++; 
        }
        if (m2 == s2.size())
        {
            m2 = i;                              
            break;
        }
        
        if (m2 > maxm)
        {
             maxm = m2;
        }
    }

    if (maxm - m1- 1 > -1)
    {
         cout << maxm - m1 - 1 << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
 
   return 0;   
}
