
#include "CIL.h"
#include<string>
explicit student(string n) {
	name = n;
	//dept = d;
	cout << "explcit creation";
}
student::~student()
{
	cout << "destructed" << endl;
}

void student::display() {
    cout << "Name: " << name << endl;
    cout << "Department: " << dept << endl;
    cout << "address" << address.street<<address.city << endl;
        /*  int n = marks.size();
    for (int i = 0;i < n;i++) {
        cout << marks[i] << " ";
    }*/
}
