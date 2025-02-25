#include<iostream>
#include <string>

using  namespace std;
class employee {
public:
	string name;
	string dept;
	int experience;
	double salary;
public:
	void display(){
        cout << "Employee Name: " << name << endl;
        cout << "Department: " << dept << endl;
        cout << "Experience: " << experience << " years" << endl;
        cout << "Salary: $"  << salary << endl;
    };
	int inc_salary(double amount){
        if (amount < 0) {
            cout << "Salary increase cannot be negative!" << endl;
            return -1;  // Error code for invalid input
        }
        
        salary += amount;  // Increase the salary by the given amount
        return 0;
    };
};
int main() {
	employee* e1 = new employee;
	e1->name = "Mansi";
	e1->dept = "CPP";
	e1->experience = 0;
	e1->salary = 25000;

	e1->display();
	e1->inc_salary(3000);
}