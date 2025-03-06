
#include <iostream>
#include<string >
#include "CIL.h"
using namespace std;

int main() {
	//student e1();
	//student e2("Aman","CSE", 0); considers it as a function call not constructor call 
	string dept = "CSE";
	student s("Aman", dept, "zeta 1","greater Noida");
	s.display();
	return 0;
}


