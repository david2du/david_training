#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    int t = 0;
    vector<int> ia;

    cin >> n;

    bool exist = false;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        exist = false;
        for (int j = 0; j < ia.size(); j++)
        {
            if (t == ia[j])
            {
                exist = true;
                break;
            }
        }

        if (!exist)
            ia.push_back(t);
    }

    for (int j = 0; j < ia.size(); j++)
    {
        cout << ia[j] << " ";
    }

    return 0;
}