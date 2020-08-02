#include <bits/stdc++.h>
using namespace std;

struct Stu
{
	string name;
	int score;
};

bool cmp(Stu a, Stu b)
{
	return a.name < b.name;
}

int main()
{
	freopen("student_name.in", "r", stdin);
	freopen("student_name.out", "w", stdout);
	
	Stu stu[50];
	int n = 0;
	int i = 0;
	
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> stu[i].name >> stu[i].score;
	}
	
	sort(stu, stu + n, cmp);
	
	for (i = 0; i < n; i++)
	{
		cout << stu[i].name << " " << stu[i].score << endl;
	}
	
	return 0;
}
