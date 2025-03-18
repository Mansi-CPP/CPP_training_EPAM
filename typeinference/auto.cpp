#include <iostream>
#include <vector>
#include <tuple>
#include <typeinfo>  // For typeid

using namespace std;

int main() {
    // 1. Basic auto usage
    auto a = 42;           // int
    auto b = 3.14;         // double
    auto c = "Hello";      // const char*

    cout << "Type of a: " << typeid(a).name() << endl;
    cout << "Type of b: " << typeid(b).name() << endl;
    cout << "Type of c: " << typeid(c).name() << endl;

    // 2. auto with const
    const int x = 100;
    cout << "type of x" << typeid(x).name() << endl;
    // if the original variable is const and const not specified before auto the const is removed
    auto y = x; // y is int (const is removed)
    const auto z = x;    // z is const int

    cout << "Type of y: " << typeid(y).name() << endl;
    cout << "Type of z: " << typeid(z).name() << endl;

    // 3. auto with reference
    int val = 50;
    auto& ref = val;     // ref is int&
    ref = 75;            // modifies val

    cout << "Type of ref: " << typeid(ref).name() << endl;

    // 4. auto with const reference
    const auto& cref = val; // cref is const int&

    cout << "Type of cref: " << typeid(cref).name() << endl;

    // 5. auto with pointer
    auto ptr = &val;  // ptr is int*
    *ptr = 80;        // modifies val

    cout << "Type of ptr: " << typeid(ptr).name() << endl;

    // 6. auto with const pointer
    const int num = 500;
    auto ptr1 = &num;       // ptr1 is const int* (cannot modify *ptr1)
    auto* ptr2 = &val;      // ptr2 is int* (can modify *ptr2)

    cout << "Type of ptr1: " << typeid(ptr1).name() << endl;
    cout << "Type of ptr2: " << typeid(ptr2).name() << endl;

    // 7. auto with STL container
    vector<int> vec = { 1, 2, 3, 4, 5 };

    // Auto with iterator
    auto it = vec.begin(); // it is std::vector<int>::iterator
    cout << "First element: " << *it << endl;
    cout << "Type of it: " << typeid(it).name() << endl;

    // Auto with range-based loop
    for (auto num : vec) {
        cout << num << " "; // num is int
    }
    cout << endl;

    // Auto with const reference in range loop
    for (const auto& num : vec) {
        cout << num << " "; // Prevents unnecessary copies
    }
    cout << endl;

    //  auto with lambda function
    auto sum = [](auto x, auto y) { return x + y; };
    cout << "Sum: " << sum(5, 10) << endl;
    cout << "Type of sum(5,10): " << typeid(sum(5, 10)).name() << endl;
    // auto can not be used in function parameters
    //void fun(auto num) { // auto not allowed

    //}

    return 0;
}
//output
//Type of a : int
//Type of b : double
//Type of c : char const* __ptr64
//type of xint
//Type of y : int
//Type of z : int
//Type of ref : int
//Type of cref : int
//Type of ptr : int* __ptr64
//Type of ptr1 : int const* __ptr64
//Type of ptr2 : int* __ptr64
//First element : 1
//Type of it : class std::_Vector_iterator < class std::_Vector_val<struct std::_Simple_types<int> > >
//1 2 3 4 5
//1 2 3 4 5
//Sum : 15
//Type of sum(5, 10) : int
