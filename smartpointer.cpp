
#include <iostream>
using namespace std;

// A generic smart pointer class
template <class T> class SmartPtr {
    T* ptr; // Actual pointer
public:
    // Constructor
    explicit SmartPtr(T* p = NULL) { ptr = p; }

    // Destructor
    ~SmartPtr() { delete (ptr); }

    // Overloading dereferencing operator
    T& operator*() { return *ptr; }

    // Overloading arrow operator so that
    // members of T can be accessed
    // like a pointer (useful if T represents
    // a class or struct or union type)
    T* operator->() { return ptr; }
};

class test {
public:
    test() {
        cout << "created" << endl;
    }
    ~test() {
        cout << "destroyed" << endl;
    }
    void show() {
        cout << "hello";
    }
};
//template <typename T>
//class AutoPtr {
//private:
//    T* ptr; // Raw pointer
//
//public:
//    // Constructor
//    explicit AutoPtr(T* p = nullptr) : ptr(p) {}
//
//    // Destructor
//    ~AutoPtr() { delete ptr; }
//
//    // Copy Constructor (Transfers Ownership!)
//    AutoPtr(AutoPtr& other) : ptr(other.ptr) {
//        other.ptr = nullptr; // Ownership transferred, old pointer set to NULL
//    }
//
//    // Copy Assignment (Transfers Ownership!)
//    AutoPtr& operator=(AutoPtr& other) {
//        if (this != &other) {
//            delete ptr;   // Delete existing resource
//            ptr = other.ptr; // Transfer ownership
//            other.ptr = nullptr; // Old pointer set to NULL
//        }
//        return *this;
//    }
//
//    // Dereference operators
//    T& operator*() const { return *ptr; }
//    T* operator->() const { return ptr; }
//
//    // Get raw pointer
//    T* get() const { return ptr; }
//};
//template <typename t>
//class UniquePtr {
//private:
//    t* ptr;
//
//public:
//    // Constructor
//    explicit UniquePtr(t* p = nullptr) : ptr(p) {}
//
//    // Destructor
//    ~UniquePtr() { delete ptr; }
//
//    
//    UniquePtr(const UniquePtr&) = delete;
//    UniquePtr& operator=(const UniquePtr&) = delete;
//
//    UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr) {
//        other.ptr = nullptr;
//    }
//
//    // Move Assignment Operator
//    UniquePtr& operator=(UniquePtr&& other) noexcept {
//        if (this != &other) {
//            delete ptr;  // Delete existing object
//            ptr = other.ptr;
//            other.ptr = nullptr;
//        }
//        return *this;
//    }
//
//    // Dereference operators
//    T& operator*() const { return *ptr; }
//    T* operator->() const { return ptr; }
//
//    // Get raw pointer
//    T* get() const { return ptr; }
//};
class B; // Forward declaration

class A {
public:
    std::shared_ptr<B> b_ptr;
    ~A() { std::cout << "A Destroyed\n"; }
};

class B {
public:
    std::weak_ptr<A> a_ptr; // Use weak_ptr to prevent circular reference
    ~B() { std::cout << "B Destroyed\n"; }
};

#include <iostream>
#include <vector>
#include <typeinfo>
#include<algorithm>
#include<memory>
#include"Smart_pointers.cpp"
int main(){
    //SmartPtr<int> ptr=new int();// using explicit does not allow this conversion from int* to int
    /*SmartPtr<int> ptr(new int());

    *ptr = 20;
    cout << *ptr;*/

    
    auto_ptr<test> ptr1(new test());
    ptr1->show();
   
    auto_ptr<test> ptr2 = ptr1;
    if (!ptr1.get()) {
        cout << "ptr1 deleted" << endl;
    }

   // unique_ptr<test>uq1 ( new test());//if exception occurs memory will be leaked so dont use
    unique_ptr<test>uq1 = make_unique<test>();
    uq1->show();
    unique_ptr<test>uq2 = move(uq1);
    if (!uq1.get()){
        cout << "uq1 moved" << endl;
    }
    unique_ptr<int> u1 = make_unique<int>(60);
    unique_ptr<int> u2(move(u1));
    u1.reset(new int(9));
    cout << "reset used" << *u1 << endl;
    cout << "u2" << u2 << endl;
    //shared pointer
    shared_ptr<test>sp1 = make_shared<test>();
    cout << "number of res" << sp1.use_count() << endl; 
    {

        shared_ptr<test>sp2(sp1);
        cout << "number of res in scope" << sp2.use_count() << endl;
    }
    cout << "number of res" << sp1.use_count() << endl;

    //weak ptr
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    a->b_ptr = b;
    b->a_ptr = a;

    return 0;
}


