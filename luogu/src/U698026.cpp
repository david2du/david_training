#include <iostream>

using namespace std;

int main()
{
    int score = 0;

    cin >> score;
    if (score < 0 || score > 100)
        cout << "No" << endl;
    else if (score < 60)
        cout << "E" << endl;
    else if (score < 70)
        cout << "D" << endl;
    else if (score < 80)
        cout << "C" << endl;
    else if (score < 90)
        cout << "B" << endl;
    else
        cout << "A" << endl;

    return 0;
}