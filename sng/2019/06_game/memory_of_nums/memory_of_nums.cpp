#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

double ratTmeNbs; //ratio between time and numbers (double) : time /  numbers need
vector<int> v;
int n = 0;
int rangeStart = 1, rangeEnd = 10;

void buildNum()
{
    for (int i = 0; i < n; i++)
    {
        int randN = 0;

        randN = rand() % (rangeEnd - rangeStart) + rangeStart;
        v.push_back(randN);
    }
}

void print()
{
    while (n < 5)
    {
        cout << "Please  Input  How  Many  Numbers  Do  You  Need :    " << endl;
        cin >> n;

        if (n < 5)
        {
            cout << "Input  Error,  Number  You  Input  MUST  Be  Bigger  Than  five." << endl;
        }
    }

    double sleepTime = n * ratTmeNbs;

    cout << "TIME : " << sleepTime << " s" << endl;

    buildNum();

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "     ";
    }

    cout << endl;
    
    Sleep(abs((int)sleepTime * 1000));

    system("cls");
}

void ask()
{
    int num;
    int num_std = 0, num_input = 0;

    num = rand() % (v.size() - 2) + 1;
    num_std = v[num - 1];

    cout << "Please  Input  No." << num << ":" << endl;

    cin >> num_input;

    if (num_input == num_std)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
        cout << "True : " << num_std << endl;
    }
}

void cleanVector()
{
    while (v.size() != 0)
    {
        v.pop_back();
    }
}

int main()
{
    string s = "yes";

    ifstream rgeIn("range.txt");
    ifstream ratIn("ratio.txt");

    rgeIn >> rangeStart >> rangeEnd;
    ratIn >> ratTmeNbs;

    srand(time(0));

    while (s.compare("yes") == 0)
    {
        n = 0;
        cleanVector();

        system("cls");

        print();
        ask();

        cout << "Want  Another  Round???   (yes or no)" << endl;
        cout << "(If you input yes, continue playing. Else, escape)" << endl;

        cin >> s;
    }

    return 0;
}