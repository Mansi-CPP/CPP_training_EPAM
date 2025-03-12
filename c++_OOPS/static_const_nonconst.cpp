#include <iostream>
#include <string>

using namespace std;
class Car {
private:
    string brand;      // Instance variable (separate for each object)
    int speed; // Instance variable (separate for each object)
    
public:    
    static int totalCars;  // Static variable (shared among all objects)
    Car(string b, int s) {
        brand = b;
        speed = s;
        totalCars++;  // Increment static variable
    }
public:

    // Display method
    void display() {
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
    }

    // Static method to get total cars
    static void showTotalCars() {
        cout << "Total Cars: " << totalCars << endl;
    }
};
int Car::totalCars=0;
int main()
{
  Car a("a",90);
  Car b("b",80);
  a.display();
  b.display();
  
  Car::showTotalCars();
  return 0;
}

const member
#include<iostream>
using namespace std;
class tempClass
{
    int s = 1;
    int p, q;
    const int abc;
public:
    static int xtempClass; // if defined as const then it will not be modified
public:
    tempClass(int val):abc(val)
    {
        cout << "Inside tempcalss constructor" << endl;
   
    }


    tempClass(const tempClass& obj):abc(obj.abc)
    { 
        cout << "Inside copy constructor" << endl;
        s = obj.s;
        p = obj.p;
        q = obj.q;

    }


    static void memFunc()
    {
        //xtempClass++;
        cout << "Inside memFunc " << xtempClass << endl;
    }

    void NonConstMemFunc(int x, int y)
    {
        p = x;
        q = y;

        this->p = x;
        this->q = y;
        this->xtempClass;
       /* this->abc = 10;*/ // invalid cannot modify const value
        //xtempClass++;
        cout << "Inside NonStaticMemFunc " << p << " ; " << q << endl;
    }

    void ConstMemFunc(int x, int y) const
    {
       /* p = x; same as this->p=p here
        q = y;*/
        ///*this->p = x;  1 if member function is constant then this function is also constant 
        //this->q = y;*/
        this->xtempClass;
        //xtempClass++;
        cout << "Inside NonStaticMemFunc " << p << " ; " << q << endl;
    }
    void modify() {
        p = 100;
        q = 200;
        cout << "Modified values: p = " << p << ", q = " << q << endl;
    }
};

//void globalFunc(const tempClass param) // tempClass param = tempobj;
//{
//
//    //param->
//}

#include <iostream>
#include<string >
#include "const.cpp"
using namespace std;
int tempClass::xtempClass = 10;
void globalFunc(const tempClass param) // tempClass param = tempobj;
{

    tempClass& nonConstParam = const_cast<tempClass&>(param);  // Remove `const`
    nonConstParam.modify(); // Now calling a function that modifies data
}
int main()
{

    const tempClass constObj(2);
    tempClass nonconstobj(10);
   // constObj.NonConstMemFunc(1, 2);// cannot call  non constant member funtction for constant object
    constObj.ConstMemFunc(1, 2);

    nonconstobj.ConstMemFunc(1, 2);
    nonconstobj.NonConstMemFunc(1, 2); //nonconst object can always call constant member function

    globalFunc(constObj);

    //tempClass::memFunc();
    //tempClass::NonStaticMemFunc();

    //tempClass tempObj2;
    //tempObj2.memFunc();

    return 0;
}



