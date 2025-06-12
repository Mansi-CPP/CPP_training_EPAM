#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Base and Derived class for pointer conversions
class Base {
public:
    virtual void greet() { cout << "Hello from Base\n"; }
};

class Derived : public Base {
public:
    void greet() override { cout << "Hello from Derived\n"; }
};
class sibling : public Base {
public:
    void greet() override { cout << "Hello from Derived\n"; }
};
class Base1 {
public:
    void greet() { cout << "Hello from Base1\n"; }
};

class Derived1 : public Base1 {
public:
    void greet() { cout << "Hello from Derived\n"; }
};
void show(Base *base) {
    Derived* der = dynamic_cast<Derived*>(base);
    if (der) {
        der->greet();
    }
    else {
        cout << "not possible";
    }
}


int main() {
    //Base* base = new Base();// not works because base points to base class object
    //Derived* der = dynamic_cast<Derived*>(base);// unsafe cast 
    //if (der) {
    //    der->greet();  // Won't run
    //}
    //else {
    //    cout << "Cast failed! base is not a Derived.\n";
    //}

    //delete base;
    Derived d;
    Base* basePtr = &d; // safe
    Derived* d2 = dynamic_cast<Derived*>(basePtr);
    cout << "2. Pointer Conversion (Derived* -> Base*): ";
    basePtr->greet();
    //Derived1 d1;
    //Base1* basePtr1 = &d1;
    //Derived* d3 = dynamic_cast<Derived1*>(basePtr1);//operand mustt have a polymorphic type
    //cout << "2. Pointer Conversion (Derived* -> Base*): ";
    //basePtr->greet();

    Base* base = new Derived;
    Derived* derived = new Derived;
    sibling* Sibling = new sibling;
    cout << "for base:" << endl;
    show(base);
    cout << "for derived:" << endl;
    show(derived);
    cout << "for sibling:" << endl;
    show(Sibling);
    cout << "Type: " << typeid(*base).name() << endl;
    cout << "Type: " << typeid(*derived).name() << endl;
    cout << "Type: " << typeid(*Sibling).name() << endl;
    delete base;
    delete derived;
    delete Sibling;
    return 0;
}

//note
1.in case of pointers
Base* base = new Base();  // base points to a real Base object

Derived* derived = dynamic_cast<Derived*>(base);  // ❌ Returns nullptr
//nullptr exist so can return nullptr 
2.in case of references 
Derived& d = dynamic_cast<Derived&>(b);  // throws bad cast exception
//null refernces do not exist 
