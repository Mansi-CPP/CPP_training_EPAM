#include<iostream>
using namespace std;
class myclass {
	int x;
	int* ptr;
public:
	myclass() {
		x = 20;
		ptr = new int(100);
		cout << "inside default const" << endl;
	}
	void print() {
		cout << "x =" << x << endl;
		cout << "ptr =" << ptr << endl;
	}
	myclass(const myclass& other) {
		x = other.x;
		ptr = new int(*other.ptr);
	}
	~myclass() {
		delete ptr;
		cout << "deleted" << endl;
	}
	myclass operator=(const myclass& ot) {
		if (this == &ot) {
			return *this;
	   }
		cout << "check"<<endl;
		delete ptr;
	
		this->x = ot.x;
		this->ptr = new int(*ot.ptr);
		return *this;
	}
};

#include <iostream>
#include<string >
#include "assignment.cpp"
using namespace std;
//If an object is declared and immediately initialized with another object → Copy constructor is used.
//If an existing object is assigned another object → Assignment operator (operator=) is used.
//That's why in your case, myclass obj3 = obj1; calls the copy constructor instead of the assignment operator. 🚀

int main()
{ 
	myclass obj1;
	obj1.print();
	myclass obj2(obj1);//copy const
	obj2.print();
	myclass obj3 = obj1;// the object is being initialise here so copy constructor is called not assignment because obj3 not exist before 
	obj3.print();
	obj2 = obj3;// assignement operator called
	obj2.print();
	obj3.print();
	obj1 = obj2 = obj3;//assignment operator first obj2=obj3 executes and delets the memory already allocated to obj2
	//then same with obj1 and obj2;
	cout << "obj1";
	obj1.print();
	cout << "obj2";
	obj2.print();
	cout << "obj3";
	obj3.print();
	obj1 = obj1;// self assignment meet ot==this so return this only
	return 0;

}


