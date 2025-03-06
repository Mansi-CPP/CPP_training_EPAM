#include "classes.h"
#include <iostream>
#include <string>
#include <iomanip>

employee::employee()
{
    name = new string("Mansi");
    dept = "";
    experience = 0;
    salary = 0;
}

employee::employee(double amount)
{
    name = new string("Mansi");
    dept = "";  //if not initialised allocates garbage value or nothing
    experience = 0;
    salary = amount;
}

employee::employee(string n, string d,int exp, double s)
{
    name = new string(n);
    dept = d;
    experience = exp;
    salary = s;
}

employee::~employee()
{
    delete name;
    cout << "destructued";
}

void employee::display()
{
    cout << "Employee Name: " << name << endl;
    cout << "Department: " << dept << endl;
    cout << "Experience: " << experience << " years" << endl;
    cout << "Salary: $" << fixed << setprecision(2) << salary << endl;
}

int employee::inc_salary(double amount)
{
    if (amount < 0) {
        cout << "Salary increase cannot be negative!" << endl;
        return -1;  // Error code for invalid input
    }

    salary += amount;  // Increase the salary by the given amount
    return 0;
}
