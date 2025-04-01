#include <iostream>
#include <string>
using namespace std;
class MyString {
private:
    std::string data; // Using std::string instead of raw pointer
public:
    MyString(const std::string& str = "") : data(str) {
        cout << "Constructor called\n";
    }

    // Copy Constructor
    MyString(const MyString& other) : data(other.data) {
        cout << "Copy Constructor called\n";
    }

    // Copy Assignment Operator
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            data = other.data;
            cout << "Copy Assignment Operator called\n";
        }
        return *this;
    }

    // Move Constructor
    MyString(MyString&& other) noexcept : data(std::move(other.data)) {
        //other.data = nullptr;
        cout << "Move Constructor called\n";
    }

    // Move Assignment Operator
    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            data = std::move(other.data);
            //other.data = nullptr;//to avoid  that other does not delete the data by calling destructor
            cout << "Move Assignment Operator called\n";
        }
        return *this;
    }

    void print() const {
        cout << data << std::endl;
    }
};
#include <iostream>
#include <vector>
#include <typeinfo>
#include<algorithm>
#include"l_valueR_value.cpp"
void foo(int&& lr) {
}
void foo1(int&& rr) {
}
int main() {
    cout << "Creating str1...\n";
    MyString str1("Hello");

    cout << "\nCopying str1 to str2...\n";
    MyString str2 = str1; // Copy Constructor (Deep Copy)
    cout << "when copy const is called"<<endl;
    cout << "str1: "; str1.print();
    cout << "str2: "; str2.print();


    cout << "\nAssigning str1 to str3...\n";
    MyString str3;
    str3 = str1; // Copy Assignment Operator
    cout << "when assig is called" << endl;
    cout << "str1: "; str1.print();
    std::cout << "str3: "; str3.print();


    std::cout << "\nMoving str1 to str4...\n";
    MyString str4 = std::move(str1); // Move Constructor
    cout << "when move const is called" << endl;
    cout << "str1: "; str1.print();
    std::cout << "str4: "; str4.print();


    std::cout << "\nMoving str2 to str5...\n";
    MyString str5;
    str5 = std::move(str2); // Move Assignment Operator
    cout << "when move assignment is called" << endl;
    cout << "str2: "; str2.print();
    std::cout << "str5: "; str5.print();



    std::cout << "\nProgram End - Destructors Called\n";
    return 0;

}
//Creating str1...
//Constructor called
//
//Copying str1 to str2...
//Copy Constructor called
//when copy const is called
//str1 : Hello
//str2 : Hello
//
//Assigning str1 to str3...
//Constructor called
//Copy Assignment Operator called
//when assig is called
//str1 : Hello
//str3 : Hello
//
//Moving str1 to str4...
//Move Constructor called
//when move const is called
//str1 :                        deleted from str1
//str4: Hello
//
//Moving str2 to str5...
//Constructor called
//Move Assignment Operator called
//when move assignment is called
//str2 :
//str5: Hello                   deleted from str2  
//
//Program End - Destructors Called
