#pragma once
#include <iostream>
using namespace std;

namespace sample {
    extern int x; // Use extern to avoid multiple definitions
    void fun();
}

namespace outer {
    void func();
    namespace inner {
        void func();
    }
}
#include "namespace.h"

int sample::x = 0;  // Define the global variable

void sample::fun() {
    std::cout << "hello" << std::endl;
}

void outer::func() {
    std::cout << "Inside first_space" << std::endl;
}

void outer::inner::func() {
    std::cout << "Inside second_space" << std::endl;
}
#include <iostream>
#include<string >
#include "namespace.h"
using namespace std;

namespace in = outer::inner;//namespace alias
int main()
{
    using namespace sample;
    fun();     // using keyword
    outer::inner::func();//scope resolution
    in::func();
    return 0;


  
}
