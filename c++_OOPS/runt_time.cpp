#include<iostream>
using namespace std;
class reptile {
public:
	void printi() {
		cout << "reptile";
	}
};
class lizard:public reptile {
public:

	void printi() {
		cout << "the reptile is lizard";
	}
};
class Animal {  // abstract class
public:
	virtual void speak() {
		cout << "the animal speaks" << endl;
	}
	virtual void print()=0; // pure virtual function it is meant to be overriden

	virtual ~Animal() {
		cout << "called destructor" << endl;
	}
};
class Dog :public Animal{
public:
	void speak() override {
		cout << "the dog barks" << endl;
	}
	void print() override
	{
		cout << "Called Dog print function"
			<< "\n\n";
	}
	~Dog() {
		cout << "called destructor for dog" << endl;
	}
};
//class cat :public Animal {
//public:
//	void speak() override {
//		cout << "the cat meows" << endl;
//	}
//	~cat() {
//		cout << "called destructor for cat" << endl;
//	}
//};
//class bird :public Animal {
//public:
//	void speak() override {
//		cout << "the bird chirps" << endl;
//	}
//	~bird() {
//		cout << "called destructor for dog" << endl;
//	}
//};


#include <iostream>
#include<string >
#include "run_time.h"
using namespace std;
int main() {
    //compile time overriding

    reptile * r;
    lizard l;
    r = &l;
    r->printi();//calls base class function 
    //a->speak();
    //runtime overriding
    //Animal* a = new Animal;// since contains a pure virtual function cannot be instanstiated and hence is abstract class
    Animal* a = new Dog();
    /*Dog d;
    a = &d;*/

    a->speak();//calls derived class function
    //a->print();// called base class function non virtual binded at compile time
    return 0;
    //destructor is always called for the base class and after destructing the derived class
}
