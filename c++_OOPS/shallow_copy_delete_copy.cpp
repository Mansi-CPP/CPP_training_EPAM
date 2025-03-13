#include<iostream>
#include<cstring>
#pragma warning(disable : 4996).
using namespace std;
class String {
public:
	char* s;
	//normal constructor
	String(const char* str) {
		s = new char(strlen(str) + 1);
		strncpy(s, str,strlen(str)+1); 
		cout << "called for" << s;
	}
	//shallow copy
	String(String& other) {
		s = other.s;
		cout << "shallow copy made";
	}
	void print() {
		cout << s << endl;
	}
	~String() {
		cout << "destructed" << s;
		delete[] s;
	}
};


#include <iostream>
#include<string >
#include "Shallow_copy_deep_copy.cpp"
using namespace std;

int main()
{
	String obj1("Riddhi");
	String obj2 = obj1;
	cout << "before" << endl;
	obj1.print();
	obj2.print();

	obj1.s[0] = 's';
	cout << "after";
	obj1.print();
	obj2.print();//now it is trying to delete memory location already deleted so error major problem with shallow copy
	return 0;

}
