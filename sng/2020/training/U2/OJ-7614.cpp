#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Stu
{
    int score;
    int name;
};

bool cmp(const Stu &A, const Stu &B)
{
     return A.score >= B.score;
}

Stu stu[5010];

int main()
{
    int n = 0, m = 0;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &stu[i].name, &stu[i].score);
    }
    
    sort(stu, stu + n, cmp);
    
    int scr = stu[floor((m - 1) * 1.50)].score;
    
    for (int i = 0; i < n; i++)
    {
        cout << stu[i].name << " " << stu[i].score << endl;
    }
    /*for (int i = 0; i < n; i++)
    {
        cout << stu[i].name << " " << stu[i].score << endl;
    }*/ 
    
    //system("pause");
    return 0;
}
