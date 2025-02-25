
#include <iostream>
#include<string >
#include "classes.h"
using namespace std;

//run time polymorphism
class base {
public:
	//void display() {
		//cout << "Hello Base";
	//}
	virtual void display() { // virtual allows to override 
		cout << "Hello Base";
	}

};
class derived :public base {
public:
	derived() {
		cout << "derived1";
	}
};
class derived1 :public base {
public:
	derived1() {
		cout << "derived1";
	}
};
class derived2 :public derived,derived1 {
public:
	derived2() {
		cout << "derived2";
	}
};
int main() {
	//base obj;
	//obj.display();// calls member function of derived class 
                  //else if not in derived ckass calls base class member function 
	base* obj = new derived;
	obj->display();
	             
}
