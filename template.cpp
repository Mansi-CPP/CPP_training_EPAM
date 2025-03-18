#include<iostream>
#include <string>
#include<typeinfo>
using namespace std;
// function template
template <typename T> 
T remainder(T a,T b){
	return a % b;
}

template<typename p>
class A {
	p a;
	p b;
public:
	A(p a1, p b2) :a(a1), b(b2) {
		cout << "constructor called" << endl;
	}
	p avg() {
		return( (a + b) / 2);
	}
	void display() {
		cout << "a" << typeid(a).name()<< endl;
		cout << "b" << typeid(b).name()<< endl;
	}
};

template<typename p1,typename p2> // class accepting different parameter types
class B{
	p1 a;
	p2 b;
public:
	B(p1 a1, p2 b2) :a(a1), b(b2) {
		cout << "constructor called" << endl;
	}
	auto avg1() {
		return((a + b) / 2);
	}
	void display1() {
		cout << "a" << typeid(a).name() << endl;
		cout << "b" << typeid(b).name() << endl;
	}
};
// full specialisation
template <typename a>
class full {
public:
	void show() {
		//cout << typeid(a).name<< endl; not in msvc
		cout << "general";
	}
};
template<>
class full<char > {
public:
	void show() {
		cout << "char *" << endl;
	}
};
// partial for function>
template<typename t1,typename t2>
class partial {
public:
	t1 a;
	t2 b;
	auto addition() {
		return a + b;
	}
};
template<typename t1>
class partial<t1,string> {
public:
	t1 a;
	string b;
	string addition() {
		return to_string(a) + b;
	}
};

int main()
{  
	/*cout<<remainder(3.4, 5)<<endl;
	cout<<remainder(5, 6)<<endl;
	cout<<remainder(3, 6.6)<<endl;
	cout<<remainder(923623593893012LL, 34617381398614871LL)<<endl;
	A<int> ex(2, 4);
	cout<<ex.avg();
	ex.display();
	B<double, int> ex2(3.2, 4);
	cout<<ex2.avg1();
	ex2.display1();*/
	string str = "hellp";
	full<int> f1;
	f1.show();
	full<char> f2;
	f2.show();
	partial<int, double> p1;
	p1.a = 2;
	p1.b = 3.0;
	cout<<p1.addition()<<endl;
	partial<int, string>p2;
	p2.a = 2;
	p2.b = str;
	cout<<p2.addition()<<endl;

	return 0;
}
