#include <iostream>
#include <vector>
#include <tuple>
#include <typeinfo>

using namespace std;

// Function returning an int
int getValue() { return 42; }

int main() {
    cout << "===== Basic decltype Usage =====" << endl;

    int a = 10;
    double b = 3.14;
    const int c = 50;

    decltype(a) x;       // x is int
    decltype(b) y = 2.71; // y is double
    decltype(c) z = 100; // z is const int

    cout << "Type of x: " << typeid(x).name() << endl;  // int
    cout << "Type of y: " << typeid(y).name() << endl;  // double
    cout << "Type of z: " << typeid(z).name() << endl;  // const int

    cout << "\n===== decltype with References and Pointers =====" << endl;

    int val = 20;
    int& ref = val;
    int* ptr = &val;

    decltype(ref) ref2 = val;  // ref2 is int& (should preserve reference)
    decltype(*ptr) ref3 = val; // ref3 is int& (because *ptr is int&)

    cout << "Type of ref2: " << typeid(ref2).name() << endl;  // int&
    cout << "Type of ref3: " << typeid(ref3).name() << endl;  // int&

    cout << "\n===== decltype with Expressions =====" << endl;

    decltype(a + b) sum; // sum is double (result type of int + double)
    sum = a + b;

    cout << "sum: " << sum << endl;
    cout << "Type of sum: " << typeid(sum).name() << endl;  // double

    cout << "\n===== decltype with Function Return Type =====" << endl;

    decltype(getValue()) num = getValue(); // num is int

    cout << "Type of num: " << typeid(num).name() << endl;  // int

    cout << "\n===== decltype(auto) (C++14) =====" << endl;

    decltype(auto) da = ref; // da is int& (preserves reference)
    cout << "Type of da: " << typeid(da).name() << endl;  // int&

    //cout << "\n===== decltype with Structured Bindings (C++17) =====" << endl;

    //pair<int, double> p = { 42, 3.14 };
    //decltype(p) newPair = { 100, 2.71 }; // newPair is pair<int, double>

    //auto [first, second] = p; // first = 42 (int), second = 3.14 (double)

    //cout << "Type of newPair: " << typeid(newPair).name() << endl;  // std::pair<int, double>
    //cout << "first: " << first << ", second: " << second << endl;

    cout << "\n===== decltype with Range-based Loop =====" << endl;

    vector<int> vec = { 1, 2, 3, 4, 5 };

    for (decltype(vec)::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    //for (const decltype(auto) num : vec) { // num is int
    //    cout << num << " ";
    //}
    //cout << endl;


    return 0;
}
//error in references ask doubt
//==== = Basic decltype Usage ==== =
//Type of x : int
//Type of y : double
//Type of z : int
//
//==== = decltype with References and Pointers ==== =
//Type of ref2 : int
//Type of ref3 : int
//
//==== = decltype with Expressions ==== =
//sum : 13.14
//Type of sum : double
//
//==== = decltype with Function Return Type ==== =
//Type of num : int
//
//==== = decltype(auto) (C++14) ==== =
//Type of da : int
//
//==== = decltype with Range - based Loop ==== =
//1 2 3 4 5
