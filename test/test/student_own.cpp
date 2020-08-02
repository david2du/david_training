#include <bits/stdc++.h>
using namespace std;
struct Student
{
	string name;
	char sex;
	int age;
	int month;
	double weight;
};
int main ()
{
	Student david;
	david.name = "david du";
	david.age = 10 ;
	david.month = 6;
	david.sex = 'm';
	david.weight = 35.4;
	cout << "name :" << endl << david.name << endl;
	cout << "age :" << endl << david.age << endl;
	cout << "month :" << endl << david.month << endl;
	cout << "sex :" << endl << david.sex << endl;
	cout << "weight :" << endl << david.weight << endl;		

	return 0;
} 
