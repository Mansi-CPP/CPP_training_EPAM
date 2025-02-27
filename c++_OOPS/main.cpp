#include <iostream>
#include<string >
#include <array>
#include "classes.h"
using namespace std;

int main() {
	employee* e1 = new employee;//this is a pointer so destructor is not called need to free using delete
	employee em(3000);//deleted
	*e1->name="Mansi";
	e1->dept = "CPP";
	e1->experience = 0;
	e1->salary = 25000;
	/*employee employees[3] = {
		employee("John","CPP", 5, 60000),
		employee("Alice","CPP", 3, 50000),
		employee("Bob","CPP", 7, 70000)
	};
	for (int i = 0; i < 3; i++) {
		cout << "Employee" << i<<endl;
		employees[i].display();
	}*/
	array<employee, 3> employees = {
	   employee("John","CPP", 5, 60000),
	   employee("Alice","CPP", 3, 50000),
	   employee("Bob","CPP", 7, 70000)
	};
	//em.display();
	//e1->inc_salary(3000);
}

