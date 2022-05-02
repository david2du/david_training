#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

struct Num
{
    int num;
    int status; //no : red, 1; err : yellow, 2; yes : green, 3; nothing : 0
};

void color(int c)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, c);
}

bool str2num_error = true;

vector<int> str2num(string str)
{
    vector<int> v;
    int n = 0;
    int i = 0;

    str2num_error = false;

    for (i = 0; i < str.size(); i++)
    {
        n = str[i] - '0';

        if ((n < 0) || (n > 9))
        {
            str2num_error = true;
            return v;
        }

        v.push_back(n);
    }

    return v;
}

int buildSingleNum()
{
    int num = 0;

    num = rand() % 10;

    return num;
}

vector<int> buildAllNum(int n)
{
    vector<int> v;
    int i = 0;
    int num = 0;
    bool same = false;

    srand(time(0));

    for (i = 0; i < n; i++)
    {
        same = true;
        while (same == true)
        {
            num = buildSingleNum();

            if (find(v.begin(), v.end(), num) == v.end())
            {
                same = false;
            }
            else
            {
                same = true;
            }
        }
        v.push_back(num);
    }

    return v;
}

int getCount()
{
    int count = 0;

    cout << "Please input the count of the numbers (1 - 9) :" << endl;

    while ((count < 1) && (count > 9))
    {
        cin >> count;
    }

    return count;
}

void guessNum_print(int num)
{
    printf("          Please input %d nums (don't split by anything)\n", num);
}

vector<int> guessNum_getNum(int num)
{
    int n = 0;
    int i = 0;
    vector<int> vnum;
    string str;

    while (str2num_error == true)
    {
        guessNum_print(num);
        cin >> str;
        vnum = str2num(str);
    }

    return vnum;
}

bool guessNum_findNum(vector<int> v, int num)
{
    int i = 0;
    bool find = false;

    for (i = 0; i < v.size(); i++)
    {
        if (v[i] == n)
        {
            find = true;
            break;
        }
    }

    return find;
}

bool guessNum_userNum_true(vector<int> v, int num, int num_dir)
{
    bool find = false;

    
}

void guessNum()
{
    vector<Num> user_num;
    vector<int> num;
    int n = 0;
    int i = 0;

    n = getCount();
    num = buildAllNum(n);

    for (i = 0; i < num.size(); i++)
    {
        user_num[i].num = num[i];
        user_num[i].status = 0;
    }
}

void test()
{
    int n = 0;
    vector<int> v1, v2;
    int i = 0;

    cin >> n;
    v1 = buildAllNum(n);

    for (i = 0; i < v1.size(); i++)
    {
        cout << v1[i];
    }
    cout << endl;

    v2 = guessNum_getnum(n);

    for (i = 0; i < v2.size(); i++)
    {
        cout << v2[i];
    }
    cout << endl;
}

int main()
{
    test();

    return 0;
}