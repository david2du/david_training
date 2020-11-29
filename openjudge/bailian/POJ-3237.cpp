#include <iostream>
using namespace std;

int main()
{
    int num = 0;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int leg = 0;

        cin >> leg;

        if (leg % 2 == 1)
        {
            cout << "0 0" << endl;
            continue;
        }
        else
        {
            if (leg % 4 == 0)
            {
                cout << leg / 4 << " ";
            }
            else
            {
                cout << leg / 4 + 1 << " ";
            }

            cout << leg / 2 << endl;
        }
    }

    return 0;
}