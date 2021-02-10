#include <bits/stdc++.h>
using namespace std;

map<int, int> DI = {{1, 31}, {2, 29}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}}; // days in a month

struct Date
{
    int month;
    int day;

    bool operator<(const Date &date) const
    {
        if (month != date.month)
        {
            return month < date.month;
        }
        else
        {
            return day < date.day;
        }
    }
    Date add(int days)
    {
        day += days;

        if (day > DI[month])
        {
            month += (day / DI[month]);
            day %= DI[month];
        }

        return (Date){month, day};
    }
};

int main()
{
    map<Date, string> mp = {{{2, 4}, "LC"}, {{2, 19}, "YS"}, {{3, 5}, "JZ"}, {{3, 20}, "CF"}, {{4, 4}, "QM"}, {{4, 19}, "GY"}, 
                    {{5, 5}, "LX"}, {{5, 20}, "XM"}, {{6, 5}, "MZ"}, {{6, 21}, "XZ"}, {{7, 6}, "XS"}, {{7, 22}, "DS"}, 
                    {{8, 7}, "LQ"}, {{8, 22}, "CS"}, {{9, 7}, "BL"}, {{9, 22}, "QF"}, {{10, 8}, "HL"}, {{10, 23}, "SJ"}, 
                    {{11, 7}, "LD"}, {{11, 22}, "XX"}, {{12, 7}, "DX"}, {{12, 21}, "DZ"}, {{0, 0}, "XH"}, {{0, 0}, "DH"}};
    Date dt;

    cin >> dt.month >> dt.day;

    auto it = mp.find(dt);
    if (it == mp.end())
    {
        do
        {
            dt = dt.add(1);

            it = mp.find(dt);
        } while (it != mp.end());
        cout << mp[dt] << endl;
    }
    else
    {
        cout << mp[dt] << endl;
    }
    

    return 0;
}

/*#include <bits/stdc++.h>
using namespace std;

struct Date
{
    int month;
    int day;

    bool operator<(const Date &date) const
    {
        if (month != date.month)
        {
            return month < date.month;
        }
        else
        {
            return day < date.day;
        }
    }
};

int main()
{
    map<Date, string> mp = {{{2, 4}, "LC"}, {{2, 19}, "YS"}, {{3, 5}, "JZ"}, {{3, 20}, "CF"}, {{4, 4}, "QM"}, {{4, 19}, "GY"}, 
                    {{5, 5}, "LX"}, {{5, 20}, "XM"}, {{6, 5}, "MZ"}, {{6, 21}, "XZ"}, {{7, 6}, "XS"}, {{7, 22}, "DS"}, 
                    {{8, 7}, "LQ"}, {{8, 22}, "CS"}, {{9, 7}, "BL"}, {{9, 22}, "QF"}, {{10, 8}, "HL"}, {{10, 23}, "SJ"}, 
                    {{11, 7}, "LD"}, {{11, 22}, "XX"}, {{12, 7}, "DX"}, {{12, 21}, "DZ"}, {{0, 0}, "XH"}, {{0, 0}, "DH"}};
    Date dt;

    cin >> dt.month >> dt.day;

    cout << mp[dt] << endl;

    return 0;
}*/