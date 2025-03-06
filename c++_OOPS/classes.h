#include<iostream>
#include <string>

using  namespace std;
class employee {
public:
	string* name;
	string dept;
	int experience;
	double salary;
public:
	employee();
	employee(double amount);
	employee(string name,string dept,int exp, double s);
	~employee();

	void display();
	int inc_salary(double salary);
};
